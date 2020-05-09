 // DecCallBack_DemoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "EasyRTMP_HKSDK.h"
#include "EasyRTMP_HKSDKDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//////////////////////////////////////////////////////////////////////////
int iPicNum=0;//Set channel NO.
LONG nPort=-1;
FILE *Videofile=NULL;
FILE *Audiofile=NULL;
char filename[100];
CString ErrorNum;

//////////////////////////////////////////////////////////////////////////
// IP to String
CString IPToStr(DWORD dwIP)
{
	CString strIP = _T("");
	WORD add1,add2,add3,add4;
	
	add1=(WORD)(dwIP&255);
	add2=(WORD)((dwIP>>8)&255);
	add3=(WORD)((dwIP>>16)&255);
	add4=(WORD)((dwIP>>24)&255);
	strIP.Format("%d.%d.%d.%d",add4,add3,add2,add1);
	return strIP;
}
//////////////////////////////////////////////////////////////////////////
////解码回调 视频为YUV数据(YV12)，音频为PCM数据
void CALLBACK DecCBFun(long nPort,char * pBuf,long nSize,FRAME_INFO * pFrameInfo, long nReserved1,long nReserved2)
{
 	long lFrameType = pFrameInfo->nType;	
	if (lFrameType ==T_AUDIO16)
	{
//		TRACE("Audio nStamp:%d\n",pFrameInfo->nStamp);
// 		OutputDebugString("test_DecCb_Write Audio16 \n");
// 		if (Audiofile==NULL)
// 		{
// 			sprintf(filename,"..\\bin\\AudionPCM.pcm",iPicNum);
// 			Audiofile = fopen(filename,"wb");
// 		}
// 		fwrite(pBuf,nSize,1,Audiofile);
	}

	else if(lFrameType == T_YV12)
	{		
//	    TRACE("Video nStamp:%d\n",pFrameInfo->nStamp);
// 		OutputDebugString("test_DecCb_Write YUV \n");
// 		if (Videofile==NULL)
// 		{
// 			sprintf(filename,"..\\bin\\VideoYV12.yuv",iPicNum);
// 			Videofile = fopen(filename,"wb");
// 		}
// 		fwrite(pBuf,nSize,1,Videofile);
	}
	else
	{

	}
}


int CreateAndWriteDataToTxtFile(CString &filename, CString &msg)//FileWriteline
{
	CStdioFile m_TextFile;
	if(!m_TextFile.Open(filename,CFile::modeNoTruncate|CFile::modeWrite))
		return FALSE;
	m_TextFile.SeekToEnd();   
	int ansiCount=1;//WideCharToMultiByte(CP_ACP,0,msg,-1,NULL,0,NULL,NULL);
	//申请空间
//	char * pTempChar=(char*)malloc(ansiCount*sizeof(char));
//	memset(pTempChar,0,ansiCount);
	//转换字符
//	WideCharToMultiByte(CP_ACP,0,msg,-1,pTempChar,ansiCount,NULL,NULL);
//	m_TextFile.Write(pTempChar,strlen(pTempChar));
	m_TextFile.Write(msg,strlen(msg));
	m_TextFile.Write("\n",1);
//	free(pTempChar);
	m_TextFile.Close();
	return TRUE;
}

void CALLBACK StdDataCallBack(LONG lRealHandle, DWORD dwDataType, BYTE *pBuffer, DWORD dwBufSize, DWORD pUser)
{
	int nRet = -1;
	CDecCallBack_DemoDlg* pThis =  (CDecCallBack_DemoDlg* )pUser;
	switch (dwDataType)
	{
	case NET_DVR_SYSHEAD://coming the stream header, open stream
		{
			nRet = 1;
		}
		break;
	case NET_DVR_STD_VIDEODATA:
		{
			nRet = 4;
#if 0
			if (pThis->m_nCIndex<100)
			{		

				CString strFileName = _T("");
				strFileName.Format(_T("./Logfile/test_%d.txt"),pThis->m_nCIndex);
				BOOL bSuc = pThis->m_file.Open(strFileName,CFile::modeWrite | CFile::modeCreate|CFile::typeBinary);
				if (bSuc)
				{
					pThis->m_file.Write(pBuffer, dwBufSize);

					pThis->m_file.Close();
				}
			}	

			TRACE("m_nCIndex==%d\r\n", pThis->m_nCIndex);
			pThis->m_nCIndex++;
#endif
		}
		break;
	case NET_DVR_STD_AUDIODATA:
		{
			nRet = 5;
		}
		break;
	case NET_DVR_STREAMDATA:
		{
			nRet = 2;
// 			if (pThis->m_nCIndex<100)
// 			{		
// 
// 				CString strFileName = _T("");
// 				strFileName.Format(_T("./Logfile/test_%d.txt"),pThis->m_nCIndex);
// 				BOOL bSuc = pThis->m_file.Open(strFileName,CFile::modeWrite | CFile::modeCreate|CFile::typeBinary);
// 				if (bSuc)
// 				{
// 					pThis->m_file.Write(pBuffer, dwBufSize);
// 
// 					pThis->m_file.Close();
// 				}
// 			}	
// 
// 			TRACE("m_nCIndex==%d\r\n", pThis->m_nCIndex);
// 			pThis->m_nCIndex++;
 		}
		break;
	}
}

