/*
	Copyright (c) 2013-2014 EasyDarwin.ORG.  All rights reserved.
	Github: https://github.com/EasyDarwin
	WEChat: EasyDarwin
	Website: http://www.EasyDarwin.org
*/
#include <stdio.h>
#include <string.h>
#include "EasyRTMPAPI.h"
#include "EasyAACEncoderAPI.h"
#ifdef _WIN32
#define KEY "6A34714D6C3469576B5A75414A553558714C48574F4F314659584E355548567A6147567958314E455379356C65475868567778576F50753434456468646D6C754A6B4A68596D397A595541794D4445325257467A65555268636E6470626C526C5957316C59584E35"
#include "getopt.h"
#else
#define KEY "6A34714D6C354F576B5971414A553558714C485A4576466C59584E356348567A6147567958334E6B61395A58444661672F704C67523246326157346D516D466962334E68514449774D545A4659584E355247467964326C75564756686257566863336B3D"
#include "unistd.h"
#include <signal.h>
#endif
#include <stdlib.h>
#include "hi_type.h"
#include "hi_net_dev_sdk.h"
#include "hi_net_dev_errors.h"


char* SRTMP             = "rtmp://192.168.31.194/live/kim2";//Default Push StreamName
char* ConfigUName	= "admin";			//SDK UserName
char* ConfigPWD		= "admin";			//SDK Password
char* ConfigDHost	= "127.0.0.1";	//SDK Host
char* ConfigDPort	= "80";				//SDK Port
char *ProgName;		//Program Name

HI_U32 u32Handle = 0;
Easy_RTMP_Handle g_RtmpHandle = 0;
EasyAACEncoder_Handle g_pAACEncoderHandle;
unsigned char m_pAACEncBufer[64*1024];

int EasyInitAACEncoder(unsigned int codec)
{
	if(g_pAACEncoderHandle == NULL)
	{
		InitParam initParam;
		initParam.u32AudioSamplerate = 8000 /*frameinfo->sample_rate*/;
		initParam.ucAudioChannel =  1 /*frameinfo->channels*/;
		initParam.u32PCMBitSize =  16 /*frameinfo->bits_per_sample*/;

		if(codec == EASY_SDK_AUDIO_CODEC_G711A)
			initParam.ucAudioCodec = Law_ALaw;
		else if(codec == EASY_SDK_AUDIO_CODEC_G711U)
			initParam.ucAudioCodec = Law_ULaw;
		else
			return -1;

		g_pAACEncoderHandle = Easy_AACEncoder_Init( initParam);
	}
	return 0;
}

HI_S32 OnEventCallback(HI_U32 u32Handle,
                                HI_U32 u32Event,
                                HI_VOID* pUserData 
                                )
{
	return HI_SUCCESS;
}


