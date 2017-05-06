package org.easydarwin.push;

import android.content.Context;
import android.graphics.ImageFormat;
import android.hardware.Camera;
import android.media.MediaCodec;
import android.media.MediaFormat;
import android.os.Build;
import android.os.Bundle;
import android.os.Environment;
import android.os.Process;
import android.preference.PreferenceManager;
import android.util.Log;
import android.view.SurfaceHolder;

import org.easydarwin.audio.AudioStream;
import org.easydarwin.easypusher.BuildConfig;
import org.easydarwin.easypusher.EasyApplication;
import org.easydarwin.easyrtmp.push.EasyRTMP;
import org.easydarwin.hw.EncoderDebugger;
import org.easydarwin.hw.NV21Convertor;
import org.easydarwin.muxer.EasyMuxer;
import org.easydarwin.sw.JNIUtil;
import org.easydarwin.sw.TxtOverlay;
import org.easydarwin.sw.X264Encoder;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.io.StringWriter;
import java.lang.ref.WeakReference;
import java.nio.ByteBuffer;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Iterator;
import java.util.List;
import java.util.concurrent.ArrayBlockingQueue;

public class MediaStream {

    private static final boolean VERBOSE = BuildConfig.DEBUG;
    Pusher mEasyPusher;
    static final String TAG = "EasyPusher";
    int width = 640, height = 480;
    int framerate, bitrate;
    int mCameraId = Camera.CameraInfo.CAMERA_FACING_BACK;
    MediaCodec mMediaCodec;
    WeakReference<SurfaceHolder> mSurfaceHolderRef;
    Camera mCamera;
    NV21Convertor mConvertor;
    boolean pushStream = false;//是否要推送数据
    AudioStream audioStream;
    private boolean isCameraBack = true;
    private int mDgree;
    private Context mApplicationContext;
    Thread pushThread;
    boolean codecAvailable = false;
    private boolean mSWCodec;
    private X264Encoder x264;
    private Consumer mConsumer;
    private EasyMuxer mMuxer;
    private int mTrackIndex;

    public MediaStream(Context context, SurfaceHolder holder) {
        mApplicationContext = context;
        mSurfaceHolderRef = new WeakReference(holder);
        if (EasyApplication.isRTMP())
            mEasyPusher = new EasyRTMP();
        else mEasyPusher = new EasyPusher();
    }

    public void startStream(String url, InitCallback callback) {
        mEasyPusher.initPush(url, mApplicationContext, callback);
        pushStream = true;
    }

    public void startStream(String ip, String port, String id, InitCallback callback) {
        mEasyPusher.initPush(ip, port, String.format("%s.sdp", id), mApplicationContext, callback);
        pushStream = true;
    }
//    public void setCallback(EasyPusher.OnInitPusherCallback callback) {
//        mEasyPusher.setOnInitPusherCallback(callback);
//    }


    public void setDgree(int dgree) {
        mDgree = dgree;
    }

    /**
     * 更新分辨率
     */
    public void updateResolution(int width, int height) {
        this.width = width;
        this.height = height;
    }

    /**
     * 重新开始
     */
    public void reStartStream() {
        if (mCamera == null) return;
        stopPreview();
        destroyCamera();
        createCamera();
        startPreview();
    }

    public static int[] determineMaximumSupportedFramerate(Camera.Parameters parameters) {
        int[] maxFps = new int[]{0, 0};
        List<int[]> supportedFpsRanges = parameters.getSupportedPreviewFpsRange();
        for (Iterator<int[]> it = supportedFpsRanges.iterator(); it.hasNext(); ) {
            int[] interval = it.next();
            if (interval[1] > maxFps[1] || (interval[0] > maxFps[0] && interval[1] == maxFps[1])) {
                maxFps = interval;
            }
        }
        return maxFps;
    }


    public static final boolean useSWCodec() {
        return Build.VERSION.SDK_INT >= 23;
    }