///实时流回调
void CALLBACK fRealDataCallBack(LONG lRealHandle,DWORD dwDataType,BYTE *pBuffer,DWORD dwBufSize,void *pUser)
{
	DWORD dRet;
	CDecCallBack_DemoDlg* pDemoDlg = (CDecCallBack_DemoDlg*)pUser;

	if (!pDemoDlg)
	{
		return ;
	}
	if (lRealHandle==0)
	{
		dRet = 0;
	}
	else if (lRealHandle==1)
	{
		dRet = 1;
	}

	pDemoDlg->ReceiveRealData(lRealHandle, dwDataType, pBuffer, dwBufSize, pUser);
}
//////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDecCallBack_DemoDlg dialog

CDecCallBack_DemoDlg::CDecCallBack_DemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDecCallBack_DemoDlg::IDD, pParent)
	, m_strUrl(_T(""))
	, m_nChangeId(0)
	, m_bDecord(FALSE)
	, m_bFilmMode(FALSE)
{
	//{{AFX_DATA_INIT(CDecCallBack_DemoDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_nfIndex = 0;
	m_sendrtmp = FALSE;
	m_strUrl = _T("rtmp://demo.easydss.com:10085/hls/test");

	for (int i=0; i<MAX_DEV+1; i++)
	{
		if(i<MAX_DEV)
		{
			for(int nI=0; nI<MAX_FRAME_LENTH; nI++)
			{
				memset(&m_pFrameCache[i][nI], 0x00, sizeof(CacheBuffder));
			}
			m_mFrameCacheLenth[i] = 0;
		}
		m_bwritevideoinfo[i] = FALSE;
	}

	m_bRtmpRunning = FALSE;
	m_bUseGPAC = TRUE;
	m_bInitAudio = FALSE;

	 m_rtmpresize = FALSE;
	//捕获数据
	 m_brtmpcapdata = FALSE;
	 m_hHandleRtmpThread=INVALID_HANDLE_VALUE;
	 m_WriteFileAndEncThrdHandle = INVALID_HANDLE_VALUE;
	 InitializeCriticalSection(&m_rtmpcs);
	 while (!m_queueframe.empty())
	 {
		 m_queueframe.pop();
	 }
	m_nKeyFCount = -1;
	 InitializeCriticalSection(&m_cs);
	 m_nCIndex = 0;
	 m_bWriting = TRUE;
	m_lCurTimeStamp = 0;

	m_nRecordDevFlag = -1;
	m_nPreRecordDevFlag = -1;
	m_bChangeWtKeyf = FALSE;
	m_nCountQueueVideoFrames = 0;
	m_nMaxQueueVideoFrames = MAX_QUEUE_FRAMECOUNT;
	m_bChange = FALSE;
	m_RtmpHandle = NULL;
}

void CDecCallBack_DemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDecCallBack_DemoDlg)
	// NOTE: the ClassWizard will add DDX and DDV calls here
	DDX_Control(pDX,IDC_STATIC_SCREEN,m_picplay);
	DDX_Text(pDX, IDC_EDIT_IPCH, iPChannel);
	DDX_Control(pDX, IDC_IPADDRESS, m_ctrlDeviceIP);
	DDX_Text(pDX, IDC_EDIT_Username, m_csUserName);
	DDX_Text(pDX, IDC_EDIT_Password, m_csPassword);
	DDX_Text(pDX, IDC_EDIT_Port, m_nLoginPort);
	//}}AFX_DATA_MAP
	DDX_Text(pDX, IDC_EDIT_URL, m_strUrl);
	DDX_Check(pDX, IDC_CHECK_WRITING, m_bWriting);
	DDX_Text(pDX, IDC_EDIT_ID, m_nChangeId);
	DDX_Check(pDX, IDC_CHECK_DECORD, m_bDecord);
	DDX_Check(pDX, IDC_CHECK_FILMMODE, m_bFilmMode);
}

