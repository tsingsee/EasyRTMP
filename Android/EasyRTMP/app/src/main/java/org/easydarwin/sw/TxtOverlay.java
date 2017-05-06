package org.easydarwin.sw;

import android.content.Context;

/**
 * Created by John on 2017/2/23.
 */

public class TxtOverlay {

    static {

//        System.loadLibrary("avdevice-57");
//        System.loadLibrary("avcodec-57");
//        System.loadLibrary("swresample-2");
//        System.loadLibrary("avformat-57");
//        System.loadLibrary("swscale-4");
//        System.loadLibrary("avfilter-6");
//        System.loadLibrary("avutil-55");
//        System.loadLibrary("postproc-54");
        System.loadLibrary("TxtOverlay");
    }

    private final Context context;

    public TxtOverlay(Context context){
        this.context = context;
    }
    private long ctx;

    public void init(int width, int height,String fonts) {
        ctx = txtOverlayInit(width, height,fonts);
    }

    public void overlay(byte[] data,
                        String txt) {
//        txt = "drawtext=fontfile="+context.getFileStreamPath("SIMYOU.ttf")+": text='EasyPusher 2017':x=(w-text_w)/2:y=H-60 :fontcolor=white :box=1:boxcolor=0x00000000@0.3";
//        txt = "movie=/sdcard/qrcode.png [logo];[in][logo] "
//                + "overlay=" + 0 + ":" + 0
//                + " [out]";
//        if (ctx == 0) throw new RuntimeException("init should be called at first!");
        txtOverlay(ctx, data, txt);
    }

    public void release() {
        txtOverlayRelease(ctx);
    }


    private static native long txtOverlayInit(int width, int height, String fonts);

    private static native void txtOverlay(long ctx, byte[] data, String txt);

    private static native void txtOverlayRelease(long ctx);

}
