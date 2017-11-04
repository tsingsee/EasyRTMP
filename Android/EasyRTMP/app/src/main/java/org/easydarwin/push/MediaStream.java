package org.easydarwin.push;

import android.content.Context;
import android.content.Intent;
import android.graphics.ImageFormat;
import android.graphics.SurfaceTexture;
import android.hardware.Camera;
import android.media.MediaCodec;
import android.media.MediaFormat;
import android.os.Build;
import android.os.Bundle;
import android.os.Environment;
import android.os.Handler;
import android.os.HandlerThread;
import android.os.Message;
import android.os.Process;
import android.preference.PreferenceManager;
import android.support.annotation.Nullable;
import android.util.Log;
import android.view.SurfaceHolder;

import org.easydarwin.audio.AudioStream;
import org.easydarwin.bus.SupportResolution;
import org.easydarwin.easypusher.BackgroundCameraService;
import org.easydarwin.easypusher.BuildConfig;
import org.easydarwin.easypusher.EasyApplication;
import org.easydarwin.easyrtmp.push.EasyRTMP;
import org.easydarwin.hw.EncoderDebugger;
import org.easydarwin.hw.NV21Convertor;
import org.easydarwin.muxer.EasyMuxer;
import org.easydarwin.sw.JNIUtil;
import org.easydarwin.sw.TxtOverlay;
import org.easydarwin.sw.X264Encoder;
import org.easydarwin.util.Util;

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

import dagger.Module;
import dagger.Provides;

import static org.easydarwin.easypusher.EasyApplication.BUS;

@Module
public class MediaStream {
    private static final boolean VERBOSE = BuildConfig.DEBUG;
    private static final int SWITCH_CAMERA = 11;
    private final boolean enanleVideo;
    Pusher mEasyPusher;
    static final String TAG = "EasyPusher";
    int width = 640, height = 480;
    int framerate, bitrate;
    int mCameraId = Camera.CameraInfo.CAMERA_FACING_BACK;
    MediaCodec mMediaCodec;
    WeakReference<SurfaceTexture> mSurfaceHolderRef;
    Camera mCamera;
    NV21Convertor mConvertor;
    boolean pushStream = false;//是否要推送数据
    AudioStream audioStream;
    private boolean isCameraBack = true;
    private int mDgree;
    private Context mApplicationContext;
    private boolean mSWCodec;
    private VideoConsumer mVC;
    private TxtOverlay overlay;
    private EasyMuxer mMuxer;
    private final HandlerThread mCameraThread;
    private final Handler mCameraHandler;
    private EncoderDebugger debugger;
    private int previewFormat;

    public MediaStream(Context context, SurfaceTexture texture) {
        this(context, texture, true);
    }

    public MediaStream(Context context, SurfaceTexture texture, boolean enableVideo) {
        mApplicationContext = context;
        mSurfaceHolderRef = new WeakReference(texture);
        if (EasyApplication.isRTMP())
            mEasyPusher = new EasyRTMP();
        else mEasyPusher = new EasyPusher();
        mCameraThread = new HandlerThread("CAMERA"){
            public void run(){
                try{
                    super.run();
                } catch (Throwable e) {
                    Intent intent = new Intent(mApplicationContext, BackgroundCameraService.class);
                    mApplicationContext.stopService(intent);
                } finally {
                    stopStream();
                    stopPreview();
                    destroyCamera();
                }
            }
        };
        mCameraThread.start();
        mCameraHandler = new Handler(mCameraThread.getLooper()) {
            @Override
            public void handleMessage(Message msg) {
                super.handleMessage(msg);
                if (msg.what == SWITCH_CAMERA) {
                    switchCameraTask.run();
                }
            }
        };
        this.enanleVideo = enableVideo;

        if (enableVideo)
            previewCallback = new Camera.PreviewCallback() {

                @Override
                public void onPreviewFrame(byte[] data, Camera camera) {
                    if (mDgree == 0) {
                        Camera.CameraInfo camInfo = new Camera.CameraInfo();
                        Camera.getCameraInfo(mCameraId, camInfo);
                        int cameraRotationOffset = camInfo.orientation;

                        if (cameraRotationOffset % 180 != 0) {
                            if (previewFormat == ImageFormat.YV12) {
                                yuvRotate(data, 0, width, height, cameraRotationOffset);
                            } else {
                                yuvRotate(data, 1, width, height, cameraRotationOffset);
                            }
                        }
                        save2file(data, String.format("/sdcard/yuv_%d_%d.yuv", height, width));
                    }
                    if (PreferenceManager.getDefaultSharedPreferences(mApplicationContext).getBoolean("key_enable_video_overlay", false)) {
                        String txt = String.format("drawtext=fontfile=" + mApplicationContext.getFileStreamPath("SIMYOU.ttf") + ": text='%s%s':x=(w-text_w)/2:y=H-60 :fontcolor=white :box=1:boxcolor=0x00000000@0.3", "EasyPusher", new SimpleDateFormat("yyyy-MM-ddHHmmss").format(new Date()));
                        txt = "EasyPusher " + new SimpleDateFormat("yy-MM-dd HH:mm:ss SSS").format(new Date());
                        overlay.overlay(data, txt);
                    }
                    mVC.onVideo(data, previewFormat);
                    mCamera.addCallbackBuffer(data);
                }

            };
    }