BEGIN_MESSAGE_MAP(CDecCallBack_DemoDlg, CDialog)
	//{{AFX_MSG_MAP(CDecCallBack_DemoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_Login, OnBUTTONLogin)
	ON_BN_CLICKED(IDC_BUTTON_CAPTURE, OnButtonCapture)
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BTN_LINK, &CDecCallBack_DemoDlg::OnBnClickedBtnLink)
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_CHECK_WRITING, &CDecCallBack_DemoDlg::OnBnClickedCheckWriting)
	ON_BN_CLICKED(IDC_BTN_CHANGE, &CDecCallBack_DemoDlg::OnBnClickedBtnChange)
	ON_BN_CLICKED(IDC_CHECK_DECORD, &CDecCallBack_DemoDlg::OnBnClickedCheckDecord)
	ON_BN_CLICKED(IDC_CHECK_FILMMODE, &CDecCallBack_DemoDlg::OnBnClickedCheckFilmmode)
	ON_BN_CLICKED(IDOK, &CDecCallBack_DemoDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CDecCallBack_DemoDlg::OnBnClickedCancel)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDecCallBack_DemoDlg message handlers

BOOL CDecCallBack_DemoDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
    UpdateData(TRUE);
	NET_DVR_Init();

	for (int nI=0; nI<MAX_DEV; nI++)
	{
		m_llRealHandle[nI] = -1;
		m_lUserID[nI]	= -1;
		m_hPlayWnd[nI] = GetDlgItem(IDC_STATIC_SCREEN+nI)->m_hWnd;
	}

	iPChannel=1;

	m_ctrlDeviceIP.SetAddress(192, 168, 99, 193);
	m_csUserName="admin";
	m_csPassword="a1234567";
	m_nLoginPort=8000;

	m_nChangeId = 1;
	m_nRecordDevFlag = 1;

    UpdateData(FALSE);


	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDecCallBack_DemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CDecCallBack_DemoDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CDecCallBack_DemoDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CDecCallBack_DemoDlg::OnBUTTONLogin() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

	DWORD dwDeviceIP;
	char DeviceIP[16] = {0};
	char cUserName[100] = {0};
	char cPassword[100] = {0};
	CString csTemp;	


	strncpy(cUserName, m_csUserName, MAX_NAMELEN);
	strncpy(cPassword, m_csPassword, PASSWD_LEN);

	for (int nI=0; nI<m_nChangeId; nI++)
	{	
		//登录设备，需要设备IP、端口、用户名、密码 Login the device
		m_ctrlDeviceIP.GetAddress(dwDeviceIP);
		csTemp = IPToStr(dwDeviceIP);
		sprintf(DeviceIP, "%s", csTemp.GetBuffer(0));

		NET_DVR_DEVICEINFO_V30 devInfo;
		m_lUserID[nI] = NET_DVR_Login_V30(DeviceIP,m_nLoginPort,cUserName,cPassword,&devInfo);

		DWORD dwReturned = 0;

		if(m_lUserID[nI]<0)
			AfxMessageBox("Login failed!");
		else
		{
			AfxMessageBox("Login successfully!");
		}
	}

	UpdateData(FALSE);
	return;
}


void CDecCallBack_DemoDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	for (int nI=0; nI<MAX_DEV; nI++)
	{	
		if(m_llRealHandle[nI]>=0)
		{
			AfxMessageBox("Stop preview!");
			return;
		}

		NET_DVR_Logout_V30(m_lUserID[nI]);
		NET_DVR_Cleanup();	
	}
	CDialog::OnCancel();
}

void CDecCallBack_DemoDlg::OnButtonCapture() 
{
	// TODO: Add your control notification handler code here
	FILE *file=NULL;

	NET_DVR_JPEGPARA JpegPara;
    JpegPara.wPicQuality=0;
    JpegPara.wPicSize=0xff;

	char *JpegPicBuffer= new char[352*288*2] ;
	DWORD  SizeReturned=0;

	
	BOOL bRet= NET_DVR_CaptureJPEGPicture_NEW(m_lUserID[0], iPChannel,&JpegPara,JpegPicBuffer,352*288*2,&SizeReturned);
	if (!bRet)
	{
		ErrorNum.Format("NET_DVR_CaptureJPEGPicture_NEW failed! Error number: %d\n",NET_DVR_GetLastError());
		AfxMessageBox(ErrorNum);
		return;
	}
	else
	{
		AfxMessageBox("NET_DVR_CaptureJPEGPicture_NEW successful");
	}

	if (file==NULL)
	{
		sprintf(filename,"JPEGCAPTest_%d.jpg",iPicNum);
		file = fopen(filename,"wb");
	}
    fwrite(JpegPicBuffer,SizeReturned,1,file);
    iPicNum++;

	delete JpegPicBuffer;
    fclose(file);
    file=NULL;

	return;
}

