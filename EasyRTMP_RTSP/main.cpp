/*
	Copyright (c) 2013-2014 EasyDarwin.ORG.  All rights reserved.
	Github: https://github.com/EasyDarwin
	WEChat: EasyDarwin
	Website: http://www.EasyDarwin.org
*/
#define _CRTDBG_MAP_ALLOC
#include <stdio.h>
#ifdef _WIN32
#include "windows.h"
#else
#include <string.h>
#include <unistd.h>
#endif
#include "getopt.h"
#include <stdio.h> 
#include <iostream> 
#include <time.h> 
#include <stdlib.h>

#include "EasyRTSPClientAPI.h"
#include "EasyAACEncoderAPI.h"
#include "EasyRTMPAPI.h"
#ifdef _WIN32
#pragma comment(lib,"libEasyRTSPClient.lib")
#pragma comment(lib,"libEasyAACEncoder.lib")
#pragma comment(lib,"libeasyrtmp.lib")
#endif

#define MAX_RTMP_URL_LEN 256
static char* RTSPURL = NULL;//"rtsp://admin:admin@192.168.1.222/22";
static char SRTMP[MAX_RTMP_URL_LEN] = { 0 };// "rtmp://www.easydss.com:10085/hls/streamxxx";

#ifdef _WIN32
#define KEY "79397037795969576B5A7341385A566170576F4F532B354659584E35556C524E5546395356464E514C6D56345A56634D5671442F532B424859585A7062695A4359574A76633246414D6A41784E6B566863336C4559584A33615735555A5746745A57467A65513D3D"
#define EasyRTSPClient_KEY "79393674363469576B5A75415170646170576938792B354659584E35556C524E5546395356464E514C6D56345A56634D5671442F532B424859585A7062695A4359574A76633246414D6A41784E6B566863336C4559584A33615735555A5746745A57467A65513D3D"
#else // linux
#define KEY "79397037795A4F576B5971415170646170576938792F4A6C59584E35636E52746346397964484E77567778576F50394C34456468646D6C754A6B4A68596D397A595541794D4445325257467A65555268636E6470626C526C5957316C59584E35"
#define EasyRTSPClient_KEY "7939367436354F576B596F41385A566170576F4F532F4A6C59584E35636E52746346397964484E77567778576F50394C34456468646D6C754A6B4A68596D397A595541794D4445325257467A65555268636E6470626C526C5957316C59584E35"
#endif

#define BUFFER_SIZE  1024*1024

typedef struct _rtmp_pusher_struct_t
{
	Easy_RTMP_Handle rtmpHandle;
	unsigned int u32AudioCodec;	
	unsigned int u32AudioSamplerate;
	unsigned int u32AudioChannel;
	EasyAACEncoder_Handle m_pAACEncoderHandle;
	unsigned char m_pAACEncBufer[64*1024];
}_rtmp_pusher;

_rtmp_pusher g_rtmpPusher = {0};
Easy_RTSP_Handle fNVSHandle = 0;

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

