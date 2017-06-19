/*
	Copyright (c) 2013-2016 EasyDarwin.ORG.  All rights reserved.
	Github: https://github.com/EasyDarwin
	WEChat: EasyDarwin
	Website: http://www.easydarwin.org
*/
package org.easydarwin.push;

import android.content.Context;
import android.provider.Settings;
import android.util.Log;

import org.easydarwin.bus.StreamStat;

import static org.easydarwin.easypusher.EasyApplication.BUS;

public class EasyPusher implements Pusher{
    /*
    *本Key为3个月临时授权License，如需商业使用，请邮件至support@easydarwin.org申请此产品的授权。
    */
    private static final String KEY = "6A36334A743536526D3430414645645A70726A7270666872615731305A584E30567778576F502B6C34456468646D6C754A6B4A68596D397A595541794D4445325257467A65555268636E6470626C526C5957316C59584E35";
    private static String TAG = "EasyPusher";

    static {
        System.loadLibrary("easypusher");
    }

    private long pPreviewTS;
    private long mTotal;
    private int mTotalFrms;

    public interface OnInitPusherCallback {
        public void onCallback(int code);

        static class CODE {
            public static final int EASY_ACTIVATE_INVALID_KEY = -1;       //无效Key
            public static final int EASY_ACTIVATE_TIME_ERR = -2;       //时间错误
            public static final int EASY_ACTIVATE_PROCESS_NAME_LEN_ERR = -3;       //进程名称长度不匹配
            public static final int EASY_ACTIVATE_PROCESS_NAME_ERR = -4;       //进程名称不匹配
            public static final int EASY_ACTIVATE_VALIDITY_PERIOD_ERR = -5;       //有效期校验不一致
            public static final int EASY_ACTIVATE_PLATFORM_ERR = -6;          //平台不匹配
            public static final int EASY_ACTIVATE_COMPANY_ID_LEN_ERR = -7;          //授权使用商不匹配
            public static final int EASY_ACTIVATE_SUCCESS = 0;        //激活成功
            public static final int EASY_PUSH_STATE_CONNECTING = 1;        //连接中
            public static final int EASY_PUSH_STATE_CONNECTED = 2;        //连接成功
            public static final int EASY_PUSH_STATE_CONNECT_FAILED = 3;        //连接失败
            public static final int EASY_PUSH_STATE_CONNECT_ABORT = 4;        //连接异常中断
            public static final int EASY_PUSH_STATE_PUSHING = 5;        //推流中
            public static final int EASY_PUSH_STATE_DISCONNECTED = 6;        //断开连接
            public static final int EASY_PUSH_STATE_ERROR = 7;
        }

    }

    private long mPusherObj = 0;

//    public native void setOnInitPusherCallback(OnInitPusherCallback callback);

    /**
     * 初始化
     *
     * @param serverIP   服务器IP
     * @param serverPort 服务端口
     * @param streamName 流名称
     * @param key        授权码
     */
    public native long init(String serverIP, String serverPort, String streamName, String key, Context context, OnInitPusherCallback callback);

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
        Log.i(TAG, "PusherStop");
        if (mPusherObj == 0) return;
        stopPush(mPusherObj);
        mPusherObj = 0;
    }

    @Override
    public synchronized void initPush(String serverIP, String serverPort, String streamName, Context context, final InitCallback callback) {
        Log.i(TAG, "PusherStart");
        String key = KEY;
        mPusherObj = init(serverIP, serverPort, streamName, key, context, new OnInitPusherCallback() {
            int code = Integer.MAX_VALUE;
            @Override
            public void onCallback(int code) {
                if (code != this.code) {
                    this.code = code;
                    if (callback != null) callback.onCallback(code);
                }
            }
        });
    }

    @Override
    public void initPush(String url, Context context, InitCallback callback) {
        throw new RuntimeException("not support");
    }

    @Override
    public void initPush(String url, Context context, InitCallback callback, int fps) {
        throw new RuntimeException("not support");
    }

    public synchronized void push(byte[] data, int offset, int length, long timestamp, int type) {
        if (mPusherObj == 0) return;
        mTotal += length;
        if (type == 1){
            mTotalFrms++;
        }
        long interval = System.currentTimeMillis() - pPreviewTS;
        if (interval >= 3000){
            long bps = mTotal * 1000 / (interval);
            long fps = mTotalFrms * 1000 / (interval);
            Log.i(TAG, String.format("bps:%d, fps:%d", fps, bps));
            pPreviewTS = System.currentTimeMillis();
            mTotal = 0;
            mTotalFrms = 0;

            BUS.post(new StreamStat((int)fps, (int)bps));
        }
        push(mPusherObj, data, offset, length, timestamp, type);
    }

    public synchronized void push(byte[] data, long timestamp, int type) {
        push( data, 0, data.length, timestamp, type);
    }
}