void CDecCallBack_DemoDlg::OnBnClickedBtnLink()
{
	// TODO: Add your control notification handler code here
	UpdateData();
	m_nKeyFCount = -1;
	m_sendrtmp = !m_sendrtmp;
	if(m_sendrtmp)
	{	
		LinkRtmp();
		m_bRtmpRunning = TRUE;
		GetDlgItem(IDC_BTN_LINK)->SetWindowText("Stop");

	}
	else
	{
		CloseRtmp();
		m_bRtmpRunning = FALSE;
		GetDlgItem(IDC_BTN_LINK)->SetWindowText("PushRtmp");

	}
}

void CDecCallBack_DemoDlg::OnDestroy()
{
	CDialog::OnDestroy();

	for (int i=0; i<MAX_DEV; i++)
	{
		for(int nI=0; nI<MAX_FRAME_LENTH; nI++)
		{
			if (m_pFrameCache[i][nI].pCacheBuffer)
			{	
				delete []m_pFrameCache[i][nI].pCacheBuffer;
				m_pFrameCache[i][nI].pCacheBuffer = NULL;
			}
		}
	}

}

//从PS流中取H264数据
//返回值：是否为数据包 
BOOL CDecCallBack_DemoDlg::GetH246FromPS(IN BYTE* pBuffer, IN int nBufLenth, BYTE** pH264, int& nH264Lenth, BOOL& bVideo)
{
	if (!pBuffer || nBufLenth<=0)
	{
		return FALSE;
	}

	BYTE* pH264Buffer = NULL;
	int nHerderLen = 0;
	
	if( pBuffer
		&& pBuffer[0]==0x00
		&& pBuffer[1]==0x00 
		&& pBuffer[2]==0x01
		&& pBuffer[3]==0xE0)//E==视频数据(此处E0标识为视频)
	{
		bVideo = TRUE;
		nHerderLen = 9 + (int)pBuffer[8];//9个为固定的数据包头长度，pBuffer[8]为填充头部分的长度
		pH264Buffer = pBuffer+nHerderLen;
		if (*pH264 == NULL)
		{
			*pH264 = new BYTE[nBufLenth];
		}
		if (*pH264&&pH264Buffer&&(nBufLenth-nHerderLen)>0)
		{	
			memcpy(*pH264, pH264Buffer, (nBufLenth-nHerderLen));
		}	
		nH264Lenth = nBufLenth-nHerderLen;
	
		return TRUE;
	}	
	else if(pBuffer 
		&& pBuffer[0]==0x00
		&& pBuffer[1]==0x00
		&& pBuffer[2]==0x01
		&& pBuffer[3]==0xC0) //C==音频数据？
	{
		*pH264 = NULL;
		nH264Lenth = 0;
		bVideo = FALSE;
	}
	else if(pBuffer 
		&& pBuffer[0]==0x00
		&& pBuffer[1]==0x00
		&& pBuffer[2]==0x01
		&& pBuffer[3]==0xBA)//视频流数据包 包头
	{
		bVideo = TRUE;
		*pH264 = NULL;
		nH264Lenth = 0;
		return FALSE;
	}
	return FALSE;
}


//实时数据回调函数---来自于本地音视频采集
//typedef int (WINAPI *RealDataCallback)(int nDevId, unsigned char *pBuffer, int nBufSize, 
//RealDataStreamType realDataType, void* realDataInfo, void* pMaster);
int  CDecCallBack_DemoDlg::RealDataCallbackFuncEx(int lRealHandle, BYTE *pBuffer,DWORD dwBufSize, DWORD dwDataType, void* lParam, void* dwUser)
{
	if (!pBuffer || dwBufSize <= 0)
	{
		return -1;
	}
	CDecCallBack_DemoDlg* pThis = (CDecCallBack_DemoDlg*)dwUser;
	void* pDataParam = (void*)lParam;
	if (pThis)
	{
		pThis->ReceiveRealData(lRealHandle,dwDataType, pBuffer, dwBufSize, pDataParam);
	}

	return 0;
}

