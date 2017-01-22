## EasyRTMP ##

### **EasyRTMP**是什么？ ###

EasyRTMP是EasyDarwin团队开发的一套RTMP直播推送功能组件，内部集成了包括：基本RTMP协议、断线重连、异步推送、环形缓冲区、推送网络拥塞自动丢帧、缓冲区关键帧检索、事件回调(断线、音视频数据回调)，通过EasyRTMP我们就可以避免接触到稍显复杂的RTMP推送或者客户端流程，只需要调用EasyRTMP的几个API接口，就能轻松、稳定地进行流媒体音视频数据的推送，支持市面上绝大部分的RTMP流媒体服务器，包括Red5、Ngnix_rtmp、crtmpserver等主流RTMP服务器，全平台支持：Windows、Linux、ARM(各种交叉编译工具链)、Android、iOS;

- **我们同时提供Windows、Linux、ARM、Android、IOS版本的EasyRTMP库**：EasyRTMP SDK商业使用需要经过授权才能永久使用，商业授权方案细节： [http://www.easydss.com/EasyRTMP.html](http://www.easydss.com/EasyRTMP.html "EasyRTMP授权")；个人及非商业用途可通过[https://github.com/EasyDarwin/Tools](https://github.com/EasyDarwin/Tools "EasyDarwin Tools")中的**EasyDarwin SDK License生成工具**生成临时License使用，或者可以邮件发送至[support@easydarwin.org](mailto:support@easydarwin.org "EasyDarwin support mail")进行更深入的合作咨询，注意ARM版本需要附上交叉编译工具链，我们会帮您具体编译；


### 调用方法 ###

- **EasyRTMP_File**：EasyRTMP做为RTMP推送端，将本地文件推送到RTMP流媒体服务器；
- **EasyRTMP_RTSP**：将RTSP/RTP数据获取到本地，再通过EasyRTMP推送到RTMP服务器；
- **Android**：Android安卓RTMP直播推流，采集安卓手机前/后摄像头、麦克风音视频推送直播；
- **iOS**：iOS苹果RTMP直播推流，采集苹果手机前/后摄像头、麦克风音视频推送直播；


### 调用过程 ###
![EasyRTMP](http://www.easydarwin.org/skin/easydarwin/images/easyrtmp20161101.png)


### 获取更多信息 ###

邮件：[support@easydarwin.org](mailto:support@easydarwin.org) 

WEB：[www.EasyDarwin.org](http://www.easydarwin.org)

Copyright &copy; EasyDarwin.org 2012-2016

![EasyDarwin](http://www.easydarwin.org/skin/easydarwin/images/wx_qrcode.jpg)
