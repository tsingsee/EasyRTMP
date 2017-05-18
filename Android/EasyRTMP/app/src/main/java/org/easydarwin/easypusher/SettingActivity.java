/*
	Copyright (c) 2013-2016 EasyDarwin.ORG.  All rights reserved.
	Github: https://github.com/EasyDarwin
	WEChat: EasyDarwin
	Website: http://www.easydarwin.org
*/

package org.easydarwin.easypusher;

import android.content.DialogInterface;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.media.audiofx.PresetReverb;
import android.media.projection.MediaProjectionManager;
import android.os.Build;
import android.preference.PreferenceManager;
import android.support.v7.app.AlertDialog;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.text.TextUtils;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.CompoundButton;
import android.widget.EditText;
import android.widget.NumberPicker;
import android.widget.TextView;
import android.widget.Toast;

import org.easydarwin.config.Config;
import org.easydarwin.push.EasyPusher;
import org.easydarwin.push.MediaStream;

public class SettingActivity extends AppCompatActivity {

    private static final boolean TEST_ = true;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_setting);
        final EditText txtIp = (EditText) findViewById(R.id.edt_server_address);
        final EditText txtPort = (EditText) findViewById(R.id.edt_server_port);
        final EditText txtId = (EditText) findViewById(R.id.edt_stream_id);
        final View rtspGroup = findViewById(R.id.rtsp_group);
        final EditText rtmpUrl = (EditText) findViewById(R.id.rtmp_url);
        if (BuildConfig.FLAVOR.equals("rtmp")) {
            rtspGroup.setVisibility(View.GONE);
            rtmpUrl.setVisibility(View.VISIBLE);
        }else{
            rtspGroup.setVisibility(View.VISIBLE);
            rtmpUrl.setVisibility(View.GONE);
        }
        String ip = EasyApplication.getEasyApplication().getIp();
        String port = EasyApplication.getEasyApplication().getPort();
        String id = EasyApplication.getEasyApplication().getId();

        txtIp.setText(ip);
        txtPort.setText(port);
        txtId.setText(id);

        rtmpUrl.setText(EasyApplication.getEasyApplication().getUrl());
        Button btnSave = (Button) findViewById(R.id.btn_save);
        btnSave.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                String ipValue = txtIp.getText().toString();
                String portValue = txtPort.getText().toString();
                String idValue = txtId.getText().toString();
                String urlValue = rtmpUrl.getText().toString();

                if (TextUtils.isEmpty(ipValue)) {
                    ipValue = Config.DEFAULT_SERVER_IP;
                }

                if (TextUtils.isEmpty(portValue)) {
                    portValue = Config.DEFAULT_SERVER_PORT;
                }

                if (TextUtils.isEmpty(idValue)) {
                    idValue = Config.DEFAULT_STREAM_ID;
                }

                if (TextUtils.isEmpty(urlValue)) {
                    urlValue = Config.DEFAULT_SERVER_URL;
                }

                EasyApplication.getEasyApplication().saveStringIntoPref(Config.SERVER_IP, ipValue);
                EasyApplication.getEasyApplication().saveStringIntoPref(Config.SERVER_PORT, portValue);
                EasyApplication.getEasyApplication().saveStringIntoPref(Config.STREAM_ID, idValue);
                EasyApplication.getEasyApplication().saveStringIntoPref(Config.SERVER_URL, urlValue);
                finish();
            }
        });

        CheckBox sendAudioOnly = (CheckBox) findViewById(R.id.enable_send_audio_only);
        sendAudioOnly.setChecked(PreferenceManager.getDefaultSharedPreferences(this).getBoolean("key_enable_send_audio_only", false));
        sendAudioOnly.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                PreferenceManager.getDefaultSharedPreferences(SettingActivity.this).edit().putBoolean("key_enable_send_audio_only", isChecked).apply();
            }
        });

        CheckBox backgroundPushing = (CheckBox) findViewById(R.id.enable_background_camera_pushing);
        backgroundPushing.setChecked(PreferenceManager.getDefaultSharedPreferences(this).getBoolean("key_enable_background_camera", true));

        backgroundPushing.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                PreferenceManager.getDefaultSharedPreferences(SettingActivity.this).edit().putBoolean("key_enable_background_camera", isChecked).apply();
            }
        });


        CheckBox x264enc = (CheckBox) findViewById(R.id.use_x264_encode);
        x264enc.setChecked(PreferenceManager.getDefaultSharedPreferences(this).getBoolean("key-sw-codec", MediaStream.useSWCodec()));

        x264enc.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                PreferenceManager.getDefaultSharedPreferences(SettingActivity.this).edit().putBoolean("key-sw-codec", isChecked).apply();
            }
        });


        CheckBox enable_local_record = (CheckBox) findViewById(R.id.enable_local_record);
        enable_local_record.setChecked(PreferenceManager.getDefaultSharedPreferences(this).getBoolean("key_enable_local_record", false));

        enable_local_record.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                PreferenceManager.getDefaultSharedPreferences(SettingActivity.this).edit().putBoolean("key_enable_local_record", isChecked).apply();
            }
        });

        TextView versionCode = (TextView) findViewById(R.id.txt_version);
        try {
            versionCode.setText("版本:" + getPackageManager().getPackageInfo(getPackageName(), 0).versionName);
        } catch (PackageManager.NameNotFoundException e) {
            e.printStackTrace();
        }


        CheckBox enable_video_overlay = (CheckBox) findViewById(R.id.enable_video_overlay);
        enable_video_overlay.setChecked(PreferenceManager.getDefaultSharedPreferences(this).getBoolean("key_enable_video_overlay", false));

        enable_video_overlay.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                PreferenceManager.getDefaultSharedPreferences(SettingActivity.this).edit().putBoolean("key_enable_video_overlay", isChecked).apply();
            }
        });
    }

    private void showToast(String message) {
        Toast.makeText(this, message, Toast.LENGTH_LONG).show();
    }

    public void onOpenLocalRecord(View view) {
        startActivity(new Intent(this, MediaFilesActivity.class));
    }

    public void onRecordFileMillis(View view) {

        View contentView = getLayoutInflater().inflate(R.layout.record_file_millis_dlg, null, false);
        final NumberPicker np = (NumberPicker) contentView.findViewById(R.id.record_file_millis_picker);
        np.setMaxValue(600);
        np.setMinValue(10);

        int record_interval = PreferenceManager.getDefaultSharedPreferences(SettingActivity.this).getInt("record_interval", 300000);
        np.setValue(record_interval/1000);
        new AlertDialog.Builder(this).setView(contentView).setPositiveButton(android.R.string.ok, new DialogInterface.OnClickListener() {
            @Override
            public void onClick(DialogInterface dialogInterface, int i) {
                PreferenceManager.getDefaultSharedPreferences(SettingActivity.this).edit().putInt("record_interval", np.getValue() * 1000).apply();
            }
        }).setNegativeButton(android.R.string.cancel, null).show();
    }
}
