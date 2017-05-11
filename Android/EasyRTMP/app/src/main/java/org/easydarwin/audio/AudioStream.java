package org.easydarwin.audio;

import android.media.AudioFormat;
import android.media.AudioRecord;
import android.media.MediaCodec;
import android.media.MediaCodecInfo;
import android.media.MediaFormat;
import android.media.MediaRecorder;
import android.util.Log;
import android.os.Process;

import org.easydarwin.easypusher.BuildConfig;
import org.easydarwin.easyrtmp.push.EasyRTMP;
import org.easydarwin.muxer.EasyMuxer;
import org.easydarwin.push.Pusher;

import java.nio.ByteBuffer;

public class AudioStream {
    private final EasyMuxer muxer;
    private int samplingRate = 8000;
    private int bitRate = 16000;
    private int BUFFER_SIZE = 1600;
    int mSamplingRateIndex = 0;
    AudioRecord mAudioRecord;
    MediaCodec mMediaCodec;
    Pusher easyPusher;
    private Thread mThread = null;
    String TAG = "AudioStream";
    //final String path = Environment.getExternalStorageDirectory() + "/123450001.aac";

    protected MediaCodec.BufferInfo mBufferInfo = new MediaCodec.BufferInfo();
    protected ByteBuffer[] mBuffers = null;

    /**
     * There are 13 supported frequencies by ADTS.
     **/
    public static final int[] AUDIO_SAMPLING_RATES = {96000, // 0
            88200, // 1
            64000, // 2
            48000, // 3
            44100, // 4
            32000, // 5
            24000, // 6
            22050, // 7
            16000, // 8
            12000, // 9
            11025, // 10
            8000, // 11
            7350, // 12
            -1, // 13
            -1, // 14
            -1, // 15
    };

    public AudioStream(Pusher easyPusher, EasyMuxer muxer) {
        this.easyPusher = easyPusher;
        this.muxer = muxer;
        int i = 0;
        for (; i < AUDIO_SAMPLING_RATES.length; i++) {
            if (AUDIO_SAMPLING_RATES[i] == samplingRate) {
                mSamplingRateIndex = i;
                break;
            }
        }
    }

