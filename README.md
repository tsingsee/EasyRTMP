## EasyRTMP ##

EasyRTMP是[TSINGSEE青犀开放平台](http://open.tsingsee.com "TSINGSEE青犀开放平台")开发的一套RTMP直播推送功能组件，内部集成了包括：基本RTMP协议、断线重连、异步推送、环形缓冲区、推送网络拥塞自动丢帧、缓冲区关键帧检索、事件回调(断线、音视频数据回调)，通过EasyRTMP我们就可以避免接触到稍显复杂的RTMP推送或者客户端流程，只需要调用EasyRTMP的几个API接口，就能轻松、稳定地进行流媒体音视频数据的推送，支持市面上绝大部分的RTMP流媒体服务器，包括Wowza、Red5、nginx-rtmp、crtmpserver等主流RTMP服务器，全平台支持：Windows、Linux、ARM(各种交叉编译工具链)、Android、iOS;

### 调用方法 ###

- **EasyRTMP_HIK**：EasyRTMP通过海康SDK取流，并进行转化，再推送到RTMP流媒体服务器；

- **EasyRTSPLive**：拉流IPC摄像机或者NVR硬盘录像机RTSP流转成RTMP推送到阿里云CDN/腾讯云CDN/RTMP流媒体服务器，支持多路RTSP流同时拉取并以RTMP协议推送发布，EasyRTSPLive我们支持任何平台，包括但不限于Windows/Linux/Android/ARM，项目地址：[https://github.com/tsingsee/EasyRTSPLive](https://github.com/tsingsee/EasyRTSPLive "EasyRTSPLive")。

- **EasyRTMPLive**：将RTSP、RTMP、HTTP、HLS等各种各样的网络流媒体先拉取到本地，进行转换，再以标准RTMP/flv协议的方式推流到RTMP流媒体服务器、CDN等，进行直播分发，项目地址：[https://github.com/tsingsee/EasyRTMPLive](https://github.com/tsingsee/EasyRTMPLive "EasyRTMPLive")。

- **EasyRTMP-Android**：Android安卓RTMP直播推流，采集安卓手机前/后摄像头、麦克风音视频推送直播；项目地址：[https://github.com/tsingsee/EasyRTMP-Android](https://github.com/tsingsee/EasyRTMP-Android "EasyRTMP-Android")

- **EasyRTMP-iOS**：iOS苹果RTMP直播推流，采集苹果手机前/后摄像头、麦克风音视频推送直播；项目地址：[https://github.com/tsingsee/EasyRTMP-iOS](https://github.com/tsingsee/EasyRTMP-iOS "EasyRTMP-iOS")

> 我们在公网部署了一台演示的RTMP高性能流媒体服务器系统：[http://demo.easydss.com](http://demo.easydss.com "RTMP流媒体服务器") ，支持RTMP直播、服务端录像、检索、回放等功能；


## 项目依赖

EasyRTMP项目依赖1个TSINGSEE青犀开放平台的Git工程：

- Include：https://github.com/tsingsee/Include

目录结构为：

	/
	/Include/
	/EasyRTMP/


### 编译方法 ###

	Windows平台采用Visual Studio 2010编译sln

	Linux下执行Builtit文件编译,具体如下：
	chmod +x Builtit
		

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


## 更多流媒体音视频资源

EasyDarwin开源流媒体服务器：<a href="http://www.easydarwin.org" target="_blank" title="EasyDarwin开源流媒体服务器">www.EasyDarwin.org</a>

EasyDSS高性能互联网直播服务：<a href="http://www.easydss.com" target="_blank" title="EasyDSS高性能互联网直播服务">www.EasyDSS.com</a>

EasyNVR安防视频可视化服务：<a href="http://www.easynvr.com" target="_blank" title="EasyNVR安防视频可视化服务">www.EasyNVR.com</a>

EasyNVS视频综合管理平台：<a href="http://www.easynvs.com" target="_blank" title="EasyNVS视频综合管理平台">www.EasyNVS.com</a>

EasyNTS云组网：<a href="http://www.easynts.com" target="_blank" title="EasyNTS云组网">www.EasyNTS.com</a>

EasyGBS国标GB/T28181服务器：<a href="http://www.easygbs.com" target="_blank" title="EasyGBS国标GB/T28181视频服务器">www.EasyGBS.com</a>

EasyRTS应急指挥平台：<a href="http://www.easyrts.com" target="_blank" title="EasyRTS应急指挥平台">www.EasyRTS.com</a>

TSINGSEE青犀开放平台：<a href="http://open.tsingsee.com" target="_blank" title="TSINGSEE青犀开放平台">open.TSINGSEE.com</a>

Copyright © <a href="http://www.tsingsee.com" target="_blank" title="青犀TSINGSEE">www.TSINGSEE.com</a> Team 2012-2020

![青犀TSINGSEE](http://www.easydarwin.org/public/images/tsingsee_qrcode_160.jpg)
