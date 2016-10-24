/*
	Copyright (c) 2012-2016 EasyDarwin.ORG.  All rights reserved.
	Github: https://github.com/EasyDarwin
	WEChat: EasyDarwin
	Website: http://www.easydarwin.org
*/
package org.easydarwin.easyrtmp.activity;

import android.app.Application;
import android.content.SharedPreferences;
import android.hardware.Camera;
import android.preference.PreferenceManager;

import org.easydarwin.easyrtmp.config.Config;
import org.easydarwin.easyrtmp.push.MediaStream;
import org.easydarwin.easyrtmp.util.Util;

import java.util.List;

public class EasyApplication extends Application {

    private static EasyApplication mApplication;

    public static MediaStream sMS;

    @Override
    public void onCreate() {
        super.onCreate();
        mApplication = this;
        if (Util.getSupportResolution(this).size() == 0) {
            StringBuilder stringBuilder = new StringBuilder();
            Camera camera = Camera.open();
            List<Camera.Size> supportedPreviewSizes = camera.getParameters().getSupportedPreviewSizes();
            for (Camera.Size str : supportedPreviewSizes) {
                stringBuilder.append(str.width + "x" + str.height).append(";");
            }
            Util.saveSupportResolution(this, stringBuilder.toString());
            camera.release();
        }
    }

    public static EasyApplication getEasyApplication() {
        return mApplication;
    }

    public void saveStringIntoPref(String key, String value) {
        SharedPreferences sharedPreferences = PreferenceManager.getDefaultSharedPreferences(this);
        SharedPreferences.Editor editor = sharedPreferences.edit();
        editor.putString(key, value);
        editor.commit();
    }

    public String getUrl() {
        SharedPreferences sharedPreferences = PreferenceManager.getDefaultSharedPreferences(this);
        String ip = sharedPreferences.getString(Config.SERVER_URL, Config.DEFAULT_SERVER_URL);
        return ip;
    }
}
