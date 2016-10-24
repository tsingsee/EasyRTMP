/*
	Copyright (c) 2013-2014 EasyDarwin.ORG.  All rights reserved.
	Github: https://github.com/EasyDarwin
	WEChat: EasyDarwin
	Website: http://www.EasyDarwin.org
*/
#define _CRTDBG_MAP_ALLOC
#include <stdio.h>

#include "windows.h"
#include "EasyRTSPClientAPI.h"
#pragma comment(lib,"libEasyRTSPClient.lib")
#include "EasyAACEncoderAPI.h"
#pragma comment(lib,"libEasyAACEncoder.lib")
#include "EasyRTMPAPI.h"
#pragma comment(lib,"libeasyrtmp.lib")

#define RTSPURL "rtsp://admin:admin@192.168.31.100/11"
//#define RTSPURL "rtsp://192.168.1.93:8554/524155"

//#define SRTMP "rtmp://124.193.154.4/live/stream"
//#define SRTMP "rtmp://w.gslb.lecloud.com/live/201610053000001k699?sign=35b318b30eb40642ba86374780e3e0e7&tm=20161005174352"
#define SRTMP "rtmp://127.0.0.1/live/kimpc"

#define BUFFER_SIZE  1024*1024

typedef struct _rtmp_pusher_struct_t
{
	Easy_RTMP_Handle rtmpHandle;
	unsigned int u32AudioCodec;				/* 音频编码类型 */
	unsigned int u32AudioSamplerate;		/* 音频采样率 */
	unsigned int u32AudioChannel;			/* 音频通道数 */
	EasyAACEncoder_Handle m_pAACEncoderHandle;
	unsigned char m_pAACEncBufer[64*1024];
}_rtmp_pusher;

_rtmp_pusher g_rtmpPusher = {0};
Easy_RTSP_Handle fNVSHandle = 0;

int EasyInitAACEncoder(RTSP_FRAME_INFO *frameinfo)
{
	if(g_rtmpPusher.m_pAACEncoderHandle == NULL)
	{
		InitParam initParam;
		initParam.u32AudioSamplerate = 8000 /*frameinfo->sample_rate*/;
		initParam.ucAudioChannel =  1 /*frameinfo->channels*/;
		initParam.u32PCMBitSize =  16 /*frameinfo->bits_per_sample*/;

		if(frameinfo->codec == EASY_SDK_AUDIO_CODEC_G711A)
			initParam.ucAudioCodec = Law_ALaw;
		else if(frameinfo->codec == EASY_SDK_AUDIO_CODEC_G711U)
			initParam.ucAudioCodec = Law_ULaw;
		else
			return -1;

		g_rtmpPusher.m_pAACEncoderHandle = Easy_AACEncoder_Init( initParam);
	}
	return 0;
}

