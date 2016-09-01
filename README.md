## EasyRTMP ##

### **EasyRTMP**是什么？ ###

EasyRTMP是EasyDarwin团队开发的一套RTMP组件，支持RTMP推送(RTMP Push)、RTMP客户端(RTMP Client)的功能，内部集成了包括：基本RTMP协议、断线重连(推送&客户端)、推送缓冲区、推送网络拥塞自动丢帧、事件回调(断线、音视频数据回调)，通过EasyRTMP我们就可以避免接触到稍显复杂的RTMP推送或者客户端流程，只需要调用EasyRTMP的几个API接口，就能轻松、稳定地进行流媒体音视频数据的推送和拉取，支持市面上绝大部分的RTMP流媒体服务器，包括Red5、Ngnix_rtmp、crtmpserver等主流RTMP服务器，全平台支持：Windows、Linux、ARM(各种交叉编译工具链)、Android、iOS;


### 调用方法 ###

- **EasyRTMP_Client**：EasyRTMP做为RTMP客户端，向RTMP服务器拉取流媒体音视频数据；
- **EasyRTMP_File**：EasyRTMP做为RTMP推送端，将本地文件推送到RTMP流媒体服务器；
- **EasyRTMP_RTSP**：将RTSP/RTP数据获取到本地，再通过EasyRTMP推送到RTMP服务器；
- **Android**：Android安卓RTMP直播推流，采集安卓手机前/后摄像头、麦克风音视频推送直播；
- **iOS**：iOS苹果RTMP直播推流，采集苹果手机前/后摄像头、麦克风音视频推送直播；


### 调用过程 ###
![](http://www.easydarwin.org/skin/easydarwin/images/easyrtmp20150908.png)


### 获取更多信息 ###

邮件：[support@easydarwin.org](mailto:support@easydarwin.org) 

WEB：[www.EasyDarwin.org](http://www.easydarwin.org)

Copyright &copy; EasyDarwin.org 2012-2016

![EasyDarwin](http://www.easydarwin.org/skin/easydarwin/images/wx_qrcode.jpg)
