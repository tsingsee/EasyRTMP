## EasyRTMP ##

EasyRTMP是[TSINGSEE青犀开放平台](http://open.tsingsee.com "TSINGSEE青犀开放平台")开发的一套RTMP直播推送功能组件，内部集成了包括：基本RTMP协议、断线重连、异步推送、环形缓冲区、推送网络拥塞自动丢帧、缓冲区关键帧检索、事件回调(断线、音视频数据回调)，通过EasyRTMP我们就可以避免接触到稍显复杂的RTMP推送或者客户端流程，只需要调用EasyRTMP的几个API接口，就能轻松、稳定地进行流媒体音视频数据的推送，支持市面上绝大部分的RTMP流媒体服务器，包括Wowza、Red5、nginx-rtmp、crtmpserver等主流RTMP服务器，全平台支持：Windows、Linux、ARM(各种交叉编译工具链)、Android、iOS;

### 调用方法 ###

- **EasyRTMP_HIK**：EasyRTMP通过海康SDK取流，并进行转化，再推送到RTMP流媒体服务器；

- **EasyRTMP_RTSP**：将RTSP/RTP数据获取到本地，再通过EasyRTMP推送到RTMP服务器；EasyRTMP_RTSP Demo除了EasyRTMP外还涉及到EasyRTSPClient库需要商业授权，EasyRTSPClient库是拉取RTSP流输出H264流和音频流的跨平台SDK。

- **EasyRTMP-Android**：Android安卓RTMP直播推流，采集安卓手机前/后摄像头、麦克风音视频推送直播；项目地址：[https://github.com/EasyDSS/EasyRTMP-Android](https://github.com/EasyDSS/EasyRTMP-Android "EasyRTMP-Android")

- **EasyRTMP-iOS**：iOS苹果RTMP直播推流，采集苹果手机前/后摄像头、麦克风音视频推送直播；项目地址：[https://github.com/EasyDSS/EasyRTMP-iOS](https://github.com/EasyDSS/EasyRTMP-iOS "EasyRTMP-iOS")

> 我们在公网部署了一台演示的RTMP服务器系统：[http://demo.easydss.com](http://demo.easydss.com "RTMP流媒体服务器") ，支持RTMP直播、服务端录像、检索、回放等功能；

### 编译方法 ###

	Windows平台采用Visual Studio 2010编译sln

	Linux下执行Builtit文件编译,具体如下：
		chmod +x Builtit
		
		"**************build stream from EasyRTMP_RTSP demo******************"
		"1. build 32bit program ./Buildit rtsp i386 [target in i386]"	
		"2. build 64bit program ./Buildit rtsp x64 [target in x64]"	
		"3. clean up ./Buildit rtsp clean"
		"-----------------------------------------------------------"
		"**************build stream from EasyRTMP_FILE demo******************"
		"4. build 32bit program ./Buildit file i386 [target in i386]"	
		"5. build 64bit program ./Buildit file x64 [target in x64]"	
		"6. clean up ./Buildit file clean"
		"-----------------------------------------------------------"
	

## 工作流程 ##
 
![EasyPusher Work Flow](http://www.easydarwin.org/github/images/easyrtmp/easyrtmp_workfolw.png)
 


## 调用过程 ##
![EasyRTMP](http://www.easydarwin.org/skin/easydarwin/images/easyrtmp20161101.png)


## 调用示例 ##

- EasyRTMP Android：支持前/后摄像头直播、安卓屏幕直播

	[https://fir.im/easyrtmp](https://fir.im/easyrtmp "https://fir.im/easyrtmp")

	![EasyRTMP Android](http://www.easydarwin.org/github/images/easyrtmpfirim20170409.png)

- EasyRTMP iOS：支持前/后摄像头直播

	[https://itunes.apple.com/us/app/easyrtmp/id1222410811?mt=8](https://itunes.apple.com/us/app/easyrtmp/id1222410811?mt=8 "EasyRTMP_iOS")

	![](http://www.easydarwin.org/github/images/easyrtmpios20170409.png)


## 技术支持 ##

- 邮件：[support@easydarwin.org](mailto:support@easydarwin.org) 

- QQ交流群：<a href="https://jq.qq.com/?_wv=1027&k=5dkmdix" title="EasyRTMP" target="_blank">**587254841**</a>

> EasyRTMP是一款非常稳定的RTMP推流直播组件，各平台版本需要经过授权才能商业使用，商业授权方案可以通过以上渠道进行更深入的技术与合作咨询；


## 获取更多信息 ##

TSINGSEE青犀开放平台：[http://open.tsingsee.com](http://open.tsingsee.com "TSINGSEE青犀开放平台")

Copyright &copy; TSINGSEE.com 2012~2019
