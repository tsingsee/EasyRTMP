/*
	Copyright (c) 2012-2017 EasyDarwin.ORG.  All rights reserved.
	Github: https://github.com/EasyDarwin
	WEChat: EasyDarwin
	Website: http://www.easydarwin.org
*/
package org.easydarwin.easyrtmp.push;

import android.content.Context;

import org.easydarwin.push.InitCallback;
import org.easydarwin.push.Pusher;

public class EasyRTMP implements Pusher {
    private static String TAG = "EasyRTMP";
    static {
        System.loadLibrary("easyrtmp");
    }

    public interface OnInitPusherCallback {
        public void onCallback(int code);

        static class CODE {
            public static final int EASY_ACTIVATE_INVALID_KEY               =   -1;       //无效Key
            public static final int EASY_ACTIVATE_TIME_ERR                  =   -2;       //时间错误
            public static final int EASY_ACTIVATE_PROCESS_NAME_LEN_ERR      =   -3;       //进程名称长度不匹配
            public static final int EASY_ACTIVATE_PROCESS_NAME_ERR          =   -4;       //进程名称不匹配
            public static final int EASY_ACTIVATE_VALIDITY_PERIOD_ERR       =   -5;       //有效期校验不一致
            public static final int EASY_ACTIVATE_PLATFORM_ERR		        =	-6;		  //平台不匹配
            public static final int EASY_ACTIVATE_COMPANY_ID_LEN_ERR        =	-7;		  //授权使用商不匹配
            public static final int EASY_ACTIVATE_SUCCESS                   =   0;        //激活成功
            public static final int EASY_RTMP_STATE_CONNECTING =   1;        //连接中
            public static final int EASY_RTMP_STATE_CONNECTED =   2;        //连接成功
            public static final int EASY_RTMP_STATE_CONNECT_FAILED =   3;        //连接失败
            public static final int EASY_RTMP_STATE_CONNECT_ABORT =   4;        //连接异常中断
            public static final int EASY_RTMP_STATE_PUSHING =   5;        //推流中
            public static final int EASY_RTMP_STATE_DISCONNECTED =   6;        //断开连接
            public static final int EASY_RTMP_STATE_ERROR =   7;
        }

    }

    private long mPusherObj = 0;

    /**
     * 初始化
     *
     * @param url       RTMP服务器地址
     * @param key        授权码
     */
    public native long init(String url, String key, Context context, OnInitPusherCallback callback);

    /**
     * 推送编码后的H264数据
     *
     * @param data      H264数据
     * @param timestamp 时间戳，毫秒
     */
    private native void push(long pusherObj, byte[] data, int offset, int length, long timestamp, int type);

    /**
     * 停止推送
     */
    private native void stopPush(long pusherObj);

    public synchronized void stop() {
        if (mPusherObj == 0) return;
        stopPush(mPusherObj);
        mPusherObj = 0;
    }

    @Override
    public void initPush(String serverIP, String serverPort, String streamName, Context context, InitCallback callback) {
        throw new RuntimeException("not support");
    }

    @Override
    public synchronized void initPush(final String url, final Context context, final InitCallback callback) {
        String key = "79397037795A36526D3430416E667059707756686B756876636D63755A57467A65575268636E64706269356C59584E35636E52746346634D5671442B6B75424859585A7062695A4359574A76633246414D6A41784E6B566863336C4559584A33615735555A5746745A57467A65513D3D";
        mPusherObj = init(url, key, context, new OnInitPusherCallback() {
            @Override
            public void onCallback(int code) {
                if (callback != null)callback.onCallback(code);
            }
        });
    }

    public void push(byte[] data, long timestamp, int type){
        push(data, 0, data.length, timestamp,type);
    }

    public synchronized void push(byte[] data, int offset, int length, long timestamp, int type){
        if (mPusherObj == 0) return;
        push(mPusherObj, data, offset, length, timestamp,type);
    }
}

