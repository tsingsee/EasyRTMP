package org.easydarwin.easypusher;

import android.app.Notification;
import android.app.NotificationManager;
import android.app.Service;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.graphics.PixelFormat;
import android.graphics.SurfaceTexture;
import android.os.Binder;
import android.os.IBinder;
import android.support.v4.app.NotificationCompat;
import android.view.Gravity;
import android.view.TextureView;
import android.view.WindowManager;

import org.easydarwin.push.MediaStream;

public class BackgroundCameraService extends Service implements TextureView.SurfaceTextureListener {
    private static final int NOTIFICATION_ID = 1;

    private static final String TAG = BackgroundCameraService.class.getSimpleName();
    public static final String EXTRA_RR = "extra_rr";
    /**
     * 表示后台是否正在渲染
     */
    public static final String EXTRA_STREAMING = "extra_streaming";
    private TextureView mOutComeVideoView;
    private WindowManager mWindowManager;
    private BroadcastReceiver mReceiver = null;
    private MediaStream mMediaStream;


    // Binder given to clients
    private final IBinder mBinder = new LocalBinder();
    private SurfaceTexture mTexture;
    private boolean mPenddingStartPreview;

    @Override
    public void onSurfaceTextureAvailable(SurfaceTexture surface, int width, int height) {
        mTexture = surface;
        if (mPenddingStartPreview){
            mMediaStream.setSurfaceTexture(mTexture);
            mMediaStream.startPreview();
        }
    }

    @Override
    public void onSurfaceTextureSizeChanged(SurfaceTexture surface, int width, int height) {

    }

    @Override
    public boolean onSurfaceTextureDestroyed(SurfaceTexture surface) {
        mTexture = null;
        return true;
    }

    @Override
    public void onSurfaceTextureUpdated(SurfaceTexture surface) {

    }

    public MediaStream getMediaStream() {
        return mMediaStream;
    }

    public void setMediaStream(MediaStream ms) {
        mMediaStream = ms;
    }

    public void activePreview() {
        mMediaStream.stopPreview();
        if (mTexture != null){
            backGroundNotificate();
            mMediaStream.setSurfaceTexture(mTexture);
            mMediaStream.startPreview();
        }else{
            mPenddingStartPreview = true;
        }
    }

    /**
     * Class used for the client Binder.  Because we know this service always
     * runs in the same process as its clients, we don't need to deal with IPC.
     */
    public class LocalBinder extends Binder {

        public BackgroundCameraService getService() {
            return BackgroundCameraService.this;
        }
    }

    @Override
    public IBinder onBind(Intent intent) {
        return mBinder;
    }

    @Override
    public void onCreate() {
        super.onCreate();

        // Create new SurfaceView, set its size to 1x1, move it to the top left
        // corner and set this service as a callback
        mWindowManager = (WindowManager) this.getSystemService(Context.WINDOW_SERVICE);
        mOutComeVideoView = new TextureView(this);

        WindowManager.LayoutParams layoutParams = new WindowManager.LayoutParams(1, 1, WindowManager.LayoutParams.TYPE_SYSTEM_OVERLAY,
                WindowManager.LayoutParams.FLAG_WATCH_OUTSIDE_TOUCH, PixelFormat.TRANSLUCENT);
        layoutParams.gravity = Gravity.LEFT | Gravity.TOP;
        mWindowManager.addView(mOutComeVideoView, layoutParams);
        mOutComeVideoView.setSurfaceTextureListener(this);
    }


    @Override
    public int onStartCommand(Intent intent, int flags, int startId) {
        if (intent == null) {
            return START_NOT_STICKY;
        }

        NotificationManager manager = (NotificationManager) getSystemService(Context.NOTIFICATION_SERVICE);
        manager.cancel(NOTIFICATION_ID);

        return super.onStartCommand(intent, flags, startId);
    }

    public void backGroundNotificate()
    {
        NotificationCompat.Builder builder = new NotificationCompat.Builder(EasyApplication.getEasyApplication());
        builder.setSmallIcon(R.mipmap.ic_launcher);
        builder.setContentTitle("EasyRTMP");
        builder.setContentText("后台采集视频中");
        Notification notification = builder.build();
        NotificationManager manager = (NotificationManager) getSystemService(Context.NOTIFICATION_SERVICE);
        manager.notify(NOTIFICATION_ID, notification);
    }

    @Override
    public void onDestroy() {
        if (mOutComeVideoView != null) {
            if (mOutComeVideoView.getParent() != null) {
                mWindowManager.removeView(mOutComeVideoView);
            }
        }
        super.onDestroy();
    }
}