HI_S32 NETSDK_APICALL OnStreamCallback(HI_U32 u32Handle,
                                HI_U32 u32DataType,	
                                HI_U8* pu8Buffer,
                                HI_U32 u32Length,
                                HI_VOID* pUserData
                                )
{
    HI_S_AVFrame* pstruAV = HI_NULL;
	HI_S_SysHeader* pstruSys = HI_NULL;
	
	if (u32DataType == HI_NET_DEV_AV_DATA)
	{
		pstruAV = (HI_S_AVFrame*)pu8Buffer;

		if (pstruAV->u32AVFrameFlag == HI_NET_DEV_VIDEO_FRAME_FLAG)
		{
			if(g_RtmpHandle == 0 ) return 0;

			if(pstruAV->u32AVFrameLen > 0)
			{
				unsigned char* pbuf = (unsigned char*)(pu8Buffer+sizeof(HI_S_AVFrame));

				EASY_AV_Frame  avFrame;
				memset(&avFrame, 0x00, sizeof(EASY_AV_Frame));
				avFrame.u32AVFrameLen = pstruAV->u32AVFrameLen;
				avFrame.pBuffer = (unsigned char*)pbuf;
				avFrame.u32VFrameType = (pstruAV->u32VFrameType==HI_NET_DEV_VIDEO_FRAME_I)?EASY_SDK_VIDEO_FRAME_I:EASY_SDK_VIDEO_FRAME_P;
				avFrame.u32AVFrameFlag = EASY_SDK_VIDEO_FRAME_FLAG;
				avFrame.u32TimestampSec = pstruAV->u32AVFramePTS/1000;
				avFrame.u32TimestampUsec = (pstruAV->u32AVFramePTS%1000)*1000;
				EasyRTMP_SendPacket(g_RtmpHandle, &avFrame);
			}	
		}
		else
		if (pstruAV->u32AVFrameFlag == HI_NET_DEV_AUDIO_FRAME_FLAG)
		{
			if(g_RtmpHandle == 0 ) return 0;

			EASY_AV_Frame	avFrame;
			memset(&avFrame, 0x00, sizeof(EASY_AV_Frame));
			avFrame.u32AVFrameFlag = EASY_SDK_AUDIO_FRAME_FLAG;

			if(pstruAV->u32AVFrameLen <= 4) return 0;

			if(EasyInitAACEncoder(EASY_SDK_AUDIO_CODEC_G711A) == 0)
			{
				memset(m_pAACEncBufer, 0, 64*1024);
				unsigned int iAACBufferLen = 0;
				unsigned char* pbuf = (unsigned char*)(pu8Buffer+sizeof(HI_S_AVFrame)) + 4;
				if(Easy_AACEncoder_Encode(g_pAACEncoderHandle, (unsigned char*)pbuf,  pstruAV->u32AVFrameLen-4, m_pAACEncBufer, &iAACBufferLen) > 0)
				{
					avFrame.pBuffer = (Easy_U8*)(m_pAACEncBufer);
					avFrame.u32AVFrameLen  = iAACBufferLen;	
					avFrame.u32TimestampSec = pstruAV->u32AVFramePTS/1000;
					avFrame.u32TimestampUsec = (pstruAV->u32AVFramePTS%1000)*1000;
					EasyRTMP_SendPacket(g_RtmpHandle, &avFrame);
				}
			}		
		}
	}
	else
	if (u32DataType == HI_NET_DEV_SYS_DATA)
	{
		pstruSys = (HI_S_SysHeader*)pu8Buffer;
		printf("Video W:%u H:%u Audio: %u \n", pstruSys->struVHeader.u32Width, pstruSys->struVHeader.u32Height, pstruSys->struAHeader.u32Format);
	}
	return HI_SUCCESS;
}

HI_S32 OnDataCallback(HI_U32 u32Handle,	
                                HI_U32 u32DataType,
                                HI_U8*  pu8Buffer,
                                HI_U32 u32Length,
                                HI_VOID* pUserData
                                )
{
	return HI_SUCCESS;
}

/* EasyRTMP callback */
int __EasyRTMP_Callback(int _frameType, char *pBuf, EASY_RTMP_STATE_T _state, void *_userPtr)
{
    if (_state == EASY_RTMP_STATE_CONNECTING)               printf("Connecting...\n");
    else if (_state == EASY_RTMP_STATE_CONNECTED)           printf("Connected\n");
    else if (_state == EASY_RTMP_STATE_CONNECT_FAILED)      printf("Connect failed\n");
    else if (_state == EASY_RTMP_STATE_CONNECT_ABORT)       printf("Connect abort\n");
    else if (_state == EASY_RTMP_STATE_DISCONNECTED)        printf("Disconnect.\n");

    return 0;
}