    /**
     * 编码
     */
    public void startRecord() {
        mThread = new Thread(new Runnable() {
            @Override
            public void run() {
                Process.setThreadPriority(Process.THREAD_PRIORITY_AUDIO);
                int len = 0, bufferIndex = 0;
                try {
                    int bufferSize = AudioRecord.getMinBufferSize(samplingRate, AudioFormat.CHANNEL_IN_MONO, AudioFormat.ENCODING_PCM_16BIT);
                    mAudioRecord = new AudioRecord(MediaRecorder.AudioSource.MIC, samplingRate, AudioFormat.CHANNEL_IN_MONO, AudioFormat.ENCODING_PCM_16BIT, bufferSize);
                    mMediaCodec = MediaCodec.createEncoderByType("audio/mp4a-latm");
                    MediaFormat format = new MediaFormat();
                    format.setString(MediaFormat.KEY_MIME, "audio/mp4a-latm");
                    format.setInteger(MediaFormat.KEY_BIT_RATE, bitRate);
                    format.setInteger(MediaFormat.KEY_CHANNEL_COUNT, 1);
                    format.setInteger(MediaFormat.KEY_SAMPLE_RATE, samplingRate);
                    format.setInteger(MediaFormat.KEY_AAC_PROFILE,
                            MediaCodecInfo.CodecProfileLevel.AACObjectLC);
                    format.setInteger(MediaFormat.KEY_MAX_INPUT_SIZE, BUFFER_SIZE);
                    mMediaCodec.configure(format, null, null, MediaCodec.CONFIGURE_FLAG_ENCODE);
                    mMediaCodec.start();
                    mBuffers = mMediaCodec.getOutputBuffers();
                    mAudioRecord.startRecording();
                    final ByteBuffer[] inputBuffers = mMediaCodec.getInputBuffers();

                    ByteBuffer mBuffer = ByteBuffer.allocate(10240);
                    while (mThread != null) {
                        bufferIndex = mMediaCodec.dequeueInputBuffer(1000);
                        if (bufferIndex >= 0) {
                            inputBuffers[bufferIndex].clear();
                            len = mAudioRecord.read(inputBuffers[bufferIndex], BUFFER_SIZE);
                            if (len == AudioRecord.ERROR_INVALID_OPERATION || len == AudioRecord.ERROR_BAD_VALUE) {
                                mMediaCodec.queueInputBuffer(bufferIndex, 0, 0, System.nanoTime() / 1000, 0);
                            } else {
                                mMediaCodec.queueInputBuffer(bufferIndex, 0, len, System.nanoTime() / 1000, 0);
                            }
                        }
                        int index = 0;
                        do {
                            index = mMediaCodec.dequeueOutputBuffer(mBufferInfo, 1000);
                            if (index >= 0) {
                                if (mBufferInfo.flags == MediaCodec.BUFFER_FLAG_CODEC_CONFIG) {
                                    continue;
                                }
                                mBuffer.clear();
                                ByteBuffer outputBuffer = mBuffers[index];
                                if (muxer != null)
                                    muxer.pumpStream(outputBuffer, mBufferInfo, false);
                                outputBuffer.get(mBuffer.array(), 7, mBufferInfo.size);
                                outputBuffer.clear();
                                mBuffer.position(7 + mBufferInfo.size);
                                addADTStoPacket(mBuffer.array(), mBufferInfo.size + 7);
                                mBuffer.flip();
                                easyPusher.push(mBuffer.array(), 0, mBufferInfo.size + 7, mBufferInfo.presentationTimeUs / 1000, 0);
                                if (BuildConfig.DEBUG) Log.i(TAG,String.format("push audio stamp:%d",mBufferInfo.presentationTimeUs / 1000));
                                mMediaCodec.releaseOutputBuffer(index, false);
                                break;
                            } else if (index == MediaCodec.INFO_OUTPUT_BUFFERS_CHANGED) {
                                mBuffers = mMediaCodec.getOutputBuffers();
                            } else if (index == MediaCodec.INFO_OUTPUT_FORMAT_CHANGED) {
                                Log.v(TAG, "output format changed...");
                                MediaFormat newFormat = mMediaCodec.getOutputFormat();
                                if (muxer != null)
                                    muxer.addTrack(newFormat, false);
                            } else if (index == MediaCodec.INFO_TRY_AGAIN_LATER) {
                                Log.v(TAG, "No buffer available...");
                            } else {
                                Log.e(TAG, "Message: " + index);
                            }
                        } while (mThread != null && index >= 0);
                    }
                } catch (Exception e) {
                    Log.e(TAG, "Record___Error!!!!!");
                    e.printStackTrace();
                } finally {
                    if (mAudioRecord != null) {
                        mAudioRecord.stop();
                        mAudioRecord.release();
                        mAudioRecord = null;
                    }
                    if (mMediaCodec != null) {
                        mMediaCodec.stop();
                        mMediaCodec.release();
                        mMediaCodec = null;
                    }
                }
            }
        }, "AACRecoder");
        mThread.start();
    }

    private void addADTStoPacket(byte[] packet, int packetLen) {
        packet[0] = (byte) 0xFF;
        packet[1] = (byte) 0xF1;
        packet[2] = (byte) (((2 - 1) << 6) + (mSamplingRateIndex << 2) + (1 >> 2));
        packet[3] = (byte) (((1 & 3) << 6) + (packetLen >> 11));
        packet[4] = (byte) ((packetLen & 0x7FF) >> 3);
        packet[5] = (byte) (((packetLen & 7) << 5) + 0x1F);
        packet[6] = (byte) 0xFC;
    }

    public void stop() {
        try {
            Thread t = mThread;
            mThread = null;
            if (t != null) {
                t.interrupt();
                t.join();
            }
        } catch (InterruptedException e) {
            e.fillInStackTrace();
        }
    }

}