void CDecCallBack_DemoDlg::ReceiveRealData(LONG lRealHandle, DWORD dwDataType, BYTE *pBuffer, DWORD dwBufSize, void* pDataParam)
{
	if (lRealHandle>=0)
	{
		DWORD dRet = 0;
		switch (dwDataType)
		{
		case NET_DVR_SYSHEAD:
			{
				if (!PlayM4_GetPort(&nPort))
				{
					break;
				}
				if (!PlayM4_OpenStream(nPort,pBuffer,dwBufSize,1024*1024))
				{
					dRet=PlayM4_GetLastError(nPort);
					break;
				}

				//设置解码回调函数 只解码不显示
				// 		if (!PlayM4_SetDecCallBack(nPort,DecCBFun))
				// 		{
				// 			dRet=PlayM4_GetLastError(nPort);
				// 			break;
				// 		}

				//设置解码回调函数 解码且显示
				if (!PlayM4_SetDecCallBackEx(nPort,DecCBFun,NULL,NULL))
				{
					dRet=PlayM4_GetLastError(nPort);
					break;
				}
				
				HWND hPlayWnd = GetDlgItem(IDC_STATIC_SCREEN)->GetSafeHwnd();
				//打开视频解码
				if (!PlayM4_Play(nPort,hPlayWnd))
				{
					dRet=PlayM4_GetLastError(nPort);
					break;
				}

				//打开音频解码, 需要码流是复合流
				if (!PlayM4_PlaySound(nPort))
				{
					dRet=PlayM4_GetLastError(nPort);
					break;
				}
			}

			break;

		case NET_DVR_STREAMDATA:
			{
				BOOL inData=PlayM4_InputData(nPort,pBuffer,dwBufSize);
				while (!inData)
				{
					Sleep(10);
					inData=PlayM4_InputData(nPort,pBuffer,dwBufSize);
					OutputDebugString("PlayM4_InputData failed \n");	
				}	
				//return ;
				//PS流数据解析处理		
				{
					int nI = 0;
					int nCacheSize = 0;
					nI = m_mFrameCacheLenth[lRealHandle];

					//直接--提取H264数据
					BOOL bVideo = FALSE;
					BOOL bPatialData = FALSE;
					bPatialData = GetH246FromPS(pBuffer,dwBufSize, &m_pFrameCache[lRealHandle][nI].pCacheBuffer, 
						m_pFrameCache[lRealHandle][nI].nCacheBufLenth, bVideo);

					if (bVideo)
					{
						if (bPatialData)//部分包数据
						{
							//缓存数据
							m_pFrameCache[lRealHandle][nI].lTimeStamp = clock();
							m_mFrameCacheLenth[lRealHandle]++;
						} 
						else//包头
						{
							int i = 0;
							if(m_mFrameCacheLenth[lRealHandle]>0)
							{
								long lH264DataLenth = m_mFrameCacheLenth[lRealHandle]*MAX_PACK_SIZE;
								BYTE* pH264Nal =  NULL;
								pH264Nal = new BYTE[lH264DataLenth];
								memset(pH264Nal, 0x00, lH264DataLenth);
								BYTE* pTempBuffer = pH264Nal;
								int nTempBufLenth = 0;

								//TRACE("m_mFrameCacheLenth==%d\r\n", pDemoDlg->m_mFrameCacheLenth);

								// 最大缓存数据个数设为pDemoDlg->m_mFrameCacheLenth，程序会过程中报错，Why? [5/6/2014-13:19:51 Dingshuai]
								for (i=0; i</*MAX_FRAME_LENTH*/m_mFrameCacheLenth[lRealHandle]; i++)
								{
									if(m_pFrameCache[lRealHandle][i].pCacheBuffer!=NULL&&m_pFrameCache[lRealHandle][i].nCacheBufLenth>0)
									{
										// 										memcpy(pTempBuffer, m_pFrameCache[i].pCacheBuffer, m_pFrameCache[i].nCacheBufLenth);
										// 										pTempBuffer = pTempBuffer + m_pFrameCache[i].nCacheBufLenth;

										memcpy(pH264Nal+nTempBufLenth, m_pFrameCache[lRealHandle][i].pCacheBuffer, 
											m_pFrameCache[lRealHandle][i].nCacheBufLenth);
										nTempBufLenth += m_pFrameCache[lRealHandle][i].nCacheBufLenth;
									}
									if (m_pFrameCache[lRealHandle][i].pCacheBuffer)
									{
										delete [](m_pFrameCache[lRealHandle][i].pCacheBuffer);
										m_pFrameCache[lRealHandle][i].pCacheBuffer = NULL;
									}	
									m_pFrameCache[lRealHandle][i].nCacheBufLenth = 0; 
								}

								if (m_bRtmpRunning && pH264Nal && nTempBufLenth>0)
								{

// 										//m_rtmp.WriteVideoH264(pH264Nal,nTempBufLenth, m_pFrameCache[0].lTimeStamp/*clock()*/, 0);
// 										if (m_brtmpcapdata)
// 										{
// 											EnterCriticalSection(&m_rtmpcs);
// 											FrameInfo *pTmpinfo;
// 											pTmpinfo=new FrameInfo;
// 											pTmpinfo->pDataBuffer=new unsigned char[nTempBufLenth];
// 											memcpy(pTmpinfo->pDataBuffer,pH264Nal,nTempBufLenth);
// 											pTmpinfo->nTimestamp = clock();//m_pFrameCache[0].lTimeStamp;
// 											pTmpinfo->nBufSize=nTempBufLenth;//m_pEncConfigInfo->nRtmpVideoWidth*m_pEncConfigInfo->nRtmpVideoHeight*3/2;
// 											pTmpinfo->bIsVideo=TRUE;
// 											pTmpinfo->nID=0;		
// 											m_queuertmpframe.push(pTmpinfo);
// 											LeaveCriticalSection(&m_rtmpcs);
// 										}
// 
// 										//WriteMp4File(pH264Nal, nTempBufLenth, 0, /*m_pFrameCache[0].lTimeStamp*/clock());
// 										if (m_pmp4file && m_bRtmpRunning)
// 										{	
// 											FrameInfo* pTmpinfo = NULL;
// 											pTmpinfo = new FrameInfo;
// 											pTmpinfo->pDataBuffer= new unsigned char[nTempBufLenth];
// 
// 											if (pTmpinfo->pDataBuffer)
// 											{
// 												memcpy(pTmpinfo->pDataBuffer, pH264Nal,nTempBufLenth);
// 											}
// 											pTmpinfo->nBufSize	 = nTempBufLenth;
// 											pTmpinfo->bIsVideo	 = TRUE;
// 											pTmpinfo->nID		 = 0;
// 											pTmpinfo->bKeyFrame  = 0;
// 
// 											EnterCriticalSection(&m_cs);
// 											pTmpinfo->nTimestamp = clock();//m_pFrameCache[0].lTimeStamp;//clock();
// 											m_queueframe.push(pTmpinfo);
// 											LeaveCriticalSection(&m_cs);
// 										}

									BOOL bIsKeyFrame = FALSE;
									//查找是否为关键帧
									if(pH264Nal[4]==0x67)
									{
										bIsKeyFrame = TRUE;
									}
									long lTimeStamp = clock();
									WriteH264DataToChace(lRealHandle, pH264Nal, nTempBufLenth, bIsKeyFrame, lTimeStamp);
								}

								if (pH264Nal)
								{
									delete []pH264Nal;
									pH264Nal = NULL;
								}
								// 缓存数据个数 清0
								m_mFrameCacheLenth[lRealHandle] = 0;
							}
						}
					}
				}
			}
			break;
		}	
	}
}

