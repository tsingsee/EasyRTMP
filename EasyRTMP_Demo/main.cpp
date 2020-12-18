/*
	Copyright (c) 2013-2019 EasyDarwin.ORG.  All rights reserved.
	Github: https://github.com/EasyDarwin
	WEChat: EasyDarwin
	Website: http://www.EasyDarwin.org
*/
#include "EasyRTMPAPI.h"
#include "trace.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ini.h"

#ifdef _WIN32
#include "getopt.h"
#define KEY "79736C36655969576B5A734132635A666F446B6D7065394659584E35556C524E55463949535573755A58686C4B56634D5671442F7066396C59584E35"
#else //linux
#include "unistd.h"
#include <signal.h>
#define KEY "79736C36655A4F576B596F4132635A666F446B6D70664E6C59584E35636E52746346396F61577370567778576F502B6C2F32566863336B3D"
#endif

#define CONF_FILE_PATH  "easyrtmp.ini"  
typedef struct _cfg_info_t
{
	int channelId;
	int option;
	char channelName[64];
	char srcFilePath[512];
	char destRtmpAddr[512];
}cfg_info;

cfg_info g_cfgInfo;

char* SRTMP=    "rtmp://demo.easydss.com:3388/live/swordtest"; //Default RTMP Push StreamName
char* ProgName;								//Program Name

int __EasyRTMP_Callback(int _frameType, char *pBuf, EASY_RTMP_STATE_T _state, void *_userPtr)
{
    if (_state == EASY_RTMP_STATE_CONNECTING)               printf("Connecting...\n");
    else if (_state == EASY_RTMP_STATE_CONNECTED)           printf("Connected\n");
    else if (_state == EASY_RTMP_STATE_CONNECT_FAILED)      printf("Connect failed\n");
    else if (_state == EASY_RTMP_STATE_CONNECT_ABORT)       printf("Connect abort\n");
    else if (_state == EASY_RTMP_STATE_DISCONNECTED)        printf("Disconnect.\n");

    return 0;
}

int find_nal(unsigned char* buf, int size, int* nal_start, int* nal_end)
{
	int i;
	// find start
	*nal_start = 0;
	*nal_end = 0;

	i = 0;
	while (   //( next_bits( 24 ) != 0x000001 && next_bits( 32 ) != 0x00000001 )
		(buf[i] != 0 || buf[i + 1] != 0 || buf[i + 2] != 0x01) &&
		(buf[i] != 0 || buf[i + 1] != 0 || buf[i + 2] != 0 || buf[i + 3] != 0x01)
		)
	{
		i++; // skip leading zero
		if (i + 4 >= size) { return 0; } // did not find nal start
	}

	if (buf[i] != 0 || buf[i + 1] != 0 || buf[i + 2] != 0x01) // ( next_bits( 24 ) != 0x000001 )
	{
		i++;
	}

	if (buf[i] != 0 || buf[i + 1] != 0 || buf[i + 2] != 0x01) { /* error, should never happen */ return 0; }
	i += 3;
	*nal_start = i;

	while (   //( next_bits( 24 ) != 0x000000 && next_bits( 24 ) != 0x000001 )
		(buf[i] != 0 || buf[i + 1] != 0 || buf[i + 2] != 0) &&
		(buf[i] != 0 || buf[i + 1] != 0 || buf[i + 2] != 0x01)
		)
	{
		i++;
		// FIXME the next line fails when reading a nal that ends exactly at the end of the data
		if (i + 3 >= size)
		{
			*nal_end = size;
			return (*nal_end - *nal_start);
		} // did not find nal end, stream ended first
	}

	*nal_end = i;
	return (*nal_end - *nal_start);
}
int get_h264_sps_and_pps(char *pbuf, int bufsize, char *_sps, int *_spslen, char *_pps, int *_ppslen)
{
	char* pin = pbuf;
	int inlen = bufsize;
	int outlen = 0;
	char* pout = NULL;
	bool bend = false;

	int datalen = 0;
	bool bSPSOrPPS = false;

	int iOutLen = bufsize;
	do
	{
		//		pout=FindNal(pin,inlen,outlen,bend);
		int nal_start = 0;
		int nal_end = 0;
		outlen = find_nal((unsigned char*)pin, inlen, &nal_start, &nal_end);
		if (outlen <= 0)
		{
			break;
		}
		pout = pin + nal_start;
		if (pout != NULL)
		{
			unsigned char naltype = (pout[0] & 0x1F);

			if (naltype == 0x07)//0x67
			{
				memcpy(_sps, pout, outlen);
				*_spslen = outlen;

				bSPSOrPPS = true;
			}
			else if (naltype == 0x08)//0x68
			{
				memcpy(_pps, pout, outlen);
				*_ppslen = outlen;

				bSPSOrPPS = true;
			}
			else if (naltype == 0x06)//SEI
			{
				//Do we need SEI??
			}
			else if(naltype == 0x05 || naltype == 0x01)//data
			{
				break;
			}

			inlen = inlen - outlen - (pout - pin);
			pin = pout + outlen;
		}
	} while (bend != true);
	return 1;
}
bool InitCfgInfo(void)
{
	int i = 0;

	memset(&g_cfgInfo, 0, sizeof(cfg_info));
	g_cfgInfo.channelId = i;
	strcpy(g_cfgInfo.channelName, "config");
	strcpy(g_cfgInfo.srcFilePath, GetIniKeyString(g_cfgInfo.channelName, "file", CONF_FILE_PATH));
	strcpy(g_cfgInfo.destRtmpAddr, GetIniKeyString(g_cfgInfo.channelName, "rtmp", CONF_FILE_PATH));
	g_cfgInfo.option = GetIniKeyInt(g_cfgInfo.channelName, "option", CONF_FILE_PATH);
	if(strlen(g_cfgInfo.srcFilePath) > 0 && strlen(g_cfgInfo.destRtmpAddr) > 0)
	{
		return true;
	}

	return false;
}