/* NVSource从RTSPClient获取数据后回调给上层 */
int Easy_APICALL __RTSPSourceCallBack( int _chid, void *_chPtr, int _mediatype, char *pbuf, RTSP_FRAME_INFO *frameinfo)
{
	if (NULL != frameinfo)
	{
		if (frameinfo->height==1088)		frameinfo->height=1080;
		else if (frameinfo->height==544)	frameinfo->height=540;
	}
	Easy_Bool bRet = 0;
	int iRet = 0;

	//目前只处理视频
	if (_mediatype == EASY_SDK_VIDEO_FRAME_FLAG)
	{
		if(frameinfo && frameinfo->length)
		{
			if( frameinfo->type == EASY_SDK_VIDEO_FRAME_I)
			{
				/*printf("pbuf = %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X",
					pbuf[0],pbuf[1],pbuf[2],pbuf[3],pbuf[4],pbuf[5],pbuf[6],pbuf[7],pbuf[8],pbuf[9],pbuf[10],pbuf[11],pbuf[12],pbuf[13],pbuf[14],pbuf[15],pbuf[16],
					pbuf[17],pbuf[18],pbuf[19],pbuf[20],pbuf[21],pbuf[22],pbuf[23],pbuf[24],pbuf[25],pbuf[26],pbuf[27],pbuf[28],pbuf[29]);*/
				/* 关键帧是SPS、PPS、IDR(均包含00 00 00 01)的组合,reserved1是sps结尾的偏移,reserved2是pps结尾的偏移 */
				if(g_rtmpPusher.rtmpHandle == 0)
				{
					g_rtmpPusher.rtmpHandle = EasyRTMP_Create();

					bRet = EasyRTMP_Connect(g_rtmpPusher.rtmpHandle, SRTMP);
					if (!bRet)
					{
						printf("Fail to EasyRTMP_Connect ...\n");
					}

					EASY_MEDIA_INFO_T mediaInfo;
					memset(&mediaInfo, 0, sizeof(EASY_MEDIA_INFO_T));
					mediaInfo.u32VideoFps = 25;
					mediaInfo.u32AudioSamplerate = 8000;
					iRet = EasyRTMP_InitMetadata(g_rtmpPusher.rtmpHandle, &mediaInfo, 1024);
					if (iRet < 0)
					{
						printf("Fail to InitMetadata ...\n");
					}
				}

				EASY_AV_Frame avFrame;
				memset(&avFrame, 0, sizeof(EASY_AV_Frame));
				avFrame.u32AVFrameFlag = EASY_SDK_VIDEO_FRAME_FLAG;
				avFrame.u32AVFrameLen = frameinfo->length;
				avFrame.pBuffer = (unsigned char*)pbuf;
				avFrame.u32VFrameType = EASY_SDK_VIDEO_FRAME_I;
				avFrame.u32TimestampSec = frameinfo->timestamp_sec;
				avFrame.u32TimestampUsec = frameinfo->timestamp_usec;
				
				iRet = EasyRTMP_SendPacket(g_rtmpPusher.rtmpHandle, &avFrame);
				if (iRet < 0)
				{
					printf("Fail to EasyRTMP_SendH264Packet(I-frame) ...\n");
				}
				else
				{
					printf("I");
				}
			}
			else
			{
				if(g_rtmpPusher.rtmpHandle)
				{
					EASY_AV_Frame avFrame;
					memset(&avFrame, 0, sizeof(EASY_AV_Frame));
					avFrame.u32AVFrameFlag = EASY_SDK_VIDEO_FRAME_FLAG;
					avFrame.u32AVFrameLen = frameinfo->length-4;
					avFrame.pBuffer = (unsigned char*)pbuf+4;
					avFrame.u32VFrameType = EASY_SDK_VIDEO_FRAME_P;
					avFrame.u32TimestampSec = frameinfo->timestamp_sec;
					avFrame.u32TimestampUsec = frameinfo->timestamp_usec;
					iRet = EasyRTMP_SendPacket(g_rtmpPusher.rtmpHandle, &avFrame);
					if (iRet < 0)
					{
						printf("Fail to EasyRTMP_SendH264Packet(P-frame) ...\n");
					}
					else
					{
						printf("P");
					}
				}
			}				
		}	
	}
	else if (_mediatype == EASY_SDK_AUDIO_FRAME_FLAG)
	{
		EASY_AV_Frame	avFrame;
		memset(&avFrame, 0x00, sizeof(EASY_AV_Frame));
		avFrame.u32AVFrameFlag = EASY_SDK_AUDIO_FRAME_FLAG;
		avFrame.u32TimestampSec = frameinfo->timestamp_sec;
		avFrame.u32TimestampUsec = frameinfo->timestamp_usec;

		if(frameinfo->codec == EASY_SDK_AUDIO_CODEC_AAC)
		{
			avFrame.pBuffer = (Easy_U8*)(pbuf);
			avFrame.u32AVFrameLen  = frameinfo->length;	
			printf("*");
			iRet = EasyRTMP_SendPacket(g_rtmpPusher.rtmpHandle, &avFrame);
		}
		else if ((frameinfo->codec == EASY_SDK_AUDIO_CODEC_G711A) || (frameinfo->codec == EASY_SDK_AUDIO_CODEC_G711U) || (frameinfo->codec == EASY_SDK_AUDIO_CODEC_G726))
		{
			if(EasyInitAACEncoder(frameinfo) == 0)
			{
				memset(g_rtmpPusher.m_pAACEncBufer, 0, 64*1024);
				unsigned int iAACBufferLen = 0;

				if(Easy_AACEncoder_Encode(g_rtmpPusher.m_pAACEncoderHandle, (unsigned char*)pbuf,  frameinfo->length, g_rtmpPusher.m_pAACEncBufer, &iAACBufferLen) > 0)
				{
					printf("*");
					avFrame.pBuffer = (Easy_U8*)(g_rtmpPusher.m_pAACEncBufer);
					avFrame.u32AVFrameLen  = iAACBufferLen;	
					iRet = EasyRTMP_SendPacket(g_rtmpPusher.rtmpHandle, &avFrame);
				}
			}
		}
	}

	return 0;
}

int main()
{
	EasyRTMP_Activate("79397037795969576B5A75412F517459702F51434A65354659584E35556C524E5546395356464E514C6D56345A56634D5671442F7065424859585A7062695A4359574A76633246414D6A41784E6B566863336C4559584A33615735555A5746745A57467A65513D3D");
	//创建EasyNVSource
	EasyRTSP_Activate("6A59754D6A3469576B5A75412F517459702F51424575354659584E35556C524E5546395356464E514C6D56345A56634D5671442B6B75424859585A7062695A4359574A76633246414D6A41784E6B566863336C4559584A33615735555A5746745A57467A65513D3D");
	EasyRTSP_Init(&fNVSHandle);
	if (NULL == fNVSHandle) return 0;

	unsigned int mediaType = EASY_SDK_VIDEO_FRAME_FLAG | EASY_SDK_AUDIO_FRAME_FLAG;
	//设置数据回调
	EasyRTSP_SetCallback(fNVSHandle, __RTSPSourceCallBack);
	//打开RTSP网络串流
	EasyRTSP_OpenStream(fNVSHandle, 0, RTSPURL, EASY_RTP_OVER_TCP, mediaType, 0, 0, NULL, 1000, 0, 1, 3);

	getchar();

	//关闭EasyNVSource拉取
	EasyRTSP_CloseStream(fNVSHandle);
	//释放EasyNVSource
	EasyRTSP_Deinit(&fNVSHandle);
	fNVSHandle = NULL;

	Easy_AACEncoder_Release(g_rtmpPusher.m_pAACEncoderHandle);
    
	//是否RTMP推送
	EasyRTMP_Release(g_rtmpPusher.rtmpHandle);
	g_rtmpPusher.rtmpHandle = 0;

    return 0;
}