    public boolean createCamera() {
        try {
            mCamera = Camera.open(mCameraId);

            Camera.Parameters parameters = mCamera.getParameters();
            int[] max = determineMaximumSupportedFramerate(parameters);
            Camera.CameraInfo camInfo = new Camera.CameraInfo();
            Camera.getCameraInfo(mCameraId, camInfo);
            int cameraRotationOffset = camInfo.orientation;
            if (mCameraId == Camera.CameraInfo.CAMERA_FACING_FRONT)
                cameraRotationOffset += 180;
            int rotate = (360 + cameraRotationOffset - mDgree) % 360;
            parameters.setRotation(rotate);
            mSWCodec = PreferenceManager.getDefaultSharedPreferences(mApplicationContext).getBoolean("key-sw-codec", useSWCodec());
            parameters.setPreviewFormat(mSWCodec ? ImageFormat.YV12 : ImageFormat.NV21);
            List<Camera.Size> sizes = parameters.getSupportedPreviewSizes();
            parameters.setPreviewSize(width, height);
            parameters.setPreviewFpsRange(max[0], max[1]);
            mCamera.setParameters(parameters);
            int displayRotation;
            displayRotation = (cameraRotationOffset - mDgree + 360) % 360;
            mCamera.setDisplayOrientation(displayRotation);
            SurfaceHolder holder = mSurfaceHolderRef.get();
            if (holder != null) {
                mCamera.setPreviewDisplay(holder);
            }
            return true;
        } catch (Exception e) {
            StringWriter sw = new StringWriter();
            PrintWriter pw = new PrintWriter(sw);
            e.printStackTrace(pw);
            String stack = sw.toString();
            destroyCamera();
            e.printStackTrace();
            return false;
        }
    }

    Object lock = new byte[0];

    class TimedBuffer {
        byte[] buffer;
        long time;

        public TimedBuffer(byte[] data) {
            buffer = data;
            time = System.currentTimeMillis();
        }
    }

    private ArrayBlockingQueue<TimedBuffer> yuvs = new ArrayBlockingQueue<TimedBuffer>(5);
    private ArrayBlockingQueue<byte[]> yuv_caches = new ArrayBlockingQueue<byte[]>(10);

    class Consumer extends Thread {
        ByteBuffer[] inputBuffers;
        ByteBuffer[] outputBuffers;
        byte[] mPpsSps = new byte[0];
        int keyFrmHelperCount = 0;
        private long timeStamp = System.currentTimeMillis();

        public Consumer() {
            super("Consumer");
        }

