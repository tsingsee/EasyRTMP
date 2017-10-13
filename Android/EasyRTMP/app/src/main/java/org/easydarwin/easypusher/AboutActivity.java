package org.easydarwin.easypusher;

import android.databinding.DataBindingUtil;
import android.graphics.Color;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.text.SpannableString;
import android.text.Spanned;
import android.text.method.LinkMovementMethod;
import android.text.style.ForegroundColorSpan;
import android.text.style.URLSpan;

import org.easydarwin.easypusher.databinding.ActivityAboutBinding;

public class AboutActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        ActivityAboutBinding binding = DataBindingUtil.setContentView(this, R.layout.activity_about);
        if (!EasyApplication.isRTMP()) {
            binding.desc.setText("EasyPusher是EasyDarwin开源流媒体团队开发的一个推送流媒体音/视频流给开源流媒体服务器EasyDarwin的标准RTSP/RTP协议推送库，全平台支持(包括Windows/Linux(32 & 64)，ARM各平台，Android、IOS)，通过EasyPusher我们就可以避免接触到稍显复杂的RTSP/RTP/RTCP推送流程，只需要调用EasyPusher的几个API接口，就能轻松、稳定地把流媒体音视频数据推送给EasyDarwin服务器进行转发和分发，EasyPusher经过长时间的企业用户检验，稳定性非常高; 项目地址：");
            binding.desc.setMovementMethod(LinkMovementMethod.getInstance());
            SpannableString
                    spannableString = new SpannableString("https://github.com/EasyDarwin/EasyPusher");
            //设置下划线文字
            spannableString.setSpan(new URLSpan("https://github.com/EasyDarwin/EasyPusher"), 0, spannableString.length(), Spanned.SPAN_INCLUSIVE_EXCLUSIVE);

            //设置文字的前景色
            spannableString.setSpan(new ForegroundColorSpan(Color.RED), 0, spannableString.length(), Spanned.SPAN_INCLUSIVE_EXCLUSIVE);

            binding.desc.append(spannableString);


            binding.desc.append("\n播放端可以使用");


            spannableString = new SpannableString("EasyPlayer");
            //设置下划线文字
            spannableString.setSpan(new URLSpan("https://fir.im/EasyPlayer"), 0, spannableString.length(), Spanned.SPAN_INCLUSIVE_EXCLUSIVE);
            //设置文字的前景色
            spannableString.setSpan(new ForegroundColorSpan(Color.RED), 0, spannableString.length(), Spanned.SPAN_INCLUSIVE_EXCLUSIVE);
            binding.desc.append(spannableString);


            binding.desc.append("或者");


            spannableString = new SpannableString("EasyPlayerPro");
            //设置下划线文字
            spannableString.setSpan(new URLSpan("https://fir.im/EasyPlayerPro"), 0, spannableString.length(), Spanned.SPAN_INCLUSIVE_EXCLUSIVE);

            //设置文字的前景色
            spannableString.setSpan(new ForegroundColorSpan(Color.RED), 0, spannableString.length(), Spanned.SPAN_INCLUSIVE_EXCLUSIVE);
            binding.desc.append(spannableString);

            binding.desc.append(".二维码如下：");
        }else{
            binding.serverTitle.setText("-EasyDSS RTMP流媒体服务器：\n");
            binding.serverTitle.setMovementMethod(LinkMovementMethod.getInstance());
            SpannableString
                    spannableString = new SpannableString("http://www.easydss.com");
            //设置下划线文字
            spannableString.setSpan(new URLSpan("http://www.easydss.com"), 0, spannableString.length(), Spanned.SPAN_INCLUSIVE_EXCLUSIVE);

            //设置文字的前景色
            spannableString.setSpan(new ForegroundColorSpan(Color.RED), 0, spannableString.length(), Spanned.SPAN_INCLUSIVE_EXCLUSIVE);

            binding.serverTitle.append(spannableString);


            binding.playerTitle.setText("-EasyPlayerPro全功能播放器：\n");
            binding.playerTitle.setMovementMethod(LinkMovementMethod.getInstance());
            spannableString = new SpannableString("https://github.com/EasyDSS/EasyPlayerPro");
            //设置下划线文字
            spannableString.setSpan(new URLSpan("https://github.com/EasyDSS/EasyPlayerPro"), 0, spannableString.length(), Spanned.SPAN_INCLUSIVE_EXCLUSIVE);

            //设置文字的前景色
            spannableString.setSpan(new ForegroundColorSpan(Color.RED), 0, spannableString.length(), Spanned.SPAN_INCLUSIVE_EXCLUSIVE);

            binding.playerTitle.append(spannableString);
        }
    }
}
