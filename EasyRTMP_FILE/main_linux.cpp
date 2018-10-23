/*
	Copyright (c) 2013-2014 EasyDarwin.ORG.  All rights reserved.
	Github: https://github.com/EasyDarwin
	WEChat: EasyDarwin
	Website: http://www.EasyDarwin.org
*/
#include "EasyRTMPAPI.h"
#include "trace.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#include "getopt.h"
#define KEY "79397037795969576B5A73414538316270444C737065354659584E35556C524E55463947535578464C6D56345A56634D5671442F70654E4659584E355247467964326C755647566862556C7A5647686C516D567A644541794D4445345A57467A65513D3D"
#else
#include "unistd.h"
#include <signal.h>
#define KEY "7939703779662B2B72624B415A4D3562704447624A664A6C59584E35636E52746346396D6157786C567778576F502B6C3430566863336C4559584A33615735555A57467453584E55614756435A584E30514449774D54686C59584E35"
#endif

char* SRTMP=    "rtmp://demo.easydss.com/hls/stream"; //Default RTMP Push StreamName
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
void PrintUsage()
{
    printf("Usage:\n");
    printf("------------------------------------------------------\n");
    printf("%s [-n <streamName>]\n", ProgName);
    printf("Help Mode:   %s -h \n", ProgName );
    printf("For example: %s -n rtmp://127.0.0.1/live/stream\n", ProgName); 
    printf("------------------------------------------------------\n");
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
    Easy_RTMP_Handle fPusherHandle = 0;
    EASY_MEDIA_INFO_T   mediainfo;

    int buf_size = 1024*512;
    char *pbuf = (char *) malloc(buf_size);
    FILE *fES = NULL;
    int position = 0;
    int iFrameNo = 0;
    int timestamp = 0;
    ProgName = argv[0];
    PrintUsage();


    while ((ch = getopt(argc,argv, "hd:p:n:")) != EOF) 
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
    	case '?':
    		return 0;
    		break;
    	default:
    		break;
    	}
    }

    fES = fopen("./test.h264", "rb");
    if (NULL == fES)        return 0;

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

    fPusherHandle = EasyRTMP_Create();

    if(fPusherHandle == NULL)
        return -2;

    EasyRTMP_SetCallback(fPusherHandle, __EasyRTMP_Callback, NULL);

    EasyRTMP_Connect(fPusherHandle, SRTMP);
    
    memset(&mediainfo, 0x00, sizeof(EASY_MEDIA_INFO_T));
    mediainfo.u32VideoCodec =   EASY_SDK_VIDEO_CODEC_H264;
    mediainfo.u32VideoFps = 25;
    EasyRTMP_InitMetadata(fPusherHandle, &mediainfo, 1024);

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
            	(naltype == 0x07 || naltype == 0x01 ) )
            {
                int framesize = position - 5;
                EASY_AV_Frame   avFrame;

                naltype = (unsigned char)pbuf[4] & 0x1F;

                memset(&avFrame, 0x00, sizeof(EASY_AV_Frame));
                avFrame.u32AVFrameLen   =   framesize;
                avFrame.pBuffer = (unsigned char*)pbuf;
                avFrame.u32VFrameType = (naltype==0x07)?EASY_SDK_VIDEO_FRAME_I:EASY_SDK_VIDEO_FRAME_P;
                avFrame.u32AVFrameFlag = EASY_SDK_VIDEO_FRAME_FLAG;
                avFrame.u32TimestampSec = timestamp/1000;
                avFrame.u32TimestampUsec = (timestamp%1000)*1000;
                EasyRTMP_SendPacket(fPusherHandle, &avFrame);
                timestamp += 1000/mediainfo.u32VideoFps;

                #ifndef _WIN32
                usleep(30*1000);
                #else
                Sleep(30);
                #endif
                memmove(pbuf, pbuf+position-5, 5);
                position = 5;

                iFrameNo ++;

                //if (iFrameNo > 100000) break;
                //break;
            }
        }
    }

    _TRACE("Press Enter exit...\n");
    getchar();

    EasyRTMP_Release(fPusherHandle);
    free(pbuf);
    return 0;
}
