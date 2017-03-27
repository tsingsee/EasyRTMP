/*
	Copyright (c) 2012-2017 EasyDarwin.ORG.  All rights reserved.
	Github: https://github.com/EasyDarwin
	WEChat: EasyDarwin
	Website: http://www.easydarwin.org
*/

package org.easydarwin.easyrtmp.activity;

import android.os.Bundle;
import android.preference.PreferenceManager;
import android.support.v7.app.AppCompatActivity;
import android.text.TextUtils;
import android.view.View;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.CompoundButton;
import android.widget.EditText;
import android.widget.Toast;

import org.easydarwin.easyrtmp.config.Config;
import org.easydarwin.easyrtmp.R;

public class SettingActivity extends AppCompatActivity {

    private static final boolean TEST_ = true;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_setting);
        final EditText txtUrl = (EditText) findViewById(R.id.edt_url);

        String url = EasyApplication.getEasyApplication().getUrl();

        txtUrl.setText(url);

        Button btnSave = (Button) findViewById(R.id.btn_save);
        btnSave.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                String urlValue = txtUrl.getText().toString();
                if (TextUtils.isEmpty(urlValue)) {
                    urlValue = Config.DEFAULT_SERVER_URL;
                }

                EasyApplication.getEasyApplication().saveStringIntoPref(Config.SERVER_URL, urlValue);
                finish();
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
    }

    private void showToast(String message) {
        Toast.makeText(this, message, Toast.LENGTH_LONG).show();
    }



}