void PrintUsage()
{
	printf("Usage:\n");
	printf("------------------------------------------------------\n");
	printf("%s [-d <host> -p <port> -n <streamName> -N <Device user> -P <Device password> -H <Device host> -T <Device Port>]\n", ProgName);
	printf("Help Mode:   %s -h \n", ProgName );
	printf("For example: %s -n rtmp://192.168.31.194/live/stream -N admin -P admin -H 192.168.66.189 -T 80\n", ProgName); 
	printf("------------------------------------------------------\n");
}
int main(int argc, char * argv[])
{
	bool bRet = false;
	Easy_I32 iRet = 0;

	int isActivated = 0;
#ifndef _WIN32
   signal(SIGPIPE, SIG_IGN);
#endif

#ifdef _WIN32
	extern char* optarg;
#endif
	int ch;
	ProgName = argv[0];	
	PrintUsage();

	while ((ch = getopt(argc,argv, "hd:p:n:N:P:H:T:")) != EOF) 
	{
		switch(ch)
		{
		case 'h':
			PrintUsage();
			return 0;
			break;
		case 'n':
			SRTMP =optarg;
			break;
		case 'N':
			ConfigUName =optarg;
			break;
		case 'P':
			ConfigPWD =optarg;
			break;
		case 'H':
			ConfigDHost =optarg;
			break;
		case 'T':
			ConfigDPort =optarg;
			break;
		case '?':
			return 0;
			break;
		default:
			break;
		}
	}

	isActivated = EasyRTMP_Activate(KEY);
	switch(isActivated)
	{
	case EASY_ACTIVATE_INVALID_KEY:
		printf("KEY is EASY_ACTIVATE_INVALID_KEY!\n");
		break;
	case EASY_ACTIVATE_TIME_ERR:
		printf("KEY is EASY_ACTIVATE_TIME_ERR!\n");
		break;
	case EASY_ACTIVATE_PROCESS_NAME_LEN_ERR:
		printf("KEY is EASY_ACTIVATE_PROCESS_NAME_LEN_ERR!\n");
		break;
	case EASY_ACTIVATE_PROCESS_NAME_ERR:
		printf("KEY is EASY_ACTIVATE_PROCESS_NAME_ERR!\n");
		break;
	case EASY_ACTIVATE_VALIDITY_PERIOD_ERR:
		printf("KEY is EASY_ACTIVATE_VALIDITY_PERIOD_ERR!\n");
		break;
	case EASY_ACTIVATE_SUCCESS:
		printf("KEY is EASY_ACTIVATE_SUCCESS!\n");
		break;
	}

	if(EASY_ACTIVATE_SUCCESS != isActivated)
		return -1;

	EASY_MEDIA_INFO_T mediainfo;
    memset(&mediainfo, 0x00, sizeof(EASY_MEDIA_INFO_T));
	mediainfo.u32VideoFps = 25;
	mediainfo.u32AudioSamplerate = 8000;

    g_RtmpHandle = EasyRTMP_Create();
	bRet = EasyRTMP_Connect(g_RtmpHandle, SRTMP);
	if (!bRet)
	{
		printf("Fail to EasyRTMP_Connect ...\n");
	}
    EasyRTMP_SetCallback(g_RtmpHandle, __EasyRTMP_Callback, NULL);
	iRet = EasyRTMP_InitMetadata(g_RtmpHandle, &mediainfo, 1024);
	if (iRet < 0)
	{
		printf("Fail to InitMetadata ...\n");
	}


    HI_S32 s32Ret = HI_SUCCESS;
    HI_S_STREAM_INFO struStreamInfo;
    
    HI_NET_DEV_Init();
    
    s32Ret = HI_NET_DEV_Login(&u32Handle, ConfigUName, ConfigPWD, ConfigDHost, atoi(ConfigDPort));
    if (s32Ret != HI_SUCCESS)
    {
        HI_NET_DEV_DeInit();
		return -1;
    }
    
	//HI_NET_DEV_SetEventCallBack(u32Handle, OnEventCallback, &a);
	HI_NET_DEV_SetStreamCallBack(u32Handle, (HI_ON_STREAM_CALLBACK)OnStreamCallback, NULL);
	//HI_NET_DEV_SetDataCallBack(u32Handle, OnDataCallback, &a);

	struStreamInfo.u32Channel = HI_NET_DEV_CHANNEL_1;
	struStreamInfo.blFlag = HI_TRUE;;
	struStreamInfo.u32Mode = HI_NET_DEV_STREAM_MODE_TCP;
	struStreamInfo.u8Type = HI_NET_DEV_STREAM_ALL;
	s32Ret = HI_NET_DEV_StartStream(u32Handle, &struStreamInfo);
	if (s32Ret != HI_SUCCESS)
	{
		HI_NET_DEV_Logout(u32Handle);
		u32Handle = 0;
		return -1;
	}    
    
 
    getchar();

	Easy_AACEncoder_Release(g_pAACEncoderHandle);
    EasyRTMP_Release(g_RtmpHandle);
    g_RtmpHandle = 0;
   
    HI_NET_DEV_StopStream(u32Handle);
    HI_NET_DEV_Logout(u32Handle);
    
    HI_NET_DEV_DeInit();

    return 0;
}