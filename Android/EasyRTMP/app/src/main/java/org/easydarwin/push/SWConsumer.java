package org.easydarwin.push;

import android.content.Context;
import android.graphics.ImageFormat;
import android.util.Log;

import org.easydarwin.muxer.EasyMuxer;
import org.easydarwin.sw.JNIUtil;
import org.easydarwin.sw.X264Encoder;

import java.util.concurrent.ArrayBlockingQueue;

/**
 * Created by apple on 2017/5/13.
 */

public class SWConsumer extends Thread implements VideoConsumer {
    private static final String TAG = "SWConsumer";
    private int mHeight;
    private int mWidth;
    private X264Encoder x264;
    private final Pusher mPusher;
    private volatile boolean mVideoStarted;
    public SWConsumer(Context context, Pusher pusher){
        mPusher = pusher;
    }
    @Override
    public void onVideoStart(int width, int height) {
        this.mWidth = width;
        this.mHeight = height;

        x264 = new X264Encoder();
        int bitrate = (int) (mWidth*mHeight*20*2*0.07f);
        x264.create(width, height, 20, bitrate/500);
        mVideoStarted = true;
        start();
    }


    class TimedBuffer {
        byte[] buffer;
        long time;

        public TimedBuffer(byte[] data) {
            buffer = data;
            time = System.currentTimeMillis();
        }
    }

    private ArrayBlockingQueue<TimedBuffer> yuvs = new ArrayBlockingQueue<TimedBuffer>(2);
    private ArrayBlockingQueue<byte[]> yuv_caches = new ArrayBlockingQueue<byte[]>(10);

    @Override
    public void run(){

        byte[]h264 = new byte[mWidth*mHeight*3/2];
        byte[] keyFrm = new byte[1];
        int []outLen = new int[1];
        do {
            try {
                int r = 0;
                TimedBuffer tb = yuvs.take();
                byte[] data = tb.buffer;
                long begin = System.currentTimeMillis();
                r = x264.encode(data, 0, h264, 0, outLen, keyFrm);
                if (r > 0) {
                    Log.i(TAG, String.format("encode spend:%d ms. keyFrm:%d", System.currentTimeMillis() - begin, keyFrm[0]));
//                                newBuf = new byte[outLen[0]];
//                                System.arraycopy(h264, 0, newBuf, 0, newBuf.length);
                }
                keyFrm[0] = 0;
                yuv_caches.offer(data);
                mPusher.push(h264, 0, outLen[0], tb.time, 1);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }while (mVideoStarted);
    }


    final int millisPerframe = 1000/20;
    long lastPush = 0;
    @Override
    public int onVideo(byte[] data, int format) {
        try {
            if (lastPush == 0) {
                lastPush = System.currentTimeMillis();
            }
            long time = System.currentTimeMillis() - lastPush;
            if (time >= 0) {
                time = millisPerframe - time;
                if (time > 0) Thread.sleep(time / 2);
            }
            byte[] buffer = yuv_caches.poll();
            if (buffer == null || buffer.length != data.length) {
                buffer = new byte[data.length];
            }
            System.arraycopy(data, 0, buffer, 0, data.length);
            yuvs.offer(new TimedBuffer(buffer));
            if (time > 0) Thread.sleep(time / 2);
            lastPush = System.currentTimeMillis();
        }catch (InterruptedException ex){
            ex.printStackTrace();
        }
        return 0;
    }

    @Override
    public void onVideoStop() {
        do {
            mVideoStarted = false;
            try {
                interrupt();
                join();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }while (isAlive());
        if (x264 != null) {
            x264.close();
        }
        x264 = null;
    }

    @Override
    public void setMuxer(EasyMuxer muxer) {

    }
}