    public void startStream(String url, InitCallback callback) {
        if (PreferenceManager.getDefaultSharedPreferences(EasyApplication.getEasyApplication()).getBoolean(EasyApplication.KEY_ENABLE_VIDEO, true))
            mEasyPusher.initPush(url, mApplicationContext, callback);
        else
            mEasyPusher.initPush(url, mApplicationContext, callback, ~0);
        pushStream = true;
    }

    public void startStream(String ip, String port, String id, InitCallback callback) {
        mEasyPusher.initPush(ip, port, String.format("%s.sdp", id), mApplicationContext, callback);
        pushStream = true;
    }

    public void setDgree(int dgree) {
        mDgree = dgree;
    }

    /**
     * 更新分辨率
     */
    public void updateResolution(final int w, final int h) {
        if (mCamera == null) return;
        stopPreview();
        destroyCamera();
        mCameraHandler.post(new Runnable() {
            @Override
            public void run() {
                width = w;
                height = h;
            }
        });
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

    public void createCamera() {

        if (Thread.currentThread() != mCameraThread) {
            mCameraHandler.post(new Runnable() {
                @Override
                public void run() {
                    Process.setThreadPriority(Process.THREAD_PRIORITY_DEFAULT);
                    createCamera();
                }
            });
            return;
        }
        if (!enanleVideo) {
            return;
        }
        try {
            mSWCodec = PreferenceManager.getDefaultSharedPreferences(mApplicationContext).getBoolean("key-sw-codec", false);
            mCamera = Camera.open(mCameraId);
            mCamera.setErrorCallback(new Camera.ErrorCallback() {
                @Override
                public void onError(int i, Camera camera) {
                    throw new IllegalStateException("Camera Error:" + i);
                }
            });
            Log.i(TAG, "open Camera");

            Camera.Parameters parameters = mCamera.getParameters();
            int[] max = determineMaximumSupportedFramerate(parameters);
            Camera.CameraInfo camInfo = new Camera.CameraInfo();
            Camera.getCameraInfo(mCameraId, camInfo);
            int cameraRotationOffset = camInfo.orientation;
            if (mCameraId == Camera.CameraInfo.CAMERA_FACING_FRONT)
                cameraRotationOffset += 180;
            int rotate = (360 + cameraRotationOffset - mDgree) % 360;
            parameters.setRotation(rotate);
            parameters.setRecordingHint(true);

            Log.i(TAG, "setRecordingHint");
            debugger = EncoderDebugger.debug(mApplicationContext, width, height);

            previewFormat = mSWCodec ? ImageFormat.YV12 : debugger.getNV21Convertor().getPlanar() ? ImageFormat.YV12 : ImageFormat.NV21;
//            previewFormat = ImageFormat.NV21;
            parameters.setPreviewFormat(previewFormat);
//            List<Camera.Size> sizes = parameters.getSupportedPreviewSizes();
            parameters.setPreviewSize(width, height);
//            parameters.setPreviewFpsRange(max[0], max[1]);
            parameters.setPreviewFrameRate(20);

//            int maxExposureCompensation = parameters.getMaxExposureCompensation();
//            parameters.setExposureCompensation(3);
//
//            if(parameters.isAutoExposureLockSupported()) {
//                parameters.setAutoExposureLock(false);
//            }

//            parameters.setWhiteBalance(Camera.Parameters.WHITE_BALANCE_AUTO);
//            parameters.setFlashMode(Camera.Parameters.FLASH_MODE_AUTO);
//            parameters.setSceneMode(Camera.Parameters.SCENE_MODE_AUTO);
//            parameters.setFocusMode(Camera.Parameters.FOCUS_MODE_CONTINUOUS_VIDEO);
//            mCamera.setFaceDetectionListener(new );

//            if (parameters.isAutoWhiteBalanceLockSupported()){
//                parameters.setAutoExposureLock(false);
//            }

            mCamera.setParameters(parameters);
            Log.i(TAG, "setParameters");
            int displayRotation;
            displayRotation = (cameraRotationOffset - mDgree + 360) % 360;
            mCamera.setDisplayOrientation(displayRotation);

            Log.i(TAG, "setDisplayOrientation");
        } catch (Exception e) {
            StringWriter sw = new StringWriter();
            PrintWriter pw = new PrintWriter(sw);
            e.printStackTrace(pw);
            String stack = sw.toString();
            destroyCamera();
            e.printStackTrace();
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

    public synchronized void startRecord() {
        if (Thread.currentThread() != mCameraThread) {
            mCameraHandler.post(new Runnable() {
                @Override
                public void run() {
                    startRecord();
                }
            });
            return;
        }
        long millis = PreferenceManager.getDefaultSharedPreferences(mApplicationContext).getInt("record_interval", 300000);
        mMuxer = new EasyMuxer(new File(recordPath, new SimpleDateFormat("yyyy_MM_dd_HH_mm_ss").format(new Date())).toString(), millis);
        if (mVC == null || audioStream == null) {
            throw new IllegalStateException("you need to start preview before startRecord!");
        }
        mVC.setMuxer(mMuxer);
        audioStream.setMuxer(mMuxer);
    }


    public synchronized void stopRecord() {
        if (Thread.currentThread() != mCameraThread) {
            mCameraHandler.post(new Runnable() {
                @Override
                public void run() {
                    stopRecord();
                }
            });
            return;
        }
        if (mVC == null || audioStream == null) {
//            nothing
        } else {
            mVC.setMuxer(null);
            audioStream.setMuxer(null);
        }
        if (mMuxer != null) mMuxer.release();
        mMuxer = null;
    }

    /**
     * 开启预览
     */
    public synchronized void startPreview() {
        if (Thread.currentThread() != mCameraThread) {
            mCameraHandler.post(new Runnable() {
                @Override
                public void run() {
                    startPreview();
                }
            });
            return;
        }
        if (mCamera != null) {
            int previewFormat = mCamera.getParameters().getPreviewFormat();
            Camera.Size previewSize = mCamera.getParameters().getPreviewSize();
            int size = previewSize.width * previewSize.height * ImageFormat.getBitsPerPixel(previewFormat) / 8;
            width = previewSize.width;
            height = previewSize.height;
            mCamera.addCallbackBuffer(new byte[size]);
            mCamera.addCallbackBuffer(new byte[size]);
            mCamera.setPreviewCallbackWithBuffer(previewCallback);
            Log.i(TAG, "setPreviewCallbackWithBuffer");

            if (Util.getSupportResolution(mApplicationContext).size() == 0) {
                StringBuilder stringBuilder = new StringBuilder();
                List<Camera.Size> supportedPreviewSizes = mCamera.getParameters().getSupportedPreviewSizes();
                for (Camera.Size str : supportedPreviewSizes) {
                    stringBuilder.append(str.width + "x" + str.height).append(";");
                }
                Util.saveSupportResolution(mApplicationContext, stringBuilder.toString());
            }
            BUS.post(new SupportResolution());

            try {
                SurfaceTexture holder = mSurfaceHolderRef.get();
                if (holder != null) {
                    mCamera.setPreviewTexture(holder);
                    Log.i(TAG, "setPreviewTexture");
                }
            } catch (IOException e) {
                e.printStackTrace();
            }


            mCamera.startPreview();
            Log.i(TAG, "startPreview");
            try {
                mCamera.autoFocus(null);
            } catch (Exception e) {
                //忽略异常
                Log.i(TAG, "auto foucus fail");
            }

            boolean rotate = false;
            if (mDgree == 0) {
                Camera.CameraInfo camInfo = new Camera.CameraInfo();
                Camera.getCameraInfo(mCameraId, camInfo);
                int cameraRotationOffset = camInfo.orientation;
                if (cameraRotationOffset == 90) {
                    rotate = true;
                } else if (cameraRotationOffset == 270) {
                    rotate = true;
                }
            }

            overlay = new TxtOverlay(mApplicationContext);
            try {
                if (mSWCodec) {
                    mVC = new SWConsumer(mApplicationContext, mEasyPusher);
                } else {
                    mVC = new HWConsumer(mApplicationContext, mEasyPusher);
                }
                if (!rotate) {
                    mVC.onVideoStart(previewSize.width, previewSize.height);
                    overlay.init(previewSize.width, previewSize.height, mApplicationContext.getFileStreamPath("SIMYOU.ttf").getPath());
                } else {
                    mVC.onVideoStart(previewSize.height, previewSize.width);
                    overlay.init(previewSize.height, previewSize.width, mApplicationContext.getFileStreamPath("SIMYOU.ttf").getPath());
                }
            } catch (IOException ex) {
                ex.printStackTrace();
            } catch (IllegalArgumentException ex) {
                ex.printStackTrace();
            }
        }
        audioStream = new AudioStream(mEasyPusher);
        audioStream.startRecord();
    }

    @Provides
    @Nullable
    public EasyMuxer getMuxer() {
        return mMuxer;
    }


    Camera.PreviewCallback previewCallback;


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
        if (Thread.currentThread() != mCameraThread) {
            mCameraHandler.post(new Runnable() {
                @Override
                public void run() {
                    stopPreview();
                }
            });
            return;
        }
        if (mCamera != null) {
            mCamera.stopPreview();
            mCamera.setPreviewCallbackWithBuffer(null);
            Log.i(TAG,"StopPreview");
        }
        if (audioStream != null) {
            audioStream.stop();
            Log.i(TAG,"Stop AudioStream");
            audioStream = null;
        }
        if (mVC != null) {
            mVC.onVideoStop();

            Log.i(TAG,"Stop VC");
        }
        if (overlay != null)
            overlay.release();

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
        if (mCameraHandler.hasMessages(SWITCH_CAMERA)) return;
        mCameraHandler.sendEmptyMessage(SWITCH_CAMERA);
    }

    private Runnable switchCameraTask = new Runnable() {
        @Override
        public void run() {
            int cameraCount = 0;
            if (isCameraBack) {
                isCameraBack = false;
            } else {
                isCameraBack = true;
            }
            if (!enanleVideo) return;
            Camera.CameraInfo cameraInfo = new Camera.CameraInfo();
            cameraCount = Camera.getNumberOfCameras();//得到摄像头的个数
            for (int i = 0; i < cameraCount; i++) {
                Camera.getCameraInfo(i, cameraInfo);//得到每一个摄像头的信息
                stopPreview();
                destroyCamera();
                if (mCameraId == Camera.CameraInfo.CAMERA_FACING_FRONT) {
                    //现在是后置，变更为前置
                    if (cameraInfo.facing == Camera.CameraInfo.CAMERA_FACING_FRONT) {//代表摄像头的方位，CAMERA_FACING_FRONT前置      CAMERA_FACING_BACK后置
                        mCameraId = Camera.CameraInfo.CAMERA_FACING_BACK;
                        createCamera();
                        startPreview();
                        break;
                    }
                } else {
                    //现在是前置， 变更为后置
                    if (cameraInfo.facing == Camera.CameraInfo.CAMERA_FACING_BACK) {//代表摄像头的方位，CAMERA_FACING_FRONT前置      CAMERA_FACING_BACK后置
                        mCameraId = Camera.CameraInfo.CAMERA_FACING_FRONT;
                        createCamera();
                        startPreview();
                        break;
                    }
                }
            }
        }
    };

    private String recordPath = Environment.getExternalStorageDirectory().getPath();

    public void setRecordPath(String recordPath) {
        this.recordPath = recordPath;
    }

    /**
     * 销毁Camera
     */
    public synchronized void destroyCamera() {

        if (Thread.currentThread() != mCameraThread) {
            mCameraHandler.post(new Runnable() {
                @Override
                public void run() {
                    destroyCamera();
                }
            });
            return;
        }
        if (mCamera != null) {
            mCamera.stopPreview();
            try {
                mCamera.release();
            } catch (Exception e) {
                e.printStackTrace();
            }
            Log.i(TAG, "release Camera");
            mCamera = null;
        }
        if (mMuxer != null) {
            mMuxer.release();
            mMuxer = null;
        }
    }

    public boolean isStreaming() {
        return pushStream;
    }


    public void stopStream() {
        mEasyPusher.stop();
        pushStream = false;
    }

    public void setSurfaceTexture(SurfaceTexture texture) {
        mSurfaceHolderRef = new WeakReference<SurfaceTexture>(texture);
    }

    public void release() {
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.JELLY_BEAN_MR2) {
            mCameraThread.quitSafely();
        } else {
            if (!mCameraHandler.post(new Runnable() {
                @Override
                public void run() {
                    mCameraThread.quit();
                }
            })) {
                mCameraThread.quit();
            }
        }
        try {
            mCameraThread.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }

    public boolean isRecording() {
        return mMuxer != null;
    }
}