int main(int argc, char * argv[])
{
    int isActivated = 0 ;
#ifndef _WIN32
    signal(SIGPIPE, SIG_IGN);
#endif

#ifdef _WIN32
    extern char* optarg;
#endif
    int ch;
    char szIP[16] = {0};
    Easy_Handle fPusherHandle = 0;
    EASY_MEDIA_INFO_T   mediainfo;

	bool b_init = false;
	char sps[255];
	int sps_len = 0;
	char pps[128];
	int pps_len = 0;

    int buf_size = 1024*1024*2;
    char *pbuf = (char *) malloc(buf_size);
	char* pSendBuf =  (char *) malloc(buf_size);

    FILE *fES = NULL;
    int position = 0;
    int iFrameNo = 0;
    int timestamp = 0;
    ProgName = argv[0];
	
	bool bSuc = InitCfgInfo();
	if (!bSuc)
	{
		printf("read config easyrtmp.ini fail£¬plz check file!\n");
		goto end;
	}

    fES = fopen(g_cfgInfo.srcFilePath, "rb");
    if (NULL == fES)
	{
		printf("read H.264 file:%s error!\n",g_cfgInfo.srcFilePath);
		goto end;
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

    if(isActivated<=0)
	{
		printf("EasyRTMP License key error,plz confirm!\n");
		goto end;
	}

	fPusherHandle = EasyRTMP_Create();

    if(fPusherHandle == NULL)
	{
		printf("create EasyRTMP push handle error,exit!\n");
        return -2;
	}

    EasyRTMP_SetCallback(fPusherHandle, __EasyRTMP_Callback, NULL);

    EasyRTMP_Connect(fPusherHandle, /*SRTMP*/g_cfgInfo.destRtmpAddr);
    

    while (1)
    {
        int nReadBytes = fread(pbuf+position, 1, 1, fES);
        if (nReadBytes < 1)
        {
            if (feof(fES))
            {
                position = 0;
                fseek(fES, 0, SEEK_SET);
                continue;
            }
            break;
        }

        position ++;

        if (position > 5)
        {
            unsigned char naltype = ( (unsigned char)pbuf[position-1] & 0x1F);

            if ((unsigned char)pbuf[position-5]== 0x00 && 
            	(unsigned char)pbuf[position-4]== 0x00 && 
            	(unsigned char)pbuf[position-3] == 0x00 &&
            	(unsigned char)pbuf[position-2] == 0x01 &&
            	(naltype == 0x05 || naltype == 0x01 ) )
            {
                int framesize = position - 5;
                EASY_AV_Frame   avFrame;

                naltype = (unsigned char)pbuf[4] & 0x1F;

				if(!b_init)
				{
					get_h264_sps_and_pps(pbuf, framesize, sps, &sps_len, pps, &pps_len );
					if (sps_len>0 && pps_len>0)
					{
						memset(&mediainfo, 0x00, sizeof(EASY_MEDIA_INFO_T));
						mediainfo.u32VideoCodec =   EASY_SDK_VIDEO_CODEC_H264;
						mediainfo.u32VideoFps = 25;
						mediainfo.u32SpsLength = sps_len;
						mediainfo.u32PpsLength = pps_len;
						memcpy(mediainfo.u8Sps,sps,sps_len );
						memcpy(mediainfo.u8Pps,pps,pps_len );

						mediainfo.u32AudioCodec =   EASY_SDK_AUDIO_CODEC_AAC;
						mediainfo.u32AudioSamplerate = 8000;
						mediainfo.u32AudioChannel = 1;

						EasyRTMP_InitMetadata(fPusherHandle, &mediainfo, 1024);
						b_init = true;
					}
				}

				if (b_init&&(naltype==0x05||naltype==0x01))
				{
					int nOffSet = 0;
					unsigned char btHeader[4];
					btHeader[0] = 0x00;
					btHeader[1] = 0x00;
					btHeader[2] = 0x00;
					btHeader[3] = 0x01;

					if (naltype==0x05)
					{
						memcpy(pSendBuf + nOffSet, btHeader, 4);
						nOffSet += 4;
						memcpy(pSendBuf + nOffSet, sps, sps_len);
						nOffSet += sps_len;
						memcpy(pSendBuf + nOffSet, btHeader, 4);
						nOffSet += 4;
						memcpy(pSendBuf + nOffSet, pps, pps_len);
						nOffSet += pps_len;
						memcpy(pSendBuf + nOffSet, btHeader, 4);
						nOffSet += 4;
						memcpy(pSendBuf + nOffSet, pbuf+4, framesize-4);
						nOffSet += framesize - 4;

					}
					else
					{						
						memcpy(pSendBuf, btHeader, 4);
						memcpy(pSendBuf + nOffSet, pbuf+4, framesize-4);
						nOffSet = framesize;
					}

					memset(&avFrame, 0x00, sizeof(EASY_AV_Frame));
					avFrame.u32AVFrameLen   =   nOffSet;
					avFrame.pBuffer = (unsigned char*)pSendBuf;
					avFrame.u32VFrameType = (naltype==0x05)?EASY_SDK_VIDEO_FRAME_I:EASY_SDK_VIDEO_FRAME_P;
					if (avFrame.u32VFrameType == EASY_SDK_VIDEO_FRAME_I)
					{
						avFrame.u32VFrameType = EASY_SDK_VIDEO_FRAME_I;
					}
					avFrame.u32AVFrameFlag = EASY_SDK_VIDEO_FRAME_FLAG;
					//avFrame.u32TimestampSec = timestamp/1000;
					//avFrame.u32TimestampUsec = (timestamp%1000)*1000;
					EasyRTMP_SendPacket(fPusherHandle, &avFrame);
					timestamp += 1000/mediainfo.u32VideoFps;
#ifndef _WIN32
					usleep(30*1000);
#else
					Sleep(30);
#endif
				}

                memmove(pbuf, pbuf+position-5, 5);
                position = 5;

                iFrameNo ++;

                //if (iFrameNo > 100000) break;
                //break;
            }
        }
    }

end:
    _TRACE("Press Enter exit...\n");
    getchar();

    EasyRTMP_Release(fPusherHandle);
    free(pbuf);
    return 0;
}