        @Override
        public void run() {
            Process.setThreadPriority(Process.THREAD_PRIORITY_AUDIO);
            Camera.Size previewSize = mCamera.getParameters().getPreviewSize();
            byte[] h264 = new byte[(int) (previewSize.width * previewSize.height * 1.5)];
//            byte[] overlayYuv = new byte[(int) (previewSize.width * previewSize.height * 1.5)];
            TxtOverlay overlay = new TxtOverlay(mApplicationContext);
            int region = 0;
            try {
                int xpos, ypos;


                if (mDgree == 0) {
                    overlay.init(previewSize.height, previewSize.width, mApplicationContext.getFileStreamPath("SIMYOU.ttf").getPath());
                } else {
                    overlay.init(previewSize.width, previewSize.height, mApplicationContext.getFileStreamPath("SIMYOU.ttf").getPath());
                }
//                overlay.init(previewSize.width, previewSize.height);
                while (mConsumer != null) {
                    TimedBuffer tb;
//                    Log.i(TAG, String.format("cache yuv:%d", yuvs.size()));
                    tb = yuvs.take();
                    byte[] data = tb.buffer;

                    SimpleDateFormat format = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
                    String t = format.format(new Date());
//                    data = overlayYuv;

                    long stamp = tb.time;
                    int[] outLen = new int[1];
                    if (mDgree == 0) {
                        Camera.CameraInfo camInfo = new Camera.CameraInfo();
                        Camera.getCameraInfo(mCameraId, camInfo);
                        int cameraRotationOffset = camInfo.orientation;
                        if (cameraRotationOffset == 90) {
                            if (mSWCodec) {
                                yuvRotate(data, 0, previewSize.width, previewSize.height, 90);
                            } else {
                                yuvRotate(data, 1, previewSize.width, previewSize.height, 90);
                            }
                        } else if (cameraRotationOffset == 270) {
                            if (mSWCodec) {
                                yuvRotate(data, 0, previewSize.width, previewSize.height, 270);
                            } else {
                                yuvRotate(data, 1, previewSize.width, previewSize.height, 270);
                            }
                        }

                        save2file(data, String.format("/sdcard/yuv_%d_%d.yuv", previewSize.height, previewSize.width));
                    }
                    if (PreferenceManager.getDefaultSharedPreferences(mApplicationContext).getBoolean("key_enable_video_overlay", false)) {
                        String txt = String.format("drawtext=fontfile=" + mApplicationContext.getFileStreamPath("SIMYOU.ttf") + ": text='%s%s':x=(w-text_w)/2:y=H-60 :fontcolor=white :box=1:boxcolor=0x00000000@0.3", "EasyPusher", new SimpleDateFormat("yyyy-MM-ddHHmmss").format(new Date()));
                        txt = "EasyPusher " + new SimpleDateFormat("yy-MM-dd HH:mm:ss SSS").format(new Date());
                        overlay.overlay(data, txt);
                    }
                    int r = 0;
                    byte[] newBuf = null;
                    synchronized (lock) {
                        if (mSWCodec && x264 != null) {
                            byte[] keyFrm = new byte[1];
                            if (false) {
                                if (keyFrmHelperCount++ > 50) {
                                    keyFrmHelperCount = 0;
                                    keyFrm[0] = 1;
                                } else {
                                    keyFrm[0] = 0;
                                }
                            }
                            long begin = System.currentTimeMillis();
                            r = x264.encode(data, 0, h264, 0, outLen, keyFrm);
                            if (r > 0) {
                                Log.i(TAG, String.format("encode spend:%d ms. keyFrm:%d", System.currentTimeMillis() - begin, keyFrm[0]));
//                                newBuf = new byte[outLen[0]];
//                                System.arraycopy(h264, 0, newBuf, 0, newBuf.length);
                            }
                        }
                    }
                    if (mSWCodec) {
                        if (r > 0) {
                            mEasyPusher.push(h264, 0, outLen[0], stamp, 1);
                        }
                    } else {
                        inputBuffers = mMediaCodec.getInputBuffers();
                        outputBuffers = mMediaCodec.getOutputBuffers();
                        int bufferIndex = mMediaCodec.dequeueInputBuffer(0);
                        if (bufferIndex >= 0) {
                            inputBuffers[bufferIndex].clear();
                            mConvertor.convert(data, inputBuffers[bufferIndex]);
                            mMediaCodec.queueInputBuffer(bufferIndex, 0, inputBuffers[bufferIndex].position(), System.nanoTime() / 1000, 0);

                            MediaCodec.BufferInfo bufferInfo = new MediaCodec.BufferInfo();
                            int outputBufferIndex = 0;
                            do {
                                outputBufferIndex = mMediaCodec.dequeueOutputBuffer(bufferInfo, 0);
                                if (outputBufferIndex == MediaCodec.INFO_TRY_AGAIN_LATER) {
                                    // no output available yet
                                } else if (outputBufferIndex == MediaCodec.INFO_OUTPUT_BUFFERS_CHANGED) {
                                    // not expected for an encoder
                                } else if (outputBufferIndex == MediaCodec.INFO_OUTPUT_FORMAT_CHANGED) {
                                    EasyMuxer muxer = MediaStream.this.mMuxer;
                                    if (muxer != null) {
                                        // should happen before receiving buffers, and should only happen once
                                        MediaFormat newFormat = mMediaCodec.getOutputFormat();
                                        muxer.addTrack(newFormat, true);
                                    }
                                } else if (outputBufferIndex < 0) {
                                    // let's ignore it
                                } else {

                                    ByteBuffer outputBuffer = outputBuffers[outputBufferIndex];

                                    EasyMuxer muxer = MediaStream.this.mMuxer;
                                    if (muxer != null) {
                                        muxer.pumpStream(outputBuffer, bufferInfo, true);
                                    }
//                        String data0 = String.format("%x %x %x %x %x %x %x %x %x %x ", outData[0], outData[1], outData[2], outData[3], outData[4], outData[5], outData[6], outData[7], outData[8], outData[9]);
//                        Log.e("out_data", data0);

                                    //记录pps和sps
                                    int type = outputBuffer.get(4) & 0x07;

                                    Log.d(TAG, String.format("type is %d", type));
                                    if (type == 7 || type == 8) {
                                        byte[] outData = new byte[bufferInfo.size];
                                        outputBuffer.get(outData);
                                        mPpsSps = outData;
                                    } else if (type == 5) {
                                        //在关键帧前面加上pps和sps数据
                                        System.arraycopy(mPpsSps, 0, h264, 0, mPpsSps.length);
                                        outputBuffer.get(h264, mPpsSps.length, bufferInfo.size);
                                        mEasyPusher.push(h264, 0, mPpsSps.length + bufferInfo.size, bufferInfo.presentationTimeUs / 1000, 1);
                                        if (BuildConfig.DEBUG)
                                            Log.i(TAG, String.format("push video stamp:%d", bufferInfo.presentationTimeUs / 1000));

                                    } else {
                                        outputBuffer.get(h264, 0, bufferInfo.size);
                                        if (System.currentTimeMillis() - timeStamp >= 3000) {
                                            timeStamp = System.currentTimeMillis();
                                            if (Build.VERSION.SDK_INT >= 23) {
                                                Bundle params = new Bundle();
                                                params.putInt(MediaCodec.PARAMETER_KEY_REQUEST_SYNC_FRAME, 0);
                                                mMediaCodec.setParameters(params);
                                            }
                                        }
                                        mEasyPusher.push(h264, 0, bufferInfo.size, bufferInfo.presentationTimeUs / 1000, 1);

                                        if (BuildConfig.DEBUG)
                                            Log.i(TAG, String.format("push video stamp:%d", bufferInfo.presentationTimeUs / 1000));
                                    }
                                    mMediaCodec.releaseOutputBuffer(outputBufferIndex, false);
                                }
                            }
                            while (outputBufferIndex >= 0);

                        } else {
                            Log.e(TAG, "No buffer available !");
                        }
                    }
                    yuv_caches.offer(data);

                }
            } catch (InterruptedException e) {
                e.printStackTrace();
            } finally {
                overlay.release();
            }
        }
    }