/* EasyRTMP回调 */
int __EasyRTMP_Callback(int _frameType, char *pBuf, EASY_RTMP_STATE_T _state, void *_userPtr)
{
	if (_state == EASY_RTMP_STATE_CONNECTING)               printf("Connecting...\n");
	else if (_state == EASY_RTMP_STATE_CONNECTED)           printf("Connected\n");
	else if (_state == EASY_RTMP_STATE_CONNECT_FAILED)      printf("Connect failed\n");
	else if (_state == EASY_RTMP_STATE_CONNECT_ABORT)       printf("Connect abort\n");
	else if (_state == EASY_RTMP_STATE_DISCONNECTED)        printf("Disconnect.\n");

	return 0;
}

bool CDecCallBack_DemoDlg::LinkRtmp()
{
	if (m_bRtmpRunning)
	{
		return false;
	}

	int isActivated = EasyRTMP_Activate(KEY);
	if(isActivated <= 0)
	{
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
		return -1;
	}

	m_RtmpHandle = EasyRTMP_Create();

	if(m_RtmpHandle == NULL)
		return -2;

	EasyRTMP_SetCallback(m_RtmpHandle, __EasyRTMP_Callback, NULL);
	EasyRTMP_Connect(m_RtmpHandle, m_strUrl.GetBuffer(m_strUrl.GetLength()));

	EASY_MEDIA_INFO_T   mediainfo;
	memset(&mediainfo, 0x00, sizeof(EASY_MEDIA_INFO_T));
	mediainfo.u32VideoCodec =   EASY_SDK_VIDEO_CODEC_H264;
	mediainfo.u32VideoFps = 25;
// 	mediainfo.u32SpsLength = videoInfo.sps->sequenceParameterSetLength;
// 	mediainfo.u32PpsLength = videoInfo.pps->pictureParameterSetLength;
// 	if (videoInfo.sps->sequenceParameterSetNALUnit && videoInfo.sps->sequenceParameterSetLength>0 )
// 	{
// 		memcpy(mediainfo.u8Sps, videoInfo.sps->sequenceParameterSetNALUnit, mediainfo.u32SpsLength);
// 	}
// 	if (videoInfo.pps->pictureParameterSetNALUnit && videoInfo.pps->pictureParameterSetLength>0 )
// 	{
// 		memcpy(mediainfo.u8Pps, videoInfo.pps->pictureParameterSetNALUnit, mediainfo.u32PpsLength);
// 	}

	mediainfo.u32AudioCodec =   EASY_SDK_AUDIO_CODEC_AAC;
	mediainfo.u32AudioSamplerate = 8000;
	mediainfo.u32AudioChannel = 1;

	int iRet = EasyRTMP_InitMetadata(m_RtmpHandle, &mediainfo, 1024);
	if (iRet < 0)
	{
		//printf("Fail to InitMetadata ...\n");
	}


	return true;
}