/* EasyRTSPClient callback */
int Easy_APICALL __RTSPSourceCallBack( int _chid, void *_chPtr, int _mediatype, char *pbuf, RTSP_FRAME_INFO *frameinfo)
{
	if (NULL != frameinfo)
	{
		if (frameinfo->height==1088)		frameinfo->height=1080;
		else if (frameinfo->height==544)	frameinfo->height=540;
	}
	Easy_Bool bRet = 0;
	int iRet = 0;

	if (_mediatype == EASY_SDK_VIDEO_FRAME_FLAG)
	{
		if(frameinfo && frameinfo->length)
		{
			if( frameinfo->type == EASY_SDK_VIDEO_FRAME_I)
			{
				/*printf("pbuf = %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X",
					pbuf[0],pbuf[1],pbuf[2],pbuf[3],pbuf[4],pbuf[5],pbuf[6],pbuf[7],pbuf[8],pbuf[9],pbuf[10],pbuf[11],pbuf[12],pbuf[13],pbuf[14],pbuf[15],pbuf[16],
					pbuf[17],pbuf[18],pbuf[19],pbuf[20],pbuf[21],pbuf[22],pbuf[23],pbuf[24],pbuf[25],pbuf[26],pbuf[27],pbuf[28],pbuf[29]);*/
				if(g_rtmpPusher.rtmpHandle == 0)
				{
					g_rtmpPusher.rtmpHandle = EasyRTMP_Create();
					if (g_rtmpPusher.rtmpHandle == NULL)
						return -1;
					EasyRTMP_SetCallback(g_rtmpPusher.rtmpHandle, __EasyRTMP_Callback, NULL);
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

					printf("Please Play the URL: %s", SRTMP);
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
					//printf("I");
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
						//printf("P");
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
			//printf("*");
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
					//printf("*");
					avFrame.pBuffer = (Easy_U8*)(g_rtmpPusher.m_pAACEncBufer);
					avFrame.u32AVFrameLen  = iAACBufferLen;	
					iRet = EasyRTMP_SendPacket(g_rtmpPusher.rtmpHandle, &avFrame);
				}
			}
		}
	}

	return 0;
}

void PrintUsage(char* ProgName)
{
	printf("Usage:\n");
	printf("------------------------------------------------------\n");
	printf("%s -s <rtsp source stream> -m <dest rtmp streamName>\n", ProgName);
	printf("Help Mode:   %s -h \n", ProgName);
	printf("For example: %s -s rtsp://admin:admin@192.168.2.100/22 -m rtmp://www.easydss.com:10085/hls/easyrtmptest\n", ProgName);
	printf("------------------------------------------------------\n");
}

int main(int argc, char * argv[])
{
#ifdef _WIN32
	extern char* optarg;
#endif
	int ch;

	srand((unsigned)time(NULL));
	sprintf(SRTMP,"rtmp://www.easydss.com:10085/hls/%d", rand()%99999999);

	int iret = EasyRTMP_Activate(KEY);
	if (iret != 0)
	{
		printf("EasyRTMP_Activate error. ret=%d!!!\n", iret);
		getchar();
		return -1;
	}

	PrintUsage(argv[0]);

	while ((ch = getopt(argc, argv, "h:s:m:")) != EOF)
	{
		switch (ch)
		{
		case 'h':
			PrintUsage(argv[0]);
			return 0;
			break;
		case 'm':
			sprintf(SRTMP, "%s", optarg);
			break;
		case 's':
			RTSPURL = optarg;
			break;
		case '?':
			return 0;
			break;
		default:
			break;
		}
	}

	if (RTSPURL == NULL)
	{
		printf("Please input the parameter -s of the RTSP source URL!\n");
		getchar();
		return -2;
	}

	printf("Please Play the URL: %s\n", SRTMP);

	EasyRTSP_Activate(EasyRTSPClient_KEY);
	EasyRTSP_Init(&fNVSHandle);
	if (NULL == fNVSHandle) 
    {
        printf("EasyRTSP_Init error. ret=%d!!!\n", iret);
		getchar();
        return -3;
    }
	unsigned int mediaType = EASY_SDK_VIDEO_FRAME_FLAG | EASY_SDK_AUDIO_FRAME_FLAG;
	
	EasyRTSP_SetCallback(fNVSHandle, __RTSPSourceCallBack);

	EasyRTSP_OpenStream(fNVSHandle, 0, RTSPURL, EASY_RTP_OVER_TCP, mediaType, 0, 0, NULL, 1000, 0, 0, 3);

	getchar();

	EasyRTSP_CloseStream(fNVSHandle);

	EasyRTSP_Deinit(&fNVSHandle);
	fNVSHandle = NULL;

	Easy_AACEncoder_Release(g_rtmpPusher.m_pAACEncoderHandle);

	EasyRTMP_Release(g_rtmpPusher.rtmpHandle);
	g_rtmpPusher.rtmpHandle = 0;

    return 0;
}