    private void save2file(byte[] data, String path) {
        if (true) return;
        try {
            FileOutputStream fos = new FileOutputStream(path, true);
            fos.write(data);
            fos.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    // 根据Unicode编码完美的判断中文汉字和符号
    private static boolean isChinese(char c) {
        Character.UnicodeBlock ub = Character.UnicodeBlock.of(c);
        if (ub == Character.UnicodeBlock.CJK_UNIFIED_IDEOGRAPHS || ub == Character.UnicodeBlock.CJK_COMPATIBILITY_IDEOGRAPHS
                || ub == Character.UnicodeBlock.CJK_UNIFIED_IDEOGRAPHS_EXTENSION_A || ub == Character.UnicodeBlock.CJK_UNIFIED_IDEOGRAPHS_EXTENSION_B
                || ub == Character.UnicodeBlock.CJK_SYMBOLS_AND_PUNCTUATION || ub == Character.UnicodeBlock.HALFWIDTH_AND_FULLWIDTH_FORMS
                || ub == Character.UnicodeBlock.GENERAL_PUNCTUATION) {
            return true;
        }
        return false;
    }

    private int getTxtPixelLength(String txt, boolean zoomed) {
        int length = 0;
        int fontWidth = zoomed ? 16 : 8;
        for (int i = 0; i < txt.length(); i++) {
            length += isChinese(txt.charAt(i)) ? fontWidth * 2 : fontWidth;
        }
        return length;
    }

    /**
     * 开启预览
     */
    public synchronized void startPreview() {
        if (mCamera != null) {
            yuv_caches.clear();
            yuvs.clear();
            mCamera.startPreview();
            try {
                mCamera.autoFocus(null);
            } catch (Exception e) {
                //忽略异常
                Log.i(TAG, "auto foucus fail");
            }

            int previewFormat = mCamera.getParameters().getPreviewFormat();
            Camera.Size previewSize = mCamera.getParameters().getPreviewSize();
            int size = previewSize.width * previewSize.height
                    * ImageFormat.getBitsPerPixel(previewFormat)
                    / 8;
            mCamera.addCallbackBuffer(new byte[size]);
            mCamera.addCallbackBuffer(new byte[size]);
            mCamera.setPreviewCallbackWithBuffer(previewCallback);


            if (mSWCodec) {
                synchronized (lock) {
                    x264 = new X264Encoder();

//                ev.setBitrate(2000);
//                ev.setFramerate(25);

                    int bitrate;
                    if (previewSize.width >= 1920) {
                        bitrate = 3200;
                    } else if (previewSize.width >= 1280) {
                        bitrate = 1600;
                    } else if (previewSize.width >= 640) {
                        bitrate = 400;
                    } else {
                        bitrate = 300;
                    }
                    if (mDgree == 0) {
                        x264.create(previewSize.height, previewSize.width, 15, bitrate);
                    } else {
                        x264.create(previewSize.width, previewSize.height, 15, bitrate);
                    }
                    codecAvailable = true;
                }
            }

            Thread t = mConsumer;
            if (t != null) {
                mConsumer = null;
                t.interrupt();
                try {
                    t.join();
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }

            long millis = PreferenceManager.getDefaultSharedPreferences(mApplicationContext).getInt("record_interval", 300000);
            if (!mSWCodec && PreferenceManager.getDefaultSharedPreferences(mApplicationContext).getBoolean("key_enable_local_record", false)) {
                mMuxer = new EasyMuxer(new File(recordPath, new SimpleDateFormat("yyyy-MM-dd_HH:mm:ss").format(new Date())).toString(), millis);
            }
            mConsumer = new Consumer();
            mConsumer.start();

            if (!mSWCodec) {
                startMediaCodec();
            } else {
            }
            audioStream = new AudioStream(mEasyPusher, mMuxer);
            audioStream.startRecord();
        }
    }


    Camera.PreviewCallback previewCallback = new Camera.PreviewCallback() {

        @Override
        public void onPreviewFrame(byte[] data, Camera camera) {
            if (data == null || !codecAvailable || mConsumer == null) {
                mCamera.addCallbackBuffer(data);
                return;
            }
            Camera.Size previewSize = mCamera.getParameters().getPreviewSize();
            if (data.length != previewSize.width * previewSize.height * 3 / 2) {
                mCamera.addCallbackBuffer(data);
                return;
            }
            byte[] buffer = yuv_caches.poll();
            if (buffer == null || buffer.length != data.length) {
                buffer = new byte[data.length];
            }
            yuvs.offer(new TimedBuffer(data));
            mCamera.addCallbackBuffer(buffer);
        }

    };


    /**
     * 旋转YUV格式数据
     *
     * @param src    YUV数据
     * @param format 0，420P；1，420SP
     * @param width  宽度
     * @param height 高度
     * @param degree 旋转度数
     */
    private static void yuvRotate(byte[] src, int format, int width, int height, int degree) {
        int offset = 0;
        if (format == 0) {
            JNIUtil.rotateMatrix(src, offset, width, height, degree);
            offset += (width * height);
            JNIUtil.rotateMatrix(src, offset, width / 2, height / 2, degree);
            offset += width * height / 4;
            JNIUtil.rotateMatrix(src, offset, width / 2, height / 2, degree);
        } else if (format == 1) {
            JNIUtil.rotateMatrix(src, offset, width, height, degree);
            offset += width * height;
            JNIUtil.rotateShortMatrix(src, offset, width / 2, height / 2, degree);
        }
    }

    /**
     * 停止预览
     */
    public synchronized void stopPreview() {
        Thread t = mConsumer;

        if (t != null) {
            mConsumer = null;
            t.interrupt();
            try {
                t.join();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        if (mCamera != null) {
            mCamera.stopPreview();
            mCamera.setPreviewCallbackWithBuffer(null);
        }
        synchronized (lock) {
            if (x264 != null) {
                x264.close();
                x264 = null;
                codecAvailable = false;
            }
        }

        if (audioStream != null) {
            audioStream.stop();
        }
        if (mMediaCodec != null) {
            stopMediaCodec();
        }

        if (mMuxer != null) {
            mMuxer.release();
            mMuxer = null;
        }
    }

    public Camera getCamera() {
        return mCamera;
    }


    /**
     * 切换前后摄像头
     */
    public void switchCamera() {
        int cameraCount = 0;
        if (isCameraBack) {
            isCameraBack = false;
        } else {
            isCameraBack = true;
        }
        Camera.CameraInfo cameraInfo = new Camera.CameraInfo();
        cameraCount = Camera.getNumberOfCameras();//得到摄像头的个数
        for (int i = 0; i < cameraCount; i++) {
            Camera.getCameraInfo(i, cameraInfo);//得到每一个摄像头的信息
            if (mCameraId == Camera.CameraInfo.CAMERA_FACING_FRONT) {
                //现在是后置，变更为前置
                if (cameraInfo.facing == Camera.CameraInfo.CAMERA_FACING_FRONT) {//代表摄像头的方位，CAMERA_FACING_FRONT前置      CAMERA_FACING_BACK后置
                    mCamera.stopPreview();//停掉原来摄像头的预览
                    mCamera.release();//释放资源
                    mCamera = null;//取消原来摄像头
                    mCameraId = Camera.CameraInfo.CAMERA_FACING_BACK;
                    createCamera();
                    startPreview();
                    break;
                }
            } else {
                //现在是前置， 变更为后置
                if (cameraInfo.facing == Camera.CameraInfo.CAMERA_FACING_BACK) {//代表摄像头的方位，CAMERA_FACING_FRONT前置      CAMERA_FACING_BACK后置
                    mCamera.stopPreview();//停掉原来摄像头的预览
                    mCamera.release();//释放资源
                    mCamera = null;//取消原来摄像头
                    mCameraId = Camera.CameraInfo.CAMERA_FACING_FRONT;
                    createCamera();
                    startPreview();
                    break;
                }
            }
        }
    }

    private String recordPath = Environment.getExternalStorageDirectory().getPath();

    public void setRecordPath(String recordPath) {
        this.recordPath = recordPath;
    }

    /**
     * 销毁Camera
     */
    public synchronized void destroyCamera() {
        if (mCamera != null) {
            mCamera.stopPreview();
            try {
                mCamera.release();
            } catch (Exception e) {

            }
            mCamera = null;
        }
    }

    /**
     * 初始化编码器
     */
    private void startMediaCodec() {
            /*
        SD (Low quality) SD (High quality) HD 720p
1 HD 1080p
1
Video resolution 320 x 240 px 720 x 480 px 1280 x 720 px 1920 x 1080 px
Video frame rate 20 fps 30 fps 30 fps 30 fps
Video bitrate 384 Kbps 2 Mbps 4 Mbps 10 Mbps
        */
        framerate = 25;
        if (width == 640 || height == 640) {
            bitrate = 2000000;
        } else if (width == 1280 || height == 1280) {
            bitrate = 4000000;
        } else {
            bitrate = 2 * width * height;
        }
        EncoderDebugger debugger = EncoderDebugger.debug(mApplicationContext, width, height);
        mConvertor = debugger.getNV21Convertor();
        try {
            mMediaCodec = MediaCodec.createByCodecName(debugger.getEncoderName());
            MediaFormat mediaFormat;
            if (mDgree == 0) {
                mediaFormat = MediaFormat.createVideoFormat("video/avc", height, width);
            } else {
                mediaFormat = MediaFormat.createVideoFormat("video/avc", width, height);
            }
            mediaFormat.setInteger(MediaFormat.KEY_BIT_RATE, bitrate);
            mediaFormat.setInteger(MediaFormat.KEY_FRAME_RATE, framerate);
            mediaFormat.setInteger(MediaFormat.KEY_COLOR_FORMAT, debugger.getEncoderColorFormat());
            mediaFormat.setInteger(MediaFormat.KEY_I_FRAME_INTERVAL, 1);
            mMediaCodec.configure(mediaFormat, null, null, MediaCodec.CONFIGURE_FLAG_ENCODE);
            mMediaCodec.start();
            codecAvailable = true;
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    /**
     * 停止编码并释放编码资源占用
     */
    private void stopMediaCodec() {
        if (mMediaCodec != null) {
            codecAvailable = false;
            mMediaCodec.stop();
            mMediaCodec.release();
            mMediaCodec = null;
        }
    }

    public boolean isStreaming() {
        return pushStream;
    }


    public void stopStream() {
        mEasyPusher.stop();
        pushStream = false;
    }

    public void destroyStream() {
        pushStream = false;
        if (pushThread != null) {
            pushThread.interrupt();
        }
        destroyCamera();
        stopMediaCodec();
        mEasyPusher.stop();
    }

    public void setSurfaceHolder(SurfaceHolder holder) {
        mSurfaceHolderRef = new WeakReference<SurfaceHolder>(holder);
    }
}