void CDecCallBack_DemoDlg::CloseRtmp()
{
	if(m_bRtmpRunning==TRUE)
	{
		EasyRTMP_Release(m_RtmpHandle);
		m_RtmpHandle = 0;

	}
}


void CDecCallBack_DemoDlg::OnBnClickedCheckWriting()
{
	// TODO: Add your control notification handler code here
	UpdateData();
}

//H264数据写入写文件缓存队列
int CDecCallBack_DemoDlg::WriteH264DataToChace(int nDevId, BYTE* pBuffer, int nBufSize, BOOL bIsKeyFrame, long lTimeStamp)
{
	if (!pBuffer || nBufSize<=0 || lTimeStamp<0)
	{
		return -1;
	}

	BOOL bKeyFrame  = bIsKeyFrame;
	int nDeviceType = nDevId+1;
	if (m_RtmpHandle && m_bRtmpRunning)
	{
		//H264推送RTMP
		EASY_AV_Frame	avFrame;
		memset(&avFrame, 0x00, sizeof(EASY_AV_Frame));

		avFrame.pBuffer = (unsigned char*)pBuffer;
		avFrame.u32AVFrameLen = nBufSize;
		avFrame.u32VFrameType = (bKeyFrame)?EASY_SDK_VIDEO_FRAME_I:EASY_SDK_VIDEO_FRAME_P;
		avFrame.u32AVFrameFlag = EASY_SDK_VIDEO_FRAME_FLAG;
		//avFrame.u32TimestampSec = lTimeStamp/1000000;
		//avFrame.u32TimestampUsec = (lTimeStamp%1000000);

		//EnterCriticalSection(&m_cs);
		EasyRTMP_SendPacket(m_RtmpHandle, &avFrame);	
	}

	return 1;
}

//写入数据到队列
int CDecCallBack_DemoDlg::WriteFilePushData(BYTE* pBuffer, int nBufSize, int nId, BOOL bVideo, BOOL bKeyFrame, long lTimeStamp)
{
	if (!pBuffer || nBufSize<=0)
	{
		return -1;
	}
	EnterCriticalSection(&m_cs);
	FrameInfo* pTmpinfo = NULL;
	pTmpinfo = new FrameInfo;
	pTmpinfo->pDataBuffer= new unsigned char[nBufSize];

	if (pTmpinfo->pDataBuffer)
	{
		memcpy(pTmpinfo->pDataBuffer, pBuffer, nBufSize);
	}
	pTmpinfo->nBufSize	 = nBufSize;
	pTmpinfo->bIsVideo	 = bVideo;
	pTmpinfo->nID		 = nId;
	pTmpinfo->bKeyFrame  = bKeyFrame;

	pTmpinfo->nTimestamp=lTimeStamp;
	m_queueframe.push(pTmpinfo);
	m_nCountQueueVideoFrames++;
	LeaveCriticalSection(&m_cs);

	return 1;
}

