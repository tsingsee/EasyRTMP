/*
	Copyright (c) 2012-2016 EasyDarwin.ORG.  All rights reserved.
	Github: https://github.com/EasyDarwin
	WEChat: EasyDarwin
	Website: http://www.easydarwin.org
*/
#ifndef _EasyRTMP_API_H
#define _EasyRTMP_API_H

#ifdef _WIN32
#define Easy_API  __declspec(dllexport)
#define Easy_APICALL  __stdcall
#define Easy_FASTCALL __fastcall
#define WIN32_LEAN_AND_MEAN
#else
#define Easy_API
#define Easy_APICALL 
#endif

#define Easy_RTMP_Handle void*

typedef int						Easy_I32;
typedef unsigned char           Easy_U8;
typedef unsigned char           Easy_UChar;
typedef unsigned short          Easy_U16;
typedef unsigned int            Easy_U32;
typedef unsigned char			Easy_Bool;

/* 视频编码 */
#define EASY_SDK_VIDEO_CODEC_H264	0x1C		/* H264 */

/* 音频编码 */
#define EASY_SDK_AUDIO_CODEC_AAC	0x15002		/* AAC */

/* 音视频帧标识 */
#define EASY_SDK_VIDEO_FRAME_FLAG	0x00000001		/* 视频帧标志 */
#define EASY_SDK_AUDIO_FRAME_FLAG	0x00000002		/* 音频帧标志 */
#define EASY_SDK_EVENT_FRAME_FLAG	0x00000004		/* 事件帧标志 */
#define EASY_SDK_MEDIA_INFO_FLAG	0x00000020		/* 媒体类型标志*/

/* 视频关键字标识 */
#define EASY_SDK_VIDEO_FRAME_I		0x01		/* I帧 */
#define EASY_SDK_VIDEO_FRAME_P		0x02		/* P帧 */
/* 连接类型 */
typedef enum __EASY_RTMP_TYPE
{
	EASY_RTMP_CLIENT	=	0x01,		/* RTMP Client */
	EASY_RTMP_PUSHER					/* RTMP Pusher */
}EASY_RTMP_TYPE;

#pragma pack(1)
typedef struct __EASY_AV_Frame
{
    Easy_U32    u32AVFrameFlag;		/* 帧标志  视频 or 音频 */
    Easy_U32    u32AVFrameLen;		/* 帧的长度 */
    Easy_U32    u32VFrameType;		/* 视频的类型，I帧或P帧 */
	Easy_U32	u32TimestampSec;	/* 时间戳(秒)*/
	Easy_U32	u32TimestampUsec;	/* 时间戳(微秒) */
	Easy_U8     *pBuffer;			/* 数据 */	
}EASY_AV_Frame;

/* 媒体信息 */
typedef struct __EASY_MEDIA_INFO_T
{
	Easy_U32 u32VideoCodec;				/* 视频编码类型 */
	Easy_U32 u32VideoFps;				/* 视频帧率 */

	Easy_U32 u32AudioCodec;				/* 音频编码类型 */
	Easy_U32 u32AudioSamplerate;		/* 音频采样率 */
	Easy_U32 u32AudioChannel;			/* 音频通道数 */
	Easy_U32 u32AudioBitsPerSample;		/* 音频采样精度 */

	Easy_U32 u32H264SpsLength;			/* 视频sps帧长度 */
	Easy_U32 u32H264PpsLength;			/* 视频pps帧长度 */
	Easy_U8	 u8H264Sps[128];			/* 视频sps帧内容 */
	Easy_U8	 u8H264Pps[36];				/* 视频sps帧内容 */
}EASY_MEDIA_INFO_T;

/*
	_frameType:		EASY_SDK_VIDEO_FRAME_FLAG/EASY_SDK_AUDIO_FRAME_FLAG/EASY_SDK_EVENT_FRAME_FLAG/...	
	_pBuf:			回调的数据部分，具体用法看Demo
	_frameInfo:		帧结构数据
	_userPtr:		用户自定义数据
*/
typedef int (Easy_FASTCALL *EasyRTMPCallBack)(int _frameType, char *pBuf, EASY_AV_Frame* _frameInfo, void *_userPtr);

#ifdef __cplusplus
extern "C"
{
#endif
	/* 创建EasyRTMP句柄  返回为句柄值 */
	Easy_API Easy_RTMP_Handle Easy_FASTCALL EasyRTMP_Create(EASY_RTMP_TYPE _rtmpType);

	/* 释放EasyRTMP 参数为EasyRTMP句柄 */
	Easy_API int Easy_FASTCALL EasyRTMP_Release(Easy_RTMP_Handle *handle);

	/* 设置数据回调 */
	Easy_API int Easy_FASTCALL EasyRTMP_SetCallback(Easy_RTMP_Handle handle, EasyRTMPCallBack _callback);

	/* 打开网络流(拉取或者推送) */
	Easy_API int Easy_APICALL EasyRTMP_StartStream(Easy_RTMP_Handle handle, char *_url, void *userPtr, int _reconn/*1000表示长连接,即如果网络断开自动重连, 其它值为连接次数*/, int _verbosity/*日志打印输出等级，0表示不输出*/);
	
	/* 推流 frame:具体推送的流媒体帧H.264/AAC */
	Easy_API Easy_U32 Easy_FASTCALL EasyRTMP_PushFrame(Easy_RTMP_Handle handle, EASY_AV_Frame* frame );

#ifdef __cplusplus
}
#endif

#endif