//模拟窗口切换
void CDecCallBack_DemoDlg::OnBnClickedBtnChange()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	m_bChange = !m_bChange;
	int lCurDevId = 1;
	if (!m_bChange)
	{
		lCurDevId = 1;
	}
	else
	{
		lCurDevId = 2;
	}

	if(lCurDevId != m_nRecordDevFlag)//1-N
	{
		if (FALSE == m_bChangeWtKeyf)
		{
			m_nPreRecordDevFlag = m_nRecordDevFlag;
			m_bChangeWtKeyf = TRUE;
		}
		m_nRecordDevFlag = lCurDevId;
	}
}

void CDecCallBack_DemoDlg::OnBnClickedCheckDecord()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
}

void CDecCallBack_DemoDlg::OnBnClickedCheckFilmmode()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
}


void CDecCallBack_DemoDlg::OnBnClickedOk()
{
	// TODO: ÔÚ´ËÌí¼Ó¿Ø¼þÍ¨Öª´¦Àí³ÌÐò´úÂë
	//CDialog::OnOK();
	// 
	BOOL bRet1;
	UpdateData(TRUE);

	//设置本地音频回调
	int nAudioId = 0;
	int nChannaels = 2;
	int nBytesPerSample = 16;
	int nSampleRate = 44100;
	int nAudioBufferType = 4096;//2048;//4096;
	int nPinType = 2;
	BOOL bUseThread = FALSE;

	int nRet = 0;
	CString strTemp = _T("");

	UpdateData(TRUE);

	for (int nI=0; nI<m_nChangeId; nI++)
	{
		if (m_llRealHandle[nI]<0)
		{

			if (m_lUserID[nI]<0)
			{
				ErrorNum.Format("Login failed Error number ：%d\n",NET_DVR_GetLastError());
				OutputDebugString(ErrorNum);
			}

			//////////////////////////////////////////////////////////////////////////
			NET_DVR_PREVIEWINFO struPlayInfo = {0};
			if (m_bDecord)
			{	
				struPlayInfo.hPlayWnd = m_hPlayWnd[nI];         //需要SDK解码时句柄设为有效值，仅取流不解码时可设为空
			}
			else
			{
				struPlayInfo.hPlayWnd = NULL;
			}
			struPlayInfo.lChannel     = 1;       //预览通道号
			struPlayInfo.dwStreamType = 0;       //0-主码流，1-子码流，2-码流3，3-码流4，以此类推
			struPlayInfo.dwLinkMode   = 0;       //0- TCP方式，1- UDP方式，2- 多播方式，3- RTP方式，4-RTP/RTSP，5-RSTP/HTTP


			//预览取流 
			///NET_DVR_RealPlay_V40 启动预览函数
			m_llRealHandle[nI] = NET_DVR_RealPlay_V40(m_lUserID[nI],&struPlayInfo,fRealDataCallBack, this);

			if (m_llRealHandle[nI]<0)
			{
				ErrorNum.Format("NET_DVR_RealPlay_V40 failed! Error number: %d\n",NET_DVR_GetLastError());
				AfxMessageBox(ErrorNum);
				return;
			}

			//设置标准音视频数据回调
			BOOL bSuc = FALSE;
			bSuc = NET_DVR_SetStandardDataCallBack(m_llRealHandle[nI], StdDataCallBack, (DWORD)this);	

			GetDlgItem(IDOK)->SetWindowText("Stop");
		}
		else
		{	
			//停止预览
			if (NET_DVR_StopRealPlay(m_llRealHandle[nI]))
			{
				bRet1=NET_DVR_GetLastError();
			}		

			m_llRealHandle[nI]=-1;

			//停止解码
			if (nPort>-1)
			{
				if (!PlayM4_StopSound())
				{
					bRet1=PlayM4_GetLastError(nPort);
				}
				if (!PlayM4_Stop(nPort))
				{
					bRet1=PlayM4_GetLastError(nPort);
				}
				if (!PlayM4_CloseStream(nPort))
				{
					bRet1=PlayM4_GetLastError(nPort);
				}
				PlayM4_FreePort(nPort);
				nPort=-1;
			}		

			//关闭保存解码后数据的音视频文件
			if (Audiofile!=NULL)
			{
				fclose(Audiofile);
				Audiofile=NULL;
			}

			if (Videofile!=NULL)
			{
				fclose(Videofile);
				Videofile=NULL;
			}		

			GetDlgItem(IDOK)->SetWindowText("Start Play");
		}
	}

	UpdateData(FALSE);
}


void CDecCallBack_DemoDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialog::OnCancel();
}
