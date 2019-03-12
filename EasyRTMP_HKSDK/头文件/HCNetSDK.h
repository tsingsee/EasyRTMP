#ifndef _HC_NET_SDK_H_
#define _HC_NET_SDK_H_

#ifndef __PLAYRECT_defined
#define __PLAYRECT_defined
typedef struct __PLAYRECT
{
    int x;                               
    int y;                                  
    int uWidth;                            
    int uHeight;                            
}PLAYRECT;
#endif

#if (defined(_WIN32)) //windows
#define NET_DVR_API  extern "C"__declspec(dllimport)
typedef  unsigned __int64 UINT64;
#elif defined(__linux__) || defined(__APPLE__) //linux
typedef     unsigned int    DWORD;
typedef     unsigned short  WORD;
typedef     unsigned short  USHORT;
typedef     int             LONG;
typedef  	unsigned char	BYTE ;
#define     BOOL int
typedef     unsigned int   	UINT;
typedef 	void* 			LPVOID;
typedef 	void* 			HANDLE;
typedef     unsigned int*  LPDWORD; 
typedef  unsigned long long UINT64;

#ifndef    TRUE
#define    TRUE	1
#endif
#ifndef    FALSE
#define	   FALSE 0
#endif
#ifndef    NULL
#define	   NULL 0
#endif

#define __stdcall 
#define CALLBACK  

#define NET_DVR_API extern "C"
typedef unsigned int   COLORKEY;
typedef unsigned int   COLORREF;

#ifndef __HWND_defined
#define __HWND_defined
	#if defined(__linux__)
		typedef unsigned int HWND;
	#else
		typedef void* HWND;
	#endif
#endif

#define NET_DVR_API extern "C"
typedef unsigned int   COLORKEY; 
typedef unsigned int   COLORREF; 

#ifndef __HDC_defined
#define __HDC_defined
    #if defined(__linux__)
    typedef struct __DC
    {
            void*   surface;        //SDL Surface
            HWND    hWnd;           // HDC window handle
    }DC;
    typedef DC* HDC;
    #else
    typedef void* HDC;
    #endif
#endif

typedef struct tagInitInfo
{
	int uWidth; 
	int uHeight; 
}INITINFO; 
#endif

//宏定义
#define MAX_NAMELEN			    16		//DVR本地登陆名
#define MAX_RIGHT			    32		//设备支持的权限（1-12表示本地权限，13-32表示远程权限）
#define NAME_LEN			    32      //用户名长度
#define PASSWD_LEN			    16      //密码长度
#define GUID_LEN				16      //GUID长度
#define DEV_TYPE_NAME_LEN		24      //设备类型名称长度
#define SERIALNO_LEN		    48      //序列号长度
#define MACADDR_LEN			    6       //mac地址长度
#define MAX_ETHERNET		    2       //设备可配以太网络
#define MAX_NETWORK_CARD        4       //设备可配最大网卡数目
#define PATHNAME_LEN		    128     //路径长度
#define MAX_PRESET_V13          16      //预置点
#define MAX_NUMBER_LEN			32		//号码最大长度
#define MAX_NAME_LEN			128		//设备名称最大长度
#define MAX_INDEX_LED           8       //LED索引最大值 2013-11-19

//2013-11-19
#define MAX_DEVNAME_LEN         32      //设备名称最大长度
#define MAX_LED_INFO            256     //屏幕字体显示信息最大长度
#define MAX_TIME_LEN            32      //时间最大长度
#define MAX_CARD_LEN            24      //卡号最大长度
#define MAX_OPERATORNAME_LEN    32      //操作人员名称最大长度

//异步登录回调状态宏定义
#define ASYN_LOGIN_SUCC			1		//异步登录成功
#define ASYN_LOGIN_FAILED		0		//异步登录失败


#define MAX_TIMESEGMENT_V30	    8       //9000设备最大时间段数
#define MAX_TIMESEGMENT		    4       //8000设备最大时间段数
#define MAX_ICR_NUM             8       //抓拍机红外滤光片预置点数2013-07-09

#define MAX_SHELTERNUM			4       //8000设备最大遮挡区域数
#define MAX_DAYS				7       //每周天数
#define PHONENUMBER_LEN			32      //pppoe拨号号码最大长度

#define MAX_DISKNUM_V30			33		//9000设备最大硬盘数/* 最多33个硬盘(包括16个内置SATA硬盘、1个eSATA硬盘和16个NFS盘) */
#define MAX_DISKNUM		        16      //8000设备最大硬盘数
#define MAX_DISKNUM_V10		    8       //1.2版本之前版本

#define MAX_WINDOW_V30			32      //9000设备本地显示最大播放窗口数
#define MAX_WINDOW_V40			64      //Netra 2.3.1扩展
#define MAX_WINDOW				16      //8000设备最大硬盘数
#define MAX_VGA_V30				4       //9000设备最大可接VGA数
#define MAX_VGA			    	1       //8000设备最大可接VGA数

#define MAX_USERNUM_V30			32      //9000设备最大用户数
#define MAX_USERNUM			    16      //8000设备最大用户数
#define MAX_EXCEPTIONNUM_V30	32      //9000设备最大异常处理数
#define MAX_EXCEPTIONNUM		16      //8000设备最大异常处理数
#define MAX_LINK				6       //8000设备单通道最大视频流连接数
#define MAX_ITC_EXCEPTIONOUT	32      //抓拍机最大报警输出

#define MAX_DECPOOLNUM			4       //单路解码器每个解码通道最大可循环解码数
#define MAX_DECNUM				4       //单路解码器的最大解码通道数（实际只有一个，其他三个保留）
#define MAX_TRANSPARENTNUM		2       //单路解码器可配置最大透明通道数
#define MAX_CYCLE_CHAN			16      //单路解码器最大轮巡通道数
#define MAX_CYCLE_CHAN_V30      64      //最大轮巡通道数（扩展）
#define MAX_DIRNAME_LENGTH		80      //最大目录长度
#define MAX_WINDOWS				16      //最大窗口数


#define MAX_STRINGNUM_V30		8		//9000设备最大OSD字符行数数
#define MAX_STRINGNUM			4       //8000设备最大OSD字符行数数
#define MAX_STRINGNUM_EX		8       //8000定制扩展
#define MAX_AUXOUT_V30			16      //9000设备最大辅助输出数
#define MAX_AUXOUT			    4       //8000设备最大辅助输出数
#define MAX_HD_GROUP			16      //9000设备最大硬盘组数
#define MAX_HD_GROUP_V40    	32      //设备最大硬盘组数
#define MAX_NFS_DISK			8       //8000设备最大NFS硬盘数

#define IW_ESSID_MAX_SIZE	    32      //WIFI的SSID号长度
#define IW_ENCODING_TOKEN_MAX	32      //WIFI密锁最大字节数
#define MAX_SERIAL_NUM			64	    //最多支持的透明通道路数
#define MAX_DDNS_NUMS	        10      //9000设备最大可配ddns数
#define MAX_DOMAIN_NAME		    64		/* 最大域名长度 */
#define MAX_EMAIL_ADDR_LEN	    48      //最大email地址长度
#define MAX_EMAIL_PWD_LEN		32      //最大email密码长度

#define MAXPROGRESS		        100     //回放时的最大百分率
#define MAX_SERIALNUM	        2       //8000设备支持的串口数 1-232， 2-485
#define CARDNUM_LEN		        20      //卡号长度
#define CARDNUM_LEN_OUT			32      //外部结构体卡号长度
#define MAX_VIDEOOUT_V30        4       //9000设备的视频输出数
#define MAX_VIDEOOUT	        2       //8000设备的视频输出数

#define MAX_PRESET_V30			256		/* 9000设备支持的云台预置点数 */
#define MAX_TRACK_V30			256		/* 9000设备支持的云台轨迹数 */
#define MAX_CRUISE_V30			256		/* 9000设备支持的云台巡航数 */
#define MAX_PRESET				128		/* 8000设备支持的云台预置点数 */
#define MAX_TRACK				128		/* 8000设备支持的云台轨迹数 */
#define MAX_CRUISE				128		/* 8000设备支持的云台巡航数 */

#define CRUISE_MAX_PRESET_NUMS	32 	    /* 一条巡航最多的巡航点 */

#define MAX_SERIAL_PORT         8       //9000设备支持232串口数
#define MAX_PREVIEW_MODE        8       /* 设备支持最大预览模式数目 1画面,4画面,9画面,16画面.... */
#define MAX_MATRIXOUT           16      /* 最大模拟矩阵输出个数 */
#define LOG_INFO_LEN            11840   /* 日志附加信息 */
#define DESC_LEN                16      /* 云台描述字符串长度 */
#define PTZ_PROTOCOL_NUM        200     /* 9000最大支持的云台协议数 */

#define MAX_AUDIO			    1       //8000语音对讲通道数
#define MAX_AUDIO_V30			2       //9000语音对讲通道数
#define MAX_CHANNUM			    16      //8000设备最大通道数
#define MAX_ALARMIN			    16      //8000设备最大报警输入数
#define MAX_ALARMOUT		    4       //8000设备最大报警输出数
//9000 IPC接入
#define MAX_ANALOG_CHANNUM      32      //最大32个模拟通道
#define MAX_ANALOG_ALARMOUT     32      //最大32路模拟报警输出 
#define MAX_ANALOG_ALARMIN      32      //最大32路模拟报警输入

#define MAX_IP_DEVICE           32      //允许接入的最大IP设备数
#define MAX_IP_DEVICE_V40       64      // 允许接入的最大IP设备数 最多可添加64个 IVMS 2000等新设备
#define MAX_IP_CHANNEL          32      //允许加入的最多IP通道数
#define MAX_IP_ALARMIN          128     //允许加入的最多报警输入数
#define MAX_IP_ALARMOUT         64      //允许加入的最多报警输出数
#define MAX_IP_ALARMIN_V40      4096    //允许加入的最多报警输入数
#define MAX_IP_ALARMOUT_V40     4096    //允许加入的最多报警输出数

#define MAX_RECORD_FILE_NUM     20      // 每次删除或者刻录的最大文件数
//SDK_V31 ATM
#define MAX_ACTION_TYPE	        12	    //自定义协议叠加交易行为最大行为个数 
#define MAX_ATM_PROTOCOL_NUM    256   //每种输入方式对应的ATM最大协议数
#define ATM_CUSTOM_PROTO        1025   //自定义协议 值为1025
#define ATM_PROTOCOL_SORT       4       //ATM协议段数 
#define ATM_DESC_LEN            32      //ATM描述字符串长度
// SDK_V31 ATM

#define MAX_EVENTID_LEN         64   //事件ID长度
#define MAX_IPV6_LEN  			64   //IPv6地址最大长度

#define MAX_CHANNUM_V40              512
#define INVALID_VALUE_UINT32         0xffffffff   //无效值
#define MAX_MULTI_AREA_NUM           24

/* 最大支持的通道数 最大模拟加上最大IP支持 */
#define MAX_CHANNUM_V30               ( MAX_ANALOG_CHANNUM + MAX_IP_CHANNEL )//64
#define MAX_ALARMOUT_V40             (MAX_IP_ALARMOUT_V40 +MAX_ANALOG_ALARMOUT) //4182
#define MAX_ALARMOUT_V30              ( MAX_ANALOG_ALARMOUT + MAX_IP_ALARMOUT )//96
#define MAX_ALARMIN_V30               ( MAX_ANALOG_ALARMIN + MAX_IP_ALARMIN )//160
#define MAX_ALARMIN_V40             (MAX_IP_ALARMIN_V40 +MAX_ANALOG_ALARMOUT) //4182
#define MAX_ANALOG_ALARM_WITH_VOLT_LIMIT	16 //受电压限定的模拟报警最大输入数

#define MAX_ROIDETECT_NUM       8    //支持的ROI区域数
#define MAX_LANERECT_NUM        5    //最大车牌识别区域数
#define MAX_FORTIFY_NUM         10   //最大布防个数
#define MAX_INTERVAL_NUM        4    //最大时间间隔个数
#define MAX_CHJC_NUM            3    //最大车辆省份简称字符个数
#define MAX_VL_NUM              5    //最大虚拟线圈个数
#define MAX_DRIVECHAN_NUM       16   //最大车道数
#define MAX_COIL_NUM            3    //最大线圈个数
#define MAX_SIGNALLIGHT_NUM     6   //最大信号灯个数
#define LEN_32					32
#define LEN_31					31 
#define MAX_CABINET_COUNT       8    //最大支持机柜数量
#define MAX_ID_LEN              48
#define MAX_PARKNO_LEN          16
#define MAX_ALARMREASON_LEN     32
#define MAX_UPGRADE_INFO_LEN    48 //获取升级文件匹配信息(模糊升级)
#define MAX_CUSTOMDIR_LEN       32 //自定义目录长度

#define MAX_TRANSPARENT_CHAN_NUM      4   //每个串口允许建立的最大透明通道数
#define MAX_TRANSPARENT_ACCESS_NUM    4   //每个监听端口允许接入的最大主机数

//ITS
#define MAX_PARKING_STATUS       8    //车位状态 0代表无车，1代表有车，2代表压线(优先级最高), 3特殊车位 
#define MAX_PARKING_NUM	         4    //一个通道最大4个车位 (从左到右车位 数组0～3)

#define MAX_ITS_SCENE_NUM        16   //最大场景数量
#define MAX_SCENE_TIMESEG_NUM    16   //最大场景时间段数量
#define MAX_IVMS_IP_CHANNEL      128  //最大IP通道数
#define DEVICE_ID_LEN            48   //设备编号长度
#define MONITORSITE_ID_LEN       48   //监测点编号长度
#define MAX_AUXAREA_NUM          16   //辅助区域最大数目
#define MAX_SLAVE_CHANNEL_NUM    16   //最大从通道数量

#define MAX_SCH_TASKS_NUM 10

#define MAX_SERVERID_LEN            64 //最大服务器ID的长度
#define MAX_SERVERDOMAIN_LEN        128 //服务器域名最大长度
#define MAX_AUTHENTICATEID_LEN      64 //认证ID最大长度
#define MAX_AUTHENTICATEPASSWD_LEN  32 //认证密码最大长度
#define MAX_SERVERNAME_LEN          64 //最大服务器用户名 
#define MAX_COMPRESSIONID_LEN       64 //编码ID的最大长度
#define MAX_SIPSERVER_ADDRESS_LEN   128 //SIP服务器地址支持域名和IP地址
//压线报警
#define MAX_PlATE_NO_LEN         32   //车牌号码最大长度 2013-09-27
#define UPNP_PORT_NUM			12	  //upnp端口映射端口数目
/*******************全局错误码 begin**********************/	
#define NET_DVR_NOERROR 					0	//没有错误
#define NET_DVR_PASSWORD_ERROR 				1	//用户名密码错误
#define NET_DVR_NOENOUGHPRI 				2	//权限不足
#define NET_DVR_NOINIT 						3	//没有初始化
#define NET_DVR_CHANNEL_ERROR 				4	//通道号错误
#define NET_DVR_OVER_MAXLINK 				5	//连接到DVR的客户端个数超过最大
#define NET_DVR_VERSIONNOMATCH				6	//版本不匹配
#define NET_DVR_NETWORK_FAIL_CONNECT		7	//连接服务器失败
#define NET_DVR_NETWORK_SEND_ERROR			8	//向服务器发送失败
#define NET_DVR_NETWORK_RECV_ERROR			9	//从服务器接收数据失败
#define NET_DVR_NETWORK_RECV_TIMEOUT		10	//从服务器接收数据超时
#define NET_DVR_NETWORK_ERRORDATA			11	//传送的数据有误
#define NET_DVR_ORDER_ERROR					12	//调用次序错误
#define NET_DVR_OPERNOPERMIT				13	//无此权限
#define NET_DVR_COMMANDTIMEOUT				14	//DVR命令执行超时
#define NET_DVR_ERRORSERIALPORT				15	//串口号错误
#define NET_DVR_ERRORALARMPORT				16	//报警端口错误
#define NET_DVR_PARAMETER_ERROR 			17  //参数错误
#define NET_DVR_CHAN_EXCEPTION				18	//服务器通道处于错误状态
#define NET_DVR_NODISK						19	//没有硬盘
#define NET_DVR_ERRORDISKNUM				20	//硬盘号错误
#define NET_DVR_DISK_FULL					21	//服务器硬盘满
#define NET_DVR_DISK_ERROR					22	//服务器硬盘出错
#define NET_DVR_NOSUPPORT					23	//服务器不支持
#define NET_DVR_BUSY						24	//服务器忙
#define NET_DVR_MODIFY_FAIL					25	//服务器修改不成功
#define NET_DVR_PASSWORD_FORMAT_ERROR		26	//密码输入格式不正确
#define NET_DVR_DISK_FORMATING				27	//硬盘正在格式化，不能启动操作
#define NET_DVR_DVRNORESOURCE				28	//DVR资源不足
#define	NET_DVR_DVROPRATEFAILED				29  //DVR操作失败
#define NET_DVR_OPENHOSTSOUND_FAIL 			30  //打开PC声音失败
#define NET_DVR_DVRVOICEOPENED 				31  //服务器语音对讲被占用
#define	NET_DVR_TIMEINPUTERROR				32  //时间输入不正确
#define	NET_DVR_NOSPECFILE					33  //回放时服务器没有指定的文件
#define NET_DVR_CREATEFILE_ERROR			34	//创建文件出错
#define	NET_DVR_FILEOPENFAIL				35  //打开文件出错
#define	NET_DVR_OPERNOTFINISH				36  //上次的操作还没有完成
#define	NET_DVR_GETPLAYTIMEFAIL				37  //获取当前播放的时间出错
#define	NET_DVR_PLAYFAIL					38  //播放出错
#define NET_DVR_FILEFORMAT_ERROR			39  //文件格式不正确
#define NET_DVR_DIR_ERROR					40	//路径错误
#define NET_DVR_ALLOC_RESOURCE_ERROR		41  //资源分配错误
#define NET_DVR_AUDIO_MODE_ERROR			42	//声卡模式错误
#define NET_DVR_NOENOUGH_BUF				43	//缓冲区太小
#define NET_DVR_CREATESOCKET_ERROR		 	44	//创建SOCKET出错
#define NET_DVR_SETSOCKET_ERROR				45	//设置SOCKET出错
#define NET_DVR_MAX_NUM						46	//个数达到最大
#define NET_DVR_USERNOTEXIST				47	//用户不存在
#define NET_DVR_WRITEFLASHERROR				48  //写FLASH出错
#define NET_DVR_UPGRADEFAIL					49  //DVR升级失败
#define NET_DVR_CARDHAVEINIT				50  //解码卡已经初始化过
#define NET_DVR_PLAYERFAILED				51	//调用播放库中某个函数失败
#define NET_DVR_MAX_USERNUM					52  //设备端用户数达到最大
#define NET_DVR_GETLOCALIPANDMACFAIL		53  //获得客户端的IP地址或物理地址失败
#define NET_DVR_NOENCODEING					54	//该通道没有编码
#define NET_DVR_IPMISMATCH					55	//IP地址不匹配
#define NET_DVR_MACMISMATCH					56	//MAC地址不匹配
#define NET_DVR_UPGRADELANGMISMATCH			57	//升级文件语言不匹配
#define NET_DVR_MAX_PLAYERPORT				58	//播放器路数达到最大
#define NET_DVR_NOSPACEBACKUP				59	//备份设备中没有足够空间进行备份
#define NET_DVR_NODEVICEBACKUP				60	//没有找到指定的备份设备
#define NET_DVR_PICTURE_BITS_ERROR			61	//图像素位数不符，限24色
#define NET_DVR_PICTURE_DIMENSION_ERROR		62	//图片高*宽超限， 限128*256
#define NET_DVR_PICTURE_SIZ_ERROR			63	//图片大小超限，限100K
#define NET_DVR_LOADPLAYERSDKFAILED			64	//载入当前目录下Player Sdk出错
#define NET_DVR_LOADPLAYERSDKPROC_ERROR		65	//找不到Player Sdk中某个函数入口
#define NET_DVR_LOADDSSDKFAILED				66	//载入当前目录下DSsdk出错
#define NET_DVR_LOADDSSDKPROC_ERROR		    67	//找不到DsSdk中某个函数入口
#define NET_DVR_DSSDK_ERROR					68	//调用硬解码库DsSdk中某个函数失败
#define NET_DVR_VOICEMONOPOLIZE				69	//声卡被独占
#define NET_DVR_JOINMULTICASTFAILED			70	//加入多播组失败
#define NET_DVR_CREATEDIR_ERROR				71	//建立日志文件目录失败
#define NET_DVR_BINDSOCKET_ERROR			72	//绑定套接字失败
#define NET_DVR_SOCKETCLOSE_ERROR			73	//socket连接中断，此错误通常是由于连接中断或目的地不可达
#define NET_DVR_USERID_ISUSING			    74	//注销时用户ID正在进行某操作
#define NET_DVR_SOCKETLISTEN_ERROR			75	//监听失败
#define NET_DVR_PROGRAM_EXCEPTION			76	//程序异常
#define NET_DVR_WRITEFILE_FAILED			77	//写文件失败
#define NET_DVR_FORMAT_READONLY				78  //禁止格式化只读硬盘
#define NET_DVR_WITHSAMEUSERNAME		    79  //用户配置结构中存在相同的用户名
#define NET_DVR_DEVICETYPE_ERROR            80  /*导入参数时设备型号不匹配*/
#define NET_DVR_LANGUAGE_ERROR              81  /*导入参数时语言不匹配*/
#define NET_DVR_PARAVERSION_ERROR           82  /*导入参数时软件版本不匹配*/
#define NET_DVR_IPCHAN_NOTALIVE             83  /*预览时外接IP通道不在线*/
#define NET_DVR_RTSP_SDK_ERROR				84	/*加载高清IPC通讯库StreamTransClient.dll失败*/
#define NET_DVR_CONVERT_SDK_ERROR			85	/*加载转码库失败*/
#define NET_DVR_IPC_COUNT_OVERFLOW			86  /*超出最大的ip接入通道数*/
#define NET_DVR_MAX_ADD_NUM                 87  /*添加标签(一个文件片段64)等个数达到最大*/
#define NET_DVR_PARAMMODE_ERROR             88 //图像增强仪，参数模式错误（用于硬件设置时，客户端进行软件设置时错误值）
#define NET_DVR_CODESPITTER_OFFLINE			89 //视频综合平台，码分器不在线
#define NET_DVR_BACKUP_COPYING				90  //设备正在备份
#define NET_DVR_CHAN_NOTSUPPORT             91  // 通道不支持该操作
#define NET_DVR_CALLINEINVALID              92  // 高度线位置太集中或长度线不够倾斜 
#define NET_DVR_CALCANCELCONFLICT           93  // 取消标定冲突，如果设置了规则及全局的实际大小尺寸过滤
#define NET_DVR_CALPOINTOUTRANGE            94 	// 标定点超出范围 
#define NET_DVR_FILTERRECTINVALID           95  // 尺寸过滤器不符合要求
#define NET_DVR_DDNS_DEVOFFLINE             96  //设备没有注册到ddns上
#define NET_DVR_DDNS_INTER_ERROR            97  //DDNS 服务器内部错误
#define NET_DVR_FUNCTION_NOT_SUPPORT_OS     98  //此功能不支持该操作系统
#define NET_DVR_DEC_CHAN_REBIND             99  //解码通道绑定显示输出次数受限
#define NET_DVR_INTERCOM_SDK_ERROR          100 //加载当前目录下的语音对讲库失败
#define NET_DVR_NO_CURRENT_UPDATEFILE       101 //没有正确的升级包  
#define NET_DVR_USER_NOT_SUCC_LOGIN         102  //用户还没登陆成功
#define NET_DVR_USE_LOG_SWITCH_FILE			103  //正在使用日志开关文件
#define NET_DVR_POOL_PORT_EXHAUST			104  //端口池中用于绑定的端口已耗尽
#define	NET_DVR_PACKET_TYPE_NOT_SUPPORT		105	//码流封装格式错误
#define NET_DVR_ALIAS_DUPLICATE				150	//别名重复  //2011-08-31 通过别名或者序列号来访问设备的新版本ddns的配置



// 2010-5-28
// 阵列错误码
#define RAID_ERROR_INDEX	                200
#define NET_DVR_NAME_NOT_ONLY               (RAID_ERROR_INDEX + 0)  // 名称已存在
#define NET_DVR_OVER_MAX_ARRAY              (RAID_ERROR_INDEX + 1 ) // 阵列达到上限
#define NET_DVR_OVER_MAX_VD                 (RAID_ERROR_INDEX + 2 ) // 虚拟磁盘达到上限
#define NET_DVR_VD_SLOT_EXCEED              (RAID_ERROR_INDEX + 3 ) // 虚拟磁盘槽位已满
#define NET_DVR_PD_STATUS_INVALID           (RAID_ERROR_INDEX + 4 ) // 重建阵列所需物理磁盘状态错误
#define NET_DVR_PD_BE_DEDICATE_SPARE        (RAID_ERROR_INDEX + 5 ) // 重建阵列所需物理磁盘为指定热备
#define NET_DVR_PD_NOT_FREE                 (RAID_ERROR_INDEX + 6 ) // 重建阵列所需物理磁盘非空闲
#define NET_DVR_CANNOT_MIG2NEWMODE          (RAID_ERROR_INDEX + 7 ) // 不能从当前的阵列类型迁移到新的阵列类型
#define NET_DVR_MIG_PAUSE                   (RAID_ERROR_INDEX + 8 ) // 迁移操作已暂停
#define NET_DVR_MIG_CANCEL                  (RAID_ERROR_INDEX + 9 ) // 正在执行的迁移操作已取消
#define NET_DVR_EXIST_VD                    (RAID_ERROR_INDEX + 10) // 阵列上阵列上存在虚拟磁盘，无法删除阵列
#define NET_DVR_TARGET_IN_LD_FUNCTIONAL     (RAID_ERROR_INDEX + 11) // 对象物理磁盘为虚拟磁盘组成部分且工作正常
#define NET_DVR_HD_IS_ASSIGNED_ALREADY      (RAID_ERROR_INDEX + 12) // 指定的物理磁盘被分配为虚拟磁盘
#define NET_DVR_INVALID_HD_COUNT            (RAID_ERROR_INDEX + 13) // 物理磁盘数量与指定的RAID等级不匹配
#define NET_DVR_LD_IS_FUNCTIONAL            (RAID_ERROR_INDEX + 14) // 阵列正常，无法重建
#define NET_DVR_BGA_RUNNING                 (RAID_ERROR_INDEX + 15) // 存在正在执行的后台任务
#define NET_DVR_LD_NO_ATAPI                 (RAID_ERROR_INDEX + 16) // 无法用ATAPI盘创建虚拟磁盘
#define NET_DVR_MIGRATION_NOT_NEED          (RAID_ERROR_INDEX + 17) // 阵列无需迁移
#define NET_DVR_HD_TYPE_MISMATCH            (RAID_ERROR_INDEX + 18) // 物理磁盘不属于同意类型
#define NET_DVR_NO_LD_IN_DG                 (RAID_ERROR_INDEX + 19) // 无虚拟磁盘，无法进行此项操作
#define NET_DVR_NO_ROOM_FOR_SPARE           (RAID_ERROR_INDEX + 20) // 磁盘空间过小，无法被指定为热备盘
#define NET_DVR_SPARE_IS_IN_MULTI_DG        (RAID_ERROR_INDEX + 21) // 磁盘已被分配为某阵列热备盘
#define NET_DVR_DG_HAS_MISSING_PD           (RAID_ERROR_INDEX + 22) // 阵列缺少盘

// x86 64bit nvr新增 2012-02-04
#define NET_DVR_NAME_EMPTY					(RAID_ERROR_INDEX + 23) /*名称为空*/
#define NET_DVR_INPUT_PARAM					(RAID_ERROR_INDEX + 24) /*输入参数有误*/
#define NET_DVR_PD_NOT_AVAILABLE			(RAID_ERROR_INDEX + 25) /*物理磁盘不可用*/
#define NET_DVR_ARRAY_NOT_AVAILABLE			(RAID_ERROR_INDEX + 26) /*阵列不可用*/
#define NET_DVR_PD_COUNT					(RAID_ERROR_INDEX + 27) /*物理磁盘数不正确*/
#define NET_DVR_VD_SMALL					(RAID_ERROR_INDEX + 28) /*虚拟磁盘太小*/
#define NET_DVR_NO_EXIST					(RAID_ERROR_INDEX + 29) /*不存在*/
#define NET_DVR_NOT_SUPPORT					(RAID_ERROR_INDEX + 30) /*不支持该操作*/
#define NET_DVR_NOT_FUNCTIONAL	 			(RAID_ERROR_INDEX + 31) /*阵列状态不是正常状态*/
#define NET_DVR_DEV_NODE_NOT_FOUND			(RAID_ERROR_INDEX + 32) /*虚拟磁盘设备节点不存在*/
#define NET_DVR_SLOT_EXCEED					(RAID_ERROR_INDEX + 33) /*槽位达到上限*/ 
#define NET_DVR_NO_VD_IN_ARRAY				(RAID_ERROR_INDEX + 34) /*阵列上不存在虚拟磁盘*/
#define NET_DVR_VD_SLOT_INVALID				(RAID_ERROR_INDEX + 35) /*虚拟磁盘槽位无效*/
#define NET_DVR_PD_NO_ENOUGH_SPACE			(RAID_ERROR_INDEX + 36) /*所需物理磁盘空间不足*/
#define NET_DVR_ARRAY_NONFUNCTION			(RAID_ERROR_INDEX + 37) /*只有处于正常状态的阵列才能进行迁移*/
#define NET_DVR_ARRAY_NO_ENOUGH_SPACE		(RAID_ERROR_INDEX + 38) /*阵列空间不足*/
#define NET_DVR_STOPPING_SCANNING_ARRAY		(RAID_ERROR_INDEX + 39) /*正在执行安全拔盘或重新扫描*/
#define NET_DVR_NOT_SUPPORT_16T             (RAID_ERROR_INDEX + 40) /*不支持创建大于16T的阵列*/
#define NET_DVR_ARRAY_FORMATING             (RAID_ERROR_INDEX + 41) /*正在执行格式化的阵列无法删除*/ 
#define NET_DVR_QUICK_SETUP_PD_COUNT        (RAID_ERROR_INDEX + 42) /*一键配置至少需要三块空闲盘*/ 
 



// 智能错误码 
#define VCA_ERROR_INDEX                     300 // 智能错误码索引
#define NET_DVR_ID_ERROR                    (VCA_ERROR_INDEX + 0)   // 配置ID不合理
#define NET_DVR_POLYGON_ERROR               (VCA_ERROR_INDEX + 1)   // 多边形不符合要求
#define NET_DVR_RULE_PARAM_ERROR            (VCA_ERROR_INDEX + 2)   // 规则参数不合理
#define NET_DVR_RULE_CFG_CONFLICT           (VCA_ERROR_INDEX + 3)   // 配置信息冲突
#define NET_DVR_CALIBRATE_NOT_READY         (VCA_ERROR_INDEX + 4)   // 当前没有标定信息
#define NET_DVR_CAMERA_DATA_ERROR           (VCA_ERROR_INDEX + 5)   // 摄像机参数不合理
#define NET_DVR_CALIBRATE_DATA_UNFIT        (VCA_ERROR_INDEX + 6)	// 长度不够倾斜，不利于标定
#define NET_DVR_CALIBRATE_DATA_CONFLICT     (VCA_ERROR_INDEX + 7)	// 标定出错，以为所有点共线或者位置太集中
#define NET_DVR_CALIBRATE_CALC_FAIL         (VCA_ERROR_INDEX + 8)	// 摄像机标定参数值计算失败
#define	NET_DVR_CALIBRATE_LINE_OUT_RECT		(VCA_ERROR_INDEX + 9)	// 输入的样本标定线超出了样本外接矩形框
#define NET_DVR_ENTER_RULE_NOT_READY		(VCA_ERROR_INDEX + 10)	// 没有设置进入区域
#define NET_DVR_AID_RULE_NO_INCLUDE_LANE	(VCA_ERROR_INDEX + 11)	// 交通事件规则中没有包括车道（特值拥堵和逆行）
#define NET_DVR_LANE_NOT_READY				(VCA_ERROR_INDEX + 12)	// 当前没有设置车道
#define NET_DVR_RULE_INCLUDE_TWO_WAY		(VCA_ERROR_INDEX + 13)	// 事件规则中包含2种不同方向
#define NET_DVR_LANE_TPS_RULE_CONFLICT      (VCA_ERROR_INDEX + 14)  // 车道和数据规则冲突
#define NET_DVR_NOT_SUPPORT_EVENT_TYPE      (VCA_ERROR_INDEX + 15)  // 不支持的事件类型
#define NET_DVR_LANE_NO_WAY                 (VCA_ERROR_INDEX + 16)  // 车道没有方向
#define NET_DVR_SIZE_FILTER_ERROR           (VCA_ERROR_INDEX + 17)  // 尺寸过滤框不合理
#define NET_DVR_LIB_FFL_NO_FACE             (VCA_ERROR_INDEX + 18) // 特征点定位时输入的图像没有人脸
#define NET_DVR_LIB_FFL_IMG_TOO_SMALL       (VCA_ERROR_INDEX + 19) // 特征点定位时输入的图像太小
#define NET_DVR_LIB_FD_IMG_NO_FACE          (VCA_ERROR_INDEX + 20) // 单张图像人脸检测时输入的图像没有人脸
#define NET_DVR_LIB_FACE_TOO_SMALL          (VCA_ERROR_INDEX + 21) // 建模时人脸太小
#define NET_DVR_LIB_FACE_QUALITY_TOO_BAD    (VCA_ERROR_INDEX + 22) // 建模时人脸图像质量太差
#define NET_DVR_KEY_PARAM_ERR               (VCA_ERROR_INDEX + 23) //高级参数设置错误
#define NET_DVR_CALIBRATE_DATA_ERR          (VCA_ERROR_INDEX + 24) //标定样本数目错误，或数据值错误，或样本点超出地平线
#define NET_DVR_CALIBRATE_DISABLE_FAIL      (VCA_ERROR_INDEX + 25) //所配置规则不允许取消标定
#define NET_DVR_VCA_LIB_FD_SCALE_OUTRANGE   (VCA_ERROR_INDEX + 26) //最大过滤框的宽高最小值超过最小过滤框的宽高最大值两倍以上
#define NET_DVR_LIB_FD_REGION_TOO_LARGE     (VCA_ERROR_INDEX + 27) //当前检测区域范围过大。检测区最大为图像的2/3
#define NET_DVR_TRIAL_OVERDUE               (VCA_ERROR_INDEX + 28) //试用版评估期已结束
#define NET_DVR_CONFIG_FILE_CONFLICT        (VCA_ERROR_INDEX + 29) //设备类型与配置文件冲突（加密狗类型与现有分析仪配置不符错误码提示）
//算法库相关错误码
#define NET_DVR_FR_FPL_FAIL                 (VCA_ERROR_INDEX + 30)   // 人脸特征点定位失败
#define NET_DVR_FR_IQA_FAIL                 (VCA_ERROR_INDEX + 31)   // 人脸评分失败
#define NET_DVR_FR_FEM_FAIL                 (VCA_ERROR_INDEX + 32)   // 人脸特征提取失败
#define NET_DVR_FPL_DT_CONF_TOO_LOW         (VCA_ERROR_INDEX + 33)   // 特征点定位时人脸检测置信度过低
#define NET_DVR_FPL_CONF_TOO_LOW            (VCA_ERROR_INDEX + 34)   // 特征点定位置信度过低
#define NET_DVR_E_DATA_SIZE                 (VCA_ERROR_INDEX + 35)  // 数据长度不匹配
#define NET_DVR_FR_MODEL_VERSION_ERR        (VCA_ERROR_INDEX + 36)  // 人脸模型数据中的模型版本错误
#define NET_DVR_FR_FD_FAIL                  (VCA_ERROR_INDEX + 37)  // 识别库中人脸检测失败
#define NET_DVR_FA_NORMALIZE_ERR            (VCA_ERROR_INDEX + 38)  // 人脸归一化出错
//其他错误码
#define NET_DVR_DOG_PUSTREAM_NOT_MATCH      (VCA_ERROR_INDEX + 39)  // 加密狗与前端取流设备类型不匹配
#define NET_DVR_DEV_PUSTREAM_NOT_MATCH      (VCA_ERROR_INDEX + 40)  // 前端取流设备版本不匹配
#define NET_DVR_PUSTREAM_ALREADY_EXISTS     (VCA_ERROR_INDEX + 41)  // 设备的其他通道已经添加过该前端设备
#define NET_DVR_SEARCH_CONNECT_FAILED       (VCA_ERROR_INDEX + 42)  // 连接检索服务器失败
#define NET_DVR_INSUFFICIENT_DISK_SPACE     (VCA_ERROR_INDEX + 43)  // 可存储的硬盘空间不足
#define NET_DVR_DATABASE_CONNECTION_FAILED  (VCA_ERROR_INDEX + 44)  // 数据库连接失败
#define NET_DVR_DATABASE_ADM_PW_ERROR       (VCA_ERROR_INDEX + 45)  // 数据库用户名、密码错误
#define NET_DVR_DECODE_YUV                  (VCA_ERROR_INDEX + 46)  // 解码失败

#define NET_DVR_RTSP_ERROR_NOENOUGHPRI          401  //无权限：服务器返回401时，转成这个错误码
#define NET_DVR_RTSP_ERROR_ALLOC_RESOURCE       402  //分配资源失败
#define NET_DVR_RTSP_ERROR_PARAMETER            403  //参数错误
#define NET_DVR_RTSP_ERROR_NO_URL               404  //指定的URL地址不存在：服务器返回404时，转成这个错误码
#define NET_DVR_RTSP_ERROR_FORCE_STOP           406  //用户中途强行退出

#define NET_DVR_RTSP_GETPORTFAILED			    407  //rtsp 得到端口错误
#define NET_DVR_RTSP_DESCRIBERROR			    410  //rtsp decribe 交互错误
#define NET_DVR_RTSP_DESCRIBESENDTIMEOUT		411  //rtsp decribe 发送超时
#define NET_DVR_RTSP_DESCRIBESENDERROR			412  //rtsp decribe 发送失败
#define NET_DVR_RTSP_DESCRIBERECVTIMEOUT		413  //rtsp decribe 接收超时
#define NET_DVR_RTSP_DESCRIBERECVDATALOST		414  //rtsp decribe 接收数据错误
#define NET_DVR_RTSP_DESCRIBERECVERROR			415  //rtsp decribe 接收失败
#define NET_DVR_RTSP_DESCRIBESERVERERR			416  //rtsp decribe 服务器返回错误状态

#define NET_DVR_RTSP_SETUPERROR			        420  //rtsp setup 交互错误
#define NET_DVR_RTSP_SETUPSENDTIMEOUT			421  //rtsp setup 发送超时
#define NET_DVR_RTSP_SETUPSENDERROR				422  //rtsp setup 发送错误
#define NET_DVR_RTSP_SETUPRECVTIMEOUT			423  //rtsp setup 接收超时
#define NET_DVR_RTSP_SETUPRECVDATALOST			424  //rtsp setup 接收数据错误
#define NET_DVR_RTSP_SETUPRECVERROR				425  //rtsp setup 接收失败
#define NET_DVR_RTSP_OVER_MAX_CHAN				426  //超过服务器最大连接数，或者服务器资源不足，服务器返回453时，转成这个错误码。
#define NET_DVR_RTSP_SETUPSERVERERR			    427  //rtsp setup 服务器返回错误状态

#define NET_DVR_RTSP_PLAYERROR			        430  //rtsp play 交互错误
#define NET_DVR_RTSP_PLAYSENDTIMEOUT			431  //rtsp play 发送超时
#define NET_DVR_RTSP_PLAYSENDERROR				432  //rtsp play 发送错误
#define NET_DVR_RTSP_PLAYRECVTIMEOUT			433  //rtsp play 接收超时
#define NET_DVR_RTSP_PLAYRECVDATALOST			434  //rtsp play 接收数据错误
#define NET_DVR_RTSP_PLAYRECVERROR				435  //rtsp play 接收失败
#define NET_DVR_RTSP_PLAYSERVERERR				436  //rtsp play 服务器返回错误状态

#define NET_DVR_RTSP_TEARDOWNERROR			    440  //rtsp teardown 交互错误
#define NET_DVR_RTSP_TEARDOWNSENDTIMEOUT		441  //rtsp teardown 发送超时
#define NET_DVR_RTSP_TEARDOWNSENDERROR			442  //rtsp teardown 发送错误
#define NET_DVR_RTSP_TEARDOWNRECVTIMEOUT		443  //rtsp teardown 接收超时
#define NET_DVR_RTSP_TEARDOWNRECVDATALOST		444  //rtsp teardown 接收数据错误
#define NET_DVR_RTSP_TEARDOWNRECVERROR			445  //rtsp teardown 接收失败
#define NET_DVR_RTSP_TEARDOWNSERVERERR			446  //rtsp teardown 服务器返回错误状态

#define  NET_PLAYM4_NOERROR					    500	//no error
#define	 NET_PLAYM4_PARA_OVER				    501	//input parameter is invalid;
#define  NET_PLAYM4_ORDER_ERROR				    502	//The order of the function to be called is error.
#define	 NET_PLAYM4_TIMER_ERROR				    503	//Create multimedia clock failed;
#define  NET_PLAYM4_DEC_VIDEO_ERROR			    504	//Decode video data failed.
#define  NET_PLAYM4_DEC_AUDIO_ERROR			    505	//Decode audio data failed.
#define	 NET_PLAYM4_ALLOC_MEMORY_ERROR		    506	//Allocate memory failed.
#define  NET_PLAYM4_OPEN_FILE_ERROR			    507	//Open the file failed.
#define  NET_PLAYM4_CREATE_OBJ_ERROR		    508	//Create thread or event failed
#define  NET_PLAYM4_CREATE_DDRAW_ERROR		    509	//Create DirectDraw object failed.
#define  NET_PLAYM4_CREATE_OFFSCREEN_ERROR      510	//failed when creating off-screen surface.
#define  NET_PLAYM4_BUF_OVER			        511	//buffer is overflow
#define  NET_PLAYM4_CREATE_SOUND_ERROR	        512	//failed when creating audio device.	
#define	 NET_PLAYM4_SET_VOLUME_ERROR	        513	//Set volume failed
#define  NET_PLAYM4_SUPPORT_FILE_ONLY	        514	//The function only support play file.
#define  NET_PLAYM4_SUPPORT_STREAM_ONLY	        515	//The function only support play stream.
#define  NET_PLAYM4_SYS_NOT_SUPPORT		        516	//System not support.
#define  NET_PLAYM4_FILEHEADER_UNKNOWN          517	//No file header.
#define  NET_PLAYM4_VERSION_INCORRECT	        518	//The version of decoder and encoder is not adapted.  
#define  NET_PALYM4_INIT_DECODER_ERROR          519	//Initialize decoder failed.
#define  NET_PLAYM4_CHECK_FILE_ERROR	        520	//The file data is unknown.
#define  NET_PLAYM4_INIT_TIMER_ERROR	        521	//Initialize multimedia clock failed.
#define	 NET_PLAYM4_BLT_ERROR			        522	//Blt failed.
#define  NET_PLAYM4_UPDATE_ERROR		        523	//Update failed.
#define  NET_PLAYM4_OPEN_FILE_ERROR_MULTI       524   //openfile error, streamtype is multi
#define  NET_PLAYM4_OPEN_FILE_ERROR_VIDEO       525   //openfile error, streamtype is video
#define  NET_PLAYM4_JPEG_COMPRESS_ERROR         526   //JPEG compress error
#define  NET_PLAYM4_EXTRACT_NOT_SUPPORT         527	//Don't support the version of this file.
#define  NET_PLAYM4_EXTRACT_DATA_ERROR          528	//extract video data failed.

//语音对讲库错误码
#define  NET_AUDIOINTERCOM_OK                   600  //无错误
#define  NET_AUDIOINTECOM_ERR_NOTSUPORT         601 //不支持
#define  NET_AUDIOINTECOM_ERR_ALLOC_MEMERY      602 //内存申请错误
#define  NET_AUDIOINTECOM_ERR_PARAMETER			603 //参数错误
#define  NET_AUDIOINTECOM_ERR_CALL_ORDER        604 //调用次序错误
#define  NET_AUDIOINTECOM_ERR_FIND_DEVICE       605 //未发现设备
#define  NET_AUDIOINTECOM_ERR_OPEN_DEVICE       606 //不能打开设备诶
#define  NET_AUDIOINTECOM_ERR_NO_CONTEXT        607 //设备上下文出错
#define  NET_AUDIOINTECOM_ERR_NO_WAVFILE        608 //WAV文件出错
#define  NET_AUDIOINTECOM_ERR_INVALID_TYPE      609 //无效的WAV参数类型
#define  NET_AUDIOINTECOM_ERR_ENCODE_FAIL       610 //编码失败
#define  NET_AUDIOINTECOM_ERR_DECODE_FAIL       611 //解码失败
#define  NET_AUDIOINTECOM_ERR_NO_PLAYBACK       612 //播放失败
#define  NET_AUDIOINTECOM_ERR_DENOISE_FAIL      613 //降噪失败
#define  NET_AUDIOINTECOM_ERR_UNKOWN            619 //未知错误

#define NET_QOS_OK								 700					//no error
#define NET_QOS_ERROR							 (NET_QOS_OK - 1)		//qos error
#define NET_QOS_ERR_INVALID_ARGUMENTS			 (NET_QOS_OK - 2)		//invalid arguments 
#define NET_QOS_ERR_SESSION_NOT_FOUND			 (NET_QOS_OK - 3)		//session net found
#define NET_QOS_ERR_LIB_NOT_INITIALIZED          (NET_QOS_OK - 4)		//lib not initialized
#define NET_QOS_ERR_OUTOFMEM                     (NET_QOS_OK - 5)		//outtofmem
#define NET_QOS_ERR_PACKET_UNKNOW                (NET_QOS_OK - 10)		//packet unknow
#define NET_QOS_ERR_PACKET_VERSION               (NET_QOS_OK - 11)		//packet version error
#define NET_QOS_ERR_PACKET_LENGTH                (NET_QOS_OK - 12)		//packet length error
#define NET_QOS_ERR_PACKET_TOO_BIG               (NET_QOS_OK - 13)		//packet too big
#define NET_QOS_ERR_SCHEDPARAMS_INVALID_BANDWIDTH (NET_QOS_OK - 20)		//schedparams invalid bandwidth
#define NET_QOS_ERR_SCHEDPARAMS_BAD_FRACTION      (NET_QOS_OK - 21)		//schedparams bad fraction
#define NET_QOS_ERR_SCHEDPARAMS_BAD_MINIMUM_INTERVAL (NET_QOS_OK - 22)	//schedparams bad minimum interval

#define NET_ERROR_TRUNK_LINE						711 //子系统已被配成干线
#define NET_ERROR_MIXED_JOINT						712 //不能进行混合拼接
#define NET_ERROR_DISPLAY_SWITCH					713 //不能进行显示通道切换
#define NET_ERROR_USED_BY_BIG_SCREEN				714 //解码资源被大屏占用
#define NET_ERROR_USE_OTHER_DEC_RESOURCE			715 //不能使用其他解码子系统资源
#define NET_ERROR_DISP_MODE_SWITCH                  716 //显示通道显示状态切换中
#define NET_ERROR_SCENE_USING						717	//场景正在使用
#define NET_ERR_NO_ENOUGH_DEC_RESOURCE              718 //解码资源不足
#define NET_ERR_NO_ENOUGH_FREE_SHOW_RESOURCE        719 //畅显资源不足
#define NET_ERR_NO_ENOUGH_VIDEO_MEMORY              720 //显存资源不足
#define NET_ERR_MAX_VIDEO_NUM                       721 //一拖多资源不足
#define NET_ERR_WIN_COVER_FREE_SHOW_AND_NORMAL      722 //窗口跨越了畅显输出口和非畅显输出口
#define NET_ERR_FREE_SHOW_WIN_SPLIT                 723 //畅显窗口不支持分屏
#define NET_ERR_INAPPROPRIATE_WIN_FREE_SHOW         724 //不是输出口整数倍的窗口不支持开启畅显
#define NET_DVR_TRANSPARENT_WIN_NOT_SUPPORT_SPLIT   725 //开启透明度的窗口不支持分屏
#define NET_DVR_SPLIT_WIN_NOT_SUPPORT_TRANSPARENT   726 //开启多分屏的窗口不支持透明度设置
#define NET_ERR_MAX_LOGO_NUM                        727 //logo数达到上限
#define NET_ERR_MAX_WIN_LOOP_NUM                    728 //轮巡窗口数达到上限

#define NET_DVR_DEV_NET_OVERFLOW		            800	//网络流量超过设备能力上限
#define NET_DVR_STATUS_RECORDFILE_WRITING_NOT_LOCK  801 //录像文件在录像，无法被锁定 
#define NET_DVR_STATUS_CANT_FORMAT_LITTLE_DISK      802 //由于硬盘太小无法格式化

//N+1错误码
#define NET_SDK_ERR_REMOTE_DISCONNECT				803 //远端无法连接
#define NET_SDK_ERR_RD_ADD_RD						804 //备机不能添加备机
#define NET_SDK_ERR_BACKUP_DISK_EXCEPT				805 //备份盘异常
#define NET_SDK_ERR_RD_LIMIT						806 //备机数已达上限
#define NET_SDK_ERR_ADDED_RD_IS_WD					807 //添加的备机是工作机
#define NET_SDK_ERR_ADD_ORDER_WRONG					808 //添加顺序出错，比如没有被工作机添加为备机，就添加工作机
#define NET_SDK_ERR_WD_ADD_WD						809 //工作机不能添加工作机
#define NET_SDK_ERR_WD_SERVICE_EXCETP				810 //工作机CVR服务异常
#define NET_SDK_ERR_RD_SERVICE_EXCETP				811 //备机CVR服务异常
#define NET_SDK_ERR_ADDED_WD_IS_RD					812 //添加的工作机是备机
#define NET_SDK_ERR_PERFORMANCE_LIMIT				813 //性能达到上限
#define NET_SDK_ERR_ADDED_DEVICE_EXIST				814 //添加的设备已经存在

//审讯机错误码
#define NET_SDK_ERR_INQUEST_RESUMING				815 //审讯恢复中
#define NET_SDK_ERR_RECORD_BACKUPING				816 //审讯备份中
#define NET_SDK_ERR_DISK_PLAYING					817 //光盘回放中
#define NET_SDK_ERR_INQUEST_STARTED					818 //审讯已开启
#define NET_SDK_ERR_LOCAL_OPERATING					819 //本地操作进行中
#define NET_SDK_ERR_INQUEST_NOT_START				820 //审讯未开启
//Netra3.1.0错误码                
#define NET_SDK_ERR_CHAN_AUDIO_BIND                 821  //通道未绑定或绑定语音对讲失败


//2011-10-25多屏控制器错误码（900-950）
#define  NET_ERR_WINCHAN_IDX				        901	// 开窗通道号错误
#define  NET_ERR_WIN_LAYER						    902	// 窗口层数错误，单个屏幕上最多覆盖的窗口层数
#define  NET_ERR_WIN_BLK_NUM			            903	// 窗口的块数错误，单个窗口可覆盖的屏幕个数
#define  NET_ERR_OUTPUT_RESOLUTION	                904	// 输出分辨率错误
#define  NET_ERR_LAYOUT							    905	// 布局号错误
#define  NET_ERR_INPUT_RESOLUTION    	            906 // 输入分辨率不支持
#define  NET_ERR_SUBDEVICE_OFFLINE                  907 // 子设备不在线
#define  NET_ERR_NO_DECODE_CHAN                     908 // 没有空闲解码通道
#define  NET_ERR_MAX_WINDOW_ABILITY                 909 // 开窗能力上限, 分布式多屏控制器中解码子设备能力上限或者显示处理器能力上限导致
#define  NET_ERR_ORDER_ERROR                        910 // 调用顺序有误
#define  NET_ERR_PLAYING_PLAN    					911 // 正在执行预案
#define  NET_ERR_DECODER_USED						912 // 解码板正在使用
#define	 NET_ERR_OUTPUT_BOARD_DATA_OVERFLOW			913	// 输出板数据量超限
#define	 NET_ERR_SAME_USER_NAME						914	// 用户名相同
#define	 NET_ERR_INVALID_USER_NAME					915	// 无效用户名
#define	 NET_ERR_MATRIX_USING						916	// 输入矩阵正在使用
#define	 NET_ERR_DIFFERENT_CHAN_TYPE				917	// 通道类型不同（矩阵输出通道和控制器的输入为不同的类型）
#define	 NET_ERR_INPUT_CHAN_BINDED					918	// 输入通道已经被其他矩阵绑定
#define	 NET_ERR_BINDED_OUTPUT_CHAN_OVERFLOW		919	// 正在使用的矩阵输出通道个数超过矩阵与控制器绑定的通道个数
#define	 NET_ERR_MAX_SIGNAL_NUM						920	// 输入信号源个数达到上限
#define  NET_ERR_INPUT_CHAN_USING					921	// 输入通道正在使用
#define  NET_ERR_MANAGER_LOGON 					    922	// 管理员已经登陆，操作失败
#define  NET_ERR_USERALREADY_LOGON 				    923	// 该用户已经登陆，操作失败
#define  NET_ERR_LAYOUT_INIT 						924	// 布局正在初始化，操作失败
#define	 NET_ERR_BASEMAP_SIZE_NOT_MATCH				925	// 底图大小不符 
#define  NET_ERR_WINDOW_OPERATING					926	// 窗口正在执行其他操作，本次操作失败
#define  NET_ERR_SIGNAL_UPLIMIT						927 // 信号源开窗个数达到上限 

//解码器错误码（951-999）
#define NET_ERR_MAX_WIN_OVERLAP						951 //达到最大窗口重叠数
#define NET_ERR_STREAMID_CHAN_BOTH_VALID			952 //stream ID和通道号同时有效
#define NET_ERR_NO_ZERO_CHAN						953 //设备无零通道
#define NEED_RECONNECT								955 //需要重定向（转码子系统使用）
#define NET_ERR_NO_STREAM_ID						956 //流ID不存在
#define NET_DVR_TRANS_NOT_START						957 //转码未启动
#define NET_ERR_MAXNUM_STREAM_ID					958 //流ID数达到上限
#define NET_ERR_WORKMODE_MISMATCH					959 //工作模式不匹配
#define NET_ERR_MODE_IS_USING						960 //已工作在当前模式
#define NET_ERR_DEV_PROGRESSING						961 //设备正在处理中
#define NET_ERR_PASSIVE_TRANSCODING					962 //正在被动转码
//能力集解析库错误码
#define XML_ABILITY_NOTSUPPORT                      1000  //不支持能力节点获取
#define	XML_ANALYZE_NOENOUGH_BUF				    1001		//输出内存不足
#define	XML_ANALYZE_FIND_LOCALXML_ERROR			    1002		//无法找到对应的本地xml
#define	XML_ANALYZE_LOAD_LOCALXML_ERROR			    1003		//加载本地xml出错
#define	XML_NANLYZE_DVR_DATA_FORMAT_ERROR		    1004		//设备能力数据格式错误
#define	XML_ANALYZE_TYPE_ERROR					    1005		//能力集类型错误
#define	XML_ANALYZE_XML_NODE_ERROR				    1006		//XML能力节点格式错误
#define XML_INPUT_PARAM_ERROR                       1007  //输入的能力XML节点值错误

//2012-10-16 报警设备错误码（1200~1300）
#define NET_ERR_SEARCHING_MODULE                    1201 // 正在搜索外接模块
#define NET_ERR_REGISTERING_MODULE                  1202 // 正在注册外接模块
#define NET_ERR_GETTING_ZONES						1203 // 正在获取防区参数
#define NET_ERR_GETTING_TRIGGERS					1204 // 正在获取触发器
#define NET_ERR_ARMED_STATUS						1205 // 系统处于布防状态
#define	NET_ERR_PROGRAM_MODE_STATUS					1206 // 系统处于编程模式
#define	NET_ERR_WALK_TEST_MODE_STATUS				1207 // 系统处于步测模式
#define	NET_ERR_BYPASS_STATUS						1208 // 旁路状态
#define NET_ERR_DISABLED_MODULE_STATUS				1209 // 功能未使能
#define	NET_ERR_NOT_SUPPORT_OPERATE_ZONE			1210 // 防区不支持该操作
#define NET_ERR_NOT_SUPPORT_MOD_MODULE_ADDR			1211 // 模块地址不能被修改
#define NET_ERR_UNREGISTERED_MODULE					1212 // 模块未注册
#define NET_ERR_PUBLIC_SUBSYSTEM_ASSOCIATE_SELF		1213 // 公共子系统关联自身
#define NET_ERR_EXCEEDS_ASSOCIATE_SUBSYSTEM_NUM		1214 // 超过公共子系统最大关联个数
#define NET_ERR_BE_ASSOCIATED_BY_PUBLIC_SUBSYSTEM	1215 // 子系统被其他公共子系统关联
#define	NET_ERR_ZONE_FAULT_STATUS					1216 // 防区处于故障状态
#define  NET_ERR_SAME_EVENT_TYPE					1217 // 事件触发报警输出开启和事件触发报警输出关闭中有相同事件类型	
#define NET_ERR_ZONE_ALARM_STATUS					1218 // 防区处于报警状态
#define NET_ERR_EXPANSION_BUS_SHORT_CIRCUIT			1219 //扩展总线短路

//2012-12-20抓拍机错误码（1400-1499）
#define NET_DVR_ERR_LANENUM_EXCEED                  1400  //车道数超出能力
#define NET_DVR_ERR_PRAREA_EXCEED                   1401  //牌识区域过大
#define NET_DVR_ERR_LIGHT_PARAM                     1402  //信号灯接入参数错误
#define NET_DVR_ERR_LANE_LINE_INVALID               1403  //车道线配置错误
#define NET_DVR_ERR_STOP_LINE_INVALID               1404  //停止线配置错误
#define NET_DVR_ERR_LEFTORRIGHT_LINE_INVALID        1405  //左/右转分界线配置错误
#define NET_DVR_ERR_LANE_NO_REPEAT                  1406  //叠加车道号重复
#define NET_DVR_ERR_PRAREA_INVALID                  1407  //牌识多边形不符合要求
#define NET_DVR_ERR_LIGHT_NUM_EXCEED                1408  //视频检测交通灯信号灯数目超出最大值
#define NET_DVR_ERR_SUBLIGHT_NUM_INVALID            1409  //视频检测交通灯信号灯子灯数目不合法
#define NET_DVR_ERR_LIGHT_AREASIZE_INVALID          1410  //视频检测交通灯输入信号灯框大小不合法
#define NET_DVR_ERR_LIGHT_COLOR_INVALID             1411  //视频检测交通灯输入信号灯颜色不合法
#define NET_DVR_ERR_LIGHT_DIRECTION_INVALID         1412  //视频检测交通灯输入灯方向属性不合法
#define NET_DVR_ERR_LACK_IOABLITY					1413  //IO口实际支持的能力不足

//2013-3-6VQD错误码（1500～1550）
#define NET_ERR_VQD_TIME_CONFLICT					1500 //VQD诊断时间段冲突
#define NET_ERR_VQD_PLAN_NO_EXIST					1501 //VQD诊断计划不存在
#define NET_ERR_VQD_CHAN_NO_EXIST					1502 //VQD监控点不存在
#define NET_ERR_VQD_CHAN_MAX						1503 //VQD计划数已达上限
#define NET_ERR_VQD_TASK_MAX						1504 //VQD任务数已达上限

/*******************全局错误码 end**********************/

/*************************************************
NET_DVR_IsSupport()返回值
1－9位分别表示以下信息（位与是TRUE)表示支持；
**************************************************/
#define NET_DVR_SUPPORT_DDRAW			0x01//支持DIRECTDRAW，如果不支持，则播放器不能工作；
#define NET_DVR_SUPPORT_BLT				0x02//显卡支持BLT操作，如果不支持，则播放器不能工作；
#define NET_DVR_SUPPORT_BLTFOURCC		0x04//显卡BLT支持颜色转换，如果不支持，播放器会用软件方法作RGB转换；
#define NET_DVR_SUPPORT_BLTSHRINKX		0x08//显卡BLT支持X轴缩小；如果不支持，系统会用软件方法转换；
#define NET_DVR_SUPPORT_BLTSHRINKY		0x10//显卡BLT支持Y轴缩小；如果不支持，系统会用软件方法转换；
#define NET_DVR_SUPPORT_BLTSTRETCHX		0x20//显卡BLT支持X轴放大；如果不支持，系统会用软件方法转换；
#define NET_DVR_SUPPORT_BLTSTRETCHY		0x40//显卡BLT支持Y轴放大；如果不支持，系统会用软件方法转换；
#define NET_DVR_SUPPORT_SSE				0x80//CPU支持SSE指令，Intel Pentium3以上支持SSE指令；
#define NET_DVR_SUPPORT_MMX				0x100//CPU支持MMX指令集，Intel Pentium3以上支持SSE指令；

/**********************云台控制命令 begin*************************/	
#define LIGHT_PWRON		2	/* 接通灯光电源 */
#define WIPER_PWRON		3	/* 接通雨刷开关 */
#define FAN_PWRON		4	/* 接通风扇开关 */
#define HEATER_PWRON	5	/* 接通加热器开关 */
#define AUX_PWRON1		6	/* 接通辅助设备开关 */
#define AUX_PWRON2		7	/* 接通辅助设备开关 */
#define SET_PRESET		8	/* 设置预置点 */
#define CLE_PRESET		9	/* 清除预置点 */

#define ZOOM_IN			11	/* 焦距以速度SS变大(倍率变大) */
#define ZOOM_OUT		12	/* 焦距以速度SS变小(倍率变小) */
#define FOCUS_NEAR      13  /* 焦点以速度SS前调 */
#define FOCUS_FAR       14  /* 焦点以速度SS后调 */
#define IRIS_OPEN       15  /* 光圈以速度SS扩大 */
#define IRIS_CLOSE      16  /* 光圈以速度SS缩小 */

#define TILT_UP			21	/* 云台以SS的速度上仰 */
#define TILT_DOWN		22	/* 云台以SS的速度下俯 */
#define PAN_LEFT		23	/* 云台以SS的速度左转 */
#define PAN_RIGHT		24	/* 云台以SS的速度右转 */
#define UP_LEFT			25	/* 云台以SS的速度上仰和左转 */
#define UP_RIGHT		26	/* 云台以SS的速度上仰和右转 */
#define DOWN_LEFT		27	/* 云台以SS的速度下俯和左转 */
#define DOWN_RIGHT		28	/* 云台以SS的速度下俯和右转 */
#define PAN_AUTO		29	/* 云台以SS的速度左右自动扫描 */

#define FILL_PRE_SEQ	30	/* 将预置点加入巡航序列 */
#define SET_SEQ_DWELL	31	/* 设置巡航点停顿时间 */
#define SET_SEQ_SPEED	32	/* 设置巡航速度 */
#define CLE_PRE_SEQ		33	/* 将预置点从巡航序列中删除 */
#define STA_MEM_CRUISE	34	/* 开始记录轨迹 */
#define STO_MEM_CRUISE	35	/* 停止记录轨迹 */
#define RUN_CRUISE		36	/* 开始轨迹 */
#define RUN_SEQ			37	/* 开始巡航 */
#define STOP_SEQ		38	/* 停止巡航 */
#define GOTO_PRESET		39	/* 快球转到预置点 */

#define DEL_SEQ         43  /* 删除巡航路径 */
#define STOP_CRUISE		    44	/* 停止轨迹 */
#define DELETE_CRUISE		45	/* 删除单条轨迹 */
#define DELETE_ALL_CRUISE	46	/* 删除所有轨迹 */

#define PAN_CIRCLE      50   /* 云台以SS的速度自动圆周扫描 */
#define DRAG_PTZ        51   /* 拖动PTZ */
/**********************云台控制命令 end*************************/	

/*************************************************
回放时播放控制命令宏定义 
NET_DVR_PlayBackControl
NET_DVR_PlayControlLocDisplay
NET_DVR_DecPlayBackCtrl的宏定义
具体支持查看函数说明和代码
**************************************************/	
#define NET_DVR_PLAYSTART		1//开始播放
#define NET_DVR_PLAYSTOP		2//停止播放
#define NET_DVR_PLAYPAUSE		3//暂停播放
#define NET_DVR_PLAYRESTART		4//恢复播放
#define NET_DVR_PLAYFAST		5//快放
#define NET_DVR_PLAYSLOW		6//慢放
#define NET_DVR_PLAYNORMAL		7//正常速度
#define NET_DVR_PLAYFRAME		8//单帧放
#define NET_DVR_PLAYSTARTAUDIO	9//打开声音
#define NET_DVR_PLAYSTOPAUDIO	10//关闭声音
#define NET_DVR_PLAYAUDIOVOLUME	11//调节音量
#define NET_DVR_PLAYSETPOS		12//改变文件回放的进度
#define NET_DVR_PLAYGETPOS		13//获取文件回放的进度
#define NET_DVR_PLAYGETTIME		14//获取当前已经播放的时间(按文件回放的时候有效)
#define NET_DVR_PLAYGETFRAME	15//获取当前已经播放的帧数(按文件回放的时候有效)
#define NET_DVR_GETTOTALFRAMES  16//获取当前播放文件总的帧数(按文件回放的时候有效)
#define NET_DVR_GETTOTALTIME    17//获取当前播放文件总的时间(按文件回放的时候有效)
#define NET_DVR_THROWBFRAME		20//丢B帧
#define NET_DVR_SETSPEED		24//设置码流速度
#define NET_DVR_KEEPALIVE		25//保持与设备的心跳(如果回调阻塞，建议2秒发送一次)
#define NET_DVR_PLAYSETTIME		26//按绝对时间定位
#define NET_DVR_PLAYGETTOTALLEN	27//获取按时间回放对应时间段内的所有文件的总长度
#define NET_DVR_PLAY_FORWARD    29 //倒放切换为正放
#define NET_DVR_PLAY_REVERSE    30 //正放切换为倒放
#define NET_DVR_SET_DECODEFFRAMETYPE 31 //设置
#define NET_DVR_SET_TRANS_TYPE		32 //设置转码格式
#define NET_DVR_PLAY_CONVERT    33 //回放转码

#define PLAYM4_DECODE_NORMAIL              0   //正常解码
#define PLAYM4_DECODE_KEY_FRAME            1   //只解I帧
#define PLAYM4_DECODE_NONE                 2   //全不解
#define PLAYM4_DECODE_TEMPORAL_LAYER_0     3   //解1/2
#define PLAYM4_DECODE_TEMPORAL_LAYER_1     4   //解1/4



//远程按键定义如下：
/* key value send to CONFIG program */
#define KEY_CODE_1      1
#define KEY_CODE_2      2
#define KEY_CODE_3      3
#define KEY_CODE_4      4
#define KEY_CODE_5      5
#define KEY_CODE_6      6
#define KEY_CODE_7      7
#define KEY_CODE_8      8
#define KEY_CODE_9      9
#define KEY_CODE_0      10
#define KEY_CODE_POWER  11
#define KEY_CODE_MENU   12
#define KEY_CODE_ENTER  13
#define KEY_CODE_CANCEL 14
#define KEY_CODE_UP     15
#define KEY_CODE_DOWN   16
#define KEY_CODE_LEFT   17
#define KEY_CODE_RIGHT  18
#define KEY_CODE_EDIT   19
#define KEY_CODE_ADD    20
#define KEY_CODE_MINUS  21
#define KEY_CODE_PLAY   22
#define KEY_CODE_REC    23
#define KEY_CODE_PAN    24
#define KEY_CODE_M      25
#define KEY_CODE_A      26
#define KEY_CODE_F1     27
#define KEY_CODE_F2     28

/* for PTZ control */
#define KEY_PTZ_UP_START        KEY_CODE_UP
#define KEY_PTZ_UP_STOP         32

#define KEY_PTZ_DOWN_START      KEY_CODE_DOWN
#define KEY_PTZ_DOWN_STOP       33

#define KEY_PTZ_LEFT_START      KEY_CODE_LEFT
#define KEY_PTZ_LEFT_STOP       34

#define KEY_PTZ_RIGHT_START     KEY_CODE_RIGHT
#define KEY_PTZ_RIGHT_STOP      35

#define KEY_PTZ_AP1_START       KEY_CODE_EDIT /* 光圈+ */
#define KEY_PTZ_AP1_STOP        36

#define KEY_PTZ_AP2_START       KEY_CODE_PAN /* 光圈- */
#define KEY_PTZ_AP2_STOP        37

#define KEY_PTZ_FOCUS1_START    KEY_CODE_A /* 聚焦+ */
#define KEY_PTZ_FOCUS1_STOP     38

#define KEY_PTZ_FOCUS2_START    KEY_CODE_M /* 聚焦- */
#define KEY_PTZ_FOCUS2_STOP     39

#define KEY_PTZ_B1_START        40 /* 变倍+ */
#define KEY_PTZ_B1_STOP         41

#define KEY_PTZ_B2_START        42 /* 变倍- */
#define KEY_PTZ_B2_STOP         43

//9000新增
#define KEY_CODE_11             44
#define KEY_CODE_12             45
#define KEY_CODE_13             46
#define KEY_CODE_14             47
#define KEY_CODE_15             48
#define KEY_CODE_16             49

#define AUDIOTALKTYPE_G722       0
#define AUDIOTALKTYPE_G711_MU    1
#define AUDIOTALKTYPE_G711_A	 2
#define AUDIOTALKTYPE_MP2L2      5
#define AUDIOTALKTYPE_G726		 6
/*************************参数配置命令 begin*******************************/
//用于NET_DVR_SetDVRConfig和NET_DVR_GetDVRConfig,注意其对应的配置结构

#define NET_DVR_GET_DEVICECFG		100		//获取设备参数
#define NET_DVR_SET_DEVICECFG		101		//设置设备参数
#define NET_DVR_GET_NETCFG			102		//获取网络参数
#define NET_DVR_SET_NETCFG			103		//设置网络参数
#define NET_DVR_GET_PICCFG			104		//获取图象参数
#define NET_DVR_SET_PICCFG			105		//设置图象参数
#define NET_DVR_GET_COMPRESSCFG		106		//获取压缩参数
#define NET_DVR_SET_COMPRESSCFG		107		//设置压缩参数
#define NET_DVR_GET_RECORDCFG		108		//获取录像时间参数
#define NET_DVR_SET_RECORDCFG		109		//设置录像时间参数
#define NET_DVR_GET_DECODERCFG		110		//获取解码器参数
#define NET_DVR_SET_DECODERCFG		111		//设置解码器参数
#define NET_DVR_GET_RS232CFG 		112		//获取232串口参数
#define NET_DVR_SET_RS232CFG		113		//设置232串口参数
#define NET_DVR_GET_ALARMINCFG 		114		//获取报警输入参数
#define NET_DVR_SET_ALARMINCFG		115		//设置报警输入参数
#define NET_DVR_GET_ALARMOUTCFG 	116		//获取报警输出参数
#define NET_DVR_SET_ALARMOUTCFG		117		//设置报警输出参数
#define NET_DVR_GET_TIMECFG 		118		//获取DVR时间
#define NET_DVR_SET_TIMECFG			119		//设置DVR时间
#define NET_DVR_GET_PREVIEWCFG 		120		//获取预览参数
#define NET_DVR_SET_PREVIEWCFG		121		//设置预览参数
#define NET_DVR_GET_VIDEOOUTCFG 	122		//获取视频输出参数
#define NET_DVR_SET_VIDEOOUTCFG		123		//设置视频输出参数
#define NET_DVR_GET_USERCFG 		124		//获取用户参数
#define NET_DVR_SET_USERCFG			125		//设置用户参数
#define NET_DVR_GET_EXCEPTIONCFG 	126		//获取异常参数
#define NET_DVR_SET_EXCEPTIONCFG	127		//设置异常参数
#define NET_DVR_GET_ZONEANDDST		128		//获取时区和夏时制参数
#define NET_DVR_SET_ZONEANDDST		129		//设置时区和夏时制参数
#define NET_DVR_GET_SHOWSTRING		130		//获取叠加字符参数
#define NET_DVR_SET_SHOWSTRING		131		//设置叠加字符参数
#define NET_DVR_GET_EVENTCOMPCFG	132		//获取事件触发录像参数
#define NET_DVR_SET_EVENTCOMPCFG	133		//设置事件触发录像参数
#define NET_DVR_GET_FTPCFG			134		//获取抓图的FTP参数(基线)
#define NET_DVR_SET_FTPCFG			135		//设置抓图的FTP参数(基线)
#define NET_DVR_GET_AUXOUTCFG		140		//获取报警触发辅助输出设置(HS设备辅助输出2006-02-28)
#define NET_DVR_SET_AUXOUTCFG		141		//设置报警触发辅助输出设置(HS设备辅助输出2006-02-28)
#define NET_DVR_GET_PREVIEWCFG_AUX 	142		//获取-s系列双输出预览参数(-s系列双输出2006-04-13)
#define NET_DVR_SET_PREVIEWCFG_AUX	143		//设置-s系列双输出预览参数(-s系列双输出2006-04-13)

/*********************************智能部分接口 begin***************************************/
//行为对应（NET_VCA_RULECFG）
#define NET_DVR_SET_RULECFG		    152	//设置行为分析规则
#define NET_DVR_GET_RULECFG	        153	//获取行为分析规则
//球机标定参数（NET_DVR_TRACK_CFG ）
#define NET_DVR_SET_TRACK_CFG       160//设置球机的配置参数 
#define NET_DVR_GET_TRACK_CFG       161//获取球机的配置参数

//智能分析仪取流配置结构
#define NET_DVR_SET_IVMS_STREAMCFG	162		//设置智能分析仪取流参数
#define NET_DVR_GET_IVMS_STREAMCFG	163		//获取智能分析仪取流参数
//智能控制参数结构
#define NET_DVR_SET_VCA_CTRLCFG		164	 //设置智能控制参数
#define NET_DVR_GET_VCA_CTRLCFG		165	 //获取智能控制参数
//屏蔽区域NET_VCA_MASK_REGION_LIST
#define NET_DVR_SET_VCA_MASK_REGION	166	 //设置屏蔽区域参数
#define NET_DVR_GET_VCA_MASK_REGION	167	 //获取屏蔽区域参数

//ATM进入区域 NET_VCA_ENTER_REGION
#define NET_DVR_SET_VCA_ENTER_REGION 168	 //设置进入区域参数
#define NET_DVR_GET_VCA_ENTER_REGION 169	 //获取进入区域参数

//标定线配置NET_VCA_LINE_SEGMENT_LIST
#define NET_DVR_SET_VCA_LINE_SEGMENT 170	 //设置标定线
#define NET_DVR_GET_VCA_LINE_SEGMENT 171	 //获取标定线

// ivms屏蔽区域NET_IVMS_MASK_REGION_LIST
#define NET_DVR_SET_IVMS_MASK_REGION 172	 //设置IVMS屏蔽区域参数
#define NET_DVR_GET_IVMS_MASK_REGION 173	 //获取IVMS屏蔽区域参数
// ivms进入检测区域NET_IVMS_ENTER_REGION
#define NET_DVR_SET_IVMS_ENTER_REGION 174	 //设置IVMS进入区域参数
#define NET_DVR_GET_IVMS_ENTER_REGION 175	 //获取IVMS进入区域参数

#define NET_DVR_SET_IVMS_BEHAVIORCFG  176	//设置智能分析仪行为规则参数
#define NET_DVR_GET_IVMS_BEHAVIORCFG  177	//获取智能分析仪行为规则参数

// IVMS 回放检索
#define NET_DVR_IVMS_SET_SEARCHCFG		178	//设置IVMS回放检索参数
#define NET_DVR_IVMS_GET_SEARCHCFG		179	//获取IVMS回放检索参数

#define NET_DVR_SET_POSITION_TRACK      180     // 设置场景跟踪配置信息
#define NET_DVR_GET_POSITION_TRACK      181     // 获取场景跟踪配置信息

#define NET_DVR_SET_CALIBRATION         182    // 设置标定信息
#define NET_DVR_GET_CALIBRATION         183    // 获取标定信息

#define NET_DVR_SET_PDC_RULECFG         184    // 设置人流量统计规则
#define NET_DVR_GET_PDC_RULECFG         185    // 获取人流量统计规则

#define NET_DVR_SET_PU_STREAMCFG        186     // 设置前段取流设备信息
#define NET_DVR_GET_PU_STREAMCFG        187     // 获取前段取流设备信息

#define NET_VCA_SET_SIZE_FILTER         194     // 设置全局尺寸过滤器
#define NET_VCA_GET_SIZE_FILTER         195     // 获取全局尺寸过滤器

#define NET_DVR_SET_TRACK_PARAMCFG      196     // 设置球机本地菜单规则
#define NET_DVR_GET_TRACK_PARAMCFG      197     // 获取球机本地菜单规则

#define NET_DVR_SET_DOME_MOVEMENT_PARAM 198     // 设置球机机芯参数
#define NET_DVR_GET_DOME_MOVEMENT_PARAM 199     // 获取球机机芯参数

/**************************************智能部分接口 begin**********************************/


#define NET_DVR_GET_PICCFG_EX		200		//获取图象参数(SDK_V14扩展命令)
#define NET_DVR_SET_PICCFG_EX		201		//设置图象参数(SDK_V14扩展命令)
#define NET_DVR_GET_USERCFG_EX 		202		//获取用户参数(SDK_V15扩展命令)
#define NET_DVR_SET_USERCFG_EX		203		//设置用户参数(SDK_V15扩展命令)
#define NET_DVR_GET_COMPRESSCFG_EX	204		//获取压缩参数(SDK_V15扩展命令2006-05-15)
#define NET_DVR_SET_COMPRESSCFG_EX	205		//设置压缩参数(SDK_V15扩展命令2006-05-15)


#define NET_DVR_GET_NETAPPCFG		222		//获取网络应用参数 NTP/DDNS/EMAIL
#define NET_DVR_SET_NETAPPCFG		223		//设置网络应用参数 NTP/DDNS/EMAIL
#define NET_DVR_GET_NTPCFG			224		//获取网络应用参数 NTP
#define NET_DVR_SET_NTPCFG			225		//设置网络应用参数 NTP
#define NET_DVR_GET_DDNSCFG			226		//获取网络应用参数 DDNS
#define NET_DVR_SET_DDNSCFG			227		//设置网络应用参数 DDNS
//对应NET_DVR_EMAILPARA
#define NET_DVR_GET_EMAILCFG		228		//获取网络应用参数 EMAIL
#define NET_DVR_SET_EMAILCFG		229		//设置网络应用参数 EMAIL

#define NET_DVR_GET_NFSCFG			230		/* NFS disk config */
#define NET_DVR_SET_NFSCFG			231		/* NFS disk config */

#define NET_DVR_GET_SHOWSTRING_EX	238		//获取叠加字符参数扩展(支持8条字符)
#define NET_DVR_SET_SHOWSTRING_EX	239		//设置叠加字符参数扩展(支持8条字符)
#define NET_DVR_GET_NETCFG_OTHER	244		//获取网络参数
#define NET_DVR_SET_NETCFG_OTHER	245		//设置网络参数

//对应NET_DVR_EMAILCFG结构
#define NET_DVR_GET_EMAILPARACFG	250		//Get EMAIL parameters
#define NET_DVR_SET_EMAILPARACFG	251		//Setup EMAIL parameters


#define NET_DVR_GET_DDNSCFG_EX		274	//获取扩展DDNS参数
#define NET_DVR_SET_DDNSCFG_EX		275	//设置扩展DDNS参数

#define	NET_DVR_SET_PTZPOS			292		//云台设置PTZ位置
#define	NET_DVR_GET_PTZPOS			293		//云台获取PTZ位置
#define	NET_DVR_GET_PTZSCOPE		294		//云台获取PTZ范围

#define NET_DVR_GET_AP_INFO_LIST	305//获取无线网络资源参数
#define NET_DVR_SET_WIFI_CFG		306	//设置IP监控设备无线参数
#define NET_DVR_GET_WIFI_CFG		307	//获取IP监控设备无线参数
#define NET_DVR_SET_WIFI_WORKMODE	308	//设置IP监控设备网口工作模式参数
#define NET_DVR_GET_WIFI_WORKMODE	309	//获取IP监控设备网口工作模式参数
#define	NET_DVR_GET_WIFI_STATUS		310	//获取设备当前wifi连接状态
/*********************************智能交通事件begin***************************************/
#define NET_DVR_GET_REFERENCE_REGION            400          // 获取参考区域
#define NET_DVR_SET_REFERENCE_REGION            401          // 设置参考区域

#define NET_DVR_GET_TRAFFIC_MASK_REGION         402     // 获取交通事件屏蔽区域
#define NET_DVR_SET_TRAFFIC_MASK_REGION         403     //  设置交通事件屏蔽区域
#define NET_DVR_SET_AID_RULECFG                 404         // 设置交通事件规则参数
#define NET_DVR_GET_AID_RULECFG                 405         // 获取交通事件规则参数

#define NET_DVR_SET_TPS_RULECFG                 406         // 设置交通统计规则参数
#define NET_DVR_GET_TPS_RULECFG                 407         // 获取交通统计规则参数

#define NET_DVR_SET_LANECFG				        408			// 设置车道规则
#define	NET_DVR_GET_LANECFG				        409			// 获取车道规则


/*********************************智能交通事件end***************************************/
#define NET_DVR_SET_FACEDETECT_RULECFG          420         // 设置人脸检测规则
#define NET_DVR_GET_FACEDETECT_RULECFG          421         // 获取人脸检测规则

/***************************DS9000新增命令(_V30) begin *****************************/
//网络(NET_DVR_NETCFG_V30结构)
#define NET_DVR_GET_NETCFG_V30		            1000		//获取网络参数
#define NET_DVR_SET_NETCFG_V30		            1001		//设置网络参数

//图象(NET_DVR_PICCFG_V30结构)
#define NET_DVR_GET_PICCFG_V30		            1002		//获取图象参数
#define NET_DVR_SET_PICCFG_V30		            1003		//设置图象参数

//录像时间(NET_DVR_RECORD_V30结构)
#define NET_DVR_GET_RECORDCFG_V30	            1004		//获取录像参数
#define NET_DVR_SET_RECORDCFG_V30	            1005		//设置录像参数

//用户(NET_DVR_USER_V30结构)
#define NET_DVR_GET_USERCFG_V30 	            1006		//获取用户参数
#define NET_DVR_SET_USERCFG_V30		            1007		//设置用户参数

//9000DDNS参数配置(NET_DVR_DDNSPARA_V30结构)
#define     NET_DVR_GET_DDNSCFG_V30		        1010		//获取DDNS(9000扩展)
#define     NET_DVR_SET_DDNSCFG_V30		        1011		//设置DDNS(9000扩展)

//EMAIL功能(NET_DVR_EMAILCFG_V30结构)
#define NET_DVR_GET_EMAILCFG_V30		        1012	//获取EMAIL参数 
#define NET_DVR_SET_EMAILCFG_V30		        1013	//设置EMAIL参数 

//巡航参数 (NET_DVR_CRUISE_PARA结构)
#define 	NET_DVR_GET_CRUISE			        1020		
#define 	NET_DVR_SET_CRUISE			        1021		


//报警输入结构参数 (NET_DVR_ALARMINCFG_V30结构)
#define 	NET_DVR_GET_ALARMINCFG_V30			1024		
#define 	NET_DVR_SET_ALARMINCFG_V30			1025

//报警输出结构参数 (NET_DVR_ALARMOUTCFG_V30结构)
#define 	NET_DVR_GET_ALARMOUTCFG_V30			1026		
#define 	NET_DVR_SET_ALARMOUTCFG_V30			1027

//视频输出结构参数 (NET_DVR_VIDEOOUT_V30结构)
#define 	NET_DVR_GET_VIDEOOUTCFG_V30			1028		
#define 	NET_DVR_SET_VIDEOOUTCFG_V30			1029	

//叠加字符结构参数 (NET_DVR_SHOWSTRING_V30结构)
#define 	NET_DVR_GET_SHOWSTRING_V30			1030		
#define 	NET_DVR_SET_SHOWSTRING_V30			1031

//异常结构参数 (NET_DVR_EXCEPTION_V30结构)
#define 	NET_DVR_GET_EXCEPTIONCFG_V30		1034		
#define 	NET_DVR_SET_EXCEPTIONCFG_V30		1035

//串口232结构参数 (NET_DVR_RS232CFG_V30结构)
#define 	NET_DVR_GET_RS232CFG_V30			1036		
#define 	NET_DVR_SET_RS232CFG_V30			1037

//网络硬盘接入结构参数 (NET_DVR_NET_DISKCFG结构)
#define		NET_DVR_GET_NET_DISKCFG				1038		//网络硬盘接入获取
#define		NET_DVR_SET_NET_DISKCFG				1039		//网络硬盘接入设置
//压缩参数 (NET_DVR_COMPRESSIONCFG_V30结构)
#define     NET_DVR_GET_COMPRESSCFG_V30	        1040		
#define     NET_DVR_SET_COMPRESSCFG_V30	        1041		

//获取485解码器参数 (NET_DVR_DECODERCFG_V30结构)
#define     NET_DVR_GET_DECODERCFG_V30		    1042		//获取解码器参数
#define     NET_DVR_SET_DECODERCFG_V30		    1043		//设置解码器参数

//获取预览参数 (NET_DVR_PREVIEWCFG_V30结构)
#define     NET_DVR_GET_PREVIEWCFG_V30		    1044		//获取预览参数
#define     NET_DVR_SET_PREVIEWCFG_V30		    1045		//设置预览参数

//辅助预览参数 (NET_DVR_PREVIEWCFG_AUX_V30结构)
#define     NET_DVR_GET_PREVIEWCFG_AUX_V30		1046		//获取辅助预览参数
#define     NET_DVR_SET_PREVIEWCFG_AUX_V30		1047		//设置辅助预览参数

//IP接入配置参数 （NET_DVR_IPPARACFG结构）
#define     NET_DVR_GET_IPPARACFG               1048        //获取IP接入配置信息 
#define     NET_DVR_SET_IPPARACFG               1049        //设置IP接入配置信息

//IP报警输入接入配置参数 （NET_DVR_IPALARMINCFG结构）
#define     NET_DVR_GET_IPALARMINCFG            1050        //获取IP报警输入接入配置信息 
#define     NET_DVR_SET_IPALARMINCFG            1051        //设置IP报警输入接入配置信息

//IP报警输出接入配置参数 （NET_DVR_IPALARMOUTCFG结构）
#define     NET_DVR_GET_IPALARMOUTCFG           1052        //获取IP报警输出接入配置信息 
#define     NET_DVR_SET_IPALARMOUTCFG           1053        //设置IP报警输出接入配置信息

//硬盘管理的参数获取 (NET_DVR_HDCFG结构)
#define     NET_DVR_GET_HDCFG			        1054	    //获取硬盘管理配置参数
#define     NET_DVR_SET_HDCFG			        1055	    //设置硬盘管理配置参数
//盘组管理的参数获取 (NET_DVR_HDGROUP_CFG结构)
#define     NET_DVR_GET_HDGROUP_CFG			    1056	    //获取盘组管理配置参数
#define     NET_DVR_SET_HDGROUP_CFG			    1057	    //设置盘组管理配置参数

//设备编码类型配置(NET_DVR_COMPRESSION_AUDIO结构)
#define     NET_DVR_GET_COMPRESSCFG_AUD         1058        //获取设备语音对讲编码参数
#define     NET_DVR_SET_COMPRESSCFG_AUD         1059        //设置设备语音对讲编码参数

//IP接入配置参数 （NET_DVR_IPPARACFG_V31结构）
#define     NET_DVR_GET_IPPARACFG_V31           1060        //获取IP接入配置信息 
#define     NET_DVR_SET_IPPARACFG_V31           1061        //设置IP接入配置信息

// 通道资源配置 (NET_DVR_IPPARACFG_V40结构)
#define NET_DVR_GET_IPPARACFG_V40               1062        // 获取IP接入配置
#define NET_DVR_SET_IPPARACFG_V40               1063        // 设置IP接入配置

#define NET_DVR_GET_CCDPARAMCFG                 1067       //IPC获取CCD参数配置
#define NET_DVR_SET_CCDPARAMCFG                 1068       //IPC设置CCD参数配置

#define NET_DVR_GET_IOINCFG		                1070    //获取抓拍机IO输入参数
#define NET_DVR_SET_IOINCFG		                1071	 //设置抓拍机IO输入参数

#define NET_DVR_GET_IOOUTCFG		            1072    //获取抓拍机IO输出参数
#define NET_DVR_SET_IOOUTCFG		            1073	 //设置抓拍机IO输出参数

#define NET_DVR_GET_FLASHCFG		            1074    //获取IO闪光灯输出参数
#define NET_DVR_SET_FLASHCFG		            1075	 //设置IO闪光灯输出参数

#define NET_DVR_GET_LIGHTSNAPCFG		        1076    //获取抓拍机红绿灯参数
#define NET_DVR_SET_LIGHTSNAPCFG	        	1077	 //设置抓拍机红绿灯参数

#define NET_DVR_GET_MEASURESPEEDCFG		        1078    //获取抓拍机测速参数
#define NET_DVR_SET_MEASURESPEEDCFG		        1079	 //设置抓拍机测速参数

#define NET_DVR_GET_IMAGEOVERLAYCFG	            1080//获取抓拍机图像叠加信息参数
#define NET_DVR_SET_IMAGEOVERLAYCFG	            1081//设置抓拍机图像叠加信息参数

#define NET_DVR_GET_SNAPCFG	                    1082//获取单IO触发抓拍功能配置
#define NET_DVR_SET_SNAPCFG	                    1083//设置单IO触发抓拍功能配置

#define NET_DVR_GET_VTPPARAM		            1084//获取虚拟线圈参数
#define NET_DVR_SET_VTPPARAM		            1085//设置虚拟线圈参数

#define NET_DVR_GET_SNAPENABLECFG				1086//获取抓拍机使能参数
#define NET_DVR_SET_SNAPENABLECFG				1087//设置抓拍机使能参数

#define NET_DVR_GET_POSTEPOLICECFG              1088//获取卡口电警参数
#define NET_DVR_SET_POSTEPOLICECFG              1089//设置卡口电警参数

#define NET_DVR_GET_JPEGCFG_V30					1090		//获取抓图的JPEG参数(基线)
#define NET_DVR_SET_JPEGCFG_V30					1091		//设置抓图的JPEG参数(基线)

#define NET_DVR_GET_SPRCFG	                    1092    //获取车牌识别参数
#define NET_DVR_SET_SPRCFG	                    1093    //设置车牌识别参数
#define NET_DVR_GET_PLCCFG                      1094   //获取车牌亮度补偿参数
#define NET_DVR_SET_PLCCFG                      1095  //设置车牌亮度补偿参数

#define NET_DVR_GET_DEVICESTATECFG              1096   //获取设备当前状态参数
#define NET_DVR_SET_CALIBRATE_TIME              1097   //设置扩展时间校时
#define NET_DVR_GET_CALIBRATE_TIME              1098   //获取扩展时间校时

#define NET_DVR_GET_DEVICECFG_V40	            1100//获取扩展设备参数 
#define NET_DVR_SET_DEVICECFG_V40	            1101//设置扩展设备参数

#define NET_DVR_GET_ZEROCHANCFG   	            1102	//获取零通道压缩参数 
#define NET_DVR_SET_ZEROCHANCFG  	            1103	//设置零通道压缩参数

#define NET_DVR_GET_ZERO_PREVIEWCFG_V30         1104    // 获取零通道预览参数配置
#define NET_DVR_SET_ZERO_PREVIEWCFG_V30         1105    // 设置零通道预览参数配置

#define NET_DVR_SET_ZERO_ZOOM	                1106     //设置零通道的缩放配置 
#define NET_DVR_GET_ZERO_ZOOM	                1107     //获取零通道的缩放配置

#define	NET_DVR_NATASSOCIATECFG_GET	            1110    //获取NAT功能相关信息
#define	NET_DVR_NATASSOCIATECFG_SET	            1111     //设置NAT功能相关信息

#define NET_DVR_GET_SNMPCFG   	                1112    //获取SNMP参数 
#define NET_DVR_SET_SNMPCFG  	                1113    //设置SNMP参数

#define NET_DVR_GET_SNMPCFG_V30   	            1114        //获取SNMPv30参数 
#define NET_DVR_SET_SNMPCFG_V30  	            1115        //设置SNMPv30参数

#define	NET_DVR_VIDEOPLATFORMALARMCFG_GET	    1130  //获取视频综合平台报警配置
#define	NET_DVR_VIDEOPLATFORMALARMCFG_SET	    1131  //设置视频综合平台报警配置

#define NET_DVR_GET_RAID_ADAPTER_INFO           1134    // 获取适配器信息
#define NET_DVR_SET_RAID_ADAPTER_INFO           1135    // 设置适配器信息   

#define	NET_DVR_MATRIX_BIGSCREENCFG_GET		    1140//获取大屏拼接参数
#define	NET_DVR_MATRIX_BIGSCREENCFG_SET		    1141//设置大屏拼接参数

#define NET_DVR_GET_MB_PLATFORMPARA			    1145 //获取平台登录参数
#define NET_DVR_SET_MB_PLATFORMPARA			    1146 //设置平台登录参数
#define NET_DVR_GET_MB_DEVSTATUS                1147 //获取移动设备状态

#define  NET_DVR_GET_DECODER_JOINT_CHAN	        1151//获取解码关联通道
#define  NET_DVR_SET_DECODER_JOINT_CHAN	        1152//设置解码关联通道

//多网卡配置
#define NET_DVR_GET_NETCFG_MULTI                1161        //获取多网卡配置
#define NET_DVR_SET_NETCFG_MULTI                1162        //设置多网卡配置

#define NET_DVR_GET_CMSPARA			            1170//获取平台参数
#define NET_DVR_SET_CMSPARA			            1171//设置平台参数
#define NET_DVR_GET_DIALSTATUS		            1172//获取拨号状态参数
#define NET_DVR_GET_SMSRELATIVEPARA	            1173//获取短信相关参数
#define NET_DVR_SET_SMSRELATIVEPARA	            1174//设置短信相关参数
#define NET_DVR_GET_PINSTATUS		            1175//获取Pin状态
#define NET_DVR_SET_PINCMD			            1176//设置PIN命令
#define NET_DVR_SET_SENSOR_CFG					1180        // 设置模拟量参数
#define NET_DVR_GET_SENSOR_CFG					1181        // 获取模拟量参数
#define NET_DVR_SET_ALARMIN_PARAM				1182		// 设置报警输入参数
#define NET_DVR_GET_ALARMIN_PARAM				1183		// 获取报警输入参数
#define NET_DVR_SET_ALARMOUT_PARAM				1184		// 设置报警输出参数
#define NET_DVR_GET_ALARMOUT_PARAM				1185		// 获取报警输出参数
#define NET_DVR_SET_SIREN_PARAM					1186		// 设置警号参数
#define NET_DVR_GET_SIREN_PARAM					1187		// 获取警号参数
#define NET_DVR_SET_ALARM_RS485CFG				1188		// 设置报警主机485参数
#define NET_DVR_GET_ALARM_RS485CFG				1189		// 获取报警主机485参数
#define NET_DVR_GET_ALARMHOST_MAIN_STATUS		1190		// 获取报警主机主要状态
#define NET_DVR_GET_ALARMHOST_OTHER_STATUS		1191		// 获取报警主机其他状态
#define NET_DVR_SET_ALARMHOST_ENABLECFG			1192		//获取报警主机使能状态
#define NET_DVR_GET_ALARMHOST_ENABLECFG			1193		//设置报警主机使能状态
#define NET_DVR_SET_ALARM_CAMCFG				1194		// 设置视频综合平台报警触发CAM操作配置
#define NET_DVR_GET_ALARM_CAMCFG				1195		// 设置视频综合平台报警触发CAM操作配置
#define NET_DVR_GET_GATEWAY_CFG                 1196        // 获取门禁参数配置
#define NET_DVR_SET_GATEWAY_CFG                 1197        // 设置门禁参数配置
#define NET_DVR_GET_POS_TEXT_CFG                1198        //获取POS参数配置
#define NET_DVR_SET_POS_TEXT_CFG                1199        //设置POS参数配置

#define NET_DVR_GET_ALARMDIALMODECFG			1198		//获取报警主机拨号参数
#define NET_DVR_SET_ALARMDIALMODECFG			1199		//设置报警主机拨号参数
#define	NET_DVR_SET_WINCFG			            1202        //窗口参数设置
#define NET_DVR_GET_ALARMHOSTDIALSETUPMODE		1204		//获取报警主机拨号启用方式
#define NET_DVR_SET_ALARMHOSTDIALSETUPMODE		1205		//设置报警主机拨号启用方式

#define NET_DVR_GET_HOLIDAY_PARAM_CFG           1240        // 获取节假日参数
#define NET_DVR_SET_HOLIDAY_PARAM_CFG           1241        // 设置节假日参数

#define NET_DVR_GET_MOTION_HOLIDAY_HANDLE       1242        // 获取移动侦测假日报警处理方式
#define NET_DVR_SET_MOTION_HOLIDAY_HANDLE       1243        // 获取移动侦测假日报警处理方式

#define NET_DVR_GET_VILOST_HOLIDAY_HANDLE       1244        // 获取视频信号丢失假日报警处理方式
#define NET_DVR_SET_VILOST_HOLIDAY_HANDLE       1245        // 获取视频信号丢失假日报警处理方式

#define NET_DVR_GET_HIDE_HOLIDAY_HANDLE         1246        // 获取遮盖假日报警处理方式
#define NET_DVR_SET_HIDE_HOLIDAY_HANDLE         1247        // 设置遮盖假日报警处理方式

#define NET_DVR_GET_ALARMIN_HOLIDAY_HANDLE      1248        // 获取报警输入假日报警处理方式
#define NET_DVR_SET_ALARMIN_HOLIDAY_HANDLE      1249        // 设置报警输入假日报警处理方式
#define NET_DVR_GET_ALARMOUT_HOLIDAY_HANDLE     1250        // 获取报警输出假日报警处理方式
#define NET_DVR_SET_ALARMOUT_HOLIDAY_HANDLE     1251        // 设置报警输出假日报警处理方式
#define NET_DVR_GET_HOLIDAY_RECORD              1252        // 获取假日录像参数
#define NET_DVR_SET_HOLIDAY_RECORD              1253        // 设置假日录像参数
#define NET_DVR_GET_NETWORK_BONDING             1254        // 获取BONDING网络参数
#define NET_DVR_SET_NETWORK_BONDING             1255        // 设置BONDING网络参数
#define NET_DVR_GET_LINK_STATUS                 1256        // 获取通道IP工作状态
#define NET_DVR_GET_DISK_QUOTA_CFG              1278        // 获取磁盘配额信息
#define NET_DVR_SET_DISK_QUOTA_CFG              1279        // 设置磁盘配额信息
#define NET_DVR_GET_JPEG_CAPTURE_CFG            1280        // 获取DVR抓图配置
#define NET_DVR_SET_JPEG_CAPTURE_CFG            1281        // 设置DVR抓图配置
#define NET_DVR_GET_SCHED_CAPTURECFG            1282        // 获取抓图计划
#define NET_DVR_SET_SCHED_CAPTURECFG            1283        // 设置抓图计划
#define NET_DVR_GET_VGA_PREVIEWCFG              1284        // 获取VGA预览配置
#define NET_DVR_SET_VGA_PREVIEWCFG              1285        // 设置VGA预览配置 
#define NET_DVR_GET_VIDEO_INPUT_EFFECT          1286        // 获取通道视频输入图像参数
#define NET_DVR_SET_VIDEO_INPUT_EFFECT          1287        // 设置通道视频输入图像参数

#define NET_DVR_GET_OPTICAL_CHANNEL				1300	//获取光端子系统通道关联信息
#define NET_DVR_SET_OPTICAL_CHANNEL				1301	//设置光端子系统通道关联信息
#define NET_DVR_GET_FIBER_CASCADE				1302	//获取光纤级联模式
#define NET_DVR_SET_FIBER_CASCADE				1303	//设置光纤级联模式
#define NET_DVR_GET_SPARTAN_STATUS				1304	//获取畅显状态
#define NET_DVR_SET_SPARTAN_STATUS				1305	//设置畅显状态
#define NET_DVR_GET_ETHERNET_CHANNEL			1306	//获取端口聚合参数
#define NET_DVR_SET_ETHERMET_CHANNEL			1307	//设置端口聚合参数
#define NET_DVR_OPTICAL_REBOOT					1320	//光端机重启
#define NET_DVR_SET_AUDIOCHAN_CFG				1321	//设置音频切换参数
#define NET_DVR_GET_AUDIOCHAN_CFG				1322	//获取音频切换参数
//SDI矩阵1.0
#define NET_DVR_SET_MATRIX_BASE_CFG             1332 //设置矩阵基本参数
#define NET_DVR_GET_MATRIX_BASE_CFG             1333 //获取矩阵基本参数
#define NET_DVR_SWITCH_MATRIX_IO                1334 //矩阵输入输出切换 
#define NET_DVR_GET_MATRIX_IO_RELATION          1335 //获取矩阵输入输入关联关系
   
#define	NET_DVR_BIGSCREENASSOCIATECFG_GET		1511 //获取大屏关联配置
#define	NET_DVR_BIGSCREENASSOCIATECFG_SET		1512 //设置大屏关联配置

//1200起
#define		NET_DVR_GETSCREENINFO		        1601 //获取大屏信息配置
#define		NET_DVR_SETSCREENINFO		        1602 //设置大屏信息配置
#define		NET_DVR_GET_SCREEN_WINCFG	        1603//单个窗口参数获取
#define		NET_DVR_LAYOUTLIST_GET 		        1605//获取布局列表
#define		NET_DVR_SET_LAYOUTCFG		        1606 //布局设置
#define		NET_DVR_LAYOUTCTRL			        1607//布局控制，1-open，2-close
#define		NET_DVR_INPUTLIST_GET		        1608 //获取输入信号源列表
#define		NET_DVR_SET_INPUTSTREAMCFG	        1609 //输入信号源设置 
#define		NET_DVR_OUTPUT_SET			        1610 //输出参数设置
#define		NET_DVR_OUTPUT_GET			        1611 //输出参数获取
#define		NET_DVR_SET_OSDCFG			        1612 //OSD参数设置
#define		NET_DVR_GET_OSDCFG			        1613 //OSD参数获取
#define		NET_DVR_BIGSCREEN_GETSERIAL         1614//获取大屏串口信息
#define		NET_DVR_GET_PLANLIST		        1615	//获取预案列表
#define		NET_DVR_SET_PLAN			        1616	//设置预案
#define		NET_DVR_CTRL_PLAN			        1617	//控制预案
#define		NET_DVR_GET_DEVICE_RUN_STATUS       1618	//获取设备运行状态
#define 	NET_DVR_GET_EXTERNAL_MATRIX_CFG		1619	//获取矩阵信息
#define		NET_DVR_SET_EXTERNAL_MATRIX_CFG		1620	//设置矩阵信息
#define		NET_DVR_GET_OUTPUT_SCREEN_RELATION	1621	//获取输出和屏幕的绑定关系
#define		NET_DVR_SET_OUTPUT_SCREEN_RELATION	1622	//设置输出和屏幕的绑定关系
#define 	NET_DVR_GET_VCS_USER_CFG			1623	//获取用户信息配置
#define		NET_DVR_SET_VCS_USER_CFG			1624	//设置用户信息配置
#define		NET_DVR_CONTROL_SCREEN				1625	//屏幕控制

#define NET_DVR_GET_DEV_BASEINFO			    1650	// 获取单个设备信息
#define NET_DVR_SET_DEV_BASEINFO			    1651	// 设置单个设备信息
#define NET_DVR_GET_DEV_NETINFO				    1652	// 获取设备的网络信息
#define NET_DVR_SET_DEV_NETINFO				    1653	// 设置设备的网络信息
#define NET_DVR_GET_SIGNAL_SOURCE_INFO		    1654	// 获取信号源信息
#define NET_DVR_SET_SIGNAL_SOURCE_INFO		    1655	// 设置信号源信息
#define NET_DVR_ADJUST_PIC_V40				    1656	// 图像微调
#define NET_DVR_RESTORE_V40					    1657	// 恢复默认参数
#define	NET_DVR_SET_NET_SIGNAL				    1658	// 设置网络信号源
#define NET_DVR_REBOOT_V40					    1659	// 重启
#define NET_DVR_CONTROL_PICTURE_V41				1660	// 图片控制V41

#define NET_DVR_GET_AUTO_REBOOT_CFG             1710    //获取自动重启参数
#define NET_DVR_SET_AUTO_REBOOT_CFG             1711    //设置自动重启参数
#define NET_DVR_GET_TRUNK_USE_STATE 			1713	//获取指定干线使用状态
#define NET_DVR_SET_PTZ_CTRL_INFO 				1714	//设置PTZ控制参数
#define NET_DVR_GET_PTZ_CTRL_INFO 				1715	//获取PTZ控制参数
#define NET_DVR_GET_PTZ_STATUS 					1716	//获取PTZ状态
#define	NET_DVR_GET_DISP_ROUTE_LIST				1717	//获取显示路径列表

#define NET_DVR_GET_DEC_RESOURCE_LIST			1720	//获取可用解码资源列表
#define NET_DVR_SET_DEC_RESOURCE_LIST			1721	//预分配解码资源 
#define NET_DVR_GET_DEC_YUV						1722	//获取解码通道关联YUV输出参数
#define NET_DVR_SET_DEC_YUV						1723	//设置解码通道关联YUV输出参数
#define NET_DVR_GET_DEC_RESOUCE					1724	//向视频综合平台申请解码资源
#define NET_DVR_FREE_DEC_RESOURCE				1725	//释放解码资源

#define NET_DVR_GET_ALARMHOSTSUBSYSTEM_CFG	    2001			//报警主机获取子系统参数
#define NET_DVR_SET_ALARMHOSTSUBSYSTEM_CFG	    2002			//报警主机设置子系统参数
#define NET_DVR_GETEXTENDALARMININFO    	    2003			//获取防区编号信息
#define NET_DVR_MODIFYALARMINNO 	            2004			//修改防区编号信息
#define NET_DVR_GET_ALARMHOST_WIRELESS_NETWORK_CFG			2005	//获取无线网络参数配置
#define	NET_DVR_SET_ALARMHOST_WIRELESS_NETWORK_CFG			2006	//设置无线网络参数配置
#define	NET_DVR_GET_ALARMHOST_NETCFG		    2007			//获取网络参数配置
#define	NET_DVR_SET_ALARMHOST_NETCFG		    2008			//设置网络参数配置
#define NET_DVR_GET_LED_SCREEN_CFG		2009	// 获取LED屏幕参数
#define NET_DVR_SET_LED_SCREEN_CFG		2010	// 设置LED屏幕参数
#define NET_DVR_GET_LED_CONTENT_CFG		2011	// 获取LED屏显内容
#define	NET_DVR_SET_LED_CONTENT_CFG		2012	// 设置LED屏显内容
#define NET_DVR_TURNON_LED				2013	// 打开LED屏
#define NET_DVR_TURNOFF_LED				2014	// 关闭LED屏
#define NET_DVR_GET_LED_TIMER_SWITCH	2015	// 获取LED屏定时开关参数
#define NET_DVR_SET_LED_TIMER_SWITCH	2016	// 设置LED屏定时开关参数
#define NET_DVR_SET_LED_BRIGHTNESS		2017	// 手动设置LED屏亮度
#define NET_DVR_GET_LED_TIMER_BRIGHTNESS		    2018	// 设置分时LED屏亮度
#define NET_DVR_SET_LED_TIMER_BRIGHTNESS		    2019	// 获取分时LED屏亮度
#define NET_DVR_LED_CHECKTIME						2020	// LED校时
#define NET_DVR_GET_ALARMHOST_AUDIO_ASSOCIATE_ALARM	2021 //获取音频跟随报警事件
#define NET_DVR_SET_ALARMHOST_AUDIO_ASSOCIATE_ALARM	2022 //设置音频跟随报警事件
#define	NET_DVR_GET_LED_STATUS						2023	//获取LED屏状态
#define NET_DVR_CLOSE_SUBSYSTEM_FAULT_ALARM         2027       // 关闭子系统故障提示音
#define NET_DVR_SET_SUBSYSTEM_BYPASS				2028       // 子系统旁路
#define NET_DVR_CANCEL_SUBSYSTEM_BYPASS				2029       // 子系统旁路恢复

#define  NET_DVR_GET_ALARMHOST_SUBSYSTEM_CFG_EX				2030			//获取子系统扩展参数
#define	 NET_DVR_SET_ALARMHOST_SUBSYSTEM_CFG_EX				2031			//设置子系统扩展参数
#define  NET_DVR_GET_ALARMHOST_PRINTER_CFG					2032			//获取打印机打印使能
#define	 NET_DVR_SET_ALARMHOST_PRINTER_CFG					2033			//设置打印机打印使能
#define	 NET_DVR_GET_ALARMHOST_ZONE_LIST_IN_SUBSYSTEM		2034			//获取指定子系统内的所有防区
#define	 NET_DVR_GET_ALARMHOST_TRIGGER_LIST					2035			//获取所有触发器
#define	 NET_DVR_ARM_ALARMHOST_SUBSYSTEM					2036			//按布防类型对子系统布防
#define	 NET_DVR_GET_ALARMHOST_EVENT_TRIG_ALARMOUT_CFG		2037			// 获取事件触发报警输出配置
#define  NET_DVR_SET_ALARMHOST_EVENT_TRIG_ALARMOUT_CFG		2038			// 设置事件触发报警输出配置
#define	 NET_DVR_GET_ALARMHOST_FAULT_CFG					2039			// 获取故障处理配置
#define  NET_DVR_SET_ALARMHOST_FAULT_CFG					2040			// 设置故障处理配置
#define  NET_DVR_SEARCH_ARMHOST_EXTERNAL_MODULE 			2041			//自动搜索
#define	 NET_DVR_REGISTER_ALARMHOST_EXTERNAL_MODULE			2042			//自动注册
#define  NET_DVR_CLOSE_ALARMHOST_OVERALL_FAULT_ALARM 		2043			//关闭全局故障提示音

#define NET_DVR_GET_SAFETYCABIN_WORK_MODE			2044 //获取防护舱工作模式参数
#define NET_DVR_SET_SAFETYCABIN_WORK_MODE			2045 //设置防护舱工作模式参数
#define NET_DVR_GET_SAFETYCABIN_PERSON_SIGNAL_CFG   2046 //获取防护舱人信号探测参数
#define NET_DVR_SET_SAFETYCABIN_PERSON_SIGNAL_CFG   2047 //设置防护舱人信号探测参数

#define  NET_DVR_GET_ALARMHOST_MODULE_CFG					2048			// 获取模块信息
//#define  NET_DVR_SET_ALARMHOST_MODULE_CFG					2049			// 设置模块信息(预留)

/********************************动环监控报警主机v20 begin****************************/
#define	 NET_DVR_GET_ALARMHOST_EXTERNAL_DEVICE_STATE		2050			//获取485外接设备状态
#define  NET_DVR_SET_ALARMHOST_EXTERNAL_DEVICE_LIMIT_VALUE  2051			//设置外接设备报警限值
#define  NET_DVR_GET_ALARMHOST_EXTERNAL_DEVICE_LIMIT_VALUE  2052			//获取外接设备报警限值
#define  NET_DVR_GET_ALARMHOST_SENSOR_JOINT_CFG				2053		// 获取模拟量关联配置
#define  NET_DVR_SET_ALARMHOST_SENSOR_JOINT_CFG				2054		// 设置模拟量关联配置
#define	 NET_DVR_SET_ALARMHOST_RS485_SLOT_CFG				2055		// 设置报警主机485槽位参数
#define  NET_DVR_GET_ALARMHOST_RS485_SLOT_CFG				2056		// 获取报警主机485槽位参数
/********************************动环监控报警主机v20 end****************************/

/********************************动环监控报警主机104规约 begin****************************/
#define NET_DVR_GET_ALL_VARIABLE_INFO	  2057   // 获取所有变量元素信息
#define NET_DVR_GET_ALARM_POINT_CFG       2058   // 获取点号信息
#define NET_DVR_SET_ALARM_POINT_CFG       2059   // 设置点号信息
#define NET_DVR_GET_HISTORY_VALUE		  2060   // 获取历史数据
#define NET_DVR_GET_ALARMHOST_ALARM_MODE  2061   // 获取数据上传方式
#define NET_DVR_SET_ALARMHOST_ALARM_MODE  2062   // 设置数据上传方式
/********************************动环监控报警主机104规约 end****************************/


/*************************************DS-19D00-0402BN(0601BN) begin*************************************/
#define NET_DVR_GET_ALARMHOST_SENSOR_VALUE	2063   // 获取模拟量实时数据
/*************************************DS-19D00-0402BN(0601BN) end*************************************/

/*************************************网络报警主机begin*************************************/
#define NET_DVR_GET_ALARMHOST_REPORT_CENTER_V40	2064   // 获取数据上传方式
#define NET_DVR_SET_ALARMHOST_REPORT_CENTER_V40	2065   // 设置数据上传方式
#define NET_DVR_GET_OUTPUT_SCHEDULE_RULECFG	    2068   // 获取时控输出参数
#define NET_DVR_SET_OUTPUT_SCHEDULE_RULECFG     2069   // 设置时控输出参数
/*************************************网络报警主机end**************************************/

/*********************************EHOME begin******************************/
#define NET_DVR_GET_CMS_CFG 					2070
#define	NET_DVR_SET_CMS_CFG						2071
/*********************************EHOME end******************************/

#define NET_DVR_GET_ALARMHOST_MAIN_STATUS_V40	2072   // 获取主要状态V40

#define NET_ITC_GET_TRIGGERCFG                  3003  //获取触发参数
#define NET_ITC_SET_TRIGGERCFG                  3004  //设置触发参数
#define NET_ITC_GET_IOOUT_PARAM_CFG	            3005  //获取IO输出参数（3.1含之后版本）
#define NET_ITC_SET_IOOUT_PARAM_CFG	            3006  //设置IO输出参数（3.1含之后版本）

#define NET_DVR_GET_CAMERA_SETUPCFG		        3007  //获取相机架设参数
#define NET_DVR_SET_CAMERA_SETUPCFG		        3008  //设置相机架设参数

#define NET_ITC_GET_TRIGGER_DEFAULTCFG          3013  //获取触发模式推荐参数
#define NET_DVR_GET_STATUS_DETECTCFG            3015  //获取状态检测使能参数
#define NET_DVR_SET_STATUS_DETECTCFG            3016  //设置状态检测使能参数
#define NET_ITC_GET_VIDEO_TRIGGERCFG            3017  //获取视频电警触发参数
#define NET_ITC_SET_VIDEO_TRIGGERCFG            3018  //设置视频电警触发参数
#define NET_DVR_GET_TPS_ALARMCFG			    3019  //获取交通统计报警参数
#define NET_DVR_SET_TPS_ALARMCFG			    3020  //设置交通统计报警参数

	
#define NET_DVR_GET_REDAREACFG                  3100   //获取红绿灯区域参数
#define NET_DVR_SET_REDAREACFG                  3101   //设置红绿灯区域参数
#define	NET_DVR_GET_TEST_SPOT					3102   //获取SPOT口测试总步数和当前第几步
#define	NET_DVR_SET_TEST_SPOT					3103   //设置SPOT口测试总步数和当前第几步
#define NET_DVR_GET_CABINETCFG					3104   //机柜参数配置获取
#define NET_DVR_SET_CABINETCFG					3105   //机柜参数配置设置
#define NET_DVR_VEHICLE_CHECK_START				3106   //黑名单稽查数据回传
#define NET_DVR_SET_CAPTUREPIC_CFG				3107   //车载抓图配置设置命令
#define NET_DVR_GET_CAPTUREPIC_CFG				3108   //车载抓图配置获取命令
#define NET_DVR_SET_MOBILEPLATE_RECOG_CFG		3109   //车载车牌识别配置设置命令
#define NET_DVR_GET_MOBILEPLATE_RECOG_CFG		3110   //车载车牌识别配置获取命令
#define NET_DVR_SET_MOBILE_RADAR_CFG			3111   //车载雷达配置设置命令
#define NET_DVR_GET_MOBILE_RADAR_CFG			3112   //车载雷达配置获取命令
#define NET_DVR_SET_MOBILE_LOCALPLATECHK_CFG	3113   //车载黑名单本地对比配置设置命令
#define NET_DVR_GET_MOBILE_LOCALPLATECHK_CFG	3114   //车载黑名单本地对比配置获取命令

#define  NET_ITC_GET_ICRCFG						3115   //获取ICR配置切换
#define  NET_ITC_SET_ICRCFG						3116   //设置ICR配置切换
#define  NET_ITC_GET_RS485_ACCESSINFO			3117   //获取Rs485关联接入设备的信息 
#define  NET_ITC_SET_RS485_ACCESSINFO			3118   //设置Rs485关联接入设备的信息
#define  NET_ITC_GET_EXCEPTIONCFG 				3119   //获取异常参数
#define  NET_ITC_SET_EXCEPTIONCFG				3120   //设置异常参数
#define  NET_ITC_GET_FTPCFG						3121   //获取ITC  FTP设置参数
#define  NET_ITC_SET_FTPCFG						3122   //设置ITC FTP设置参数

#define NET_DVR_GET_AUDIO_INPUT                 3201   //获取音频输入参数
#define NET_DVR_SET_AUDIO_INPUT                 3202  //设置音频输入参数
#define NET_DVR_GET_CAMERA_DEHAZE_CFG           3203   //获取去雾参数配置
#define NET_DVR_SET_CAMERA_DEHAZE_CFG           3204  //设置去雾参数配置
#define NET_DVR_REMOTECONTROL_ALARM             3205  //远程控制遥控器布防
#define NET_DVR_REMOTECONTROL_DISALARM          3206  //远程控制遥控器撤防
#define NET_DVR_REMOTECONTROL_STUDY             3207  //远程控制遥控器学习
#define NET_DVR_WIRELESS_ALARM_STUDY            3208  //远程控制无线报警学习
#define NET_IPC_GET_AUX_ALARMCFG                3209   //获取辅助报警参数配置
#define NET_IPC_SET_AUX_ALARMCFG                3210  //设置辅助报警参数配置
#define NET_DVR_GET_PREVIEW_DISPLAYCFG	        3211  //获取预览显示参数
#define NET_DVR_SET_PREVIEW_DISPLAYCFG	     	3212  //设置预览显示参数
#define NET_DVR_REMOTECONTROL_PTZ            	3213  //远程控制PTZ
#define NET_DVR_REMOTECONTROL_PRESETPOINT   	3214   //远程控制预置点
#define NET_DVR_REMOTECONTROL_CRUISE         	3215   //远程控制巡航

#define NET_DVR_GET_MULTI_STREAM_COMPRESSIONCFG  3216 //远程获取多码流压缩参数
#define NET_DVR_SET_MULTI_STREAM_COMPRESSIONCFG  3217 //远程设置多码流压缩参数 

#define NET_DVR_GET_WPSCFG	                    3218  //获取WPS参数
#define NET_DVR_SET_WPSCFG	                    3219  //设置WPS参数
#define NET_DVR_WPS_CONNECT                     3220  //远程启用WPS连接
#define NET_DVR_GET_DEVICE_PIN                  3221  //获取设备PIN码
#define NET_DVR_UPDATE_PIN                      3223  //更新设备PIN码
#define NET_DVR_GET_PRESETCFG           		3224  //获取预置点参数
#define NET_DVR_GET_PTZCRUISECFG        		3225  //获取巡航路径参数
#define NET_DVR_GET_PRESET_NUM		    		3226  //获取预置点个数
#define NET_DVR_GET_PTZCRUISE_NUM				3227  //获取巡航路径个数

#define NET_DVR_GET_MOTION_TRACK_CFG			3228  //获取跟踪参数
#define NET_DVR_SET_MOTION_TRACK_CFG			3229  //设置跟踪参数

#define NET_DVR_GET_IPADDR_FILTERCFG		    3232  //获取IP地址过滤参数
#define NET_DVR_SET_IPADDR_FILTERCFG		    3233  //设置IP地址过滤参数

#define NET_DVR_GET_LOGO_OVERLAYCFG	            3234  //获取LOGO图片叠加参数 
#define NET_DVR_SET_LOGO_OVERLAYCFG	            3235  //设置LOGO图片叠加参数

#define NET_DVR_GET_IPV6_LIST                   3236  //获取网卡的全部IPV6地址信息
#define NET_DVR_GET_AUDIOOUT_VOLUME             3237  //获取输出音频大小
#define NET_DVR_SET_AUDIOOUT_VOLUME             3238  //设置输出音频大小
#define NET_DVR_GET_FUZZY_UPGRADE               3239  //获取模糊升级匹配信息

#define NET_DVR_FISHEYE_CFG                     3244  //鱼眼长连接配置
#define NET_DVR_GET_PTZ_POINT                   3245  //获取PTZ点坐标
#define NET_DVR_SET_PTZ_POINT                   3246  //设置PTZ点坐标
#define NET_DVR_REMOTECONTROL_DEV_PARAM         3247  //设置设备登录客户端参数
#define NET_DVR_GET_FISHEYE_STREAM_STATUS       3248  //获取鱼眼码流状态

#define NET_DVR_GET_GBT28181_ACCESS_CFG			3249  //获取GBT28181协议接入配置		
#define NET_DVR_SET_GBT28181_ACCESS_CFG			3250  //设置GBT28181协议接入配置
#define NET_DVR_GET_GBT28181_CHANINFO_CFG		3251  //获取GBT28181协议接入设备的通道信息
#define NET_DVR_SET_GBT28181_CHANINFO_CFG		3252  //设置GBT28181协议接入设备的通道信息
#define NET_DVR_GET_GBT28181_ALARMINCFG			3253  //获取GBT28181协议接入设备的报警信息
#define NET_DVR_SET_GBT28181_ALARMINCFG			3254  //设置GBT28181协议接入设备的报警信息
#define NET_DVR_GET_ISP_CAMERAPARAMCFG			3255  //获取ISP前端参数配置
#define NET_DVR_SET_ISP_CAMERAPARAMCFG			3256  //设置ISP前端参数配置
#define NET_DVR_GET_DEVSERVER_CFG				3257  //获取模块服务配置
#define NET_DVR_SET_DEVSERVER_CFG				3258  //设置模块服务配置

//2013-11-25
#define	NET_DVR_GET_WIPERINFO_CFG				3259     //雨刷配置获取
#define	NET_DVR_SET_WIPERINFO_CFG				3260     //雨刷配置设置

/********************************200万像素网络高清红外球(V5.0.2) begin****************************/
#define NET_DVR_GET_LOW_LIGHTCFG                3303	   //获取快球低照度设置信息
#define NET_DVR_SET_LOW_LIGHTCFG                3304       //设置快球低照度设置信息

#define NET_DVR_GET_FOCUSMODECFG                3305       //获取快球聚焦模式信息
#define NET_DVR_SET_FOCUSMODECFG                3306       //设置快球聚焦模式信息

#define NET_DVR_GET_INFRARECFG                  3307       //获取快球红外设置信息
#define NET_DVR_SET_INFRARECFG                  3308       //设置快球红外设置信息

#define NET_DVR_GET_AEMODECFG                   3309       //获取快球其他设置信息
#define NET_DVR_SET_AEMODECFG                   3310       //设置快球其他设置信息

#define NET_DVR_CONTROL_RESTART_SUPPORT         3312 //快球机芯重启
#define NET_DVR_CONTROL_RESTORE_SUPPORT         3311 // 	恢复前端默认参数(参数能力中有的前端参数配置相关的都恢复)
/********************************200万像素网络高清红外球(V5.0.2) end****************************/
#define NET_DVR_CONTROL_PTZ_PATTERN             3313       //云台花样扫描
#define NET_DVR_GET_PTZ_PARKACTION_CFG          3314	   //获取云台守望参数
#define NET_DVR_SET_PTZ_PARKACTION_CFG          3315       //设置云台守望参数
#define NET_DVR_CONTROL_PTZ_MANUALTRACE         3316       //手动跟踪定位

#define NET_DVR_GET_ROI_DETECT_NUM				3349 //获取ROI检测区域编号数目
#define NET_DVR_GET_ROI_DETECT					3350 //获取ROI检测区域配置
#define NET_DVR_SET_ROI_DETECT					3351 //设置ROI检测区域配置
#define NET_DVR_GET_FACE_DETECT					3352 //获取人脸侦测配置
#define NET_DVR_SET_FACE_DETECT					3353 //设置人脸侦测配置
#define NET_DVR_GET_CORRIDOR_MODE				3354 //获取走廊模式功能配置
#define NET_DVR_SET_CORRIDOR_MODE				3355 //设置走廊模式功能配置

//2013-07-16
#define NET_DVR_GET_SCENECHANGE_DETECTIONCFG    3356 //获取场景变更报警配置
#define NET_DVR_SET_SCENECHANGE_DETECTIONCFG	3357 //设置场景变更报警配置

/********************************筒机6升级版42XX系列(V5.0.4) begin****************************/
#define NET_DVR_GET_TRAVERSE_PLANE_DETECTION    3360 
#define NET_DVR_SET_TRAVERSE_PLANE_DETECTION    3361 
#define NET_DVR_GET_FIELD_DETECTION				3362 //获取区域侦测配置
#define NET_DVR_SET_FIELD_DETECTION				3363 //设置区域侦测配置
#define NET_DVR_GET_DEFOCUSPARAM				3364 //获取虚焦侦测参数配置
#define NET_DVR_SET_DEFOCUSPARAM				3365 //设置虚焦侦测参数配置
#define NET_DVR_GET_AUDIOEXCEPTIONPARAM			3366 //获取音频异常配置
#define NET_DVR_SET_AUDIOEXCEPTIONPARAM			3367 //设置音频异常配置
#define NET_DVR_GET_CCDPARAMCFG_EX              3368 //获取CCD参数配置
#define NET_DVR_SET_CCDPARAMCFG_EX              3369 //设置CCD参数配置
#define NET_DVR_START_GET_INPUTVOLUME			3370//开始获取音量
/********************************筒机6升级版42XX系列(V5.0.4) end  ****************************/

/********************************前端IPC软件平台(V5.1.0) begin****************************/
#define NET_DVR_SET_SCH_TASK					3380 //设置球机定时任务
#define NET_DVR_GET_SCH_TASK					3381  //获取球机定时任务
#define NET_DVR_SET_PRESET_NAME					3382 //设置预置点名称
#define NET_DVR_GET_PRESET_NAME					3383 //获取预置点名称
#define NET_DVR_SET_AUDIO_NAME					3384 //设置语音名称
#define NET_DVR_GET_AUDIO_NAME					3385  //获取语音名称
/********************************前端IPC软件平台(V5.1.0) end  ****************************/


/********************************球机IPC V5.1.4 begin****************************/
#define NET_DVR_RESUME_INITRACKPOS              3386  //恢复跟踪初始位
/********************************球机IPC V5.1.4 end****************************/

/********************************智能人脸识别****************************/
#define NET_DVR_GET_FACESNAPCFG                 5001  //获取人脸抓拍参数
#define NET_DVR_SET_FACESNAPCFG                 5002  //设置人脸抓拍参数
#define NET_DVR_GET_DEVACCESS_CFG               5005  //获取接入设备参数
#define NET_DVR_SET_DEVACCESS_CFG               5006  //设置接入设备参数
#define NET_DVR_GET_SAVE_PATH_CFG               5007  //获取存储信息参数
#define NET_DVR_SET_SAVE_PATH_CFG               5008  //设置存储信息参数
#define NET_VCA_GET_RULECFG_V41			        5011  //获取行为分析参数(扩展)
#define NET_VCA_SET_RULECFG_V41			        5012  //设置行为分析参数(扩展)
#define NET_DVR_GET_AID_RULECFG_V41             5013  //获取交通事件规则参数
#define NET_DVR_SET_AID_RULECFG_V41             5014  //设置交通事件规则参数
#define NET_DVR_GET_TPS_RULECFG_V41             5015  //获取交通统计规则参数(扩展)
#define NET_DVR_SET_TPS_RULECFG_V41             5016  //设置交通统计规则参数(扩展)
#define NET_VCA_GET_FACEDETECT_RULECFG_V41      5017  //获取ATM人脸检测规则(扩展) 
#define NET_VCA_SET_FACEDETECT_RULECFG_V41      5018  //设置ATM人脸检测规则(扩展)
#define NET_DVR_GET_PDC_RULECFG_V41             5019  //设置人流量统计规则(扩展)
#define NET_DVR_SET_PDC_RULECFG_V41             5020  //获取人流量统计规则(扩展)
#define NET_DVR_GET_TRIAL_VERSION_CFG           5021  //获取试用版信息
#define NET_DVR_GET_VCA_CTRLINFO_CFG            5022  //批量获取智能控制参数
#define NET_DVR_SET_VCA_CTRLINFO_CFG            5023  //批量设置智能控制参数
#define NET_DVR_SYN_CHANNEL_NAME                5024  //同步通道名
#define NET_DVR_GET_RESET_COUNTER               5025  //获取统计数据清零参数（人流量、交通统计）
#define NET_DVR_SET_RESET_COUNTER               5026  //设置统计数据清零参数（人流量、交通统计）
#define NET_DVR_GET_OBJECT_COLOR                5027  //获取物体颜色属性
#define NET_DVR_SET_OBJECT_COLOR                5028  //设置物体颜色属性
#define NET_DVR_GET_AUX_AREA                    5029  //获取辅助区域
#define NET_DVR_SET_AUX_AREA                    5030  //设置辅助区域
#define NET_DVR_GET_CHAN_WORKMODE               5031  //获取通道工作模式
#define NET_DVR_SET_CHAN_WORKMODE               5032  //设置通道工作模式
#define NET_DVR_GET_SLAVE_CHANNEL               5033  //获取从通道参数
#define NET_DVR_SET_SLAVE_CHANNEL               5034  //设置从通道参数
#define NET_DVR_GET_VQD_EVENT_RULE              5035  //获取视频质量诊断事件规则
#define NET_DVR_SET_VQD_EVENT_RULE              5036  //设置视频质量诊断事件规则
#define NET_DVR_GET_BASELINE_SCENE              5037  //获取基准场景参数
#define NET_DVR_SET_BASELINE_SCENE              5038  //设置基准场景参数
#define NET_DVR_CONTROL_BASELINE_SCENE          5039  //基准场景操作
#define NET_DVR_SET_VCA_DETION_CFG				5040  //设置智能移动参数配置
#define NET_DVR_GET_VCA_DETION_CFG				5041  //获取智能移动参数配置

/********************************智能人脸识别 end****************************/

/********************************ITS****************************/
#define NET_ITS_GET_BASE_INFO		            5060//获取终端基本信息
#define NET_ITS_GET_IMGMERGE_CFG	            5063//获取图片合成配置参数
#define NET_ITS_SET_IMGMERGE_CFG	            5064//设置图片合成配置参数
#define NET_ITS_GET_UPLOAD_CFG		            5065//获取数据上传配置
#define NET_ITS_SET_UPLOAD_CFG		            5066//设置数据上传配置
#define NET_ITS_GET_WORKSTATE		            5069//获取终端工作状态
#define NET_ITS_GET_IPC_CHAN_CFG	            5070//获取通道IPC信息
#define NET_ITS_SET_IPC_CHAN_CFG	            5071//设置通道IPC信息
#define NET_ITS_GET_OVERLAP_CFG		            5072//获取字符叠加参数配置
#define NET_ITS_SET_OVERLAP_CFG	            	5073//设置字符叠加参数配置
#define NET_ITS_GET_ROAD_INFO	            	5076//获取路口信息

#define NET_ITS_REMOTE_DEVICE_CONTROL			5077//设置远程设备控制
#define NET_ITS_GET_GATEIPC_CHAN_CFG			5078//获取出入口参数
#define NET_ITS_SET_GATEIPC_CHAN_CFG			5079//设置出入口参数
#define NET_ITS_TRANSCHAN_START					5080//同步数据服务器建立连接
#define NET_ITS_GET_ECTWORKSTATE				5081//获取出入口终端工作状态
#define NET_ITS_GET_ECT_CHAN_INFO				5082//获取出入口终端通道状态

//2013-11-19
#define NET_DVR_SET_ITS_EXDEVCFG				5084 //设置ITS外接设备信息
#define NET_DVR_GET_ITS_EXDEVCFG				5085 //获取ITS外接设备信息
#define NET_DVR_GET_ITS_EXDEVSTATUS				5086 //获取ITS所有外接设备信息
#define NET_DVR_SET_ITS_ENDEVCMD                5087 //设置ITS终端出入口控制命令
#define NET_DVR_SET_ENISSUED_DATADEL            5088 //设置ITS终端出入口控制清除

//ITS 5090~5100 停车场项目
#define NET_ITS_GET_LAMP_CTRLCFG				5090  //获取内外置灯参数
#define NET_ITS_SET_LAMP_CTRLCFG				5091  //设置内外置灯参数
#define NET_ITS_GET_PARKSPACE_ATTRIBUTE_CFG     5092  //获取特殊车位参数
#define NET_ITS_SET_PARKSPACE_ATTRIBUTE_CFG     5093  //设置特殊车位参数
#define NET_ITS_GET_LAMP_EXTERNAL_CFG			5094  //获取外控配置参数
#define NET_ITS_SET_LAMP_EXTERNAL_CFG			5095  //设置外控配置参数
#define NET_ITS_SET_COMPEL_CAPTURE				5096  //设置车位强制抓图

/********************************ITS end****************************/

#define NET_DVR_GET_MONITOR_PLAN_VQD			5100  //长连接获取诊断服务器计划
#define NET_DVR_GET_MONITORID_VQD               5101  //长连接获取对应计划内的监控点信息
#define NET_DVR_SET_MONITOR_INFO                5102  //批量设置计划内的监控点信息 
#define NET_DVR_DEL_MONITOR_PLAN_VQD            5103  //删除计划
#define NET_DVR_GET_MONITOR_VQD_STATUS          5104  //平台查询诊断服务器的状态
#define NET_DVR_GET_RECORD_INFO                 5105  //获取资源图片查询
#define NET_DVR_GET_MONITOR_VQDCFG              5106  //获取服务器的监控点信息
#define NET_DVR_SET_MONITOR_VQDCFG              5107  //设置服务器的监控点信息
#define NET_DVR_SET_MONITOR_PLAN_VQDCFG         5108  //设置管理计划(单独的计划)

/*************************智能多场景********************************/
#define NET_DVR_GET_SCENE_CFG                   5201  //获取场景信息
#define NET_DVR_SET_SCENE_CFG                   5202  //设置场景信息
#define NET_DVR_GET_SCENE_REFERENCE_REGION      5203  //获取参考区域
#define NET_DVR_SET_SCENE_REFERENCE_REGION      5204  //设置参考区域
#define NET_DVR_GET_SCENE_CALIBRATION           5205  //获取标定信息
#define NET_DVR_SET_SCENE_CALIBRATION           5206  //设置标定信息
#define NET_DVR_GET_SCENE_MASK_REGION           5207  //获取屏蔽区域
#define NET_DVR_SET_SCENE_MASK_REGION           5208  //设置屏蔽区域
#define	NET_DVR_GET_SCENE_LANECFG		        5209  //获取车道规则
#define NET_DVR_SET_SCENE_LANECFG		        5210  //设置车道规则
#define NET_DVR_GET_SCENE_AID_RULECFG           5211  //获取交通事件规则参数
#define NET_DVR_SET_SCENE_AID_RULECFG           5212  //设置交通事件规则参数
#define NET_DVR_GET_SCENE_TPS_RULECFG           5213  //获取交通统计规则参数
#define NET_DVR_SET_SCENE_TPS_RULECFG           5214  //设置交通统计规则参数
#define NET_DVR_GET_SCENE_TIME_CFG              5215  //获取通道的场景时间段配置
#define NET_DVR_SET_SCENE_TIME_CFG              5216  //设置通道的场景时间段配置
#define NET_DVR_GET_FORENSICS_MODE              5217  //获取取证方式参数
#define NET_DVR_SET_FORENSICS_MODE              5218  //设置取证方式参数
/*************************智能多场景end*****************************/

#define NET_DVR_GET_DISK_RAID_INFO              6001  //获取磁盘Raid信息
#define NET_DVR_SET_DISK_RAID_INFO              6002  //设置磁盘Raid信息
	
#define NET_DVR_GET_DVR_SYNCHRONOUS_IPC         6005  //获取：是否为前端IPC同步设备参数
#define NET_DVR_SET_DVR_SYNCHRONOUS_IPC         6006  //设置：是否为前端IPC同步设备参数

#define NET_DVR_SET_DVR_IPC_PASSWD              6008  //设置：IPC用户名密码
#define NET_DVR_GET_DEVICE_NET_USING_INFO       6009  //获取：当前设备网络资源使用情况

#define NET_DVR_SET_DVR_IPC_NET                 6012  //设置：设置前端IPC的网络地址

#define NET_DVR_GET_RECORD_CHANNEL_INFO         6013  //获取：录像通道信息
#define NET_DVR_SET_RECORD_CHANNEL_INFO         6014  //设置：录像通道信息


#define NET_DVR_MOUNT_DISK						6015     // 加载磁盘
#define NET_DVR_UNMOUNT_DISK				    6016     // 卸载磁盘

// CVR 
#define NET_DVR_GET_STREAM_SRC_INFO				6017  //获取：流来源信息
#define NET_DVR_SET_STREAM_SRC_INFO				6018  //设置：流来源信息
#define NET_DVR_GET_STREAM_RECORD_INFO			6019  //获取：流录像信息
#define NET_DVR_SET_STREAM_RECORD_INFO			6020  //设置：流录像信息
#define NET_DVR_GET_STREAM_RECORD_STATUS		6021  //获取：流录像状态
#define NET_DVR_SET_STREAM_RECORD_STATUS		6022  //设置：流录像状态
#define NET_DVR_GET_STREAM_INFO					6023  //获取已添加的流ID信息

//NVR：96xx
#define NET_DVR_GET_IP_ALARM_GROUP_NUM          6100  //获取：IP通道报警输入输出组数
#define NET_DVR_GET_IP_ALARM_IN                 6101  //获取：IP通道报警输入信息
#define NET_DVR_GET_IP_ALARM_OUT                6102  //获取：IP通道报警输出信息

//9000 v2.2
#define NET_DVR_GET_FTPCFG_SECOND		        6103  	//获取图片上传FTP参数
#define NET_DVR_SET_FTPCFG_SECOND		        6104  	//设置图片上传FTP参数

#define NET_DVR_GET_DEFAULT_VIDEO_EFFECT		6105	   // 获取视频输入效果参数默认值
#define NET_DVR_SET_VIDEO_EFFECT				6106       // 设置通道视频输入图像参数
#define NET_DVR_DEL_INVALID_DISK				6107       // 删除无效磁盘

#define NET_DVR_GET_DRAWFRAME_DISK_QUOTA_CFG	6109	//获取抽帧通道磁盘配额
#define NET_DVR_SET_DRAWFRAME_DISK_QUOTA_CFG	6110	//设置抽帧通道磁盘配额

#define NET_DVR_GET_NAT_CFG                     6111     //获取NAT映射参数
#define NET_DVR_SET_NAT_CFG                     6112     //设置NAT映射参数  
#define NET_DVR_GET_AES_KEY                     6113     //获取设备AES加密密钥
#define NET_DVR_GET_POE_CFG                     6114     //获取POE参数
#define NET_DVR_SET_POE_CFG                     6115     //设置POE参数
#define NET_DVR_GET_CUSTOM_PRO_CFG              6116     //获取自定义协议参数
#define NET_DVR_SET_CUSTOM_PRO_CFG              6117     //设置自定义协议参数
#define NET_DVR_GET_STREAM_CABAC                6118     //获取码流压缩性能选项
#define NET_DVR_SET_STREAM_CABAC                6119     //设置码流压缩性能选项   
#define NET_DVR_GET_ESATA_MINISAS_USAGE_CFG	    6120  //获取eSATA和miniSAS用途
#define NET_DVR_SET_ESATA_MINISAS_USAGE_CFG	    6121  //设置eSATA和miniSAS用途 

#define NET_DVR_GET_HDCFG_V40			        6122  //获取硬盘信息参数
#define NET_DVR_SET_HDCFG_V40			        6123  //设置硬盘信息参数
#define NET_DVR_GET_POE_CHANNEL_ADD_MODE        6124     //获取POE通道添加方式
#define NET_DVR_SET_POE_CHANNEL_ADD_MODE        6125     //设置POE通道添加方式
#define NET_DVR_GET_DIGITAL_CHANNEL_STATE       6126     //获取设备数字通道状态
#define   NET_DVR_GET_BONJOUR_CFG    6127 // 获取Bonjour信息
#define   NET_DVR_SET_BONJOUR_CFG    6128 // 设置Bonjour信息


#define NET_DVR_GET_SOCKS_CFG	     6130    //获取SOCKS信息 
#define NET_DVR_SET_SOCKS_CFG  	     6131    //设置SOCKS信息

#define	NET_DVR_GET_QOS_CFG	         6132	// 获取QoS信息
#define NET_DVR_SET_QOS_CFG	         6133	// 设置QoS信息

#define NET_DVR_GET_HTTPS_CFG		 6134		//获取HTTPS信息
#define NET_DVR_SET_HTTPS_CFG		 6135		//设置HTTPS信息

#define NET_DVR_GET_WD1_CFG          6136 //远程获取WD1使能开关
#define NET_DVR_SET_WD1_CFG          6137 //远程设置WD1使能开关

#define NET_DVR_CREATE_CERT          6138     //创建证书
#define NET_DVR_DELETE_CERT          6139     //删除证书


#define NET_DVR_GET_RECORD_LOCK_PERCENTAGE	    6140  //获取录像段锁定比例
#define NET_DVR_SET_RECORD_LOCK_PERCENTAGE      6141  //设置录像段锁定比例

#define NET_DVR_CMD_TRIGGER_PERIOD_RECORD	    6144 //外部命令触发指定时间录像
#define NET_DVR_UPLOAD_CERT                     6145    //上传证书
#define NET_DVR_DOWNLOAD_CERT                   6146     //下载证书
#define NET_DVR_GET_CERT                        6147     //获取证书

#define NET_DVR_GET_POS_FILTER_CFG				6148	//获取POS过滤规则
#define NET_DVR_SET_POS_FILTER_CFG				6149	//设置POS过滤规则
#define NET_DVR_GET_CONNECT_POS_CFG				6150    //获取DVR与POS连接方式
#define NET_DVR_SET_CONNECT_POS_CFG				6151	//设置DVR与POS连接方式
#define NET_DVR_GET_CHAN_FILTER_CFG				6152	//获取规则与通道关联信息
#define NET_DVR_SET_CHAN_FILTER_CFG				6153    //设置规则与通道关联信息


#define NET_DVR_GET_FTPCFG_V40		            6162	//获取FTP信息
#define NET_DVR_SET_FTPCFG_V40		            6163	//设置FTP信息

#define NET_DVR_GET_MONTHLY_RECORD_DISTRIBUTION 6164   //获取月历录像分布
#define NET_DVR_GET_ACCESS_DEVICE_CHANNEL_INFO  6165   //获取待接入设备通道信息
#define NET_DVR_GET_PREVIEW_SWITCH_CFG			6166   //获取设备本地预览切换参数
#define NET_DVR_SET_PREVIEW_SWITCH_CFG			6167   //设置设备本地预览切换参数

//Netra3.0.0
#define NET_DVR_GET_N_PLUS_ONE_WORK_MODE			6168	//获取N+1工作模式
#define NET_DVR_SET_N_PLUS_ONE_WORK_MODE			6169	//设置N+1工作模式

#define NET_DVR_GET_HD_STATUS	 					6170	//获取硬盘状态
#define NET_DVR_SET_HD_STATUS	 					6171	//设置硬盘状态

#define NET_DVR_IMPORT_IPC_CFG_FILE					6172    //导入IPC配置文件
#define NET_DVR_EXPORT_IPC_CFG_FILE					6173    //导出IPC配置文件
#define NET_DVR_UPGRADE_IPC							6174    //升级IP通道

#define NET_DVR_GET_RAID_BACKGROUND_TASK_SPEED		6175	//获取RAID后台任务速度
#define NET_DVR_SET_RAID_BACKGROUND_TASK_SPEED		6176	//设置RAID后台任务速度

//marvell 256路NVR
#define NET_DVR_GET_EXCEPTIONCFG_V40                6177    //获取异常参数配置
#define NET_DVR_SET_EXCEPTIONCFG_V40                6178    //设置异常参数配置
#define NET_DVR_GET_PICCFG_V40                      6179    //获取图象参数 支持变长	NetSDK_
#define NET_DVR_SET_PICCFG_V40                      6180    //设置图象参数， 支持变长
#define NET_DVR_GET_ALARMINCFG_V40                  6181    //获取报警输入参数，支持变长
#define NET_DVR_SET_ALARMINCFG_V40                  6182    //获取报警输入参数，支持变长
#define NET_DVR_GET_IPALARMINCFG_V40                6183    //获取IP报警输入接入配置信息 
#define NET_DVR_GET_IPALARMOUTCFG_V40               6185    //获取IP报警输出接入配置信息 
#define NET_DVR_GET_USERCFG_V40                     6187    //获取用户参数
#define NET_DVR_SET_USERCFG_V40                     6188    //设置用户参数
#define NET_DVR_GET_WORK_STATUS                     6189    //获取设备工作状态
#define NET_DVR_GET_JPEG_CAPTURE_CFG_V40            6190    //获取DVR抓图配置
#define NET_DVR_SET_JPEG_CAPTURE_CFG_V40            6191    //设置DVR抓图配置
#define NET_DVR_GET_HDGROUP_CFG_V40                 6192    //获取盘组管理配置参数
#define NET_DVR_SET_HDGROUP_CFG_V40                 6193    //设置盘组管理配置参数

//91系列HD-SDI高清DVR
#define NET_DVR_GET_ACCESS_CAMERA_INFO      6201 // 获取前端相机信息
#define NET_DVR_SET_ACCESS_CAMERA_INFO      6202 // 设置前端相机信息
#define NET_DVR_PULL_DISK					6203 // 安全拔盘
#define NET_DVR_SCAN_RAID					6204 // 扫描阵列
					
#define NET_DVR_GET_RECORD_PACK				    6301    //获取录像打包参数
#define NET_DVR_SET_RECORD_PACK				    6302    //设置录像打包参数

// CVR 2.0.X
#define NET_DVR_GET_USER_RIGHT_CFG				6210        // 获取用户权限
#define NET_DVR_SET_USER_RIGHT_CFG				6211        // 设置用户权限

#define NET_DVR_ONE_KEY_CONFIG			        6212		// 一键配置CVR
#define NET_DVR_RESTART_SERVICE					6213        // 重启CVR服务

#define NET_DVR_GET_MAX_MACHINE_NUM_CFG			6214		// 获取备机最大个数
#define NET_DVR_SET_MAX_MACHINE_NUM_CFG			6215		// 设置备机最大个数

#define NET_DVR_ADD_DEVICE						6216		//N+1模式添加设备
#define NET_DVR_DEL_DEVICE						6217		//N+1模式删除设备

#define NET_DVR_GET_DATA_CALLBACK_CFG			6218		// 获取数据回迁状态
#define NET_DVR_SET_DATA_CALLBACK_CFG			6219		// 设置数据回迁状态

#define NET_DVR_CLONE_LUN						6220	//克隆LUN卷
#define NET_DVR_EXPAND_LUN						6221	//扩展和重命名LUN卷

#define NET_DVR_GET_N_PLUS_ONE_DEVICE_INFO		6222    //获取N+1设备信息
#define NET_DVR_MODIFY_DVR_NET_DISK				6223	//修改DVR网盘
//#define NET_DVR_DEL_DVR_NET_DISK				6224	//删除DVR网盘

#define NET_DVR_CREATE_NAS						6225	//创建NAS
#define NET_DVR_DELETE_NAS						6226	//删除NAS 

#define NET_DVR_OPEN_ISCSI	 					6227	//开启iSCSI
#define NET_DVR_CLOSE_ISCSI						6228	//关闭iSCSI 

#define NET_DVR_GET_FC					        6229    //获取光纤信息
#define NET_DVR_OPEN_FC	 						6230	//开启FC
#define NET_DVR_CLOSE_FC	 					6231	//关闭FC

//审讯机外部命令
#define NET_DVR_INQUEST_GET_CDW_STATUS 			6350  //获取审讯机刻录状态-长连接

#define NET_DVR_GET_OUTPUT_CFG                  6401        //获取显示输出参数
#define NET_DVR_SET_OUTPUT_CFG                  6402        //设置显示输出参数
#define NET_DVR_CODER_DISPLAY_START             6403        //开始输出
#define NET_DVR_CODER_DISPLAY_STOP              6404        //停止输出
#define NET_DVR_GET_WINDOW_STATUS               6405        //获取显示窗口状态

//VQD功能接口
#define NET_DVR_GET_VQD_LOOP_DIAGNOSE_CFG       6406        //获取VQD循环诊断配置参数
#define NET_DVR_SET_VQD_LOOP_DIAGNOSE_CFG       6407        //设置VQD循环诊断配置参数
#define NET_DVR_GET_VQD_DIAGNOSE_INFO           6408        //手动获取VQD诊断信息

#define	NET_DVR_GET_DEVICE_LAN_ENCODE			6501 //获取设备的语言编码


#define NET_DVR_GET_MB_POWERCTRLPARA		    8000//获取启动控制参数
#define	NET_DVR_SET_MB_POWERCTRLPARA		    8001 //设置启动控制参数
#define NET_DVR_GET_AUTOBACKUPPARA			    8002//获取自动备份参数
#define NET_DVR_SET_AUTOBACKUPPARA			    8003 //设置自动备份参数
#define NET_DVR_GET_MB_GPSPARA				    8004//获取GPS参数
#define NET_DVR_SET_MB_GPSPARA				    8005 //设置GPS参数
#define NET_DVR_GET_MB_SENSORINPARA			    8006//获取SENSOR参数
#define NET_DVR_SET_MB_SENSORINPARA			    8007 //设置SENSOR参数
#define NET_DVR_GET_GSENSORPARA				    8008//获取GSENSOR参数
#define NET_DVR_SET_GSENSORPARA				    8009 //设置GSENSOR参数
#define NET_DVR_GET_MB_DOWNLOADSVRPARA		    8010//获取下载服务器参数
#define NET_DVR_SET_MB_DOWNLOADSVRPARA		    8011//设置下载服务器参数
#define NET_DVR_GET_PLATERECOG_PARA			    8012//获取车牌识别参数
#define NET_DVR_SET_PLATERECOG_PARA			    8013//设置车牌识别参数
#define NET_DVR_GET_ENFORCESYS_PARA			    8014//获取车辆稽查参数
#define NET_DVR_SET_ENFORCESYS_PARA		    	8015//设置车辆稽查参数
#define NET_DVR_GET_GPS_DATA					8016 //获取GPS数据
#define NET_DVR_GET_ANALOG_ALARMINCFG			8017//获取模拟报警输入参数
#define NET_DVR_SET_ANALOG_ALARMINCFG			8018//设置模拟报警输入参数

/*****************************电视墙 start****************************/
#define	NET_DVR_MATRIX_WALL_SET		            9001  //设置电视墙中屏幕参数
#define	NET_DVR_MATRIX_WALL_GET	                9002  //获取电视墙中屏幕参数
#define	NET_DVR_WALLWIN_GET			            9003  //电视墙中获取窗口参数
#define	NET_DVR_WALLWIN_SET			            9004  //电视墙中设置窗口参数
#define	NET_DVR_WALLWINPARAM_SET		        9005  //设置电视墙窗口相关参数
#define	NET_DVR_WALLWINPARAM_GET		        9006  //获取电视墙窗口相关参数
#define NET_DVR_WALLSCENEPARAM_GET				9007  //设置场景模式参数
#define NET_DVR_WALLSCENEPARAM_SET				9008  //获取场景模式参数
#define NET_DVR_MATRIX_GETWINSTATUS             9009  //获取窗口解码状态
#define	NET_DVR_GET_WINASSOCIATEDDEVINFO		9010  //电视墙中获取对应资源信息
#define	NET_DVR_WALLOUTPUT_GET		            9011  //电视墙中获取显示输出参数
#define	NET_DVR_WALLOUTPUT_SET		            9012  //电视墙中设置显示输出参数
#define NET_DVR_GET_UNITEDMATRIXSYSTEM          9013  //电视墙中获取对应资源
#define NET_DVR_GET_WALL_CFG					9014  //获取电视墙全局参数
#define NET_DVR_SET_WALL_CFG					9015  //设置电视墙全局参数
#define NET_DVR_CLOSE_ALL_WND					9016  //关闭所有窗口
#define NET_DVR_SWITCH_WIN_TOP                  9017  //窗口置顶
#define NET_DVR_SWITCH_WIN_BOTTOM               9018  //窗口置底

#define	NET_DVR_CLOSE_ALL_WND_V41				9019  //电视墙关闭所有窗口v41（有多个电视墙）
#define	NET_DVR_GET_WALL_WINDOW_V41				9020  //获取电视墙中的窗口v41
#define	NET_DVR_SET_WALL_WINDOW_V41				9021  //设置电视墙中的窗口v41
#define	NET_DVR_GET_CURRENT_SCENE_V41			9022  //获取当前电视墙中正在使用的场景v41
#define	NET_DVR_GET_WALL_SCENE_PARAM_V41		9023  //获取当前电视墙中正在使用的场景v41
#define	NET_DVR_SET_WALL_SCENE_PARAM_V41		9024  //设置当前电视墙中正在使用的场景v41
#define NET_DVR_GET_MATRIX_LOGO_CFG             9025  //获取logo参数
#define NET_DVR_SET_MATRIX_LOGO_CFG             9026  //设置logo参数
#define NET_DVR_GET_WIN_LOGO_CFG				9027  //获取窗口logo参数
#define NET_DVR_SET_WIN_LOGO_CFG				9028  //设置窗口logo参数
#define NET_DVR_DELETE_LOGO                     9029  //删除logo
#define NET_DVR_SET_DISPLAY_EFFECT_CFG			9030  //设置显示输出效果参数v41
#define NET_DVR_GET_DISPLAY_EFFECT_CFG			9031  //获取显示输出效果参数v41
#define NET_DVR_DEC_PLAY_REMOTE_FILE			9032  //解码播放远程文件
#define NET_DVR_GET_WIN_ZOOM_STATUS             9033  //获取窗口电子放大状态
/*****************************电视墙 end******************************/

/*******************************LCD拼接屏 begin******************************************/
#define NET_DVR_SIMULATE_REMOTE_CONTROL         9035    //模拟遥控按键 2013-09-05
#define NET_DVR_SET_SCREEN_SIGNAL_CFG			9036	//设置屏幕信号源参数
#define	NET_DVR_GET_SCREEN_SIGNAL_CFG			9037	//获取屏幕信号源参数
#define NET_DVR_SET_SCREEN_SPLICE_CFG  			9038	//设置屏幕拼接
#define	NET_DVR_GET_SCREEN_SPLICE_CFG			9039	//获取屏幕拼接
#define NET_DVR_GET_SCREEN_FAN_WORK_MODE 		9040	//获取风扇工作方式
#define NET_DVR_SET_SCREEN_FAN_WORK_MODE 		9041	//设置风扇工作方式
#define NET_DVR_SHOW_SCREEN_WORK_STATUS  		9044	//显示屏幕状态
#define NET_DVR_GET_VGA_CFG  					9045	//获取VGA信号配置
#define NET_DVR_SET_VGA_CFG  					9046	//设置VGA信号配置
#define NET_DVR_GET_SCREEN_MENU_CFG				9048   //获取屏幕菜单配置
#define NET_DVR_SET_SCREEN_MENU_CFG  			9049	//设置屏幕菜单配置
#define NET_DVR_SET_SCREEN_DISPLAY_CFG  	    9050	//设置显示参数 2013-08-28
#define	NET_DVR_GET_SCREEN_DISPLAY_CFG	        9051	//获取显示参数 2013-08-28
#define NET_DVR_SET_PIP_CFG  					9060	//设置画中画参数
#define	NET_DVR_GET_PIP_CFG						9061	//获取画中画参数
#define NET_DVR_SET_DEFOG_LCD  					9073	//设置去雾参数
#define	NET_DVR_GET_DEFOG_LCD					9074	//获取去雾参数
#define NET_DVR_SHOW_IP  						9075	//显示IP
#define NET_DVR_SCREEN_MAINTENANCE_WALL			9076	//屏幕维墙
#define NET_DVR_SET_SCREEN_POS  				9077	//设置屏幕位置参数
#define	NET_DVR_GET_SCREEN_POS					9078	//获取屏幕位置参数
/*******************************LCD拼接屏 end******************************************/

#define NET_DVR_GET_STREAM_DST_COMPRESSIONINFO	9101  //获取目标压缩参数
#define NET_DVR_SET_STREAM_DST_COMPRESSIONINFO  9102  //设置目标压缩参数
#define NET_DVR_GET_STREAM_TRANS_STATUS			9103  //获取流状态
#define NET_DVR_GET_DEVICE_TRANS_STATUS			9104  //获取设备转码状态
#define NET_DVR_GET_ALLSTREAM_SRC_INFO  		9105  //获取所有流信息
#define NET_DVR_GET_BIG_SCREEN_AUDIO	        9106  //获取大屏音频信息
#define NET_DVR_SET_BIG_SCREEN_AUDIO	        9107  //设置大屏音频信息
#define NET_DVR_GET_DEV_WORK_MODE				9108  //获取转码设备工作模式
#define NET_DVR_SET_DEV_WORK_MODE				9109  //设置转码设备工作模式
#define NET_DVR_APPLY_TRANS_CHAN                9110  //按流ID申请转码通道
#define NET_DVR_GET_DISPCHAN_CFG                9111  //批量获取显示通道参数
#define NET_DVR_SET_DISPCHAN_CFG                9112  //批量设置显示通道参数

#define NET_DVR_GET_DEC_CHAN_STATUS				9113  //获取解码通道解码状态
#define NET_DVR_GET_DISP_CHAN_STATUS			9114  //获取显示通道状态        
#define NET_DVR_GET_ALARMIN_STATUS				9115  //获取报警输入状态
#define NET_DVR_GET_ALARMOUT_STATUS				9116  //获取报警输出状态
#define NET_DVR_GET_AUDIO_CHAN_STATUS			9117  //获取语音对讲状态

#define	NET_DVR_GET_VIDEO_AUDIOIN_CFG			9118   //获取视频的音频输入参数
#define NET_DVR_SET_VIDEO_AUDIOIN_CFG			9119   //设置视频的音频输入参数

#define	NET_DVR_SET_BASEMAP_CFG					9120  //设置底图参数
#define NET_DVR_GET_BASEMAP_CFG					9121  //获取底图参数
#define NET_DVR_GET_VIRTUAL_SCREEN_CFG          9122  //获取超高清输入子系统参数
#define NET_DVR_SET_VIRTUAL_SCREEN_CFG          9123  //设置超高清输入子系统参数
#define NET_DVR_GET_BASEMAP_WIN_CFG				9124  //获取底图窗口参数
#define NET_DVR_SET_BASEMAP_WIN_CFG				9125  //设置底图窗口参数
#define NET_DVR_DELETE_PICTURE					9126  //删除底图
#define NET_DVR_GET_BASEMAP_PIC_INFO			9127  //获取底图图片信息


#define NET_DVR_GET_RS485_WORK_MODE             10001 //获取RS485串口工作模式
#define NET_DVR_SET_RS485_WORK_MODE             10002 //设置RS485串口工作模式
#define NET_DVR_GET_SPLITTER_TRANS_CHAN_CFG     10003 //获取码分器透明通道参数
#define NET_DVR_SET_SPLITTER_TRANS_CHAN_CFG     10004 //设置码分器透明通道参数

#define  NET_DVR_GET_SIP_CFG					11001   //IP可视化机获取SIP参数
#define  NET_DVR_SET_SIP_CFG					11002   //IP可视化机设置SIP参数
#define  NET_DVR_GET_IP_VIEW_DEVCFG				11003  //获取IP对讲分机配置
#define  NET_DVR_SET_IP_VIEW_DEVCFG				11004  //设置IP对讲分机配置
#define  NET_DVR_GET_IP_VIEW_AUDIO_CFG			11005  //获取IP对讲分机音频参数
#define  NET_DVR_SET_IP_VIEW_AUDIO_CFG			11006  //设置IP对讲分机音频参数
#define	 NET_DVR_GET_IP_VIEW_CALL_CFG			11007  //获取IP对讲分机呼叫参数
#define  NET_DVR_SET_IP_VIEW_CALL_CFG			11008  //设置IP对讲分机呼叫参数
#define	 NET_DVR_GET_AUDIO_LIMIT_ALARM_CFG		11009	//获取声音超限配置参数
#define	 NET_DVR_SET_AUDIO_LIMIT_ALARM_CFG		11010	//设置声音超限配置参数
#define	 NET_DVR_GET_BUTTON_DOWN_ALARM_CFG		11011	//获取按钮按下告警配置参数
#define	 NET_DVR_SET_BUTTON_DOWN_ALARM_CFG		11012	//设置按钮按下告警配置参数

#define NET_DVR_GET_ISCSI_CFG                   11070 // 获取ISCSI存储配置协议 
#define NET_DVR_SET_ISCSI_CFG                   11071 // 获取ISCSI存储配置协议 

//2013-11-21 获取设备当前的温度和湿度
#define NET_DVR_GET_TEMP_HUMI                   12005

#define NET_DVR_T1_TEST_CMD                    131073 //当测试命令来用，通过数据区域的文本内容区分具体做什么.数据长度不得大于1024
                                                      //数据区格式为：<T1TestCmd type="0"/>//恢复设备默认参数并关机。

// 美分定制菜单输出模式外部命令
#define NET_DVR_GET_MEMU_OUTPUT_MODE			0x26001			// 获取菜单输出模式
#define NET_DVR_SET_MEMU_OUTPUT_MODE			0x26002			// 设置菜单输出模式


#define NET_DVR_GET_SELFCHECK_RESULT        20000    //获取设备自检结果
#define NET_DVR_SET_TEST_COMMAND            20001    //设置测试控制命令
#define NET_DVR_SET_TEST_DEVMODULE          20002    //设置测试硬件模块控制命令
#define NET_DVR_GET_TEST_DEVMODULE          20003    //获取测试硬件模块控制命令

#define NET_DVR_SET_AUTOFOCUS_TEST          20004 //保存自动对焦参数 2013-10-26

/***************************DS9000新增命令(_V30) end *****************************/

#define NET_DVR_GET_TEST_VERSION_HEAD           268435441   //获取测试版本头
#define NET_DVR_SET_TEST_VERSION_HEAD           268435442   //设置测试版本头
#define NET_DVR_GET_TEST_VERSION_HEAD_V1        268435443   //获取测试版本头-第二版
#define NET_DVR_SET_TEST_VERSION_HEAD_V1        268435444   //设置测试版本头-第二版
#define NET_DVR_GET_TEST_VERSION_HEAD_V2        268435445   //获取测试版本头-第三版
#define NET_DVR_SET_TEST_VERSION_HEAD_V2        268435446   //设置测试版本头-第三版

#define NET_DVR_GET_TEST_VERSION_HEAD_ONLY_0    268435447   //获取测试版本头,当前仅有一个版本
#define NET_DVR_SET_TEST_VERSION_HEAD_ONLY_0    268435448   //设置测试版本头,当前仅有一个版本


#define MAX_LOCAL_ADDR_LEN			 96		//SOCKS最大本地网段个数
#define	MAX_COUNTRY_NAME_LEN		  4		//国家简写名称长度

/************************DVR日志 begin***************************/

/* 报警 */
//主类型
#define MAJOR_ALARM						0x1
//次类型
#define MINOR_ALARM_IN					0x1		/* 报警输入 */
#define MINOR_ALARM_OUT					0x2		/* 报警输出 */
#define MINOR_MOTDET_START				0x3		/* 移动侦测报警开始 */
#define MINOR_MOTDET_STOP				0x4		/* 移动侦测报警结束 */
#define MINOR_HIDE_ALARM_START			0x5		/* 遮挡报警开始 */
#define MINOR_HIDE_ALARM_STOP			0x6		/* 遮挡报警结束 */
#define MINOR_VCA_ALARM_START			0x7		/*智能报警开始*/
#define MINOR_VCA_ALARM_STOP			0x8		/*智能报警停止*/
#define MINOR_ITS_ALARM_START           0x09    // 交通事件报警开始
#define MINOR_ITS_ALARM_STOP            0x0A    // 交通事件报警结束
//2010-11-10 网络报警日志
#define MINOR_NETALARM_START            0x0b    /*网络报警开始*/
#define MINOR_NETALARM_STOP             0x0c    /*网络报警结束*/
//2010-12-16 报警板日志，与"MINOR_ALARM_IN"配对使用
#define MINOR_NETALARM_RESUME			0x0d	/*网络报警恢复*/
//2012-4-5 IPC PIR、无线、呼救报警
#define MINOR_WIRELESS_ALARM_START      0x0e  /* 无线报警开始 */
#define MINOR_WIRELESS_ALARM_STOP  	    0x0f /* 无线报警结束 */
#define MINOR_PIR_ALARM_START   	    0x10  /* 人体感应报警开始 */
#define MINOR_PIR_ALARM_STOP   		    0x11  /* 人体感应报警结束 */
#define MINOR_CALLHELP_ALARM_START  	0x12  /* 呼救报警开始 */
#define MINOR_CALLHELP_ALARM_STOP  		0x13  /* 呼救报警结束 */
#define MINOR_IPCHANNEL_ALARMIN_START   0x14  //数字通道报警输入开始：PCNVR在接收到数字通道的MINOR_ALARM_IN产生“数字通道报警输入开始”，10s，再收不到MINOR_ALARM_IN，产生“数字通道报警输入结束”
#define MINOR_IPCHANNEL_ALARMIN_STOP    0x15  //数字通道报警输入开始：同上
#define MINOR_DETECTFACE_ALARM_START    0x16  /* 人脸侦测报警开始 */
#define MINOR_DETECTFACE_ALARM_STOP  	0x17  /* 人脸侦测报警结束 */
#define MINOR_VQD_ALARM_START           0x18  //VQD报警
#define MINOR_VQD_ALARM_STOP            0x19  //VQD报警结束 
#define MINOR_VCA_SECNECHANGE_DETECTION 0x1a  //场景侦测报警 2013-07-16
#define MINOR_VCA_ALARM_LINE_DETECTION_BEGIN            0x20  
#define MINOR_VCA_ALARM_LINE_DETECTION_END            	0x21  
#define MINOR_VCA_ALARM_INTRUDE_BEGIN				  	0x22  //区域侦测开始	
#define MINOR_VCA_ALARM_INTRUDE_END				   		0x23  //区域侦测结束	
#define MINOR_VCA_ALARM_AUDIOINPUT                		0x24   //音频异常输入
#define MINOR_VCA_ALARM_AUDIOABNORMAL             		0x25   //声强突变
#define MINOR_VCA_DEFOCUS_DETECTION_BEGIN            	0x26  //虚焦侦测开始
#define MINOR_VCA_DEFOCUS_DETECTION_END            		0x27  //虚焦侦测结束

//民用NVR
#define MINOR_EXT_ALARM            0x28             /*IPC外部报警*/

#define MINOR_VCA_FACE_ALARM_BEGIN					0x29	   /*人脸侦测开始*/
#define MINOR_VCA_FACE_ALARM_END					0x30	   /*人脸侦测结束*/
#define MINOR_VCA_SCENE_CHANGE_ALARM_BEGIN			0x31   /*场景变更侦测开始*/
#define MINOR_VCA_SCENE_CHANGE_ALARM_END			0x32   /*场景变更侦测结束*/
#define MINOR_VCA_ALARM_AUDIOINPUT_BEGIN			0x33   /*音频异常输入开始*/
#define MINOR_VCA_ALARM_AUDIOINPUT_END				0x34   /*音频异常输入结束*/
#define MINOR_VCA_ALARM_AUDIOABNORMAL_BEGIN			0x35  /*声强突变侦测开始*/
#define MINOR_VCA_ALARM_AUDIOABNORMAL_END			0x36  /*声强突变侦测结束*/

/* 异常 */
//主类型
#define MAJOR_EXCEPTION					0x2
//次类型
#define MINOR_RAID_ERROR				0x20	/* 阵列异常 */
#define MINOR_VI_LOST					0x21	/* 视频信号丢失 */
#define MINOR_ILLEGAL_ACCESS			0x22	/* 非法访问 */
#define MINOR_HD_FULL					0x23	/* 硬盘满 */
#define MINOR_HD_ERROR					0x24	/* 硬盘错误 */
#define MINOR_DCD_LOST					0x25	/* MODEM 掉线(保留不使用) */
#define MINOR_IP_CONFLICT				0x26	/* IP地址冲突 */
#define MINOR_NET_BROKEN				0x27	/* 网络断开*/
#define MINOR_REC_ERROR                 0x28    /* 录像出错 */
#define MINOR_IPC_NO_LINK               0x29    /* IPC连接异常 */
#define MINOR_VI_EXCEPTION              0x2a    /* 视频输入异常(只针对模拟通道) */
#define MINOR_IPC_IP_CONFLICT           0x2b    /*ipc ip 地址 冲突*/
#define MINOR_SENCE_EXCEPTION           0x2c    // 场景异常

#define MINOR_PIC_REC_ERROR  			0x2d    /* 抓图出错--获取图片文件失败*/
#define MINOR_VI_MISMATCH    			0x2e    /* 视频制式不匹配*/
#define MINOR_RESOLUTION_MISMATCH		0x2f	/*前端/录像分辨率不匹配  */

//2009-12-16 增加视频综合平台日志类型
#define MINOR_FANABNORMAL				0x31	/* 视频综合平台：风扇状态异常 */
#define MINOR_FANRESUME					0x32	/* 视频综合平台：风扇状态恢复正常 */
#define MINOR_SUBSYSTEM_ABNORMALREBOOT	0x33	/* 视频综合平台：6467异常重启 */
#define MINOR_MATRIX_STARTBUZZER		0x34	/* 视频综合平台：dm6467异常，启动蜂鸣器 */

//2010-01-22 增加视频综合平台异常日志次类型
#define MINOR_NET_ABNORMAL				0x35	/*网络状态异常*/
#define MINOR_MEM_ABNORMAL				0x36	/*内存状态异常*/
#define MINOR_FILE_ABNORMAL				0x37	/*文件状态异常*/
#define MINOR_PANEL_ABNORMAL			0x38 /*前面板连接异常*/
#define MINOR_PANEL_RESUME				0x39 /*前面板恢复正常*/	
#define MINOR_RS485_DEVICE_ABNORMAL		0x3a 	/*RS485连接状态异常*/
#define MINOR_RS485_DEVICE_REVERT		0x3b    /*RS485连接状态异常恢复*/

//2012-2-18 增加大屏控制器异常日志次类型
#define MINOR_SCREEN_SUBSYSTEM_ABNORMALREBOOT   0x3c            //子板异常启动
#define	MINOR_SCREEN_SUBSYSTEM_ABNORMALINSERT	0x3d			//子板插入
#define	MINOR_SCREEN_SUBSYSTEM_ABNORMALPULLOUT	0x3e			//子板拔出
#define	MINOR_SCREEN_ABNARMALTEMPERATURE		0x3f			//温度异常
//2012-07-26 视频综合平台v2.1
#define MINOR_HIGH_TEMPERATURE_PROTECT  0x40 //子板过热保护

//Netra 2.2.2
#define MINOR_RECORD_OVERFLOW           0x41              /*缓冲区溢出*/  
#define MINOR_DSP_ABNORMAL              0x42              //DSP异常 

//Netra 3.0.0
#define MINOR_ANR_RECORD_FAIED                 0x43         /*ANR录像失败*/ 
#define MINOR_SPARE_WORK_DEVICE_EXCEPT         0x44			/*热备设备工作机异常*/
#define MINOR_START_IPC_MAS_FAILED             0x45			/*开启IPC MAS失败*/ 
//高性能 256路NVR
#define MINOR_IPCM_CRASH                       0x46         /*IPCM异常重启*/

//[add]by silujie 2013-3-22 14:16
//0x2000~0x3fff 为设备报警日志
//0x4000~0x5000 为设备异常日志
#define MINOR_SUBSYSTEM_IP_CONFLICT		0x4000		//子板IP冲突
#define MINOR_SUBSYSTEM_NET_BROKEN		0x4001		//子板断网
#define	MINOR_FAN_ABNORMAL				0x4002		//风扇异常
#define	MINOR_BACKPANEL_TEMPERATURE_ABNORMAL		0x4003		//背板温度异常

/* 操作 */
//主类型
#define MAJOR_OPERATION					0x3

//次类型
#define MINOR_VCA_MOTIONEXCEPTION		0x29  //智能侦测异常
#define MINOR_START_DVR					0x41	/* 开机 */
#define MINOR_STOP_DVR					0x42	/* 关机 */
#define MINOR_STOP_ABNORMAL				0x43	/* 异常关机 */
#define MINOR_REBOOT_DVR                0x44    /*本地重启设备*/

#define MINOR_LOCAL_LOGIN				0x50	/* 本地登陆 */
#define MINOR_LOCAL_LOGOUT				0x51	/* 本地注销登陆 */
#define MINOR_LOCAL_CFG_PARM			0x52	/* 本地配置参数 */
#define MINOR_LOCAL_PLAYBYFILE          0x53	/* 本地按文件回放或下载 */
#define MINOR_LOCAL_PLAYBYTIME          0x54	/* 本地按时间回放或下载*/
#define MINOR_LOCAL_START_REC			0x55	/* 本地开始录像 */
#define MINOR_LOCAL_STOP_REC			0x56	/* 本地停止录像 */
#define MINOR_LOCAL_PTZCTRL				0x57	/* 本地云台控制 */
#define MINOR_LOCAL_PREVIEW				0x58	/* 本地预览 (保留不使用)*/
#define MINOR_LOCAL_MODIFY_TIME         0x59	/* 本地修改时间(保留不使用) */
#define MINOR_LOCAL_UPGRADE             0x5a	/* 本地升级 */
#define MINOR_LOCAL_RECFILE_OUTPUT      0x5b    /* 本地备份录象文件 */
#define MINOR_LOCAL_FORMAT_HDD          0x5c    /* 本地初始化硬盘 */
#define MINOR_LOCAL_CFGFILE_OUTPUT      0x5d    /* 导出本地配置文件 */
#define MINOR_LOCAL_CFGFILE_INPUT       0x5e    /* 导入本地配置文件 */
#define MINOR_LOCAL_COPYFILE            0x5f    /* 本地备份文件 */
#define MINOR_LOCAL_LOCKFILE            0x60    /* 本地锁定录像文件 */
#define MINOR_LOCAL_UNLOCKFILE          0x61    /* 本地解锁录像文件 */
#define MINOR_LOCAL_DVR_ALARM           0x62    /* 本地手动清除和触发报警*/
#define MINOR_IPC_ADD                   0x63    /* 本地添加IPC */
#define MINOR_IPC_DEL                   0x64    /* 本地删除IPC */
#define MINOR_IPC_SET                   0x65    /* 本地设置IPC */
#define MINOR_LOCAL_START_BACKUP		0x66	/* 本地开始备份 */
#define MINOR_LOCAL_STOP_BACKUP			0x67	/* 本地停止备份*/
#define MINOR_LOCAL_COPYFILE_START_TIME 0x68	/* 本地备份开始时间*/
#define MINOR_LOCAL_COPYFILE_END_TIME	0x69	/* 本地备份结束时间*/
#define MINOR_LOCAL_ADD_NAS             0x6a	/*本地添加网络硬盘 （nfs、iscsi）*/
#define MINOR_LOCAL_DEL_NAS             0x6b	/* 本地删除nas盘 （nfs、iscsi）*/
#define MINOR_LOCAL_SET_NAS             0x6c	/* 本地设置nas盘 （nfs、iscsi）*/
#define MINOR_LOCAL_RESET_PASSWD        0x6d    /* 本地恢复管理员默认密码*/ 

#define MINOR_REMOTE_LOGIN				0x70	/* 远程登录 */
#define MINOR_REMOTE_LOGOUT				0x71	/* 远程注销登陆 */
#define MINOR_REMOTE_START_REC			0x72	/* 远程开始录像 */
#define MINOR_REMOTE_STOP_REC			0x73	/* 远程停止录像 */
#define MINOR_START_TRANS_CHAN			0x74	/* 开始透明传输 */
#define MINOR_STOP_TRANS_CHAN			0x75	/* 停止透明传输 */
#define MINOR_REMOTE_GET_PARM			0x76	/* 远程获取参数 */
#define MINOR_REMOTE_CFG_PARM			0x77	/* 远程配置参数 */
#define MINOR_REMOTE_GET_STATUS         0x78	/* 远程获取状态 */
#define MINOR_REMOTE_ARM				0x79	/* 远程布防 */
#define MINOR_REMOTE_DISARM				0x7a	/* 远程撤防 */
#define MINOR_REMOTE_REBOOT				0x7b	/* 远程重启 */
#define MINOR_START_VT					0x7c	/* 开始语音对讲 */
#define MINOR_STOP_VT					0x7d	/* 停止语音对讲 */
#define MINOR_REMOTE_UPGRADE			0x7e	/* 远程升级 */
#define MINOR_REMOTE_PLAYBYFILE         0x7f	/* 远程按文件回放 */
#define MINOR_REMOTE_PLAYBYTIME         0x80	/* 远程按时间回放 */
#define MINOR_REMOTE_PTZCTRL			0x81	/* 远程云台控制 */
#define MINOR_REMOTE_FORMAT_HDD         0x82    /* 远程格式化硬盘 */
#define MINOR_REMOTE_STOP               0x83    /* 远程关机 */
#define MINOR_REMOTE_LOCKFILE			0x84	/* 远程锁定文件 */
#define MINOR_REMOTE_UNLOCKFILE         0x85	/* 远程解锁文件 */
#define MINOR_REMOTE_CFGFILE_OUTPUT     0x86    /* 远程导出配置文件 */
#define MINOR_REMOTE_CFGFILE_INTPUT     0x87    /* 远程导入配置文件 */
#define MINOR_REMOTE_RECFILE_OUTPUT     0x88    /* 远程导出录象文件 */
#define MINOR_REMOTE_DVR_ALARM          0x89    /* 远程手动清除和触发报警*/
#define MINOR_REMOTE_IPC_ADD			0x8a	/* 远程添加IPC */
#define MINOR_REMOTE_IPC_DEL			0x8b	/* 远程删除IPC */
#define MINOR_REMOTE_IPC_SET			0x8c	/* 远程设置IPC */
#define MINOR_REBOOT_VCA_LIB            0x8d    /*重启智能库*/
#define MINOR_REMOTE_ADD_NAS            0x8e   /* 远程添加nas盘 （nfs、iscsi）*/
#define MINOR_REMOTE_DEL_NAS            0x8f   /* 远程删除nas盘 （nfs、iscsi）*/
#define MINOR_REMOTE_SET_NAS            0x90   /* 远程设置nas盘 （nfs、iscsi）*/
#define MINOR_LOCAL_OPERATE_LOCK        0x9d			/* 本地操作锁定             */
#define MINOR_LOCAL_OPERATE_UNLOCK      0x9e            /* 本地操作解除锁定         */
#define MINOR_REMOTE_DELETE_HDISK       0x9a            /* 远程删除异常不存在的硬盘 */
#define MINOR_REMOTE_LOAD_HDISK         0x9b            /* 远程加载硬盘             */
#define MINOR_REMOTE_UNLOAD_HDISK       0x9c            /* 远程卸载硬盘   */


//2010-05-26 增加审讯DVR日志类型
#define MINOR_LOCAL_START_REC_CDRW      0x91   /* 本地开始讯问 */
#define MINOR_LOCAL_STOP_REC_CDRW       0x92   /* 本地停止讯问 */
#define MINOR_REMOTE_START_REC_CDRW     0x93   /* 远程开始讯问 */
#define MINOR_REMOTE_STOP_REC_CDRW      0x94   /* 远程停止讯问 */

#define MINOR_LOCAL_PIC_OUTPUT			0x95   /* 本地备份图片文件 */ 
#define MINOR_REMOTE_PIC_OUTPUT			0x96   /* 远程备份图片文件 */

//2011-07-26 增加81审讯DVR日志类型
#define MINOR_LOCAL_INQUEST_RESUME      0x97   /* 本地恢复审讯事件*/
#define MINOR_REMOTE_INQUEST_RESUME     0x98   /* 远程恢复审讯事件*/

//2013-01-23 增加86高清审讯NVR操作日志
#define MINOR_LOCAL_ADD_FILE            0x99        /*本地导入文件*/
#define MINOR_LOCAL_DEL_FILE            0x9f        /*本地删除审讯*/
#define MINOR_REMOTE_INQUEST_ADD_FILE   0x100       /*远程导入文件*/ 
#define MINOR_REMOTE_INQUEST_DEL_FILE   0x101       /*远程删除文件*/

//2009-12-16 增加视频综合平台日志类型
#define MINOR_SUBSYSTEMREBOOT           0xa0	/*视频综合平台：dm6467 正常重启*/
#define MINOR_MATRIX_STARTTRANSFERVIDEO 0xa1	/*视频综合平台：矩阵切换开始传输图像*/
#define MINOR_MATRIX_STOPTRANSFERVIDEO	0xa2	/*视频综合平台：矩阵切换停止传输图像*/
#define MINOR_REMOTE_SET_ALLSUBSYSTEM   0xa3	/*视频综合平台：设置所有6467子系统信息*/
#define MINOR_REMOTE_GET_ALLSUBSYSTEM   0xa4	/*视频综合平台：获取所有6467子系统信息*/
#define MINOR_REMOTE_SET_PLANARRAY      0xa5	/*视频综合平台：设置计划轮巡组*/
#define MINOR_REMOTE_GET_PLANARRAY      0xa6	/*视频综合平台：获取计划轮巡组*/
#define MINOR_MATRIX_STARTTRANSFERAUDIO 0xa7	/*视频综合平台：矩阵切换开始传输音频*/
#define MINOR_MATRIX_STOPRANSFERAUDIO   0xa8	/*视频综合平台：矩阵切换停止传输音频*/
#define MINOR_LOGON_CODESPITTER         0xa9	/*视频综合平台：登陆码分器*/
#define MINOR_LOGOFF_CODESPITTER        0xaa	/*视频综合平台：退出码分器*/

//2010-01-22 增加视频综合平台中解码器操作日志
#define MINOR_START_DYNAMIC_DECODE 		0xb0	/*开始动态解码*/
#define MINOR_STOP_DYNAMIC_DECODE		0xb1	/*停止动态解码*/
#define MINOR_GET_CYC_CFG				0xb2	/*获取解码器通道轮巡配置*/
#define MINOR_SET_CYC_CFG				0xb3	/*设置解码通道轮巡配置*/
#define MINOR_START_CYC_DECODE			0xb4	/*开始轮巡解码*/
#define MINOR_STOP_CYC_DECODE			0xb5	/*停止轮巡解码*/
#define MINOR_GET_DECCHAN_STATUS		0xb6	/*获取解码通道状态*/
#define MINOR_GET_DECCHAN_INFO			0xb7	/*获取解码通道当前信息*/
#define MINOR_START_PASSIVE_DEC			0xb8	/*开始被动解码*/
#define MINOR_STOP_PASSIVE_DEC			0xb9	/*停止被动解码*/
#define MINOR_CTRL_PASSIVE_DEC			0xba	/*控制被动解码*/
#define MINOR_RECON_PASSIVE_DEC			0xbb	/*被动解码重连*/
#define MINOR_GET_DEC_CHAN_SW			0xbc	/*获取解码通道总开关*/
#define MINOR_SET_DEC_CHAN_SW			0xbd	/*设置解码通道总开关*/
#define MINOR_CTRL_DEC_CHAN_SCALE		0xbe	/*解码通道缩放控制*/
#define MINOR_SET_REMOTE_REPLAY			0xbf	/*设置远程回放*/
#define MINOR_GET_REMOTE_REPLAY			0xc0	/*获取远程回放状态*/
#define MINOR_CTRL_REMOTE_REPLAY		0xc1	/*远程回放控制*/
#define MINOR_SET_DISP_CFG				0xc2	/*设置显示通道*/
#define MINOR_GET_DISP_CFG				0xc3	/*获取显示通道设置*/
#define MINOR_SET_PLANTABLE				0xc4	/*设置计划轮巡表*/
#define MINOR_GET_PLANTABLE				0xc5	/*获取计划轮巡表*/
#define MINOR_START_PPPPOE				0xc6	/*开始PPPoE连接*/
#define MINOR_STOP_PPPPOE				0xc7	/*结束PPPoE连接*/
#define MINOR_UPLOAD_LOGO				0xc8	/*上传LOGO*/
//推模式操作日志
#define MINOR_LOCAL_PIN					0xc9    /* 本地PIN功能操作 */
#define MINOR_LOCAL_DIAL				0xca    /* 本地手动启动断开拨号 */    
#define MINOR_SMS_CONTROL				0xcb    /* 短信控制上下线 */    
#define MINOR_CALL_ONLINE				0xcc    /* 呼叫控制上线 */    
#define MINOR_REMOTE_PIN				0xcd    /* 远程PIN功能操作 */
//2010-12-16 报警板日志
#define MINOR_REMOTE_BYPASS             0xd0    /* 远程旁路*/
#define MINOR_REMOTE_UNBYPASS           0xd1    /* 远程旁路恢复*/
#define MINOR_REMOTE_SET_ALARMIN_CFG    0xd2    /* 远程设置报警输入参数*/
#define MINOR_REMOTE_GET_ALARMIN_CFG    0xd3    /* 远程获取报警输入参数*/
#define MINOR_REMOTE_SET_ALARMOUT_CFG   0xd4    /* 远程设置报警输出参数*/
#define MINOR_REMOTE_GET_ALARMOUT_CFG   0xd5    /* 远程获取报警输出参数*/
#define MINOR_REMOTE_ALARMOUT_OPEN_MAN  0xd6    /* 远程手动开启报警输出*/
#define MINOR_REMOTE_ALARMOUT_CLOSE_MAN 0xd7    /* 远程手动关闭报警输出*/
#define MINOR_REMOTE_ALARM_ENABLE_CFG   0xd8    /* 远程设置报警主机的RS485串口使能状态*/
#define MINOR_DBDATA_OUTPUT				0xd9	/* 导出数据库记录 */
#define MINOR_DBDATA_INPUT				0xda	/* 导入数据库记录 */
#define MINOR_MU_SWITCH					0xdb	/* 级联切换 */
#define MINOR_MU_PTZ					0xdc	/* 级联PTZ控制 */

#define MINOR_LOCAL_CONF_REB_RAID       0x101           /*本地配置自动重建*/
#define MINOR_LOCAL_CONF_SPARE          0x102           /*本地配置热备*/
#define MINOR_LOCAL_ADD_RAID            0x103           /*本地创建阵列*/
#define MINOR_LOCAL_DEL_RAID            0x104           /*本地删除阵列*/
#define MINOR_LOCAL_MIG_RAID            0x105           /*本地迁移阵列*/
#define MINOR_LOCAL_REB_RAID            0x106           /* 本地手动重建阵列*/
#define MINOR_LOCAL_QUICK_CONF_RAID     0x107           /*本地一键配置*/
#define MINOR_LOCAL_ADD_VD              0x108           /*本地创建虚拟磁盘*/
#define MINOR_LOCAL_DEL_VD              0x109           /*本地删除虚拟磁盘*/
#define MINOR_LOCAL_RP_VD               0x10a           /*本地修复虚拟磁盘*/
#define MINOR_LOCAL_FORMAT_EXPANDVD     0X10b           /*本地扩展虚拟磁盘扩容*/
#define MINOR_LOCAL_RAID_UPGRADE        0X10c           /*本地raid卡升级*/  
#define MINOR_LOCAL_STOP_RAID           0x10d           /*本地暂停RAID操作(即安全拔盘)*/  
#define MINOR_REMOTE_CONF_REB_RAID      0x111           /*远程配置自动重建*/
#define MINOR_REMOTE_CONF_SPARE         0x112            /*远程配置热备*/
#define MINOR_REMOTE_ADD_RAID           0x113           /*远程创建阵列*/
#define MINOR_REMOTE_DEL_RAID           0x114           /*远程删除阵列*/
#define MINOR_REMOTE_MIG_RAID           0x115           /*远程迁移阵列*/
#define MINOR_REMOTE_REB_RAID           0x116           /* 远程手动重建阵列*/
#define MINOR_REMOTE_QUICK_CONF_RAID    0x117           /*远程一键配置*/
#define MINOR_REMOTE_ADD_VD             0x118           /*远程创建虚拟磁盘*/
#define MINOR_REMOTE_DEL_VD             0x119           /*远程删除虚拟磁盘*/
#define MINOR_REMOTE_RP_VD              0x11a           /*远程修复虚拟磁盘*/
#define MINOR_REMOTE_FORMAT_EXPANDVD    0X11b           /*远程虚拟磁盘扩容*/
#define MINOR_REMOTE_RAID_UPGRADE       0X11c           /*远程raid卡升级*/  
#define MINOR_REMOTE_STOP_RAID          0x11d           /*远程暂停RAID操作(即安全拔盘)*/
#define MINOR_LOCAL_START_PIC_REC       0x121          /*本地开始抓图*/ 
#define MINOR_LOCAL_STOP_PIC_REC        0x122          /*本地停止抓图*/
#define MINOR_LOCAL_SET_SNMP            0x125           /*本地配置SNMP*/
#define MINOR_LOCAL_TAG_OPT             0x126          /*本地标签操作*/
#define MINOR_REMOTE_START_PIC_REC      0x131          /*远程开始抓图*/
#define MINOR_REMOTE_STOP_PIC_REC       0x132           /*远程停止抓图*/
#define MINOR_REMOTE_SET_SNMP           0x135            /*远程配置SNMP*/
#define MINOR_REMOTE_TAG_OPT            0x136             /*远程标签操作*/  

// 9000 v2.2.0
#define MINOR_LOCAL_VOUT_SWITCH         0x140   /* 本地输出口切换操作*/
#define MINOR_STREAM_CABAC         		0x141   /* 码流压缩性能选项配置操作*/

//Netra 3.0.0
#define MINOR_LOCAL_SPARE_OPT       	0x142   /*本地N+1 热备相关操作*/
#define MINOR_REMOTE_SPARE_OPT    		0x143   /*远程N+1 热备相关操作*/
#define MINOR_LOCAL_IPCCFGFILE_OUTPUT	0x144  	/* 本地导出ipc配置文件*/
#define MINOR_LOCAL_IPCCFGFILE_INPUT  	0x145   /* 本地导入ipc配置文件 */
#define MINOR_LOCAL_IPC_UPGRADE         0x146   /* 本地升级IPC */
#define MINOR_REMOTE_IPCCFGFILE_OUTPUT  0x147   /* 远程导出ipc配置文件*/
#define MINOR_REMOTE_IPCCFGFILE_INPUT   0x148   /* 远程导入ipc配置文件*/
#define MINOR_REMOTE_IPC_UPGRADE        0x149   /* 远程升级IPC */



#define MINOR_SET_MULTI_MASTER          0x201    /*设置大屏主屏*/
#define MINOR_SET_MULTI_SLAVE           0x202    /*设置大屏子屏*/
#define MINOR_CANCEL_MULTI_MASTER       0x203    /*取消大屏主屏*/
#define MINOR_CANCEL_MULTI_SLAVE        0x204    /*取消大屏子屏*/

#define MINOR_DISPLAY_LOGO				0x205    /*显示LOGO*/
#define MINOR_HIDE_LOGO                 0x206    /*隐藏LOGO*/
#define MINOR_SET_DEC_DELAY_LEVEL       0x207    /*解码通道延时级别设置*/
#define MINOR_SET_BIGSCREEN_DIPLAY_AREA 0x208    /*设置大屏显示区域*/
#define MINOR_CUT_VIDEO_SOURCE          0x209    /*大屏视频源切割设置*/
#define MINOR_SET_BASEMAP_AREA          0x210    /*大屏底图区域设置*/
#define MINOR_DOWNLOAD_BASEMAP          0x211    /*下载大屏底图*/
#define MINOR_CUT_BASEMAP               0x212    /*底图切割配置*/
#define MINOR_CONTROL_ELEC_ENLARGE      0x213    /*电子放大操作(放大或还原)*/
#define MINOR_SET_OUTPUT_RESOLUTION     0x214    /*显示输出分辨率设置*/
#define MINOR_SET_TRANCSPARENCY         0X215    /*图层透明度设置*/
#define MINOR_SET_OSD                   0x216    /*显示OSD设置*/
#define MINOR_RESTORE_DEC_STATUS        0x217    /*恢复初始状态(场景切换时，解码恢复初始状态)*/

//2011-11-11 增加大屏控制器操作日志次类型
#define MINOR_SCREEN_SET_INPUT			0x251    /*修改输入源*/
#define MINOR_SCREEN_SET_OUTPUT			0x252    /*修改输出通道*/
#define MINOR_SCREEN_SET_OSD			0x253    /*修改虚拟LED*/
#define MINOR_SCREEN_SET_LOGO			0x254    /*修改LOGO*/
#define MINOR_SCREEN_SET_LAYOUT			0x255    /*设置布局*/
#define	MINOR_SCREEN_PICTUREPREVIEW		0x256	 /*回显操作*/

//2012-06-14 CVCS2.0, 窗口设置等操作在V1.0， V1.1中已经有了，当时在设备日志中没有定义 
#define MINOR_SCREEN_GET_OSD			0x257   /*获取虚拟LED*/
#define MINOR_SCREEN_GET_LAYOUT			0x258   /*获取布局*/
#define MINOR_SCREEN_LAYOUT_CTRL		0x259   /*布局控制*/
#define MINOR_GET_ALL_VALID_WND			0x260	/*获取所有有效窗口*/
#define MINOR_GET_SIGNAL_WND			0x261	/*获取单个窗口信息*/
#define MINOR_WINDOW_CTRL				0x262	/*窗口控制*/
#define MINOR_GET_LAYOUT_LIST			0x263	/*获取布局列表*/
#define MINOR_LAYOUT_CTRL				0x264	/*布局控制*/
#define MINOR_SET_LAYOUT				0x265	/*设置布局*/
#define MINOR_GET_SIGNAL_LIST			0x266	/*获取输入信号源列表*/
#define MINOR_GET_PLAN_LIST				0x267	/*获取预案列表*/
#define MINOR_SET_PLAN					0x268	/*修改预案*/
#define MINOR_CTRL_PLAN					0x269	/*控制预案*/
#define MINOR_CTRL_SCREEN				0x270	/*屏幕控制*/
#define MINOR_ADD_NETSIG				0x271	/*添加信号源*/
#define MINOR_SET_NETSIG				0x272	/*修改信号源*/
#define MINOR_SET_DECBDCFG				0x273	/*设置解码板参数*/
#define MINOR_GET_DECBDCFG				0x274	/*获取解码板参数*/
#define MINOR_GET_DEVICE_STATUS			0x275	/*获取设备信息*/
#define MINOR_UPLOAD_PICTURE			0x276	/*底图上传*/
#define MINOR_SET_USERPWD				0x277	/*设置用户密码*/
#define MINOR_ADD_LAYOUT				0x278	/*添加布局*/
#define MINOR_DEL_LAYOUT				0x279	/*删除布局*/
#define MINOR_DEL_NETSIG				0x280	/*删除信号源*/
#define MINOR_ADD_PLAN					0x281	/*添加预案*/
#define MINOR_DEL_PLAN					0x282	/*删除预案*/
#define MINOR_GET_EXTERNAL_MATRIX_CFG	0x283	//获取外接矩阵配置
#define MINOR_SET_EXTERNAL_MATRIX_CFG	0x284	//设置外接矩阵配置
#define	MINOR_GET_USER_CFG				0x285	//获取用户配置
#define	MINOR_SET_USER_CFG				0x286	//设置用户配置
#define	MINOR_GET_DISPLAY_PANEL_LINK_CFG 0x287	//获取显示墙连接配置
#define	MINOR_SET_DISPLAY_PANEL_LINK_CFG 0x288	//设置显示墙连接配置

#define	MINOR_GET_WALLSCENE_PARAM	0x289		//获取电视墙场景
#define	MINOR_SET_WALLSCENE_PARAM	0x28a		//设置电视墙场景
#define	MINOR_GET_CURRENT_WALLSCENE		0x28b		//获取当前使用场景
#define	MINOR_SWITCH_WALLSCENE			0x28c		//场景切换
#define	MINOR_SIP_LOGIN					0x28d		//SIP注册成功
#define MINOR_VOIP_START				0x28e		//VOIP对讲开始
#define MINOR_VOIP_STOP					0x28f		//VOIP对讲停止

// Netra 2.2.2
#define MINOR_LOCAL_LOAD_HDISK          0x300            //本地加载硬盘             
#define MINOR_LOCAL_DELETE_HDISK        0x301            //本地删除异常不存在的硬盘

//KY2013 3.0.0
#define MINOR_LOCAL_MAIN_AUXILIARY_PORT_SWITCH	0X302 //本地主辅口切换
#define MINOR_LOCAL_HARD_DISK_CHECK				0x303 //本地物理硬盘自检

//Netra3.1.0
#define MINOR_LOCAL_CFG_DEVICE_TYPE		0x310	//本地配置设备类型
#define MINOR_REMOTE_CFG_DEVICE_TYPE	0x311	//远程配置设备类型
#define MINOR_LOCAL_CFG_WORK_HOT_SERVER	0x312	//本地配置工作机热备服务器
#define MINOR_REMOTE_CFG_WORK_HOT_SERVER	0x313	//远程配置工作机热备服务器
#define MINOR_LOCAL_DELETE_WORK			0x314	//本地删除工作机
#define MINOR_REMOTE_DELETE_WORK		0x315	//远程删除工作机
#define	MINOR_LOCAL_ADD_WORK			0x316	//本地添加工作机
#define MINOR_REMOTE_ADD_WORK			0x317	//远程添加工作机

//2012-03-05 ITC操作日志类型
#define MINOR_SET_TRIGGERMODE_CFG          0x1001    /*设置触发模式参数*/
#define MINOR_GET_TRIGGERMODE_CFG          0x1002    /*获取触发模式参数*/
#define MINOR_SET_IOOUT_CFG                0x1003    /*设置IO输出参数*/
#define MINOR_GET_IOOUT_CFG                0x1004    /*获取IO输出参数*/
#define MINOR_GET_TRIGGERMODE_DEFAULT      0x1005    /*获取触发模式推荐参数*/
#define MINOR_GET_ITCSTATUS                0x1006    /*获取状态检测参数*/
#define MINOR_SET_STATUS_DETECT_CFG        0x1007    /*设置状态检测参数*/
#define MINOR_GET_STATUS_DETECT_CFG        0x1008    /*获取状态检测参数*/
#define MINOR_SET_VIDEO_TRIGGERMODE_CFG    0x1009  /*设置视频触发模式参数*/
#define MINOR_GET_VIDEO_TRIGGERMODE_CFG     0x100a   /*获取视频触发模式参数*/

//2013-04-19 ITS操作日志类型
#define MINOR_LOCAL_ADD_CAR_INFO            0x2001  /*本地添加车辆信息*/
#define MINOR_LOCAL_MOD_CAR_INFO            0x2002  /*本地修改车辆信息*/
#define MINOR_LOCAL_DEL_CAR_INFO            0x2003  /*本地删除车辆信息*/
#define MINOR_LOCAL_FIND_CAR_INFO           0x2004  /*本地查找车辆信息*/
#define MINOR_LOCAL_ADD_MONITOR_INFO        0x2005  /*本地添加布控信息*/
#define MINOR_LOCAL_MOD_MONITOR_INFO        0x2006  /*本地修改布控信息*/
#define MINOR_LOCAL_DEL_MONITOR_INFO        0x2007  /*本地删除布控信息*/
#define MINOR_LOCAL_FIND_MONITOR_INFO       0x2008  /*本地查询布控信息*/
#define MINOR_LOCAL_FIND_NORMAL_PASS_INFO   0x2009  /*本地查询正常通行信息*/
#define MINOR_LOCAL_FIND_ABNORMAL_PASS_INFO   0x200a  /*本地查询异常通行信息*/
#define MINOR_LOCAL_FIND_PEDESTRIAN_PASS_INFO   0x200b  /*本地查询正常通行信息*/
#define MINOR_LOCAL_PIC_PREVIEW             0x200c  /*本地图片预览*/
#define MINOR_LOCAL_SET_GATE_PARM_CFG           0x200d  /*设置本地配置出入口参数*/
#define MINOR_LOCAL_GET_GATE_PARM_CFG           0x200e  /*获取本地配置出入口参数*/
#define MINOR_LOCAL_SET_DATAUPLOAD_PARM_CFG     0x200f  /*设置本地配置数据上传参数*/
#define MINOR_LOCAL_GET_DATAUPLOAD_PARM_CFG     0x2010  /*获取本地配置数据上传参数*/

//2013-11-19新增日志类型
#define MINOR_LOCAL_DEVICE_CONTROL                         0x2011   /*本地设备控制(本地开关闸)*/
#define MINOR_LOCAL_ADD_EXTERNAL_DEVICE_INFO               0x2012   /*本地添加外接设备信息 */
#define MINOR_LOCAL_MOD_EXTERNAL_DEVICE_INFO	           0x2013   /*本地修改外接设备信息 */
#define MINOR_LOCAL_DEL_EXTERNAL_DEVICE_INFO               0x2014   /*本地删除外接设备信息 */
#define MINOR_LOCAL_FIND_EXTERNAL_DEVICE_INFO              0x2015   /*本地查询外接设备信息 */
#define MINOR_LOCAL_ADD_CHARGE_RULE                        0x2016   /*本地添加收费规则 */
#define MINOR_LOCAL_MOD_CHARGE_RULE                        0x2017   /*本地修改收费规则 */
#define MINOR_LOCAL_DEL_CHARGE_RULE                        0x2018   /*本地删除收费规则 */
#define MINOR_LOCAL_FIND_CHARGE_RULE                       0x2019   /*本地查询收费规则 */
#define MINOR_LOCAL_COUNT_NORMAL_CURRENTINFO               0x2020   /*本地统计正常通行信息 */
#define MINOR_LOCAL_EXPORT_NORMAL_CURRENTINFO_REPORT       0x2021   /*本地导出正常通行信息统计报表 */
#define MINOR_LOCAL_COUNT_ABNORMAL_CURRENTINFO             0x2022   /*本地统计异常通行信息 */
#define MINOR_LOCAL_EXPORT_ABNORMAL_CURRENTINFO_REPORT     0x2023   /*本地导出异常通行信息统计报表 */
#define MINOR_LOCAL_COUNT_PEDESTRIAN_CURRENTINFO           0x2024   /*本地统计行人通行信息 */
#define MINOR_LOCAL_EXPORT_PEDESTRIAN_CURRENTINFO_REPORT   0x2025   /*本地导出行人通行信息统计报表 */
#define MINOR_LOCAL_FIND_CAR_CHARGEINFO                    0x2026   /*本地查询过车收费信息 */
#define MINOR_LOCAL_COUNT_CAR_CHARGEINFO                   0x2027   /*本地统计过车收费信息 */
#define MINOR_LOCAL_EXPORT_CAR_CHARGEINFO_REPORT           0x2028   /*本地导出过车收费信息统计报表 */
#define MINOR_LOCAL_FIND_SHIFTINFO                         0x2029   /*本地查询交接班信息 */
#define MINOR_LOCAL_FIND_CARDINFO                          0x2030   /*本地查询卡片信息 */
#define MINOR_LOCAL_ADD_RELIEF_RULE                        0x2031   /*本地添加减免规则 */
#define MINOR_LOCAL_MOD_RELIEF_RULE                        0x2032   /*本地修改减免规则 */
#define MINOR_LOCAL_DEL_RELIEF_RULE                        0x2033   /*本地删除减免规则 */
#define MINOR_LOCAL_FIND_RELIEF_RULE                       0x2034   /*本地查询减免规则 */
#define MINOR_LOCAL_GET_ENDETCFG                           0x2035   /*本地获取出入口控制机离线检测配置 */ 
#define MINOR_LOCAL_SET_ENDETCFG                           0x2036   /*本地设置出入口控制机离线检测配置*/
#define MINOR_LOCAL_SET_ENDEV_ISSUEDDATA                   0x2037   /*本地设置出入口控制机下发卡片信息 */
#define MINOR_LOCAL_DEL_ENDEV_ISSUEDDATA                   0x2038   /*本地清空出入口控制机下发卡片信息 */

#define MINOR_REMOTE_DEVICE_CONTROL                        0x2101   /*远程设备控制*/
#define MINOR_REMOTE_SET_GATE_PARM_CFG                     0x2102   /*设置远程配置出入口参数*/
#define MINOR_REMOTE_GET_GATE_PARM_CFG                     0x2103   /*获取远程配置出入口参数*/
#define MINOR_REMOTE_SET_DATAUPLOAD_PARM_CFG               0x2104   /*设置远程配置数据上传参数*/
#define MINOR_REMOTE_GET_DATAUPLOAD_PARM_CFG               0x2105   /*获取远程配置数据上传参数*/
#define MINOR_REMOTE_GET_BASE_INFO                         0x2106   /*远程获取终端基本信息*/
#define MINOR_REMOTE_GET_OVERLAP_CFG                       0x2107   /*远程获取字符叠加参数配置*/              
#define MINOR_REMOTE_SET_OVERLAP_CFG                       0x2108   /*远程设置字符叠加参数配置*/ 
#define MINOR_REMOTE_GET_ROAD_INFO                         0x2109   /*远程获取路口信息*/
#define MINOR_REMOTE_START_TRANSCHAN                       0x210a   /*远程建立同步数据服务器*/
#define MINOR_REMOTE_GET_ECTWORKSTATE                      0x210b   /*远程获取出入口终端工作状态*/
#define MINOR_REMOTE_GET_ECTCHANINFO                       0x210c   /*远程获取出入口终端通道状态*/

//远程控制 2013-11-19
#define MINOR_REMOTE_ADD_EXTERNAL_DEVICE_INFO              0x210d   /*远程添加外接设备信息 */
#define MINOR_REMOTE_MOD_EXTERNAL_DEVICE_INFO              0x210e   /*远程修改外接设备信息 */
#define MINOR_REMOTE_GET_ENDETCFG                          0x210f   /*远程获取出入口控制机离线检测配置 */ 
#define MINOR_REMOTE_SET_ENDETCFG                          0x2110   /*远程设置出入口控制机离线检测配置*/
#define MINOR_REMOTE_ENDEV_ISSUEDDATA                      0x2111   /*远程设置出入口控制机下发卡片信息 */
#define MINOR_REMOTE_DEL_ENDEV_ISSUEDDATA                  0x2112   /*远程清空出入口控制机下发卡片信息 */

//ITS 0x2115~0x2120 停车场车位项目
#define MINOR_REMOTE_ON_CTRL_LAMP           0x2115  /*开启远程控制车位指示灯*/       
#define MINOR_REMOTE_OFF_CTRL_LAMP          0x2116  /*关闭远程控制车位指示灯*/
//Netra3.1.0
#define MINOR_SET_VOICE_LEVEL_PARAM         0x2117  /*设置音量大小 */
#define MINOR_SET_VOICE_INTERCOM_PARAM      0x2118  /*设置音量录音 */
#define MINOR_SET_INTELLIGENT_PARAM         0x2119  /*智能配置*/ 
#define MINOR_LOCAL_SET_RAID_SPEED          0x211a  /*本地设置raid速度*/
#define MINOR_REMOTE_SET_RAID_SPEED         0x211b /*远程设置raid速度*/

/*日志附加信息*/
//主类型
#define MAJOR_INFORMATION               0x4     /*附加信息*/
//次类型
#define MINOR_HDD_INFO                  0xa1 /*硬盘信息*/
#define MINOR_SMART_INFO                0xa2 /*SMART信息*/
#define MINOR_REC_START                 0xa3 /*开始录像*/
#define MINOR_REC_STOP                  0xa4 /*停止录像*/
#define MINOR_REC_OVERDUE				0xa5 /*过期录像删除*/
#define MINOR_LINK_START				0xa6 //连接前端设备
#define MINOR_LINK_STOP					0xa7 //断开前端设备　
#define MINOR_NET_DISK_INFO				0xa8 //网络硬盘信息
#define MINOR_RAID_INFO                 0xa9 //raid相关信息
#define MINOR_RUN_STATUS_INFO           0xaa /*系统运行状态信息*/

//Netra3.0.0
#define MINOR_SPARE_START_BACKUP		0xab   /*热备系统开始备份指定工作机*/
#define MINOR_SPARE_STOP_BACKUP			0xac   /*热备系统停止备份指定工作机*/
#define MINOR_SPARE_CLIENT_INFO         0xad   /*热备客户机信息*/
#define MINOR_ANR_RECORD_START			0xae   /*ANR录像开始*/
#define MINOR_ANR_RECORD_END			0xaf   /*ANR录像结束*/
#define MINOR_ANR_ADD_TIME_QUANTUM		0xb0	/*ANR添加时间段*/
#define MINOR_ANR_DEL_TIME_QUANTUM		0xb1	/*ANR删除时间段*/


#define MINOR_PIC_REC_START             0xb3  /* 开始抓图*/    
#define MINOR_PIC_REC_STOP              0xb4  /* 停止抓图*/
#define MINOR_PIC_REC_OVERDUE           0xb5  /* 过期图片文件删除 */
//Netra3.1.0
#define  MINOR_CLIENT_LOGIN             0xb6   /*登录服务器成功*/
#define  MINOR_CLIENT_RELOGIN			0xb7   /*重新登录服务器*/
#define  MINOR_CLIENT_LOGOUT			0xb8   /*退出服务器成功*/
#define  MINOR_CLIENT_SYNC_START		0xb9   /*录像同步开始*/
#define  MINOR_CLIENT_SYNC_STOP			0xba   /*录像同步终止*/
#define  MINOR_CLIENT_SYNC_SUCC			0xbb   /*录像同步成功*/
#define  MINOR_CLIENT_SYNC_EXCP			0xbc   /*录像同步异常*/
#define  MINOR_GLOBAL_RECORD_ERR_INFO   0xbd   /*全局错误记录信息*/
#define  MINOR_BUFFER_STATE             0xbe   /*缓冲区状态日志记录*/
#define  MINOR_DISK_ERRORINFO_V2        0xbf   /*硬盘错误详细信息V2*/

typedef enum tagALARMHOST_MAJOR_TYPE
{
    MAJOR_ALARMHOST_ALARM = 1,
    MAJOR_ALARMHOST_EXCEPTION,
    MAJOR_ALARMHOST_OPERATION,
    MAJ0R_ALARMHOST_EVENT
}ALARMHOST_MAJOR_TYPE;

typedef enum tagALARMHOST_MINOR_TYPE
{
    // 报警 
    MINOR_SHORT_CIRCUIT =0x01,      // 短路报警
    MINOR_BROKEN_CIRCUIT,           // 断路报警
    MINOR_ALARM_RESET,              // 报警复位
    MINOR_ALARM_NORMAL,				// 报警恢复正常
    MINOR_PASSWORD_ERROR,			// 密码错误（连续3次输入密码错误）
    MINOR_ID_CARD_ILLEGALLY,		// 非法感应卡ID
    MINOR_KEYPAD_REMOVE,			// 键盘防拆
    MINOR_KEYPAD_REMOVE_RESTORE,	// 键盘防拆复位
    MINOR_DEV_REMOVE,				// 设备防拆
    MINOR_DEV_REMOVE_RESTORE,		// 设备防拆复位
    MINOR_BELOW_ALARM_LIMIT1,		// 模拟量低于报警限1
    MINOR_BELOW_ALARM_LIMIT2,		// 模拟量低于报警限2
    MINOR_BELOW_ALARM_LIMIT3,		// 模拟量低于报警限3
    MINOR_BELOW_ALARM_LIMIT4,		// 模拟量低于报警限4
    MINOR_ABOVE_ALARM_LIMIT1,		// 模拟量高于报警限1
    MINOR_ABOVE_ALARM_LIMIT2,		// 模拟量高于报警限2
    MINOR_ABOVE_ALARM_LIMIT3,		// 模拟量高于报警限3
    MINOR_ABOVE_ALARM_LIMIT4,		// 模拟量高于报警限4
	MINOR_URGENCYBTN_ON,			// 紧急按钮按下
	MINOR_URGENCYBTN_OFF,			// 紧急按钮复位
	MINOR_VIRTUAL_DEFENCE_BANDIT,			//软防区匪警
	MINOR_VIRTUAL_DEFENCE_FIRE,				//软防区火警
	MINOR_VIRTUAL_DEFENCE_URGENT,			//软防区紧急
	MINOR_ALARMHOST_MOTDET_START,			//移动侦测报警开始
	MINOR_ALARMHOST_MOTDET_STOP,			//移动侦测报警结束
	MINOR_ALARMHOST_HIDE_ALARM_START,		//遮挡报警开始
	MINOR_ALARMHOST_HIDE_ALARM_STOP,		//遮挡报警结束
	MINOR_ALARMHOST_UPS_ALARM,				//UPS报警
	MINOR_ALARMHOST_ELECTRICITY_METER_ALARM, //电量表报警
	MINOR_ALARMHOST_SWITCH_POWER_ALARM,		//开关电源报警
	MINOR_ALARMHOST_GAS_DETECT_SYS_ALARM,	  //气体检测系统报警
	MINOR_ALARMHOST_TRANSFORMER_TEMPRATURE_ALARM, //变电器温显表报警
	MINOR_ALARMHOST_TEMP_HUMI_ALARM,			//温湿度传感器报警

    // 异常
    MINOR_POWER_ON      = 0x01,	// 上电
    MINOR_POWER_OFF,				// 掉电
    MINOR_WDT_RESET,				// WDT 复位
    MINOR_LOW_BATTERY_VOLTAGE,		// 蓄电池电压低
    MINOR_AC_LOSS,					// 交流电断电
    MINOR_AC_RESTORE,				// 交流电恢复
    MINOR_RTC_EXCEPTION,			// RTC实时时钟异常
    MINOR_NETWORK_CONNECT_FAILURE,	// 网络连接断
    MINOR_NETWORK_CONNECT_RESTORE,	// 网络连接恢复
    MINOR_TEL_LINE_CONNECT_FAILURE,	// 电话线连接断
    MINOR_TEL_LINE_CONNECT_RESTORE,	// 电话线连接恢复
    MINOR_EXPANDER_BUS_LOSS,		// 扩展总线模块掉线
    MINOR_EXPANDER_BUS_RESTORE,		// 扩展总线模块掉线恢复
    MINOR_KEYPAD_BUS_LOSS,			// 键盘总线模块掉线
    MINOR_KEYPAD_BUS_RESTORE,		// 键盘总线模块掉线恢复
    MINOR_SENSOR_FAILURE,			// 模拟量传感器故障
    MINOR_SENSOR_RESTORE,			// 模拟量传感器恢复
    MINOR_RS485_CONNECT_FAILURE,	// RS485通道连接断
    MINOR_RS485_CONNECT_RESTORE,	// RS485通道连接断恢复
    MINOR_BATTERT_VOLTAGE_RESTORE,  // 蓄电池电压恢复正常 
	MINOR_WIRED_NETWORK_ABNORMAL,	//有线网络异常
	MINOR_WIRED_NETWORK_RESTORE,	//有线网络恢复正常
	MINOR_GPRS_ABNORMAL,			//GPRS通信异常
	MINOR_GPRS_RESTORE,				//GPRS恢复正常
	MINOR_3G_ABNORMAL,				//3G通信异常
	MINOR_3G_RESTORE,				//3G恢复正常
	MINOR_SIM_CARD_ABNORMAL,		//SIM卡异常
	MINOR_SIM_CARD_RESTORE,			//SIM卡恢复正常
	MINOR_ALARMHOST_VI_LOST,		// 视频信号丢失
	MINOR_ALARMHOST_ILLEGAL_ACCESS,	// 非法访问
	MINOR_ALARMHOST_HD_FULL,		// 硬盘满
	MINOR_ALARMHOST_HD_ERROR,		// 硬盘错误
	MINOR_ALARMHOST_DCD_LOST,		// MODEM 掉线(保留不使用)
	MINOR_ALARMHOST_IP_CONFLICT,	// IP地址冲突
	MINOR_ALARMHOST_NET_BROKEN,		// 网络断开
	MINOR_ALARMHOST_REC_ERROR,      // 录像出错
	MINOR_ALARMHOST_VI_EXCEPTION,   // 视频输入异常(只针对模拟通道)
	MINOR_ALARMHOST_FORMAT_HDD_ERROR, //远程格式化硬盘失败

    // 操作 
    MINOR_GUARD         = 0x01,		// 普通布防
    MINOR_UNGUARD,					// 普通撤防
    MINOR_BYPASS,					// 旁路
    MINOR_DURESS_ACCESS,			// 挟持
    MINOR_ALARMHOST_LOCAL_REBOOT,	// 本地重启
    MINOR_ALARMHOST_REMOTE_REBOOT,	// 远程重启
    MINOR_ALARMHOST_LOCAL_UPGRADE,	// 本地升级
    MINOR_ALARMHOST_REMOTE_UPGRADE,	// 远程升级
    MINOR_RECOVERY_DEFAULT_PARAM,	// 恢复默认参数
    MINOR_ALARM_OUTPUT,				// 控制报警输出
    MINOR_ACCESS_OPEN,				// 控制门禁开
    MINOR_ACCESS_CLOSE,				// 控制门禁关
    MINOR_SIREN_OPEN,				// 控制警号开
    MINOR_SIREN_CLOSE,				// 控制警号关
    MINOR_MOD_ZONE_CONFIG,			// 修改防区设置
    MINOR_MOD_ALARMOUT_CONIFG,		// 控制报警输出配置
    MINOR_MOD_ANALOG_CONFIG,		// 修改模拟量配置
    MINOR_RS485_CONFIG,				// 修改485通道配置
    MINOR_PHONE_CONFIG,				// 修改拨号配置
    MINOR_ADD_ADMIN,				// 增加管理员
    MINOR_MOD_ADMIN_PARAM,			// 修改管理员参数
    MINOR_DEL_ADMIN,				// 删除管理员
    MINOR_ADD_NETUSER,				// 增加后端操作员
    MINOR_MOD_NETUSER_PARAM,		// 修改后端操作员参数
    MINOR_DEL_NETUSER,				// 删除后端操作员
    MINOR_ADD_OPERATORUSER,			// 增加前端操作员
    MINOR_MOD_OPERATORUSER_PW,		// 修改前端操作员密码
    MINOR_DEL_OPERATORUSER,			// 删除前端操作员
    MINOR_ADD_KEYPADUSER,			// 增加键盘/读卡器用户	
    MINOR_DEL_KEYPADUSER,			// 删除键盘/读卡器用户	
    MINOR_REMOTEUSER_LOGIN,			// 远程用户登陆
    MINOR_REMOTEUSER_LOGOUT,		// 远程用户注销
    MINOR_REMOTE_GUARD,				// 远程布防
    MINOR_REMOTE_UNGUARD,			// 远程撤防
    MINOR_MOD_HOST_CONFIG,          // 修改主机配置
    MINOR_RESTORE_BYPASS,			// 旁路恢复
	MINOR_ALARMOUT_OPEN,			// 报警输出开启
	MINOR_ALARMOUT_CLOSE,			// 报警输出关闭
	MINOR_MOD_SUBSYSTEM_PARAM,		// 修改子系统参数配置
	MINOR_GROUP_BYPASS,				// 组旁路
	MINOR_RESTORE_GROUP_BYPASS,		// 组旁路恢复
	MINOR_MOD_GRPS_PARAM,			// 修改GPRS参数
	MINOR_MOD_NET_REPORT_PARAM,		// 修改网络上报参数配置
	MINOR_MOD_REPORT_MOD,			// 修改上传方式配置
	MINOR_MOD_GATEWAY_PARAM,		// 修改门禁参数配置
	MINOR_ALARMHOST_REMOTE_START_REC,		// 远程开始录像
	MINOR_ALARMHOST_REMOTE_STOP_REC,		// 远程停止录像
	MINOR_ALARMHOST_START_TRANS_CHAN,		// 开始透明传输
	MINOR_ALARMHOST_STOP_TRANS_CHAN,		// 停止透明传输
	MINOR_ALARMHOST_START_VT,				// 开始语音对讲
	MINOR_ALARMHOST_STOP_VTM,				// 停止语音对讲
	MINOR_ALARMHOST_REMOTE_PLAYBYFILE,		// 远程按文件回放
	MINOR_ALARMHOST_REMOTE_PLAYBYTIME,      // 远程按时间回放
	MINOR_ALARMHOST_REMOTE_PTZCTRL,			// 远程云台控制
	MINOR_ALARMHOST_REMOTE_FORMAT_HDD,      // 远程格式化硬盘
	MINOR_ALARMHOST_REMOTE_LOCKFILE,		// 远程锁定文件
	MINOR_ALARMHOST_REMOTE_UNLOCKFILE,      // 远程解锁文件
	MINOR_ALARMHOST_REMOTE_CFGFILE_OUTPUT,  // 远程导出配置文件
	MINOR_ALARMHOST_REMOTE_CFGFILE_INTPUT,  // 远程导入配置文件
	MINOR_ALARMHOST_REMOTE_RECFILE_OUTPUT,  // 远程导出录象文件
	
	MINOR_ALARMHOST_STAY_ARM,						//留守布防
	MINOR_ALARMHOST_QUICK_ARM,						//即时布防
	MINOR_ALARMHOST_AUTOMATIC_ARM,					//自动布防
	MINOR_ALARMHOST_AUTOMATIC_DISARM,				//自动撤防
	MINOR_ALARMHOST_KEYSWITCH_ARM,					//钥匙防区布防
	MINOR_ALARMHOST_KEYSWITCH_DISARM,				//钥匙防区撤防
	MINOR_ALARMHOST_CLEAR_ALARM,					//消警
	MINOR_ALARMHOST_MOD_FAULT_CFG,					//修改系统故障配置
	MINOR_ALARMHOST_MOD_EVENT_TRIGGER_ALARMOUT_CFG,	//修改事件触发报警输出配置
	MINOR_ALARMHOST_SEARCH_EXTERNAL_MODULE,			//搜索外接模块
	MINOR_ALARMHOST_REGISTER_EXTERNAL_MODULE,		//重新注册外接模块
	MINOR_ALARMHOST_CLOSE_KEYBOARD_ALARM,			//关闭键盘报警提示音
	MINOR_ALARMHOST_MOD_3G_PARAM,					//修改3G参数


    // 事件 
    MINOR_SCHOOLTIME_IRGI_B = 0x01,		// B码校时
    MINOR_SCHOOLTIME_SDK,				// SDK校时
    MINOR_SCHOOLTIME_SELFTEST			// 定时自检校时
}ALARMHOST_MINOR_TYPE;


//当日志的主类型为MAJOR_OPERATION=03，次类型为MINOR_LOCAL_CFG_PARM=0x52或者MINOR_REMOTE_GET_PARM=0x76或者MINOR_REMOTE_CFG_PARM=0x77时，dwParaType:参数类型有效，其含义如下：
#define PARA_VIDEOOUT	0x1
#define PARA_IMAGE		0x2
#define PARA_ENCODE		0x4
#define PARA_NETWORK	0x8
#define PARA_ALARM		0x10
#define PARA_EXCEPTION	0x20
#define PARA_DECODER	0x40    /*解码器*/
#define PARA_RS232		0x80
#define PARA_PREVIEW	0x100
#define PARA_SECURITY	0x200
#define PARA_DATETIME	0x400
#define PARA_FRAMETYPE	0x800    /*帧格式*/
#define PARA_VCA_RULE   0x1001  //行为规则 
#define PARA_VCA_CTRL   0x1002  //配置智能控制信息
#define PARA_VCA_PLATE  0x1003 //  车牌识别

#define PARA_CODESPLITTER 0x2000 /*码分器参数*/
//2010-01-22 增加视频综合平台日志信息次类型
#define PARA_RS485		  0x2001			/* RS485配置信息*/
#define PARA_DEVICE		  0x2002			/* 设备配置信息*/
#define PARA_HARDDISK	  0x2003			/* 硬盘配置信息 */
#define PARA_AUTOBOOT	  0x2004			/* 自动重启配置信息*/
#define PARA_HOLIDAY	  0x2005			/* 节假日配置信息*/			
#define PARA_IPC		  0x2006			/* IP通道配置 */	
/*************************参数配置命令 end*******************************/


/*******************查找文件和日志函数返回值*************************/
#define NET_DVR_FILE_SUCCESS		    1000	//获得文件信息
#define NET_DVR_FILE_NOFIND			    1001	//没有文件
#define NET_DVR_ISFINDING			    1002	//正在查找文件
#define	NET_DVR_NOMOREFILE			    1003	//查找文件时没有更多的文件
#define	NET_DVR_FILE_EXCEPTION		    1004	//查找文件时异常

/*********************回调函数类型 begin************************/

//报警回调命令
#define COMM_ALARM                           0x1100	//8000报警信息主动上传

#define COMM_SCENECHANGE_DETECTION_UPLOAD	 0x1130	//场景变更报警上传(布防)2013-7-16

//对应NET_VCA_RULE_ALARM
#define COMM_ALARM_RULE                      0x1102	 //行为分析报警信息
#define COMM_ALARM_PDC                       0x1103  //人数统计报警信息
#define COMM_ALARM_VIDEOPLATFORM             0x1104  //视频综合平台报警
#define COMM_ALARM_ALARMHOST                 0x1105  //网络报警主机报警
#define COMM_ALARM_FACE                      0x1106  //人脸检测识别报警信息
#define COMM_RULE_INFO_UPLOAD                0x1107  // 事件数据信息上传
#define COMM_ALARM_AID                       0x1110  //交通事件报警信息
#define COMM_ALARM_TPS                       0x1111  //交通参数统计报警信息
//智能人脸抓拍结果上传
#define COMM_UPLOAD_FACESNAP_RESULT          0x1112  //人脸识别结果上传
#define COMM_ALARM_TFS                       0x1113  //交通取证报警信息
#define COMM_ALARM_TPS_V41                   0x1114  //交通参数统计报警信息扩展
#define COMM_ALARM_AID_V41                   0x1115  //交通事件报警信息扩展
#define COMM_ALARM_VQD_EX                    0x1116	 //视频质量诊断报警
#define COMM_SENSOR_VALUE_UPLOAD             0x1120  //模拟量数据实时上传
#define COMM_SENSOR_ALARM                    0x1121  //模拟量报警上传
#define COMM_SWITCH_ALARM                    0x1122	 //开关量报警
#define COMM_ALARMHOST_EXCEPTION             0x1123  //报警主机故障报警
#define COMM_ALARMHOST_OPERATEEVENT_ALARM    0x1124  //操作事件报警上传
#define COMM_ALARMHOST_SAFETYCABINSTATE      0x1125	 //防护舱状态
#define COMM_ALARMHOST_ALARMOUTSTATUS        0x1126	 //报警输出口/警号状态
#define COMM_ALARMHOST_CID_ALARM 		 	 0x1127	 //报告报警上传
#define	COMM_ALARMHOST_EXTERNAL_DEVICE_ALARM 0x1128	 //报警主机外接设备报警上传
#define COMM_ALARMHOST_DATA_UPLOAD           0x1129	 //报警数据上传
#define COMM_ALARM_AUDIOEXCEPTION			 0x1150	 //声音报警信息
#define COMM_ALARM_DEFOCUS                   0x1151	 //虚焦报警信息
#define COMM_ALARM_BUTTON_DOWN_EXCEPTION	 0x1152	 //按钮按下报警信息
#define COMM_ALARM_ALARMGPS                  0x1202  //GPS报警信息上传
#define	COMM_TRADEINFO                       0x1500  //ATMDVR主动上传交易信息
#define COMM_UPLOAD_PLATE_RESULT             0x2800	 //上传车牌信息
#define COMM_ITC_STATUS_DETECT_RESULT        0x2810  //实时状态检测结果上传(智能高清IPC)
#define COMM_IPC_AUXALARM_RESULT             0x2820  //PIR报警、无线报警、呼救报警上传
#define COMM_UPLOAD_PICTUREINFO              0x2900	 //上传图片信息
#define COMM_SNAP_MATCH_ALARM                0x2902  //黑名单比对结果上传
#define COMM_ITS_PLATE_RESULT                0x3050  //终端图片上传
#define	COMM_ITS_TRAFFIC_COLLECT             0x3051  //终端统计数据上传
#define COMM_ITS_GATE_VEHICLE                0x3052  //出入口车辆抓拍数据上传
#define COMM_ITS_GATE_FACE                   0x3053  //出入口人脸抓拍数据上传
#define COMM_ITS_GATE_COSTITEM				 0x3054  //出入口过车收费明细 2013-11-19
#define COMM_ITS_GATE_HANDOVER				 0x3055  //出入口交接班数据 2013-11-19
#define COMM_ITS_PARK_VEHICLE                0x3056  //停车场数据上传
#define COMM_ITS_BLACKLIST_ALARM             0x3057  //黑名单报警上传

#define COMM_ALARM_V30				         0x4000	 //9000报警信息主动上传
#define COMM_IPCCFG			                 0x4001	 //9000设备IPC接入配置改变报警信息主动上传
#define COMM_IPCCFG_V31			             0x4002	 //9000设备IPC接入配置改变报警信息主动上传扩展 9000_1.1
#define COMM_IPCCFG_V40                      0x4003  // IVMS 2000 编码服务器 NVR IPC接入配置改变时报警信息上传
#define COMM_ALARM_DEVICE                    0x4004  //设备报警内容，由于通道值大于256而扩展
#define COMM_ALARM_CVR						 0x4005  //CVR 2.0.X外部报警类型
#define COMM_ALARM_HOT_SPARE				 0x4006  //热备异常报警（N+1模式异常报警）
#define COMM_ALARM_V40				         0x4007	//移动侦测，视频丢失，遮挡，IO信号量等报警信息主动上传，报警数据为可变长

#define	COMM_ITS_ROAD_EXCEPTION		         0x4500	 //路口设备异常报警
#define	COMM_ITS_EXTERNAL_CONTROL_ALARM		 0x4520  //外控报警
#define	COMM_SCREEN_ALARM                    0x5000  //多屏控制器报警类型
#define COMM_DVCS_STATE_ALARM			     0x5001  //分布式大屏控制器报警上传
#define COMM_ALARM_VQD						 0x6000  //VQD主动报警上传 
#define COMM_PUSH_UPDATE_RECORD_INFO 		 0x6001  //推模式录像信息上传

#define COMM_DIAGNOSIS_UPLOAD                0x5100  //诊断服务器VQD报警上传

/*************操作异常类型(消息方式, 回调方式(保留))****************/
#define EXCEPTION_EXCHANGE			    0x8000	//用户交互时异常
#define EXCEPTION_AUDIOEXCHANGE		    0x8001	//语音对讲异常
#define EXCEPTION_ALARM				    0x8002	//报警异常
#define EXCEPTION_PREVIEW			    0x8003	//网络预览异常
#define EXCEPTION_SERIAL			    0x8004	//透明通道异常
#define EXCEPTION_RECONNECT			    0x8005	//预览时重连
#define EXCEPTION_ALARMRECONNECT	    0x8006	//报警时重连
#define EXCEPTION_SERIALRECONNECT	    0x8007	//透明通道重连
#define SERIAL_RECONNECTSUCCESS         0x8008	//透明通道重连成功
#define EXCEPTION_PLAYBACK	            0x8010	//回放异常
#define EXCEPTION_DISKFMT	            0x8011	//硬盘格式化
#define EXCEPTION_PASSIVEDECODE         0x8012  //被动解码异常
#define EXCEPTION_EMAILTEST             0x8013  //邮件测试异常    
#define EXCEPTION_BACKUP                0x8014  //备份异常
#define PREVIEW_RECONNECTSUCCESS        0x8015  //预览时重连成功
#define ALARM_RECONNECTSUCCESS          0x8016  //报警时重连成功
#define RESUME_EXCHANGE				    0x8017	//用户交互恢复
#define NETWORK_FLOWTEST_EXCEPTION      0x8018  //网络流量检测异常
#define EXCEPTION_PICPREVIEWRECONNECT	0x8019	//图片预览重连
#define PICPREVIEW_RECONNECTSUCCESS		0x8020	//图片预览重连成功
#define EXCEPTION_PICPREVIEW			0x8021	//图片预览异常
#define	EXCEPTION_MAX_ALARM_INFO		0x8022	//报警信息缓存已达上限
#define	EXCEPTION_LOST_ALARM			0x8023  //报警丢失
#define EXCEPTION_PASSIVETRANSRECONNECT 0x8024  //被动转码重连
#define PASSIVETRANS_RECONNECTSUCCESS   0x8025  //被动转码重连成功
#define EXCEPTION_PASSIVETRANS          0x8026  //被动转码异常
#define SUCCESS_PUSHDEVLOGON            0x8030  //推模式设备注册成功
#define EXCEPTION_RELOGIN			    0x8040	//用户重登陆
#define RELOGIN_SUCCESS		            0x8041	//用户重登陆成功
/********************预览回调函数*********************/
#define NET_DVR_SYSHEAD			1	//系统头数据
#define NET_DVR_STREAMDATA		2	//视频流数据（包括复合流和音视频分开的视频流数据）
#define NET_DVR_AUDIOSTREAMDATA	3	//音频流数据
#define NET_DVR_STD_VIDEODATA	4	//标准视频流数据
#define NET_DVR_STD_AUDIODATA	5	//标准音频流数据
#define NET_DVR_SDP             6   //SDP信息(Rstp传输时有效)
#define NET_DVR_CHANGE_FORWARD  10  //码流改变为正放  
#define NET_DVR_CHANGE_REVERSE  11  //码流改变为倒放
#define NET_DVR_PRIVATE_DATA    112 //私有数据,包括智能信息

//设备型号(DVR类型)
/* 设备类型 */
#define DVR							1				/*对尚未定义的dvr类型返回NETRET_DVR*/
#define ATMDVR						2				/*atm dvr*/
#define DVS							3				/*DVS*/
#define DEC							4				/* 6001D */
#define ENC_DEC						5				/* 6001F */
#define DVR_HC						6				/*8000HC*/
#define DVR_HT						7				/*8000HT*/
#define DVR_HF						8				/*8000HF*/
#define DVR_HS						9				/* 8000HS DVR(no audio) */
#define DVR_HTS						10              /* 8016HTS DVR(no audio) */
#define DVR_HB						11              /* HB DVR(SATA HD) */
#define DVR_HCS						12              /* 8000HCS DVR */
#define DVS_A						13              /* 带ATA硬盘的DVS */
#define DVR_HC_S					14              /* 8000HC-S */
#define DVR_HT_S					15              /* 8000HT-S */
#define DVR_HF_S					16              /* 8000HF-S */
#define DVR_HS_S					17              /* 8000HS-S */
#define ATMDVR_S					18              /* ATM-S */
#define DVR_7000H					19				/*7000H系列*/
#define DEC_MAT						20              /*多路解码器*/
#define DVR_MOBILE					21				/* mobile DVR */                 
#define DVR_HD_S					22              /* 8000HD-S */
#define DVR_HD_SL					23				/* 8000HD-SL */
#define DVR_HC_SL					24				/* 8000HC-SL */
#define DVR_HS_ST					25				/* 8000HS_ST */
#define DVS_HW						26              /* 6000HW */
#define DS630X_D					27              /* 多路解码器 */
#define DS640X_HD					28				/*640X高清解码器*/
#define DS610X_D                    29              /*610X解码器*/
#define IPCAM						30				/*IP 摄像机*/
#define MEGA_IPCAM					31				/*852F&852MF*/
#define IPCAM_X62MF					32				/*862MF可以接入9000设备*/
#define ITCCAM                      35              /*智能高清网络摄像机*/
#define IVS_IPCAM                   36              /*智能分析高清网络摄像机*/
#define ZOOMCAM                     38              /*一体机*/
#define IPDOME                      40              /*IP 标清球机*/
#define IPDOME_MEGA200              41              /*IP 200万高清球机*/
#define IPDOME_MEGA130              42              /*IP 130万高清球机*/
#define IPDOME_AI                   43              /*IP 高清智能快球*/
#define TII_IPCAM                   44              /*红外热成像摄像机*/
#define IPMOD						50				/*IP 模块*/
#define IDS6501_HF_P                60              // 6501 车牌 
#define IDS6101_HF_A                61              //智能ATM
#define IDS6002_HF_B                62          //双机跟踪：DS6002-HF/B
#define IDS6101_HF_B	            63              //行为分析：DS6101-HF/B DS6101-HF/B_SATA
#define IDS52XX		                64          //智能分析仪IVMS
#define IDS90XX						65				// 9000智能
#define IDS8104_AHL_S_HX            66          // 海鑫人脸识别 ATM
#define IDS8104_AHL_S_H             67              // 私有人脸识别 ATM
#define IDS91XX						68				// 9100智能
#define IIP_CAM_B                   69              // 智能行为IP摄像机
#define IIP_CAM_F                   70              //智能人脸IP摄像机
#define DS71XX_H					71				/* DS71XXH_S */
#define DS72XX_H_S					72				/* DS72XXH_S */
#define DS73XX_H_S					73				/* DS73XXH_S */
#define DS72XX_HF_S                 74              //DS72XX_HF_S
#define DS73XX_HFI_S                75              //DS73XX_HFI_S
#define DS76XX_H_S					76				/* DVR,e.g. DS7604_HI_S */
#define DS76XX_N_S					77				/* NVR,e.g. DS7604_NI_S */
#define DS81XX_HS_S					81				/* DS81XX_HS_S */
#define DS81XX_HL_S					82				/* DS81XX_HL_S */
#define DS81XX_HC_S					83				/* DS81XX_HC_S */
#define DS81XX_HD_S					84				/* DS81XX_HD_S */
#define DS81XX_HE_S					85				/* DS81XX_HE_S */
#define DS81XX_HF_S					86				/* DS81XX_HF_S */
#define DS81XX_AH_S					87				/* DS81XX_AH_S */
#define DS81XX_AHF_S				88				/* DS81XX_AHF_S */
#define DS90XX_HF_S		            90              /*DS90XX_HF_S*/
#define DS91XX_HF_S					91              /*DS91XX_HF_S*/
#define DS91XX_HD_S					92              /*91XXHD-S(MD)*/
#define IDS90XX_A					93				// 9000智能 ATM
#define IDS91XX_A					94				// 9100智能 ATM
#define DS95XX_N_S					95              /*DS95XX_N_S NVR 不带任何输出*/
#define DS96XX_N_SH					96              /*DS96XX_N_SH NVR*/
#define DS90XX_HF_SH                97              /*DS90XX_HF_SH */   
#define DS91XX_HF_SH                98              /*DS91XX_HF_SH */
#define DS_B10_XY                   100             /*视频综合平台设备型号(X:编码板片数，Y:解码板片数)*/
#define DS_6504HF_B10               101             /*视频综合平台内部编码器*/
#define DS_6504D_B10                102             /*视频综合平台内部解码器*/
#define DS_1832_B10                 103             /*视频综合平台内部码分器*/
#define DS_6401HFH_B10              104             /*视频综合平台内部光纤板*/
#define DS_65XXHC					105				//65XXHC DVS
#define DS_65XXHC_S					106				//65XXHC-SATA DVS
#define DS_65XXHF					107				//65XXHF DVS
#define DS_65XXHF_S					108				//65XXHF-SATA DVS
#define DS_6500HF_B                 109             //65 rack DVS
#define IVMS_6200_C                 110             // iVMS-6200(/C)  
#define IVMS_6200_B                 111             // iVMS-6200(/B)
#define DS_72XXHV_ST15				112				//72XXHV_ST  海思3515平台 DVR
#define DS_72XXHV_ST20				113				//72XXHV_ST  海思3520平台 DVR
#define IVMS_6200_T			        114             // IVMS-6200(/T)
#define IVMS_6200_BP                115             // IVMS-6200(/BP)
#define DS_81XXHC_ST				116				//DS_81XXHC_ST
#define DS_81XXHS_ST				117				//DS_81XXHS_ST
#define DS_81XXAH_ST				118				//DS_81XXAH_ST
#define DS_81XXAHF_ST				119				//DS_81XXAHF_ST
#define DS_66XXDVS				    120				//66XX DVS

#define DS_1964_B10                 121             /*视频综合平台内部报警器*/
#define DS_B10N04_IN				122             /*视频综合平台内部级联输入*/
#define DS_B10N04_OUT				123             /*视频综合平台内部级联输出*/
#define DS_B10N04_INTEL             124             /*视频综合平台内部智能*/
#define DS_6408HFH_B10E_RM          125             //V6高清
#define DS_B10N64F1_RTM             126             //V6级联不带DSP
#define DS_B10N64F1D_RTM            127             //V6级联带DSP
#define DS_B10_SDS                  128             //视频综合平台子域控制器
#define DS_B10_DS                   129             //视频综合平台域控制器
#define DS_6401HFH_B10V    			130     	    //VGA高清编码器
#define DS_6504D_B10B               131             /*视频综合平台内部标清解码器*/
#define DS_6504D_B10H               132             /*视频综合平台内部高清解码器*/
#define DS_6504D_B10V               133             /*视频综合平台内部VGA解码器*/
#define DS_6408HFH_B10S			    134             //视频综合平台SDI子板 
#define DS_18XX_N      				135             /* 矩阵接入网关*/ 
#define DS_6504HF_B10F_CLASS        136				//光端机SD
#define DS_18XX_PTZ					141				/*网络码分类产品*/
#define DS_19AXX					142				/*通用报警主机类产品*/
#define DS_19BXX					143				/*家用报警主机*/
#define DS_19CXX					144				/*自助银行报警主机*/
#define DS_19DXX					145				/*动环监控报警主机*/	
#define DS_19XX                     146             /*1900系列报警主机*/ 
#define DS_19SXX					147				/*视频报警主机*/
#define DS_1HXX						148				/*CS类产品*/ //防护舱

//2011-11-30
#define	DS_C10H						161				/*多屏控制器*/
#define DS_C10N_BI					162				//BNC处理器
#define DS_C10N_DI					163				//rbg处理器
#define DS_C10N_SI					164				//码流处理器
#define DS_C10N_DO					165				//显示处理器
#define DS_C10N_SERVER				166				//分布式服务器


#define IDS_8104_AHFL_S_H           171             // 8104ATM 
#define IDS_65XX_HF_A               172             // 65 ATM
#define IDS90XX_HF_RH               173             // 9000 智能RH
#define IDS91XX_HF_RH               174             // 9100 智能RH设备
#define IDS_65XX_HF_B               175             // 65 行为分析
#define IDS_65XX_HF_P               176             // 65 车牌识别
#define IVMS_6200_F 		        177             // IVMS-6200(/F)
#define IVMS_6200_A                 178             //iVMS-6200(/A)
#define IVMS_6200_F_S 		        179             // IVMS-6200(/F_S)人脸后检索分析仪

#define DS90XX_HF_RH                181             // 9000 RH    648
#define DS91XX_HF_RH                182             // 9100 RH设备 648
#define DS78XX_S					183             // 78系列设备 6446
#define DS81XXHW_S					185				// 81 Resolution 960 KY2011
#define DS81XXHW_ST					186             // DS81XXHW_ST  KY2011
#define DS91XXHW_ST					187             // DS91XXHW_ST  KY2011
#define DS91XX_ST					188             // DS91XX_ST netra
#define DS81XX_ST					189             // DS81XX_ST netra
#define DS81XXHX_ST					190             // DS81XXHDI_ST,DS81XXHE_ST ky2012
#define DS73XXHX_ST					191             // DS73XXHI_ST ky2012
#define DS81XX_SH                   192             // 审讯81SH,81SHF
#define DS81XX_SN                   193             // 审讯81SNL

#define DS96XXN_ST                  194             //NVR:DS96xxN_ST
#define DS86XXN_ST                  195             //NVR:DS86xxN_ST
#define DS80XXHF_ST                 196             //DVR:DS80xxHF_ST
#define DS90XXHF_ST                 197             //DVR:DS90xxHF_ST
#define DS76XXN_ST                  198             //NVR:DS76xxN_ST

#define DS_9664N_RX                 199         //NVR:DS_9664N_RX
#define ENCODER_SERVER				200			// 编码卡服务器
#define DECODER_SERVER              201         // 解码卡服务器
#define PCNVR_SERVER                202         // PCNVR存储服务器
#define CVR_SERVER                  203         // 邦诺CVR，他给自己定的类型为DVR_S-1
#define DS_91XXHFH_ST				204         // 91系列HD-SDI高清DVR
#define DS_66XXHFH					205         // 66高清编码器
#define	TRAFFIC_TS_SERVER			210	       //终端服务器
#define	TRAFFIC_VAR					211	       //视频分析记录仪
#define IPCALL                      212        //IP可视对讲分机

#define DS_B11_M_CLASS 			    301             /*视频综合平台设备型号*/
#define DS_B12_M_CLASS 		 		302             /*视频综合平台设备型号*/
#define DS_6504HF_B11_CLASS 		303             /*视频综合平台内部编码器*/
#define DS_6504HF_B12_CLASS 		304              /*视频综合平台内部编码器*/
#define  DS_6401HFH_B11V_CLASS 	    305     //VGA高清
#define  DS_6401HFH_B12V_CLASS 	    306     //VGA高清
#define  DS_6408HFH_B11S_CLASS 	    307     //SDI
#define  DS_6408HFH_B12S_CLASS  	308     //SDI
#define  DS_6504D_B11H_CLASS        309   /*视频综合平台内部高清解码器*/
#define  DS_6504D_B11B_CLASS        310    /*视频综合平台内部标清解码器*/
#define  DS_6504D_B12B_CLASS        311       /*视频综合平台内部标清解码器*/
#define  DS_6504D_B11V_CLASS        312      /*视频综合平台内部VGA解码器*/
#define  DS_6504D_B12V_CLASS        313     /*视频综合平台内部VGA解码器*/
//B10新增
#define  DS_6401HFH_B10R_CLASS 	    314     //B10 RGB高清
#define  DS_6401HFH_B10D_CLASS 	    315     //B10 DVI高清
#define  DS_6401HFH_B10H_CLASS 	    316     //B10 HDMI高清
//B11新增
#define  DS_6401HFH_B11R_CLASS 	    317     //B11 RGB高清
#define  DS_6401HFH_B11D_CLASS 	    318     //B11 DVI高清
#define  DS_6401HFH_B11H_CLASS 	    319     //B11 HDMI高清
//B12新增
#define  DS_6401HFH_B12R_CLASS 	    320     //B12 RGB高清
#define  DS_6401HFH_B12D_CLASS 	    321     //B12 DVI高清
#define  DS_6401HFH_B12H_CLASS 	    322     //B12 HDMI高清
#define  DS_65XXD_B10Ex_CLASS		323     //netra高清解码 

//B10 V2.1新增
#define  DS_6516HW_B10_CLASS		324     //netra高线编码
#define  DS_6401HFH_B10F_RX_CLASS   326		//高清光端机接入（支持1/2路光端机接入）
#define  DS_6502HW_B10F_RX_CLASS	327		//960H光端机接入（支持1/4/8路光端机接入）
//2012-5-16新增
#define  DS_6504D_B11Ex_CLASS		328     //netra高清解码
#define  DS_6504D_B12Ex_CLASS		329     //netra高清解码
#define  DS_6512_B11_CLASS			330     //netra高线编码
#define  DS_6512_B12_CLASS			331     //netra高线编码
#define  DS_6504D_B10H_CLASS        332     //视频综合平台内部高清解码器

#define  DS_65XXT_B10_CLASS         333     //视频综合平台转码子系统
#define  DS_65XXD_B10_CLASS         335     //视频综合平台万能解码板
#define  DS_IVMSE_B10X_CLASS        336     //X86服务器子系统

#define  DS_6508HFH_B10ES_CLASS		338     //SDI输入编码子系统
#define  DS_82NCG_CLASS			    340     //联网网关中的子系统
#define  DS_82VAG_CLASS			    341     //联网网关中的子系统 
#define  DS_1802XXF_B10_CLASS       342     //光口交换子系统
#define  iDS_6504_B10EVAC_CLASS     343     //智能子系统
#define  iDS_6504_B10EDEC_CLASS     344     //智能子系统
#define  DS_6402HFH_B10EV_CLASS     345     //netra编码(VGA)
#define  DS_6402HFH_B10ED_CLASS     346     //netra编码(DVI)
#define  DS_6402HFH_B10EH_CLASS     347     //netra编码(HDMI)
#define  DS_6404HFH_B10T_RX_CLASS   348     //光纤接入编码
#define  DS_6504D_AIO_CLASS     	349	    //netra高清解码
#define  DS_IVMST_B10_CLASS			350	    //X86转码子系统
#define  DS_6402_AIO_CLASS          351     //netra编码
#define  DS_iVMSE_AIO_CLASS         352     //x86服务器子系统
#define  DS_AIO_M_CLASS             353     //一体机


#define  DS_6508HF_B10E_CLASS		355		//BNC输入编码子系统
#define  DS_6404HFH_B10ES_CLASS		356		//SDI输入编码子系统
#define  DS_6402HFH_B10ER_CLASS		358		//RGB输入编码子系统
#define  DS_6404HFH_B10T_RM_CLASS	361		//光纤输入编码子系统
#define  DS_6516D_B10EB_CLASS		362		//BNC输出解码子系统
#define  DS_6516D_B10ES_CLASS		363		//SDI输出解码子系统

//DVI/HDMI/VGA畅显解码公用一个类型
#define  DS_6508D_B10FH_CLASS		364
#define  DS_6508D_B10FD_CLASS		364
#define  DS_6508D_B10FV_CLASS		364

#define  DS_6508_B11E_CLASS			365		//BNC输入编码子系统
#define  DS_6402_B11ES_CLASS		366		//SDI输入编码子系统
#define  DS_6402_B11EV_CLASS		367		//VGA输入编码子系统
#define  DS_6402_B11ER_CLASS		368		//RGB输入编码子系统
#define  DS_6402_B11ED_CLASS		369		//DVI输入编码子系统
#define  DS_6402_B11EH_CLASS		370		//HDMI输入编码子系统
#define  DS_6516D_B11EB_CLASS		371		//BNC输出解码子系统
#define  DS_6516D_B11ES_CLASS		372		//SDI输出解码子系统

#define  DS_6508_B12E_CLASS         373     //BNC输入编码子系统
#define	 DS_6402_B12ES_CLASS		375		//SDI输入编码子系统
#define  DS_6402_B12EV_CLASS		376		//VGA输入编码子系统
#define  DS_6402_B12ER_CLASS		377		//RGB输入编码子系统
#define  DS_6402_B12ED_CLASS		378		//DVI输入编码子系统
#define  DS_6402_B12EH_CLASS		379		//HDMI输入编码子系统
#define  DS_6516D_B12EB_CLASS		380		//BNC输出解码子系统

#define  DS_iVMSE_AIO_8100x_CLASS   381     //金融行业一体机X86子系统
#define  DS_iVMSE_AIO_87x_CLASS     382     //智能楼宇一体机X86子系统

//B20新增
#define  DS_B20_MSU_NP              400     //B20主控板
#define  DS_6416HFH_B20S            401     //SDI输入编码
#define  DS_6416HFH_B20_RM          402     //光纤输入高清编码
#define  DS_6564D_B20D              403     //DVI解码
#define  DS_6564D_B20H              404     //HDMI解码
#define  DS_6564D_B20V              405     //VGA解码
#define  DS_6408HFH_B20V            407     //VGA编码板
#define  DS_MMC_B20_CLASS           408     //B20主控
#define  DS_CARD_CHIP_B20_CLASS     409     //B20主控子板
#define  DS_6564D_B20B_DEV_CLASS    410     //BNC解码子系统
#define  DS_6564D_B20S_DEV_CLASS    411     //SDI解码子系统
#define  DS_6532HF_B20B_DEV_CLASS   412     //BNC编码子系统
#define  DS_6408HFH_B20D_DEV_CLASS  413     //DVI编码子系统
#define  DS_6408HFH_B20H_DEV_CLASS  414     //HDMI编码子系统
#define  DS_IVMSE_B20_CLASS			415     //X86服务器子系统
#define  DS_6402HFH_B20Y_DEV_CLASS  416     //YUV编码子系统
#define  DS_6508HW_B20_DEV_CLASS    417     //HW编码子系统

//报警设备
#define DS_19M00_MN					601     //报警主机百兆网络模块 

#define DS64XXHD_T					701		//64-T高清解码器
#define DS_65XXD                    703     //65万能解码器
#define DS63XXD_T					704		//63-T标清解码器
#define SCE_SERVER                  705     //抓屏服务器
#define DS_64XXHD_S                 706     //64XXHD-S高清解码器
#define DS_68XXT					707     //多功能视音频转码器
#define DS_65XXD_T                  708     //65D-T万能解码器

//SDI矩阵
#define DS_C50S                     751     //SDI矩阵

#define DS_D20XX                    750             //LCD屏幕 解码卡  2013-09-25
//一体化云台
#define IP_PTSYS_MEGA200			1001   //IP 200万一体化云台
#define IPCAM_FISHEYE               1002   //鱼眼摄像机

#define IPCAM_365					1010	//支持365的平台的IPC CAM
#define IPCAM_R0					1011	//支持A5S的平台的IPC CAM
#define IPCAM_R1					1012    //支持385的平台的IPC CAM
#define IPCAM_R2					1013    //支持R2的平台的IPC CAM
#define IPCAM_R3					1014    //支持8127的平台的IPC CAM
#define IPCAM_R4					1015    //支持S2的平台的IPC CAM

#define IPDOME_365					1110    //支持365的平台的IPD CAM
#define IPDOME_R0					1111    //支持A5S的平台的IPD CAM
#define IPDOME_R1					1112    //支持385的平台的IPD CAM
#define IPDOME_R2					1113    //支持R2的平台的IPD CAM
#define IPDOME_R3					1114    //支持8127的平台的IPD CAM
#define IPDOME_R4					1115    //支持S2的平台的IPD CAM
#define ITCCAM_R3					1211    //支持8127的平台的ITCCAM

//新增设备类型 2013-11-19
#define TRAFFIC_ECT					1400  //ECT设备类型
#define TRAFFIC_PARKING_SERVER		1401  //停车场服务器

// DVR
#define DS90XXHW_ST					2001	// DS90XXHW_ST混合DVR
#define DS72XXHX_SH                 2002	// DS-72xxHV_SH, DS-72xxHF-SH 
#define DS_92XX_HF_ST				2003	// DS-92XX-HF-ST 
#define DS_91XX_HF_XT				2004	// NETRET_9100DVR_HF_XT
#define DS_90XX_HF_XT               2005	// NETRET_9000DVR_HF_XT 
#define DS_73XXHX_SH				2006	// NETRET_7300DVR_HX_SH  
#define DS_72XXHFH_ST				2007	// NETRET_7200DVR_HFH_ST
//DS_67系列

#define DS_67XXHF_SATA              2008 // DS-67XXHF-SATA
#define DS_67XXHW                   2009 // DS-67XXHW 
#define DS_67XXHW_SATA              2010 // DS-67XXHW-SATA
#define DS_67XXHF                   2011 // DS-67XXHF

//Netra2.3
#define DS_72XXHF_SV                2012  // DS-72xxHF-SV 
#define DS_72XXHW_SV                2013   // DS-72xxHW-SV

#define DS_81XXHX_SH                2014   // NETRET_8100DVR_HX_SH

#define DS_71XXHX_SL				2015	// KY2013平台小型DVR

#define DS_76XXH_ST					2016	// Netra平台DS_76XXH_ST


#define DS_73XXHFH_ST   			2017   //NETRET_7300HFH_ST
#define DS_81XXHFH_ST   			2018   //NETRET_8100HFH_ST

#define DS_72XXHFH_SL				2019	//hi3521 


#define IDS_91XX_HF_ST_A            2100    //iDS-9100HF-ST/A
#define IDS_91XX_HF_ST_B            2101    //iDS-9100HF-ST/B
#define IDS_90XX_HF_ST_A            2102    //iDS-9000HF-ST/A
#define IDS_90XX_HF_ST_B            2103    //iDS-9000HF-ST/B
#define IDS_81XX_HF_ST_A            2104    //iDS-8100HF-ST/A
#define IDS_81XX_HF_ST_B            2105    //iDS-8100HF-ST/B
#define IDS_80XX_HF_ST_A            2106    //iDS-8000HF-ST/A
#define IDS_80XX_HF_ST_B            2107    //iDS-8000HF-ST/B
#define IDS_8104_AHFL_ST            2108    //智能混合ATM机

// NVR
#define DS_77XXN_ST				    2201	// Netra NVR DS-77XXHF-ST
#define DS_95XX_N_ST			    2202	// Netra 95XXN_ST NVR          
#define DS_85XX_N_ST			    2203	// Netra 85XXN_ST NVR
#define DS_96XX_N_XT			    2204	// NETRET_9600NVR_N_XT
#define DS_76XX_N_SE				2205	// NETRET_7600NVR_N_SE

//高清审讯机
#define DS_86XXSN_SX				2206	// NETRET_8608NVR_SX，包括4中类型DS-8608SNL-SP、DS-8608SNL-ST、DS-8608SN-SP、DS-8608SN-ST，L表示带LCD，P表POE

//#define DS_96XX_N_RX				2207  //Netra平台DS-96XX-N-RX
#define DS_71XXN_SL					2208  //8107平台DS-71XXN-SL 民用产品
#define CS_N1_1XX					2209  //8107平台CS_N1_1XX，民用事业部所用

#define DS_71XXN_SN					2210	//NETRET_71XX_N_SN  海思平台经济型民用产品 
#define CS_N1_2XX					2211	//NETRET_N1_2XX		海思平台民用事业部所用
#define DS_76XX_N_SHT				2212	//NETRET_76XX_N_SHT  海思平台后端基线产品
#define DS_96XXX_N_E                2213    //高新性能NVR(256) 

#define	DS_76XXN_EX					2214 /* HISI3535 平台76 78系列NVR，注：包括 4 8 16路的E1一盘位， 8 16 32路 E2两盘位； /N /P设备*/
#define DS_77XXN_E4					2215/* HISI3535 平台77系列NVR，   注：包括8 16 32路， /N /P设备*/
#define DS_86XXN_E8					2216/* HISI3535 平台86系列NVR，   注：包括8 16 32路， /N /P设备*/
//PCNVR
#define PCNVR_IVMS_4200             2301	// PCNVR_IVMS_4200


//智能分析仪
#define IVMS_6200_TP                2401   //IVMS-6200 交通诱导分析仪
#define IVMS_6200_TF                2402   //IVMS-6200 交通取证分析仪
#define IVMS_6200_D                 2403   //iVMS-6200(/D)
//HISI3531平台混合ATM DVR， 其中L表示带液晶屏，P表示带poe
#define DS_81XXAHW_ST				2501
#define DS_81XXAHW_SP				2502
#define DS_81XXAHWL_ST				2503
#define DS_81XXAHWL_SP				2504

/**********************设备类型 end***********************/
/******************************能力集获取*********************************/
//能力获取命令
#define DEVICE_SOFTHARDWARE_ABILITY         0x001  //设备软硬件能力
#define DEVICE_NETWORK_ABILITY              0x002  //设备网络能力
#define DEVICE_ENCODE_ALL_ABILITY           0x003  //设备所有编码能力
#define	DEVICE_ENCODE_CURRENT               0x004  //设备当前编码能力
#define IPC_FRONT_PARAMETER			        0x005	 //ipc前端参数1.0
#define IPC_UPGRADE_DESCRIPTION		        0x006	 //ipc升级信息
#define DEVICE_RAID_ABILITY                 0x007  //RAID能力
#define DEVICE_ENCODE_ALL_ABILITY_V20       0x008	 //设备所有编码能力2.0
#define IPC_FRONT_PARAMETER_V20		        0x009	 //ipc前端参数2.0
#define DEVICE_ALARM_ABILITY                0x00a  //辅助报警能力
#define DEVICE_DYNCHAN_ABILITY		        0x00b  //设备数字通道能力
#define DEVICE_USER_ABILITY                 0x00c  //设备用户管理参数能力
#define DEVICE_NETAPP_ABILITY               0x00d  //设备网络应用参数能力
#define DEVICE_VIDEOPIC_ABILITY             0x00e  //设备图像参数能力
#define DEVICE_JPEG_CAP_ABILITY             0x00f  //设备JPEG抓图能力
#define DEVICE_SERIAL_ABILITY               0x010  //RS232和RS485串口能力
#define DEVICE_ABILITY_INFO			        0x011	 //设备通用能力类型，具体能力根据发送的能力节点来区分
#define STREAM_ABILITY                      0x012  //流能力
#define SYSTEM_MANAGEMENT_ABILITY           0x013  //设备系统管理能力
#define IP_VIEW_DEV_ABILITY					0x014  //IP可视对讲分机能力
#define VCA_DEV_ABILITY 	                0x100  //设备智能分析的总能力
#define VCA_CHAN_ABILITY                    0x110  //行为分析能力
#define MATRIXDECODER_ABILITY               0x200  //多路解码器显示、解码能力
#define VIDEOPLATFORM_ABILITY               0x210 //视频综合平台能力集
#define VIDEOPLATFORM_SBUCODESYSTEM_ABILITY 0x211 //视频综合平台编码子系统能力集
#define WALL_ABILITY                        0x212  //电视墙能力集
#define MATRIX_ABILITY                      0x213  //SDI矩阵能力 
#define DECODECARD_ABILITY                  0x220 //解码卡服务器能力集
#define VIDEOPLATFORM_ABILITY_V40           0x230 //视频综合平台能力集
#define MATRIXMANAGEDEVICE_ABILITY          0x240 //矩阵接入网关能力集
#define MATRIXDECODER_ABILITY_V41           0x260 //解码器能力集
#define DECODER_ABILITY                     0x261 //解码器xml能力集
#define DECODECARD_ABILITY_V41              0x270 //解码卡服务器能力集V41
#define CODECARD_ABILITY                    0x271  //编码卡能力集
#define SNAPCAMERA_ABILITY                  0x300  //抓拍机能力集
#define ITC_TRIGGER_MODE_ABILITY            0x301  //智能IPC设备的触发模式能力
#define COMPRESSIONCFG_ABILITY              0x400  //获取压缩参数能力集合
#define COMPRESSION_LIMIT                   0x401  //获取主子码流压缩参数能力限制
#define PIC_CAPTURE_ABILITY			        0x402  //获图片分辨率能力集合
#define ALARMHOST_ABILITY                   0x500 //网络报警主机能力集 
#define IT_DEVICE_ABILITY                   0x501  //智能交通能力集
#define	SCREENCONTROL_ABILITY		        0x600 	//大屏控制器能力集
#define	SCREENSERVER_ABILITY                0x610 	//大屏服务器能力集
#define FISHEYE_ABILITY                     0x700   //鱼眼能力集
#define LCD_SCREEN_ABILITY					0x800	//LCD屏幕能力 2013-10-12
/*************************************************
参数配置结构、参数(其中_V30为9000新增)
**************************************************/



/////////////////////////////////////////////////////////////////////////
//校时结构参数
typedef struct
{
	DWORD dwYear;		//年
	DWORD dwMonth;		//月
	DWORD dwDay;		//日
	DWORD dwHour;		//时
	DWORD dwMinute;		//分
	DWORD dwSecond;		//秒
}NET_DVR_TIME, *LPNET_DVR_TIME;

typedef struct tagNET_DVR_TIME_V30
{
	WORD wYear;
	BYTE byMonth;
	BYTE byDay;
	BYTE byHour;
	BYTE byMinute;
	BYTE bySecond;
	BYTE byRes;
	WORD wMilliSec;
	BYTE byRes1[2];
}NET_DVR_TIME_V30, *LPNET_DVR_TIME_V30;

typedef struct  tagNET_DVR_CALIBRATE_TIME
{
	DWORD  dwSize;
	NET_DVR_TIME struTime;
	WORD wMilliSec;
	BYTE byRes[14];
}NET_DVR_CALIBRATE_TIME,*LPNET_DVR_CALIBRATE_TIME;

typedef struct tagNET_DVR_TIME_EX
{
	 WORD wYear;
	 BYTE byMonth;
	 BYTE byDay;
	 BYTE byHour;
	 BYTE byMinute;
	 BYTE bySecond;
	 BYTE byRes;
}NET_DVR_TIME_EX,*LPNET_DVR_TIME_EX;

//时间段(子结构)
typedef struct
{
	//开始时间
    BYTE byStartHour;
	BYTE byStartMin;
	//结束时间
	BYTE byStopHour;
	BYTE byStopMin;
}NET_DVR_SCHEDTIME, *LPNET_DVR_SCHEDTIME;

/*设备报警和异常处理方式*/
/*设备报警和异常处理方式*/
#define NOACTION			0x0				/*无响应*/
#define WARNONMONITOR		0x1				/*监视器上警告*/
#define WARNONAUDIOOUT		0x2				/*声音警告*/
#define UPTOCENTER			0x4				/*上传中心*/
#define TRIGGERALARMOUT		0x8				/*触发报警输出*/
#define TRIGGERCATPIC		0x10			/*触发抓图并上传E-mail*/
#define SEND_PIC_FTP        0x200           /*抓图并上传ftp*/

typedef struct tagNET_DVR_STRUCTHEAD
{
    WORD	wLength;		//结构长度
    BYTE	byVersion ;	/*高低4位分别代表高低版本，后续根据版本和长度进行扩展，不同的版本的长度进行限制*/
    BYTE	byRes;
}NET_DVR_STRUCTHEAD, *LPNET_DVR_STRUCTHEAD;

typedef struct tagNET_DVR_HANDLEEXCEPTION_V41
{    
    DWORD   dwHandleType;        //异常处理,异常处理方式的"或"结果   
    /*0x00: 无响应*/
    /*0x01: 监视器上警告*/
    /*0x02: 声音警告*/
    /*0x04: 上传中心*/
    /*0x08: 触发报警输出*/
    /*0x10: 触发JPRG抓图并上传Email*/
    /*0x20: 无线声光报警器联动*/
    /*0x40: 联动电子地图(目前只有PCNVR支持)*/
    /*0x200: 抓图并上传FTP*/ 
    DWORD   dwMaxRelAlarmOutChanNum ; //触发的报警输出通道数（只读）最大支持数
    DWORD   dwRelAlarmOut[MAX_ALARMOUT_V40]; //触发报警通道  
    BYTE    byRes[64];           //保留
}NET_DVR_HANDLEEXCEPTION_V41, *LPNET_DVR_HANDLEEXCEPTION_V41;

typedef struct tagNET_DVR_HANDLEEXCEPTION_V40
{    
    DWORD   dwHandleType;        //异常处理,异常处理方式的"或"结果   
    /*0x00: 无响应*/
    /*0x01: 监视器上警告*/
    /*0x02: 声音警告*/
    /*0x04: 上传中心*/
    /*0x08: 触发报警输出*/
    /*0x10: 触发JPRG抓图并上传Email*/
    /*0x20: 无线声光报警器联动*/
    /*0x40: 联动电子地图(目前只有PCNVR支持)*/
    /*0x200: 抓图并上传FTP*/ 
    DWORD   dwMaxRelAlarmOutChanNum ; //触发的报警输出通道数（只读）最大支持数量
    DWORD   dwRelAlarmOutChanNum; //触发的报警输出通道数 实际支持数
    DWORD   dwRelAlarmOut[MAX_CHANNUM_V30]; //触发报警通道  
    BYTE    byRes[64];           //保留
}NET_DVR_HANDLEEXCEPTION_V40, *LPNET_DVR_HANDLEEXCEPTION_V40;

//报警和异常处理结构(子结构)(多处使用)(9000扩展)
typedef struct
{
	DWORD	dwHandleType;	/*处理方式,处理方式的"或"结果*/
	/*0x00: 无响应*/
	/*0x01: 监视器上警告*/
	/*0x02: 声音警告*/
	/*0x04: 上传中心*/
	/*0x08: 触发报警输出*/
	/*0x10: 触发JPRG抓图并上传Email*/
	/*0x20: 无线声光报警器联动*/
	/*0x40: 联动电子地图(目前只有PCNVR支持)*/
	/*0x200: 抓图并上传FTP*/
	BYTE byRelAlarmOut[MAX_ALARMOUT_V30];  
    //报警触发的输出通道,报警触发的输出,为1表示触发该输出
}NET_DVR_HANDLEEXCEPTION_V30, *LPNET_DVR_HANDLEEXCEPTION_V30;

//报警和异常处理结构(子结构)(多处使用)
typedef struct
{
	DWORD	dwHandleType;			/*处理方式,处理方式的"或"结果*/
	/*0x00: 无响应*/
	/*0x01: 监视器上警告*/
	/*0x02: 声音警告*/
	/*0x04: 上传中心*/
	/*0x08: 触发报警输出*/
	/*0x10: Jpeg抓图并上传EMail*/
	BYTE byRelAlarmOut[MAX_ALARMOUT];  //报警触发的输出通道,报警触发的输出,为1表示触发该输出
}NET_DVR_HANDLEEXCEPTION, *LPNET_DVR_HANDLEEXCEPTION;

//DVR设备参数
typedef struct
{
	DWORD dwSize;
	BYTE sDVRName[NAME_LEN];     //DVR名称
	DWORD dwDVRID;				//DVR ID,用于遥控器 //V1.4(0-99), V1.5(0-255)
	DWORD dwRecycleRecord;		//是否循环录像,0:不是; 1:是
	//以下不可更改
	BYTE sSerialNumber[SERIALNO_LEN];  //序列号
	DWORD dwSoftwareVersion;			//软件版本号,高16位是主版本,低16位是次版本
	DWORD dwSoftwareBuildDate;			//软件生成日期,0xYYYYMMDD
	DWORD dwDSPSoftwareVersion;		    //DSP软件版本,高16位是主版本,低16位是次版本
	DWORD dwDSPSoftwareBuildDate;		// DSP软件生成日期,0xYYYYMMDD
	DWORD dwPanelVersion;				// 前面板版本,高16位是主版本,低16位是次版本
	DWORD dwHardwareVersion;	// 硬件版本,高16位是主版本,低16位是次版本
	BYTE byAlarmInPortNum;		//DVR报警输入个数
	BYTE byAlarmOutPortNum;		//DVR报警输出个数
	BYTE byRS232Num;			//DVR 232串口个数
	BYTE byRS485Num;			//DVR 485串口个数
	BYTE byNetworkPortNum;		//网络口个数
	BYTE byDiskCtrlNum;			//DVR 硬盘控制器个数
	BYTE byDiskNum;				//DVR 硬盘个数
	BYTE byDVRType;				//DVR类型, 1:DVR 2:ATM DVR 3:DVS ......
	BYTE byChanNum;				//DVR 通道个数
	BYTE byStartChan;			//起始通道号,例如DVS-1,DVR - 1
	BYTE byDecordChans;			//DVR 解码路数
	BYTE byVGANum;				//VGA口的个数
	BYTE byUSBNum;				//USB口的个数
    BYTE byAuxoutNum;			//辅口的个数
    BYTE byAudioNum;			//语音口的个数
    BYTE byIPChanNum;			//最大数字通道数
}NET_DVR_DEVICECFG, *LPNET_DVR_DEVICECFG;

/*
IP地址
*/
typedef struct
{		
	char	sIpV4[16];						/* IPv4地址 */
	BYTE	byIPv6[128];						/* 保留 */
}NET_DVR_IPADDR, *LPNET_DVR_IPADDR;

/*
网络数据结构(子结构)(9000扩展)
*/
typedef struct 
{
	NET_DVR_IPADDR	struDVRIP;          					//DVR IP地址
	NET_DVR_IPADDR	struDVRIPMask;  //DVR IP地址掩码
	DWORD	dwNetInterface;   								//网络接口1-10MBase-T 2-10MBase-T全双工 3-100MBase-TX 4-100M全双工 5-10M/100M自适应
	WORD	wDVRPort;										//端口号
	WORD	wMTU;											//增加MTU设置，默认1500。
	BYTE	byMACAddr[MACADDR_LEN];							// 物理地址
	BYTE    byRes[2];              //保留
}NET_DVR_ETHERNET_V30, *LPNET_DVR_ETHERNET_V30;

/*
网络数据结构(子结构)
*/
typedef struct
{
	char sDVRIP[16];          //DVR IP地址
	char sDVRIPMask[16];      //DVR IP地址掩码
	DWORD dwNetInterface;     //网络接口 1-10MBase-T 2-10MBase-T全双工 3-100MBase-TX 4-100M全双工 5-10M/100M自适应
	WORD wDVRPort;		      //端口号
	BYTE byMACAddr[MACADDR_LEN];		//服务器的物理地址
}NET_DVR_ETHERNET;

//pppoe结构
typedef struct 
{
	DWORD	dwPPPOE;										//0-不启用,1-启用
	BYTE	sPPPoEUser[NAME_LEN];							//PPPoE用户名
	char	sPPPoEPassword[PASSWD_LEN];						// PPPoE密码
	NET_DVR_IPADDR	struPPPoEIP;							//PPPoE IP地址
}NET_DVR_PPPOECFG, *LPNET_DVR_PPPOECFG;

//网络配置结构(9000扩展)
typedef struct
{	
	DWORD dwSize;
	NET_DVR_ETHERNET_V30	struEtherNet[MAX_ETHERNET];		//以太网口
	NET_DVR_IPADDR	struRes1[2];					/*保留*/
	NET_DVR_IPADDR	struAlarmHostIpAddr;					/* 报警主机IP地址 */
	BYTE	byRes2[4];								/* 保留 */
	WORD	wAlarmHostIpPort;								/* 报警主机端口号 */
	BYTE    byUseDhcp;                                      /* 是否启用DHCP 0xff-无效 0-不启用 1-启用*/
	BYTE	byIPv6Mode;								//IPv6分配方式，0-路由公告，1-手动设置，2-启用DHCP分配
	NET_DVR_IPADDR	struDnsServer1IpAddr;					/* 域名服务器1的IP地址 */
	NET_DVR_IPADDR	struDnsServer2IpAddr;					/* 域名服务器2的IP地址 */
	BYTE	byIpResolver[MAX_DOMAIN_NAME];					/* IP解析服务器域名或IP地址 */
	WORD	wIpResolverPort;								/* IP解析服务器端口号 */
	WORD	wHttpPortNo;									/* HTTP端口号 */
	NET_DVR_IPADDR	struMulticastIpAddr;					/* 多播组地址 */
	NET_DVR_IPADDR	struGatewayIpAddr;						/* 网关地址 */
	NET_DVR_PPPOECFG struPPPoE;	
    BYTE    byRes[64];
} NET_DVR_NETCFG_V30, *LPNET_DVR_NETCFG_V30;

//多网卡配置网卡结构
typedef struct 
{
	NET_DVR_IPADDR struDVRIP;           //DVR IP地址
	NET_DVR_IPADDR struDVRIPMask;           //DVR IP地址掩码
	DWORD dwNetInterface;    //网络接口1-10MBase-T 2-10MBase-T全双工 3-100MBase-TX 4-100M全双工 5-10M/100M/1000M自适应
	BYTE byCardType;  //网卡类型，0-普通网卡，1-内网网卡，2-外网网卡
	BYTE byRes1[1]; 
	WORD wMTU;             //增加MTU设置，默认1500。
	BYTE byMACAddr[MACADDR_LEN]; //物理地址，只用于显示
	BYTE byRes2[2]; //保留
	BYTE byUseDhcp;                          /* 是否启用DHCP */
	BYTE byRes3[3];
	NET_DVR_IPADDR struGatewayIpAddr;     /* 网关地址 */
	NET_DVR_IPADDR struDnsServer1IpAddr; /* 域名服务器1的IP地址 */
	NET_DVR_IPADDR struDnsServer2IpAddr; /* 域名服务器2的IP地址 */
}NET_DVR_ETHERNET_MULTI, *LPNET_DVR_ETHERNET_MULTI;

//多网卡网络配置结构
typedef struct
{
	DWORD  dwSize;
	BYTE   byDefaultRoute;        //默认路由，0表示struEtherNet[0]，1表示struEtherNet[1]
	BYTE   byNetworkCardNum;      //设备实际可配置的网卡数目
	BYTE   byWorkMode;   //0-普通多网卡模式，1-内外网隔离模式
	BYTE   byRes[1]; //保留
	NET_DVR_ETHERNET_MULTI struEtherNet[MAX_NETWORK_CARD]; //以太网口
	NET_DVR_IPADDR         struManageHost1IpAddr;     /* 主管理主机IP地址 */
	NET_DVR_IPADDR         struManageHost2IpAddr;     /* 辅管理主机IP地址 */
	NET_DVR_IPADDR	       struAlarmHostIpAddr; /* 报警主机IP地址 */
	WORD wManageHost1Port;     /* 主管理主机端口号 */
	WORD wManageHost2Port;     /* 辅管理主机端口号 */
	WORD wAlarmHostIpPort;     /* 报警主机端口号 */
	BYTE  byIpResolver[MAX_DOMAIN_NAME];     /* IP解析服务器域名或IP地址 */
	WORD wIpResolverPort; /* IP解析服务器端口号 */
	WORD wDvrPort; //通讯端口 默认8000 
	WORD wHttpPortNo; /* HTTP端口号 */
	BYTE  byRes2[6];
	NET_DVR_IPADDR   struMulticastIpAddr; /* 多播组地址 */
	NET_DVR_PPPOECFG struPPPoE;
	BYTE        byRes3[24];
}NET_DVR_NETCFG_MULTI, *LPNET_DVR_NETCFG_MULTI;

//网络配置结构
typedef struct
{
	DWORD dwSize;
	NET_DVR_ETHERNET struEtherNet[MAX_ETHERNET];		/* 以太网口 */
	char sManageHostIP[16];		//远程管理主机地址
	WORD wManageHostPort;		//远程管理主机端口号
	char sIPServerIP[16];            //IPServer服务器地址
	char sMultiCastIP[16];     //多播组地址
	char sGatewayIP[16];       	//网关地址
	char sNFSIP[16];			//NFS主机IP地址
	BYTE sNFSDirectory[PATHNAME_LEN];//NFS目录
	DWORD dwPPPOE;				//0-不启用,1-启用
	BYTE sPPPoEUser[NAME_LEN];	//PPPoE用户名
	char sPPPoEPassword[PASSWD_LEN];// PPPoE密码
	char sPPPoEIP[16];			//PPPoE IP地址(只读)
	WORD wHttpPort;				//HTTP端口号
}NET_DVR_NETCFG, *LPNET_DVR_NETCFG;

//sip配置
typedef struct tagNET_DVR_SIP_CFG
{
	DWORD dwSize;
	BYTE byEnableAutoLogin;    //使能自动注册，0-不使能，1-使能
	BYTE byLoginStatus;  //注册状态，0-未注册，1-已注册，此参数只能获取
	BYTE byRes1[2];
	NET_DVR_IPADDR stuServerIP;  //SIP服务器IP
	WORD wServerPort;    //SIP服务器端口
    BYTE byRes2[2];
	BYTE byUserName[NAME_LEN];  //注册用户名
	BYTE byPassWord[PASSWD_LEN]; //注册密码
	BYTE byLocalNo[MAX_NUMBER_LEN];
	BYTE byDispalyName[MAX_NAME_LEN]; //设备显示名称
	WORD wLocalPort;     //本地端口
	BYTE byLoginCycle;   //注册周期，1-99分钟
	BYTE byRes[129];
}NET_DVR_SIP_CFG, *LPNET_DVR_SIP_CFG;

//IP可视对讲分机配置
typedef struct tagNET_DVR_IP_VIEW_DEVCFG
{
	DWORD dwSize;
	BYTE  byDefaultRing; //默认铃音，范围1-6
	BYTE  byRingVolume;  //铃音音量，范围0-9
	BYTE  byInputVolume; //输入音量值，范围0-6
	BYTE  byOutputVolume; //输出音量值，范围0-9	
	WORD  wRtpPort;  //Rtp端口
	BYTE  byRes1[2];
	DWORD dwPreviewDelayTime; //预览延时配置，0-30秒
	BYTE  byRes2[64];
}NET_DVR_IP_VIEW_DEVCFG,*LPNET_DVR_IP_VIEW_DEVCFG;

//Ip可视对讲音频相关参数配置
typedef struct tagNET_DVR_IP_VIEW_AUDIO_CFG
{
	DWORD dwSize;	
	BYTE  byAudioEncPri1; //音频编码优先级1，0-OggVorbis，1-G711_U，2-G711_A， 5-MPEG2,6-G726，7-AAC
	BYTE  byAudioEncPri2; //音频编码优先级2，当sip服务器不支持音频编码1时会使用音频编码2，0-OggVorbis，1-G711_U，2-G711_A， 5-MPEG2,6-G726，7-AAC
	WORD  wAudioPacketLen1; //音频编码1数据包长度
	WORD  wAudioPacketLen2; //音频编码2数据包长度
	BYTE  byRes[30];
}NET_DVR_IP_VIEW_AUDIO_CFG,*LPNET_DVR_IP_VIEW_AUDIO_CFG;

//IP分机呼叫对讲参数配置结构体
typedef struct tagNET_DVR_IP_VIEW_CALL_CFG
{
	DWORD dwSize ;
	BYTE  byEnableAutoResponse; //使能自动应答,0-不使能，1-使能
	BYTE  byAudoResponseTime; //自动应答时间，0-30秒
	BYTE  byRes1[2];
	BYTE  byEnableAlarmNumber1; //启动报警号码1，0-不启动，1-启动
	BYTE  byRes2[3];
	BYTE  byAlarmNumber1[MAX_NUMBER_LEN]; //呼叫号码1
	BYTE  byEnableAlarmNumber2; //启动报警号码2，0-不启动，1-启动
	BYTE  byRes3[3];
	BYTE  byAlarmNumber2[MAX_NUMBER_LEN]; //呼叫号码2，呼叫号码1失败会尝试呼叫号码2
	BYTE  byRes4[72];
}NET_DVR_IP_VIEW_CALL_CFG,*LPNET_DVR_IP_VIEW_CALL_CFG;

//通道图象结构
//移动侦测(子结构)(按组方式扩展)
typedef struct
{    
    DWORD     dwMaxRecordChanNum;   //设备支持的最大关联录像通道数-只读
    DWORD     dwCurRecordChanNum;    //当前实际已配置的关联录像通道数
    DWORD     dwRelRecordChan[MAX_CHANNUM_V30];	 /* 实际触发录像通道，按值表示,采用紧凑型排列，从下标0 - MAX_CHANNUM_V30-1有效，如果中间遇到0xffffffff,则后续无效*/  
    BYTE       byRes[64];          //保留
}NET_DVR_RECORDCHAN, *LPNET_DVR_RECORDCHAN;

//移动侦测(子结构)(9000扩展)
typedef struct 
{
	BYTE byMotionScope[64][96];									/*侦测区域,0-96位,表示64行,共有96*64个小宏块,为1表示是移动侦测区域,0-表示不是*/
	BYTE byMotionSensitive;										/*移动侦测灵敏度, 0 - 5,越高越灵敏,oxff关闭*/
	BYTE byEnableHandleMotion;									/* 是否处理移动侦测 0－否 1－是*/ 
	BYTE byEnableDisplay;	/*启用移动侦测高亮显示，0-否，1-是*/
	char reservedData;	
	NET_DVR_HANDLEEXCEPTION_V30 struMotionHandleType;				/* 处理方式 */
	NET_DVR_SCHEDTIME struAlarmTime[MAX_DAYS][MAX_TIMESEGMENT_V30]; /*布防时间*/
	BYTE byRelRecordChan[MAX_CHANNUM_V30];									/* 报警触发的录象通道*/
}NET_DVR_MOTION_V30, *LPNET_DVR_MOTION_V30;

//移动侦测(子结构)
typedef struct 
{
	BYTE byMotionScope[18][22];	/*侦测区域,共有22*18个小宏块,为1表示改宏块是移动侦测区域,0-表示不是*/
	BYTE byMotionSensitive;		/*移动侦测灵敏度, 0 - 5,越高越灵敏,0xff关闭*/
	BYTE byEnableHandleMotion;	/* 是否处理移动侦测 */
	BYTE byEnableDisplay;	/*启用移动侦测高亮显示，0-否，1-是*/
	char reservedData;
	NET_DVR_HANDLEEXCEPTION strMotionHandleType;	/* 处理方式 */
	NET_DVR_SCHEDTIME struAlarmTime[MAX_DAYS][MAX_TIMESEGMENT];//布防时间
	BYTE byRelRecordChan[MAX_CHANNUM]; //报警触发的录象通道,为1表示触发该通道
}NET_DVR_MOTION, *LPNET_DVR_MOTION;

//遮挡报警(子结构)(9000扩展)  区域大小704*576
typedef struct 
{
	DWORD dwEnableHideAlarm;				/* 是否启动遮挡报警 ,0-否,1-低灵敏度 2-中灵敏度 3-高灵敏度*/
	WORD wHideAlarmAreaTopLeftX;			/* 遮挡区域的x坐标 */
	WORD wHideAlarmAreaTopLeftY;			/* 遮挡区域的y坐标 */
	WORD wHideAlarmAreaWidth;				/* 遮挡区域的宽 */
	WORD wHideAlarmAreaHeight;				/*遮挡区域的高*/
	NET_DVR_HANDLEEXCEPTION_V30 strHideAlarmHandleType;	/* 处理方式 */
	NET_DVR_SCHEDTIME struAlarmTime[MAX_DAYS][MAX_TIMESEGMENT_V30];//布防时间
}NET_DVR_HIDEALARM_V30, *LPNET_DVR_HIDEALARM_V30;
//遮挡报警(子结构)  区域大小704*576
typedef struct 
{
	DWORD dwEnableHideAlarm;				/* 是否启动遮挡报警 ,0-否,1-低灵敏度 2-中灵敏度 3-高灵敏度*/
	WORD wHideAlarmAreaTopLeftX;			/* 遮挡区域的x坐标 */
	WORD wHideAlarmAreaTopLeftY;			/* 遮挡区域的y坐标 */
	WORD wHideAlarmAreaWidth;				/* 遮挡区域的宽 */
	WORD wHideAlarmAreaHeight;				/*遮挡区域的高*/
	NET_DVR_HANDLEEXCEPTION strHideAlarmHandleType;	/* 处理方式 */
	NET_DVR_SCHEDTIME struAlarmTime[MAX_DAYS][MAX_TIMESEGMENT];//布防时间
}NET_DVR_HIDEALARM, *LPNET_DVR_HIDEALARM;

//信号丢失报警(子结构)(9000扩展)
typedef struct 
{
	BYTE byEnableHandleVILost;	/* 是否处理信号丢失报警 */
	NET_DVR_HANDLEEXCEPTION_V30 strVILostHandleType;	/* 处理方式 */
	NET_DVR_SCHEDTIME struAlarmTime[MAX_DAYS][MAX_TIMESEGMENT_V30];//布防时间
}NET_DVR_VILOST_V30, *LPNET_DVR_VILOST_V30;

//信号丢失报警(子结构)
typedef struct 
{
	BYTE byEnableHandleVILost;	/* 是否处理信号丢失报警 */
	NET_DVR_HANDLEEXCEPTION strVILostHandleType;	/* 处理方式 */
	NET_DVR_SCHEDTIME struAlarmTime[MAX_DAYS][MAX_TIMESEGMENT];//布防时间
}NET_DVR_VILOST, *LPNET_DVR_VILOST;

//遮挡区域(子结构)
typedef struct 
{
	WORD wHideAreaTopLeftX;				/* 遮挡区域的x坐标 */
	WORD wHideAreaTopLeftY;				/* 遮挡区域的y坐标 */
	WORD wHideAreaWidth;				/* 遮挡区域的宽 */
	WORD wHideAreaHeight;				/*遮挡区域的高*/
}NET_DVR_SHELTER, *LPNET_DVR_SHELTER;

typedef struct
{
	BYTE byBrightness;  	/*亮度,0-255*/
	BYTE byContrast;    	/*对比度,0-255*/	
	BYTE bySaturation;  	/*饱和度,0-255*/
	BYTE byHue;    			/*色调,0-255*/
}NET_DVR_COLOR, *LPNET_DVR_COLOR;


//通道图象结构(9000扩展)
typedef struct
{
	DWORD dwSize;
	BYTE  sChanName[NAME_LEN];
	DWORD dwVideoFormat;	/* 只读 视频制式 1-NTSC 2-PAL*/
	BYTE  byReservedData[64];/*保留*/
	DWORD dwShowChanName; // 预览的图象上是否显示通道名称,0-不显示,1-显示 区域大小704*576
	WORD wShowNameTopLeftX;				/* 通道名称显示位置的x坐标 */
	WORD wShowNameTopLeftY;				/* 通道名称显示位置的y坐标 */
	//视频信号丢失报警
	NET_DVR_VILOST_V30 struVILost;
	NET_DVR_VILOST_V30 struRes;		/*保留*/
//	BYTE byRes1[328];
	//移动侦测
	NET_DVR_MOTION_V30 struMotion;
	//遮挡报警
	NET_DVR_HIDEALARM_V30 struHideAlarm;
	//遮挡  区域大小704*576
	DWORD dwEnableHide;		/* 是否启动遮挡 ,0-否,1-是*/
	NET_DVR_SHELTER struShelter[MAX_SHELTERNUM];
	//OSD
	DWORD dwShowOsd;// 预览的图象上是否显示OSD,0-不显示,1-显示 区域大小704*576
	WORD wOSDTopLeftX;				/* OSD的x坐标 */
	WORD wOSDTopLeftY;				/* OSD的y坐标 */
	BYTE byOSDType;					/* OSD类型(主要是年月日格式) */
	/* 0: XXXX-XX-XX 年月日 */
	/* 1: XX-XX-XXXX 月日年 */
	/* 2: XXXX年XX月XX日 */
	/* 3: XX月XX日XXXX年 */
	/* 4: XX-XX-XXXX 日月年*/
	/* 5: XX日XX月XXXX年 */
	/*6: xx/xx/xxxx(月/日/年) */
	/*7: xxxx/xx/xx(年/月/日) */
	/*8: xx/xx/xxxx(日/月/年)*/
	BYTE byDispWeek;				/* 是否显示星期 */
	BYTE byOSDAttrib;				/* OSD属性:透明，闪烁 */
	/* 1: 透明,闪烁 */
	/* 2: 透明,不闪烁 */
	/* 3: 闪烁,不透明 */
	/* 4: 不透明,不闪烁 */
    BYTE byHourOSDType;				/* OSD小时制:0-24小时制,1-12小时制 */
	BYTE byFontSize;//字体大小，16*16(中)/8*16(英)，1-32*32(中)/16*32(英)，2-64*64(中)/32*64(英)  3-48*48(中)/24*48(英) 0xff-自适应(adaptive)
	BYTE byRes[63];
}NET_DVR_PICCFG_V30, *LPNET_DVR_PICCFG_V30;

//通道图象结构SDK_V14扩展
typedef struct 
{
	DWORD dwSize;
	BYTE sChanName[NAME_LEN];
	DWORD dwVideoFormat;	/* 只读 视频制式 1-NTSC 2-PAL*/
	BYTE byBrightness;  	/*亮度,0-255*/
	BYTE byContrast;    	/*对比度,0-255*/	
	BYTE bySaturation;  	/*饱和度,0-255 */
	BYTE byHue;    			/*色调,0-255*/
	//显示通道名
	DWORD dwShowChanName; // 预览的图象上是否显示通道名称,0-不显示,1-显示 区域大小704*576
	WORD wShowNameTopLeftX;				/* 通道名称显示位置的x坐标 */
	WORD wShowNameTopLeftY;				/* 通道名称显示位置的y坐标 */
	//信号丢失报警
	NET_DVR_VILOST struVILost;
	//移动侦测
	NET_DVR_MOTION struMotion;
	//遮挡报警
	NET_DVR_HIDEALARM struHideAlarm;
	//遮挡  区域大小704*576
	DWORD dwEnableHide;		/* 是否启动遮挡 ,0-否,1-是*/
	NET_DVR_SHELTER struShelter[MAX_SHELTERNUM];
	//OSD
	DWORD dwShowOsd;// 预览的图象上是否显示OSD,0-不显示,1-显示 区域大小704*576
	WORD wOSDTopLeftX;				/* OSD的x坐标 */
	WORD wOSDTopLeftY;				/* OSD的y坐标 */
	BYTE byOSDType;					/* OSD类型(主要是年月日格式) */
	/* 0: XXXX-XX-XX 年月日 */
	/* 1: XX-XX-XXXX 月日年 */
	/* 2: XXXX年XX月XX日 */
	/* 3: XX月XX日XXXX年 */
	/* 4: XX-XX-XXXX 日月年*/
	/* 5: XX日XX月XXXX年 */
	/*6: xx/xx/xxxx(月/日/年) */
	/*7: xxxx/xx/xx(年/月/日) */
	/*8: xx/xx/xxxx(日/月/年)*/
	BYTE byDispWeek;				/* 是否显示星期 */
	BYTE byOSDAttrib;				/* OSD属性:透明，闪烁 */
	/* 1: 透明,闪烁 */
	/* 2: 透明,不闪烁 */
	/* 3: 闪烁,不透明 */
	/* 4: 不透明,不闪烁 */
	BYTE byHourOsdType;		/* OSD小时制:0-24小时制,1-12小时制 */
}NET_DVR_PICCFG_EX, *LPNET_DVR_PICCFG_EX;

//通道图象结构(SDK_V13及之前版本)
typedef struct 
{
	DWORD dwSize;
	BYTE sChanName[NAME_LEN];
	DWORD dwVideoFormat;	/* 只读 视频制式 1-NTSC 2-PAL*/
	BYTE byBrightness;  	/*亮度,0-255*/
	BYTE byContrast;    	/*对比度,0-255*/	
	BYTE bySaturation;  	/*饱和度,0-255 */
	BYTE byHue;    			/*色调,0-255*/
	//显示通道名
	DWORD dwShowChanName; // 预览的图象上是否显示通道名称,0-不显示,1-显示 区域大小704*576
	WORD wShowNameTopLeftX;				/* 通道名称显示位置的x坐标 */
	WORD wShowNameTopLeftY;				/* 通道名称显示位置的y坐标 */
	//信号丢失报警
	NET_DVR_VILOST struVILost;
	//移动侦测
	NET_DVR_MOTION struMotion;
	//遮挡报警
	NET_DVR_HIDEALARM struHideAlarm;
	//遮挡  区域大小704*576
	DWORD dwEnableHide;		/* 是否启动遮挡 ,0-否,1-是*/
	WORD wHideAreaTopLeftX;				/* 遮挡区域的x坐标 */
	WORD wHideAreaTopLeftY;				/* 遮挡区域的y坐标 */
	WORD wHideAreaWidth;				/* 遮挡区域的宽 */
	WORD wHideAreaHeight;				/*遮挡区域的高*/
	//OSD
	DWORD dwShowOsd;// 预览的图象上是否显示OSD,0-不显示,1-显示 区域大小704*576
	WORD wOSDTopLeftX;				/* OSD的x坐标 */
	WORD wOSDTopLeftY;				/* OSD的y坐标 */
	BYTE byOSDType;					/* OSD类型(主要是年月日格式) */
	/* 0: XXXX-XX-XX 年月日 */
	/* 1: XX-XX-XXXX 月日年 */
	/* 2: XXXX年XX月XX日 */
	/* 3: XX月XX日XXXX年 */
	/* 4: XX-XX-XXXX 日月年*/
	/* 5: XX日XX月XXXX年 */
	/*6: xx/xx/xxxx(月/日/年) */
	/*7: xxxx/xx/xx(年/月/日) */
	/*8: xx/xx/xxxx(日/月/年)*/
	BYTE byDispWeek;				/* 是否显示星期 */
	BYTE byOSDAttrib;				/* OSD属性:透明，闪烁 */
	/* 1: 透明,闪烁 */
	/* 2: 透明,不闪烁 */
	/* 3: 闪烁,不透明 */
	/* 4: 不透明,不闪烁 */
	char reservedData2;
}NET_DVR_PICCFG, *LPNET_DVR_PICCFG;

//码流压缩参数(子结构)(9000扩展)
typedef struct 
{
	BYTE byStreamType;		//码流类型 0-视频流, 1-复合流, 表示事件压缩参数时最高位表示是否启用压缩参数
    /*分辨率0-DCIF                      1-CIF,                     2-QCIF,                 3-4CIF,             
	        4-2CIF                      5（保留）,                 6-QVGA(320*240),        7-QQVGA(160*120),  
			12-384*288                  13-576*576,                   
			16-VGA（640*480）,          17-UXGA（1600*1200）,      18-SVGA(800*600),       19-HD720p(1280*720）,   
			20-XVGA,                    21-HD900p,                 23-1536*1536,              
			24-1920*1920,               27-HD1080i,                   
			28-2560*1920,               29-1600*304,               30-2048*1536,           31-2448*2048,                
			32-2448*1200,               33-2448*800,               34-XGA（1024*768），    35-SXGA（1280*1024）,         
			36-WD1(960*576/960*480),    37-1080i,                  38-WSXGA(1440*900),     39-HD_F(1920*1080/1280*720),  
			40-HD_H(1920*540/1280*360), 41-HD_Q(960*540/630*360),  42-2336*1744,           43-1920*1456,                 
			44-2592*2048,               45-3296*2472,              46-1376*768,            47-1366*768,                 
		    48-1360*768,                49-WSXGA+,                 50-720*720,             51-1280*1280,                 
			52-2048*768,                53-2048*2048,              54-2560*2048,           55-3072*2048,
			56-2304*1296                57-WXGA(1280*800),         58-1600*600
			0xff-Auto(使用当前码流分辨率)
	*/
    BYTE byResolution;  	
	BYTE byBitrateType;		//码率类型 0:变码率, 1:定码率,0xfe:自动，和源一致
	BYTE byPicQuality;		//图象质量 0-最好 1-次好 2-较好 3-一般 4-较差 5-差,自动，和源一致
    /*视频码率:0-保留，1-16K(保留)，2-32K，3-48k，4-64K，5-80K，6-96K，7-128K，8-160k，9-192K，10-224K，
    11-256K，12-320K，13-384K，14-448K，15-512K，16-640K，17-768K，18-896K，19-1024K，20-1280K，21-1536K，22-1792K，23-2048K，
    24-3072K，25-4096K，26-8192K，27-16384K。最高位(31位)置成1表示是自定义码流，0～30位表示码流值，最小值16k,0xfffffffe，自动，和源一致*/
	DWORD dwVideoBitrate; 	 
	DWORD dwVideoFrameRate;	//帧率 0-全部; 1-1/16; 2-1/8; 3-1/4; 4-1/2; 5-1; 6-2; 7-4; 8-6; 9-8; 10-10; 11-12; 12-16; 13-20; V2.0版本中新加14-15; 15-18; 16-22;
	                        //17-25；18-30；19-35；20-40；21-45；22-50；23-55；24-60,0xfffffffe-自动，和源一致
	WORD  wIntervalFrameI;  //I帧间隔,0xfffe 自动，和源一致
	BYTE  byIntervalBPFrame;//0-BBP帧; 1-BP帧; 2-单P帧(2006-08-11 增加单P帧的配置接口，可以改善实时流延时问题)；0xfe-自动，和源一致
 	BYTE  byres1;        //保留
	BYTE  byVideoEncType;   //视频编码类型 0-私有264，1-标准h264，2-标准mpeg4，7-M-JPEG，8-MPEG2，0xfe-自动（和源一致），0xff-无效 
 	BYTE  byAudioEncType;   //音频编码类型 0-OggVorbis;1-G711_U;2-G711_A;5-MP2L2;6-G276;7-AAC;0xff-无效
	BYTE  byVideoEncComplexity; //视频编码复杂度，0-低，1-中，2高,0xfe:自动，和源一致
	BYTE  byEnableSvc; //0 - 不启用SVC功能；1- 启用SVC功能
    BYTE  byFormatType; //封装类型，1-裸流，2-RTP封装，3-PS封装，4-TS封装，5-私有，6-FLV，7-ASF，8-3GP,9-RTP+PS（国标：GB28181），0xff-无效
	BYTE  byAudioBitRate; //音频码率0-默认，1-8Kbps, 2- 16Kbps, 3-32Kbps，4-64Kbps，5-128Kbps，6-192Kbps；(IPC5.1.0默认4-64Kbps)
	BYTE  byres[6];
}NET_DVR_COMPRESSION_INFO_V30, *LPNET_DVR_COMPRESSION_INFO_V30;


//通道压缩参数(9000扩展)
typedef struct 
{
	DWORD dwSize;
	NET_DVR_COMPRESSION_INFO_V30 struNormHighRecordPara;    //录像 对应8000的普通
	NET_DVR_COMPRESSION_INFO_V30 struRes;//保留 char reserveData[28];
    NET_DVR_COMPRESSION_INFO_V30 struEventRecordPara;       //事件触发压缩参数
	NET_DVR_COMPRESSION_INFO_V30 struNetPara;               //网传(子码流)
}NET_DVR_COMPRESSIONCFG_V30, *LPNET_DVR_COMPRESSIONCFG_V30;

//码流压缩参数(子结构)
typedef struct 
{
	BYTE byStreamType;		//码流类型0-视频流,1-复合流,表示压缩参数时最高位表示是否启用压缩参数
	BYTE byResolution;  	//分辨率0-DCIF 1-CIF, 2-QCIF, 3-4CIF, 4-2CIF, 5-2QCIF(352X144)(车载专用)
	BYTE byBitrateType;		//码率类型0:变码率，1:定码率
	BYTE  byPicQuality;		//图象质量 0-最好 1-次好 2-较好 3-一般 4-较差 5-差
	DWORD dwVideoBitrate; 	//视频码率 0-保留 1-16K(保留) 2-32K 3-48k 4-64K 5-80K 6-96K 7-128K 8-160k 9-192K 10-224K 11-256K 12-320K
							// 13-384K 14-448K 15-512K 16-640K 17-768K 18-896K 19-1024K 20-1280K 21-1536K 22-1792K 23-2048K
							//最高位(31位)置成1表示是自定义码流, 0-30位表示码流值(MIN-32K MAX-8192K)。
	DWORD dwVideoFrameRate;	//帧率 0-全部; 1-1/16; 2-1/8; 3-1/4; 4-1/2; 5-1; 6-2; 7-4; 8-6; 9-8; 10-10; 11-12; 12-16; 13-20;
}NET_DVR_COMPRESSION_INFO, *LPNET_DVR_COMPRESSION_INFO;

//通道压缩参数
typedef struct 
{
	DWORD dwSize;
	NET_DVR_COMPRESSION_INFO struRecordPara; //录像/事件触发录像
	NET_DVR_COMPRESSION_INFO struNetPara;	//网传/保留
}NET_DVR_COMPRESSIONCFG, *LPNET_DVR_COMPRESSIONCFG;

//码流压缩参数(子结构)(扩展) 增加I帧间隔
typedef struct 
{
	BYTE byStreamType;		//码流类型0-视频流, 1-复合流
	BYTE byResolution;  	//分辨率0-DCIF 1-CIF, 2-QCIF, 3-4CIF, 4-2CIF, 5-2QCIF(352X144)(车载专用)
	BYTE byBitrateType;		//码率类型0:变码率，1:定码率
	BYTE  byPicQuality;		//图象质量 0-最好 1-次好 2-较好 3-一般 4-较差 5-差
	DWORD dwVideoBitrate; 	//视频码率 0-保留 1-16K(保留) 2-32K 3-48k 4-64K 5-80K 6-96K 7-128K 8-160k 9-192K 10-224K 11-256K 12-320K
	// 13-384K 14-448K 15-512K 16-640K 17-768K 18-896K 19-1024K 20-1280K 21-1536K 22-1792K 23-2048K
	//最高位(31位)置成1表示是自定义码流, 0-30位表示码流值(MIN-32K MAX-8192K)。
	DWORD dwVideoFrameRate;	//帧率 0-全部; 1-1/16; 2-1/8; 3-1/4; 4-1/2; 5-1; 6-2; 7-4; 8-6; 9-8; 10-10; 11-12; 12-16; 13-20, //V2.0增加14-15, 15-18, 16-22;
	WORD  wIntervalFrameI;  //I帧间隔
	//2006-08-11 增加单P帧的配置接口，可以改善实时流延时问题
	BYTE  byIntervalBPFrame;//0-BBP帧; 1-BP帧; 2-单P帧
	BYTE  byRes;
}NET_DVR_COMPRESSION_INFO_EX, *LPNET_DVR_COMPRESSION_INFO_EX;

//通道压缩参数(扩展)
typedef struct 
{
	DWORD dwSize;
	NET_DVR_COMPRESSION_INFO_EX struRecordPara; //录像
	NET_DVR_COMPRESSION_INFO_EX struNetPara;	//网传
}NET_DVR_COMPRESSIONCFG_EX, *LPNET_DVR_COMPRESSIONCFG_EX;


//时间段录像参数配置(子结构)
typedef struct 
{
	NET_DVR_SCHEDTIME struRecordTime;
	BYTE byRecordType;	//0:定时录像，1:移动侦测，2:报警录像，3:动测|报警，4:动测&报警, 5:命令触发, 6: 智能录像,10-PIR报警，11-无线报警，12-呼救报警，13-所有报警,14-智能交通事件，15越界侦测，16区域入侵侦测，17音频异常侦测
	char reservedData[3];
}NET_DVR_RECORDSCHED, *LPNET_DVR_RECORDSCHED;

//全天录像参数配置(子结构)
typedef struct 
{
	WORD wAllDayRecord;				/* 是否全天录像 0-否 1-是*/
	BYTE byRecordType;				/* 录象类型 0:定时录像，1:移动侦测，2:报警录像，3:动测|报警，4:动测&报警 5:命令触发, 6: 智能录像,10-PIR报警，11-无线报警，12-呼救报警，13-移动|报警输入|PIR|无线报警|呼救报警,14-智能交通事件,15-越界侦测,16-区域入侵,17-声音异常,18-场景变更侦测,19-智能侦测（越界侦测|区域入侵|进入区域|离开区域|人脸识别）*/
	char reservedData;
}NET_DVR_RECORDDAY, *LPNET_DVR_RECORDDAY;

//通道录像参数配置(9000扩展)
typedef struct 
{
	DWORD	dwSize;
	DWORD	dwRecord;  						/*是否录像 0-否 1-是*/
	NET_DVR_RECORDDAY	struRecAllDay[MAX_DAYS];
	NET_DVR_RECORDSCHED	struRecordSched[MAX_DAYS][MAX_TIMESEGMENT_V30];
	DWORD	dwRecordTime;					/* 录象延时长度 0-5秒， 1-10秒， 2-30秒， 3-1分钟， 4-2分钟， 5-5分钟， 6-10分钟*/
	DWORD	dwPreRecordTime;				/* 预录时间 0-不预录 1-5秒 2-10秒 3-15秒 4-20秒 5-25秒 6-30秒 7-0xffffffff(尽可能预录) */
	DWORD	dwRecorderDuration;				/* 录像保存的最长时间 */
	BYTE	byRedundancyRec;	/*是否冗余录像,重要数据双备份：0/1*/
	BYTE	byAudioRec;		/*录像时复合流编码时是否记录音频数据：国外有此法规*/
	BYTE	byStreamType;  // 0:主码流 1：子码流
	BYTE	byPassbackRecord;  // 0:不回传录像 1：回传录像
	WORD	wLockDuration;  // 录像锁定时长，单位小时 0表示不锁定，0xffff表示永久锁定，录像段的时长大于锁定的持续时长的录像，将不会锁定
	BYTE	byRecordBackup;  // 0:录像不存档 1：录像存档
	BYTE 	bySVCLevel;	//SVC抽帧类型：0-不抽，1-抽二分之一 2-抽四分之三
	BYTE	byReserve[4]; 
}NET_DVR_RECORD_V30, *LPNET_DVR_RECORD_V30;

//通道录像参数配置
typedef struct 
{
	DWORD dwSize;
	DWORD dwRecord;  /*是否录像 0-否 1-是*/
	NET_DVR_RECORDDAY struRecAllDay[MAX_DAYS];
	NET_DVR_RECORDSCHED struRecordSched[MAX_DAYS][MAX_TIMESEGMENT];
	DWORD dwRecordTime;	/* 录象时间长度 */
	DWORD dwPreRecordTime;	/* 预录时间 0-不预录 1-5秒 2-10秒 3-15秒 4-20秒 5-25秒 6-30秒 7-0xffffffff(尽可能预录) */
}NET_DVR_RECORD, *LPNET_DVR_RECORD;

//云台协议表结构配置
typedef struct
{ 
    DWORD dwType;               /*解码器类型值*/    
    BYTE  byDescribe[DESC_LEN]; /*解码器的描述符，和8000中的一致*/    
}NET_DVR_PTZ_PROTOCOL;

typedef struct
{    
    DWORD   dwSize;    
    NET_DVR_PTZ_PROTOCOL struPtz[PTZ_PROTOCOL_NUM];/*最大200中PTZ协议*/    
    DWORD   dwPtzNum;           /*有效的ptz协议数目，从0开始(即计算时加1)*/
    BYTE    byRes[8];
}NET_DVR_PTZCFG, *LPNET_DVR_PTZCFG;

/***************************云台类型(end)******************************/

//通道解码器(云台)参数配置(9000扩展)
typedef struct 
{
	DWORD dwSize;
	DWORD dwBaudRate;//波特率(bps)，0－50，1－75，2－110，3－150，4－300，5－600，6－1200，7－2400，8－4800，9－9600，10－19200， 11－38400，12－57600，13－76800，14－115.2k;
	BYTE byDataBit;// 数据有几位 0－5位，1－6位，2－7位，3－8位;
	BYTE byStopBit;// 停止位 0－1位，1－2位;
	BYTE byParity;// 校验 0－无校验，1－奇校验，2－偶校验;
	BYTE byFlowcontrol;// 0－无，1－软流控,2-硬流控
	WORD wDecoderType;//解码器类型, 从0开始，对应ptz协议列表从NET_DVR_IPC_PROTO_LIST得到
	WORD wDecoderAddress;	/*解码器地址:0 - 255*/
	BYTE bySetPreset[MAX_PRESET_V30];		/* 预置点是否设置,0-没有设置,1-设置*/
	BYTE bySetCruise[MAX_CRUISE_V30];		/* 巡航是否设置: 0-没有设置,1-设置 */
	BYTE bySetTrack[MAX_TRACK_V30];		    /* 轨迹是否设置,0-没有设置,1-设置*/
}NET_DVR_DECODERCFG_V30, *LPNET_DVR_DECODERCFG_V30;

//通道解码器(云台)参数配置
typedef struct 
{
	DWORD dwSize;
	DWORD dwBaudRate;       //波特率(bps)，0－50，1－75，2－110，3－150，4－300，5－600，6－1200，7－2400，8－4800，9－9600，10－19200， 11－38400，12－57600，13－76800，14－115.2k;
	BYTE byDataBit;         // 数据有几位 0－5位，1－6位，2－7位，3－8位;
	BYTE byStopBit;         // 停止位 0－1位，1－2位;
	BYTE byParity;          // 校验 0－无校验，1－奇校验，2－偶校验;
	BYTE byFlowcontrol;     // 0－无，1－软流控,2-硬流控
	WORD wDecoderType;      //解码器类型  NET_DVR_IPC_PROTO_LIST中得到
	WORD wDecoderAddress;	/*解码器地址:0 - 255*/
	BYTE bySetPreset[MAX_PRESET];		/* 预置点是否设置,0-没有设置,1-设置*/
	BYTE bySetCruise[MAX_CRUISE];		/* 巡航是否设置: 0-没有设置,1-设置 */
	BYTE bySetTrack[MAX_TRACK];		/* 轨迹是否设置,0-没有设置,1-设置*/
}NET_DVR_DECODERCFG, *LPNET_DVR_DECODERCFG;

//ppp参数配置(子结构)
typedef struct 
{
	NET_DVR_IPADDR struRemoteIP;	//远端IP地址
	NET_DVR_IPADDR struLocalIP;		//本地IP地址
	char sLocalIPMask[16];			//本地IP地址掩码
	BYTE sUsername[NAME_LEN];		/* 用户名 */
	BYTE sPassword[PASSWD_LEN];		/* 密码 */
	BYTE byPPPMode;					//PPP模式, 0－主动，1－被动
	BYTE byRedial;					//是否回拨 ：0-否,1-是
	BYTE byRedialMode;				//回拨模式,0-由拨入者指定,1-预置回拨号码
	BYTE byDataEncrypt;				//数据加密,0-否,1-是
	DWORD dwMTU;					//MTU
	char sTelephoneNumber[PHONENUMBER_LEN];   //电话号码
}NET_DVR_PPPCFG_V30, *LPNET_DVR_PPPCFG_V30;

//ppp参数配置(子结构)
typedef struct 
{
	char sRemoteIP[16];				//远端IP地址
	char sLocalIP[16];				//本地IP地址
	char sLocalIPMask[16];			//本地IP地址掩码
	BYTE sUsername[NAME_LEN];		/* 用户名 */
	BYTE sPassword[PASSWD_LEN];		/* 密码 */
	BYTE byPPPMode;					//PPP模式, 0－主动，1－被动
	BYTE byRedial;					//是否回拨 ：0-否,1-是
	BYTE byRedialMode;				//回拨模式,0-由拨入者指定,1-预置回拨号码
	BYTE byDataEncrypt;				//数据加密,0-否,1-是
	DWORD dwMTU;					//MTU
	char sTelephoneNumber[PHONENUMBER_LEN];   //电话号码
}NET_DVR_PPPCFG, *LPNET_DVR_PPPCFG;

//RS232串口参数配置(9000扩展)
typedef struct
{
    DWORD dwBaudRate;   /*波特率(bps)，0－50，1－75，2－110，3－150，4－300，5－600，6－1200，7－2400，8－4800，9－9600，10－19200， 11－38400，12－57600，13－76800，14－115.2k;*/
    BYTE byDataBit;     /* 数据有几位 0－5位，1－6位，2－7位，3－8位 */
    BYTE byStopBit;     /* 停止位 0－1位，1－2位 */
    BYTE byParity;      /* 校验 0－无校验，1－奇校验，2－偶校验 */
    BYTE byFlowcontrol; /* 0－无，1－软流控,2-硬流控 */
    DWORD dwWorkMode;   /* 工作模式，0－232串口用于PPP拨号，1－232串口用于参数控制，2－透明通道  3- ptz模式,审讯温湿度传感器 4-报警盒模式*/
}NET_DVR_SINGLE_RS232;

//RS232串口参数配置(9000扩展)
typedef struct 
{
	DWORD dwSize;
    NET_DVR_SINGLE_RS232 struRs232[MAX_SERIAL_PORT];/*注意：此结构修改了，原来是单个结构，现在修改为了数组结构*/
	NET_DVR_PPPCFG_V30 struPPPConfig;
}NET_DVR_RS232CFG_V30, *LPNET_DVR_RS232CFG_V30;

//RS232串口参数配置
typedef struct 
{
	DWORD dwSize;
	DWORD dwBaudRate;//波特率(bps)，0－50，1－75，2－110，3－150，4－300，5－600，6－1200，7－2400，8－4800，9－9600，10－19200， 11－38400，12－57600，13－76800，14－115.2k;
	BYTE byDataBit;// 数据有几位 0－5位，1－6位，2－7位，3－8位;
	BYTE byStopBit;// 停止位 0－1位，1－2位;
	BYTE byParity;// 校验 0－无校验，1－奇校验，2－偶校验;
	BYTE byFlowcontrol;// 0－无，1－软流控,2-硬流控
	DWORD dwWorkMode;// 工作模式，0－窄带传输(232串口用于PPP拨号)，1－控制台(232串口用于参数控制)，2－透明通道
	NET_DVR_PPPCFG struPPPConfig;
}NET_DVR_RS232CFG, *LPNET_DVR_RS232CFG;


typedef struct 
{
    DWORD dwEnablePresetChan;	/*启用预置点的通道*/
    DWORD dwPresetPointNo;		/*调用预置点通道对应的预置点序号, 0xfffffff表示不调用预置点。*/
}NET_DVR_PRESETCHAN_INFO, LPNET_DVR_PRESETCHAN_INFO;

typedef struct 
{
    DWORD dwEnableCruiseChan;	/*启用巡航的通道*/
    DWORD dwCruiseNo;		/*巡航通道对应的巡航编号, 0xfffffff表示无效*/
}NET_DVR_CRUISECHAN_INFO, LPNET_DVR_CRUISECHAN_INFO;

typedef struct 
{
    DWORD dwEnablePtzTrackChan;	/*启用云台轨迹的通道*/
    DWORD dwPtzTrackNo;		/*云台轨迹通道对应的编号, 0xfffffff表示无效*/
}NET_DVR_PTZTRACKCHAN_INFO, LPNET_DVR_PTZTRACKCHAN_INFO;


//报警输入参数配置(256路NVR扩展)
typedef struct tagNET_DVR_ALARMINCFG_V40
{
	DWORD dwSize;
	BYTE sAlarmInName[NAME_LEN];	/* 名称 */
	BYTE byAlarmType;	            //报警器类型,0：常开,1：常闭
	BYTE byAlarmInHandle;	        /* 是否处理 0-不处理 1-处理*/
    BYTE byChannel;                 // 报警输入触发智能识别通道
    BYTE byRes1;                    //保留			
    DWORD   dwHandleType;        //异常处理,异常处理方式的"或"结果   
    /*0x00: 无响应*/
    /*0x01: 监视器上警告*/
    /*0x02: 声音警告*/
    /*0x04: 上传中心*/
    /*0x08: 触发报警输出*/
    /*0x10: 触发JPRG抓图并上传Email*/
    /*0x20: 无线声光报警器联动*/
    /*0x40: 联动电子地图(目前只有PCNVR支持)*/
    /*0x200: 抓图并上传FTP*/ 
    DWORD   dwMaxRelAlarmOutChanNum ; //触发的报警输出通道数（只读）最大支持数量
    DWORD   dwRelAlarmOutChanNum; //触发的报警输出通道数 实际支持数
    DWORD   dwRelAlarmOut[MAX_ALARMOUT_V40]; //触发报警通道
	NET_DVR_SCHEDTIME struAlarmTime[MAX_DAYS][MAX_TIMESEGMENT_V30];//布防时间
    /*触发的录像通道*/
    DWORD   dwMaxRecordChanNum;   //设备支持的最大关联录像通道数-只读
    DWORD   dwCurRecordChanNum;    //当前实际已配置的关联录像通道数
    DWORD   dwRelRecordChan[MAX_CHANNUM_V40];	 /* 实际触发录像通道，按值表示,采用紧凑型排列，从下标0 - dwCurRecordChanNum -1有效，如果中间遇到0xffffffff,则后续无效*/ 
    DWORD   dwMaxEnablePtzCtrlNun; //最大可启用的云台控制总数(只读)
    DWORD   dwEnablePresetChanNum;  //当前已启用预置点的数目
    NET_DVR_PRESETCHAN_INFO struPresetChanInfo[MAX_CHANNUM_V40]; //启用的预置点信息
	BYTE    byRes2[516];					/*保留*/
    DWORD   dwEnableCruiseChanNum;  //当前已启用巡航的通道数目
    NET_DVR_CRUISECHAN_INFO struCruiseChanInfo[MAX_CHANNUM_V40]; //启用巡航功能通道的信息
    DWORD   dwEnablePtzTrackChanNum;  //当前已启用巡航的通道数目
    NET_DVR_PTZTRACKCHAN_INFO struPtzTrackInfo[MAX_CHANNUM_V40]; //调用云台轨迹的通道信息
    BYTE    byRes[256];
}NET_DVR_ALARMINCFG_V40, *LPNET_DVR_ALARMINCFG_V40;

//报警输入参数配置(9000扩展)
typedef struct 
{
	DWORD dwSize;
	BYTE sAlarmInName[NAME_LEN];	/* 名称 */
	BYTE byAlarmType;	            //报警器类型,0：常开,1：常闭
	BYTE byAlarmInHandle;	        /* 是否处理 0-不处理 1-处理*/
    BYTE byChannel;                 // 报警输入触发智能识别通道
    BYTE byRes1[1];			
	NET_DVR_HANDLEEXCEPTION_V30 struAlarmHandleType;	/* 处理方式 */
	NET_DVR_SCHEDTIME struAlarmTime[MAX_DAYS][MAX_TIMESEGMENT_V30];//布防时间
	BYTE byRelRecordChan[MAX_CHANNUM_V30]; //报警触发的录象通道,为1表示触发该通道
	BYTE byEnablePreset[MAX_CHANNUM_V30];		/* 是否调用预置点 0-否,1-是*/
	BYTE byPresetNo[MAX_CHANNUM_V30];			/* 调用的云台预置点序号,一个报警输入可以调用多个通道的云台预置点, 0xff表示不调用预置点。*/
	BYTE byRes2[192];					/*保留*/
	BYTE byEnableCruise[MAX_CHANNUM_V30];		/* 是否调用巡航 0-否,1-是*/
	BYTE byCruiseNo[MAX_CHANNUM_V30];			/* 巡航 */
	BYTE byEnablePtzTrack[MAX_CHANNUM_V30];		/* 是否调用轨迹 0-否,1-是*/
	BYTE byPTZTrack[MAX_CHANNUM_V30];			/* 调用的云台的轨迹序号 */
    BYTE byRes3[16];
}NET_DVR_ALARMINCFG_V30, *LPNET_DVR_ALARMINCFG_V30;


typedef struct tagNET_DVR_ALARMINFO_FIXED_HEAD
{
    DWORD dwAlarmType;              /*0-信号量报警,1-硬盘满,2-信号丢失，3－移动侦测，4－硬盘未格式化,5-写硬盘出错,6-遮挡报警，7-制式不匹配, 8-非法访问，9-视频信号异常，10-录像异常，11-智能场景变化，12-阵列异常，13-前端/录像分辨率不匹配*/
    NET_DVR_TIME_EX struAlarmTime;	//发生报警的时间
    union
    {
        BYTE	byUnionLen[128];
        struct
        {
            DWORD	dwAlarmInputNo;		//发生报警的报警输入通道号，一次只有一个
            DWORD	dwTrigerAlarmOutNum;	/*触发的报警输出个数，用于后面计算变长数据部分中所有触发的报警输出通道号，四字节表示一个*/
            DWORD	dwTrigerRecordChanNum;	/*触发的录像通道个数，用于后面计算变长数据部分中所有触发的录像通道号，四字节表示一个*/
        }struIOAlarm;	// 报警类型dwAlarmType为0时有效
        struct
        {
            DWORD	dwAlarmChanNum;	/*发生报警通道数据个数，用于后面计算变长数据部分中所有发生的报警通道号，四字节表示一个*/
        }struAlarmChannel;	// dwAlarmType为2，3，6，9，10或13时有效
        struct
        {
            DWORD	dwAlarmHardDiskNum;	/*发生报警的硬盘数据长度，用于后面计算变长数据部分中所有发生报警的硬盘号，四节表示一个*/
        }struAlarmHardDisk;	// dwAlarmType为1,4,5时有效
    }uStruAlarm;
}NET_DVR_ALRAM_FIXED_HEADER, *LPNET_DVR_ALARM_FIXED_HEADER;

//上传报警信息(256路NVR扩展)
typedef struct NET_DVR_ALARMINFO_V40
{
    NET_DVR_ALRAM_FIXED_HEADER 	struAlarmFixedHeader;	//报警固定部分
    DWORD*		        		pAlarmData;	//报警可变部分内容
}NET_DVR_ALARMINFO_V40, *LPNET_DVR_ALARMINFO_V40;

//报警输入参数配置
typedef struct 
{
	DWORD dwSize;
	BYTE sAlarmInName[NAME_LEN];	/* 名称 */
	BYTE byAlarmType;	//报警器类型,0：常开,1：常闭
	BYTE byAlarmInHandle;	/* 是否处理 0-不处理 1-处理*/
    BYTE byChannel;                 // 报警输入触发智能识别通道
    BYTE byRes;                     
    NET_DVR_HANDLEEXCEPTION struAlarmHandleType;	/* 处理方式 */
	NET_DVR_SCHEDTIME struAlarmTime[MAX_DAYS][MAX_TIMESEGMENT];//布防时间
	BYTE byRelRecordChan[MAX_CHANNUM]; //报警触发的录象通道,为1表示触发该通道
	BYTE byEnablePreset[MAX_CHANNUM];		/* 是否调用预置点 0-否,1-是*/
	BYTE byPresetNo[MAX_CHANNUM];			/* 调用的云台预置点序号,一个报警输入可以调用多个通道的云台预置点, 0xff表示不调用预置点。*/
	BYTE byEnableCruise[MAX_CHANNUM];		/* 是否调用巡航 0-否,1-是*/
	BYTE byCruiseNo[MAX_CHANNUM];			/* 巡航 */
	BYTE byEnablePtzTrack[MAX_CHANNUM];		/* 是否调用轨迹 0-否,1-是*/
	BYTE byPTZTrack[MAX_CHANNUM];			/* 调用的云台的轨迹序号 */
}NET_DVR_ALARMINCFG, *LPNET_DVR_ALARMINCFG;

//模拟报警输入参数配置
typedef struct
{
	DWORD 	dwSize;
	BYTE		byEnableAlarmHandle; //处理报警输入
	BYTE		byRes1[3];
	BYTE		byAlarmInName[NAME_LEN]; //模拟报警输入名称
	WORD		wAlarmInUpper; //模拟输入电压上限，实际值乘10，范围0~360
	WORD		wAlarmInLower; //模拟输入电压下限，实际值乘10，范围0~360 
	NET_DVR_HANDLEEXCEPTION_V30 struAlarmHandleType;	/* 处理方式 */ 
	NET_DVR_SCHEDTIME struAlarmTime[MAX_DAYS][MAX_TIMESEGMENT_V30];//布防时间
	BYTE		byRelRecordChan[MAX_CHANNUM_V30]; //被触发的录像通道
	BYTE		byRes2[100];
}NET_DVR_ANALOG_ALARMINCFG, *LPNET_DVR_ANALOG_ALARMINCFG;

//上传报警信息(9000扩展)
typedef struct 
{
	DWORD dwAlarmType;/*0-信号量报警,1-硬盘满,2-信号丢失,3－移动侦测,4－硬盘未格式化,5-读写硬盘出错,6-遮挡报警,7-制式不匹配, 8-非法访问, 9-视频信号异常,
                        10-录像异常,11- 智能场景变化,12-阵列异常,13-前端/录像分辨率不匹配,14-申请解码资源失败,15-智能侦测*/
	DWORD dwAlarmInputNumber;/*报警输入端口*/
	BYTE byAlarmOutputNumber[MAX_ALARMOUT_V30];/*触发的输出端口，为1表示对应输出*/
	BYTE byAlarmRelateChannel[MAX_CHANNUM_V30];/*触发的录像通道，为1表示对应录像, dwAlarmRelateChannel[0]对应第1个通道*/
	BYTE byChannel[MAX_CHANNUM_V30];/*dwAlarmType为2或3,6,9,10,14时，表示哪个通道，dwChannel[0]对应第1个通道*/
	BYTE byDiskNumber[MAX_DISKNUM_V30];/*dwAlarmType为1,4,5时,表示哪个硬盘, dwDiskNumber[0]对应第1个硬盘*/
#ifdef SDK_CHEZAI
	NET_DVR_ADDIT_POSITION GPS_pos;  /* GPS定位信息 */
#endif
}NET_DVR_ALARMINFO_V30, *LPNET_DVR_ALARMINFO_V30;

typedef struct tagNET_DVR_ALARM_HOT_SPARE
{
	DWORD  dwSize;   //结构体
	DWORD  dwExceptionCase;   //报警原因   0-网络异常
	NET_DVR_IPADDR  struDeviceIP;    //产生异常的设备IP地址
	BYTE    byRes[256];         //保留
}NET_DVR_ALARM_HOT_SPARE, *LPNET_DVR_ALARM_HOT_SPARE;

typedef struct 
{
	DWORD dwAlarmType;/*0-信号量报警,1-硬盘满,2-信号丢失,3－移动侦测,4－硬盘未格式化,5-读写硬盘出错,6-遮挡报警,7-制式不匹配, 8-非法访问, 9-视频信号异常，10-录像异常 11- 智能场景变化*/
	DWORD dwAlarmInputNumber;/*报警输入端口*/
	DWORD dwAlarmOutputNumber[MAX_ALARMOUT];/*触发的输出端口，哪一位为1表示对应哪一个输出*/
	DWORD dwAlarmRelateChannel[MAX_CHANNUM];/*触发的录像通道，哪一位为1表示对应哪一路录像, dwAlarmRelateChannel[0]对应第1个通道*/
	DWORD dwChannel[MAX_CHANNUM];/*dwAlarmType为2或3,6,9,10时，表示哪个通道，dwChannel[0]位对应第1个通道*/
	DWORD dwDiskNumber[MAX_DISKNUM];/*dwAlarmType为1,4,5时,表示哪个硬盘, dwDiskNumber[0]位对应第1个硬盘*/
}NET_DVR_ALARMINFO, *LPNET_DVR_ALARMINFO;

//////////////////////////////////////////////////////////////////////////////////////
//IPC接入参数配置
/* IP设备结构 */
typedef struct 
{
    DWORD dwEnable;				    /* 该IP设备是否启用 */
    BYTE sUserName[NAME_LEN];		/* 用户名 */
    BYTE sPassword[PASSWD_LEN];	    /* 密码 */ 
    NET_DVR_IPADDR struIP;			/* IP地址 */
    WORD wDVRPort;			 	    /* 端口号 */
    BYTE byRes[34];				/* 保留 */
}NET_DVR_IPDEVINFO, *LPNET_DVR_IPDEVINFO;

//ipc接入设备信息扩展，支持ip设备的域名添加
typedef struct tagNET_DVR_IPDEVINFO_V31
{
    BYTE byEnable;				    //该IP设备是否有效
	BYTE byProType;					//协议类型，0-私有协议，1-松下协议，2-索尼
    BYTE byEnableQuickAdd;        // 0 不支持快速添加  1 使用快速添加 
    // 快速添加需要设备IP和协议类型，其他信息由设备默认指定
    BYTE byRes1;					//保留字段，置0
    BYTE sUserName[NAME_LEN];		//用户名
    BYTE sPassword[PASSWD_LEN];	    //密码
    BYTE byDomain[MAX_DOMAIN_NAME];	//设备域名
    NET_DVR_IPADDR struIP;			//IP地址
    WORD wDVRPort;			 	    // 端口号
    BYTE byRes2[34];				//保留字段，置0
}NET_DVR_IPDEVINFO_V31, *LPNET_DVR_IPDEVINFO_V31;

/* IP通道匹配参数 */
typedef struct 
{
    BYTE byEnable;					/* 该通道是否在线 */
    BYTE byIPID;					//IP设备ID低8位，当设备ID为0时表示通道不可用
    BYTE byChannel;					/* 通道号 */
    BYTE byIPIDHigh;                // IP设备ID的高8位
	BYTE byTransProtocol;		        //传输协议类型0-TCP/auto(具体有设备决定)，1-UDP 2-多播 3-仅TCP 4-auto
	BYTE byres[31];					/* 保留 */
} NET_DVR_IPCHANINFO, *LPNET_DVR_IPCHANINFO;

/* IP接入配置结构 */
typedef struct 
{
    DWORD dwSize;			                            /* 结构大小 */
    NET_DVR_IPDEVINFO  struIPDevInfo[MAX_IP_DEVICE];    /* IP设备 */
    BYTE byAnalogChanEnable[MAX_ANALOG_CHANNUM];        /* 模拟通道是否启用，从低到高表示1-32通道，0表示无效 1有效 */
    NET_DVR_IPCHANINFO struIPChanInfo[MAX_IP_CHANNEL];	/* IP通道 */    
}NET_DVR_IPPARACFG, *LPNET_DVR_IPPARACFG;
/* 扩展IP接入配置结构 */
typedef struct tagNET_DVR_IPPARACFG_V31
{
    DWORD dwSize;			                            /* 结构大小 */
    NET_DVR_IPDEVINFO_V31  struIPDevInfo[MAX_IP_DEVICE];    /* IP设备 */
    BYTE byAnalogChanEnable[MAX_ANALOG_CHANNUM];        /* 模拟通道是否启用，从低到高表示1-32通道，0表示无效 1有效 */
    NET_DVR_IPCHANINFO struIPChanInfo[MAX_IP_CHANNEL];	/* IP通道 */    
}NET_DVR_IPPARACFG_V31, *LPNET_DVR_IPPARACFG_V31;

typedef  struct tagNET_DVR_IPSERVER_STREAM
{
    BYTE    byEnable;   // 是否在线
    BYTE    byRes[3];               // 保留字节
    NET_DVR_IPADDR struIPServer;    //IPServer 地址
    WORD    wPort;                  //IPServer 端口
    WORD    wDvrNameLen;            // DVR 名称长度
    BYTE    byDVRName[NAME_LEN];    // DVR名称
    WORD    wDVRSerialLen;          // 序列号长度
    WORD    byRes1[2];              // 保留字节
    BYTE    byDVRSerialNumber[SERIALNO_LEN];    // DVR序列号长度
    BYTE    byUserName[NAME_LEN];   // DVR 登陆用户名
    BYTE    byPassWord[PASSWD_LEN]; // DVR登陆密码
    BYTE    byChannel;              // DVR 通道
    BYTE    byRes2[11];             //  保留字节
}NET_DVR_IPSERVER_STREAM, *LPNET_DVR_IPSERVER_STREAM;

//流媒体服务器基本配置
typedef struct tagNET_DVR_STREAM_MEDIA_SERVER_CFG
{
    BYTE	byValid;			/*是否可用*/
    BYTE	byRes1[3];
    NET_DVR_IPADDR  struDevIP;      
    WORD	wDevPort;			/*流媒体服务器端口*/    
    BYTE	byTransmitType;		/*传输协议类型 0-TCP，1-UDP*/
    BYTE	byRes2[69];
}NET_DVR_STREAM_MEDIA_SERVER_CFG,*LPNET_DVR_STREAM_MEDIA_SERVER_CFG;

//设备通道信息
typedef struct tagNET_DVR_DEV_CHAN_INFO
{
    NET_DVR_IPADDR 	struIP;		    //DVR IP地址
    WORD 	wDVRPort;			 	//端口号
    BYTE 	byChannel;				//通道号
    BYTE	byTransProtocol;		//传输协议类型0-TCP，1-UDP
    BYTE	byTransMode;			//传输码流模式 0－主码流 1－子码流
    BYTE	byFactoryType;			/*前端设备厂家类型,通过接口获取*/
    BYTE	byDeviceType; //设备类型(视频综合平台智能板使用)，1-解码器（此时根据视频综合平台能力集中byVcaSupportChanMode字段来决定是使用解码通道还是显示通道），2-编码器
    BYTE    byDispChan;//显示通道号,智能配置使用
    BYTE	bySubDispChan;//显示通道子通道号，智能配置时使用
	BYTE	byResolution;	//; 1-CIF 2-4CIF 3-720P 4-1080P 5-500w大屏控制器使用，大屏控制器会根据该参数分配解码资源
    BYTE	byRes[2];
    BYTE    byDomain[MAX_DOMAIN_NAME];	//设备域名
    BYTE	sUserName[NAME_LEN];	//监控主机登陆帐号
    BYTE	sPassword[PASSWD_LEN];	//监控主机密码
}NET_DVR_DEV_CHAN_INFO,*LPNET_DVR_DEV_CHAN_INFO;

//直接通过流媒体取流
typedef struct tagNET_DVR_PU_STREAM_CFG
{
    DWORD								dwSize;
    NET_DVR_STREAM_MEDIA_SERVER_CFG	struStreamMediaSvrCfg;
    NET_DVR_DEV_CHAN_INFO				struDevChanInfo;
}NET_DVR_PU_STREAM_CFG,*LPNET_DVR_PU_STREAM_CFG;

typedef struct tagNET_DVR_DDNS_STREAM_CFG
{
	BYTE   byEnable;   // 是否启用
    BYTE   byRes1[3];
    NET_DVR_IPADDR  struStreamServer;            //流媒体服务器地址
    WORD   wStreamServerPort;           //流媒体服务器端口   
    BYTE   byStreamServerTransmitType;  //流媒体传输协议类型 0-TCP，1-UDP
	BYTE   byRes2;
	NET_DVR_IPADDR   struIPServer;          //IPSERVER地址
	WORD   wIPServerPort;        //IPserver端口号
	BYTE   byRes3[2];           
    BYTE   sDVRName[NAME_LEN];   //DVR名称
	WORD   wDVRNameLen;            // DVR名称长度
    WORD   wDVRSerialLen;          // 序列号长度
    BYTE   sDVRSerialNumber[SERIALNO_LEN];    // DVR序列号
    BYTE   sUserName[NAME_LEN];   // DVR 登陆用户名
    BYTE   sPassWord[PASSWD_LEN]; // DVR登陆密码
	WORD   wDVRPort;   //DVR端口号
    BYTE   byRes4[2];    
    BYTE   byChannel;              // DVR 通道
	BYTE   byTransProtocol; //传输协议类型0-TCP，1-UDP
    BYTE   byTransMode; //传输码流模式 0－主码流 1－子码流
    BYTE   byFactoryType; //前端设备厂家类型,通过接口获取
}NET_DVR_DDNS_STREAM_CFG, *LPNET_DVR_DDNS_STREAM_CFG;

typedef struct tagNET_DVR_PU_STREAM_URL
{
	BYTE    byEnable; 
	BYTE    strURL[240];
	BYTE	byTransPortocol ; // 传输协议类型 0-tcp  1-UDP
	WORD    wIPID;  //设备ID号，wIPID = iDevInfoIndex + iGroupNO*64 +1
	BYTE	byChannel;  //通道号
	BYTE    byRes[7];   
}NET_DVR_PU_STREAM_URL, *LPNET_DVR_PU_STREAM_URL;

typedef struct tagNET_DVR_HKDDNS_STREAM
{
    BYTE    byEnable;				 // 是否在线
    BYTE    byRes[3];               // 保留字节
    BYTE    byDDNSDomain[64];		// hiDDNS服务器
    WORD    wPort;                  // hiDDNS 端口
    WORD    wAliasLen;              // 别名长度
    BYTE    byAlias[NAME_LEN];		 // 别名
    WORD    wDVRSerialLen;          // 序列号长度
    BYTE    byRes1[2];              // 保留字节
    BYTE    byDVRSerialNumber[SERIALNO_LEN];    // DVR序列号
    BYTE    byUserName[NAME_LEN];   // DVR 登陆用户名
    BYTE    byPassWord[PASSWD_LEN]; // DVR登陆密码
    BYTE    byChannel;              // DVR通道
    BYTE    byRes2[11];             // 保留字	
}NET_DVR_HKDDNS_STREAM, *LPNET_DVR_HKDDNS_STREAM;

typedef struct tagNET_DVR_IPCHANINFO_V40
{
	BYTE    byEnable;				/* 该通道是否在线 */
	BYTE    byRes1;
	WORD    wIPID;                  //IP设备ID
    DWORD 	dwChannel;				//通道号
    BYTE	byTransProtocol;		//传输协议类型0-TCP，1-UDP
    BYTE	byTransMode;			//传输码流模式 0－主码流 1－子码流
    BYTE	byFactoryType;			/*前端设备厂家类型,通过接口获取*/
    BYTE	byRes[241];
}NET_DVR_IPCHANINFO_V40,*LPNET_DVR_IPCHANINFO_V40;

typedef union tagNET_DVR_GET_STREAM_UNION
{
    NET_DVR_IPCHANINFO      struChanInfo;	/*IP通道信息*/
    NET_DVR_IPSERVER_STREAM struIPServerStream;  // IPServer去流
    NET_DVR_PU_STREAM_CFG   struPUStream;     //  通过前端设备获取流媒体去流
	NET_DVR_DDNS_STREAM_CFG struDDNSStream;     //通过IPServer和流媒体取流
	NET_DVR_PU_STREAM_URL   struStreamUrl;        //通过流媒体到url取流
	NET_DVR_HKDDNS_STREAM	struHkDDNSStream;   //通过hiDDNS去取流
	NET_DVR_IPCHANINFO_V40 struIPChan; //直接从设备取流（扩展）
}NET_DVR_GET_STREAM_UNION, *LPNET_DVR_GET_STREAM_UNION;

typedef enum
{
    NET_SDK_IP_DEVICE = 0,
    NET_SDK_STREAM_MEDIA,
    NET_SDK_IPSERVER,
	NET_SDK_DDNS_STREAM_CFG,
	NET_SDK_STREAM_MEDIA_URL,
	NET_SDK_HKDDNS,
	NET_SDK_IP_DEVICE_ADV
}GET_STREAM_TYPE;

typedef struct tagNET_DVR_STREAM_MODE
{
    BYTE    byGetStreamType; //取流方式GET_STREAM_TYPE，0-直接从设备取流，1-从流媒体取流、2-通过IPServer获得ip地址后取流,3.通过IPServer找到设备，再通过流媒体去设备的流
	                         //4-通过流媒体由URL去取流,5-通过hkDDNS取流，6-直接从设备取流(扩展)，使用NET_DVR_IPCHANINFO_V40结构
	BYTE    byRes[3];        //保留字节
    NET_DVR_GET_STREAM_UNION uGetStream;    // 不同取流方式结构体
}NET_DVR_STREAM_MODE, *LPNET_DVR_STREAM_MODE;

//扩展IP接入配置设备
typedef struct tagNET_DVR_IPPARACFG_V40
{
    DWORD      dwSize;			                /* 结构大小 */
    DWORD	   dwGroupNum;					//	 设备支持的总组数    
    DWORD      dwAChanNum;					//最大模拟通道个数
    DWORD      dwDChanNum;                  //数字通道个数
    DWORD      dwStartDChan;		            //起始数字通道
    BYTE       byAnalogChanEnable[MAX_CHANNUM_V30];    /* 模拟通道是否启用，从低到高表示1-64通道，0表示无效 1有效 */
    NET_DVR_IPDEVINFO_V31   struIPDevInfo[MAX_IP_DEVICE_V40];      /* IP设备 */
    NET_DVR_STREAM_MODE  struStreamMode[MAX_CHANNUM_V30];
    BYTE            byRes2[20];                 // 保留字节
}NET_DVR_IPPARACFG_V40, *LPNET_DVR_IPPARACFG_V40;


//为CVR扩展的报警类型
typedef struct tagNET_DVR_ALARMINFO_DEV
{
	DWORD     dwAlarmType;  //0-编码器(通道)信号量报警；1-私有卷二损坏；2- NVR服务退出；
	//3-编码器状态异常；4-系统时钟异常；5-录像卷剩余容量过低；
	//6-编码器(通道)移动侦测报警；7-编码器(通道)遮挡报警。
	NET_DVR_TIME   struTime;     //报警时间
	BYTE       byRes[32];    //保留
	DWORD      dwNumber;     //数目
    WORD       *pNO;         //dwNumber个WORD; 每个WORD表示一个通道号，或者磁盘号, 无效时为0
}NET_DVR_ALARMINFO_DEV, *LPNET_DVR_ALARMINFO_DEV;

/* 报警输出参数 */
typedef struct 
{
    BYTE byIPID;					/* IP设备ID取值1- MAX_IP_DEVICE */
    BYTE byAlarmOut;				/* 报警输出号 */
    BYTE byRes[18];					/* 保留 */
}NET_DVR_IPALARMOUTINFO, *LPNET_DVR_IPALARMOUTINFO;

/* IP报警输出配置结构 */
typedef struct 
{
    DWORD dwSize;			                        /* 结构大小 */    
   NET_DVR_IPALARMOUTINFO struIPAlarmOutInfo[MAX_IP_ALARMOUT];/* IP报警输出 */
}NET_DVR_IPALARMOUTCFG, *LPNET_DVR_IPALARMOUTCFG;

/* IP报警输出参数 */
typedef struct tagNET_DVR_IPALARMOUTINFO_V40
{
    DWORD dwIPID;					/* IP设备ID */
    DWORD dwAlarmOut;				/* IP设备ID对应的报警输出号 */
    BYTE  byRes[32];				/* 保留 */
}NET_DVR_IPALARMOUTINFO_V40, *LPNET_DVR_IPALARMOUTINFO_V40;/*报警输出参数*/

typedef struct tagNET_DVR_IPALARMOUTCFG_V40
{
    DWORD   dwSize;  //结构体长度
    DWORD   dwCurIPAlarmOutNum;
    NET_DVR_IPALARMOUTINFO_V40 struIPAlarmOutInfo[MAX_IP_ALARMOUT_V40];/*IP报警输出*/
    BYTE     byRes[256];
}NET_DVR_IPALARMOUTCFG_V40, *LPNET_DVR_IPALARMOUTCFG_V40; /*IP报警输出*/

/* 报警输入参数 */
typedef struct 
{
    BYTE byIPID;					/* IP设备ID取值1- MAX_IP_DEVICE */
    BYTE byAlarmIn;					/* 报警输入号 */
    BYTE byRes[18];					/* 保留 */
}NET_DVR_IPALARMININFO, *LPNET_DVR_IPALARMININFO;

/* IP报警输入配置结构 */
typedef struct 
{
    DWORD dwSize;			                        /* 结构大小 */    
    NET_DVR_IPALARMININFO struIPAlarmInInfo[MAX_IP_ALARMIN];/* IP报警输入 */
}NET_DVR_IPALARMINCFG, *LPNET_DVR_IPALARMINCFG;

/* IP报警输入参数 */
typedef struct tagNET_DVR_IPALARMININFO_V40
{
    DWORD dwIPID;					/* IP设备ID */
    DWORD dwAlarmIn;				/* IP设备ID对应的报警输入号 */
    BYTE  byRes[32];				/* 保留 */
}NET_DVR_IPALARMININFO_V40, *LPNET_DVR_IPALARMININFO_V40;   /* 报警输入参数 */

typedef struct tagNET_DVR_IPALARMINCFG_V40
{
    DWORD   dwSize;  //结构体长度
    DWORD   dwCurIPAlarmInNum;  //当前报警输入口数
    NET_DVR_IPALARMININFO_V40 struIPAlarmInInfo[MAX_IP_ALARMIN_V40];/* IP报警输入*/
    BYTE     byRes[256];
}NET_DVR_IPALARMINCFG_V40, *LPNET_DVR_IPALARMINCFG_V40; /*IP报警输入资源*/

//ipc alarm info
typedef struct tagNET_DVR_IPALARMINFO
{
    NET_DVR_IPDEVINFO  struIPDevInfo[MAX_IP_DEVICE];            /* IP设备 */
    BYTE byAnalogChanEnable[MAX_ANALOG_CHANNUM];                /* 模拟通道是否启用，0-未启用 1-启用 */
    NET_DVR_IPCHANINFO struIPChanInfo[MAX_IP_CHANNEL];	        /* IP通道 */
    NET_DVR_IPALARMININFO struIPAlarmInInfo[MAX_IP_ALARMIN];    /* IP报警输入 */
    NET_DVR_IPALARMOUTINFO struIPAlarmOutInfo[MAX_IP_ALARMOUT]; /* IP报警输出 */
}NET_DVR_IPALARMINFO, *LPNET_DVR_IPALARMINFO;

//ipc配置改变报警信息扩展 9000_1.1
typedef struct tagNET_DVR_IPALARMINFO_V31
{
    NET_DVR_IPDEVINFO_V31  struIPDevInfo[MAX_IP_DEVICE];            /* IP设备 */
    BYTE byAnalogChanEnable[MAX_ANALOG_CHANNUM];                /* 模拟通道是否启用，0-未启用 1-启用 */
    NET_DVR_IPCHANINFO struIPChanInfo[MAX_IP_CHANNEL];	        /* IP通道 */
    NET_DVR_IPALARMININFO struIPAlarmInInfo[MAX_IP_ALARMIN];    /* IP报警输入 */
    NET_DVR_IPALARMOUTINFO struIPAlarmOutInfo[MAX_IP_ALARMOUT]; /* IP报警输出 */   
}NET_DVR_IPALARMINFO_V31, *LPNET_DVR_IPALARMINFO_V31;

typedef struct tagNET_DVR_IPALARMINFO_V40
{
    NET_DVR_IPDEVINFO_V31 struIPDevInfo[MAX_IP_DEVICE_V40];           // IP设备
    BYTE     byAnalogChanEnable[MAX_CHANNUM_V30];           /* 模拟通道是否启用，0-未启用 1-启用 */
    NET_DVR_IPCHANINFO struIPChanInfo[MAX_CHANNUM_V30];	        /* IP通道 */
    NET_DVR_IPALARMININFO struIPAlarmInInfo[MAX_IP_ALARMIN];    /* IP报警输入 */
    NET_DVR_IPALARMOUTINFO struIPAlarmOutInfo[MAX_IP_ALARMOUT]; /* IP报警输出 */   
    BYTE                    byRes[20];                          // 保留字节
}NET_DVR_IPALARMINFO_V40, *LPNET_DVR_IPALARMINFO_V40;

typedef enum _HD_STAT_
{
	HD_STAT_OK					=	0,    /* 正常 */
	HD_STAT_UNFORMATTED			=	1,    /* 未格式化 */
	HD_STAT_ERROR           	=	2,    /* 错误 */
	HD_STAT_SMART_FAILED    	=	3,    /* SMART状态 */
	HD_STAT_MISMATCH        	=	4,    /* 不匹配 */
	HD_STAT_IDLE            	=	5,    /* 休眠*/
	NET_HD_STAT_OFFLINE     	=	6,    /* 网络盘处于未连接状态 */
	HD_RIADVD_EXPAND            =   7,    /* 虚拟磁盘可扩容 */
	HD_STAT_REPARING            =   10,   /* 硬盘正在修复(9000 2.0) */
	HD_STAT_FORMATING           =   11,   /* 硬盘正在格式化(9000 2.0) */ 
}HD_STAT;


//本地硬盘信息配置
typedef struct
{
    DWORD dwHDNo;         /*硬盘号, 取值0~MAX_DISKNUM_V30-1*/
    DWORD dwCapacity;     /*硬盘容量(不可设置)*/
    DWORD dwFreeSpace;    /*硬盘剩余空间(不可设置)*/
	DWORD dwHdStatus;     //硬盘状态(不可设置) HD_STAT 0-正常, 1-未格式化, 2-错误, 3-SMART状态, 
							//4-不匹配, 5-休眠 6-网络硬盘不在线 7-虚拟磁盘可扩容 10-硬盘正在修复
							//11-硬盘正在格式化 12-硬盘正在等待格式化 13-硬盘已卸载 14-本地硬盘不存在
	                        //15-正在删除(网络硬盘)
    BYTE  byHDAttr;       /*0-普通, 1-冗余; 2-只读 3-存档（CVR专用）*/
	BYTE  byHDType;		  /*0-本地硬盘,1-ESATA硬盘,2-NAS硬盘,3-iSCSI硬盘 4-Array虚拟磁盘*/
    BYTE  byDiskDriver;   // 值 代表其ASCII字符 
	BYTE  byRes1[1];
    DWORD dwHdGroup;      /*属于哪个盘组 1-MAX_HD_GROUP*/
	BYTE  byRecycling;   // 是否循环利用 0：不循环利用，1：循环利用
	BYTE  byRes2[3];
	DWORD  dwStorageType;    //按位表示 0-不支持 非0-支持
							// dwStorageType & 0x1 表示是否是普通录像专用存储盘     
							// dwStorageType & 0x2  表示是否是抽帧录像专用存储盘
							// dwStorageType & 0x4 表示是否是图片录像专用存储盘

	DWORD dwPictureCapacity; //硬盘图片容量(不可设置)，单位:MB
	DWORD dwFreePictureSpace; //剩余图片空间(不可设置)，单位:MB
    BYTE  byRes3[104];
}NET_DVR_SINGLE_HD, *LPNET_DVR_SINGLE_HD;

typedef struct
{
    DWORD dwSize;
    DWORD dwHDCount;          /*硬盘数(不可设置)*/
    NET_DVR_SINGLE_HD struHDInfo[MAX_DISKNUM_V30];//硬盘相关操作都需要重启才能生效；
}NET_DVR_HDCFG, *LPNET_DVR_HDCFG;

//本地盘组信息配置扩展
typedef struct tagNET_DVR_SINGLE_HDGROUP_V40
{
    DWORD 	dwHDGroupNo;       /*盘组号(不可设置) 1-MAX_HD_GROUP*/        
    DWORD  	dwRelRecordChan[MAX_CHANNUM_V40];  //触发的录像通道，按值表示，遇到0xffffffff时后续视为无效     
    BYTE   	byRes[64];				/* 保留 */
}NET_DVR_SINGLE_HDGROUP_V40, *LPNET_DVR_SINGLE_HDGROUP_V40;

typedef struct tagNET_DVR_HDGROUP_CFG_V40
{
    DWORD  	dwSize;                //结构体大小
    DWORD     dwMaxHDGroupNum; 		  //设备支持的最大盘组数-只读
    DWORD     dwCurHDGroupNum;       /*当前配置的盘组数*/
    NET_DVR_SINGLE_HDGROUP_V40 struHDGroupAttr[MAX_HD_GROUP]; //硬盘相关操作都需要重启才能生效；
    BYTE   	byRes[128]; //保留
}NET_DVR_HDGROUP_CFG_V40, *LPNET_DVR_HDGROUP_CFG_V40;

//本地盘组信息配置
typedef struct
{
    DWORD dwHDGroupNo;       /*盘组号(不可设置) 1-MAX_HD_GROUP*/        
    BYTE byHDGroupChans[MAX_CHANNUM_V30]; /*盘组对应的录像通道, 0-表示该通道不录象到该盘组，1-表示录象到该盘组*/
    BYTE byRes[8];
}NET_DVR_SINGLE_HDGROUP, *LPNET_DVR_SINGLE_HDGROUP;

typedef struct
{
    DWORD dwSize;
    DWORD dwHDGroupCount;        /*盘组总数(不可设置)*/
    NET_DVR_SINGLE_HDGROUP struHDGroupAttr[MAX_HD_GROUP];//硬盘相关操作都需要重启才能生效；
}NET_DVR_HDGROUP_CFG, *LPNET_DVR_HDGROUP_CFG;
                                       

//配置缩放参数的结构
typedef struct
{
    DWORD dwSize;
    DWORD dwMajorScale;    /* 主显示 0-不缩放，1-缩放*/
    DWORD dwMinorScale;    /* 辅显示 0-不缩放，1-缩放*/
    DWORD dwRes[2];
}NET_DVR_SCALECFG, *LPNET_DVR_SCALECFG;



//DVR报警输出(9000扩展)
typedef struct 
{
	DWORD dwSize;
	BYTE sAlarmOutName[NAME_LEN];	/* 名称 */
	DWORD dwAlarmOutDelay;	/* 输出保持时间(-1为无限，手动关闭) */
	//0-5秒,1-10秒,2-30秒,3-1分钟,4-2分钟,5-5分钟,6-10分钟,7-手动
	NET_DVR_SCHEDTIME struAlarmOutTime[MAX_DAYS][MAX_TIMESEGMENT_V30];/* 报警输出激活时间段 */
    BYTE byRes[16];
}NET_DVR_ALARMOUTCFG_V30, *LPNET_DVR_ALARMOUTCFG_V30;

//DVR报警输出
typedef struct 
{
	DWORD dwSize;
	BYTE sAlarmOutName[NAME_LEN];	/* 名称 */
	DWORD dwAlarmOutDelay;	/* 输出保持时间(-1为无限，手动关闭) */
	//0-5秒,1-10秒,2-30秒,3-1分钟,4-2分钟,5-5分钟,6-10分钟,7-手动
	NET_DVR_SCHEDTIME struAlarmOutTime[MAX_DAYS][MAX_TIMESEGMENT];/* 报警输出激活时间段 */
}NET_DVR_ALARMOUTCFG, *LPNET_DVR_ALARMOUTCFG;

//DVR本地预览参数(9000扩展)
/*切换是指在当前预览模式下切换显示画面，而不是切换预览模式。比如byPreviewNumber为0（1画面），bySwitchSeq[0][0] = 1,bySwitchSeq[0][1] = 2,bySwitchSeq[0][2] = 3 
则本地画面一直是1画面，然后在输出画面按1,2,3通道顺序切换*/
typedef struct 
{
    DWORD dwSize;
    BYTE byPreviewNumber;//预览模式,0-1画面,1-4画面,2-9画面,3-16画面,0xff:最大画面
    BYTE byEnableAudio;//是否声音预览,0-不预览,1-预览
    WORD wSwitchTime;//切换时间,0-不切换,1-5s,2-10s,3-20s,4-30s,5-60s,6-120s,7-300s
    BYTE bySwitchSeq[MAX_PREVIEW_MODE][MAX_WINDOW_V30];//切换顺序,如果lSwitchSeq[i]为 0xff表示不用
    BYTE byRes[24];
}NET_DVR_PREVIEWCFG_V30, *LPNET_DVR_PREVIEWCFG_V30;

//DVR本地预览参数
typedef struct 
{
	DWORD dwSize;
	BYTE byPreviewNumber;//预览数目,0-1画面,1-4画面,2-9画面,3-16画面,0xff:最大画面
	BYTE byEnableAudio;//是否声音预览,0-不预览,1-预览
	WORD wSwitchTime;//切换时间,0-不切换,1-5s,2-10s,3-20s,4-30s,5-60s,6-120s,7-300s
	BYTE bySwitchSeq[MAX_WINDOW];//切换顺序,如果lSwitchSeq[i]为 0xff表示不用
}NET_DVR_PREVIEWCFG, *LPNET_DVR_PREVIEWCFG;

//DVR视频输出
typedef struct 
{
	WORD wResolution;							/* 分辨率 */
	WORD wFreq;									/* 刷新频率 */
	DWORD dwBrightness;							/* 亮度 */
}NET_DVR_VGAPARA;

/*
* MATRIX输出参数结构
*/
typedef struct
{		
	WORD	wOrder[MAX_ANALOG_CHANNUM];		/* 预览顺序, 0xff表示相应的窗口不预览 */
	WORD	wSwitchTime;				/* 预览切换时间 */
	BYTE	res[14];
}NET_DVR_MATRIXPARA_V30, *LPNET_DVR_MATRIXPARA_V30;

typedef struct 
{
	WORD wDisplayLogo;						/* 显示视频通道号 */
	WORD wDisplayOsd;						/* 显示时间 */
}NET_DVR_MATRIXPARA;

typedef struct 
{
	BYTE byVideoFormat;						/* 输出制式,0-PAL,1-NTSC */
	BYTE byMenuAlphaValue;					/* 菜单与背景图象对比度 */
	WORD wScreenSaveTime;					/* 屏幕保护时间 0-从不,1-1分钟,2-2分钟,3-5分钟,4-10分钟,5-20分钟,6-30分钟 */
	WORD wVOffset;							/* 视频输出偏移 */
	WORD wBrightness;						/* 视频输出亮度 */
	BYTE byStartMode;						/* 启动后视频输出模式(0:菜单,1:预览)*/
	BYTE byEnableScaler;                    /* 是否启动缩放 (0-不启动, 1-启动)*/
}NET_DVR_VOOUT;

//DVR视频输出(9000扩展)
typedef struct 
{
	DWORD dwSize;
	NET_DVR_VOOUT struVOOut[MAX_VIDEOOUT_V30];
	NET_DVR_VGAPARA struVGAPara[MAX_VGA_V30];	/* VGA参数 */
	NET_DVR_MATRIXPARA_V30 struMatrixPara[MAX_MATRIXOUT];		/* MATRIX参数 */
    BYTE byRes[16];
}NET_DVR_VIDEOOUT_V30, *LPNET_DVR_VIDEOOUT_V30;

//DVR视频输出
typedef struct 
{
	DWORD dwSize;
	NET_DVR_VOOUT struVOOut[MAX_VIDEOOUT];
	NET_DVR_VGAPARA struVGAPara[MAX_VGA];	/* VGA参数 */
	NET_DVR_MATRIXPARA struMatrixPara;		/* MATRIX参数 */
}NET_DVR_VIDEOOUT, *LPNET_DVR_VIDEOOUT;


//单用户参数(子结构)(扩展)
typedef struct tagNET_DVR_USER_INFO_V40
{
	BYTE	sUserName[NAME_LEN];			/* 用户名只能用16字节 */
	BYTE	sPassword[PASSWD_LEN];			/* 密码 */
	BYTE    byLocalRight[MAX_RIGHT];	/* 本地权限 */
	/*数组0: 本地控制云台*/
	/*数组1: 本地手动录象*/
	/*数组2: 本地回放*/
	/*数组3: 本地设置参数*/
	/*数组4: 本地查看状态、日志*/
	/*数组5: 本地高级操作(升级，格式化，重启，关机)*/
    /*数组6: 本地查看参数 */
    /*数组7: 本地管理模拟和IP camera */
    /*数组8: 本地备份 */
    /*数组9: 本地关机/重启 */    
	BYTE    byRemoteRight[MAX_RIGHT];/* 远程权限 */	
	/*数组0: 远程控制云台*/
	/*数组1: 远程手动录象*/
	/*数组2: 远程回放 */
	/*数组3: 远程设置参数*/
	/*数组4: 远程查看状态、日志*/
	/*数组5: 远程高级操作(升级，格式化，重启，关机)*/
	/*数组6: 远程发起语音对讲*/
	/*数组7: 远程预览*/
	/*数组8: 远程请求报警上传、报警输出*/
	/*数组9: 远程控制，本地输出*/
	/*数组10: 远程控制串口*/	
    /*数组11: 远程查看参数 */
    /*数组12: 远程管理模拟和IP camera */
    /*数组13: 远程关机/重启 */	
    DWORD    dwNetPreviewRight[MAX_CHANNUM_V40];			/* 远程可以预览的通道，从前往后顺序排列，遇到0xffffffff后续均为无效*/
	DWORD    dwLocalRecordRight[MAX_CHANNUM_V40];			/* 本地可以录像的通道，从前往后顺序排列，遇到0xffffffff后续均为无效*/
	DWORD    dwNetRecordRight[MAX_CHANNUM_V40];			/* 远程可以录像的通道，从前往后顺序排列，遇到0xffffffff后续均为无效*/
	DWORD    dwLocalPlaybackRight[MAX_CHANNUM_V40];			/* 本地可以回放的通道，从前往后顺序排列，遇到0xffffffff后续均为无效*/
	DWORD    dwNetPlaybackRight[MAX_CHANNUM_V40];			/* 远程可以回放的通道，从前往后顺序排列，遇到0xffffffff后续均为无效*/
	DWORD    dwLocalPTZRight[MAX_CHANNUM_V40];				/* 本地可以PTZ的通道，从前往后顺序排列，遇到0xffffffff后续均为无效*/
	DWORD    dwNetPTZRight[MAX_CHANNUM_V40];				/* 远程可以PTZ的通道，从前往后顺序排列，遇到0xffffffff后续均为无效*/
	DWORD    dwLocalBackupRight[MAX_CHANNUM_V40];			/* 本地备份权限通道，从前往后顺序排列，遇到0xffffffff后续均为无效*/
	NET_DVR_IPADDR	struUserIP;				/* 用户IP地址(为0时表示允许任何地址) */
    BYTE     byMACAddr[MACADDR_LEN];	/* 物理地址 */
	BYTE     byPriority;				/* 优先级，0xff-无，0--低，1--中，2--高 */
                                    /* 无……表示不支持优先级的设置
                                    低……默认权限:包括本地和远程回放,本地和远程查看日志和
状态,本地和远程关机/重启
                                    中……包括本地和远程控制云台,本地和远程手动录像,本地和
远程回放,语音对讲和远程预览、本地备份,本地/远程关机/重启
                                    高……管理员 */
	BYTE	byAlarmOnRight;         // 报警输入口布防权限 1-有权限，0-无权限
	BYTE	byAlarmOffRight;         // 报警输入口撤防权限 1-有权限，0-无权限
	BYTE	byBypassRight;           // 报警输入口旁路权限 1-有权限，0-无权限 

	BYTE	byRes[118];	
}NET_DVR_USER_INFO_V40, *LPNET_DVR_USER_INFO_V40;


//单用户参数(子结构)(9000扩展)
typedef struct
{
	BYTE sUserName[NAME_LEN];		/* 用户名 */
	BYTE sPassword[PASSWD_LEN];		/* 密码 */
	BYTE byLocalRight[MAX_RIGHT];	/* 本地权限 */
	/*数组0: 本地控制云台*/
	/*数组1: 本地手动录象*/
	/*数组2: 本地回放*/
	/*数组3: 本地设置参数*/
	/*数组4: 本地查看状态、日志*/
	/*数组5: 本地高级操作(升级，格式化，重启，关机)*/
    /*数组6: 本地查看参数 */
    /*数组7: 本地管理模拟和IP camera */
    /*数组8: 本地备份 */
    /*数组9: 本地关机/重启 */    
	BYTE byRemoteRight[MAX_RIGHT];/* 远程权限 */	
	/*数组0: 远程控制云台*/
	/*数组1: 远程手动录象*/
	/*数组2: 远程回放 */
	/*数组3: 远程设置参数*/
	/*数组4: 远程查看状态、日志*/
	/*数组5: 远程高级操作(升级，格式化，重启，关机)*/
	/*数组6: 远程发起语音对讲*/
	/*数组7: 远程预览*/
	/*数组8: 远程请求报警上传、报警输出*/
	/*数组9: 远程控制，本地输出*/
	/*数组10: 远程控制串口*/	
    /*数组11: 远程查看参数 */
    /*数组12: 远程管理模拟和IP camera */
    /*数组13: 远程关机/重启 */
	BYTE byNetPreviewRight[MAX_CHANNUM_V30];		/* 远程可以预览的通道 0-有权限，1-无权限*/
	BYTE byLocalPlaybackRight[MAX_CHANNUM_V30];	/* 本地可以回放的通道 0-有权限，1-无权限*/
	BYTE byNetPlaybackRight[MAX_CHANNUM_V30];	/* 远程可以回放的通道 0-有权限，1-无权限*/
	BYTE byLocalRecordRight[MAX_CHANNUM_V30];		/* 本地可以录像的通道 0-有权限，1-无权限*/
	BYTE byNetRecordRight[MAX_CHANNUM_V30];		/* 远程可以录像的通道 0-有权限，1-无权限*/
	BYTE byLocalPTZRight[MAX_CHANNUM_V30];		/* 本地可以PTZ的通道 0-有权限，1-无权限*/
	BYTE byNetPTZRight[MAX_CHANNUM_V30];			/* 远程可以PTZ的通道 0-有权限，1-无权限*/
	BYTE byLocalBackupRight[MAX_CHANNUM_V30];		/* 本地备份权限通道 0-有权限，1-无权限*/
	NET_DVR_IPADDR struUserIP;		/* 用户IP地址(为0时表示允许任何地址) */
	BYTE byMACAddr[MACADDR_LEN];	/* 物理地址 */
	BYTE byPriority;				/* 优先级，0xff-无，0--低，1--中，2--高 */
                                    /*
                                    无……表示不支持优先级的设置
                                    低……默认权限:包括本地和远程回放,本地和远程查看日志和状态,本地和远程关机/重启
                                    中……包括本地和远程控制云台,本地和远程手动录像,本地和远程回放,语音对讲和远程预览
                                          本地备份,本地/远程关机/重启
                                    高……管理员
                                    */
	BYTE	byAlarmOnRight;         // 报警输入口布防权限
	BYTE	byAlarmOffRight;        // 报警输入口撤防权限
	BYTE	byBypassRight;          // 报警输入口旁路权限
	BYTE	byRes[14];	
}NET_DVR_USER_INFO_V30, *LPNET_DVR_USER_INFO_V30;

//单用户参数(SDK_V15扩展)(子结构)
typedef struct 
{
	BYTE sUserName[NAME_LEN];		/* 用户名 */
	BYTE sPassword[PASSWD_LEN];		/* 密码 */
	DWORD dwLocalRight[MAX_RIGHT];	/* 权限 */
	/*数组0: 本地控制云台*/
	/*数组1: 本地手动录象*/
	/*数组2: 本地回放*/
	/*数组3: 本地设置参数*/
	/*数组4: 本地查看状态、日志*/
	/*数组5: 本地高级操作(升级，格式化，重启，关机)*/
	DWORD dwLocalPlaybackRight;		/* 本地可以回放的通道 bit0 -- channel 1*/
	DWORD dwRemoteRight[MAX_RIGHT];	/* 权限 */
	/*数组0: 远程控制云台*/
	/*数组1: 远程手动录象*/
	/*数组2: 远程回放 */
	/*数组3: 远程设置参数*/
	/*数组4: 远程查看状态、日志*/
	/*数组5: 远程高级操作(升级，格式化，重启，关机)*/
	/*数组6: 远程发起语音对讲*/
	/*数组7: 远程预览*/
	/*数组8: 远程请求报警上传、报警输出*/
	/*数组9: 远程控制，本地输出*/
	/*数组10: 远程控制串口*/
	DWORD dwNetPreviewRight;		/* 远程可以预览的通道 bit0 -- channel 1*/
	DWORD dwNetPlaybackRight;		/* 远程可以回放的通道 bit0 -- channel 1*/
	char sUserIP[16];				/* 用户IP地址(为0时表示允许任何地址) */
	BYTE byMACAddr[MACADDR_LEN];	/* 物理地址 */
}NET_DVR_USER_INFO_EX, *LPNET_DVR_USER_INFO_EX;

//单用户参数(子结构)
typedef struct 
{
	BYTE sUserName[NAME_LEN];		/* 用户名 */
	BYTE sPassword[PASSWD_LEN];		/* 密码 */
	DWORD dwLocalRight[MAX_RIGHT];	/* 权限 */
	/*数组0: 本地控制云台*/
	/*数组1: 本地手动录象*/
	/*数组2: 本地回放*/
	/*数组3: 本地设置参数*/
	/*数组4: 本地查看状态、日志*/
	/*数组5: 本地高级操作(升级，格式化，重启，关机)*/
	DWORD dwRemoteRight[MAX_RIGHT];	/* 权限 */
	/*数组0: 远程控制云台*/
	/*数组1: 远程手动录象*/
	/*数组2: 远程回放 */
	/*数组3: 远程设置参数*/
	/*数组4: 远程查看状态、日志*/
	/*数组5: 远程高级操作(升级，格式化，重启，关机)*/
	/*数组6: 远程发起语音对讲*/
	/*数组7: 远程预览*/
	/*数组8: 远程请求报警上传、报警输出*/
	/*数组9: 远程控制，本地输出*/
	/*数组10: 远程控制串口*/
	char sUserIP[16];				/* 用户IP地址(为0时表示允许任何地址) */
	BYTE byMACAddr[MACADDR_LEN];	/* 物理地址 */
}NET_DVR_USER_INFO, *LPNET_DVR_USER_INFO;

//DVR用户参数(扩展)
typedef struct  tagNET_DVR_USER_V40
{
    DWORD dwSize;  //结构体大小
    DWORD dwMaxUserNum; //设备支持的最大用户数-只读
    NET_DVR_USER_INFO_V40 struUser[MAX_USERNUM_V30];  /* 用户参数 */
}NET_DVR_USER_V40,*LPNET_DVR_USER_V40;

//DVR用户参数(9000扩展)
typedef struct
{
	DWORD dwSize;
	NET_DVR_USER_INFO_V30 struUser[MAX_USERNUM_V30];
}NET_DVR_USER_V30, *LPNET_DVR_USER_V30;

//DVR用户参数(SDK_V15扩展)
typedef struct 
{
	DWORD dwSize;
	NET_DVR_USER_INFO_EX struUser[MAX_USERNUM];
}NET_DVR_USER_EX, *LPNET_DVR_USER_EX;

//DVR用户参数
typedef struct 
{
	DWORD dwSize;
	NET_DVR_USER_INFO struUser[MAX_USERNUM];
}NET_DVR_USER, *LPNET_DVR_USER;

typedef struct tagNET_DVR_EXCEPTION_V40
{
    DWORD             dwSize ;             //结构体大小
    DWORD             dwMaxGroupNum ;    //设备支持的最大组数
    NET_DVR_HANDLEEXCEPTION_V41 struExceptionHandle[MAX_EXCEPTIONNUM_V30];    
    BYTE   		 	byRes[128];          //保留
}NET_DVR_EXCEPTION_V40,*LPNET_DVR_EXCEPTION_V40; /*异常参数配置扩展结构体*/

//DVR异常参数(9000扩展)
typedef struct 
{
	DWORD dwSize;
	NET_DVR_HANDLEEXCEPTION_V30 struExceptionHandleType[MAX_EXCEPTIONNUM_V30];
	/*数组0-盘满,1- 硬盘出错,2-网线断,3-局域网内IP 地址冲突, 4-非法访问, 5-输入/输出视频制式不匹配, 6-视频信号异常, 7-录像异常 8-阵列异常，9-前端/录像分辨率不匹配异常，10-行车超速(车载专用) 11-热备异常（N+1使用）12-温度，13-子系统异常，14-风扇异常*/
}NET_DVR_EXCEPTION_V30, *LPNET_DVR_EXCEPTION_V30;

//DVR异常参数
typedef struct 
{
	DWORD dwSize;
	NET_DVR_HANDLEEXCEPTION struExceptionHandleType[MAX_EXCEPTIONNUM];
	/*数组0-盘满,1- 硬盘出错,2-网线断,3-局域网内IP 地址冲突,4-非法访问, 5-输入/输出视频制式不匹配, 6-视频信号异常*/
}NET_DVR_EXCEPTION, *LPNET_DVR_EXCEPTION;

//通道状态(9000扩展)
typedef struct 
{
	BYTE byRecordStatic; //通道是否在录像,0-不录像,1-录像
	BYTE bySignalStatic; //连接的信号状态,0-正常,1-信号丢失
	BYTE byHardwareStatic;//通道硬件状态,0-正常,1-异常,例如DSP死掉
	BYTE byRes1;		//保留
	DWORD dwBitRate;//实际码率
	DWORD dwLinkNum;//客户端连接的个数
	NET_DVR_IPADDR struClientIP[MAX_LINK];//客户端的IP地址
    DWORD dwIPLinkNum;//如果该通道为IP接入，那么表示IP接入当前的连接数
    BYTE byExceedMaxLink;		// 是否超出了单路6路连接数 0 - 未超出, 1-超出
	BYTE byRes[7];        // 保留字节
    DWORD dwChannelNo;    //当前的通道号，0xffffffff表示无效
}NET_DVR_CHANNELSTATE_V30, *LPNET_DVR_CHANNELSTATE_V30;

//通道状态
typedef struct 
{
	BYTE byRecordStatic; //通道是否在录像,0-不录像,1-录像
	BYTE bySignalStatic; //连接的信号状态,0-正常,1-信号丢失
	BYTE byHardwareStatic;//通道硬件状态,0-正常,1-异常,例如DSP死掉
	char reservedData;		//保留
	DWORD dwBitRate;//实际码率
	DWORD dwLinkNum;//客户端连接的个数
	DWORD dwClientIP[MAX_LINK];//客户端的IP地址
}NET_DVR_CHANNELSTATE, *LPNET_DVR_CHANNELSTATE;

//硬盘状态
typedef struct 
{
	DWORD dwVolume;//硬盘的容量
	DWORD dwFreeSpace;//硬盘的剩余空间
	DWORD dwHardDiskStatic; //硬盘的状态,按位:1-休眠,2-不正常,3-休眠硬盘出错,4-未格式化, 5-未连接状态(网络硬盘),6-硬盘正在格式化
}NET_DVR_DISKSTATE, *LPNET_DVR_DISKSTATE;

typedef struct tagNET_DVR_WORKSTATE_V40
{ 
    DWORD   dwSize ;            //结构体大小
    DWORD   dwDeviceStatic; 	 //设备的状态,0-正常,1-CPU占用率太高,超过85%,2-硬件错误,例如串口死掉
    NET_DVR_DISKSTATE  struHardDiskStatic[MAX_DISKNUM_V30];   //硬盘状态,一次最多只能获取33个硬盘信息
    NET_DVR_CHANNELSTATE_V30 struChanStatic[MAX_CHANNUM_V40/*512*/];//通道的状态，从前往后顺序排列
    DWORD   dwHasAlarmInStatic[MAX_ALARMIN_V40/*512*/]; //有报警的报警输入口，按值表示，按下标值顺序排列，值为0xffffffff时当前及后续值无效
    DWORD   dwHasAlarmOutStatic[MAX_ALARMOUT_V40/*512*/]; //有报警输出的报警输出口，按值表示，按下标值顺序排列，值为0xffffffff时当前及后续值无效
    DWORD   dwLocalDisplay;			//本地显示状态,0-正常,1-不正常
    BYTE    byAudioInChanStatus[MAX_AUDIO_V30/*2*/];		//按位表示语音通道的状态 0-未使用，1-使用中，第0位表示第1个语音通道
    BYTE    byRes[126]; 				//保留
}NET_DVR_WORKSTATE_V40, *LPNET_DVR_WORKSTATE_V40; /*设备工作状态扩展结构体*/

typedef struct tagNET_DVR_GETWORKSTATE_COND
{
    DWORD   dwSize ;  //结构体长度
    BYTE    byFindHardByCond; /*0-查找全部磁盘(但一次最多只能查找33个)，此时dwFindHardStatusNum无效*/
    BYTE    byFindChanByCond ;  /*0-查找全部通道，此时dwFindChanNum无效*/
    BYTE    byRes1[2] ;//保留	
    DWORD   dwFindHardStatus[MAX_DISKNUM_V30/*33*/] ; /*要查找的硬盘号，按值表示，该值采用顺序排列， 遇到0xffffffff则认为后续无效 */
    DWORD   dwFindChanNo[MAX_CHANNUM_V40/*512*/] ; /*要查找的通道号，按值表示，该值采用顺序排列， 遇到0xffffffff则认为后续无效 */
    BYTE 	byRes[64] ; //保留
}NET_DVR_GETWORKSTATE_COND, *LPNET_DVR_GETWORKSTATE_COND;

//DVR工作状态(9000扩展)
typedef struct 
{
	DWORD dwDeviceStatic; 	//设备的状态,0-正常,1-CPU占用率太高,超过85%,2-硬件错误,例如串口死掉
	NET_DVR_DISKSTATE  struHardDiskStatic[MAX_DISKNUM_V30];
	NET_DVR_CHANNELSTATE_V30 struChanStatic[MAX_CHANNUM_V30];//通道的状态
	BYTE  byAlarmInStatic[MAX_ALARMIN_V30]; //报警端口的状态,0-没有报警,1-有报警
	BYTE  byAlarmOutStatic[MAX_ALARMOUT_V30]; //报警输出端口的状态,0-没有输出,1-有报警输出
	DWORD  dwLocalDisplay;//本地显示状态,0-正常,1-不正常
    BYTE  byAudioChanStatus[MAX_AUDIO_V30];//表示语音通道的状态 0-未使用，1-使用中, 0xff无效
    BYTE  byRes[10];
}NET_DVR_WORKSTATE_V30, *LPNET_DVR_WORKSTATE_V30;

//DVR工作状态
typedef struct 
{
	DWORD dwDeviceStatic; 	//设备的状态,0-正常,1-CPU占用率太高,超过85%,2-硬件错误,例如串口死掉
	NET_DVR_DISKSTATE  struHardDiskStatic[MAX_DISKNUM];
	NET_DVR_CHANNELSTATE struChanStatic[MAX_CHANNUM];//通道的状态
	BYTE  byAlarmInStatic[MAX_ALARMIN]; //报警端口的状态,0-没有报警,1-有报警
	BYTE  byAlarmOutStatic[MAX_ALARMOUT]; //报警输出端口的状态,0-没有输出,1-有报警输出
	DWORD  dwLocalDisplay;//本地显示状态,0-正常,1-不正常
}NET_DVR_WORKSTATE, *LPNET_DVR_WORKSTATE;



//日志信息(9000扩展)
typedef struct 
{
	NET_DVR_TIME strLogTime;
	DWORD	dwMajorType;	//主类型 1-报警; 2-异常; 3-操作; 0xff-全部
	DWORD	dwMinorType;//次类型 0-全部;
	BYTE	sPanelUser[MAX_NAMELEN]; //操作面板的用户名
	BYTE	sNetUser[MAX_NAMELEN];//网络操作的用户名
	NET_DVR_IPADDR	struRemoteHostAddr;//远程主机地址
	DWORD	dwParaType;//参数类型,9000设备MINOR_START_VT/MINOR_STOP_VT时，表示语音对讲的端子号
	DWORD	dwChannel;//通道号
	DWORD	dwDiskNumber;//硬盘号
	DWORD	dwAlarmInPort;//报警输入端口
	DWORD	dwAlarmOutPort;//报警输出端口
    DWORD   dwInfoLen;
    char    sInfo[LOG_INFO_LEN];
}NET_DVR_LOG_V30, *LPNET_DVR_LOG_V30;

//日志信息
typedef struct 
{
	NET_DVR_TIME strLogTime;
	DWORD	dwMajorType;	//主类型 1-报警; 2-异常; 3-操作; 0xff-全部
	DWORD	dwMinorType;//次类型 0-全部;
	BYTE	sPanelUser[MAX_NAMELEN]; //操作面板的用户名
	BYTE	sNetUser[MAX_NAMELEN];//网络操作的用户名
	char	sRemoteHostAddr[16];//远程主机地址
	DWORD	dwParaType;//参数类型
	DWORD	dwChannel;//通道号
	DWORD	dwDiskNumber;//硬盘号
	DWORD	dwAlarmInPort;//报警输入端口
	DWORD	dwAlarmOutPort;//报警输出端口
}NET_DVR_LOG, *LPNET_DVR_LOG;

/************************DVR日志 end***************************/

/************************动环报警管理主机日志查找 begin************************************************/
typedef struct tagNET_DVR_ALARMHOST_SEARCH_LOG_PARAM
{
    WORD            wMajorType;		// 主类型
    WORD            wMinorType;		// 次类型 
    NET_DVR_TIME    struStartTime;	// 开始时间 
    NET_DVR_TIME    struEndTime;	// 结束时间
    BYTE            byRes[8];		// 保留字节
}NET_DVR_ALARMHOST_SEARCH_LOG_PARAM, LPNET_DVR_ALARMHOST_SEARCH_LOG_PARAM;

typedef struct tagNET_DVR_ALARMHOST_LOG_RET
{
    NET_DVR_TIME	struLogTime;                //  日志时间
    BYTE		    sUserName[NAME_LEN];     // 操作用户
    NET_DVR_IPADDR	struIPAddr;                 // 操作IP地址
    WORD		    wMajorType;                 // 主类型 
    WORD		    wMinorType;                 // 次类型
    WORD	    	wParam;	                    // 操作参数
    BYTE		    byRes[10];
    DWORD		    dwInfoLen;	                // 描述信息长度
    char			sInfo[LOG_INFO_LEN];       // 描述信息
}NET_DVR_ALARMHOST_LOG_RET, *LPNET_DVR_ALARMHOST_LOG_RET;

/*************************动环报警管理主机日志查找 end***********************************************/

//报警输出状态(9000扩展)
typedef struct 
{
	BYTE Output[MAX_ALARMOUT_V30];
}NET_DVR_ALARMOUTSTATUS_V30, *LPNET_DVR_ALARMOUTSTATUS_V30;

//报警输出状态
typedef struct 
{
	BYTE Output[MAX_ALARMOUT];
}NET_DVR_ALARMOUTSTATUS, *LPNET_DVR_ALARMOUTSTATUS;

//交易信息
typedef struct 
{
	USHORT m_Year;
	USHORT m_Month;
	USHORT m_Day;
	USHORT m_Hour;
	USHORT m_Minute;
	USHORT m_Second;
	BYTE DeviceName[24];	//设备名称
	DWORD dwChannelNumer;	//通道号
	BYTE CardNumber[32];	//卡号
	char cTradeType[12];	//交易类型
	DWORD dwCash;			//交易金额
}NET_DVR_TRADEINFO, *LPNET_DVR_TRADEINFO;


//ATM专用
/****************************ATM(begin)***************************/
#define NCR		0
#define DIEBOLD	1
#define WINCOR_NIXDORF	2
#define SIEMENS	3
#define OLIVETTI	4
#define FUJITSU	5
#define HITACHI	6
#define SMI		7
#define IBM		8
#define BULL	9
#define YiHua	10
#define LiDe	11
#define GDYT	12
#define Mini_Banl	13
#define GuangLi	14
#define DongXin	15
#define ChenTong	16
#define NanTian	17
#define XiaoXing	18
#define GZYY	19
#define QHTLT	20
#define DRS918	21
#define KALATEL	22
#define NCR_2	23	
#define NXS		24


/*帧格式*/
typedef struct 
{
	BYTE code[12];		/* 代码 */
}NET_DVR_FRAMETYPECODE;


//ATM参数
typedef struct 
{
	DWORD dwSize;
	char sATMIP[16];						/* ATM IP地址 */
	DWORD dwATMType;						/* ATM类型 */
	DWORD dwInputMode;						/* 输入方式	0-网络侦听 1-网络接收 2-串口直接输入 3-串口ATM命令输入*/
	DWORD dwFrameSignBeginPos;              /* 报文标志位的起始位置*/
	DWORD dwFrameSignLength;				/* 报文标志位的长度 */
	BYTE  byFrameSignContent[12];			/* 报文标志位的内容 */
	DWORD dwCardLengthInfoBeginPos;			/* 卡号长度信息的起始位置 */
	DWORD dwCardLengthInfoLength;			/* 卡号长度信息的长度 */
	DWORD dwCardNumberInfoBeginPos;			/* 卡号信息的起始位置 */
	DWORD dwCardNumberInfoLength;			/* 卡号信息的长度 */
	DWORD dwBusinessTypeBeginPos;           /* 交易类型的起始位置 */
	DWORD dwBusinessTypeLength;				/* 交易类型的长度 */
	NET_DVR_FRAMETYPECODE frameTypeCode[10];/* 类型 */
}NET_DVR_FRAMEFORMAT, *LPNET_DVR_FRAMEFORMAT;
//SDK_V31 ATM

/*过滤设置*/
typedef struct	tagNET_DVR_FILTER
{	
	BYTE			        byEnable;			//0,不启用;1,启用
	BYTE					byMode;				//0,ASCII;1,HEX	
    BYTE                    byFrameBeginPos;    // 需要过滤目标字符串起始位置     
	BYTE					byRes[1];           // 保留字节
	BYTE 					byFilterText[16];	//过滤字符串
	BYTE					byRes2[12];         // 保留字节
}NET_DVR_FILTER, *LPNET_DVR_FILTER;

//数据包分析 数据包标识
typedef struct	tagNET_DVR_IDENTIFICAT
{	
	BYTE					byStartMode;		//起始字符模式:0,ASCII;1,HEX
	BYTE					byEndMode;			//结束字符模式：0,ASCII;1,HEX
	BYTE					byRes[2];           //保留字节
	NET_DVR_FRAMETYPECODE	struStartCode;		//数据包起始标识字符
	NET_DVR_FRAMETYPECODE	struEndCode;		//数据包结束标识字符
	BYTE					byRes1[12];         //保留字节
}NET_DVR_IDENTIFICAT, *LPNET_DVR_IDENTIFICAT;

typedef struct	tagNET_DVR_PACKAGE_LOCATION/*报文信息位置*/
{	
	BYTE 					byOffsetMode;			/*报文位置信息模式 0,token(字符标志模式);1,fix（固定模式）*/
    BYTE                    byRes1[3];				// 保留字节
	DWORD  				    dwOffsetPos;			/*mode为1的时候使用,固定偏移大小*/
	NET_DVR_FRAMETYPECODE	struTokenCode;			/*标志位*/
	BYTE					byMultiplierValue;		/*标志位多少次出现*/
	BYTE					byEternOffset;			/*附加字符偏移量*/
	BYTE					byCodeMode;			    /*0,ASCII;1,HEX*/
	BYTE 					byRes2[9];			    //保留字节
}NET_DVR_PACKAGE_LOCATION, *LPNET_DVR_PACKAGE_LOCATION;


typedef struct	tagNET_DVR_PACKAGE_LENGTH//报文信息长度
{	
	BYTE					byLengthMode;			//长度类型，0,可变长度;1,固定长度;2,自助长度(从卡号中获取)
    BYTE                    byRes1[3];              // 保留字节
	DWORD  			    	dwFixLength;			    //mode为1的时候使用,固定长度大小
	DWORD					dwMaxLength;            //报文信息最大长度  byLengthMode为0时使用
	DWORD					dwMinLength;            //报文信息最小长度  byLengthMode为0时使用
	BYTE					byEndMode;			    //可变长度 终结符模式 0,ASCII;1,HEX	
    BYTE                    byRes2[3];              //保留字节
	NET_DVR_FRAMETYPECODE	struEndCode;		//可变长度终结符
	DWORD					dwLengthPos;			//lengthMode为2的时候使用，卡号长度在报文中的位置
	DWORD					dwLengthLen;			//lengthMode为2的时候使用，卡号长度的长度
	BYTE					byRes3[8];              // 保留字节
}NET_DVR_PACKAGE_LENGTH,* LPNET_DVR_PACKAGE_LENGTH;
 
typedef struct	tagNET_DVR_OSD_POSITION//OSD 叠加的位置
{	
	BYTE					byPositionMode;		//叠加风格，共2种；0，不显示；1，自定义
    BYTE                    byRes1[3];          // 保留字节
	DWORD 					dwPosX;				//x坐标，叠加风格为自定义时使用
	DWORD					dwPosY;				//y坐标，叠加风格为自定义时使用
	BYTE					byRes2[8];          //保留字节
}NET_DVR_OSD_POSITION, *LPNET_DVR_OSD_POSITION;

typedef struct	tagNET_DVR_DATE_FORMAT//日期显示格式
{	
	BYTE					byMonth;			    //Month,0.mm;1.mmm;2.mmmm							
	BYTE 					byDay;				    //Day,0.dd;									
	BYTE 					byYear;				    //Year,0.yy;1.yyyy	
	BYTE					byDateForm;			    //0~5，年月日的排列组合
	BYTE					byRes[20];              // 保留字节
	char					chSeprator[4];		    //分隔符
	char	    			chDisplaySeprator[4];	//显示分隔符
    BYTE	    			byDisplayForm;			//0~5，3个item的排列组合
	BYTE					res[27];                // 保留字节
}NET_DVR_DATE_FORMAT, *LPNET_DVR_DATE_FORMAT;
typedef struct	tagNET_DVRT_TIME_FORMAT//时间显示格式
{	
	BYTE					byTimeForm;				//1. HH MM SS;0. HH MM
	BYTE 					byRes1[23];             // 保留字节
    BYTE                    byHourMode;             //0,12;1,24 
    BYTE                    byRes2[3];              // 保留字节
	char					chSeprator[4]; 			//报文分隔符，暂时没用
	char					chDisplaySeprator[4];	//显示分隔符
	BYTE	    			byDisplayForm;			//0~5，3个item的排列组合
    BYTE                    byRes3[3];              // 保留字节
	BYTE					byDisplayHourMode;		//0,12;1,24 
	BYTE					byRes4[19];             // 保留字节
}NET_DVR_TIME_FORMAT, *LPNET_DVR_TIME_FORMAT;

typedef struct tagNET_DVR_OVERLAY_CHANNEL
{	
	BYTE                    byChannel[64];//叠加的通道 每个字节标识一个通道， 例如byChannel[0]值为1对应叠加通道1，0表示不叠加通道1。
	DWORD					dwDelayTime;			//叠加延时时间
	BYTE					byEnableDelayTime;		//是否启用叠加延时
	BYTE					byRes[11];          // 保留字节
}NET_DVR_OVERLAY_CHANNEL, *LPNET_DVR_OVERLAY_CHANNEL;

// ATM 报文行为信息
typedef struct tagNET_DVR_ATM_PACKAGE_ACTION
{	
	NET_DVR_PACKAGE_LOCATION	struPackageLocation;// 报文位置信息
	NET_DVR_OSD_POSITION		struOsdPosition;    // OSD 叠加位置
	NET_DVR_FRAMETYPECODE		struActionCode;		//交易类型行为码
	NET_DVR_FRAMETYPECODE		struPreCode;		//叠加字符前的字符
	BYTE					byActionCodeMode;		//交易类型行为码模式0,ASCII;1,HEX
	BYTE					byRes[7];               // 保留字节
}NET_DVR_ATM_PACKAGE_ACTION, *LPNET_DVR_ATM_PACKAGE_ACTION;

// ATM 报文DATA信息
typedef struct tagNET_DVR_ATM_PACKAGE_DATE
{	
	NET_DVR_PACKAGE_LOCATION	struPackageLocation;// 日期在报文中的位置信息
	NET_DVR_DATE_FORMAT		    struDateForm;		//日期显示格式
	NET_DVR_OSD_POSITION		struOsdPosition;	// OSD叠加位置信息
	BYTE				    	res[8]; 			// 保留字节
}NET_DVR_ATM_PACKAGE_DATE, *LPNET_DVR_ATM_PACKAGE_DATE;


//ATM报文时间信息
typedef struct tagNET_DVR_ATM_PACKAGE_TIME
{	
	NET_DVR_PACKAGE_LOCATION	location;		// 时间在报文中的位置信息
	NET_DVR_TIME_FORMAT		    struTimeForm;	// 时间显示格式
	NET_DVR_OSD_POSITION		struOsdPosition;// OSD 叠加位置信息
	BYTE					    byRes[8];		// 保留字节
}NET_DVR_ATM_PACKAGE_TIME, *LPNET_DVR_ATM_PACKAGE_TIME;


// ATM 其他报文信息（卡号，交易金额，交易序号）
typedef struct tagNET_DVR_ATM_PACKAGE_OTHERS
{	
	NET_DVR_PACKAGE_LOCATION	struPackageLocation; //报文位置信息
	NET_DVR_PACKAGE_LENGTH	struPackageLength;		//长度信息
	NET_DVR_OSD_POSITION		struOsdPosition;	// OSD叠加位置信息
	NET_DVR_FRAMETYPECODE		struPreCode;		//叠加字符前的字符
	BYTE					res[8];					//保留字节
}NET_DVR_ATM_PACKAGE_OTHERS, *LPNET_DVR_ATM_PACKAGE_OTHERS;


//用户自定义协议
typedef struct tagNET_DVR_ATM_USER_DEFINE_PROTOCOL
{
    NET_DVR_IDENTIFICAT        struIdentification;  //报文标志
    NET_DVR_FILTER             struFilter; //数据包过滤设置
    NET_DVR_ATM_PACKAGE_OTHERS struCardNoPara; //叠加卡号设置
    NET_DVR_ATM_PACKAGE_ACTION struTradeActionPara[MAX_ACTION_TYPE]; //叠加交易行为设置 0-9 依次对应InCard OutCard OverLay SetTime GetStatus Query WithDraw Deposit ChanPass Transfer
    NET_DVR_ATM_PACKAGE_OTHERS struAmountPara; //叠加交易金额设置
    NET_DVR_ATM_PACKAGE_OTHERS struSerialNoPara; //叠加交易序号设置
    NET_DVR_OVERLAY_CHANNEL    struOverlayChan; //叠加通道设置
    NET_DVR_ATM_PACKAGE_DATE   struRes1; //叠加日期，保留
    NET_DVR_ATM_PACKAGE_TIME   struRes2; //叠加时间，保留
    BYTE                       byRes3[124];        //保留
}NET_DVR_ATM_USER_DEFINE_PROTOCOL, *LPNET_DVR_ATM_USER_DEFINE_PROTOCOL;

typedef struct tagNET_DVR_ATM_FRAMEFORMAT_V30
{		
    DWORD                        dwSize;                 //结构大小
    BYTE					    byEnable;				/*是否启用0,不启用;1,启用*/
    BYTE					    byInputMode;			/**输入方式:0-网络监听、1网络协议、2-串口监听、3-串口协议*/
    BYTE					    byRes1[34];              //保留字节 
    NET_DVR_IPADDR		    	struAtmIp;				/*ATM 机IP 网络监听时使用 */
    WORD					    wAtmPort;				/* 网络协议方式时是使用*/
    BYTE					    byRes2[2];              // 保留字节
    DWORD					    dwAtmType;				/*ATM协议类型，从NET_DVR_ATM_PROTOCOL结构中获取，如果类型为自定义时使用用户自定义协议*/
    NET_DVR_ATM_USER_DEFINE_PROTOCOL   struAtmUserDefineProtocol; //用户自定义协议，当ATM类型为自定时需要使用该定义
    BYTE					    byRes3[8];
}NET_DVR_ATM_FRAMEFORMAT_V30, *LPNET_DVR_ATM_FRAMEFORMAT_V30;


typedef struct  tagNET_DVR_ATM_PROTO_TYPE
{
    DWORD dwAtmType; //ATM协议类型，同时作为索引序号 ATM 配置中的dwAtmType 自定义时为1025
    char chDesc[ATM_DESC_LEN]; //ATM协议简单描述
}NET_DVR_ATM_PROTO_TYPE, *LPNET_DVR_ATM_PROTO_TYPE; //协议信息数据结构

typedef struct tagNET_DVR_ATM_PROTO_LIST    //ATM 协议列表
{
    DWORD                  dwAtmProtoNum;           // 协议列表的个数
    NET_DVR_ATM_PROTO_TYPE struAtmProtoType[MAX_ATM_PROTOCOL_NUM]; //协议列表信息
}NET_DVR_ATM_PROTO_LIST, *LPNET_DVR_ATM_PROTO_LIST;

typedef struct tagNET_DVR_ATM_PROTOCOL
{
    DWORD dwSize;
    NET_DVR_ATM_PROTO_LIST struNetListenList; // 网络监听协议描述
    NET_DVR_ATM_PROTO_LIST struSerialListenList; //串口监听协议描述
    NET_DVR_ATM_PROTO_LIST struNetProtoList;     //网络协议描述
    NET_DVR_ATM_PROTO_LIST struSerialProtoList;   //串口协议描述
    NET_DVR_ATM_PROTO_TYPE struCustomProto;        //自定义协议
}NET_DVR_ATM_PROTOCOL, *LPNET_DVR_ATM_PROTOCOL;
// SDK_V31

/*****************************DS-6001D/F(begin)***************************/
//DS-6001D Decoder
typedef struct 
{
	BYTE byEncoderIP[16];		//解码设备连接的服务器IP
	BYTE byEncoderUser[16];		//解码设备连接的服务器的用户名
	BYTE byEncoderPasswd[16];	//解码设备连接的服务器的密码
	BYTE bySendMode;			//解码设备连接服务器的连接模式
	BYTE byEncoderChannel;		//解码设备连接的服务器的通道号
	WORD wEncoderPort;			//解码设备连接的服务器的端口号
	BYTE reservedData[4];		//保留
}NET_DVR_DECODERINFO, *LPNET_DVR_DECODERINFO;

typedef struct 
{
	BYTE byEncoderIP[16];		//解码设备连接的服务器IP
	BYTE byEncoderUser[16];		//解码设备连接的服务器的用户名
	BYTE byEncoderPasswd[16];	//解码设备连接的服务器的密码
	BYTE byEncoderChannel;		//解码设备连接的服务器的通道号
	BYTE bySendMode;			//解码设备连接的服务器的连接模式
	WORD wEncoderPort;			//解码设备连接的服务器的端口号
	DWORD dwConnectState;		//解码设备连接服务器的状态
	BYTE reservedData[4];		//保留
}NET_DVR_DECODERSTATE, *LPNET_DVR_DECODERSTATE;

/*解码设备控制码定义*/
#define NET_DEC_STARTDEC		1
#define NET_DEC_STOPDEC			2
#define NET_DEC_STOPCYCLE		3
#define NET_DEC_CONTINUECYCLE	4
/*连接的通道配置*/
typedef struct 
{
	char sDVRIP[16];				/* DVR IP地址 */
	WORD wDVRPort;			 		/* 端口号 */
	BYTE sUserName[NAME_LEN];		/* 用户名 */
	BYTE sPassword[PASSWD_LEN];		/* 密码 */
	BYTE byChannel;					/* 通道号 */
	BYTE byLinkMode;				/* 连接模式 */
	BYTE byLinkType;				/* 连接类型 0－主码流 1－子码流 */
}NET_DVR_DECCHANINFO, *LPNET_DVR_DECCHANINFO;

/*每个解码通道的配置*/
typedef struct 
{
	BYTE	byPoolChans;			/*每路解码通道上的循环通道数量, 最多4通道 0表示没有解码*/
	NET_DVR_DECCHANINFO struchanConInfo[MAX_DECPOOLNUM];
	BYTE	byEnablePoll;			/*是否轮巡 0-否 1-是*/
	BYTE	byPoolTime;				/*轮巡时间 0-保留 1-10秒 2-15秒 3-20秒 4-30秒 5-45秒 6-1分钟 7-2分钟 8-5分钟 */
}NET_DVR_DECINFO, *LPNET_DVR_DECINFO;

/*整个设备解码配置*/
typedef struct 
{
	DWORD	dwSize;
	DWORD	dwDecChanNum; 		/*解码通道的数量*/
	NET_DVR_DECINFO struDecInfo[MAX_DECNUM];
}NET_DVR_DECCFG, *LPNET_DVR_DECCFG;

//2005-08-01
/* 解码设备透明通道设置 */
typedef struct 
{
	DWORD dwEnableTransPort;	/* 是否启动透明通道 0－不启用 1－启用*/
	char sDecoderIP[16];		/* DVR IP地址 */
	WORD wDecoderPort;			/* 端口号 */
	WORD wDVRTransPort;			/* 配置前端DVR是从485/232输出，1表示232串口,2表示485串口 */
	char cReserve[4];
}NET_DVR_PORTINFO, *LPNET_DVR_PORTINFO;

typedef struct 
{
	DWORD dwSize;
	NET_DVR_PORTINFO struTransPortInfo[MAX_TRANSPARENTNUM]; /* 数组0表示232 数组1表示485 */
}NET_DVR_PORTCFG, *LPNET_DVR_PORTCFG;

/* 控制网络文件回放 */
typedef struct 
{
	DWORD dwSize;
	char sDecoderIP[16];		/* DVR IP地址 */
	WORD wDecoderPort;			/* 端口号 */
	WORD wLoadMode;				/* 回放下载模式 1－按名字 2－按时间 */
	union
	{
		BYTE byFile[100];		/* 回放的文件名 */
		struct
		{
			DWORD dwChannel;
			BYTE sUserName[NAME_LEN];	/*请求视频用户名*/
			BYTE sPassword[PASSWD_LEN];	/* 密码 */
			NET_DVR_TIME struStartTime;	/* 按时间回放的开始时间 */
			NET_DVR_TIME struStopTime;	/* 按时间回放的结束时间 */
		}bytime;
	}mode_size;
}NET_DVR_PLAYREMOTEFILE, *LPNET_DVR_PLAYREMOTEFILE;

/*当前设备解码连接状态*/
typedef struct 
{
	DWORD dwWorkType;		/*工作方式：1：轮巡、2：动态连接解码、3：文件回放下载 4：按时间回放下载*/
	char sDVRIP[16];		/*连接的设备ip*/
	WORD wDVRPort;			/*连接端口号*/
	BYTE byChannel;			/* 通道号 */
	BYTE byLinkMode;		/* 连接模式 */
	DWORD	dwLinkType;		/*连接类型 0－主码流 1－子码流*/
	union
	{
		struct
		{
			BYTE sUserName[NAME_LEN];	/*请求视频用户名*/
			BYTE sPassword[PASSWD_LEN];	/* 密码 */
			char cReserve[52];
		}userInfo;
		struct
		{
			BYTE   fileName[100];
		}fileInfo;
		struct
		{
			DWORD	dwChannel;
			BYTE	sUserName[NAME_LEN];	/*请求视频用户名*/
			BYTE	sPassword[PASSWD_LEN];	/* 密码 */
			NET_DVR_TIME struStartTime;		/* 按时间回放的开始时间 */
			NET_DVR_TIME struStopTime;		/* 按时间回放的结束时间 */
		}timeInfo;
	}objectInfo;
}NET_DVR_DECCHANSTATUS, *LPNET_DVR_DECCHANSTATUS;

typedef struct 
{
	DWORD   dwSize;
	NET_DVR_DECCHANSTATUS struDecState[MAX_DECNUM];
}NET_DVR_DECSTATUS, *LPNET_DVR_DECSTATUS;
/*****************************DS-6001D/F(end)***************************/

//单字符参数(子结构)
typedef struct 
{
	WORD wShowString;				// 预览的图象上是否显示字符,0-不显示,1-显示 区域大小704*576,单个字符的大小为32*32
	WORD wStringSize;				/* 该行字符的长度，不能大于44个字符 */
	WORD wShowStringTopLeftX;		/* 字符显示位置的x坐标 */
	WORD wShowStringTopLeftY;		/* 字符名称显示位置的y坐标 */
	char sString[44];				/* 要显示的字符内容 */
}NET_DVR_SHOWSTRINGINFO, *LPNET_DVR_SHOWSTRINGINFO;

//叠加字符(9000扩展)
typedef struct 
{
	DWORD dwSize;
	NET_DVR_SHOWSTRINGINFO struStringInfo[MAX_STRINGNUM_V30];				/* 要显示的字符内容 */
}NET_DVR_SHOWSTRING_V30, *LPNET_DVR_SHOWSTRING_V30;

//叠加字符扩展(8条字符)
typedef struct 
{
	DWORD dwSize;
	NET_DVR_SHOWSTRINGINFO struStringInfo[MAX_STRINGNUM_EX];				/* 要显示的字符内容 */
}NET_DVR_SHOWSTRING_EX, *LPNET_DVR_SHOWSTRING_EX;

//叠加字符
typedef struct 
{
	DWORD dwSize;
	NET_DVR_SHOWSTRINGINFO struStringInfo[MAX_STRINGNUM];				/* 要显示的字符内容 */
}NET_DVR_SHOWSTRING, *LPNET_DVR_SHOWSTRING;

/****************************DS9000新增结构(begin)******************************/
/*
EMAIL参数结构
*/
typedef struct
{		
	DWORD		dwSize;
	BYTE		sAccount[NAME_LEN];				/* 账号*/ 
	BYTE		sPassword[MAX_EMAIL_PWD_LEN];			/*密码 */
	struct
	{
		BYTE	sName[NAME_LEN];				/* 发件人姓名 */
		BYTE	sAddress[MAX_EMAIL_ADDR_LEN];		/* 发件人地址 */
	}struSender;
	BYTE		sSmtpServer[MAX_EMAIL_ADDR_LEN];	/* smtp服务器 */
	BYTE		sPop3Server[MAX_EMAIL_ADDR_LEN];	/* pop3服务器 */
	struct
	{
		BYTE	sName[NAME_LEN];				/* 收件人姓名 */
		BYTE	sAddress[MAX_EMAIL_ADDR_LEN];		/* 收件人地址 */
	}struReceiver[3];							/* 最多可以设置3个收件人 */
	BYTE		byAttachment;					/* 是否带附件 */
	BYTE		bySmtpServerVerify;				/* 发送服务器要求身份验证 */
    BYTE        byMailInterval;                 /* mail interval */
	BYTE        byEnableSSL;					//ssl是否启用9000_1.1
	WORD        wSmtpPort;						//gmail的465，普通的为25     
	BYTE        byRes[74];						//保留
} NET_DVR_EMAILCFG_V30, *LPNET_DVR_EMAILCFG_V30;

/*
DVR实现巡航数据结构
*/
typedef struct
{	
	DWORD 	dwSize;
	BYTE	byPresetNo[CRUISE_MAX_PRESET_NUMS];		/* 预置点号 */
	BYTE 	byCruiseSpeed[CRUISE_MAX_PRESET_NUMS];	/* 巡航速度 */
	WORD	wDwellTime[CRUISE_MAX_PRESET_NUMS];		/* 停留时间 */
	BYTE	byEnableThisCruise;						/* 是否启用 */
	BYTE	res[15];
}NET_DVR_CRUISE_PARA, *LPNET_DVR_CRUISE_PARA; 
/****************************DS9000新增结构(end)******************************/

//时间点
typedef struct 
{
	DWORD dwMonth;		//月 0-11表示1-12个月
	DWORD dwWeekNo;		//第几周 0－第1周 1－第2周 2－第3周 3－第4周 4－最后一周
	DWORD dwWeekDate;	//星期几 0－星期日 1－星期一 2－星期二 3－星期三 4－星期四 5－星期五 6－星期六
	DWORD dwHour;		//小时	开始时间0－23 结束时间1－23
	DWORD dwMin;		//分	0－59
}NET_DVR_TIMEPOINT;

//夏令时参数
typedef struct 
{
	DWORD dwSize;
	DWORD dwZoneIndex; //应用层软件使用NET_DVR_NTPPARA 中的cTimeDifferenceH 或cTimeDifferenceM 来设置时区，此处用获取的值填充，不对用户提供输入编辑框
	BYTE byRes1[12];			//保留
	DWORD dwEnableDST;		//是否启用夏时制 0－不启用 1－启用
	BYTE byDSTBias;	//夏令时偏移值，30min, 60min, 90min, 120min, 以分钟计，传递原始数值
	BYTE byRes2[3];
	NET_DVR_TIMEPOINT struBeginPoint;	//夏时制开始时间
	NET_DVR_TIMEPOINT struEndPoint;	//夏时制停止时间
}NET_DVR_ZONEANDDST, *LPNET_DVR_ZONEANDDST;

//图片质量
typedef struct 
{
	/*注意：当图像压缩分辨率为VGA时，支持0=CIF, 1=QCIF, 2=D1抓图，
	当分辨率为3=UXGA(1600x1200), 4=SVGA(800x600), 5=HD720p(1280x720),6=VGA,7=XVGA, 8=HD900p
	仅支持当前分辨率的抓图*/

	/* 可以通过能力集获取
	   0-CIF，           1-QCIF，           2-D1，         3-UXGA(1600x1200), 4-SVGA(800x600),5-HD720p(1280x720)，
	   6-VGA，           7-XVGA，           8-HD900p，     9-HD1080，     10-2560*1920，
       11-1600*304，     12-2048*1536，     13-2448*2048,  14-2448*1200， 15-2448*800，
       16-XGA(1024*768), 17-SXGA(1280*1024),18-WD1(960*576/960*480),      19-1080i,      20-576*576，     
	   21-1536*1536,     22-1920*1920,      23-320*240,    24-720*720,    25-1024*768,
	   26-1280*1280,     27-1600*600,       28-2048*768,   0xff-Auto(使用当前码流分辨率)
	*/
	WORD	wPicSize;			
	WORD	wPicQuality;			/* 图片质量系数 0-最好 1-较好 2-一般 */
}NET_DVR_JPEGPARA, *LPNET_DVR_JPEGPARA;

/* aux video out parameter */
//辅助输出参数配置
typedef struct 
{
	DWORD dwSize;
	DWORD dwAlarmOutChan;                       /* 选择报警弹出大报警通道切换时间：1画面的输出通道: 0:主输出/1:辅1/2:辅2/3:辅3/4:辅4 */
	DWORD dwAlarmChanSwitchTime;                /* :1秒 - 10:10秒 */
	DWORD dwAuxSwitchTime[MAX_AUXOUT];			/* 辅助输出切换时间: 0-不切换,1-5s,2-10s,3-20s,4-30s,5-60s,6-120s,7-300s */
	BYTE  byAuxOrder[MAX_AUXOUT][MAX_WINDOW];	/* 辅助输出预览顺序, 0xff表示相应的窗口不预览 */
}NET_DVR_AUXOUTCFG, *LPNET_DVR_AUXOUTCFG;


//ntp
typedef struct 
{
	BYTE sNTPServer[64];   /* Domain Name or IP addr of NTP server */
	WORD wInterval;		 /* adjust time interval(hours) */
	BYTE byEnableNTP;    /* enable NPT client 0-no，1-yes*/
	signed char cTimeDifferenceH; /* 与国际标准时间的 小时偏移-12 ... +13 */
	signed char cTimeDifferenceM;/* 与国际标准时间的 分钟偏移0, 30, 45*/
	BYTE res1;
    WORD wNtpPort;         /* ntp server port 9000新增 设备默认为123*/
    BYTE res2[8];
}NET_DVR_NTPPARA, *LPNET_DVR_NTPPARA;

//ddns
typedef struct 
{
	BYTE sUsername[NAME_LEN];  /* DDNS账号用户名/密码 */
	BYTE sPassword[PASSWD_LEN];
	BYTE sDomainName[64];       /* 域名 */
	BYTE byEnableDDNS;			/*是否应用 0-否，1-是*/
	BYTE res[15];
}NET_DVR_DDNSPARA, *LPNET_DVR_DDNSPARA;


typedef struct
{
	BYTE byHostIndex;					/* 0-私有DDNS 1－Dyndns 2－PeanutHull(花生壳)*/
	BYTE byEnableDDNS;					/*是否应用DDNS 0-否，1-是*/
	WORD wDDNSPort;						/* DDNS端口号 */
	BYTE sUsername[NAME_LEN];			/* DDNS用户名*/
	BYTE sPassword[PASSWD_LEN];			/* DDNS密码 */
	BYTE sDomainName[MAX_DOMAIN_NAME];	/* 设备配备的域名地址 */
	BYTE sServerName[MAX_DOMAIN_NAME];	/* DDNS 对应的服务器地址，可以是IP地址或域名 */
	BYTE byRes[16];
}NET_DVR_DDNSPARA_EX, *LPNET_DVR_DDNSPARA_EX;

//9000扩展
typedef struct
{
    BYTE byEnableDDNS;
    BYTE byHostIndex;/*0-IPServer 1－Dyndns 2－PeanutHull(花生壳)，3- NO-IP, 4- hiDDNS*/
    BYTE byRes1[2];
    struct
    {    
        BYTE sUsername[NAME_LEN];			/* DDNS账号用户名*/
        BYTE sPassword[PASSWD_LEN];			/* 密码 */
        BYTE sDomainName[MAX_DOMAIN_NAME];	/* 设备配备的域名地址 */
        BYTE sServerName[MAX_DOMAIN_NAME];	/* DDNS协议对应的服务器地址，可以是IP地址或域名 */
        WORD wDDNSPort;						/* 端口号 */
        BYTE byRes[10];
    } struDDNS[MAX_DDNS_NUMS];
    BYTE byRes2[16];
}NET_DVR_DDNSPARA_V30, *LPNET_DVR_DDNSPARA_V30;

//email
typedef struct 
{
	BYTE sUsername[64];  /* 邮件账号/密码 */
	BYTE sPassword[64];
	BYTE sSmtpServer[64];
	BYTE sPop3Server[64];
	BYTE sMailAddr[64];   /* email */
	BYTE sEventMailAddr1[64];  /* 上传报警/异常等的email */
	BYTE sEventMailAddr2[64];
	BYTE res[16];
}NET_DVR_EMAILPARA, *LPNET_DVR_EMAILPARA;

//网络参数配置
typedef struct 
{
	DWORD  dwSize;
	char  sDNSIp[16];                /* DNS服务器地址 */
	NET_DVR_NTPPARA  struNtpClientParam;      /* NTP参数 */
	NET_DVR_DDNSPARA struDDNSClientParam;     /* DDNS参数 */
	BYTE res[464];			/* 保留 */
}NET_DVR_NETAPPCFG, *LPNET_DVR_NETAPPCFG;

//nfs结构配置
typedef struct
{
    char sNfsHostIPAddr[16];
    BYTE sNfsDirectory[PATHNAME_LEN];        // PATHNAME_LEN = 128
}NET_DVR_SINGLE_NFS, *LPNET_DVR_SINGLE_NFS;

typedef struct 
{
	DWORD  dwSize;
	NET_DVR_SINGLE_NFS struNfsDiskParam[MAX_NFS_DISK];
}NET_DVR_NFSCFG, *LPNET_DVR_NFSCFG;

typedef struct tagNET_DVR_ISCSI_CFG
{   
    DWORD dwSize;                   // 结构大小
    WORD wVrmPort;                  // VRM 监听端口
    BYTE byEnable;                  // 是否启用 ISCSI存储
    BYTE byRes[69];                 // 保留字节
    NET_DVR_IPADDR struVrmAddr;          // VRM ip地址 16位
    char chNvtIndexCode[64];        //nvt index Code 
}NET_DVR_ISCSI_CFG, *LPNET_DVR_ISCSI_CFG;  

//巡航点配置(私有IP快球专用)
typedef struct
{
    BYTE	PresetNum;	//预置点
    BYTE	Dwell;		//停留时间
    BYTE	Speed;		//速度
    BYTE	Reserve;	//保留
}NET_DVR_CRUISE_POINT, *LPNET_DVR_CRUISE_POINT;

typedef struct 
{
	NET_DVR_CRUISE_POINT struCruisePoint[32];			//最大支持32个巡航点
}NET_DVR_CRUISE_RET, *LPNET_DVR_CRUISE_RET;

/************************************多路解码器(begin)***************************************/
typedef struct 
{
	DWORD	dwSize;
	char	sFirstDNSIP[16];
	char	sSecondDNSIP[16];
	char	sRes[32];
}NET_DVR_NETCFG_OTHER, *LPNET_DVR_NETCFG_OTHER;

typedef struct 
{
	char 	sDVRIP[16];				/* DVR IP地址 */
	WORD 	wDVRPort;			 	/* 端口号 */
	BYTE 	byChannel;				/* 通道号 */
	BYTE	byTransProtocol;			/* 传输协议类型 0-TCP, 1-UDP */
	BYTE	byTransMode;				/* 传输码流模式 0－主码流 1－子码流*/
	BYTE	byRes[3];
	BYTE	sUserName[NAME_LEN];			/* 监控主机登陆帐号 */
	BYTE	sPassword[PASSWD_LEN];			/* 监控主机密码 */
}NET_DVR_MATRIX_DECINFO, *LPNET_DVR_MATRIX_DECINFO;

//启动/停止动态解码
typedef struct 
{
	DWORD	dwSize;				
	NET_DVR_MATRIX_DECINFO struDecChanInfo;		/* 动态解码通道信息 */
}NET_DVR_MATRIX_DYNAMIC_DEC, *LPNET_DVR_MATRIX_DYNAMIC_DEC;

typedef struct  
{
    DWORD 	dwSize;
    DWORD   dwIsLinked;         /* 解码通道状态 0－休眠 1－正在连接 2－已连接 3-正在解码 */
    DWORD   dwStreamCpRate;     /* Stream copy rate, X kbits/second */
    char    cRes[64];		/* 保留 */
}NET_DVR_MATRIX_DEC_CHAN_STATUS, *LPNET_DVR_MATRIX_DEC_CHAN_STATUS;

typedef struct 
{
	DWORD	dwSize;
	NET_DVR_MATRIX_DECINFO struDecChanInfo;		/* 解码通道信息 */
	DWORD	dwDecState;	/* 0-动态解码 1－循环解码 2－按时间回放 3－按文件回放 */
	NET_DVR_TIME StartTime;		/* 按时间回放开始时间 */
	NET_DVR_TIME StopTime;		/* 按时间回放停止时间 */
	char    sFileName[128];		/* 按文件回放文件名 */
}NET_DVR_MATRIX_DEC_CHAN_INFO, *LPNET_DVR_MATRIX_DEC_CHAN_INFO;

//连接的通道配置 2007-11-05
typedef struct 
{
	DWORD dwEnable;					/* 是否启用 0－否 1－启用*/
	NET_DVR_MATRIX_DECINFO struDecChanInfo;		/* 轮巡解码通道信息 */
}NET_DVR_MATRIX_DECCHANINFO, *LPNET_DVR_MATRIX_DECCHANINFO;

//2007-11-05 新增每个解码通道的配置
typedef struct 
{
	DWORD	dwSize;
	DWORD	dwPoolTime;			/*轮巡时间 */
	NET_DVR_MATRIX_DECCHANINFO struchanConInfo[MAX_CYCLE_CHAN];
}NET_DVR_MATRIX_LOOP_DECINFO, *LPNET_DVR_MATRIX_LOOP_DECINFO;

//2007-12-22
typedef struct 
{
	BYTE	baudrate; 	/* 波特率 */
	BYTE	databits;		/* 数据位 */
	BYTE	stopbits;		/* 停止位 */
	BYTE	parity;		/* 奇偶校验位 */
	BYTE	flowcontrol;	/* 流控 */
	BYTE	res[3];
}TTY_CONFIG, *LPTTY_CONFIG;

typedef struct  
{					
	BYTE byTranChanEnable;	/* 当前透明通道是否打开 0：关闭 1：打开 */	
	/*
	 *	多路解码器本地有1个485串口，1个232串口都可以作为透明通道,设备号分配如下：
	 *	0 RS485
	 *	1 RS232 Console
	 */
	BYTE	byLocalSerialDevice;			/* Local serial device */
	/*
	 *	远程串口输出还是两个,一个RS232，一个RS485
	 *	1表示232串口
	 *	2表示485串口
	 */
	BYTE	byRemoteSerialDevice;			/* Remote output serial device */
	BYTE	res1;							/* 保留 */
	char	sRemoteDevIP[16];				/* Remote Device IP */
	WORD	wRemoteDevPort;				/* Remote Net Communication Port */
	BYTE	res2[2];						/* 保留 */
	TTY_CONFIG RemoteSerialDevCfg;
}NET_DVR_MATRIX_TRAN_CHAN_INFO, *LPNET_DVR_MATRIX_TRAN_CHAN_INFO;

typedef struct  
{
	DWORD dwSize;
	BYTE 	by232IsDualChan; /* 设置哪路232透明通道是全双工的 取值1到MAX_SERIAL_NUM */
	BYTE	by485IsDualChan; /* 设置哪路485透明通道是全双工的 取值1到MAX_SERIAL_NUM */
	BYTE	res[2];	/* 保留 */
	NET_DVR_MATRIX_TRAN_CHAN_INFO struTranInfo[MAX_SERIAL_NUM];/*同时支持建立MAX_SERIAL_NUM个透明通道*/
}NET_DVR_MATRIX_TRAN_CHAN_CONFIG, *LPNET_DVR_MATRIX_TRAN_CHAN_CONFIG;

//2007-12-24 Merry Christmas Eve...
typedef struct 
{
	DWORD	dwSize;
	char	sDVRIP[16];		/* DVR IP地址 */	
	WORD	wDVRPort;			/* 端口号 */	
	BYTE	byChannel;			/* 通道号 */
	BYTE 	byReserve;
	BYTE	sUserName[NAME_LEN];		/* 用户名 */
	BYTE	sPassword[PASSWD_LEN];		/* 密码 */
	DWORD	dwPlayMode;   	/* 0－按文件 1－按时间*/        	
	NET_DVR_TIME StartTime;
	NET_DVR_TIME StopTime;
	char    sFileName[128];
}NET_DVR_MATRIX_DEC_REMOTE_PLAY, *LPNET_DVR_MATRIX_DEC_REMOTE_PLAY;

/* 文件播放命令 */
#define NET_DVR_PLAYSTART		1//开始播放
#define NET_DVR_PLAYSTOP		2//停止播放
#define NET_DVR_PLAYPAUSE		3//暂停播放
#define NET_DVR_PLAYRESTART		4//恢复播放
#define NET_DVR_PLAYFAST		5//快放
#define NET_DVR_PLAYSLOW		6//慢放
#define NET_DVR_PLAYNORMAL		7//正常速度
#define NET_DVR_PLAYSTARTAUDIO	9//打开声音
#define NET_DVR_PLAYSTOPAUDIO	10//关闭声音
#define NET_DVR_PLAYSETPOS		12//改变文件回放的进度

typedef struct 
{
	DWORD	dwSize;
	DWORD	dwPlayCmd;		/* 播放命令 见文件播放命令*/
	DWORD	dwCmdParam;		/* 播放命令参数 */
}NET_DVR_MATRIX_DEC_REMOTE_PLAY_CONTROL, *LPNET_DVR_MATRIX_DEC_REMOTE_PLAY_CONTROL;

typedef struct  
{
	DWORD dwSize;
	DWORD dwCurMediaFileLen;		/* 当前播放的媒体文件长度 */       
	DWORD dwCurMediaFilePosition;	/* 当前播放文件的播放位置 */        
	DWORD dwCurMediaFileDuration;	/* 当前播放文件的总时间 */        
	DWORD dwCurPlayTime;			/* 当前已经播放的时间 */        
	DWORD dwCurMediaFIleFrames;		/* 当前播放文件的总帧数 */        
	DWORD dwCurDataType;			/* 当前传输的数据类型，19-文件头，20-流数据， 21-播放结束标志 */        
	BYTE res[72];	
}NET_DVR_MATRIX_DEC_REMOTE_PLAY_STATUS, *LPNET_DVR_MATRIX_DEC_REMOTE_PLAY_STATUS;

//2009-4-11 added by likui 多路解码器new
typedef struct tagNET_MATRIX_PASSIVEMODE
{
    WORD	wTransProtol;		//传输协议，0-TCP, 1-UDP, 2-MCAST
    WORD	wPassivePort;		//UDP端口, TCP时默认
    NET_DVR_IPADDR  struMcastIP;	//TCP,UDP时无效, MCAST时为多播地址
    BYTE	byStreamType;/* 数据播放模式:REAL_TIME_STREAM(1)实时流,RECORD_STREAM(2)文件流 */
    BYTE	byRes[7];
}NET_DVR_MATRIX_PASSIVEMODE, *LPNET_DVR_MATRIX_PASSIVEMODE;

typedef struct tagMATRIX_TRAN_CHAN_INFO 
{					
	BYTE byTranChanEnable;	/* 当前透明通道是否打开 0：关闭 1：打开 */	
    /*
	 *	多路解码器本地有1个485串口，1个232串口都可以作为透明通道,设备号分配如下：
	 *	0 RS485
	 *	1 RS232 Console
	 */
	BYTE	byLocalSerialDevice;			/* Local serial device */
    /*
	 *	远程串口输出还是两个,一个RS232，一个RS485
	 *	1表示232串口
	 *	2表示485串口
	 */
	BYTE	byRemoteSerialDevice;			/* Remote output serial device */
	BYTE	byRes1;							/* 保留 */		
    NET_DVR_IPADDR  struRemoteDevIP;/* Remote Device IP */
	WORD    wRemoteDevPort;				/* Remote Net Communication Port */
    BYTE    byIsEstablished;			/* 透明通道建立成功标志，0-没有成功，1-建立成功 */
    BYTE	byRes2;						/* 保留 */
	TTY_CONFIG RemoteSerialDevCfg;
	BYTE  	byUsername[NAME_LEN]; 		/* 32BYTES */
	BYTE   	byPassword[PASSWD_LEN]; 		/* 16BYTES */
	BYTE 	byRes3[16];
} NET_DVR_MATRIX_TRAN_CHAN_INFO_V30,*LPNET_DVR_MATRIX_TRAN_CHAN_INFO_V30;

typedef struct tagMATRIX_TRAN_CHAN_CONFIG 
{
	DWORD   dwSize;
	BYTE 	by232IsDualChan; /* 设置哪路232透明通道是全双工的 取值1到MAX_SERIAL_NUM */
	BYTE	by485IsDualChan; /* 设置哪路485透明通道是全双工的 取值1到MAX_SERIAL_NUM */
	BYTE	vyRes[2];	/* 保留 */
	NET_DVR_MATRIX_TRAN_CHAN_INFO_V30 struTranInfo[MAX_SERIAL_NUM];/*同时支持建立MAX_SERIAL_NUM个透明通道*/
}NET_DVR_MATRIX_TRAN_CHAN_CONFIG_V30,*LPNET_DVR_MATRIX_TRAN_CHAN_CONFIG_V30;

typedef struct  
{
    DWORD								dwEnable;	/* 是否启用 0－否 1－启用*/
    NET_DVR_STREAM_MEDIA_SERVER_CFG	streamMediaServerCfg;	
    NET_DVR_DEV_CHAN_INFO 		struDevChanInfo;		/* 轮巡解码通道信息 */
}NET_DVR_MATRIX_CHAN_INFO_V30,*LPNET_DVR_CYC_SUR_CHAN_ELE_V30;

typedef struct  tagMATRIX_LOOP_DECINFO_V30
{
    DWORD							dwSize;
    DWORD							dwPoolTime;		/*轮巡间隔*/
    NET_DVR_MATRIX_CHAN_INFO_V30	struchanConInfo[MAX_CYCLE_CHAN_V30];
    BYTE               				byRes[16];
} NET_DVR_MATRIX_LOOP_DECINFO_V30,*LPNET_DVR_MATRIX_LOOP_DECINFO_V30;


typedef struct tagDEC_MATRIX_CHAN_INFO_V30
{
    DWORD	dwSize;
    NET_DVR_STREAM_MEDIA_SERVER_CFG streamMediaServerCfg;	/*流媒体服务器配置*/
    NET_DVR_DEV_CHAN_INFO 			  struDevChanInfo;		/* 解码通道信息 */
    DWORD	dwDecState;		/* 0-动态解码 1－循环解码 2－按时间回放 3－按文件回放 */
    NET_DVR_TIME StartTime;		/* 按时间回放开始时间 */
    NET_DVR_TIME StopTime;		/* 按时间回放停止时间 */
    char    sFileName[128];		/* 按文件回放文件名 */
    DWORD   dwGetStreamMode;	/*取流模式:1-主动，2-被动*/
    NET_DVR_MATRIX_PASSIVEMODE      struPassiveMode;
    BYTE	byRes[32];
}NET_DVR_MATRIX_DEC_CHAN_INFO_V30,*LPNET_DVR_MATRIX_DEC_CHAN_INFO_V30;

#define MAX_RESOLUTIONNUM    64 //支持的最大分辨率数目
typedef struct tagNET_DVR_MATRIX_ABILITY
{
    DWORD dwSize;
    BYTE  byDecNums;
    BYTE  byStartChan;
    BYTE  byVGANums;
    BYTE  byBNCNums;
    BYTE  byVGAWindowMode[8][12];     /*VGA支持的窗口模式，VGA1可能由混合输出*/
    BYTE  byBNCWindowMode[4];       	/*BNC支持的窗口模式*/
    BYTE  byDspNums;   
    BYTE  byHDMINums;//HDMI显示通道个数（从25开始）
    BYTE  byDVINums;//DVI显示通道个数（从29开始）
	BYTE  byRes1[13];
	BYTE  bySupportResolution[MAX_RESOLUTIONNUM];//按照上面的枚举定义,一个字节代表一个分辨率是//否支持，1：支持，0：不支持
	BYTE  byHDMIWindowMode[4][8];//HDMI支持的窗口模式
	BYTE  byDVIWindowMode[4][8];//DVI支持的窗口模式
	BYTE  byRes2[24];
}NET_DVR_MATRIX_ABILITY, *LPNET_DVR_MATRIX_ABILITY;
//上传logo结构
typedef struct tagNET_DVR_DISP_LOGOCFG
{
    DWORD		dwCorordinateX;	//图片显示区域X坐标
    DWORD		dwCorordinateY;	//图片显示区域Y坐标
	WORD        wPicWidth; //图片宽
	WORD        wPicHeight; //图片高
    BYTE        byRes1[4];
    BYTE        byFlash;  //是否闪烁1-闪烁，0-不闪烁
    BYTE        byTranslucent; //是否半透明1-半透明，0-不半透明
    BYTE		byRes2[6];				//保留
    DWORD		dwLogoSize;//LOGO大小，包括BMP的文件头
}NET_DVR_DISP_LOGOCFG,*LPNET_DVR_DISP_LOGOCFG;

/*编码类型*/
#define NET_DVR_ENCODER_UNKOWN 0 /*未知编码格式*/
#define NET_DVR_ENCODER_H264   1 /*私有 264*/
#define NET_DVR_ENCODER_S264   2 /*Standard H264*/
#define NET_DVR_ENCODER_MPEG4  3 /*MPEG4*/
#define NET_DVR_ORIGINALSTREAM 4 /*Original Stream*/
#define NET_DVR_PICTURE		   5/*Picture*/
#define NET_DVR_ENCODER_MJPEG  6
#define NET_DVR_ECONDER_MPEG2  7
/* 打包格式 */
#define NET_DVR_STREAM_TYPE_UNKOWN   0     /*未知打包格式*/
#define NET_DVR_STREAM_TYPE_PRIVT    1     /*私有格式*/
#define NET_DVR_STREAM_TYPE_TS       7   /* TS打包 */
#define NET_DVR_STREAM_TYPE_PS       8   /* PS打包 */
#define NET_DVR_STREAM_TYPE_RTP      9    /* RTP打包 */
#define NET_DVR_STREAM_TYPE_ORIGIN   10 //未打包(视频综合平台解码子系统用)

/*解码通道状态*/
typedef struct
{
    BYTE  byDecodeStatus; /*当前状态:0:未启动，1：启动解码*/
    BYTE  byStreamType;    /*码流类型*/
    BYTE  byPacketType;     /*打包方式*/
    BYTE  byRecvBufUsage; /*接收缓冲使用率*/
    BYTE  byDecBufUsage; /*解码缓冲使用率*/
    BYTE  byFpsDecV; /*视频解码帧率*/
    BYTE  byFpsDecA; /*音频解码帧率*/
    BYTE  byCpuLoad;     /*DSP CPU使用率*/ 
    BYTE  byRes1[4];    
    DWORD dwDecodedV; /*解码的视频帧*/
    DWORD dwDecodedA; /*解码的音频帧*/
    WORD wImgW; /*解码器当前的图像大小,宽*/
    WORD wImgH; //高
    BYTE byVideoFormat; /*视频制式:0-NON,NTSC--1,PAL--2*/
    BYTE  byRes2[3];
    DWORD  dwDecChan;       /*获取全部解码通道状态时有效，设置时可填0*/
    BYTE  byRes3[20]; 
}NET_DVR_MATRIX_CHAN_STATUS, *LPNET_DVR_MATRIX_CHAN_STATUS;

/*显示通道状态*/
#define NET_DVR_MAX_DISPREGION 16         /*每个显示通道最多可以显示的窗口*/
//分辨率
//
typedef enum
{
	/*VGA*/
    VGA_NOT_AVALIABLE,
    VGA_THS8200_MODE_SVGA_60HZ,    //(800*600)
    VGA_THS8200_MODE_SVGA_75HZ,    //(800*600)
    VGA_THS8200_MODE_XGA_60HZ,     //(1024*768)
    VGA_THS8200_MODE_XGA_75HZ,     //(1024*768)
    VGA_THS8200_MODE_SXGA_60HZ,    //(1280*1024)
    VGA_THS8200_MODE_720P_60HZ,    //(1280*720)
    VGA_THS8200_MODE_1080I_60HZ,   //(1920*1080)
    VGA_THS8200_MODE_1080P_30HZ,   //(1920*1080)
    VGA_THS8200_MODE_UXGA_30HZ,    //(1600*1200)
	/*HDMI*/	
	HDMI_SII9134_MODE_XGA_60HZ,	   //(1024*768)
	HDMI_SII9134_MODE_SXGA_60HZ,   //(1280*1024)
	HDMI_SII9134_MODE_SXGA2_60HZ,  //(1280*960)
	HDMI_SII9134_MODE_720P_60HZ,   //(1280*720)	
	HDMI_SII9134_MODE_720P_50HZ,   //(1280*720)		
	HDMI_SII9134_MODE_1080I_60HZ,  //(1920*1080)
	HDMI_SII9134_MODE_1080I_50HZ,  //(1920*1080)	
	HDMI_SII9134_MODE_1080P_25HZ,  //(1920*1080)
	HDMI_SII9134_MODE_1080P_30HZ,  //(1920*1080)
	HDMI_SII9134_MODE_1080P_50HZ,  //(1920*1080)
	HDMI_SII9134_MODE_1080P_60HZ,  //(1920*1080)
	HDMI_SII9134_MODE_UXGA_60HZ,   //(1600*1200)
	/*DVI*/	
	DVI_SII9134_MODE_XGA_60HZ,	   //(1024*768)
	DVI_SII9134_MODE_SXGA_60HZ,	   //(1280*1024)
	DVI_SII9134_MODE_SXGA2_60HZ,   //(1280*960)
	DVI_SII9134_MODE_720P_60HZ,	   //(1280*720)	
	DVI_SII9134_MODE_720P_50HZ,    //(1280*720)		
	DVI_SII9134_MODE_1080I_60HZ,   //(1920*1080)
	DVI_SII9134_MODE_1080I_50HZ,   //(1920*1080)
	DVI_SII9134_MODE_1080P_25HZ,   //(1920*1080)
	DVI_SII9134_MODE_1080P_30HZ,   //(1920*1080)
	DVI_SII9134_MODE_1080P_50HZ,   //(1920*1080)
	DVI_SII9134_MODE_1080P_60HZ,   //(1920*1080)
	DVI_SII9134_MODE_UXGA_60HZ,     //(1600*1200)
    VGA_DECSVR_MODE_SXGA2_60HZ,
    HDMI_DECSVR_MODE_1080P_24HZ,
    DVI_DECSVR_MODE_1080P_24HZ,
    YPbPr_DECSVR_MODE_720P_60HZ,
	YPbPr_DECSVR_MODE_1080I_60HZ
}VGA_MODE;

//低帧率定义
#define           LOW_DEC_FPS_1_2                51
#define           LOW_DEC_FPS_1_4                52
#define           LOW_DEC_FPS_1_8                53
#define           LOW_DEC_FPS_1_16               54

/*视频制式标准*/
typedef enum
{
    VS_NON = 0,
    VS_NTSC = 1,
    VS_PAL = 2
}VIDEO_STANDARD;

typedef struct tagNET_DVR_VGA_DISP_CHAN_CFG
{        
    DWORD	dwSize; 
    BYTE	byAudio;			/*音频是否开启,0-否，1-是*/
    BYTE    byAudioWindowIdx;      /*音频开启子窗口*/
    BYTE 	byVgaResolution;      /*VGA的分辨率*/
    BYTE	byVedioFormat;         /*1:NTSC,2:PAL,0-NULL*/
    DWORD	dwWindowMode;		/*画面模式,从能力集获取,目前支持1,2,4,9,16*/       
    BYTE	byJoinDecChan[MAX_WINDOWS];/*各个子窗口关联的解码通道*/
    BYTE	byEnlargeStatus;          /*是否处于放大状态，0：不放大，1：放大*/
    BYTE    byEnlargeSubWindowIndex;//放大的子窗口号
	union
	{
		BYTE byRes[16];
		struct
		{
			/*各个子窗口对应解码通道所对应的解码子系统的槽位号(对于视频综合平台中解码子系统有效)*/
			BYTE	 byJoinDecoderId[MAX_WINDOWS];
		}struVideoPlatform;
		struct
		{
			BYTE	 byRes[16];
		}struNotVideoPlatform;
	}struDiff;
	/*区分共用体，0-视频综合平台内部解码器显示通道配置，1-其他解码器显示通道配置*/
	BYTE		byUnionType;
	BYTE		byScale; /*显示模式，0---真实显示，1---缩放显示( 针对BNC )*/
}NET_DVR_VGA_DISP_CHAN_CFG,*LPNET_DVR_VGA_DISP_CHAN_CFG;


/*显示通道状态*/
#define NET_DVR_MAX_DISPREGION 16 /*每个显示通道最多可以显示的窗口*/
typedef struct
{
    BYTE  byDispStatus;          /*显示状态：0：未显示，1：启动显示*/
    BYTE  byBVGA;                /*0-BNC，1-VGA， 2-HDMI，3-DVI*/
    BYTE  byVideoFormat;        /*视频制式:1:NTSC,2:PAL,0-NON*/
    BYTE  byWindowMode;        /*当前画面模式*/
    BYTE  byJoinDecChan[MAX_WINDOWS];        /*各个子窗口关联的解码通道*/
    BYTE  byFpsDisp[NET_DVR_MAX_DISPREGION]; /*每个子画面的显示帧率*/
    BYTE  byScreenMode;			//屏幕模式0-普通 1-大屏
    BYTE  byRes2[31];
}NET_DVR_DISP_CHAN_STATUS, *LPNET_DVR_DISP_CHAN_STATUS;

#define MAX_DECODECHANNUM   32//多路解码器最大解码通道数
#define MAX_DISPCHANNUM   24//多路解码器最大显示通道数

/*解码器设备状态*/
typedef struct tagNET_DVR_DECODER_WORK_STATUS
{
    DWORD dwSize;
    NET_DVR_MATRIX_CHAN_STATUS struDecChanStatus[MAX_DECODECHANNUM]; /*解码通道状态*/
    NET_DVR_DISP_CHAN_STATUS   struDispChanStatus[MAX_DISPCHANNUM];  /*显示通道状态*/
    BYTE byAlarmInStatus[MAX_ANALOG_ALARMIN];         /*报警输入状态*/
    BYTE byAlarmOutStatus[MAX_ANALOG_ALARMOUT];       /*报警输出状态*/
    BYTE byAudioInChanStatus;          /*语音对讲状态*/
    BYTE byRes[127];
}NET_DVR_DECODER_WORK_STATUS,*LPNET_DVR_DECODER_WORK_STATUS;

//2009-12-1 增加被动解码播放控制
typedef struct tagNET_DVR_PASSIVEDECODE_CONTROL
{
    DWORD	dwSize;
    DWORD	dwPlayCmd;		/* 播放命令 见文件播放命令*/
    DWORD	dwCmdParam;		/* 播放命令参数 */
    BYTE	byRes[16];//Reverse
}NET_DVR_PASSIVEDECODE_CONTROL,*LPNET_DVR_PASSIVEDECODE_CONTROL;

#define		PASSIVE_DEC_PAUSE			1	/*被动解码暂停(仅文件流有效)*/
#define		PASSIVE_DEC_RESUME			2	/*恢复被动解码(仅文件流有效)*/
#define 	PASSIVE_DEC_FAST          	3   /*快速被动解码(仅文件流有效)*/
#define 	PASSIVE_DEC_SLOW			4   /*慢速被动解码(仅文件流有效)*/
#define 	PASSIVE_DEC_NORMAL      	5   /*正常被动解码(仅文件流有效)*/
#define 	PASSIVE_DEC_ONEBYONE      	6  /*被动解码单帧播放(保留)*/
#define 	PASSIVE_DEC_AUDIO_ON 		7   /*音频开启*/
#define 	PASSIVE_DEC_AUDIO_OFF		8  	 /*音频关闭*/
#define		PASSIVE_DEC_RESETBUFFER	    9    /*清空缓冲区*/
//2009-12-16 增加控制解码器解码通道缩放
typedef struct tagNET_DVR_MATRIX_DECCHAN_CONTROL
{        
	DWORD	dwSize;
	BYTE	byDecChanScaleStatus;/*解码通道显示缩放控制,1表示缩放显示，0表示真实显示*/
    BYTE    byDecodeDelay;//解码延时，0-默认，1-实时性好，2-实时性较好，3-实时性中，流畅性中，4-流畅性较好，5-流畅性好，0xff-自动调整   
    BYTE    byRes[66];	
}NET_DVR_MATRIX_DECCHAN_CONTROL,*LPNET_DVR_MATRIX_DECCHAN_CONTROL;

/************************************多路解码器(end)***************************************/
//2009-8-19 视频综合平台接口函数
/************************************视频综合平台(begin)***************************************/
#define MAX_SUBSYSTEM_NUM	80   //一个矩阵系统中最多子系统数量
#define MAX_SERIALLEN		36  //最大序列号长度
#define MAX_LOOPPLANNUM		16//最大计划切换组
#define DECODE_TIMESEGMENT 4//计划解码每天时间段数
typedef struct tagNET_DVR_SUBSYSTEMINFO
{
    BYTE		bySubSystemType;//子系统类型，1-解码用子系统，2-编码用子系统，3-级联输出子系统，4-级联输入子系统，5-码分器子系统，6-报警主机子系统，7-智能子系统，0-NULL（此参数只能获取）		
    BYTE		byChan;//子系统通道数，对于码分子系统，代表485串口数量（此参数只能获取）					
    BYTE		byLoginType;//注册类型，1-直连，2-DNS，3-花生壳
    BYTE		byRes1[5];
    NET_DVR_IPADDR   struSubSystemIP;		/*IP地址（可修改）*/
    WORD		wSubSystemPort;        //子系统端口号（可修改）
    BYTE		byRes2[6];
    NET_DVR_IPADDR  struSubSystemIPMask;//子网掩码
    NET_DVR_IPADDR	struGatewayIpAddr;	/* 网关地址*/   
    BYTE		sUserName[NAME_LEN];	/* 用户名 （此参数只能获取）*/
    BYTE		sPassword[PASSWD_LEN];	/*密码（此参数只能获取）*/
    char		sDomainName[MAX_DOMAIN_NAME];//域名(可修改)
    char 		sDnsAddress[MAX_DOMAIN_NAME];/*DNS域名或IP地址*/
    BYTE		sSerialNumber[SERIALNO_LEN];//序列号（此参数只能获取）
}NET_DVR_SUBSYSTEMINFO, *LPNET_DVR_SUBSYSTEMINFO;

typedef struct tagNET_DVR_ALLSUBSYSTEMINFO
{
    DWORD dwSize;
    NET_DVR_SUBSYSTEMINFO struSubSystemInfo[MAX_SUBSYSTEM_NUM];
    BYTE byRes[8];
}NET_DVR_ALLSUBSYSTEMINFO, *LPNET_DVR_ALLSUBSYSTEMINFO;

typedef struct  tagNET_DVR_LOOPPLAN_SUBCFG
{
    DWORD 						    dwSize;
    DWORD							dwPoolTime;		/*轮巡间隔，单位：秒*/      
    NET_DVR_MATRIX_CHAN_INFO_V30 struChanConInfo[MAX_CYCLE_CHAN_V30];
    BYTE               				byRes[16];
}NET_DVR_LOOPPLAN_SUBCFG,*LPNET_DVR_LOOPPLAN_SUBCFG;

typedef struct tagNET_DVR_ALARMMODECFG
{
    DWORD 	dwSize;
    BYTE	byAlarmMode;//报警触发类型，1-轮巡，2-保持		
    WORD	wLoopTime;//轮巡时间, 单位：秒			
    BYTE    byRes[9];
}NET_DVR_ALARMMODECFG,*LPNET_DVR_ALARMMODECFG;

typedef struct  tagNET_DVR_CODESPLITTERINFO
{
    DWORD			dwSize;
    NET_DVR_IPADDR   struIP;		/*码分器IP地址*/
    WORD		wPort;        			//码分器端口号
    BYTE		byRes1[6];
    BYTE		sUserName[NAME_LEN];	/* 用户名 */
    BYTE		sPassword[PASSWD_LEN];	/*密码 */
    BYTE        byChan;//码分器485号
    BYTE		by485Port;//485口地址
    BYTE		byRes2[14];
} NET_DVR_CODESPLITTERINFO, *LPNET_DVR_CODESPLITTERINFO;

typedef struct tagNET_DVR_ASSOCIATECFG
{
    BYTE	byAssociateType;//关联类型，1-报警
    WORD	wAlarmDelay;//报警延时，0－5秒；1－10秒；2－30秒；3－1分钟；4－2分钟；5－5分钟；6－10分钟；
    BYTE	byAlarmNum;//报警号，具体的值由应用赋，相同的报警赋相同的值
    BYTE	byRes[8];
} NET_DVR_ASSOCIATECFG,*LPNET_DVR_ASSOCIATECFG;

typedef struct tagNET_DVR_DYNAMICDECODE
{
    DWORD						    dwSize;
    NET_DVR_ASSOCIATECFG   		struAssociateCfg;//触发动态解码关联结构
    NET_DVR_PU_STREAM_CFG		struPuStreamCfg;//动态解码结构
    BYTE							byRes[8];
}NET_DVR_DYNAMICDECODE,*LPNET_DVR_DYNAMICDECODE;

typedef struct  tagNET_DVR_DECODESCHED
{
	NET_DVR_SCHEDTIME  struSchedTime;//
    BYTE  byDecodeType;/*0-无，1-轮巡解码，2-动态解码*/
	BYTE  byLoopGroup;//轮巡组号
	BYTE  byRes[6];
	NET_DVR_PU_STREAM_CFG struDynamicDec;//动态解码
} NET_DVR_DECODESCHED, *LPNET_DVR_DECODESCHED;

typedef struct tagNET_DVR_PLANDECODE
{
	DWORD dwSize;
	NET_DVR_DECODESCHED struDecodeSched[MAX_DAYS][DECODE_TIMESEGMENT];//周一作为开始，和9000一致
	BYTE byRes[8];
} NET_DVR_PLANDECODE,*LPNET_DVR_PLANDECODE;

//end
/************************************视频综合平台(end)***************************************/
typedef struct 
{	/* 12 bytes */
	DWORD	dwSize;
	char	sUserName[32];
	char 	sPassWord[32];
	char 	sFromName[32];			/* Sender *///字符串中的第一个字符和最后一个字符不能是"@",并且字符串中要有"@"字符
	char 	sFromAddr[48];			/* Sender address */
	char 	sToName1[32];			/* Receiver1 */
	char 	sToName2[32];			/* Receiver2 */
	char 	sToAddr1[48];			/* Receiver address1 */
	char 	sToAddr2[48];			/* Receiver address2 */
	char	sEmailServer[32];		/* Email server address */
	BYTE	byServerType;			/* Email server type: 0-SMTP, 1-POP, 2-IMTP…*/
	BYTE	byUseAuthen;			/* Email server authentication method: 1-enable, 0-disable */
	BYTE	byAttachment;			/* enable attachment */
	BYTE	byMailinterval;			/* mail interval 0-2s, 1-3s, 2-4s. 3-5s*/
} NET_DVR_EMAILCFG, *LPNET_DVR_EMAILCFG;

typedef struct 
{
	DWORD dwSize;
	NET_DVR_COMPRESSION_INFO_EX  struLowCompression;	//定时录像
	NET_DVR_COMPRESSION_INFO_EX  struEventCompression;	//事件触发录像
}NET_DVR_COMPRESSIONCFG_NEW, *LPNET_DVR_COMPRESSIONCFG_NEW;

//球机位置信息
typedef struct
{
    WORD wAction;//获取时该字段无效
    WORD wPanPos;//水平参数
    WORD wTiltPos;//垂直参数
    WORD wZoomPos;//变倍参数
}NET_DVR_PTZPOS, *LPNET_DVR_PTZPOS;

//球机范围信息
typedef struct
{
    WORD wPanPosMin;//水平参数min
    WORD wPanPosMax;//水平参数max
    WORD wTiltPosMin;//垂直参数min
    WORD wTiltPosMax;//垂直参数max
    WORD wZoomPosMin;//变倍参数min
    WORD wZoomPosMax;//变倍参数max
}NET_DVR_PTZSCOPE, *LPNET_DVR_PTZSCOPE;

//rtsp配置 ipcamera专用
typedef struct
{
    DWORD dwSize;         //长度
    WORD  wPort;          //rtsp服务器侦听端口
    BYTE  byReserve[54];  //预留
}NET_DVR_RTSPCFG, *LPNET_DVR_RTSPCFG;

/********************************接口参数结构(begin)*********************************/

//NET_DVR_Login()参数结构
typedef struct
{
	BYTE sSerialNumber[SERIALNO_LEN];   //序列号
	BYTE byAlarmInPortNum;		        //DVR报警输入个数
	BYTE byAlarmOutPortNum;		        //DVR报警输出个数
	BYTE byDiskNum;				        //DVR硬盘个数
	BYTE byDVRType;				        //DVR类型, 1:DVR 2:ATM DVR 3:DVS ......
	BYTE byChanNum;				        //DVR 通道个数
	BYTE byStartChan;			        //起始通道号,例如DVS-1,DVR - 1
}NET_DVR_DEVICEINFO, *LPNET_DVR_DEVICEINFO;

//NET_DVR_Login_V30()参数结构
typedef struct
{
    BYTE sSerialNumber[SERIALNO_LEN];  //序列号
    BYTE byAlarmInPortNum;		        //报警输入个数
    BYTE byAlarmOutPortNum;		        //报警输出个数
    BYTE byDiskNum;				    //硬盘个数
    BYTE byDVRType;				    //设备类型, 1:DVR 2:ATM DVR 3:DVS ......
    BYTE byChanNum;				    //模拟通道个数
    BYTE byStartChan;			        //起始通道号,例如DVS-1,DVR - 1
    BYTE byAudioChanNum;                //语音通道数
    BYTE byIPChanNum;					//最大数字通道个数，低位  
	BYTE byZeroChanNum;			//零通道编码个数 //2010-01-16
	BYTE byMainProto;			//主码流传输协议类型 0-private, 1-rtsp,2-同时支持private和rtsp
	BYTE bySubProto;				//子码流传输协议类型0-private, 1-rtsp,2-同时支持private和rtsp
    BYTE bySupport;        //能力，位与结果为0表示不支持，1表示支持，
    //bySupport & 0x1, 表示是否支持智能搜索
    //bySupport & 0x2, 表示是否支持备份
    //bySupport & 0x4, 表示是否支持压缩参数能力获取
    //bySupport & 0x8, 表示是否支持多网卡
    //bySupport & 0x10, 表示支持远程SADP
    //bySupport & 0x20, 表示支持Raid卡功能
    //bySupport & 0x40, 表示支持IPSAN 目录查找
	//bySupport & 0x80, 表示支持rtp over rtsp
    BYTE bySupport1;        // 能力集扩充，位与结果为0表示不支持，1表示支持
	//bySupport1 & 0x1, 表示是否支持snmp v30
	//bySupport1 & 0x2, 支持区分回放和下载
	//bySupport1 & 0x4, 是否支持布防优先级	
	//bySupport1 & 0x8, 智能设备是否支持布防时间段扩展
	//bySupport1 & 0x10, 表示是否支持多磁盘数（超过33个）
	//bySupport1 & 0x20, 表示是否支持rtsp over http	
	//bySupport1 & 0x80, 表示是否支持车牌新报警信息2012-9-28, 且还表示是否支持NET_DVR_IPPARACFG_V40结构体
    BYTE bySupport2; /*能力，位与结果为0表示不支持，非0表示支持							
							bySupport2 & 0x1, 表示解码器是否支持通过URL取流解码
							bySupport2 & 0x2,  表示支持FTPV40
							bySupport2 & 0x4,  表示支持ANR
							bySupport2 & 0x8,  表示支持CCD的通道参数配置
							bySupport2 & 0x10,  表示支持布防报警回传信息（仅支持抓拍机报警 新老报警结构）
							bySupport2 & 0x20,  表示是否支持单独获取设备状态子项
							bySupport2 & 0x40,  表示是否是码流加密设备*/
	WORD wDevType;              //设备型号
	BYTE bySupport3; //能力集扩展，位与结果为0表示不支持，1表示支持
							//bySupport3 & 0x1, 表示是否多码流
							// bySupport3 & 0x4 表示支持按组配置， 具体包含 通道图像参数、报警输入参数、IP报警输入、输出接入参数、
                            // 用户参数、设备工作状态、JPEG抓图、定时和时间抓图、硬盘盘组管理 
							//bySupport3 & 0x8为1 表示支持使用TCP预览、UDP预览、多播预览中的"延时预览"字段来请求延时预览（后续都将使用这种方式请求延时预览）。而当bySupport3 & 0x8为0时，将使用 "私有延时预览"协议。
							//bySupport3 & 0x10 表示支持"获取报警主机主要状态（V40）"。
							//bySupport3 & 0x20 表示是否支持通过DDNS域名解析取流

	BYTE byMultiStreamProto;//是否支持多码流,按位表示,0-不支持,1-支持,bit1-码流3,bit2-码流4,bit7-主码流，bit-8子码流
	BYTE byStartDChan;		//起始数字通道号,0表示无效
	BYTE byStartDTalkChan;	//起始数字对讲通道号，区别于模拟对讲通道号，0表示无效
	BYTE byHighDChanNum;		//数字通道个数，高位
	BYTE bySupport4;
	BYTE byLanguageType;// 支持语种能力,按位表示,每一位0-不支持,1-支持  
						//  byLanguageType 等于0 表示 老设备
						//  byLanguageType & 0x1表示支持中文
						//  byLanguageType & 0x2表示支持英文
	BYTE byRes2[9];		//保留
}NET_DVR_DEVICEINFO_V30, *LPNET_DVR_DEVICEINFO_V30;

typedef void (CALLBACK *fLoginResultCallBack) (LONG lUserID, DWORD dwResult, LPNET_DVR_DEVICEINFO_V30 lpDeviceInfo , void* pUser);

#define NET_DVR_DEV_ADDRESS_MAX_LEN 129
#define NET_DVR_LOGIN_USERNAME_MAX_LEN 64
#define NET_DVR_LOGIN_PASSWD_MAX_LEN 64


typedef struct  
{
	char sDeviceAddress[NET_DVR_DEV_ADDRESS_MAX_LEN];
	BYTE byRes1;
	WORD wPort;
	char sUserName[NET_DVR_LOGIN_USERNAME_MAX_LEN];
	char sPassword[NET_DVR_LOGIN_PASSWD_MAX_LEN];
	fLoginResultCallBack cbLoginResult;
	void *pUser;
	BOOL bUseAsynLogin;
	BYTE byRes2[128];
}NET_DVR_USER_LOGIN_INFO,*LPNET_DVR_USER_LOGIN_INFO;

//sdk网络环境枚举变量，用于远程升级
typedef enum _SDK_NET_ENV
{
    LOCAL_AREA_NETWORK = 0,
        WIDE_AREA_NETWORK
}SDK_NETWORK_ENVIRONMENT;

//显示模式
typedef enum
{
	NORMALMODE = 0,
	OVERLAYMODE
}DISPLAY_MODE;

//发送模式
typedef enum
{
	PTOPTCPMODE = 0,
	PTOPUDPMODE,
	MULTIMODE,
	RTPMODE,
	RESERVEDMODE
}SEND_MODE;

//抓图模式
typedef enum 
{
	BMP_MODE = 0,		//BMP模式
	JPEG_MODE = 1		//JPEG模式 
}CAPTURE_MODE;

//实时声音模式
typedef enum
{
	MONOPOLIZE_MODE = 1,//独占模式
	SHARE_MODE = 2		//共享模式
}REALSOUND_MODE;

//软解码预览参数
typedef struct
{
	LONG lChannel;//通道号
	LONG lLinkMode;//最高位(31)为0表示主码流，为1表示子，0－30位表示码流连接方式: 0：TCP方式,1：UDP方式,2：多播方式,3 - RTP方式，4-RTP/RTSP,5-RSTP/HTTP 
	HWND hPlayWnd;//播放窗口的句柄,为NULL表示不播放图象
	char* sMultiCastIP;//多播组地址
	BYTE byProtoType; //应用层取流协议，0-私有协议，1-RTSP协议
	BYTE byRes[3];
}NET_DVR_CLIENTINFO, *LPNET_DVR_CLIENTINFO;

//SDK状态信息(9000新增)
typedef struct 
{
    DWORD dwTotalLoginNum;		//当前login用户数
    DWORD dwTotalRealPlayNum;	//当前realplay路数
    DWORD dwTotalPlayBackNum;	//当前回放或下载路数
    DWORD dwTotalAlarmChanNum;	//当前建立报警通道路数
    DWORD dwTotalFormatNum;		//当前硬盘格式化路数
    DWORD dwTotalFileSearchNum;	//当前日志或文件搜索路数
    DWORD dwTotalLogSearchNum;	//当前日志或文件搜索路数
    DWORD dwTotalSerialNum;	    //当前透明通道路数
    DWORD dwTotalUpgradeNum;	//当前升级路数
    DWORD dwTotalVoiceComNum;	//当前语音转发路数
    DWORD dwTotalBroadCastNum;	//当前语音广播路数
    DWORD dwTotalListenNum;	    //当前网络监听路数
    DWORD dwEmailTestNum;       //当前邮件计数路数
    DWORD dwBackupNum;          // 当前文件备份路数
	DWORD dwTotalInquestUploadNum; //当前审讯上传路数
    DWORD dwRes[6];
}NET_DVR_SDKSTATE, *LPNET_DVR_SDKSTATE;

//SDK功能支持信息(9000新增)
typedef struct 
{
    DWORD dwMaxLoginNum;		//最大login用户数 MAX_LOGIN_USERS
    DWORD dwMaxRealPlayNum;		//最大realplay路数 WATCH_NUM
    DWORD dwMaxPlayBackNum;		//最大回放或下载路数 WATCH_NUM
    DWORD dwMaxAlarmChanNum;	//最大建立报警通道路数 ALARM_NUM
    DWORD dwMaxFormatNum;		//最大硬盘格式化路数 SERVER_NUM
    DWORD dwMaxFileSearchNum;	//最大文件搜索路数 SERVER_NUM
    DWORD dwMaxLogSearchNum;	//最大日志搜索路数 SERVER_NUM
    DWORD dwMaxSerialNum;	    //最大透明通道路数 SERVER_NUM
    DWORD dwMaxUpgradeNum;	    //最大升级路数 SERVER_NUM
    DWORD dwMaxVoiceComNum;		//最大语音转发路数 SERVER_NUM
    DWORD dwMaxBroadCastNum;	//最大语音广播路数 MAX_CASTNUM
    DWORD dwRes[10];
}NET_DVR_SDKABL, *LPNET_DVR_SDKABL;

//报警设备信息
typedef struct
{   
    BYTE byUserIDValid;                 /* userid是否有效 0-无效，1-有效 */
    BYTE bySerialValid;                 /* 序列号是否有效 0-无效，1-有效 */
    BYTE byVersionValid;                /* 版本号是否有效 0-无效，1-有效 */
    BYTE byDeviceNameValid;             /* 设备名字是否有效 0-无效，1-有效 */
    BYTE byMacAddrValid;                /* MAC地址是否有效 0-无效，1-有效 */    
    BYTE byLinkPortValid;               /* login端口是否有效 0-无效，1-有效 */
    BYTE byDeviceIPValid;               /* 设备IP是否有效 0-无效，1-有效 */
    BYTE bySocketIPValid;               /* socket ip是否有效 0-无效，1-有效 */
    LONG lUserID;                       /* NET_DVR_Login()返回值, 布防时有效 */
    BYTE sSerialNumber[SERIALNO_LEN];	/* 序列号 */
    DWORD dwDeviceVersion;			    /* 版本信息 高16位表示主版本，低16位表示次版本*/
    char sDeviceName[NAME_LEN];		    /* 设备名字 */
    BYTE byMacAddr[MACADDR_LEN];		/* MAC地址 */    
    WORD wLinkPort;                     /* link port */
    char sDeviceIP[128];    			/* IP地址 */
    char sSocketIP[128];    			/* 报警主动上传时的socket IP地址 */
    BYTE byIpProtocol;                  /* Ip协议 0-IPV4, 1-IPV6 */
    BYTE byRes2[11];
}NET_DVR_ALARMER, *LPNET_DVR_ALARMER;

//硬解码显示区域参数(子结构)
typedef struct
{
	long bToScreen;
	long bToVideoOut;
	long nLeft;
	long nTop;
	long nWidth;
	long nHeight;
	long nReserved;
}NET_DVR_DISPLAY_PARA, *LPNET_DVR_DISPLAY_PARA;

//硬解码预览参数
typedef struct
{
	LONG lChannel;//通道号
	LONG lLinkMode; //最高位(31)为0表示主码流，为1表示子，0－30位表示码流连接方式:0：TCP方式,1：UDP方式,2：多播方式,3 - RTP方式，4-电话线，5－128k宽带，6－256k宽带，7－384k宽带，8－512k宽带；
	char* sMultiCastIP;
	NET_DVR_DISPLAY_PARA struDisplayPara;
}NET_DVR_CARDINFO, *LPNET_DVR_CARDINFO;

//录象文件参数
typedef struct 
{
	char sFileName[100];//文件名
	NET_DVR_TIME struStartTime;//文件的开始时间
	NET_DVR_TIME struStopTime;//文件的结束时间
	DWORD dwFileSize;//文件的大小
}NET_DVR_FIND_DATA, *LPNET_DVR_FIND_DATA;

//录象文件参数(9000)
typedef struct 
{
    char sFileName[100];//文件名
    NET_DVR_TIME struStartTime;//文件的开始时间
    NET_DVR_TIME struStopTime;//文件的结束时间
    DWORD dwFileSize;//文件的大小
    char sCardNum[32];
    BYTE byLocked;//9000设备支持,1表示此文件已经被锁定,0表示正常的文件
	BYTE byFileType;  //文件类型:0－定时录像,1-移动侦测 ，2－报警触发，
	//3-报警|移动侦测 4-报警&移动侦测 5-命令触发 6-手动录像,7－震动报警，8-环境报警，9-智能报警，10-PIR报警，11-无线报警，12-呼救报警,14-智能交通事件
    BYTE byRes[2];
}NET_DVR_FINDDATA_V30, *LPNET_DVR_FINDDATA_V30;

//录象文件参数(cvr)
typedef struct 
{
    char sFileName[100];//文件名
    NET_DVR_TIME struStartTime;//文件的开始时间
    NET_DVR_TIME struStopTime;//文件的结束时间
    DWORD dwFileSize;//文件的大小
    char sCardNum[32];
    BYTE byLocked;//9000设备支持,1表示此文件已经被锁定,0表示正常的文件
	BYTE byFileType;  //文件类型:0－定时录像,1-移动侦测 ，2－报警触发，
	//3-报警|移动侦测 4-报警&移动侦测 5-命令触发 6-手动录像,7－震动报警，8-环境报警，9-智能报警，10-PIR报警，11-无线报警，12-呼救报警,14-智能交通事件
    BYTE byQuickSearch; //0:普通查询结果，1：快速（日历）查询结果
	BYTE byRes;
	DWORD dwFileIndex; //文件索引号
    BYTE byRes1[128];	
}NET_DVR_FINDDATA_V40, *LPNET_DVR_FINDDATA_V40;

//录象文件参数(带卡号)
typedef struct 
{
	char sFileName[100];//文件名
	NET_DVR_TIME struStartTime;//文件的开始时间
	NET_DVR_TIME struStopTime;//文件的结束时间
	DWORD dwFileSize;//文件的大小
	char sCardNum[32];
}NET_DVR_FINDDATA_CARD, *LPNET_DVR_FINDDATA_CARD;


//录象文件查找条件结构
typedef struct 
{
    LONG lChannel;//通道号
    DWORD dwFileType;//录象文件类型
	   //不带卡号，0xff－全部，0－定时录像,1-移动侦测 ，2－报警触发，3-报警|移动侦测 4-报警&移动侦测 5-命令触发 6-手动录像,7-智能录像，10-PIR报警，11-无线报警，12-呼救报警，13-移动|报警输入|PIR|无线报警|呼救报警，14-智能交通事件
	 //带卡号，0xff－全部，0－定时录像，1-移动侦测，2－接近报警，3－出钞报警，4－进钞报警，5-命令触发，6－手动录像，7－震动报警，8-环境报警，9-智能报警，10-PIR报警，11-无线报警，12-呼救报警，13-移动|报警输入|PIR|无线报警|呼救报警，14-智能交通事件
    DWORD dwIsLocked;//是否锁定 0-正常文件,1-锁定文件, 0xff表示所有文件
    DWORD dwUseCardNo;//是否使用卡号
    BYTE sCardNumber[32];//卡号
    NET_DVR_TIME struStartTime;//开始时间
    NET_DVR_TIME struStopTime;//结束时间
}NET_DVR_FILECOND, *LPNET_DVR_FILECOND;

//云台区域选择放大缩小(私有 快球专用)
typedef struct 
{
	int xTop;     //方框起始点的x坐标
	int yTop;     //方框结束点的y坐标
	int xBottom;  //方框结束点的x坐标
	int yBottom;  //方框结束点的y坐标
	int bCounter; //保留
}NET_DVR_POINT_FRAME, *LPNET_DVR_POINT_FRAME;

//语音对讲参数
typedef struct tagNET_DVR_COMPRESSION_AUDIO
{
	BYTE  byAudioEncType;   //音频编码类型 0-OggVorbis;1-G711_U;2-G711_A;5-MP2L2;6-G726;7-AAC
	BYTE  byres[7];//这里保留音频的压缩参数 
}NET_DVR_COMPRESSION_AUDIO, *LPNET_DVR_COMPRESSION_AUDIO;

//2009-7-22


#define IW_ESSID_MAX_SIZE						 32
#define WIFI_WEP_MAX_KEY_COUNT					 4
#define WIFI_WEP_MAX_KEY_LENGTH					 33
#define WIFI_WPA_PSK_MAX_KEY_LENGTH				 63
#define WIFI_WPA_PSK_MIN_KEY_LENGTH				 8
#define WIFI_MAX_AP_COUNT						 20

typedef struct tagNET_DVR_AP_INFO
{
	char  sSsid[IW_ESSID_MAX_SIZE];
	DWORD  dwMode;						/* 0 mange 模式;1 ad-hoc模式，参见NICMODE */
	DWORD  dwSecurity;           /*0 不加密；1 wep加密；2 wpa-psk;3 wpa-Enterprise;4-WPA2_PSK参见WIFISECURITY*/
	DWORD  dwChannel;            /*1-11表示11个通道*/
	DWORD  dwSignalStrength;    /*0-100信号由最弱变为最强*/
	DWORD  dwSpeed;               /*速率,单位是0.01mbps*/
}NET_DVR_AP_INFO,*LPNET_DVR_AP_INFO;

typedef struct tagNET_DVR_AP_INFO_LIST
{
	DWORD dwSize;
	DWORD dwCount;        /*无线AP数量，不超过20*/
	NET_DVR_AP_INFO struApInfo[WIFI_MAX_AP_COUNT];
}NET_DVR_AP_INFO_LIST,*LPNET_DVR_AP_INFO_LIST;

typedef struct tagNET_DVR_WIFIETHERNET
{	
	char sIpAddress[16];				/*IP地址*/
	char sIpMask[16];					/*掩码*/	
	BYTE	byMACAddr[MACADDR_LEN];		/*物理地址，只用来显示*/
	BYTE	bRes[2];
	DWORD	dwEnableDhcp;				/*是否启动dhcp  0不启动 1启动*/
	DWORD	dwAutoDns;					/*如果启动dhcp是否自动获取dns,0不自动获取 1自动获取；对于有线如果启动dhcp目前自动获取dns*/	
	char sFirstDns[16];						 /*第一个dns域名*/
	char sSecondDns[16];					 /*第二个dns域名*/
	char sGatewayIpAddr[16]; 				/* 网关地址*/
	BYTE   bRes2[8];
}NET_DVR_WIFIETHERNET,*LPNET_DVR_WIFIETHERNET;

typedef struct tagNET_DVR_WIFI_CFG_EX
{
	NET_DVR_WIFIETHERNET struEtherNet;        /*wifi网口*/
	char sEssid[IW_ESSID_MAX_SIZE];	 /*SSID*/
	DWORD dwMode;      /* 0 mange 模式;1 ad-hoc模式，参见*/
	DWORD dwSecurity; /*0-不加密;1-WEP加密;2-WPA-personal; 3-WPA-enterprise;4-WPA2-personal;5-WPA2-enterprise */
	union 
	{
		struct 
		{
			DWORD dwAuthentication;/*0 -开放式 1-共享式*/
			DWORD dwKeyLength;/* 0 -64位；1- 128位；2-152位*/
			DWORD dwKeyType;/*0 16进制;1 ASCI */
			DWORD dwActive;/*0 索引：0---3表示用哪一个密钥*/
			char sKeyInfo[WIFI_WEP_MAX_KEY_COUNT][WIFI_WEP_MAX_KEY_LENGTH];
		}wep;
		struct 
		{
			DWORD dwKeyLength;/*8-63个ASCII字符*/
			char sKeyInfo[WIFI_WPA_PSK_MAX_KEY_LENGTH];
			BYTE byEncryptType;  /*WPA/WPA2模式下加密类型,0-AES, 1-TKIP*/
		}wpa_psk;
		struct 
		{
            BYTE byEncryptType;  /*加密类型,0-AES, 1-TKIP*/
			BYTE byAuthType; //认证类型，0-EAP_TTLS,1-EAP_PEAP,2-EAP_TLS
            BYTE byRes[2];
			union
            {
				struct 
				{
                    BYTE byEapolVersion; //EAPOL版本，0-版本1，1-版本2
                    BYTE byAuthType; //内部认证方式，0-PAP，1-MSCHAPV2
                    BYTE byRes1[2];
                    BYTE byAnonyIdentity [NAME_LEN]; //匿名身份
					BYTE byUserName[NAME_LEN]; //用户名
                    BYTE byPassword[NAME_LEN]; //密码
                    BYTE byRes[44];
				}EAP_TTLS; //WPA-enterprise/WPA2-enterpris模式适用
				struct 
				{
                    BYTE byEapolVersion; //EAPOL版本，0-版本1，1-版本2
                    BYTE byAuthType; //内部认证方式，0-GTC，1-MD5，2-MSCHAPV2
                    BYTE byPeapVersion; //PEAP版本，0-版本0，1-版本1
                    BYTE byPeapLabel; //PEAP标签，0-老标签，1-新标签
                    BYTE byAnonyIdentity[NAME_LEN]; //匿名身份
					BYTE byUserName[NAME_LEN]; //用户名
					BYTE byPassword[NAME_LEN]; //密码
                    BYTE byRes[44]; 
				}EAP_PEAP; //WPA-enterprise/WPA2-enterpris模式适用
				struct 
				{
                    BYTE byEapolVersion; //EAPOL版本，0-版本1，1-版本2
                    BYTE byRes1[3]; 
                    BYTE byIdentity[NAME_LEN]; //身份
					BYTE byPrivateKeyPswd[NAME_LEN]; //私钥密码
                    BYTE byRes[76]; 
				}EAP_TLS; 
            }auth_param;
		}wpa_wpa2; //WPA-enterprise/WPA2-enterpris模式适用
	}key;	
}NET_DVR_WIFI_CFG_EX,*LPNET_DVR_WIFI_CFG_EX;

//wifi配置结构
typedef struct tagNET_DVR_WIFI_CFG
{
	DWORD dwSize;
	NET_DVR_WIFI_CFG_EX struWifiCfg;
}NET_DVR_WIFI_CFG,*LPNET_DVR_WIFI_CFG;

//wifi连接状态
typedef	 struct  tagNET_DVR_WIFI_CONNECT_STATUS
{
	DWORD		dwSize;
	BYTE		byCurStatus;	//1-已连接，2-未连接，3-正在连接
	BYTE		byRes1[3];		//保留
	DWORD		dwErrorCode;	// byCurStatus = 2时有效,1-用户名或密码错误,2-无此路由器,3-未知错误
	BYTE		byRes[244];
}NET_DVR_WIFI_CONNECT_STATUS,*LPNET_DVR_WIFI_CONNECT_STATUS;

//wifi工作模式
typedef struct tagNET_DVR_WIFI_WORKMODE
{
	DWORD dwSize;
	DWORD dwNetworkInterfaceMode; /*0 自动切换模式　1 有线模式*/
}NET_DVR_WIFI_WORKMODE,*LPNET_DVR_WIFI_WORKMODE;

//结构参数宏定义 
#define VCA_MAX_POLYGON_POINT_NUM		10		//检测区域最多支持10个点的多边形
#define MAX_RULE_NUM					8		//最多规则条数
#define MAX_TARGET_NUM    				30		//最多目标个数
#define MAX_CALIB_PT 					6		//最大标定点个数
#define MIN_CALIB_PT 					4		//最小标定点个数
#define MAX_TIMESEGMENT_2	    		2		//最大时间段数
#define MAX_LICENSE_LEN					16		//车牌号最大长度
#define MAX_PLATE_NUM					3		//车牌个数
#define MAX_MASK_REGION_NUM				4       //最多四个屏蔽区域
#define MAX_SEGMENT_NUM					6        //摄像机标定最大样本线数目
#define MIN_SEGMENT_NUM					3        //摄像机标定最小样本线数目


//智能控制信息
#define MAX_VCA_CHAN  16//最大智能通道数
typedef struct tagNET_VCA_CTRLINFO
{
	BYTE   byVCAEnable;		//是否开启智能
	BYTE   byVCAType;	    //智能能力类型，VCA_CHAN_ABILITY_TYPE 
	BYTE   byStreamWithVCA; //码流中是否带智能信息
    BYTE   byMode;			//模式，ATM能力时参照VCA_CHAN_MODE_TYPE ,TFS能力时参照TFS_CHAN_MODE_TYPE
	BYTE   byControlType;   //控制类型，按位表示，0-否，1-是
	                        // byControlType &1 是否启用抓拍功能
	BYTE   byRes[3]; 		//保留，设置为0 
}NET_VCA_CTRLINFO, * LPNET_VCA_CTRLINFO;

//智能控制信息结构
typedef struct tagNET_VCA_CTRLCFG
{
	DWORD dwSize;
	NET_VCA_CTRLINFO  struCtrlInfo[MAX_VCA_CHAN]; 	//控制信息,数组0对应设备的起始通道
	BYTE byRes[16];
}NET_VCA_CTRLCFG, * LPNET_VCA_CTRLCFG;

//智能设备能力集
typedef struct tagNET_VCA_DEV_ABILITY
{
	DWORD dwSize;              //结构长度
	BYTE byVCAChanNum;         //智能通道个数
	BYTE byPlateChanNum;       //车牌通道个数
	BYTE byBBaseChanNum;       //行为基本版个数
	BYTE byBAdvanceChanNum;    //行为高级版个数
	BYTE byBFullChanNum;       //行为完整版个数
	BYTE byATMChanNum;		   //智能ATM个数
    BYTE byPDCChanNum;         //人数统计通道个数
    BYTE byITSChanNum;         //交通事件通道个数
    BYTE byBPrisonChanNum;     //行为监狱版(监舍)通道个数
	BYTE byFSnapChanNum;       //人脸抓拍通道个数
	BYTE byFSnapRecogChanNum;  //人脸抓拍和识别通道个数
	BYTE byFRetrievalChanNum;  //人脸后检索个数
	BYTE bySupport;            //能力，位与结果为0表示不支持，1表示支持
                               //bySupport & 0x1，表示是否支持智能跟踪 2012-3-22
                               //bySupport & 0x2，表示是否支持128路取流扩展2012-12-27
	BYTE byFRecogChanNum;      //人脸识别通道个数
	BYTE byBPPerimeterChanNum; //行为监狱版(周界)通道个数
	BYTE byTPSChanNum;         //交通诱导通道个数
    BYTE byTFSChanNum;         //道路违章取证通道个数
	BYTE byFSnapBFullChanNum;  //人脸抓拍和行为分析通道个数
	BYTE byRes[22];
}NET_VCA_DEV_ABILITY, *LPNET_VCA_DEV_ABILITY;


//行为分析能力类型
typedef enum _VCA_ABILITY_TYPE_
{
    TRAVERSE_PLANE_ABILITY      = 0x01,       //穿越警戒面
    ENTER_AREA_ABILITY          = 0x02,       //进入区域
    EXIT_AREA_ABILITY           = 0x04,       //离开区域
    INTRUSION_ABILITY           = 0x08,       //入侵
    LOITER_ABILITY              = 0x10,       //徘徊
    LEFT_TAKE_ABILITY           = 0x20,       //物品遗留拿取
    PARKING_ABILITY             = 0x40,       //停车
    RUN_ABILITY                 = 0x80,       //快速移动
    HIGH_DENSITY_ABILITY        = 0x100,      //人员聚集
    LF_TRACK_ABILITY			= 0x200,      //球机跟踪
    VIOLENT_MOTION_ABILITY		= 0x400,      //剧烈运动检测
    REACH_HIGHT_ABILITY			= 0x800,      //攀高检测
    GET_UP_ABILITY				= 0x1000,     //起身检测
    LEFT_ABILITY                = 0x2000,     //物品遗留
    TAKE_ABILITY                = 0x4000,     //物品拿取
    LEAVE_POSITION              = 0x8000,     //离岗
    TRAIL_ABILITY               = 0x10000,    //尾随 
    KEY_PERSON_GET_UP_ABILITY   = 0x20000,    //重点人员起身检测
    FALL_DOWN_ABILITY           = 0x80000,    //倒地
    AUDIO_ABNORMAL_ABILITY      = 0x100000,   //声强突变
    ADV_REACH_HEIGHT_ABILITY    = 0x200000,   //折线攀高
    TOILET_TARRY_ABILITY        = 0x400000,   //如厕超时
    YARD_TARRY_ABILITY          = 0x800000,   //放风场滞留
    ADV_TRAVERSE_PLANE_ABILITY  = 0x1000000,  //折线警戒面
    HUMAN_ENTER_ABILITY         = 0x10000000, //人靠近ATM ,只在ATM_PANEL模式下支持
    OVER_TIME_ABILITY           = 0x20000000, //操作超时,只在ATM_PANEL模式下支持
    STICK_UP_ABILITY            = 0x40000000, //贴纸条
    INSTALL_SCANNER_ABILITY     = 0x80000000  //安装读卡器
}VCA_ABILITY_TYPE;

//智能通道类型
typedef enum _VCA_CHAN_ABILITY_TYPE_
{
	VCA_BEHAVIOR_BASE     =  1,          //行为分析基本版
	VCA_BEHAVIOR_ADVANCE  =  2,          //行为分析高级版
	VCA_BEHAVIOR_FULL     =  3,          //行为分析完整版
    VCA_PLATE     		  =  4,          //车牌能力
	VCA_ATM               =  5,          //ATM能力
    VCA_PDC               =  6,          //人流量统计
    VCA_ITS               =  7,          //智能 交通事件
    VCA_BEHAVIOR_PRISON   =  8,          //行为分析监狱版(监舍) 
	VCA_FACE_SNAP         = 9,           //人脸抓拍能力
	VCA_FACE_SNAPRECOG    = 10,          //人脸抓拍和识别能力
	VCA_FACE_RETRIEVAL    = 11,          //人脸后检索能力
	VCA_FACE_RECOG        = 12,          //人脸识别能力
	VCA_BEHAVIOR_PRISON_PERIMETER =  13, // 行为分析监狱版 (周界)
	VCA_TPS               = 14,          //交通诱导
	VCA_TFS               = 15,          //道路违章取证
	VCA_BEHAVIOR_FACESNAP = 16           //人脸抓拍和行为分析能力
}VCA_CHAN_ABILITY_TYPE;

//智能ATM模式类型(ATM能力特有)
typedef enum _VCA_CHAN_MODE_TYPE_
{
    VCA_ATM_PANEL     =  0, //ATM面板
    VCA_ATM_SURROUND  =  1,  //ATM环境
    VCA_ATM_FACE		= 2	//ATM人脸
}VCA_CHAN_MODE_TYPE;

//交通取证TFS通道模式(TFS能力特有)
typedef enum _TFS_CHAN_MODE_TYPE_
{
    TFS_CITYROAD    =  0,  //TFS 城市道路
    TFS_FREEWAY     =  1   //TFS 高速道路
}TFS_CHAN_MODE_TYPE;

//行为分析场景模式
typedef enum _BEHAVIOR_SCENE_MODE_TYPE_
{
    BEHAVIOR_SCENE_DEFAULT = 0, //系统默认
    BEHAVIOR_SCENE_WALL = 1,    //围墙
    BEHAVIOR_SCENE_INDOOR = 2   //室内
}BEHAVIOR_SCENE_MODE_TYPE;

//通道能力输入参数
typedef struct tagNET_VCA_CHAN_IN_PARAM
{
	BYTE byVCAType;	    //VCA_CHAN_ABILITY_TYPE枚举值
	BYTE byMode;		//模式，ATM 能力时参照VCA_CHAN_MODE_TYPE,TFS能力时参照TFS_CHAN_MODE_TYPE,当VCA_TYPE 为交通事件时参照TRAFFIC_SCENE_MODE
	BYTE byRes[2]; 	    //保留，设置为0 
}NET_VCA_CHAN_IN_PARAM, *LPNET_VCA_CHAN_IN_PARAM;


//行为能力集结构
typedef struct tagNET_VCA_BEHAVIOR_ABILITY
{
	DWORD dwSize;		 //结构长度
	DWORD dwAbilityType; //支持的能力类型，按位表示，见VCA_ABILITY_TYPE定义
	BYTE  byMaxRuleNum;	 //最大规则数
	BYTE  byMaxTargetNum; //最大目标数
    BYTE  bySupport;		// 支持的功能类型   按位表示  
                            // bySupport & 0x01 支持标定功能
    BYTE byRes[9];        //保留，设置为0
}NET_VCA_BEHAVIOR_ABILITY, *LPNET_VCA_BEHAVIOR_ABILITY;

// 交通能力集结构
typedef struct tagNET_DVR_ITS_ABILITY
{
    DWORD 	dwSize;             // 结构体大小
    DWORD 	dwAbilityType;      // 支持的能力列表  参照ITS_ABILITY_TYPE
	BYTE 	byMaxRuleNum;	 	//最大规则数
	BYTE 	byMaxTargetNum; 	//最大目标数
   	BYTE	byRes[10];		    // 保留
}NET_DVR_ITS_ABILITY, *LPNET_DVR_ITS_ABILITY;

/***********************************end*******************************************/

/************************************智能参数结构*********************************/
//智能共用结构
//坐标值归一化,浮点数值为当前画面的百分比大小, 精度为小数点后三位
//点坐标结构
typedef struct tagNET_VCA_POINT
{	
	float fX;								// X轴坐标, 0.001~1
	float fY;								//Y轴坐标, 0.001~1
}NET_VCA_POINT, *LPNET_VCA_POINT;

//区域框结构
typedef struct tagNET_VCA_RECT
{
	float fX;               //边界框左上角点的X轴坐标, 0.001~1
	float fY;               //边界框左上角点的Y轴坐标, 0.001~1
	float fWidth;           //边界框的宽度, 0.001~1
	float fHeight;          //边界框的高度, 0.001~1
}NET_VCA_RECT, *LPNET_VCA_RECT;

//行为分析事件类型
typedef enum _VCA_EVENT_TYPE_
{
    VCA_TRAVERSE_PLANE     = 0x1,        //穿越警戒面
    VCA_ENTER_AREA         = 0x2,        //目标进入区域,支持区域规则
    VCA_EXIT_AREA		   = 0x4,        //目标离开区域,支持区域规则
    VCA_INTRUSION          = 0x8,        //周界入侵,支持区域规则
    VCA_LOITER             = 0x10,       //徘徊,支持区域规则
    VCA_LEFT_TAKE          = 0x20,       //物品遗留拿取,支持区域规则
    VCA_PARKING	           = 0x40,       //停车,支持区域规则
    VCA_RUN	               = 0x80,       //快速移动,支持区域规则
    VCA_HIGH_DENSITY       = 0x100,      //区域内人员聚集,支持区域规则
    VCA_VIOLENT_MOTION     = 0x200,		 //剧烈运动检测
    VCA_REACH_HIGHT        = 0x400,		 //攀高检测
    VCA_GET_UP             = 0x800,	     //起身检测
    VCA_LEFT               = 0x1000,     //物品遗留
    VCA_TAKE               = 0x2000,     //物品拿取
    VCA_LEAVE_POSITION     = 0x4000,     //离岗
    VCA_TRAIL              = 0x8000,     //尾随
    VCA_KEY_PERSON_GET_UP  = 0x10000,    //重点人员起身检测
    VCA_FALL_DOWN          = 0x80000,    //倒地检测
    VCA_AUDIO_ABNORMAL     = 0x100000,   //声强突变检测
    VCA_ADV_REACH_HEIGHT   = 0x200000,   //折线攀高
    VCA_TOILET_TARRY       = 0x400000,   //如厕超时
    VCA_YARD_TARRY         = 0x800000,   //放风场滞留
    VCA_ADV_TRAVERSE_PLANE = 0x1000000,  //折线警戒面
    VCA_HUMAN_ENTER        = 0x10000000, //人靠近ATM           只在ATM_PANEL模式下支持
    VCA_OVER_TIME          = 0x20000000, //操作超时            只在ATM_PANEL模式下支持
    VCA_STICK_UP           = 0x40000000, //贴纸条,支持区域规则
    VCA_INSTALL_SCANNER    = 0x80000000  //安装读卡器,支持区域规则
}VCA_EVENT_TYPE;

//行为分析事件类型扩展
typedef enum _VCA_RULE_EVENT_TYPE_EX_
{
    ENUM_VCA_EVENT_TRAVERSE_PLANE     = 1,   //穿越警戒面
    ENUM_VCA_EVENT_ENTER_AREA         = 2,   //目标进入区域,支持区域规则
    ENUM_VCA_EVENT_EXIT_AREA          = 3,   //目标离开区域,支持区域规则
    ENUM_VCA_EVENT_INTRUSION          = 4,   //周界入侵,支持区域规则
    ENUM_VCA_EVENT_LOITER             = 5,   //徘徊,支持区域规则
    ENUM_VCA_EVENT_LEFT_TAKE          = 6,   //物品遗留拿取,支持区域规则
    ENUM_VCA_EVENT_PARKING            = 7,   //停车,支持区域规则
    ENUM_VCA_EVENT_RUN                = 8,   //快速移动,支持区域规则
    ENUM_VCA_EVENT_HIGH_DENSITY       = 9,   //区域内人员聚集,支持区域规则
    ENUM_VCA_EVENT_VIOLENT_MOTION     = 10,  //剧烈运动检测
    ENUM_VCA_EVENT_REACH_HIGHT        = 11,  //攀高检测
    ENUM_VCA_EVENT_GET_UP             = 12,  //起身检测
    ENUM_VCA_EVENT_LEFT               = 13,  //物品遗留
    ENUM_VCA_EVENT_TAKE               = 14,  //物品拿取
    ENUM_VCA_EVENT_LEAVE_POSITION     = 15,  //离岗
    ENUM_VCA_EVENT_TRAIL              = 16,  //尾随
    ENUM_VCA_EVENT_KEY_PERSON_GET_UP  = 17,  //重点人员起身检测
    ENUM_VCA_EVENT_FALL_DOWN          = 20,  //倒地检测
    ENUM_VCA_EVENT_AUDIO_ABNORMAL     = 21,  //声强突变检测
    ENUM_VCA_EVENT_ADV_REACH_HEIGHT   = 22,  //折线攀高
    ENUM_VCA_EVENT_TOILET_TARRY       = 23,  //如厕超时
    ENUM_VCA_EVENT_YARD_TARRY         = 24,  //放风场滞留
    ENUM_VCA_EVENT_ADV_TRAVERSE_PLANE = 25,  //折线警戒面
    ENUM_VCA_EVENT_HUMAN_ENTER        = 29,  //人靠近ATM,只在ATM_PANEL模式下支持   
    ENUM_VCA_EVENT_OVER_TIME          = 30,  //操作超时,只在ATM_PANEL模式下支持
    ENUM_VCA_EVENT_STICK_UP           = 31,  //贴纸条,支持区域规则
    ENUM_VCA_EVENT_INSTALL_SCANNER    = 32   //安装读卡器,支持区域规则
} VCA_RULE_EVENT_TYPE_EX;

//警戒面穿越方向类型
typedef enum _VCA_CROSS_DIRECTION_
{
	VCA_BOTH_DIRECTION,  // 双向 
	VCA_LEFT_GO_RIGHT,   // 由左至右 
	VCA_RIGHT_GO_LEFT    // 由右至左 
}VCA_CROSS_DIRECTION;

//线结构
typedef struct tagNET_VCA_LINE
{
	NET_VCA_POINT struStart;    //起点 
	NET_VCA_POINT struEnd;      //终点
}NET_VCA_LINE, *LPNET_VCA_LINE;

//多边型结构体
typedef struct tagNET_VCA_POLYGON
{
	DWORD dwPointNum;                                  //有效点 大于等于3，若是3点在一条线上认为是无效区域，线交叉认为是无效区域 
	NET_VCA_POINT  struPos[VCA_MAX_POLYGON_POINT_NUM]; //多边形边界点,最多十个 
}NET_VCA_POLYGON, *LPNET_VCA_POLYGON;

//警戒面参数
typedef struct tagNET_VCA_TRAVERSE_PLANE
{	
    NET_VCA_LINE struPlaneBottom;          //警戒面底边
    VCA_CROSS_DIRECTION dwCrossDirection;  //穿越方向: 0-双向，1-从左到右，2-从右到左
    BYTE bySensitivity;                    //灵敏度参数，范围[1,5]
    BYTE byPlaneHeight;                    //警戒面高度
    BYTE byRes2[38];                       //保留
}NET_VCA_TRAVERSE_PLANE, *LPNET_VCA_TRAVERSE_PLANE;

//进入/离开区域参数
typedef struct tagNET_VCA_AREA
{
    NET_VCA_POLYGON struRegion;//区域范围
    BYTE byRes[8];
}NET_VCA_AREA, *LPNET_VCA_AREA;

//根据报警延迟时间来标识报警中带图片，报警间隔和IO报警一致，1秒发送一个。
//入侵参数
typedef struct tagNET_VCA_INTRUSION
{
    NET_VCA_POLYGON struRegion;//区域范围
    WORD wDuration;            //行为事件触发时间阈值: 1-120秒，建议5秒，判断是有效报警的时间  在ATM系统中触发文件阈值为 1-1000秒
    BYTE bySensitivity;        //灵敏度参数，范围[1-100]
	BYTE byRate;               //占比：区域内所有未报警目标尺寸目标占区域面积的比重，归一化为－；
	BYTE byRes[4];             //保留
}NET_VCA_INTRUSION, *LPNET_VCA_INTRUSION;

//徘徊参数
typedef struct tagNET_VCA_PARAM_LOITER
{
    NET_VCA_POLYGON struRegion;//区域范围
    WORD wDuration; //触发时间阈值：1-120秒，建议10秒
    BYTE byRes[6];
}NET_VCA_LOITER, *LPNET_VCA_LOITER;

//物品遗留/物品拿取参数
typedef struct tagNET_VCA_TAKE_LEFT
{
    NET_VCA_POLYGON struRegion;//区域范围
    WORD wDuration; //触发时间阈值：1-120秒，建议10秒
    BYTE byRes[6];
}NET_VCA_TAKE_LEFT, *LPNET_VCA_TAKE_LEFT;

//停车参数
typedef struct tagNET_VCA_PARKING
{
    NET_VCA_POLYGON struRegion;	//区域范围
    WORD wDuration;				//触发时间阈值：1-100秒，建议10秒
    BYTE byRes[6];
}NET_VCA_PARKING, *LPNET_VCA_PARKING;

//快速移动参数
typedef struct tagNET_VCA_RUN
{
	NET_VCA_POLYGON struRegion;	//区域范围
    float  fRunDistance;		//人快速移动最大距离, 范围: [0.1, 1.00] 像素模式 实际模式(1,20)m/s
    BYTE    byRes1;             // 保留字节
    BYTE    byMode;             // 0 像素模式  1 实际模式
    BYTE byRes[2];
}NET_VCA_RUN, *LPNET_VCA_RUN;

//人员聚集参数
typedef struct tagNET_VCA_HIGH_DENSITY
{
    NET_VCA_POLYGON struRegion;//区域范围
    float           fDensity;       //聚集比率, 范围: [0.1, 1.0]
    BYTE            byRes;          // 保留字节
    WORD            wDuration;      // 触发人员聚集参数报警阈值 20-360s
}NET_VCA_HIGH_DENSITY, *LPNET_VCA_HIGH_DENSITY; 

//剧烈运动参数
typedef struct tagNET_VCA_VIOLENT_MOTION
{
    NET_VCA_POLYGON struRegion;//区域范围
    WORD  wDuration;           //触发剧烈运动报警阈值：1-50秒
    BYTE  bySensitivity;       //灵敏度参数，范围[1,5]
	BYTE  byMode;              //0-纯视频模式，1-音视频联合模式，2-纯音频模式
    BYTE  byRes[4];            //保留
}NET_VCA_VIOLENT_MOTION, *LPNET_VCA_VIOLENT_MOTION; 

// 攀高参数
typedef struct tagNET_VCA_REACH_HIGHT
{
    NET_VCA_LINE struVcaLine;   //攀高警戒面
    WORD wDuration; //触发攀高报警阈值：1-120秒
    BYTE	byRes[6];           // 保留字节
}NET_VCA_REACH_HIGHT, *LPNET_VCA_REACH_HIGHT;

// 起床参数
typedef struct tagNET_VCA_GET_UP
{
    NET_VCA_POLYGON struRegion; //区域范围
    WORD	wDuration;	        //触发起床报警阈值1-100 秒
	BYTE    byMode;             //起身检测模式,0-大床通铺模式,1-高低铺模式,2-大床通铺坐立起身模式
	BYTE    bySensitivity;      //灵敏度参数，范围[1,10]
    BYTE	byRes[4];		    //保留字节
}NET_VCA_GET_UP, * LPNET_VCA_GET_UP;

// 物品遗留
typedef struct tagNET_VCA_LEFT
{
    NET_VCA_POLYGON struRegion; // 区域范围
    WORD       wDuration;       // 触发物品遗留报警阈值 10-100秒
	BYTE       bySensitivity;   // 灵敏度参数，范围[1,5] 
    BYTE       byRes[5];        // 保留字节
}NET_VCA_LEFT, *LPNET_VCA_LEFT;

// 物品拿取
typedef struct tagNET_VCA_TAKE
{
    NET_VCA_POLYGON struRegion;     // 区域范围
    WORD            wDuration;      // 触发物品拿取报警阈值10-100秒
	BYTE            bySensitivity;  // 灵敏度参数，范围[1,5] 
    BYTE            byRes[5];       // 保留字节
}NET_VCA_TAKE, *LPNET_VCA_TAKE;

typedef struct tagNET_VCA_OVER_TIME
{
    NET_VCA_POLYGON     struRegion;    // 区域范围
    WORD               wDuration;  // 操作报警时间阈值 4s-60000s
    BYTE   byRes[6];   // 保留字节
}NET_VCA_OVER_TIME, *LPNET_VCA_OVER_TIME;

typedef struct tagNET_VCA_HUMAN_ENTER
{
    DWORD                dwRes[23];			//保留字节
}NET_VCA_HUMAN_ENTER, *LPNET_VCA_HUMAN_ENTER;

//贴纸条参数
typedef struct tagNET_VCA_STICK_UP
{
    NET_VCA_POLYGON struRegion;//区域范围
    WORD wDuration; //触发时间阈值：4-60秒，建议10秒
    BYTE  bySensitivity;       //灵敏度参数，范围[1,5]
    BYTE byRes[5];
}NET_VCA_STICK_UP, *LPNET_VCA_STICK_UP; 

//读卡器参数
typedef struct tagNET_VCA_SCANNER
{
    NET_VCA_POLYGON struRegion;//区域范围
    WORD wDuration; //读卡持续时间：4-60秒
    BYTE bySensitivity;       //灵敏度参数，范围[1,5]
    BYTE byRes[5];
}NET_VCA_SCANNER, *LPNET_VCA_SCANNER; 

//离岗事件
typedef struct tagNET_VCA_LEAVE_POSITION
{
	NET_VCA_POLYGON   struRegion; //区域范围
	WORD   wLeaveDelay;  //无人报警时间，单位：s，取值1-1800
	WORD   wStaticDelay; //睡觉报警时间，单位：s，取值1-1800
	BYTE   byMode;       //模式，0-离岗事件，1-睡岗事件，2-离岗睡岗事件
	BYTE   byPersonType; //值岗人数类型，0-单人值岗，1-双人值岗
	BYTE   byRes[2];     //保留
}NET_VCA_LEAVE_POSITION, *LPNET_VCA_LEAVE_POSITION;

//尾随参数
typedef struct tagNET_VCA_TRAIL
{
	NET_VCA_POLYGON struRegion;//区域范围
	WORD  wRes;      /* 保留 */
	BYTE  bySensitivity;       /* 灵敏度参数，范围[1,5] */
	BYTE  byRes[5];
}NET_VCA_TRAIL, *LPNET_VCA_TRAIL;

//倒地参数
typedef struct tagNET_VCA_FALL_DOWN
{
	NET_VCA_POLYGON struRegion;//区域范围
	WORD  wDuration;      /* 触发事件阈值 1-60s*/
	BYTE  bySensitivity;       /* 灵敏度参数，范围[1,5] */
	BYTE  byRes[5];
}NET_VCA_FALL_DOWN, *LPNET_VCA_FALL_DOWN;

//声强突变参数
typedef struct tagNET_VCA_AUDIO_ABNORMAL
{
    WORD wDecibel;       //声音强度
	BYTE bySensitivity;  //灵敏度参数，范围[1,5] 
    BYTE byAudioMode;    //声音检测模式，0-灵敏度检测，1-分贝阈值检测，2-灵敏度与分贝阈值检测 
    BYTE byEnable;       //使能，是否开启
	BYTE byThreshold;    //声音阈值[0,100]
	BYTE byRes[54];      //保留   
}NET_VCA_AUDIO_ABNORMAL, *LPNET_VCA_AUDIO_ABNORMAL;

typedef struct tagNET_DVR_AUDIO_EXCEPTION
{
	DWORD dwSize;
	BYTE byEnableAudioInException;  //使能，是否开启
	BYTE byRes1[3];
	NET_VCA_AUDIO_ABNORMAL  struAudioAbnormal;  
	NET_DVR_SCHEDTIME	struAlarmSched[MAX_DAYS][MAX_TIMESEGMENT_V30]; //布防时间
	NET_DVR_HANDLEEXCEPTION_V40 struHandleException;  //异常处理方式
	DWORD  dwMaxRelRecordChanNum ;  //报警触发的录象通道 数（只读）最大支持数量
	DWORD  dwRelRecordChanNum ;     //报警触发的录象通道 数 实际支持的数量
	DWORD  byRelRecordChan[MAX_CHANNUM_V30];
	BYTE byRes2[32];
}NET_DVR_AUDIO_EXCEPTION, *LPNET_DVR_AUDIO_EXCEPTION;

typedef struct tagNET_VCA_TOILET_TARRY
{
	NET_VCA_POLYGON struRegion;//区域范围
    WORD wDelay;        //如厕超时时间[1,3600]，单位：秒
	BYTE byRes[6];    
}NET_VCA_TOILET_TARRY, *LPNET_VCA_TOILET_TARRY;

typedef struct tagNET_VCA_YARD_TARRY
{
	NET_VCA_POLYGON struRegion;//区域范围
    WORD wDelay;        //放风场滞留时间[1,120]，单位：秒
	BYTE byRes[6];    
}NET_VCA_YARD_TARRY, *LPNET_VCA_YARD_TARRY;

typedef struct tagNET_VCA_ADV_REACH_HEIGHT
{
    NET_VCA_POLYGON struRegion; //攀高折线
	DWORD   dwCrossDirection;   //跨越方向(详见VCA_CROSS_DIRECTION): 0-双向，1-从左到右2-从右到左
    BYTE	byRes[4];		    // 保留字节
}NET_VCA_ADV_REACH_HEIGHT, * LPNET_VCA_ADV_REACH_HEIGHT;

typedef struct tagNET_VCA_ADV_TRAVERSE_PLANE
{
	NET_VCA_POLYGON struRegion; //警戒面折线
	DWORD   dwCrossDirection;   //跨越方向(详见VCA_CROSS_DIRECTION): 0-双向，1-从左到右2-从右到左
	BYTE    bySensitivity;      //灵敏度参数，范围[1,5] 
	BYTE	byRes[3];		    //保留字节
} NET_VCA_ADV_TRAVERSE_PLANE,*LPNET_VCA_ADV_TRAVERSE_PLANE;


//警戒事件参数
typedef union tagNET_VCA_EVENT_UNION
{
	DWORD                      uLen[23];			//参数
	NET_VCA_TRAVERSE_PLANE     struTraversePlane;   //穿越警戒面参数 
	NET_VCA_AREA    	       struArea;            //进入/离开区域参数
	NET_VCA_INTRUSION          struIntrusion;       //入侵参数
	NET_VCA_LOITER             struLoiter;          //徘徊参数
	NET_VCA_TAKE_LEFT          struTakeTeft;		//物品遗留/物品拿取参数
	NET_VCA_PARKING            struParking;	        //停车参数
	NET_VCA_RUN                struRun;	            //快速移动参数
	NET_VCA_HIGH_DENSITY       struHighDensity;	    //人员聚集参数  
    NET_VCA_VIOLENT_MOTION     struViolentMotion;	//剧烈运动
    NET_VCA_REACH_HIGHT	       struReachHight;      //攀高
    NET_VCA_GET_UP		       struGetUp;           //起床
    NET_VCA_LEFT               struLeft;            //物品遗留
    NET_VCA_TAKE               struTake;            // 物品拿取
    NET_VCA_HUMAN_ENTER        struHumanEnter;      //人员进入
	NET_VCA_OVER_TIME          struOvertime;        //操作超时
    NET_VCA_STICK_UP 	       struStickUp;		    //贴纸条
    NET_VCA_SCANNER 	       struScanner;		    //读卡器参数 	
	NET_VCA_LEAVE_POSITION     struLeavePos;        //离岗参数
	NET_VCA_TRAIL              struTrail;           //尾随参数
	NET_VCA_FALL_DOWN          struFallDown;        //倒地参数
	NET_VCA_AUDIO_ABNORMAL     struAudioAbnormal;   //声强突变
	NET_VCA_ADV_REACH_HEIGHT   struReachHeight;     //折线攀高参数
	NET_VCA_TOILET_TARRY       struToiletTarry;     //如厕超时参数
	NET_VCA_YARD_TARRY         struYardTarry;       //放风场滞留参数
	NET_VCA_ADV_TRAVERSE_PLANE struAdvTraversePlane;//折线警戒面参数
}NET_VCA_EVENT_UNION, *LPNET_VCA_EVENT_UNION;

// 尺寸过滤器类型
typedef enum _VCA_SIZE_FILTER_MODE_
{
	IMAGE_PIX_MODE, //根据像素大小设置
	REAL_WORLD_MODE, //根据实际大小设置
    DEFAULT_MODE 	// 默认模式
}SIZE_FILTER_MODE;
//尺寸过滤器
typedef struct tagNET_VCA_SIZE_FILTER
{
	BYTE    byActive;			//是否激活尺寸过滤器 0-否 非0-是
    BYTE    byMode;		 //过滤器模式SIZE_FILTER_MODE
	BYTE    byRes[2];        //保留，置0
	NET_VCA_RECT struMiniRect;    //最小目标框,全0表示不设置
	NET_VCA_RECT struMaxRect;	  //最大目标框,全0表示不设置
}NET_VCA_SIZE_FILTER, *LPNET_VCA_SIZE_FILTER;

//警戒规则结构
typedef struct tagNET_VCA_ONE_RULE
{
	BYTE   byActive;					//是否激活规则,0-否,非0-是
	BYTE   byRes[7];         			//保留，设置为0字段
    BYTE   byRuleName[NAME_LEN];		//规则名称
	VCA_EVENT_TYPE dwEventType;			//行为分析事件类型
    NET_VCA_EVENT_UNION uEventParam;	//行为分析事件参数
    NET_VCA_SIZE_FILTER  struSizeFilter;  //尺寸过滤器
	NET_DVR_SCHEDTIME struAlarmTime[MAX_DAYS][MAX_TIMESEGMENT_2];//布防时间
	NET_DVR_HANDLEEXCEPTION_V30 struHandleType;	  //处理方式 
	BYTE byRelRecordChan[MAX_CHANNUM_V30];			//报警触发的录象通道,为1表示触发该通道
}NET_VCA_ONE_RULE, *LPNET_VCA_ONE_RULE;

//行为分析配置结构体
typedef struct tagNET_VCA_RULECFG
{
	DWORD  dwSize;			//结构长度
	BYTE   byPicProType;	//报警时图片处理方式 0-不处理 非0-上传
	BYTE   byUpLastAlarm; //2011-04-06 是否先上传最近一次的报警
	BYTE   byPicRecordEnable;  /*2012-3-1是否启用图片存储, 0-不启用, 1-启用*/
	BYTE   byRes;
	NET_DVR_JPEGPARA  struPictureParam; 		//图片规格结构
	NET_VCA_ONE_RULE  struRule[MAX_RULE_NUM];  //规则数组
}NET_VCA_RULECFG, *LPNET_VCA_RULECFG;


//尺寸过滤策略
typedef struct tagNET_VCA_FILTER_STRATEGY
{
	BYTE    byStrategy;      //尺寸过滤策略 0 - 不启用 1-高度和宽度过滤,2-面积过滤
	BYTE    byRes[11];       //保留
}NET_VCA_FILTER_STRATEGY,*LPNET_VCA_FILTER_STRATEGY;

//规则触发参数
typedef struct tagNET_VCA_RULE_TRIGGER_PARAM
{
	BYTE   byTriggerMode;   //规则的触发方式，0- 不启用，1- 轨迹点 2- 目标面积 
	BYTE   byTriggerPoint;  //触发点，触发方式为轨迹点时有效 0- 中,1-上,2-下
	BYTE   byRes1[2];       //保留
	float  fTriggerArea;    //触发目标面积百分比 [0,100]，触发方式为目标面积时有效
	BYTE   byRes2[4];       //保留
}NET_VCA_RULE_TRIGGER_PARAM,*LPNET_VCA_RULE_TRIGGER_PARAM;

//警戒规则结构
typedef struct tagNET_VCA_ONE_RULE_V41
{
	BYTE   byActive; //是否激活规则,0-否,非0-是
	BYTE   byRes1[5];  //保留，设置为0字段
	WORD   wEventTypeEx; //行为事件类型扩展，用于代替字段dwEventType，参考VCA_RULE_EVENT_TYPE_EX
    BYTE   byRuleName[NAME_LEN]; //规则名称
	VCA_EVENT_TYPE dwEventType;	//行为事件类型，保留是为了兼容，后续建议使用wEventTypeEx获取事件类型
    NET_VCA_EVENT_UNION uEventParam; //行为分析事件参数
    NET_VCA_SIZE_FILTER  struSizeFilter;  //尺寸过滤器
	NET_DVR_SCHEDTIME struAlarmTime[MAX_DAYS][MAX_TIMESEGMENT_V30];//布防时间
	NET_DVR_HANDLEEXCEPTION_V30 struHandleType;	//处理方式 
	BYTE   byRelRecordChan[MAX_CHANNUM_V30]; //报警触发的录象通道,为1表示触发该通道
    WORD   wAlarmDelay; //智能报警延时，0-5s,1-10,2-30s,3-60s,4-120s,5-300s,6-600s
    BYTE   byRes2[2]; //保留
	NET_VCA_FILTER_STRATEGY     struFilterStrategy; //尺寸过滤策略
	NET_VCA_RULE_TRIGGER_PARAM  struTriggerParam;   //规则触发参数
	BYTE   byRes[32];
}NET_VCA_ONE_RULE_V41, *LPNET_VCA_ONE_RULE_V41;

//行为分析配置结构体
typedef struct tagNET_VCA_RULECFG_V41
{
	DWORD  dwSize;			//结构长度
	BYTE    byPicProType;	//报警时图片处理方式 0-不处理 非0-上传
	BYTE    byUpLastAlarm; //2011-04-06 是否先上传最近一次的报警
	BYTE    byPicRecordEnable;  /*2012-3-1是否启用图片存储, 0-不启用, 1-启用*/
	BYTE    byRes1;
	NET_DVR_JPEGPARA struPictureParam; 		//图片规格结构
	NET_VCA_ONE_RULE_V41  struRule[MAX_RULE_NUM];  //规则数组
	BYTE byRes[32];
}NET_VCA_RULECFG_V41, *LPNET_VCA_RULECFG_V41;

//简化目标结构体
typedef struct tagNET_VCA_TARGET_INFO
{
    DWORD    dwID;				//目标ID ,人员聚集过高报警时为0
	NET_VCA_RECT struRect;      //目标边界框 
    BYTE      byRes[4];			//保留
}NET_VCA_TARGET_INFO, *LPNET_VCA_TARGET_INFO;

//简化的规则信息, 包含规则的基本信息
typedef struct tagNET_VCA_RULE_INFO
{
    BYTE   byRuleID;		        //规则ID,0-7
    BYTE   byRes[1];	            //保留
    WORD   wEventTypeEx;            //行为事件类型扩展，用于代替字段dwEventType，参考VCA_RULE_EVENT_TYPE_EX
    BYTE   byRuleName[NAME_LEN];    //规则名称
    VCA_EVENT_TYPE  dwEventType;    //行为事件类型，保留是为了兼容，后续建议使wEventTypeEx获取事件类型
    NET_VCA_EVENT_UNION uEventParam;//事件参数
}NET_VCA_RULE_INFO, *LPNET_VCA_RULE_INFO;

//前端设备地址信息，智能分析仪表示的是前端设备的地址信息，其他设备表示本机的地址
typedef struct tagNET_VCA_DEV_INFO
{
	NET_DVR_IPADDR  struDevIP; //前端设备地址， 
	WORD wPort; 			//前端设备端口号， 
	BYTE byChannel;  		//前端设备通道， 
    BYTE byIvmsChannel;		// Ivms 通道 
} NET_VCA_DEV_INFO, *LPNET_VCA_DEV_INFO;

//行为分析结果上报结构
typedef struct  tagNET_VCA_RULE_ALARM
{
	DWORD    dwSize;						//结构长度
	DWORD    dwRelativeTime;				//相对时标
	DWORD    dwAbsTime;						//绝对时标
	NET_VCA_RULE_INFO     struRuleInfo;		//事件规则信息
	NET_VCA_TARGET_INFO  struTargetInfo;	//报警目标信息
	NET_VCA_DEV_INFO  	 struDevInfo;		//前端设备信息
	DWORD dwPicDataLen;						//返回图片的长度 为0表示没有图片，大于0表示该结构后面紧跟图片数据*/
    BYTE       byPicType;		//  0-普通图片 1-对比图片
    BYTE       byRes[3];		// 保留字节
    DWORD      dwRes[3];		/* 保留，设置为0*/
	BYTE  *pImage;   						//指向图片的指针
}NET_VCA_RULE_ALARM, *LPNET_VCA_RULE_ALARM;

//行为分析规则DSP信息叠加结构
typedef struct tagNET_VCA_DRAW_MODE
{ 
	DWORD  dwSize;
	BYTE	byDspAddTarget;			//编码是否叠加目标
	BYTE    byDspAddRule;			//编码是否叠加规则
	BYTE	byDspPicAddTarget;		//抓图是否叠加目标
	BYTE	byDspPicAddRule;		//抓图是否叠加规则
	BYTE	byRes[4];			
}NET_VCA_DRAW_MODE, *LPNET_VCA_DRAW_MODE;

//物体类型
typedef enum tagOBJECT_TYPE_ENUM
{    
	ENUM_OBJECT_TYPE_COAT  = 1  //上衣
}OBJECT_TYPE_ENUM;

//物体颜色条件结构体
typedef struct tagNET_DVR_OBJECT_COLOR_COND
{   
	DWORD  dwChannel;   //通道号
	DWORD  dwObjType;   //物体类型，参见OBJECT_TYPE_ENUM
	BYTE   byRes[64];   //保留
}NET_DVR_OBJECT_COLOR_COND,*LPNET_DVR_OBJECT_COLOR_COND;

//图片参数
typedef struct tagNET_DVR_PIC
{
	BYTE   byPicType;        //图片类型，1-jpg
	BYTE   byRes1[3];        //保留
	DWORD  dwPicWidth;       //图片宽度
	DWORD  dwPicHeight;      //图片高度
	DWORD  dwPicDataLen;     //图片数据实际大小
	DWORD  dwPicDataBuffLen; //图片数据缓冲区大小
	BYTE*  byPicDataBuff;    //图片数据缓冲区
	BYTE   byRes2[40];       //保留
}NET_DVR_PIC,*LPNET_DVR_PIC;

//颜色联合体
typedef union tagNET_DVR_OBJECT_COLOR_UNION
{    
	NET_DVR_COLOR  struColor;   //颜色值
    NET_DVR_PIC    struPicture; //图片
    BYTE           byRes[64];   //保留
}NET_DVR_OBJECT_COLOR_UNION,*LPNET_DVR_OBJECT_COLOR_UNION;

//物体颜色参数结构体
typedef struct tagNET_DVR_OBJECT_COLOR
{    
    DWORD  dwSize;       //结构体大小
	BYTE   byEnable;     //0-不启用，1-启用
	BYTE   byColorMode;  //取色方式，1-颜色值，2-图片
	BYTE   byRes1[2];    //保留
	NET_DVR_OBJECT_COLOR_UNION uObjColor; //物体颜色联合体，取值依赖于取色方式
	BYTE   byRes2[64];   //保留
}NET_DVR_OBJECT_COLOR, *LPNET_DVR_OBJECT_COLOR;

//区域类型
typedef enum tagAREA_TYPE_ENUM
{    
	ENUM_OVERLAP_REGION  = 1,//共同区域
	ENUM_BED_LOCATION  = 2   //床铺位置
}AREA_TYPE_ENUM;

//辅助区域
typedef struct tagNET_DVR_AUXAREA
{
	DWORD  dwAreaType;   //区域类型，参见AREA_TYPE_ENUM
	BYTE   byEnable;     //0-不启用，1-启用
	BYTE   byRes1[3];     //保留
	NET_VCA_POLYGON struPolygon; //区域
	BYTE   byRes2[16];   //保留
}NET_DVR_AUXAREA,*LPNET_DVR_AUXAREA;

//辅助区域列表
typedef struct tagNET_DVR_AUXAREA_LIST
{
    DWORD	 dwSize;	// 结构体大小
	NET_DVR_AUXAREA struArea[MAX_AUXAREA_NUM]; //辅助区域
	BYTE	byRes2[64];	// 保留
}NET_DVR_AUXAREA_LIST,*LPNET_DVR_AUXAREA_LIST;

//通道工作模式
typedef enum tagCHAN_WORKMODE_ENUM
{    
	ENUM_CHAN_WORKMODE_INDEPENDENT = 1,  //独立模式
	ENUM_CHAN_WORKMODE_MASTER  = 2,      //主模式
    ENUM_CHAN_WORKMODE_SLAVE  = 3        //从模式
}CHAN_WORKMODE_ENUM;

//通道工作模式参数结构体
typedef struct tagNET_DVR_CHANNEL_WORKMODE
{   
    DWORD dwSize;        //结构体大小
	BYTE  byWorkMode;    //工作模式，参见CHAN_WORKMODE_ENUM
	BYTE  byRes[63];     //保留
}NET_DVR_CHANNEL_WORKMODE,*LPNET_DVR_CHANNEL_WORKMODE;

//设备通道参数结构体
typedef struct tagNET_DVR_CHANNEL
{
    BYTE   byAddress[MAX_DOMAIN_NAME];	//设备IP或域名
	WORD   wDVRPort;			 	    //端口号
	BYTE   byRes1[2];                   //保留
    BYTE   sUserName[NAME_LEN];	        //主机用户名
	BYTE   sPassword[PASSWD_LEN];       //主机密码
	DWORD  dwChannel;                   //通道号
	BYTE   byRes2[32];                  //保留
}NET_DVR_CHANNEL,*LPNET_DVR_CHANNEL;

//从通道信息联合体
typedef union tagNET_DVR_SLAVE_CHANNEL_UNION
{
	BYTE            byRes[152];        //联合体大小
	DWORD           dwLocalChannel;    //本机通道
	NET_DVR_CHANNEL struRemoteChannel; //远程通道
}NET_DVR_SLAVE_CHANNEL_UNION,*LPNET_DVR_SLAVE_CHANNEL_UNION;

//从通道参数结构体
typedef struct tagNET_DVR_SLAVE_CHANNEL_PARAM
{
 	BYTE   byChanType;   //从通道类型，1-本机通道，2-远程通道 
 	BYTE   byRes1[3];    //保留
 	NET_DVR_SLAVE_CHANNEL_UNION uSlaveChannel; //从通道联合体，取值依赖于byChanType
 	BYTE   byRes2[64];   //保留
}NET_DVR_SLAVE_CHANNEL_PARAM,*LPNET_DVR_SLAVE_CHANNEL_PARAM;


//从通道参数配置结构体
typedef struct tagNET_DVR_SLAVE_CHANNEL_CFG
{   
     DWORD dwSize;   //结构体大小
 	NET_DVR_SLAVE_CHANNEL_PARAM struChanParam[MAX_SLAVE_CHANNEL_NUM];//从通道参数
 	BYTE  byRes[64];  //保留
}NET_DVR_SLAVE_CHANNEL_CFG,*LPNET_DVR_SLAVE_CHANNEL_CFG;

//视频质量诊断检测事件
typedef enum tagVQD_EVENT_ENUM
{    
    ENUM_VQD_EVENT_BLUR           = 1,  //图像模糊
    ENUM_VQD_EVENT_LUMA           = 2,  //亮度异常
    ENUM_VQD_EVENT_CHROMA         = 3,  //图像偏色
    ENUM_VQD_EVENT_SNOW           = 4,  //雪花干扰
    ENUM_VQD_EVENT_STREAK         = 5,  //条纹干扰
    ENUM_VQD_EVENT_FREEZE         = 6,  //画面冻结
    ENUM_VQD_EVENT_SIGNAL_LOSS    = 7,  //信号丢失
    ENUM_VQD_EVENT_PTZ            = 8,  //云台失控
    ENUM_VQD_EVENT_SCNENE_CHANGE  = 9,  //场景突变
    ENUM_VQD_EVENT_VIDEO_ABNORMAL = 10, //视频异常
    ENUM_VQD_EVENT_VIDEO_BLOCK    = 11, //视频遮挡
}VQD_EVENT_ENUM;

//视频质量诊断事件条件结构体
typedef struct tagNET_DVR_VQD_EVENT_COND
{
	DWORD dwChannel;   //通道号
	DWORD dwEventType; //检测事件类型，参见VQD_EVENT_ENUM
	BYTE  byRes[64];   //保留
}NET_DVR_VQD_EVENT_COND,*LPNET_DVR_VQD_EVENT_COND;

//视频质量诊断事件参数
typedef struct tagNET_DVR_VQD_EVENT_PARAM
{ 
	BYTE   byThreshold;    //报警阈值，范围[0,100]
	BYTE   byTriggerMode;  //1-持续触发，2-单次触发
	BYTE   byUploadPic;    //0-不上传图片，1-上传图片，无论是否上传图片，事后都可以从设备获取该事件所对应最新的一张报警图片，参见接口NET_DVR_StartDownload
	BYTE   byRes1;         //保留
	DWORD  dwTimeInterval; //持续触发报警时间间隔，范围[0,3600] 单位：秒
	BYTE   byRes2[64];     //保留
}NET_DVR_VQD_EVENT_PARAM,*LPNET_DVR_VQD_EVENT_PARAM;

//视频质量诊断事件规则
typedef struct tagNET_DVR_VQD_EVENT_RULE
{   
    DWORD  dwSize;       //结构体大小 
	BYTE   byEnable;     //0-不启用，1-启用
	BYTE   byRes1[3];    //保留
	NET_DVR_VQD_EVENT_PARAM struEventParam; //视频质量诊断事件参数
	NET_DVR_SCHEDTIME struAlarmTime[MAX_DAYS][MAX_TIMESEGMENT_V30];//检测时间
	NET_DVR_HANDLEEXCEPTION_V30 struHandleType;  //处理方式
	BYTE   byRelRecordChan[MAX_IVMS_IP_CHANNEL]; //报警触发的录象通道：1表示触发该通道；0表示不触发 
	BYTE   byRe2[128];    //保留
}NET_DVR_VQD_EVENT_RULE,*LPNET_DVR_VQD_EVENT_RULE;

//基准场景参数
typedef struct tagNET_DVR_BASELINE_SCENE
{   
    DWORD dwSize;     //结构体大小
    BYTE  byEnable;   //0-不启用，1-启用
	BYTE  byRes[63];  //保留
}NET_DVR_BASELINE_SCENE,*LPNET_DVR_BASELINE_SCENE;

//基准场景操作参数结构体
typedef struct tagNET_DVR_CONTROL_BASELINE_SCENE_PARAM
{   
    DWORD dwSize;     //结构体大小
    DWORD dwChannel;  //通道号
    BYTE  byCommand;  //操作类型，1-此字段保留，暂不使用，2-更新基准场景
	BYTE  byRe[127];  //保留
}NET_DVR_CONTROL_BASELINE_SCENE_PARAM,*LPNET_DVR_CONTROL_BASELINE_SCENE_PARAM;

//视频质量诊断报警结构体
typedef struct tagNET_DVR_VQD_ALARM
{   
    DWORD  dwSize;                //结构体大小
    DWORD  dwRelativeTime;        //相对时标
	DWORD  dwAbsTime;	          //绝对时标
    NET_VCA_DEV_INFO struDevInfo; //前端设备信息 
	DWORD  dwEventType;           //事件类型，参考VQD_EVENT_ENUM
	float  fThreshold;            //报警阈值[0.000,1.000]
	DWORD  dwPicDataLen;          //图片长度，为0表示没有图片
	BYTE   *pImage;               //指向图片的指针           
	BYTE   byRes[128];            //保留
}NET_DVR_VQD_ALARM,*LPNET_DVR_VQD_ALARM;

//标定点子结构
typedef struct tagNET_DVR_CB_POINT
{
	NET_VCA_POINT struPoint;     //标定点，主摄像机（枪机）
	NET_DVR_PTZPOS struPtzPos;  //球机输入的PTZ坐标
	BYTE	byRes[8];
}NET_DVR_CB_POINT, LPNET_DVR_CB_POINT;

//标定参数配置结构
typedef struct tagNET_DVR_TRACK_CALIBRATION_PARAM
{	
	BYTE byPointNum;			//有效标定点个数
	BYTE byRes[3];				
	NET_DVR_CB_POINT  struCBPoint[MAX_CALIB_PT]; //标定点组
}NET_DVR_TRACK_CALIBRATION_PARAM, *LPNET_DVR_TRACK_CALIBRATION_PARAM;

//球机配置结构
typedef struct tagNET_DVR_TRACK_CFG 
{	
	DWORD dwSize;				//结构长度	
    BYTE byEnable;				//标定使能
    BYTE byFollowChan;          // 被控制的从通道
    BYTE byDomeCalibrate;			//设置智能跟踪球机标定，1设置 0不设置 
    BYTE byRes;					// 保留字节
	NET_DVR_TRACK_CALIBRATION_PARAM  struCalParam; //标定点组
}NET_DVR_TRACK_CFG, *LPNET_DVR_TRACK_CFG ;

//跟踪模式
typedef enum _TRACK_MODE_
{
	MANUAL_CTRL = 0,  //手动跟踪
	ALARM_TRACK    //报警触发跟踪
}TRACK_MODE;

//手动控制结构
typedef struct tagNET_DVR_MANUAL_CTRL_INFO 
{
	NET_VCA_POINT struCtrlPoint;
	BYTE  byRes[8];
}NET_DVR_MANUAL_CTRL_INFO, *LPNET_DVR_MANUAL_CTRL_INFO ;

//跟踪模式结构
typedef struct tagNET_DVR_TRACK_MODE
{
	DWORD dwSize;		//结构长度
	BYTE byTrackMode;   //跟踪模式
    BYTE byRuleConfMode;   //规则配置跟踪模式0-本地配置跟踪，1-远程配置跟踪
    BYTE byRes[2];   //保留，置0
	union
	{
		DWORD dwULen[4];
		NET_DVR_MANUAL_CTRL_INFO  struManualCtrl;//手动跟踪结构
	}uModeParam;
}NET_DVR_TRACK_MODE,*LPNET_DVR_TRACK_MODE;

typedef struct tagNET_DVR_ALARM_JPEG
{
    BYTE    byPicProType;	    /*报警时图片处理方式 0-不处理 1-上传*/
    BYTE    byRes[3];           //保留字节
    NET_DVR_JPEGPARA struPicParam; 				/*图片规格结构*/
}NET_DVR_ALARM_JPEG, *LPNET_DVR_ALARM_JPEG;

//分析仪行为分析规则结构
//警戒规则结构
typedef struct tagNET_IVMS_ONE_RULE_
{
	BYTE    byActive;           /* 是否激活规则,0-否, 非0-是 */
	BYTE	byRes1[7];	//保留，设置为0字段
	BYTE   byRuleName[NAME_LEN]; //规则名称
	VCA_EVENT_TYPE dwEventType;   //行为分析事件类型
    NET_VCA_EVENT_UNION uEventParam;//行为分析事件参数
    NET_VCA_SIZE_FILTER  struSizeFilter;  //尺寸过滤器
	BYTE byRes2[68]; /*保留，设置为0*/
}NET_IVMS_ONE_RULE, *LPNET_IVMS_ONE_RULE;

// 分析仪规则结构
typedef struct tagNET_IVMS_RULECFG
{
	NET_IVMS_ONE_RULE  struRule[MAX_RULE_NUM];   //规则数组
}NET_IVMS_RULECFG, *LPNET_IVMS_RULECFG;

// IVMS行为分析配置结构
typedef struct tagNET_IVMS_BEHAVIORCFG
{
    DWORD dwSize;
	BYTE    byPicProType;	    //报警时图片处理方式 0-不处理 非0-上传
	BYTE    byRes[3];
	NET_DVR_JPEGPARA struPicParam; 				//图片规格结构
	NET_IVMS_RULECFG struRuleCfg[MAX_DAYS][MAX_TIMESEGMENT];//每个时间段对应规则
} NET_IVMS_BEHAVIORCFG, *LPNET_IVMS_BEHAVIORCFG;

//智能分析仪取流计划子结构
typedef struct tagNET_IVMS_DEVSCHED
{
	NET_DVR_SCHEDTIME 	struTime;       //时间参数
	NET_DVR_PU_STREAM_CFG struPUStream; //前端取流参数
}NET_IVMS_DEVSCHED, *LPNET_IVMS_DEVSCHED;

//智能分析仪参数配置结构
typedef struct tagNET_IVMS_STREAMCFG
{
    DWORD dwSize;
	NET_IVMS_DEVSCHED	struDevSched[MAX_DAYS][MAX_TIMESEGMENT];//按时间段配置前端取流以及规则信息
} NET_IVMS_STREAMCFG, *LPNET_IVMS_STREAMCFG;

//屏蔽区域
typedef struct tagNET_VCA_MASK_REGION
{
    BYTE byEnable;			//是否激活, 0-否，非0-是
	BYTE byRes[3];         //保留，置0
	NET_VCA_POLYGON  struPolygon; //屏蔽多边形
}NET_VCA_MASK_REGION, * LPNET_VCA_MASK_REGION;

//屏蔽区域链表结构
typedef struct tagNET_VCA_MASK_REGION_LIST
{
	DWORD dwSize;     //结构长度
	BYTE byRes[4];     //保留，置0
	NET_VCA_MASK_REGION  struMask[MAX_MASK_REGION_NUM]; //屏蔽区域数组
}NET_VCA_MASK_REGION_LIST, *LPNET_VCA_MASK_REGION_LIST;


//ATM进入区域参数
typedef struct tagNET_VCA_ENTER_REGION//防止干扰ATM检测
{
	DWORD dwSize;
    BYTE byEnable;			//是否激活，0-否，非0-是
	BYTE byRes1[3];
	NET_VCA_POLYGON  struPolygon; //进入区域
	BYTE byRes2[16];
}NET_VCA_ENTER_REGION, * LPNET_VCA_ENTER_REGION;

//IVMS屏蔽区域链表
typedef struct tagNET_IVMS_MASK_REGION_LIST
{
	DWORD dwSize;    //结构长度
	NET_VCA_MASK_REGION_LIST struList[MAX_DAYS][ MAX_TIMESEGMENT];
}NET_IVMS_MASK_REGION_LIST, *LPNET_IVMS_MASK_REGION_LIST;

//IVMS的ATM进入区域参数
typedef struct tagNET_IVMS_ENTER_REGION
{
	DWORD dwSize;
	NET_VCA_ENTER_REGION  struEnter[MAX_DAYS][ MAX_TIMESEGMENT]; //进入区域
}NET_IVMS_ENTER_REGION, *LPNET_IVMS_ENTER_REGION;

// ivms 报警图片上传结构
typedef struct tagNET_IVMS_ALARM_JPEG
{
    BYTE                byPicProType;               
    BYTE                byRes[3];
    NET_DVR_JPEGPARA      struPicParam;     
}NET_IVMS_ALARM_JPEG, *LPNET_IVMS_ALARM_JPEG;

// IVMS 后检索配置
typedef struct tagNET_IVMS_SEARCHCFG
{
    DWORD                        dwSize;
    NET_DVR_MATRIX_DEC_REMOTE_PLAY struRemotePlay;// 远程回放
    NET_IVMS_ALARM_JPEG         struAlarmJpeg; // 报警上传图片配置
    NET_IVMS_RULECFG           struRuleCfg;   //IVMS 行为规则配置
}NET_IVMS_SEARCHCFG, *LPNET_IVMS_SEARCHCFG;
/************************************end******************************************/
//NAS认证配置
typedef struct tagNET_DVR_IDENTIFICATION_PARAM
{
	BYTE	sUserName[NAME_LEN];		/* 用户名 32*/
	BYTE	sPassword[PASSWD_LEN];		/* 密码 16*/
	BYTE	byRes1[4];	//保留
}NET_DVR_IDENTIFICATION_PARAM, *LPNET_DVR_IDENTIFICATION_PARAM;

typedef union tagNET_DVR_MOUNT_PARAM_UNION
{
	BYTE  uLen[52];                    //联合体结构大小
    NET_DVR_IDENTIFICATION_PARAM struIdentificationParam;//(SMB/CIFS时生效)
} NET_DVR_MOUNT_PARAM_UNION, *LPNET_DVR_MOUNT_PARAM_UNION;

typedef struct tagNET_DVR_NAS_MOUNT_PARAM
{
	BYTE  byMountType; //0～保留,1~NFS, 2~ SMB/CIFS
	BYTE  byRes[3];
	NET_DVR_MOUNT_PARAM_UNION uMountParam;
}NET_DVR_NAS_MOUNT_PARAM, *LPNET_DVR_NAS_MOUNT_PARAM;

typedef union tagNET_DVR_MOUNTMETHOD_PARAM_UNION
{
	BYTE  uLen[56]; //联合体结构大小                    
	NET_DVR_NAS_MOUNT_PARAM struNasMountParam;//NAS挂载方式 (byNetDiskType为NFS(NAS)时生效) 
}NET_DVR_MOUNTMETHOD_PARAM_UNION, *LPNET_DVR_MOUNTMETHOD_PARAM_UNION;

//网络硬盘结构配置
typedef struct tagNET_DVR_SINGLE_NET_DISK_INFO
{
	BYTE byNetDiskType;						//网络硬盘类型, 0-NFS(NAS),1-iSCSI
	BYTE byRes1[3];							//保留
    NET_DVR_IPADDR struNetDiskAddr;			//网络硬盘地址
    BYTE sDirectory[PATHNAME_LEN];			// PATHNAME_LEN = 128
	WORD wPort;							    //iscsi有端口，现在为默认
	BYTE  byRes2[2];
	NET_DVR_MOUNTMETHOD_PARAM_UNION  uMountMethodParam;
	BYTE  byRes3[8];				//保留
}NET_DVR_SINGLE_NET_DISK_INFO, *LPNET_DVR_SINGLE_NET_DISK_INFO;

#define MAX_NET_DISK	16//最大网络硬盘个数

typedef struct tagNET_DVR_NET_DISKCFG 
{
    DWORD  dwSize;
    NET_DVR_SINGLE_NET_DISK_INFO struNetDiskParam[MAX_NET_DISK];
}NET_DVR_NET_DISKCFG, *LPNET_DVR_NET_DISKCFG;

//事件类型
//主类型
typedef enum _MAIN_EVENT_TYPE_
{
	EVENT_MOT_DET = 0,		//移动侦测
	EVENT_ALARM_IN = 1,		//报警输入
	EVENT_VCA_BEHAVIOR = 2,	// 行为分析
	EVENT_INQUEST = 3,       //审讯事件
	EVENT_VCA_DETECTION = 4, //智能侦测
	EVENT_STREAM_INFO = 100  //流ID信息
}MAIN_EVENT_TYPE;

#define INQUEST_START_INFO        0x1001       /*讯问开始信息*/
#define INQUEST_STOP_INFO         0x1002       /*讯问停止信息*/
#define INQUEST_TAG_INFO          0x1003       /*重点标记信息*/
#define INQUEST_SEGMENT_INFO      0x1004       /*审讯片断状态信息*/

typedef enum _VCA_DETECTION_MINOR_TYPE_
{
	EVENT_VCA_TRAVERSE_PLANE     = 1,        //越警侦测
	EVENT_FIELD_DETECTION,		     //区域入侵侦测
	EVENT_AUDIO_INPUT_ALARM,      //音频输入异常
	EVENT_SOUND_INTENSITY_ALARM,   //声强突变侦测
	EVENT_FACE_DETECTION,             //人脸侦测
	EVENT_VIRTUAL_FOCUS_ALARM, /*虚焦侦测*/
	EVENT_SCENE_CHANGE_ALARM, /*场景变更侦测*/
	EVENT_ALL = 0xffffffff				//表示全部
}VCA_DETECTION_MINOR_TYPE;



//行为分析主类型对应的次类型， 0xffff表示全部
typedef enum _BEHAVIOR_MINOR_TYPE_
{
	EVENT_TRAVERSE_PLANE     = 0,    // 穿越警戒面
	EVENT_ENTER_AREA,				//目标进入区域,支持区域规则
	EVENT_EXIT_AREA,				//目标离开区域,支持区域规则
	EVENT_INTRUSION,				 // 周界入侵,支持区域规则
	EVENT_LOITER,				 //徘徊,支持区域规则
	EVENT_LEFT_TAKE,				//物品遗留拿取,支持区域规则
	EVENT_PARKING,					//停车,支持区域规则
	EVENT_RUN,					//快速移动,支持区域规则
	EVENT_HIGH_DENSITY,				 //区域内人员聚集,支持区域规则
    EVENT_STICK_UP,				//贴纸条,支持区域规则
    EVENT_INSTALL_SCANNER,				//安装读卡器,支持区域规则
    EVENT_OPERATE_OVER_TIME,        // 操作超时
    EVENT_FACE_DETECT,              // 异常人脸
    EVENT_LEFT,                     // 物品遗留
    EVENT_TAKE,                      // 物品拿取
	EVENT_LEAVE_POSITION,         //离岗事件
	EVENT_TRAIL_INFO = 16,            //尾随
	EVENT_FALL_DOWN_INFO = 19,                 //倒地
	EVENT_OBJECT_PASTE	    =20,		// 异物粘贴区域
	EVENT_FACE_CAPTURE_INFO = 21,                //正常人脸
	EVENT_MULTI_FACES_INFO = 22,                  //多张人脸
	EVENT_AUDIO_ABNORMAL_INFO = 23,             //声强突变
	EVENT_DETECT	= 24     			   //智能侦测
}BEHAVIOR_MINOR_TYPE;

// 主类型100，对应的小类型
typedef enum _STREAM_INFO_MINOR_TYPE_
{
	EVENT_STREAM_ID  = 0,				// 流ID
	EVENT_TIMING = 1,					// 定时录像
	EVENT_MOTION_DETECT = 2,			// 移动侦测
	EVENT_ALARM = 3,					// 报警录像
	EVENT_ALARM_OR_MOTION_DETECT = 4,	// 报警或移动侦测
	EVENT_ALARM_AND_MOTION_DETECT = 5,	// 报警和移动侦测
	EVENT_COMMAND_TRIGGER = 6,			// 命令触发
	EVENT_MANNUAL = 7,					// 手动录像
        EVENT_BACKUP_VOLUME = 8				// 存档卷录像
}STREAM_INFO_MINOR_TYPE;

// typedef enum tagITS_MINOR_TYPE
// {
//     ITS_EVENT_CONGESTION    = 0,    // 拥堵
//     ITS_EVENT_PARKING,              // 停车
//     ITS_EVENT_INVERSE,              // 逆行
//     ITS_EVENT_PEDESTRIAN,           // 行人
//     ITS_EVENT_DEBRIS                // 遗留物，抛洒物碎片
// }ITS_MINOR_TYPE;

// 邦诺CVR
#define MAX_ID_COUNT    256
#define MAX_STREAM_ID_COUNT    1024
#define STREAM_ID_LEN   32
#define PLAN_ID_LEN  32

// 流信息 - 72字节长
typedef struct tagNET_DVR_STREAM_INFO 
{
	DWORD dwSize;
	BYTE  byID[STREAM_ID_LEN];      //ID数据
	DWORD dwChannel;                //关联设备通道，等于0xffffffff时，表示不关联
	BYTE  byRes[32];                //保留
}NET_DVR_STREAM_INFO, *LPNET_DVR_STREAM_INFO;

#define SEARCH_EVENT_INFO_LEN 300	//事件信息长度

//事件搜索条件
typedef struct tagNET_DVR_SEARCH_EVENT_PARAM
{
	WORD wMajorType;			//0-移动侦测，1-报警输入, 2-智能事件
	WORD wMinorType;			//搜索次类型- 根据主类型变化，0xffff表示全部
	NET_DVR_TIME struStartTime;	//搜索的开始时间，停止时间: 同时为(0, 0) 表示从最早的时间开始，到最后，最前面的4000个事件
	NET_DVR_TIME struEndTime;	//
	BYTE			byLockType;		// 0xff-全部，0-未锁，1-锁定
	BYTE 			byValue;			//0-按位表示，1-按值表示
	BYTE 			byRes[130];		// 保留
	union	
	{
		BYTE byLen[SEARCH_EVENT_INFO_LEN];		  
		struct//报警输入
		{
			BYTE byAlarmInNo[MAX_ALARMIN_V30];    //报警输入号，byAlarmInNo[0]若置1则表示查找由报警输入1触发的事件
			BYTE byRes[SEARCH_EVENT_INFO_LEN - MAX_ALARMIN_V30];
		}struAlarmParam;

		struct//报警输入--按值
        {
            WORD wAlarmInNo[128];     /*报警输入号，按值表示,采用紧凑型排列*/
            BYTE byRes[44]; //保留
        }struAlarmParamByValue;
		
		struct//移动侦测
		{
			BYTE byMotDetChanNo[MAX_CHANNUM_V30];//移动侦测通道，byMotDetChanNo[0]若置1则表示查找由通道1发生移动侦测触发的事件
			BYTE byRes[SEARCH_EVENT_INFO_LEN - MAX_CHANNUM_V30];
		}struMotionParam;

		struct//移动侦测--按值
        {
            WORD wMotDetChanNo[64];		/* 移动侦测通道，按值表示 ,采用紧凑型排列*/
            BYTE byRes[172];				/*保留*/
        }struMotionParamByValue;
		
		struct//行为分析
		{
			BYTE byChanNo[MAX_CHANNUM_V30];	//触发事件的通道
			BYTE byRuleID;					//规则ID，0xff表示全部
			BYTE byRes1[43];				//保留
		}struVcaParam;

		struct //行为分析--按值方式查找 
        {
            WORD wChanNo[64];	 //行为分析对应的通道，按值表示,采用紧凑型排列
            BYTE byRuleID;      //行为分析类型，规则0xff表示全部，从0开始
            BYTE byRes[171];	 /*保留*/           
        }struVcaParamByValue;

		struct//审讯事件搜索条件
		{			
			BYTE byRoomIndex;    //审讯室编号,从1开始
			BYTE byRes[299];     //保留
		} struInquestParam;
		struct  //智能侦测查找条件
		{
			BYTE byChan [256];//触发智能侦测的通道号，按数组下标表示，byChan[0]若置1则表示查找由通道1发生移动侦测触发的事件 
		}struVCADetectByBit;
		
        struct//智能侦测查找条件 ，通道号按值表示
		{
			DWORD dwChanNo[MAX_CHANNUM_V30-1];// 触发通道号,按值表示，0xffffffff无效，且后续数据也表示无效值
			BYTE byAll;//0-表示不是全部，1-表示全部。
			BYTE byres[3];
		}struVCADetectByValue;
		struct
		{
			NET_DVR_STREAM_INFO struIDInfo; // 流id信息，72字节长
			DWORD				dwCmdType;  // 外部触发类型，NVR接入云存储使用
			BYTE				byBackupVolumeNum; //存档卷号，CVR使用
			BYTE				byRes[223];
		}struStreamIDParam;
	}uSeniorParam;
}NET_DVR_SEARCH_EVENT_PARAM, *LPNET_DVR_SEARCH_EVENT_PARAM;

//查找返回结果
typedef struct tagNET_DVR_SEARCH_EVENT_RET
{
	WORD wMajorType;			//主类型
	WORD wMinorType;			//次类型
	NET_DVR_TIME struStartTime;	//事件开始的时间
	NET_DVR_TIME struEndTime;   //事件停止的时间，脉冲事件时和开始时间一样
	BYTE byChan[MAX_CHANNUM_V30];	
	BYTE byRes[36];
	union		
	{
		struct//报警输入结果
		{
			DWORD dwAlarmInNo;     //报警输入号
			BYTE byRes[SEARCH_EVENT_INFO_LEN];
		}struAlarmRet;
		struct//移动侦测结果
		{
			DWORD dwMotDetNo;	//移动侦测通道
			BYTE byRes[SEARCH_EVENT_INFO_LEN];
		}struMotionRet;
		struct//行为分析结果  
		{
			DWORD dwChanNo;					//触发事件的通道号
			BYTE byRuleID;					//规则ID
			BYTE byRes1[3];					//保留
			BYTE byRuleName[NAME_LEN];		//规则名称
			NET_VCA_EVENT_UNION uEvent;     //行为事件参数
		}struVcaRet;
		struct//审讯事件
		{
			BYTE  byRoomIndex;     //审讯室编号,从1开始
            BYTE  byDriveIndex;    //刻录机编号,从1开始
			BYTE  byRes1[6];       //保留
            DWORD dwSegmentNo;     //本片断在本次审讯中的序号,从1开始 
			WORD  wSegmetSize;     //本片断的大小, 单位M 
            WORD  wSegmentState;   //本片断状态 0 刻录正常，1 刻录异常，2 不刻录审讯
			BYTE  byRes2[288];     //保留
		}struInquestRet;
		struct //流id录像查询结果
		{
			DWORD dwRecordType;	//录像类型 0-定时录像 1-移动侦测 2-报警录像 3-报警|移动侦测 4-报警&移动侦测 5-命令触发 6-手动录像 7-震动报警 8-环境触发 9-智能报警 10-回传录像
			DWORD dwRecordLength;	//录像大小
			BYTE  byLockFlag;    // 锁定标志 0：没锁定 1：锁定
			BYTE  byDrawFrameType;    // 0：非抽帧录像 1：抽帧录像
			BYTE  byRes1[2];
			BYTE  byFileName[NAME_LEN]; 	//文件名
			DWORD dwFileIndex;    		// 存档卷上的文件索引
			BYTE  byRes[256];
		}struStreamIDRet;
	}uSeniorRet;
}NET_DVR_SEARCH_EVENT_RET, *LPNET_DVR_SEARCH_EVENT_RET;

//SDK_V35  2009-10-26

// 标定配置类型
typedef enum tagCALIBRATE_TYPE
{
    PDC_CALIBRATE  = 0x01,  // PDC 标定
    BEHAVIOR_OUT_CALIBRATE  = 0x02, //行为室外场景标定  
    BEHAVIOR_IN_CALIBRATE = 0x03,    // 行为室内场景标定 
    ITS_CALBIRETE       = 0x04      //  交通事件标定
}CALIBRATE_TYPE;

#define MAX_RECT_NUM  6
typedef struct tagNET_DVR_RECT_LIST
{	
    BYTE    byRectNum;    // 矩形框的个数
    BYTE    byRes1[11];  //保留字节 
    NET_VCA_RECT struVcaRect[MAX_RECT_NUM]; // 最大为6个Rect 
}NET_DVR_RECT_LIST, *LPNET_DVR_RECT_LIST;

// PDC 标定参数
typedef struct tagNET_DVR_PDC_CALIBRATION
{
    NET_DVR_RECT_LIST struRectList;       // 标定矩形框列表
    BYTE           byRes[120];       // 保留字节 
}NET_DVR_PDC_CALIBRATION, *LPNET_DVR_PDC_CALIBRATION;


// 标定线的属性类别，用来表示当前标定线在实际表示的是高度线还是长度线。
typedef enum tagLINE_MODE
{
    HEIGHT_LINE,        //高度样本线
    LENGTH_LINE        //长度样本线
}LINE_MODE;
/*
在设置标定信息的时候，如果相应位设置了使能，并设置相关参数，
若没有设置使能，则标定后可以获取相关的摄像机参数
*/
typedef struct tagNET_DVR_CAMERA_PARAM
{
    BYTE    byEnableHeight;     // 是否使能设置摄像机高度线
    BYTE    byEnableAngle;      // 是否使能设置摄像机俯仰角度
    BYTE    byEnableHorizon;    // 是否使能设置摄像机地平线
    BYTE    byRes[5];   // 保留字节 
    float   fCameraHeight;    // 摄像机高度
    float   fCameraAngle;     // 摄像机俯仰角度
    float   fHorizon;         // 场景中的地平线
}NET_DVR_CAMERA_PARAM, *LPNET_DVR_CAMERA_PARAM;
/*
当fValue表示目标高度的时候，struStartPoint和struEndPoint分别表示目标头部点和脚部点。
当fValue表示线段长度的时候，struStartPoint和struEndPoint分别表示线段起始点和终点，
mode表示当前样本线表示高度线还是长度线。
*/
typedef struct tagNET_DVR_LINE_SEGMENT
{
    BYTE            byLineMode;     // 参照 LINE_MODE
    BYTE            byRes[3];       // 保留字节 
    NET_VCA_POINT   struStartPoint;  
    NET_VCA_POINT   struEndPoint;
    float           fValue;
}NET_DVR_LINE_SEGMENT, *LPNET_DVR_LINE_SEGMENT;

#define  MAX_LINE_SEG_NUM 8

/*
标定样本线目前需要4-8调样本线，以获取摄像机相关参数
*/
typedef struct tagNET_DVR_BEHAVIOR_OUT_CALIBRATION
{
    DWORD                   dwLineSegNum;          // 样本线个数
    NET_DVR_LINE_SEGMENT    struLineSegment[MAX_LINE_SEG_NUM];    // 样本线最大个数
    NET_DVR_CAMERA_PARAM    struCameraParam;    // 摄像机参数
    BYTE byRes[20];
}NET_DVR_BEHAVIOR_OUT_CALIBRATION, *LPNET_DVR_BEHAVIOR_OUT_CALIBRATION;

/*
该结构体表示IAS智能库标定样本，
其中包括一个目标框和一条对应的高度标定线；
目标框为站立的人体外接矩形框；高度线样本标识从人头顶点到脚点的标定线；
用归一化坐标表示；
*/
typedef struct tagNET_DVR_IN_CAL_SAMPLE
{
    NET_VCA_RECT struVcaRect;   // 目标框
    NET_DVR_LINE_SEGMENT struLineSegment;    // 高度标定线
}NET_DVR_IN_CAL_SAMPLE, *LPNET_DVR_IN_CAL_SAMPLE;

#define  MAX_SAMPLE_NUM 5

typedef struct tagNET_DVR_BEHAVIOR_IN_CALIBRATION 
{
    DWORD    dwCalSampleNum;      //  标定样本个数
    NET_DVR_IN_CAL_SAMPLE  struCalSample[MAX_SAMPLE_NUM]; // 标定样本最大个数
    NET_DVR_CAMERA_PARAM    struCameraParam;    // 摄像机参数
    BYTE byRes[16];
}NET_DVR_BEHAVIOR_IN_CALIBRATION, *LPNET_DVR_BEHAVIOR_IN_CALIBRATION;

#define  CALIB_PT_NUM 4
typedef struct tagNET_DVR_ITS_CALIBRATION
{
    DWORD dwPointNum; //标定点数
    NET_VCA_POINT struPoint[CALIB_PT_NUM]; //图像坐标
    float       fWidth;
    float       fHeight;
    BYTE        byRes1[100];        // 保留字节
}NET_DVR_ITS_CALIBRATION, *LPNET_DVR_ITS_CALIBRATION;

// 标定参数联合体
// 后续的相关标定参数可以放在该结构里面
typedef union tagNET_DVR_CALIBRATION_PRARM_UNION
{
    BYTE byRes[240];                    //联合体结构大小
    NET_DVR_PDC_CALIBRATION struPDCCalibration;  //PDC 标定参数
    NET_DVR_BEHAVIOR_OUT_CALIBRATION  struBehaviorOutCalibration;  //  行为室外场景标定  主要应用于IVS等
    NET_DVR_BEHAVIOR_IN_CALIBRATION  struBehaviorInCalibration;     // 行为室内场景标定，主要应用IAS等 
    NET_DVR_ITS_CALIBRATION struITSCalibration;
}NET_DVR_CALIBRATION_PRARM_UNION, *LPNET_DVR_CALIBRATION_PRARM_UNION;


// 标定配置结构
typedef struct tagNET_DVR_CALIBRATION_CFG
{
    DWORD   dwSize;               //标定结构大小
    BYTE    byEnable;           // 是否启用标定
    BYTE    byCalibrationType;    // 标定类型 根据不同类型在联合体类选择不同的标定 参考CALIBRATE_TYPE
    BYTE    byRes1[2];
    NET_DVR_CALIBRATION_PRARM_UNION uCalibrateParam;  // 标定参数联合体
    BYTE    byRes2[12];
}NET_DVR_CALIBRATION_CFG, *LPNET_DVR_CALIBRATION_CFG; 

//流量统计方向结构体
typedef struct  tagNET_DVR_PDC_ENTER_DIRECTION
{
    NET_VCA_POINT struStartPoint; //流量统计方向起始点
    NET_VCA_POINT struEndPoint;    // 流量统计方向结束点 
}NET_DVR_PDC_ENTER_DIRECTION, *LPNET_DVR_PDC_ENTER_DIRECTION;

typedef struct tagNET_DVR_PDC_RULE_CFG
{
    DWORD           dwSize;              //结构大小
    BYTE            byEnable;             // 是否激活规则;
    BYTE            byRes1[23];       // 保留字节 
    NET_VCA_POLYGON          struPolygon;            // 多边形
    NET_DVR_PDC_ENTER_DIRECTION  struEnterDirection;    // 流量进入方向
} NET_DVR_PDC_RULE_CFG, *LPNET_DVR_PDC_RULE_CFG;

typedef struct tagNET_DVR_PDC_RULE_CFG_V41
{
    DWORD           dwSize;              //结构大小
    BYTE            byEnable;             // 是否激活规则;
	BYTE            byRes1[23];       // 保留字节 
    NET_VCA_POLYGON struPolygon;            // 多边形
	NET_DVR_PDC_ENTER_DIRECTION  struEnterDirection;    // 流量进入方向
	NET_DVR_SCHEDTIME struAlarmTime[MAX_DAYS][MAX_TIMESEGMENT_V30];//布防时间
	NET_DVR_TIME_EX struDayStartTime; //白天开始时间，时分秒有效
	NET_DVR_TIME_EX struNightStartTime; //夜晚开始时间，时分秒有效
	BYTE            byRes[100];       // 保留字节
}NET_DVR_PDC_RULE_CFG_V41, *LPNET_DVR_PDC_RULE_CFG_V41;

//试用版信息结构体
typedef struct tagNET_DVR_TRIAL_VERSION_CFG
{
	DWORD dwSize;
	WORD wReserveTime; //试用期剩余时间，0xffff表示无效，单位：天
    BYTE byRes[62];
}NET_DVR_TRIAL_VERSION_CFG, *LPNET_DVR_TRIAL_VERSION_CFG;

typedef struct tagNET_DVR_SYN_CHANNEL_NAME_PARAM
{
	DWORD dwSize;
	DWORD dwChannel; //通道号
	BYTE  byRes[64]; 
}NET_DVR_SYN_CHANNEL_NAME_PARAM, *LPNET_DVR_SYN_CHANNEL_NAME_PARAM;

typedef struct tagNET_DVR_RESET_COUNTER_CFG
{
	DWORD dwSize;
	BYTE  byEnable; //是否启用，0-不启用，1-启用
	BYTE  byRes1[3];
	NET_DVR_TIME_EX struTime[MAX_DAYS];//数据清零时间，时分秒有效
	BYTE  byRes[64]; 
}NET_DVR_RESET_COUNTER_CFG, *LPNET_DVR_RESET_COUNTER_CFG;

typedef struct tagNET_DVR_VCA_CTRLINFO_COND
{
	DWORD dwSize;
    NET_DVR_STREAM_INFO  struStreamInfo;
	BYTE byRes[64];
}NET_DVR_VCA_CTRLINFO_COND, *LPNET_DVR_VCA_CTRLINFO_COND;

typedef struct tagNET_DVR_VCA_CTRLINFO_CFG
{
	DWORD  dwSize;
    BYTE   byVCAEnable;     //是否开启智能
	BYTE   byVCAType;       //智能能力类型，VCA_CHAN_ABILITY_TYPE 
	BYTE   byStreamWithVCA; //码流中是否带智能信息
    BYTE   byMode;			//模式，ATM 能力时参照VCA_CHAN_MODE_TYPE ,TFS 能力时参照 TFS_CHAN_MODE_TYPE，行为分析完整版时参照BEHAVIOR_SCENE_MODE_TYPE
	BYTE   byControlType;   //控制类型，按位表示，0-否，1-是
	                        //byControlType &1 是否启用抓拍功能
                            //byControlType &2 是否启用联动前端设备
	BYTE   byRes[83]; 		//保留，设置为0
}NET_DVR_VCA_CTRLINFO_CFG, *LPNET_DVR_VCA_CTRLINFO_CFG;

//设置人流量统计参数  复用行为内部关键字参数 
// HUMAN_GENERATE_RATE
// 目标生成速度参数，控制PDC库生成目标的速度。速度越快，目标越容易生成。当输入视频光照条件较差，对比度较低时，或者设置的规则区域较小时，应加快目标生成速度， 避免目标的漏检；当输入视频中对比度较高时，或者规则区域较大时，应该降低目标生成速度，以减少误检。目标生成速度参数共有5级，1级速度最慢，5级最快，默认参数为3。
// 
// DETECT_SENSITIVE
// 目标检测灵敏度控制参数，控制PDC库中一个矩形区域被检测为目标的灵敏度。灵敏度越高，矩形区域越容易被检测为目标，灵敏度越低则越难检测为目标。当输入视频光照条件较差，对比度较低时，应提高检测灵敏度， 避免目标的漏检；当输入视频中对比度较高时，应该降低检测灵敏度，以减少误检。对应参数共有5级，级别1灵敏度最低，5级最高，默认级别为3。
// TRAJECTORY_LEN
// 轨迹生成长度控制参数，表示生成轨迹时要求目标的最大位移像素。对应参数共有5级，级别1，生成长度最长，轨迹生成最慢，5级生成长度最短，轨迹生成最快，默认级别为3。
// TRAJECT_CNT_LEN
// 轨迹计数长度控制参数，表示轨迹计数时要求目标的最大位移像素。对应参数共有5级，级别1，计数要求长度最长，轨迹计数最慢，5级计数要求长度最短，轨迹计数最快，默认级别为3。
// PREPROCESS
// 图像预处理控制参数，0 - 不处理；1 - 处理。默认为0；
// CAMERA_ANGLE
// 摄像机角度输入参数， 0 - 倾斜； 1 - 垂直。默认为0；
typedef enum tagPDC_PARAM_KEY
{
    HUMAN_GENERATE_RATE = 50,              // 目标生成速度 从50开始
    DETECT_SENSITIVE    = 51,               // 检测灵敏度
}PDC_PARAM_KEY;

typedef struct tagNET_DVR_PDC_TARGET_INFO
{
    DWORD       dwTargetID;                 // 目标id 
    NET_VCA_RECT struTargetRect;               // 目标框
    BYTE      byRes1[8];        // 保留字节
}NET_DVR_PDC_TARGET_INFO, *LPNET_DVR_PDC_TARGET_INFO;

typedef struct tagNET_DVR_PDC_TARGET_IN_FRAME
{
    BYTE           byTargetNum;                   //目标个数
    BYTE            byRes1[3];
        NET_DVR_PDC_TARGET_INFO  struTargetInfo[MAX_TARGET_NUM];   //目标信息数组
    BYTE    byRes2[8];                  // 保留字节
}NET_DVR_PDC_TARGET_IN_FRAME, *LPNET_DVR_PDC_TARGET_IN_FRAME;

typedef struct tagNET_DVR_PDC_ALRAM_INFO
{
    DWORD                       dwSize;           // PDC人流量报警上传结构体大小
    BYTE                        byMode;            // 0 单帧统计结果 1最小时间段统计结果  
    BYTE                        byChannel;           // 报警上传通道号
    BYTE                        byRes1[2];         // 保留字节   
    NET_VCA_DEV_INFO  	 struDevInfo;		        //前端设备信息
    union		
    {
        struct   // 单帧统计结果时使用
        {
            DWORD   dwRelativeTime;     // 相对时标
            DWORD   dwAbsTime;          // 绝对时标
            BYTE    byRes[92];            
        }struStatFrame;
        struct
        {
            NET_DVR_TIME                      tmStart; // 统计起始时间 
            NET_DVR_TIME                      tmEnd;  //  统计结束时间 
            BYTE byRes[92];
        }struStatTime;
    }uStatModeParam;  // 作为一个联合体 单帧的时候才有帧内目标信息 最小时间段统计结果需要统计时间 参数
    DWORD                       dwLeaveNum;        // 离开人数
    DWORD                       dwEnterNum;        // 进入人数
    BYTE                        byRes2[40];           // 保留字节
}NET_DVR_PDC_ALRAM_INFO, *LPNET_DVR_PDC_ALRAM_INFO;


//  人流量信息查询 
typedef struct tagNET_DVR_PDC_QUERY
{
    NET_DVR_TIME tmStart;
    NET_DVR_TIME tmEnd;
    DWORD       dwLeaveNum;
    DWORD       dwEnterNum; 
    BYTE        byRes1[256];
}NET_DVR_PDC_QUERY, *LPNET_DVR_PDC_QUERY;

typedef struct    tagNET_DVR_PTZ_POSITION
{
    // 是否启用场景，在设置场景行为规则的时候该字段无效，在设置球机本地配置场景位置信息时作为使能位
    BYTE byEnable;
    BYTE byRes1[3];  //保留
    BYTE byPtzPositionName[NAME_LEN]; //场景位置名称
    NET_DVR_PTZPOS struPtzPos; //ptz 坐标
    BYTE byRes2[40];
}NET_DVR_PTZ_POSITION, *LPNET_DVR_PTZ_POSITION;

typedef struct tagNET_DVR_POSITION_RULE_CFG
{
    DWORD                   dwSize;             // 结构大小 
    NET_DVR_PTZ_POSITION    struPtzPosition;    // 场景位置信息
    NET_VCA_RULECFG         struVcaRuleCfg;     //行为规则配置
    BYTE                    byRes2[80];         // 保留字节
}NET_DVR_POSITION_RULE_CFG, *LPNET_DVR_POSITION_RULE_CFG;

typedef struct tagNET_DVR_POSITION_RULE_CFG_V41
{
    DWORD                   dwSize;             // 结构大小 
    NET_DVR_PTZ_POSITION    struPtzPosition;    // 场景位置信息
	NET_VCA_RULECFG_V41         struVcaRuleCfg;     //行为规则配置
	BYTE  byTrackEnable; //是否启用跟踪
	BYTE  byRes1;
	WORD wTrackDuration; //跟踪持续时间，单位s
    BYTE                    byRes2[76];         // 保留字节
}NET_DVR_POSITION_RULE_CFG_V41, *LPNET_DVR_POSITION_RULE_CFG_V41;


typedef struct tagNET_DVR_LIMIT_ANGLE
{
    BYTE                byEnable;	// 是否启用场景限位功能
    BYTE				byRes1[3];
    NET_DVR_PTZPOS      struUp;     // 上限位
    NET_DVR_PTZPOS      struDown;   // 下限位
    NET_DVR_PTZPOS      struLeft;   // 左限位
    NET_DVR_PTZPOS      struRight;  // 右限位
    BYTE                byRes2[20];
}NET_DVR_LIMIT_ANGLE, *LPNET_DVR_LIMIT_ANGLE;

typedef struct tagNET_DVR_POSITION_INDEX
{
    BYTE    byIndex;    // 场景索引
    BYTE    byRes1;
    WORD	wDwell;	// 停留时间 
    BYTE    byRes2[4];   // 保留字节
}NET_DVR_POSITION_INDEX, *LPNET_DVR_POSITION_INDEX;

#define  MAX_POSITION_NUM 10
typedef struct tagNET_DVR_POSITION_TRACK_CFG
{
    DWORD dwSize;
    BYTE    byNum; // 场景个数
    BYTE    byRes1[3];
    NET_DVR_POSITION_INDEX   struPositionIndex[MAX_POSITION_NUM];
    BYTE    byRes2[8];
}NET_DVR_POSITION_TRACK_CFG, *LPNET_DVR_POSITION_TRACK_CFG;

//巡航路径场景信息
typedef struct tagNET_DVR_PATROL_SCENE_INFO
{
    WORD   wDwell;         // 停留时间 30-300
    BYTE   byPositionID;   // 场景号1-10，默认0表示该巡航点不添加场景
    BYTE   byRes[5];
}NET_DVR_PATROL_SCENE_INFO, *LPNET_DVR_PATROL_SCENE_INFO;

// 场景巡航跟踪配置信息
typedef struct tagNET_DVR_PATROL_TRACKCFG
{
    DWORD  dwSize;                                 // 结构大小
    NET_DVR_PATROL_SCENE_INFO struPatrolSceneInfo[10];    // 巡航路径
    BYTE   byRes[16];                              // 保留字节
}NET_DVR_PATROL_TRACKCFG, *LPNET_DVR_PATROL_TRACKCFG;

//球机本地规则菜单配置结构体
typedef struct tagNET_DVR_TRACK_PARAMCFG
{
    DWORD   dwSize;             // 结构大小
    WORD    wAlarmDelayTime;    // 报警延时时间，目前球机只支持全局入侵 范围1-120秒
    WORD    wTrackHoldTime;     // 报警跟踪持续时间  范围0-300秒
    BYTE    byTrackMode;        //  参照 IPDOME_TRACK_MODE
    BYTE	 byPreDirection;	// 跟踪方向预判 0-不启用 1-启用
    BYTE 	 byTrackSmooth;	    // 跟踪连续  0-不启用 1-启用
    BYTE	 byZoomAdjust;	// 倍率系数调整 参见下表
    BYTE	byMaxTrackZoom;	//最大跟踪倍率系数,0-表示默认倍率系数,等级6-标定值*1.0(默认),1-5为缩小标定值，值越小，缩小的比例越大,7-15为放大，值越大，放大的比例越大
	BYTE   byStopTrackWhenFindFace;  //人脸检测到后是否停止跟踪 0-否 1-是
	BYTE   byStopTrackThreshold;   //跟踪终止评分阈值
	BYTE   byRes[9];          //  保留字节                
}NET_DVR_TRACK_PARAMCFG, *LPNET_DVR_TRACK_PARAMCFG;

// 球机机芯参数
typedef struct tagNET_DVR_DOME_MOVEMENT_PARAM
{
    WORD wMaxZoom;   // 球机最大倍率系数
    BYTE    byRes[42];  // 保留字节
}NET_DVR_DOME_MOVEMENT_PARAM, *LPNET_DVR_DOME_MOVEMENT_PARAM;

/********************************智能交通事件 begin****************************************/
#define  MAX_REGION_NUM			8       // 区域列表最大数目
#define  MAX_TPS_RULE			8       // 最大参数规则数目
#define  MAX_AID_RULE			8      // 最大事件规则数目
#define  MAX_LANE_NUM			8		// 最大车道数目

//交通事件类型，
typedef enum tagTRAFFIC_AID_TYPE
{
    CONGESTION          = 0x01,    //拥堵
    PARKING             = 0x02,    //停车  
    INVERSE             = 0x04,    //逆行
    PEDESTRIAN          = 0x08,    //行人                      
    DEBRIS              = 0x10,    //遗留物 抛洒物碎片 
    SMOKE               = 0x20,    //烟雾  
	OVERLINE            = 0x40,     //压线
	VEHICLE_CONTROL_LIST  = 0x80,  //黑名单数据
	SPEED                 = 0x100  //超速
}TRAFFIC_AID_TYPE;

typedef enum tagTRAFFIC_SCENE_MODE
{
	FREEWAY = 0,	//  高速户外场景
	TUNNEL,         //  高速隧道场景
	BRIDGE          //  高速桥梁场景
}TRAFFIC_SCENE_MODE;

typedef enum tagITS_ABILITY_TYPE
{
    ITS_CONGESTION_ABILITY             = 0x01,      //拥堵
    ITS_PARKING_ABILITY                = 0x02,      //停车  
    ITS_INVERSE_ABILITY                = 0x04,      //逆行
    ITS_PEDESTRIAN_ABILITY             = 0x08,      //行人                      
    ITS_DEBRIS_ABILITY                 = 0x10,      //遗留物 抛洒物碎片
    ITS_SMOKE_ABILITY                  = 0x20,      //烟雾-隧道
    ITS_OVERLINE_ABILITY               = 0x40,      //压线
	ITS_VEHICLE_CONTROL_LIST_ABILITY   = 0x80,		//黑名单数据
	ITS_SPEED_ABILITY				   = 0x100,	//超速	

    ITS_LANE_VOLUME_ABILITY            = 0x010000,  //车道流量
    ITS_LANE_VELOCITY_ABILITY          = 0x020000,  //车道平均速度
    ITS_TIME_HEADWAY_ABILITY           = 0x040000,  //车头时距
    ITS_SPACE_HEADWAY_ABILITY          = 0x080000,  //车头间距
    ITS_TIME_OCCUPANCY_RATIO_ABILITY   = 0x100000,  //车道占有率，（时间上)
    ITS_SPACE_OCCUPANCY_RATIO_ABILITY  = 0x200000,  //车道占有率，百分比计算（空间上)
    ITS_LANE_QUEUE_ABILITY             = 0x400000,  //排队长度
	ITS_VEHICLE_TYPE_ABILITY           = 0x800000,  //车辆类型
	ITS_TRAFFIC_STATE_ABILITY          = 0x1000000  //交通状态
}ITS_ABILITY_TYPE;

// 交通统计参数
typedef enum tagITS_TPS_TYPE
{
    LANE_VOLUME           = 0x01,    //车道流量
    LANE_VELOCITY         = 0x02,    //车道速度
    TIME_HEADWAY          = 0x04,    //车头时距
    SPACE_HEADWAY         = 0x08,    //车头间距
    TIME_OCCUPANCY_RATIO  = 0x10,    //车道占有率 (时间上)
    SPACE_OCCUPANCY_RATIO = 0x20,    //车道占有率，百分比计算(空间上)
    QUEUE                 = 0x40,    //排队长度
	VEHICLE_TYPE          = 0x80,    //车辆类型
	TRAFFIC_STATE         = 0x100    //交通状态
}ITS_TPS_TYPE; 

typedef struct tagNET_DVR_REGION_LIST 
{
	DWORD	dwSize;	// 结构体大小
	BYTE    byNum;      // 区域个数
	BYTE    byRes1[3];    // 保留字节
	NET_VCA_POLYGON struPolygon[MAX_REGION_NUM]; // 区域
	BYTE	byRes2[20];	// 保留字节
}NET_DVR_REGION_LIST,*LPNET_DVR_REGION_LIST;


// 方向结构体
typedef struct tagNET_DVR_DIRECTION
{
    NET_VCA_POINT struStartPoint;   // 方向起始点
    NET_VCA_POINT struEndPoint;     // 方向结束点 
}NET_DVR_DIRECTION, *LPNET_DVR_DIRECTION;

// 单个车道
typedef struct tagNET_DVR_ONE_LANE
{
	BYTE	byEnable;                   // 车道是否启用
	BYTE	byRes1[11];	                // 保留字节
	BYTE    byLaneName[NAME_LEN];       // 车道规则名称
	NET_DVR_DIRECTION struFlowDirection;// 车道内车流方向
	NET_VCA_POLYGON struPolygon;		// 车道区域
}NET_DVR_ONE_LANE, *LPNET_DVR_ONE_LANE;

// 车道配置
typedef struct tagNET_DVR_LANE_CFG
{
	DWORD	dwSize;	// 结构体大小
	NET_DVR_ONE_LANE struLane[MAX_LANE_NUM];	// 车道参数 数组下标作为车道ID，
	BYTE	byRes1[40];	 // 保留字节
}NET_DVR_LANE_CFG, *LPNET_DVR_LANE_CFG;

// 交通事件参数
typedef struct tagNET_DVR_AID_PARAM
{
	WORD    wParkingDuration;       // 违停检测灵敏度  10-120s
	WORD    wPedestrianDuration;    // 行人持续时间    1-120s
	WORD    wDebrisDuration;        // 抛洒物持续时间  10-120s
	WORD    wCongestionLength;      // 拥堵长度阈值    5-200（米）
	WORD    wCongestionDuration;    // 拥堵持续参数    10-120s
	WORD    wInverseDuration;       // 逆行持续时间    1-10s
	WORD    wInverseDistance;       // 逆行距离阈值 单位m 范围[2-100] 默认 10米
	WORD    wInverseAngleTolerance; // 允许角度偏差 90-180度,车流与逆行允许的夹角
	WORD    wIllegalParkingTime;    // 违停时间[4,60]，单位：分钟 ,TFS(交通违章取证) 城市模式下
	WORD    wIllegalParkingPicNum;  // 违停图片数量[1,6], TFS(交通违章取证) 城市模式下
	BYTE    byMergePic;             // 图片拼接,TFS 城市模式下 0- 不拼接 1- 拼接
	BYTE    byRes1[23];             // 保留字节
}NET_DVR_AID_PARAM, *LPNET_DVR_AID_PARAM;

// 单条交通事件规则结构体
typedef struct tagNET_DVR_ONE_AID_RULE
{   
    BYTE    byEnable;                   // 是否启用事件规则
    BYTE    byRes1[3];                  // 保留字节
    BYTE    byRuleName[NAME_LEN];       // 规则名称 
    DWORD   dwEventType;                // 交通事件检测类型 TRAFFIC_AID_TYPE
    NET_VCA_SIZE_FILTER struSizeFilter; // 尺寸过滤器
    NET_VCA_POLYGON     struPolygon;    // 规则区域
    NET_DVR_AID_PARAM   struAIDParam;   //  事件参数
    NET_DVR_SCHEDTIME   struAlarmTime[MAX_DAYS][MAX_TIMESEGMENT_2];//布防时间
    NET_DVR_HANDLEEXCEPTION_V30 struHandleType;	  //处理方式 
	BYTE byRelRecordChan[MAX_CHANNUM_V30];        //报警触发的录象通道,为1表示触发该通道
    BYTE byRes2[20];
}NET_DVR_ONE_AID_RULE, *LPNET_DVR_ONE_AID_RULE;

// 交通事件规则
typedef struct tagNET_DVR_AID_RULECFG
{
    DWORD   dwSize;                    // 结构体大小 
    BYTE    byPicProType;              //报警时图片处理方式 0-不处理 非0-上传
    BYTE    byRes1[3];                 // 保留字节
    NET_DVR_JPEGPARA struPictureParam; //图片规格结构
    NET_DVR_ONE_AID_RULE  struOneAIDRule[MAX_AID_RULE];
    BYTE    byRes2[32];
}NET_DVR_AID_RULECFG, *LPNET_DVR_AID_RULECFG;

// 单条交通事件规则结构体(扩展)
typedef struct tagNET_DVR_ONE_AID_RULE_V41
{   
    BYTE                        byEnable;                 // 是否启用事件规则
    BYTE                        byRes1[3];                // 保留字节
    BYTE                        byRuleName[NAME_LEN];     // 规则名称 
    DWORD                       dwEventType;              // 交通事件检测类型 TRAFFIC_AID_TYPE
    NET_VCA_SIZE_FILTER         struSizeFilter;           // 尺寸过滤器
    NET_VCA_POLYGON             struPolygon;              // 规则区域
    NET_DVR_AID_PARAM           struAIDParam;             // 事件参数
    NET_DVR_SCHEDTIME           struAlarmTime[MAX_DAYS][MAX_TIMESEGMENT_V30];// 布防时间段
    NET_DVR_HANDLEEXCEPTION_V30 struHandleType;	          //处理方式 
	BYTE                        byRelRecordChan[MAX_IVMS_IP_CHANNEL]; //报警触发的录象通道：1表示触发该通道；0表示不触发 
	BYTE                        byRes2[60];               //保留
}NET_DVR_ONE_AID_RULE_V41, *LPNET_DVR_ONE_AID_RULE_V41;

// 交通事件规则(扩展)
typedef struct tagNET_DVR_AID_RULECFG_V41
{
	DWORD   dwSize;                     // 结构体大小 
	BYTE    byPicProType;               // 报警时图片处理方式 0-不处理 非0-上传
	BYTE    byRes1[3];                  // 保留字节
	NET_DVR_JPEGPARA struPictureParam; 	// 图片规格结构
    NET_DVR_ONE_AID_RULE_V41  struAIDRule[MAX_AID_RULE];  //规则数组
    BYTE    byRes2[128];                //保留
} NET_DVR_AID_RULECFG_V41, *LPNET_DVR_AID_RULECFG_V41;

// 交通统计参数结构体
typedef struct tagNET_DVR_ONE_TPS_RULE
{
    BYTE    byEnable;                   //是否使能车道交通规则参数
	BYTE	byLaneID;		            //车道ID
    BYTE    byRes1[2];
    DWORD   dwCalcType;                 //统计参数类型ITS_TPS_TYPE
    NET_VCA_SIZE_FILTER struSizeFilter; //尺寸过滤器 
    NET_VCA_POLYGON struVitrualLoop;    //虚拟线圈
    NET_DVR_SCHEDTIME struAlarmTime[MAX_DAYS][MAX_TIMESEGMENT_2];//布防时间
    NET_DVR_HANDLEEXCEPTION_V30 struHandleType;	//处理方式,一般为处理是否上传中心，其他功能不需要
    BYTE    byRes2[20];                         //保留字节
}NET_DVR_ONE_TPS_RULE, *LPNET_DVR_ONE_TPS_RULE;

// 交通参数统计规则配置结构体
typedef struct tagNET_DVR_TPS_RULECFG
{
	DWORD   dwSize;              // 结构大小
	NET_DVR_ONE_TPS_RULE struOneTpsRule[MAX_TPS_RULE]; // 下标对应交通参数ID
	BYTE    byRes2[40];         // 保留字节
}NET_DVR_TPS_RULECFG, *LPNET_DVR_TPS_RULECFG;

// 交通统计参数结构体(扩展)
typedef struct tagNET_DVR_ONE_TPS_RULE_V41
{
    BYTE    byEnable;                     //是否使能车道交通规则参数
	BYTE	byLaneID;		              //车道ID
    BYTE    byRes1[2];                    //保留
    DWORD   dwCalcType;                   // 统计参数类型ITS_TPS_TYPE
    NET_VCA_SIZE_FILTER  struSizeFilter;  //尺寸过滤器 
    NET_VCA_POLYGON      struVitrualLoop; //虚拟线圈
    NET_DVR_SCHEDTIME    struAlarmTime[MAX_DAYS][MAX_TIMESEGMENT_V30];//布防时间
	NET_DVR_HANDLEEXCEPTION_V30 struHandleType;	   //处理方式 
    BYTE    byRes2[60];                   // 保留字节
}NET_DVR_ONE_TPS_RULE_V41, *LPNET_DVR_ONE_TPS_RULE_V41;


// 交通参数统计规则配置结构体(扩展)
typedef struct tagNET_DVR_TPS_RULECFG_V41
{
	DWORD   dwSize;         // 结构大小
	NET_DVR_ONE_TPS_RULE_V41 struOneTpsRule[MAX_TPS_RULE]; // 下标对应交通参数ID
	BYTE    byRes[128];     // 保留
}NET_DVR_TPS_RULECFG_V41, *LPNET_DVR_TPS_RULECFG_V41;

// 交通事件信息
typedef struct tagNET_DVR_AID_INFO
{
    BYTE            byRuleID;   // 规则序号，为规则配置结构下标，0-16
    BYTE            byRes1[3];
    BYTE            byRuleName[NAME_LEN]; //  规则名称
    DWORD           dwAIDType;  // 报警事件类型
    NET_DVR_DIRECTION   struDirect; // 报警指向区域  
	BYTE    bySpeedLimit; //限速值，单位km/h[0,255]
	BYTE    byCurrentSpeed; //当前速度值，单位km/h[0,255]
    BYTE            byRes2[38];  // 保留字节 
}NET_DVR_AID_INFO, *LPNET_DVR_AID_INFO;

// 交通事件报警 
typedef struct tagNET_DVR_AID_ALARM
{
    DWORD               dwSize;         // 结构长度
    DWORD               dwRelativeTime;	// 相对时标
    DWORD               dwAbsTime;		// 绝对时标
    NET_VCA_DEV_INFO  	struDevInfo;	// 前端设备信息
    NET_DVR_AID_INFO    struAIDInfo;    // 交通事件信息
    DWORD               dwPicDataLen;   // 返回图片的长度 为0表示没有图片，大于0表示该结构后面紧跟图片数据
    BYTE                *pImage;        // 指向图片的指针 
    BYTE                byRes[40];      // 保留字节  
}NET_DVR_AID_ALARM, *LPNET_DVR_AID_ALARM;

// 车道队列结构体 
typedef struct tagNET_DVR_LANE_QUEUE
{
    NET_VCA_POINT   struHead;       //队列头
    NET_VCA_POINT   struTail;       //队列尾
    DWORD           dwLength;      //实际队列长度 单位为米 [0-500]
}NET_DVR_LANE_QUEUE, *LPNET_DVR_LANE_QUEUE; 

typedef enum tagTRAFFIC_DATA_VARY_TYPE
{
    NO_VARY,         //无变化 
    VEHICLE_ENTER,   //车辆进入虚拟线圈
    VEHICLE_LEAVE,   //车辆离开虚拟线圈 
    UEUE_VARY        //队列变化             
}TRAFFIC_DATA_VARY_TYPE; 

typedef struct tagNET_DVR_LANE_PARAM
{
    BYTE    byRuleName[NAME_LEN];  //车道规则名称 
    BYTE    byRuleID;              //规则序号，为规则配置结构下标，0-7 
    BYTE    byVaryType;            //车道交通参数变化类型 参照 TRAFFIC_DATA_VARY_TYPE
	BYTE	byLaneType;			   //车道上行或下行
	BYTE	byRes1;
    DWORD    dwLaneVolume;         //车道流量 ，统计有多少车子通过
    DWORD   dwLaneVelocity;        //车道速度，公里计算
    DWORD   dwTimeHeadway;         //车头时距，以秒计算
    DWORD   dwSpaceHeadway;        //车头间距，以米来计算
    float   fSpaceOccupyRation;    //车道占有率，百分比计算（空间上)
    NET_DVR_LANE_QUEUE  struLaneQueue;    //车道队列长度
    NET_VCA_POINT       struRuleLocation; //线圈规则的中心点位置
    BYTE    byRes2[32];
}NET_DVR_LANE_PARAM, *LPNET_DVR_LANE_PARAM;


typedef struct tagNET_DVR_TPS_INFO
{
    DWORD   dwLanNum;   // 交通参数的车道数目
    NET_DVR_LANE_PARAM  struLaneParam[MAX_TPS_RULE];
}NET_DVR_TPS_INFO, *LPNET_DVR_TPS_INFO;

typedef struct tagNET_DVR_TPS_ALARM
{
    DWORD             dwSize;          //结构体大小
    DWORD             dwRelativeTime;  //相对时标
    DWORD             dwAbsTime;       //绝对时标
    NET_VCA_DEV_INFO  struDevInfo;     //前端设备信息
    NET_DVR_TPS_INFO  struTPSInfo;     //交通事件信息
	BYTE              byRes1[32];      //保留字节
}NET_DVR_TPS_ALARM, *LPNET_DVR_TPS_ALARM;

typedef enum tagTRAFFIC_DATA_VARY_TYPE_EX_ENUM
{    
	ENUM_TRAFFIC_VARY_NO             = 0x00,   //无变化
	ENUM_TRAFFIC_VARY_VEHICLE_ENTER  = 0x01,   //车辆进入虚拟线圈
	ENUM_TRAFFIC_VARY_VEHICLE_LEAVE  = 0x02,   //车辆离开虚拟线圈
	ENUM_TRAFFIC_VARY_QUEUE          = 0x04,   //队列变化
	ENUM_TRAFFIC_VARY_STATISTIC      = 0x08,   //统计数据变化（每分钟变化一次包括平均速度，车道空间/时间占有率，交通状态）        
}TRAFFIC_DATA_VARY_TYPE_EX_ENUM;  

typedef struct tagNET_DVR_LANE_PARAM_V41
{
    BYTE               byRuleName[NAME_LEN]; // 车道规则名称
	BYTE               byRuleID;             // 规则序号，为规则配置结构下标，0-7 
	BYTE	           byLaneType;		     // 车道上行或下行
	BYTE               byTrafficState;       // 车道的交通状态，0-无效，1-畅通，2-拥挤，3-堵塞
    BYTE               byRes1;               // 保留
	DWORD              dwVaryType;           // 车道交通参数变化类型参照  TRAFFIC_DATA_VARY_TYPE_EX_ENUM，按位区分
	DWORD              dwTpsType;            // 数据变化类型标志，表示当前上传的统计参数中，哪些数据有效，参照ITS_TPS_TYPE,按位区分
	DWORD              dwLaneVolume;	     // 车道流量，统计有多少车子通过
	DWORD              dwLaneVelocity;       // 车道速度，公里计算
	DWORD              dwTimeHeadway ;       // 车头时距，以秒计算
	DWORD              dwSpaceHeadway;       // 车头间距，以米来计算
	float              fSpaceOccupyRation;   // 车道占有率，百分比计算（空间上)
	float              fTimeOccupyRation;    // 时间占有率，百分比计算
	DWORD              dwLightVehicle;       // 小型车数量
	DWORD              dwMidVehicle;         // 中型车数量
	DWORD              dwHeavyVehicle;       // 重型车数量
	NET_DVR_LANE_QUEUE struLaneQueue;        // 车道队列长度
	NET_VCA_POINT      struRuleLocation;     // 规则位置虚拟线圈的中心
	BYTE               byRes2[64];           // 保留
}NET_DVR_LANE_PARAM_V41, *LPNET_DVR_LANE_PARAM_V41;


typedef struct tagNET_DVR_TPS_INFO_V41
{
    DWORD                   dwLanNum;          // 交通参数的车道数目
	NET_DVR_LANE_PARAM_V41  struLaneParam[MAX_TPS_RULE];
	BYTE                    byRes[32];         //保留
}NET_DVR_TPS_INFO_V41, *LPNET_DVR_TPS_INFO_V41;

// 人脸规则配置 
typedef struct tagNET_DVR_FACEDETECT_RULECFG
{
    DWORD          dwSize;              // 结构体大小
    BYTE           byEnable;            // 是否启用
    BYTE           byEventType;			//警戒事件类型， 0-异常人脸; 1-正常人脸;2-异常人脸&正常人脸;
	BYTE           byUpLastAlarm;       //2011-04-06 是否先上传最近一次的报警
	BYTE           byUpFacePic; //是否上传人脸子图，0-否，1-是	
    BYTE           byRuleName[NAME_LEN];
    NET_VCA_POLYGON     struVcaPolygon;    // 人脸检测规则区域
    BYTE           byPicProType;	//报警时图片处理方式 0-不处理 非0-上传
    BYTE           bySensitivity;   // 规则灵敏度
    WORD            wDuration;      // 触发人脸报警时间阈值
    NET_DVR_JPEGPARA    struPictureParam; 		//图片规格结构
    NET_VCA_SIZE_FILTER struSizeFilter;         //尺寸过滤器
    NET_DVR_SCHEDTIME   struAlarmTime[MAX_DAYS][MAX_TIMESEGMENT_2];//布防时间
    NET_DVR_HANDLEEXCEPTION_V30 struHandleType;	  //处理方式 
    BYTE           byRelRecordChan[MAX_CHANNUM_V30];			//报警触发的录象通道,为1表示触发该通道
	BYTE           byPicRecordEnable;  /*2012-3-1是否启用图片存储, 0-不启用, 1-启用*/
    BYTE            byRes2[39];         //保留字节
}NET_DVR_FACEDETECT_RULECFG, *LPNET_DVR_FACEDETECT_RULECFG;

typedef struct tagNET_DVR_FACE_PIPCFG
{	
	BYTE byEnable; //是否开启画中画
	BYTE byBackChannel; //背景通道号（面板通道）
	BYTE byPosition; //叠加位置，0-左上,1-左下,2-右上,3-右下
	BYTE byPIPDiv; //分屏系数(人脸画面:面板画面)，0-1:4,1-1:9,2-1:16
	BYTE byRes[4];
}NET_DVR_FACE_PIPCFG, *LPNET_DVR_FACE_PIPCFG;

typedef struct tagNET_DVR_FACEDETECT_RULECFG_V41
{
    DWORD dwSize;              // 结构体大小
    BYTE  byEnable;            // 是否启用
    BYTE  byEventType;			//警戒事件类型， 0-异常人脸; 1-正常人脸;2-异常人脸&正常人脸;
	BYTE  byUpLastAlarm;       //2011-04-06 是否先上传最近一次的报警
	BYTE  byUpFacePic; //是否上传人脸子图，0-否，1-是	
    BYTE  byRuleName[NAME_LEN];
    NET_VCA_POLYGON struVcaPolygon;    // 人脸检测规则区域
    BYTE  byPicProType;	//报警时图片处理方式 0-不处理 非0-上传
    BYTE  bySensitivity;   // 规则灵敏度
    WORD  wDuration;      // 触发人脸报警时间阈值
    NET_DVR_JPEGPARA    struPictureParam; 		//图片规格结构
    NET_VCA_SIZE_FILTER struSizeFilter;         //尺寸过滤器
    NET_DVR_SCHEDTIME   struAlarmTime[MAX_DAYS][MAX_TIMESEGMENT_V30];//布防时间
    NET_DVR_HANDLEEXCEPTION_V30 struHandleType;	  //处理方式 
	BYTE  byRelRecordChan[MAX_CHANNUM_V30];			//报警触发的录象通道,为1表示触发该通道
	BYTE  byPicRecordEnable;  /*2012-10-22是否启用图片存储, 0-不启用, 1-启用*/
	BYTE  byRes1;
	WORD  wAlarmDelay; //2012-10-22智能报警延时，0-5s,1-10,2-30s,3-60s,4-120s,5-300s,6-600s
    NET_DVR_FACE_PIPCFG struFacePIP; //2012-11-7画中画参数
    BYTE  byRes[28];         //保留字节
}NET_DVR_FACEDETECT_RULECFG_V41, *LPNET_DVR_FACEDETECT_RULECFG_V41;

typedef struct tagNET_DVR_FACEDETECT_ALARM
{
    DWORD  dwSize;     		// 结构大小
    DWORD 	dwRelativeTime; // 相对时标
    DWORD	dwAbsTime;			// 绝对时标
    BYTE        byRuleName[NAME_LEN];   // 规则名称
    NET_VCA_TARGET_INFO  struTargetInfo;	//报警目标信息
    NET_VCA_DEV_INFO  	 struDevInfo;		//前端设备信息
    DWORD dwPicDataLen;						//返回图片的长度 为0表示没有图片，大于0表示该结构后面紧跟图片数据*/
    BYTE		byAlarmPicType;			// 0-异常人脸报警图片 1- 人脸图片,2-多张人脸 
	BYTE     byPanelChan;        /*2012-3-1人脸通道关联的面板通道*/
    BYTE byRes1[2];
	DWORD dwFacePicDataLen;			//人脸图片的长度 为0表示没有图片，大于0表示该结构后面紧跟图片数据*/
    BYTE   byRes[48];              // 保留字节
    BYTE  *pFaceImage; //指向人脸图指针
    BYTE  *pImage;   						//指向图片的指针
}NET_DVR_FACEDETECT_ALARM, *LPNET_DVR_FACEDETECT_ALARM;

typedef struct tagNET_DVR_EVENT_PARAM_UNION
{
    DWORD   uLen[3];        	// 联合体大小为12字节
    DWORD  dwHumanIn;  	//有无人接近 0 - 无人 1- 有人  
    float       fCrowdDensity;  // 人员聚集值
}NET_DVR_EVENT_PARAM_UNION, *LPNET_DVR_EVENT_PARAM_UNION;

// 目前只有有人无人事件和人员聚集事件实时报警上传
typedef struct tagNET_DVR_EVENT_INFO
{
    BYTE   byRuleID;				// Rule ID
    BYTE   byRes[3];				// 保留字节
    BYTE   byRuleName[NAME_LEN];	// 规则名称
    DWORD       dwEventType;    		// 参照VCA_EVENT_TYPE
    NET_DVR_EVENT_PARAM_UNION uEventParam;  // 
}NET_DVR_EVENT_INFO, *LPNET_DVR_EVENT_INFO;

typedef struct tagNET_DVR_EVENT_INFO_LIST
{
    BYTE			byNum;		// 事件实时信息个数
    BYTE			byRes1[3];			// 保留字节
    NET_DVR_EVENT_INFO struEventInfo[MAX_RULE_NUM];	// 事际实时信息
}NET_DVR_EVENT_INFO_LIST,*LPNET_DVR_EVENT_INFO_LIST;

typedef struct tagNET_DVR_RULE_INFO_ALARM
{
    DWORD 			dwSize;				// 结构体大小
    DWORD 		dwRelativeTime; 	// 相对时标
    DWORD		dwAbsTime;			// 绝对时标
    NET_VCA_DEV_INFO  	struDevInfo;		// 前端设备信息
    NET_DVR_EVENT_INFO_LIST struEventInfoList;	//事件信息列表
    BYTE			byRes2[40];			// 保留字节
}NET_DVR_RULE_INFO_ALARM, *LPNET_DVR_RULE_INFO_ALARM;

//单条场景时间段
typedef struct tagNET_DVR_ONE_SCENE_TIME
{
	BYTE     byActive;                     //0 -无效,1–有效
	BYTE     byRes1[3];                    //保留
	DWORD    dwSceneID;                    //场景ID
	NET_DVR_SCHEDTIME struEffectiveTime;   //场景起效时间
	BYTE     byRes2[16];                   //保留
}NET_DVR_ONE_SCENE_TIME, *LPNET_DVR_ONE_SCENE_TIME ;

//场景起效时间段配置
typedef struct tagNET_DVR_SCENE_TIME_CFG
{   
	DWORD  dwSize;                                               //结构大小
	NET_DVR_ONE_SCENE_TIME struSceneTime[MAX_SCENE_TIMESEG_NUM]; //场景时间段数组
	BYTE   byRes[64];                                            //保留
}NET_DVR_SCENE_TIME_CFG, *LPNET_DVR_SCENE_TIME_CFG;


//单条场景配置信息
typedef struct  tagNET_DVR_ONE_SCENE_CFG_
{    
	BYTE   byEnable;                 //是否启用该场景,0-不启用 1- 启用
	BYTE   byDirection;              //监测方向 1-上行，2-下行，3-双向，4-由东向西，5-由南向北，6-由西向东，7-由北向南，8-其它
	BYTE   byRes1[2];                //保留
	DWORD  dwSceneID;                //场景ID(只读), 0 - 表示该场景无效
	BYTE   bySceneName[NAME_LEN];    //场景名称
	NET_DVR_PTZPOS struPtzPos;       //ptz 坐标
	DWORD  dwTrackTime;              //球机跟踪时间[5,300] 秒，TFS(交通取证)模式下有效
    BYTE   byRes2[24];               //保留
}NET_DVR_ONE_SCENE_CFG, *LPNET_DVR_ONE_SCENE_CFG;

//场景配置结构体
typedef struct tagNET_DVR_SCENE_CFG
{
	DWORD dwSize;                                          //结构大小
	NET_DVR_ONE_SCENE_CFG struSceneCfg[MAX_ITS_SCENE_NUM]; //场景配置信息
	BYTE   byRes[40];                                      //保留
}NET_DVR_SCENE_CFG,*LPNET_DVR_SCENE_CFG;

//多场景操作条件
typedef struct tagNET_DVR_SCENE_COND
{
	DWORD   dwSize;       //结构大小
    LONG    lChannel;     //通道号
    DWORD   dwSceneID;    //场景ID, 0-表示该场景无效
	BYTE    byRes[48];    //保留
}NET_DVR_SCENE_COND, *LPNET_DVR_SCENE_COND;

//取证方式
typedef struct tagNET_DVR_FORENSICS_MODE
{
	DWORD  dwSize;      //结构大小
	BYTE   byMode;      // 0-手动取证 ,1-自动取证
	BYTE   byRes[23];   //保留
}NET_DVR_FORENSICS_MODE,*LPNET_DVR_FORENSICS_MODE;

//报警场景信息
typedef struct tagNET_DVR_SCENE_INFO_
{  
	DWORD           dwSceneID;              //场景ID, 0 - 表示该场景无效
	BYTE            bySceneName[NAME_LEN];  //场景名称
	BYTE            byDirection;            //监测方向 1-上行，2-下行，3-双向，4-由东向西，5-由南向北，6-由西向东，7-由北向南，8-其它
	BYTE            byRes1[3];              //保留
	NET_DVR_PTZPOS  struPtzPos;             //Ptz 坐标
	BYTE            byRes2[64] ;            //保留
}NET_DVR_SCENE_INFO,*LPNET_DVR_SCENE_INFO;

//交通事件报警(扩展)
typedef struct tagNET_DVR_AID_ALARM_V41
{
    DWORD              dwSize;              //结构长度
    DWORD              dwRelativeTime;	    //相对时标
    DWORD              dwAbsTime;			//绝对时标
    NET_VCA_DEV_INFO   struDevInfo;		    //前端设备信息
	NET_DVR_AID_INFO   struAIDInfo;         //交通事件信息
	NET_DVR_SCENE_INFO struSceneInfo;       //场景信息
    DWORD              dwPicDataLen;        //图片长度
	BYTE               *pImage; 			//指向图片的指针
    BYTE               byRes[128];          //保留
}NET_DVR_AID_ALARM_V41, *LPNET_DVR_AID_ALARM_V41;

//交通统计信息报警(扩展)
typedef struct tagNET_DVR_TPS_ALARM_V41
{
    DWORD                 dwSize;          // 结构体大小
    DWORD                 dwRelativeTime;  // 相对时标
    DWORD                 dwAbsTime;       // 绝对时标
    NET_VCA_DEV_INFO      struDevInfo;     // 前端设备信息
	NET_DVR_TPS_INFO_V41  struTPSInfo;     // 交通参数统计信息 
    BYTE                  byRes[128];      // 保留
} NET_DVR_TPS_ALARM_V41,*LPNET_DVR_TPS_ALARM_V41;

/*******************************智能交通事件 end*****************************************/

#define XXX_MAJOR_VERSION      2

/* 子版本号，性能优化、局部结构调整、模块内集成其他库的主版本提升时递增，最大31 */

#define XXX_SUB_VERSION        3

/* 修正版本号，修正bug后递增，最大31 */

#define XXX_REVISION_VERSION   4

typedef struct tagNET_DVR_VCA_VERSION
{
	WORD    wMajorVersion;		// 主版本号
	WORD    wMinorVersion;		// 次版本号
	WORD    wRevisionNumber;	// 修正号
	WORD    wBuildNumber;		// 编译号
	WORD	wVersionYear;		//	版本日期-年
	BYTE	byVersionMonth;		//	版本日期-月
	BYTE	byVersionDay;		//	版本日期-日
	BYTE	byRes[8];			// 保留字节
}NET_DVR_VCA_VERSION, *LPNET_DVR_VCA_VERSION;


/******************************智能 end***********************************/

/******************************车牌识别 begin******************************************/
typedef struct tagNET_DVR_PLATE_PARAM
{	
    BYTE    byPlateRecoMode;    //车牌识别的模式,默认为1(视频触发模式)
    BYTE    byBelive;		    //整牌置信度阈值, 只用于视频识别方式, 根据背景复杂程度设置, 误触发率高就设高, 漏车率高就设低, 建议在80-90范围内
    BYTE    byRes[22];          //保留字节
}NET_DVR_PALTE_PARAM, *LPNET_DVR_PALTE_PARAM;

typedef struct tagNET_DVR_PLATECFG
{	
    DWORD		dwSize;
    DWORD    dwEnable;				           /* 是否启用视频车牌识别 0－否 1－是 */
    BYTE    byPicProType;	//报警时图片处理方式 0-不处理 非0-上传
    BYTE    byRes1[3];  // 保留字节
    NET_DVR_JPEGPARA struPictureParam; 		//图片规格结构
    NET_DVR_PALTE_PARAM struPlateParam;   // 车牌识别参数配置
    NET_DVR_HANDLEEXCEPTION struHandleType;	   /* 处理方式 */
	NET_DVR_SCHEDTIME struAlarmTime[MAX_DAYS][MAX_TIMESEGMENT];//布防时间
	BYTE    byRelRecordChan[MAX_CHANNUM];        //报警触发的录象通道,为1表示触发该通道
    BYTE   byRes[20];   // 保留字节
}NET_DVR_PLATECFG, *LPNET_DVR_PLATECFG;

// 车牌识别结果子结构
typedef struct tagNET_DVR_PLATE_INFO
{
    BYTE  byPlateType;					//车牌类型
    BYTE  byColor;						//车牌颜色
    BYTE  byBright;						//车牌亮度
    BYTE  byLicenseLen;					//车牌字符个数
    BYTE  byEntireBelieve;					//整个车牌的置信度，-100
    BYTE  byRes[35];					//保留
    NET_VCA_RECT	struPlateRect;		//车牌位置
    char sLicense[MAX_LICENSE_LEN];		//车牌号码
    BYTE byBelieve[MAX_LICENSE_LEN];	//各个识别字符的置信度，如检测到车牌"浙A12345", 置信度为,20,30,40,50,60,70，则表示"浙"字正确的可能性只有%，"A"字的正确的可能性是%
}NET_DVR_PLATE_INFO, *LPNET_DVR_PLATE_INFO;

typedef struct tagNET_DVR_PLATERECO_RESULE
{
    DWORD dwSize;
    DWORD    dwRelativeTime;				//相对时标
    DWORD    dwAbsTime;						//绝对时标
    NET_VCA_DEV_INFO struDevInfo;           // 前段设备信息
    NET_DVR_PLATE_INFO struPlateInfo;
    DWORD dwPicDataLen;						//返回图片的长度 为0表示没有图片，大于0表示该结构后面紧跟图片数据*/
    DWORD dwRes[4];							//保留，设置为0
    BYTE  *pImage;   						//指向图片的指针
}NET_DVR_PLATERECO_RESULE, *LPNET_DVR_PLATERECO_RESULE;

/******************************车牌识别 end******************************************/

/*******************************视频综合平台***********************************/
typedef struct 
{
    NET_DVR_TIME strLogTime;
    DWORD	dwMajorType;	//Main type 1-alarm; 2-abnormal; 3-operation; 0xff-all 
    DWORD	dwMinorType;	//Hypo-Type 0-all;
    BYTE	sPanelUser[MAX_NAMELEN]; //user ID for local panel operation
    BYTE	sNetUser[MAX_NAMELEN];//user ID for network operation
    NET_DVR_IPADDR	struRemoteHostAddr;//remote host IP
    DWORD	dwParaType;//parameter type
    DWORD	dwChannel;//channel number
    DWORD	dwDiskNumber;//HD number
    DWORD	dwAlarmInPort;//alarm input port
    DWORD	dwAlarmOutPort;//alarm output port
    DWORD   dwInfoLen;
    BYTE    byDevSequence;//槽位号
    BYTE    byMacAddr[MACADDR_LEN];//MAC地址,6
    BYTE    sSerialNumber[SERIALNO_LEN];//序列号，48
    char    sInfo[LOG_INFO_LEN - SERIALNO_LEN - MACADDR_LEN - 1 ];
}NET_DVR_LOG_MATRIX, *LPNET_DVR_LOG_MATRIX;

//2009-11-21 视频综合平台
typedef struct tagVEDIOPLATLOG
{
    BYTE bySearchCondition;//搜索条件，0-按槽位号搜索，1-按序列号搜索，2-按MAC地址进行搜索
	//槽位号，0-79：对应子系统的槽位号；
    //0xff：表示搜索所有的日志，包括78K和所有6467；
    //0xfe：表示搜索78K上的日志；0xfd：子域日志；0xfc：域日志。。
    BYTE byDevSequence;
    BYTE  sSerialNumber[SERIALNO_LEN];//序列号，48
    BYTE  byMacAddr[MACADDR_LEN];//MAC地址,6
} NET_DVR_VEDIOPLATLOG, *LPNET_DVR_VEDIOPLATLOG;

typedef struct tagNET_DVR_CODESYSTEMABILITY
{
    DWORD dwSize;
    DWORD dwAbilityVersion;//能力集版本号，高16位表示主版本，低16位表示次版本 
    DWORD dwSupportMaxVideoFrameRate;//单位(K)
	/*按位:
	0:定时录像；
	1:定时|事件触发录像 
	2:移动侦测录像；
	3:网络开关量报警录像；
	4:移动侦测|网络开关量报警录像；
	5:移动侦测&网络开关量报警录像；
	6:周界防范触发录像；
	7:人脸检测触发录像；
	8:车牌识别触发录像；
	9:手动录像*/
    DWORD dwSupportRecordType;
    BYTE  bySupportLinkMode;//按位:第0位:表示主码流，第1位:表示子码流
	BYTE  bySupportStringRow;//支持字符叠加行数
    BYTE  bySupportHideNum;//支持视频遮挡数量
    BYTE  byRes1;
	/*0-DCIF，1-CIF，2-QCIF，3-4CIF，4-2CIF，6-QVGA(320*240), 16-VGA，17-UXGA，18-SVGA，19-HD720p，20-XVGA，21-HD900p，22-SXGAp，27-HD1080i，28-2560*1920，29-1600*304，30-2048*1536，31-2448*2048，32-2448*1200，33-2448*800 ，34-XGA（1024x768），35-SXGA（1280x1024）*/
	BYTE  byMainStreamSupportResolution[8];//主码流支持的分辨率，按位
	BYTE  bySubStreamSupportResolution[8];//子码流支持的分辨率，按位
	BYTE  byEventStreamSupportResolution[8];//事件触发码流支持的分辨率，按位
    BYTE  byNotSupportPreview;//是否支持预览,1-不支持，0-支持
    BYTE  byNotSupportStorage;//是否支持存储,1-不支持，0-支持
    BYTE  byRes2[98];//保留		
}NET_DVR_CODESYSTEMABILITY, *LPNET_DVR_CODESYSTEMABILITY;

/********************************end*******************************************/

/******************************抓拍机*******************************************/
//IO输入配置
typedef struct tagNET_DVR_IO_INCFG
{
    DWORD   dwSize;
    BYTE    byIoInStatus;//输入的IO口状态，0-下降沿，1-上升沿，2-上升沿和下降沿，3-高电平，4-低电平
    BYTE	byRes[3];//保留字节
}NET_DVR_IO_INCFG, *LPNET_DVR_IO_INCFG;

//IO输出配置
typedef struct tagNET_DVR_IO_OUTCFG
{
    DWORD   dwSize;
    BYTE    byDefaultStatus;//IO默认状态：0-低电平，1-高电平 
    BYTE    byIoOutStatus;//IO起效时状态：0-低电平，1-高电平，2-脉冲
    WORD    wAheadTime;//输出IO提前时间，单位us
    DWORD   dwTimePluse;//脉冲间隔时间，单位us
    DWORD   dwTimeDelay;//IO有效持续时间，单位us
	BYTE    byFreqMulti;		//倍频，数值范围[1,15]
	BYTE    byDutyRate;		//占空比，[0,40%]
    BYTE    byRes[2];
}NET_DVR_IO_OUTCFG, *LPNET_DVR_IO_OUTCFG;

//闪光灯配置
typedef struct tagNET_DVR_FLASH_OUTCFG
{
    DWORD  dwSize;
    BYTE   byMode;//闪光灯闪烁模式，0-不闪，1-闪，2-关联闪，3-轮闪
    BYTE   byRelatedIoIn;//闪光灯关联的输入IO号（关联闪时此参数有效）
	BYTE   byRecognizedLane;  /*关联的IO号，按位表示，bit0表示IO1是否关联，0-不关联，1-关联*/
	BYTE   byDetectBrightness;/*自动检测亮度使能闪光灯0-不检测；1-检测*/
	BYTE   byBrightnessThreld;/*使能闪光灯亮度阈值，范围[0,100],高于阈值闪*/
    BYTE   byStartHour;		//开始时间-小时,取值范围0-23
	BYTE   byStartMinute;		//开始时间-分,取值范围0-59
	BYTE   byEndHour;		 	//结束时间-小时,取值范围0-23
	BYTE   byEndMinute;		//结束时间-分,取值范围0-59
	BYTE   byFlashLightEnable;	//设置闪光灯时间使能:0-关;1-开
	BYTE   byRes[2];
}NET_DVR_FLASH_OUTCFG, *LPNET_DVR_FLASH_OUTCFG;

//红绿灯功能（2个IO输入一组）
typedef struct tagNET_DVR_LIGHTSNAPCFG
{
    DWORD   dwSize;
    BYTE	byLightIoIn;//红绿灯的IO 号
    BYTE	byTrigIoIn;//触发的IO号
    BYTE	byRelatedDriveWay;//触发IO关联的车道号
    BYTE	byTrafficLight; //0-高电平红灯，低电平绿灯；1-高电平绿灯，低电平红灯
    BYTE 	bySnapTimes1; //红灯抓拍次数1，0-不抓拍，非0-连拍次数，最大5次 
    BYTE 	bySnapTimes2; //绿灯抓拍次数2，0-不抓拍，非0-连拍次数，最大5次 
    BYTE	byRes1[2];
    WORD	wIntervalTime1[MAX_INTERVAL_NUM];//红灯连拍间隔时间，ms
    WORD	wIntervalTime2[MAX_INTERVAL_NUM];//绿灯连拍间隔时间，ms
    BYTE	byRecord;//闯红灯周期录像标志，0-不录像，1-录像
    BYTE	bySessionTimeout;//闯红灯周期录像超时时间（秒）
    BYTE	byPreRecordTime;//闯红灯录像片段预录时间(秒)
    BYTE	byVideoDelay;//闯红灯录像片段延时时间（秒）
    BYTE	byRes2[32];//保留字节
}NET_DVR_LIGHTSNAPCFG, *LPNET_DVR_LIGHTSNAPCFG;

//测速功能(2个IO输入一组）
typedef struct tagNET_DVR_MEASURESPEEDCFG
{
    DWORD   dwSize;
    BYTE	byTrigIo1;   //测速第1线圈
    BYTE	byTrigIo2;   //测速第2线圈
    BYTE	byRelatedDriveWay;//触发IO关联的车道号
    BYTE	byTestSpeedTimeOut;//测速模式超时时间，单位s
    DWORD   dwDistance;//线圈距离,cm
    BYTE	byCapSpeed;//测速模式起拍速度，单位km/h
    BYTE	bySpeedLimit;//限速值，单位km/h
    BYTE 	bySnapTimes1; //线圈1抓拍次数，0-不抓拍，非0-连拍次数，最大5次 
    BYTE 	bySnapTimes2; //线圈2抓拍次数，0-不抓拍，非0-连拍次数，最大5次 
    WORD	wIntervalTime1[MAX_INTERVAL_NUM];//线圈1连拍间隔时间，ms
    WORD	wIntervalTime2[MAX_INTERVAL_NUM];//线圈2连拍间隔时间，ms
    BYTE	byRes[32];//保留字节
}NET_DVR_MEASURESPEEDCFG, *LPNET_DVR_MEASURESPEEDCFG;

//视频参数配置
typedef struct tagNET_DVR_VIDEOEFFECT
{
    BYTE byBrightnessLevel; /*0-100*/
    BYTE byContrastLevel; /*0-100*/
    BYTE bySharpnessLevel; /*0-100*/
    BYTE bySaturationLevel; /*0-100*/
    BYTE byHueLevel; /*0-100,（保留）*/
    BYTE byEnableFunc; //使能，按位表示，bit0-SMART IR(防过曝)，bit1-低照度,bit2-强光抑制使能，0-否，1-是
	BYTE byLightInhibitLevel; //强光抑制等级，[1-3]表示等级
	BYTE byGrayLevel; //灰度值域，0-[0-255]，1-[16-235]
}NET_DVR_VIDEOEFFECT, *LPNET_DVR_VIDEOEFFECT;

//增益配置
typedef struct tagNET_DVR_GAIN
{
    BYTE byGainLevel; /*增益：0-100*/
    BYTE byGainUserSet; /*用户自定义增益；0-100，对于抓拍机，是CCD模式下的抓拍增益*/
    BYTE byRes[2];
    DWORD dwMaxGainValue;/*最大增益值，单位dB*/
}NET_DVR_GAIN, *LPNET_DVR_GAIN;

//白平衡配置
typedef struct tagNET_DVR_WHITEBALANCE
{
    BYTE byWhiteBalanceMode; /*0-手动白平衡（MWB）,1-自动白平衡1（AWB1）,2-自动白平衡2 (AWB2),3-自动控制改名为锁定白平衡(Locked WB)，
	                         4-室外(Indoor)，5-室内(Outdoor)6-日光灯(Fluorescent Lamp)，7-钠灯(Sodium Lamp)，
	                         8-自动跟踪(Auto-Track)9-一次白平衡(One Push)，10-室外自动(Auto-Outdoor)，
	                         11-钠灯自动 (Auto-Sodiumlight)，12-水银灯(Mercury Lamp)，13-自动白平衡(Auto)，
	                         14-白炽灯 (IncandescentLamp)，15-暖光灯(Warm Light Lamp)，16-自然光(Natural Light) */
    BYTE byWhiteBalanceModeRGain; /*手动白平衡时有效，手动白平衡 R增益*/
    BYTE byWhiteBalanceModeBGain; /*手动白平衡时有效，手动白平衡 B增益*/
    BYTE byRes[5];
}NET_DVR_WHITEBALANCE, *LPNET_DVR_WHITEBALANCE;

//曝光控制
typedef struct tagNET_DVR_EXPOSURE
{
    BYTE  byExposureMode; /*0 手动曝光 1自动曝光*/
	BYTE  byAutoApertureLevel; /* 自动光圈灵敏度, 0-10 */ 
    BYTE  byRes[2];
    DWORD dwVideoExposureSet; /* 自定义视频曝光时间（单位us）*//*注:自动曝光时该值为曝光最慢值 新增20-1s(1000000us)*/        
    DWORD dwExposureUserSet; /* 自定义曝光时间,在抓拍机上应用时，CCD模式时是抓拍快门速度*/   
    DWORD dwRes;    
} NET_DVR_EXPOSURE, *LPNET_DVR_EXPOSURE;

//宽动态配置
typedef struct tagNET_DVR_WDR
{
    BYTE byWDREnabled; /*宽动态：0 dsibale  1 enable 2 auto*/
    BYTE byWDRLevel1; /*0-F*/
    BYTE byWDRLevel2; /*0-F*/
    BYTE byWDRContrastLevel; /*0-100*/
    BYTE byRes[16];
} NET_DVR_WDR, *LPNET_DVR_WDR;

//日夜转换功能配置
typedef struct tagNET_DVR_DAYNIGHT
{
    BYTE byDayNightFilterType; /*日夜切换：0-白天，1-夜晚，2-自动，3-定时，4-报警输入触发*/
    BYTE bySwitchScheduleEnabled; /*0 dsibale  1 enable,(保留)*/
    //定时模式参数
    BYTE byBeginTime; /*开始时间（小时），0-23*/
    BYTE byEndTime; /*结束时间（小时），0-23*/
    //模式2
    BYTE byDayToNightFilterLevel; //0-7
    BYTE byNightToDayFilterLevel; //0-7
    BYTE byDayNightFilterTime;//(60秒)
    //定时模式参数
	BYTE byBeginTimeMin; //开始时间（分），0-59
	BYTE byBeginTimeSec; //开始时间（秒），0-59
	BYTE byEndTimeMin; //结束时间（分），0-59
	BYTE byEndTimeSec; //结束时间（秒），0-59
	//报警输入触发模式参数
    BYTE byAlarmTrigState; //报警输入触发状态，0-白天，1-夜晚
} NET_DVR_DAYNIGHT, *LPNET_DVR_DAYNIGHT;

//Gamma校正
typedef struct tagNET_DVR_GAMMACORRECT
{
    BYTE byGammaCorrectionEnabled; /*0 dsibale  1 enable*/
    BYTE byGammaCorrectionLevel; /*0-100*/
    BYTE byRes[6];
} NET_DVR_GAMMACORRECT, *LPNET_DVR_GAMMACORRECT;

//背光补偿配置
typedef struct tagNET_DVR_BACKLIGHT
{
    BYTE byBacklightMode; /*背光补偿:0 off 1 UP、2 DOWN、3 LEFT、4 RIGHT、5MIDDLE、6自定义*/
    BYTE byBacklightLevel; /*0x0-0xF*/
    BYTE byRes1[2];
    DWORD dwPositionX1; //（X坐标1）
    DWORD dwPositionY1; //（Y坐标1）
    DWORD dwPositionX2; //（X坐标2）
    DWORD dwPositionY2; //（Y坐标2）
    BYTE byRes2[4];
} NET_DVR_BACKLIGHT, *LPNET_DVR_BACKLIGHT;

//数字降噪功能
typedef struct tagNET_DVR_NOISEREMOVE
{
    BYTE byDigitalNoiseRemoveEnable; /*0-不启用，1-普通模式数字降噪，2-专家模式数字降噪*/
    BYTE byDigitalNoiseRemoveLevel; /*普通模式数字降噪级别：0x0-0xF*/
	BYTE bySpectralLevel;       /*专家模式下空域强度：0-100*/
    BYTE byTemporalLevel;   /*专家模式下时域强度：0-100*/
	BYTE byDigitalNoiseRemove2DEnable;         /* 抓拍帧2D降噪，0-不启用，1-启用 */	
	BYTE byDigitalNoiseRemove2DLevel;            /* 抓拍帧2D降噪级别，0-100 */
    BYTE byRes[2];
} NET_DVR_NOISEREMOVE, *LPNET_DVR_NOISEREMOVE;

//CMOS模式下前端镜头配置
typedef struct tagNET_DVR_CMOSMODCFG
{
	BYTE byCaptureMod;   //抓拍模式：0-抓拍模式1；1-抓拍模式2
	BYTE byBrightnessGate;//亮度阈值
	BYTE byCaptureGain1;   //抓拍增益1,0-100
	BYTE byCaptureGain2;   //抓拍增益2,0-100
	DWORD dwCaptureShutterSpeed1;//抓拍快门速度1
	DWORD dwCaptureShutterSpeed2;//抓拍快门速度2
	BYTE  byRes[4];
}NET_DVR_CMOSMODECFG, *LPNET_DVR_CMOSMODECFG;

//前端参数配置
typedef struct tagNET_DVR_CAMERAPARAMCFG
{
    DWORD dwSize;
    NET_DVR_VIDEOEFFECT struVideoEffect;/*亮度、对比度、饱和度、锐度、色调配置*/    
    NET_DVR_GAIN struGain;/*自动增益*/
    NET_DVR_WHITEBALANCE struWhiteBalance;/*白平衡*/
    NET_DVR_EXPOSURE struExposure; /*曝光控制*/
    NET_DVR_GAMMACORRECT struGammaCorrect;/*Gamma校正*/
    NET_DVR_WDR struWdr;/*宽动态*/
    NET_DVR_DAYNIGHT struDayNight;/*日夜转换*/
    NET_DVR_BACKLIGHT struBackLight;/*背光补偿*/
    NET_DVR_NOISEREMOVE struNoiseRemove;/*数字降噪*/
    BYTE byPowerLineFrequencyMode; /*0-50HZ; 1-60HZ*/
    BYTE byIrisMode; /*0 自动光圈 1手动光圈*/    
    BYTE byMirror ;  /* 镜像：0 off，1- leftright，2- updown，3-center */
    BYTE byDigitalZoom;  /*数字缩放:0 dsibale  1 enable*/
    BYTE byDeadPixelDetect;   /*坏点检测,0 dsibale  1 enable*/
	BYTE byBlackPwl;/*黑电平补偿 ,  0-255*/ 
	BYTE byEptzGate;// EPTZ开关变量:0-不启用电子云台，1-启用电子云台
	BYTE byLocalOutputGate;//本地输出开关变量0-本地输出关闭1-本地BNC输出打开 2-HDMI输出关闭  
				     //20-HDMI_720P50输出开
					 //21-HDMI_720P60输出开
					 //22-HDMI_1080I60输出开
					 //23-HDMI_1080I50输出开
					 //24-HDMI_1080P24输出开
					 //25-HDMI_1080P25输出开
					 //26-HDMI_1080P30输出开
					 //27-HDMI_1080P50输出开
			         //28-HDMI_1080P60输出开
					 //40-SDI_720P50,
					 //41-SDI_720P60,
					 //42-SDI_1080I50,
					 //43-SDI_1080I60,
					 //44-SDI_1080P24,
					 //45-SDI_1080P25,
					 //46-SDI_1080P30,
					 //47-SDI_1080P50,
					 //48-SDI_1080P60
	BYTE byCoderOutputMode;//编码器fpga输出模式0直通3像素搬家
	BYTE byLineCoding; //是否开启行编码：0-否，1-是
	BYTE byDimmerMode; //调光模式：0-半自动，1-自动
	BYTE byPaletteMode; //调色板：0-白热，1-黑热，2-调色板2，…，8-调色板8
	BYTE byEnhancedMode; //增强方式（探测物体周边）：0-不增强，1-1，2-2，3-3，4-4
	BYTE byDynamicContrastEN;    //动态对比度增强 0-1
	BYTE byDynamicContrast;    //动态对比度 0-100
	BYTE byJPEGQuality;    //JPEG图像质量 0-100
	NET_DVR_CMOSMODECFG struCmosModeCfg;//CMOS模式下前端参数配置，镜头模式从能力集获取
	BYTE byFilterSwitch; //滤波开关：0-不启用，1-启用
	BYTE byFocusSpeed; //镜头调焦速度：0-10
	BYTE byAutoCompensationInterval; //定时自动快门补偿：1-120，单位：分钟
	BYTE bySceneMode;  //场景模式：0-室外，1-室内，2-默认，3-弱光
}NET_DVR_CAMERAPARAMCFG, *LPNET_DVR_CAMERAPARAMCFG;

//透雾
typedef struct tagNET_DVR_DEFOGCFG
{
	BYTE byMode; //模式，0-不启用，1-自动模式，2-常开模式
	BYTE byLevel; //等级，0-100
	BYTE byRes[6]; 
}NET_DVR_DEFOGCFG, *LPNET_DVR_DEFOGCFG;

//电子防抖
typedef struct tagNET_DVR_ELECTRONICSTABILIZATION
{
	BYTE byEnable;//使能 0- 不启用，1- 启用
	BYTE byLevel; //等级，0-100
	BYTE byRes[6]; 
}NET_DVR_ELECTRONICSTABILIZATION, *LPNET_DVR_ELECTRONICSTABILIZATION;

//走廊模式
typedef struct tagNET_DVR_CORRIDOR_MODE_CCD
{
	BYTE       byEnableCorridorMode; //是否启用走廊模式 0～不启用， 1～启用
	BYTE       byRes[11];
}NET_DVR_CORRIDOR_MODE_CCD, *LPNET_DVR_CORRIDOR_MODE_CCD;

// SMART IR(防过曝)配置参数
typedef struct tagNET_DVR_SMARTIR_PARAM
{
	BYTE  byMode;//0～手动，1～自动
	BYTE  byIRDistance;//红外距离等级(等级，距离正比例)level:1~100 默认:50（手动模式下增加）
	BYTE  byRes[2];
}NET_DVR_SMARTIR_PARAM,*LPNET_DVR_SMARTIR_PARAM;

//在byIrisMode 为P-Iris1时生效，配置红外光圈大小等级，配置模式
typedef struct tagNET_DVR_PIRIS_PARAM
{
	BYTE  byMode;//0-自动，1-手动
	BYTE  byPIrisAperture;//红外光圈大小等级(等级,光圈大小正比例)level:1~100 默认:50（手动模式下增加）
	BYTE  byRes[6];
}NET_DVR_PIRIS_PARAM,*LPNET_DVR_PIRIS_PARAM;

//前端参数配置
typedef struct tagNET_DVR_CAMERAPARAMCFG_EX
{
    DWORD dwSize;
    NET_DVR_VIDEOEFFECT struVideoEffect;/*亮度、对比度、饱和度、锐度、色调配置*/    
    NET_DVR_GAIN struGain;/*自动增益*/
    NET_DVR_WHITEBALANCE struWhiteBalance;/*白平衡*/
    NET_DVR_EXPOSURE struExposure; /*曝光控制*/
    NET_DVR_GAMMACORRECT struGammaCorrect;/*Gamma校正*/
    NET_DVR_WDR struWdr;/*宽动态*/
    NET_DVR_DAYNIGHT struDayNight;/*日夜转换*/
    NET_DVR_BACKLIGHT struBackLight;/*背光补偿*/
    NET_DVR_NOISEREMOVE struNoiseRemove;/*数字降噪*/
    BYTE byPowerLineFrequencyMode; /*0-50HZ; 1-60HZ*/
    BYTE byIrisMode; /*0-自动光圈 1-手动光圈, 2-P-Iris1*/    
    BYTE byMirror ;  /* 镜像：0 off，1- leftright，2- updown，3-center */
    BYTE byDigitalZoom;  /*数字缩放:0 dsibale  1 enable*/
    BYTE byDeadPixelDetect;   /*坏点检测,0 dsibale  1 enable*/
	BYTE byBlackPwl;/*黑电平补偿 ,  0-255*/ 
	BYTE byEptzGate;// EPTZ开关变量:0-不启用电子云台，1-启用电子云台
	BYTE byLocalOutputGate;//本地输出开关变量0-本地输出关闭1-本地BNC输出打开 2-HDMI输出关闭  
	//20-HDMI_720P50输出开
	//21-HDMI_720P60输出开
	//22-HDMI_1080I60输出开
	//23-HDMI_1080I50输出开
	//24-HDMI_1080P24输出开
	//25-HDMI_1080P25输出开
	//26-HDMI_1080P30输出开
	//27-HDMI_1080P50输出开
	//28-HDMI_1080P60输出开
	BYTE byCoderOutputMode;//编码器fpga输出模式0直通3像素搬家
	BYTE byLineCoding; //是否开启行编码：0-否，1-是
	BYTE byDimmerMode; //调光模式：0-半自动，1-自动
	BYTE byPaletteMode; //调色板：0-白热，1-黑热，2-调色板2，…，8-调色板8
	BYTE byEnhancedMode; //增强方式（探测物体周边）：0-不增强，1-1，2-2，3-3，4-4
	BYTE byDynamicContrastEN;    //动态对比度增强 0-1
	BYTE byDynamicContrast;    //动态对比度 0-100
	BYTE byJPEGQuality;    //JPEG图像质量 0-100
	NET_DVR_CMOSMODECFG struCmosModeCfg;//CMOS模式下前端参数配置，镜头模式从能力集获取
	BYTE byFilterSwitch; //滤波开关：0-不启用，1-启用
	BYTE byFocusSpeed; //镜头调焦速度：0-10
	BYTE byAutoCompensationInterval; //定时自动快门补偿：1-120，单位：分钟
	BYTE bySceneMode;  //场景模式：0-室外，1-室内，2-默认，3-弱光
	NET_DVR_DEFOGCFG struDefogCfg;//透雾参数
	NET_DVR_ELECTRONICSTABILIZATION struElectronicStabilization;//电子防抖
	NET_DVR_CORRIDOR_MODE_CCD struCorridorMode;//走廊模式
	BYTE   byExposureSegmentEnable; //0~不启用,1~启用  曝光时间和增益呈阶梯状调整，比如曝光往上调整时，先提高曝光时间到中间值，然后提高增益到中间值，再提高曝光到最大值，最后提高增益到最大值
	BYTE   byBrightCompensate;//亮度增强 [0~100]
	/*
	0-关闭、1-640*480@25fps、2-640*480@30ps、3-704*576@25fps、4-704*480@30fps、5-1280*720@25fps、6-1280*720@30fps、
	7-1280*720@50fps、8-1280*720@60fps、9-1280*960@15fps、10-1280*960@25fps、11-1280*960@30fps、
	12-1280*1024@25fps、13--1280*1024@30fps、14-1600*900@15fps、15-1600*1200@15fps、16-1920*1080@15fps、
	17-1920*1080@25fps、18-1920*1080@30fps、19-1920*1080@50fps、20-1920*1080@60fps、21-2048*1536@15fps、22-2048*1536@20fps、
	23-2048*1536@24fps、24-2048*1536@25fps、25-2048*1536@30fps、26-2560*2048@25fps、27-2560*2048@30fps、
	28-2560*1920@7.5fps、29-3072*2048@25fps、30-3072*2048@30fps、31-2048*1536@12.5、32-2560*1920@6.25、
	33-1600*1200@25、34-1600*1200@30、35-1600*1200@12.5、36-1600*900@12.5、37-1600@900@15、38-800*600@25、39-800*600@30
	*/
	BYTE   byCaptureModeN; //视频输入模式（N制）
	BYTE   byCaptureModeP; //视频输入模式（P制）
	NET_DVR_SMARTIR_PARAM struSmartIRParam; //红外放过爆配置信息
    NET_DVR_PIRIS_PARAM struPIrisParam;//PIris配置信息对应byIrisMode字段从2-PIris1开始生效
	BYTE   byRes1[296];
}NET_DVR_CAMERAPARAMCFG_EX, *LPNET_DVR_CAMERAPARAMCFG_EX;

//车牌颜色
typedef enum _VCA_PLATE_COLOR_
{
	VCA_BLUE_PLATE  = 0,       //蓝色车牌
	VCA_YELLOW_PLATE,          //黄色车牌
	VCA_WHITE_PLATE,          //白色车牌
	VCA_BLACK_PLATE,           //黑色车牌
	VCA_GREEN_PLATE           //绿色车牌
}VCA_PLATE_COLOR;

//车牌类型
typedef enum _VCA_PLATE_TYPE_
{
	VCA_STANDARD92_PLATE = 0,	//标准民用车与军车
	VCA_STANDARD02_PLATE,		//02式民用车牌 
	VCA_WJPOLICE_PLATE,		    //武警车 
	VCA_JINGCHE_PLATE,			//警车
	STANDARD92_BACK_PLATE, 	    //民用车双行尾牌
	VCA_SHIGUAN_PLATE,          //使馆车牌
	VCA_NONGYONG_PLATE,         //农用车
	VCA_MOTO_PLATE              //摩托车
}VCA_PLATE_TYPE;

typedef enum _VLR_VEHICLE_CLASS
{
    VLR_OTHER       = 0,	   // 其它
	VLR_VOLKSWAGEN = 1,    // 大众
	VLR_BUICK        = 2,	   // 别克
	VLR_BMW         = 3,	   // 宝马
	VLR_HONDA       = 4,	   // 本田
	VLR_PEUGEOT     = 5,	   // 标致
	VLR_TOYOTA      = 6,	   // 丰田
	VLR_FORD         = 7,	   // 福特
	VLR_NISSAN       = 8,	   // 日产
	VLR_AUDI         = 9,	   // 奥迪
	VLR_MAZDA       = 10,    // 马自达
	VLR_CHEVROLET  = 11,    // 雪佛兰
	VLR_CITROEN     = 12,    // 雪铁龙
	VLR_HYUNDAI    = 13,    // 现代
	VLR_CHERY       = 14    // 奇瑞
}VLR_VEHICLE_CLASS;

//车辆信息
typedef struct tagNET_DVR_VEHICLE_INFO_
{
    DWORD dwIndex;					//车辆序号
    BYTE  byVehicleType;		//车辆类型
    BYTE  byColorDepth;		//车身颜色深浅
    BYTE  byColor;					//车身颜色,0-其他色，1-白色，2-银色，3-灰色，4-黑色，5-红色，6-深蓝，7-蓝色，8-黄色，9-绿色，10-棕色，11-粉色，12-紫色
    BYTE  byRes1;				//保留
    WORD  wSpeed;					//单位km/h
    WORD  wLength;					//前一辆车的车身长度
	BYTE  byIllegalType;           //违规类型，0-正常;1-低速2-超速3-逆行，,4-闯红灯,5-压车道线,6-不按导向，7-路口滞留，8-机占非，9-违法变道，10-不按车道 11-违反禁令，12-路口停车，13-绿灯停车
    BYTE  byVehicleLogoRecog; //参考枚举类型 VLR_VEHICLE_CLASS
	BYTE  byRes2[2]; //保留
	BYTE  byCustomInfo[16];  //自定义信息
	BYTE  byRes3[16];	
}NET_DVR_VEHICLE_INFO, *LPNET_DVR_VEHICLE_INFO;

//车牌检测结果
typedef struct tagNET_DVR_PLATE_RESULT
{
    DWORD   dwSize;						//结构长度
    BYTE	byResultType;			//0-视频识别结果，1图像识别结果 2 大于10M时走下载路线
	BYTE    byChanIndex;			//通道号
    WORD    wAlarmRecordID;	//报警录像ID(用于查询录像，仅当byResultType为2时有效)
    DWORD   dwRelativeTime;		//相对时间点  
    BYTE    byAbsTime[32];		//绝对时间点,yyyymmddhhmmssxxx,e.g.20090810235959999（毫秒）
    DWORD   dwPicLen;					//图片长度(近景图)
    DWORD	dwPicPlateLen;			//车牌小图片长度
    DWORD   dwVideoLen;					//录像内容长度
    BYTE	byTrafficLight;				//0-非红绿灯抓拍，1-绿灯时抓拍；2-红灯时抓拍
    BYTE    byPicNum;				//连拍的图片序号
    BYTE	byDriveChan;				//触发车道号
    BYTE	 byVehicleType;     //0- 未知，1- 客车，2- 货车，3- 轿车，4- 面包车，5- 小货车
    DWORD   dwBinPicLen; //车牌二值图长度
	DWORD   dwCarPicLen;//车辆原图长度
	DWORD   dwFarCarPicLen;  //远景图长度
	BYTE    *pBuffer3;   //车牌二值图
	BYTE    *pBuffer4;  //车辆原图
	BYTE    *pBuffer5;  //远景图
	BYTE    byRes3[8];                      //保留 
    NET_DVR_PLATE_INFO  struPlateInfo;    //车牌信息结构
    NET_DVR_VEHICLE_INFO struVehicleInfo; //车辆信息
    BYTE	*pBuffer1;   		        // 当上传的是图片(近景图)，指针指向图片信息，当上传的是视频，指针指向视频信息，如果不想获得图片或视频信息，传NULL(DVS车辆近景图)
    BYTE    *pBuffer2;                  // 当上传的是图片(车牌图)时，指向车牌图片的指针（DVS车牌彩图）
}NET_DVR_PLATE_RESULT, *LPNET_DVR_PLATE_RESULT;
//后面紧跟图片数据和录像数据，只传一种，图片数据为场景图片+车牌小图片

//图像叠加信息配置        
typedef struct tagNET_DVR_IMAGEOVERLAYCFG
{
	DWORD		dwSize;
	BYTE		byOverlayInfo;//叠加使能开关，0-不叠加，1-叠加
	BYTE		byOverlayMonitorInfo;//是否叠加监测点信息，0-不叠加，1-叠加
	BYTE		byOverlayTime;//是否叠加时间，0-不叠加，1-叠加
	BYTE		byOverlaySpeed;//是否叠加速度，0-不叠加，1-叠加
	BYTE		byOverlaySpeeding;//是否叠加超速比例，0-不叠加，1-叠加
	BYTE		byOverlayLimitFlag;//是否叠加限速标志，0-不叠加，1-叠加
	BYTE		byOverlayPlate;//是否叠加车牌号，0-不叠加，1-叠加
	BYTE		byOverlayColor;//是否叠加车身颜色，0-不叠加，1-叠加
    BYTE		byOverlayLength;//是否叠加车长，0-不叠加，1-叠加
    BYTE		byOverlayType;//是否叠加车型，0-不叠加，1-叠加
    BYTE		byOverlayColorDepth;//是否叠加车身颜色深浅，0-不叠加，1-叠加
    BYTE		byOverlayDriveChan;//是否叠加车道，0-不叠加，1-叠加
    BYTE		byOverlayMilliSec; //叠加毫秒信息 0-不叠加，1-叠加
	BYTE		byOverlayIllegalInfo; //叠加违章信息 0-不叠加，1-叠加
	BYTE        byOverlayRedOnTime;  //叠加红灯已亮时间 0-不叠加，1-叠加
	BYTE        byFarAddPlateJpeg;      //远景图是否叠加车牌截图,0-不叠加,1-叠加
	BYTE        byNearAddPlateJpeg;      //近景图是否叠加车牌截图,0-不叠加,1-叠加
	BYTE		byRes1[3];    //保留
	BYTE		byMonitorInfo1[32];    //监测点信息1
	BYTE		byMonitorInfo2[44]; //检测点信息2
	BYTE		byRes2[52];    //保留
}NET_DVR_IMAGEOVERLAYCFG, *LPNET_DVR_IMAGEOVERLAYCFG;

//单IO触发抓拍功能配置
typedef struct tagNET_DVR_SNAPCFG
{
    DWORD   dwSize;
    BYTE	byRelatedDriveWay;//触发IO关联的车道号
    BYTE 	bySnapTimes; //线圈抓拍次数，0-不抓拍，非0-连拍次数，目前最大5次  
    WORD	wSnapWaitTime;  //抓拍等待时间，单位ms，取值范围[0,60000]
    WORD	wIntervalTime[MAX_INTERVAL_NUM];//连拍间隔时间，ms
    BYTE	byRes2[24];//保留字节
}NET_DVR_SNAPCFG, *LPNET_DVR_SNAPCFG;

typedef enum _ITC_MAINMODE_ABILITY_
{
    ITC_MODE_UNKNOW    = 0x0,   //无
	ITC_POST_MODE  = 0x1,  //卡口模式
	ITC_EPOLICE_MODE      = 0x2,  //电警模式
	ITC_POSTEPOLICE_MODE  = 0x4  //卡式电警模式
}ITC_MAINMODE_ABILITY;

typedef enum _ITC_RECOG_REGION_TYPE_
{
    ITC_REGION_RECT    = 0x0,   //矩形
	ITC_REGION_POLYGON  = 0x1,  //多边形
}ITC_RECOG_REGION_TYPE;

typedef struct tagNET_DVR_SNAP_ABILITY
{
    DWORD dwSize;
    BYTE  byIoInNum;//IO输入口数
    BYTE  byIoOutNum;//IO输出口数
    BYTE  bySingleSnapNum;//单IO触发组数
    BYTE  byLightModeArrayNum;//红绿灯模式组数
    BYTE  byMeasureModeArrayNum;//测速模式组数
	BYTE  byPlateEnable; //车牌识别能力
	BYTE  byLensMode;//镜头模式0-CCD,1-CMOS
	BYTE  byPreTriggerSupport; //是否支持原触发模式，0-支持，1-不支持
	DWORD dwAbilityType; //支持的触发模式能力，按位表示，定义见ITC_MAINMODE_ABILITY
	BYTE  byIoSpeedGroup; //支持的IO测速组数
	BYTE  byIoLightGroup; //支持的IO红绿灯组数
	BYTE  byRecogRegionType; //牌识区域支持的类型，详见定义ITC_RECOG_REGION_TYPE
	BYTE  bySupport; //设备能力，按位表示，0-不支持，1-支持
	// bySupport&0x1，表示是否支持扩展的字符叠加配置
	// bySupport&0x2，表示是否支持扩展的校时配置结构
	// bySupport&0x4, 表示是否支持多网卡(多网隔离)
	// bySupport&0x8, 表示是否支持网卡的bonding功能(网络容错)
	// bySupport&0x10, 表示是否支持语音对讲
	//2013-07-09 能力集返回
	WORD wSupportMultiRadar;// 设备能力，按位表示，0-不支持，1-支持
	// wSupportMultiRadar&0x1，表示 卡口RS485雷达 支持车道关联雷达处理
	// wSupportMultiRadar&0x2，表示 卡口虚拟线圈 支持车道关联雷达处理
	// wSupportMultiRadar&0x4，表示 混行卡口 支持车道关联雷达处理
	// wSupportMultiRadar&0x8，表示 视频检测 支持车道关联雷达处理
	BYTE  byICRPresetNum;
	// 表示支持的ICR预置点（滤光片偏移点）数
	BYTE  byICRTimeSlot;//表示支持的ICR的时间段数（1～8）
	BYTE  bySupportRS485Num;//表示支持的RS485口的数量
	BYTE  byExpandRs485SupportSensor;// 设备能力，按位表示，0-不支持，1-支持
	// byExpandRs485SupportSensor &0x1，表示电警车检器支持车检器
	// byExpandRs485SupportSensor &0x2，表示卡式电警车检器支持车检器
	BYTE  byExpandRs485SupportSignalLampDet;// 设备能力，按位表示，0-不支持，1-支持
	// byExpandRs485SupportSignalLampDet &0x1，表示电警车检器支持外接信号灯检测器
    // byExpandRs485SupportSignalLampDet &0x2，表示卡式电警车检器支持外接信号灯检测器
	BYTE  byRes[13];
} NET_DVR_SNAP_ABILITY, *LPNET_DVR_SNAP_ABILITY;

typedef struct tagNET_ITC_ICRTIMECFG
{
	NET_DVR_SCHEDTIME  struTime;
	BYTE   byAssociateRresetNo;//预置点号1～8 , 0代表无
	BYTE   bySubSwitchMode;//1~白天，2~晚上 (当预置点等于0 的时候生效)
    BYTE   byRes[10];
}NET_ITC_ICRTIMECFG, *LPNET_ITC_ICRTIMECFG;

typedef struct tagNET_ITC_ICR_TIMESWITCH_PARAM  //156
{
	NET_ITC_ICRTIMECFG  struAutoCtrlTime[MAX_TIMESEGMENT_V30];//自动切换时间段 (自动切换下 时空下生效 现在支持4组，预留4组)
	BYTE  byICRPreset[MAX_ICR_NUM]; //实际生效根据能力集动态显示 [0~100] 数组下标表示预置点号1～8 （0～7 相对应）
	BYTE  byRes[20];
}NET_ITC_ICR_TIMESWITCH_PARAM, *LPNET_ITC_ICR_TIMESWITCH_PARAM;

typedef struct tagNET_ITC_ICR_MANUALSWITCH_PARAM
{	
	BYTE  byICRPreset[MAX_ICR_NUM]; //实际生效根据能力集动态显示 [0~100]
    BYTE  bySubSwitchMode;//1~白天，2~晚上
	BYTE  byRes[147];
}NET_ITC_ICR_MANUALSWITCH_PARAM, *LPNET_ITC_ICR_MANUALSWITCH_PARAM;

typedef struct tagNET_ITC_ICR_AOTOSWITCH_PARAM
{
	BYTE  byICRPreset[MAX_ICR_NUM]; //实际生效根据能力集动态显示 [0~100] 数组下标表示预置点号1～8 （0～7 相对应）
	BYTE  byRes[148];
}NET_ITC_ICR_AOTOSWITCH_PARAM, *LPNET_ITC_ICR_AOTOSWITCH_PARAM;

typedef union tagNET_ITC_ICR_PARAM_UNION
{
	BYTE uLen[156];
	NET_ITC_ICR_AOTOSWITCH_PARAM struICRAutoSwitch;
	NET_ITC_ICR_MANUALSWITCH_PARAM struICRManualSwitch;
	NET_ITC_ICR_TIMESWITCH_PARAM struICRTimeSwitch;
}NET_ITC_ICR_PARAM_UNION,*LPNET_ITC_ICR_PARAM_UNION;

typedef struct tagNET_ITC_ICRCFG
{
	DWORD dwSize;
	BYTE  bySwitchType;//1~自动切换，2~手动切换 ,3~定时切换 
	BYTE  byRes[3];
	NET_ITC_ICR_PARAM_UNION uICRParam;
}NET_ITC_ICRCFG, *LPNET_ITC_ICRCFG;

//2013-07-09 异常处理
typedef struct
{    
	DWORD   dwHandleType; //异常处理,异常处理方式的"或"结果
	/*0x00: 无响应*/
	/*0x01: 监视器上警告*/
	/*0x02: 声音警告*/
	/*0x04: 上传中心*/
	/*0x08: 触发报警输出（继电器输出）*/
	/*0x10: 触发JPRG抓图并上传Email*/
	/*0x20: 无线声光报警器联动*/
	/*0x40: 联动电子地图(目前只有PCNVR支持)*/
	/*0x200: 抓图并上传FTP*/  
	BYTE 	byEnable; //0～不启用，1～启用
	BYTE	byRes;
	WORD	wDuration;//持续时间(单位/s)
	BYTE	byAlarmOutTriggered[MAX_ITC_EXCEPTIONOUT];//触发输出通道
	BYTE    byRes1[8];
} NET_ITC_HANDLEEXCEPTION, *LPNET_ITC_HANDLEEXCEPTION;

typedef struct
{
	DWORD dwSize;
	NET_ITC_HANDLEEXCEPTION struSnapExceptionType[MAX_EXCEPTIONNUM_V30]; //数组的每个元素都表示一种异常，数组0- 硬盘出错,1-网线断,2-IP 地址冲突, 3-车检器异常, 4-信号灯检测器异常
}NET_ITC_EXCEPTION,*LPNET_ITC_EXCEPTION;

typedef struct tagNET_DVR_TRIGCOORDINATE
{
    WORD wTopLeftX; /*线圈左上角横坐标（2个字节）*/
    WORD wTopLeftY; /*线圈左上角纵坐标（2个字节）*/
    WORD wWdith; /*线圈宽度（2个字节）*/
    WORD wHeight; /*线圈高度（2个字节）*/
} NET_DVR_TRIGCOORDINATE, *LPNET_DVR_TRIGCOORDINATE;

typedef enum _PROVINCE_CITY_IDX_
{
	ANHUI_PROVINCE             = 0,              //安徽
	AOMEN_PROVINCE             = 1,              //澳门
	BEIJING_PROVINCE           = 2,              //北京
	CHONGQING_PROVINCE         = 3,              //重庆
	FUJIAN_PROVINCE            = 4,              //福建
	GANSU_PROVINCE             = 5,              //甘肃
	GUANGDONG_PROVINCE         = 6,              //广东
	GUANGXI_PROVINCE           = 7,              //广西
	GUIZHOU_PROVINCE           = 8,              //贵州
	HAINAN_PROVINCE            = 9,              //海南
	HEBEI_PROVINCE             = 10,             //河北
	HENAN_PROVINCE             = 11,             //河南
	HEILONGJIANG_PROVINCE      = 12,             //黑龙江
	HUBEI_PROVINCE             = 13,             //湖北
	HUNAN_PROVINCE             = 14,             //湖南
	JILIN_PROVINCE             = 15,             //吉林
	JIANGSU_PROVINCE           = 16,             //江苏
	JIANGXI_PROVINCE           = 17,             //江西
	LIAONING_PROVINCE          = 18,             //辽宁
	NEIMENGGU_PROVINCE         = 19,             //内蒙古
	NINGXIA_PROVINCE           = 20,             //宁夏
	QINGHAI_PROVINCE           = 21,             //青海
	SHANDONG_PROVINCE          = 22,             //山东
	SHANXI_JIN_PROVINCE        = 23,             //山西
	SHANXI_SHAN_PROVINCE       = 24,             //陕西
	SHANGHAI_PROVINCE          = 25,             //上海
	SICHUAN_PROVINCE           = 26,             //四川
	TAIWAN_PROVINCE            = 27,             //台湾
	TIANJIN_PROVINCE           = 28,             //天津
	XIZANG_PROVINCE            = 29,             //西藏
	XIANGGANG_PROVINCE         = 30,             //香港
	XINJIANG_PROVINCE          = 31,             //新疆
	YUNNAN_PROVINCE            = 32,             //云南
	ZHEJIANG_PROVINCE          = 33              //浙江
}PROVINCE_CITY_IDX;

typedef struct tagNET_DVR_GEOGLOCATION
{
	int iRes[2]; /*保留*/
	DWORD dwCity; /*城市，详见PROVINCE_CITY_IDX */
}NET_DVR_GEOGLOCATION, *LPNET_DVR_GEOGLOCATION;

//场景模式
typedef enum _SCENE_MODE_
{
	UNKOWN_SCENE_MODE   = 0,            //未知场景模式
	HIGHWAY_SCENE_MODE  = 1,            //高速场景模式
	SUBURBAN_SCENE_MODE = 2,            //郊区场景模式(保留)
	URBAN_SCENE_MODE    = 3,            //市区场景模式
	TUNNEL_SCENE_MODE   = 4             //隧道场景模式(保留)
}SCENE_MODE;

typedef struct tagNET_DVR_VTPARAM
{
    DWORD   dwSize;
	BYTE    byEnable;  /* 是否使能虚拟线圈，0-不使用，1-使用*/
	BYTE    byIsDisplay; /* 是否显示虚拟线圈，0-不显示，1-显示*/
	BYTE    byLoopPos; //晚间触发线圈的偏向：0-向上，1-向下
	BYTE    bySnapGain; /*抓拍增益*/
	DWORD   dwSnapShutter; /*抓拍快门速度*/
    NET_DVR_TRIGCOORDINATE struTrigCoordinate; //保留
    NET_DVR_TRIGCOORDINATE struRes[MAX_VL_NUM];
    BYTE    byTotalLaneNum;/*视频触发的车道数1*/
    BYTE    byPolarLenType; /*偏振镜类型，0：不加偏振镜；1：加施耐德偏振镜。*/
    BYTE	byDayAuxLightMode; /*白天辅助照明模式，0：无辅助照明；1：LED灯照明；2：闪光灯照明*/
    BYTE	byLoopToCalRoadBright; /*用以计算路面亮度的车道(虚拟线圈)*/
    BYTE	byRoadGrayLowTh; /*路面亮度低阈值初始化值1*/
    BYTE	byRoadGrayHighTh; /*路面亮度高阈值初始化值140*/
    WORD	wLoopPosBias; /*晚间触发线圈位移30*/
    DWORD   dwHfrShtterInitValue; /*连续图像曝光时间的初始值2000*/
    DWORD   dwSnapShtterInitValue; /*抓拍图像曝光时间的初始值500*/
    DWORD   dwHfrShtterMaxValue; /*连续图像曝光时间的最大值20000*/
    DWORD   dwSnapShtterMaxValue; /*抓拍图像曝光时间的最大值1500*/
    DWORD   dwHfrShtterNightValue; /*晚间连续图像曝光时间的设置值3000*/
    DWORD   dwSnapShtterNightMinValue; /*晚间抓拍图像曝光时间的最小值3000*/
    DWORD   dwSnapShtterNightMaxValue; /*晚间抓拍图像曝光时间的最大值5000*/
    DWORD   dwInitAfe; /*增益的初始值200*/
    DWORD   dwMaxAfe; /*增益的最大值400*/
	WORD    wResolutionX;/* 设备当前分辨率宽*/
	WORD    wResolutionY;/* 设备当前分辨率高*/
    DWORD   dwGainNightValue; /*晚间增益，默认值70*/
	DWORD   dwSceneMode; /*场景模式， 详见SCENE_MODE */
	DWORD   dwRecordMode; /*录像标志：0-不录像，1-录像*/
	NET_DVR_GEOGLOCATION struGeogLocation; /*地址位置*/
	BYTE    byTrigFlag[MAX_VL_NUM]; /*触发标志，0-车头触发；1-车尾触发；2-车头/车尾都触发*/
	BYTE    byTrigSensitive[MAX_VL_NUM];  /*触发灵敏度，1-100*/
	BYTE    byRes2[62];
}NET_DVR_VTPARAM, *LPNET_DVR_VTPARAM;

typedef struct tagNET_DVR_SNAPENABLECFG
{
	DWORD dwSize;
	BYTE  byPlateEnable;//是否支持车牌识别，0-不支持，1-支持
	BYTE  byRes1[2];   //保留
	BYTE  byFrameFlip;   //图像是否翻转 0-不翻转，1-翻转
	WORD  wFlipAngle;    //图像翻转角度 0,90,180,270
	WORD  wLightPhase;   //相位，取值范围[0, 360]
	BYTE  byLightSyncPower;  //是否信号灯电源同步，0-不同步；1-同步
	BYTE  byFrequency;		//信号频率
	BYTE  byUploadSDEnable;  //是否自动上传SD图片，0-否；1-是
    BYTE  byPlateMode; //识别模式参数:0-视频触发,1-外部触发
	BYTE  byUploadInfoFTP; //是否上传抓拍附加信息到FTP，0-否，1-是
	BYTE  byAutoFormatSD; //是否自动格式化SD卡，0-否，1-是
	WORD  wJpegPicSize; //Jpeg图片大小[64-8196]
	BYTE  byRes[56]; //保留
}NET_DVR_SNAPENABLECFG, *LPNET_DVR_SNAPENABLECFG;

/*ftp上传参数*/
typedef struct 
{
	DWORD	dwSize;
	DWORD	dwEnableFTP;			/*是否启动ftp上传功能*/
	char	sFTPIP[16];				/*ftp 服务器*/
	DWORD	dwFTPPort;				/*ftp端口*/
	BYTE	sUserName[NAME_LEN];	/*用户名*/
	BYTE	sPassword[PASSWD_LEN];	/*密码*/
	DWORD	dwDirLevel;	/*0 = 不使用目录结构，直接保存在根目录,1 = 使用1级目录,2=使用2级目录*/
	WORD 	wTopDirMode;	/* 一级目录，0x1 = 使用设备名,0x2 = 使用设备号,0x3 = 使用设备ip地址，0x4=使用监测点,0x5=使用时间(年月),0x=6自定义,0x7=违规类型,0x8=方向,0x9=地点*/
	WORD 	wSubDirMode;	/* 二级目录，0x1 = 使用通道名,0x2 = 使用通道号，,0x3=使用时间(年月日),0x4=使用车道号,0x=5自定义,0x6=违规类型,0x7=方向,0x8=地点*/
	BYTE    byEnableAnony; //启用匿名，0-否，1-是
	BYTE 	byRes[23];
}NET_DVR_FTPCFG, *LPNET_DVR_FTPCFG;

/*可用来命名图片的相关元素 */
#define PICNAME_ITEM_DEV_NAME 	    1		/*设备名*/
#define PICNAME_ITEM_DEV_NO 	    2		/*设备号*/
#define PICNAME_ITEM_DEV_IP 	    3		/*设备IP*/
#define PICNAME_ITEM_CHAN_NAME 	    4		/*通道名*/
#define PICNAME_ITEM_CHAN_NO 	    5		/*通道号*/
#define PICNAME_ITEM_TIME 		    6		/*时间*/
#define PICNAME_ITEM_CARDNO		    7		/*卡号*/
#define PICNAME_ITEM_PLATE_NO       8   /*车牌号码*/
#define PICNAME_ITEM_PLATE_COLOR    9   /*车牌颜色*/
#define PICNAME_ITEM_CAR_CHAN       10  /*车道号*/
#define PICNAME_ITEM_CAR_SPEED      11  /*车辆速度*/
#define PICNAME_ITEM_CARCHAN        12  /*监测点*/
#define PICNAME_ITEM_PIC_NUMBER     13  //图片序号
#define PICNAME_ITEM_CAR_NUMBER     14  //车辆序号
#define PICNAME_MAXITEM 		    15

#define PICNAME_ITEM_SPEED_LIMIT_VALUES    15 //限速值
#define PICNAME_ITEM_ILLEGAL_CODE          16 //国标违法代码
#define PICNAME_ITEM_CROSS_NUMBER          17 //路口编号
#define PICNAME_ITEM_DIRECTION_NUMBER      18 //方向编号

//图片命名
typedef struct 
{
	BYTE 	byItemOrder[PICNAME_MAXITEM];	/*	桉数组定义文件命名的规则 */
	BYTE 	byDelimiter;		/*分隔符，一般为'_'*/
}NET_DVR_PICTURE_NAME, *LPNET_DVR_PICTURE_NAME;

//命名规则：2013-09-27
#define PICNAME_ITEM_PARK_DEV_IP 	        1		/*设备IP*/
#define PICNAME_ITEM_PARK_PLATE_NO          2       /*车牌号码*/
#define PICNAME_ITEM_PARK_TIME 		        3		/*时间*/
#define PICNAME_ITEM_PARK_INDEX             4       /*车位编号*/
#define PICNAME_ITEM_PARK_STATUS            5       /*车位状态*/
//图片命名扩展 2013-09-27
typedef struct 
{
	BYTE 	byItemOrder[PICNAME_MAXITEM];	/*	桉数组定义文件命名的规则 */
	BYTE 	byDelimiter;	            	/*分隔符，一般为'_'*/
	BYTE    byRes[32];                      /*保留*/
}NET_DVR_PICTURE_NAME_EX, *LPNET_DVR_PICTURE_NAME_EX;

/* 串口抓图设置*/
typedef struct 
{
	BYTE	byStrFlag;	/*串口数据开始符*/
	BYTE 	byEndFlag;	/*结束符*/
	WORD	wCardIdx;	/*卡号相对起始位*/
	DWORD 	dwCardLen;	/*卡号长度*/
	DWORD   dwTriggerPicChans;	/*所触发的通道号，按位，从第1位开始计，即0x2表示第一通道*/
}NET_DVR_SERIAL_CATCHPIC_PARA, *LPNET_DVR_SERIAL_CATCHPIC_PARA;

//DVR抓图参数配置（基线）
typedef struct 
{
	DWORD	dwSize;
	NET_DVR_JPEGPARA struJpegPara[MAX_CHANNUM_V30];	/*每个通道的图像参数*/
	WORD	wBurstMode;							/*抓图方式,按位设置.0x1=报警输入触发，0x2=移动侦测触发 0x4=232触发，0x8=485触发，0x10=网络触发*/
	WORD	wUploadInterval;					/*图片上传间隔(秒)[0,65535]*/
	NET_DVR_PICTURE_NAME 	struPicNameRule;	/* 图片命名规则 */
	BYTE	bySaveToHD;		/*是否保存到硬盘*/
	BYTE	byRes1;
	WORD	wCatchInterval;		/*抓图间隔(毫秒)[0,65535]*/
	BYTE	byRes2[12];
	NET_DVR_SERIAL_CATCHPIC_PARA struRs232Cfg;
	NET_DVR_SERIAL_CATCHPIC_PARA struRs485Cfg;
	DWORD dwTriggerPicTimes[MAX_CHANNUM_V30];	/* 每个通道一次触发拍照次数 */
	DWORD dwAlarmInPicChanTriggered[MAX_ALARMIN_V30]; /*报警触发抓拍通道,按位设置，从第1位开始*/
}NET_DVR_JPEGCFG_V30, *LPNET_DVR_JPEGCFG_V30;

//抓拍触发请求结构(保留)
typedef struct tagNET_DVR_MANUALSNAP
{
    BYTE byRes[24]; //保留
}NET_DVR_MANUALSNAP, *LPNET_DVR_MANUALSNAP;

typedef struct tagNET_DVR_SPRCFG    
{
    DWORD dwSize; 
	BYTE byDefaultCHN[MAX_CHJC_NUM]; /*设备运行省份的汉字简写*/
	BYTE byPlateOSD;    /*0:不发送车牌彩色图,1:发送车牌彩色图*/
	BYTE bySendJPEG1;   /*0-不传送近景JPEG图,1-传送近景JPEG图*/
	BYTE bySendJPEG2;   /*0-不传送远景JPEG图,1-传送远景JPEG图*/
	WORD wDesignedPlateWidth;   /*车牌设计宽度*/
	BYTE byTotalLaneNum;  /*识别的车道数*/
	BYTE byRes1;      /*保留*/
	WORD wRecognizedLane;  /*识别的车道号，按位表示，bit0表示车道1是否识别，0-不识别，1-识别*/
    NET_VCA_RECT struLaneRect[MAX_LANERECT_NUM];  /*车道识别区域*/
	DWORD dwRecogMode;  /*识别的类型，
	    bit0-背向识别：0-正向车牌识别，1-背向识别(尾牌识别) ； 
		bit1-大车牌识别或小车牌识别：0-小车牌识别，1-大车牌识别 ；
		bit2-车身颜色识别：0-不采用车身颜色识别，在背向识别或小车牌识别时禁止启用，1-车身颜色识别；
		bit3-农用车识别：0-不采用农用车识别，1-农用车识别； 
		bit4-模糊识别：0-不采用模糊识别，1-模糊识别；
		bit5-帧定位或场定位：0-帧定位，1-场定位；
		bit6-帧识别或场识别：0-帧识别，1-场识别； 
		bit7-晚上或白天：0-白天，1-晚上 */
	BYTE  bySendPRRaw;       	//是否发送原图：0-不发送，1-发送 
	BYTE  bySendBinImage;  	//是否发送车牌二值图：0-不发送，1-发送 
	BYTE  byDelayCapture;  //延时抓拍控制,单位：帧
	BYTE  byUseLED;    //使用LED控制，0-否，1-是
	BYTE  byRes2[68];    //保留
}NET_DVR_SPRCFG, *LPNET_DVR_SPRCFG;

typedef struct tagNET_DVR_PLCCFG
{
	DWORD dwSize;
	BYTE byPlcEnable;	//是否启用车牌亮度补偿（默认启用）：0-关闭，1-启用 
	BYTE byPlateExpectedBright;	//车牌的预期亮度（默认值50）, 范围[0, 100]
	BYTE byRes1[2];	//保留 
	BYTE byTradeoffFlash;     //是否考虑闪光灯的影响: 0 - 否;  1 - 是(默认); 
	//使用闪光灯补光时, 如果考虑减弱闪光灯的亮度增强效应, 则需要设为1;否则为0
	BYTE byCorrectFactor;     //纠正系数, 范围[0, 100], 默认值50 (在tradeoff_flash切换时,恢复默认值）
	WORD wLoopStatsEn;  //是否该线圈的亮度，按位表示，0-不统计，1-统计
	BYTE byPlcBrightOffset;// 车牌亮度补偿灵敏度(虚拟线圈模式起效)，取值范围1~100
	BYTE byRes[19];
}NET_DVR_PLCCFG, *LPNET_DVR_PLCCFG;

typedef struct tagNET_DVR_DEVICESTATECFG
{
	DWORD dwSize;
	WORD wPreviewNum; //预览连接个数
	WORD wFortifyLinkNum; //布防连接个数
	NET_DVR_IPADDR struPreviewIP[MAX_LINK];  //预览的用户IP地址
	NET_DVR_IPADDR struFortifyIP[MAX_FORTIFY_NUM]; //布防连接的用户IP地址
	DWORD dwVideoFrameRate;	//帧率：0-全部; 1-1/16; 2-1/8; 3-1/4; 4-1/2; 5-1; 6-2; 7-4; 8-6; 9-8; 10-10; 11-12; 12-16; 13-20; 14-15; 15-18; 16-22;
	BYTE byResolution;  	//分辨率0-DCIF 1-CIF, 2-QCIF, 3-4CIF, 4-2CIF 5（保留）,16-VGA（640*480）, 17-UXGA（1600*1200）, 18-SVGA （800*600）,19-HD720p（1280*720）,20-XVGA,  21-HD900p, 27-HD1080i, 28-2560*1920, 29-1600*304, 30-2048*1536, 31-2448*2048
	BYTE bySnapResolution;  	//抓拍分辨率0-DCIF 1-CIF, 2-QCIF, 3-4CIF, 4-2CIF 5（保留）,16-VGA（640*480）, 17-UXGA（1600*1200）, 18-SVGA （800*600）,19-HD720p（1280*720）,20-XVGA,  21-HD900p, 27-HD1080i, 28-2560*1920, 29-1600*304, 30-2048*1536, 31-2448*2048
	BYTE byStreamType; //传输类型：0-主码流；1-子码流
	BYTE byTriggerType; //触发模式：0-视频触发；1-普通触发
	DWORD dwSDVolume;  //SD卡容量
	DWORD dwSDFreeSpace; //SD卡剩余空间
	BYTE byDetectorState[MAX_DRIVECHAN_NUM][MAX_COIL_NUM];  //车检器状态：0-未使用；1-正常；2-异常
	BYTE byDetectorLinkState; //车检器连接状态：0-未连接；1-连接
	BYTE bySDStatus;    //SD卡状态 0－活动；1－休眠；2－异常，3-无sd卡
	BYTE byFortifyLevel[MAX_FORTIFY_NUM]; //布防等级，0-无，1-一等级（高），2-二等级（中），3-三等级（低）
	BYTE byRes2[116]; //保留
}NET_DVR_DEVICESTATECFG, *LPNET_DVR_DEVICESTATECFG;

typedef struct tagNET_DVR_POSTEPOLICECFG
{
	DWORD dwSize;
	DWORD dwDistance;//线圈距离,单位cm，取值范围[0,20000]
	DWORD dwLightChan[MAX_SIGNALLIGHT_NUM];	//信号灯通道号
	BYTE  byCapSpeed;//标志限速，单位km/h，取值范围[0,255]
	BYTE  bySpeedLimit;//限速值，单位km/h，取值范围[0,255]
	BYTE  byTrafficDirection;//车流方向，0-由东向西，1-由西向东，2-由南向北，3-由北向南
	BYTE  byRes1; //保留
	WORD  wLoopPreDist;        /*触发延迟距离 ，单位：分米*/
	WORD  wTrigDelay;             /*触发硬延时时间 ，单位：毫秒*/
	BYTE  byRes[124];//保留字节
}NET_DVR_POSTEPOLICECFG, *LPNET_DVR_POSTEPOLICECFG;
/***************************** end *********************************************/

#define IPC_PROTOCOL_NUM      50   //ipc 协议最大个数

//协议类型
typedef struct tagNET_DVR_PROTO_TYPE
{ 
    DWORD dwType;               /*ipc协议值*/    
    BYTE  byDescribe[DESC_LEN]; /*协议描述字段*/    
}NET_DVR_PROTO_TYPE, LPNET_DVR_PROTO_TYPE;

//协议列表
typedef struct tagNET_DVR_IPC_PROTO_LIST
{    
	DWORD   dwSize; 
	DWORD   dwProtoNum;           /*有效的ipc协议数目*/   
    NET_DVR_PROTO_TYPE struProto[IPC_PROTOCOL_NUM];   /*有效的ipc协议*/    
    BYTE    byRes[8];
}NET_DVR_IPC_PROTO_LIST, *LPNET_DVR_IPC_PROTO_LIST;

#define MAX_ALERTLINE_NUM	8 //最大警戒线条数	

typedef struct tagNET_DVR_TRAVERSE_PLANE_SEARCHCOND
{	
    NET_VCA_TRAVERSE_PLANE struVcaTraversePlane[MAX_ALERTLINE_NUM/*8*/];  //穿越境界面参数
    DWORD dwPreTime;   /*智能报警提前时间 单位:秒*/
    DWORD dwDelayTime; /*智能报警延迟时间 单位:秒*/ 
    BYTE byRes[5656]; //保留
}NET_DVR_TRAVERSE_PLANE_SEARCHCOND, *LPNET_DVR_TRAVERSE_PLANE_SEARCHCOND; //越界侦测查询条件

#define MAX_INTRUSIONREGION_NUM	8 //最大区域数数
typedef struct tagNET_DVR_INTRUSION_SEARCHCOND  
{
    NET_VCA_INTRUSION struVcaIntrusion[MAX_INTRUSIONREGION_NUM/*8*/]; //入侵区域
    DWORD dwPreTime;   /*智能报警提前时间 单位:秒*/
    DWORD dwDelayTime; /*智能报警延迟时间 单位:秒*/ 
    BYTE byRes[5400]; //保留
} NET_DVR_INTRUSION_SEARCHCOND, *LPNET_DVR_INTRUSION_SEARCHCOND; //区域入侵


typedef union tagNET_DVR_AREA_SMARTSEARCH_COND_UNION
{  
    BYTE    byLen[6144];  //结构体长度
    BYTE    byMotionScope[64][96]; //侦测区域 0-96位表示64行，共有96*64个小宏块，1-是移动侦测区域，0-非移动侦测区域 
    NET_DVR_TRAVERSE_PLANE_SEARCHCOND struTraversPlaneCond; //越界侦测
    NET_DVR_INTRUSION_SEARCHCOND struIntrusionCond; //区域入侵
}NET_DVR_AREA_SMARTSEARCH_COND_UNION,
*LPNET_DVR_AREA_SMARTSEARCH_COND_UNION;


//智能搜索参数
typedef struct tagNET_DVR_SMART_SEARCH_PARAM
{
	BYTE	  byChan;					//通道号
    BYTE      bySearchCondType; //智能查找联合体NET_DVR_AREA_SMARTSEARCH_COND_UNION的索引     
	/*0-移动侦测区域 ，1-越界侦测， 2-区域入侵*/
    BYTE      byRes1[2];
	NET_DVR_TIME struStartTime;		//录像开始的时间
	NET_DVR_TIME struEndTime;		//录像停止的时间
    NET_DVR_AREA_SMARTSEARCH_COND_UNION uSmartSearchCond;  //智能查找条件
    BYTE  bySensitivity;   			//移动侦测搜索灵敏度,1	>80%  2 40%~80%  3 1%~40%	
    BYTE byRes2[11];
}NET_DVR_SMART_SEARCH_PARAM, *LPNET_DVR_SMART_SEARCH_PARAM;

typedef struct tagNET_DVR_SMART_SEARCH_RET
{
	NET_DVR_TIME struStartTime;	//移动侦测报警开始的时间
	NET_DVR_TIME struEndTime;   //事件停止的时间
	BYTE byRes[64];
}NET_DVR_SMART_SEARCH_RET, *LPNET_DVR_SMART_SEARCH_RET;

// IPSAN 文件目录查找
typedef struct tagNET_DVR_IPSAN_SERACH_PARAM
{
    NET_DVR_IPADDR  struIP;     // IPSAN IP地址
    WORD            wPort;      // IPSAN  端口
    BYTE            byRes[10];  // 保留字节
}NET_DVR_IPSAN_SERACH_PARAM, *LPNET_DVR_IPSAN_SERACH_PARAM;

typedef struct tagNET_DVR_IPSAN_SERACH_RET
{
    BYTE byDirectory[128];  // 返回的文件目录
    BYTE byRes[20];
}NET_DVR_IPSAN_SERACH_RET, *LPNET_DVR_IPSAN_SERACH_RET;

//DVR设备参数
typedef struct
{
	DWORD dwSize;
	BYTE sDVRName[NAME_LEN];     //DVR名称
	DWORD dwDVRID;				//DVR ID,用于遥控器 //V1.4(0-99), V1.5(0-255)
	DWORD dwRecycleRecord;		//是否循环录像,0:不是; 1:是
	//以下不可更改
	BYTE sSerialNumber[SERIALNO_LEN];  //序列号
	DWORD dwSoftwareVersion;			//软件版本号,高16位是主版本,低16位是次版本
	DWORD dwSoftwareBuildDate;			//软件生成日期,0xYYYYMMDD
	DWORD dwDSPSoftwareVersion;		    //DSP软件版本,高16位是主版本,低16位是次版本
	DWORD dwDSPSoftwareBuildDate;		// DSP软件生成日期,0xYYYYMMDD
	DWORD dwPanelVersion;				// 前面板版本,高16位是主版本,低16位是次版本
	DWORD dwHardwareVersion;	// 硬件版本,高16位是主版本,低16位是次版本
	BYTE byAlarmInPortNum;		//DVR报警输入个数
	BYTE byAlarmOutPortNum;		//DVR报警输出个数
	BYTE byRS232Num;			//DVR 232串口个数
	BYTE byRS485Num;			//DVR 485串口个数 
	BYTE byNetworkPortNum;		//网络口个数
	BYTE byDiskCtrlNum;			//DVR 硬盘控制器个数
	BYTE byDiskNum;				//DVR 硬盘个数
	BYTE byDVRType;				//DVR类型, 1:DVR 2:ATM DVR 3:DVS ......
	BYTE byChanNum;				//DVR 通道个数
	BYTE byStartChan;			//起始通道号,例如DVS-1,DVR - 1
	BYTE byDecordChans;			//DVR 解码路数
	BYTE byVGANum;				//VGA口的个数 
	BYTE byUSBNum;				//USB口的个数
    BYTE byAuxoutNum;			//辅口的个数
    BYTE byAudioNum;			//语音口的个数
	BYTE byIPChanNum;			//最大数字通道数 低8位，高8位见byHighIPChanNum 
	BYTE byZeroChanNum;			//零通道编码个数
    BYTE bySupport;        //能力，位与结果为0表示不支持，1表示支持，
    //bySupport & 0x1, 表示是否支持智能搜索
    //bySupport & 0x2, 表示是否支持备份
    //bySupport & 0x4, 表示是否支持压缩参数能力获取
    //bySupport & 0x8, 表示是否支持多网卡
    //bySupport & 0x10, 表示支持远程SADP
    //bySupport & 0x20, 表示支持Raid卡功能
    //bySupport & 0x40, 表示支持IPSAN搜索
	//bySupport & 0x80, 表示支持rtp over rtsp
	BYTE byEsataUseage;		//Esata的默认用途，0-默认备份，1-默认录像
    BYTE byIPCPlug;			//0-关闭即插即用，1-打开即插即用
	BYTE byStorageMode;		//0-盘组模式,1-磁盘配额, 2抽帧模式
	BYTE bySupport1;		//能力，位与结果为0表示不支持，1表示支持
	//bySupport1 & 0x1, 表示是否支持snmp v30
	//bySupport1 & 0x2, 支持区分回放和下载
	//bySupport1 & 0x4, 是否支持布防优先级	
	//bySupport1 & 0x8, 智能设备是否支持布防时间段扩展
	//bySupport1 & 0x10, 表示是否支持多磁盘数（超过33个）
	//bySupport1 & 0x20, 表示是否支持rtsp over http	
	WORD wDevType;//设备型号
	BYTE  byDevTypeName[DEV_TYPE_NAME_LEN];//设备型号名称 
	BYTE bySupport2; //能力集扩展，位与结果为0表示不支持，1表示支持
	//bySupport2 & 0x1, 表示是否支持扩展的OSD字符叠加(终端和抓拍机扩展区分)
	BYTE byAnalogAlarmInPortNum; //模拟报警输入个数
	BYTE byStartAlarmInNo;    //模拟报警输入起始号
    BYTE byStartAlarmOutNo;  //模拟报警输出起始号
    BYTE byStartIPAlarmInNo;  //IP报警输入起始号  0-无效
    BYTE byStartIPAlarmOutNo; //IP报警输出起始号 0-无效
    BYTE byHighIPChanNum;     //数字通道个数，高8位 
	BYTE byRes2[9];			//保留
}NET_DVR_DEVICECFG_V40, *LPNET_DVR_DEVICECFG_V40;

#define MAX_ZEROCHAN_NUM    16
//零通道压缩配置参数
typedef struct tagNET_DVR_ZEROCHANCFG
{
	DWORD dwSize;			//结构长度
	BYTE  byEnable;			//0-停止零通道编码，1-表示启用零通道编码
	BYTE  byRes1[3];			//保留
	DWORD dwVideoBitrate; 	//视频码率 0-保留 1-16K(保留) 2-32K 3-48k 4-64K 5-80K 6-96K 7-128K 8-160k 9-192K 10-224K 11-256K 12-320K
	// 13-384K 14-448K 15-512K 16-640K 17-768K 18-896K 19-1024K 20-1280K 21-1536K 22-1792K 23-2048K
	//最高位(31位)置成1表示是自定义码流, 0-30位表示码流值(MIN-32K MAX-8192K)。
	DWORD dwVideoFrameRate;	//帧率 0-全部; 1-1/16; 2-1/8; 3-1/4; 4-1/2; 5-1; 6-2; 7-4; 8-6; 9-8; 10-10; 11-12; 12-16; 13-20, //V2.0增加14-15, 15-18, 16-22;
	BYTE  byRes2[32];        //保留
}NET_DVR_ZEROCHANCFG, *LPNET_DVR_ZEROCHANCFG;

//零通道缩放参数
typedef struct tagNET_DVR_ZERO_ZOOMCFG
{
	DWORD dwSize;			    //结构长度
	NET_VCA_POINT  struPoint;	//画面中的坐标点
	BYTE byState;			    //现在的状态，0-缩小，1-放大  
    BYTE byPreviewNumber;       //预览数目,0-1画面,1-4画面,2-9画面,3-16画面 该参数只读
	BYTE byPreviewSeq[MAX_WINDOW_V30];//画面通道信息 该参数只读
    BYTE byRes[30];				//保留 
}NET_DVR_ZERO_ZOOMCFG, *LPNET_DVR_ZERO_ZOOMCFG;

#define DESC_LEN_64 64
typedef struct tagNET_DVR_SNMPCFG
{
    DWORD   dwSize;			//结构长度
    BYTE    byEnable;			//0-禁用SNMP，1-表示启用SNMP
    BYTE    byRes1[3];			//保留
    WORD    wVersion;		//snmp 版本  v1 = 1, v2 =2, v3 =3，设备目前不支持 v3
    WORD    wServerPort; //snmp消息接收端口，默认 161
    BYTE    byReadCommunity[NAME_LEN]; //读共同体，最多31,默认"public"
    BYTE    byWriteCommunity[NAME_LEN];//写共同体,最多31 字节,默认 "private"
    BYTE 	byTrapHostIP [DESC_LEN_64];	//自陷主机ip地址描述，支持IPV4 IPV6和域名描述    
    WORD    wTrapHostPort;   // trap主机端口
    BYTE    byTrapName[NAME_LEN];	
	BYTE    byRes2[70];    //保留
}NET_DVR_SNMPCFG, *LPNET_DVR_SNMPCFG;

typedef struct tagNET_DVR_SNMPv3_USER
{
    BYTE	byUserName[NAME_LEN];			// 用户名				
    BYTE	bySecLevel;						// 安全级别 1-无校验 2-无授权校验 3-授权校验
    BYTE	byAuthtype;						// 认证类型 0-MD5认证 1-SHA认证 2: none
	BYTE	byPrivtype;						// 0: DES; 1: AES; 2: none;
	BYTE	byRes[5];
    BYTE	byAuthpass[PASSWD_LEN];			// 认证密码
    BYTE	byPrivpass[PASSWD_LEN];			// 加密密码
}NET_DVR_SNMPv3_USER, *LPNET_DVR_SNMPv3_USER;

// snmpv30
typedef struct tagNET_DVR_SNMPCFG_V30
{
    DWORD				dwSize;			//结构长度
    BYTE				byEnableV1;		//0-禁用SNMP V1，1-表示启用SNMP V1
	BYTE				byEnableV2;		//0-禁用SNMP V2，1-表示启用SNMP V2
	BYTE				byEnableV3;		//0-禁用SNMP V3，1-表示启用SNMP V3
    BYTE				byRes1[3];
    WORD				wServerPort;					//snmp消息接收端口，默认 161
    BYTE				byReadCommunity[NAME_LEN];		//读共同体，最多31,默认"public"
    BYTE				byWriteCommunity[NAME_LEN];		//写共同体,最多31 字节,默认 "private"
    BYTE 				byTrapHostIP [DESC_LEN_64];		//自陷主机ip地址描述，支持IPV4 IPV6和域名描述    
    WORD				wTrapHostPort;					// trap主机端口
    BYTE				byRes2[2];       
	NET_DVR_SNMPv3_USER	struRWUser;    // 读写用户
	NET_DVR_SNMPv3_USER	struROUser;    // 只读用户
	BYTE				byTrapName[NAME_LEN];
}NET_DVR_SNMPCFG_V30, *LPNET_DVR_SNMPCFG_V30;

#define  PROCESSING          0     //正在处理
#define  PROCESS_SUCCESS     100   //过程完成
#define  PROCESS_EXCEPTION   400   //过程异常
#define  PROCESS_FAILED      500   //过程失败

#define  SOFTWARE_VERSION_LEN 48
typedef struct tagNET_DVR_SADPINFO
{
    NET_DVR_IPADDR  struIP;     // 设备IP地址
    WORD            wPort;      // 设备端口号
    WORD            wFactoryType;   // 设备厂家类型
    char            chSoftwareVersion[SOFTWARE_VERSION_LEN];
    char            chSerialNo[16]; // 序列号
    WORD            wEncCnt;       // 编码通道个数
    BYTE	        byMACAddr[MACADDR_LEN];		// MAC 地址
    NET_DVR_IPADDR  struSubDVRIPMask;   // DVR IP地址掩码
    NET_DVR_IPADDR  struGatewayIpAddr;  // 网关
    NET_DVR_IPADDR	struDnsServer1IpAddr;			/* 域名服务器1的IP地址 */
    NET_DVR_IPADDR	struDnsServer2IpAddr;			/* 域名服务器2的IP地址 */
    BYTE            byDns;
    BYTE            byDhcp;
    BYTE            byRes[158];     // 保留字节
}NET_DVR_SADPINFO, *LPNET_DVR_SADPINFO;

#define  MAX_SADP_NUM   256   // 搜索到设备最大数目
typedef struct tagNET_DVR_SADPINFO_LIST
{
    DWORD            dwSize;   //  结构大小
    WORD             wSadpNum;   // 搜索到设备数目
    BYTE             byRes[6];   // 保留字节
    NET_DVR_SADPINFO struSadpInfo[MAX_SADP_NUM]; // 搜索
}NET_DVR_SADPINFO_LIST, *LPNET_DVR_SADPINFO_LIST;

typedef struct tagNET_DVR_SADP_VERIFY
{
    char chPassword[PASSWD_LEN];
    NET_DVR_IPADDR struOldIP;
    WORD        wOldPort;
    BYTE        byRes[62];
}NET_DVR_SADP_VERIFY, *LPNET_DVR_SADP_VERIFY;

/*******************************备份接口 begin********************************/
//获取备份设备信息接口定义
#define DESC_LEN_32          32   //描述字长度
#define MAX_NODE_NUM         256  //节点个数

typedef struct tagNET_DVR_DESC_NODE
{ 
    int   iValue;           
    BYTE  byDescribe[DESC_LEN_32]; //描述字段 
    DWORD dwFreeSpace;           //获取磁盘列表专用,单位为M
    BYTE  byRes[12];			  //保留  
}NET_DVR_DESC_NODE, *LPNET_DVR_DESC_NODE;

typedef struct tagNET_DVR_DISKABILITY_LIST
{ 
    DWORD     dwSize;            //结构长度
    DWORD     dwNodeNum;		 //能力结点个数
    NET_DVR_DESC_NODE  struDescNode[MAX_NODE_NUM];  //描述参数  
}NET_DVR_DISKABILITY_LIST, *LPNET_DVR_DISKABILITY_LIST;

//备份进度列表
#define BACKUP_SUCCESS                100  //备份完成
#define BACKUP_CHANGE_DEVICE          101  //备份设备已满，更换设备继续备份

#define BACKUP_SEARCH_DEVICE          300  //正在搜索备份设备
#define BACKUP_SEARCH_FILE            301  //正在搜索录像文件
#define BACKUP_SEARCH_LOG_FILE        302  //正在搜索日志文件

#define BACKUP_EXCEPTION			  400  //备份异常
#define BACKUP_FAIL					  500  //备份失败

#define BACKUP_TIME_SEG_NO_FILE       501  //时间段内无录像文件
#define BACKUP_NO_RESOURCE            502  //申请不到资源
#define BACKUP_DEVICE_LOW_SPACE       503  //备份设备容量不足
#define BACKUP_DISK_FINALIZED         504  //刻录光盘封盘
#define BACKUP_DISK_EXCEPTION         505  //刻录光盘异常
#define BACKUP_DEVICE_NOT_EXIST       506  //备份设备不存在
#define BACKUP_OTHER_BACKUP_WORK      507  //有其他备份操作在进行
#define BACKUP_USER_NO_RIGHT          508  //用户没有操作权限
#define BACKUP_OPERATE_FAIL           509  //操作失败
#define BACKUP_NO_LOG_FILE            510  //硬盘中无日志

//备份过程接口定义
typedef struct tagNET_DVR_BACKUP_NAME_PARAM
{
    DWORD dwFileNum;   //文件个数
    NET_DVR_FINDDATA_V30 struFileList[MAX_RECORD_FILE_NUM]; //文件列表
    BYTE byDiskDes[DESC_LEN_32];   //备份磁盘描述
    BYTE byWithPlayer;      //是否备份播放器
    BYTE byContinue;    /*是否继续备份 0不继续 1继续*/
    BYTE byRes[34];         //保留
}NET_DVR_BACKUP_NAME_PARAM, *LPNET_DVR_BACKUP_NAME_PARAM;

typedef struct tagNET_DVR_BACKUP_TIME_PARAM
{
    LONG            lChannel;        //按时间备份的通道
    NET_DVR_TIME    struStartTime;   //备份的起始时间
    NET_DVR_TIME    struStopTime;    //备份的终止时间
    BYTE            byDiskDes[DESC_LEN_32];     //备份磁盘描述
    BYTE            byWithPlayer;               //是否备份播放器
    BYTE            byContinue;                 //是否继续备份 0不继续 1继续
	BYTE            byDrawFrame;			     //0 不抽帧  1 抽帧
	BYTE            byRes[33];					 // 保留字节 
}NET_DVR_BACKUP_TIME_PARAM, *LPNET_DVR_BACKUP_TIME_PARAM;
/********************************* end *******************************************/

typedef enum _COMPRESSION_ABILITY_TYPE_
{
    COMPRESSION_STREAM_ABILITY = 0, //码流压缩类型
	MAIN_RESOLUTION_ABILITY = 1,	//主码流压缩分辨率
	SUB_RESOLUTION_ABILITY  = 2,	//子码流压缩分辨率
	EVENT_RESOLUTION_ABILITY =  3,  //事件压缩参数分辨率
	FRAME_ABILITY = 4,				//帧率能力
	BITRATE_TYPE_ABILITY = 5,		//位率类型能力
	BITRATE_ABILITY = 6,			//位率上限
	THIRD_RESOLUTION_ABILITY = 7,   //三码流压缩分辨率
	STREAM_TYPE_ABILITY = 8,        //码流类型
	PIC_QUALITY_ABILITY = 9,         //图像质量
	INTERVAL_BPFRAME_ABILITY = 10,  //BP帧间隔
	VIDEO_ENC_ABILITY = 11,           //视频编码能力
	AUDIO_ENC_ABILITY = 12,           //音频编码能力
	VIDEO_ENC_COMPLEXITY_ABILITY = 13, //视频编码复杂度能力
	FORMAT_ABILITY = 14, //封装格式能力
}COMPRESSION_ABILITY_TYPE;

//能力列表
typedef struct tagNET_DVR_ABILITY_LIST
{ 
    DWORD     dwAbilityType;	//能力类型 COMPRESSION_ABILITY_TYPE
    BYTE      byRes[32];        //保留字节
    DWORD     dwNodeNum;		//能力结点个数
    NET_DVR_DESC_NODE  struDescNode[MAX_NODE_NUM];  //描述参数  
}NET_DVR_ABILITY_LIST, *LPNET_DVR_ABILITY_LIST;

#define MAX_ABILITYTYPE_NUM  12   //最大能力项
// 压缩参数能力列表
typedef struct tagNET_DVR_COMPRESSIONCFG_ABILITY
{ 
    DWORD     dwSize;            //结构长度
    DWORD     dwAbilityNum;		//能力类型个数
    NET_DVR_ABILITY_LIST struAbilityNode[MAX_ABILITYTYPE_NUM]; //描述参数  
}NET_DVR_COMPRESSIONCFG_ABILITY, *LPNET_DVR_COMPRESSIONCFG_ABILITY;

/********************************9000RH begin****************************************/
#define SUPPORT_PD_NUM			16
#define SUPPORT_ARRAY_NUM		8
#define SUPPORT_VD_NUM			128

typedef enum tagRAID_MODE
{
    RAID0 = 1,
    RAID1,
    RAID10,
    RAID1E,
    RAID5,
    RAID6,
    RAID50,
    JBOD, 
    RAID60
}RAID_MODE;

typedef enum tagHD_SUPPORT_TYPE
{
    HD_TYPE_SATA    = 0x01,
    HD_TYPE_PATA    = 0x02,
    HD_TYPE_SAS     = 0x04,
    HD_TYPE_ATAPI   = 0x08,
    HD_TYPE_TAPE    = 0x10,
    HD_TYPE_SES     = 0x20
}HD_SUPPORT_TYPE;

// 按位表示 位为0表示不支持  1表示支持
typedef enum tagSUPPORT_RAID_TYPE
{
    RAID0_ABILITY   = 0x0001,
    RAID1_ABILITY   = 0x0002,
    RAID10_ABILITY  = 0x0004,
    RAID1E_ABILITY  = 0x0008,
    RAID5_ABILITY   = 0x0010,
    RAID6_ABILITY   = 0x0020,
    RAID50_ABILITY  = 0x0040,
    JBOD_ABILITY    = 0x0080,
    RAID60_ABILITY  = 0x0100
}SUPPORT_RAID_TYPE;

// 物理磁盘 
typedef struct tagNET_DVR_PHY_DISK_INFO
{
    WORD    wPhySlot;         // 硬盘槽位 
    BYTE    byType;         // 硬盘信息；0 普通，1全局热备，2-阵列热备 3-阵列盘
    BYTE    byStatus;       // 硬盘状态；  0-正常 1-降级 2-已删除 3-磁盘丢失 4-下线 5-次正常 6-外来 7-异常 8-SMART状态异常 0xff-不存在
    BYTE    byMode[40];   // 硬盘类型 字符串
    DWORD   dwHCapacity;    //  磁盘总量高32位 单位kb
    DWORD   dwLCapacity;    //  磁盘总量低32位
    BYTE    byArrrayName[MAX_NAMELEN];
    WORD    wArrayID;          // 所属阵列ID
    BYTE    byRes[102];         // 保留字节  
}NET_DVR_PHY_DISK_INFO, *LPNET_DVR_PHY_DISK_INFO;

typedef struct tagNET_DVR_PHY_DISK_LIST
{
    DWORD   dwSize;
    DWORD   dwCount;
    NET_DVR_PHY_DISK_INFO struPhyDiskInfo[SUPPORT_PD_NUM];
}NET_DVR_PHY_DISK_LIST, *LPNET_DVR_PHY_DISK_LIST;

typedef enum tagBGA_TYPE
{
    BGA_REBUILD = 0x01,            // 重建
    BGA_CONSISTENCY_FIX = 0x02,    // 一致性检查并修复
    BGA_CONSISTENCY_CHECK = 0x04,  // 一致性检查
    BGA_INIT_QUICK = 0x08,         // 初始化(快)
    BGA_INIT_BACK = 0x10,          // 初始化(完全)
    BGA_MIGRATION = 0x20,       // 迁移
    BGA_INIT_FORE = 0x40,           // 初始化
    BGA_COPYBACK = 0x80             // 回迁
}BGA_TYPE;

typedef enum tagBGA_STATE
{
    BGA_STATE_NONE = 0,     //  无后台任务
    BGA_STATE_RUNNING,       //  后台任务正在运行
    BGA_STATE_ABORTED,       //  后台任务取消
    BGA_STATE_PAUSED         //  后台任务暂停     
}BGA_STATE;
typedef struct tagNET_DVR_BGA_INFO
{
	BYTE    byBga;  // 后台任务及类型 
	BYTE	byBgaState;		   /*函数返回值--后台任务状态*/
	WORD    wBgaPercentage;     /*函数返回值--后台任务执行百分比*/
	BYTE    byRes[4];  // 保留字节
}NET_DVR_BGA_INFO, *LPNET_DVR_BGA_INFO;

// 阵列信息
typedef struct tagNET_DVR_ARRAY_INFO
{
    WORD    wArrayID; // 阵列ID
    BYTE    byRaidMode; // raid模式  参照RAID_MODE
    BYTE    byStatus;  // 0-在线 1-磁盘丢失 2-下线 3-降级 4-异常 5-次正常 6-外来盘  7-已删除 8-SMART状态异常 0xff-不存在
    DWORD   dwHCapacity; // 阵列容量高32位
    DWORD   dwLCapacity; // 阵列容量低32位
    DWORD   dwHFreeSpace;   // 阵列剩余空间高32位
    DWORD   dwLFreeSpace;   // 阵列剩余空间高32位
    BYTE    byArrayName[MAX_NAMELEN]; // 阵列名称
    BYTE    byPDCount;  // 物理磁盘数目
    BYTE    bySpareCount;   // 热备数目
    BYTE    byRes1[2];
    WORD    wPDSlots[SUPPORT_PD_NUM];	// 物理磁盘索引
    WORD    wSparePDSlots[SUPPORT_PD_NUM];	// 热备磁盘索引
    NET_DVR_BGA_INFO	struBgaInfo;	// 后台任务运行状态
    BYTE    byRes2[80]; // 保留字节
}NET_DVR_ARRAY_INFO, *LPNET_DVR_ARRAY_INFO;

typedef struct tagNET_DVR_ARRAY_LIST
{
    DWORD   dwSize;     // 结构体大小
    DWORD   dwCount;    // 阵列个数
    NET_DVR_ARRAY_INFO struArrayInfo[SUPPORT_ARRAY_NUM];
}NET_DVR_ARRAY_LIST, *LPNET_DVR_ARRAY_LIST;

//虚拟磁盘信息
typedef struct tagNET_DVR_VD_INFO
{
    WORD    wSlot;    //虚拟磁盘槽位  
    BYTE    byStatus; // 状态0-正常 1-降级 2-已删除 3-磁盘丢失 4-下线 5-次正常 6-外来 7-异常 8-SMART状态异常 0xff-不存在 
    BYTE    byRaidMode; // Raid 模式 参照 RAID_MODE
    WORD    wArrayID;      // 所属阵列ID
    BYTE    byRepair;   // 是否需要修复 0 不需要 1需要
    BYTE	byUsage;	  	//LUN卷的使用方式  0-IPSAN 1-FCSAN 2-DVR网盘 3-NAS 4-录像卷
    BYTE	byArrayName[MAX_NAMELEN];
    BYTE    byName[MAX_NAMELEN];    // 虚拟磁盘名名称
    DWORD   dwHCapacity;    // 虚拟磁盘容量高32位
    DWORD   dwLCapacity;    // 虚拟磁盘容量低32位
    DWORD   dwHFreeSpace;   // 虚拟磁盘剩余空间高32位
    DWORD   dwLFreeSpace;   // 虚拟磁盘剩余空间低32位
    NET_DVR_BGA_INFO	struBgaInfo;	// 后台运行状态
	DWORD				dwBlockSize;	//最小存储单元块大小
	NET_DVR_IPADDR		struWarrantIP;	// 授权的DVR网盘IP
	char				szArrayGroup[NAME_LEN]; 	//使用的阵列名称组，以逗号隔开，为空则使用默认阵列
    BYTE				byRes[20];
}NET_DVR_VD_INFO, *LPNET_DVR_VD_INFO;

typedef struct tagNET_DVR_VD_LIST
{
    DWORD   dwSize;     // 结构体大小
    DWORD   dwCount;    // 虚拟磁盘个数
    NET_DVR_VD_INFO struVDInfo[SUPPORT_VD_NUM];  //虚拟磁盘数组
}NET_DVR_VD_LIST, *LPNET_DVR_VD_LIST;

typedef struct tagNET_DVR_ADAPTER_VERSION
{
    WORD    wMajorVersion;
    WORD    wMinorVersion;
    WORD    wRevisionNumber;
    WORD    wBuildNumber;
}NET_DVR_ADAPTER_VERSION, *LPNET_DVR_ADAPTER_VERSION;

typedef struct tagNET_DVR_VD_SLOT
{
    WORD  wVDSlot;
    BYTE  byAlloc;  // 是否已经分配
    BYTE  byRes[5];
    DWORD dwHVDSlotSize;	// 虚拟磁盘空间大小高32位
	DWORD dwLVDSlotSize;	// 虚拟磁盘空间大小低32位
}NET_DVR_VD_SLOT, *LPNET_DVR_VD_SLOT;

typedef struct tagNET_DVR_ARRAY_SPACE_ALLOC_INFO
{
    BYTE    byVDSlotCount;						/*current number of slots in DG*/ 
    BYTE    byRes1[3];              // 保留字节
    NET_DVR_VD_SLOT struVDSlots[SUPPORT_VD_NUM];
}NET_DVR_ARRAY_SPACE_ALLOC_INFO, *LPNET_DVR_ARRAY_SPACE_ALLOC_INFO;

typedef struct tagNET_DVR_RAID_ADAPTER_INFO
{
    DWORD dwSize;    // 结构体大小
    NET_DVR_ADAPTER_VERSION struVersion;	// 适配器版本号
    BYTE    bySlotCount;    //适配器槽位数
    BYTE    bySupportMigrate;  // 迁移(1-支持  0-不支持)
    BYTE    bySupportExpand;   // 扩容  (1-支持  0-不支持)
    BYTE    bySupportRebuild;  // 是否支持重建阵列 (1、支持 0-不支持)
    WORD    wSlotSupportType; //  按位表示 HD_SUPPORT_TYPE
    WORD    wSupportRaidType;      // 支持Raid 类型 按位表示  
    BYTE    byAutoRebuild;      // 0 不自动重建 1自动重建 可设
    BYTE    byRes[27];      // 保留字节
}NET_DVR_RAID_ADAPTER_INFO, *LPNET_DVR_RAID_ADAPTER_INFO;

typedef struct tagNET_DVR_OPERATE_ARRAY_PARAM
{
    //是否一键创建  如果为一键创建，则创建时时候的之需要array名称，而不需要其他参数
    // 其他参数有设备自行创建
    BYTE    byRaidMode;     // 创建/迁移时Raid的类型
    BYTE    byPDCount;  // 物理磁盘数目
    WORD    wArrayID;   // 迁移或者重建时需要指出阵列ID      
    WORD    wPDSlots[SUPPORT_PD_NUM];// 物理磁盘 
    BYTE    byName[MAX_NAMELEN];  // array 名称
	BYTE    byInitMode;              //初始化方式
    BYTE    byRes2[19];
}NET_DVR_OPERATE_ARRAY_PARAM, *LPNET_DVR_OPERATE_ARRAY_PARAM;
#define INIT_QUICK                                      0    /*快速初始化*/
#define INIT_FULLFOREGROUND                             1    /*完全初始化(前台)*/
#define INIT_FULLBACKGROUND                             2    /*完全初始化(后台)*/

typedef struct tagNET_DVR_OPERATE_VD_PARAM
{
    WORD    wArrayID;		// 阵列ID
    BYTE    bySlot;			// 创建虚拟磁盘指定槽位
    BYTE    byInitType;     // 创建虚拟磁盘时初始化类型 0 - 快速初始化 1 - 前台完全初始化 2 - 后台完全初始化
	DWORD	dwHCapacity;	// 虚拟磁盘大小高32位
	DWORD	dwLCapacity;	// 虚拟磁盘大小低32位
    BYTE    byName[MAX_NAMELEN]; // 虚拟磁盘名称
    BYTE    byRes2[16];          // 保留字节 
}NET_DVR_OPERATE_VD_PARAM, *LPNET_DVR_OPERATE_VD_PARAM;


typedef struct tagNET_DVR_SPARE_DISK_PARAM
{
    WORD    wPDSlot;        // 物理磁盘槽位
    WORD    wArrayID;       // 所属的阵列
    BYTE    bySpareType;    // 热备类型 1-全局热备  2 指定阵列  当为指定阵列的时候需要指出所属阵列的ID
    BYTE    byRes[7];       // 保留字节
}NET_DVR_SPARE_DISK_PARAM, *LPNET_DVR_SPARE_DISK_PARAM;

/********************************9000RH End****************************************/


#define MATRIX_MAXDECSUBSYSTEMCHAN	4//视频综合平台解码子系统通道号

//获取解码子系统关联信息
typedef struct tagNET_DVR_DECSUBSYSTEMJIONSTATUS
{
    BYTE	byJoinStatus;//关联状态，0-没有关联，1-已经关联
    BYTE	byJoinSubSystem;//所关联子系统槽位号
    BYTE	byJoinDispNum;//所关联显示通道号
    BYTE	byJoinSubWindowNum;//所关联子窗口号
    BYTE	byRes[4];
}NET_DVR_DECSUBSYSTEMJIONSTATUS,LPNET_DVR_DECSUBSYSTEMJIONSTATUS;

typedef struct tagNET_DVR_SINGLESUBSYSTEMJOININFO
{
    BYTE	bySubSystemType;//子系统类型，0-无，1-解码用子系统，2-编码用子系统，3-级联输出子系统，4-级联输入子系统,5-码分子系统，6-报警子系统
    BYTE	byConnectStatus;//级联系统关联状态，1-连接正常，2-连接断开
    BYTE    byMatrixNum;//级联视频综合平台号，子系统类型是3或4时可用
    BYTE	bySubSystemNum;//级联子系统槽位号，0~79，子系统类型是3或4时可用    
    NET_DVR_DECSUBSYSTEMJIONSTATUS struDecSub [MATRIX_MAXDECSUBSYSTEMCHAN];
    BYTE	byBindStatus;//绑定状态，0-没有绑定，1-已经绑定（大屏拼接时用到）
    BYTE    byRes[7];
}NET_DVR_SINGLESUBSYSTEMJOININFO,LPNET_DVR_SINGLESUBSYSTEMJOININFO;

typedef struct tagNET_DVR_ALLDECSUBSYSTEMJOININFO
{
    DWORD dwSize;
    NET_DVR_SINGLESUBSYSTEMJOININFO struSingleSubSystemJoinInfo[MAX_SUBSYSTEM_NUM];//80
    BYTE  byRes[8];
}NET_DVR_ALLDECSUBSYSTEMJOININFO, *LPNET_DVR_ALLDECSUBSYSTEMJOININFO;

//2010-04-13 增加NAT功能相关配置
typedef struct tagNET_DVR_NATASSOCIATECFG
{
	DWORD		  		dwSize;
    NET_DVR_NETCFG_V30  struNatIpAddress[2];//NAT IP地址 
	BYTE				byNATEnable;//是否启用NAT功能，0-不启用，非0-启用
	BYTE		  		byRes[63];
}NET_DVR_NATASSOCIATECFG, *LPNET_DVR_NATASSOCIATECFG;

//2010-06-01 视频综合平台报警配置
typedef struct tagNET_DVR_TEMPERATUREALARMCFG
{
	BYTE	 byEnableTemperatureAlarm;//使能温度超限报警，0-报警，1-不报警
    BYTE	 byRes1[3];
	int 	 iTemperatureUpLimited;	//精确到小数点后两位，如1234表示温度12.34度
	int 	 iTemperatureDownLimited;	
	NET_DVR_HANDLEEXCEPTION_V30 struTempHandleType;	/* 处理方式 */
	NET_DVR_SCHEDTIME struAlarmTime[MAX_DAYS][MAX_TIMESEGMENT_V30]; /*布防时间*/
	BYTE	 byRes2[32];
}NET_DVR_TEMPERATUREALARMCFG, *LPNET_DVR_TEMPERATUREALARMCFG;

typedef struct tagNET_DVR_BOARDALARMCFG
{
	BYTE   byEnablePullAlarm;//热插拔报警使能，1-报警，0-不报警
    BYTE   byRes1[3];
	NET_DVR_HANDLEEXCEPTION_V30 struBoardHandleType;	/* 处理方式 */
	NET_DVR_SCHEDTIME struAlarmTime[MAX_DAYS][MAX_TIMESEGMENT_V30]; /*布防时间*/
	BYTE   byRes2[32];
}NET_DVR_BOARDALARMCFG, *LPNET_DVR_BOARDALARMCFG;


typedef struct tagNET_DVR_VIDEOPLATFORMALARMCFG
{
	DWORD 						 dwSize;
	NET_DVR_TEMPERATUREALARMCFG  struTempAlarmCfg;	
	NET_DVR_BOARDALARMCFG 		 struBoardAlarmCfg;	
    NET_DVR_HANDLEEXCEPTION_V30  struHandleException[MAX_EXCEPTIONNUM];//0-风扇异常，1-子系统异常，2-IP地址冲突，3-网线断，4-非法访问，5-光纤异常，6-前面板异常
    BYTE						 byRes[32];
}NET_DVR_VIDEOPLATFORMALARMCFG,*LPNET_DVR_VIDEOPLATFORMALARMCFG;
//2010-05-17
typedef struct  tagNET_DVR_CODESPLITTERASSOCIATE
{
	DWORD		dwSize;
	NET_DVR_IPADDR   struIP;  /*编码器IP地址*/
	WORD		wPort;        //编码器端口号
	BYTE		byRes1[6];
    BYTE		sUserName[NAME_LEN];	/* 用户名（32） */
	BYTE		sPassword[PASSWD_LEN];	/*密码 （16）*/
	BYTE        byChan;//编码器通道号
	BYTE		byRes2[15];
} NET_DVR_CODESPLITTERASSOCIATE, *LPNET_DVR_CODESPLITTERASSOCIATE;

//2010-06-01 视频综合平台报警上传结构
typedef struct tagNET_DVR_MATRIXSUBSYSTEMINFO
{
	BYTE   byMatrixNum;//视频综合平台号
	BYTE	bySubSystemNum;//子系统槽位号
	BYTE   byRes [14];
} NET_DVR_MATRIXSUBSYSTEMINFO, *LPNET_DVR_MATRIXSUBSYSTEMINFO;

typedef struct tagNET_DVR_VIDEOPLATFORM_ALRAMINFO
{
	DWORD  dwSize;      //结构体大小
	BYTE   byAlarmType;	// 0-拔出子板，1-插入子板,2-温度超上限报警，3-温度超下限报警，4-风扇状态异常，5-子系统异常,6-非法访问，7-光纤异常报警,8-前面板异常报警
	BYTE   byBoardNum;     //子板号，从1起，B10不支持该字段，无效，置为0xff
	BYTE   byRes1[2];
    BYTE   bySubSystemChan[8]; //子板槽位号,一个子板中有8个子系统，其分别对应的槽位号，子系统异常时，bySubSystemChan[0]表示对应子系统序号        
	int    iTemperature;  //温度超限报警时有用，温度值
	BYTE   byMainboardSeq;//温度超限报警时有用，0-非主板，1-主板
    BYTE   byRes2[3];
    BYTE   byFanSequence[32];//风扇异常时风扇号    
	NET_DVR_MATRIXSUBSYSTEMINFO struInputNote;// 光纤异常报警时使用，输入结点
	NET_DVR_MATRIXSUBSYSTEMINFO struOutputNote;//光纤异常报警时使用，输出结点
	BYTE   byRes3[68];	
}NET_DVR_VIDEOPLATFORM_ALRAMINFO,*LPNET_DVR_VIDEOPLATFORM_ALRAMINFO;

/***************************审讯DVR begin *****************************/
#define MAX_INQUEST_PIP_NUM		3     //单通道显示的画中画数目
#define MAX_INQUEST_CDRW_NUM	4     //最大刻录机数目
#define MAX_INQUEST_PIP_NUM_EX	16		//审讯机画中画最大个数

typedef struct 
{
	DWORD      dwSize;
    DWORD      dwNum;                       //刻录机的数量
	DWORD      dwRwSelectPara[MAX_CHANNUM_V30];// 是否选中该光驱
	DWORD      dwModeSelect;                //0表示循环刻录模式  1表示并行刻录模式(默认模式)
	BYTE	   byRes[24];                   //保留
	DWORD	   dwStartCDRW;                 //DVR 本地已经开始刻录
	DWORD      dwHdExcp;                    //硬盘有异 常
	DWORD	   dwInterval;                  //时间间隔，10分钟(0)、20分钟(1)、30分钟(2)
	char 	   sLable[64];                  //光盘名称
}NET_DVR_INQUEST_CDRW_CFG, *LPNET_DVR_INQUEST_CDRW_CFG;

typedef struct
{
    char      sFileName[36];			 //文件名
    DWORD     dwFileLen;				 //文件长度
}NET_DVR_INQUEST_FILEINFO, *LPNET_DVR_INQUEST_FILEINFO;

typedef struct 
{
    DWORD     dwFileNum;			         // 需要刻录或者删除的文件数，最多一次20个
	NET_DVR_INQUEST_FILEINFO struFileInfo[MAX_RECORD_FILE_NUM];
	//下面两个参数在表示刻录的文件时使用
	DWORD     dwCDIndex;				    //刻录机的索引：1:选择1号刻录机；2:选择2号刻录机； 3:3号刻录机,4:4号刻录机,5:所有刻录机
	DWORD      bFinalizeDisc;		     	// 0=刻录完之后不封盘；1=刻录完之后封盘
}NET_DVR_INQUEST_FILES, *LPNET_DVR_INQUEST_FILES;

typedef struct 
{	
	DWORD     dwEnable;			//刻录机状态是否有效,0-无效,1-有效	
	DWORD     dwStatus;			/* 当dwType=0时，
								0-光盘正常，1-无光盘或光盘异常,
								当dwType=1或2时，
								0-刻录正常，1-无光盘或光盘异常，
								2-光盘已封盘(81不支持)，3-光盘空间不足，
								4-异常导致审讯终止(81不支持)
								当dwType=3时，
								0-刻录正常，1-无光盘或光盘异常，
								2-光盘已封盘(81不支持)，3-光盘空间不足
								当dwType=4时，
								0-刻录正常，1-无光盘或光盘异常，
								2-光盘已封盘(81不支持)，3-光盘空间不足
								当dwType=5时,
								0-光盘正常， 1-无光盘或光盘异常,
								2-光盘已封盘(81不支持)
								当dwType=6或7时,
								0-刻录正常, 1-无光盘或光盘异常,
	2-光盘已封盘(81不支持), 3-光盘空间不足*/		
	DWORD    dwVolumn;      //光盘容量,单位M
	DWORD    dwFreeSpace;   //光盘剩余容量,单位M    
	DWORD    dwTimeLeft; 	// 光盘剩余时间，单位秒
	BYTE  	    byCDType;     	// 光盘类型
	BYTE       byRes[3];      //保留字节
}NET_DVR_INQUEST_CDRW, *LPNET_DVR_INQUEST_CDRW;

typedef struct 
{	
     /*运行状态：0-审讯开始，
	1-审讯过程中刻录，2-审讯停止，
	3-刻录审讯文件, 
	4-备份(事后备份和本地备份)
	5-空闲
	6-初始化硬盘
	7-恢复审讯*/
    DWORD    dwType;        	
    NET_DVR_INQUEST_CDRW   strCDRWNum[MAX_INQUEST_CDRW_NUM];   //数组0表示刻录机1	
	NET_DVR_TIME_EX			struInquestStartTime;		//审讯开始的时间点
	BYTE					byRes[16];             //保留
}NET_DVR_INQUEST_CDRW_STATUS, *LPNET_DVR_INQUEST_CDRW_STATUS;

typedef struct
{
	BYTE     byPipChan;			  //画中画显示的通道 0xFF关闭
	BYTE     byRes[3];			  //保留字节
	WORD     wTopLeftX;			  //画中画的x坐标
	WORD     wTopLeftY;			  //画中画的Y坐标
}NET_DVR_INQUEST_PIP_PARAM, *LPNET_DVR_INQUEST_PIP_PARAM;

typedef struct 
{
	BYTE     byBaseChan;          //显示画中画所在的通道
	BYTE     byBackChan;          //显示画中画背景通道
	BYTE     byPIPMode;           /*是否开启, 
									0 当前窗口无小画面
									1 当前窗口有1个小画面
									2 当前窗口有2个小画面
									3 当前窗口有3个小画面
                                  */
	BYTE     byRes;               //保留字节
	NET_DVR_INQUEST_PIP_PARAM  strPipPara[MAX_INQUEST_PIP_NUM];  //画面位置的参数    
}NET_DVR_INQUEST_PIP_STATUS, *LPNET_DVR_INQUEST_PIP_STATUS;

//V40扩展，将画中画个数扩展为32个
typedef struct tagNET_DVR_INQUEST_PIP_PARAM_V40
{
	BYTE     byPipChan;      /*画中画显示的通道 0xFF关闭*/ 
	BYTE     byRes1[3];
	WORD     wTopLeftX;     	/*画中画的x坐标*/
	WORD     wTopLeftY;     	/*画中画的Y坐标*/
	WORD     wHeight;    		/*画中画的高 */
	WORD     wWidth;    		/*画中画的宽 */
	BYTE	 byRes2[32];
}NET_DVR_INQUEST_PIP_PARAM_V40, *LPNET_DVR_INQUEST_PIP_PARAM_V40;

typedef struct tagNET_DVR_INQUEST_PIP_STATUS_V40
{
	NET_DVR_STRUCTHEAD	struStructHead;
	BYTE     		byBaseChan;     /*显示画中画所在的通道*/
	BYTE     		byBackChan;     /*显示画中画背景通道*/
	BYTE     		byPIPMode;      /*是否开启, 0 当前窗口无小画面
											1 当前窗口有1个小画面
											2 当前窗口有2个小画面
											3 当前窗口有3个小画面
											5 当前窗口有5个小画面
											7 当前窗口有7个小画面
											255  当前窗口关闭预览画面*/
	BYTE     					byPipCount;          /*小画面的个数*/
	BYTE						byRes[32];		/*保留*/
	NET_DVR_INQUEST_PIP_PARAM_V40 	strPipPara[MAX_INQUEST_PIP_NUM_EX];  /*画面位置的参数*/
}NET_DVR_INQUEST_PIP_STATUS_V40, *LPNET_DVR_INQUEST_PIP_STATUS_V40;

typedef struct 
{
	BYTE	sSecretKey[16];        /*码流加密密钥*/
	BYTE	byRes[64];             /*保留字节*/
}NET_DVR_INQUEST_SECRET_INFO, *LPNET_DVR_INQUEST_SECRET_INFO;


/***************************审讯DVR end *****************************/


/********************************接口参数结构(end)*********************************/
#define		MAX_BIGSCREENNUM	100//最多大屏拼接数

typedef struct tagNET_DVR_SINGLESCREENCFG
{
    BYTE	byScreenSeq;//屏幕序号，0xff表示不用此屏,64-T解码器第一个表示主屏
    BYTE	bySubSystemNum;//解码子系统槽位号,解码器此值没有用
    BYTE	byDispNum;//解码子系统上对应显示通道号，64-T解码器中该值表示解码器的显示通道号
    BYTE	byRes[9];
}NET_DVR_SINGLESCREENCFG, *LPNET_DVR_SINGLESCREENCFG;

typedef struct tagNET_DVR_BIGSCREENCFG
{
    DWORD   dwSize;
	BYTE	byEnable;//大屏拼接使能，0-不使能，1-使能
    BYTE	byModeX;/*大屏拼接模式*/
    BYTE	byModeY;
    BYTE	byMainDecodeSystem;//综合平台的解码板中该值表示主屏槽位号，64-T解码器中该值表示解码通道号
    BYTE	byMainDecoderDispChan;//主屏所用显示通道号，1.1netra版本新增，netra解码器有两个显示通道，都能够作为主屏。64-T中该值无效
	BYTE	byVideoStandard;      //大屏每个子屏制式相同 1:NTSC,2:PAL
    BYTE	byRes1[2];
	DWORD  dwResolution;         //大屏每个子屏分辨率相同
    //大屏拼接从屏幕信息
    NET_DVR_SINGLESCREENCFG struFollowSingleScreen[MAX_BIGSCREENNUM]; 
    //起始坐标必须为基准坐标的整数倍
	WORD    wBigScreenX; //大屏在电视墙中起始X坐标
	WORD    wBigScreenY; //大屏在电视墙中起始Y坐标
	BYTE	byRes2[12];
}NET_DVR_BIGSCREENCFG, *LPNET_DVR_BIGSCREENCFG;

 
#define	DECODEPIC_LEFTADJUST			1		/*图像左移*/
#define	DECODEPIC_RIGHTADJUST			2		/*图像右移*/
#define	DECODEPIC_UPADJUST				3		/*图像上移*/
#define	DECODEPIC_DOWNADJUST			4		/*图像下移*/
#define	DECODEPIC_REDUCEADJUST			5		/*图像缩小*/  
#define	DECODEPIC_FULL_SCREEN_ADJUST	6		/*图像全屏*/
#define	DECODEPIC_CANCEL_FULL_SCREEN_ADJUST	7		/*图像取消全屏显示*/   

#define 	MAX_UNITEDMATRIX_NUM		8//级联中最多视频综合平台数量
#define 	MAX_SUBDOMAIN_NUM		    4//级联中最多子域数量
typedef struct tagNET_DVR_SUBSERVERINFO
{
	BYTE		bySequence;//序号，对于子域，是子域号，对于视频综合平台，是平台号，0表示无此平台\子域
	BYTE		byBelongSubDomain;//对于平台有效，表示属于哪个子域
	BYTE		byRes1[6];
	DWORD       dwMaxIpcNums;//连接的最多IPC数量
    NET_DVR_IPADDR struSubMatrixIP;		/*IP地址*/
    WORD		wSubMatrixPort;        /*子系统端口号*/
    BYTE		byRes2[6];
}NET_DVR_SUBSERVERINFO, *LPNET_DVR_SUBSERVERINFO;

typedef struct tagNET_DVR_UNITEDMATRIXINFO
{
	DWORD dwSize;
	NET_DVR_SUBSERVERINFO struDomainInfo;
	NET_DVR_SUBSERVERINFO struSubDomainInfo[MAX_SUBDOMAIN_NUM];//子域信息
	NET_DVR_SUBSERVERINFO struMatrixInfo[MAX_UNITEDMATRIX_NUM];//视频综合平台信息
    BYTE  byRes[32];
}NET_DVR_UNITEDMATRIXINFO, *LPNET_DVR_UNITEDMATRIXINFO;		

typedef struct tagNET_DVR_REGCALLBACKPARAM
{
	char sDeviceID[NAME_LEN];//设备ID串
	char sPassword[PASSWD_LEN];
	BYTE sSerialNumber[SERIALNO_LEN]; /* 设备序列号 */
	DWORD dwDeviceType;//设备类型
	BYTE nStatus;// 上下线状态（0下线，1上线）
	/* net type, 0: unknow; 1: 2G wireless networks; 2: 3G wireless networks; 3: line networks */
	BYTE byNetType;	
	BYTE byRes[14];
}NET_DVR_REGCALLBACKPARAM, *LPNET_DVR_REGCALLBACKPARAM;

typedef struct tagNET_DVR_LOGONREPONSEPARAM
{
    //心跳时间间隔，单位：秒, 5的倍数，180秒以内。默认是15秒。
	WORD wHeartbeatTime;
	BYTE byOvertimes;// 设备心跳超时次数，默认是3次
	BYTE byRes[13];	
}NET_DVR_LOGONREPONSEPARAM, *LPNET_DVR_LOGONREPONSEPARAM;


typedef struct tagNET_DVR_PREVIEWPARAM
{
    BYTE byTransProtol;		//传输协议，0-TCP, 1-UDP
    BYTE byTransMode;		///* 传输码流模式 0－主码流 1－子码流*/ 
    NET_DVR_IPADDR struCuIp; //CU端IP地址
    WORD wPort;/*CU端口*/
    WORD wUdpPort;
    BYTE bySupportQos;//是否启用QOS,1-启用，0-不启用
	//是否是NAT预览请求，0-否，1-是(只需byTransMode字段)
	BYTE  byNatRequest;
    BYTE  byPreviewType;// 0-普通预览 1-延时预览
	BYTE  byRes[7];
}NET_DVR_PREVIEWPARAM, *LPNET_DVR_PREVIEWPARAM;
typedef struct tagNET_DVR_DEVICENATINFO
{
	NET_DVR_IPADDR struPuIp; //PU端外网IP地址
	WORD	wOuterPort;/*PU外网端口*/
	WORD	wInterPort;//PU发送视频的本地端口
    DWORD   nSessionID;//CMS分配的sessionID
	BYTE	byRes[4];
}NET_DVR_DEVICENATINFO, *LPNET_DVR_DEVICENATINFO;


typedef struct tagNET_DVR_PREVIEWCALLBACKPARAM
{
	LONG lChannel;
	BYTE nLinkProtocol;
	BYTE nTransMode;
    BYTE byPreviewType; //0-普通预览 1-延时预览
    BYTE byRes[5];
    DWORD nSessionID;//CMS分配的sessionID
}NET_DVR_PREVIEWCALLBACKPARAM, *LPNET_DVR_PREVIEWCALLBACKPARAM;

//回放
typedef struct tagNET_DVR_PLAYBACKREQUESTPARAM
{
    BYTE byPlayBackMode;		/* 回放下载模式 1－按名字 2－按时间 */
    BYTE byRes1[3];
    union
    {
        char sFileName [100];		/* 回放的文件名 */
        struct 
        {
            LONG	lChannel;				/*回放的通道号*/
            NET_DVR_TIME struStartTime;			/* 按时间回放的开始时间 */
            NET_DVR_TIME struStopTime;			/* 按时间回放的结束时间 */
            BYTE    byRes[48];
        }struPlayBackbyTime;
    }playbackmode;
    NET_DVR_IPADDR struCuIp; //CU端IP地址
    WORD	wPort;/*CU端口*/
    BYTE	byRes2[2];
    DWORD   dwSessionID;//CMS分配的sessionID,输出参数
    BYTE    byRes3[16];
}NET_DVR_PLAYBACKREQUESTPARAM, *LPNET_DVR_PLAYBACKREQUESTPARAM;    

//2010-10-06
typedef struct tagNET_DVR_PLAYBACKCALLBACKPARAM
{
    BYTE byPlayBackMode;		/* 回放下载模式 1－按名字 2－按时间 */
    BYTE byRes1[3];
    union
    {
        char sFileName [100];		/* 回放的文件名 */
        struct 
        {
            LONG    	lChannel;				/*回放的通道号*/
            NET_DVR_TIME struStartTime;			/* 按时间回放的开始时间 */
            NET_DVR_TIME struStopTime;			/* 按时间回放的结束时间 */
            BYTE       byRes[48];
        }struPlayBackbyTime;
    }playbackmode;
    DWORD nSessionID;//CMS分配的sessionID
    BYTE byRes2[44];
}NET_DVR_PLAYBACKCALLBACKPARAM, *LPNET_DVR_PLAYBACKCALLBACKPARAM;  

typedef struct tagNET_DVR_VOICEREQUESETPARAM
{
    BYTE	nVoiceChannel;		//对讲通道号
    BYTE	byRes1[3];
    NET_DVR_IPADDR struCuIp; //CU端IP地址
    WORD	 wPort;/*CU端口*/
    BYTE	byRes2[10];
}NET_DVR_VOICEREQUESTPARAM, *LPNET_DVR_VOICEREQUESTPARAM;             

typedef struct tagNET_DVR_ALARMSETUPREQUESETPARAM
{
	NET_DVR_IPADDR struCuIp; //CU端IP地址
	WORD	 wPort;/*CU端口*/
	BYTE	byRes[2];
}NET_DVR_ALARMSETUPREQUESTPARAM, *LPNET_DVR_ALARMSETUPREQUESTPARAM;		
	
typedef struct tagNET_DVR_GPSALARMINFO
{
    BYTE byDeviceID[NAME_LEN];/*设备的ID串*/
    NET_DVR_TIME_EX struGpsTime;    /*GPS上传的时间*/
    DWORD	dwLongitude;	/* 经度*/
    DWORD	dwLatitude;  /* 纬度*/
    int 	iTimeZone; /*时区，用分钟数表示，+60代表东1区，+480代表东8区，-60代表西区，-480代表西8区，该字段和GPSTime构成一个完整的时间描述*/ 
    DWORD dwDirection; /*车辆方向=实际方向（以度为单位，正北方向为，顺时针方向计算）*100*/
    WORD  wSatellites; /*卫星数量*/
    WORD  wPrecision; /*精度*/
    DWORD dwHeight; /*高度:厘米，预留*/
    DWORD dwGPSSeq; /*GPS序号，GPS补传时要用到*/
    WORD  wSpeed;//速度，单位，km/h
    /* direction[0]:'E'or'W'(东经/西经), direction[1]:'N'or'S'(北纬/南纬)*/
    char sDirection[2]; 
    BYTE byLocateMode;/*定位模式(初值0)，1,自主定位,2,差分3,估算,4,数据无效*/  
    BYTE byRes[3];
}NET_DVR_GPSALARMINFO, *LPNET_DVR_GPSALARMINFO;

//图片信息上传
typedef struct tagNET_DVR_PICINFO
{
	DWORD   dwSize;				//结构长度
	BYTE    byChanIndex;			//通道号
	BYTE    byRes1[3];				//保留
	BYTE 	byDeviceID[NAME_LEN];/*设备的ID串*/
	BYTE    byAbsTime[32];		//绝对时间点, yyyymmddhhmmssxxx,
	DWORD   dwPicLen;					//图片长度
	BYTE	byRes2[32];
	BYTE	*pPicBuffer;
}NET_DVR_PICTUREINFO, *LPNET_DVR_PICTUREINFO;

//平台参数
typedef struct tagNET_DVR_CMSPARAM
{
	DWORD   dwSize;
	NET_DVR_IPADDR struCmsAddr;
	WORD   wCmsPort;
	BYTE   byRes1[2];
	BYTE   sDeviceID[NAME_LEN];
	BYTE   byPassword[PASSWD_LEN];
	NET_DVR_IPADDR struPicServerAddr;
	WORD   wPicServerPort;
	WORD   wCmsUdpPort;//CMS用于UDP外网查询的端口
	BYTE   byRes2[12];
}NET_DVR_CMSPARAM, *LPNET_DVR_CMSPARAM;

///拨号功能
#define DIALPASSWD_LEN  32 //拨号密码长度

typedef struct tagNET_DVR_QOSPARAM
{
	WORD wMaxBitUL;	/* the maximum number of kbits/s in up-link traffic */
	WORD wMaxBitDL;	/* the maximum number of kbits/s in down-link traffic */
	BYTE byTrafficClass;	/* 0: conversationnal; 1: streaming; 2: interactive;3: background; 4: subscribed value(default) */
	BYTE byRes[7];
}NET_DVR_QOSPARAM, *LPNET_DVR_QOSPARAM;


typedef struct tagNET_DVR_PPPDPARAM
{
	BYTE byDialNum[NAME_LEN];		/* dial number, eg. "#777" */
	BYTE byUserName[NAME_LEN];	/* user name, eg. "card" */
	BYTE byPassword[DIALPASSWD_LEN];	/* password, eg. "card" */
	BYTE byApn[NAME_LEN];		/* access point name, eg. "cmnet" */
	NET_DVR_IPADDR struLocalIp;/* local IP address */
	NET_DVR_IPADDR struRemoteIp;/* remote IP address */
	WORD wMtuSize;		/* max transfer unit of ppp interface */
	BYTE byVerifyProtocal;	/* IPCP verify protocal: 0: auto; 1: CHAP; 2: PAP */
	BYTE byRes[25];	
}NET_DVR_PPPDPARAM, *LPNET_DVR_PPPDPARAM;

#define MAX_PHONE_NUM		        32//最长号码长度

typedef struct tagNET_DVR_DIALPARAM
{
	DWORD dwSize;
	BYTE bEnable3G;		/* 0: disable; 1: enable 3g */
	BYTE byDialMethod;		/* dial methold: 0: auto dial; 1: manual dial; */
	BYTE bySwitchMethod;	/* switch methold: 0: auto switch;1：3G优先，2: manual switch to 2G; 3: manual switch to 3G; */
    BYTE byEnaAlarmInDial;   /* 使能报警输入触发拨号; 0: disable; 1: enable */
    BYTE byRes1[10];
	WORD wOffLineTime;		/* auto off line when no connection exist,单位：分钟，范围：5~65535分钟 */	
	NET_DVR_PPPDPARAM struPppdParam;
    NET_DVR_QOSPARAM struQosParam;
    BYTE byUimNumber[MAX_PHONE_NUM];
    BYTE byRes2[24];
}NET_DVR_DIALPARAM, *LPNET_DVR_DIALPARAM;

typedef struct tagNET_DVR_DIALREQUEST
{
	BYTE byConnNum;		/*网卡序号*/
	BYTE byNetType;		/* 指定获得某个网络的默认拨号参数，设置时此参数没用。0：自动；1：CDMA；2：EVDO；3：WCDMA；4：TD-SCDMA */
	BYTE byRes[6];
} NET_DVR_DIALREQUEST, *LPNET_DVR_DIALREQUEST;
			 
			 
/* UIM card information */
typedef enum
{
	UIM_UNKNOWN = 0,
	UIM_VALID = 1,
	UIM_NOVALID = 4,
	UIM_ROAM = 11,
	UIM_NOEXIST = 255
}UIM_INFO;

/* real 3g mode */
typedef enum
{
	 /* evdo */
	RMODE_CDMA1X = 12,
	RMODE_EVDO = 14,
	RMODE_CDMAHYBRID = 18,
	/* wcdma */
	RMODE_GSM = 21,
	RMODE_GPRS = 22,
	RMODE_EDGE = 23,
	RMODE_WCDMA = 24,
	RMODE_HSDPA = 25,
	RMODE_HSUPA = 26,
	RMODE_HSPA = 27,
	/* tdscdma */
	RMODE_TGSM = 31,
	RMODE_TGPRS = 32,
	RMODE_TEDGE = 33,
	RMODE_TDSCDMA = 34,
	RMODE_TDHSDPA = 35,
	RMODE_TDHSUPA = 36,
	RMODE_TDHSPA = 37
}REAL_MODE;

typedef struct tagNET_DVR_DIALSTATUS
{
	 BYTE byRealMode;		/* REAL_MODE ,real 3g mode networks */
	 BYTE byUimCard;		/* UIM_INFO ,UIM card information */
	 BYTE byRes1[6];
	 DWORD dwSignal;			/* signal RSSI */
	 DWORD dwDialStatus;		/* dial status */
	 NET_DVR_IPADDR struLocalIp;	/* wireless networks IP address */
	 NET_DVR_IPADDR struRemoteIp;	/* wireless networks gateway */
	 NET_DVR_IPADDR struNetMask;	/* wireless networks netmask */
	 NET_DVR_IPADDR struDns;		/* wireless networks DNS */	 
	 BYTE  byRes2[16];
}NET_DVR_DIALSTATUS, *LPNET_DVR_DIALSTATUS;

//短信功能
#define MAX_WHITELIST_NUM	        8 //最大白名单数

#define HARDDISKFULL_EXCEPTION      0x0     /*硬盘满*/
#define HARDDISKERROR_EXCEPTION     0x1     /*硬盘错*/
#define ETHERNETBROKEN_EXCEPTION    0x2     /*网线断*/
#define IPADDRCONFLICT_EXCEPTION    0x3     /*IP地址冲突*/
#define ILLEGALACCESS_EXCEPTION     0x4     /*非法访问*/
#define VI_EXCEPTION                0x5     /*视频信号异常*/
#define VS_MISMATCH_EXCEPTION       0x6     /*输入/输出视频制式不匹配 */
#define VIDEOCABLELOSE_EXCEPTION    0x7     /*视频无信号*/
#define AUDIOCABLELOSE_EXCEPTION    0x8     /*音频无信号*/
#define ALARMIN_EXCEPTION           0x9     /*报警输入*/
#define MASKALARM_EXCEPTION         0xa     /*遮挡报警*/
#define MOTDET_EXCEPTION            0xb     /*移动侦测*/
#define RECORDING_EXCEPTION         0xc     /*录像异常*/
#define WIRELESS_EXCEPTION          0xd     /*PIR报警*/
#define PIR_EXCEPTION				0xe     /*无线报警*/
#define CALLHELP_EXCEPTION          0xf     /*呼救报警*/

#define PHONECFG_RECEIVE_SMS        0x0  /* 支持接收报警短信 */
#define PHONECFG_SMS_CONTROL        0x1  /* 支持短信控制上下线 */
#define PHONECFG_CALL_CONTROL       0x2  /* 支持呼叫控制上线 */

typedef struct tagNET_DVR_PHONECFG
{
    BYTE byWhiteList[MAX_PHONE_NUM];
    BYTE byPhonePerssion[32]; /*按字节表示是否使能该号码的某功能，具体位代表的含义
                                见PHONECFG_RECEIVE_SMS等定义 */
    BYTE byAlarmHandler[32];   /*按字节表示是否使能对某个报警类型的短信发送*/
    BYTE byRes[128];
} NET_DVR_PHONECFG, *LPNET_DVR_PHONECFG;

typedef struct tagNET_DVR_SMSRELATIVEPARAM
{
	 DWORD dwSize;
	 BYTE bEnableSmsAlarm;	/* 0: disable; 1: enable 3g */
	 BYTE byRes1[7];
	 NET_DVR_PHONECFG struWhiteList[MAX_WHITELIST_NUM];
	 BYTE byRes2[32];
}NET_DVR_SMSRELATIVEPARAM, *LPNET_DVR_SMSRELATIVEPARAM;


typedef struct tagNET_DVR_SMSLISTINFO
{
	 DWORD  dwSize;
	 DWORD dwTotalSmsNum;//短信条数
	 BYTE  byRes[8];
	 BYTE  *pSmsParam;
	 DWORD dwBufLen;//所分配指针长度，输入参数
}NET_DVR_SMSLISTINFO, *LPNET_DVR_SMSLISTINFO;

typedef struct tagNET_DVR_SMSPARAM
{
	 DWORD dwIndex;			/* the index of sms */
	 BYTE byStatus;			/* read yet or not */
	 BYTE byRes[7];
	 NET_DVR_TIME_EX struRecvTime;		/* sms receive time */
}NET_DVR_SMSPARAM, *LPNET_DVR_SMSPARAM;
				 
#define	MAX_SMSCONTENT_LEN		140//短信内容长度
typedef struct tagNET_DVR_SMSCONTENT
{
	BYTE byPhoneNum[MAX_PHONE_NUM];
	BYTE byMsg[MAX_SMSCONTENT_LEN];
}NET_DVR_SMSCONTENT, *LPNET_DVR_SMSCONTENT; 	
			  
//pin码配置
typedef enum
{
	CPIN_READY = 1,
	CPIN_PIN = 2,
	CPIN_PUK = 3,
	CPIN_PIN2 = 4,
	CPIN_PUK2 = 5
}PIN_READY;

typedef struct tagNET_DVR_PINSTATUS
{
	DWORD dwSize;
	BYTE byStatus;		/* PIN status, defination see enum: PIN_READY */
	BYTE byPinTimes;	/* remain input PIN times */
	BYTE byPukTimes;	/* remain input PUK times */	
	BYTE bEnableLock;	/* now the PIN locking function is enabled or not: 0, not enabled lock; 1, lock enabled */
	BYTE byRes[4];
}NET_DVR_PINSTATUS, *LPNET_DVR_PINSTATUS;

typedef enum
{
	PIN_ENABLE = 1,
	PIN_DISABLE = 2,
	PIN_VERIFY = 3,
	PUK_VERIFY = 4,
	PIN_CHANGE = 5
}PIN_CMD;
#define MAX_PIN_LEN		12  //PIN码最大长度
typedef struct tagNET_DVR_PINCODEPARAM
{
	 DWORD dwSize;
	 BYTE byPinCmd;		/* PIN command, defination see enum: PIN_CMD */
	 BYTE byRes1[3];
	 BYTE byPinCode[MAX_PIN_LEN];		/* pin/puk code */
	 BYTE byNewPinCode[MAX_PIN_LEN];	/* new pin code */
	 BYTE byRes2[16];
}NET_DVR_PINCODEPARAM, *LPNET_DVR_PINCODEPARAM;


//图片质量
typedef struct 
{
	/* 0=CIF, 1=QCIF, 2=D1 3=UXGA(1600x1200), 4=SVGA(800x600), 5=HD720p(1280x720),6=VGA*/
	WORD	wPicSize;
	WORD	wPicQuality; /* 图片质量系数 0-最好 1-较好 2-一般 */
	//抓图图片处理方式，1-上传中心，2-设备本地保存，3-上传中心同时设备本地保存
	BYTE	byPicTackleMode; 
	BYTE   byRes[11];
}NET_DVR_PUSHJPEGPARA, *LPNET_DVR_PUSHJPEGPARA;


#define	COM_PUSHALARM		0x1200	//设备基本报警信息上传，推模式设备使用
#define	COM_PUSHALARM_V30	0x1201	//设备基本报警信息上传v30，推模式设备使用
typedef struct tagNET_DVR_PUSHALARMINFO
{
	DWORD dwAlarmType;/*0-信号量报警,1-硬盘满,2-信号丢失,3－移动侦测,4－硬盘未格式化,5-读写硬盘出错,6-遮挡报警,7-制式不匹配, 8-非法访问*/
	DWORD dwAlarmInputNumber;/*报警输入端口*/
	DWORD dwAlarmOutputNumber[MAX_ALARMOUT];/*触发的输出端口，哪一位为1表示对应哪一个输出*/
	DWORD dwAlarmRelateChannel[MAX_CHANNUM];/*触发的录像通道，哪一位为1表示对应哪一路录像, dwAlarmRelateChannel[0]对应第1个通道*/
	DWORD dwChannel[MAX_CHANNUM];/*dwAlarmType为2或3,6时，表示哪个通道，dwChannel[0]对应第1个通道*/
	DWORD dwDiskNumber[MAX_DISKNUM];/*dwAlarmType为1,4,5时,表示哪个硬盘, dwDiskNumber[0]位对应第1个硬盘*/
	BYTE byDeviceID[NAME_LEN];/*设备的ID串*/
	BYTE byRes[4];
}NET_DVR_PUSHALARMINFO, *LPNET_DVR_PUSHALARMINFO;

typedef struct 
{
	DWORD dwAlarmType;/*0-信号量报警,1-硬盘满,2-信号丢失,3－移动侦测,4－硬盘未格式化,5-读写硬盘出错,6-遮挡报警,7-制式不匹配, 8-非法访问, 9-视频信号异常，10-录像异常 11- 智能场景变化  12-阵列异常 */
	DWORD dwAlarmInputNumber;/*报警输入端口*/
	BYTE byAlarmOutputNumber[MAX_ALARMOUT_V30];/*触发的输出端口，为1表示对应输出*/
	BYTE byAlarmRelateChannel[MAX_CHANNUM_V30];/*触发的录像通道，为1表示对应录像, dwAlarmRelateChannel[0]对应第1个通道*/
	BYTE byChannel[MAX_CHANNUM_V30];/*dwAlarmType为2或3,6，9，10时，表示哪个通道，dwChannel[0]对应第1个通道*/
	BYTE byDiskNumber[MAX_DISKNUM_V30];/*dwAlarmType为1,4,5时,表示哪个硬盘, dwDiskNumber[0]对应第1个硬盘*/
	BYTE byDeviceID[NAME_LEN];/*设备的ID串*/
	BYTE byRes[7];
}NET_DVR_PUSHALARMINFO_V30, *LPNET_DVR_PUSHALARMINFO_V30;

//2011-04-20
//启动控制
typedef struct tagNET_DVR_MB_AUTOWORKPARA
{
	/*当前启动控制方式 0:  预留,  1:  延时关机,  2:  自动开关机*/
	BYTE	byCurPowerCtrlType;   
    BYTE	byRes[3];
	NET_DVR_SCHEDTIME	struWorkTime[MAX_DAYS][2];	
}NET_DVR_MB_AUTOWORKPARA, *LPNET_DVR_MB_AUTOWORKPARA;

typedef struct tagNET_DVR_MB_POWERCTRLPARA
{
    DWORD    dwSize;
	DWORD	 dwHaltDelay; /* 关机延迟时间,单位min */
	NET_DVR_MB_AUTOWORKPARA  struAutoWorkPara;/*启动控制相关参数设置*/
	BYTE       byEnableUnderVoltProtect;   /*是否开启欠压保护*/
	BYTE       byUnderVoltPercent;   /*欠压保护百分比，有85、90、95三个有效值*/
	BYTE       byRes[34];
}NET_DVR_MB_POWERCTRLPARA, *LPNET_DVR_MB_POWERCTRLPARA;
/*注：1）、关机延迟时间, 可选时间为 0，5分钟，10分钟 ，20分钟 25分钟 30分钟 35分钟 40分钟 ，45 分钟 50分钟 ，60分钟 ，60*2分钟 ，60*3  60 *4   60*5  60*6 */

//自动备份
typedef struct tagNET_DVR_MB_AUTOBACKUPPARA
{
    DWORD dwSize;
	BYTE  byEnableAutoBackup; /* 是否开启自动备份 0 关闭 ，1 开启 */
	BYTE  byRes1[3];
	BYTE  byBackupChannel[MAX_CHANNUM_V30]; 	/*需要备份的通道*/
	BYTE  byBackupDays[MAX_CHANNUM_V30];/*备份天数*/
	/* 备份文件类型 
	{0,ALL_RECORD_TYPE,全部},
	{1,TIMING_REC,定时},
	{2,MOTION_DETECT_REC,移动侦测 },
	{3,ALARM_REC,报警 },
	{4,MANUAL_REC,手动录像}*/
	BYTE  byBackupFileType[MAX_CHANNUM_V30];
	NET_DVR_SCHEDTIME struBackupTime[MAX_CHANNUM_V30][2];	/* 自动备份时间段*/				
	BYTE  byRes2[36];						/* 保留字节*/
}NET_DVR_MB_AUTOBACKUPPARA, *LPNET_DVR_MB_AUTOBACKUPPARA;


typedef struct tagNET_DVR_MB_GPSPARA
{
	DWORD dwSize;
	BYTE  byEnableGPS;	/*是否启用GPS */
	BYTE  byGpsInterface;/*gps接收接口0-rs232, 1-rs485, 2-frontpanel, 3-lcd */
	BYTE  bySpeedUnit;  /*速度单位，0：公里/小时，1 ：英里/小时*/
	BYTE  byEnableRetrieve; /* 盲区补发(1启用，0不启用) */
	int	  iAdjustTime;/*时区*/
	BYTE  byEnableAdjustTime;/*是否启用GPS校时， 1-启用, 0-不启动*/
	BYTE  byRes1[5];
	WORD  wGpsUploadInterval;	/* GPS上传间隔, 秒*/
	BYTE  byGpsOsdChannel[MAX_CHANNUM_V30];/*OSD 显示，每字节代表一路 */
	DWORD dwSpeedLimit;	/* 限速报警*/
	NET_DVR_HANDLEEXCEPTION_V30  struGpsAlarm; 
	BYTE  byRes2[36];
}NET_DVR_MB_GPSPARA, *LPNET_DVR_MB_GPSPARA;
/*注：1）、当单位为公里/小时 时范围为（0 ,965）；当采用英里/小时做单位的时候 ，最大速度范围为：0-600*/

#define 		SENSOR_IN_NUMBER  		8
typedef struct tagNET_DVR_MB_SENSORINPARA
{
	DWORD dwSize;
	BYTE  byTriggerType[SENSOR_IN_NUMBER];/*行车状态相关触发的联动，只用后4个，分别代表刹车、左转、右转、倒车，0-高电平，1-低电平*/
	BYTE  byTriggerChannel [SENSOR_IN_NUMBER];
	BYTE  byOsdDisplay [MAX_CHANNUM_V30];/*OSD显示,每位代表一路*/
	BYTE  byRes[32];
}NET_DVR_MB_SENSORINPARA, *LPNET_DVR_MB_SENSORINPARA;


typedef struct tagNET_DVR_ACCELERATIONCFG
{
	DWORD	dwMaxXAcc;	/* X轴加速度报警值 ，该取值为实际数值乘以10,最小为0*/
	DWORD	dwMaxYAcc;	/* Y轴加速度报警值 ，该取值为实际数值乘以10.最小为0*/
	DWORD	dwMaxZAcc;	/* Z轴加速度报警值， 该取值为实际数值乘以10,最小为0*/
	BYTE	byRes[4];
}NET_DVR_ACCELERATIONCFG,*LPNET_DVR_ACCERATIONCFG;

typedef struct tagNET_DVR_GSENSORPARA
{
    DWORD dwSize;
	NET_DVR_ACCELERATIONCFG struAccelerationCfg;
	BYTE  byModuleSelect;/*模块选择：0内置/1外置*/
    BYTE  byRes1[3];
	NET_DVR_HANDLEEXCEPTION_V30 struHandleException;
	BYTE  byRes2[24];	/*保留扩展字节*/
}NET_DVR_GSENSORPARA, *LPNET_DVR_GSENSORPARA;

typedef struct tagNET_DVR_MB_DOWNLOADSVRPARA
{
    DWORD dwSize;
	NET_DVR_IPADDR	struDownloadSvrIp;		/* 自动下载服务器地址 */
    BYTE  byRes[64];
}NET_DVR_MB_DOWNLOADSVRPARA,*LPNET_DVR_MB_DOWNLOADSVRPARA;

/* 车牌识别的相关参数*/
typedef struct tagNET_DVR_PLATERECOG_PARA
{
	DWORD dwSize;
	BYTE byPrMode; /* 车牌识别的模式, 静态图像0/动态视频1 */
	BYTE byPrScene; /* 车牌识别的场景, 低速场景0/高速场景1 */
	BYTE byPrDetRect; /* 0:全屏幕;1:中心区域 */
	BYTE byPrPicQuality; /* 车牌识别返回的图片质量, 0:最低/3:最高 */	
	BYTE byPrPicMode;/*车牌识别返回的图片分辨率: JPEG_MODE_D1, JPEG_MODE_CIF, JPEG_MODE_QCIF */
	BYTE byPlateOsdDisplay; /* 车牌OSD是否显示 0:不显示/1:显示 */
	BYTE byPrProvCharIndex;	/* 车牌识别省份首汉字对应的索引 */
	BYTE byPrProvCharIndex1;	/* 车牌识别常见首汉字1对应的索引 */
	BYTE byPrProvCharIndex2;	/* 车牌识别常见首汉字2对应的索引 */
	BYTE byRes[7];
}NET_DVR_PLATERECOG_PARA, *LPNET_DVR_PLATERECOG_PARA;


/* 动态取证系统,限速设置参数的结构*/
typedef struct tagNET_DVR_SPEEDLMT_PARA
{
	BYTE	bStartMaxSpeedLimit;		/* 开启高速限制 */
	BYTE	bStartMinSpeedLimit;		/* 开启低速限制 */
	BYTE	byRes[6];
	DWORD	dwMaxSpeedLimit;				/* 最高限速 */
	DWORD	dwMinSpeedLimit;				/* 最低限速 */
}NET_DVR_SPEEDLMT_PARA, *LPNET_DVR_SPEEDLMT_PARA;

/* 动态取证系统,车牌比对参数的结构*/
typedef struct tagNET_DVR_PLATECHECK_PARA
{
	BYTE	bAlarmWhenChecked;			/* 稽查成功是否报警 */
	BYTE	bInformWhenChecked;			/* 稽查成功是否对话框提示 */
	BYTE	byRes[6];
	NET_DVR_IPADDR struBlackFtpServer;			/* 黑名单FTP服务器地址 */
}NET_DVR_PLATECHECK_PARA, *LPNET_DVR_PLATECHECK_PARA;

typedef struct tagNET_DVR_ENFORCESYS_PARA
{
	DWORD dwSize;
	NET_DVR_SPEEDLMT_PARA	struSpeedLmtPara;	/*限速设置*/
	NET_DVR_PLATECHECK_PARA struPlateCheckPara;	/*车牌比对*/
	BYTE	bySelPeccType;	/*是否选择违章类型*/
	BYTE	byEnfOptHabit; /*取证操作习惯, 0:长按取证;1:短按两次取证*/
	/*预览帧率调节模式分三种：
	A 关闭 adjPrevFpsMode=0
	以固定高帧率(25FPS)预览
	B 标准 adjPrevFpsMode=1
	以固定低帧率(6FPS)预览
	C 自适应 adjPrevFpsMode=2
	根据GPS速度信息动态调整预览帧率，
	3秒无有效GPS的情况下，以固定高帧率预览*/
	BYTE	byAdjPrevFpsMode;		
	BYTE	byRes1;
	NET_DVR_IPADDR  struUploadServerIp; //上传服务器地址
	WORD	wUploadServerPort;
	BYTE	byRes2[18];
}NET_DVR_ENFORCESYS_PARA, *LPNET_DVR_ENFORCESYS_PARA;

typedef struct tagNET_DVR_PUSHMODEPARAM
{
    //直连模式下UDP预览模式，1-同端口多路流，2-一端口一路流
    BYTE byUdpPreviewMode; 
    //语音对讲工作模式，0-语音对讲，1-语音转发（SDK不进行语音的采集和播放）
    BYTE byVoiceWorkMode; 
    BYTE byRes[18];	
}NET_DVR_PUSHMODEPARAM, *LPNET_DVR_PUSHMODEPARAM;

#define MAX_ALARMHOST_ALARMIN_NUM	        512//网络报警主机最大报警输入口数
#define MAX_ALARMHOST_ALARMOUT_NUM	        512//网络报警主机最大报警输出口数

#define ALARMHOST_MAX_AUDIOOUT_NUM		    32//网络报警主机最大语音输出数
#define ALARMHOST_MAX_ELECTROLOCK_NUM		32//网络报警主机最大电锁数
#define ALARMHOST_MAX_MOBILEGATE_NUM		32//网络报警主机最大移动门数
#define ALARMHOST_MAX_SIREN_NUM             8 // 最大警号数目
#define MAX_ALARMHOST_SUBSYSTEM             32//报警主机最大子系统数

typedef enum tagSENSOR_TYPE
{
	SENSOR_TYPE_NONE = 0,       //无
	SENSOR_TYPE_TEMPERATURE = 1, // 温度
	SENSOR_TYPE_HUMIDITY ,      // 湿度
	SENSOR_TYPE_WINDSPEED,      // 风速
	SENSOR_TYPE_GAS,            //气体
	SENSOR_AC_VOLTAGE,				// 交流电压
	SENSOR_AC_CURRENT,				// 交流电流
	SENSOR_DC_VOLTAGE,				// 直流电压
	SENSOR_DC_CURRENT,				// 直流电流
	SENSOR_WATER_PRESSURE,			// 水压
	SENSOR_PRESSURE_TRANSMITTER,	// 压力变送器
	SENSOR_FLOW_TRANSMITTER,		// 流量变送器
	SENSOR_WATER_LEAKAGE,			// 漏水传感器
	SENSOR_INTERGRATED_TEMPERATURE_DETECTOR,	//一体化温变
	SENSOR_ISOLATION_TEMPERATURE_DETECTOR,		//隔离式温变
	SENSOR_RESIDUAL_CHLORINE,					//在线余氯仪
	SENSOR_TYPE_UNKNOW = 255    	// 未定义
}SENSOR_TYPE;

typedef struct tagNET_DVR_SENSOR_INFO
{
	DWORD  dwSize;                 // 结构体大小
	BYTE    byName[NAME_LEN];    // 传感器名称
	BYTE    byEnable;               // 是否启用 
	BYTE    byValid;                // 是否有效 传感器正常不正常(该参数只能获取不能个配置)
	BYTE    byType;                 // 模拟量类型 参照SENSOR_TYPE
	BYTE	byAlarmMode;//报警模式，五种，15-HHHH、14-HHHL、12-HHLL、8HLLL、0-LLLL，即：1111（上上上上），1110（上上上下），1100（上上下下），1000(上下下下)，0000(下下下下)
	float   fMeasureHigh;           // 量程上限
	float   fMeasureLow;            // 量程下限
	float	fAlarm1;           //报警限1,报警限1-4 依次增大
	float	fAlarm2;           //报警限2
	float	fAlarm3;           //报警限3
	float	fAlarm4;           //报警限4
	DWORD   dwOsdCfg;          //模拟量字符叠加，按位表示0-15对应视频通道1-16
	float	fSensitive;			// 灵敏度表示当实时值的变化超过灵敏度的范围时，则表示实时值发生了变化，否则认为没有发生变化。如：灵敏度为0.1，则表示前后检测的两个值之差大于0.1时，则认为数据发生变化大于0.1，需要上传。如果为1，则表示变化超过1时上报。
	BYTE	bySensorStandard;	//传感器规格，0- 0~20mA，1, 0~5V
	BYTE    byRes3[115];            // 保留字节
}NET_DVR_SENSOR_INFO, *LPNET_DVR_SENSOR_INFO;

typedef struct tagNET_DVR_SIREN_PARAM
{
	DWORD   dwSize;					// 结构大小
    BYTE    byName[NAME_LEN];		// 名称
	WORD    wDelay;					// 输出延迟 单位为秒, 范围 0~5599s 0表示一直有输出
	BYTE	byRes1[2];
	DWORD   dwOverallEventJointSirenOn;		//全局事件联动警号输出开启，事件类型按位表示，bit0-主机防拆, bit1-全局键盘紧急报警
	DWORD	dwSubsystemEventJointSirenOn[MAX_ALARMHOST_SUBSYSTEM/*32*/];//子系统事件联动警号输出开启。数组下标表示子系统号，每一个元素按位表示事件类型，bit0-紧急报警
	BYTE    byRes2[448];  // 保留字节　　
}NET_DVR_SIREN_PARAM, *LPNET_DVR_SIREN_PARAM;

typedef struct tagNET_DVR_AIR_CONDITION_PARAM
{
	DWORD	dwSize;		// 结构体大小
	BYTE	byEnable;	// 0--关机 1--开机
	BYTE	byMode;		// 空调模式
	BYTE	byTemperature;	// 温度，具体值表示 通常为16-30度
	BYTE	byRes[9];		// 保留字节
}NET_DVR_AIR_CONDITION_PARAM, *LPNET_DVR_AIR_CONDITION_PARAM;

typedef enum tagDETECTOR_TYPE
{
    PANIC_BUTTON = 0,               // 紧急开关
    MAGNETIC_CONTACT,               // 门磁开关
    SMOKE_DETECTOR,                 // 烟感探测器
    ACTIVE_INFRARED_DETECTOR,       // 主动红外探测器
    PASSIVE_INFRARED_DETECTOR,      // 被动红外探测器
    GLASS_BREAK_DETECTOR,           // 玻璃破碎探测器
    VIBRATION_DETECTOR,             // 震动探测器
    DUAL_TECHNOLOGY_PIR_DETECTOR,   // 双鉴移动探测器
    TRIPLE_TECHNOLOGY_PIR_DETECTOR, // 三技术探测器
    HUMIDITY_DETECTOR,              // 湿度探测器
    TEMPERATURE_DETECTOR,           // 温感探测器
    COMBUSTIBLE_GAS_DETECTOR,        // 可燃气体探测器
	DYNAMIC_SWITCH,					//随动开关
	CONTROL_SWITCH,					//控制开关
    OTHER_DETECTOR = 0xffff          // 其他探测器   
}DETECTOR_TYPE;

typedef struct tagNET_DVR_ALARMIN_PARAM
{
	DWORD   dwSize;
	BYTE    byName[NAME_LEN];
	WORD    wDetectorType; // DETECTOR_TYPE
	BYTE    byType;     //防区类型，0:即时防区,1-24小时防区,2-延时防区 ,3-内部防区，4-钥匙防区 5-火警防区 6-周界防区 7-24小时无声防区 0xff-无
	BYTE    byUploadAlarmRecoveryReport;    //是否上传防区报警恢复报告，0-不上传，1-上传        
	DWORD	dwParam;    // 防区参数  延时防区延时多长时间, 动环报警主机和自助行报警主机的延时时间通过这个参数来设置 , 具体用哪种设置方式通过能力集中的bySupportAlarmInDelay字段来区别
    NET_DVR_SCHEDTIME struAlarmTime[MAX_DAYS][MAX_TIMESEGMENT];/*布防时间时间段*/
	BYTE    byAssociateAlarmOut[MAX_ALARMHOST_ALARMOUT_NUM];  // 报警输入关联报警输出
    BYTE	byAssociateSirenOut[8];		//  警号输出 数组0 表示警号1 值为1表示输出 0 表示不输出
    BYTE	bySensitivityParam;//防区灵敏度参数, 0-10ms、1-250ms、2-500ms、3-750ms
    BYTE	byArrayBypass;//是否加入旁路组,0-不支持组旁路,1-支持组旁路
	BYTE	byJointSubSystem; //防区所属的子系统号，该参数只能获取  
	BYTE    byModuleStatus;	//模块状态 1-在线 2-离线
	WORD	wModuleAddress;	//模块地址，扩展模块从0~255，0xFFFF表示无效
	BYTE	byModuleChan;	//模块通道号，从1开始，最大值根据模块类型来决定，0xFF表示无效
	BYTE	byModuleType;	//模块类型，1-本地防区，2-单防区，3-双防区，4-8防区，5-8路模拟量防区, 6-单防区触发器
	WORD	wZoneIndex;		//防区号，该参数只能获取	  
    BYTE    byRes2[42];      // 保留字节
}NET_DVR_ALARMIN_PARAM, *LPNET_DVR_ALARMIN_PARAM;

typedef struct tagNET_DVR_ALARMOUT_PARAM
{
	DWORD   dwSize;             // 结构体大小
	BYTE    byName[NAME_LEN];   // 名称
	WORD    wDelay;             // 输出延迟 单位s, 范围：0~3599s 0 表示一直有输出
	WORD	wTriggerIndex;		//触发器号，该参数只能获取
	BYTE    byAssociateAlarmIn[MAX_ALARMHOST_ALARMIN_NUM];   //表示警号跟随的报警输入通道 （多个报警输入同时触发一个警号输出）数组下标0表示报警输入1，依次类推 0-不跟随 1-跟随
	BYTE	byModuleType;	//外接触发器类型，1-本地触发器， 2-4路触发器，3-8路触发器 4-单防区触发器，5-32路触发器
	BYTE	byModuleStatus;	//外接触发器状态 1-在线 2-离线
	WORD	wModuleAddress;	//外接触发器地址，扩展模块从0~255，0xFFFF表示无效
	BYTE	byModuleChan;	//外接触发器通道号，从1开始，最大值根据模块类型来决定，0xFF表示无效
	BYTE   	byRes2[55]; 			//保留字节
}NET_DVR_ALARMOUT_PARAM, *LPNET_DVR_ALARMOUT_PARAM;

typedef struct tagNET_DVR_ALARMIN_SETUP
{
    BYTE byAssiciateAlarmIn[MAX_ALARMHOST_ALARMIN_NUM];//报警输入通道 数组下标0对应报警输入口1，依次类推
    BYTE byRes[100];//保留字节
}NET_DVR_ALARMIN_SETUP, *LPNET_DVR_ALARMIN_SETUP;

typedef struct tagNET_DVR_ALARMHOST_MAIN_STATUS
{
	DWORD  dwSize; 
	BYTE   bySetupAlarmStatus[MAX_ALARMHOST_ALARMIN_NUM];//报警输入口布防状态，(最大支持512个报警输入口查询)，0-对应报警输入口处于撤防状态，1-对应报警输入口处于布防状态
	BYTE   byAlarmInStatus[MAX_ALARMHOST_ALARMIN_NUM];//报警输入口报警状态，(最大支持512个报警输入口查询)，0-对应报警输入口当前无报警，1-对应报警输入口当前有报警
	BYTE   byAlarmOutStatus[MAX_ALARMHOST_ALARMOUT_NUM];//报警输出口状态，(最大支持512个报警输出口查询)，0-对应报警输出口无报警，1-对应报警输出口有报警
    BYTE   byBypassStatus[MAX_ALARMHOST_ALARMIN_NUM];  // 旁路状态 数组下标表示0对应报警输入口1 0-表示报警输入口没有旁路 1-表示报警输入口旁路
	BYTE   bySubSystemGuardStatus[MAX_ALARMHOST_SUBSYSTEM]; //子系统布防状态,0-对应子系统处于撤防状态，1-对应子系统处于布防状态
    BYTE   byAlarmInFaultStatus[MAX_ALARMHOST_ALARMIN_NUM];//报警输入口故障状态，0-对应报警输入口处于正常状态，1-对应报警输入口处于故障状态
    BYTE   byRes[56];      //  保留字节
}NET_DVR_ALARMHOST_MAIN_STATUS, *LPNET_DVR_ALARMHOST_MAIN_STATUS;

typedef struct tagNET_DVR_ALARMHOST_MAIN_STATUS_V40
{
	DWORD  dwSize; 
	BYTE   bySetupAlarmStatus[MAX_ALARMHOST_ALARMIN_NUM];//防区布防状态，(最大支持512个防区查询)，0-对应防区处于撤防状态，1-对应防区处于布防状态
	BYTE   byAlarmInStatus[MAX_ALARMHOST_ALARMIN_NUM];//防区报警状态，(最大支持512个防区查询)，0-对应防区当前无报警，1-对应防区当前有报警
	BYTE   byAlarmOutStatus[MAX_ALARMHOST_ALARMOUT_NUM];//触发器状态，(最大支持512个触发器查询)，0-对应触发器无报警，1-对应触发器有报警
	BYTE   byBypassStatus[MAX_ALARMHOST_ALARMIN_NUM];  // 旁路状态 数组下标表示0对应防区1 0-表示防区没有旁路 1-表示防区旁路
	BYTE   bySubSystemGuardStatus[MAX_ALARMHOST_SUBSYSTEM/*32*/]; //子系统布防状态,0-对应子系统处于撤防状态，1-对应子系统处于布防状态
	BYTE   byAlarmInFaultStatus[MAX_ALARMHOST_ALARMIN_NUM];//防区故障状态，0-对应防区处于正常状态，1-对应防区处于故障状态
	BYTE   byAlarmInMemoryStatus[MAX_ALARMHOST_ALARMIN_NUM];//防区报警记忆状态， 0-对应防区当前无报警，1-对应防区当前有报警
	BYTE   byRes[1024];      //  保留字节
}NET_DVR_ALARMHOST_MAIN_STATUS_V40, *LPNET_DVR_ALARMHOST_MAIN_STATUS_V40;

typedef struct tagNET_DVR_ALARMHOST_OTHER_STATUS
{
	DWORD  dwSize;
    BYTE   bySirenStatus[ALARMHOST_MAX_SIREN_NUM];    // 警号输出状态 0-警号处于无报警状态，1-警号处于有报警状态
    BYTE   byRes[92];             // 保留字节
}NET_DVR_ALARMHOST_OTHER_STATUS, *LPNET_DVR_ALARMHOST_OTHER_STATUS;

//使能状态配置
typedef struct tagNET_DVR_ALARMHOST_ENABLECFG
{
	DWORD dwSize;
	BYTE  byAudioOutEnable[ALARMHOST_MAX_AUDIOOUT_NUM];//语音输出使能，0-禁能，1-使能
	BYTE  byElectroLockEnable[ALARMHOST_MAX_ELECTROLOCK_NUM];//电锁使能，0-禁能，1-使能
	BYTE  byMobileGateEnable[ALARMHOST_MAX_MOBILEGATE_NUM];//移动门使能，0-禁能，1-使能
	BYTE  bySirenEnable[ALARMHOST_MAX_SIREN_NUM];//警号使能， 0-禁能，1-使能
	BYTE  bySerialPurpose;//串口用途，0-用于级联报警主机，1-用于PTZ控制
	BYTE  byRes[63];	
}NET_DVR_ALARMHOST_ENABLECFG, *LPNET_DVR_ALARMHOST_ENABLECFG;

typedef struct tagNET_DVR_ALARMHOST_ABILITY
{
	DWORD   dwSize;					  // 结构体大小
	WORD    wTotalAlarmInNum;         // 报警输入口总数(防区),包括级联
	WORD    wLocalAlarmInNum;         // 本地报警输入口
	WORD    wExpandAlarmInNum;        // 可扩展的报警输入口
	WORD    wTotalAlarmOutNum;        // 报警输出口总数 （设备支持的总数）
	WORD    wLocalAlarmOutNum;        // 本地报警输出口个数
	WORD    wExpandAlarmOutNum;       // 可扩展的报警输出口
	WORD    wTotalRs485Num;           // 报警输出口总数 （设备支持的总数）
	WORD    wLocalRs485Num;           // 本地485口数
	WORD    wExpandRs485Num;          // 可扩展的485口数
	WORD	wFullDuplexRs485Num;    // 全双工的485口数
	WORD    wTotalSensorNum;          // 模拟量最大个数 (设备支持的总数)
	WORD	wLocalSensorNum;		// 本地模拟量个数
	WORD    wExpandSensorNum;         // 可扩展的模拟量个数
	WORD    wAudioOutNum;			    //语音输出个数
	WORD    wGatewayNum;			//门禁个数
	WORD    wElectroLockNum;		    //电锁个数
	WORD    wSirenNum;     			// 主机警号数目
	WORD    wSubSystemNum;			// 可划分子系统数目
    WORD    wNetUserNum;            // 网络用户数
    WORD    wKeyboardNum;           // 键盘数
    WORD    wOperatorUserNum;           // 操作用户数
	BYTE    bySupportDetector;//是否支持常开、常闭探测器，1-支持，0-不支持
    BYTE    bySupportSensitivity;//是否支持防区灵敏度，1-支持，0-不支持
    BYTE    bySupportArrayBypass;//是否支持组旁路，1-支持，0-不支持
    BYTE    bySupportAlarmInDelay;//是否支持防区延迟,1-支持，0-不支持
	//如果bySupportAlarmInDelay为1时，表示客户端应该使用NET_DVR_ALARMIN_PARAM 中的dwParam来设置延时时间，动环报警主机和自助行报警主机使用这种配置延时方式;
	//如果bySupportAlarmInDelay为0时，表示通过NET_DVR_ALARMSUBSYSTEMPARAM 中的wEnterDelay 、wExitDelay 来设置
    BYTE    bySupportAlarmInType[16];//支持的防区类型,数组0:即时防区,1-24小时防区,2-延时防区 ,3-内部防区，4-钥匙防区 5-火警防区 6-周界防区 7-24小时无声防区 15-无
	BYTE	byTelNum;		//支持电话个数
	BYTE	byCenterGroupNum;	//中心组个数
	BYTE	byGPRSNum;		//GPRS中心数，最多4个
	BYTE	byNetNum;		//网络中心数，最多4个
	BYTE	byAudioNum;		//音频个数
	BYTE	by3GNum;		//3G模块个数
	BYTE	byAnalogVideoChanNum;		//模拟视频通道个数
	BYTE	byDigitalVideoChanNum;		//数字视频通道个数
	BYTE	bySubSystemArmType;		//子系统布防类型，0-表示不支持，1-表示支持。bit0-普通布防（注：网络小主机只支持普通布防，在能力集中加这个字段的时候网络小主机已经发布，所以网络小主机中该字段为0，所以用0表示支持，1表示不支持。对外接口中SDK内部会做兼容），bit1-即时布防，bit2-留守布防。	
	BYTE	byPublicSubSystemNum;	//公共子系统个数
	DWORD	dwSupport1;	//按位表示，结果非0表示支持，0表示不支持
	// bit0: 	是否支持子系统内配置警号输出时间，如果支持则警号输出时间在每个子系统内配置，如果不支持，警号时间在警号参数配置里面设置
	// bit1:	是否支持事件触发报警输出开启
	// bit2:	是否支持事件触发报警输出关闭
	// bit3:	是否支持子系统使能
	// bit4;	是否支持防区布防
	// bit5;	是否支持子系统自动布撤防
	// bit6:	是否支持具体故障关联声音输出
	// bit7:	是否支持故障状态查询
	// bit8:	是否支持子系统扩展配置
	// bit9:    是否支持钥匙防区操作子系统
	// bit10:   是否支持"键盘提示成功发送报告"配置
	// bit11:   是否支持导入导出参数配置
    // bit12:   是否支持LED屏幕参数配置
	// bit13: 是否支持故障关联本地故障灯输出
	DWORD	dwSubSystemEvent;		//子系统事件，按位表示，0表示不支持，非0表示支持,bit0-进入延时，bit1-退出延时，bit2-布防，bit3-撤防，bit4-报警，bit5-消除报警记忆
	DWORD	dwOverallEvent;			//全局事件，按位表示，0表示不支持，非0表示支持，bit0-交流电掉电，bit1-电池电压低，bit2-电话线掉线，bit3-有线网络异常，bit4-无线网络异常
	DWORD	dwFaultType;			//设备支持的故障类型，bit0-交流电断电，bit1-蓄电池欠压，bit2-主机防拆开，bit3-电话线掉线，bit4-主键盘掉线，bit5-网络故障，bit6-无线异常，bit7-扩展总线异常，bit8-硬盘异常	
	BYTE	byPublicSubsystemAssociateSubsystemNum;	//公共子系统可关联的子系统个数
	BYTE	byOverallKeyboard;	//全局键盘个数
    WORD    wSafetyCabinSupport; //防护舱控制器能力，按位表示，结果非0表示支持，0表示不支持	
    //bit0: 是否支持防护舱控制器工作模式配置
    //bit1: 是否支持人信号传感器类型配置
    //bit2: 是否支持幕帘传感器参数配置（探测延迟时间、人状态变化响应时间）
    //bit3: 是否支持红外对射传感器参数配置（滤波）
	//bit4: 是否支持防护舱使用超时时间配置
	BYTE	by485SlotNum;		//485虚拟槽位号
	BYTE	byRes[121];			//  保留字节
}NET_DVR_ALARMHOST_ABILITY, *LPNET_DVR_ALARMHOST_ABILITY;

typedef struct tagNET_DVR_ALARM_RS485CFG
{
	DWORD   dwSize;                 // 结构体大小
	BYTE    sDeviceName[NAME_LEN];  // 前端设备名称 
	WORD    wDeviceType;            // 前端设备类型ALARM_FRONT_DEVICE _TYPE
	WORD    wDeviceProtocol;        // 前端设备协议 通过获取协议列表获取	
	DWORD   dwBaudRate;             //波特率(bps)，0-50，1-75，2-110，3-150，4-300，5-600，6-1200，7-2400，8-4800，9-9600，10-19200，11-38400，12-57600，13-76800，14-115.2k 
	BYTE    byDataBit;              // 数据有几位：0-5位，1-6位，2-7位，3-8位 
	BYTE    byStopBit;              // 停止位：0-1位，1-2位 
	BYTE    byParity;               //是否校验：0-无校验，1-奇校验，2-偶校验 
	BYTE    byFlowcontrol;           // 是否流控：0-无，1-软流控,2-硬流控 
	BYTE	byDuplex;				// 0 - 半双工1- 全双工  只有通道1可以是全双工其他都只能是半双工
    BYTE    byWorkMode;				// 工作模式 0-控制台 1-透明通道
    BYTE    byRes[38];              // 保留字节
}NET_DVR_ALARM_RS485CFG, *LPNET_DVR_ALARM_RS485CFG;

#define MAX_DEVICE_PROTO_NUM       256
#define MAX_DEVICE_TYPE_NUM			256

// 485前端设备支持协议列表
typedef struct tagNET_DVR_DEVICE_PROTO_LIST
{
    DWORD   dwSize;             // 结构体大小
    DWORD   dwProtoNum;         // 协议个数
    NET_DVR_PROTO_TYPE struProtoType[MAX_DEVICE_PROTO_NUM];  // 协议类型
    BYTE    byRes[12];          // 保留字节
}NET_DVR_DEVICE_PROTO_LIST, *LPNET_DVR_DEVICE_PROTO_LIST;

typedef struct tagNET_DVR_DEVICE_TYPE
{
	DWORD	dwType;
	BYTE	byDescribe[DESC_LEN];
}NET_DVR_DEVICE_TYPE, *LPNET_DVR_DEVICE_TYPE;

typedef struct tagNET_DVR_DEVICE_TYPE_LIST
{
	DWORD	dwSize;				// 结构体大小
	DWORD	dwTypeNum;			// 类型个数
	NET_DVR_DEVICE_TYPE struDeviceType[MAX_DEVICE_TYPE_NUM];
	BYTE	byRes[12];
}NET_DVR_DEVICE_TYPE_LIST, *LPNET_DVR_DEVICE_TYPE_LIST;

#define	MAX_ALARMHOST_VIDEO_CHAN	64
typedef struct tagNET_DVR_ALARM_DEVICE_USER
{
	DWORD  dwSize;                 // 结构体大小
	BYTE   sUserName[NAME_LEN];    // 用户名
	BYTE   sPassword[PASSWD_LEN];	// 密码
    NET_DVR_IPADDR	struUserIP;					/* 用户IP地址(为0时表示允许任何地址) */
    BYTE   byMACAddr[MACADDR_LEN];			/* 物理地址 */
    BYTE   byUserType; // 0-普通用户 1-管理员用户
	BYTE   byAlarmOnRight;         // 布防权限
	BYTE   byAlarmOffRight;        // 撤防权限
	BYTE   byBypassRight;          // 旁路权限
	BYTE   byOtherRight[MAX_RIGHT];  // 其他权限
    // 0 -- 日志权限
    // 1 -- 重启关机
    // 2 -- 参数设置权限
    // 3 --	参数获取权限
    // 4 -- 恢复默认参数权限
    // 5 -- 警号输出权限
    // 6 -- PTZ 控制权限
	// 7 -- 远程升级权限
	// 8 -- 远程预览
	// 9 -- 远程手动录像
	// 10 -- 远程回放
	BYTE	byNetPreviewRight[MAX_ALARMHOST_VIDEO_CHAN/8];	// 远程可以预览的通道，按位表示各通道（bit0-channel 1），1-有权限，0-无权限
	BYTE	byNetRecordRight[MAX_ALARMHOST_VIDEO_CHAN/8];	// 远程可以录像的通道，按位表示各通道（bit0-channel 1），1-有权限，0-无权限
	BYTE	byNetPlaybackRight[MAX_ALARMHOST_VIDEO_CHAN/8]; // 远程可以回放的通道，按位表示各通道（bit0-channel 1），1-有权限，0-无权限
	BYTE	byNetPTZRight[MAX_ALARMHOST_VIDEO_CHAN/8];		// 远程可以PTZ的通道，按位表示各通道（bit0-channel 1），1-有权限，0-无权限
	//BYTE	byPriority;										// 优先级，0xff-无，0--低，1--中，2--高
	//无（表示不支持优先级的设置）
	//低（默认权限：包括远程回放，远程查看日志和状态，远程关机/重启）
	//中（包括远程控制云台，远程手动录像，远程回放，语音对讲和远程预览，本地备份，本地/远程关机/重启）
	//高（管理员）
	BYTE	byRes2[168];              // 保留字节
}NET_DVR_ALARM_DEVICE_USER, *LPNET_DVR_ALARM_DEVICE_USER;

typedef struct tagNET_DVR_KEYBOARD_USER
{
	DWORD 	dwSize; 	// 结构体大小
	DWORD	dwID;		// 键盘用户ID
	BYTE	byDefanceArea[MAX_ALARMHOST_ALARMIN_NUM]; //防区权限  按数组下标表示 最大支持512个防区 0 - 无权限 1- 有权限
	BYTE	byRes[560];		// 保留字节
}NET_DVR_KEYBOARD_USER, *LPNET_DVR_KEYBOARD_USER;

typedef struct tagNET_DVR_OPERATE_USER
{
	DWORD	 dwSize;		// 结构体大小
	BYTE    sUserName[NAME_LEN];    // 用户名
    BYTE    sPassword[PASSWD_LEN];  // 密码
    BYTE   bySubSystemPermission;/*0-安装员权限 操作员权限（所有子系统）如下： 1-单布防，无布防报告，不能旁路 2-单撤防，无撤防报告，不能旁路 3-布撤防，无布撤防报告，不能旁路 
	4-单布防，有布//防报告，不能旁路 5-单撤防，有撤防报告，不能旁路 6-布撤防，有布撤防报告，不能旁路  7-单布防，无布撤防报告，允许旁路 
	8-单撤防，无布撤防报告，允许旁路 9-布撤防，无布撤防报告，允许旁路 10-单布防，有布防报告，允许旁路 11-单撤防，有撤防报告，允许旁路 1
	2-布撤防，有布撤防报告，允许旁路*/
    BYTE    byRes[63];             //  保留字节
}NET_DVR_OPERATE_USER, *LPNET_DVR_OPERATE_USER;

typedef struct tagNET_DVR_GATEWAY_CFG
{
    DWORD	dwSize;		// 结构体大小
    BYTE	byName[NAME_LEN];	//  门禁名称	
    BYTE	byEnable;	// 是否启用
    BYTE    byLocalEnable;  //  本地是否启用
    WORD    wDelayTime;	// 开启延时时间	单位为秒0-65535 0为一直开启
	BYTE	byLockWorkMode;//电锁工作模式，0-通电启动，1-断电启动
    BYTE	byRes[31];	// 保留字节
}NET_DVR_GATEWAY_CFG, *LPNET_DVR_GATEWAY_CFG;

typedef struct tagNET_DVR_SENSOR_ALARM
{
    DWORD   dwSize;		        // 结构体大小
    DWORD   dwAbsTime;	        // 绝对时标信息  OSD显示信息
    BYTE    byName[NAME_LEN]; 	// sensor 名称
    BYTE    bySensorChannel;    // 模拟量通道
    BYTE    byType;             // 模拟量类型
    BYTE	byAlarmType;	    // 1-上4、2-上3、3-上2、4-上1、5-下1、6-下2、7-下3、8-下4 和当前模式有关
                                // 例如当为1000时,有上1下1，2，3报警四种报警
    BYTE	byAlarmMode;        //报警模式，五种，-HHHH、-HHHL、-HHLL、HLLL、-LLLL， 作为平台报警程度判断功能,即：1111（上上上上），1110（上上上下），1100（上上下下），1000(上下下下)，0000(下下下下) 
    float	fValue;		        // 但前模拟量的值
    BYTE	byRes2[32];		    // 保留字节
}NET_DVR_SENSOR_ALARM, *LPNET_DVR_SENSOR_ALARM;

typedef struct 
{
    /*预留，目前报警主机的报警没有类型(布防网络序，监听主机序)*/
    DWORD  dwAlarmType;             
    /*数组0对应第1个输入端口*/
    BYTE   byAlarmInputNumber[MAX_ALARMHOST_ALARMIN_NUM];
    BYTE	byRes[160];
}NET_DVR_ALARMHOST_ALARMINFO,*LPNET_DVR_ALARMHOST_ALARMINFO;
// 开关量报警上传
typedef struct tagNET_DVR_SWITCH_ALARM
{
    DWORD dwSize;
    BYTE   byName[NAME_LEN]; 	// switch 名称
    WORD  wSwitchChannel;     // 开关量通道, 0-255
    BYTE	byAlarmType;		// 报警类型 0--正常，1--短路，2--断路,3-异常 
    BYTE 	byRes[41];			// 保留字节
}NET_DVR_SWITCH_ALARM, *LPNET_DVR_SWITCH_ALARM;

typedef union tagNET_DVR_ALARMHOST_EXCEPTION_PARAM
{
    DWORD   dwUnionSize[20];        // 联合体大小    
}NET_DVR_ALARMHOST_EXCEPTION_PARAM, *LPNET_DVR_ALARMHOST_EXCEPTION_PARAM;

typedef struct tagNET_DVR_ALARMHOST_EXCEPTION_ALARM
{
    DWORD   dwSize;             // 结构体大小
    // 异常参数  1-设备防拆报警 2-设备防拆后后恢复正常 3-主电源掉电报警 4-主电源掉电后恢复正常 5-内部通信故障报警 
    // 6-内部通信故障后恢复正常  7-电话线断线 8-电话线断线恢复 9-自检失败报警  10-自检失败后恢复正常    
    // 11蓄电池欠压  12蓄电池电压恢复正常，13-蓄电池故障；14-MBUS模块掉线；15-MBUS模块掉线恢复；16-键盘掉线；
    //17-键盘掉线恢复；18-设备被移动；19-设备被移动复位  20-485外设线路断报警  21-485外设线路断后恢复正常
    DWORD   dwExceptionType;    
    BYTE   byRes[36];          // 保留
}NET_DVR_ALARMHOST_EXCEPTION_ALARM, *LPNET_DVR_ALARMHOST_EXCEPTION_ALARM;

//自助行拨号参数配置及启用方式配置
#define MAX_CENTERNUM			4		//G1,G2 G3 G4或者N1，N2，N3，N4或者T1，T2，T3，T4
typedef struct tagNET_DVR_PHONECENTERDIALCFG
{
    BYTE sCenterName[NAME_LEN];
    BYTE byPhoneNum[MAX_PHONE_NUM/*32*/];  //中心号码  
    BYTE byRepeatCall;          //重复拨号次数，1~15次
    BYTE byPstnProtocol;        //通信协议，0-CID；
    BYTE byDialDelay;           //拨号延时，最大150s, 0-150
    BYTE byPstnTransMode;       //传输方式，0-DTMF 5/S，1-DTMF 10/S；
    BYTE byRes1[6];
    BYTE byReceiverId[6];     	//接收机识别账号；
    BYTE byRes2[32];
}NET_DVR_PHONECENTERDIALCFG, *LPNET_DVR_PHONECENTERDIALCFG;

typedef struct tagNET_DVR_ALARMHOSTDIALCFG
{
    DWORD dwSize;
    NET_DVR_PHONECENTERDIALCFG struPhoneCenterParam[MAX_CENTERNUM];//主中心参数
	WORD wReportPeriod;      //测试报告上传周期，小时，（最大值支持7天，即168小时), 范围；1-168
	WORD wFirstReportTime;	 //从设备启动到第一条测试报告上传，1~3600分钟
	BYTE  byReportValid;	//0-不启用测试报告上传 1-启用测试报告上传
    BYTE  byRes[19];
}NET_DVR_ALARMHOSTDIALCFG, *LPNET_DVR_ALARMHOSTDIALCFG;

typedef struct tagNET_DVR_ALARMHOSTDIALSETUPMODE
{
	DWORD dwSize;
	BYTE byEnableMode;//启用方式，0：不启用，1：一直启用，2:网线断启用，正常时关闭；
    BYTE byCallType; //上传中心方式，1-单中心，2-双中心，3，一报一备
    BYTE byRes1[14];
}NET_DVR_ALARMHOSTDIALSETUPMODE, *LPNET_DVR_ALARMHOSTDIALSETUPMODE;

#define  MAX_PU_CHAN_NUM    512

typedef struct tagNET_DVR_PU_CHAN_INFO
{
    NET_DVR_IPADDR  struIpAddr;     // ip地址
    WORD            wPort;          // 端口
    WORD            wChannel;       // 通道     
    BYTE            byRes[24];      // 
}NET_DVR_PU_CHAN_INFO, *LPNET_DVR_PU_CHAN_INFO;

typedef struct tagNET_DVR_PU_CHAN_LIST
{
    DWORD   dwSize;     // 结构体
    DWORD   dwNum;      // 前端通道个数
    NET_DVR_PU_CHAN_INFO struPuChanInfo[MAX_PU_CHAN_NUM];
}NET_DVR_PU_CHAN_LIST, *LPNET_DVR_PU_CHAN_LIST;

#define  MAX_ALARM_CAM_NUM	32		// 报警触发CAM最大个数

typedef struct tagNET_DVR_PTZ_CTRL
{
	BYTE    byEnable;   // 是否启用PTZ控制
	BYTE    byType;     // PTZ 控制的类型 1- 预置点 2 -巡航  3-轨迹
	BYTE    byPtzNo;    //  ptz 控制的预置点 巡航 轨迹号
	BYTE    byRes[5];    // 保留字节
}NET_DVR_PTZ_CTRL, *LPNET_DVR_PTZ_CTRL;

typedef struct tagNET_DVR_ALARM_CAM_INFO
{
	DWORD			dwCamID;      // 触发的CAM通道操作
	DWORD           dwRecordTime;   // 触发录像时间 单位为s  -1表示一直录像 0 表示不录像
	DWORD           dwMonID;      // 触发Cam到Mon号显示
	DWORD           dwResidentTime; // 轮巡停留时间单位为s  -1表示一直停留 0 表示不停留
	NET_DVR_PTZ_CTRL struPtzCtrl;    // PTZ控制信息
    BYTE			byAlarmOffMode;		// 报警切换上墙取消模式   0-立即取消，1-自动取消，2-手动取消 立即取消，报警取消时立即取消解码上墙   自动取消，报警取消时等待一定时间后取消解码上墙，我们约定是20秒  手动取消，用户通过手动的方式取消
    BYTE            byDevType;		// 当设备为智能设备时，生效表示智能报警设备取流源 1-解码卡	 2-编码卡
    BYTE            byDecChan;		// 当为解码通道为解码通道号
    BYTE            byRes[17];      // 保留字节
}NET_DVR_ALARM_CAM_INFO, *LPNET_DVR_ALARM_CAM_INFO;

typedef struct tagNET_DVR_ALARM_CAM_CFG
{
	DWORD		dwSize;			// 结构体大小
	BYTE        byEnable;       // 是否启用报警触发CAM联动 设备默认不启用
	BYTE        byRes[7];       // 保留字节
	DWORD		dwNum;			// 触发CAM联动的个数 即取数组的前几个有效处理  
	NET_DVR_ALARM_CAM_INFO struAlarmCam[MAX_ALARM_CAM_NUM];
}NET_DVR_ALARM_CAM_CFG, *LPNET_DVR_ALARM_CAM_CFG;

#define MAX_GATEWAY_NUM 		8  // 最大门禁个数
typedef struct tagNET_DVR_ALARMHOST_AUDIO_ASSOCIATE_ALARM
{
	DWORD 		dwSize;
	BYTE		byEnterDoor[8];	// 下标表示门禁号，元素数值表示关联信息，0表示不关联， 1-8表示关联的音频号
	BYTE		byExitDoor[8]; 	// 下标表示门禁号，元素数值表示关联信息，0表示不关联， 1-8表示关联的音频号
	BYTE 		byAlarmIn[MAX_ALARMHOST_ALARMIN_NUM/*512*/];  //关联报警输入，下标表示报警输入号，元素数值表示关联信息，0表示不关联， 1-8表示关联的音频号
	BYTE 		byRes[128];
}NET_DVR_ALARMHOST_AUDIO_ASSOCIATE_ALARM, *LPNET_DVR_ALARMHOST_AUDIO_ASSOCIATE_ALARM;

//数据上传下载（语音上传下载的扩展）
typedef struct tagNET_DVR_UPLOAD_PARAM
{
	DWORD 		dwSize;
	BYTE		byUploadType;	/*上传方式，1-根据文件名绝对地址读取数据文件上传， 2-从缓冲区读取数据上传*/
	BYTE		byDataType;		//数据类型：1-音频数据
	BYTE		byDataNum;		//数据编号，如：上传语音，则该参数表示语音号
	BYTE		byAudioType;		//语音格式，0-wave
	char		sFileName[260];		//数据文件的全路径
	char		*lpBuffer;			//数据缓冲区
	DWORD		dwBufferSize;		//缓冲区大小
	BYTE		byRes2[128];
}NET_DVR_UPLOAD_PARAM, *LPNET_DVR_UPLOAD_PARAM;

typedef void (CALLBACK *DATADOWNLOAD)(LONG nDownloadHandle, DWORD dwDataType, void* pBuffer, DWORD dwBufSize, void *pUser);
typedef struct tagNET_DVR_ALARMHOST_PARAM
{
	DWORD 		dwSize;
	BYTE		byDownType;		/*下载的数据保存方式，1-根据文件名绝对地址保存数据， 2-通过回调函数获取数据*/
	BYTE		byDataType;		//数据类型：1-音频数据
	BYTE		byDataNum;		//数据编号，如：下载语音，则该参数表示语音号
	BYTE		byRes1;
	char		sFileName[260];		//数据文件的全路径
	DATADOWNLOAD lpDataCallBack; //下载时的回调函数句柄
	void*		pUserData;	//用户数据，将在回调函数中传回
	BYTE		byRes2[128];
}NET_DVR_DOWNLOAD_PARAM, *LPNET_DVR_DOWNLOAD_PARAM;

typedef void (CALLBACK *DATADOWNLOAD)(LONG nDownloadHandle, DWORD dwDataType, void* pBuffer, DWORD dwBufSize, void *pUser);
typedef struct tagNET_DVR_ALARMHOST_DOWNLOAD_PARAM
{
	DWORD 		dwSize;
	BYTE		byDownType;		/*下载的数据保存方式，1-根据文件名绝对地址保存数据， 2-通过回调函数获取数据*/
	BYTE		byDataType;		//数据类型：1-音频数据
	BYTE		byDataNum;		//数据编号，如：下载语音，则该参数表示语音号
	BYTE		byRes1;
	char		sFileName[260];		//数据文件的全路径
	DATADOWNLOAD lpDataCallBack; //下载时的回调函数句柄
	void*		pUserData;	//用户数据，将在回调函数中传回
	BYTE		byRes2[128];
}NET_DVR_ALARMHOST_DOWNLOAD_PARAM, *LPNET_DVR_ALARMHOST_DOWNLOAD_PARAM;

//LED屏幕参数
typedef  struct tagNET_DVR_LED_SCREEN_CFG
{
	DWORD 		dwSize;
	BYTE		sLEDName[NAME_LEN/*32*/];	// LED屏幕名称
	BYTE		byTransMode; 				// 现只支持串口通讯 1-串口通信
	BYTE		byProtocolType;				// 协议类型，对应LED屏的厂家
	BYTE		byLEDColor; 				// 1-单色， 2-双色， 3-256级灰度双基色， 4- 全彩色（目前只用单色）
	BYTE		byDataPolarity;				// 数据极性 .0-负极，1-正极
	BYTE		byOEPolarity;				// 0-低有效 1-高有效
	BYTE		byScanMode; 				// 1-1/16,  2-1/8,  3-1/4,  4-1/2,  5-静态
	BYTE		byRes1[2];
	//屏幕宽度和高度最小是16*16点，间隔是8个点	
	WORD		wLEDWidth;	 				// 16~2048
	WORD 		wLEDHeight;					// 16~2048
	BYTE		byRes2[64];
}NET_DVR_LED_SCREEN_CFG, *LPNET_DVR_LED_SCREEN_CFG;

//LED屏显内容
#define  MAX_CONTENT_LEN  512
typedef  struct tagNET_DVR_LED_CONTENT_CFG
{
	DWORD 		dwSize;
	BYTE		sLEDContent[MAX_CONTENT_LEN];	// LED屏幕显示内容
	BYTE		byContentAct;					// 1-静态，2-快速打出，3-向左移动，4-向右移动， 5-向上移动， 6-向下移动
	BYTE		byContentSpeed;					// 1-24（1最快，24最慢）	
	BYTE		byContentStayTime; 				// 0-127.5s(精度0.5s， SDK传送时候*2，即传送数值0-255，设备端在使用的时候需除以2)
	BYTE		byRes[33];
}NET_DVR_LED_CONTENT_CFG, *LPNET_DVR_LED_CONTENT_CFG;

//LED定时开关机
#define 	LED_TIMER_NUM 			3			// LED开机、关机时间组数
#define		TIME_SEGMENT_A_DAY		48			// 时间段个数，一天24小时，半小时一个段

typedef struct tagNET_DVR_SWITCH_TIME
{
	BYTE	byValid;				// 该组定时时间是否有效，时间是成对设置的
	BYTE	byRes[3];
	NET_DVR_TIME_EX struTimeOn; 	// 开机时间
	NET_DVR_TIME_EX struTimeOff; 	// 关机时间
}NET_DVR_SWITCH_TIME, *LPNET_DVR_SWITCH_TIME;


typedef struct tagNET_DVR_LED_SWITCH_TIME
{
	DWORD		dwSize;
	NET_DVR_SWITCH_TIME struTimer[LED_TIMER_NUM /*3*/]; 		//定时开关机时间，结构体中只有小时和分钟两个参数有效，每组开机时间要早于该组的关机时间，但比前一组的关机时间要晚，例如：struTimer[0]的关机时间是10：00那么，struTimer[0]的开机时间须设置为10:00之前， struTimer[1]的开机时间须设置为10：:00以后。
	BYTE		byRes[64];
}NET_DVR_LED_SWITCH_TIME, *LPNET_DVR_LED_SWITCH_TIME;

//分时亮度调节
typedef struct tagNET_DVR_LED_BRIGHTNESS_STEP
{
	DWORD 		dwSize;
	BYTE		byValid;		//分时亮度调节是否有效
	BYTE		byRes1[3];
	BYTE 		byBrightnessStep[TIME_SEGMENT_A_DAY /*48*/]; 	//将全天24个小时分为48个时段，每30分钟一个时段，用48个字节表示每个时段的亮度级别，亮度共16级，用0~15表示。
	BYTE		byRes2[48];
}NET_DVR_LED_BRIGHTNESS_STEP, *LPNET_DVR_LED_BRIGHTNESS_STEP;

typedef struct tagNET_DVR_LED_STATUS
{
	DWORD	dwSize;
	BYTE	bySwitchState;		//1-开机状态 2-关机状态
	BYTE	byBrightness;		//亮度值，范围0-15
	BYTE	byRes[62];
}NET_DVR_LED_STATUS, *LPNET_DVR_LED_STATUS;

//2010-12-28 高清解码卡能力集 begin
//新的解码卡服务器能力集
#define		MAX_DECODE_CARD_NUM			6   //最多高清解码卡数
/********************高清解码卡输出模式宏定义********************/
typedef enum _HD_DISPLAY_FORMAT
{
	HD_DISPLAY_FORMAT_INVALID = 0x00000000,
	HD_DISPLAY_FORMAT_CVBS = 0x00000001,
	HD_DISPLAY_FORMAT_DVI = 0x00000002,
	HD_DISPLAY_FORMAT_VGA = 0x00000004, 
	HD_DISPLAY_FORMAT_HDMI = 0x00000008, 
	HD_DISPLAY_FORMAT_YPbPr = 0x00000010
}HD_DISPLAY_FORMAT,*LPHD_DISPLAY_FORMAT;

/********************高清解码卡输出模式宏定义********************/
typedef struct tagNET_DVR_DECCARD_ABILITY      /*高清解码卡能力集*/
{
    BYTE byCardType;      //解码卡类型(0:MD,1:MD+,2:HD)
    BYTE byDecNums;      //解码通道数
    BYTE byDispNums;      //显示通道数
    BYTE byDecStartIdx;     //首个解码通道在所有解码通道中的索引
    BYTE byDispStartIdx;     //首个显示通道在所有显示通道中的索引
    BYTE byDispResolution[80]; //输出模式支持的分辨率
    BYTE byDispFormat[8];     //支持的输出模式(按HD_DISPLAY_FORMAT)
    BYTE byWindowMode[4][8]; //支持的窗口模式(比如1,2,4,9,16))
    BYTE byRes[35];
} NET_DVR_DECCARD_ABILITY,*LPNET_DVR_DECCARD_ABILITY;

typedef struct tagNET_DVR_DECODESVR_ABILITY
{
    DWORD dwSize;      /* 结构体大小 */
    BYTE byCardNums;      /* 解码卡数 */
    BYTE byStartChan;     /* 起始通道号 */
    BYTE byRes1[2];
    NET_DVR_DECCARD_ABILITY struDecCardAbility[MAX_DECODE_CARD_NUM];
	BYTE byRes2[64];
}NET_DVR_DECODESVR_ABILITY, *LPNET_DVR_DECODESVR_ABILITY;

typedef struct tagNET_MATRIX_DEV_CHAN_INFO
{
    NET_DVR_IPADDR 	struIP;		    //DVR IP地址
    WORD 	wDVRPort;			 	//端口号
    BYTE 	byChannel;				//通道号
    BYTE	byTransProtocol;		//传输协议类型0-TCP，1-UDP
    BYTE	byTransMode;			//传输码流模式 0－主码流 1－子码流
    BYTE	byFactoryType;			/*前端设备厂家类型,通过接口获取*/
    BYTE	byUsedSlotNum;			//是否使用槽位号，0-不使用，1-使用
    BYTE	bySlotNum;//槽位号
    BYTE	byRes[68];
    BYTE	sUserName[NAME_LEN];	//监控主机登陆帐号
    BYTE	sPassword[PASSWD_LEN];	//监控主机密码
}NET_MATRIX_DEV_CHAN_INFO,*LPNET_MATRIX_DEV_CHAN_INFO;

typedef struct tagNET_MATRIX_PU_STREAM_CFG
{
    DWORD							dwSize;
    NET_DVR_STREAM_MEDIA_SERVER_CFG	struStreamMediaSvrCfg;
    NET_MATRIX_DEV_CHAN_INFO		struDevChanInfo;
} NET_MATRIX_PU_STREAM_CFG,LPNET_MATRIX_PU_STREAM_CFG;

/*camera配置单元结构*/
typedef struct tagNET_DVR_MATRIX_CAMERACFG
{
    DWORD					dwGlobalIndex;//全局编号
    DWORD					dwInterIndex;//局部编号
	BYTE					sCamName[NAME_LEN];
    NET_MATRIX_PU_STREAM_CFG struPuStreamCfg;
} NET_DVR_MATRIX_CAMERACFG,*LPNET_DVR_MATRIX_CAMERACFG;

typedef struct tagNET_DVR_MATRIX_CAMERALIST
{
	DWORD			dwSize;
	BYTE			byRes[12];
	DWORD			dwCamNum;//CAM数量
	BYTE  			*pBuffer;
	DWORD 			dwBufLen;//所分配指针长度，输入参数
} NET_DVR_MATRIX_CAMERALIST,*LPNET_DVR_MATRIX_CAMERALIST;

typedef struct tagNET_DVR_DISP_CHAN_INFO
{
    NET_DVR_IPADDR	struIP;				/* 解码器 IP地址 */
    WORD 	wDVRPort;			 	/* 端口号 */
    BYTE 	byDispChannel;			/* 显示通道号 */
    BYTE	byUsedSlotNum;			//是否使用槽位号，0-使用，1-不使用
    BYTE	bySlotNum;//槽位号
    BYTE	byRes[7];
    BYTE	sUserName[NAME_LEN];	/*登陆帐号 */
    BYTE	sPassword[PASSWD_LEN];	/*密码 */
}NET_DVR_DISP_CHAN_INFO,*LPNET_DVR_DISP_CHAN_INFO;

/*monitor配置单元结构*/
typedef struct tagNET_DVR_MATRIX_MONITORCFG
{
    DWORD						dwGlobalIndex;//全局编号
    DWORD						dwInterIndex;
	BYTE						sMonName[NAME_LEN];
    NET_DVR_DISP_CHAN_INFO		struDispChanCfg;
} NET_DVR_MATRIX_MONITORCFG,*LPNET_DVR_MATRIX_MONITORCFG;
typedef struct tagNET_DVR_MATRIX_MONITORLIST
{
    DWORD		dwSize;
	BYTE		byRes[12];
	DWORD		dwMonNum;//MON数量
	BYTE  		*pBuffer;
	DWORD 		dwBufLen;//所分配指针长度，输入参数
} NET_DVR_MATRIX_MONITORLIST,*LPNET_DVR_MATRIX_MONITORLIST;

#define 	MAX_SUBMATRIX_NUM		8//级联中子最多从系统数量
typedef struct tagNET_DVR_SUBMATRIXINFO
{
	BYTE		byMainMatrix;//是否是主系统，1-是，0-否
	BYTE		bySubMatrixSequence;//级联子视频综合平台系统序号
	BYTE		byLoginType;//注册类型，1-直连，2-DNS，3-花生壳
	BYTE		byRes1[9];
	NET_DVR_IPADDR  struSubMatrixIP;		/*IP地址（可修改）*/
	WORD		wSubMatrixPort;        /*子系统端口号（可修改）*/
	BYTE		byRes2[6];
	NET_DVR_IPADDR  struSubMatrixIPMask;    /*IP地址掩码*/
	NET_DVR_IPADDR	struGatewayIpAddr;		 /* 网关地址 */    
	BYTE		sUserName[NAME_LEN];	/* 用户名 （此参数只能获取）*/
	BYTE		sPassword[PASSWD_LEN];	/*密码 （此参数只能获取）*/
	char		sDomainName[MAX_DOMAIN_NAME];//域名(可修改)
	char 		sDnsAddress[MAX_DOMAIN_NAME];/*DNS域名或IP地址*/
	BYTE		sSerialNumber[SERIALNO_LEN];//序列号（此参数只能获取）
	BYTE		byRes3[16];
}NET_DVR_SUBMATRIXINFO, *LPNET_DVR_SUBMATRIXINFO;

typedef struct tagNET_DVR_ALLUNITEDMATRIXINFO
{
	DWORD dwSize;
	NET_DVR_SUBMATRIXINFO struSubMatrixInfo[MAX_SUBMATRIX_NUM];
	BYTE  byRes2[32];
}NET_DVR_ALLUNITEDMATRIXINFO, *LPNET_DVR_ALLUNITEDMATRIXINFO;
		 
#define	MAX_GATEWAYTRUNKNUM		1024 //级联视频综合平台中最大路由干线数
	 
typedef struct tagNET_DVR_MATRIXGATEWAYNOTE
{
	 WORD	wTrunkInToOutAbility;//干线带宽，按D1的标准衡量，如4表示支持4个D1
	 WORD	wTrunkOutToInAbility;//干线带宽，按D1的标准衡量，如4表示支持4个D1，双向光纤时用到此值
	 BYTE    byRes[4];
	 NET_DVR_MATRIXSUBSYSTEMINFO struInputNote;
	 NET_DVR_MATRIXSUBSYSTEMINFO struOutputNote;
}NET_DVR_MATRIXGATEWAYNOTE, *LPNET_DVR_MATRIXGATEWAYNOTE;

typedef struct tagNET_DVR_MATRIXGATEWAYINFO
{
	 DWORD dwSize;
	 NET_DVR_MATRIXGATEWAYNOTE struGatewayNote[MAX_GATEWAYTRUNKNUM];
	 BYTE  byRes [32];
}NET_DVR_MATRIXGATEWAYINFO, *LPNET_DVR_MATRIXGATEWAYINFO;

typedef struct tagNET_DVR_MATRIXCODESYSTEMINFO
{
	 BYTE   byMatrixNum;//视频综合平台号
	 BYTE	bySubSystemNum;//子系统槽位号
	 BYTE	byChan;//编码通道
	 BYTE   byRes [13];
}NET_DVR_MATRIXCODESYSTEMINFO,*LPNET_DVR_MATRIXCODESYSTEMINFO;
typedef struct tagNET_DVR_MATRIXDECODESYSTEMINFO
{
	 BYTE    byMatrixNum;//视频综合平台号
	 BYTE	bySubSystemNum;//子系统槽位号
	 BYTE	byDispChan;//显示通道
	 BYTE	bySubDispChan;//显示通道子通道号
	 BYTE    byRes [12];
}NET_DVR_MATRIXDECODESYSTEMINFO,*LPNET_DVR_MATRIXDECODESYSTEMINFO;

typedef struct tagNET_DVR_MATRIXSWITCH
{
	 NET_DVR_MATRIXCODESYSTEMINFO struInputNote;
	 NET_DVR_MATRIXDECODESYSTEMINFO struOutputNote;
	 BYTE	byRes[32];
}NET_DVR_MATRIXSWITCH, *LPNET_DVR_MATRIXSWITCH;

typedef enum {
	ENC_CARD = 0,
	DEC_CARD,
	SD_DEC_CARD,
	FPGA_CARD,
	CS_CARD,
	ALERTOR_CARD,
	NAT_0,
	NAT_1,
	VCA_CARD,
	VGA_DEC_CARD,
	VGA_ENC_CARD,
	ERR_CARD,
} DEV_TYPE;

typedef struct tagNET_DVR_MATRIXSWITCHCTRL
{
	DWORD dwCamId;//摄像机全局编号
	DWORD dwMonId;//监视器全局编号
	BYTE  bySubWindowNum;//监视器对应子窗口号
	BYTE   bySwitchType;/*切换类型，0:正常切换，1:报警触发切换，2:报警取消，0xff:表示此MON上所有报警全部取消*/
	WORD   wAlarmType;//报警设备类型，1:报警主机，2：智能设备
	DWORD  dwResidentTime;/* 显示驻留时间，0xFFFFFFFF 时 为常驻情况，保持显示*/
	BYTE   byVcaDevType;//当报警设备类型是"智能设备"时，按DEV_TYPE类型
	BYTE   byRes[19];
}NET_DVR_MATRIXSWITCHCTRL, *LPNET_DVR_MATRIXSWITCHCTRL;

typedef struct tagNET_DVR_MATRIXDATABASE
{
    //配置文件类型，1-域数据库配置文件，2-子域数据库配置文件，3-平台数据库配置文件，4-场景配置文件，0xff最后一次失败的数据库语句
    DWORD dwDevType; 
	DWORD dwParam; //参数，代表域号、子域号、平台号，场景配置文件时此值无用
	BYTE  byFileType;//文件类型，1-sql语句，2-db语句，3-场景配置文件
    BYTE  byRes [3];
} NET_DVR_MATRIXDATABASE, *LPNET_DVR_MATRIXDATABASE;

typedef struct tagNET_DVR_SUBSYSTEMINFO_V40
{
	/*子系统类型，1-解码用子系统，2-编码用子系统，3-级联输出子系统，4-级联输入子系统，5-码分器子系统，6-报警主机子系统，7-智能子系统，8-V6解码子系统，9-V6子系统，10-转码子系统，11-X86服务器子系统，12-超高清输入子系统，0-NULL（此参数只能获取）*/
	BYTE		bySubSystemType;
	//子系统通道数，对于码分子系统，代表485串口数量（此参数只能获取）
	BYTE		byChan;
	BYTE		byLoginType;//注册类型，1-直连，2-DNS，3-花生壳
	BYTE		bySlotNum ;//槽位号，此参数只能获取
    BYTE		byRes1[4];
	NET_DVR_IPADDR   struSubSystemIP;		/*IP地址（可修改）*/
	NET_DVR_IPADDR   struSubSystemIPMask;//子网掩码
	NET_DVR_IPADDR	 struGatewayIpAddr;	/* 网关地址 */
	WORD		wSubSystemPort;        //子系统端口号（可修改）
	BYTE		byRes2[6];
    BYTE		sUserName[NAME_LEN];	/* 用户名 （此参数只能获取）*/
	BYTE		sPassword[PASSWD_LEN];	/*密码(可修改)*/
	char		sDomainName[MAX_DOMAIN_NAME];//域名(可修改)
	char 		sDnsAddress[MAX_DOMAIN_NAME];/*DNS域名或IP地址*/
	BYTE		sSerialNumber[SERIALNO_LEN];//序列号（此参数只能获取）
	BYTE		byBelongBoard;//所属子板号，从1开始，0xff表示无效
	BYTE		byInterfaceType;//接口类型，1-BNC，2-VGA，3-HDMI，4-DVI，5-SDI，6-光纤，7-RGB，8-YPbPr，0xff表示无效
	BYTE		byInterfaceNums;//接口个数，0xff表示无效
	BYTE		byInterfaceStartNum;//接口起始号，0xff表示无效
	BYTE        byDeviceName[20];//子系统名称
	BYTE		byRes3[36];
}NET_DVR_SUBSYSTEMINFO_V40, *LPNET_DVR_SUBSYSTEMINFO_V40;

#define  MAX_SUBSYSTEM_NUM_V40  120
typedef struct tagNET_DVR_ALLSUBSYSTEMINFO_V40
{
	DWORD dwSize;
	NET_DVR_SUBSYSTEMINFO_V40 struSubSystemInfo[MAX_SUBSYSTEM_NUM_V40];
	BYTE byRes[8];
}NET_DVR_ALLSUBSYSTEMINFO_V40, *LPNET_DVR_ALLSUBSYSTEMINFO_V40;

typedef struct tagNET_DVR_SINGLESUBSYSTEMJOININFO_V40
{
	/*子系统类型，1-解码用子系统，2-编码用子系统，3-级联输出子系统，4-级联输入子系统，5-码分器子系统，6-报警主机子系统，7-智能子系统，8-V6解码子系统，9-V6子系统，0-NULL（此参数只能获取）*/
	BYTE   bySubSystemType; 
	BYTE   byConnectStatus;//级联系统关联状态，1-连接正常，2-连接断开
	BYTE   byMatrixNum;//级联视频综合平台号，子系统类型是3或4时可用
	BYTE   bySubSystemNum;//级联子系统槽位号，0~79，子系统类型是3或4时可用
	NET_DVR_DECSUBSYSTEMJIONSTATUS struDecSub [MATRIX_MAXDECSUBSYSTEMCHAN];
	BYTE   byBindStatus;//绑定状态，0-没有绑定，1-已经绑定（大屏拼接时用到）
	BYTE   bySlotNum ;//槽位号，此参数只能获取
    //子系统类型为1的时可用，0-未关联，1-D1，2-720，3-1080
    BYTE   byDecodeAbility; 
    BYTE   byUsedTrunk;
	BYTE   byRes[64];
}NET_DVR_SINGLESUBSYSTEMJOININFO_V40,LPNET_DVR_SINGLESUBSYSTEMJOININFO_V40;

typedef struct tagNET_DVR_ALLDECSUBSYSTEMJOININFO_V40
{
	DWORD dwSize;
	NET_DVR_SINGLESUBSYSTEMJOININFO_V40 struSingleSubSystemJoinInfo[MAX_SUBSYSTEM_NUM_V40];
	BYTE  byRes[48];
}NET_DVR_ALLDECSUBSYSTEMJOININFO_V40, *LPNET_DVR_ALLDECSUBSYSTEMJOININFO_V40;

#define  MAX_OPTICALFIBER_NUM  16
typedef struct tagNET_DVR_SUBSYSTEM_ABILITY
{
	/*子系统类型，1-解码用子系统，2-编码用子系统，3-级联输出子系统，4-级联输入子系统，5-码分器子系统，6-报警主机子系统，7-智能子系统，8-V6解码子系统，9-V6子系统，10-转码子系统，11-X86服务器子系统，0-NULL（此参数只能获取）*/
	BYTE  bySubSystemType;
	BYTE  byChanNum;//子系统通道数
	BYTE  byStartChan;//子系统起始通道数
	BYTE  bySlotNum ;//槽位号 
	BYTE  byRes1[4];
	union
	{
		BYTE byRes[200];		
		struct
		{
            BYTE byDecode;        //是否是带解码功能的智能板,1-是，0-否
			BYTE byNeedPreAllocDec; //是否需要预分配解码资源，1-是，0-否
			BYTE byVACType;  //智能子系统类型，0-普通型，1-增强型
			BYTE byRes[197];
		}struVACSystemAbility;
		struct
		{
			BYTE  byVGANums;//VGA显示通道个数（从1开始）
			BYTE  byBNCNums;//BNC显示通道个数（从9开始）
			BYTE  byHDMINums;//HDMI显示通道个数（从25开始）
			BYTE  byDVINums;//DVI显示通道个数（从29开始）
			BYTE  byLayerNums ;//大屏拼接中，做主屏时所支持图层数
			BYTE  bySpartan;//畅显功能，0-不支持，1-支持
            BYTE  byDecType; //解码子系统类型，0-普通型,1-增强型(普通型分屏时前4窗口需使用自身资源，增强型无此限制，增强型最多可被其他子系统借16路D1解码资源
			                  //增强型被大屏关联为子屏后资源可被借用，普通型则不能被借用)
                              //2-智能关联解码子系统，3-转码关联解码子系统（智能和转码关联子系统不能用于解码上墙）
			BYTE  byOutputSwitch;//是否支持HDMI/DVI互相切换，0-不支持，1-支持
            BYTE  byRes1[39];            
			BYTE  byDecoderType ; //解码板是否支持多厂家码流解码，0-不支持，1-支持
            BYTE  byRes2[152];
		}struDecoderSystemAbility;
		struct
		{
			BYTE  byCoderType;//编码器类型，0-标清，1-高清, 2-模拟高清
			BYTE  byOptical;//光端机接入，0-否，1-是
            BYTE  byOpticalSubChan; //每个光口信道数			
            BYTE  bySupportAVSeparate;//是否支持音视频分离，0-不支持，1-支持
            BYTE  byRes[196];
		}struCoderSystemAbility;
        struct
        {
            WORD	wTrunkAbility;//干线带宽，按D1的标准衡量，如4表示支持4个D1
			BYTE    byOpticalFiberNum;//光纤条数
            BYTE    byRes[197];
        }struInputSystemAbility;
        struct
        {
            WORD	wTrunkAbility;//干线带宽，按D1的标准衡量，如4表示支持4个D1
            BYTE    byOpticalFiberNum;//光纤条数
            BYTE    byRes[197];
        }struOutputSystemAbility;
		struct
		{
			BYTE	by485Num;//码分子系统中485数量
			BYTE	bySlotNum;//每个485槽位数
			BYTE    byRes[198];
		}struCodeSpitterSystemAbility;
        struct
        {
            WORD	wAlarmInNums;
            WORD	wAlarmOutNums;
            /* 标识报警盒是否连接， 1表示已连接， 为0 表示未连接 */
            BYTE  byAlarmBoxEnable[4][8];
            BYTE  bySupportContact; /* 视频综合平台内部报警联动，0-不支持,1-支持 */
            BYTE  byRes[163];
		}struAlarmHostSystemAbility;
		struct
		{
			BYTE  byOpticalFiberNum;//光纤条数
			BYTE  byRes1[3];
			//光纤带宽，按D1的标准衡量，如4表示支持4个D1
			WORD	wTrunkAbility[MAX_OPTICALFIBER_NUM/*16*/];
			BYTE  byRes2[164];
		}struInOutputSystemAbility;
	}struAbility;
}NET_DVR_SUBSYSTEM_ABILITY, *LPNET_DVR_SUBSYSTEM_ABILITY;

typedef struct tagNET_DVR_VIDEOPLATFORM_ABILITY_V40
{
    DWORD   dwSize;
	BYTE    byCodeSubSystemNums;//编码子系统数量
	BYTE    byDecodeSubSystemNums;//解码子系统数量
	BYTE    bySupportNat;//是否支持NAT，0-不支持，1-支持
	BYTE    byInputSubSystemNums;//级联输入子系统数量
	BYTE	byOutputSubSystemNums;//级联输出子系统数量
	BYTE	byCodeSpitterSubSystemNums;//码分子系统数量
	BYTE	byAlarmHostSubSystemNums;//报警子系统数量
	BYTE	bySupportBigScreenNum;//所支持最多组成大屏的个数
	BYTE	byVCASubSystemNums;//智能子系统数量
	BYTE	byV6SubSystemNums;//V6子系统数量
	BYTE	byV6DecoderSubSystemNums;//V6解码子系统数量
    BYTE	bySupportBigScreenX;/*大屏拼接的模式：m×n*/
    BYTE	bySupportBigScreenY;
    BYTE	bySupportSceneNums;//支持场景模式的个数
    BYTE    byVcaSupportChanMode;//智能支持的通道使用模式，0-使用解码通道，1-使用显示通道及子通道号
    BYTE    bySupportScreenNums;//所支持的大屏的屏幕最大个数
    BYTE    bySupportLayerNums;//所支持的图层数，0xff-无效
    BYTE    byNotSupportPreview;//是否支持预览,1-不支持，0-支持
    BYTE    byNotSupportStorage;//是否支持存储,1-不支持，0-支持
    BYTE    byUploadLogoMode;//上传logo模式，0-上传给解码通道，1-上传给显示通道
	NET_DVR_SUBSYSTEM_ABILITY struSubSystemAbility[MAX_SUBSYSTEM_NUM_V40];
	BYTE	by485Nums;//485串口个数
    BYTE	by232Nums;//232串口个数
    BYTE	bySerieStartChan;//起始通道
    BYTE	byScreenMode;//大屏模式，0-主屏由客户端分配，1-主屏由设备端分配
    BYTE	byDevVersion;//设备版本，0-B10/B11/B12，1-B20
    BYTE	bySupportBaseMapNums;//所支持的底图数，底图号从1开始
    WORD    wBaseLengthX;//每个屏大小的基准值，B20使用
    WORD    wBaseLengthY;
    BYTE    bySupportPictureTrans;  //是否支持图片回显，0-不支持，1-支持	
    BYTE    bySupportPreAllocDec;   //是否支持智能解码资源预分配，0-不支持，1-支持
    BYTE    bySupportDecAutoManage; //是否支持解码资源管理
    BYTE    byTranDevSubSystemNums; //转码子系统数量
    BYTE    byRes2[626];
}NET_DVR_VIDEOPLATFORM_ABILITY_V40, *LPNET_DVR_VIDEOPLATFORM_ABILITY_V40;

typedef struct tagNET_DVR_VIDEOPLATFORM_ABILITY
{
    DWORD dwSize;
	BYTE  byCodeSubSystemNums;//编码子系统数量
	BYTE  byDecodeSubSystemNums;//解码子系统数量
	BYTE  bySupportNat;//是否支持NAT，0-不支持，1-支持
    BYTE  byInputSubSystemNums;//级联输入子系统数量
    BYTE  byOutputSubSystemNums;//级联输出子系统数量
    BYTE  byCodeSpitterSubSystemNums;//码分子系统数量
    BYTE  byAlarmHostSubSystemNums;//报警子系统数量
    BYTE  bySupportBigScreenNum;//所支持最多大屏拼接数量
    BYTE  byVCASubSystemNums;//智能子系统数量
	BYTE  byRes1[11];   
	NET_DVR_SUBSYSTEM_ABILITY struSubSystemAbility[MAX_SUBSYSTEM_NUM];
    BYTE  by485Nums;//485串口个数
    BYTE  by232Nums;//485串口个数
    BYTE  bySerieStartChan;//起始通道
    BYTE  byRes2[637];    
}NET_DVR_VIDEOPLATFORM_ABILITY, *LPNET_DVR_VIDEOPLATFORM_ABILITY;
//获取能力集接口

//模式A 
typedef struct tagNET_DVR_HOLIDATE_MODEA
{
    BYTE    byStartMonth;	// 开始月 从1开始
    BYTE	byStartDay;		// 开始日 从1开始
    BYTE	byEndMonth;		// 结束月 
    BYTE	byEndDay;		// 结束日
    BYTE	byRes[4];		// 保留字节
}NET_DVR_HOLIDATE_MODEA, *LPNET_DVR_HOLIDATE_MODEA;

typedef struct tagNET_DVR_HOLIDATE_MODEB
{
    BYTE	byStartMonth;	// 从1开始
    BYTE	byStartWeekNum;	// 第几个星期 从1开始 
    BYTE	byStartWeekday;	// 星期几
    BYTE	byEndMonth;		// 从1开始
    BYTE	byEndWeekNum;	// 第几个星期 从1开始 
    BYTE	byEndWeekday;	// 星期几	
    BYTE	byRes[2];		// 保留字节 
}NET_DVR_HOLIDATE_MODEB, *LPNET_DVR_HOLIDATE_MODEB;

typedef struct tagNET_DVR_HOLIDATE_MODEC
{
    WORD	wStartYear;		// 年
    BYTE	byStartMon;		// 月
    BYTE	byStartDay;		// 日
    WORD	wEndYear;		// 年
    BYTE	byEndMon;		// 月
    BYTE	byEndDay;		// 日
}NET_DVR_HOLIDATE_MODEC, *LPNET_DVR_HOLIDATE_MODEC;

typedef union tagNET_DVR_HOLIDATE_UNION
{	
    // 联合体大小 12字节
    DWORD				    dwSize[3];
    NET_DVR_HOLIDATE_MODEA	struModeA;	// 模式A
    NET_DVR_HOLIDATE_MODEB	struModeB;	// 模式B
    NET_DVR_HOLIDATE_MODEC	struModeC;	// 模式C
}NET_DVR_HOLIDATE_UNION, *LPNET_DVR_HOLIDATE_UNION;

typedef enum tagHOLI_DATE_MODE
{
    HOLIDATE_MODEA = 0,
    HOLIDATE_MODEB,
    HOLIDATE_MODEC
}HOLI_DATE_MODE;

typedef struct tagNET_DVR_HOLIDAY_PARAM
{
    BYTE	byEnable;			// 是否启用
    BYTE	byDateMode;			// 日期模式 0-模式A 1-模式B 2-模式C
    BYTE	byRes1[2];			// 保留字节
    NET_DVR_HOLIDATE_UNION uHolidate;	// 假日日期
    BYTE	byName[NAME_LEN];	// 假日名称
    BYTE	byRes2[20];			// 保留字节
}NET_DVR_HOLIDAY_PARAM, *LPNET_DVR_HOLIDAY_PARAM;

#define  MAX_HOLIDAY_NUM	32

typedef struct tagNET_DVR_HOLIDAY_PARAM_CFG
{
    DWORD	dwSize;			// 结构体大小
    NET_DVR_HOLIDAY_PARAM struHolidayParam[MAX_HOLIDAY_NUM];	// 假日参数
    DWORD	byRes[40];		// 保留参数
}NET_DVR_HOLIDAY_PARAM_CFG, *LPNET_DVR_HOLIDAY_PARAM_CFG;

// 假日报警处理方式
typedef struct tagNET_DVR_HOLIDAY_HANDLE
{
    DWORD	dwSize;				// 结构体大小
    NET_DVR_SCHEDTIME              struAlarmTime[MAX_TIMESEGMENT_V30];	// 布防时间段
    BYTE	byRes2[240];		// 保留字节
}NET_DVR_HOLIDAY_HANDLE, *LPNET_DVR_HOLIDAY_HANDLE;

typedef struct tagNET_DVR_HOLIDAY_RECORD
{
    DWORD           dwSize;
    NET_DVR_RECORDDAY     struRecDay;     // 录像参数
    NET_DVR_RECORDSCHED   struRecordSched[MAX_TIMESEGMENT_V30]; // 录像时间段
    BYTE      byRes[20];      //  保留字节
}NET_DVR_HOLIDAY_RECORD, *LPNET_DVR_HOLIDAY_RECORD;

#define  MAX_LINK_V30  128

typedef struct tagNET_DVR_ONE_LINK
{
    NET_DVR_IPADDR  struIP;     // 客户端IP
    LONG            lChannel;   // 通道号
    BYTE            byRes[32];  // 保留字节
}NET_DVR_ONE_LINK, *LPNET_DVR_ONE_LINK;

typedef struct tagNET_DVR_LINK_STATUS
{
    DWORD   dwSize;      // 结构体大小
    WORD    wLinkNum;    // 连接的数目
    BYTE    byRes1[2];  // 保留字节
    NET_DVR_ONE_LINK struOneLink[MAX_LINK_V30];   // 连接的客户端信息
    BYTE    byRes[32];  // 保留字节
}NET_DVR_LINK_STATUS, *LPNET_DVR_LINK_STATUS;

#define MAX_BOND_NUM  2

typedef struct tagNET_DVR_ONE_BONDING
{
    BYTE    byMode;				// 工作模式0 - 网络容错 1 - 负载均衡
    BYTE	byUseDhcp;			// 是否使能dhcp
    BYTE	byMasterCard;	    //  指定哪张网卡为主网卡		
    BYTE    byStatus;           // BONDING的状态  0 - 异常 1-正常 只能获取不能设置
    BYTE	byBond[MAX_NETWORK_CARD];// byBond[0]== 1 表示使用eh0  0表示不使用eh0
    NET_DVR_ETHERNET_V30	struEtherNet;		// 网卡参数
    NET_DVR_IPADDR	struGatewayIpAddr;  // 网关地址
    BYTE	byRes[20];			// 保留字节
}NET_DVR_ONE_BONDING, *LPNET_DVR_ONE_BONDING;

typedef struct tagNET_DVR_NETWORK_BONDING
{
    DWORD   dwSize;         // 结构体大小
    BYTE    byEnable;       // 是否启用bonding功能
    BYTE    byNum;          // Bonding网卡的个数
    BYTE    byRes1[2];         //  保留字节
    NET_DVR_ONE_BONDING struOneBond[MAX_BOND_NUM];
    BYTE	byRes2[40];		// 保留字节
}NET_DVR_NETWORK_BONDING, *LPNET_DVR_NETWORK_BONDING;


// 磁盘配额
typedef struct tagNET_DVR_DISK_QUOTA 
{
	BYTE	byQuotaType;	 // 磁盘配额类型,1 - 按容量 
    BYTE    byRes1[7];       // 保留字节
    DWORD   dwHCapacity;     // 分配的磁盘容量高32位 单位MB
    DWORD   dwLCapacity;     // 分配的磁盘容量低32位 单位MB
    DWORD   dwHUsedSpace;    // 已使用的磁盘大小高32位 单位MB
    DWORD   dwLUsedSpace;    // 已使用的磁盘大小低32位 单位MB
	BYTE    byQuotaRatio;    //	分配的磁盘比例,单位:%
    BYTE    byRes2[21];      // 保留字节
}NET_DVR_DISK_QUOTA, *LPNET_DVR_DISK_QUOTA;

typedef struct tagNET_DVR_DISK_QUOTA_CFG
{
    DWORD   dwSize;         // 结构体大小
    NET_DVR_DISK_QUOTA    struPicQuota;    //  图片配额
    NET_DVR_DISK_QUOTA    struRecordQuota;    //  录像配额
    BYTE    byRes[60];      //保留字节
}NET_DVR_DISK_QUOTA_CFG, *LPNET_DVR_DISK_QUOTA_CFG;


typedef struct tagNET_DVR_TIMING_CAPTURE
{
    NET_DVR_JPEGPARA  struJpegPara;   // 定时抓图图片质量
	DWORD      dwPicInterval;  // 定时抓图时间间隔,单位s   1-1s 2-2s 3-3s 4-4s 5-5s 
                                //	6-10m 7-30m 8-1h 9-12h 10-24h
    BYTE       byRes[12];      // 保留字节
}NET_DVR_TIMING_CAPTURE, *LPNET_DVR_TIMING_CAPTURE;

typedef struct tagNET_DVR_REL_CAPTURE_CHAN
{
    BYTE    byChan[16];    // 按位表示
    BYTE    byRes[20];          // 保留字节
}NET_DVR_REL_CAPTURE_CHAN, *LPNET_DVR_REL_CAPTURE_CHAN;

#define MAX_PIC_EVENT_NUM      32
#define MAX_ALARMIN_CAPTURE   16

typedef struct  tagNET_DVR_REL_CAPTURE_CHAN_V40
{
    DWORD   dwMaxRelCaptureChanNum;  //最大可触发的关联通道数-只读属性
    DWORD   dwChanNo[MAX_CHANNUM_V40]; //触发的关联抓图通道号，按值表示，采用紧凑型排列,0xffffffff表示后续无效
    BYTE     byRes[32];
}NET_DVR_REL_CAPTURE_CHAN_V40, *LPNET_DVR_REL_CAPTURE_CHAN_V40;

typedef struct tagNET_DVR_EVENT_CAPTURE_V40
{
    NET_DVR_JPEGPARA  struJpegPara;   // 事件抓图图片质量
    DWORD   dwPicInterval;   // 事件抓图时间间隔  单位为秒 
    NET_DVR_REL_CAPTURE_CHAN_V40 struRelCaptureChan[MAX_PIC_EVENT_NUM];   // 数组下标 0 移动侦测触发抓图 1 视频遮挡触发抓图 2 视频丢失触发抓图,数组3表示PIR报警抓图，数组4表示无线报警抓图，数组5表示呼救报警抓图,数组6表示智能抓图
    NET_DVR_REL_CAPTURE_CHAN_V40 struAlarmInCapture[MAX_ALARMIN_CAPTURE];    // 报警输入触发抓图，下标0 代表报警输入1 依次类推
    DWORD   dwMaxGroupNum;  //设备支持的最大报警输入组数，每组16个报警输入
    BYTE      byCapTimes; //抓图张数
    BYTE      byRes[59];
}NET_DVR_EVENT_CAPTURE_V40, *LPNET_DVR_EVENT_CAPTURE_V40;


typedef struct tagNET_DVR_EVENT_CAPTURE
{
    NET_DVR_JPEGPARA  struJpegPara;   // 事件抓图图片质量
    DWORD       dwPicInterval;  // 事件抓图时间间隔  单位为秒  1-1s 2-2s 3-3s 4-4s 5-5s 
	//	6-10m 7-30m 8-1h 9-12h 10-24h
    NET_DVR_REL_CAPTURE_CHAN struRelCaptureChan[MAX_PIC_EVENT_NUM]; // 数组下标 0 移动侦测触发抓图 1 视频遮挡触发抓图,2 视频丢失触发抓图,数组3表示PIR报警抓图，数组4表示无线报警抓图，数组5表示呼救报警抓图,数组6表示智能抓图， 数组7表示人脸侦测
    NET_DVR_REL_CAPTURE_CHAN struAlarmInCapture[MAX_ALARMIN_CAPTURE];    // 报警输入触发抓图，下标0 代表报警输入1 依次类推
	BYTE       byCapTimes; //抓图张数
    BYTE       byRes[59];
}NET_DVR_EVENT_CAPTURE, *LPNET_DVR_EVENT_CAPTURE;

typedef struct tagNET_DVR_JPEG_CAPTURE_CFG_V40
{
    DWORD     				        dwSize;               //结构体长度
    NET_DVR_TIMING_CAPTURE        struTimingCapture;    
    NET_DVR_EVENT_CAPTURE_V40    struEventCapture;
    BYTE       byRes3[20];     // 保留字节
}NET_DVR_JPEG_CAPTURE_CFG_V40, *LPNET_DVR_JPEG_CAPTURE_CFG_V40;

typedef struct tagNET_DVR_JPEG_CAPTURE_CFG
{
    DWORD      dwSize;         // 结构体大小
    NET_DVR_TIMING_CAPTURE struTimingCapture;    
    NET_DVR_EVENT_CAPTURE struEventCapture;
    BYTE       byRes3[20];     // 保留字节
}NET_DVR_JPEG_CAPTURE_CFG, *LPNET_DVR_JPEG_CAPTURE_CFG;  

typedef struct tagNET_DVR_CAPTURE_DAY
{
    BYTE	byAllDayCapture;	// 是否全天抓图
    BYTE	byCaptureType;		// 抓图类型：0-定时抓图，1-移动侦测抓图，2-报警抓图，3-移动侦测或报警抓图，4-移动侦测和报警抓图，6-智能报警抓图
    BYTE	byRes[2];
}NET_DVR_CAPTURE_DAY, *LPNET_DVR_CAPTURE_DAY;

typedef struct tagNET_DVR_CAPTURE_SCHED
{
    NET_DVR_SCHEDTIME struCaptureTime;        // 抓图时间段
    BYTE        byCaptureType;       // 抓图类型：0-定时抓图，1-移动侦测抓图，2-报警抓图，3-移动侦测或报警抓图，4-移动侦测和报警抓图，6-智能报警抓图
    BYTE        byRes[3];           // 保留字节
}NET_DVR_CAPTURE_SCHED, *LPNET_DVR_CAPTURE_SCHED;

// 通道抓图计划
typedef struct tagNET_DVR_SCHED_CAPTURECFG
{
    DWORD  dwSize;     // 结构体
    BYTE	byEnable;	// 是否抓图
    BYTE	byRes1[3];	// 保留字节
    NET_DVR_CAPTURE_DAY	struCaptureDay[MAX_DAYS];	// 全天抓图计划
    NET_DVR_CAPTURE_SCHED	struCaptureSched[MAX_DAYS][MAX_TIMESEGMENT_V30];	// 时间段抓图布防计划
    NET_DVR_CAPTURE_DAY	struCaptureHoliday;			// 假日抓图计划
    NET_DVR_CAPTURE_SCHED	struHolidaySched[MAX_TIMESEGMENT_V30];	// 时间段假日抓图布防计划
    DWORD	dwRecorderDuration;	// 抓图保存最长时间 0xffffffff表示该值无效 
    BYTE	byRes[40];			// 保留字节
}NET_DVR_SCHED_CAPTURECFG, *LPNET_DVR_SCHED_CAPTURECFG;


typedef struct tagNET_DVR_FLOW_TEST_PARAM
{
	DWORD  dwSize;              //结构大小
    LONG   lCardIndex;         //网卡索引
    DWORD  dwInterval;         //设备上传流量时间间隔, 单位:100ms
    BYTE   byRes[8];           //保留字节
}NET_DVR_FLOW_TEST_PARAM, *LPNET_DVR_FLOW_TEST_PARAM;

typedef struct tagNET_DVR_FLOW_INFO
{
	DWORD  dwSize;             //结构大小
	DWORD  dwSendFlowSize;     //发送流量大小,单位kbps
	DWORD  dwRecvFlowSize;     //接收流量大小,单位kbps
    BYTE   byRes[20];          //保留 
}NET_DVR_FLOW_INFO, *LPNET_DVR_FLOW_INFO;

//  录像标签
#define LABEL_NAME_LEN 40
typedef struct tagNET_DVR_RECORD_LABEL
{
    DWORD  dwSize;					// 结构体大小
    NET_DVR_TIME  struTimeLabel;			// 标签的时间 
    BYTE	byQuickAdd;				// 是否快速添加 快速添加时标签名称无效
    BYTE	byRes1[3];				// 保留字节
    BYTE	sLabelName[LABEL_NAME_LEN];	// 标签的名称 长度为40字节  
    BYTE	byRes2[40];				// 保留字节
}NET_DVR_RECORD_LABEL, *LPNET_DVR_RECORD_LABEL;

#define  LABEL_IDENTIFY_LEN     64
typedef struct tagNET_DVR_LABEL_IDENTIFY
{
    BYTE    sLabelIdentify[LABEL_IDENTIFY_LEN];    // 64字节标识
    BYTE    byRes[8];               // 保留字节
}NET_DVR_LABEL_IDENTIFY, *LPNET_DVR_LABEL_IDENTIFY;

#define MAX_DEL_LABEL_IDENTIFY  20// 删除的最大标签标识个数

typedef struct tagNET_DVR_DEL_LABEL_PARAM
{
    DWORD   dwSize;       // 结构体大小
    BYTE    byMode;   // 按位表示,0x01表示按标识删除
    BYTE    byRes1;
    WORD    wLabelNum;      // 标签数目      
    NET_DVR_LABEL_IDENTIFY struIndentify[MAX_DEL_LABEL_IDENTIFY]; // 标签标识
    BYTE    byRes2[160];   //保留字节    
}NET_DVR_DEL_LABEL_PARAM, *LPNET_DVR_DEL_LABEL_PARAM;

typedef struct tagNET_DVR_LABEL_PARAM
{
	NET_DVR_LABEL_IDENTIFY struIndentify; //要修改的标签标识
	BYTE byRes1[24];
	BYTE sLabelName[LABEL_NAME_LEN];	//修改后的标签名称
	BYTE byRes2[40];				
}NET_DVR_MOD_LABEL_PARAM, *LPNET_DVR_MOD_LABEL_PARAM;

// 标签搜索结构体
typedef struct tagNET_DVR_FIND_LABEL
{
    DWORD       dwSize;          // 结构体大小
    LONG	    lChannel;		// 查找的通道
    NET_DVR_TIME	struStartTime;	// 开始时间
    NET_DVR_TIME	struStopTime;	// 结束时间
    BYTE	    sLabelName[LABEL_NAME_LEN];	//  录像标签名称 如果标签名称为空，则搜索起止时间所有标签
	BYTE		byDrawFrame;		//0:不抽帧，1：抽帧
    BYTE	    byRes[39];		// 保留字节
}NET_DVR_FIND_LABEL, *LPNET_DVR_FIND_LABEL;

// 标签信息结构体
typedef struct tagNET_DVR_FINDLABEL_DATA
{
    BYTE	sLabelName[LABEL_NAME_LEN];	// 标签名称
    NET_DVR_TIME struTimeLabel;		// 标签时间
    NET_DVR_LABEL_IDENTIFY struLabelIdentify; // 标签标识
    BYTE	byRes1[32];			// 保留字节
}NET_DVR_FINDLABEL_DATA, *LPNET_DVR_FINDLABEL_DATA;

#define CARDNUM_LEN_V30 40
typedef struct tagNET_DVR_FIND_PICTURE_PARAM
{
    DWORD  dwSize;         // 结构体大小 
    LONG   lChannel;       // 通道号
    BYTE   byFileType;      /* 查找的图片类型:0定时抓图1 移动侦测抓图 2 报警抓图3  报警 | 移动侦测抓图 4 报警 & 移动侦测抓图 
											 6 手动抓图 ,9-智能图片,10- PIR报警，11- 无线报警，12- 呼救报警,
	0xa 预览时截图，0xd 人脸侦测, 0xe 越界侦测，0xf 入侵区域侦测，0x10 场景变更侦测, 0x11-设备本地回放时截图, 0x12-智能侦测，0xff- 全部类型 2013-07-16*/  
    BYTE   byNeedCard;     // 是否需要卡号
    BYTE   byRes1[2];      // 保留字节
    BYTE   sCardNum[CARDNUM_LEN_V30];     // 卡号
    NET_DVR_TIME  struStartTime;//查找图片的开始时间
    NET_DVR_TIME  struStopTime;// 查找图片的结束时间
    BYTE   byRes2[40];     // 保留字节
}NET_DVR_FIND_PICTURE_PARAM, *LPNET_DVR_FIND_PICTURE_PARAM;

#define PICTURE_NAME_LEN 64

typedef struct
{
    char    sFileName[PICTURE_NAME_LEN];//图片名
    NET_DVR_TIME struTime;//图片的时间
    DWORD dwFileSize;//图片的大小
    char    sCardNum[CARDNUM_LEN_V30];	//卡号
    BYTE byRes[32];		//  保留字节
}NET_DVR_FIND_PICTURE,*LPNET_DVR_FIND_PICTURE;

#define MAX_RECORD_PICTURE_NUM  50      //  最大备份图片张数  

typedef struct tagNET_DVR_BACKUP_PICTURE_PARAM
{
	DWORD  dwSize;         // 结构体大小   
	DWORD  dwPicNum;
	NET_DVR_FIND_PICTURE struPicture[MAX_RECORD_PICTURE_NUM];
	BYTE   byDiskDes[DESC_LEN_32];
	BYTE   byWithPlayer;
	BYTE   byContinue;    /*是否继续备份 0不继续 1继续*/
	BYTE   byRes[34];
}NET_DVR_BACKUP_PICTURE_PARAM, *LPNET_DVR_BACKUP_PICTURE_PARAM;

typedef struct 
{	
	DWORD dwSize;           //结构体大小
	DWORD dwChannel;        //通道号
	BYTE  byCompressType;   //待获取的压缩参数类型1,主码流2,子码流3,事件
	BYTE  byRes[15];        //保留
	NET_DVR_COMPRESSIONCFG_V30  struCurrentCfg; //当前压缩参数配置
}NET_DVR_COMPRESSION_LIMIT, *LPNET_DVR_COMPRESSION_LIMIT;

#define   STEP_READY       0    //准备升级
#define   STEP_RECV_DATA   1    //接收升级包数据
#define   STEP_UPGRADE     2    //升级系统
#define   STEP_BACKUP      3    //备份系统
#define   STEP_SEARCH      255  //搜索升级文件

typedef struct tagNET_DVR_VIDEO_EFFECT
{
	DWORD dwBrightValue;      //亮度[0,255]
	DWORD dwContrastValue;    //对比度[0,255]
	DWORD dwSaturationValue;  //饱和度[0,255]
	DWORD dwHueValue;         //色调[0,255]
	DWORD dwSharpness;		  //锐度[0,255]
	DWORD dwDenoising;		  //去噪[0,255]
	BYTE  byRes[12];
}NET_DVR_VIDEO_EFFECT, *LPNET_DVR_VIDEO_EFFECT;

typedef struct tagNET_DVR_VIDEO_INPUT_EFFECT
{	
	DWORD					dwSize;				//结构体大小
	WORD					wEffectMode;        //模式 0-标准 1-室内 2-弱光 3-室外  255-自定义
	BYTE					byRes1[146];        //保留
	NET_DVR_VIDEO_EFFECT	struVideoEffect;	//视频效果参数
	BYTE					byRes2[60];			//保留
}NET_DVR_VIDEO_INPUT_EFFECT, *LPNET_DVR_VIDEO_INPUT_EFFECT;


typedef struct tagNET_DVR_VIDEOPARA_V40
{
	DWORD	dwChannel;			// 通道号
	DWORD	dwVideoParamType;  	// 视频参数类型 0-亮度 1-对比度 2-饱和度 3-色度 4-锐度 5-去噪
	DWORD	dwVideoParamValue;  //对应的视频参数值，范围依据能力集
	BYTE 	byRes[12];
}NET_DVR_VIDEOPARA_V40, *LPNET_DVR_VIDEOPARA_V40;

typedef struct tagNET_DVR_DEFAULT_VIDEO_COND
{
	DWORD	dwSize;			// 结构体大小
	DWORD	dwChannel;		// 通道号
	DWORD	dwVideoMode;	// 模式
	BYTE	byRes[32];      // 保留
}NET_DVR_DEFAULT_VIDEO_COND, *LPNET_DVR_DEFAULT_VIDEO_COND;

typedef struct tagNET_DVR_ENCODE_JOINT_PARAM
{
    DWORD	dwSize;			// 结构体大小
    BYTE	byJointed;		//  0 没有关联 1 已经关联
    BYTE	byDevType;		// 被关联的设备类型  1 代表智能设备
    BYTE	byRes1[2];		// 保留字节
    NET_DVR_IPADDR	struIP;			// 关联的被取流设备IP地址
    WORD	wPort;			// 关联的被取流设备端口号
    WORD	wChannel;		// 关联的被取流设备通道号
    BYTE	byRes2[20];			// 保留字节
}NET_DVR_ENCODE_JOINT_PARAM, *LPNET_DVR_ENCODE_JOINT_PARAM;	

typedef struct tagNET_DVR_VCA_CHAN_WORKSTATUS
{
    BYTE	byJointed;				// 0-没有关联  1-已经关联
    BYTE	byRes1[3];
    NET_DVR_IPADDR	struIP;					// 关联的取流设备IP地址
    WORD	wPort;					// 关联的取流设备端口号
    WORD	wChannel;				// 关联的取流设备通道号
    BYTE	byVcaChanStatus;		// 0 - 未启用 1 - 启用
    BYTE	byRes2[19];				// 保留字节
}NET_DVR_VCA_CHAN_WORKSTATUS, *LPNET_DVR_VCA_CHAN_WORKSTATUS;

typedef struct tagNET_DVR_VCA_DEV_WORKSTATUS
{
    DWORD	dwSize;			// 结构体大小
    BYTE	byDeviceStatus;	// 设备的状态0 - 正常工作 1- 不正常工作
    BYTE	byCpuLoad;		// CPU使用率0-100 分别代表使用百分率
    NET_DVR_VCA_CHAN_WORKSTATUS struVcaChanStatus[MAX_VCA_CHAN];
    DWORD	byRes[40];		// 保留字节
}NET_DVR_VCA_DEV_WORKSTATUS, *LPNET_DVR_VCA_DEV_WORKSTATUS;

typedef struct tagNET_DVR_VGA_DISP_CHAN_CFG_V40
{        
    DWORD	dwSize; 
    BYTE   byAudio;			/*音频是否开启*/
    BYTE   byAudioWindowIdx;      /*音频开启子窗口*/
    BYTE 	byVgaResolution;      /*分辨率，从能力集获取*/
    BYTE	byVedioFormat;         /*1:NTSC,2:PAL，0-NULL*/
    DWORD	dwWindowMode;		/*画面模式，能力集获取*/       
    BYTE  	byJoinDecChan[MAX_WINDOWS];/*各个子窗口关联的解码通道*/
	BYTE	byEnlargeStatus;          /*是否处于放大状态，0：不放大，1：放大*/
	BYTE    byEnlargeSubWindowIndex;//放大的子窗口号
	BYTE	byScale; /*显示模式，0---真实显示，1---缩放显示( 针对BNC )*/
	/*区分共用体，0-视频综合平台内部解码器显示通道配置，1-其他解码器显示通道配置*/
	BYTE	byUnionType;
	union
	{
		BYTE byRes[160];
		struct
		{
			/*各个子窗口对应解码通道所对应的解码子系统的槽位号(对于视频综合平台中解码子系统有效)*/
			BYTE	byJoinDecoderId[MAX_WINDOWS];
			//显示窗口所解视频分辨率，1-D1,2-720P,3-1080P，设备端需要根据此//分辨率进行解码通道的分配，如1分屏配置成1080P，则设备会把4个解码通
			//道都分配给此解码通道
			BYTE	byDecResolution;
			BYTE	byRes[143];
		}struVideoPlatform;
		struct
		{
			BYTE	byRes[160];
		}struNotVideoPlatform;
	}struDiff;
	BYTE	byRes[120];
}NET_DVR_VGA_DISP_CHAN_CFG_V40,*LPNET_DVR_VGA_DISP_CHAN_CFG_V40;

typedef struct tagNET_DVR_V6SUBSYSTEMPARAM
{
	BYTE		bySerialTrans;//是否透传，0-否，1-是
    BYTE		byRes[35];
}NET_DVR_V6SUBSYSTEMPARAM, *LPNET_DVR_V6SUBSYSTEMPARAM;

#define		NET_DVR_V6PSUBSYSTEMARAM_GET	1501//获取V6子系统配置
#define		NET_DVR_V6PSUBSYSTEMARAM_SET	1502//设置V6子系统配置


typedef struct tagNET_DVR_CORRECT_DEADPIXEL_PARAM
{
	DWORD dwSize;
	DWORD dwCommand; //命令：0-进入坏点模式，1-添加坏点，2-保存坏点，3-退出坏点
	DWORD dwDeadPixelX; //坏点X坐标
	DWORD dwDeadPixelY; //坏点Y坐标
	BYTE byRes[12]; //保留
}NET_DVR_CORRECT_DEADPIXEL_PARAM, *LPNET_DVR_CORRECT_DEADPIXEL_PARAM;

#define MAX_REDAREA_NUM   6   //最大红绿灯区域个数
typedef struct tagNET_DVR_REDAREACFG
{
	DWORD dwSize;
	DWORD dwCorrectEnable; //是否开启校正功能，0-关闭，1-开启
	DWORD dwCorrectLevel; //校正级别，1(校正度最低)-10(校正度最高),默认为5
	DWORD dwAreaNum; //校正区域个数
	NET_VCA_RECT struLaneRect[MAX_REDAREA_NUM]; //校正区域
	BYTE   byRes2[32]; //保留
}NET_DVR_REDAREACFG, *LPNET_DVR_REDAREACFG;

typedef struct tagNET_DVR_HISTORICDATACFG
{
    DWORD dwSize;
	DWORD dwTotalNum;  //历史数据个数
	BYTE byRes[16];
}NET_DVR_HISTORICDATACFG, *LPNET_DVR_HISTORICDATACFG;


#define INQUEST_MESSAGE_LEN     44    //审讯重点标记信息长度
#define INQUEST_MAX_ROOM_NUM    2     //最大审讯室个数
#define MAX_RESUME_SEGMENT      2     //支持同时恢复的片段数目

typedef struct tagNET_DVR_INQUEST_ROOM
{
	BYTE		byRoomIndex;     //审讯室编号
    BYTE		byRes[23];       //保留
}NET_DVR_INQUEST_ROOM, *LPNET_DVR_INQUEST_ROOM;

typedef struct tagNET_DVR_INQUEST_MESSAGE
{
	char 		sMessage[INQUEST_MESSAGE_LEN]; //重点标记信息
    BYTE	byRes[46];                     //保留
}NET_DVR_INQUEST_MESSAGE, *LPNET_DVR_INQUEST_MESSAGE;

typedef struct tagNET_DVR_INQUEST_SENSOR_DEVICE
{
	WORD	wDeviceType;	//数据采集设备型号:0-无 1-米乐 2-镭彩 3-优力 4-佳盟 5-永控、6-垅上、7-维纳斯达
	WORD	wDeviceAddr;	//数据采集设备地址	
	BYTE 	byRes[28];	    //保留
}NET_DVR_INQUEST_SENSOR_DEVICE, *LPNET_DVR_INQUEST_SENSOR_DEVICE;

typedef struct tagNET_DVR_INQUEST_SENSOR_INFO
{
	NET_DVR_INQUEST_SENSOR_DEVICE struSensorDevice[INQUEST_MAX_ROOM_NUM];
	DWORD   dwSupportPro;      //支持协议类型,按位表示, 新版本走能力集，不再扩展此字段
							   //0x1:米乐 0x2:镭彩 0x4:优力
	BYTE    byRes[120];        //保留
}NET_DVR_INQUEST_SENSOR_INFO, *LPNET_DVR_INQUEST_SENSOR_INFO;

typedef struct tagNET_DVR_INQUEST_ROOM_INFO
{
	char		szCDName[NAME_LEN];	//光盘名称，单室双刻光盘名称是一样的
	union
	{
		BYTE 	byBitRate;	// byCalcType为0时有效，(0-32、1-48、2-64、3-80、4-96、5-128、
								//6-160、7-192、8-224、9-256、10-320、11-384、12-448、
								//13-512、14-640、15-768、16-896前16个值保留)17-1024、18-1280、19-1536、
								//20-1792、21-2048、22-3072、23-4096、24-8192
		BYTE	byInquestTime;  // byCalcType为1时有效，0-1小时, 1-2小时,2-3小时,3-4小时, 4-6小时,5-8小时
		//8-16小时, 9-20小时,10-22小时,11-24小时
	}uCalcMode;
	BYTE		byCalcType;			//刻录计算类型0-按码率 1-按时间
	BYTE		byAutoDelRecord;	// 是否自动删除录像，0-不删除，即结束时保存录像 1-删除
	BYTE		byAlarmThreshold;		// 声音报警阀值
	BYTE		byInquestChannelResolution;     //审讯通道分辨率，0:720P  1:1080P
	BYTE		byRes[11];
}NET_DVR_INQUEST_ROOM_INFO, *LPNET_DVR_INQUEST_ROOM_INFO;

typedef struct tagNET_DVR_INQUEST_SYSTEM_INFO
{
	DWORD  dwRecordMode;         //刻录模式:1 单室双刻模式 2 单室轮刻模式 3 双室双刻模式（修改需要重启设备）
    DWORD  dwWorkMode;           //工作模式:0 标准模式 1 通用模式(保留，目前只有标准模式)
	DWORD  dwResolutionMode;     //设备分辨率，0:标清 1:D1 2:720P 3:1080P（高清审讯机不用此字段）
	NET_DVR_INQUEST_SENSOR_INFO struSensorInfo;  //温湿度传感器配置	
	NET_DVR_INQUEST_ROOM_INFO 	struInquestRoomInfo[INQUEST_MAX_ROOM_NUM];
	BYTE    byRes[24];	
}NET_DVR_INQUEST_SYSTEM_INFO, *LPNET_DVR_INQUEST_SYSTEM_INFO;

typedef struct tagNET_DVR_INQUEST_RESUME_SEGMENT
{
	NET_DVR_TIME  struStartTime; //事件起始时间
	NET_DVR_TIME  struStopTime;  //事件终止时间
	BYTE	byRoomIndex;         //审讯室编号,从1开始
	BYTE    byDriveIndex;        //刻录机编号,从1开始
	WORD    wSegmetSize;         //本片断的大小, 单位M 
	DWORD   dwSegmentNo;         //本片断在本次审讯中的序号,从1开始 
	BYTE    byRes[24];           //保留
}NET_DVR_INQUEST_RESUME_SEGMENT, *LPNET_DVR_INQUEST_RESUME_SEGMENT;

typedef struct tagNET_DVR_INQUEST_RESUME_EVENT
{
	DWORD   dwResumeNum;       //需恢复的事件个数
	NET_DVR_INQUEST_RESUME_SEGMENT struResumeSegment[MAX_RESUME_SEGMENT];
	BYTE    byRes[200];        //保留
}NET_DVR_INQUEST_RESUME_EVENT, *LPNET_DVR_INQUEST_RESUME_EVENT;

typedef struct tagNET_DVR_INQUEST_DEVICE_VERSION
{
	BYTE  byMainVersion;         /*基线主版本.
								   0 : 未知
								   1 : 8000审讯DVR
								       次版本: 1 : 8000HD-S
								   2 : 8100审讯DVR 
									   次版本: 1 : 审讯81SNL
											   2 : 审讯81SH
											   3 : 审讯81SFH
								   3 : 8608高清审讯机NVR 
									   次版本: 1 : DS-8608SN-SP
											   2 : DS-8608SN-ST
									  */
	BYTE  bySubVersion;          //基线次版本
    BYTE  byUpgradeVersion;      //升级版本,未升级为0
	BYTE  byCustomizeVersion;     //定制版本,非定制为0
	BYTE  byRes[60];             //保留
}NET_DVR_INQUEST_DEVICE_VERSION, *LPNET_DVR_INQUEST_DEVICE_VERSION;

typedef struct tagNET_DVR_DISK_RAID_INFO 
{
    DWORD dwSize;   //结构体大小
	BYTE byEnable;  //磁盘Raid是否禁用
    BYTE byRes[35];  //保留字节
}NET_DVR_DISK_RAID_INFO, *LPNET_DVR_DISK_RAID_INFO;


typedef struct tagNET_DVR_SYNCHRONOUS_IPC
{
	DWORD dwSize;    //结构体大小
	BYTE  byEnable;  //是否启用：为前端IPC同步设备参数
	BYTE  byRes[7];  //保留
}NET_DVR_SYNCHRONOUS_IPC, *LPNET_DVR_SYNCHRONOUS_IPC;

typedef struct tagNET_DVR_IPC_PASSWD
{
	DWORD dwSize;    //结构体大小
	char sOldPasswd[PASSWD_LEN];  //IPC的旧密码，传给DVR让DVR验证
	char sNewPasswd[PASSWD_LEN];  //IPC的新密码
	BYTE byRes[32];
}NET_DVR_IPC_PASSWD, *LPNET_DVR_IPC_PASSWD;

//通过获取DVR的网络状态：单位bps
typedef struct tagNET_DEVICE_NET_USING_INFO 
{
	DWORD dwSize;    //结构体大小
    DWORD dwPreview;   //预览
    DWORD dwPlayback;  //回放
    DWORD dwIPCModule; //IPC接入
	DWORD dwNetDiskRW; //网盘读写
    BYTE res[32];
}NET_DVR_DEVICE_NET_USING_INFO, *LPNET_DVR_DEVICE_NET_USING_INFO;

//通过DVR设置前端IPC的IP地址
typedef struct tagNET_DVR_IPC_NETCFG
{
	DWORD dwSize;      //结构体大小
	NET_DVR_IPADDR struIP;       //IPC的IP地址
	WORD wPort;       //IPC的端口
	char res[126];  
}NET_DVR_IPC_NETCFG, *LPNET_DVR_IPC_NETCFG;

//按时间锁定
typedef struct tagNET_DVR_TIME_LOCK
{
	DWORD dwSize;      //结构体大小
	NET_DVR_TIME strBeginTime;
	NET_DVR_TIME strEndTime;
	DWORD   dwChannel;        //通道号, 0xff表示所有通道
	DWORD   dwRecordType;     //录像类型:  0xffffffff－全部，0－定时录像，1-移动侦测，2－报警触发，3-报警触发或移动侦测，4-报警触发和移动侦测，5-命令触发，6-手动录像，7-智能录像(同文件查找)
	DWORD   dwLockDuration;   //锁定持续时间,单位秒,0xffffffff表示永久锁定
	NET_DVR_TIME_EX strUnlockTimePoint;	//加锁时有效，当dwLockDuration不为永久锁定时，锁定持续的时间到此时间点就自动解锁
	BYTE    byRes[4];
}NET_DVR_TIME_LOCK, *LPNET_DVR_TIME_LOCK;

typedef struct tagNET_DVR_LOCK_RETURN
{
	DWORD dwSize;      //结构体大小
	NET_DVR_TIME strBeginTime; 
	NET_DVR_TIME strEndTime;
	BYTE    byRes[20];
}NET_DVR_LOCK_RETURN, *LPNET_DVR_LOCK_RETURN;

//67DVS
//证书下载类型
typedef enum 
{
    UPGRADE_CERT_FILE = 0, 
	UPLOAD_CERT_FILE = 1,
	TRIAL_CERT_FILE = 2,
    CONFIGURATION_FILE = 3
}NET_SDK_UPLOAD_TYPE;  

typedef enum 
{
	NET_SDK_DOWNLOAD_CERT = 0,		//下载证书
	NET_SDK_DOWNLOAD_IPC_CFG_FILE = 1,//下载IPC配置文件
    NET_SDK_DOWNLOAD_BASELINE_SCENE_PIC = 2, //下载基准场景图片
	NET_SDK_DOWNLOAD_VQD_ALARM_PIC = 3,       //下载VQD报警图片
    NET_SDK_DOWNLOAD_CONFIGURATION_FILE=4   //下载配置文件
}NET_SDK_DOWNLOAD_TYPE;

//下载状态
typedef enum 
{
	NET_SDK_DOWNLOAD_STATUS_SUCCESS = 1,	//下载成功
	NET_SDK_DOWNLOAD_STATUS_PROCESSING,		//正在下载
	NET_SDK_DOWNLOAD_STATUS_FAILED,			//下载失败
	NET_SDK_DOWNLOAD_STATUS_UNKOWN_ERROR	//未知错误 
}NET_SDK_DOWNLOAD_STATUS;

typedef struct tagNET_DVR_BONJOUR_CFG
{
    DWORD	dwSize;				// 结构体大小
	BYTE	byEnableBonjour;		// Bonjour使能 0 ：开启 1：关闭
    BYTE 	byRes1[3];				
    BYTE 	byFriendlyName[MAX_DOMAIN_NAME]; 	// 服务名
	BYTE 	byRes2[128];
}NET_DVR_BONJOUR_CFG, *LPNET_DVR_BONJOUR_CFG;

typedef struct tagNET_DVR_SOCKS_CFG
{
	DWORD			dwSize;				// 结构体大小
    BYTE			byEnableSocks;  		// 使能 0：关闭 1：开启
	BYTE 			byVersion;  			// SOCKS版本 4：SOCKS4   5：SOCKS5
	WORD			wProxyPort;				// 代理端口，默认1080
	BYTE			byProxyaddr[MAX_DOMAIN_NAME];  	// 代理IP地址，可以是域名
    BYTE 			byUserName[MAX_DOMAIN_NAME]; 	// 用户名 SOCKS才用
    BYTE 			byPassword[NAME_LEN];			// 密码SOCKS5才用
	BYTE 			byLocalAddr[MAX_LOCAL_ADDR_LEN];  //不使用socks代理的网段，格式为"ip/netmask;ip/netmask;…"
    BYTE 			byRes[128];
}NET_DVR_SOCKS_CFG, *LPNET_DVR_SOCKS_CFG;



typedef struct tagNET_DVR_QOS_CFG
{
	DWORD		dwSize;
    BYTE		byManageDscp;   // 管理数据的DSCP值 [0-63]
    BYTE		byAlarmDscp;    // 报警数据的DSCP值 [0-63]
    BYTE		byVideoDscp;    // 视频数据的DSCP值 [0-63]，byFlag为0时，表示音视频
	BYTE		byAudioDscp;    // 音频数据的DSCP值 [0-63]，byFlag为1时有效
	BYTE		byFlag;			// 0：音视频合一，1：音视频分开
	BYTE		byEnable;
    BYTE 		byRes[126];
}NET_DVR_QOS_CFG, *LPNET_DVR_QOS_CFG;

typedef struct tagNET_DVR_HTTPS_CFG
{
	DWORD		dwSize;
	WORD		wHttpsPort;		// HTTPS端口
	BYTE		byEnable;		// 使能 0：关闭 1：开启
	BYTE		byRes[125];
}NET_DVR_HTTPS_CFG, *LPNET_DVR_HTTPS_CFG;

//证书相关
typedef struct tagNET_DVR_CERT_NAME
{
    BYTE	byCountry[MAX_COUNTRY_NAME_LEN];  			//国家代号 CN等
    BYTE 	byState[MAX_DOMAIN_NAME];				//洲或省
    BYTE 	byLocality[MAX_DOMAIN_NAME];			//地区
    BYTE 	byOrganization[MAX_DOMAIN_NAME];		//组织
    BYTE 	byUnit[MAX_DOMAIN_NAME];				//单位
    BYTE 	byCommonName[MAX_DOMAIN_NAME];
	BYTE 	byEmail[MAX_DOMAIN_NAME];  
	BYTE 	byRes[128];
}NET_DVR_CERT_NAME, *LPNET_DVR_CERT_NAME ;

typedef struct tagNET_DVR_CERT_PARAM
{
	DWORD dwSize;
	WORD wCertFunc; //证书种类，0-802.1x,1-HTTPS
	WORD wCertType; //证书类型，0-CA，1-Certificate,2-私钥文件
	BYTE byFileType; //证书文件类型，0-PEM,1-PFX
	BYTE  byRes[35]; 
}NET_DVR_CERT_PARAM, *LPNET_DVR_CERT_PARAM;

#define UPLOAD_CERTIFICATE  1 //上传证书


typedef struct tagNET_DVR_CERT_INFO
{
	DWORD 				dwSize;
	NET_DVR_CERT_PARAM 	struCertParam;	//证书参数
	DWORD				dwValidDays;   //有效天数，类型为自签名时有效
	BYTE     			byPasswd[NAME_LEN];   //私钥密码
	NET_DVR_CERT_NAME 	struCertName;    // 证书名称
	NET_DVR_CERT_NAME 	struIssuerName;    // 证书发行者名称（自签名证书信息获取时有效）
	NET_DVR_TIME_EX     	struBeginTime;   //证书创建时间（自签名证书信息获取时有效）
	NET_DVR_TIME_EX     	struEndTime;   //证书截止时间（自签名证书信息获取时有效）
	BYTE     			serialNumber[NAME_LEN];   //证书标识码（自签名证书信息获取时有效）
	BYTE 				byVersion; 
	BYTE     			byKeyAlgorithm;			//加密类型 0-RSA  1-DSA
	BYTE      			byKeyLen;				//加密长度 0-512  1-1024、 2-2048
	BYTE     			bySignatureAlgorithm; //签名算法类型（自签名证书信息获取时有效）
	BYTE 				byRes[128];
}NET_DVR_CERT_INFO, *LPNET_DVR_CERT_INFO;


//channel record status
//***通道录像状态*****//
typedef struct tagNET_DVR_CHANS_RECORD_STATUS
{
	BYTE byValid;       //是否有效
	BYTE byRecord;      /*(只读)录像类型, 按位表示:0: 不在录像；1：在录像 2-空闲 
						3-无连接 4-无输入视频 5-未加载 6-存档中
							7-回传中 8-用户名或密码错 9-未验证
							10-存档中和录像中 11-录像回传中和录像中*/
	WORD wChannelNO;   //通道号
	DWORD dwRelatedHD;  //关联磁盘
	BYTE	byOffLineRecord;  //断网录像功能 0-关闭 1-开启
	BYTE	byRes[7];      //保留字节
}NET_DVR_CHANS_RECORD_STATUS, *LPNET_DVR_CHANS_RECORD_STATUS;


typedef struct tagNET_DVR_IP_ALARM_GROUP_NUM
{
	DWORD dwSize; 
	DWORD dwIPAlarmInGroup;      //IP通道报警输入组数
	DWORD dwIPAlarmInNum;       //IP通道报警输入个数
	DWORD dwIPAlarmOutGroup;     //IP通道报警输出组数
	DWORD dwIPAlarmOutNum;      //IP通道报警输出个数
	BYTE byRes[64];  
}NET_DVR_IP_ALARM_GROUP_NUM, *LPNET_DVR_IP_ALARM_GROUP_NUM;
//****NVR end***//

typedef struct tagNET_DVR_CHAN_GROUP_RECORD_STATUS
{
	DWORD dwSize; //结构体大小
	NET_DVR_CHANS_RECORD_STATUS struChanStatus[MAX_CHANNUM_V30]; //一组64个
}NET_DVR_CHAN_GROUP_RECORD_STATUS, *LPNET_DVR_CHAN_GROUP_RECORD_STATUS;


typedef struct tagNET_DVR_RECTCFG
{
	WORD wXCoordinate; /*矩形左上角起始点X坐标*/
	WORD wYCoordinate; /*矩形左上角Y坐标*/
	WORD wWidth;       /*矩形宽度*/
	WORD wHeight;      /*矩形高度*/
}NET_DVR_RECTCFG, *LPNET_DVR_RECTCFG;
/*窗口信息*/
typedef struct tagNET_DVR_WINCFG
{
	DWORD dwSize;
	BYTE  byVaild;
	BYTE  byInputIdx;          /*输入源索引*/
    BYTE  byLayerIdx;          /*图层，0为最底层*/
	BYTE  byTransparency; //透明度，0～100 
	NET_DVR_RECTCFG  struWin;//目的窗口(相对显示墙)
    WORD wScreenHeight;//大屏高
    WORD wScreenWidth;//大屏宽
	BYTE  byRes[20];
}NET_DVR_WINCFG, *LPNET_DVR_WINCFG;

#define  MAX_LAYERNUMS	32

typedef struct tagNET_DVR_ALLWINCFG
{
    DWORD dwSize;
    NET_DVR_WINCFG struWinCfg[MAX_LAYERNUMS];
    BYTE  byRes2[24];
}NET_DVR_ALLWINCFG, *LPNET_DVR_ALLWINCFG;

typedef struct tagNET_DVR_SCREENZOOM
{
	DWORD dwSize;
	DWORD dwScreenNum;//大屏号
	NET_DVR_POINT_FRAME struPointFrame;
	BYTE  byLayer;//图层号
	BYTE  byRes[11];
}NET_DVR_SCREENZOOM, *LPNET_DVR_SCREENZOOM;

//2011-04-18
/*摄像机信息,最多9999个，从1开始 */
typedef struct tagNET_MATRIX_CAMERAINFO
{  
    DWORD dwGlobalCamId;      /* cam的全局编号*/
    BYTE  sCamName[NAME_LEN]; /*cam的名称*/
    DWORD dwMatrixId;          /*cam对应矩阵的编号*/
    DWORD dwLocCamId;         /*cam对应矩阵的内部编号*/ 
    BYTE  byValid;    /*是否有效，0-否，1-是*/
    BYTE  byPtzCtrl; /* 是否可控，0-否，1-是*/
    BYTE  byUseType; //*使用类型，0-不作为干线使用，1-BNC，2-SP3,3-V6光纤，4-其他光纤*/ 
	BYTE  byUsedByTrunk;//当前使用状态，0-没有被使用，1-被干线使用 
	BYTE  byTrunkReq; /*摄像机分辨率,以D1为单位：1 - 1个D1，2- 2个D1，作为干线使用时，指的是干线的带宽*/
	BYTE  byRes1[3];
	NET_DVR_TIME struInstallTime;//安装时间
    BYTE  sPurpose[NAME_LEN];/*用途描述*/
	BYTE  byRes2[20];  
}NET_MATRIX_CAMERAINFO, *LPNET_MATRIX_CAMERAINFO;

/*监视器信息，最多2048个*/
typedef struct tagNET_MATRIX_MONITORINFO 
{
    DWORD	dwGloalMonId; /*mon 的统一编号*/
    BYTE	sMonName[NAME_LEN];
    DWORD	dwMatrixId;  /*mon所在矩阵的编号*/
    DWORD	dwLocalMonId; /*mon的内部编号*/
    BYTE	byValid;    /*是否有效，0-否，1-是*/
	BYTE	byTrunkType; /*使用类型，0-不作为干线使用，1-BNC，2-SP3,3-V6光纤，4-其他光纤*/ 
	BYTE	byUsedByTrunk;//当前使用状态，0-没有被使用，1-被干线使用 
	BYTE	byTrunkReq; /*分辨率, 以D1为单位：1- 1个D1，2- 2个D1，作为干线使用时，指的是干线的带宽*/
	NET_DVR_TIME struInstallTime;//安装时间
    BYTE	sPurpose[NAME_LEN];/*用途描述*/
    BYTE	byRes[20];  
}NET_MATRIX_MONITORINFO, *LPNET_MATRIX_MONITORINFO;

typedef struct tagNET_MATRIX_DIGITALMATRIX
{
	NET_DVR_IPADDR  struAddress; /*设备为数字设备时的IP信息*/
	WORD	wPort;
	BYTE	byNicNum; /*0 - eth0, 1 - eth1, 考虑双网口如何通信加入绑定的网口*/
	BYTE	byRes[69];   
}NET_MATRIX_DIGITALMATRIX, *LPNET_MATRIX_DIGITALMATRIX;
typedef struct tagNET_MATRIX_ANALOGMATRIX
{
	BYTE	bySerPortNum;   /*连接的串口号*/
	BYTE    byMatrixSerPortType;/* 矩阵接入网关的串口与模拟矩阵的键盘口(键盘协议)连接还是与矩阵通信口（矩阵协议）连接 ，0 --- 矩阵协议通讯口 1 --- 键盘通讯口*/
	BYTE	byRes1[2];
	NET_DVR_SINGLE_RS232 struRS232;	//232串口参数
	BYTE	byRes2[200];      
}NET_MATRIX_ANALOGMATRIX, *LPNET_MATRIX_ANALOGMATRIX;

typedef union tagNET_MATRIX_UNION
{
	NET_MATRIX_DIGITALMATRIX struDigitalMatrix;
	NET_MATRIX_ANALOGMATRIX struAnalogMatrix;
}NET_MATRIX_UNION, *LPNET_MATRIX_UNION;
/*矩阵配置信息，最多20个*/
typedef struct tagNET_MATRIX_MATRIXINFO 
{
	DWORD   dwSize;
	DWORD	dwMatrixId;  /*矩阵编号*/
	BYTE	sDevName[NAME_LEN];
	BYTE	byCtrlType; /*指通讯方式是串口通信, 还是网络通信*/
	BYTE	byProtocolType;/*设置通信控制协议*/
	BYTE	byRes1[6];   /*预留*/
	NET_MATRIX_UNION struMatrixUnion;
	DWORD	dwMaxPortsIn; /*矩阵输入数*/
	DWORD	dwMaxPortsOut;/*矩阵输出数*/
	BYTE	sUserName[NAME_LEN];   /*登录用户名*/
	BYTE	sPassword[PASSWD_LEN];  /*登录密码*/        
	NET_DVR_TIME struInstallTime;//安装时间
	BYTE	sPurpose[NAME_LEN];/*用途描述*/
	BYTE	byRes2[20];   /*预留*/
}NET_MATRIX_MATRIXINFO, *LPNET_MATRIX_MATRIXINFO;


typedef struct tagNET_DVR_MATRIXLIST
{
	DWORD	dwSize;
	BYTE	byRes[12];
	DWORD	dwMatrixNum;//设备返回的矩阵数量
	BYTE    *pBuffer;//矩阵信息缓冲区
	DWORD   dwBufLen;//所分配指针长度，输入参数
}NET_DVR_MATRIXLIST,*LPNET_DVR_MATRIXLIST;
 
/*串口配置信息*/
typedef struct tagNET_MATRIX_UARTPARAM
{	
	DWORD dwSize;
	BYTE  byPortName[NAME_LEN];
	WORD  wUserId; /*用户编号，当连接设备为键盘时，绑定一个用户，用于权限管理*/
	BYTE  byPortType;    /*串口类型，三种0-RS232/1-RS485/2-RS422*/
	BYTE  byFuncType; /*串口连接的设备的类型0-空闲，1-键盘，2-用作透明通道(485串口不可配置成透明通道),3-模拟矩阵*/     
	BYTE  byProtocolType;  /*串口支持的协议类型, 当连接键盘设备时需要该信息,获取键盘支持协议的编号及描述符*/
	BYTE  byBaudRate;
	BYTE  byDataBits;
	BYTE  byStopBits;   /*停止位*/
	BYTE  byParity;      /*校验*/
	BYTE  byFlowCtrl;   /*流控，软件流控，无流控*/
	BYTE  byRes[22];     /*预留*/
}NET_MATRIX_UARTPARAM, *LPNET_MATRIX_UARTPARAM;

//最多256个用户，1～256
typedef struct tagNET_MATRIX_USERPARAM 
{
	DWORD dwSize;
    BYTE	sUserName[NAME_LEN];
    BYTE	sPassword[PASSWD_LEN/*16*/];
    BYTE	byRole;/*用户角色:0-管理员,1-操作员；只有一个系统管理员，255个操作员*/
    BYTE	byLevel;  /*统一级别，用于操作级别管理,1- 255*/
    BYTE	byRes[18];
}NET_MATRIX_USERPARAM, *LPNET_MATRIX_USERPARAM;

//最多255个资源组
typedef struct tagNET_MATRIX_RESOURSEGROUPPARAM
{
    DWORD dwSize;
    BYTE  byGroupName[NAME_LEN];
	BYTE  byGroupType;/*0-摄像机CAM组，1-监视器MON组*/
	BYTE  byRes1;
    WORD  wMemNum;
    DWORD dwGlobalId[512];
    BYTE  byRes2[20];
}NET_MATRIX_RESOURCEGROUPPARAM,*LPNET_MATRIX_RESOURSEGROUPPARAM;

//最多255个用户组
typedef struct tagNET_MATRIX_USERGROUPPARAM
{
	DWORD dwSize;
	BYTE  sGroupName[NAME_LEN];
	WORD  wUserMember[255];  /*包含的用户成员*/
	WORD  wResorceGroupMember[255]; /*包含的资源组成员*/
	BYTE  byPermission[32];//权限，数组0-ptz权限、切换权限、查询权限
	BYTE  byRes[20];
} NET_MATRIX_USERGROUPPARAM, *LPNET_MATRIX_USERGROUPPARAM;

typedef struct tagNET_MATRIX_TRUNKPARAM
{
	DWORD	dwSize;
    DWORD	dwTrunkId;
    BYTE	sTrunkName[NAME_LEN];
    DWORD	dwSrcMonId;
    DWORD	dwDstCamId;
	BYTE	byTrunkType;  /*使用类型  1-BNC，2-SP3光纤高清，3-SP3光纤D1， 4-V6光纤，5-其他光纤*/
	BYTE	byAbility;     /*表示光纤的带宽，可以传输几路*/
	BYTE	bySubChan;   /*针对光纤干线而言，表示子通道号*/
	BYTE    byLevel;		/* 干线级别 1-255*/
	WORD	wReserveUserID;	//预留的用户ID： 1~256 ，0表示释放预留
	BYTE   byRes[18]; 
} NET_MATRIX_TRUNKPARAM, *LPNET_MATRIX_TRUNKPARAM;

typedef struct tagNET_DVR_MATRIX_TRUNKLIST
{
	DWORD	dwSize;
	BYTE	byRes[12];
	DWORD	dwTrunkNum;//设备返回的干线数量
	BYTE    *pBuffer;//干线信息缓冲区
	DWORD   dwBufLen;//所分配指针长度，输入参数
}NET_DVR_MATRIX_TRUNKLIST,*LPNET_DVR_MATRIX_TRUNKLIST;

#define MATRIX_PROTOCOL_NUM    20    //支持的最大矩阵协议数
#define KEYBOARD_PROTOCOL_NUM  20    //支持的最大键盘协议数
typedef struct tagNET_DVR_PROTO_TYPE_EX
{ 
	WORD wType;               /*ipc协议值*/  
	WORD wCommunitionType;		/*0：模拟 1：数字 2：兼容模拟、数字*/
	BYTE  byDescribe[DESC_LEN]; /*协议描述字段*/    
}NET_DVR_PROTO_TYPE_EX, LPNET_DVR_PROTO_TYPE_EX;

typedef struct tagNET_DVR_MATRIXMANAGE_ABIILITY
{
	DWORD	dwSize;
	DWORD	dwMaxCameraNum;//最大Camera数量
	DWORD	dwMaxMonitorNum;//最大监视器数量
	WORD	wMaxMatrixNum;//最大矩阵数量
	WORD	wMaxSerialNum;//串口数量
	WORD	wMaxUser;//最大用户数
	WORD	wMaxResourceArrayNum;//最大资源组数
	WORD	wMaxUserArrayNum;//最大用户组数
	WORD	wMaxTrunkNum;//最大干线数
	BYTE	nStartUserNum;//起始用户号
	BYTE	nStartUserGroupNum;//起始用户组号
	BYTE	nStartResourceGroupNum;//起始资源组号
	BYTE	nStartSerialNum;//起始串口号
	DWORD   dwMatrixProtoNum;     /*有效的矩阵协议数目，从0开始*/
	NET_DVR_PROTO_TYPE_EX struMatrixProto[MATRIX_PROTOCOL_NUM];/*最大协议列表长度*/    
    DWORD   dwKeyBoardProtoNum;     /*有效的键盘协议数目，从0开始*/
    NET_DVR_PROTO_TYPE_EX struKeyBoardProto[KEYBOARD_PROTOCOL_NUM];/*最大协议列表长度*/   
	BYTE    byRes[32];
} NET_DVR_MATRIXMANAGE_ABILITY, *LPNET_DVR_MATRIXMANAGE_ABILITY;

//人脸抓拍规则(单条)
typedef struct tagNET_VCA_SINGLE_FACESNAPCFG
{
	BYTE byActive;				//是否激活规则：0-否，1-是
	BYTE byRes[3];     //保留
    NET_VCA_SIZE_FILTER struSizeFilter;   //尺寸过滤器
	NET_VCA_POLYGON     struVcaPolygon;		//人脸识别区域
}NET_VCA_SINGLE_FACESNAPCFG, *LPNET_VCA_SINGLE_FACESNAPCFG;

//人脸抓拍规则参数
typedef struct tagNET_VCA_FACESNAPCFG
{
	DWORD dwSize;
	BYTE bySnapTime;					//单个目标人脸的抓拍次数0-10
	BYTE bySnapInterval;                 //抓拍间隔，单位：帧
	BYTE bySnapThreshold;               //抓拍阈值，0-100
	BYTE byGenerateRate; 		//目标生成速度,范围[1, 5]	
	BYTE bySensitive;			//目标检测灵敏度，范围[1, 5]
	BYTE byReferenceBright; //2012-3-27参考亮度[0,100]
	BYTE byMatchType;         //2012-5-3比对报警模式，0-目标消失后报警，1-实时报警
    BYTE byMatchThreshold;  //2012-5-3实时比对阈值，0~100
	NET_DVR_JPEGPARA  struPictureParam; //图片规格结构
	NET_VCA_SINGLE_FACESNAPCFG struRule[MAX_RULE_NUM]; //人脸抓拍规则
	BYTE byRes2[100];
}NET_VCA_FACESNAPCFG, *LPNET_VCA_FACESNAPCFG;

//人脸抓拍结果
typedef struct tagNET_VCA_FACESNAP_RESULT
{
	DWORD   dwSize;     		// 结构大小
	DWORD 	dwRelativeTime;     // 相对时标
	DWORD	dwAbsTime;			// 绝对时标
    DWORD   dwFacePicID;       //人脸图ID
	DWORD   dwFaceScore;		//人脸评分,0-100
	NET_VCA_TARGET_INFO  struTargetInfo;	//报警目标信息
    NET_VCA_RECT         struRect;      //人脸子图区域
	NET_VCA_DEV_INFO  	 struDevInfo;		//前端设备信息
	DWORD   dwFacePicLen;		//人脸子图的长度，为0表示没有图片，大于0表示有图片
    DWORD   dwBackgroundPicLen; //背景图的长度，为0表示没有图片，大于0表示有图片(保留)
	BYTE    byRes[60];              // 保留字节
	BYTE*   pBuffer1;  //人脸子图的图片数据
	BYTE*   pBuffer2;  //背景图的图片数据（保留，通过查找背景图接口可以获取背景图）
}NET_VCA_FACESNAP_RESULT, *LPNET_VCA_FACESNAP_RESULT;

//虚焦侦测结果
typedef struct  tagNET_DVR_DEFOCUS_ALARM
{
	DWORD   dwSize;     /*结构长度*/
	NET_VCA_DEV_INFO  	 struDevInfo;/*设备信息*/
	BYTE	byRes[64];		// 保留字节
}NET_DVR_DEFOCUS_ALARM, *LPNET_DVR_DEFOCUS_ALARM;

typedef struct  tagNET_DVR_AUDIOEXCEPTION_ALARM
{
	DWORD      dwSize;     /*结构长度*/
	BYTE  byAlarmType;//报警类型，1-音频输入异常，2-音频输入突变
	BYTE  byRes1;
	WORD wAudioDecibel;//声音强度（音频输入突变时用到）
	NET_VCA_DEV_INFO  	 struDevInfo;/*设备信息*/
	BYTE	byRes[64];		// 保留字节
}NET_DVR_AUDIOEXCEPTION_ALARM, *LPNET_DVR_AUDIOEXCEPTION_ALARM;

typedef struct  tagNET_BUTTON_DOWN_EXCEPTION_ALARM
{
	DWORD      dwSize;     /*结构长度*/
	NET_VCA_DEV_INFO  	 struDevInfo;/*设备信息*/
	BYTE	byRes[64];		// 保留字节
}NET_BUTTON_DOWN_EXCEPTION_ALARM, *LPNET_BUTTON_DOWN_EXCEPTION_ALARM;

typedef struct tagNET_VCA_FD_IMAGE_CFG
{
    DWORD   dwWidth;                  //灰度图像数据宽度
	DWORD   dwHeight;                 //灰度图像高度
	DWORD   dwImageLen;  //灰度图像数据长度
	BYTE     byRes[20];  //保留
	BYTE     *pImage;    //灰度图像数据
}NET_VCA_FD_IMAGE_CFG, *LPNET_VCA_FD_IMAGE_CFG;

typedef struct tagNET_VCA_FD_PROCIMG_CFG
{
    DWORD    dwSize;           //结构大小
    BYTE     byEnable;         //是否激活规则;
    BYTE     bySensitivity;      //检测灵敏度，[0,5]
    BYTE     byRes1[22];       //保留字节 
    NET_VCA_SIZE_FILTER  struSizeFilter;  //尺寸过滤器
    NET_VCA_POLYGON   struPolygon;    //多边形
    NET_VCA_FD_IMAGE_CFG struFDImage;  //图片信息
    BYTE     byRes2[20];    //保留
}NET_VCA_FD_PROCIMG_CFG, *LPNET_VCA_FD_PROCIMG_CFG;

typedef struct tagNET_VCA_SUB_PROCIMG
{
	DWORD dwImageLen;  //图片数据长度
	DWORD dwFaceScore;		//人脸评分,0-100
	NET_VCA_RECT struVcaRect; //人脸子图区域
	BYTE  byRes[20];  //保留
	BYTE  *pImage;  //图片数据
}NET_VCA_SUB_PROCIMG, *LPNET_VCA_SUB_PROCIMG;

typedef struct tagNET_VCA_FD_PROCIMG_RESULT
{
	DWORD dwSize;   //结构大小
	DWORD dwImageId; //大图ID
	BYTE byRes[20]; //保留
	DWORD dwSubImageNum;  //人脸子图张数
	NET_VCA_SUB_PROCIMG  struProcImg[MAX_TARGET_NUM];  //单张子图信息
}NET_VCA_FD_PROCIMG_RESULT, *LPNET_VCA_FD_PROCIMG_RESULT;

typedef struct tagNET_VCA_PICMODEL_RESULT
{
	DWORD dwImageLen;  //图片数据长度
	DWORD dwModelLen;  //模型数据长度
	BYTE  byRes[20]; //保留
	BYTE  *pImage;  //人脸图片数据指针
	BYTE  *pModel;  //模型数据指针
}NET_VCA_PICMODEL_RESULT, *LPNET_VCA_PICMODEL_RESULT;

typedef struct tagNET_VCA_REGISTER_PIC
{
	DWORD dwImageID; //大图ID
	DWORD dwFaceScore;		//人脸评分,0-100
	NET_VCA_RECT struVcaRect;  //人脸子图区域
	BYTE  byRes[20];  //保留
}NET_VCA_REGISTER_PIC, *LPNET_VCA_REGISTER_PIC;

#define MAX_HUMAN_PICTURE_NUM  10   //最大照片数
#define MAX_HUMAN_BIRTHDATE_LEN 10   //最大出生年月长度

typedef struct tagNET_DVR_AREAINFOCFG
{ 
	WORD wNationalityID; //国籍
	WORD wProvinceID; //省
	WORD wCityID; //市
	WORD wCountyID; //县
	BYTE byRes[4]; //保留
}NET_DVR_AREAINFOCFG, *LPNET_DVR_AREAINFOCFG;

typedef struct tagNET_VCA_HUMAN_ATTRIBUTE
{
	BYTE   bySex; //性别：0-男，1-女
	BYTE   byCertificateType; //证件类型：0-身份证，1-警官证
	BYTE   byBirthDate[MAX_HUMAN_BIRTHDATE_LEN]; //出生年月，如：201106
	BYTE   byName[NAME_LEN]; //姓名
	NET_DVR_AREAINFOCFG struNativePlace; //籍贯参数
	BYTE   byCertificateNumber[NAME_LEN];  //证件号
	BYTE   byRes2[20];
}NET_VCA_HUMAN_ATTRIBUTE, *LPNET_VCA_HUMAN_ATTRIBUTE;

typedef struct tagNET_VCA_HUMANATTRIBUTE_COND
{
	BYTE   bySex; //性别：0-不启用，1-男，2-女
	BYTE   byCertificateType; //证件类型：0-不启用，1-身份证，2-警官证
	BYTE   byStartBirthDate[MAX_HUMAN_BIRTHDATE_LEN]; //起始出生年月，如：201106
	BYTE   byEndBirthDate[MAX_HUMAN_BIRTHDATE_LEN]; //截止出生年月，如201106
	BYTE   byName[NAME_LEN]; //姓名
	NET_DVR_AREAINFOCFG struNativePlace; //籍贯参数
	BYTE   byCertificateNumber[NAME_LEN];  //证件号
	BYTE   byRes[20];
}NET_VCA_HUMANATTRIBUTE_COND, *LPNET_VCA_HUMANATTRIBUTE_COND;


typedef struct tagNET_VCA_BLACKLIST_INFO
{
	DWORD  dwSize;   //结构大小
	DWORD  dwRegisterID;  //名单注册ID号（只读）
	DWORD  dwGroupNo; //分组号
	BYTE   byType; //黑白名单标志：0-全部，1-白名单，2-黑名单
	BYTE   byLevel; //黑名单等级，0-全部，1-低，2-中，3-高
	BYTE   byRes1[2];  //保留
	NET_VCA_HUMAN_ATTRIBUTE struAttribute;  //人员信息
	BYTE   byRemark[NAME_LEN]; //备注信息
	BYTE   byRes2[20];
}NET_VCA_BLACKLIST_INFO, *LPNET_VCA_BLACKLIST_INFO;

typedef struct tagNET_VCA_BLACKLIST_PARA
{
    DWORD dwSize;   //结构大小
	NET_VCA_BLACKLIST_INFO struBlackListInfo;  //黑名单基本参数
	DWORD dwRegisterPicNum;  //黑名单图个数
	NET_VCA_PICMODEL_RESULT struRegisterPic[MAX_HUMAN_PICTURE_NUM];  //黑名单图片信息
	BYTE  byRes[40]; //保留
}NET_VCA_BLACKLIST_PARA, *LPNET_VCA_BLACKLIST_PARA;

typedef struct tagNET_VCA_BLACKLIST_COND
{
    LONG  lChannel; //通道号
	DWORD dwGroupNo; //分组号
	BYTE  byType; //黑白名单标志：0-全部，1-白名单，2-黑名单
	BYTE  byLevel; //黑名单等级，0-全部，1-低，2-中，3-高
	BYTE  byRes1[2];  //保留
	NET_VCA_HUMAN_ATTRIBUTE struAttribute; //人员信息
	BYTE  byRes[20];
}NET_VCA_BLACKLIST_COND, *LPNET_VCA_BLACKLIST_COND;

typedef struct tagNET_VCA_BLACKLIST_PIC
{
    DWORD dwSize;   //结构大小
	DWORD dwFacePicNum;  //人脸图个数
	BYTE  byRes[20]; //保留
	NET_VCA_PICMODEL_RESULT  struBlackListPic[MAX_HUMAN_PICTURE_NUM];  //单张照片信息
}NET_VCA_BLACKLIST_PIC, *LPNET_VCA_BLACKLIST_PIC;

typedef struct tagNET_VCA_FIND_PICTURECOND
{
    LONG lChannel;//通道号
    NET_DVR_TIME struStartTime;//开始时间
	NET_DVR_TIME struStopTime;//结束时间
	BYTE byRes[12]; //保留
}NET_VCA_FIND_PICTURECOND, *LPNET_VCA_FIND_PICTURECOND;

#define MAX_FACE_PIC_LEN   6144   //最大人脸图片数据长度
typedef struct tagNET_VCA_SUB_SNAPPIC_DATA
{
	DWORD dwFacePicID; //人脸图ID
	DWORD dwFacePicLen;  //人脸图数据长度
	NET_DVR_TIME struSnapTime;  //抓拍时间
	DWORD dwSimilarity; //相似度
	BYTE  byRes[16];  //保留
	char  sPicBuf[MAX_FACE_PIC_LEN];  //图片数据
}NET_VCA_SUB_SNAPPIC_DATA, *LPNET_VCA_SUB_SNAPPIC_DATA;

typedef struct tagNET_VCA_ADVANCE_FIND
{
	DWORD dwFacePicID; //人脸图片ID
	BYTE  byRes[36];
}NET_VCA_ADVANCE_FIND, *LPNET_VCA_ADVANCE_FIND;

typedef struct tagNET_VCA_NORMAL_FIND
{
	DWORD dwImageID; //大图ID
	DWORD dwFaceScore;  //人脸评分
	NET_VCA_RECT struVcaRect; //人脸子图区域
	BYTE byRes[20];
}NET_VCA_NORMAL_FIND, *LPNET_VCA_NORMAL_FIND;

typedef union tagNET_VCA_FIND_SNAPPIC_UNION
{
	NET_VCA_NORMAL_FIND  struNormalFind; //普通检索
    NET_VCA_ADVANCE_FIND struAdvanceFind; //高级检索
}NET_VCA_FIND_SNAPPIC_UNION, *LPNET_VCA_FIND_SNAPPIC_UNION;

typedef enum _VCA_FIND_SNAPPIC_TYPE_
{
    VCA_NORMAL_FIND  = 0x00000000,   //普通检索
	VCA_ADVANCE_FIND  = 0x00000001  //高级检索
}VCA_FIND_SNAPPIC_TYPE;

typedef struct tagNET_VCA_FIND_PICTURECOND_ADVANCE
{
    LONG lChannel;//通道号
    NET_DVR_TIME struStartTime;//开始时间
	NET_DVR_TIME struStopTime;//结束时间
	BYTE byThreshold;  //阈值，0-100
	BYTE byRes[23]; //保留
	VCA_FIND_SNAPPIC_TYPE dwFindType;//检索类型，详见VCA_FIND_SNAPPIC_TYPE
	NET_VCA_FIND_SNAPPIC_UNION uFindParam; //检索参数
}NET_VCA_FIND_PICTURECOND_ADVANCE, *LPNET_VCA_FIND_PICTURECOND_ADVANCE;

typedef struct tagNET_VCA_FACESNAP_INFO_ALARM
{
	DWORD dwRelativeTime;     // 相对时标
	DWORD dwAbsTime;			// 绝对时标
    DWORD dwSnapFacePicID;       //抓拍人脸图ID
	DWORD dwSnapFacePicLen;		//抓拍人脸子图的长度，为0表示没有图片，大于0表示有图片
	NET_VCA_DEV_INFO struDevInfo;		//前端设备信息
   	BYTE  byRes[20];              // 保留字节
	BYTE  *pBuffer1;  //抓拍人脸子图的图片数据
}NET_VCA_FACESNAP_INFO_ALARM, *LPNET_VCA_FACESNAP_INFO_ALARM;

typedef struct tagNET_VCA_BLACKLIST_INFO_ALARM
{
	NET_VCA_BLACKLIST_INFO struBlackListInfo; //黑名单基本信息
    DWORD dwBlackListPicLen;       //黑名单人脸子图的长度，为0表示没有图片，大于0表示有图片
   	BYTE  byRes[20];              // 保留字节
	BYTE  *pBuffer1;  //黑名单人脸子图的图片数据
}NET_VCA_BLACKLIST_INFO_ALARM, *LPNET_VCA_BLACKLIST_INFO_ALARM;

typedef struct tagNET_VCA_FACESNAP_MATCH_ALARM
{
	DWORD dwSize;     		// 结构大小
    float fSimilarity; //相似度，[0.001,1]
	NET_VCA_FACESNAP_INFO_ALARM  struSnapInfo; //抓拍信息
    NET_VCA_BLACKLIST_INFO_ALARM struBlackListInfo; //黑名单信息
	BYTE  byRes[60];              // 保留字节
}NET_VCA_FACESNAP_MATCH_ALARM, *LPNET_VCA_FACESNAP_MATCH_ALARM;


typedef struct tagNET_VCA_BLACKLIST_INFO_ALARM_LOG
{
	NET_VCA_BLACKLIST_INFO struBlackListInfo; //黑名单基本信息
    DWORD dwBlackListPicID;       //黑名单人脸子图ID，用于查找图片
   	BYTE  byRes[20];              // 保留字节
}NET_VCA_BLACKLIST_INFO_ALARM_LOG, *LPNET_VCA_BLACKLIST_INFO_ALARM_LOG;

typedef struct tagNET_VCA_FACESNAP_INFO_ALARM_LOG
{
	DWORD dwRelativeTime;     // 相对时标
	DWORD dwAbsTime;			// 绝对时标
    DWORD dwSnapFacePicID;       //抓拍人脸图ID
	NET_VCA_DEV_INFO  	 struDevInfo;		//前端设备信息
   	BYTE  byRes[20];              // 保留字节
}NET_VCA_FACESNAP_INFO_ALARM_LOG, *LPNET_VCA_FACESNAP_INFO_ALARM_LOG;

typedef struct tagNET_VCA_FACESNAP_MATCH_ALARM_LOG
{
	DWORD dwSize;     		// 结构大小
    float fSimilarity; //相似度，[0.001,1]
	NET_VCA_FACESNAP_INFO_ALARM_LOG  struSnapInfoLog; //抓拍信息
    NET_VCA_BLACKLIST_INFO_ALARM_LOG struBlackListInfoLog; //黑名单信息
	BYTE  byRes[60];              // 保留字节
}NET_VCA_FACESNAP_MATCH_ALARM_LOG, *LPNET_VCA_FACESNAP_MATCH_ALARM_LOG;

typedef struct tagNET_VCA_FACEMATCH_PICCOND
{
	DWORD dwSize;     		// 结构大小
   	DWORD dwSnapFaceID; //抓拍人脸子图ID
	DWORD dwBlackListID; //匹配的黑名单ID
	DWORD dwBlackListFaceID; //比对的黑名单人脸子图ID
	BYTE  byRes[20];              // 保留字节
}NET_VCA_FACEMATCH_PICCOND, *LPNET_VCA_FACEMATCH_PICCOND;

typedef struct tagNET_VCA_FACEMATCH_PICTURE
{
	DWORD dwSize;     		// 结构大小
   	DWORD dwSnapFaceLen; //抓拍人脸子图长度
	DWORD dwBlackListFaceLen; //比对的黑名单人脸子图长度
	BYTE  byRes[20];              //保留字节
	BYTE *pSnapFace;  //抓拍人脸子图的图片数据
	BYTE *pBlackListFace;  //比对的黑名单人脸子图数据
}NET_VCA_FACEMATCH_PICTURE, *LPNET_VCA_FACEMATCH_PICTURE;

typedef struct tagNET_VCA_BLACKLIST_FASTREGISTER_PARA
{
    DWORD dwSize;   //结构大小
	NET_VCA_BLACKLIST_INFO struBlackListInfo;  //黑名单基本参数
	DWORD dwImageLen;  //图像数据长度
	BYTE  byRes[124];  //保留
	BYTE  *pImage;    //图像数据
}NET_VCA_BLACKLIST_FASTREGISTER_PARA, *LPNET_VCA_BLACKLIST_FASTREGISTER_PARA;

//单个分区配置
typedef struct tagNET_VCA_SINGLE_PATH
{
	BYTE  byActive;  // 是否可用,0-否,1-是 
	BYTE  byType;   //0-存储抓拍，1-存储黑名单比对报警，2-存储抓拍和黑名单比对报警，0xff-无效
	BYTE  bySaveAlarmPic; //是否用于保存断网的报警图片，0-否，1-是
	BYTE  byRes1[5]; //保留
	DWORD dwDiskDriver;   //盘符号，从0开始
	DWORD dwLeftSpace;   //预留容量（单位为G）
	BYTE  byRes2[8]; //保留
}NET_VCA_SINGLE_PATH, *LPNET_VCA_SINGLE_PATH;

//存储路径设置
typedef struct tagNET_VCA_SAVE_PATH_CFG
{ 
	DWORD dwSize;   //结构大小
	NET_VCA_SINGLE_PATH  struPathInfo[MAX_DISKNUM_V30]; //单个分区
	BYTE  byRes[40]; //保留
}NET_VCA_SAVE_PATH_CFG, *LPNET_VCA_SAVE_PATH_CFG;

typedef struct tagNET_DVR_DEV_ACCESS_CFG
{
    DWORD   dwSize;
    NET_DVR_IPADDR 	struIP;		//接入设备的IP地址
    WORD 	wDevicePort;			 	//端口号
	BYTE	byEnable;		         //是否启用，0-否，1-是
	BYTE 	byRes1;				//保留
    BYTE	sUserName[NAME_LEN];	//接入设备的登录帐号
	BYTE	sPassword[PASSWD_LEN];	//接入设备的登录密码
	BYTE	byRes2[60];
}NET_DVR_DEV_ACCESS_CFG,*LPNET_DVR_DEV_ACCESS_CFG;

/********************************智能人脸识别 end****************************/
//分辨率
#define MAKE_RESOLUTION(_interlace_, _width_, _height_, _fps_) \
	(((_interlace_)<<28) \
	|((((_width_)>>3)&0x1ff)<<19)| \
	((((_height_)>>1)&0x7ff)<<8)| \
((_fps_)&0xff))
#define GET_RES_INTERLACE(_res_) \
(((_res_)>>28)&0x1)
#define GET_RES_WIDTH(_res_) \
((((_res_)>>19)&0x1ff)<<3)
#define GET_RES_HEIGHT(_res_) \
((((_res_)>>8)&0x7ff)<<1)
#define GET_RES_FPS(_res_) \
((_res_)&0xff)

#define NOT_AVALIABLE	MAKE_RESOLUTION (0,0,0,0)
#define SVGA_60HZ 		MAKE_RESOLUTION(0, 800, 600, 60)
#define SVGA_75HZ 		MAKE_RESOLUTION(0, 800, 600, 75)
#define XGA_60HZ 		MAKE_RESOLUTION(0, 1024, 768, 60) 
#define XGA_75HZ 		MAKE_RESOLUTION(0, 1024, 768, 75)
#define SXGA_60HZ  		MAKE_RESOLUTION(0, 1280, 1024, 60)
#define SXGA2_60HZ  	MAKE_RESOLUTION(0, 1280, 960, 60) 
#define _720P_60HZ  	MAKE_RESOLUTION(0, 1280, 720, 60)
#define _720P_50HZ  	MAKE_RESOLUTION(0, 1280, 720, 50) 
#define _1080I_60HZ 	MAKE_RESOLUTION(1, 1920, 1080, 60)
#define _1080I_50HZ  	MAKE_RESOLUTION(1, 1920, 1080, 50)
#define _1080P_60HZ 	MAKE_RESOLUTION(0, 1920, 1080, 60)
#define _1080P_50HZ 	MAKE_RESOLUTION(0, 1920, 1080, 50)
#define _1080P_30HZ 	MAKE_RESOLUTION(0, 1920, 1080, 30)
#define _1080P_25HZ 	MAKE_RESOLUTION(0, 1920, 1080, 25)
#define _1080P_24HZ 	MAKE_RESOLUTION(0, 1920, 1080, 24)
#define UXGA_60HZ  		MAKE_RESOLUTION(0, 1600, 1200, 60)
#define UXGA_30HZ  		MAKE_RESOLUTION(0, 1600, 1200, 30)
#define WSXGA_60HZ 		MAKE_RESOLUTION(0, 1680, 1050, 60)
#define WUXGA_60HZ  	MAKE_RESOLUTION(0, 1920, 1200, 60)
#define WUXGA_30HZ 		MAKE_RESOLUTION(0, 1920, 1200, 30)
#define WXGA_60HZ  		MAKE_RESOLUTION(0, 1360, 768, 60)
#define SXGA_PLUS_60HZ	MAKE_RESOLUTION(0, 1400, 1050, 60)


//显示通道画面分割模式
#define  MAX_WINDOWS_NUM 12		//画面分割模式的数量
#define  MAX_SUPPORT_RES 32
#define  MAX_DISPNUM_V41 32

typedef struct tagNET_DVR_DISPWINDOWMODE
{
    BYTE byDispChanType;//显示通道类型：0-BNC, 1-VGA, 2-HDMI, 3-DVI
    BYTE byDispChanSeq;//显示通道序号,从1开始，如果类型是VGA，则表示第几个VGA
    BYTE byRes[2];
    BYTE byDispMode[MAX_WINDOWS_NUM/*12*/];
}NET_DVR_DISPWINDOWMODE, *LPNET_DVR_DISPWINDOWMODE;

typedef struct tagNET_DVR_DISPINFO
{
    BYTE  byChanNums;//通道个数
    BYTE  byStartChan;//起始通道
    BYTE  byRes[2];
    DWORD	dwSupportResolution[MAX_SUPPORT_RES/*32*/];//支持分辨率
}NET_DVR_DISPINFO, *LPNET_DVR_DISPINFO;

//大屏拼接信息
typedef struct tagNET_DVR_SCREENINFO
{
	BYTE  bySupportBigScreenNums;//最多大屏拼接数量
	BYTE  byStartBigScreenNum;//大屏拼接起始号
	BYTE  byMaxScreenX;//大屏拼接模式
	BYTE  byMaxScreenY;
	BYTE  byRes[8];
}NET_DVR_SCREENINFO, *LPNET_DVR_SCREENINFO;

typedef struct tagNET_DVR_MATRIX_ABILITY_V41
{
	DWORD dwSize;
	BYTE  byDspNums;//DSP个数  
    BYTE  byDecChanNums;//解码通道数
	BYTE  byStartChan;//起始解码通道
	BYTE  byRes1[5];
	NET_DVR_DISPINFO struVgaInfo;//VGA显示通道信息
	NET_DVR_DISPINFO struBncInfo;//BNC显示通道信息
	NET_DVR_DISPINFO struHdmiInfo;//HDMI显示通道信息
	NET_DVR_DISPINFO struDviInfo;//DVI显示通道信息
	NET_DVR_DISPWINDOWMODE struDispMode[MAX_DISPNUM_V41/*32*/];
	NET_DVR_SCREENINFO struBigScreenInfo;
	BYTE  bySupportAutoReboot; //是否支持自动重启，0-不支持，1-支持
	BYTE  byRes2[119];
} NET_DVR_MATRIX_ABILITY_V41, *LPNET_DVR_MATRIX_ABILITY_V41;

//显示通道配置
#define  MAX_WINDOWS			    16
#define  MAX_WINDOWS_V41			36

#define  STARTDISPCHAN_VGA		1
#define  STARTDISPCHAN_BNC		9
#define  STARTDISPCHAN_HDMI		25
#define  STARTDISPCHAN_DVI		29

typedef union tagNET_DVR_VIDEO_PLATFORM
{
	BYTE byRes[160];
	struct
	{
		/*各个子窗口对应解码通道所对应的解码子系统的槽位号(对于视频综合平台中解码子系统有效)*/
		//如果综合平台支持自动分配解码资源，此参数不需要填充
		BYTE	byJoinDecoderId[MAX_WINDOWS_V41];
		//显示窗口所解视频分辨率，1-D1,2-720P,3-1080P，设备端需要根据此分辨率进行解码通道的分配，如1分屏配置成1080P，则设备会把4个解码通道都分配给此解码通道
		BYTE	byDecResolution[MAX_WINDOWS_V41];
		NET_DVR_RECTCFG struPosition; //显示通道在电视墙中位置
		BYTE	byRes[80];
	}struVideoPlatform;
	struct
	{
		BYTE	byRes[160];
	}struNotVideoPlatform;
}NET_DVR_VIDEO_PLATFORM, LPNET_DVR_VIDEO_PLATFORM;


typedef struct tagNET_DVR_MATRIX_VOUTCFG
{        
    DWORD	dwSize; 
    BYTE	byAudio;			/*音频是否开启*/
    BYTE	byAudioWindowIdx;      /*音频开启子窗口*/
    BYTE	byDispChanType;      /*显示通道类型：0-BNC，1-VGA，2-HDMI，3-DVI，4-YPbPr(解码卡服务器DECODER_SERVER专用)*/   
    BYTE	byVedioFormat;         /*1:NTSC,2:PAL，0-NULL*/
	DWORD	dwResolution;//分辨率
    DWORD	dwWindowMode;		/*画面模式，能力集获取*/       
    BYTE	byJoinDecChan[MAX_WINDOWS_V41];/*各个子窗口关联的解码通道,设备支持解码资源自动分配时此参数不用填充*/
	BYTE	byEnlargeStatus;          /*是否处于放大状态，0：不放大，1：放大*/
	BYTE	byEnlargeSubWindowIndex;//放大的子窗口号
	BYTE	byScale; /*显示模式，0---真实显示，1---缩放显示( 针对BNC )*/
	BYTE	byUnionType;/*区分共用体,0-视频综合平台内部解码器显示通道配置，1-其他解码器显示通道配置*/
	NET_DVR_VIDEO_PLATFORM		struDiff;
    DWORD   dwDispChanNum; //显示输出号，此参数在全部获取时有效
	BYTE	byRes2[76];
}NET_DVR_MATRIX_VOUTCFG,*LPNET_DVR_MATRIX_VOUTCFG;

/*解码器设备状态*/
typedef struct tagNET_DVR_DISP_CHAN_STATUS_V41
{
    BYTE  byDispStatus;      /*显示状态：0：未显示，1：启动显示*/
    BYTE  byBVGA;              /*0-BNC，1-VGA， 2-HDMI，3-DVI，0xff-无效*/
    BYTE  byVideoFormat;     /*视频制式，1:NTSC,2:PAL,0-NON*/
    BYTE  byWindowMode;       /*画面模式*/
    BYTE  byJoinDecChan[MAX_WINDOWS_V41];   /*各个子画面关联的解码通道*/
    BYTE  byFpsDisp[MAX_WINDOWS_V41];        /*每个子画面的显示帧率*/
    BYTE  byScreenMode;		/*屏幕模式0-普通 1-大屏*/
    BYTE  byRes1[3];
    DWORD  dwDispChan; /*获取全部显示通道状态时有效，设置时可填0*/
    BYTE  byRes2[24];                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          
}NET_DVR_DISP_CHAN_STATUS_V41, *LPNET_DVR_DISP_CHAN_STATUS_V41;

/*解码器设备状态*/
typedef struct tagNET_DVR_DECODER_WORK_STATUS_V41
{
    DWORD dwSize;
	NET_DVR_MATRIX_CHAN_STATUS struDecChanStatus[32];     /*解码通道状态*/
	/*显示通道状态*/
    NET_DVR_DISP_CHAN_STATUS_V41   struDispChanStatus[MAX_DISPNUM_V41/*32*/];     
    BYTE byAlarmInStatus[32];         /*报警输入状态*/
    BYTE byAlarmOutStatus[32];       /*报警输出状态*/
    BYTE byAudioInChanStatus;          /*语音对讲状态*/
    BYTE byRes[127];
}NET_DVR_DECODER_WORK_STATUS_V41,*LPNET_DVR_DECODER_WORK_STATUS_V41;
/*******************************文件回放-远程回放设置*******************************/
typedef struct tagNET_DVR_MATRIX_DEC_REMOTE_PLAY_V41
{
    DWORD	dwSize;
    NET_DVR_IPADDR	struIP;		/* DVR IP地址 */	
    WORD	wDVRPort;			/* 端口号 */	
    BYTE	byChannel;			/* 通道号 */
    BYTE 	byReserve;
    BYTE	sUserName[NAME_LEN];		/* 用户名 */
    BYTE	sPassword[PASSWD_LEN];		/* 密码 */
    DWORD	dwPlayMode;   	/* 0－按文件 1－按时间*/        	
    NET_DVR_TIME StartTime;
    NET_DVR_TIME StopTime;
    char    sFileName[128];
    BYTE	byRes[64];		/*保留*/
}NET_DVR_MATRIX_DEC_REMOTE_PLAY_V41, *LPNET_DVR_MATRIX_DEC_REMOTE_PLAY_V41;


#define  MAX_BIGSCREENNUM_SCENE 100
#define  MAX_LAYERNUMS	32

//显示通道配置结构
typedef struct tagNET_DVR_RECTCFG_SCENE
{
	WORD wXCoordinate; /*矩形左上角起始点X坐标*/
	WORD wYCoordinate; /*矩形左上角Y坐标*/
	WORD wWidth;       /*矩形宽度*/
	WORD wHeight;      /*矩形高度*/
}NET_DVR_RECTCFG_SCENE, *LPNET_DVR_RECTCFGSCENE;

typedef struct tagNET_DVR_SCENEDISPCFG
{       
	BYTE	byEnable;//是否启用，0-不启用，1-启用
	BYTE	bySoltNum;//槽位号
	BYTE	byRes1[2]; 
    BYTE	byDispChanNum; 
    BYTE	byAudio;				/*音频是否开启,0-否，1-是*/
    BYTE	byAudioWindowIdx;      /*音频开启子窗口*/
	BYTE	byVedioFormat;          /*1:NTSC,2:PAL，0-NULL*/
	BYTE	byWindowMode;			/*画面模式，从能力集获取*/   
	BYTE	byEnlargeStatus;         /*是否处于放大状态，0：不放大，1：放大*/
	BYTE    byEnlargeSubWindowIndex;//放大的子窗口号    
	BYTE	byScale; /*显示模式，0-真实显示，1-缩放显示( 针对BNC )*/
	DWORD   dwResolution;//分辨率
	BYTE	byJoinDecChan[MAX_WINDOWS_V41];/*各个子窗口关联的解码通道*/
	BYTE	byJoinDecoderId[MAX_WINDOWS_V41];/*槽位号*/
	//显示窗口所解视频分辨率，1-D1,2-720P,3-1080P，设备端需要根据此//分辨率进行解码通道的分配，如1分屏配置成1080P，则设备会把4个解码通道都分配给此解码通道
	BYTE	byDecResolution[MAX_WINDOWS_V41];
	BYTE	byRow;//大屏所在的行的序号
	BYTE	byColumn;//大屏所在的列的序号
    BYTE	byRes2[5];
	NET_DVR_RECTCFG struDisp; //电视墙显示位置
} NET_DVR_SCENEDISPCFG,*LPNET_DVR_SCENEDISPCFG;

typedef struct tagDEV_CHAN_INFO_SCENE
{
	NET_DVR_IPADDR struIP;				/* DVR IP地址 */
	WORD 	wDVRPort;			 	/* 端口号 */
	BYTE 	byChannel;		/* 通道号，对于9000等设备的IPC接入，通道号从33开始 */
	BYTE	byTransProtocol;		/* 传输协议类型0-TCP，1-UDP ，2-MCAST，3-RTP*/
	BYTE	byTransMode;			/* 传输码流模式 0－主码流 1－子码流*/
	BYTE	byFactoryType;				/*前端设备厂家类型*/
	BYTE	byDeviceType;			//设备类型，1-IPC，2- ENCODER
    BYTE	byRes[5];
	BYTE	sUserName[NAME_LEN];	/* 监控主机登陆帐号 */
	BYTE	sPassword[PASSWD_LEN];	/* 监控主机密码 */
} NET_DVR_DEV_CHAN_INFO_SCENE,*LPNET_DVR_DEV_CHAN_INFO_SCENE;

/*流媒体服务器基本配置*/
typedef struct tagSTREAM_MEDIA_SERVER_CFG_SCENE
{
	BYTE	byValid;			/*是否启用流媒体服务器取流,0表示无效*/
	BYTE	byRes1[3];
	NET_DVR_IPADDR struDevIP;	/*流媒体服务器地址*/
	WORD	wDevPort;			/*流媒体服务器端口*/
	BYTE	byTransmitType;		/*传输协议类型0-TCP，1-UDP */
	BYTE	byRes2[5];
}NET_DVR_STREAM_MEDIA_SERVER_CFG_SCENE,*LPNET_DVR_STREAM_MEDIA_SERVER_CFG_SCENE;

typedef struct tagPU_STREAM_CFG_SCENE
{
	NET_DVR_STREAM_MEDIA_SERVER_CFG_SCENE	streamMediaServerCfg;
	NET_DVR_DEV_CHAN_INFO_SCENE				struDevChanInfo;
}NET_DVR_PU_STREAM_CFG_SCENE,*LPNET_DVR_PU_STREAM_CFG_SCENE;

typedef struct  tagNET_DVR_CYC_SUR_CHAN_ELE_SCENE
{
	BYTE							byEnable;	/* 是否启用 0－否 1－启用*/
	BYTE							byRes[3];
	NET_DVR_STREAM_MEDIA_SERVER_CFG_SCENE	struStreamMediaSvrCfg;	
    NET_DVR_DEV_CHAN_INFO_SCENE			struDecChanInfo;	/*轮巡解码通道信息*/
}NET_DVR_CYC_SUR_CHAN_ELE_SCENE,*LPNET_DVR_CYC_SUR_CHAN_ELE_SCENE;

//轮巡解码结构
typedef struct  tagNET_DVR_MATRIX_LOOP_DECINFO_SCENE
{
	WORD	wPoolTime;		/*轮询间隔*/
	BYTE	byRes1[2];
    NET_DVR_CYC_SUR_CHAN_ELE_SCENE	struChanArray[MAX_CYCLE_CHAN/*16*/];
    BYTE    byRes2[4];
} NET_DVR_MATRIX_LOOP_DECINFO_SCENE,*LPNET_DVR_MATRIX_LOOP_DECINFO_SCENE;

//单个解码通道配置结构体
typedef struct tagNET_DVR_DECODECHANCFG_SCENE/*struct size : 2064*/
{
	BYTE	byDecodeEnable;//解码起停标志，0-停止，1-启用动态解码，2-启用轮巡解码
	BYTE	bySlotNum;//槽位号
	BYTE	byDecChan;
	BYTE	byJointAllDecodeChan;		//是否关联万能解码通道 0-不关联，1-关联
	BYTE	byJointSlotNum;			//关联的槽位号（万能解码板的槽位号）
	BYTE	byJointChanNum;		//关联的通道号（万能解码板通道号）
	BYTE    byRes[2];
	union
	{
		NET_DVR_PU_STREAM_CFG_SCENE struSceneDynamicDecCfg; 
		NET_DVR_MATRIX_LOOP_DECINFO_SCENE struSceneCycDecCfg;
	 } struDecCfg;
}NET_DVR_DECODECHANCFG_SCENE,*LPNET_DVR_DECODECHANCFG_SCENE;

typedef struct tagNET_DVR_BIGSCREENCFG_SCENE
{
    BYTE byAllValid; /*漫游使能标志 */
    BYTE byAssociateBaseMap;//关联的底图序号，0代表不关联
    BYTE byEnableSpartan;//大屏畅显使能，1-开，0-关
	BYTE byRes;
    NET_DVR_WINCFG struWinCfg[MAX_LAYERNUMS];
    NET_DVR_BIGSCREENCFG struBigScreen;
}NET_DVR_BIGSCREENCFG_SCENE, *LPNET_DVR_BIGSCREENCFG_SCENE;

typedef struct tagNET_DVR_MATRIX_SCENECFG
{
    DWORD dwSize;
    BYTE  sSceneName[NAME_LEN];
    BYTE  byBigScreenNums;//大屏的个数，最大值通过能力集获取
    BYTE  byRes1[3];
    WORD  wDecChanNums;//场景中解码通道的个数
    WORD  wDispChanNums;//场景中显示通道的个数
    BYTE  byRes2[12];
    BYTE  *pBigScreenBuffer;//大屏配置缓冲区, byBigScreenNums×sizeof(NET_DVR_BIGSCREENCFG_SCENE)
    BYTE  *pDecChanBuffer;//解码通道配置缓冲区, wDecChanNums×sizeof(NET_DVR_DECODECHANCFG_SCENE)
    BYTE  *pDispChanBuffer;//显示通道配置缓冲区, wDispChanNums×sizeof(NET_DVR_SCENEDISPCFG)
}NET_DVR_MATRIX_SCENECFG, *LPNET_DVR_MATRIX_SCENECFG;

#define	NET_DVR_GET_ALLWINCFG		            1503 //窗口参数获取

typedef struct tagNET_DVR_BIGSCREENASSOCIATECFG
{
    DWORD dwSize;
    BYTE  byEnableBaseMap;//使能底图显示
    BYTE  byAssociateBaseMap;//关联的底图序号，0代表不关联
	BYTE  byEnableSpartan;//大屏畅显使能，1-开，0-关
    BYTE  byRes[21];
} NET_DVR_BIGSCREENASSOCIATECFG, *LPNET_DVR_BIGSCREENASSOCIATECFG;
/*******************************窗口设置*******************************/
#define MAX_WIN_COUNT  224 //支持的最大开窗数

typedef struct tagNET_DVR_SCREEN_WINCFG
{
	DWORD	dwSize;
	BYTE	byVaild;
	BYTE	byInputType;		//见CAM_MDOE
	WORD	wInputIdx;			/*输入源索引*/
    DWORD	dwLayerIdx;			/*图层，0为最底层*/
	NET_DVR_RECTCFG  struWin;	//目的窗口(相对显示墙)
	BYTE	byWndIndex;			//窗口号
	BYTE	byCBD;				//0-无，1-带背景，2-不带背景
	BYTE	bySubWnd;			//0不是，1是
	BYTE    byRes1;
	DWORD   dwDeviceIndex;//设备序号
	BYTE	byRes2[16];
}NET_DVR_SCREEN_WINCFG, *LPNET_DVR_SCREEN_WINCFG;

typedef struct tagNET_DVR_WINLIST
{
	DWORD	dwSize;
	WORD	wScreenSeq;	//设备序号
	BYTE	byRes[10];
	DWORD	dwWinNum;	//设备返回的窗口数量
	BYTE    *pBuffer;	//窗口信息缓冲区，最大为224*sizeof(NET_DVR_WINCFG)
	DWORD   dwBufLen;	//所分配指针长度
}NET_DVR_WINLIST,*LPNET_DVR_WINLIST;

#define MAX_LAYOUT_COUNT 16		//最大布局数
typedef struct tagNET_DVR_LAYOUTCFG
{
	DWORD dwSize;
    BYTE  byValid;								//布局是否有效
    BYTE  byRes1[3];
    BYTE  byLayoutName[NAME_LEN/*32*/];			//布局名称			
	NET_DVR_SCREEN_WINCFG struWinCfg[MAX_WIN_COUNT/*224*/];	//布局内窗口参数
	BYTE  byRes2[16];
}NET_DVR_LAYOUTCFG, *LPNET_DVR_LAYOUTCFG;

typedef struct tagNET_DVR_LAYOUT_LIST
{
    DWORD dwSize;
    NET_DVR_LAYOUTCFG struLayoutInfo[MAX_LAYOUT_COUNT/*16*/];   //所有布局
    BYTE byRes[4];
}NET_DVR_LAYOUT_LIST, *LPNET_DVR_LAYOUT_LIST;

#define MAX_CAM_COUNT  224

typedef enum tagNET_DVR_CAM_MODE
{
	NET_DVR_UNKNOW  = 0,//无效
	NET_DVR_CAM_BNC,
	NET_DVR_CAM_VGA,
	NET_DVR_CAM_DVI,
	NET_DVR_CAM_HDMI,
	NET_DVR_CAM_IP,
	NET_DVR_CAM_RGB,
    NET_DVR_CAM_DECODER,
	NET_DVR_CAM_MATRIX,
	NET_DVR_CAM_YPBPR,
	NET_DVR_CAM_USB,
}NET_DVR_CAM_MODE;

typedef struct tagNET_DVR_INPUTSTREAMCFG
{
	DWORD	dwSize ;
	BYTE	byValid ;
	BYTE	byCamMode;						//信号输入源类型，见NET_DVR_CAM_MODE
    WORD	wInputNo;						//信号源序号0-224
    BYTE	sCamName[NAME_LEN] ;			//信号输入源名称
	NET_DVR_VIDEOEFFECT struVideoEffect;	//视频参数
	NET_DVR_PU_STREAM_CFG	struPuStream;	//ip输入时使用
	WORD	wBoardNum ;						//信号源所在的板卡号
	WORD	wInputIdxOnBoard;				//信号源在板卡上的位置
	WORD	wResolutionX;					//分辨率
	WORD	wResolutionY;
	BYTE	byVideoFormat;					//视频制式，0-无，1-NTSC，2-PAL
    BYTE	byNetSignalResolution;	//; 1-CIF 2-4CIF 3-720P 4-1080P 5-500wp 。网络信号源的分辨率，在添加网络信号源时传给设备，设备根据这个分辨率来分配解码资源。
    BYTE	sGroupName[NAME_LEN/*32*/];	//网络信号源分组 组名
	BYTE	byJointMatrix;			//  关联矩阵 ，0-不关联  1-关联
	BYTE	byRes;  
}NET_DVR_INPUTSTREAMCFG, *LPNET_DVR_INPUTSTREAMCFG;

typedef struct tagNET_DVR_INPUTSTREAM_LIST
{
    DWORD dwSize;
    NET_DVR_INPUTSTREAMCFG struInputStreamInfo[MAX_CAM_COUNT]; //所有信号源
    BYTE byRes[4];
}NET_DVR_INPUTSTREAM_LIST, *LPNET_DVR_INPUTSTREAM_LIST;

/*******************************输出参数配置*******************************/
/*输出通道管理*/
typedef struct tagNET_DVR_OUTPUTPARAM
{
	DWORD  dwSize;
	BYTE   byMonMode;		/*输出连接模式,1-BNC,2-VGA,3-DVI,4-HDMI*/
	BYTE   byRes1[3];
	DWORD  dwResolution;	/*分辨率，根据能力集获取所支持的进行设置*/;
	NET_DVR_VIDEOEFFECT  struVideoEffect;	/*输出通道视频参数配置*/
	BYTE	byRes2[32];
}NET_DVR_OUTPUTPARAM, *LPNET_DVR_OUTPUTPARAM;

typedef struct tagNET_DVR_OUTPUTCFG
{
	DWORD	dwSize;
	BYTE	byScreenLayX;						//大屏布局-横坐标
	BYTE	byScreenLayY;						//大屏布局-纵坐标
	WORD	wOutputChanNum;					//输出通道个数，0表示设备支持的最大输出通道个数，最大个数从能力集获取，其他值表示实际输出通道个数
	BYTE	byRes1[4];
	NET_DVR_OUTPUTPARAM  struOutputParam;	/*输出通道视频参数配置*/
	BYTE	sWallName[16];					//电视墙名称
	BYTE	byRes2[8];
}NET_DVR_OUTPUTCFG, *LPNET_DVR_OUTPUTCFG;

/*******************************能力集*******************************/
#define SCREEN_PROTOCOL_NUM  	20    //支持的最大大屏控制器协议数
//多屏服务器能力集
typedef struct tagNET_DVR_SCREENSERVER_ABILITY
{
    DWORD dwSize;   			/*结构长度*/
    BYTE byIsSupportScreenNum; /*所支持大屏控制器的数目*/
    BYTE bySerialNums;			//串口个数
    BYTE byMaxInputNums;
    BYTE byMaxLayoutNums;
    BYTE byMaxWinNums;
    BYTE byRes1[19];
    BYTE byMaxScreenLayX;//大屏布局-最大横坐标大屏数
    BYTE byMaxScreenLayY;//大屏布局-最大纵坐标大屏数
    WORD wMatrixProtoNum; /*有效的大屏协议数目*/
    NET_DVR_PROTO_TYPE struScreenProto[SCREEN_PROTOCOL_NUM];/*最大协议列表*/
    BYTE byRes2[24];
}NET_DVR_SCREENSERVER_ABILITY, *LPNET_DVR_SCREENSERVER_ABILITY;

//多屏控制器能力集
typedef struct tagNET_DVR_SCREENCONTROL_ABILITY
{
    DWORD dwSize;   		/*结构长度*/
	BYTE byLayoutNum; 		/* 布局个数*/
	BYTE byWinNum; 			/*屏幕窗口个数*/
	BYTE byOsdNum;  		/*OSD个数*/
	BYTE byLogoNum; 		/*Logo个数*/
	BYTE byInputStreamNum;  //输入源个数 ---设备支持最大输入通道个数（包括本地输入源和网络输入源）
	BYTE byOutputChanNum;	//输出通道个数---设备支持最大输出通道个数
	BYTE byCamGroupNum;		/*分组个数*/
	BYTE byPlanNum;    		/*预案个数*/
	BYTE byRes1[5];
    BYTE byIsSupportPlayBack;  /*是否支持回放*/	
    BYTE byMatrixInputNum;  //支持输入矩阵最大个数
    BYTE byMatrixOutputNum; //支持输出矩阵最大个数
    NET_DVR_DISPINFO struVgaInfo;//VGA输出信息
	NET_DVR_DISPINFO struBncInfo;//BNC输出信息
	NET_DVR_DISPINFO struHdmiInfo;//HDMI输出信息
	NET_DVR_DISPINFO struDviInfo;//DVI输出信息
	BYTE byMaxUserNums;//支持用户数
	BYTE byPicSpan;		//底图跨度，一张底图最多可覆盖的屏幕数
	WORD wDVCSDevNum;	//分布式大屏控制器最大设备数
    WORD wNetSignalNum;	//最大网络输入源个数
	WORD wBaseCoordinateX;//基准坐标
	WORD wBaseCoordinateY; 
	BYTE byExternalMatrixNum;	//最大外接矩阵个数
	BYTE byRes2[49];
}NET_DVR_SCREENCONTROL_ABILITY, *LPNET_DVR_SCREENCONTROL_ABILITY;

/*******************************输入信号状态*******************************/
typedef struct tagNET_DVR_ANALOGINPUTSTATUS
{
	DWORD	dwLostFrame;		/*视频输入丢帧数*/
	BYTE	byHaveSignal;		/*是否有视频信号输入*/
	BYTE	byVideoFormat;		/*视频制式，1：NTSC,2：PAL,0：无*/
	BYTE	byRes[46];
} NET_DVR_ANALOGINPUTSTATUS, *LPNET_DVR_ANALOGINPUTSTATUS;

typedef union tagNET_DVR_INPUTSTATUS_UNION
{
	NET_DVR_MATRIX_CHAN_STATUS struIpInputStatus;
	NET_DVR_ANALOGINPUTSTATUS struAnalogInputStatus;
} NET_DVR_INPUTSTATUS_UNION, *LPNET_DVR_INPUTSTATUS_UNION;

typedef struct tagNET_DVR_INPUTSTATUS
{
	WORD	wInputNo;		/*信号源序号*/
	BYTE	byInputType;	//见NET_DVR_CAM_MODE
	BYTE	byRes1[9];
	NET_DVR_INPUTSTATUS_UNION struStatusUnion;
	BYTE	byRes2[16];
} NET_DVR_INPUTSTATUS, *LPNET_DVR_INPUTSTATUS;

typedef struct tagNET_DVR_SCREENINPUTSTATUS
{
	DWORD	dwSize;
	BYTE	byRes[12];
	DWORD	dwNums;		//设备返回的输入源状态的数量
	BYTE    *pBuffer;	//缓冲区
	DWORD   dwBufLen;	//所分配指针长度，输入参数
}NET_DVR_SCREENINPUTSTATUS,*LPNET_DVR_SCREENINPUTSTATUS;

typedef struct tagNET_DVR_SCREENALARMCFG
{
	DWORD	dwSize;
    BYTE	byAlarmType;	//报警类型，1-子板拔出，2-子板插入，3-子系统状态异常，4-子系统恢复恢复 5-输入源异常   6-温度报警 7-FPGA版本不匹配 8-预案开始 9-预案结束 10-解码板断网 11-解码板IP地址冲突，12-风扇异常
	BYTE	byBoardType;	// 1-输入板 2-输出板 ，3-主板，4-背板，报警类型为1，2，3，6的时候使用 
	BYTE	bySubException;	//输入异常时具体子异常 1- 分辨率正常改变 2-输入端口类型改变3-分辨率错误4-分辨率改变导致解码资源不足，关闭该输入源对应窗口。5-分辨率改变，导致已开窗的缩放比例不在1/8到8倍范围。6-分辨率恢复正常,7-分辨率改变导致输出板数据量超限,设备关闭窗口 
	BYTE	byRes1;
    WORD	wStartInputNum; // 异常输入源（异常起点） 
	WORD	wEndInputNum;	// 异常输入源（异常终点） 
    BYTE	byRes2[16];	   
}NET_DVR_SCREENALARMCFG, *LPNET_DVR_SCREENALARMCFG;

typedef struct tagNET_DVR_MATRIX_CFG
{
    BYTE  byValid;				//判断是否是模拟矩阵（是否有效）
    BYTE  byCommandProtocol;	//模拟矩阵的指令（4种）
    BYTE  byScreenType;			//保留	
    BYTE  byRes1;
    BYTE  byScreenToMatrix[32];	//模拟矩阵的输出与屏幕的对应关系
    BYTE  byRes2[4];
}NET_DVR_MATRIX_CFG, *LPNET_DVR_MATRIX_CFG;

typedef struct tagNET_DVR_DIGITALSCREEN
{
    NET_DVR_IPADDR  struAddress;/*设备为数字设备时的IP信息*/
    WORD			wPort;		//通道号
    BYTE			byRes[26];  //保留
}NET_DVR_DIGITALSCREEN, *LPNET_DVR_DIGITALSCREEN;
typedef struct tagNET_DVR_ANALOGSCREEN
{
    BYTE	byDevSerPortNum;   /*连接设备的串口号*/
	BYTE    byScreenSerPort;  /*连接大屏的串口号*/
    BYTE	byRes[130];   
    NET_DVR_MATRIX_CFG struMatrixCfg;
}NET_DVR_ANALOGSCREEN, *LPNET_DVR_ANALOGSCREEN;

typedef union tagNET_DVR_SCREEN_UNION
{
    NET_DVR_DIGITALSCREEN struDigitalScreen;
    NET_DVR_ANALOGSCREEN struAnalogScreen;
}NET_DVR_SCREEN_UNION, *LPNET_DVR_SCREEN_UNION;
typedef struct tagNET_DVR_SCREEN_SCREENINFO
{
    DWORD dwSize;
    BYTE byValid;				//是否有效
    BYTE nLinkMode;				//连接方式，0-串口，1-网口
    BYTE byDeviceType;			//设备型号，能力集获取
    BYTE byScreenLayX;			//大屏布局-横坐标
    BYTE byScreenLayY;			//大屏布局-纵坐标
    BYTE byRes1[3];
    BYTE sUserName[NAME_LEN];	/*登录用户名*/
    BYTE sPassword[PASSWD_LEN]; /*登录密码*/   
	BYTE sDevName[NAME_LEN];	/*设备名称*/
    NET_DVR_SCREEN_UNION struScreenUnion;
    BYTE byInputNum;			// 输入源个数
	BYTE byOutputNum;			// 输出源个数
	BYTE byCBDNum;				//CBD个数
	BYTE byRes2[29];
} NET_DVR_SCREEN_SCREENINFO, *LPNET_DVR_SCREEN_SCREENINFO;

/*******************************底图上传*******************************/
typedef struct tagNET_DVR_BASEMAP_CFG
{	
    BYTE byScreenIndex;         //屏幕的序号
	BYTE byMapNum;				/*被分割成了多少块 */
    BYTE res[2];
	WORD wSourWidth;			/* 原图片的宽度 */
	WORD wSourHeight;			/* 原图片的高度 */
}NET_DVR_BASEMAP_CFG, LPNET_DVR_BASEMAP_CFG;


typedef struct tagNET_DVR_PICCFG
{
	DWORD	dwSize;		//大小
	BYTE	byUseType;	//1-底图，2-GIF图片，3-CAD图片
    BYTE    bySequence;//序号
	BYTE	byWallNo;		//电视墙号
	BYTE	byRes1;
	NET_DVR_BASEMAP_CFG	struBasemapCfg;
	BYTE	sPicName[NAME_LEN];//图片名称
	BYTE	byRes2[32];
}NET_DVR_PICTURECFG, *LPNET_DVR_PICTURECFG;

/*******************************OSD*******************************/
#define MAX_OSDCHAR_NUM 256
typedef struct tagNET_DVR_OSDCFG
{
	DWORD   dwSize;
	BYTE    byValid;    /*是否有效 0无效 1有效*/
    BYTE    byDispMode;  //显示模式，1-透明，2-半透明，3-覆盖三种模式
    BYTE    byFontColorY; /*字体颜色Y,0-255*/
    BYTE    byFontColorU; /*字体颜色U,0-255*/
    BYTE    byFontColorV; /*字体颜色V,0-255*/
    BYTE    byBackColorY; /*背景颜色Y,0-255*/
    BYTE    byBackColorU; /*背景颜色U,0-255*/
	BYTE    byBackColorV; /*背景颜色V,0-255*/
    WORD    wXCoordinate;   /*OSD在屏幕左上角位置x*/
    WORD    wYCoordinate;   /*OSD在屏幕左上角位置y*/
    WORD    wWidth;       /*OSD宽度*/
	WORD    wHeight;      /*OSD高度*/
	DWORD   dwCharCnt;     /*字符的个数*/
    WORD    wOSDChar[MAX_OSDCHAR_NUM];       /*OSD字符内容*/
	BYTE    byRes[32];
}NET_DVR_OSDCFG, *LPNET_DVR_OSDCFG;


/*******************************获取串口信息*******************************/
typedef struct tagNET_DVR_SERIAL_CONTROL
{ 
	DWORD	dwSize ;
	BYTE    bySerialNum;        // 串口个数
	BYTE	byRes1[3];
	BYTE    bySerial[32];
	BYTE    byRes2[32];
}NET_DVR_SERIAL_CONTROL, *LPNET_DVR_SERIAL_CONTROL;

/*******************************屏幕控制*******************************/
//屏幕输入源控制
typedef enum tagINPUT_INTERFACE_TYPE
{
	INTERFACE_VGA = 0,
	INTERFACE_SVIDEO, // 2046NL不支持，2046NH支持
	INTERFACE_YPBPR,
	INTERFACE_DVI ,
	INTERFACE_BNC , 
	INTERFACE_DVI_LOOP,//(环通) 2046NH不支持，2046NL支持
	INTERFACE_BNC_LOOP, //(环通) 2046NH不支持，2046NL.支持
	INTERFACE_HDMI,
}INPUT_INTERFACE_TYPE;
typedef struct tagNET_DVR_INPUT_INTERFACE_CTRL
{
	BYTE	byInputSourceType;	//见INPUT_INTERFACE_TYPE
	BYTE	byRes[15];
}NET_DVR_INPUT_INTERFACE_CTRL, *LPNET_DVR_INPUT_INTERFACE_CTRL;
//显示单元颜色控制
typedef struct tagNET_DVR_DISPLAY_COLOR_CTRL
{
	BYTE	byColorType;		//1-亮度 2-对比度 3-饱和度 4-清晰度
	char	byScale;			//-1 、0、+1三个值
	BYTE	byRes[14];
}NET_DVR_DISPLAY_COLOR_CTRL, *LPNET_DVR_DISPLAY_COLOR_CTRL;
//显示单元位置控制
typedef struct tagNET_DVR_DISPLAY_POSITION_CTRL
{
	BYTE	byPositionType;	//1-水平位置 2-垂直位置，
	char	byScale;			//-1 、0、+1三个值
	BYTE	byRes[14];
}NET_DVR_DISPLAY_POSITION_CTRL, *LPNET_DVR_DISPLAY_POSITION_CTRL;

typedef  union tagNET_DVR_SCREEN_CONTROL_PARAM
{
	NET_DVR_INPUT_INTERFACE_CTRL 	struInputCtrl;
	NET_DVR_DISPLAY_COLOR_CTRL 		struDisplayCtrl;
	NET_DVR_DISPLAY_POSITION_CTRL 	struPositionCtrl;
	BYTE		byRes[16];
}NET_DVR_SCREEN_CONTROL_PARAM, *LPNET_DVR_SCREEN_CONTROL_PARAM;

typedef struct tagNET_DVR_SCREEN_CONTROL
{ 	
	DWORD 	dwSize;			 
	DWORD  	dwCommand ;      /* 控制方法 1-开 2-关 3-屏幕输入源选择 4-显示单元颜色控制 5-显示单元位置控制*/
	BYTE   	byProtocol;      //串口协议类型,1:LCD-S1,2:LCD-S2
	BYTE	byRes1[3];
	NET_DVR_SCREEN_CONTROL_PARAM	struControlParam;
	BYTE   	byRes2[52];	
}NET_DVR_SCREEN_CONTROL, *LPNET_DVR_SCREEN_CONTROL;

/*******************************屏幕控制V41*******************************/
typedef struct tagNET_DVR_SCREEN_CONTROL_V41
{ 	
	DWORD   dwSize;
	BYTE	bySerialNo;		//串口号
	BYTE	byBeginAddress;	//左上角屏幕号，从1开始
	BYTE	byEndAddress;	//右下角屏幕号，从1开始
	BYTE   	byProtocol;      	   // 串口协议类型  1-LCD-S1 , 2-LCD-S2 , 3-LCD-L1 ， 4-LCD-DLP， 5-LCD-S3 , 6-LCD-H1 
	DWORD  	dwCommand ;      /* 控制方法 1-开 2-关 3-屏幕输入源选择 4-显示单元颜色控制 5-显示单元位置控制*/
	NET_DVR_SCREEN_CONTROL_PARAM	struControlParam;
	BYTE	byWallNo;		// 电视墙号
	BYTE   	byRes[51];	
}NET_DVR_SCREEN_CONTROL_V41, *LPNET_DVR_SCREEN_CONTROL_V41;

/*******************************预案管理*******************************/
#define		MAX_PLAN_ACTION_NUM 	32 	//预案动作个数
#define		DAYS_A_WEEK				7	//一周7天
#define		MAX_PLAN_COUNT			16	//预案个数


typedef enum
{
	NET_DVR_SWITCH_LAYOUT = 1, 		// 布局切换 默认
	NET_DVR_SCREEN_POWER_OFF,  		// 关闭大屏幕显示
	NET_DVR_SCREEN_POWER_ON,   		// 打开大屏幕显示
}NET_DVR_PLAN_OPERATE_TYPE;

/*预案项信息*/
typedef struct  tagNET_DVR_PLAN_INFO
{
	BYTE  	byValid;      	// 该项是否有效
	BYTE  	byType;       	// 见定义NET_DVR_PLAN_OPERATE_TYPE
	WORD  	wLayoutNo;  	// 布局号
	BYTE	byScreenStyle;    //屏幕型号，开关机所用，1是低亮，2是高亮
	BYTE	byRes1[3];
	DWORD  	dwDelayTime;  	// 一个项的运行时间, 单位秒
	BYTE	byRes2[32];
} NET_DVR_PLAN_INFO, *LPNET_DVR_PLAN_INFO;
typedef struct tagNET_DVR_CYCLE_TIME
{
	BYTE	byValid; 
	BYTE	byRes[3];
	NET_DVR_TIME_EX struTime;
}NET_DVR_CYCLE_TIME, *LPNET_DVR_CYCLE_TIME;
/*预案管理*/
typedef struct tagNET_DVR_PLAN_CFG
{
	DWORD 	dwSize;
	BYTE  	byValid;      	// 该预案是否有效
	BYTE  	byWorkMode;  	// 预案工作模式 1表示手动，2自动，3预案循环
	BYTE	byWallNo;		//电视墙号，从1开始
	BYTE	byRes1;
	BYTE  	byPlanName[NAME_LEN/*32*/]; //预案名称
	NET_DVR_TIME_EX struTime; // 工作模式为自动时使用
	NET_DVR_CYCLE_TIME struTimeCycle[DAYS_A_WEEK/*7*/]; /*循环时间，周期为一个星期，年、月、日三个参数不使用。如：struTimeCycle[0]中的byValid的值是1，表示星期天执行该预案。星期取值区间为[0,6]，其中0代表星期天，1代表星期一，以此类推*/
	DWORD 	dwWorkCount;  	// 预案内容执行次数，0为一直循环播放，其他值表示次数
	NET_DVR_PLAN_INFO strPlanEntry[MAX_PLAN_ACTION_NUM/*32*/];  // 预案执行的内容
	BYTE	byRes2[64];
}NET_DVR_PLAN_CFG, *LPNET_DVR_PLAN_CFG;


/*******************************获取设备状态*******************************/
/*预案列表*/
typedef struct tagNET_DVR_PLAN_LIST
{
	DWORD		dwSize;
	DWORD		dwPlanNums;			//设备输入信号源数量
	BYTE  		*pBuffer;			//指向dwInputSignalNums个NET_DVR_PLAN_CFG结构大小的缓冲区
	BYTE		byWallNo;			//墙号，从1开始
	BYTE		byRes1[2];
	DWORD 		dwBufLen;			//所分配缓冲区长度，输入参数（大于等于dwInputSignalNums个NET_DVR_PLAN_CFG结构大小）
	BYTE		byRes2[64];
} NET_DVR_PLAN_LIST,*LPNET_DVR_PLAN_LIST;


/*******************************预案控制*******************************/
//该结构体可作为通用控制结构体
typedef struct tagNET_DVR_CONTROL_PARAM
{
	DWORD	dwSize;
	BYTE	sDeviceID[NAME_LEN]; //被控设备的设备ID
	WORD	wChan;				 //被控通道
	BYTE	byIndex;			 //控制索引，根据命令确定具体表示什么索引
	BYTE	byRes1;
	DWORD	dwControlParam;
	BYTE	byRes2[32];
}NET_DVR_CONTROL_PARAM, *LPNET_DVR_CONTROL_PARAM;

/*******************************获取设备状态*******************************/
typedef struct tagNET_DVR_DEVICE_RUN_STATUS
{
	DWORD 	dwSize;
	DWORD	dwMemoryTotal;		//内存总量	单位Kbyte
	DWORD	dwMemoryUsage;		//内存使用量 单位Kbyte
	BYTE	byCPUUsage;			//CPU使用率 0-100
	BYTE	byRes[127];
}NET_DVR_DEVICE_RUN_STATUS, *LPNET_DVR_DEVICE_RUN_STATUS;

// 91系列HD-SDI高清DVR 相机信息
typedef struct tagNET_DVR_ACCESS_CAMERA_INFO
{
	DWORD dwSize;
   	char  sCameraInfo[32];		// 前端相机信息
	BYTE  byInterfaceType;		// 前端接入接口类型，1:VGA, 2:HDMI, 3:YPbPr 4:SDI 5:FC
	BYTE  byRes1[3];
	DWORD dwChannel;
   	BYTE  byRes[24];
}NET_DVR_ACCESS_CAMERA_INFO, *LPNET_DVR_ACCESS_CAMERA_INFO;

typedef struct tagNET_DVR_AUDIO_INPUT_PARAM
{
    BYTE  byAudioInputType;  //音频输入类型，0-mic in，1-line in
	BYTE  byVolume; //volume,[0-100]
	BYTE  byEnableNoiseFilter; //是否开启声音过滤-关，-开
	BYTE  byres[5];
}NET_DVR_AUDIO_INPUT_PARAM, *LPNET_DVR_AUDIO_INPUT_PARAM;

typedef struct tagNET_DVR_CAMERA_DEHAZE_CFG
{
	DWORD dwSize;
	BYTE byDehazeMode; //0-不启用，1-自动模式，2-开
	BYTE byLevel; //等级，0-100
	BYTE byRes[6]; 
}NET_DVR_CAMERA_DEHAZE_CFG, *LPNET_DVR_CAMERA_DEHAZE_CFG;

typedef struct tagNET_DVR_INPUT_SGNAL_LIST
{
    DWORD		dwSize;
    DWORD		dwInputSignalNums;	//设备输入信号源数量
    BYTE  		*pBuffer;			//指向dwInputSignalNums个NET_DVR_INPUTSTREAMCFG结构大小的缓冲区
    BYTE		byRes1[3];
    DWORD 		dwBufLen;			//所分配缓冲区长度，输入参数（大于等于dwInputSignalNums个NET_DVR_INPUTSTREAMCFG结构大小）
    BYTE		byRes2[64];
} NET_DVR_INPUT_SIGNAL_LIST,*LPNET_DVR_INPUT_SIGNAL_LIST;

// 安全拔盘状态
#define PULL_DISK_SUCCESS    	1   // 安全拔盘成功
#define PULL_DISK_FAIL    		2   // 安全拔盘失败
#define PULL_DISK_PROCESSING    3   // 正在停止阵列
#define PULL_DISK_NO_ARRAY 		4	// 阵列不存在 
#define PULL_DISK_NOT_SUPPORT	5 	// 不支持安全拔盘

// 扫描阵列状态
#define SCAN_RAID_SUC			1 	// 扫描阵列成功
#define SCAN_RAID_FAIL			2 	// 扫描阵列失败
#define SCAN_RAID_PROCESSING	3	// 正在扫描阵列
#define SCAN_RAID_NOT_SUPPORT	4 	// 不支持阵列扫描

// 设置前端相机类型状态
#define SET_CAMERA_TYPE_SUCCESS    		1   // 成功
#define SET_CAMERA_TYPE_FAIL    		2   // 失败
#define SET_CAMERA_TYPE_PROCESSING		3   // 正在处理

//9000 2.2
typedef struct tagNET_DVR_RECORD_TIME_SPAN_INQUIRY
{
	DWORD	dwSize;    //结构体大小
    BYTE    byType;    //0 正常音视频录像, 1图片通道录像, 2ANR通道录像, 3抽帧通道录像
	BYTE 	byRes[63]; //保留
}NET_DVR_RECORD_TIME_SPAN_INQUIRY, *LPNET_DVR_RECORD_TIME_SPAN_INQUIRY;

typedef struct tagNET_DVR_RECORD_TIME_SPAN
{
	DWORD		  dwSize;        //结构体大小
	NET_DVR_TIME  strBeginTime;  //开始时间
	NET_DVR_TIME  strEndTime;    //结束时间
    BYTE		  byType;        //0 正常音视频录像, 1图片通道录像, 2ANR通道录像, 3抽帧通道录像
	BYTE 		  byRes[35];     //保留
}NET_DVR_RECORD_TIME_SPAN, *LPNET_DVR_RECORD_TIME_SPAN;

typedef struct tagNET_DVR_DRAWFRAME_DISK_QUOTA_CFG
{
    DWORD    dwSize;					//结构体大小
    BYTE     byPicQuota;				//图片百分比	 [0%,  30%]
	BYTE     byRecordQuota;				//普通录像百分比 [20%, 40%]
	BYTE     byDrawFrameRecordQuota;	//抽帧录像百分比 [30%, 80%]
    BYTE     byRes[61];					//保留字节
}NET_DVR_DRAWFRAME_DISK_QUOTA_CFG, *LPNET_DVR_DRAWFRAME_DISK_QUOTA_CFG;

typedef struct tagNET_DVR_NAT_PORT
{
    WORD wEnable;         //该端口是否使能映射
    WORD wExtPort;		//映射的外部端口号
	BYTE byRes[12];       //保留
}NET_DVR_NAT_PORT, *LPNET_DVR_NAT_PORT;

typedef struct  tagNET_DVR_NAT_CFG
{
	DWORD dwSize;          //结构体大小
    WORD wEnableUpnp;     //UPNP功能是否启用
    WORD wEnableNat;		//UPNP端口映射（NAT）功能是否启用(保留，与wEnableUpnp保持一致)
    NET_DVR_IPADDR  struIpAddr;      //NAT路由器LAN IP地址
    NET_DVR_NAT_PORT    struHttpPort;   //web server http端口映射配置
    NET_DVR_NAT_PORT    struCmdPort; //命令端口映射配置(8000)
    NET_DVR_NAT_PORT    struRtspPort;  //rtsp端口映射配置
	BYTE byFriendName[64]; //服务名
	BYTE byNatType; //UPNP端口映射类型，0-手动，1-自动
	BYTE            byRes1[3];    //保留
	NET_DVR_NAT_PORT    struHttpsPort;     //https端口映射配置
	BYTE            byres[76];    //保留
}NET_DVR_NAT_CFG, *LPNET_DVR_NAT_CFG;

typedef struct
{
    DWORD  dwEnabled;               //该端口是否被使能映射
    WORD   wInternalPort;           //映射前的端口
    WORD   wExternalPort;           //映射后的端口
	DWORD  dwStatus;				 /*端口映射状态
									 0 未生效
									 1 未生效：映射源端口与目的端口需一致
									 2 未生效:  映射端口号已被使用
									 3 生效
									*/
	NET_DVR_IPADDR	struNatExternalIp;       //映射后的外部地址
	NET_DVR_IPADDR	struNatInternalIp;       //NAT路由器LAN IP地址
	BYTE   byRes[16];               //保留
}NET_DVR_UPNP_PORT_STATE, *LPNET_DVR_UPNP_PORT_STATE;


typedef struct
{
	NET_DVR_UPNP_PORT_STATE strUpnpPort[UPNP_PORT_NUM];     //端口映射状态,数组0 web server端口 数组1 管理端口 数组2 rtsp端口
	BYTE   byRes[200];              //保留
}NET_DVR_UPNP_NAT_STATE, *LPNET_DVR_UPNP_NAT_STATE;

typedef struct tagNET_DVR_PLAYCOND
{
	DWORD			 dwChannel;
	NET_DVR_TIME     struStartTime;
	NET_DVR_TIME     struStopTime;
	BYTE			 byDrawFrame;  //0:不抽帧，1：抽帧
	BYTE			 byRes[63];    //保留
}NET_DVR_PLAYCOND, *LPNET_DVR_PLAYCOND;

typedef struct tagNET_DVR_ATMFINDINFO
{
    BYTE    byTransactionType;       //交易类型 0-全部，1-查询， 2-取款， 3-存款， 4-修改密码，5-转账， 6-无卡查询 7-无卡存款， 8-吞钞 9-吞卡 10-自定义
    BYTE    byRes[3] ;    //保留
    DWORD  dwTransationAmount ;     //交易金额 ;
} NET_DVR_ATMFINDINFO, *LPNET_DVR_ATMFINDINFO ;

typedef union  tagNET_DVR_SPECIAL_FINDINFO_UNION
{
    BYTE  byLenth[8] ;
    NET_DVR_ATMFINDINFO      struATMFindInfo;	       //ATM查询
}NET_DVR_SPECIAL_FINDINFO_UNION, *LPNET_DVR_SPECIAL_FINDINFO_UNION;


typedef struct tagNET_DVR_FILECOND_V40
{
	LONG           lChannel;
	DWORD          dwFileType;
	DWORD          dwIsLocked;
	DWORD          dwUseCardNo;
	BYTE           sCardNumber[CARDNUM_LEN_OUT];
	NET_DVR_TIME   struStartTime;
	NET_DVR_TIME   struStopTime;
	BYTE           byDrawFrame; //0:不抽帧，1：抽帧
	BYTE		byFindType; //0:查询普通卷，1：查询存档卷
	BYTE		byQuickSearch; //0:普通查询，1：快速（日历）查询
	BYTE        bySpecialFindInfoType ;    //专有查询条件类型 0-无效， 1-带ATM查询条件  
	DWORD       dwVolumeNum;  //存档卷号
	BYTE		byWorkingDeviceGUID[GUID_LEN];    //工作机GUID，通过获取N+1得到
    NET_DVR_SPECIAL_FINDINFO_UNION uSpecialFindInfo ;   //专有查询条件
	BYTE        byRes2[32];    //保留
}NET_DVR_FILECOND_V40, *LPNET_DVR_FILECOND_V40;

typedef struct 
{
	BYTE	sAESKey[16];        /*码流加密密钥*/
	BYTE	byRes[64];          /*保留字节*/
}NET_DVR_AES_KEY_INFO, *LPNET_DVR_AES_KEY_INFO;

typedef struct
{
	NET_DVR_IPADDR struIP;     //IP地址
	BYTE  byRes[128]; //保留
}NET_DVR_POE_CFG, *LPNET_DVR_POE_CFG;

#define MAX_PRO_PATH         256    //最大协议路径长度

typedef struct
{
	DWORD dwSize;              //结构体大小
	DWORD dwEnabled;           //是否启用该协议0 不启用 1 启用
	char  sProtocalName[DESC_LEN];   //自定义协议名称, 16位
	BYTE  byRes1[64];          //保留,用于协议名称扩展
	DWORD dwEnableSubStream;   //子码流是否启用0 不启用 1 启用
	
	BYTE  byMainProType;        //主码流协议类型 1 RTSP
	BYTE  byMainTransType;		//主码流传输类型 0：Auto 1：udp 2：rtp over rtsp
	WORD  wMainPort;           //主码流端口	
	char  sMainPath[MAX_PRO_PATH];  //主码流路径
	
	BYTE  bySubProType;         //子码流协议类型 1 RTSP
	BYTE  bySubTransType;		//子码流传输类型 0：Auto 1：udp 2：rtp over rtsp
	WORD  wSubPort;            //子码流端口
	char  sSubPath[MAX_PRO_PATH];   //子码流路径 
	
	BYTE  byRes2[200];          //保留
}NET_DVR_CUSTOM_PROTOCAL, *LPNET_DVR_CUSTOM_PROTOCAL;


//B10能支持PSIA设备
//循环上墙结构体（实时）
typedef struct  
{
    DWORD	dwEnable; /* 是否启用 0－否 1－启用*/
    BYTE	byType; //设备类型 0: DEV_SDK  1:DEV_DAHUA  2:DEV_EHOME	3:DEV_OTHERES
    BYTE	byRes[3];  //保留
    NET_DVR_STREAM_MEDIA_SERVER_CFG streamMediaServerCfg; 
    NET_DVR_DEV_CHAN_INFO  struDevChanInfo; /* 轮循解码通道信息 */
    BYTE	sRtspUrl[128];//流地址
}NET_DVR_MATRIX_CHAN_INFO_EX,*LPNET_DVR_MATRIX_CHAN_INFO_EX;

typedef struct
{
    DWORD	dwSize;
    DWORD	dwPoolTime;	/*轮询间隔*/
    NET_DVR_MATRIX_CHAN_INFO_EX		struchanConInfo[MAX_CYCLE_CHAN_V30];
    BYTE    byRes[16];
}NET_DVR_MATRIX_LOOP_DECINFO_EX,*LPNET_DVR_MATRIX_LOOP_DECINFO_EX;

//实时预览上墙结构体
typedef struct
{
    DWORD dwSize;
    BYTE byType; //设备类型 0: DEV_SDK  1:DEV_DAHUA  2:DEV_EHOME 3:DEV_OTHERES
    BYTE byRes[3]; //保留
    NET_DVR_STREAM_MEDIA_SERVER_CFG struStreamMediaSvrCfg;
    NET_DVR_DEV_CHAN_INFO struDevChanInfo;
    BYTE sRtspUrl[128];//流地址
}NET_DVR_PU_STREAM_CFG_EX,*LPNET_DVR_PU_STREAM_CFG_EX;

typedef struct tagNET_DVR_MATRIX_TRUNKCFG
{
    DWORD     dwGlobalIndex;  //主键
    DWORD     dwInterIndex;   //本地全局编号
    BYTE      sTrunkName[NAME_LEN];
    BYTE      byType;   //设备类型1-bnc, 2-SP3, 3-V6
    BYTE      byDir;   //干线方向 1-输入2-输出
    BYTE      byAbility;   //干线能力，D1衡量
    BYTE      bySubsys;   //子系统ID
    BYTE      byChan;     //通道ID
    BYTE      byRes[255];     //预留
} NET_DVR_MATRIX_TRUNKCFG,*LPNET_DVR_MATRIX_TRUNKCFG;

typedef struct tagNET_DVR_DECSUBSYSTEMJIONSTATUS_V41
{
    BYTE        byJoinStatus;//关联状态，0-没有关联，1-已经关联，通过其他字段判断被自己关联或被其他子系统关联，2-被占用，byDecodeAbility大于1时有效，3-被大屏主屏关联，4-被大屏子屏关联
    BYTE		byJoinSubSystem;// 所关联或占用的子系统槽位号
    BYTE		byJoinDispNum;// 所关联或占用的显示通道号
    BYTE		byJoinSubWindowNum;// 所关联或占用的子窗口号
    BYTE		byDecodeAbility;   //解码通道的当前解码能力，0-未关联，1-D1，2-720，3-1080
    BYTE		byRes[15];
}NET_DVR_DECSUBSYSTEMJIONSTATUS_V41,LPNET_DVR_DECSUBSYSTEMJIONSTATUS_V41;

typedef struct tagNET_DVR_SINGLESUBSYSTEMJOININFO_V41
{
    /*子系统类型，1-解码用子系统，2-编码用子系统，3-级联输出子系统，4-级联输入子系统，5-码分器子系统，6-报警主机子系统，7-智能子系统，8-V6解码子系统，9-V6子系统，0-NULL（此参数只能获取）*/
    BYTE	bySubSystemType; 
    BYTE	byConnectStatus;//级联系统关联状态，1-连接正常，2-连接断开
    BYTE    byMatrixNum;//级联视频综合平台号，子系统类型是3或4时可用
    BYTE	bySubSystemNum;//级联子系统槽位号，子系统类型是3或4时可用
    NET_DVR_DECSUBSYSTEMJIONSTATUS_V41 struSubSystem[MAX_DECODECHANNUM];
    BYTE	byBindStatus;//绑定状态，0-没有绑定，1-已经绑定（大屏拼接时用到）
    BYTE	bySlotNum ;//槽位号，此参数只能获取
    BYTE    byUsedTrunk;//是否被干线使用，0-未被使用，1-被使用
    BYTE    byRes[65];
}NET_DVR_SINGLESUBSYSTEMJOININFO_V41,LPNET_DVR_SINGLESUBSYSTEMJOININFO_V41;

typedef struct tagNET_DVR_ALLDECSUBSYSTEMJOININFO_V41
{
    DWORD dwSize;
    NET_DVR_SINGLESUBSYSTEMJOININFO_V41 struSingleSubSystemJoinInfo[MAX_SUBSYSTEM_NUM_V40];
    BYTE  byRes[48];
}NET_DVR_ALLDECSUBSYSTEMJOININFO_V41,*LPNET_DVR_ALLDECSUBSYSTEMJOININFO_V41;

//////////子系统配置/////////////
#define MAX_ALARMHOSTKEYBOARD 64 //网络报警主机最大键盘数
typedef struct tagNET_DVR_PUBLIC_SUB_SYSTEM
{
	//关联子系统号，按位表示，bit0表示该公共子系统关联子系统1.
	DWORD	dwJointSubSystem;
	BYTE	byRes[16];
}NET_DVR_PUBLIC_SUB_SYSTEM, *LPNET_DVR_PUBLIC_SUB_SYSTEM;

typedef struct tagNET_DVR_NOAMAL_SUB_SYSTEM
{
	//表示被哪些公共子系统关联，按位表示，bit0 表示，该子系统.被关联到公共子系统1
	DWORD	dwBeJoinedSubSystem;
	BYTE	byRes[16];	
}NET_DVR_NOAMAL_SUB_SYSTEM, *LPNET_DVR_NOAMAL_SUB_SYSTEM;

typedef union tagNET_DVR_JOINT_SUB_SYSTEM
{
	// byPublicAttributeEnable为0时使用该变量
	NET_DVR_NOAMAL_SUB_SYSTEM 	struNormalSubSystem;
	//byPublicAttributeEnable为1时使用该变量
	NET_DVR_PUBLIC_SUB_SYSTEM		struPublicSubSystem;
	BYTE	byRes[20];	
}NET_DVR_JOINT_SUB_SYSTEM,*LPNET_DVR_JOINT_SUB_SYSTEM;
typedef struct tagNET_DVR_ALARMSUBSYSTEMPARAM
{
    DWORD		dwSize;
    WORD		wEnterDelay;					//进入延时,单位:秒, 范围：10-150 动环报警主机和自助行报警主机的延时时间在 NET_DVR_ALARMIN_PARAM 中的dwParam来设置延时时间
	//具体用哪种设置方式通过能力集中的bySupportAlarmInDelay字段来区别
    WORD		wExitDelay;//退出延时,单位:秒， 范围10-300
    BYTE		byHostageReport;				//挟持报告，0禁能 1使能
	BYTE		bySubsystemEnable;				//子系统使能
	BYTE		byKeyToneOfArmOrDisarm;			// 键盘提示成功发送布撤防报告，0-键盘不提示 1-键盘输出提示音
	BYTE		byKeyToneOfManualTestReport;	//键盘提示成功发送测试报告，0-键盘不提示 1-键盘输出提示音
	WORD		wDelayTime;						//警号输出延时，当能力集中dwSupport1中的bit0位为1时，使用该参数设置警号输出时间。bit0为0时，使用NET_DVR_SIREN_PARAM中的wDelay参数设置警号输出时间
	BYTE		byRes1;
	BYTE 		byPublicAttributeEnable;		//是否为公共子系统
	NET_DVR_JOINT_SUB_SYSTEM struJointSubSystem;		
	BYTE		byKeyZoneArm;					//是否支持钥匙防区对子系统进行布防操作
	BYTE		byKeyZoneArmReport;				//是否支持钥匙防区对子系统布防时发送布防报告
	BYTE		byKeyZoneDisarm;				//是否支持钥匙防区对子系统进行撤防操作
	BYTE		byKeyZoneDisarmReport;			//是否支持钥匙防区对子系统进行撤防操作时发送撤防报告
    BYTE		byRes2[624];					// 保留字节
}NET_DVR_ALARMSUBSYSTEMPARAM, *LPNET_DVR_ALARMSUBSYSTEMPARAM;

//子系统参数配置扩展
#define	MAX_KEYBOARD_USER_NUM	256
typedef struct tagNET_DVR_SUBSYSTEM_PARAM_EX
{
	DWORD 	dwSize;
	NET_DVR_SCHEDTIME struAlarmTime[MAX_DAYS/*7*/][MAX_TIMESEGMENT_V30/*8*/]; //布撤防时间
	BYTE	byAlarmInAdvance;			// 布撤防提前提示时间0~45分
	BYTE	byRes1[3];
	BYTE 	byJointAlarmIn[MAX_ALARMHOST_ALARMIN_NUM / 8];//按位，表示子系统关联的报警输入通道号，0-不加入，1-加入
	BYTE 	byJointKeyboard[MAX_ALARMHOSTKEYBOARD/*64*/ / 8];//按位，表示支持的键盘号，0-不加入，1-加入
	BYTE	byJointOpetaterUser[MAX_KEYBOARD_USER_NUM/8];//按位表示，bit0表示键盘操作用户1 ，0-不关联 1-关联
    BYTE 	byRes2[512];			// 保留字节
}NET_DVR_SUBSYSTEM_PARAM_EX, *LPNET_DVR_SUBSYSTEM_PARAM_EX;


typedef struct tagNET_DVR_ALARMHOST_PRINTER_CFG
{
	DWORD 	dwSize;
	BYTE 	byPrinterEnable;		//是否启用打印机
	BYTE	byPrintTime;			//是否打印时间
	BYTE 	byFaultDetect;			//是否检测打印机故障
	BYTE	byRes1;
	DWORD	dwAlarmInfo;			//报警信息，按位表示。bit0-防区报警，bit1-防区报警恢复，bit2-紧急报警，bit-3挟持报警
	DWORD	dwDeviceInfo;			//设备信息，按位表示。bit0-交流电断电、bit1-交流电断电恢复，bit2-蓄电池欠压、bit3-蓄电池欠压恢复，bit4-电话线断线、bit5-电话线断线恢复，bit6-测试报告、bit7-防拆、bit8-防拆恢复、bit9-485设备掉线、bit10-485设备掉线恢复、bit11-无线网络异常、bit12-无线网络恢复正常、bit13-有线网络异常、bit14-有线网络恢复正常、bit15-扩展总线异常、bit17-扩展总线恢复正常、bit17-硬盘故障、bit18-硬盘故障恢复
	DWORD	dwOperateInfo;			//操作信息，按位表示。bit0-布防、bit1-撤防、bit2-消警、bit3-旁路、bit4-旁路恢复、bit5-进入编程、bit6-退出编程、bit7-主机复位
	BYTE 	byRes2[256];			// 保留字节
}NET_DVR_ALARMHOST_PRINTER_CFG, *LPNET_DVR_ALARMHOST_PRINTER_CFG;

//////////GPRS参数配置/////////////
#define	ACCOUNTNUM_LEN 			6
#define	APN_NAME_LEN			32
#define	APN_USERNAME_LEN		24
#define	APN_USERPASSWORD_LEN	16

typedef struct tagNET_DVR_ALARMHOST_NETPARAM
{ 
	DWORD dwSize;
	NET_DVR_IPADDR struIP;
	WORD	wPort;
	BYTE	byRes1[2];
	BYTE	byDomainName[MAX_DOMAIN_NAME/*64*/]; //域名，GPRS参数配置时有效，网络参数配置时该字段不使用
	BYTE	byReportProtocol;		//1-private 2-NAL2300
	BYTE	byDevID[ACCOUNTNUM_LEN/*6*/]; //协议为NAL2300时有效
	BYTE	byRes2[33]; //GPRS的域名解析是在固定的服务器上进行的，所以不需要给解析服务器的信息预留一些字段
}NET_DVR_ALARMHOST_NETPARAM,  *LPNET_DVR_ALARMHOST_NETPARAM;

typedef struct tagNET_DVR_ALARMHOST_WIRELESS_NETWORK_CFG
{
	DWORD	dwSize;
	NET_DVR_ALARMHOST_NETPARAM struNetCenter[MAX_CENTERNUM]; //中心 GPRS网络相关参数的配置 
	BYTE 	byAPNName[APN_NAME_LEN/*32*/];
	BYTE	byAPNUserName[APN_USERNAME_LEN/*24*/];
	BYTE	byAPNPassWord[APN_USERPASSWORD_LEN/*16*/];
	BYTE	byReconnTime;	//重连时间，连接失效后启用重连的时间，10秒为单位,取值范围1-30
	BYTE	byOverTime;		//超时时间，超过OverTime时间没有收到有效数据则重连，范围1-254，单位30秒
	BYTE	byDetectLinkTime;	//	//探测链路是否还保持，范围1-30，单位10s
	BYTE	byRes1;
	BYTE	bySIMNum[NAME_LEN/*32*/]; //SIM卡号（手机号）
	NET_DVR_IPADDR	struSIMIP;	  //登陆网络后网络给分配的IP地址，只能获取
	BYTE	byRes2[64];
}NET_DVR_ALARMHOST_WIRELESS_NETWORK_CFG, *LPNET_DVR_ALARMHOST_WIRELESS_NETWORK_CFG;


//////////网络参数配置/////////////
typedef struct tagNET_DVR_ALARMHOST_NETCFG
{
	DWORD dwSize;
	NET_DVR_ALARMHOST_NETPARAM 	struNetCenter[MAX_CENTERNUM];
	BYTE	byRes1[32];
}NET_DVR_ALARMHOST_NETCFG,  *LPNET_DVR_ALARMHOST_NETCFG;

//////////积木上传方式/////////////
#define	MAX_REPORTCHAN_NUM		4
#define	MAX_CENTERGROUP_NUM		16
typedef struct tagNET_DVR_ALARMHOST_REPORTCENTER_CFG
{
	DWORD	dwSize;
	BYTE	byValid;				//是否启用
	BYTE	byRes[3]; //保留1
	BYTE	byChanAlarmMode[MAX_REPORTCHAN_NUM/*4*/];	//中心组报警通道， 1-T1、2-T2、 3-N1、 4-N2、5-G1、 6-G2
	BYTE	byDealFailCenter[MAX_CENTERGROUP_NUM/*16*/]; //向指定中心组发送失败报告，用数组下标表示是哪个中心组，0-不选择、1-选择
	BYTE	byDataType;	//1-报警数据 2-非报警数据 3-所有数据
	BYTE	byRes2[15];	//保留2
}NET_DVR_ALARMHOST_REPORTCENTER_CFG, *LPNET_DVR_ALARMHOST_REPORTCENTER_CFG;

#define MAX_EVENT_NUM 32//网络报警主机最大事件数
typedef struct tagNET_DVR_ALARMHOST_REPORT_CENTER_CFG_V40
{
	DWORD		dwSize;			
	BYTE		byValid;			//是否启用
	BYTE		byDataType;			//1-所有报警数据 2-所有非报警数据 3-所有数据，4-防区报警报告，5-非防区报警报告
	BYTE		byRes[2]; 			//保留1
	BYTE		byChanAlarmMode[MAX_REPORTCHAN_NUM/*4*/];	//中心组报警通道， 1-T1、2-T2、 3-N1、 4-N2、5-G1、 6-G2(如果设备支持3G，G1，G2表示3G模块，如果不支持，表示GPRS模块，一款设备中3G模块和GPRS模块只会出现一种)
	BYTE		byDealFailCenter[MAX_CENTERGROUP_NUM/*16*/]; //向指定中心组发送失败报告，用数组下标表示是哪个中心组，0-不选择、1-选择
	BYTE	 	byZoneReport[MAX_ALARMHOST_ALARMIN_NUM];	//防区报告类型，0-不上传，1-上传 
	BYTE		byNonZoneReport[MAX_EVENT_NUM]; //非防区报警报告, 每一个元素表示一种事件类型，0-不上传，1-上传，byNonZoneReport[0]-软防区报告 byNonZoneReport[1]-系统状态报告 byNonZoneReport[2]-取消报告 byNonZoneReport[3]-测试报告 byNonZoneReport[4]-布防报告 byNonZoneReport[5]-撤防报告 byNonZoneReport[6]-挟持报告 byNonZoneReport[7]-报警恢复报告 byNonZoneReport[8]-旁路报告 byNonZoneReport[9]-旁路恢复报告。
	BYTE		byRes2[256];			//保留2
}NET_DVR_ALARMHOST_REPORT_CENTER_CFG_V40, *LPNET_DVR_ALARMHOST_REPORT_CENTER_CFG_V40;


//////////防护舱状态上传/////////////
typedef  struct tagNET_DVR_ALARMHOST_SAFETYCABINSTATE
{
	DWORD	dwSize;
	BYTE	byEnterButton;	//进门按钮状态 0-不按下 1-按钮按下
	BYTE	byExitButton;	//出门按钮状态 0-不按下 1-按钮按下
	BYTE	byDoorState;	//门状态	0-门关闭 1-门打开
	BYTE	byLockState;	//锁状态 0-锁关	1-锁开
	BYTE	byUrgencyButton;	//紧急按钮状态	0-不按下 1-按钮按下
	BYTE	byManState;		//人状态	 0-没人 1-有人
    BYTE    byAbnormal; //异常状态  0-正常 1-异常(防护舱使用超时上传异常)
	BYTE    byLightState;   //灯光状态 0-关 ，1-开
	BYTE    byFanState;     //风扇状态 0-关，1-开
	BYTE	byRes[63];
}NET_DVR_ALARMHOST_SAFETYCABINSTATE,*LPNET_DVR_ALARMHOST_SAFETYCABINSTATE;

/////////警号输出口，警号状态上传/////////////
typedef  struct tagNET_DVR_ALARMHOST_ALARMOUTSTATUS
{
	DWORD	dwSize;
	BYTE	byName[32];		//报警输出口名称或警号名称
	BYTE	byAlarmType;	//1-报警输出口状态， 2-警号状态
	WORD	wChan;			//如果是报警输出口状态，该值的范围为0-511；如果是警号状态，范围1-8（防护舱只有1个警号输出）
	BYTE	byAlarmStatus; //报警状态 0-无报警 1-有报警
	BYTE	byRes[32];
}NET_DVR_ALARMHOST_ALARMOUTSTATUS,*LPNET_DVR_ALARMHOST_ALARMOUTSTATUS;

//////////语音上传下载/////////////
typedef struct tagNET_DVR_AUDIO_PARAM
{
	DWORD		dwSize;
	BYTE		byAudioFormat;      //音频格式，1-G711，2-OggVorbis 
	BYTE		byRes1;
    WORD		wChannels;          // number of channels (i.e. mono, stereo...)
    DWORD		dwSamplesPerSec;	//采样率
    BYTE		byRes2[20];			//保留
    DWORD		dwAudioSize;		//音频长度大小，压缩后的大小
}NET_DVR_AUDIO_PARAM,*LPNET_DVR_AUDIO_PARAM;

//预览V40接口
typedef struct tagNET_DVR_PREVIEWINFO
{
	LONG lChannel;//通道号
    DWORD dwStreamType;	// 码流类型，0-主码流，1-子码流，2-码流3，3-码流4 等以此类推
	DWORD dwLinkMode;// 0：TCP方式,1：UDP方式,2：多播方式,3 - RTP方式，4-RTP/RTSP,5-RSTP/HTTP 
	HWND hPlayWnd;//播放窗口的句柄,为NULL表示不播放图象
	DWORD bBlocked;  //0-非阻塞取流, 1-阻塞取流, 如果阻塞SDK内部connect失败将会有5s的超时才能够返回,不适合于轮询取流操作.
	DWORD bPassbackRecord; //0-不启用录像回传,1启用录像回传
	BYTE byPreviewMode;//预览模式，0-正常预览，1-延迟预览
	BYTE byStreamID[STREAM_ID_LEN/*32*/];//流ID，lChannel为0xffffffff时启用此参数
	BYTE byProtoType; //应用层取流协议，0-私有协议，1-RTSP协议
	BYTE byRes[222];
}NET_DVR_PREVIEWINFO, *LPNET_DVR_PREVIEWINFO;


//事件触发报警输出

typedef struct tagNET_DVR_TRIGGER_EVENT
{
	DWORD	dwSize;
	DWORD	dwOverallEventTriggerAlarmoutOn;	//全局事件触发报警输出开启，按位或，bit0-交流电掉电，bit1-电池电压低，bit2-电话线掉线，bit3-有线网络异常，bit4-无线网络异常
	DWORD	dwOverallEventTriggerAlarmoutOff;	//全局事件触发报警输出开启，按位或，bit0-交流电掉电，bit1-电池电压低，bit2-电话线掉线，bit3-有线网络异常，bit4-无线网络异常
	DWORD	dwSubSystemEventTriggerAlarmoutOn[MAX_ALARMHOST_SUBSYSTEM/*32*/]; //子系统事件触发报警输出开启,dwSubSystemEvent[0]表示子系统1，dwSubSystemEvent[2]表示子系统2，具体的子系统个数从能力集获取（wSubSystem），每个子系统的事件按位表示，bit0-进入延时，bit1-退出延时，bit2-布防，bit3-撤防，bit4-报警，bit5-消除报警记忆,bit6-报警恢复
	DWORD	dwSubSystemEventTriggerAlarmoutOff[MAX_ALARMHOST_SUBSYSTEM/*32*/]; //子系统事件触发报警输出关闭,wSubSystemEvent[0]表示子系统1，dwSubSystemEvent[2]表示子系统2，具体的子系统个数从能力集获取（wSubSystem），每个子系统的事件按位表示，bit0-进入延时，bit1-退出延时，bit2-布防，bit3-撤防，bit4-报警，bit5-消除报警记忆,bit6-报警恢复
	BYTE	byRes[128];
}NET_DVR_TRIGGER_EVENT, *LPNET_DVR_TRIGGER_EVENT;

//故障处理配置
typedef struct  tagNET_DVR_ALARMHOST_FAULT_CFG
{
	DWORD 	dwSize;
	DWORD	dwCheckFault;	//是否检测故障，bit0-交流电断电，bit1-蓄电池欠压，bit2-主机防拆开，bit3-电话线掉线，bit4-485设备异常，bit5-网络故障，bit6-无线异常，bit7-扩展总线异常，bit8-硬盘异常，具体支持的故障类型从能力集获取
	DWORD	dwOverallFaultJointLED;		//故障关联全局键盘指示灯输出 bit0-交流电断电，bit1-蓄电池欠压，bit2-主机防拆开，bit3-电话线掉线，bit4-485设备异常，bit5-网络故障，bit6-无线异常，bit7-扩展总线异常，bit8-硬盘异常，具体支持的故障类型从能力集获取
	DWORD	dwOverallFaultJointSound;	//故障关联全局键盘声音输出 bit0-交流电断电，bit1-蓄电池欠压，bit2-主机防拆开，bit3-电话线掉线，bit4-485设备异常，bit5-网络故障，bit6-无线异常，bit7-扩展总线异常，bit8-硬盘异常，具体支持的故障类型从能力集获取
	DWORD	dwSubSystemFaultJointLED[MAX_ALARMHOST_SUBSYSTEM]; /*故障关联子系统键盘指示灯输出，dwSubSystemFaultJointLED[0]表示子系统1的关联信息。dwSubSystemFaultJointLED[0]的每一位表示一中故障，bit0-交流电断电，bit1-蓄电池欠压，bit2-主机防拆开，bit3-电话线掉线，bit4-485设备异常，bit5-网络故障，bit6-无线异常，bit7-扩展总线异常，bit8-硬盘异常; dwSubSystemFaultJointLED[1]表示子系统2，以此类推*/
	DWORD	dwSubSystemFaultJointSound[MAX_ALARMHOST_SUBSYSTEM];/*故障关联子系统键盘声音输出（声音在键盘上输出）dwSubSystemFaultJointLED[0]表示子系统1的关联信息。dwSubSystemFaultJointSound [0]的每一位表示一中故障，bit0-交流电断电，bit1-蓄电池欠压，bit2-主机防拆开，bit3-电话线掉线，bit4-485设备异常，bit5-网络故障，bit6-无线异常，bit7-扩展总线异常，bit8-硬盘异常; dwSubSystemFaultJointSound [1]表示子系统2，以此类推*/
	DWORD	dwFaultJointFaultLight;//故障关联故障灯输出
	BYTE	byRes[60];
}NET_DVR_ALARMHOST_FAULT_CFG, *LPNET_DVR_ALARMHOST_FAULT_CFG;

typedef struct tagNET_DVR_LIST_INFO
{
	DWORD	dwSize;
	BYTE	byIndex;			//子系统号，0xff表示所有子系统
	BYTE   	byRes[63];      //保留
}NET_DVR_LIST_INFO, *LPNET_DVR_LIST_INFO;

#define CID_CODE_LEN 4
typedef enum tagNET_DVR_ALARMHOST_REPORT_TYPE
{
	NET_DVR_DEFENCE_ALARM = 1,		//防区报警
		NET_DVR_VIDEO_ALARM,			//视频报警
		NET_DVR_VIRTUAL_DEFENCE_ALARM,	//软防区报警
		NET_DVR_HOSTAGE_ALARM,			//挟持报警
		NET_DVR_KNOCK_DOWN_ALARM,		//防拆报警
		NET_DVR_OPERATE_ALARM,			//操作报告
		NET_DVR_OHTER_ABNORMAL_ALARM	//异常报告
}NET_DVR_ALARMHOST_REPORT_TYPE;

typedef struct tagNET_DVR_CID_ALARM
{
    DWORD	dwSize;
    BYTE	sCIDCode[CID_CODE_LEN/*4*/];	//CID事件号
    BYTE	sCIDDescribe[NAME_LEN/*32*/];	//CID事件名
    NET_DVR_TIME_EX struTriggerTime;			//触发报警的时间点
    NET_DVR_TIME_EX struUploadTime;				//上传报警的时间点
	BYTE	sCenterAccount[ACCOUNTNUM_LEN/*6*/];	//中心帐号
	BYTE	byReportType;					//见定义NET_DVR_ALARMHOST_REPORT_TYPE
	BYTE	byUserType;						//用户类型，0-网络用户 1-键盘用户
	BYTE	sUserName[NAME_LEN/*32*/];		//网络用户用户名
	WORD	wKeyUserNo;						//键盘用户号	0xFFFF表示无效
	BYTE	byKeypadNo;						//键盘号		0xFF表示无效
	BYTE	bySubSysNo;						//子系统号		0xFF表示无效
	WORD	wDefenceNo;						//防区号		0xFFFF表示无效
	BYTE	byVideoChanNo;					//视频通道号	0xFF表示无效
	BYTE	byDiskNo;						//硬盘号		0xFF表示无效
	WORD	wModuleAddr;					//模块地址		0xFFFF表示无效
    BYTE	byRes[62];
}NET_DVR_CID_ALARM, *LPNET_DVR_CID_ALARM;

typedef struct tagNET_DVR_ALARMHOST_MODULE_CFG
{
	DWORD dwSize;
	BYTE	byModuleType;	//1-防区，2-触发器 3-防区触发器      
	BYTE	byZoneType;		//防区类型，1-本地防区，2-单防区，3-双防区，4-8防区，5-8路模拟量防区，6-单防区触发器，0xff表示该参数无效
	BYTE	byTriggerType;	//触发器类型，1-本地触发器， 2-4路触发器，3-8路触发器，4-单防区触发器，0xff表示该参数无效
	BYTE	byRes[253];
} NET_DVR_ALARMHOST_MODULE_CFG, *LPNET_DVR_ALARMHOST_MODULE_CFG;


#define MAX_DECODE_CARD_SUPPORTDISPNUMS 8//每个解码卡最多支持的显示通道数
#define MAX_SUPPORT_RES 32
typedef struct tagNET_DVR_DECCARD_ABILITY_V41 /*高清解码卡能力集*/
{
    BYTE byCardType;      //解码卡类型(0:MD,1:MD+,2:HD)
    BYTE byDecNums;      //解码通道数 
    BYTE byDispNums;      //显示通道数 
    BYTE byDecStartIdx;     //首个解码通道在所有解码通道中的索引 
    BYTE byDispStartIdx;     //首个显示通道在所有显示通道中的索引
    BYTE byRes1[3]; 
    DWORD dwVgaSupportResolution[MAX_SUPPORT_RES/*32*/];//支持的分辨率
    DWORD dwHdmiSupportResolution[MAX_SUPPORT_RES/*32*/];//支持的分辨率
    DWORD dwDviSupportResolution[MAX_SUPPORT_RES/*32*/];//支持的分辨率
    DWORD dwYpbprSupportResolution[MAX_SUPPORT_RES/*32*/];//支持的分辨率
    BYTE byDispFormat[MAX_DECODE_CARD_SUPPORTDISPNUMS];   //支持的输出模式(按HD_DISPLAY_FORMAT中的枚举) 
    BYTE byWindowMode[MAX_DECODE_CARD_SUPPORTDISPNUMS][12]; //支持的窗口模式(比如1,2,4,9,16))
    BYTE byRes2[36];
} NET_DVR_DECCARD_ABILITY_V41,*LPNET_DVR_DECCARD_ABILITY_V41;

#define		MAX_DECODE_CARD_NUM			6   //最多高清解码卡数
typedef struct tagNET_DVR_DECODESVR_ABILITY_V41
{
    DWORD dwSize;      /* 结构体大小 */
    BYTE byCardNums;      /* 解码卡数 */
    BYTE byStartChan;     /* 起始通道号 */
    BYTE byRes1[2];
    NET_DVR_DECCARD_ABILITY_V41 struDecCardAbility[MAX_DECODE_CARD_NUM];
    BYTE byRes2[64];
}NET_DVR_DECODESVR_ABILITY_V41, *LPNET_DVR_DECODESVR_ABILITY_V41;

// 流录像状态
typedef struct tagNET_DVR_STREAM_RECORD_STATUS
{
	DWORD           dwSize;
	BYTE			byRecord;         //(只读)录像类型, 0：不在录像，1：在录像 2-空闲 
									  //3-无连接 4-无输入视频 5-未加载 6-存档中
									  //7-回传中 8-用户名或密码错 9-未验证
									  //10-存档中和录像中 11-录像回传中和录像中
	BYTE			byOffLineRecord;  //断网录像功能 0-关闭 1-开启
	BYTE			byRes1[2];        //保留字节
	DWORD			dwRelatedHD;      //关联磁盘
	BYTE			byRes2[8];        //保留字节
}NET_DVR_STREAM_RECORD_STATUS, *LPNET_DVR_STREAM_RECORD_STATUS;

typedef struct tagNET_DVR_DIRECT_CONNECT_CHAN_INFO
{
    BYTE		byEnable;					//是否启用
	BYTE		byProType;					//协议类型，0-私有协议(default), (需要从设备获取能力)
	BYTE  		byZeroChan;					//是否是零通道,0-不是，1-是
    BYTE		byRes1[1];						//保留字段，置0
    BYTE		sUserName[NAME_LEN];		//用户名
    BYTE		sPassword[PASSWD_LEN];	    //密码
    BYTE		byDomain[MAX_DOMAIN_NAME];	//设备域名
    NET_DVR_IPADDR  struIP;				        //IP地址
	WORD		wDVRPort;			 	    //端口号
	BYTE		byStreamType;               //主码流:0; 子码流：1
	BYTE		byOnline;					//只读，0-不在线 1-在线
	DWORD		dwChannel;                  //通道号
	BYTE		byTransProtocol;			//协议类型，0-TCP，1-UDP，2-多播
	BYTE		byRes3[27];				    //保留字段，置0
}NET_DVR_DIRECT_CONNECT_CHAN_INFO, *LPNET_DVR_DIRECT_CONNECT_CHAN_INFO;

typedef struct tagNET_DVR_PU_STREAM_URL_CFG
{ 
	BYTE    byEnable;  
	BYTE    byRes[3]; 
	BYTE    byStreamMediaIP[64];//流媒体IP 
	WORD    wStreamMediaPort; //流媒体端口
	BYTE    byTransmitType; //流媒体传输协议 0- TCP  1- UDP
	BYTE    byRes1[33];
	BYTE    byDevIP[64]; //设备IP 
	WORD    wDevPort; //设备端口
	BYTE    byChannel; //通道号
	BYTE    byTransMode; //传输模式 0-主码流 1- 子码流 
	BYTE    byProType;    
	//厂家类型 0-私有 1-大华 2-汉邦 3-郎驰 4-蓝色星际 NET_DVR_GetIPCProtoList接口获取
	//VQD流媒体下只支持 0，1方式；直连支持 0，1，2，3，4
	BYTE    byTransProtocol; //传输协议类型0-TCP,  1-UDP,  2-多播方式,  3-RTP
	BYTE    byRes3[2];
	BYTE    sUserName[NAME_LEN];   //设备登陆用户名
	BYTE    sPassWord[PASSWD_LEN]; // 设备登陆密码
	BYTE    byRes2[28];  //预留  
}NET_DVR_PU_STREAM_URL_CFG, *LPNET_DVR_PU_STREAM_URL_CFG;

typedef union tagNET_DVR_STREAM_TYPE_UNION
{
    NET_DVR_DIRECT_CONNECT_CHAN_INFO	struChanInfo;	      //IP通道信息  类型值为0
    NET_DVR_PU_STREAM_URL				struStreamUrl;        //通过流媒体到url取流，类型值为4
	NET_DVR_PU_STREAM_URL_CFG           struStreamUrlCfg; //通过流媒体到指定监控设备上取流，类型值为6
}NET_DVR_STREAM_TYPE_UNION, *LPNET_DVR_STREAM_TYPE_UNION;

typedef struct tagNET_DVR_STREAM_MODE_TYPE
{
	BYTE					byGetStreamType;	//取流方式，0-直接从设备取流，1-从流媒体取流、2-通过IPServer获得ip地址后取流, 3.通过IPServer找到设备，再通过流媒体去设备的流 4-通过流媒体由URL去取流
	BYTE					byRes[3];			// 保留字节
    NET_DVR_STREAM_TYPE_UNION	uGetStream;			// 不同取流方式结构体
}NET_DVR_STREAM_MODE_TYPE, *LPNET_DVR_STREAM_MODE_TYPE;

// 流来源信息
typedef struct tagNET_DVR_STREAM_SRC_INFO
{
	DWORD					    dwSize;
	NET_DVR_STREAM_MODE_TYPE	struStreamSrcInfo;
}NET_DVR_STREAM_SRC_INFO,*LPNET_DVR_STREAM_SRC_INFO;

// 流录像信息
typedef struct 
{
	DWORD			dwSize;
	NET_DVR_RECORD_V30	struRecordInfo;
}NET_DVR_STREAM_RECORD_INFO, *LPNET_DVR_STREAM_RECORD_INFO;

// 按流ID对时间段加锁
typedef struct tagNET_DVR_STREAM_TIME_LOCK
{
	DWORD			dwSize;				// 结构体大小
	NET_DVR_TIME	strBeginTime;		// 开始时间
	NET_DVR_TIME	strEndTime;			// 结束时间
	NET_DVR_STREAM_INFO struStreamInfo;		// 流信息
	DWORD			dwRecordType;		// 录像类型:  0xff－全部，－定时录像，-移动侦测，－报警触发，-报警触发或移动侦测，-报警触发和移动侦测，-命令触发，-手动录像，-智能录像(同文件查找)
	DWORD			dwLockDuration;		// 锁定持续时间,单位秒，0xffffffff表示永久锁定
	NET_DVR_TIME_EX		strUnlockTimePoint;	// 加锁时有效，当dwLockDuration不为永久锁定时，锁定持续的时间到此时间点就自动解锁
	BYTE				byRes[4];
}NET_DVR_STREAM_TIME_LOCK, *LPNET_DVR_STREAM_TIME_LOCK;

// 按ID+时间回放结构体
typedef struct tagNET_DVR_VOD_PARA
{
	DWORD				dwSize;
	NET_DVR_STREAM_INFO struIDInfo; 
    NET_DVR_TIME		struBeginTime;
	NET_DVR_TIME		struEndTime;
	HWND				hWnd;
	BYTE				byDrawFrame; //0:不抽帧，1：抽帧
	BYTE				byVolumeType;  //0-普通录像卷  1-存档卷
	BYTE				byVolumeNum;  //卷号，目前指存档卷号
	BYTE         		byRes1;
	DWORD			   	dwFileIndex;  	//存档卷上的录像文件索引，搜索存档卷录像时返回的值
	BYTE				byRes2[24];
}NET_DVR_VOD_PARA, *LPNET_DVR_VOD_PARA;

// 手动录像
typedef struct tagNET_DVR_MANUAL_RECORD_PARA
{
	NET_DVR_STREAM_INFO struStreamInfo; 
	DWORD			lRecordType;
	BYTE			byRes[32];
}NET_DVR_MANUAL_RECORD_PARA, *LPNET_DVR_MANUAL_RECORD_PARA;


// CABAC码流压缩性能选项，开启可提高20%，只有模拟通道可以用
typedef struct tagNET_DVR_STREAM_CABAC
{
	DWORD		dwSize;              	//结构体大小
	BYTE 		byCabacEnable;       	//码流压缩性能选项值0 不提升 1 提升
	BYTE  		byRes1[31];          		//保留
}NET_DVR_STREAM_CABAC, *LPNET_DVR_STREAM_CABAC;

#define  MAX_IOSPEED_GROUP_NUM      4 //IO测速组个数
#define  MAX_IOOUT_NUM              4  //最大IO输出口个数
#define  MAX_IOIN_NUM               8  //最大IO输入口个数
#define  MAX_IOIN_NUMEX             10 //最大IO输入口个数(扩展)
#define  MAX_ITC_LANE_NUM           6  //最大车道个数
#define  MAX_LANEAREA_NUM           2  //单车道最大区域个数
#define  ITC_MAX_POLYGON_POINT_NUM	20	//检测区域最多支持20个点的多边形
#define  MAX_ITC_SERIALCHECK_NUM    8 //串口校验类型个数
#define  MAX_LIGHT_NUM              6 //最大交通灯数
#define  MAX_VIDEO_INTERVAL_NUM     2  //最大抓拍间隔数
#define  MAX_VIDEO_DETECT_LIGHT_NUM  12  //视频检测的最大检测区域
#define  MAX_RS485_NUM  12 //485口最大支持数

//IO输出口参数（3.1版本（含）之后）
typedef struct tagNET_ITC_IOOUT_PARAM
{
	DWORD    dwSize;
    BYTE     byDefaultStatus;//IO默认状态：0-低电平，1-高电平 
	BYTE     byIOOutStatus;//IO起效时状态：0-低电平，1-高电平，2-脉冲
	BYTE     byMode; //闪光灯工作方式,按位表示，0-表示工作，1-表示不工作，bit0-视频，bit1-卡口，bit2-违章
	BYTE     byRes1;
	DWORD    dwTimeDelay;//IO有效持续时间，单位us
	WORD     wAheadTime;//输出IO提前时间，单位us
	BYTE     byFreqMulti;		//倍频，数值范围[1,15]
	BYTE     byDutyRate;		//占空比，[0,40%]
	BYTE     byDetectBrightness;/*自动检测亮度使能闪光灯0-不检测；1-检测*/
	BYTE     byBrightnessThreld;/*使能闪光灯亮度阈值，范围[0,100],高于阈值闪*/
	BYTE     byFlashLightEnable;	//设置闪光灯时间使能:0-关;1-开
	BYTE     byStartHour;		//开始时间-小时,取值范围0-23
	BYTE     byStartMinute;		//开始时间-分,取值范围0-59
	BYTE     byEndHour;		//结束时间-小时,取值范围0-23
	BYTE     byEndMinute;		//结束时间-分,取值范围0-59
	BYTE     byAutoPlateBrightness;// 车牌亮度自动使能闪光灯 0-不启用 1-启用
    BYTE     byRes[8];
}NET_ITC_IOOUT_PARAM, *LPNET_ITC_IOOUT_PARAM;

typedef enum _ITC_TRIGGERMODE_TYPE_
{
	ITC_POST_IOSPEED_TYPE              = 0x1,  //IO测速（卡口）
	ITC_POST_SINGLEIO_TYPE             = 0x2,  //单IO触发（卡口）
	ITC_POST_RS485_TYPE                = 0x4,  //RS485车检器触发（卡口）
	ITC_POST_RS485_RADAR_TYPE          = 0x8,  //RS485雷达触发（卡口）
	ITC_POST_VIRTUALCOIL_TYPE          = 0x10,   //虚拟线圈触发（卡口）
	ITC_POST_HVT_TYPE				   = 0x20,	//混行卡口视频触发（卡口）
	ITC_EPOLICE_IO_TRAFFICLIGHTS_TYPE  = 0x100,  //IO红绿灯（电警）
	ITC_EPOLICE_RS485_TYPE             = 0x200,  //RS485车检器电警触发（电警）
	ITC_PE_RS485_TYPE                  = 0x10000,  //RS485车检器卡式电警触发（卡式电警）
	ITC_VIDEO_EPOLICE_TYPE             = 0x20000 //视频电警触发（卡式电警）
}ITC_TRIGGERMODE_TYPE;

//能力集接口的输出参数，对应pOutBuf参数
typedef struct tagNET_ITC_TRIGGERMODE_ABILITY
{
	DWORD dwSize;
	DWORD dwTriggerType; //触发类型，按位表示，定义ITC_TRIGGERMODE_ABILITY定义，根据输入的能力类型不同，此处返回的触发类型也不同
    BYTE byRes[16]; 
}NET_ITC_TRIGGERMODE_ABILITY, *LPNET_ITC_TRIGGERMODE_ABILITY;

typedef struct tagNET_ITC_INTERVAL_PARAM    
{
    BYTE byIntervalType;	//间隔类型（默认按时间），0-时间起效,1-距离起效
    BYTE byRes1[3];
    WORD wInterval[MAX_INTERVAL_NUM];//连拍间隔时间（单位ms）或连拍间隔距离（单位分米），当byIntervalType为0时，表示间隔时间，当byIntervalType为1时，表示距离
    BYTE byRes[8];
}NET_ITC_INTERVAL_PARAM, *LPNET_ITC_INTERVAL_PARAM;

//牌识参数
typedef struct tagNET_ITC_PLATE_RECOG_PARAM
{
    BYTE byDefaultCHN[MAX_CHJC_NUM]; /*设备运行省份的汉字简写*/
    BYTE byEnable; //是否启用该区域牌识，0-否，1-是
    DWORD dwRecogMode;  /*识别的类型，
	    bit0-背向识别：0-正向车牌识别，1-背向识别(尾牌识别) ； 
		bit1-大车牌识别或小车牌识别：0-小车牌识别，1-大车牌识别 ；
		bit2-车身颜色识别：0-不采用车身颜色识别，在背向识别或小车牌识别时禁止启用，1-车身颜色识别；
		bit3-农用车识别：0-不采用农用车识别，1-农用车识别； 
		bit4-模糊识别：0-不采用模糊识别，1-模糊识别；
		bit5-帧定位或场定位：0-帧定位，1-场定位；
		bit6-帧识别或场识别：0-帧识别，1-场识别； 
		bit7-晚上或白天：0-白天，1-晚上 
		bit8-摩托车识别：0-不采用摩托车识别，1-摩托车识别;
		bit9-场景模式：0-电警/多帧，1-卡口；
		bit10-微小车牌：0-不启用，1-启用微小车牌识别(像素60～80)*/
	BYTE byVehicleLogoRecog;//车标识别 0-不启用，1-启用  
	BYTE byRes[31];
}NET_ITC_PLATE_RECOG_PARAM, *LPNET_ITC_PLATE_RECOG_PARAM;

//多边型结构体
typedef struct tagNET_ITC_POLYGON
{
	DWORD dwPointNum; //有效点 大于等于3，若是3点在一条线上认为是无效区域，线交叉认为是无效区域 
	NET_VCA_POINT  struPos[ITC_MAX_POLYGON_POINT_NUM]; //多边形边界点,最多20个 
}NET_ITC_POLYGON, *LPNET_ITC_POLYGON;

typedef struct tagNET_ITC_PLATE_RECOG_REGION_PARAM    
{
	BYTE byMode; //区域类型，0-矩形，1-多边形
	BYTE byRes1[3];
	union
	{
		NET_VCA_RECT struRect;  //矩形区域
		NET_ITC_POLYGON struPolygon; //多边形区域
	}uRegion;
	BYTE  byRes[16];    //保留
}NET_ITC_PLATE_RECOG_REGION_PARAM, *LPNET_ITC_PLATE_RECOG_REGION_PARAM;

//单组IO测速参数
typedef struct tagNET_ITC_SINGLE_IOSPEED_PARAM
{
    BYTE byEnable; //是否启用，0-不启用，1-启用
    BYTE byTrigCoil1; //第一线圈关联IO，0-IO1,1-IO2,2-IO3,3-IO4,4-IO5,5-IO6
    BYTE byCoil1IOStatus;//第一线圈IO输入口状态，0-下降沿（默认），1-上升沿，2-上升沿和下降沿，3-高电平，4-低电平
    BYTE byTrigCoil2; //第二线圈关联IO，0-IO1,1-IO2,2-IO3,3-IO4,4-IO5,5-IO6
    BYTE byCoil2IOStatus;//第二线圈IO输入口状态，0-下降沿（默认），1-上升沿，2-上升沿和下降沿，3-高电平，4-低电平
    BYTE byRelatedDriveWay;//关联的车道号
    BYTE byTimeOut;//超时时间（默认10），单位s
	BYTE byRelatedIOOutEx;//第0位表示IO输出口1，以此类推，0-不关联，1-关联 支持关联到8个(兼容byRelatedIOOut字段)
    DWORD dwDistance;//线圈距离（默认1000）,单位：厘米
    BYTE byCapSpeed;//起拍速度（默认30），单位km/h
    BYTE bySpeedLimit;//限速值（默认60），单位km/h
    BYTE bySpeedCapEn; //是否启用超速抓拍，0-否，1-是
    BYTE bySnapTimes1; //线圈1抓拍次数（默认不抓拍），0-不抓拍，非0-连拍次数，最大5次 
    BYTE bySnapTimes2; //线圈2抓拍次数（默认1），0-不抓拍，非0-连拍次数，最大5次
	BYTE byBigCarSpeedLimit; //大车车速限制值
    BYTE byRes2;
    BYTE byIntervalType;	//间隔类型（默认按时间），0-时间起效,1-距离起效
	WORD wInterval1[MAX_INTERVAL_NUM];//线圈1连拍间隔时间（单位ms）或连拍间隔距离（单位分米），当byIntervalType为0时，表示间隔时间，当byIntervalType为1时，表示距离
	WORD wInterval2[MAX_INTERVAL_NUM];//线圈2连拍间隔时间（单位ms）或连拍间隔距离（单位分米），当byIntervalType为0时，表示间隔时间，当byIntervalType为1时，表示距离
    BYTE byRelatedIOOut[MAX_IOOUT_NUM]; //关联的IO输出口(可以同时关联多个)，数组0表示IO输出口1，数组1表示IO输出口2，以此类推，0-不关联，1-关联
    BYTE byFlashMode;   //闪光灯闪烁模式，0-同时闪，1-轮流闪
	BYTE byLaneType;   //车道类型，0-未配置、1-高速公路、2-城市快速路、0xff-其他道路
    BYTE byRes3[2];
    NET_ITC_PLATE_RECOG_REGION_PARAM struPlateRecog[MAX_LANEAREA_NUM]; //牌识参数(可用牌识区域1个，保留一个)
    BYTE  byRes[32];
}NET_ITC_SINGLE_IOSPEED_PARAM, *LPNET_ITC_SINGLE_IOSPEED_PARAM;

//卡口IO测速参数
typedef struct tagNET_ITC_POST_IOSPEED_PARAM
{
    NET_ITC_PLATE_RECOG_PARAM struPlateRecog; //牌识参数
    NET_ITC_SINGLE_IOSPEED_PARAM struSingleIOSpeed[MAX_IOSPEED_GROUP_NUM]; //单个IO测速组参数
    BYTE  byRes[32];
}NET_ITC_POST_IOSPEED_PARAM, *LPNET_ITC_POST_IOSPEED_PARAM;

//单IO参数
typedef struct tagNET_ITC_SINGLEIO_PARAM
{
    BYTE byDefaultStatus;//IO触发默认状态：0-低电平，1-高电平
    BYTE byRelatedDriveWay;//关联的车道号
    BYTE bySnapTimes; //抓拍次数（默认1），0-不抓拍，非0-连拍次数，最大5
	BYTE byRelatedIOOutEx;//第0位表示IO输出口1，以此类推，0-不关联，1-关联 支持关联到8个(兼容byRelatedIOOut字段)
    NET_ITC_INTERVAL_PARAM struInterval; //抓拍间隔参数
    BYTE byRelatedIOOut[MAX_IOOUT_NUM]; //关联的IO输出口，可以同时关联多个
    BYTE byFlashMode;   //闪光灯闪烁模式，0-同时闪，1-轮流闪
	BYTE byEnable;//单IO使能标志0-不启用，1-启用 (Remark:在能力返回支持 bySupport&0x20，表示是否支持单IO触发界面IO使能配置 时生效)
    BYTE byRes2[2];
    NET_ITC_PLATE_RECOG_REGION_PARAM struPlateRecog[MAX_LANEAREA_NUM]; //牌识参数
    BYTE  byRes[32];
}NET_ITC_SINGLEIO_PARAM, *LPNET_ITC_SINGLEIO_PARAM;

//单IO触发参数
typedef struct tagNET_ITC_POST_SINGLEIO_PARAM
{
    NET_ITC_PLATE_RECOG_PARAM struPlateRecog; //牌识参数
    NET_ITC_SINGLEIO_PARAM struSingleIO[MAX_IOIN_NUMEX]; //单个IO触发参数
    BYTE  byRes[360];
}NET_ITC_POST_SINGLEIO_PARAM, *LPNET_ITC_POST_SINGLEIO_PARAM;

typedef struct tagNET_ITC_LANE_PARAM
{
    BYTE byEnable; //是否启用该车道，0-不启用，1-启用
    BYTE byRelatedDriveWay;//关联的车道号
    WORD wDistance; //线圈距离，计算速度
    WORD wTrigDelayTime; //触发延迟时间（默认200），单位：毫秒
    BYTE byTrigDelayDistance; //触发延迟距离（默认0），单位：分米
    BYTE bySpeedCapEn; //是否启用超速抓拍，0-否，1-是
    BYTE bySignSpeed;//标志限速，单位km/h
	BYTE bySpeedLimit;//限速值，单位km/h
	BYTE bySnapTimes; //抓拍次数（默认1），0-不抓拍，非0-连拍次数，最大5
	BYTE byOverlayDriveWay; //OSD叠加的车道号
    NET_ITC_INTERVAL_PARAM struInterval; //抓拍间隔参数
    BYTE byRelatedIOOut[MAX_IOOUT_NUM]; //关联的IO输出口，可以同时关联多个
    BYTE byFlashMode;   //闪光灯闪烁模式，0-同时闪，1-轮流闪
	BYTE byCartSignSpeed;//标志限速(大车)，单位km/h
	BYTE byCartSpeedLimit;//限速值（大车），单位km/h
    BYTE byRelatedIOOutEx;//第0位表示IO输出口1，以此类推，0-不关联，1-关联 支持关联到8个(兼容byRelatedIOOut字段)
    NET_ITC_PLATE_RECOG_REGION_PARAM struPlateRecog[MAX_LANEAREA_NUM]; //车道牌识参数
	BYTE byLaneType;   //车道类型，0-未配置、1-高速公路、2-城市快速路、0xff-其他道路
	BYTE byRes[15];
}NET_ITC_LANE_PARAM, *LPNET_ITC_LANE_PARAM;

//卡口RS485车检器触发参数
typedef struct tagNET_ITC_POST_RS485_PARAM
{
    BYTE byRelatedLaneNum;//关联的车道个数
	BYTE byTriggerSpareMode; //触发备用模式，0-默认，1-卡口虚拟线圈模式
	BYTE byFaultToleranceTime;//容错时间(单位:分钟)，用于检测车检器是否正常的最大时间
    BYTE byRes1; 
    NET_ITC_PLATE_RECOG_PARAM struPlateRecog; //牌识参数
    NET_ITC_LANE_PARAM struLane[MAX_ITC_LANE_NUM]; //关联的车道参数
    BYTE  byRes[32];
}NET_ITC_POST_RS485_PARAM, *LPNET_ITC_POST_RS485_PARAM;

typedef struct tagNET_ITC_RADAR_PARAM
{
	BYTE    byRadarType;	//雷达类型，0-无雷达,1-安道雷雷达，2-奥利维亚，3-川速微波4,雷达接IO扩展盒(此参数在卡口虚拟线圈、混行卡口界面中使用，卡口RS485雷达不使用),0xff-其它类型
	BYTE    byLevelAngle;   //与水平线所成角度,默认为25°(0到90度)
	WORD    wRadarSensitivity; //雷达灵敏度 
	WORD    wRadarSpeedValidTime;//雷达速度有效时间(0~2000] ,0表示不支持
	BYTE    byRes1[2];
	float  	fLineCorrectParam;//线性矫正参数[0.0~2.0]
	int  	iConstCorrectParam;//常量矫正参数[-100~100]
	BYTE    byRes2[8];
}NET_ITC_RADAR_PARAM, *LPNET_ITC_RADAR_PARAM;

typedef struct tagNET_ITC_RS485_ACCESS_INFO_COND  //条件结构
{
    DWORD dwSize;
    DWORD dwChannel;
    DWORD dwTriggerModeType;
    BYTE  byAssociateRS485No;//关联的RS485号 1～5 (唯一值)
	//	BYTE  byModeType; //0～预留，1～雷达，2～车检器，3～信号灯检测器
    BYTE  byRes[15];
}NET_ITC_RS485_ACCESS_INFO_COND,*LPNET_ITC_RS485_ACCESS_INFO_COND;

typedef struct tagNET_ITC_RADAR_INFO_PARAM
{
	NET_ITC_RADAR_PARAM  struRadarParam;//24
	BYTE  byAssociateLaneNo;//关联的车道号1～99 (这个值可以在不同RS485口重复)
	BYTE  byRes[103];
}NET_ITC_RADAR_INFO_PARAM, *LPNET_ITC_RADAR_INFO_PARAM;

typedef union tagNET_ITC_ACCESS_DEVINFO_PARAM_UNION
{
	BYTE uLen[128];
	NET_ITC_RADAR_INFO_PARAM struRadarInfoParam;//雷达参数配置
}NET_ITC_ACCESS_DEVINFO_PARAM_UNION, *LPNET_ITC_ACCESS_DEVINFO_PARAM_UNION;

typedef struct tagNET_ITC_RS485_ACCESS_CFG //144  配置结构
{
	DWORD dwSize;
	BYTE  byModeType;//0～预留，bit1～雷达，bit2～车检器，bit3～信号灯检测器
	BYTE  byRes[3];
	NET_ITC_ACCESS_DEVINFO_PARAM_UNION uITCAccessDevinfoParam; //64
	BYTE  byRes1[12];
}NET_ITC_RS485_ACCESS_CFG,*LPNET_ITC_RS485_ACCESS_CFG;

//2013-07-09 雷达关联车道扩展
typedef struct tagNET_ITC_RS485_ACCESS_INFO
{
	DWORD dwSize;
	NET_ITC_RADAR_PARAM  struRadar[MAX_ITC_LANE_NUM];//多车道雷达信息
	//根据能力集开发显示，不支持的默认为0，不显示  （有几个车道支持几个）
	BYTE  byRes[20];
}NET_ITC_RS485_ACCESS_INFO, *LPNET_ITC_RS485_ACCESS_INFO;


//卡口RS485雷达触发参数
typedef struct tagNET_ITC_POST_RS485_RADAR_PARAM
{
	BYTE byRelatedLaneNum;//关联的车道个数
	BYTE byRes1[3];
    NET_ITC_PLATE_RECOG_PARAM struPlateRecog; //牌识参数
    NET_ITC_LANE_PARAM struLane[MAX_ITC_LANE_NUM]; //关联的车道参数
    NET_ITC_RADAR_PARAM struRadar;  //雷达参数
    BYTE  byRes[32];
}NET_ITC_POST_RS485_RADAR_PARAM, *LPNET_ITC_POST_RS485_RADAR_PARAM;

typedef struct tagNET_ITC_VTLANE_PARAM
{
	BYTE byRelatedDriveWay;//关联的车道号
	BYTE bySpeedCapEn; //是否启用超速抓拍，0-否，1-是
	BYTE bySignSpeed;//标志限速，单位km/h
	BYTE bySpeedLimit;//限速值，单位km/h
	BYTE bySnapTimes; //抓拍次数（默认1），0-不抓拍，非0-连拍次数，最大5
	BYTE byBigCarSignSpeed;///*大车标志限速，单位km/h*/
	BYTE byBigCarSpeedLimit;/*大车限速值，单位km/h*/
	BYTE byRelatedIOOutEx;//第0位表示IO输出口1，以此类推，0-不关联，1-关联 支持关联到8个(兼容byRelatedIOOut字段)
	NET_ITC_INTERVAL_PARAM struInterval; //抓拍间隔参数
	BYTE byRelatedIOOut[MAX_IOOUT_NUM]; //关联的IO输出口，可以同时关联多个
	BYTE byFlashMode;   //闪光灯闪烁模式，0-同时闪，1-轮流闪
	BYTE byRes2[3];
	NET_ITC_PLATE_RECOG_REGION_PARAM struPlateRecog[MAX_LANEAREA_NUM]; //车道牌识参数
    NET_VCA_LINE struLine; //车道线
}NET_ITC_VTLANE_PARAM, *LPNET_ITC_VTLANE_PARAM;

typedef struct tagNET_ITC_VTCOIL_INFO
{
	NET_VCA_RECT struLaneRect;  /*虚拟线圈区域*/
	BYTE byTrigFlag; //触发标志，0-车头触发；1-车尾触发；2-车头/车尾都触发
	BYTE byTrigSensitive;  //触发灵敏度，1-100
	BYTE byRelatedIOOut[MAX_IOOUT_NUM]; //关联的IO输出口(可以同时关联多个)，数组0表示IO输出口1，数组1表示IO输出口2，以此类推，0-不关联，1-关联
	BYTE byFlashMode;   //闪光灯闪烁模式，0-同时闪，1-轮流闪
	BYTE byLaneType;   //车道类型，0-未配置、1-高速公路、2-城市快速路、0xff-其他道路
	BYTE byEnableRadar; //是否启用雷达测速，0-否，1-是
	NET_ITC_VTLANE_PARAM struLane; //关联的车道参数
    BYTE byRes[32];
}NET_ITC_VTCOIL_INFO, *LPNET_ITC_VTCOIL_INFO;

//卡口虚拟线圈触发参数
typedef struct tagNET_ITC_POST_VTCOIL_PARAM
{
    BYTE    byRelatedLaneNum;//关联的车道个数
    BYTE    byIsDisplay; //视频中是否显示虚拟线圈，0-不显示，1-显示
    BYTE    byLoopPos; //晚间触发线圈的偏向（默认10）
    BYTE    byPolarLenType; /*偏振镜类型，0：不加偏振镜；1：加施耐德偏振镜。*/
	BYTE    byDayAuxLightMode; /*白天辅助照明模式，0：无辅助照明；1：LED灯照明；2：闪光灯照明*/
	BYTE    byVideoLaneNO; //视频参考亮度的参考车道号
	BYTE    byVideoLowTh; /*视频参考亮度低阈值初始化值（默认40）*/
	BYTE    byVideoHighTh; /*视频参考亮度高阈值初始化值（默认55）*/
	BYTE    byRecordMode; //录像标志：0-不录像，1-录像
	BYTE 	bySnapMode;//抓拍模式：0-频闪模式；1-爆闪模式
	BYTE 	byRes1[2];
	WORD    wResolutionX;/* 设备当前分辨率宽*/
	WORD    wResolutionY;/* 设备当前分辨率高*/
	DWORD   dwDayInitExp; /*视频白天曝光时间的初始值2000*/
	DWORD   dwDayMaxExp; /*视频白天曝光时间的最大值20000*/
	DWORD   dwNightExp; /*晚间视频曝光时间的设置值3000*/
	DWORD   dwSnapExp; /*抓拍曝光时间*/
	BYTE    byDayInitGain; /*视频白天增益的初始值200*/
	BYTE    byDayMaxGain; /*视频白天增益的最大值400*/
	BYTE    byNightGain; /*晚间视频增益*/
	BYTE    bySnapGain; /*抓拍增益*/
	DWORD   dwSceneMode; //场景模式， 详见SCENE_MODE
	NET_DVR_GEOGLOCATION struGeogLocation; //地址位置(默认浙江)
	NET_ITC_PLATE_RECOG_PARAM struPlateRecog; //牌识参数
	NET_ITC_VTCOIL_INFO struVtCoil[MAX_VL_NUM]; //虚拟线圈参数
	NET_ITC_RADAR_PARAM struRadar;  //雷达参数
	NET_VCA_LINE struLine; //右车道线
    BYTE  byRes[16];
}NET_ITC_POST_VTCOIL_PARAM, *LPNET_ITC_POST_VTCOIL_PARAM;

//单组IO红绿灯参数
typedef struct tagNET_ITC_SINGLE_IOTL_PARAM
{
    BYTE byEnable; //是否启用，0-不启用，1-启用
	BYTE byLightIO; //红绿灯IO，0-IO1,1-IO2,2-IO3,3-IO4,4-IO5,5-IO6
	BYTE byTrafficLight; //红绿灯有效状态0-高电平红灯，低电平绿灯；1-高电平绿灯，低电平红灯
	BYTE byTrigIO;//触发的IO号，0-IO1,1-IO2,2-IO3,3-IO4,4-IO5,5-IO6
	BYTE byTrigIOStatus;//触发IO口的状态（默认0），0-下降沿，1-上升沿，2-上升沿和下降沿，3-高电平，4-低电平
	BYTE byRelatedDriveWay;//关联的车道号
	BYTE byRecordEnable;//闯红灯周期录像标志，0-不录像，1-录像
	BYTE byRecordType;//闯红灯录像类型，0-预录，1-延时录像
	BYTE byPreRecordTime;//闯红灯录像片段预录时间（默认0），单位：秒
	BYTE byRecordDelayTime;//闯红灯录像片段延时时间（默认0），单位：秒
	BYTE byRecordTimeOut;//闯红灯周期录像超时时间（秒）
	BYTE byRedSnapTimes; //红灯抓拍次数，0-不抓拍，非0-连拍次数，最大5次 
	BYTE byGreenSnapTimes; //绿灯抓拍次数，0-不抓拍，非0-连拍次数，最大5次
	BYTE byRelatedIOOutEx;//第0位表示IO输出口1，以此类推，0-不关联，1-关联 支持关联到8个(兼容byRelatedIOOut字段)
	BYTE byRes1;
	BYTE byIntervalType;	//间隔类型（默认按时间），0-时间起效,1-距离起效
	WORD wRedInterval[MAX_INTERVAL_NUM];//红灯连拍间隔时间（单位ms）或连拍间隔距离（单位分米），当byIntervalType为0时，表示间隔时间，当byIntervalType为1时，表示距离
	WORD wGreenInterval[MAX_INTERVAL_NUM];//绿灯连拍间隔时间（单位ms）或连拍间隔距离（单位分米），当byIntervalType为0时，表示间隔时间，当byIntervalType为1时，表示距离
	BYTE byRelatedIOOut[MAX_IOOUT_NUM]; //关联的IO输出口，可以同时关联多个
	BYTE byFlashMode;   //闪光灯闪烁模式，0-同时闪，1-轮流闪
	BYTE byRes2[3];
	NET_ITC_PLATE_RECOG_REGION_PARAM struPlateRecog[MAX_LANEAREA_NUM]; //牌识区域参数
    BYTE  byRes[32];
}NET_ITC_SINGLE_IOTL_PARAM, *LPNET_ITC_SINGLE_IOTL_PARAM;

//电警IO红绿灯参数
typedef struct tagNET_ITC_EPOLICE_IOTL_PARAM
{
	NET_ITC_PLATE_RECOG_PARAM struPlateRecog; //牌识参数
	NET_ITC_SINGLE_IOTL_PARAM struSingleIOTL[MAX_IOSPEED_GROUP_NUM]; //单组IO红绿灯参数
    BYTE  byRes[32];
}NET_ITC_EPOLICE_IOTL_PARAM, *LPNET_ITC_EPOLICE_IOTL_PARAM;

typedef enum _ITC_SERIAL_PROTOCOL_
{
	ITC_PROTOCOL_UNKNOW = 0, /*未知*/
	ITC_SINGLE_COIL_PROTOCOL_MODE1 = 1, /*单线圈车检器协议模式1（显示为：单_进1_出1_延1_1），到达、离开、离开延时抓拍，离开牌识，上传3张车辆图片和车牌结果*/
	ITC_DOUBLE_COIL_PROTOCOL_MODE1 = 2, /*双线圈车检器协议模式1（显示为：双_进1_出1_出2_1），到达1、离开1、离开2抓拍，离开1牌识，上传3张车辆图片和车牌结果（默认）*/
	ITC_DOUBLE_COIL_PROTOCOL_MODE2 = 3, /*双线圈车检器协议模式2（显示为：双_出1_出2_延2_1），离开1、离开2、离开2延时抓拍，离开1牌识，上传3张车辆图片和车牌结果*/
	ITC_DOUBLE_COIL_PROTOCOL_MODE3 = 4, /*双线圈车检器协议模式3（显示为：双_进2_出1_延2_1），进入2、离开1、离开2延时抓拍，离开1牌识，上传3张车辆图片和车牌结果*/
	ITC_DOUBLE_COIL_PROTOCOL_MODE4 = 5, /*双线圈车检器协议模式4（显示为：双/三_进2_出2_延2_1），到达2、离开2、离开2延时抓拍，离开1牌识，上传3张车辆图片和车牌结果*/
	ITC_DOUBLE_COIL_PROTOCOL_MODE5 = 6, /*双线圈车检器协议模式5（显示为：双/三_进2_出2_延2_2），到达2、离开2、离开2延时抓拍，到达2、离开1均牌识，上传3张车辆图片和置信度高的车牌结果（默认）*/
	ITC_DOUBLE_COIL_PROTOCOL_MODE6 = 7, /*双线圈车检器协议模式6（显示为：双/三_进1_出2_延2_2），到达1、离开2、离开2延时抓拍，到达1、离开1均牌识，上传3张车辆图片和置信度高的车牌结果*/
	ITC_DOUBLE_COIL_PROTOCOL_MODE7 = 8, /*双线圈车检器协议模式7（显示为：双_进1_出1_延2_1），到达1、离开1、离开2延时抓拍，离开1牌识，上传车辆图片（卡口离开1，闯红灯到达1、离开1、离开2延时）和车牌结果*/
	ITC_DOUBLE_COIL_PROTOCOL_MODE8 = 9, /*双线圈车检器协议模式8（显示为：双_进1_出1_延2_2），到达1、离开1、离开2延时抓拍，到达1、离开1均牌识，上传车辆图片（卡口离开1，闯红灯到达1、离开1、离开2延时）和置信度高的车牌结果（默认）*/
	ITC_SINGLE_COIL_PROTOCOL_MODE2 = 10, /*单线圈车检器协议模式2（显示为：单_进1_出1_延1_2），到达、离开、离开延时抓拍，到达、离开均牌识，上传车辆图片（卡口离开，闯红灯到达、离开、离开延时）和置信度高的车牌结果（默认）*/
	ITC_OTHER_PROTOCOL = 0xff /*其它车检器协议(用于老demo参数配置，3.3之后版本关联的demo和控件均不支持此值)*/
}ITC_SERIAL_PROTOCOL;

//正常过车逻辑抓拍类型
typedef enum _ITC_NORMAL_PASS_SERIAL_PROTOCOL_
{
	ITC_NORMAL_PASS_SERIAL_UNKNOW     =  0,   //未知
	ITC_NORMAL_PASS_PROTOCOL_MODE1  = 1,  //单线圈，离开抓拍，牌识上传（默认）
	ITC_NORMAL_PASS_PROTOCOL_MODE2 =2,  //单线圈，到达、离开抓拍，均牌识，仅上传离开车辆图片和置信度高的车牌结果
	ITC_NORMAL_PASS_PROTOCOL_MODE3 =3,  //双线圈，离开1抓拍，牌识上传（默认）
	ITC_NORMAL_PASS_PROTOCOL_MODE4 =4, //双线圈，到达1、离开1抓拍，均牌识，仅上传离开1车辆图片和置信度高的车牌结果
	ITC_NORMAL_PASS_PROTOCOL_MODE5 =5, //双线圈，到达2、离开1抓拍，均牌识，仅上传离开1车辆图片和置信度高的车牌结果
}ITC_NORMAL_PASS_SERIAL_PROTOCOL;

//逆行违规逻辑抓拍类型
typedef enum _ITC_INVERSE_SERIAL_PROTOCOL_
{
	ITC_INVERSE_SERIAL_UNKNOW     =  0,   //未知
	ITC_INVERSE_PROTOCOL_MODE1  = 1,  //不抓拍
	ITC_INVERSE_PROTOCOL_MODE2 =2,  //到达1连抓2张、离开2抓拍，到达1两张均牌识，上传3张车辆图片和置信度高的车牌结果
	ITC_INVERSE_PROTOCOL_MODE3 =3,  //到达1、离开2抓拍，到达1牌识，上传2张车辆图片和车牌结果
}ITC_INVERSE_SERIAL_PROTOCOL;

//超速违规逻辑抓拍类型
typedef enum _ITC_SPEED_SERIAL_PROTOCOL_
{
	ITC_SPEED_SERIAL_UNKNOW     =  0,   //未知
	ITC_SPEED_PROTOCOL_MODE1  = 1,  //不抓拍
	ITC_SPEED_PROTOCOL_MODE2 =2,  //双/三线圈，离开1，离开2，离开2延时抓拍，离开1牌识，上传车辆图片（卡口离开1，超速离开1、离开2、离开2延时）和车牌结果
	ITC_SPEED_PROTOCOL_MODE3 =3,  //双/三线圈，离开1，离开2，离开2延时抓拍，离开1牌识，上传车辆图片（卡口离开1，超速离开1、离开2）和车牌结果
}ITC_SPEED_SERIAL_PROTOCOL;

//车检器参数
typedef struct tagNET_ITC_SERIAL_INFO
{
	BYTE bySerialProtocol; //车检器协议类型，详见ITC_SERIAL_PROTOCOL
	BYTE byIntervalType;	//间隔类型（默认按时间），0-时间起效,1-距离起效
	WORD wInterval;//连拍间隔时间（单位ms）或连拍间隔距离（单位分米），当byIntervalType为0时，表示间隔时间，当byIntervalType为1时，表示距离
	BYTE byNormalPassProtocol; //正常过车抓拍协议类型，详见ITC_NORMAL_PASS_SERIAL_PROTOCOL
	BYTE byInverseProtocol; //逆行抓拍协议类型，详见ITC_INVERSE_SERIAL_PROTOCOL
	BYTE bySpeedProtocol; //超速抓拍协议类型，详见ITC_SPEED_SERIAL_PROTOCOL
    BYTE byRes[9];
}NET_ITC_SERIAL_INFO, *LPNET_ITC_SERIAL_INFO;

typedef struct tagNET_ITC_EPOLICE_LANE_PARAM
{
	BYTE byEnable; //是否启用该车道，0-不启用，1-启用
	BYTE byRelatedDriveWay;//关联的车道号
	WORD wDistance; //线圈距离，单位厘米
	BYTE byRecordEnable;//闯红灯周期录像标志，0-不录像，1-录像
	BYTE byRecordType;//闯红灯录像类型，0-预录，1-延时录像
	BYTE byPreRecordTime;//闯红灯录像片段预录时间（默认0），单位：秒
	BYTE byRecordDelayTime;//闯红灯录像片段延时时间（默认0），单位：秒
	BYTE byRecordTimeOut;//闯红灯周期录像超时时间（秒）
	BYTE bySignSpeed;//标志限速(卡式电警模式有效)，单位km/h
	BYTE bySpeedLimit;//限速值(卡式电警模式有效)，单位km/h
	BYTE byOverlayDriveWay; //OSD叠加的车道号
	NET_ITC_SERIAL_INFO struSerialInfo; //车检器参数
	BYTE byRelatedIOOut[MAX_IOOUT_NUM]; //关联的IO输出口，可以同时关联多个
	BYTE byFlashMode;   //闪光灯闪烁模式，0-同时闪，1-轮流闪
	BYTE bySerialType; //车检器类型，0-私有车检器，1-私有OEM车检器，2-其他车检器
	BYTE byRelatedIOOutEx;//第0位表示IO输出口1，以此类推，0-不关联，1-关联 支持关联到8个(兼容byRelatedIOOut字段)
	BYTE byRes2;
	NET_ITC_PLATE_RECOG_REGION_PARAM struPlateRecog[MAX_LANEAREA_NUM]; //车道牌识参数
	BYTE byBigCarSignSpeed;	///*大车标志限速，单位km/h*/
	BYTE byBigCarSpeedLimit;/*大车限速值，单位km/h*/	
	BYTE byRedTrafficLightChan;//红灯通道号：1～16（红绿灯检测器）
	BYTE byYellowTrafficLightChan;//黄灯通道号：1～16（红绿灯检测器）
    BYTE byRes3[12];
}NET_ITC_EPOLICE_LANE_PARAM, *LPNET_ITC_EPOLICE_LANE_PARAM;

//电警/卡式电警RS485车检器触发参数
typedef struct tagNET_ITC_EPOLICE_RS485_PARAM
{
	BYTE byRelatedLaneNum;//关联的车道个数
	BYTE byTrafficLightSignalSrc;//交通灯信号来源 0～车检器 1～红绿灯检测器
	BYTE byRes1[2];
	NET_ITC_PLATE_RECOG_PARAM struPlateRecog; //牌识参数
	NET_ITC_EPOLICE_LANE_PARAM struLane[MAX_ITC_LANE_NUM]; //关联的车道参数
    BYTE  byRes[32];
}NET_ITC_EPOLICE_RS485_PARAM, *LPNET_ITC_EPOLICE_RS485_PARAM;

//车道属性参数结构
typedef struct tagNET_ITC_LANE_LOGIC_PARAM
{
	BYTE byUseageType; //车道用途类型，详见ITC_LANE_USEAGE_TYPE
	BYTE byDirectionType; //车道方向类型，详见ITC_LANE_DIRECTION_TYPE
    BYTE byRes[34];
}NET_ITC_LANE_LOGIC_PARAM, *LPNET_ITC_LANE_LOGIC_PARAM;

//视频电警线结构
typedef struct tagNET_ITC_LINE
{
	NET_VCA_LINE struLine; //线参数
	BYTE byLineType; //线类型，详见ITC_LINE_TYPE
	BYTE byRes[7];
}NET_ITC_LINE, *LPNET_ITC_LINE;

typedef struct tagNET_ITC_SNAPMODE_PARAM
{
	BYTE 	byVehicleCapMode;//机动车抓拍模式，0-频闪模式；1-爆闪模式
	BYTE 	byNoVehicleCapMode;//非机动车抓拍模式，0-频闪模式；1-爆闪模式
	BYTE 	byPasserCapMode;//行人抓拍模式，0-频闪模式；1-爆闪模式
	BYTE 	byRes[29];
}NET_ITC_SNAPMODE_PARAM, *LPNET_ITC_SNAPMODE_PARAM;

//size = 128
typedef struct tagNET_ITC_HVT_EC_PARAM
{
	DWORD 		dwCapShutter;			//抓拍快门0~65535
	WORD 		wCapGain;			//抓拍增益0～100
	BYTE  		byRes[2];
	DWORD 		dwDayTimeVideoShutter;	//白天曝光时间最大值
	WORD 		wDayTimeVideoGain;		//白天增益最大值
	WORD 		wNightVideoGain;			//晚上增益最大值
	DWORD 		wNightVideoShutter;		//晚上曝光时间最大值
	BYTE  		byRes1[108];
}NET_ITC_HVT_EC_PARAM, *LPNET_ITC_HVT_EC_PARAM;

typedef struct tagNET_ITC_LANE_HVT_PARAM
{
	BYTE byLaneNO; //关联的车道号 1~255（用于叠加和上传）
	BYTE bySignSpeed;	//标志限速，单位km/h 0～255  70
	BYTE bySpeedLimit;	//限速值，单位km/h 0～255    80 实际起效
	BYTE byBigCarSignSpeed;///*大车标志限速，单位km/h*/
	BYTE byBigCarSpeedLimit;/*大车限速值，单位km/h*/
	BYTE bySpeedCapEn; //是否启用超速抓拍，0-否，1-是
	BYTE byCaptureCount;//抓拍张数1～5(正常)
	BYTE byRelatedIOOut;	/*关联的IO输出口(可以同时关联多个)，按位表示IO输出口，第0位表示IO输出口1，以此类推，0-不关联，1-关联*/
	BYTE byFlashMode;		/*闪光灯闪烁模式，0-同时闪，1-轮流闪*/
	BYTE byEnableRadar; //是否启用雷达测速，0-否，1-是
	BYTE byRes2[2];
	DWORD dwCapTarget;	//抓拍类型 bit0 表示机动车 bit1 表示非机动车 bit2 表示行人 0～表示不选择 1～表示选择
	NET_ITC_INTERVAL_PARAM struInterval; //抓拍间隔参数
	BYTE byRes3[24];
	NET_ITC_LANE_LOGIC_PARAM struLane; //车道属性，用byUseageType和byCarDriveDirect
	NET_ITC_LINE struLeftLaneLine;		  //左车道线，线类型为虚线、实线、单黄线和双黄线
	NET_ITC_LINE struRightLaneLine;		  //右车道线，线类型为虚线、实线、单黄线和双黄线
	NET_ITC_POLYGON struPlateRecog;         //牌识区域参数
	NET_ITC_POLYGON struTraceArea;		  //视频触发焦点区域
	NET_VCA_LINE  struForwardTrigLine;	  //正向触发线：一条线段，关心端点位置，目前只支持水平配置，接口按线段的两个端点保存。（一般配置为正向车辆的最佳触发位置）     
	NET_VCA_LINE  struBackwardTrigLine;     //背向触发线：一条线段，关心端点位置，目前只支持水平配置，接口按线段的两个端点保存（一般配置为背向车辆的最佳触发位置）
	NET_VCA_LINE  struLeftTrigLine;		  //左边触发线：一条线段，关心端点位置，目前只支持垂直配置，接口按线段的两个端点保存（一般配置为从左边进入车辆的最佳触发位置）
	NET_VCA_LINE  struRightTrigLine;		  //右边触发线：一条线段，关心端点位置，目前只支持垂直配置，接口按线段的两个端点保存（一般配置为从右边进入车辆的最佳触发位置）
	BYTE byRes4[60];
}NET_ITC_LANE_HVT_PARAM, *LPNET_ITC_LANE_HVT_PARAM;

typedef struct tagNET_ITC_POST_HVT_PARAM
{
	BYTE byLaneNum;//识别的车道个数，1-6 
	BYTE bySceneMode;//0-未知1-城区道路；2-小区出入口
	BYTE byRoadExpBright;//路面期望亮度（视频曝光参数调整的依据之一。在无机动车时，依据此亮度期望值，调整视频曝光参数）
	BYTE byPlateExpBright;//车牌期望亮度（视频曝光参数调整的依据之一。在有机动车通过并识别到车牌时，依据此亮度期望值，对视频曝光参数调整）
	NET_ITC_POLYGON struDetectArea;					//视频检测区域  
	NET_ITC_SNAPMODE_PARAM  struCapMode;//抓拍模式  
	NET_ITC_HVT_EC_PARAM struEcParam;	//曝光控制参数  
	NET_ITC_LANE_HVT_PARAM struLaneParam[MAX_ITC_LANE_NUM]; //单车道属性
	NET_ITC_PLATE_RECOG_PARAM  struPlateRecog;	//牌识参数
	NET_DVR_GEOGLOCATION struGeogLocation;	//地址位置（默认浙江）
	BYTE byRes[324];
}NET_ITC_POST_HVT_PARAM, *LPNET_ITC_POST_HVT_PARAM;

typedef union tagNET_ITC_TRIGGER_PARAM_UNION
{
	DWORD  uLen[1070];			//参数
	NET_ITC_POST_IOSPEED_PARAM    struIOSpeed; //（卡口）IO测速参数 
	NET_ITC_POST_SINGLEIO_PARAM   struSingleIO; //（卡口）单IO参数
	NET_ITC_POST_RS485_PARAM       struPostRs485; //（卡口）RS485车检器参数
	NET_ITC_POST_RS485_RADAR_PARAM  struPostRadar; //（卡口）RS485雷达参数
	NET_ITC_POST_VTCOIL_PARAM     struVtCoil; //（卡口）虚拟线圈参数
	NET_ITC_POST_HVT_PARAM          struHvt;	/*（卡口）混行卡口参数*/
	NET_ITC_EPOLICE_IOTL_PARAM     struIOTL;		//（电警）IO红绿灯参数
	NET_ITC_EPOLICE_RS485_PARAM    struEpoliceRs485; //（电警）RS485车检器触发参数
	NET_ITC_EPOLICE_RS485_PARAM  struPERs485;	//（卡式电警）RS485车检器触发参数
}NET_ITC_TRIGGER_PARAM_UNION, *LPNET_ITC_TRIGGER_PARAM_UNION;

//单个触发参数结构
typedef struct tagNET_ITC_SINGLE_TRIGGERCFG
{
	BYTE  byEnable;	//是否启用该触发模式，0-否，1-是
    BYTE  byRes1[3];
    DWORD dwTriggerType; //触发类型，详见ITC_TRIGGERMODE_TYPE
    NET_ITC_TRIGGER_PARAM_UNION uTriggerParam; //触发参数
    BYTE  byRes[64];
}NET_ITC_SINGLE_TRIGGERCFG, *LPNET_ITC_SINGLE_TRIGGERCFG;

//触发参数结构
typedef struct tagNET_ITC_TRIGGERCFG
{
	DWORD   dwSize;			//结构长度
	NET_ITC_SINGLE_TRIGGERCFG  struTriggerParam;  //单个触发参数
    BYTE    byRes[32];
}NET_ITC_TRIGGERCFG, *LPNET_ITC_TRIGGERCFG;

//单个IO接入信号灯参数
typedef struct tagNET_ITC_SINGLE_IO_LIGHT_PARAM
{
	BYTE byLightType; //交通灯导向类型,0-左转灯,1-直行灯,2-右转灯
	BYTE byRelatedIO; //关联的IO口号
	BYTE byRedLightState; //红灯电平状态，0-高电平红灯，1-低电平红灯
    BYTE byRes[17];
}NET_ITC_SINGLE_IO_LIGHT_PARAM, *LPNET_ITC_SINGLE_IO_LIGHT_PARAM;

//IO接入信号灯参数
typedef struct tagNET_ITC_IO_LIGHT_PARAM
{
	NET_ITC_SINGLE_IO_LIGHT_PARAM struIOLight[MAX_LIGHT_NUM]; //单个IO接入信号灯参数
    BYTE byRes[8];
}NET_ITC_IO_LIGHT_PARAM, *LPNET_ITC_IO_LIGHT_PARAM;

//单个485接入信号灯参数
typedef struct tagNET_ITC_SINGLE_RS485_LIGHT_PARAM
{
	BYTE byLightType; //交通灯导向类型，0-左转灯，1-直行灯，2-右转灯
	BYTE byRelatedLightChan; //关联的红绿灯检测器通道号
	BYTE byInputLight;	//接入的信号灯类型，0-接红灯，1-接绿灯
	BYTE byRelatedYLightChan; //关联的黄灯检测器通道号
    BYTE byRes[16];
}NET_ITC_SINGLE_RS485_LIGHT_PARAM, *LPNET_ITC_SINGLE_RS485_LIGHT_PARAM;

//485接入信号灯参数
typedef struct tagNET_ITC_RS485_LIGHT_PARAM
{
	NET_ITC_SINGLE_RS485_LIGHT_PARAM struRS485Light[MAX_LIGHT_NUM]; //单个485接入信号灯参数
    BYTE byRes[8];
}NET_ITC_RS485_LIGHT_PARAM, *LPNET_ITC_RS485_LIGHT_PARAM;

typedef struct tagNET_POS_PARAM
{
	WORD wLeft;
	WORD wTop;
	WORD wRight;
	WORD wBottom;
}NET_POS_PARAM, *LPNET_POS_PARAM;

//单组视频检测交通信号灯参数结构
typedef struct tagNET_ITC_SINGLE_VIDEO_DETECT_LIGHT_PARAM
{
	BYTE byLightNum; //交通灯个数
	BYTE byStraightLight; //是否有直行标志灯，0-否 ，1-是
	BYTE byLeftLight; //是否有左转标志灯，0-否，1-是
	BYTE byRightLight; //是否有右转标志灯，0-否，1-是
	BYTE byRedLight;//是否有红灯，0-否，1-是
	BYTE byGreenLight; //是否有绿灯，0-否，1-是
	BYTE byYellowLight; //是否有黄灯，0-否，1-是
	BYTE byRes1;
	NET_POS_PARAM struLightRect; //交通灯区域
    BYTE byRes[24];
}NET_ITC_SINGLE_VIDEO_DETECT_LIGHT_PARAM, *LPNET_ITC_SINGLE_VIDEO_DETECT_LIGHT_PARAM;


//视频检测交通信号灯参数结构(最大可有12个区域检测，488字节)
typedef struct tagNET_ITC_VIDEO_DETECT_LIGHT_PARAM
{
	NET_ITC_SINGLE_VIDEO_DETECT_LIGHT_PARAM struTrafficLight[MAX_VIDEO_DETECT_LIGHT_NUM]; //单个视频检测信号灯参数
	BYTE byRes[8];
}NET_ITC_VIDEO_DETECT_LIGHT_PARAM, *LPNET_ITC_VIDEO_DETECT_LIGHT_PARAM;

//交通信号灯接入参数
typedef union tagNET_ITC_LIGHT_ACCESSPARAM_UNION
{
	DWORD uLen[122];
	NET_ITC_IO_LIGHT_PARAM struIOLight; //IO接入信号灯参数
	NET_ITC_RS485_LIGHT_PARAM struRS485Light; //485接入信号灯参数
	NET_ITC_VIDEO_DETECT_LIGHT_PARAM struVideoDelectLight; //视频检测信号灯参数
}NET_ITC_LIGHT_ACCESSPARAM_UNION, *LPNET_ITC_LIGHT_ACCESSPARAM_UNION;

//交通信号灯参数结构
typedef struct tagNET_ITC_TRAFFIC_LIGHT_PARAM
{
	BYTE bySource; //交通信号灯接入源，0-IO接入，1-RS485接入
	BYTE byRes1[3];
	NET_ITC_LIGHT_ACCESSPARAM_UNION struLightAccess;//信号灯接入参数
    BYTE byRes[32];
}NET_ITC_TRAFFIC_LIGHT_PARAM, *LPNET_ITC_TRAFFIC_LIGHT_PARAM;

//违规检测类型宏定义
typedef enum _ITC_VIOLATION_DETECT_TYPE_
{
    ITC_VIOLATION_POST = 0x01, //卡口抓拍
	ITC_VIOLATION_DRIVELINE = 0x02,//压车道线抓拍
	ITC_VIOLATION_REVERSE = 0x04,//逆行抓拍
	ITC_VIOLATION_REDLIGHT = 0x08,//闯红灯抓拍
	ITC_VIOLATION_DIRECTION = 0x10,//不按导向行驶抓拍
	ITC_VIOLATION_INTERSECTION_CONGEST = 0x20,//路口滞留抓拍
	ITC_VIOLATION_NONDRIVEWAY = 0x40,  //机占非抓拍
	ITC_VIOLATION_CHANGELANE = 0x80, //违法变道
	ITC_VIOLATION_BAN = 0x100, //违法禁令
	ITC_VIOLATION_INTERSECTION_PARK=0x200,//路口停车
	ITC_VIOLATION_GREEN_PARK=0x400//绿灯停车
}ITC_VIOLATION_DETECT_TYPE;

//违规检测参数结构
typedef struct tagNET_ITC_VIOLATION_DETECT_PARAM
{
    DWORD dwVioDetectType; //违规检测类型, 按位表示, 详见ITC_VIOLATION_DETECT_TYPE ,0-不启用,1-启用
	BYTE byDriveLineSnapTimes; //压车道线抓拍张数,2-3
	BYTE byReverseSnapTimes; //逆行抓拍,2-3
	WORD wStayTime; //机占非停留时间（该时间后抓拍），单位s
	BYTE byNonDriveSnapTimes;//机占非抓拍张数2-3
	BYTE byChangeLaneTimes;//违法变道抓拍张数 2-3
	BYTE bybanTimes;//违法禁令抓拍张数2-3
	BYTE byRes2;
	WORD wSnapPosFixPixel; //第2,3张抓拍位置最小偏移(违反信号灯时起效)（单位：像素） 命名需改进
	BYTE byRes1[22];
	WORD wStopLineDis;  //电警第2张违规图片与停止线的最短距离，[0,300]单位(像素)
    BYTE byRes[14];
}NET_ITC_VIOLATION_DETECT_PARAM, *LPNET_ITC_VIOLATION_DETECT_PARAM;

//车道用途类型定义
typedef enum _ITC_LANE_USEAGE_TYPE_
{
	ITC_LANE_USEAGE_UNKNOW     =  0,   //未知
	ITC_LANE_CARRIAGEWAY  = 1,  //正常车道
	ITC_LANE_BUS      = 2,  //公交车专用道
	ITC_LANE_FAST  = 3,  //快车道
	ITC_LANE_SLOW  = 4,  //慢车道
	ITC_LANE_MOTOR     = 5,   //摩托车道
	ITC_LANE_NONMOTOR  = 6,  //非机动车道
	ITC_LANE_REVERSE_LANE = 7, //反向车道
	ITC_LANE_BAN_TRUCKS  = 8, // 禁止货车车道
	ITC_LANE_MIX = 9 //混合车道
}ITC_LANE_USEAGE_TYPE;

//车道方向类型定义
typedef enum _ITC_LANE_DIRECTION_TYPE_
{
	ITC_LANE_DIRECTION_UNKNOW     =  0,   //未知
	ITC_LANE_LEFT      = 1,  //左转
	ITC_LANE_STRAIGHT  = 2,  //直行
	ITC_LANE_LEFT_STRAIGHT = 3, //左转+直行
	ITC_LANE_RIGHT  = 4,  //右转
	ITC_LANE_LEFT_RIGHT = 5, //左转+右转
	ITC_LANE_RIGHT_STRAIGHT = 6, //右转+直行
	ITC_LANE_LEFT_RIGHT_STRAIGHT = 7, //左转+右转+直行
	ITC_LANE_LEFT_WAIT  =  9,  //左转待行
	ITC_LANE_STRAIGHT_WAIT = 10, //直行待行
	ITC_LANE_FORWARD = 11, //正向行驶
	ITC_LANE_BACKWARD = 12, //背向行驶
	ITC_LANE_BOTHWAY = 13 //双向行驶
}ITC_LANE_DIRECTION_TYPE; 

//线类型定义
typedef enum _ITC_LINE_TYPE_
{
	ITC_LINT_UNKNOW     =  0,   //未知
	ITC_LINE_WHITE      = 1,  //车道间的白实线
	ITC_LINE_STOP       = 2, //车道停止线
	ITC_LINE_SINGLE_YELLOW = 3, //单黄线
	ITC_LINE_DOUBLE_YELLOW = 4, //双黄线
	ITC_LINE_GUARD_RAIL = 5, //车道线上有护栏
	ITC_LINE_NO_CROSS = 6, //车辆无法跨越的车道线
	ITC_LINE_DOTTED = 7 //虚线
}ITC_LINE_TYPE;

//违规检测线参数结构
typedef struct tagNET_ITC_VIOLATION_DETECT_LINE
{
	NET_ITC_LINE  struLaneLine; //车道线参数
	NET_ITC_LINE  struStopLine; //停止线参数
	NET_ITC_LINE  struRedLightLine; //闯红灯触发线参数
	NET_ITC_LINE  struCancelLine; //直行触发位置取消线
	NET_ITC_LINE struWaitLine; //待行区停止线参数
    NET_ITC_LINE struRes[8];
}NET_ITC_VIOLATION_DETECT_LINE, *LPNET_ITC_VIOLATION_DETECT_LINE;

//单个车道视频电警触发参数结构
typedef struct tagNET_ITC_LANE_VIDEO_EPOLICE_PARAM
{
	BYTE byLaneNO; //关联的车道号
    BYTE bySensitivity; //线圈灵敏度，[1,100]
	BYTE byEnableRadar;//启用雷达测试0-不启用，1-启用
	BYTE byRes1;
	NET_ITC_LANE_LOGIC_PARAM struLane; //车道参数
	NET_ITC_VIOLATION_DETECT_PARAM struVioDetect; //违规检测参数
	NET_ITC_VIOLATION_DETECT_LINE struLine; //违规检测线
	NET_ITC_POLYGON struPlateRecog; //牌识区域参数
	BYTE byRecordEnable;//闯红灯周期录像标志，0-不录像，1-录像
	BYTE byRecordType;//闯红灯录像类型，0-预录，1-延时录像
	BYTE byPreRecordTime;//闯红灯录像片段预录时间（默认0），单位：秒
	BYTE byRecordDelayTime;//闯红灯录像片段延时时间（默认0），单位：秒
	BYTE byRecordTimeOut;//闯红灯周期录像超时时间（秒）
    BYTE byRes[59];
}NET_ITC_LANE_VIDEO_EPOLICE_PARAM, *LPNET_ITC_LANE_VIDEO_EPOLICE_PARAM;

//视频电警触发参数结构
typedef struct tagNET_ITC_VIDEO_EPOLICE_PARAM
{
	BYTE byEnable;	//是否启用，0-不启用，1-启用
	BYTE byLaneNum; //识别的车道个数
	BYTE byLogicJudge;//闯红灯违规判断逻辑，设置值为：0-按方向，1-按车道
	BYTE byRes1;
	NET_ITC_PLATE_RECOG_PARAM struPlateRecog; //牌识参数
	NET_ITC_TRAFFIC_LIGHT_PARAM struTrafficLight; //交通信号灯参数
	NET_ITC_LANE_VIDEO_EPOLICE_PARAM struLaneParam[MAX_ITC_LANE_NUM]; //单车道参数
	NET_ITC_LINE  struLaneBoundaryLine; //车道边界线（最右边车道的边界线）
	NET_ITC_LINE  struLeftLine; //左转弯分界线
	NET_ITC_LINE  struRightLine; //右转弯分界线
	NET_ITC_LINE  struTopZebraLine; //上部斑马线
	NET_ITC_LINE  struBotZebraLine; //下部斑马线
    BYTE  byRes[32];
}NET_ITC_VIDEO_EPOLICE_PARAM, *LPNET_ITC_VIDEO_EPOLICE_PARAM;

typedef union tagNET_ITC_VIDEO_TRIGGER_PARAM_UNION
{
	DWORD  uLen[1150];			
	NET_ITC_VIDEO_EPOLICE_PARAM struVideoEP; //视频电警参数
}NET_ITC_VIDEO_TRIGGER_PARAM_UNION, *LPNET_ITC_VIDEO_TRIGGER_PARAM_UNION;

typedef struct tagNET_ITC_VIDEO_TRIGGER_PARAM
{
	DWORD dwSize;
	DWORD dwMode; //触发模式，详见ITC_TRIGGERMODE_TYPE
    NET_ITC_VIDEO_TRIGGER_PARAM_UNION uVideoTrigger; //触发模式参数
    BYTE  byRes[32];
}NET_ITC_VIDEO_TRIGGER_PARAM, *LPNET_ITC_VIDEO_TRIGGER_PARAM;

typedef struct tagNET_DVR_STATUS_DETECTCFG
{
	DWORD  dwSize;			//结构长度
	BYTE   byEnableTrigIODetect; //开启触发IO状态检测，1-是，0-否
	BYTE   byEnableFlashOutDetect; //开启同步输出状态检测，1-是，0-否
	BYTE   byEnableRS485Detect; //开启RS485接收状态检测，1-是，0-否
	BYTE   byEnableTrafficLightDetect;//开启交通灯状态检测，1-是，0-否
	BYTE   byRes[28];
}NET_DVR_STATUS_DETECTCFG, *LPNET_DVR_STATUS_DETECTCFG;

typedef enum _ITC_STATUS_DETECT_TYPE_
{
	ITC_STATUS_DETECT_NULL = 0,		//未知
	ITC_STATUS_DETECT_TRIGGERIO,	//触发IO
	ITC_STATUS_DETECT_FLASHOUT,     //同步输出
	ITC_STATUS_DETECT_RS485, //RS485
	ITC_STATUS_DETECT_TRIGGERTYPE, //触发类型（保留）
	ITC_STATUS_DETECT_TRAFFICLIGHT_COLOR,  //交通灯（区分颜色）
	ITC_STATUS_DETECT_TRAFFICLIGHT_TURN  //交通灯（区分转向）
}ITC_STATUS_DETECT_TYPE;

typedef struct tagNET_ITC_TRIGGERIO_INFO
{
	BYTE byTriggerIOIndex[MAX_IOIN_NUM]; //触发IO号
	BYTE byRes[40]; 
}NET_ITC_TRIGGERIO_INFO, *LPNET_ITC_TRIGGERIO_INFO;

typedef struct tagNET_ITC_FLASHOUT_INFO
{
	BYTE byFlashOutIndex[MAX_IOOUT_NUM]; //同步输出号
	BYTE byRes[44]; 
}NET_ITC_FLASHOUT_INFO, *LPNET_ITC_FLASHOUT_INFO;

typedef struct tagNET_ITC_SERIAL_CHECKINFO
{
	BYTE bySerialIndex[MAX_ITC_SERIALCHECK_NUM]; //485串口校验结果，0-无效,1-有效, bySerialIndex[0]表示正确的头, bySerialIndex[1]表示正确的尾
	BYTE byRes[40]; 
}NET_ITC_SERIAL_CHECKINFO, *LPNET_ITC_SERIAL_CHECKINFO;

typedef struct tagNET_ITC_TRIGGERTYPE_INFO
{
	BYTE byTrigTypeIndex; //触发类型值
	BYTE byRes[47]; 
}NET_ITC_TRIGGERTYPE_INFO, *LPNET_ITC_TRIGGERTYPE_INFO;

//视频电警
typedef struct tagNET_ITC_TRAFFIC_LIGHT_COLOR
{
	BYTE  byLeftLight;//左转灯，0 表示无效，1为红灯 2为绿灯 3 黄灯 4灯都不亮
	BYTE  byRightLight; //右转灯，0 表示无效，1为红灯 2为绿灯 3 黄灯 4灯都不亮
	BYTE  byStraightLight; //直行灯，0 表示无效，1为红灯 2为绿灯 3 黄灯 4灯都不亮
	BYTE  byRes[45];
}NET_ITC_TRAFFIC_LIGHT_COLOR, *LPNET_ITC_TRAFFIC_LIGHT_COLOR;

//非视频电警
typedef struct tagNET_ITC_TRAFFIC_LIGHT_TURN
{
	BYTE byLightType[MAX_ITC_LANE_NUM];// 0 表示无效，1为红灯 2为绿灯 3 黄灯 4灯都不亮
	BYTE byRes[42];
} NET_ITC_TRAFFIC_LIGHT_TURN, *LPNET_ITC_TRAFFIC_LIGHT_TURN;

typedef union tagNET_ITC_STATUS_UNION
{
	BYTE   uLen[48];			//参数
	NET_ITC_TRIGGERIO_INFO struTrigIO; //触发IO口号
	NET_ITC_FLASHOUT_INFO struFlashOut; //同步输出
	NET_ITC_SERIAL_CHECKINFO struSerial;  //串口
	NET_ITC_TRIGGERTYPE_INFO struTrigType; //触发类型（保留）
	NET_ITC_TRAFFIC_LIGHT_COLOR struTrafficLightColor; //交通灯（区分颜色）对应类型ITC_STATUS_DETECT_TRAFFICLIGHT_COLOR
	NET_ITC_TRAFFIC_LIGHT_TURN struTrafficLightTurn;//交通灯（区分转向）对应类型ITC_STATUS_DETECT_TRAFFICLIGHT_TURN
}NET_ITC_STATUS_UNION, *LPNET_ITC_STATUS_UNION;

typedef struct tagNET_ITC_STATUS_DETECT_RESULT
{
	ITC_STATUS_DETECT_TYPE dwStatusType;//状态检测类型，详见ITC_STATUS_DETECT_TYPE
	NET_ITC_STATUS_UNION uStatusParam; //状态检测结果
	DWORD dwHoldTime; //灯亮持续时间（保留），单位：ms
	BYTE byRes[32];
}NET_ITC_STATUS_DETECT_RESULT, *LPNET_ITC_STATUS_DETECT_RESULT;

typedef struct tagNET_DVR_SETUPALARM_PARAM
{
    DWORD dwSize;
	BYTE  byLevel; //布防优先级，0-一等级（高），1-二等级（中），2-三等级（低）
	BYTE  byAlarmInfoType; //上传报警信息类型（抓拍机支持），0-老报警信息（NET_DVR_PLATE_RESULT），1-新报警信息(NET_ITS_PLATE_RESULT)2012-9-28
	BYTE  byRetAlarmTypeV40; //0--返回V30, 1--设备支持V40则返回V40，不支持则返回V30
	BYTE  byRes1;         //保留
    BYTE  byRetVQDAlarmType; //VQD报警上传类型，0-上传报报警NET_DVR_VQD_DIAGNOSE_INFO，1-上传报警NET_DVR_VQD_ALARM
	BYTE  byRes[11];
}NET_DVR_SETUPALARM_PARAM, *LPNET_DVR_SETUPALARM_PARAM;

typedef struct tagNET_ITC_VIDEO_TRIGGER_COND
{
    DWORD dwSize;
	DWORD dwChannel;
    DWORD dwTriggerMode; //视频触发模式类型，详见ITC_TRIGGERMODE_TYPE
    BYTE byRes[16];
}NET_ITC_VIDEO_TRIGGER_COND, *LPNET_ITC_VIDEO_TRIGGER_COND;

//条件结构
typedef struct tagNET_ITC_FTP_TYPE_COND
{
    DWORD dwChannel;//通道号
	BYTE	byWorkMode;  // 0-FTP1(主FTP)，1-FTP2(备FTP)
	BYTE	byRes[7];
}NET_ITC_FTP_TYPE_COND, *LPNET_ITC_FTP_TYPE_COND;

//配置结构
typedef struct tagNET_ITC_FTP_CFG
{
	DWORD            dwSize;
	BYTE			    byEnable;			/*是否启动ftp上传功能，0-否，1-是*/
	BYTE 				byAddressType;   //0-实际ipv4 ipv6地址 1-域名
	// 控制unionServer是使用实际地址还是域名
	WORD				wFTPPort;			/*端口*/
	union
	{
		struct
		{
			BYTE			szDomain[MAX_DOMAIN_NAME];//服务器地址，域名 
            BYTE			byRes1[80];
		}struDomain;
		struct
		{
			NET_DVR_IPADDR 	struIp;/*IP地址*/		//IPv4 IPv6地址, 144字节
		} struAddrIP;
	}unionServer;  //使用联合体结构，通过byAddressType字段表示是IP地址还是域名 64	
	BYTE				szUserName[NAME_LEN];		/*用户名*/
	BYTE				szPassWORD[PASSWD_LEN];		/*密码*/
	BYTE	            byRes4;  // 0-FTP1(主FTP)，1-FTP2(备FTP)
	BYTE				byDirLevel;	/*0 = 不使用目录结构，直接保存在根目录,
									1 = 使用1级目录,2=使用2级目录,
									3 = 使用3级目录,4=使用4级目录*/					
	BYTE 				byRes1;
	BYTE   			byUploadDataType;//0-全部，1-卡口，2-违章 (单FTP时默认选择全部，双FTP时支持卡口，违章的选择)
	NET_DVR_PICTURE_NAME 	struPicNameRule;/* 图片命名规则 */
	BYTE				byTopDirMode; /*一级目录, 0x1 = 使用设备名,
									  0x2 = 使用设备号,0x3 =使用设备ip地址，
									  0x4=使用监测点,0x5=使用时间(年月),  
									  0x6=使用时间(年月日),0x7=违规类型,0x8=方向,0x9=地点,
									  0xa=通道名,0xb=通道号,0xc=车道号0xff=自定义*/
	BYTE				bySubDirMode; /*二级目录, 0x1 =使用设备名,
									  0x2 = 使用设备号,0x3 =使用设备ip地址，
									  0x4=使用监测点,0x5=使用时间(年月),  
									  0x6=使用时间(年月日),0x7=违规类型,0x8=方向,0x9=地点,
									  0xa=通道名,0xb=通道号,0xc=车道号0xff=自定义*/
	BYTE				byThreeDirMode; /*三级目录, 0x1 = 使用设备名,
										0x2 = 使用设备号,0x3 =使用设备ip地址，
										0x4=使用监测点,0x5=使用时间(年月),  
										0x6=使用时间(年月日),0x7=违规类型,0x8=方向,0x9=地点,
										0xa=通道名,0xb=通道号,0xc=车道号0xff=自定义*/
	BYTE				byFourDirMode; /*四级目录, 0x1 =使用设备名,
									   0x2 = 使用设备号,0x3 =使用设备ip地址，
									   0x4=使用监测点,0x5=使用时间(年月),  
									   0x6=使用时间(年月日),0x7=违规类型,0x8=方向,0x9=地点,
									   0xa=通道名,0xb=通道号,0xc=车道号0xff=自定义*/
	BYTE              byRes2[32];
	BYTE			    szTopCustomDir[MAX_CUSTOMDIR_LEN]; /*自定义一级目录*/  
	BYTE				szSubCustomDir[MAX_CUSTOMDIR_LEN];/*自定义二级目录*/
	BYTE				szThreeCustomDir[MAX_CUSTOMDIR_LEN];	/*自定义三级目录*/
	BYTE				szFourCustomDir[MAX_CUSTOMDIR_LEN];	/*自定义四级目录*/
	BYTE 				byRes3[900]; //满足12级扩展预留 支持透传
}NET_ITC_FTP_CFG, *LPNET_ITC_FTP_CFG;

typedef enum _VCA_DATABASE_TYPE_
{
	DATABASE_NULL = 0, //未知
	DATABASE_SNAP,    //抓拍数据库
	DATABASE_FACE    //人脸数据库
}VCA_DATABASE_TYPE;

typedef struct tagNET_VCA_DATABASE_PARAM
{
	DWORD dwSize;
	DWORD dwDataBaseID; //数据库ID（设备生成，添加时无效，修改和删除时有效）
	DWORD dwDataBaseType; //数据库类型，见VCA_DATABASE_TYPE
	BYTE byDataBaseName[NAME_LEN]; //数据库名称
	BYTE byAttribute[64]; //数据库属性
	BYTE byRes[20];
}NET_VCA_DATABASE_PARAM, *LPNET_VCA_DATABASE_PARAM;

typedef struct tagNET_VCA_FIND_DATABASE_COND
{
	DWORD dwDataBaseType; //数据库类型，详见VCA_DATABASE_TYPE
	BYTE byRes[12]; //保留
}NET_VCA_FIND_DATABASE_COND, *LPNET_VCA_FIND_DATABASE_COND;

typedef struct tagNET_VCA_DELETE_DATABASE_COND
{
	DWORD dwSize;
	DWORD dwDataBaseType; //数据库类型，见VCA_DATABASE_TYPE
	DWORD dwDataBaseID; //数据库ID
	BYTE byRes[64]; //保留
}NET_VCA_DELETE_DATABASE_COND, *LPNET_VCA_DELETE_DATABASE_COND;

typedef struct tagNET_VCA_INQUIRE_SNAPDB_COND
{
	DWORD dwChannel;//通道号
    NET_DVR_TIME struStartTime;//开始时间
	NET_DVR_TIME struStopTime;//结束时间
	BYTE bySex; //性别：0-不启用，1-男，2-女
	BYTE byRes1[3]; //保留
	BYTE byStartBirthDate[MAX_HUMAN_BIRTHDATE_LEN]; //起始出生年月，如：201106
	BYTE byEndBirthDate[MAX_HUMAN_BIRTHDATE_LEN]; //截止出生年月，如201106
	BYTE byAttribute1[NAME_LEN]; //属性1
	BYTE byAttribute2[NAME_LEN]; //属性2
	BYTE byRes[12]; //保留
}NET_VCA_INQUIRE_SNAPDB_COND, *LPNET_VCA_INQUIRE_SNAPDB_COND;

typedef struct tagNET_VCA_INQUIRE_SNAPRECORD_RESULT
{ 
	DWORD dwSize; //结构体大小
	DWORD dwDataBaseID;  //数据库ID
	DWORD dwRecordID; //记录ID
	NET_DVR_TIME struSnapTime;  //抓拍时间
	BYTE bySex; //性别：0-不启用，1-男，2-女
	BYTE byRes1[3]; //保留
	BYTE byStartBirthDate[MAX_HUMAN_BIRTHDATE_LEN]; //起始出生年月，如：201106
	BYTE byEndBirthDate[MAX_HUMAN_BIRTHDATE_LEN]; //截止出生年月，如201106
	BYTE byAttribute1[NAME_LEN]; //属性1
	BYTE byAttribute2[NAME_LEN]; //属性2
	DWORD dwFacePicID; //人脸图ID
	DWORD dwFacePicLen;  //人脸图数据长度
	BYTE byRes[80];  //保留
	BYTE *pFacePic;    //人脸图数据
}NET_VCA_INQUIRE_SNAPRECORD_RESULT, *LPNET_VCA_INQUIRE_SNAPRECORD_RESULT;

typedef union tagNET_VCA_DELETE_SNAPRECORD_COND_UNION
{ 
	NET_VCA_INQUIRE_SNAPDB_COND struAttribute;  //人员信息（批量删除）
	DWORD dwRecordID; //记录ID（单条删除）
}NET_VCA_DELETE_SNAPRECORD_COND_UNION, *LPNET_VCA_DELETE_SNAPRECORD_COND_UNION;

typedef enum _VCA_DELETE_RECORD_TYPE_
{
	DELETE_RECORD_SINGLE = 0, //单条删除
	DELETE_RECORD_BATCH    //批量删除
}VCA_DELETE_RECORD_TYPE;

typedef struct tagNET_VCA_DELETE_SNAPRECORD_COND
{ 
    VCA_DELETE_RECORD_TYPE dwDeleteType; //删除记录类型
	NET_VCA_DELETE_SNAPRECORD_COND_UNION uDeleteCond;  //删除参数
	BYTE  byRes[40]; //保留
}NET_VCA_DELETE_SNAPRECORD_COND, *LPNET_VCA_DELETE_SNAPRECORD_COND;

typedef enum _VCA_SEARCH_DATABASE_TYPE_
{
    VCA_NORMAL_SEARCH_DATABASE  = 0x00000000,   //普通检索
	VCA_ADVANCE_SEARCH_DATABASE  = 0x00000001  //高级检索
}VCA_SEARCH_DATABASE_TYPE;

typedef struct tagNET_VCA_ADVANCE_SEARCH_DATABASE_COND
{
    DWORD dwDataBaseType; //数据库类型，详见VCA_DATABASE_TYPE
    DWORD dwDataBaseID; //数据库ID
	DWORD dwFacePicID; //人脸图片ID
	BYTE byRes[36];
}NET_VCA_ADVANCE_SEARCH_DATABASE_COND, *LPNET_VCA_ADVANCE_SEARCH_DATABASE_COND;

typedef union tagNET_VCA_SEARCH_DATABASE_COND_UNION
{
    DWORD uLen[25];
	NET_VCA_REGISTER_PIC struNormalFind; //普通检索
	NET_VCA_ADVANCE_SEARCH_DATABASE_COND struAdvanceFind; //高级检索
}NET_VCA_SEARCH_DATABASE_COND_UNION, *LPNET_VCA_SEARCH_DATABASE_COND_UNION;

typedef struct tagNET_VCA_SEARCH_DATABASE_PARAM
{
	DWORD dwSearchType; //检索类型，详见VCA_SEARCH_DATABASE_TYPE
	NET_VCA_SEARCH_DATABASE_COND_UNION uSearchCond; //检索参数
	BYTE byRes[16];
}NET_VCA_SEARCH_DATABASE_PARAM, *LPNET_VCA_SEARCH_DATABASE_PARAM;

typedef struct tagNET_VCA_SEARCH_SNAPDB_COND
{ 
	DWORD dwChannel; //通道
    DWORD dwDataBaseID; //数据库ID
	NET_DVR_TIME struStartTime;//开始时间
	NET_DVR_TIME struStopTime;//结束时间
	BYTE bySex; //性别：0-不启用，1-男，2-女
	BYTE byRes1[3]; //保留
	BYTE byStartBirthDate[MAX_HUMAN_BIRTHDATE_LEN]; //起始出生年月，如：201106
	BYTE byEndBirthDate[MAX_HUMAN_BIRTHDATE_LEN]; //截止出生年月，如201106
	BYTE byAttribute1[NAME_LEN]; //属性1
	BYTE byAttribute2[NAME_LEN]; //属性2
	NET_VCA_SEARCH_DATABASE_PARAM struSearchParam;  //检索参数
	DWORD dwMaxSearchNum; //最大检索条数
	WORD wThreshold;  //阈值，0-100
	BYTE  byRes[78]; //保留
}NET_VCA_SEARCH_SNAPDB_COND, *LPNET_VCA_SEARCH_SNAPDB_COND;

typedef struct tagNET_VCA_SEARCH_SNAPRECORD_RESULT
{ 
	DWORD dwSize; //结构体大小
	DWORD dwDataBaseID;  //数据库ID
    DWORD dwRecordID; //记录ID
	NET_DVR_TIME struSnapTime;//抓拍时间
	BYTE bySex; //性别：0-不启用，1-男，2-女
	BYTE byRes1[3]; //保留
	BYTE byStartBirthDate[MAX_HUMAN_BIRTHDATE_LEN]; //起始出生年月，如：201106
	BYTE byEndBirthDate[MAX_HUMAN_BIRTHDATE_LEN]; //截止出生年月，如201106
	BYTE byAttribute1[NAME_LEN]; //属性1
	BYTE byAttribute2[NAME_LEN]; //属性2
	float fSimilarity; //相似度，[0.001,1]
	DWORD dwFacePicID; //人脸图ID
	DWORD dwFacePicLen;  //人脸图数据长度
	BYTE byRes[80];  //保留
	BYTE *pFacePic;    //人脸图数据
}NET_VCA_SEARCH_SNAPRECORD_RESULT, *LPNET_VCA_SEARCH_SNAPRECORD_RESULT;

typedef struct tagNET_VCA_DATARECORD_INFO
{ 
	DWORD dwSize; //结构体大小
    DWORD dwRecordID; //记录ID，添加时无效，修改时有效
	NET_VCA_HUMAN_ATTRIBUTE struAttribute;  //人员信息
	NET_VCA_REGISTER_PIC struRegisterPic;  //人员图片信息
	BYTE  byRemark1[NAME_LEN]; //备注信息1
	BYTE  byRemark2[64]; //备注信息2
	BYTE  byRes[32]; //保留
}NET_VCA_DATARECORD_INFO, *LPNET_VCA_DATARECORD_INFO;

typedef struct tagNET_VCA_FAST_DATARECORD_INFO
{ 
	DWORD dwSize; //结构体大小
	NET_VCA_HUMAN_ATTRIBUTE struAttribute;  //人员信息
	BYTE  byRemark1[NAME_LEN]; //备注信息1
	BYTE  byRemark2[64]; //备注信息2
	DWORD dwImageLen;  //图像数据长度
	BYTE  byRes[80];  //保留
	BYTE *pImage;    //图像数据
}NET_VCA_FAST_DATARECORD_INFO, *LPNET_VCA_FAST_DATARECORD_INFO;

typedef struct tagNET_VCA_INQUIRE_DATARECORD_RESULT
{ 
	DWORD dwSize; //结构体大小
	DWORD dwDataBaseID;  //数据库ID
    DWORD dwRecordID; //记录ID
	NET_VCA_HUMAN_ATTRIBUTE struAttribute;  //人员信息
	BYTE  byRemark1[NAME_LEN]; //备注信息1
	BYTE  byRemark2[64]; //备注信息2
	DWORD dwFacePicID; //人脸图ID
	DWORD dwFacePicLen;  //人脸图数据长度
	BYTE byRes[80];  //保留
	BYTE *pFacePic;    //人脸图数据
}NET_VCA_INQUIRE_DATARECORD_RESULT, *LPNET_VCA_INQUIRE_DATARECORD_RESULT;

typedef struct tagNET_VCA_SEARCH_DATARECORD_RESULT
{ 
	DWORD dwSize; //结构体大小
	DWORD dwDataBaseID;  //数据库ID
    DWORD dwRecordID; //记录ID
	NET_VCA_HUMAN_ATTRIBUTE struAttribute;  //人员信息
	BYTE  byRemark1[NAME_LEN]; //备注信息1
	BYTE  byRemark2[64]; //备注信息2
	float fSimilarity; //相似度，[0.001,1]
	DWORD dwFacePicID; //人脸图ID
	DWORD dwFacePicLen;  //人脸图数据长度
	BYTE byRes[80];  //保留
	BYTE *pFacePic;    //人脸图数据
}NET_VCA_SEARCH_DATARECORD_RESULT, *LPNET_VCA_SEARCH_DATARECORD_RESULT;

typedef struct tagNET_VCA_DATARECORD_COND
{ 
	DWORD dwDataBaseID; //数据库ID
	NET_VCA_HUMANATTRIBUTE_COND struAttribute;  //人员信息
	BYTE byRes[80];  //保留
}NET_VCA_DATARECORD_COND, *LPNET_VCA_DATARECORD_COND;

typedef union tagNET_VCA_DELETE_RECORD_COND_UNION
{ 
	NET_VCA_HUMANATTRIBUTE_COND struAttribute;  //人员信息（批量删除）
	DWORD dwRecordID; //记录ID（单条删除）
}NET_VCA_DELETE_RECORD_COND_UNION, *LPNET_VCA_DELETE_RECORD_COND_UNION;

typedef struct tagNET_VCA_DELETE_RECORD_COND
{ 
    VCA_DELETE_RECORD_TYPE dwDeleteType; //删除记录类型
	NET_VCA_DELETE_RECORD_COND_UNION uDeleteCond;  //删除参数
	BYTE  byRes[40]; //保留
}NET_VCA_DELETE_RECORD_COND, *LPNET_VCA_DELETE_RECORD_COND;

typedef struct tagNET_VCA_SEARCH_FACEDB_COND
{ 
	DWORD dwDataBaseID; //数据库ID
	NET_VCA_HUMANATTRIBUTE_COND struAttribute;  //人员信息
	NET_VCA_SEARCH_DATABASE_PARAM struSearchParam;  //检索参数
	DWORD dwMaxSearchNum; //最大检索条数
	WORD wThreshold;  //阈值，0-100
	BYTE  byRes[78]; //保留
}NET_VCA_SEARCH_FACEDB_COND, *LPNET_VCA_SEARCH_FACEDB_COND;

typedef struct tagNET_VCA_FIND_MATCHPIC_COND
{
	DWORD dwSize;
	DWORD dwDataBaseType; //数据库类型，见VCA_DATABASE_TYPE
	DWORD dwDataBaseID; //数据库ID
	DWORD dwRecordID; //记录ID
	BYTE byRes[64]; //保留
}NET_VCA_FIND_MATCHPIC_COND, *LPNET_VCA_FIND_MATCHPIC_COND;

typedef struct tagNET_VCA_FIND_MATCHPIC_RESULT
{
	DWORD dwSize;
	DWORD dwDataBaseType; //数据库类型，见VCA_DATABASE_TYPE
	DWORD dwDataBaseID; //数据库ID
	DWORD dwRecordID; //记录ID
	DWORD dwPicLen; //图片长度
	BYTE byRes[64]; //保留
	BYTE *pPicBuffer; //图片数据指针
}NET_VCA_FIND_MATCHPIC_RESULT, *LPNET_VCA_FIND_MATCHPIC_RESULT;

typedef struct tagNET_DVR_REMOTECONTROL_ALARM_PARAM
{
	DWORD dwSize;
	DWORD dwChannel; //通道号
	WORD wDealyTime; //延迟时间，单位s
	BYTE  byRes[30]; 
}NET_DVR_REMOTECONTROL_ALARM_PARAM, *LPNET_DVR_REMOTECONTROL_ALARM_PARAM;

typedef struct tagNET_DVR_REMOTECONTROL_STUDY_PARAM
{
	DWORD dwSize;
	DWORD dwChannel; //通道号
	BYTE  byRes[16]; 
}NET_DVR_REMOTECONTROL_STUDY_PARAM, *LPNET_DVR_REMOTECONTROL_STUDY_PARAM;

typedef struct tagNET_DVR_WIRELESS_ALARM_STUDY_PARAM
{
	DWORD dwSize;
	DWORD dwChannel; //通道号
	BYTE  byIndex;  //无线报警序号，1-8
	BYTE  byRes[15]; 
}NET_DVR_WIRELESS_ALARM_STUDY_PARAM, *LPNET_DVR_WIRELESS_ALARM_STUDY_PARAM;

#define MAX_AUX_ALARM_NUM 8 //最大辅助报警个数
#define MAX_WIRELESS_ALARM_NUM 8 //最大无线报警个数
typedef enum _IPC_AUX_ALARM_TYPE_
{
    IPC_AUXALARM_UNKNOW = 0, //未知
	IPC_AUXALARM_PIR = 1, //PIR报警
	IPC_AUXALARM_WIRELESS = 2,   //无线报警
	IPC_AUXALARM_CALLHELP = 3  //呼救报警
}IPC_AUX_ALARM_TYPE;

typedef struct tagNET_DVR_AUDIO_LIMIT_ALARM_CFG
{	
	DWORD	dwSize;
	BYTE	byEnable;//使能
	BYTE	byRes1[3];
	DWORD	dwDecibelLimit; //分贝告警阀值
	NET_DVR_HANDLEEXCEPTION_V30	struHandleException;  //异常处理方式
	BYTE	byRes2[24];
}NET_IPC_AUDIO_LIMIT_ALARM_CFG,*LPNET_IPC_AUDIO_LIMIT_ALARM_CFG;

typedef struct tagNET_DVR_BUTTON_DOWN_ALARM_CFG
{	
	DWORD	dwSize;
	BYTE	byEnable;//使能
	BYTE	byRes1[3]; 
	NET_DVR_HANDLEEXCEPTION_V30	struHandleException;  //异常处理方式
	BYTE	byRes2[24];
}NET_IPC_BUTTON_DOWN_ALARM_CFG,*LPNET_IPC_BUTTON_DOWN_ALARM_CFG;

typedef struct tagNET_IPC_PIR_ALARMCFG
{
    BYTE byAlarmName[NAME_LEN];	/* 报警名称 */
	BYTE byAlarmHandle;	        /* 是否处理 0-不处理 1-处理*/
	BYTE byRes1[3];			
	NET_DVR_HANDLEEXCEPTION_V30 struAlarmHandleType;	/* 处理方式 */	
    BYTE byRelRecordChan[MAX_CHANNUM_V30]; //报警触发的录象通道,为1表示触发该通道
    BYTE byRes[64];
}NET_IPC_PIR_ALARMCFG, *LPNET_IPC_PIR_ALARMCFG;

typedef struct tagNET_IPC_PIR_ALARMCFG_EX
{
    BYTE byAlarmName[NAME_LEN];	/* 报警名称 */
	BYTE byAlarmHandle;	        /* 是否处理 0-不处理 1-处理*/
	BYTE byRes1[3];			
	NET_DVR_HANDLEEXCEPTION_V30 struAlarmHandleType;	/* 处理方式 */	
	BYTE byRelRecordChan[MAX_CHANNUM_V30]; //报警触发的录象通道,为1表示触发该通道
	NET_DVR_SCHEDTIME   struAlarmTime[MAX_DAYS][MAX_TIMESEGMENT_V30];
    BYTE byRes[1464];
}NET_IPC_PIR_ALARMCFG_EX, *LPNET_IPC_PIR_ALARMCFG_EX;

//呼救报警
typedef struct tagNET_IPC_CALLHELP_ALARMCFG
{
	BYTE byAlarmHandle;	        /* 是否处理 0-不处理 1-处理*/
	BYTE byRes1[3];			
	NET_DVR_HANDLEEXCEPTION_V30 struAlarmHandleType;	/* 处理方式 */	
    BYTE byRelRecordChan[MAX_CHANNUM_V30]; //报警触发的录象通道,为1表示触发该通道
    BYTE byRes[64];
}NET_IPC_CALLHELP_ALARMCFG, *LPNET_IPC_CALLHELP_ALARMCFG;

typedef struct tagNET_IPC_SINGLE_WIRELESS_ALARMCFG
{
    BYTE byAlarmName[NAME_LEN];	/* 报警名称 */
	BYTE byAlarmHandle;	        /* 是否处理 0-不处理 1-处理*/
	BYTE byID; //无线报警ID，1-8
	BYTE byRes1[2];			
	NET_DVR_HANDLEEXCEPTION_V30 struAlarmHandleType;	/* 处理方式 */
	BYTE byRelRecordChan[MAX_CHANNUM_V30]; //报警触发的录象通道,为1表示触发该通道	
    BYTE byRes[32];
}NET_IPC_SINGLE_WIRELESS_ALARMCFG, *LPNET_IPC_SINGLE_WIRELESS_ALARMCFG;

typedef struct tagNET_IPC_WIRELESS_ALARMCFG
{
	NET_IPC_SINGLE_WIRELESS_ALARMCFG struWirelessAlarm[MAX_WIRELESS_ALARM_NUM]; //单个无线报警参数
    BYTE byRes[32];
}NET_IPC_WIRELESS_ALARMCFG, *LPNET_IPC_WIRELESS_ALARMCFG;

typedef union tagNET_IPC_AUX_ALARMCFG_UNION
{
    DWORD uLen[472];
	NET_IPC_PIR_ALARMCFG_EX struPIRAlarm; //PIR报警参数
	NET_IPC_WIRELESS_ALARMCFG struWirelessAlarm; //无线报警参数
	NET_IPC_CALLHELP_ALARMCFG struCallHelpAlarm; //呼救报警参数
}NET_IPC_AUX_ALARMCFG_UNION, *LPNET_IPC_AUX_ALARMCFG_UNION;

typedef struct tagNET_IPC_SINGLE_AUX_ALARMCFG
{
	BYTE byAlarmType;	   //报警器类型，详见IPC_AUX_ALARM_TYPE
	BYTE byRes1[3];			
	NET_IPC_AUX_ALARMCFG_UNION uAlarm; //报警参数
    BYTE byRes[16];
}NET_IPC_SINGLE_AUX_ALARMCFG, *LPNET_IPC_SINGLE_AUX_ALARMCFG;

typedef struct tagNET_IPC_AUX_ALARMCFG
{
	DWORD dwSize;
    NET_IPC_SINGLE_AUX_ALARMCFG struAlarm[MAX_AUX_ALARM_NUM]; //报警参数
    BYTE byRes[64];
}NET_IPC_AUX_ALARMCFG, *LPNET_IPC_AUX_ALARMCFG;

typedef union tagNET_IPC_AUXALARM_UPLOAD_UNION
{
    DWORD uLen[66];
    NET_IPC_PIR_ALARMCFG struPIRAlarm; //PIR报警参数
	NET_IPC_SINGLE_WIRELESS_ALARMCFG struWirelessAlarm; //无线报警参数
	NET_IPC_CALLHELP_ALARMCFG struCallHelpAlarm; //呼救报警参数
}NET_IPC_AUXALARM_UPLOAD_UNION, *LPNET_IPC_AUXALARM_UPLOAD_UNION;

typedef struct tagNET_IPC_AUXALARM_RESULT
{
	DWORD dwSize;
	DWORD dwChannel; //通道号
	BYTE byAlarmType;	   //报警器类型，详见IPC_AUX_ALARM_TYPE
	BYTE byRes1[3];
	NET_IPC_AUXALARM_UPLOAD_UNION struAuxAlarm; //报警结果参数
    BYTE byDeviceID[NAME_LEN];/*设备的ID串*/
    BYTE byRes[32];
}NET_IPC_AUXALARM_RESULT, *LPNET_IPC_AUXALARM_RESULT;

typedef struct tagNET_DVR_PREVIEW_DISPLAYCFG
{
    DWORD  dwSize;         // 结构体大小 
    BYTE   byCorrectMode;   //校正模式，0-软件校正，1-芯片校正
    BYTE   byMountType;     //安装类型，0-吸顶，1-桌面，2-墙面
    BYTE   byRealTimeOutput;  //实时输出，0 -不启用，1- 启用
    BYTE   byRes[61];
}NET_DVR_PREVIEW_DISPLAYCFG, *LPNET_DVR_PREVIEW_DISPLAYCFG;

typedef struct tagNET_DVR_REMOTECONTROL_PTZ_PARAM
{
	DWORD dwSize;
	DWORD dwChannel; //通道号
	DWORD dwPTZCommand; //PTZ控制命令 
	NET_VCA_POINT struVcaPoint; //预览界面点坐标
	DWORD dwSpeed; //控制的速度，取值范围[0,7]
	DWORD dwStop; //停止动作或开始动作：0-开始；1-停止
	BYTE  byRes[32]; 
}NET_DVR_REMOTECONTROL_PTZ_PARAM, *LPNET_DVR_REMOTECONTROL_PTZ_PARAM;

typedef struct tagNET_DVR_PRESET_POINT_PARAM
{
	DWORD dwSize;
	DWORD dwChannel; //通道号
	DWORD dwPTZPresetCmd; //预置点控制命令 
	NET_VCA_POINT struVcaPoint; //预览界面点坐标
	DWORD dwPresetIndex; //预置点的序号（从1开始），最多支持255个预置点
	WORD  wZoomCoordinate;///<预置点窗口Zoom值
	BYTE  byRes[30];
}NET_DVR_PRESET_POINT_PARAM, *LPNET_DVR_PRESET_POINT_PARAM;

typedef struct tagNET_DVR_PTZ_CRUISE_PARAM
{
	DWORD dwSize;
	DWORD dwChannel; //通道号
	DWORD dwPTZCruiseCmd; //巡航控制命令 
	NET_VCA_POINT struVcaPoint; //预览界面点坐标
	WORD wCruiseRoute; //巡航路径，最多支持32条路径（序号从1开始）
	WORD wCruisePoint; //巡航点，最多支持32个点（序号从1开始）
	WORD wInput; //不同巡航命令时的值不同，预置点(最大255)、时间(最大255)、速度(最大40)
	WORD wZoomCoordinate;///<预置点窗口Zoom值
	BYTE  byRes[32];
}NET_DVR_PTZ_CRUISE_PARAM, *LPNET_DVR_PTZ_CRUISE_PARAM;

typedef struct tagNET_DVR_WPS_PARAM
{
	DWORD dwSize;
	BYTE byEnableWps; //启用WPS，0-否，1-是
	BYTE byRes[31]; 
}NET_DVR_WPS_PARAM, *LPNET_DVR_WPS_PARAM;

typedef struct tagNET_DVR_PIN_PARAM
{
	DWORD dwSize;
	BYTE byPIN[8]; //PIN码
	BYTE byRes[32]; 
}NET_DVR_PIN_PARAM, *LPNET_DVR_PIN_PARAM;

typedef struct tagNET_DVR_WPS_CONNECT_PARAM_
{
	DWORD dwSize;
	BYTE byConnectType; //WPS连接方式，0-PBC,1-AP PIN
	BYTE byRes1[3];
	BYTE byPIN[8]; //PIN码(WPS连接方式为AP PIN时有效)
	BYTE byEssid[IW_ESSID_MAX_SIZE]; //essid(WPS连接方式为AP PIN时有效)
	BYTE byRes[32]; 
}NET_DVR_WPS_CONNECT_PARAM, *LPNET_DVR_WPS_CONNECT_PARAM;

typedef struct tagNET_DVR_DECODER_JOINT_PARAM
{
    DWORD	dwSize;		// 结构体大小
    BYTE	byJointed;		//  0 没有关联 1 已经关联
    BYTE	byRes1[3];		// 保留字节
    NET_DVR_IPADDR	struIP;	// 被关联解码器的IP地址
    WORD	wPort;			// 被关联解码器的端口号
	WORD	wChannel;		// 被关联解码器的解码通道号
	BYTE	sDeviceName[NAME_LEN];	//被关联解码器的设备名称
	BYTE	sChanName[NAME_LEN];	//被关联解码器的解码通道名称
	BYTE	byRes2[32];		// 保留字节
}NET_DVR_DECODER_JOINT_PARAM, *LPNET_DVR_DECODER_JOINT_PARAM;


/**********************推模式图片回显结构体***************************/
typedef struct tagNET_DVR_PIC_VIEW_PARAM
{
	DWORD	dwSize;
	NET_DVR_IPADDR	struCuIp; //CU端IP地址
	WORD	wPort;/*CU端口*/
	BYTE	bySourceIndex;	//信号源通道号
	BYTE	byRes[29];
}NET_DVR_PIC_VIEW_PARAM, *LPNET_DVR_PIC_VIEW_PARAM;

#define DVCS_DEVICEID_LEN   16
//2012-03-13图片回显注册消息回调
typedef struct tagNET_DVR_PICVIEW_CALLBACKPARAM
{
	DWORD	dwUserID;
	BYTE    sDeviceID[DVCS_DEVICEID_LEN];
	LONG	nPicViewHandle; //回显句柄
	WORD	wSignalIndex;	//信号源索引
	WORD	wHeadLen;		//文件头长度 私有的码流文件头都是40
	BYTE	byHeadBuf[100]; //文件头
	BYTE	byRes2[32];
}NET_DVR_PICVIEW_CALLBACKPARAM, *LPNET_DVR_PICVIEW_CALLBACKPARAM;

/**********************获取子设备信息列表***************************/
#define DEVICEID_LEN	  32

typedef struct tagNET_DVR_DEVICEID_INFO
{
	DWORD		dwSize;
	DWORD		dwDeviceIndex;	//设备序号
	BYTE		byWallNo;	 //墙号，从1开始
	BYTE	    byRes1[27];
	DWORD		dwChan;		//通道号
	DWORD		dwInputSignalIndex; //信号源索引，集中式大屏控制器使用
	BYTE		byRes2[60];
}NET_DVR_DEVICEID_INFO, *LPNET_DVR_DEVICEID_INFO;


typedef struct tagNET_DVR_SINGLE_NETPARAM
{
	DWORD  dwSize;
	BYTE   byUseDhcp;				 //是否启用DHCP 0xff-无效 0-不启用 1-启用
	BYTE   byRes1[3];
	NET_DVR_IPADDR  struDevIP;       // 设备IP地址
	NET_DVR_IPADDR  struSubnetMask;  // 设备子网掩码
	NET_DVR_IPADDR  struGateway;     // 设备网关
	WORD	wDevPort;				 // 设备端口号
	BYTE	byMACAddr[MACADDR_LEN];   // MAC 地址(只能获取)
	BYTE	byRes2[16];
} NET_DVR_SINGLE_NETPARAM, *LPNET_DVR_SINGLE_NETPARAM;

typedef struct tagNET_DVR_CHAN_INFO
{
	DWORD	dwSize;
	BYTE	byValid;				//0-无效 1-有效
	BYTE	byRes1[3];
	BYTE	sChanName[NAME_LEN];    //通道名称
	NET_DVR_COLOR struVideoColor;   //信号源颜色
	WORD	wResolutionX;		//当前分辨率---宽 
	WORD	wResolutionY;		//当前分辨率---高
	BYTE   byRes2[40];
} NET_DVR_CHAN_INFO, *LPNET_DVR_CHAN_INFO;

//编码子设备信息
typedef struct tagNET_DVR_CODEDEV_INFO 
{
	NET_DVR_CHAN_INFO struChanInfo[MAX_CHANNUM/*16*/];/*设备通道信息*/ 
} NET_DVR_CODEDEV_INFO, *LPNET_DVR_CODEDEV_INFO;

//解码子设备信息
typedef struct tagNET_DVR_DECODEDEV_INFO 
{
	BYTE	byRes[1408];
} NET_DVR_DECODEDEV_INFO, *LPNET_DVR_DECODEDEV_INFO;

//网络信号源信息
typedef struct tagNET_DVR_NETSIGNAL_INFO
{
	DWORD	dwSize;
	BYTE	byDevName[NAME_LEN/*32*/];//网络信号源名称
	NET_DVR_PU_STREAM_CFG struPuStream;  
	BYTE    byValid;			//是否有效，0-无效，删除时设为0  1-有效，添加和修改时设为1/
	BYTE 	byRes1[3];	//保留
    BYTE	sGroupName[NAME_LEN/*32*/];//网络信号源所在组的组名，网络信号源根据这个组名来分类
	WORD	wResolutionX;		//当前分辨率---宽 
	WORD	wResolutionY;		//当前分辨率---高
	BYTE	byRes2[24];		
}NET_DVR_NETSIGNAL_INFO, *LPNET_DVR_NETSIGNAL_INFO;

typedef struct tagNET_DVR_NETSIGNALDEV_INFO
{
	NET_DVR_NETSIGNAL_INFO struDevInfo;
	BYTE	byRes1[816];
}NET_DVR_NETSIGNALDEV_INFO, *LPNET_DVR_NETSIGNALDEV_INFO;

typedef union tagNET_DVR_DIFFDEV_INFO 
{
	NET_DVR_CODEDEV_INFO struCodeDevInfo;		//编码设备信息
	NET_DVR_DECODEDEV_INFO struDecodeDevInfo;	//解码设备信息
	NET_DVR_NETSIGNALDEV_INFO struNetSignalInfo;	//网络信号源信息
} NET_DVR_DIFFDEV_INFO, *LPNET_DVR_DIFFDEV_INFO;

/*注册设备信息*/
typedef enum tagNET_DVCS_DEVICE_TYPE
{
	NET_DVR_BNC_PROC = 1,                       /* BNC处理器 */
	NET_DVR_RGB_PROC,                       /* RGB处理器 */
	NET_DVR_STP_PROC,                       /* 转码处理器 */
	NET_DVR_DISP_PROC,                      /* 显示处理器 */
	NET_DVR_NETSIGNAL						//网络信号源
}NET_DVCS_DEVICE_TYPE;

typedef struct  tagNET_DVR_SINGLE_DEV_INFO 
{
	DWORD	dwSize;
	DWORD	dwSoftVersion;			/*设备软件版本号(只能获取) 最高8位为主版本号，次高8位为次版本号，低16位为修复版本号*/
	DWORD	dwSoftwareBuildDate; 		//版本编译日期Build, 0xYYYYMMDD
	BYTE	byUseInSys;				/*是否在系统中使用*/
	BYTE	byDevStatus;			/*设备当前状态，0-下线，1-上线(只能获取)*/ 
	BYTE	byDeviceType;			/*设备类型(只能获取)  见DEVICE_TYPE*/ 
	BYTE	byRes1[17];
	BYTE	sDevName[NAME_LEN];     /*设备名称*/
	NET_DVR_SINGLE_NETPARAM struEtherNet[MAX_ETHERNET]; /*设备网络参数*/
	BYTE	sSerialNumber[SERIALNO_LEN];	/*设备序列号*/
	NET_DVR_DIFFDEV_INFO  struSubDevInfo;		/*设备信息*/ 
	DWORD	dwDeviceIndex;//设备序号，每个设备唯一确定
	BYTE	byRes2[48];
} NET_DVR_SINGLE_DEV_INFO, *LPNET_DVR_SINGLE_DEV_INFO;

typedef struct tagNET_DVR_DEVLIST
{
	DWORD		dwSize;
	DWORD		dwDevNums;//设备返回的分布式子设备数量
	BYTE  		*pBuffer;
	BYTE		byRes1[3];
	DWORD 		dwBufLen;//所分配指针长度，输入参数
	BYTE		byRes2[64];
} NET_DVR_DEVLIST,*LPNET_DVR_DEVLIST;

/********************************子设备信息配置****************************/
typedef struct tagNET_DVR_DEV_BASE_INFO
{
	DWORD  dwSize;
	BYTE   byEnable;          /*是否在系统中使用*/
	BYTE   byDeviceType;      /*设备类型(只能获取)*/ 
	BYTE   byRes1[2];
	BYTE   sDevName[NAME_LEN]; /*设备名称*/ 
	BYTE   byRes2[24];
} NET_DVR_DEV_BASE_INFO,*LPNET_DVR_DEV_BASE_INFO;

/********************************子设备网络信息配置****************************/

/*网络配置信息*/
typedef  struct tagNET_DVR_NETPARAM
{	
	DWORD dwSize;
	NET_DVR_SINGLE_NETPARAM struEtherNet[MAX_ETHERNET];//以太网口	
	BYTE   byRes[64];
} NET_DVR_NETPARAM, *LPNET_DVR_NETPARAM;

/********************************显示单元配置****************************/
// 绑定屏幕和设备关系(16个字节)
typedef struct tagNET_DVR_DISP_SCREEN
{
	DWORD	dwSize;
	WORD	wScreenID;		// 屏幕ID号, ID号从1开始
	BYTE	byWallNo;		// 电视墙号
	BYTE	byRes1;			// 保留1
	DWORD	dwDeviceIndex;	// 输出设备序号
	BYTE	byRes2[16];		// 保留2
}NET_DVR_DISP_SCREEN, *LPNET_DVR_DISP_SCREEN;

// 屏幕控制
typedef struct tagNET_DVR_TEXTSHOW
{
	DWORD dwSize;
	BYTE  byShowText;//是否显示文字，1-显示文字，0-不显示文字
	BYTE  byRes[35];
}NET_DVR_TEXTSHOW, *LPNET_DVR_TEXTSHOW;

typedef struct tagNET_DVR_SCREENLIST
{
	DWORD		dwSize;
	BYTE		byWallNo;	//电视墙号，从1开始
	BYTE		byRes[11];
	DWORD		dwScreenNums;//设备返回的映射显示屏数量
	BYTE  		*pBuffer;
	DWORD 		dwBufLen;//所分配指针长度，输入参数
} NET_DVR_SCREENLIST,*LPNET_DVR_SCREENLIST;

typedef struct tagNET_DVR_OPERATE_DEVICE
{
	DWORD	dwSize;
	DWORD	dwSubCommand;	//设置设备的命令，1-设备开始升级，2-停止升级
	DWORD	dwDeviceIndex;//设备序号
	BYTE	byRes[44];
}NET_DVR_OPERATE_DEVICE, *LPNET_DVR_OPERATE_DEVICE;

//设备升级
typedef struct tagNET_DVR_UPGRADE_STATE
{
	DWORD	dwProgress; // 0-100
	BYTE 	byState;  //升级进度：1-升级完成 2-正在升级 3-升级失败
	BYTE	byRes2[31];
}NET_DVR_UPGRADE_STATE, *LPNET_DVR_UPGRADE_STATE;
typedef void (CALLBACK *DVCS_UPGRADESTATE_CB)(LONG nUpgradeHandle, BYTE *pBuffer, DWORD dwBufSize, void* pUser);

//
//大屏控制器图片回显数据类型，现在大屏控制器回显的是图片（DATA_BMP），分布式大屏回显的是（DATA_SUBSTREAM）
typedef enum
{
	NET_DVR_DATA_BMP = 0,
	NET_DVR_START_CALLBACK, 
	NET_DVR_STREAM_SYSHEAD,
	NET_DVR_STREAM_DATA
}PIC_PREVIEW_DATATYPE;

typedef struct tagNET_DVR_START_PIC_VIEW_INFO
{
	DWORD	dwSize;
	DWORD	dwSignalIndex;	//信号源序号，该参数用于大屏控制器，其他设备该值设为0
	DWORD	dwDeviceIndex;//设备序号
	BYTE	byRes1[12];
	BYTE	byChanIndex;	//通道号
	BYTE    byRes2[3];
	//视频综合平台回显参数
    DWORD   dwScreenNum; //大屏序号：从零开始
	DWORD   dwLayer;     //图层号：从零开始
	DWORD   dwResolution;//回显分辨率,1-QCIF,2-CIF,3-D1
	BYTE    byFrame;//帧率，单位：帧/秒
	BYTE    byRes3[15];
}NET_DVR_START_PIC_VIEW_INFO, *LPNET_DVR_START_PIC_VIEW_INFO;

typedef struct tagNET_DVR_DVCS_STATE_ALARM
{
	DWORD	dwSize;
	BYTE	byAlarmType;		// 报警类型,1-设备上线，2-设备离线 3-服务器上线 4-服务器离线 5-管理员登陆 6-预案开始,7-预案结束，8-分辨率变化，9-图像切割失败，10-设备资源不足，11-温度异常*/
	BYTE	byDeviceType;		// 设备类型 见定义NET_DVCS_DEVICE_TYPE */ 
	BYTE	byWallNo;			// 墙号，从1开始， 0表示无效
	BYTE	byDeviceChanIndex; 	// 设备通道号，0表示无效，其他值表示通道号
	DWORD	dwDeviceIndex;		// 设备序号， 0表示无效
	WORD	wResolutionX;		// 分辨率-宽  0表示无效
	WORD	wResolutionY;		// 分辨率-高  0表示无效
	WORD	wTemperature;       // 设备温度 单位：摄氏度, 0表示无效 
	BYTE	byRes[86];
}NET_DVR_DVCS_STATE_ALARM, *LPNET_DVR_DVCS_STATE_ALARM;

typedef struct tagNET_DVR_PIC_ADJUST
{
	DWORD		dwSize;
	BYTE		bySubCommand;		//见宏定义DECODEPIC_LEFTADJUST等
	BYTE		byScale;			//调整的量值
	BYTE		byPictureProportion;	//图像缩放比例 0-无效 1-4:3, 2-16:9
	BYTE		byRes[29];			
}NET_DVR_PIC_ADJUST, *LPNET_DVR_PIC_ADJUST;

/********************************图片控制****************************/
typedef struct tagNET_DVR_PICTURE_PARAM
{
	DWORD	dwSize;		
	BYTE	byControlCommand;	//切换命令，1-显示，2-隐藏，3-全部删除（针对GIF图片	）
	BYTE	byUseType;			//图片类型，1-OSD 2-底图，3-GIF
	BYTE	byWallNo;			//电视墙墙号，从1开始
	BYTE	byPictureNo;		//图片序号
	BYTE	byRes[64];
}NET_DVR_PICTURE_PARAM, *LPNET_DVR_PICTURE_PARAM;

/********************************分布式大屏 end****************************/

// 76SP设备POE通道添加方式配置
typedef struct tagNET_DVR_POE_CHANNEL_ADD_MODE
{
	DWORD		dwSize;              	//结构体大小
	BYTE 		byAddMode;     			//添加方式 0: 即插即用 1: 手动添加	
	BYTE  		byRes1[127];          	//保留
}NET_DVR_POE_CHANNEL_ADD_MODE, *LPNET_DVR_POE_CHANNEL_ADD_MODE;

#define MAX_ESATA_NUM 16
#define MAX_MINISAS_NUM 96

typedef struct tagNET_DVR_ESATA_MINISAS_USAGE
{
	DWORD		dwSize;
	BYTE	    byESATAUsage[MAX_ESATA_NUM];		// 数组索引表示第几个eSATA，0：默认备份 1：默认录像
	BYTE	    byMiniSASUsage[MAX_MINISAS_NUM];	// 数组索引表示第几个miniSAS，0：默认备份 1：默认录像
	BYTE 		byRes[32];
}NET_DVR_ESATA_MINISAS_USAGE, *LPNET_DVR_ESATA_MINISAS_USAGE;

#define MAX_DISK_NUM 128

typedef struct tagNET_DVR_BACKUP_LOG_PARAM
{
	DWORD		dwSize;
	BYTE	    byDiskDesc[DESC_LEN_32];		//备份磁盘描述
	BYTE		byHardDisk[MAX_DISK_NUM];		//需备份的硬盘号，备份几个取前几个 
	BYTE		byBackupHardDiskNum;  			//需备份的硬盘个数
	BYTE	    byContinue;						//是否继续备份，0-不继续，1-继续
	BYTE        byAllLogBackUp ;        /*是否全部备份，0-按磁盘号备份，1-备份所有日志，当为1时，需备份的磁盘号和硬盘个数无效*/
	BYTE 		byRes[29];
}NET_DVR_BACKUP_LOG_PARAM, *LPNET_DVR_BACKUP_LOG_PARAM;

typedef struct tagNET_DVR_DIGITAL_CHANNEL_STATE
{
	DWORD	dwSize;
	BYTE	byDigitalAudioChanTalkState[MAX_CHANNUM_V30];  //表示数字语音通道的对讲状态 0-未使用，1-使用中, 0xff无效
	BYTE	byDigitalChanState[MAX_CHANNUM_V30];  /*数字通道的连接状态 byDigitalChanErrState[0] 
															表示第一个数字通道，具体值表示状态码，祥见NET_SDK_DIGITAL_CHANNEL_STATUS，
															以此类推，0xff表示无效通道或未添加IPC*/
	BYTE	byDigitalAudioChanTalkStateEx[MAX_CHANNUM_V30*3];  //表示数字语音通道的对讲状态，从第MAX_CHANNUM_V30+1 到第MAX_CHANNUM_V30*4个， 0-未使用，1-使用中, 0xff无效
    BYTE	byDigitalChanStateEx[MAX_CHANNUM_V30*3];  /*数字通道的连接状态 byDigitalChanErrStateEx[0]表示第从第MAX_CHANNUM_V30+1个个数字通道，具体值表示状态码，祥见NET_SDK_DIGITAL_CHANNEL_STATUS，以此类推，0表示无效*/
	BYTE	byRes[64];
}NET_DVR_DIGITAL_CHANNEL_STATE, *LPNET_DVR_DIGITAL_CHANNEL_STATE;

//数字通道状态
typedef enum
{
	NET_SDK_DC_STATUS_CONNECTED = 1,				//已连接
	NET_SDK_DC_STATUS_CONNECTING,					//正在连接
	NET_SDK_DC_STATUS_BAND_WIDTH_EXCEED,		//超过系统带宽
	NET_SDK_DC_STATUS_DOMAIN_ERROR,				//域名错误
	NET_SDK_DC_STATUS_CHANNEL_ERROR,				//通道号错误
	NET_SDK_DC_STATUS_ACCOUNT_ERROR,				//用户名或密码错误
	NET_SDK_DC_STATUS_STREAM_TYPE_NOT_SUPPORT,	//流类型不支持
	NET_SDK_DC_STATUS_CONFLICT_WITH_DVR,			//和设备IP地址冲突
	NET_SDK_DC_STATUS_CONFLICT_WITH_IPC,			//和IPC IP地址冲突
	NET_SDK_DC_STATUS_NETWORK_UNREACHBALE,			//网络不可达
	NET_SDK_DC_STATUS_IPC_NOT_EXIST,				//IP通道未接入
	NET_SDK_DC_STATUS_IPC_EXCEPTION,				//IP通道异常
	NET_SDK_DC_STATUS_OTHER_ERROR,                  //其他错误
    NET_SDK_DC_STATUS_RESOLUTION_NOT_SUPPORT        //IPC分辨率不支持
}NET_SDK_DIGITAL_CHANNEL_STATUS;


/*************************************ITS****************************/
#define VERSION_LEN                 32 //版本长度
#define	MAX_OVERLAP_ITEM_NUM		50 //最大字符叠加种数
#define	ITS_MAX_DEVICE_NUM		    32 //最大设备个数

//终端基本信息
typedef struct tagNET_ITS_BASEINFO
{
	DWORD   dwSize;	
	BYTE    byMainVer[VERSION_LEN];	// 算法主流程版本
	BYTE    byMprVer[VERSION_LEN];	// 多帧识别库版本
	BYTE    byBvtVer[VERSION_LEN];	// 背向视频库版本
	BYTE    byLptVer[VERSION_LEN];	// 视频跟踪库版本
	BYTE    byTvdVer[VERSION_LEN];	// 违章检测库版本
	BYTE    byTldVer[VERSION_LEN];	// 信号灯检测库版本
	BYTE    byRes[252];		// 预留字段
}NET_ITS_BASEINFO,*LPNET_ITS_BASEINFO;

//图片合成参数
typedef struct tagNET_ITS_IMGMERGE_CFG
{
    DWORD  dwSize;
	BYTE   byIsMerge;		//是否需要合成（0：不合成；1：合成）
	BYTE   byRes1[3];
	DWORD  dwOneMergeType;	//抓拍单张图合成方式（可能会截取特写图）
    /************************************************************************/
	/* 201 两张图片上下排列合成,合成后图片宽为单张图的1倍,高为2倍         */
	/* 202 两张图片左右排列合成,合成后图片宽为单张图的2倍,高为1倍         */
	/* 301 三张图片上下排列合成,合成后图片宽为单张图的1倍,高为3倍         */
	/* 302 三张图片左右排列合成,合成后图片宽为单张图的3倍,高为1倍		  */
	/* 303 从三张图片中取一幅车牌特写区域,组成四张图片;四张图片"田"字型合成,
		   特写在右下;合成后图片宽为单张图的2倍,高为2倍					  */
	/* 304 从三张图片中取一幅车牌特写区域,组成四张图片;四张图片"田"字型合成,
		   特写在右下;合成后图片宽为单张图的1倍,高为1倍					  */
	/* 305 从三张图片中取一幅车牌特写区域,组成四张图片;四张图片"田"字型合成,
		   特写在左上;合成后图片宽为单张图的2倍,高为2倍					  */
	/* 306 从三张图片中取一幅车牌特写区域,组成四张图片;四张图片"田"字型合成,
		   特写在左上;压缩图片分辨率,合成后图片宽为单张图的1倍,高为1倍	  */
    /* 307 三张图片"品"字型排列合成										  */
	/* 308 三张图片倒"品"字型排列合成									  */
	/************************************************************************/
	DWORD  dwTwoMergeType;	//抓拍两张图合成方式
	DWORD  dwThreeMergeType;	//抓拍三张图合成方式
    DWORD  dwJpegQuality;      //压缩质量（0~100）
    DWORD  dwCloseupIndex;     //特写图抓拍第几张
	DWORD  dwMerageMaxSize;   //合成图片大小的上限,300-10240(单位KB)
	WORD   wCloseupDeviation; // 特写图偏移量(50~图片高度)，单位:像素
	BYTE   byRes[30];
}NET_ITS_IMGMERGE_CFG,*LPNET_ITS_IMGMERGE_CFG;

//交通数据主机
typedef	struct	tagNET_ITS_TRAFFIC_DATA_HOST
{
 	NET_DVR_IPADDR	struHostAddr;	// 远程主机IP
	WORD			wHostPort;	// 远程主机Port
	BYTE			byRes1[2];
	DWORD			dwDataType;	// 上传远程主机的数据类型（定义见下），按位表示
	BYTE			bySuspendUpload;	// 是否暂停数据上传：0-正常上传；1-暂停上传
	BYTE			byUploadStrategy;	// 上传策略：0-最新数据优先上传；1-按照通行时间上传
	WORD			wUploadInterval;	// 上传间隔时间（ms，1~2000），该参数只对历史数据有效
	DWORD			dwUploadTimeOut; //上传超时时间
	BYTE			byRes[24];
}NET_ITS_TRAFFIC_DATA_HOST,*LPNET_ITS_TRAFFIC_DATA_HOST;

//数据上传参数
typedef  struct	tagNET_ITS_UPLOAD_CFG
{
  	DWORD              	dwSize;
  	NET_ITS_TRAFFIC_DATA_HOST	struRemoteDataHost1;   	//接收交通数据主机1
  	NET_ITS_TRAFFIC_DATA_HOST	struRemoteDataHost2;	    //接收交通数据主机2 
}NET_ITS_UPLOAD_CFG,*LPNET_ITS_UPLOAD_CFG;

typedef struct tagNET_DVR_SYSTEM_TIME
{
	WORD  wYear;   	    //年
	WORD  wMonth;  		//月
	WORD  wDay;    		//日
	WORD  wHour;   		//时
	WORD  wMinute;  	//分
	WORD  wSecond;  	//秒
	WORD  wMilliSec;	//毫秒
	BYTE  byRes[2];
}NET_DVR_SYSTEM_TIME, *LPNET_DVR_SYSTEM_TIME;

//交通数据主机状态信息
typedef	struct tagNET_ITS_TRAFFIC_DATA_INFO
{
	DWORD    dwDataQuantity;      //数据总量
	DWORD    dwDataRsendQuantity;     //未发送数量（需要上传交通数据主机的）
	NET_DVR_SYSTEM_TIME      struStartTime;        //未发送数据的最早时间
	NET_DVR_SYSTEM_TIME      struEndTime;        //未发送数据的最晚时间
	NET_DVR_IPADDR   struDataHost;    //接收交通数据主机
}NET_ITS_TRAFFIC_DATA_INFO, *LPNET_ITS_TRAFFIC_DATA_INFO;

//终端工作状态
typedef  struct tagNET_ITS_WORKSTATE
{ 
	DWORD  dwSize ;
	BYTE   byDevName[NAME_LEN];	// 设备名称
	DWORD  dwRunTime;		// 系统运行时间，单位s
	NET_ITS_TRAFFIC_DATA_INFO	struTrafficDataInfo[2]; //支持两台主机（数据上传配置的主机）
	DWORD  dwMemoryUsage;	// 内存占用率（如果内存占用率为30%，此处填30）
	DWORD  dwCpuUsage;		// cpu占用率（如果cpu占用率为30%，此处填30）
	DWORD  dwDevTemperature;	// 本机温度
	DWORD  dwDeviceStatic; 	// 设备的状态,0-正常,1-CPU占用率太高,超过85%,2-硬件错误,例如串口死掉
	NET_DVR_DISKSTATE  struHardDiskStatic[MAX_DISKNUM_V30];   //硬盘状态
	NET_DVR_CHANNELSTATE_V30 struChanStatic[MAX_CHANNUM_V30]; //通道的状态
	BYTE  byAlarmInStatic[MAX_ALARMIN_V30];  //报警输入口的状态,0-没有报警,1-有报警
	BYTE  byAlarmOutStatic[MAX_ALARMOUT_V30]; //报警输出端口的状态,0-没有输出,1-有报警输出
	DWORD dwLocalDisplay;			//本地显示状态,0-正常,1-不正常
	BYTE  byAudioInChanStatus[8];  	//表示语音通道的状态 0-未使用，1-使用中，数组0表示第1个语音通道
	BYTE  byRes[36]; 			//保留
}NET_ITS_WORKSTATE, *LPNET_ITS_WORKSTATE;

//出入口交通配置获取参数
typedef  struct tagNET_ITS_ECT_WORKSTATE_COMMAND
{ 
	DWORD	dwSize;
	DWORD   dwChannel;
	BYTE    byRes[256]; 			//保留
}NET_ITS_ECT_WORKSTATE_COMMAND, *LPNET_ITS_ECT_WORKSTATE_COMMAND;

typedef struct tagNET_ITS_ECTWORKSTATE
{ 
	DWORD	 dwSize ;
	BYTE	 byDevName[NAME_LEN];	// 设备名称
	DWORD    dwRunTime;		// 系统运行时间，单位s
	NET_ITS_TRAFFIC_DATA_INFO	struTrafficDataInfo[2]; //支持两台主机（数据上传配置的主机）
	DWORD    dwMemoryUsage;	// 内存占用率（如果内存占用率为30%，此处填30）
	DWORD    dwCpuUsage;		// cpu占用率（如果cpu占用率为30%，此处填30）
	DWORD    dwDevTemperature;	// 本机温度
	DWORD    dwDeviceStatic; 	// 设备的状态,0-正常,1-CPU占用率太高,超过85%,2-硬件错误,例如串口死掉
	NET_DVR_DISKSTATE  struHardDiskStatic[MAX_DISKNUM_V30];   //硬盘状态
	BYTE     byAlarmInStatic[MAX_ALARMIN_V30];  //报警输入口的状态,0-没有报警,1-有报警
	BYTE     byAlarmOutStatic[MAX_ALARMOUT_V30]; //报警输出端口的状态,0-没有输出,1-有报警输出
	DWORD    dwLocalDisplay;			//本地显示状态,0-正常,1-不正常
	BYTE     byRes[256]; 			//保留
}NET_ITS_ECTWORKSTATE, *LPNET_ITS_ECTWORKSTATE;

// 图片信息（后续会加入码流）
typedef struct tagNET_ITS_PICTURE_INFO
{
	DWORD   dwDataLen;		    //媒体数据长度
	BYTE    byType;			// 0:车牌图;1:场景图;2:合成图;3:码流
	BYTE    byRes1[3];          //保留
	DWORD   dwRedLightTime;		//经过的红灯时间  （s）
	BYTE    byAbsTime[32];		//绝对时间点,yyyymmddhhmmssxxx,e.g.20090810235959999  最后三位为毫秒数
	NET_VCA_RECT   struPlateRect;	//车牌位置
	NET_VCA_RECT  struPlateRecgRect;   //牌识区域坐标
	BYTE	*pBuffer;	//数据指针
	BYTE    byRes2[12];   		//保留
}NET_ITS_PICTURE_INFO, *LPNET_ITS_PICTURE_INFO;

// 检测结果
typedef struct tagNET_ITS_PLATE_RESULT
{
	DWORD   dwSize;		//结构长度
	DWORD   dwMatchNo;		//匹配序号,由(车辆序号,数据类型,车道号)组成匹配码
	BYTE    byGroupNum;	//图片组数量（一辆过车相机多次抓拍的数量，代表一组图片的总数，用于延时匹配数据）
	BYTE    byPicNo;		//连拍的图片序号（接收到图片组数量后，表示接收完成;接收超时不足图片组数量时，根据需要保留或删除）
	BYTE    bySecondCam;	//是否第二相机抓拍（如远近景抓拍的远景相机，或前后抓拍的后相机，特殊项目中会用到）
	BYTE    byFeaturePicNo; //闯红灯电警，取第几张图作为特写图,0xff-表示不取
	BYTE	byDriveChan;		//触发车道号
	BYTE	byVehicleType;     //0- 未知，1-客车，2-货车，3-轿车，4-面包车，5-小货车
	BYTE    byRes1[2];			//保留
	WORD    wIllegalType;       //违章类型采用国标定义
	BYTE    byIllegalSubType[8];   //违章子类型
	BYTE    byPostPicNo;    //违章时取第几张图片作为卡口图,0xff-表示不取
	BYTE    byChanIndex;		//通道号（保留）
	WORD	wSpeedLimit;		//限速上限（超速时有效）
	BYTE	byRes2[2];
	NET_DVR_PLATE_INFO  struPlateInfo; 	//车牌信息结构
	NET_DVR_VEHICLE_INFO struVehicleInfo;	//车辆信息
	BYTE    byMonitoringSiteID[48];		//监测点编号
	BYTE    byDeviceID[48];				//设备编号
	BYTE    byDir;    		//监测方向，1-上行，2-下行，3-双向，4-由东向西，5-由南向北,6-由西向东，7-由北向南，8-其它
	BYTE    byDetectType;	//检测方式,1-地感触发，2-视频触发，3-多帧识别，4-雷达触发
	BYTE      byRes3[22]; //保留
	NET_DVR_TIME_V30  struSnapFirstPicTime;//端点时间(ms)（抓拍第一张图片的时间）
	DWORD   dwIllegalTime;//违法持续时间（ms） = 抓拍最后一张图片的时间 - 抓拍第一张图片的时间
	DWORD   dwPicNum;		//图片数量（与picGroupNum不同，代表本条信息附带的图片数量，图片信息由struVehicleInfoEx定义	
	NET_ITS_PICTURE_INFO struPicInfo[6]; 		//图片信息,单张回调，最多6张图，由序号区分
}NET_ITS_PLATE_RESULT, *LPNET_ITS_PLATE_RESULT;

//出入口车辆抓拍数据上传
typedef struct tagNET_ITS_GATE_VEHICLE
{
	DWORD   dwSize;		//结构长度
	DWORD   dwMatchNo;		//匹配序号,由(车辆序号,数据类型,车道号)组成匹配码 默认0
	BYTE    byGroupNum;	//图片组数量（一辆过车相机多次抓拍的数量，代表一组图片的总数，用于延时匹配数据）默认 1 抓拍类型下图片数据 控制后续接收延时操作
	BYTE    byPicNo;		//连拍的图片组上传图片序号（接收到图片组数量后，表示接收完成。
	//接收超时不足图片组数量时，根据需要保留或删除）
	BYTE    bySecondCam;	//是否第二相机抓拍（如远近景抓拍的远景相机，或前后抓拍的后相机，特殊项目中会用到）标示前后相机抓拍图片
	BYTE    byRes; //标记为预留
	WORD    wLaneid;            //车道号1～32（索引车道号，可以跳跃）
	BYTE    byCamLaneId;	//对应相机车道号1～16（相机配置的车道号，可以跳跃，可以相同）
	BYTE    byRes1;			//保留
	BYTE    byAlarmReason[MAX_ALARMREASON_LEN]; //自定义报警类型 默认为中文
	WORD    wBackList;    //标记为是否报警数据 0 表示为正常过车数据 1 表示黑名单
	WORD	wSpeedLimit;		//限速上限（超速时有效）km/h
	DWORD   dwChanIndex;		//通道号
	NET_DVR_PLATE_INFO    struPlateInfo; 	//车牌信息结构
	NET_DVR_VEHICLE_INFO  struVehicleInfo;	//车辆信息  含速度
	BYTE    byMonitoringSiteID[MAX_ID_LEN];		//监测点编号
	BYTE    byDeviceID[MAX_ID_LEN];				//设备编号 
	BYTE    byDir;    		//监测方向，0-其它 1 入场，2 出场
	BYTE    byDetectType;	//检测方式, 0-其他 1-地感触发，2-视频触发，3-多帧识别，4-雷达触发
	BYTE    byRes2[2];
	BYTE    byCardNo[MAX_ID_LEN]; // 卡号
	DWORD   dwPicNum;		//图片数量（与picGroupNum不同，代表本条信息附带的图片数量，图片信息由struVehicleInfoEx定义	
	NET_ITS_PICTURE_INFO struPicInfo[4]; 		//图片信息,单张回调，最多4张图，由序号区分
	//2013-11-19 出入口车辆抓拍数据上传（监听方式）新增参数
	BYTE    bySwipeTime[MAX_TIME_LEN];//增加刷卡时间  时间格式为yyyymmddhh24missfff
	BYTE    byRes3[224];
}NET_ITS_GATE_VEHICLE, *LPNET_ITS_GATE_VEHICLE;

//出入口人脸识别
typedef  struct  tagNET_ITS_GATE_FACE
{
	DWORD   dwSize;            //结构体长度
	BYTE    byGroupNum;	//图片组数量（一个行人相机多次抓拍的数量，代表一组图片的总数，用于延时匹配数据）
	BYTE    byPicNo;		//连拍的图片序号（接收到图片组数量后，表示接收完成。
	//接收超时不足图片组数量时，根据需要保留或删除）
	BYTE    byFeaturePicNo; //连抓时取第几张图作为特写图,0xff-表示不取
	BYTE    byRes;   //保留
	WORD    wLaneid;            //车道号1～32（索引车道号，可以跳跃）
	BYTE    byCamLaneId;	//对应相机车道号1～16（相机配置的车道号，可以跳跃，可以相同）
	BYTE    byDir;    	//监测方向，0-其他 1 入场， 2 出场
	DWORD   dwChanIndex;		//通道号 
	BYTE    byMonitoringSiteID[MAX_ID_LEN];		//监测点编号
	BYTE    byDeviceID[MAX_ID_LEN];				//设备编号
	NET_VCA_FACESNAP_RESULT     struFaceInfo;   //人脸抓拍数据	
	BYTE    byRes2[256];   //预留
}NET_ITS_GATE_FACE, *LPNET_ITS_GATE_FACE;

//停车场数据上传
typedef struct _tagNET_ITS_PARK_VEHICLE_
{
	DWORD   dwSize; //结构长度
	BYTE    byGroupNum; //图片组数量（单次轮询抓拍的图片数量）
	BYTE    byPicNo; //连拍的图片组上传图片序号（接收到图片组数量后，表示接收完成
	//接收超时不足图片组数量时，根据需要保留或删除）
	BYTE    byLocationNum; //单张图片所管理的车位数
	BYTE    byParkError; //停车异常，0-正常 1 异常
	BYTE    byParkingNo[MAX_PARKNO_LEN];//车位编号
	BYTE    byLocationStatus; //车位车辆状态，0-无车，1有车
	BYTE    bylogicalLaneNum;//逻辑车位号，0-3，一个相机最大能管4个车位 （0代表最左边，3代表最右边）
	WORD    wUpLoadType;//第零位表示：0~轮训上传、1~变化上传
	BYTE    byRes1[4]; //保留字节
	DWORD   dwChanIndex; //通道号数字通道
	NET_DVR_PLATE_INFO   struPlateInfo;  //车牌信息结构
	NET_DVR_VEHICLE_INFO struVehicleInfo; //车辆信息
	BYTE    byMonitoringSiteID[MAX_ID_LEN]; //监测点编号
	BYTE    byDeviceID[MAX_ID_LEN]; //设备编号 
	DWORD   dwPicNum; //图片数量（与picGroupNum不同，代表本条信息附带的图片数量
	//，图片信息由struVehicleInfoEx定义 
	NET_ITS_PICTURE_INFO struPicInfo[2];  //图片信息,单张回调，最多2张图，由序号区分
	BYTE   byRes2[256];
}NET_ITS_PARK_VEHICLE, *LPNET_ITS_PARK_VEHICLE;

//交通取证报警
typedef struct tagNET_DVR_TFS_ALARM
{
    DWORD                   dwSize;                //结构体大小
    DWORD                   dwRelativeTime;        //相对时标
	DWORD                   dwAbsTime;	           //绝对时标
	DWORD                   dwIllegalType;         //违章类型，采用国标定义
	DWORD                   dwIllegalDuration;     //违法持续时间（单位：秒） = 抓拍最后一张图片的时间 - 抓拍第一张图片的时间
	BYTE                    byMonitoringSiteID[MONITORSITE_ID_LEN];//监测点编号（路口编号、内部编号）
	BYTE                    byDeviceID[DEVICE_ID_LEN];             //设备编号
	NET_VCA_DEV_INFO        struDevInfo;	       //前端设备信息
	NET_DVR_SCENE_INFO      struSceneInfo;         //场景信息
	NET_DVR_TIME_EX         struBeginRecTime;      //录像开始时间 
	NET_DVR_TIME_EX         struEndRecTime;        //录像结束时间 
	NET_DVR_AID_INFO        struAIDInfo;           //交通事件信息
	NET_DVR_PLATE_INFO      struPlateInfo;         //车牌信息
	NET_DVR_VEHICLE_INFO    struVehicleInfo;       //车辆信息
	DWORD                   dwPicNum;              //图片数量
	NET_ITS_PICTURE_INFO    struPicInfo[8];        //图片信息，最多8张 
	BYTE                    byRes[128];            //保留
}NET_DVR_TFS_ALARM,*LPNET_DVR_TFS_ALARM;

typedef struct _tagNET_ITS_ECT_BLACKLIST_
{
	DWORD dwSize;
	DWORD dwChannel; //通道号
	BYTE  bylogicalLaneNo;//逻辑车道号
	BYTE  byRes1[3];
	BYTE  byLaneName[NAME_LEN];//车道名称 32
	NET_DVR_PLATE_INFO  struPlateInfo;  //车牌信息结构  
	BYTE  byRes2[256];       // 保留字节    
}NET_ITS_ECT_BLACKLIST, *LPNET_ITS_ECT_BLACKLIST;

//IPC通道参数配置
typedef	struct 	tagNET_ITS_IPC_CHAN_CFG
{
	DWORD		dwSize; 
	BYTE		byCameraType;		//相机种类，0-监控用相机；1-线圈触发相机；2-视频分析用相机,3-一体机
	BYTE		byRes1[3];		   //保留
	BYTE		byMonitoringSiteID[48];		//监测点编号
	BYTE		byDeviceID[48];				//设备编号
	BYTE		byDirectionNo;	     //监测方向编号,0-无,1-上行,2-下行,3-双向,4-由东向西,5-由南向北,6-由西向东,7-由北向南,8-其他
	BYTE		byMonitorInfo[48];  	//监测点信息描述
	BYTE		byRes2[15];		//保留
}NET_ITS_IPC_CHAN_CFG, *LPNET_ITS_IPC_CHAN_CFG;

//单个设备信息
typedef struct tagNET_ITS_SINGLE_DEVICE_INFO
{
	DWORD  dwDeviceType;          //设备类型，0-终端，1-相机，2-补光灯，3-车检器
	DWORD  dwDirID;               //方向编号
	DWORD  dwLaneID;             //车道编号
	DWORD  dwDeviceState;         //设备状态  0正常 非0 异常（参考设备异常代码表）
	BYTE   byDeviceName[32];     //设备名称
	BYTE   byDeviceID[48];		   //设备编号，一般用序列号，车检器用地址
	NET_DVR_TIME_V30  struTriggerTime;//触发时间
	BYTE byRes[4];
}NET_ITS_SINGLE_DEVICE_INFO,*LPNET_ITS_SINGLE_DEVICE_INFO;

//路口信息
typedef struct tagNET_ITS_ROADINFO
{	
	DWORD	 dwSize;
	DWORD	 dwChannel;		  //通道号,0xffffffff表示终端，其它表示对应的相机
	BYTE     byTriggerMode;    //  0:线圈触发;  1:视频触发
	BYTE	 byRes1[3];
	DWORD    dwDeviceNum;       //实际设备个数 
	BYTE     byMonitoringSiteID[48];	//监测点编号
	BYTE  	 byRoadInfo[48];       //监测点信息
	NET_ITS_SINGLE_DEVICE_INFO		struSingleDevice[ITS_MAX_DEVICE_NUM];
	BYTE     byRes[16];
}NET_ITS_ROADINFO,*LPNET_ITS_ROADINFO;

//单个车道路况信息
typedef struct tagNET_ITS_TRAFFIC_DRIVE_CHAN
{
	BYTE   byDriveChan;		//车道号
	BYTE   byRes1[3];    		// 预留
	WORD   wCarFlux;			//汽车流量数
	WORD   wPasserbyFlux;		//行人流量数
	WORD   wShayFlux;		//二轮车流量数
	float  fAverOccpancy;   	//平均车道占有率百分比
	WORD   wAverSpeed;		 //平均车速(km/h)
	WORD   wAverCarDis;    	//平均车距(单位待定)
	BYTE   byRes2[16];   		 // 预留
}NET_ITS_TRAFFIC_DRIVE_CHAN,*LPNET_ITS_TRAFFIC_DRIVE_CHAN;

typedef struct tagNET_ITS_TRAFFIC_COLLECT
{
	DWORD  dwSize;		//结构大小
	BYTE   byMonitoringSiteID[48];		//监测点编号
	BYTE   byDeviceID[48];				//设备编号
	BYTE   byLaneNum;	//车道总数
	BYTE   byDir;    	//监测方向
	BYTE   byDetectType;    //检测方式1-地感线圈、2-视频触发、3、多帧识别、4雷达触发
	BYTE   byRes1;   		//预留 	
	DWORD  dwChannel; //通道号
	NET_DVR_SYSTEM_TIME 	struStartTime;		//统计开始时间
	DWORD  dwSamplePeriod;	//统计时间,单位秒
	NET_ITS_TRAFFIC_DRIVE_CHAN	struDriveChan[6]; 		//交通流量数据,每个相机支持6个车道
	BYTE   byRes2[24]; 	//预留
}NET_ITS_TRAFFIC_COLLECT,*LPNET_ITS_TRAFFIC_COLLECT;

typedef struct tagNET_ITS_OVERLAPCFG_COND
{
    DWORD dwSize;
	DWORD dwChannel;
    DWORD dwConfigMode; //配置模式，0-终端，1-前端(直连前端或终端接前端)
    BYTE  byRes[16];
}NET_ITS_OVERLAPCFG_COND, *LPNET_ITS_OVERLAPCFG_COND;

typedef enum ITS_OVERLAP_ITEM_TYPE
{
	OVERLAP_ITEM_NULL = 0,	      //0-未知
	OVERLAP_ITEM_SITE,                //1-地点
	OVERLAP_ITEM_ROADNUM,             //2-路口编号
	OVERLAP_ITEM_INSTRUMENTNUM,       //3-设备编号
	OVERLAP_ITEM_DIRECTION,           //4-方向编号
	OVERLAP_ITEM_DIRECTIONDESC,       //5-方向
	OVERLAP_ITEM_LANENUM,             //6-车道号
	OVERLAP_ITEM_LANEDES,             //7-车道
	OVERLAP_ITEM_CAPTIME,             //8-抓拍时间(不带毫秒)
	OVERLAP_ITEM_CAPTIME_MILLSECOND,  //9-抓拍时间(带毫秒)
	OVERLAP_ITEM_PLATENUM,            //10-车牌号
	OVERLAP_ITEM_CARCOLOR,            //11-车身颜色
	OVERLAP_ITEM_CARTYPE,             //12-车辆类型
	OVERLAP_ITEM_CARBRAND,            //13-车辆品牌
	OVERLAP_ITEM_CARSPEED,            //14-车辆速度
	OVERLAP_ITEM_SPEEDLIMIT,          //15-限速标志
	OVERLAP_ITEM_CARLENGTH,           //16-车辆长度1~99m
	OVERLAP_ITEM_ILLEGALNUM,          //17-违法代码(违法代码叠加应该没用的，应该直接叠加违法信息，比如正常、低速、超速、逆行、闯红灯、占道、压黄线等)
	OVERLAP_ITEM_MONITOR_INFO,      //18-监测点信息
	OVERLAP_ITEM_ILLEGALDES,          //19-违法行为
	OVERLAP_ITEM_OVERSPEED_PERCENT,	//20-超速比
	OVERLAP_ITEM_RED_STARTTIME,           //21-红灯开始时间
	OVERLAP_ITEM_RED_STOPTIME,		//22-红灯结束时间
	OVERLAP_ITEM_RED_DURATION,        //23-红灯已亮时间
	OVERLAP_ITEM_SECUNITY_CODE,		//24-防伪码
	OVERLAP_ITEM_CAP_CODE		//25-抓拍编号                       
}ITS_OVERLAP_ITEM_TYPE;

//字符叠加每一条信息结构体
typedef struct tagNET_ITS_OVERLAP_SINGLE_ITEM_PARAM
{
	BYTE byRes1[2];                   // 保留
	BYTE byItemType;   //类型，详见OVERLAP_ITEM_TYPE
	BYTE byChangeLineNum;		   //叠加项后的换行数[0-10](默认0)
	BYTE bySpaceNum;				   //叠加项后的空格数[0-255](默认0)
	BYTE byRes[15];
}NET_ITS_OVERLAP_SINGLE_ITEM_PARAM, *LPNET_ITS_OVERLAP_SINGLE_ITEM_PARAM;

typedef struct tagNET_ITS_OVERLAP_ITEM_PARAM
{
	NET_ITS_OVERLAP_SINGLE_ITEM_PARAM struSingleItem[MAX_OVERLAP_ITEM_NUM]; //单条字符参数
	DWORD dwLinePercent;  //叠加行百分比(0-100),(默认100)
	DWORD dwItemsStlye;   //叠加方式：0-横排,1-竖排(默认横排)
	WORD  wStartPosTop;    //起始上坐标,只对图片内部叠加有效[0~2448](默认0)
	WORD  wStartPosLeft;    //起始左坐标,只对图片内部叠加有效[0~2448](默认0)
	WORD  wCharStyle;    //字体类型,0-宋体1-魏体(默认)
	WORD  wCharSize;    //字符大小,0--16x16,1--32x32,2-48x48,3--64x64 (默认)
	WORD  wCharInterval;    //字符间距，[0～16]，可设单位：像素(默认)
	BYTE  byRes1[2];
	DWORD dwForeClorRGB;      //前景色的RGB值bit0-1:(B) bit2-3:(G) bit4-5:(G) (默认x00FFFFFF-白)
	DWORD dwBackClorRGB; //背景色的RGB值,只对图片外叠加有效bit0-1:(B) bit2-3:(G) bit4-5:(G) (默认x00000000-黑)
	BYTE  byColorAdapt;	//颜色是否自适应0-否1-是
	BYTE  byRes[31];
}NET_ITS_OVERLAP_ITEM_PARAM, *LPNET_ITS_OVERLAP_ITEM_PARAM;

//叠加项具体信息
typedef struct tagNET_ITS_OVERLAP_INFO_PARAM
{
	BYTE bySite[128];           //地点描述
	BYTE byRoadNum[32];  //路口编号
	BYTE byInstrumentNum[32];				//设备编号
	BYTE byDirection[32];        //方向编号
	BYTE byDirectionDesc[32];    //方向描述
	BYTE byLaneDes[32];        //车道描述
	BYTE byRes1[32];     //保留
	BYTE byMonitoringSite1[44];		//监测点1信息
	BYTE byMonitoringSite2[32];		//监测点2信息
	BYTE byRes[64];		//保留
}NET_ITS_OVERLAP_INFO_PARAM, *LPNET_ITS_OVERLAP_INFO_PARAM;

typedef struct tagNET_ITS_OVERLAP_CFG
{
	DWORD dwSize;	
    BYTE  byEnable; //是否启用，0-不启用，1-启用
    BYTE  byRes1[3]; 
	NET_ITS_OVERLAP_ITEM_PARAM		struOverLapItem; //字符串参数
	NET_ITS_OVERLAP_INFO_PARAM 	struOverLapInfo;  //字符串内容信息
	BYTE  byRes[32];
}NET_ITS_OVERLAP_CFG, *LPNET_ITS_OVERLAP_CFG;

#define  MAX_PTZCRUISE_POINT_NUM   32   //最大支持32个巡航点


//预置点信息
typedef struct tagNET_DVR_PRESET_INFO
{
	DWORD dwSize;
	DWORD dwPresetNum; //预置点个数
	DWORD dwGroupNum;  //组数
	BYTE  byRes[8];
}NET_DVR_PRESET_INFO, *LPNET_DVR_PRESET_INFO;

//输入参数
typedef struct tagNET_DVR_PRESET_COND
{
    DWORD dwSize;
	DWORD dwChannel;
	DWORD dwGroupNO; //组号
    BYTE byRes[8];
}NET_DVR_PRESET_COND, *LPNET_DVR_PRESET_COND;

//输出参数
typedef struct tagNET_DVR_PRESETCFG
{
	DWORD dwSize;
	DWORD dwPresetIndex; //预置点序号
	NET_VCA_POINT struVcaPoint; //预置点坐标
	WORD wZoomCoordinate; ///<预置点窗口Zoom值
	BYTE  byRes[30]; 
}NET_DVR_PRESETCFG, *LPNET_DVR_PRESETCFG;

//获取巡航路径的数目
typedef struct tagNET_DVR_PTZCRUISE_INFO
{
    DWORD dwSize;
	DWORD dwPtzCruiseNum; //路径个数
    DWORD dwGroupNum; //组数
    BYTE byRes[8];
}NET_DVR_PTZCRUISE_INFO, *LPNET_DVR_PTZCRUISE_INFO;

//输入参数：
typedef struct tagNET_DVR_PTZCRUISE_COND
{
    DWORD dwSize;
	DWORD dwChannel;
	DWORD dwGroupNO; //组号
    BYTE byRes[8];
}NET_DVR_PTZCRUISE_COND, *LPNET_DVR_PTZCRUISE_COND;

//输出参数
typedef struct tagNET_DVR_PTZCRUISE_POINTCFG
{
	DWORD dwSize;
	DWORD dwPresetIndex; //预置点序号
	NET_VCA_POINT struVcaPoint; //预置点坐标
	BYTE	byDwell;		//停留时间
	BYTE	bySpeed;		//速度
	WORD  wZoomCoordinate;///<预置点窗口Zoom值
	BYTE   byRes[28]; 
}NET_DVR_PTZCRUISE_POINTCFG, *LPNET_DVR_PTZCRUISE_POINTCFG;

typedef struct tagNET_DVR_PTZCRUISECFG
{
	DWORD dwSize;
	DWORD dwCruiseRoute; //巡航路径序号
	NET_DVR_PTZCRUISE_POINTCFG struCruisePoint[MAX_PTZCRUISE_POINT_NUM]; //最大支持32个巡航点
	BYTE  byRes[32]; 
}NET_DVR_PTZCRUISECFG, *LPNET_DVR_PTZCRUISECFG;

//跟踪模式结构
typedef struct tagNET_DVR_MOTION_TRACK_CFG
{
	DWORD dwSize; 
	BYTE byEnableTrack;   //启用跟踪，0-否，1-是
	BYTE byRes[63];
}NET_DVR_MOTION_TRACK_CFG, *LPNET_DVR_MOTION_TRACK_CFG;

typedef struct tagNET_DVR_REBOOT_TIME
{
	BYTE byDate;   //星期几，1-7代表星期一到星期日
	BYTE byHour;   //时
	BYTE byMinute; //分	
	BYTE byRes1;
	BYTE byRebootMode; //0-按周重启，1-按月重启（此参数只能获取，不能设置）
	BYTE byRes[11]; //保留
}NET_DVR_REBOOT_TIME,*LPNET_DVR_REBOOT_TIME;

typedef struct tagNET_DVR_AUTO_REBOOT_CFG
{
	DWORD dwSize;
	NET_DVR_REBOOT_TIME struRebootTime;
}NET_DVR_AUTO_REBOOT_CFG,*LPNET_DVR_AUTO_REBOOT_CFG;

#define NET_DVR_GPS_FINDING       0   //正在查找
#define NET_DVR_GPS_RECV          1   //接收数据
#define NET_DVR_GPS_OVER          2   //查找结束
#define NET_DVR_GPS_EXCEPTION     3   //接收异常
typedef struct tagNET_DVR_MENU_OUTPUT_MODE
{
	DWORD		dwSize;
	BYTE		byMenuOutputMode; //非同源设备：0-Auto 1-主CVBS 2-HDMI 3-VGA 同源设备：0-Auto 1-主CVBS 2-HDMI/VGA
	BYTE		byRes[63];
}NET_DVR_MENU_OUTPUT_MODE, *LPNET_DVR_MENU_OUTPUT_MODE;

typedef struct tagNET_DVR_MB_IPADDR
{
	NET_DVR_IPADDR   struIP;  //IP地址
	WORD        wPort;   //端口号
	BYTE        byRes[2];
}NET_DVR_MB_IPADDR,*LPNET_DVR_MB_IPADDR;

typedef struct tagNET_DVR_MB_WVSPARA
{
	NET_DVR_MB_IPADDR struWVSAddr;
	BYTE byPuid[NAME_LEN];    //设备id
	BYTE byPassword[PASSWD_LEN];  //密码
	BYTE byRes[8];
}NET_DVR_MB_WVSPARA, *LPNET_DVR_MB_WVSPARA;

typedef struct tagNET_DVR_MB_EHOMEPARA
{
	NET_DVR_MB_IPADDR struEHomeAddr;
	BYTE byPuid[NAME_LEN];   //设备id
}NET_DVR_MB_EHOMEPARA, *LPNET_DVR_MB_EHOMEPARA;

typedef struct tagNET_DVR_MB_PLATFORMPARA
{   
	DWORD dwSize;
	BYTE byNetEnvironment;/*网络环境,0-wireless,1-3G,2-wLan,3-lan*/
	BYTE byCurPlatForm;   /*< 当前平台0 - WVS, 1 - E家, 2 - 推模式 */
	BYTE byRes1[2];	
	NET_DVR_MB_WVSPARA  struWVSPara; /*车载平台(平台登入)*/
	NET_DVR_MB_EHOMEPARA struMbEHpara;/*E家平台车载平台不设置设备登入密码 */
	BYTE byRes2[64];
}NET_DVR_MB_PLATFORMPARA, *LPNET_DVR_MB_PLATFORMPARA;

typedef struct tagNET_DVR_MB_GPS_STATUS
{
	BYTE		byGPSModule;      /*gps模块, 0: 不存在, 1: 正常*/
	BYTE		byPositionStatus;	  /*gps定位状态, 0: 定位失败, 1: 定位成功*/
	BYTE		bySignalStrength;    /*信号强度, 0: 弱, 1: 正常, 2: 强*/
	BYTE		byres[5];
}NET_DVR_MB_GPS_STATUS, *LPNET_DVR_MB_GPS_STATUS;

typedef struct tagNET_DVR_MB_GSENSOR_STATUS
{
	BYTE		byGsensorModule;	/*g-sensor模块, 0: not exist, 1: 内置, 2: 外置*/
	BYTE		byCurAccX[10]; 	/*当前X轴加速度*/
	BYTE		byCurAccY[10];	/*当前Y轴加速度*/
	BYTE		byCurAccZ[10];	/*当前Z轴加速度*/
	BYTE		byRefAccX[10];	/* X轴加速度标定值*/
	BYTE		byRefAccY[10];	/* Y轴加速度标定值*/
	BYTE		byRefAccZ[10];	/* Z轴加速度标定值*/
	BYTE		byres[3];
}NET_DVR_MB_GSENSOR_STATUS, *LPNET_DVR_MB_GSENSOR_STATUS;

#define IP_ADDR_LEN 		16
#define IW_ESSID_MAX_SIZE	32

typedef struct tagNET_DVR_MB_WIFI_STATUS
{
	BYTE		byEnableWiFi; /* 无线, 0 关, 1 开 */
	BYTE 		byWiFiConnectStatus;  /* WIFI状态, 0: 连接失败, 1: 连接成功 2: 无模块*/
	BYTE		bySignalStrength;             /* 信号强度, 0 弱, 1 正常, 2 强 */
	BYTE		byIPaddress[IP_ADDR_LEN];   /*WIFI 设备 ip*/
	BYTE		byEssid[IW_ESSID_MAX_SIZE];  /*无线接入点essid*/
	BYTE		byres[5];
}NET_DVR_MB_WIFI_STATUS,*LPNET_DVR_MB_WIFI_STATUS;

typedef struct tagNET_DVR_MB_PLATFORM_STATUS
{
	BYTE		byCurPlat;	  /*当前平台, 0: wvs, 1: ivms, 2: 推模式(net_3g_sdk)*/
	BYTE		byLoginStatus; 	/*login 状态, 0: login failed, 1: login success*/
	BYTE		byExceptionInfo;  	/*异常信息*/
/*
WVS :exception info:
	    0: 连接服务器失败
		1: 注册中
		2: 用户名密码错误
		3: 注册超时
		4: 心跳超时
		5: 注册成功
iVMS :exception info:
	    0未注册	
		1注册中	
		2注册连接出错
		3注册超时
		4长时间没有心跳，连接中断
		5重新注册
		6 CMS中注册设备数量已经超过限定的台数
		7 CMS中注册通道数量已经超过限定通道数
		8设备在WEB管理中心中没有配置
		9CMS和WEB管理中心通信失败
		10登录未知错误
		11注册成功
推模式 :exception info:	
        0未注册
		1: 注册中
		2: 重复注册
		3: 注册连接失败
		4: 服务器IP变化
		5: 注册成功
		6: 用户注销
		7: 心跳超时
*/						
	BYTE		byres[5];
}NET_DVR_MB_PLATFORM_STATUS, *LPNET_DVR_MB_PLATFORM_STATUS;

					
typedef struct tagNET_DVR_MB_MOBILEDEV_STATUS
{
	DWORD		dwSize;      /*结构大小*/
	union
	{
		NET_DVR_MB_GPS_STATUS struGPSStatus;
		NET_DVR_MB_GSENSOR_STATUS struGSensorStatus;
		NET_DVR_MB_WIFI_STATUS struWiFiStatus;
		NET_DVR_MB_PLATFORM_STATUS struPlatformStatus;
	}mobileStatus;
}NET_DVR_MB_MOBILEDEV_STATUS, *LPNET_DVR_MB_MOBILEDEV_STATUS;

#define NET_DVR_GPS_STATUS       0
#define NET_DVR_GSENSOR_STATUS   1
#define NET_DVR_WIFI_STATUS      2
#define NET_DVR_PLATFORM_STATUS  3

//GPS点信息结构
typedef struct tagNET_DVR_GPS_INFO
{
	/* 经纬度为S*100 */
	BYTE    byDirection[2];		/*direction[0]0or1(东经/西经), direction[1]:0or1(北纬/南纬)  */
    BYTE    bySvs;         /* satellite vehicles(初值0)：有效定位星数 */
	BYTE    byLocateMode;  /* 定位模式(初值0)：仅NMEA0183 3.00版本输出，0=自主定位，1=差分，2=估算，3=数据无效 */
    WORD    wHDOP;  /* 水平精度因子，度量GPS精确度，0.5-99.9，6以内定位精度高，20以上需丢弃，这里存储的是乘以10以后的整数 */     
	WORD    wHeight;         	/* 高度 */
	DWORD   dwLatitude;	 /*纬度latitude = 实际度*3600*100+实际分*60*100+实际秒*100 */
	DWORD   dwLongitude; /*经度longitude =实际度*3600*100+实际分*60*100+实际秒*100 */
	DWORD   dwVehicleSpeed;		/* mobile speed =实际速度*100000 实际单位kph*/
	DWORD	dwVehicleDirection;	/* mobile direction= 实际方向*100，实际数值是方向角，正北为0度，顺时针 */
	BYTE	byRes[8];            // 保留
}NET_DVR_GPS_INFO,*LPNET_DVR_GPS_INFO; //32字节

//GPS关联时间
typedef struct tagNTE_DVR_GPS_DATA
{
	NET_DVR_GPS_INFO  struGPSInfo;      //GPS坐标点
	NET_DVR_TIME      struTime;    		//GPS坐标对应的时间点，UTC时间
	BYTE	    byRes[12];             // 保留
}NET_DVR_GPS_DATA,*LPNET_DVR_GPS_DATA;

//GPS查找条件结构
typedef struct tagNET_DVR_GET_GPS_DATA_PAPAM
{	
	DWORD dwCmdType;              //0-按时间段查找GPS数据,1-按时间点查找GPS数据	
	union
	{
		struct
		{
			NET_DVR_TIME struBeginTime;               //GPS数据查找起始时间       
			NET_DVR_TIME struEndTime;                 //GPS数据查找结束时间
            DWORD dwInterval;                  //GPS点时间间隔，单位秒
			BYTE  byRes[76];                    // 保留
		}TimeSeg;
		struct
		{
			NET_DVR_TIME struTimePoint;              //GPS数据查找起始时间单位秒
			BYTE  byRes[104];              // 保留
		}TimePoint;	
	}GpsDataParam;
}NET_DVR_GET_GPS_DATA_PARAM,*LPNET_DVR_GET_GPS_DATA_PARAM;

typedef struct tagNET_DVR_SDKLOCAL_CFG
{
	BYTE	byEnableAbilityParse;	//使用能力集解析库,0-不使用,1-使用,默认不使用
	BYTE    byVoiceComMode;          //对讲模式，0-使用对讲库（默认），1-使用windows api模式	
	BYTE	byRes[382];
	BYTE	byProtectKey[128];	//默认设置为0
}NET_DVR_SDKLOCAL_CFG, *LPNET_DVR_SDKLOCAL_CFG;

typedef struct tagNET_DVR_LOCAL_ABILITY_PARSE_CFG
{
	BYTE	byEnableAbilityParse;	//使用能力集解析库,0-不使用,1-使用,默认不使用
	BYTE	byRes[127];				
}NET_DVR_LOCAL_ABILITY_PARSE_CFG, *LPNET_DVR_LOCAL_ABILITY_PARSE_CFG;

typedef struct tagNET_DVR_LOCAL_TALK_MODE_CFG
{
	BYTE	byTalkMode;				//对讲模式，0-使用对讲库（默认），1-使用windows api模式
	BYTE	byRes[127];				
}NET_DVR_LOCAL_TALK_MODE_CFG, *LPNET_DVR_LOCAL_TALK_MODE_CFG;


typedef struct tagNET_DVR_LOCAL_PROTECT_KEY_CFG
{
	BYTE	byProtectKey[128];		//默认设置为0
	BYTE	byRes[128];			
}NET_DVR_LOCAL_PROTECT_KEY_CFG, *LPNET_DVR_LOCAL_PROTECT_KEY_CFG;



typedef enum tagNET_SDK_LOCAL_CFG_TYPE
{
	NET_SDK_LOCAL_CFG_TYPE_TCP_PORT_BIND = 0,		//本地TCP端口绑定配置，对应结构体NET_DVR_LOCAL_TCP_PORT_BIND_CFG
	NET_SDK_LOCAL_CFG_TYPE_UDP_PORT_BIND,			//本地UDP端口绑定配置，对应结构体NET_DVR_LOCAL_UDP_PORT_BIND_CFG
	NET_SDK_LOCAL_CFG_TYPE_MEM_POOL,				//内存池本地配置，对应结构体NET_DVR_LOCAL_MEM_POOL_CFG
	NET_SDK_LOCAL_CFG_TYPE_MODULE_RECV_TIMEOUT,		//按模块配置超时时间，对应结构体NET_DVR_LOCAL_MODULE_RECV_TIMEOUT_CFG
	NET_SDK_LOCAL_CFG_TYPE_ABILITY_PARSE,			//是否使用能力集解析库，对应结构体NET_DVR_LOCAL_ABILITY_PARSE_CFG
	NET_SDK_LOCAL_CFG_TYPE_TALK_MODE,				//对讲模式，对应结构体NET_DVR_LOCAL_TALK_MODE_CFG
	NET_SDK_LOCAL_CFG_TYPE_PROTECT_KEY,				//密钥设置，对应结构体NET_DVR_LOCAL_PROTECT_KEY_CFG
    NET_SDK_LOCAL_CFG_TYPE_CFG_VERSION              //用于测试版本头的设备端兼容情况
}NET_SDK_LOCAL_CFG_TYPE;

typedef struct tagNET_DVR_LOCAL_CFG_VERSION
{
    BYTE	byVersion;			            //版本信息
    BYTE	byRes[63];						//保留
}NET_DVR_LOCAL_CFG_VERSION, *LPNET_DVR_LOCAL_CFG_VERSION;

typedef struct tagNET_DVR_LOCAL_TCP_PORT_BIND_CFG
{
	WORD	wLocalBindTcpMinPort;			//本地绑定Tcp最小端口
	WORD	wLocalBindTcpMaxPort;			//本地绑定Tcp最大端口
	BYTE	byRes[60];						//保留
}NET_DVR_LOCAL_TCP_PORT_BIND_CFG, *LPNET_DVR_LOCAL_TCP_PORT_BIND_CFG;


typedef struct tagNET_DVR_LOCAL_UDP_PORT_BIND_CFG
{
	WORD	wLocalBindUdpMinPort;			//本地绑定Udp最小端口
	WORD	wLocalBindUdpMaxPort;			//本地绑定Udp最大端口
	BYTE	byRes[60];						//保留
}NET_DVR_LOCAL_UDP_PORT_BIND_CFG, *LPNET_DVR_LOCAL_UDP_PORT_BIND_CFG;


typedef struct tagNET_DVR_LOCAL_MEM_POOL_CFG
{
	DWORD	dwAlarmMaxBlockNum;		//报警模块内存池最多向系统申请的内存块（block）个数，每个block为64MB, 超过这个上限则不向系统申请，0表示无上限
	DWORD	dwAlarmReleaseInterval;				//报警模块空闲内存释放的间隔，单位秒，为0表示不释放
	BYTE	byRes[512];							//保留
}NET_DVR_LOCAL_MEM_POOL_CFG, *LPNET_DVR_LOCAL_MEM_POOL_CFG;

typedef struct tagNET_DVR_LOCAL_MODULE_RECV_TIMEOUT_CFG
{
	DWORD		dwPreviewTime;		//预览模块超时时间
	DWORD		dwAlarmTime;		//报警模块超时时间
	DWORD		dwVodTime;			//回放模块超时时间
	DWORD		dwElse;				//其他模块
	BYTE		byRes[512];							//保留
}NET_DVR_LOCAL_MODULE_RECV_TIMEOUT_CFG, *LPNET_DVR_LOCAL_MODULE_RECV_TIMEOUT_CFG;

typedef  struct  tagNET_DVR_OPTICAL_CHANNEL_BIND
{
    WORD wChannelIndex;    //光口号(0-7)
	WORD wSubChannel;      //光口子通道号，取值范围从能力集获取
	BYTE  byBind;      //0-不绑定或清除绑定，1-绑定
	BYTE  byRes[3];
}NET_DVR_OPTICAL_CHANNEL_BIND,*LPNET_DVR_OPTICAL_CHANNEL_BIND;

typedef struct tagNET_DVR_OPTICAL_CHANNEL_CFG
{
    DWORD dwSize;
	NET_DVR_OPTICAL_CHANNEL_BIND struBindVideo;//视频绑定
    NET_DVR_OPTICAL_CHANNEL_BIND struBindAudio;//音频绑定
    BYTE  byRes[16];           //保留   
}NET_DVR_OPTICAL_CHANNEL_CFG,*LPNET_DVR_OPTICAL_CHANNEL_CFG;

typedef struct tagNET_DVR_OPTICAL_INFO
{
    DWORD dwSize;
	BYTE  bySlotNum;//编码子系统槽位号
	BYTE  byChannel; //编码通道号
	BYTE  byRes[18];
}NET_DVR_OPTICAL_INFO,*LPNET_DVR_OPTICAL_INFO;

//音频切换
typedef struct tagNET_DVR_AUDIO_SURCHAN_CFG
{
	DWORD dwSize;
	BYTE  byStatus;       //音频是否开启，1-开，0-关
	BYTE  byRes1[3];
	//以下参数当byStatus == 1时有效
	DWORD dwSubWinNum; //关联的子窗口号
	DWORD dwSurChanNum;             /*监控通道号  */   
	NET_DVR_IPADDR struIpaddr;            /*监控通道地址 */
	WORD   wPort;                      	/*监控通道端口 */ 	
	BYTE   byRes2[14];
}NET_DVR_AUDIO_SURCHAN_CFG, *LPNET_DVR_AUDIO_SURCHAN_CFG;

//端口聚合
#define MAX_ETHERNET_PORT_NUM       8//每条链路最大端口数
typedef struct tagNET_DVR_ETHERNET_CHANNEL_INFO
{
	DWORD dwSize;
	BYTE byConverge[MAX_ETHERNET_PORT_NUM];
	//byConverge[i] = j表示将第i个端口加入到第j条链路，j的取值为1-8,j=0表示移除
	BYTE byRes[32];
}NET_DVR_ETHERNET_CHANNEL_INFO,*LPNET_DVR_ETHERNET_CHANNEL_INFO;

//畅显
typedef struct tagNET_DVR_SPARTAN_INFO
{
	DWORD  dwSize;
	BYTE   bySpartanStatus; //0-畅显关，1-畅显开
	BYTE   byRes[31];
}NET_DVR_SPARTAN_INFO,*LPNET_DVR_SPARTAN_INFO;

typedef struct tagNET_DVR_IPADDR_FILTERCFG
{
	DWORD dwSize;
	BYTE byEnable; //启用IP地址过滤，0-否，1-是
	BYTE byFilterType; //过滤类型，0-禁用，1-允许
	BYTE byRes[18];
    BYTE byIPAddr[1024];	//IP地址信息，格式192.168.1.2;192.168.1.3
}NET_DVR_IPADDR_FILTERCFG, *LPNET_DVR_IPADDR_FILTERCFG;

typedef struct tagNET_DVR_LOGO_OVERLAYCFG
{
	DWORD dwSize;
	BYTE  byEnable; //是否启用，0-否，1-是
	BYTE  byRes1[3];
	DWORD dwCoordinateX;	//图片显示区域X坐标
    DWORD dwCoordinateY;	//图片显示区域Y坐标
	WORD  wPicWidth; //图片宽
	WORD  wPicHeight; //图片高
    BYTE  byRes[16];		//保留
}NET_DVR_LOGO_OVERLAYCFG,*LPNET_DVR_LOGO_OVERLAYCFG;


typedef struct tagNET_DVR_INVALID_DISK_PARAM
{
	NET_DVR_STRUCTHEAD	struStructHead;
	DWORD				dwDiskNo;			// 磁盘号
	BYTE				byDelAll;			// 0-删除dwDiskNo  1-删除全部无效磁盘
	BYTE 				byres[31];
}NET_DVR_INVALID_DISK_PARAM, *LPNET_DVR_INVALID_DISK_PARAM;


typedef struct tagNET_DVR_INVALID_MOUNT_DISK_PARAM
{
	NET_DVR_STRUCTHEAD	struStructHead;
	DWORD				dwDiskNo;			// 磁盘号
	BYTE 				byres[32];
}NET_DVR_MOUNT_DISK_PARAM, *LPNET_DVR_MOUNT_DISK_PARAM;

// 长连接回调类型
typedef enum
{
	NET_SDK_CALLBACK_TYPE_STATUS = 0,		// 回调状态值
	NET_SDK_CALLBACK_TYPE_PROGRESS,			// 回调进度值
	NET_SDK_CALLBACK_TYPE_DATA				// 回调数据内容
}NET_SDK_CALLBACK_TYPE;


// 回调类型为NET_SDK_CALLBACK_TYPE_STATUS时的状态值
typedef enum
{
	NET_SDK_CALLBACK_STATUS_SUCCESS = 1000,		// 成功
	NET_SDK_CALLBACK_STATUS_PROCESSING,			// 处理中
	NET_SDK_CALLBACK_STATUS_FAILED,				// 失败
	NET_SDK_CALLBACK_STATUS_EXCEPTION,			// 异常
	NET_SDK_CALLBACK_STATUS_LANGUAGE_MISMATCH,	//（IPC配置文件导入）语言不匹配
	NET_SDK_CALLBACK_STATUS_DEV_TYPE_MISMATCH	//（IPC配置文件导入）设备类型不匹配
}NET_SDK_CALLBACK_STATUS_NORMAL;

#define NET_SDK_OKC_STATUS_SUCCESS				1000  //一键配置成功
#define NET_SDK_OKC_STATUS_FAILED				1002  //一键配置失败
#define NET_SDK_OKC_STATUS_START_CONFIG			1003  //开始配置
#define NET_SDK_OKC_CHECK_HD					1004  //检测磁盘
#define NET_SDK_OKC_INIT_HD						1005  //初始化磁盘
#define NET_SDK_OKC_CREATE_RAID_OR_SINGLE_DISK	1006  //创建阵列或者单盘模式
#define NET_SDK_OKC_INIT_CVR_SERVICE			1007  //初始化CVR服务
#define NET_SDK_OKC_CREATE_RECORD_VOLUME		1008  //创建录像卷
//以下为一键配置失败的状态码
#define NET_SDK_OKC_ERR_LOAD_CONF_FAILED              1009 //加载配置文件失败
#define NET_SDK_OKC_ERR_NOT_SUPPORT_RAID_LEVLE        1010 //不支持此种类型的raid 
#define NET_SDK_OKC_ERR_CONFIGURATION_CONFLICT		  1011 //系统已经存在riad或存储池
#define NET_SDK_OKC_ERR_GET_DISK_INFO_FAILED          1012 //获取磁盘信息失败
#define NET_SDK_OKC_ERR_CHECK_DISK_FAILED             1013 //检测磁盘失败
#define NET_SDK_OKC_ERR_INIT_DISK_FAILED              1014 //初始化磁盘失败
#define NET_SDK_OKC_ERR_DISK_CAPACITY_SMALL           1015 //磁盘总容量不足
#define NET_SDK_OKC_ERR_BOTH_SV_NS                    1016 //同时存在SV盘和NS盘
#define NET_SDK_OKC_ERR_CREATE_RAID_FAILED            1017 //创建raid失败
#define NET_SDK_OKC_ERR_GET_RAID_FAILED               1018 //获取raid失败
#define NET_SDK_OKC_ERR_CREATE_SPARE_FAILED           1019 //创建热备盘失败
#define NET_SDK_OKC_ERR_CREATE_STORAGE_POOL_FAILED    1020 //创建存储池失败
#define NET_SDK_OKC_ERR_GET_POOL_INFO_FAILED          1021 //获取存储池信息失败
#define NET_SDK_OKC_ERR_CREATE_LUN_FAILED   	      1022 //创建lun卷失败
#define NET_SDK_OKC_ERR_GET_LUN_INFO_FAILED           1023 //获取lun信息失败
#define NET_SDK_OKC_ERR_CREATE_BACKUP_FAILED    	  1024 //创建预留卷失败
#define NET_SDK_OKC_ERR_GET_BACKUP_FAILED          	  1025 //获取预留卷失败
#define NET_SDK_OKC_ERR_CREATE_PRIVATE_LUN_FAILED  	  1026 //创建私有卷失败
#define NET_SDK_OKC_ERR_CREATE_RV_FAILED              1027 //创建录像卷失败
#define NET_SDK_OKC_ERR_CREATE_ARCH_RV_FAILED         1028 //创建存档卷失败
#define NET_SDK_OKC_ERR_START_CVR_SERVICE_FAILED	  1029 //开启CVR服务失败

typedef enum
{
	NET_SDK_GET_NEXT_STATUS_SUCCESS = 1000,	// 成功读取到数据，客户端处理完本次数据后需要再次调用NET_DVR_RemoteConfigGetNext获取下一条数据
	NET_SDK_GET_NETX_STATUS_NEED_WAIT,		// 需等待设备发送数据，继续调用NET_DVR_RemoteConfigGetNext函数
	NET_SDK_GET_NEXT_STATUS_FINISH,			// 数据全部取完，此时客户端可调用NET_DVR_StopRemoteConfig结束长连接
	NET_SDK_GET_NEXT_STATUS_FAILED,			// 出现异常，客户端可调用NET_DVR_StopRemoteConfig结束长连接
}NET_SDK_GET_NEXT_STATUS;

//导入配置文件错误码
typedef enum tagNET_SDK_IPC_CFG_FILE_ERR_CODE
{
    NET_SDK_IPC_CFG_FILE_NO_ERR = 0,								/* 没出错 */
	NET_SDK_IPC_CFG_FILE_ERR_CODE_CHANNEL_INVALID = 1,       /* 通道ID非法 */
	NET_SDK_IPC_CFG_FILE_ERR_CODE_CHANNEL_DUPLICATE,         /* 通道ID重复 */
	NET_SDK_IPC_CFG_FILE_ERR_CODE_IP_INVALID,              /* 通道IP或域名非法 */
	NET_SDK_IPC_CFG_FILE_ERR_CODE_IP_DUPLICATE,           /* 通道IP或域名重复 */
	NET_SDK_IPC_CFG_FILE_ERR_CODE_IP_CONFLICT_WITH_LOCAL, /* 通道IP与本地IP冲突 */
	NET_SDK_IPC_CFG_FILE_ERR_CODE_PROTOCOL_INVALID,         /* 协议错误 */
	NET_SDK_IPC_CFG_FILE_ERR_CODE_PORT_INVALID,             /* 管理端口错误 */
	NET_SDK_IPC_CFG_FILE_ERR_CODE_DEVICE_CHANNEL_ERR,   /* 设备通道号错误 */
	NET_SDK_IPC_CFG_FILE_ERR_CODE_USER_NAME_ERR,       /* 用户名含非法字符 */
	NET_SDK_IPC_CFG_FILE_ERR_CODE_PASSWD_ERR,             /* 密码含非法字符 */
    NET_SDK_IPC_CFG_FILE_ERR_CODE_TRANSPORT_PROTOCOL_INVALID /*传输协议错误*/
}NET_SDK_IPC_CFG_FILE_ERR_CODE;

//IPC升级错误码
typedef enum
{
	NET_SDK_UPGRADE_IPC_INVALID = 0,				//无效通道或未选择该通道升级
	NET_SDK_UPGRADE_IPC_SUCCESS,					//升级成功
	NET_SDK_UPGRADE_IPC_OFFLINE,					//IPC不在线
	NET_SDK_UPGRADE_IPC_NOT_SUPPORT,				//IPC不支持升级命令
	NET_SDK_UPGRADE_IPC_LANGUAGE_MISMATCH,			//语言不匹配
	NET_SDK_UPGRADE_IPC_WRITE_FLASH_FAILED,			//写flsh失败
	NET_SDK_UPGRADE_IPC_OTHER_ERROR					//其他错误
}NET_SDK_UPGRADE_IPC_ERR_CODE;


#define MAX_CODE_CARD_SUPPORTDISPNUMS 8//每个编码卡最多支持的显示通道数
#define MAX_SUPPORT_RES 32

typedef enum _BOARD_TYPE
{
	DS4004HC_BOARD		=2,  //4004HC
	DS4008HC_BOARD		=3,  //4008HC
	DS4016HC_BOARD		=4,  //4016HC
	DS4001HF_BOARD		=5,  //4001HF
	DS4004HF_BOARD		=6,  //4004HF
	DS4002MD_BOARD		=7,  //4002MD
	DS4004MD_BOARD		=8,  //4004MD
	DS4016HCS_BOARD		=9,  //4016HCS
	DS4004HC_PLUS_BOARD	=13, //4004HC+
	DS4008HC_PLUS_BOARD	=14, //4008HC+
	DS4016HC_PLUS_BOARD	=15, //4016HC+
	DS4008HF_BOARD		=16, //4008HF
	DS4008MD_BOARD		=17, //4008MD
	DS4008HS_BOARD		=18, //4008HS
	DS4016HS_BOARD		=19, //4016HS
		
	DS4108HCV_BOARD		=20, //4108HCV
	DS4116HCV_BOARD		=21, //4116HCV
	DS5016HC_BOARD		=22, //5016HC
		
	DS4208HFV_BOARD		=23, //4208HFV
	DS4216HC_BOARD		=24, //4216HC
	DS4216HFV_BOARD		=25, //4216HFV
		
	DS5008HF_BOARD		=26, //5008HF
	DS5116HF_BOARD		=27, //5116HF
		
	DS5216HC_BOARD		=28, //5216HC
	DS5208HF_BOARD		=29, //5208HF
	DS5216HF_BOARD		=30, //5216HF
		
	DS4101HD_BOARD		=31, //4101HD
	DS4102HD_BOARD		=32, //4102HD
	DS4104HD_BOARD		=33, //4104HD
		
	DS4002MD_PLUS_BOARD =34, //4002MD+  
	DS4004MD_PLUS_BOARD =35, //4004MD+
		
	DS4204HFV_BOARD		=36, //4204HFV
	DS4308HCV_BOARD		=37, //4308HCV
	DS4308HFV_BOARD		=38, //4308HFV
	DS4316HCV_BOARD		=39, //4316HCV
	DS4316HFV_BOARD		=40, //4316HFV
	DS4304HD_BOARD		=41, //4304HD
	DS4304HFH_BOARD     =42, //4304HFH
	DS4304HFV_BOARD     =43, //4304HFV
	DS4302HFH_BOARD     =44, //4302HFH
	DS5316HF_BOARD      =45, //5316HF
	DS4308HW_BOARD      =46, //4308HW
	DS4316HW_BOARD      =47, //4316HW
	DS4308MD_BOARD      =48, //4308MD
	UNKNOWN_BOARD_TYPE  =0xffffffff,
}BOARD_TYPE;

typedef struct tagNET_DVR_CODECARD_ABILITY /*高清编码卡能力集*/
{
	BYTE byCardType;      //编码卡类型(按BOARD_TYPE中的枚举)
	BYTE byCodeNums;      //编码通道数 
    BYTE byDispNums;      //显示通道数 
    BYTE byCodeStartIdx;     //首个编码通道在所有编码通道中的索引 
    BYTE byDispStartIdx;     //首个显示通道在所有显示通道中的索引
    BYTE byRes1[3]; 
    DWORD dwVgaSupportResolution[MAX_SUPPORT_RES/*32*/];//支持的分辨率
    DWORD dwHdmiSupportResolution[MAX_SUPPORT_RES/*32*/];//支持的分辨率
    DWORD dwDviSupportResolution[MAX_SUPPORT_RES/*32*/];//支持的分辨率
    DWORD dwYpbprSupportResolution[MAX_SUPPORT_RES/*32*/];//支持的分辨率
    BYTE byDispFormat[MAX_CODE_CARD_SUPPORTDISPNUMS];   //支持的输出模式(按HD_DISPLAY_FORMAT中的枚举) 
    BYTE byWindowMode[MAX_CODE_CARD_SUPPORTDISPNUMS][12]; //支持的窗口模式(比如1,2,4,9,16))
    BYTE byRes2[36];
}NET_DVR_CODECARD_ABILITY,*LPNET_DVR_CODECARD_ABILITY;

#define		MAX_CODE_CARD_NUM			8   //最多高清编码卡数
typedef struct tagNET_DVR_CODESVR_ABILITY
{
    DWORD dwSize;      /* 结构体大小 */
    BYTE byCardNums;      /* 编码卡数 */
    BYTE byStartChan;     /* 起始通道号 */
    BYTE byRes1[2];
    NET_DVR_CODECARD_ABILITY struCodeCardAbility[MAX_CODE_CARD_NUM];
    BYTE byRes2[64];
}NET_DVR_CODESVR_ABILITY, *LPNET_DVR_CODESVR_ABILITY;

typedef struct tagNET_DVR_CODER_SERVER_OUTPUT_CFG
{
	DWORD  dwSize;
	BYTE   byDispChanType;		/*显示通道类型：0-BNC，1-VGA，2-HDMI，3-DVI*/ //此参数只能获取
	BYTE   byVedioFormat;      /*1:NTSC,2:PAL，0-NULL*/
	BYTE   byRes1[2];
	DWORD  dwResolution;       //分辨率
	DWORD  dwWindowMode;		/*画面模式，支持模式从能力集获取*/
	BYTE   byRes2[64];
}NET_DVR_CODER_SERVER_OUTPUT_CFG,*LPNET_DVR_CODER_SERVER_OUTPUT_CFG;

typedef struct tagNET_DVR_DISPLAY_START_INFO 
{
	DWORD  dwSize;
	DWORD  dwDisplayChan; //显示通道号
	DWORD  dwCodeChan; //编码通道号
	DWORD  dwWinNum;   //窗口号，从1起
	BYTE   byEnableAudio; //开启音频，0-关，1-开
	BYTE   byRes[31];
}NET_DVR_DISPLAY_START_INFO,*LPNET_DVR_DISPLAY_START_INFO;

typedef struct tagNET_DVR_CODER_WINDOW_INFO
{
	DWORD dwSize;
	DWORD dwDisplayChan;//显示通道号
	DWORD dwWinNum;     //窗口号，从1开始
	BYTE  byRes[16];
}NET_DVR_CODER_WINDOW_INFO,*LPNET_DVR_CODER_WINDOW_INFO;

typedef struct tagNET_DVR_WINDOW_STATUS
{
    DWORD  dwSize;         //结构大小
    DWORD  dwCodeChan;      /*编码通道号*/
    BYTE   byDisplay;              /*是否输出，0-否，1-是*/
    BYTE   byAudio;			/*音频是否开启,0-否，1-是*/   
    BYTE   byRes[30];                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          
}NET_DVR_WINDOW_STATUS,*LPNET_DVR_WINDOW_STATUS;

typedef struct tagNET_DVR_RECORD_LOCK_PERCENTAGE
{
	DWORD 	dwSize;      		//结构体大小
	BYTE 	byPercentage;    	//百分比，取值范围[0,100]
	BYTE  	byRes[31];          //保留
}NET_DVR_RECORD_LOCK_PERCENTAGE, *LPNET_DVR_RECORD_LOCK_PERCENTAGE;

typedef struct tagNET_DVR_UPDATE_RECORD_INFO
{
	DWORD 			dwSize; 			//结构体大小
	NET_DVR_STREAM_INFO struStreasmInfo; 	//流ID
	DWORD  			dwBeginTime;    //录像总的开始时间
	DWORD 			dwEndTime;		//录像总的结束时间
	BYTE  			byRes[32];       //保留
}NET_DVR_UPDATE_RECORD_INFO, *LPNET_DVR_UPDATE_RECORD_INFO;

typedef struct tagNET_DVR_CMD_TRIGGER_PERIOD_RECORD_PARA
{
	NET_DVR_STREAM_INFO		struStreamInfo; 
	DWORD					dwCmdType; 						//外部触发类型 
	DWORD					dwRecordTimeLen;				//录像持续时间，单位：秒
	BYTE					byEventID[MAX_EVENTID_LEN];		//事件ID，作为附加信息
	BYTE					byRes[128];
}NET_DVR_CMD_TRIGGER_PERIOD_RECORD_PARA, *LPNET_DVR_CMD_TRIGGER_PERIOD_RECORD_PARA;

typedef struct tagNET_DVR_LOCK_FILE_BY_NAME_PARA
{
	BYTE				byFileName[NAME_LEN]; 	// 录像文件名，老协议只传32个文件名
    DWORD				dwLockDuration;			// 锁定持续时间,单位秒，0xffffffff表示永久锁定
	BYTE				byRes[512];
}NET_DVR_LOCK_FILE_BY_NAME_PARA, *LPNET_DVR_LOCK_FILE_BY_NAME_PARA;


typedef struct tagNET_DVR_MULTI_STREAM_COMPRESSIONCFG_COMD
{
	DWORD					dwSize;
    NET_DVR_STREAM_INFO		struStreamInfo;
    DWORD					dwStreamType; //码流类型，0-主码流，1-子码流，2-事件类型，3-码流3，……
	BYTE					byRes[32];
}NET_DVR_MULTI_STREAM_COMPRESSIONCFG_COND, *LPNET_DVR_MULTI_STREAM_COMPRESSIONCFG_COND;


typedef struct tagNET_DVR_MULTI_STREAM_COMPRESSIONCFG
{
	DWORD							dwSize;
    DWORD							dwStreamType;		//码流类型，0-主码流，1-子码流，2-事件类型，3-码流3，……
	NET_DVR_COMPRESSION_INFO_V30	struStreamPara;		//码流压缩参数
	BYTE							byRes[80];
}NET_DVR_MULTI_STREAM_COMPRESSIONCFG, *LPNET_DVR_MULTI_STREAM_COMPRESSIONCFG;

typedef struct tagNET_DVR_PUSHALARMINFO_V40
{
	DWORD dwAlarmType; /*0-信号量报警,1-硬盘满,2-信号丢失,3－移动侦测,4－硬盘未格式化,5-读写硬盘出错,6-遮挡报警,7-制式不匹配, 8-非法访问, 9-视频信号异常，10-录像异常 11- 智能场景变化  12-阵列异常 */
	union
	{
		BYTE byRes[300];
		struct
		{
			DWORD dwAlarmInputNumber;    /*按位,第0位对应第0个输入端口,dwAlarmType为0时需要设置*/
			BYTE  byAlarmOutputNumber[MAX_ALARMOUT_V30];   /*按位,第0位对应第0个输出端口, */
			BYTE  byAlarmRelateChannel[MAX_CHANNUM_V30];  /*按位,第0位对应第0个通道*/
			BYTE  byRes1[97];
            BYTE  byDeviceID[NAME_LEN]; /*设备的ID串*/
            BYTE  byRes2[7];
		}struIOAlarm;
		struct
		{
			BYTE byStreamID[STREAM_ID_LEN]; // ID信息
			BYTE byRes1[132];
			BYTE byChannel[MAX_CHANNUM_V30];             /*按位,0x2表示第1通道，第1位对应第1个通道(从通道1开始)，dwAlarmType为2或3, 6，9，10时需要设置, */
			BYTE byRes2[33];
            BYTE byDeviceID[NAME_LEN]; /*设备的ID串*/
            BYTE byRes3[7];
		}struStreamIDorChannel;
		struct
		{
			BYTE byRes1[228];
			BYTE byDiskNumber[MAX_DISKNUM_V30];  /*按位,第0位对应第0个硬盘,dwAlarmType为1,4,5时需要设置*/
            BYTE byDeviceID[NAME_LEN]; /*设备的ID串*/
            BYTE byRes2[7];
		}struDiskAlarm;
	}uAlarmInfo;
}NET_DVR_PUSHALARMINFO_V40, *LPNET_DVR_PUSHALARMINFO_V40;

typedef struct tagNET_DVR_RECORD_PACK
{
    NET_DVR_STRUCTHEAD 	struStruceHead;
	DWORD 			dwPackageInterval;    // 打包时间间隔 ，时间单位：分钟
	BYTE  			byRes[32];       		// 保留
}NET_DVR_RECORD_PACK,*LPNET_DVR_RECORD_PACK;


#define NET_DVR_FIND_NAS_DIRECTORY     6161        //查找NAS目录
#define NET_DVR_NAS_FINDING       0   //正在查找
#define NET_DVR_NAS_RECV          1   //接收数据
#define NET_DVR_NAS_OVER          2   //查找结束
#define NET_DVR_NAS_EXCEPTION     3   //接收异常
typedef struct tagNET_DVR_NET_DISK_SERACH_PARAM
{
    NET_DVR_IPADDR    		  struIP;     	// IP地址
    WORD  			wPort;      // IP端口
    BYTE    			byRes[10];  // 保留字节
}NET_DVR_NET_DISK_SERACH_PARAM, *LPNET_DVR_NET_DISK_SERACH_PARAM;


typedef struct tagNET_DVR_NET_DISK_SERACH_RET
{
    BYTE byDirectory[128];  // 返回的文件目录
    BYTE byRes[20];
}NET_DVR_NET_DISK_SERACH_RET, *LPNET_DVR_NET_DISK_SERACH_RET;

typedef struct tagNET_DVR_WD1_CFG
{
	NET_DVR_STRUCTHEAD 	struStruceHead;
	BYTE  			byWD1Enable;     	//WD1使能开关 0 关闭 1 开启	
	BYTE 				byRes[31];          	//保留
}NET_DVR_WD1_CFG, *LPNET_DVR_WD1_CFG;

typedef struct tagNET_DVR_FTPCFG_V40
{
	NET_DVR_STRUCTHEAD 	struStruceHead;
	BYTE				byEnableFTP;		    /*是否启动ftp上传功能，0-否，1-是*/
	BYTE				byProtocolType;	 	    /*协议类型 0-FTP，1-SFTP*/
	WORD				wFTPPort;			    /*端口*/
	union 
	{
		struct
		{
			BYTE			szDomain[64];	    //服务器地址，可以使IPv4 IPv6或是域名
			BYTE			byRes1[80];
		}struDomain;
		struct
		{
			NET_DVR_IPADDR 	struIp;             /*IP地址:IPv4 IPv6地址, 144字节*/
		}struAddrIP;
	}unionServer;  //使用联合体结构，防止既是IP地址又是域名的情况

	BYTE				szUserName[32];		    /*用户名*/
	BYTE				szPassWORD[16];		    /*密码*/
	BYTE				szTopCustomDir[64];	    /*自定义一级目录*/
	BYTE				szSubCustomDir[64];	    /*自定义二级目录*/
	BYTE				byDirLevel;	            /*0 = 不使用目录结构，直接保存在根目录,	1 = 使用1级目录,2=使用2级目录*/
	BYTE 				byTopDirMode;	        /* 一级目录，0x1 = 使用设备名,0x2 = 使用设备号,0x3 = 使用设备ip地址，
												   0x4=使用监测点,0x5=使用时间(年月),0x6-使用自定义 ,0x7=违规类型,
												   0x8=方向,0x9=地点*/
	BYTE 				bySubDirMode;           /*二级目录，0x1=使用通道名,0x2=使用通道号 0x3=使用时间(年月日),
											      0x4=使用车道号,0x5-使用自定义, 0x6=违规类型,0x7=方向,0x8=地点,
											      0x9 = 车位编号*/
	BYTE				byType;			        /* 0-主服务器，1-备服务器*/
	BYTE                byEnableAnony;          /*启用匿名 0-否 1是*/
	BYTE                byAddresType;           /*0 使用IPV4、IPV6  1- 使用域名*/
	/*******************2013-09-27 新增参数 begin********************************/
	BYTE				byFTPPicType;           //0-保留，1-停车场抓拍图片命名规则
	BYTE 				byRes2;                 /*保留*/
	NET_DVR_PICTURE_NAME_EX	 struPicNameRule;   /* 图片命名规则: 	
												   byFTPPicType ==1的时候,自数组内的命名规则是停车场抓拍图片命名规则*/
	BYTE 				byRes[204];             /*保留*/
	/*******************2013-09-27 新增参数 end ********************************/
}NET_DVR_FTPCFG_V40, *LPNET_DVR_FTPCFG_V40;

typedef struct tagNET_DVR_FTP_TYPE
{
	BYTE	byType;  // 0-主服务器，1-备服务器
	BYTE	byRes[3];
}NET_DVR_FTP_TYPE, *LPNET_DVR_FTP_TYPE;


/********************************电视墙 begin*********************************/
typedef struct tagNET_DVR_SINGLEWALLPARAM
{
	DWORD  dwSize;
	BYTE   byEnable;	
	BYTE   byRes1[3];
	DWORD  dwWallNum;//电视墙输出号
	//坐标须为基准坐标的整数倍（128×128），宽度和高度值不用设置，即为基准值
	NET_DVR_RECTCFG struRectCfg;
	BYTE	byRes2[36];
}NET_DVR_SINGLEWALLPARAM, *LPNET_DVR_SINGLEWALLPARAM;

/*窗口信息*/
typedef struct tagNET_DVR_WALLWINCFG
{
	DWORD dwSize;
	BYTE  byEnable;
	BYTE  byRes1[7];
	DWORD dwWinNum;//窗口号
	DWORD dwLayerIndex;//窗口相对应的图层号
	NET_DVR_RECTCFG struWinPosition;//目的窗口(相对显示墙)
	DWORD dwDeviceIndex;//分布式大屏控制器设备序号
	WORD wInputIndex;//输入信号源
	BYTE  byRes2[14];
}NET_DVR_WALLWINCFG, *LPNET_DVR_WALLWINCFG;

typedef struct tagNET_DVR_WALL_INDEX
{
	DWORD	dwSize;
	BYTE	byWallNo;	//电视墙序号，从1开始
	BYTE	bySceneNo;	//场景序号
	BYTE	byRes1[2];
	DWORD	dwDeviceID;	//分布式子设备ID
	DWORD	dwWindowNo;	//窗口序号/信号源序号
	BYTE	byRes2[32];
}NET_DVR_WALL_INDEX, *LPNET_DVR_WALL_INDEX;

typedef struct tagNET_DVR_WALLWINPARAM
{
	DWORD dwSize;
	BYTE  byTransparency; //使能透明度，0-关，非0-开	
	BYTE  byWinMode;//窗口分屏模式，能力集获取
    BYTE  byEnableSpartan;//畅显使能，0-关，1-开
    BYTE  byDecResource;  //为窗口分配的解码资源，1-D1,2-720P,3-1080P
    BYTE  byRes[32];
}NET_DVR_WALLWINPARAM, *LPNET_DVR_WALLWINPARAM;

typedef struct tagNET_DVR_WALLSCENECFG
{
	DWORD	dwSize;
	BYTE	sSceneName[NAME_LEN];	//场景名称
	BYTE	byEnable;				//场景是否有效，0-无效，1-有效
	BYTE	bySceneIndex;			//场景号，只能获取。获取所有场景时使用该参数
	BYTE	byRes [78];
}NET_DVR_WALLSCENECFG, *LPNET_DVR_WALLSCENECFG;

typedef struct tagNET_DVR_WALLWIN_INFO
{
	DWORD dwSize;
	DWORD dwWinNum;   //窗口号
	DWORD dwSubWinNum;//子窗口号
	BYTE  byRes[16];
}NET_DVR_WALLWIN_INFO,*LPNET_DVR_WALLWIN_INFO;

typedef struct tagNET_DVR_WALL_WIN_STATUS
{
	DWORD dwSize ;
    BYTE  byDecodeStatus; /*当前解码状态:0:未启动,1 :已启动*/
    BYTE  byStreamType;    /*码流类型*/
    BYTE  byPacketType;    /*打包方式*/
    BYTE  byFpsDecV; /*视频解码帧率*/
    BYTE  byFpsDecA; /*音频解码帧率*/
    BYTE  byRes1[7];    
    DWORD dwDecodedV; /*解码的视频帧*/
    DWORD dwDecodedA; /*解码的音频帧*/
    WORD  wImgW; /*当前码流源的图像大小*/
    WORD  wImgH; 
    BYTE  byStreamMode ; //码流源(此参数对视频综合平台有效)：1-网络，2-综合平台内部编码子系统,0xff-无效
    BYTE  byRes2[31];
}NET_DVR_WALL_WIN_STATUS, *LPNET_DVR_WALL_WIN_STATUS;

typedef struct tagNET_DVR_WININDEX_INFO
{
	DWORD dwWinIndex; //窗口号
	DWORD dwSubWinIndex;//子窗口号
	BYTE  byType ;//资源类型，1-解码，2-回显
    BYTE  byRes[7];
}NET_DVR_WININDEX_INFO, *LPNET_DVR_WININDEX_INFO;

typedef struct tagNET_DVR_ASSOCIATEDDEV_CHAN_INFO
{
	DWORD  dwSize ;
	BYTE   sAddress[MAX_DOMAIN_NAME];//ip地址，或是域名
    WORD   wDVRPort;			 	/* 端口号 */
    WORD   wChannel;				/* 通道号 */
    BYTE   sUserName[NAME_LEN];	/* 监控主机登陆帐号 */
	BYTE   sPassword[PASSWD_LEN];	/* 监控主机密码 */
    BYTE   byRes[24];
}NET_DVR_ASSOCIATEDDEV_CHAN_INFO,*LPNET_DVR_ASSOCIATEDDEV_CHAN_INFO;

typedef struct tagNET_DVR_WALLOUTPUTPARAM
{
	DWORD dwSize;
	DWORD dwResolution; //分辨率	
	NET_DVR_VIDEOEFFECT struRes;
	BYTE  byVideoFormat;  //0-无效，1-N制，2-P制
	BYTE  byRes[63];
}NET_DVR_WALLOUTPUTPARAM, *LPNET_DVR_WALLOUTPUTPARAM;

#define 	MAX_UNITEDMATRIX_NUM		8  //级联中最多视频综合平台数量

typedef struct NET_DVR_SUBMATRIXSYSTEMINFO
{
	//平台号，0表示无此平台
	DWORD		dwSequence;
	BYTE		sAddress[MAX_DOMAIN_NAME];//ip地址，或是域名
    WORD		wSubMatrixPort;        /*子系统端口号*/
	BYTE		byRes1[6];   
	BYTE		sUserName[NAME_LEN];	/*用户名*/
	BYTE		sPassword[PASSWD_LEN];	/*密码 */   
	BYTE		byRes2[36];
}NET_DVR_SUBMATRIXSYSTEMINFO,*LPNET_DVR_SUBMATRIXSYSTEMINFO;

typedef struct tagNET_DVR_UNITEDMATRIXSYSTEMINFO
{
	DWORD dwSize;
	//视频综合平台信息
	NET_DVR_SUBMATRIXSYSTEMINFO struMatrixInfo[MAX_UNITEDMATRIX_NUM]; 
    BYTE  byRes[32];
}NET_DVR_UNITEDMATRIXSYSTEMINFO,*LPNET_DVR_UNITEDMATRIXSYSTEMINFO;

typedef struct tagNET_DVR_WALL_CFG
{
	DWORD dwSize;
	BYTE  byTransparency;//透明度,0-100,0为不透明
	BYTE  byRes[63];
}NET_DVR_WALL_CFG,*LPNET_DVR_WALL_CFG;
/********************************电视墙 end*********************************/

typedef struct tagNET_DVR_LOW_LIGHT_CFG
{
	DWORD dwSize;
	BYTE  byLowLightLimt; /* 低照度电子快门: 0-关，1-开 */
	BYTE  byLowLightLimtLevel; /*球机0-关，1-慢快门*2，2-慢快门*3，3-慢快门*4，4-慢快门*6，5-慢快门*8，6-慢快门*12，7-慢快门*16，8-慢快门*24，9-慢快门*32，10-慢快门*48，11-慢快门*64，12-慢快门*96，13-慢快门*128，14-慢快门*256，15-慢快门*512*/
	BYTE  byRes[66];
}NET_DVR_LOW_LIGHT_CFG, *LPNET_DVR_LOW_LIGHT_CFG;

typedef struct tagNET_DVR_FOCUSMODE_CFG
{
	DWORD dwSize;
	BYTE  byFocusMode;  /* 聚焦模式，0-自动，1-手动，2-半自动 */
	BYTE  byAutoFocusMode; /* 自动聚焦模式，0-关，1-模式A，2-模式B，3-模式AB，4-模式C 自动聚焦模式，需要在聚焦模式为自动时才显示*/
	WORD  wMinFocusDistance; /* 最小聚焦距离，单位CM,  0-自动，0xffff-无穷远 */
	BYTE  byZoomSpeedLevel;  /* 变倍速度，为实际取值，1-3 */
	BYTE  byFocusSpeedLevel; /* 聚焦速度，为实际取值，1-3 */
	BYTE  byOpticalZoom;		/* 光学变倍，0-255 */
	BYTE  byDigtitalZoom;		/* 数字变倍，0-255 */
	BYTE  byRes[64];
}NET_DVR_FOCUSMODE_CFG, *LPNET_DVR_FOCUSMODE_CFG;

typedef struct tagNET_DVR_INFRARE_CFG
{
	DWORD  dwSize;
	BYTE  byIrControlMode;  /* 红外球机配置-控制模式：0-自动，1-手动 */
	BYTE  byIrBrightness;	/* 红外球机配置-红外亮度：0-100 */
	BYTE  byIrSensitivity;	/* 红外球机配置-红外灯灵敏度：0-100 */
	BYTE  byIrTrigMode; /* 触发模式 0-机芯触发，1-光敏触发 自动模式下生效*/
	BYTE  byIrBrightnessLimit;/* 亮度限制 如果此值为80，表示的意义是当前红外灯的亮度为原先根据自动策略计算出的亮度值×80% 自动模式下生效*/   
	BYTE  byRes[63];
}NET_DVR_INFRARE_CFG, *LPNET_DVR_INFRARE_CFG;

typedef struct tagNET_DVR_AEMODECFG
{
	DWORD  dwSize;
	int   iIrisSet;	/* 光圈，为实际取值*100的值，0-关 */
	int   iGainSet;	/* 快球增益，曝光补偿，为实际取值*100的值，有可能是负值 */
	int   iGainLimit;/* 增益限制，曝光补偿，为实际取值*100的值，有可能是负值 */
	int   iExposureCompensate; /* 曝光补偿，为实际取值*100的值，比如1050代表10.5dB, -750代表-7.5dB */
	BYTE  byExposureModeSet;	/* 球机的曝光模式,0-手动模式，1-自动曝光，2-光圈优先，3-快门优先，4-增益优先 */
	BYTE  byShutterSet;	/* 快门，0-关，1-自动x1，2-自动x2，3-自动x4，4-自动x8，5-自动x16，6-自动x32，7-自动x64，8-自动x128，9-1/1，10-1/2，11-1/3，12-1/4，13-1/6，14-1/8，15-1/12，16-1/15，17-1/25，18-1/30，19-1/50，20-1/60，21-1/75，22-1/90，23-1/100，24-1/120，25-1/125，26-1/150，27-1/180，28-1/200，29-1/215，30-1/250，31-1/300，32-1/350，33-1/425，34-1/500，35-1/600，36-1/725，37-1/1000，38-1/1250，39-1500,40-1/1750，41-1/2000，42-1/2500，43-3000,44-1/3500，45-1/4000，46-1/6000，47-1/10000，48-1/30000，49-1/100000 */
	BYTE  byImageStabilizeLevel;  /* 防抖动等级: 0-3 */
	BYTE  byCameraIrCorrect; /* 红外校正: 0-自动，1-开，2,关 */
	BYTE  byHighSensitivity; /* 高灵敏度设置: 0-关，1-开 */
	BYTE  byInitializeLens;  /* 初始化镜头: 0-关，1-开 */
	BYTE  byChromaSuppress; /* 色彩抑制 :0-255*/
	BYTE  byRes[65];
}NET_DVR_AEMODECFG, *LPNET_DVR_AEMODECFG;

typedef struct tagNET_DVR_EXTERNAL_MATRIX_CFG
{
	DWORD		dwSize;
	BYTE		byValid;			// 有效时为设置，无效时为删除
	BYTE		byRes1[3];
	BYTE	    sMatrixName[NAME_LEN/*32*/];       // 矩阵的名称
	DWORD  	    dwMatrixID;		// 矩阵的ID号，只能获取
	WORD		wMatrixInputChanNum;				// 矩阵的输入通道数目
	WORD		wMatrixOutputChanNum;			// 矩阵的输出通道数目
	WORD   	    wMatrixOutputChanRef[MAX_CAM_COUNT];   // 设备输入和矩阵输出的绑定关系，数组下标表示控制器设备输入通道号，元素的值表示矩阵的输出通道号，元素值大于0 表示绑定矩阵输出通道，元素值为0时表示不绑定。
	BYTE		byMatrixChanType;// 矩阵的通道类型1-BNC、2-VGA、3-RGB、4-DVI
	BYTE		byMatrixProtocol;	// 矩阵所用协议1、ZT1.0、2.ZT2.0、3.Extron、4.Creator
	BYTE		byMatrixType;		//1-模拟矩阵，2-数字矩阵
	BYTE		byRes2;
	NET_MATRIX_UNION struMatrixUnion;	
	BYTE		byRes3[128];		
}NET_DVR_EXTERNAL_MATRIX_CFG, *LPNET_DVR_EXTERNAL_MATRIX_CFG;


#define MAX_INPUTNUMS 1024
#define MAX_OUTPUTNUMS 256
typedef struct tagNET_DVR_ASSOCIATE_INPUT_PARAM
{
	BYTE byEnable;
	BYTE byRes1[3];
	DWORD dwDeviceIndex;//分布式大屏控制器设备序号
	WORD wInputIndex;//输入信号源
	BYTE  byRes2[18];
}NET_DVR_ASSOCIATE_INPUT_PARAM, *LPNET_DVR_ASSOCIATE_INPUT_PARAM;

typedef struct tagNET_DVR_ASSOCIATE_OUTPUT_PARAM
{
	BYTE	byEnable;
	BYTE	byWallNo;		//墙号，从1开始
	BYTE	byRes1[2];
	DWORD	dwOutputIndex;	//输出显示屏的序号	
	BYTE	byRes2[20];
}NET_DVR_ASSOCIATE_OUTPUT_PARAM,*LPNET_DVR_ASSOCIATE_OUTPUT_PARAM;

typedef struct tagNET_DVR_VCS_USER_INFO
{
	DWORD   dwSize;
	BYTE	sUserName[NAME_LEN];			// 用户名，最大16字节
	BYTE	sPassWord[PASSWD_LEN];		// 密码
	NET_DVR_IPADDR	struUserIP;	// 用户IP地址(为0时表示允许任何地址)
	BYTE	byMacAddr[MACADDR_LEN];			// 物理地址
	BYTE	byPriority;		// 优先级，1-管理员，2-操作员 ，管理员具有任何权限，操作员没有"管理用户"的权限
	BYTE	byRes1;
	DWORD	dwRight;/*远程操作权限，按位表示，0-不支持，1-支持，各32位代表的权限类型*/	
	//bit0-查看基本参数
	//bit1-设置基本参数
	//bit2-显示屏管理
	//bit3-窗口管理
	//bit4-信号源管理
	//bit5-布局管理
	//bit6-预案管理
	//bit7-底图管理
	//bit8-OSD管理
	//bit9-回显权限
	//bit10-报警布防
	//bit11-远程升级
	//bit12-恢复默认设置
	//bit13-导入导出配置
	//bit14-日志查询
	//bit15-远程重启
	//bit16-GIS地图
	NET_DVR_ASSOCIATE_INPUT_PARAM struInputParam[MAX_INPUTNUMS/*1024*/];
	NET_DVR_ASSOCIATE_OUTPUT_PARAM struOutputParam[MAX_OUTPUTNUMS/*256*/];
	BYTE	byRes2[128];				/* 保留 */
} NET_DVR_VCS_USER_INFO, *LPNET_DVR_VCS_USER_INFO;

typedef struct tagNET_DVR_STREAM_MEDIA_SERVER_CFG_V41
{    
    BYTE    byValid; //是否启用，0-否，1-是
    BYTE	byRes1[3];
    BYTE    byAddress[MAX_DOMAIN_NAME];   //IP或者域名   
    WORD	wDevPort;			/*流媒体服务器端口*/    
    BYTE	byTransmitType;		/*传输协议类型 0-TCP，1-UDP*/
    BYTE	byRes2[69];
}NET_DVR_STREAM_MEDIA_SERVER_CFG_V41,*LPNET_DVR_STREAM_MEDIA_SERVER_CFG_V41;

//设备通道信息
typedef struct tagNET_DVR_DEV_CHAN_INFO_V41
{
	BYTE    byAddress[MAX_DOMAIN_NAME];	//设备域名
    WORD 	wDVRPort;			 	//端口号
    BYTE 	byChannel;				//通道号
    BYTE	byTransProtocol;		//传输协议类型0-TCP，1-UDP
    BYTE	byTransMode;			//传输码流模式 0－主码流 1－子码流
    BYTE	byFactoryType;			/*前端设备厂家类型,通过接口获取*/
    BYTE	byDeviceType; //设备类型(视频综合平台智能板使用)，1-解码器（此时根据视频综合平台能力集中byVcaSupportChanMode字段来决定是使用解码通道还是显示通道），2-编码器
    BYTE    byDispChan;//显示通道号,智能配置使用
    BYTE	bySubDispChan;//显示通道子通道号，智能配置时使用
	BYTE	byResolution;	//; 1-CIF 2-4CIF 3-720P 4-1080P 5-500w大屏控制器使用，大屏控制器会根据该参数分配解码资源
    BYTE    byUseZeroChan; //是否使用零通道，0-否，1-是
    BYTE	byRes[1];   
    BYTE	sUserName[NAME_LEN];	//监控主机登陆帐号
    BYTE	sPassword[PASSWD_LEN];	//监控主机密码
}NET_DVR_DEV_CHAN_INFO_V41,*LPNET_DVR_DEV_CHAN_INFO_V41;

typedef struct tagNET_DVR_DEV_CHAN_INFO_EX
{
	BYTE    byChanType;              //通道类型，0-普通通道,1-零通道,2-流ID
	BYTE    byStreamId[STREAM_ID_LEN];//流ID
	BYTE    byRes1[31];
	BYTE    byAddress[MAX_DOMAIN_NAME];	//设备域名
    WORD 	wDVRPort;			 	//端口号
    BYTE 	byChannel;				//通道号
    BYTE	byTransProtocol;		//传输协议类型0-TCP，1-UDP
    BYTE	byTransMode;			//传输码流模式 0－主码流 1－子码流
    BYTE	byFactoryType;			/*前端设备厂家类型,通过接口获取*/
    BYTE	byDeviceType; //设备类型(视频综合平台智能板使用)，1-解码器（此时根据视频综合平台能力集中byVcaSupportChanMode字段来决定是使用解码通道还是显示通道），2-编码器
    BYTE    byDispChan;//显示通道号,智能配置使用
    BYTE	bySubDispChan;//显示通道子通道号，智能配置时使用
	BYTE	byResolution;	//; 1-CIF 2-4CIF 3-720P 4-1080P 5-500w大屏控制器使用，大屏控制器会根据该参数分配解码资源
    BYTE	byRes[2];   
    BYTE	sUserName[NAME_LEN];	//监控主机登陆帐号
    BYTE	sPassword[PASSWD_LEN];	//监控主机密码
}NET_DVR_DEV_CHAN_INFO_EX,*LPNET_DVR_DEV_CHAN_INFO_EX;

typedef struct tagNET_DVR_STREAM_MEDIA_SERVER
{    
    BYTE   byValid; //是否启用，0-否，1-是
    BYTE   byRes1[3];
    BYTE   byAddress[MAX_DOMAIN_NAME];   //IP或者域名 
    WORD   wDevPort;			/*流媒体服务器端口*/    
    BYTE   byTransmitType;		/*传输协议类型 0-TCP，1-UDP*/
    BYTE   byRes2[5];
}NET_DVR_STREAM_MEDIA_SERVER,*LPNET_DVR_STREAM_MEDIA_SERVER;

typedef struct tagNET_DVR_DEV_DDNS_INFO
{
	BYTE   byDevAddress[MAX_DOMAIN_NAME];	//域名(IPServer或hiDDNS时可填序列号或者别名)
	BYTE   byTransProtocol;		//传输协议类型0-TCP，1-UDP, 2-MCAST
	BYTE   byTransMode;			//传输码流模式 0－主码流 1－子码流
	BYTE   byDdnsType;         //域名服务器类型，0-IPServer 1－Dyndns 2－PeanutHull(花生壳)，3- NO-IP, 4- hiDDNS
	BYTE   byRes1[1];
	BYTE   byDdnsAddress[MAX_DOMAIN_NAME];  //DDNS服务器地址
	WORD   wDdnsPort;			 	//DDNS服务器端口号
	BYTE   byChanType;              //0-普通通道,1-零通道,2-流ID
	BYTE   byFactoryType;			//前端设备厂家类型,通过接口获取
	DWORD  dwChannel; //通道号
	BYTE   byStreamId[STREAM_ID_LEN]; //流ID
    BYTE   sUserName[NAME_LEN];	//监控主机登陆帐号
	BYTE   sPassword[PASSWD_LEN];	//监控主机密码
	WORD   wDevPort;				//前端设备通信端口
	BYTE   byRes2[2];
}NET_DVR_DEV_DDNS_INFO,*LPNET_DVR_DEV_DDNS_INFO;

typedef struct tagNET_DVR_DEC_STREAM_DEV_EX
{
	NET_DVR_STREAM_MEDIA_SERVER	struStreamMediaSvrCfg;
	NET_DVR_DEV_CHAN_INFO_EX			    struDevChanInfo;
}NET_DVR_DEC_STREAM_DEV_EX,*LPNET_DVR_DEC_STREAM_DEV_EX;


//DDNS方式取流
typedef struct tagNET_DVR_DEC_DDNS_DEV
{
	NET_DVR_DEV_DDNS_INFO struDdnsInfo;
	NET_DVR_STREAM_MEDIA_SERVER struMediaServer;
}NET_DVR_DEC_DDNS_DEV,*LPNET_DVR_DEC_DDNS_DEV;

typedef union tagNET_DVR_DEC_STREAM_MODE
{
    NET_DVR_DEC_STREAM_DEV_EX struDecStreamDev;
	NET_DVR_PU_STREAM_URL struUrlInfo;
	NET_DVR_DEC_DDNS_DEV struDdnsDecInfo;
	BYTE byRes[300];	
}NET_DVR_DEC_STREAM_MODE,*LPNET_DVR_DEC_STREAM_MODE;

typedef struct tagNET_DVR_PU_STREAM_CFG_V41
{
	DWORD dwSize;
    BYTE byStreamMode;/*取流模式，0-无效，1-通过IP或域名取流，2-通过URL取流,3-通过动态域名解析向设备取流*/
	BYTE byRes1[3];
    NET_DVR_DEC_STREAM_MODE uDecStreamMode;//取流信息
	BYTE  byRes2[64];
}NET_DVR_PU_STREAM_CFG_V41,*LPNET_DVR_PU_STREAM_CFG_V41;

typedef struct  tagNET_DVR_MATRIX_CHAN_INFO_V41
{
	BYTE byEnable; //是否启用，0-否，1-是
	BYTE byStreamMode;/*取流模式，0-无效，1-通过IP或域名取流，2-通过URL取流,3-通过动态域名解析向设备取流*/
	BYTE byRes[2];
    NET_DVR_DEC_STREAM_MODE uDecStreamMode;//取流信息
}NET_DVR_MATRIX_CHAN_INFO_V41,*LPNET_DVR_MATRIX_CHAN_INFO_V41;

typedef struct  tagNET_DVR_MATRIX_LOOP_DECINFO_V41
{
    DWORD							dwSize;
    DWORD							dwPoolTime;		/*轮巡间隔*/
    NET_DVR_MATRIX_CHAN_INFO_V41	struchanConInfo[MAX_CYCLE_CHAN_V30];
    BYTE               			byRes[16];
}NET_DVR_MATRIX_LOOP_DECINFO_V41,*LPNET_DVR_MATRIX_LOOP_DECINFO_V41;

typedef struct tagNET_DVR_MATRIX_DEC_CHAN_INFO_V41
{
    DWORD	dwSize;
    BYTE byStreamMode;/*取流模式，0-无效，1-通过IP或域名取流，2-通过URL取流,3-通过动态域名解析向设备取流*/
	BYTE byRes1[3];
    NET_DVR_DEC_STREAM_MODE uDecStreamMode;//取流信息
    DWORD	dwPlayMode;		/* 0-动态解码 1－循环解码 2－按时间回放 3－按文件回放 */
    NET_DVR_TIME StartTime;		/* 按时间回放开始时间 */
    NET_DVR_TIME StopTime;		/* 按时间回放停止时间 */
    BYTE    sFileName[128];		/* 按文件回放文件名 */
    DWORD   dwGetStreamMode;	/*取流模式:1-主动，2-被动*/
    NET_DVR_MATRIX_PASSIVEMODE    struPassiveMode;
    BYTE	byRes2[32];
}NET_DVR_MATRIX_DEC_CHAN_INFO_V41,*LPNET_DVR_MATRIX_DEC_CHAN_INFO_V41;

typedef struct tagNet_DVR_IP_ADDRESS
{
	BYTE	byDevAddress[MAX_DOMAIN_NAME];	/*设备IP地址*/
	WORD	wDevPort;       //设备端口
	BYTE 	byres[134];
}NET_DVR_IP_ADDRESS, *LPNET_DVR_IP_ADDRESS;

typedef struct tagNet_DVR_DDNS_ADDRESS
{
	BYTE byDevAddress[MAX_DOMAIN_NAME];	/*DDNS域名*/
	BYTE byDevDdns[MAX_DOMAIN_NAME];	/*设备地址*/
	BYTE byDdnsType; //域名服务器类型，0-IPServer 1－Dyndns 2－PeanutHull(花生壳)，//3- NO-IP, 4- hiDDNS
	BYTE byRes1[3];
	WORD wDevPort;       //设备端口
	WORD wDdnsPort; //域名服务器端口
	BYTE byres[64];
}NET_DVR_DDNS_ADDRESS, *LPNET_DVR_DDNS_ADDRESS;

typedef struct tagNet_DVR_PLAY_BACK_BY_TIME
{
	NET_DVR_TIME StartTime;
	NET_DVR_TIME StopTime;
}NET_DVR_PLAY_BACK_BY_TIME, *LPNET_DVR_PLAY_BACK_BY_TIME;

typedef struct tagNet_DVR_MATRIX_DEC_REMOTE_PLAY_EX
{
	DWORD	dwSize;
	DWORD	dwDecChannel;  //解码通道号
	BYTE	byAddressType;  //设备地址类型，0-IP，1-DDNS
	BYTE	byChannelType;  //通道类型，0-普通通道，1-零通道，2-流ID
	BYTE	byres[2];
	BYTE	sUserName[NAME_LEN];		/* 用户名 */
	BYTE	sPassword[PASSWD_LEN];		/* 密码 */
	DWORD	dwChannel;			/* 设备通道号 */
	BYTE	byStreamId[STREAM_ID_LEN];  //流ID,此参数在通道类型为流ID时有效
	DWORD	dwPlayMode;   	/* 0－按文件 1－按时间*/
	union
	{
		BYTE byRes[200];
		NET_DVR_IP_ADDRESS struIpAddr;
		NET_DVR_DDNS_ADDRESS struDdnsAddr;
	}unionAddr;
	
	union
	{
		BYTE byRes[128];
		NET_DVR_PLAY_BACK_BY_TIME struPlayBackByTime; //按时间回放时文件信息
		char sFileName[128];	//按文件名回放时文件信息
	}unionPlayBackInfo;
}NET_DVR_MATRIX_DEC_REMOTE_PLAY_EX, *LPNET_DVR_MATRIX_DEC_REMOTE_PLAY_EX;

typedef struct tagNET_DVR_DISPLAY_EFFECT_CFG
{
	DWORD dwSize;
	NET_DVR_COLOR  struColor;      //显示相关参数/
	BYTE byRes[32];
}NET_DVR_DISPLAY_EFFECT_CFG,*LPNET_DVR_DISPLAY_EFFECT_CFG;


/*************************************63T 64T 65D V2.0.0 end******************************/

/********************************矩阵接入网关V20 begin****************************/

//获取干线状态
typedef struct tagNET_DVR_TRUNK_USE_STATE
{
	DWORD		dwSize;
	DWORD		dwTrunkID;	//干线ID
	WORD		wReserveUserID;	//预留的用户ID： 1~256 ，0表示释放预留
	BYTE		byStatus;  //1-空闲，2-占用，3-复用 */
	BYTE		byRes1;
	BYTE  		byUserId[256];  //数组下标表示用户ID号，数组元素的值表示是否使用干线。如：byUserID[0] 的值为1，表示用户ID为0的用户正在使用，byUserID[0] 的值为0表示用户ID为0的用户没有使用这条干线
	BYTE	   	byRes2[64];  
}NET_DVR_TRUNK_USE_STATE,  *LPNET_DVR_TRUNK_USE_STATE;


//PTZ控制参数
typedef struct tagNET_DVR_PTZ_CTRL_INFO
{
	DWORD	dwSize;
	DWORD	dwCtrlDelayTime;		//PTZ控制持续时间，指PTZ控制后在dwCtrlDelayTime时间内，其他同级别或低级别用户对其操作无效。单位：秒
	BYTE	byRes[64];
}NET_DVR_PTZ_CTRL_INFO, *LPNET_DVR_PTZ_CTRL_INFO;

//显示路径
#define		MAX_MATRIX_CASCADE		32
typedef struct tagNET_DVR_MATRIX_ROUTE_INFO
{
	DWORD		dwSize;
	DWORD	   	dwCamNo;
	DWORD   	dwMonNo;
	DWORD		dwSubWin;
	DWORD		dwUserId;
	DWORD   	dwTrunkId[MAX_MATRIX_CASCADE/*32*/];//trunkId成员对应级联级数从1到32，从CAM端开始，trunkId[0]表示第一级级联，trunkId[1]表示第二级级联, trunkId[i] = 0 表示无干线
	BYTE		byRes[64];      /* 预留 */
}NET_DVR_MATRIX_ROUTE_INFO, *LPNET_DVR_MATRIX_ROUTE_INFO;


//获取PTZ状态
typedef struct tagNET_DVR_PTZ_STATUS
{
	DWORD		dwSize;
	DWORD		dwUserID;	//1~256，0 表示无用户
	DWORD   	dwStatus;  	// PTZ控制状态0-停止、1-运行
	DWORD		dwRestTime;  //剩余时间
	BYTE		byRes[64];  
}NET_DVR_PTZ_STATUS, *LPNET_DVR_PTZ_STATUS;

typedef struct tagNET_DVR_SAFETYCABIN_WORK_MODE
{
	DWORD dwSize;
	BYTE  byWorkMode; //工作模式，0-无人门常开，1-无人门常锁
	BYTE  byRes[15];
}NET_DVR_SAFETYCABIN_WORK_MODE,*LPNET_DVR_SAFETYCABIN_WORK_MODE;

typedef struct tagNET_DVR_SAFETYCABIN_PERSON_SIGNAL_CFG
{
	DWORD dwSize;
	BYTE  bySensorType; //传感器类型，0-红外对射型，1-幕帘传感器
	BYTE  bySensitivity; //传感器敏感度，范围：0-100%
	BYTE  byDevUseTimeout; //防护舱使用超时时间，单位：分,范围：5-30，默认超时15min,超时后通过布防通道上传报警
	BYTE  byRes1;
	WORD  wCurtainDelayTime; //幕帘传感器探测延时时间，单位：秒，范围：0-10
	WORD  wCurtainResponseTime; //幕帘人状态变化控制器响应时间，单位：秒，范围：0-300	
	BYTE  byRes2[32];
}NET_DVR_SAFETYCABIN_PERSON_SIGNAL_CFG,*LPNET_DVR_SAFETYCABIN_PERSON_SIGNAL_CFG;	

typedef struct tagNET_DVR_ETHERNET_IPV6_COND
{
	DWORD		dwSize;
    BYTE  byMACAddr[MACADDR_LEN]; //网卡的物理地址
	BYTE  byRes[64];      //保留
}NET_DVR_ETHERNET_IPV6_COND,*LPNET_DVR_ETHERNET_IPV6_COND;

typedef struct tagNET_DVR_ETHERNET_IPV6_CFG
{
	DWORD		dwSize;
	BYTE  byState; //IPv6状态，0-路由分配，1-自动设置
	BYTE  byRes1[3]; 
    BYTE  byIPv6[MAX_IPV6_LEN]; //IPv6地址
	BYTE  byRes[64];      //保留
}NET_DVR_ETHERNET_IPV6_CFG,*LPNET_DVR_ETHERNET_IPV6_CFG;

/*********************************前端IPC 5.1.0 begin**************************************/
typedef struct  //8
{
	BYTE byHour;//0~24
	BYTE byMinute;//0~60
	BYTE bySecond;//0~60
	BYTE byRes;
	WORD wMilliSecond; //0~1000
	BYTE byRes1[2];
}NET_DVR_DAYTIME,*LPNET_DVR_DAYTIME;

typedef struct
{
	NET_DVR_DAYTIME  struStartTime; //开始时间
	NET_DVR_DAYTIME  struStopTime; //结束时间
}NET_DVR_SCHEDULE_DAYTIME, *LPNET_DVR_SCHEDULE_DAYTIME;

typedef struct
{
	BYTE byObjectSize;//占比参数(0~100)
	BYTE byMotionSensitive; /*移动侦测灵敏度, 0 - 5,越高越灵敏,0xff关闭*/
	BYTE byRes[6];
}NET_DVR_DNMODE, *LPNET_DVR_DNMODE;

typedef struct //60
{
	BYTE byAreaNo;//区域编号(IPC- 1~8)
	BYTE byRes[3];
	NET_VCA_RECT struRect;//单个区域的坐标信息(矩形) size = 16;
	NET_DVR_DNMODE  struDayNightDisable;//关闭模式
	NET_DVR_DNMODE  struDayModeParam;//白天模式
	NET_DVR_DNMODE  struNightModeParam;//夜晚模式
	BYTE byRes1[8];
}NET_DVR_MOTION_MULTI_AREAPARAM, *LPNET_DVR_MOTION_MULTI_AREAPARAM;

typedef struct
{
	BYTE byDayNightCtrl;//日夜控制 0~关闭,1~自动切换,2~定时切换(默认关闭)
	BYTE byRes[3];
	NET_DVR_SCHEDULE_DAYTIME struScheduleTime;//切换时间  16
	NET_DVR_MOTION_MULTI_AREAPARAM struMotionMultiAreaParam[MAX_MULTI_AREA_NUM];//最大支持24个区域
	BYTE byRes1[60];
}NET_DVR_MOTION_MULTI_AREA,*LPNET_DVR_MOTION_MULTI_AREA; //1328

typedef struct
{
	BYTE byMotionScope[64][96];		/*侦测区域,0-96位,表示64行,共有96*64个小宏块,目前有效的是22*18,为1表示是移动侦测区域,0-表示不是*/
	BYTE byMotionSensitive;			/*移动侦测灵敏度, 0 - 5,越高越灵敏,0xff关闭*/
	BYTE byRes[3];
}NET_DVR_MOTION_SINGLE_AREA, *LPNET_DVR_MOTION_SINGLE_AREA;

typedef struct 
{
	NET_DVR_MOTION_SINGLE_AREA  struMotionSingleArea; //普通模式下的单区域设
	NET_DVR_MOTION_MULTI_AREA struMotionMultiArea; //专家模式下的多区域设置	
}NET_DVR_MOTION_MODE_PARAM, *LPNET_DVR_MOTION_MODE_PARAM;

typedef struct 
{	
	NET_DVR_MOTION_MODE_PARAM  struMotionMode; //(5.1.0新增)
	BYTE byEnableHandleMotion;		/* 是否处理移动侦测 0－否 1－是*/ 
	BYTE byEnableDisplay;	/*启用移动侦测高亮显示，0-否，1-是*/
	BYTE byConfigurationMode; //0~普通,1~专家(5.1.0新增)
	BYTE byRes1; //保留字节
 	/* 异常处理方式 */
    DWORD   dwHandleType;        //异常处理,异常处理方式的"或"结果   
    /*0x00: 无响应*/
    /*0x01: 监视器上警告*/
    /*0x02: 声音警告*/
    /*0x04: 上传中心*/
    /*0x08: 触发报警输出*/
    /*0x10: 触发JPRG抓图并上传Email*/
    /*0x20: 无线声光报警器联动*/
    /*0x40: 联动电子地图(目前只有PCNVR支持)*/
    /*0x200: 抓图并上传FTP*/ 
    DWORD   dwMaxRelAlarmOutChanNum ; //触发的报警输出通道数（只读）最大支持数量
    DWORD   dwRelAlarmOut[MAX_ALARMOUT_V40]; //实际触发的报警输出号，按值表示,采用紧凑型排列，从下标0 - dwRelAlarmOut -1有效，如果中间遇到0xffffffff,则后续无效
	NET_DVR_SCHEDTIME struAlarmTime[MAX_DAYS][MAX_TIMESEGMENT_V30]; /*布防时间*/
 /*触发的录像通道*/
    DWORD     dwMaxRecordChanNum;   //设备支持的最大关联录像通道数-只读
    DWORD     dwRelRecordChan[MAX_CHANNUM_V40];	 /* 实际触发录像通道，按值表示,采用紧凑型排列，从下标0 - dwRelRecordChan -1有效，如果中间遇到0xffffffff,则后续无效*/  
	BYTE  byRes[128]; //保留字节
}NET_DVR_MOTION_V40,*LPNET_DVR_MOTION_V40;

typedef struct
{
	DWORD dwEnableHideAlarm;				/* 是否启动遮挡报警，0-否，1-低灵敏度，2-中灵敏度，3-高灵敏度*/
	WORD wHideAlarmAreaTopLeftX;			/* 遮挡区域的x坐标 */
	WORD wHideAlarmAreaTopLeftY;			/* 遮挡区域的y坐标 */
	WORD wHideAlarmAreaWidth;				/* 遮挡区域的宽 */
	WORD wHideAlarmAreaHeight;				/*遮挡区域的高*/ 
	/* 信号丢失触发报警输出 */	
    DWORD   dwHandleType;        //异常处理,异常处理方式的"或"结果   
    /*0x00: 无响应*/
    /*0x01: 监视器上警告*/
    /*0x02: 声音警告*/
    /*0x04: 上传中心*/
    /*0x08: 触发报警输出*/
    /*0x10: 触发JPRG抓图并上传Email*/
    /*0x20: 无线声光报警器联动*/
    /*0x40: 联动电子地图(目前只有PCNVR支持)*/
    /*0x200: 抓图并上传FTP*/ 
    DWORD   dwMaxRelAlarmOutChanNum ; //触发的报警输出通道数（只读）最大支持数量
	DWORD   dwRelAlarmOut[MAX_ALARMOUT_V40]; /*触发报警输出号，按值表示,采用紧凑型排列，从下标0 - dwRelAlarmOut -1有效，如果中间遇到0xffffffff,则后续无效*/  
	NET_DVR_SCHEDTIME struAlarmTime[MAX_DAYS][MAX_TIMESEGMENT_V30]; /*布防时间*/
	BYTE  byRes[64]; //保留
}NET_DVR_HIDEALARM_V40,*LPNET_DVR_HIDEALARM_V40; //遮挡报警

typedef struct
{
	DWORD dwEnableVILostAlarm;				/* 是否启动信号丢失报警 ,0-否,1-是*/
	 /* 信号丢失触发报警输出 */	
    DWORD   dwHandleType;        //异常处理,异常处理方式的"或"结果   
    /*0x00: 无响应*/
    /*0x01: 监视器上警告*/
    /*0x02: 声音警告*/
    /*0x04: 上传中心*/
    /*0x08: 触发报警输出*/
    /*0x10: 触发JPRG抓图并上传Email*/
    /*0x20: 无线声光报警器联动*/
    /*0x40: 联动电子地图(目前只有PCNVR支持)*/
    /*0x200: 抓图并上传FTP*/ 
    DWORD   dwMaxRelAlarmOutChanNum ; //触发的报警输出通道数（只读）最大支持数量
    DWORD   dwRelAlarmOut[MAX_ALARMOUT_V40]; /*触发报警输出号，按值表示,采用紧凑型排列，从下标0 - dwRelAlarmOut -1有效，如果中间遇到0xffffffff,则后续无效*/
	NET_DVR_SCHEDTIME struAlarmTime[MAX_DAYS][MAX_TIMESEGMENT_V30]; /*布防时间*/
	BYTE  byRes[64]; //保留
}NET_DVR_VILOST_V40,*LPNET_DVR_VILOST_V40;	//信号丢失报警

typedef struct
{
	NET_DVR_COLOR	  struColor[MAX_TIMESEGMENT_V30];/*图象参数(第一个有效，其他三个保留)*/
	NET_DVR_SCHEDTIME  struHandleTime[MAX_TIMESEGMENT_V30];/*处理时间段(保留)*/
}NET_DVR_VICOLOR, *LPNET_DVR_VICOLOR;

typedef struct
{
	DWORD  dwSize;
	BYTE  sChanName[NAME_LEN]; 
	DWORD  dwVideoFormat;	/* 只读 视频制式 1-NTSC 2-PAL  */
	NET_DVR_VICOLOR struViColor;//	图像参数按时间段设置
	//显示通道名
	DWORD  dwShowChanName; // 预览的图象上是否显示通道名称,0-不显示,1-显示
	WORD    wShowNameTopLeftX;				/* 通道名称显示位置的x坐标 */
	WORD    wShowNameTopLeftY;				/* 通道名称显示位置的y坐标 */
	//隐私遮挡
	DWORD  dwEnableHide;		/* 是否启动遮挡 ,0-否,1-是*/
	NET_DVR_SHELTER struShelter[MAX_SHELTERNUM];
	//OSD
	DWORD  dwShowOsd;// 预览的图象上是否显示OSD,0-不显示,1-显示
	WORD   wOSDTopLeftX;				/* OSD的x坐标 */
	WORD   wOSDTopLeftY;				/* OSD的y坐标 */
	BYTE    byOSDType;					/* OSD类型(主要是年月日格式) */
	/* 0: XXXX-XX-XX 年月日 */
	/* 1: XX-XX-XXXX 月日年 */
	/* 2: XXXX年XX月XX日 */
	/* 3: XX月XX日XXXX年 */
	/* 4: XX-XX-XXXX 日月年*/
	/* 5: XX日XX月XXXX年 */
	/*6: xx/xx/xxxx(月/日/年) */
	/*7: xxxx/xx/xx(年/月/日) */
	/*8: xx/xx/xxxx(日/月/年)*/
	BYTE    byDispWeek;				/* 是否显示星期 */
	BYTE    byOSDAttrib;				/* OSD属性:透明，闪烁 */
	/* 0: 不显示OSD */
	/* 1: 透明，闪烁 */
	/* 2: 透明，不闪烁 */
	/* 3: 不透明，闪烁 */
	/* 4: 不透明，不闪烁 */	
	BYTE    byHourOSDType;				/* OSD小时制:0-24小时制,1-12小时制 */
	BYTE    byFontSize;      //16*16(中)/8*16(英)，1-32*32(中)/16*32(英)，2-64*64(中)/32*64(英) FOR 91系列HD-SDI高清DVR
	BYTE    byRes1[3]; //保留
	NET_DVR_VILOST_V40 struVILost;  //视频信号丢失报警（支持组）
	NET_DVR_VILOST_V40 struAULost;  /*音频信号丢失报警（支持组）*/
	NET_DVR_MOTION_V40 struMotion;  //移动侦测报警（支持组）
	NET_DVR_HIDEALARM_V40 struHideAlarm;  //遮挡报警（支持组）
	BYTE    byRes[128];
}NET_DVR_PICCFG_V40,*LPNET_DVR_PICCFG_V40;

typedef struct  //
{
	DWORD				   dwSize; 
	BYTE   byWorkType;// 0-自适应, 1-定时模式
	BYTE   byRes[3];
	//定时模式参数
	NET_DVR_SCHEDULE_DAYTIME  struDayNightScheduleTime;//日夜定时切换模式(白天时间)
	NET_DVR_CAMERAPARAMCFG_EX   struSelfAdaptiveParam; //自适应参数
	NET_DVR_CAMERAPARAMCFG_EX   struDayIspAdvanceParam;//白天参数
	NET_DVR_CAMERAPARAMCFG_EX   struNightIspAdvanceParam;//夜晚参数
    BYTE   byRes1[512];
}NET_DVR_ISP_CAMERAPARAMCFG,*LPNET_DVR_ISP_CAMERAPARAMCFG;

typedef struct
{
	DWORD       dwSize; 
	BYTE         byIrLampServer;//红外灯设置 0～禁用，1～启用
    BYTE         bytelnetServer;//telnet设置 0～禁用，1～启用
	BYTE         byABFServer;//ABF设置 0～启用，1～禁用
	BYTE         byRes[253];
}NET_DVR_DEVSERVER_CFG,*LPNET_DVR_DEVSERVER_CFG;

typedef struct tagNET_DVR_GBT28181_ACCESS_CFG
{
	DWORD				   dwSize; 
	BYTE				   byEnable;//28181协议使能 0-关闭 1-开启
	BYTE                  byRes;
	WORD                 wLocalSipPort;//1024-65535(IPC设备端)
	char                   szServerID[MAX_SERVERID_LEN];//服务器ID：64字节字符串，仅限数字
	char           szServerDomain[MAX_SIPSERVER_ADDRESS_LEN] ;// 服务器域
	char           szSipServerAddress[MAX_SIPSERVER_ADDRESS_LEN] ;// SIP服务器地址支持域名和IP地址
	WORD         wServerSipPort;//服务器SIP端口：1024-65535
	BYTE         byRes3[2];
	char           szSipUserName[MAX_SERVERNAME_LEN];//SIP用户名称：64字节字符串(第三方SIP终端请求IPC服务时使用)
	char           szSipAuthenticateID[MAX_AUTHENTICATEID_LEN];//SIP用户认证ID：64字节字符串
	char          szSipAuthenticatePasswd[MAX_AUTHENTICATEPASSWD_LEN];//SIP用户认证密码：32字节字符串(IPC设备注册到SIP服务器时使用)
	DWORD      dwRegisterValid;//注册有效期：单位秒，默认3600；
	BYTE         byHeartbeatInterval;//心跳间隔：单位秒，默认10秒；
	BYTE         byMaxHeartbeatTimeOut;//最大心跳超时次数：默认3次；
	BYTE         byStreamType;// 取流类型0～主码流，1～子码流，2～3码流
	BYTE         byRes4[253];
}NET_DVR_GBT28181_ACCESS_CFG,*LPNET_DVR_GBT28181_ACCESS_CFG;

//GBT28181协议的设备编码通道配置
typedef struct tagNET_DVR_GBT28181_CHANINFO_CFG
{
	DWORD				   dwSize;
	char    szVideoChannelNumID[MAX_COMPRESSIONID_LEN];//设备视频通道编码ID：64字节字符串，仅限数字
	BYTE             byRes[256];
}NET_DVR_GBT28181_CHANINFO_CFG,*LPNET_DVR_GBT28181_CHANINFO_CFG;

//GBT28181协议的报警输入通道配置 条件结构
typedef struct tagNET_DVR_ALARMIN_INFO
{
	NET_DVR_STREAM_INFO struStreamInfo;
	DWORD  dwAlarmInChannel;//报警输入通道号
	BYTE  byRes[32]; //保留
}NET_DVR_ALARMIN_INFO,*LPNET_DVR_ALARMIN_INFO;

//GBT28181协议的报警输入通道配置 配置结构
typedef struct tagNET_DVR_GBT28181_ALARMINCFG
{
	DWORD				   dwSize;
	char    szAlarmInNumID[MAX_COMPRESSIONID_LEN];//设备报警输入编码ID（每一路报警输入不同）：20字节字符串，仅限数字
	BYTE             byRes[256];
}NET_DVR_GBT28181_ALARMINCFG,*LPNET_DVR_GBT28181_ALARMINCFG;
/*********************************前端IPC 5.1.0 end**************************************/

typedef struct tagNET_DVR_CAMERA_SETUPCFG
{
	DWORD dwSize;
	WORD  wSetupHeight; //架设高度[0,20]，单位：米
	BYTE  byLensType; //镜头焦距类型，0-未知,1-8mm,2-12mm,3-16mm,4-25mm,5-35mm,6-50mm,7-4mm,8-6mm
	BYTE  bySetupHeightUnit;// 架设高度单位0～M,1~CM
	DWORD dwSceneDis; //图像下边缘位置与相机之间的水平距离，单位：厘米
	float fPitchAngle;//相机俯仰角度[-180°, 180°],
	float fInclineAngle;//相机倾斜角度[-180°,180°]
	float fRotateAngle;//相机旋转角度[-180°,180°]
	WORD  wVideoDetCoefficient; //视频测试系数[0,300](3.6新增)
	BYTE  byErectMethod; //架设方式0-正装，1-侧装(3.6新增)
    BYTE  byRes[41]; 
}NET_DVR_CAMERA_SETUPCFG, *LPNET_DVR_CAMERA_SETUPCFG;

//起止日期段参数结构体
typedef struct tagNET_DVR_SCHEDDATE
{   
	BYTE   byStartMonth;   //起始（月）
	BYTE   byStartDay;     //起始（日）
	BYTE   byStopMonth;    //结束（月）
	BYTE   byStopDay;      //结束（日）
}NET_DVR_SCHEDDATE,*LPNET_DVR_SCHEDDATE;

//时控输出参数
typedef struct tagNET_DVR_OUTPUT_SCHEDULE
{   
	NET_DVR_SCHEDTIME struTime;  //时间段
	BYTE byState;                //0–关闭, 1–开启
	BYTE byRes[11];              //保留
} NET_DVR_OUTPUT_SCHEDULE ,*LPNET_DVR_OUTPUT_SCHEDULE;

//单条时控输出规则参数
typedef struct tagNET_DVR_ONE_OUTPUT_SCHEDULE_RULE
{   
	BYTE                     byEnable;    //是否启用规则,0-否,1-是
	BYTE                     byRes1[3];   //保留
	NET_DVR_SCHEDDATE        struDate;    //日期区段
	NET_DVR_OUTPUT_SCHEDULE  struOutputSchedule[MAX_TIMESEGMENT_V30];  //最多支持8个时间段的时控输出
	BYTE                     byRes2[16];  //保留
}NET_DVR_ONE_OUTPUT_SCHEDULE_RULE,*LPNET_DVR_ONE_OUTPUT_SCHEDULE_RULE;

//时控输出规则参数
typedef struct tagNET_DVR_OUTPUT_SCHEDULE_RULECFG
{   
	DWORD  dwSize; //结构体大小
	NET_DVR_ONE_OUTPUT_SCHEDULE_RULE struOutputRule[MAX_RULE_NUM]; //最多支持8个日期区段的规则配置
	BYTE   byRes[64];  //保留
}NET_DVR_OUTPUT_SCHEDULE_RULECFG,*LPNET_DVR_OUTPUT_SCHEDULE_RULECFG;

//交通统计报警参数
typedef struct tagNET_DVR_TPS_ALARMCFG
{
    DWORD dwSize;
	BYTE byEnable; //是否启用交通统计报警上传
	BYTE byRes1[3];	//
	DWORD dwInterval;//统计间隔时间（单位：分钟）
    BYTE  byRes[248];
}NET_DVR_TPS_ALARMCFG, *LPNET_DVR_TPS_ALARMCFG;

typedef struct tagNET_DVR_DOWNLOAD_ALARM_RECORD_COND
{
	DWORD dwSize;
	WORD  wAlarmRecordID;	//报警录像ID(用于查询录像，仅当byResultType为2时有效)
	BYTE  byRes[130];
}NET_DVR_DOWNLOAD_ALARM_RECORD_COND, *LPNET_DVR_DOWNLOAD_ALARM_RECORD_COND;

typedef struct tagNET_DVR_CABINET_AlARM_PARAMCFG
{
	char  sCabinetName[NAME_LEN];
	BYTE  byAssociateIO;//1-4，0xff， 其中1-4表示具体的IO通道号，0xff表示不启用
	BYTE  byCabinetState;//0~低电平,1~高电平
	BYTE  byAlarmIntervalTime;//取值范围1-60，单位：秒
	BYTE  byRes1[25]; 
}NET_DVR_CABINET_AlARM_PARAMCFG, *LPNET_DVR_CABINET_AlARM_PARAMCFG;

typedef struct tagNET_DVR_CABINET_CFG
{
	DWORD dwSize;
	BYTE  byEnable;//0~不启用，1～启用
    BYTE  byRes[3];
	NET_DVR_CABINET_AlARM_PARAMCFG struCabinetCfg[MAX_CABINET_COUNT];
	BYTE  byRes1[84];
} NET_DVR_CABINET_CFG, *LPNET_DVR_CABINET_CFG;

typedef  struct  tagNET_ITS_GATE_LANE_CFG
{ 
	BYTE      byGateSiteID[MAX_ID_LEN];    //出入口编号
	BYTE	  byGateInfo[MAX_ID_LEN];  	//出入口信息描述
	BYTE      byLaneName[NAME_LEN];     //车道名称
	BYTE      byValid;              //是否启用 0 表示未启用，1表示启用
	BYTE	  byCamLaneId; 	//对应相机车道号1～16（相机配置的车道号，可以跳跃，可以相同）
	WORD      wLaneid;            //车道号1～32（索引车道号，可以跳跃 逻辑车道）
	BYTE	  byRelativeIoNum;         //逻辑车道号关联的输出口编号  	
	BYTE      byDirection;          //方向编号;  0 -其他 1 入场  2 出场 3 双向
	BYTE	  byLprMode; //牌识放行配置0 全部进1 除黑名单进2 白名单进
	BYTE 	  byCardMode; //卡片放行配置0 全部进1 除黑名单进2 白名单进 
	BYTE 	  byGateLaneMode;//出入口放行配置模式 0-全部进 1-只有牌识匹配放行2 只有刷卡匹配放//行 3-牌识或卡片有一个匹配则放行 4-牌识且卡片同时匹配则放行 5-全不进
	//2013-11-19 新增参数
	BYTE      byCharge;//是否收费 0-不收费，1-收费
	BYTE      byChargeMode;//收费类型 0-车牌收费，1-卡号收费
	BYTE      byRes1;
	BYTE      byLedRelativeIndex[MAX_INDEX_LED];//LED 索引 (1~255) 紧凑排列，0表示无效，不解析后面的数据
	BYTE      byGateRelativeIndex;//出入口控制机相对索引
	BYTE      byFarRrRelativeIndex;// 远距离读卡器相对索引
	BYTE      byRes[82]; //预留
}NET_ITS_GATE_LANE_CFG, *LPNET_ITS_GATE_LANE_CFG;

typedef	struct  tagNET_ITS_IPC_CHAN_LANE_CFG
{
	DWORD     dwSize; 
	BYTE	  byIpcType;  //0-无，1-车牌抓拍，2-人脸抓拍，3-监控相机
	BYTE	  byRes[135];
	NET_ITS_GATE_LANE_CFG  struGateLane[4]; //车道配置结构体
}NET_ITS_IPC_CHAN_LANE_CFG, *LPNET_ITS_IPC_CHAN_LANE_CFG;

//设备远程控制
typedef	struct	tagNET_ITS_REMOTE_COMMAND
{
	WORD            wLaneid; //车道号1～32（索引车道号，可以跳跃）
	BYTE	 		byCamLaneId;	//对应相机车道号1～16（相机配置的车道号，可以跳跃，可以相同）
	BYTE            byRes;     //预留
	DWORD           dwCode;       //命令码 0x0 开闸 0x1 关闸，其它待扩展
	BYTE			byRes1[128];
}NET_ITS_REMOTE_COMMAND,*LPNET_ITS_REMOTE_COMMAND;

typedef  struct	tagNET_ITS_REMOTE_CONTROL_
{
	DWORD          dwSize;
	NET_ITS_REMOTE_COMMAND	struRemoteCommand;   //远程命令结构
}NET_ITS_REMOTE_CONTROL,*LPNET_ITS_REMOTE_CONTROL;

//长连接获取通道状态
typedef struct tagNET_ITS_ECT_CHANNELSTATE
{
	DWORD dwSize;
	BYTE  byRecordStatic; //通道是否在录像,0-不录像,1-录像
	BYTE  bySignalStatic; //连接的信号状态,0-正常,1-信号丢失
	BYTE  byHardwareStatic;//通道硬件状态,0-正常,1-异常,例如DSP死掉
	BYTE  byChannelArmState; //接入IPC的布防状态
	DWORD dwChannel; //通道号
	DWORD dwBitRate;//实际码率
	DWORD dwLinkNum;//客户端连接的个数
	NET_DVR_IPADDR struClientIP[MAX_LINK];//客户端的IP地址
    DWORD dwIPLinkNum;//如果该通道为IP接入，那么表示IP接入当前的连接数
	BYTE  byExceedMaxLink;	// 是否超出了128路连接数 0 - 未超出, 1-超出     
	BYTE  byRes[139];       // 保留字节    
}NET_ITS_ECT_CHANNELSTATE, *LPNET_ITS_ECT_CHANNELSTATE;

//外接灯
typedef struct tagNET_DVR_PARK_EXTERNAL_SUBINFO
{
	BYTE   byEnable; //0 ～ 不开启 1 ～ 开启
	BYTE   byFlicker;//0 ～ 不闪烁 1 ～ 闪烁
	BYTE   byIOState;//0 ～ 低电平 1 ～ 高电平 (外置灯起效)
	BYTE   byRes[5];
}NET_DVR_PARK_EXTERNAL_SUBINFO, *LPNET_DVR_PARK_EXTERNAL_SUBINFO;

typedef struct tagNET_DVR_PARK_INLAY_SUBINFO
{
	BYTE   byEnable; //0～不开启 1 ～开启
	BYTE   byFlicker;//0～不闪烁 1 ～闪烁
	BYTE   byLampColor;//0-灭 1-红 2-绿 3-黄 4-蓝 5-品红 6-青 7-白色 (内置灯起效) 
	BYTE   byRes[21];
}NET_DVR_PARK_INLAY_SUBINFO, *LPNET_DVR_PARK_INLAY_SUBINFO;

typedef struct tagNET_DVR_PARKINFO
{
	NET_DVR_PARK_EXTERNAL_SUBINFO   struNormalParkIOState;//有车io电平状态
	NET_DVR_PARK_EXTERNAL_SUBINFO   struNormalNoParkIOState;//无车io电平状态
	NET_DVR_PARK_EXTERNAL_SUBINFO   struSpecialParkIOState;//特殊车位有车io电平状态
	NET_DVR_PARK_EXTERNAL_SUBINFO   struSpecialNoParkIOState;//特殊车位无车io电平状态
	BYTE   byRes[32];
}NET_DVR_PARKINFO, *LPNET_DVR_PARKINFO;

typedef struct tagNET_DVR_EXTERNAL_LAMP_CTRL_MODE
{
	NET_DVR_PARKINFO  struParkInfo[MAX_PARKING_NUM];/*外接灯的情况下车位信息，一个通道最大4个车位 (从左到右车位 数组0～3)*/
	BYTE   byRes[32];
}NET_DVR_EXTERNAL_LAMP_CTRL_MODE, *LPNET_DVR_EXTERNAL_LAMP_CTRL_MODE; 

typedef struct tagNET_DVR_INLAY_LAMP_CTRL_MODE
{
	NET_DVR_PARK_INLAY_SUBINFO  struLampStateCtrl[MAX_PARKING_STATUS];
	BYTE   byRes[96];
}NET_DVR_INLAY_LAMP_CTRL_MODE, *LPNET_DVR_INLAY_LAMP_CTRL_MODE; 

typedef union tagNET_DVR_LAMP_CTRL_MODE_UNION
{
	BYTE uLen[288];
	NET_DVR_INLAY_LAMP_CTRL_MODE struInlayLampCtrlMode;/*内置灯控制模式结构*/ 
	NET_DVR_EXTERNAL_LAMP_CTRL_MODE struExternalLampCtrlMode;/*外接灯控制模式结构*/ 		
}NET_DVR_LAMP_CTRL_MODE_UNION, *LPNET_DVR_LAMP_CTRL_MODE_UNION;/*灯控制模式联合体*/ 

typedef struct tagNET_DVR_LAMP_CTRL_INFO
{
	DWORD     dwSize;
	BYTE      byLampCtrlMode;/*控灯模式：1代表内置灯，2代表外接灯*/
	BYTE      byCtrlChannelIndex;/*交替控制通道号(33~48)*/
	BYTE      byRes[2];
	NET_DVR_LAMP_CTRL_MODE_UNION  uLampCtrlMode;/*灯控制模式联合体*/
	BYTE      byRes2[32];
}NET_DVR_LAMP_CTRL_INFO, *LPNET_DVR_LAMP_CTRL_INFO;

//车位属性配置（默认都是normal）
typedef struct tagNET_DVR_PARKSPACE_INFO
{
	BYTE      byParkSpaceAttribute; //0~普通车位 1～特殊车位
	BYTE      byRes[23];
}NET_DVR_PARKSPACE_INFO, *LPNET_DVR_PARKSPACE_INFO;

typedef struct tagNET_DVR_PARKSPACE_ATTRIBUTE
{
	DWORD     dwSize;
	NET_DVR_PARKSPACE_INFO  struParkSpaceInfo[MAX_PARKING_NUM];//一个通道最大4个车位 (从左到右车位 数组0～3)
	BYTE      byRes[64];
}NET_DVR_PARKSPACE_ATTRIBUTE, *LPNET_DVR_PARKSPACE_ATTRIBUTE;

//指示灯外控
typedef struct tagNET_DVR_LAMP_STATE
{
	BYTE      byFlicker;//0~不闪烁 1 ～闪烁
	BYTE      byRes1[3];
	DWORD     dwIONo;//1~IO1;2~IO2;4~IO3;
	BYTE      byRes2[8];
}NET_DVR_LAMP_STATE, *LPNET_DVR_LAMP_STATE;

typedef struct tagNET_DVR_LAMP_EXTERNAL_CFG
{
	DWORD     dwSize;
	BYTE      byEnable; //外控使能 0～不启用 1～启用
	BYTE      byRes1[3];
	NET_DVR_LAMP_STATE     struLampStateCtrl;//指示灯外控
	BYTE      byRes2[32];
}NET_DVR_LAMP_EXTERNAL_CFG, *LPNET_DVR_LAMP_EXTERNAL_CFG;

//车位强制抓图 一个通道最多四车位
typedef struct tagNET_DVR_COMPEL_CAPTURE
{
	DWORD      dwSize;
	BYTE	   byParkIndex;/*车位序号从左到右 1,2,3,4*/
	BYTE       byRes[63];
}NET_DVR_COMPEL_CAPTURE, *LPNET_DVR_COMPEL_CAPTURE;

//外控报警结构
typedef struct tagNET_DVR_EXTERNAL_CONTROL_ALARM
{
	DWORD     dwSize;
	DWORD	  dwChannelNo;
	NET_DVR_LAMP_STATE      struLampStateCtrl;//指示灯外控状态
	NET_DVR_TIME      struExternalBeginTime;/*外控开始时间*/ 
	BYTE	  byRes1[64];
}NET_DVR_EXTERNAL_CONTROL_ALARM, *LPNET_DVR_EXTERNAL_CONTROL_ALARM;

typedef struct tagNET_DVR_VOLTAGE
{
	int iPhaseAVol;			//A相电压
	int iPhaseBVol;			//B相电压
	int iPhaseCVol;			//C相电压
	int iAveragePhaseVol;	//相电压平均值
}NET_DVR_VOLTAGE, *LPNET_DVR_VOLTAGE;

typedef struct _tagNET_DVR_LINE_VOLTAGE
{
	int iLineVolAB;			//AB线电压
	int iLineVolBC;			//BC线电压
	int iLineVolCA;			//CA线电压
	int iAverageLineVol;	//线电压平均值
} NET_DVR_LINE_VOLTAGE,*LPNET_DVR_LINE_VOLTAGE;


//电流
typedef struct tagNET_DVR_CURRENT
{
	int iPhaseACurrent;			//A相电流
	int iPhaseBCurrent;			//B相电流
	int iPhaseCCurrent;			//C相电流
	BYTE byRes[4];
}NET_DVR_CURRENT, *LPNET_DVR_CURRENT;

//功率
typedef struct tagNET_DVR_POWER
{
	int iPhaseAPower;			//A相功率
	int iPhaseBPower;			//B相功率
	int iPhaseCPower;			//C相功率
	int iSysTotalPower;			//系统总功率
}NET_DVR_POWER, *LPNET_DVR_POWER;

//功率因素
typedef struct tagNET_DVR_POWER_FACTOR
{
	int iPhaseAPowerFactor;	//A相功率因素
	int iPhaseBPowerFactor;		//B相功率因素
	int iPhaseCPowerFactor;		//C相功率因素
	int iTotalPowerFactor;		//总功率因素
}NET_DVR_POWER_FACTOR, *LPNET_DVR_POWER_FACTOR;

//频率
typedef struct tagNET_DVR_FREQUENCY
{
	int iPhaseAFrequency;		//A相频率
	int iPhaseBFrequency;		//B相频率
	int iPhaseCFrequency;		//C相频率
	BYTE byRes[4];
}NET_DVR_FREQUENCY, *LPNET_DVR_FREQUENCY;

//负载率
typedef struct tagNET_DVR_LOAD_FACTOR
{
	int iPhaseALoadFactor;		//A相负载率
	int iPhaseBLoadFactor;		//B相负载率
	int iPhaseCLoadFactor;		//C相负载率
	BYTE	byRes[4];
} NET_DVR_LOAD_FACTOR, *LPNET_DVR_LOAD_FACTOR;

//UPS状态
typedef struct tagNET_DVR_ALARMHOST_UPS_STATE
{
	NET_DVR_VOLTAGE		struInputVoltage;	//输入电压
	NET_DVR_VOLTAGE		struBypassVoltage;	//旁路电压
	NET_DVR_VOLTAGE		struOutputVoltage;	//输出电压
	int iRectifierVol;			//整流器电压
	int iInverterVol;			//逆变器电压

	NET_DVR_CURRENT	struInputCurrent;	//输入电流
	NET_DVR_CURRENT	struBypassCurrent;	//旁路电流
	NET_DVR_CURRENT	struOutputCurrent;	//输出电流
	int iInverterCurrent;		//逆变器电流

	NET_DVR_FREQUENCY	struInputFrequency;	//输入频率
	NET_DVR_FREQUENCY	struBypassFrequency;	//旁路频率
	NET_DVR_FREQUENCY	struOutputFrequency;	//输出频率
	int iInverterFre;			//逆变器频率

	NET_DVR_POWER 		struInputPower;	//输入功率
	NET_DVR_POWER		struBypassPower;	//旁路功率
	NET_DVR_POWER		struOutputPower;	//输出功率
	NET_DVR_POWER		struComplexPower;	//复功率

	int iNormalPower;			//标称功率
	int iPowerFacter;			//功率因素

	NET_DVR_LOAD_FACTOR	struBatteryLoadFactor;	//电池负载率
	int iBatteryEstimated;		//电池备份时间(min)
	int iBatteryTemperature;		//电池温度
int iBatteryVoltage;			//电池电压


	BYTE	byRectifierState;		//整流器运行状态/*1正常 2异常*/
	BYTE	byInverterState;		//逆变器运行状态/*1正常 2异常*/
	BYTE	byChargeState;		//充电器运行状态/*1正常 2异常*/
	BYTE	byBatteryState;		//电池运行状态/*1正常 2异常*/
	BYTE	byAutoBypassState;	//自动旁路状态/*1正常 2异常*/
	BYTE	byRes2[247];
} NET_DVR_ALARMHOST_UPS_STATE, *LPNET_DVR_ALARMHOST_UPS_STATE; 

//开关电源状态
typedef struct tagNET_DVR_ALARMHOST_SWITCH_POWER_STATE
{
	NET_DVR_VOLTAGE		struACVoltage;	//交流电压
	int 	iDCConvertVoltage;	//DC转换器电压
	NET_DVR_CURRENT		struACCurrent;	//交流电流
	int 	iTotalCurrent;			//负载总电流
	int 	iBattery1Temperature;	//电池1温度
	int 	iBattery2Temperature;	//电池2温度
	int 	iBattery1Current;		//电池1电流
	int 	iBattery2Current;		//电池2电流
	int 	iBattery3Current;		//电池3电流
	int 	iBattery4Current;		//电池4电流
	int 	iBatteryTestVoltage;	//电池测试电压
	int 	iRectifierOutputVoltage;	//整流模块输出电压
	int 	iRectifierOutputCurrent;	//整流模块输出电流
	int 	iDCOutputVoltage;		//直流输出电压
	BYTE	byRes[432];
} NET_DVR_ALARMHOST_SWITCH_POWER_SUPPLY_STATE, 
*LPNET_DVR_ALARMHOST_SWITCH_POWER_SUPPLY_STATE;

//气体探测器状态
typedef struct tagNET_DVR_ALARMHOST_GAS_DETECTOR_STATE
{
	int		iSF6;			//SF6，单位ppm
	int  	iFlow;           //流量，ml/min       
	int		iTemperature;		//温度，单位摄氏度
	int		iO2;		    //氧气，单位%
	int		iHumidity;		//湿度，单位%
	BYTE	byRes[492];
} NET_DVR_ALARMHOST_GAS_DETECTOR_STATE,
*LPNET_DVR_ALARMHOST_GAS_DETECTOR_STATE;

//温湿度传感器状态
typedef struct tagNET_DVR_ALARMHOST_TEMP_HUMI_SENSOR_STATE
{
	int		iTemperature;	//温度，单位摄氏度
	int		iHumidity;		//湿度，单位%
	BYTE	byRes[504];
} NET_DVR_ALARMHOST_TEMP_HUMI_SENSOR_STATE, *LPNET_DVR_ALARMHOST_TEMP_HUMI_SENSOR_STATE;

//空调状态
typedef struct tagNET_DVR_ALARMHOST_AIRCONDITION_STATE
{
	int		iTemperature;	//温度，单位摄氏度
	int		iHumidity;		//湿度，单位%
	BYTE   byRunState;		//运行状态 1-正常，2-停机
	BYTE	byRes[503];
} NET_DVR_ALARMHOST_AIRCONDITION_STATE, *LPNET_DVR_ALARMHOST_AIRCONDITION_STATE;


//电量表状态
typedef struct tagNET_DVR_ALARMHOST_ELECTRICITY_STATE
{
	int		iDCVoltage;		//直流电压
	int		iDCCurrent;		//直流电流
	NET_DVR_VOLTAGE		struPhaseVoltage;	//相电压
	NET_DVR_LINE_VOLTAGE struLineVoltage;	//线电压
	NET_DVR_CURRENT	struCurrent[4];		//电流，struCurrent[0]表示第1路, 以此类推 
	int iAverageCurrent;	//平均电流
	int iNeutralCurrent;		//中线电流
	NET_DVR_POWER	struActivePower[4];	//有功功率 struActivePower[0]表示第一路有功功率，以此类推
	NET_DVR_POWER	struReactivePower[4];	//无功功率 struReactivePower[0]表示第一路无功功率，以此类推
	NET_DVR_POWER	struApparentPower[4];	//视在功率 struApprentPower[0]表示第一路视在功率，以此类推
	NET_DVR_POWER_FACTOR	struPowerFactor[4];	//功率因素，struPowerFactor[0]表示第一路功率因素，以此类推
	NET_DVR_FREQUENCY		struFrequency;			//频率
	BYTE byRes[128];
}NET_DVR_ALARMHOST_ELECTRICITY_STATE, *LPNET_DVR_ALARMHOST_ELECTRICITY_STATE;

//变电器温显表状态
typedef struct  tagNET_DVR_ALARMHOST_TRANSFORMER_TEMP_STATE
{
	int		iPhaseATemperature;		//A相温度
	int		iPhaseBTemperature;		//B相温度
	int		iPhaseCTemperature;		//C相温度
	int		iPhaseDTemperature;		//D相温度
	BYTE 	byRes[496];
}NET_DVR_ALARMHOST_TRANSFORMER_TEMP_STATE, *LPNET_DVR_ALARMHOST_TRANSFORMER_TEMP_STATE;


typedef union tagNET_DVR_EXTERNAL_DEVICE_STATE_UNION
{
	NET_DVR_ALARMHOST_UPS_STATE struUpsState;		//UPS状态
	NET_DVR_ALARMHOST_SWITCH_POWER_SUPPLY_STATE struSwitchPowerState;//开关电源状态
	NET_DVR_ALARMHOST_GAS_DETECTOR_STATE struGasDetectorState;//气体检测系统状态
	NET_DVR_ALARMHOST_TEMP_HUMI_SENSOR_STATE struTempHumiSensorState;//温湿度传感器状态
	NET_DVR_ALARMHOST_AIRCONDITION_STATE struAirConditionState;//空调状态
	NET_DVR_ALARMHOST_ELECTRICITY_STATE struElectricityState;//电量表状态
	NET_DVR_ALARMHOST_TRANSFORMER_TEMP_STATE struTransformerTempState;	//变电器状态
	BYTE	byRes[512];
} NET_DVR_EXTERNAL_DEVICE_STATE_UNION, *LPNET_DVR_EXTERNAL_DEVICE_STATE_UNION;

typedef struct tagNET_DVR_ALARMHOST_EXTERNAL_DEVICE_STATE
{
	DWORD dwSize;
	BYTE	byDevType;	//1-UPS，2-开关电源，3-气体检测系统，4-温湿度传感器，5-空调，6-电量表，7-变电器状态
	BYTE	byRes1[3];
	NET_DVR_EXTERNAL_DEVICE_STATE_UNION struDevState;
	BYTE	byRes2[32];
} NET_DVR_ALARMHOST_EXTERNAL_DEVICE_STATE, *LPNET_DVR_ALARMHOST_EXTERNAL_DEVICE_STATE;


//UPS报警限值
typedef struct tagNET_DVR_ALARMHOST_UPS_LIMIT_VALUE
{
	int iInputVolHigh;		//越限输入电压值(高值)
	int iInputVolLow;		//越限输入电压值(低值)
	int iInputFreHigh;		//越限输入频率值(高值)
	int iInputFreLow;		//越限输入频率值(低值)
	int iOutputVolHigh;	//越界输出电压值(高值)
	int iOutputVolLow;		//越界输出电压值(低值)
	int iBatteryVoltageLow;	//电池低电压限值
	int iBatterySurplus;		//电池后备时间低 限值
	int iBatteryTemperatureHigh;//电池温度高限值
	BYTE	byRes[64];			//保留
}NET_DVR_ALARMHOST_UPS_LIMIT_VALUE, *LPNET_DVR_ALARMHOST_UPS_LIMIT_VALUE;

//温湿度传感器限值
typedef struct tagNET_DVR_ALARMHOST_TEMP_HUMIDITY_SENSOR_LIMIT_VALUE
{
	int iTemperatureHighLimit;	//温度高限值，单位摄氏度
	int iTemperatureLowLimit;	//温度低限值，单位摄氏度
	int iHumidityHighLimit;		//湿度高限值，单位%
	int iHumidityLowLimit;		//湿度低限值，单位%
	BYTE	byRes[84];		
} NET_DVR_ALARMHOST_TEMP_HUMIDITY_SENSOR_LIMIT_VALUE, *LPNET_DVR_ALARMHOST_TEMP_HUMIDITY_SENSOR_LIMIT_VALUE;

typedef union tagNET_DVR_EXTERNAL_DEVICE_LIMIT_VALUE_UNION
{
	NET_DVR_ALARMHOST_UPS_LIMIT_VALUE struUpsLimitValue;
	NET_DVR_ALARMHOST_TEMP_HUMIDITY_SENSOR_LIMIT_VALUE struTempHumidityLimitValue;
}NET_DVR_EXTERNAL_DEVICE_LIMIT_VALUE_UNION,*LPNET_DVR_EXTERNAL_DEVICE_LIMIT_VALUE_UNION;

typedef struct tagNET_DVR_ALARMHOST_EXTERNAL_DEVICE_LIMIT_VALUE
{
	DWORD dwSize;
	BYTE	byDevType;	//1-UPS，2-温湿度传感器
	BYTE	byRes1[3];
	NET_DVR_EXTERNAL_DEVICE_LIMIT_VALUE_UNION struAlarmValue;
	BYTE	byRes2[32];
}NET_DVR_ALARMHOST_EXTERNAL_DEVICE_LIMIT_VALUE, *LPNET_DVR_ALARMHOST_EXTERNAL_DEVICE_LIMIT_VALUE;

#define	ALARMHOST_ALARMOUT_NUM	64  //触发器个数
typedef struct  tagNET_DVR_ALARMHOST_SENSOR_JOINT_CFG
{
	DWORD 		dwSize;
	BYTE		bySensorJointAlarmOut[MAX_ALARMHOST_ALARMOUT_NUM/*512*/];//模拟量联动触发器，0-不联动，1-联动
	BYTE		bySensorJointSiren[ALARMHOST_MAX_SIREN_NUM/*8*/];//模拟量联动警号
	BYTE		bySensorAlarmTypeJointAlarmOut[ALARMHOST_ALARMOUT_NUM/*64*/];//模拟量按类型联动触发器，该字段是bySensorJointAlarmOut的扩展。数组下标表示触发器号，数组元素的值按位表示报警类型，各个类型间是"或"的关系。类型值定义：1bit0-限1；bit1-限2；bit2-限3；bit3-限4；bit4-故障
	BYTE		bySesorAlarmTypeJointSiren[ALARMHOST_MAX_SIREN_NUM]; //模拟量按类型联动警号，该字段是bySensorJointSiren的扩展。数组下标表示警号序号，数组元素的值按位表示报警类型，各个类型间是"或"的关系。类型值定义：bit0-限1；bit1-限2；bit2-限3；bit3-限4；bit4-故障
	BYTE		byRes[56];
}NET_DVR_ALARMHOST_SENSOR_JOINT_CFG, *LPNET_DVR_ALARMHOST_SENSOR_JOINT_CFG;

//UPS报警信息上传
typedef struct tagNET_DVR_ALARMHOST_UPS_ALARMINFO
{
	BYTE	byAlarmType;/*报警类型：1.A相输入电压越限 2.B相输入电压越限 3.C相输入电压越限 4.A相输出电压越限5.B相输出电压越限 6.C相输出电压越限7.A相输入频率越限 8.B相输入频率越限9.C相输入频率越限10.整流器电压越限报警 11.过载报警 12.电池电压低报警 13.电池后备时间超低报警 14.电池温度超高报警 15.逆变器关闭报警 16.自动旁路开报警 17.整流器故障报警 18.逆变器故障报警 19.充电器故障报警	20.电池故障报警	 21.自动旁路故障报警 */	
	BYTE	byChanNo;	//485通道号，从1开始
	BYTE   bySlotNo;	//485虚拟槽位号
	BYTE	byRes1;		//保留
	int 		iAlarmValue;		//报警值
	BYTE	byRes2[64];		//保留
}NET_DVR_ALARMHOST_UPS_ALARMINFO, *LPNET_DVR_ALARMHOST_UPS_ALARMINFO;

//开关电源报警上传
typedef struct tagNET_DVR_ALARMHOST_SWITCH_POWER_SUPPLY_ALARMINFO
{
	BYTE	byAlarmType;	/*报警类型：1-电池测试失败 2-AC-DC转换器故障，3-输入线/相电压AB/A越限，4-输入线/相电压BC/B越限，5-输入线/相电压CA/C越限，6-输出电流A越限，7-输出电流B越限，8-输出电流C越限，9整流模块故障，10-风扇故障，11-直流电压越限*/
	BYTE	byChanNo;		//485通道号，从1开始
	BYTE	bySlotNo;		//485虚拟槽位号
	BYTE	byRes1;
	int 	iAlarmValue;		//报警值
	BYTE	byRes2[64];
}NET_DVR_ALARMHOST_SWITCH_POWER_SUPPLY_ALARMINFO, 
*LPNET_DVR_ALARMHOST_SWITCH_POWER_SUPPLY_ALARMINFO;

//气体检测系统报警
typedef struct tagNET_DVR_ALARMHOST_GAS_DETECT_SYS_ALARMINFO
{
	BYTE	byAlarmType;	/*报警类型：1- SF6气体含量异常，2-氧气含量异常，3-温度值异常，4-湿度值异常，5-流量*/
	BYTE	byChanNo;	//485通道号，从1开始
	BYTE	bySlotNo;	//485虚拟槽位号
	BYTE	byRes1;
	int 	iAlarmValue;		//报警值
	BYTE	byRes2[64];
}NET_DVR_ALARMHOST_GAS_DETECT_SYS_ALARMINFO, 
*LPNET_DVR_ALARMHOST_GAS_DETECT_SYS_ALARMINFO;


//温湿度传感器报警
typedef struct tagNET_DVR_ALARMHOST_TEMP_HUMIDITY_SENSOR_ALARMINFO
{
	BYTE	byAlarmType;	//1-温度异常，2-湿度异常
	BYTE	byChanNo;		//485通道号
	BYTE	bySlotNo;		//485槽位号
	BYTE	byRes1;
	int 		iAlarmValue;	//报警值
	BYTE	byRes2[64];
} NET_DVR_ALARMHOST_TEMP_HUMIDITY_SENSOR_ALARMINFO, *LPNET_DVR_ALARMHOST_TEMP_HUMIDITY_SENSOR_ALARMINFO;

typedef union  tagNET_DVR_485_DEVICE_ALARM_UNION
{
	NET_DVR_ALARMHOST_UPS_ALARMINFO struUPSAlarm; //UPS报警
	NET_DVR_ALARMHOST_SWITCH_POWER_SUPPLY_ALARMINFO struSwitchPowerAlarm; //开关电源报警
	NET_DVR_ALARMHOST_GAS_DETECT_SYS_ALARMINFO struGasDetectSystemAlarm; //气体检测系统报警
	NET_DVR_ALARMHOST_TEMP_HUMIDITY_SENSOR_ALARMINFO struTempHumiditySensorAlarm; //温湿度传感器报警
	BYTE	byRes[72];
} NET_DVR_485_DEVICE_ALARM_UNION, *LPNET_DVR_485_DEVICE_ALARM_UNION;

//485外接设备报警信息
typedef struct  tagNET_DVR_485_EXTERNAL_DEVICE_ALARMINFO
{
	DWORD dwSize;
	BYTE	byAlarmType;	//1-UPS报警，2-开关电源报警，3-气体检测系统报警，4-温湿度传感器报警
	BYTE	byRes1[3];
	NET_DVR_485_DEVICE_ALARM_UNION struAlarmInfo;
	BYTE	byRes2[16];
} NET_DVR_485_EXTERNAL_DEVICE_ALARMINFO, *LPNET_DVR_485_EXTERNAL_DEVICE_ALARMINFO;

typedef struct tagNET_DVR_ALARMHOST_RS485_SLOT_CFG
{
    DWORD   	dwSize;              // 结构体大小
    BYTE    	sDeviceName[NAME_LEN];  	// 前端设备名称 
    WORD    	wDeviceType;        	// 前端设备类型ALARM_FRONT_DEVICE _TYPE
	WORD		wDeviceProtocol;     // 前端设备协议 通过获取协议列表获取
	WORD        wAddress;			//设备地址	
	BYTE    	byRes[62];          // 保留字节
}NET_DVR_ALARMHOST_RS485_SLOT_CFG, *LPNET_DVR_ALARMHOST_RS485_SLOT_CFG;

//DM385平台网络摄像机
//走廊模式
typedef struct tagNET_DVR_CORRIDOR_MODE
{
	DWORD		dwSize;
	BYTE        byEnableCorridorMode; //是否启用走廊模式 0～不启用， 1～启用
	BYTE        byRes[127];
}NET_DVR_CORRIDOR_MODE, *LPNET_DVR_CORRIDOR_MODE;

//人脸侦测
typedef struct tagNET_DVR_DETECT_FACE
{
	DWORD	 dwSize;
	BYTE	 byEnableDetectFace; //是否启用 0～不启用， 1～启用
	BYTE	 byDetectSensitive; //灵敏度 10个等级 1～10
	BYTE     byEnableDisplay;	/*启用移动侦测高亮显示，0-否，1-是*/
	BYTE     byRes;
	NET_DVR_HANDLEEXCEPTION_V40  struAlarmHandleType; /*处理方式*/
	NET_DVR_SCHEDTIME struAlarmTime[MAX_DAYS][MAX_TIMESEGMENT_V30]; /*布防时间 */
	DWORD    dwMaxRelRecordChanNum;     //报警触发的录象通道 数（只读）最大支持数量
	DWORD    dwRelRecordChanNum;     //报警触发的录象通道数 实际支持数
	DWORD    dwRelRecordChan[MAX_CHANNUM_V30];	/* 报警触发的录象通道*/
	BYTE	 byRes1[64];
}NET_DVR_DETECT_FACE, *LPNET_DVR_DETECT_FACE;

typedef struct tagNET_DVR_MUL_STREAM_CHANNEL_GROUP
{
	DWORD	    dwSize;				 // 结构体大小
	DWORD       dwGroup ;             //组号
	NET_DVR_MULTI_STREAM_COMPRESSIONCFG_COND  struMultiStreamCfg; //多码流配置
	BYTE         byRes[64] ;        
}NET_DVR_MUL_STREAM_CHANNEL_GROUP,*LPNET_DVR_MUL_STREAM_CHANNEL_GROUP;

typedef struct tagNET_DVR_CHANNEL_GROUP
{
	DWORD	    dwSize;	// 结构体大小
	DWORD       dwChannel; //通道号
	DWORD       dwGroup;  //组号 
	BYTE        byRes[64];        
}NET_DVR_CHANNEL_GROUP, *LPNET_DVR_CHANNEL_GROUP;


typedef struct tagNET_VCA_TRAVERSE_PLANEPARAM
{
	DWORD dwSize;
	BYTE	byEnable;//使能
	BYTE	byEnableDualVca;// 启用支持智能后检索 0-不启用，1-启用
	BYTE	byRes1[2];
	NET_VCA_TRAVERSE_PLANE struAlertParam[MAX_ALERTLINE_NUM];  //警戒线参数
	NET_DVR_SCHEDTIME	struAlarmSched[MAX_DAYS][MAX_TIMESEGMENT_V30];
	NET_DVR_HANDLEEXCEPTION_V40 struHandleException;  //异常处理方式
	DWORD  dwMaxRelRecordChanNum ;  //报警触发的录象通道 数（只读）最大支持数量
	DWORD  dwRelRecordChanNum ;     //报警触发的录象通道 数 实际支持的数量
	DWORD  byRelRecordChan[MAX_CHANNUM_V30];//触发录像的通道号
    NET_DVR_SCHEDTIME struHolidayTime[MAX_TIMESEGMENT_V30]; //假日布防时间
	BYTE byRes2[100];
}NET_VCA_TRAVERSE_PLANE_DETECTION, *LPNET_VCA_TRAVERSE_PLANE_DETECTION;


typedef struct tagNET_VCA_FIELDDETECION
{
	DWORD dwSize;
	BYTE byEnable; //使能，是否开启
	BYTE byEnableDualVca;// 启用支持智能后检索 0-不启用，1-启用
	BYTE byRes1[2];
	NET_VCA_INTRUSION struIntrusion[MAX_INTRUSIONREGION_NUM];//每个区域的参数设置
	NET_DVR_SCHEDTIME struAlarmSched[MAX_DAYS][MAX_TIMESEGMENT_V30]; //布防时间
	NET_DVR_HANDLEEXCEPTION_V40 struHandleException;  //异常处理方式
	DWORD  dwMaxRelRecordChanNum ;  //报警触发的录象通道 数（只读）最大支持数量
	DWORD  dwRelRecordChanNum ;     //报警触发的录象通道 数 实际支持的数量
	DWORD  byRelRecordChan[MAX_CHANNUM_V30];//触发录像通道
    NET_DVR_SCHEDTIME struHolidayTime[MAX_TIMESEGMENT_V30/*8*/]; //假日布防时间
	BYTE byRes2[100];
}NET_VCA_FIELDDETECION, *LPNET_VCA_FIELDDETECION;

typedef struct tagNET_DVR_ROI_DETECT_NUM
{
	DWORD   dwSize;
	DWORD   dwGroup;
	DWORD   dwStreamType;	//码流类型，0-主码流，1-子码流，2-事件类型，3-码流3，……
	DWORD   dwRoiFixNum; //固定区域总数，确定后续再次获取的组号
	DWORD   dwRoiFixID[MAX_ROIDETECT_NUM];//IPC现在支持4个，球机现在支持24个
	BYTE    szFixRoiName[MAX_ROIDETECT_NUM][NAME_LEN];//固定ROI区域名称
	DWORD   dwRoiTrackNum; //自动跟踪区域总数，确定后续再次获取的组号
	DWORD   dwRoiTrackID[MAX_ROIDETECT_NUM];//IPC现在支持4个，球机现在支持24个
	BYTE    byRes[320];
}NET_DVR_ROI_DETECT_NUM, *LPNET_DVR_ROI_DETECT_NUM;

typedef  enum  _DETECT_ROI_TYPE_
{
	DETECT_FIX_ROI  =  0, //检测ROI固定区域
	DETECT_TRACK_ROI = 1 //检测ROI 自动跟踪区域
}DETECT_ROI_TYPE;
//条件参数
typedef struct tagNET_DVR_ROI_DETECT_COND
{
	DWORD   dwSize;
	DWORD   dwRoiID; //区域检测号 一个PTZ支持4个 
	NET_DVR_MULTI_STREAM_COMPRESSIONCFG_COND  struMultiStreamCfg; //多码流配置
	BYTE    byRoiDetectType; // DECTECT_ROI_TYPE 的值
	BYTE    byRoiDetectTrackType;//固定区域时，该字段无效；跟踪区域时，1～人脸侦测（IPC）,2～移动物体跟踪
	BYTE    byRes[30];
}NET_DVR_ROI_DETECT_COND,*LPNET_DVR_ROI_DETECT_COND;

//配置参数
//ROI固定区域模式 区域编码功能
typedef struct tagNET_DVR_ROI_FIX_RECT_CFG
{
	BYTE  byEnableFixRoi; // ROI固定区域模式 是否启用 0～不启用， 1～启用
	BYTE  byImageQualityLevel; //图像质量提升等级 1～6
	BYTE  byRes[2];
	BYTE  szFixRoiName[NAME_LEN];
	NET_VCA_RECT  struRoiRect;  //ROI区域
	BYTE  byRes1[468];
}NET_DVR_ROI_FIX_RECT_CFG, *LPNET_DVR_ROI_FIX_RECT_CFG;

//ROI自动跟踪模式 区域编码功能  
typedef struct tagNET_DVR_ROI_TRACK_RECT_CFG
{
	BYTE  byEnableTrackRoi; // ROI自动跟踪模式 是否启用 0～不启用， 1～启用
	BYTE  byImageQualityLevel; //图像质量提升等级 1～6
	BYTE  byModeType;// 0 ~ 无, 1～人脸模式(移动和静止的物体), 2~移动物体跟踪(移动的物体)
	BYTE  byRes[509];
}NET_DVR_ROI_TRACK_RECT_CFG, *LPNET_DVR_ROI_TRACK_RECT_CFG;

typedef union tagNET_DVR_ROI_DETECT_UNION
{
	DWORD						uLen[128];   
	NET_DVR_ROI_FIX_RECT_CFG    strRoiFixRectCfg;//固定区域模式
	NET_DVR_ROI_TRACK_RECT_CFG  strRoiTrackRectCfg;//自动跟踪模式
}NET_DVR_ROI_DETECT_UNION,*LPNET_DVR_ROI_DETECT_UNION;

typedef struct tagNET_DVR_ROI_DETECT_CFG
{
	DWORD      dwSize;  //560
	DWORD	   dwStreamType;	//码流类型，0-主码流，1-子码流，2-事件类型，3-码流3，……
	BYTE       byRoiDetectType; // DECTECT_ROI_TYPE 的值 
	BYTE       byRes[3];
	NET_DVR_ROI_DETECT_UNION  uRoiDetectInfo; //ROI检测区域
	BYTE       byRes1[36];
}NET_DVR_ROI_DETECT_CFG, *LPNET_DVR_ROI_DETECT_CFG;

//虚焦侦测
typedef struct tagNET_VCA_DEFOCUSPARAM
{	
	DWORD dwSize;
	BYTE byEnable;//使能
	BYTE byRes1[3];
	NET_DVR_HANDLEEXCEPTION_V40 struHandleException;  //异常处理方式
	BYTE byRes2[24];
}NET_VCA_DEFOCUSPARAM,*LPNET_VCA_DEFOCUSPARAM;

//IPC5.1.0
typedef struct tagNET_DVR_PRESET_NAME
{
	DWORD dwSize;
	WORD wPresetNum; //预置点编号
	BYTE byRes1[2]; //字节对齐 
	char byName[NAME_LEN];
	BYTE byRes[64];
}NET_DVR_PRESET_NAME, *LPNET_DVR_PRESET_NAME;

typedef struct
{
	NET_DVR_SCHEDTIME struSchedTime; //时间
	WORD  wAction;  ///< 定时动作具体动作
	WORD  wActionNum; ///< 特殊动作子编号，如预置点，巡航，花样，报警输出，日夜切换，
    BYTE byres[12];
}NET_DVR_SCHEDTASK,* LPNET_DVR_SCHEDTASK;

//定时任务
typedef struct tagNET_DVR_TIME_TASK
{
	DWORD dwSize;
	BYTE byTaskEnable;   ///< 使能 1-开，0-关
	BYTE byRes[3];    ///< 字节对齐
	NET_DVR_SCHEDTASK struTask[MAX_DAYS][MAX_SCH_TASKS_NUM];	///< 7天，每天10时间段
	DWORD dwParkTime;   ///< 守望时间 5s-720s
	BYTE byRes1[64];
}NET_DVR_TIME_TASK,*LPNET_DVR_TIME_TASK;

//条件结构体
typedef struct tagNET_DVR_CHANNEL_INDEX
{
	DWORD dwSize;				 // 结构体大小
	DWORD dwChannel ;           //通道号
	DWORD dwIndex ;             //索引号
	BYTE  byRes[64] ;        
}NET_DVR_CHANNEL_INDEX, *LPNET_DVR_CHANNEL_INDEX;

typedef struct tagNET_DVR_AUDIO_NAME
{
	DWORD dwSize;				 // 结构体大小
	char  cName[NAME_LEN] ;          //名称
	BYTE  byRes[64];          
}NET_DVR_AUDIO_NAME, *LPNET_DVR_AUDIO_NAME;

//登录设备参数
typedef struct tagNET_DVR_LOGIN_DEVICE_PARAM_
{	
    DWORD  dwSize;       //结构体大小
    BYTE   byMobileDev;  //设备种类, 0- 非移动设备, 1 - 移动设备
    BYTE   byRes[63];    //保留					
}NET_DVR_LOGIN_DEVICE_PARAM, *LPNET_DVR_LOGIN_DEVICE_PARAM;

//码流输出模式
typedef enum tagFISHEYE_STREAM_OUTPUT_MODE_
{
    FISHEYE_STREAM_MODE_FISHEYE    = 1,   //鱼眼模式
    FISHEYE_STREAM_MODE_PTZ        = 2,   //PTZ模式
    FISHEYE_STREAM_MODE_PANORAMA   = 3    //全景模式
}FISHEYE_STREAM_OUTPUT_MODE;

//回调数据类型枚举
typedef enum _CALLBACK_TYPE_DATA_ENUM_
{
    ENUM_FISHEYE_STREAM_STATUS   = 1,  //鱼眼码流输出状态
    ENUM_FISHEYE_PTZPOS          = 2,  //ptz通道当前所处鱼眼模式下的坐标
    ENUM_FISHEYE_REALTIME_OUTPUT = 3   //实时输出模式
}CALLBACK_TYPE_DATA_ENUM;

//鱼眼码流状态
typedef struct tagNET_DVR_FISHEYE_STREAM_STATUS_
{   
    DWORD  dwSize;        //结构体大小 
    BYTE   byStreamMode;  //码流输出模式，参见FISHEYE_STREAM_OUTPUT_MODE
    BYTE   byRes[63];     //保留
}NET_DVR_FISHEYE_STREAM_STATUS,*LPNET_DVR_FISHEYE_STREAM_STATUS;

//长连接回调数据结构体
typedef struct tagNET_DVR_CALLBACK_TYPE_DATA
{   
    DWORD  dwChannel;      //通道号
    DWORD  dwDataType;     //参见CALLBACK_TYPE_DATA_ENUM
    DWORD  dwDataLen;      //数据长度
    BYTE*  pData;          //数据，当dwTypeData为 ENUM_FISHEYE_STREAM_STATUS，其对应为NET_DVR_FISHEYE_STREAM_STATUS
    BYTE   byRes[64];      //保留    
}NET_DVR_CALLBACK_TYPE_DATA,*LPNET_DVR_CALLBACK_TYPE_DATA;

//鱼眼ptz拖动参数
typedef struct tagNET_DVR_DRAG_POS_PARAM
{
    DWORD          dwChannel;      //通道号
    DWORD          dwPtzChannel;   //当dwChannel所指通道模式为FISHEYE_STREAM_MODE_FISHEYE（鱼眼模式时），此值为其拖动所联动的ptz通道。当dwChannel通道模式为非鱼眼时，置为0即可
    NET_VCA_POINT  struToPoint;    //拖动画面要跳转到的目标点，目标点位置相对于预览画面的左上角
    NET_VCA_POINT  struOriPoint;   //拖动操作起始点,此点为当次拖动操作开始时，鼠标指针相对于预览画面左上角的位置
    BYTE           byRes[56];      //保留
}NET_DVR_DRAG_POS_PARAM,*LPNET_DVR_DRAG_POS_PARAM;

//平台查询诊断服务器的状态
typedef struct tagNET_DVR_QUERY_STATUS
{
    DWORD      dwSize;
	BYTE       byCpuLoad; 	  //CPU资源占用情况, 取值范围：0-100
	BYTE       byMemLoad;	  //Memory资源占用情况，取值范围：0-100
	WORD       wAbility;      //诊断服务器能力集，大于0
	WORD       wRemainAbility;//诊断服务器剩余能力，取值范围：大于 0  剩余监控点的个数
	WORD       wTotalPlanNum; //最多64个计划>
	WORD       wCurPlanNum;   //当前计划数  最多64个计划>
	BYTE       byRes[62];     //保留
}NET_DVR_QUERY_STATUS, *LPNET_DVR_QUERY_STATUS;

typedef struct tagNET_DVR_MONITOR_VQDCFG
{
	DWORD   dwSize;
	BYTE   byEnable;	   ///是否启用     
	BYTE   byDevType;     	//设备类型：0-非云台设备，1-带云台设备
	BYTE   bySignalPoint;   ///< 信号丢失阀值，0-100
	BYTE   byBlurPoint;    ///< 图像模糊阀值，0-100
	BYTE   byLumaPoint;    ///< 亮度异常阀值，0-100
	BYTE   byChromaPoint;    ///< 图像偏色阀值，0-100
	BYTE   bySnowPoint;    ///< 雪花干扰阀值，0-100
	BYTE   byStreakPoint;    ///< 条纹干扰阀值，0-100
	BYTE   byFreezePoint;    ///< 画面冻结阀值，0-100
	BYTE   byPTZPoint;    ///< 云台失控阀值，0-100
	BYTE   byMonitorDel;  //< 监控点删除 0-不删除， 1-删除
	BYTE   byRes[53];
} NET_DVR_MONITOR_VQDCFG, *LPNET_DVR_MONITOR_VQDCFG;

//诊断结果
typedef struct tagNET_DVR_DIAGNOSIS_UPLOAD
{
	DWORD  dwSize;
	char   sStreamID[STREAM_ID_LEN];	///< 流ID，长度小于32个字节
   	char  sMonitorIP[64];  ///< 监控点ip
   	DWORD  dwChanIndex;  ///< 监控点通道号  
	DWORD  dwWidth;  ///< 图像宽度
	DWORD  dwHeight;  ///< 图像高度
	NET_DVR_TIME  struCheckTime;  ///< 检测时间(合并日期和时间字段)，格式：2012-08-06 13:00:00
	BYTE  byResult;  ///0-未检测 1-正常 2-异常 3-登录失败 4-取流异常
	BYTE  bySignalResult; ///< 视频丢失检测结果 0-未检测 1-正常 2-异常
   	BYTE  byBlurResult;  ///< 图像模糊检测结果，0-未检测 1-正常 2-异常
   	BYTE  byLumaResult;  ///< 亮度异常检测结果，0-未检测 1-正常 2-异常
   	BYTE  byChromaResult;  ///< 偏色检测结果，0-未检测 1-正常 2-异常
   	BYTE  bySnowResult;  ///< 雪花点干扰检测结果，0-未检测 1-正常 2-异常
	BYTE  byStreakResult;  ///< 条纹干扰检测结果，0-未检测 1-正常 2-异常
   	BYTE  byFreezeResult;  ///< 画面冻结检测结果，0-未检测 1-正常 2-异常
   	BYTE  byPTZResult;  ///< 云台检测结果，0-未检测 1-正常 2-异常
	BYTE  byRes1[3];
	char  sSNapShotURL[256];	///<图片URL地址
	BYTE  byRes2[64];
}NET_DVR_DIAGNOSIS_UPLOAD, *LPNET_DVR_DIAGNOSIS_UPLOAD;

typedef struct tagNET_DVR_DOWN_LOAD_REQUEST   ///< 这个数据结构是平台发送到诊断服务器的
{
	NET_DVR_STREAM_INFO  struStreamInfo;
   	char   sSnapShotURL[256];  ///< 诊断抓图URL，长度小于256个字节	
	BYTE   byRes[32];
}NET_DVR_DOWN_LOAD_REQUEST, *LPNET_DVR_DOWN_LOAD_REQUEST;

typedef struct tagNET_DVR_VQD_RESULT_INFO  ///< 这个数据结构是诊断服务器返回给平台的
{
	DWORD  dwSize;
	char   sStreamID[32];	 ///<流ID(监控点ID)，长度小于32个字节
	DWORD  dwPicLength;  ///图片长度
	BYTE   byStatus;     ///< 设置结果:0-成功,1-数据有误，2-图片不存在，3-获取图片失败
	BYTE   byRes[31];
   	char   *pSnapShot;      ///< 诊断抓图，是一块图片缓存数据(700k)
}NET_DVR_VQD_RESULT_INFO, *LPNET_DVR_VQD_RESULT_INFO;

typedef struct tagNET_DVR_PLAN_VQD_CFG
{
	DWORD   dwSize;
	BYTE    sPlanID[PLAN_ID_LEN];	///< 计划id，长度小于32个字节
   	NET_DVR_SCHEDTIME  struDetectTime[MAX_DAYS][MAX_TIMESEGMENT_V30];	///< 检测时间 
	BYTE	byPlanMode;  ///0:即时计划，1:周期计划
	BYTE    byRes1;// 	
	BYTE    byCheckFlag;  ///< 是否检测，0-不检测，1-检测
	BYTE    bySignal;  ///<视频丢失 是否检测，0-不检测，1-检测
   	BYTE    byBlur;  ///< 图像模糊 是否检测，0-不检测，1-检测
   	BYTE    byLuma;  ///< 亮度异常 是否检测，0-不检测，1-检测
   	BYTE    byChroma;  ///< 偏色检测 是否检测，0-不检测，1-检测
   	BYTE    bySnow;  ///<雪花点干扰 是否检测，0-不检测，1-检测
	BYTE    byStreak;  ///<条纹干扰 是否检测，0-不检测，1-检测
   	BYTE    byFreeze;  ///<画面冻结是否检测，0-不检测，1-检测
   	BYTE    byPTZ;  ///<云台是否检测，0-不检测，1-检测
	BYTE    byEnablePlanRound;  ///计划循环是否开启
	BYTE    byRes[20];     
}NET_DVR_PLAN_VQD_CFG, *LPNET_DVR_PLAN_VQD_CFG;


typedef struct tagNET_DVR_TEST_SPOTCFG
{
	DWORD dwSize;
	BYTE  byStepCount;                //总步数
	BYTE  byStepIndex;                //当前第几步
	BYTE  byRes[14];
}NET_DVR_TEST_SPOTCFG, *LPNET_DVR_TEST_SPOTCFG;

//第三方IPC列表
typedef enum tagNET_DVR_IPC_ENUM
{
    ENUM_BUSINESS_INVALID = -1,
		
	ENUM_BUSINESS_HIKVISION = 0,
	ENUM_BUSINESS_PANASONIC,
	ENUM_BUSINESS_SONY,
	ENUM_BUSINESS_AXIS,
	ENUM_BUSINESS_SANYO,
	ENUM_BUSINESS_BOSCH,
	ENUM_BUSINESS_ZAVIO,
	ENUM_BUSINESS_GRANDEYE,
	ENUM_BUSINESS_PROVIDEO,
	ENUM_BUSINESS_ARECONT, // 9 
	ENUM_BUSINESS_ACTI,
	ENUM_BUSINESS_PELCO,
	ENUM_BUSINESS_VIVOTEK,
	ENUM_BUSINESS_INFINOVA,  
	ENUM_BUSINESS_DAHUA,	//14
	
	ENUM_BUSINESS_HIK_STD_H264 = 0x20,
	ENUM_BUSINESS_HIK_STD_MPEG4,
	ENUM_BUSINESS_SUNELL ,	//景阳
	ENUM_BUSINESS_ATEME ,	
	ENUM_BUSINESS_LAUNCH,	//朗驰
	ENUM_BUSINESS_YAAN,    //雅安
	ENUM_BUSINESS_BLUESKY,	//蓝色星际
	ENUM_BUSINESS_BLUESKYLIMIT,//蓝色星际
	ENUM_BUSINESS_TDWY,			//天地伟业
	ENUM_BUSINESS_HBGK,			//汉邦高科
	ENUM_BUSINESS_SANTACHI,		//金三立
	ENUM_BUSINESS_HIGHEASY,		//恒忆
	ENUM_BUSINESS_SAMSUNG,          
	
	ENUM_BUSINESS_URL_RTSP = 0x40,    /* url类型取流 */
	ENUM_BUSINESS_ONVIF,            
	
	ENUM_MAX_BUSINESS_TYPE,    //最大厂商类型
} NET_DVR_IPC_ENUM, *LPNET_DVR_IPC_ENUM;

typedef struct tagNET_DVR_MRD_SEARCH_PARAM
{
	DWORD			dwSize;			// 结构体大小
	NET_DVR_STREAM_INFO	struStreamInfo;	// 监控点
	WORD 			wYear;      		// 年 
	BYTE 			byMonth;    		// 月
	BYTE			byDrawFrame;	// 0-不抽帧 1-抽帧
	BYTE  			byRes[32];       // 保留
}NET_DVR_MRD_SEARCH_PARAM, *LPNET_DVR_MRD_SEARCH_PARAM;

typedef struct tagNET_DVR_MRD_SEARCH_RESULT
{	
	DWORD			dwSize;			// 结构体大小
	BYTE			byRecordDistribution[LEN_32];   // 录像分布，byRecordDistribution[0]=1表示1日存在录像，byRecordDistribution[0]=0表示没有录像，
	//byRecordDistribution[1]表示2日，以此类推
	BYTE			byHasEventRecode[LEN_31];            //事件录像 0-无事件录像，1-有事件录像
	BYTE			byRes;        				//保留
}NET_DVR_MRD_SEARCH_RESULT, *LPNET_DVR_MRD_SEARCH_RESULT;


typedef struct tagNET_DVR_ACCESS_DEVICE_INFO
{
	DWORD	dwSize;	// 结构体大小
	BYTE 	byGroup;			// 组号，每组可获取 64个通道，从0开始, 0表示第1组，以此类推
	BYTE	byProType;					//协议类型，0-私有协议，1-松下协议，2-索尼
	BYTE	byAccessMode;		//接入模式，0-IP地址，1-域名
    BYTE	byRes1;					//保留字段，置0
    char	szUserName[NAME_LEN];		//用户名
    char	szPassword[PASSWD_LEN];	    //密码
    char	szDomain[MAX_DOMAIN_NAME];	//设备域名
    NET_DVR_IPADDR struIP;			//IP地址
    WORD	wPort;			 	    // 端口号
    BYTE	byRes2[34];				//保留字段，置0
}NET_DVR_ACCESS_DEVICE_INFO, *LPNET_DVR_ACCESS_DEVICE_INFO;

typedef struct tagNET_DVR_ACCESS_DEVICE_CHANNEL_INFO
{
	DWORD	dwSize;	// 结构体大小
	DWORD	dwTotalChannelNum;      //设备总通道个数，设备不在线时返回0，byChannel无效
	BYTE 	byChannel[MAX_CHANNUM_V30];    /*byChannel[i]为0表示第（byGroup+1）*（i-1）通道未接入到NVR，
								为1表示该通道已接入到NVR
								byGroup在NET_DVR_ACCESS_DEVICE_INFO中*/
	BYTE  byRes[32];           //保留
}NET_DVR_ACCESS_DEVICE_CHANNEL_INFO, *LPNET_DVR_ACCESS_DEVICE_CHANNEL_INFO;

typedef struct tagNET_DVR_PREVIEW_SWITCH_COND
{
	DWORD	dwSize; //组号
    BYTE	byGroup; //组号，每组可配置64个画面
	BYTE	byVideoOutType; /*视频输出接口类型,0-主CVBS,1-HDMI 2-VGA 3-辅助输出一
							4-辅助输出二 5-辅助输出三 6-辅助输出四, 7-辅助HDMI, 8-扩展HDMI1,
                            9-扩展HDMI2, 10-扩展HDMI3, 11-扩展HDMI4 */
    BYTE	byRes[2];
}NET_DVR_PREVIEW_SWITCH_COND, *LPNET_DVR_PREVIEW_SWITCH_COND;

typedef struct tagNET_DVR_PREVIEW_SWITCH_CFG
{
	DWORD	dwSize;	// 版本管理及结构体大小
	WORD	wSwitchSeq[MAX_WINDOW_V40];/*bySwitchSeq [i]=6，表示第（组号*64+i+1）个窗口
										显示第六通道，为0xff表示该窗口不显示*/
	BYTE	byPreviewNumber;/*预览数目,0-1画面,1-4画面,2-9画面,3-16画面, 4-6画面, 5-8画面，6-25画面,7-32画面, 8-36画面
								0xff:最大画面*/
	BYTE	byEnableAudio;//是否声音预览,0-不预览,1-预览
	BYTE	bySwitchTime;//切换时间,0-不切换,1-5s,2-10s,3-20s,4-30s, 5-60s 6-120s,7-300s
    BYTE	byRes[33];		//保留
}NET_DVR_PREVIEW_SWITCH_CFG,* LPNET_DVR_PREVIEW_SWITCH_CFG;

// CVR 2.0.X
typedef struct tagNET_DVR_USER_COND
{	
	char		szUserName[NAME_LEN];
	BYTE		byRes[48];
}NET_DVR_USER_COND, *LPNET_DVR_USER_COND;

typedef struct tagNET_DVR_USER_RIGHT_CFG
{	
	DWORD			dwSize;
	BYTE			byAddMonitoringPointRight; // 添加监控点（前端设备）权限0-无 1-有
	BYTE			byModMonitoringPointRight; // 修改监控点（前端设备）权限0-无 1-有
	BYTE			byDelMonitoringPointRight; // 添加监控点（前端设备）权限0-无 1-有
	BYTE			bySetRecordPlanRight; // 制定录像策略权限0-无 1-有
	BYTE			byDelRecordPlanRight; // 删除录像策略权限0-无 1-有
	BYTE			byEnableOrDisableRecordPlanRight; // 启用和禁用录像计划权限0-无 1-有
	BYTE			byManualRecordRight; // 启动和停止手动录像权限0-无 1-有
	BYTE			bySetAlarmRecordRight; // 报警录像设定权限0-无 1-有
	BYTE			byRecordBackupRight; // 录像存档权限0-无 1-有
	BYTE			byRecordDownloadRight; // 录像下载权限0-无 1-有
	BYTE			byRecordDeleteRight; // 录像删除权限0-无 1-有（保留）
	BYTE			byDelBackupRecordRight; // 删除存档录像权限0-无 1-有（保留）
	BYTE			bySetBackupVolumeRight; // 设置存档卷权限0-无 1-有
	BYTE			byRecordPlayBackRight; // 录像回放权限0-无 1-有
	BYTE			byLogDeleteRight; // 日志清空权限0-无 1-有（保留）
	BYTE			byLogDownloadRight; // 日志下载权限0-无 1-有（保留）
	BYTE			byAddUserRight; // 添加用户权限0-无 1-有
	BYTE			byDelUserRight; // 删除用户权限0-无 1-有
	BYTE			byModUserRight; // 修改用户权限0-无 1-有
	BYTE			byAllocUserRight; // 用户权限分配权限0-无 1-有
	BYTE			byRes[128];
}NET_DVR_USER_RIGHT_CFG, *LPNET_DVR_USER_RIGHT_CFG;

typedef struct tagNET_DVR_MACHINE_MAX_NUM_CFG
{
	DWORD				dwSize;
	DWORD   			dwMaxNum; 		// 最大备机数目
	BYTE 	  			byRes[32];
}NET_DVR_MACHINE_MAX_NUM_CFG, *LPNETDVR_MACHINE_MAX_NUM_CFG;

//配置N+1设备工作机模式，NVR需要这步，CVR不需要
typedef struct tagNET_DVR_N_PLUS_ONE_WORK_MODE_CFG
{
	DWORD	dwSize ;
	BYTE	byWorkMode;		//0-工作机 1-备机
	BYTE	byRes[127];       //保留
}NET_DVR_N_PLUS_ONE_WORK_MODE_CFG, *LPNET_DVR_N_PLUS_ONE_WORK_MODE_CFG;

typedef struct tagNET_DVR_ADD_PARAM
{
	NET_DVR_IPADDR	struIP;		// 设备IP
	char			szPassword[PASSWD_LEN];	//备机密码，需简易加密
	BYTE 			byAddType; 		// 0-（工作机上）添加备机，1-（备机上）添加工作机
	BYTE 			byDisableBackup; //备份功能使能开关 0-开启1-关闭 CVR默认开启
}NET_DVR_ADD_PARAM, *LPNET_DVR_ADD_PARAM;

typedef struct tagNET_DVR_DEL_PARAM
{
    NET_DVR_IPADDR	struIP;		// 设备IP
	BYTE 			byDelType; 	// 0-删除指定的机器（备机或工作机）1-全删
}NET_DVR_DEL_PARAM, *LPNET_DVR_DEL_PARAM;

typedef union tagNET_DVR_NPO_PARAM_UNION
{
	NET_DVR_ADD_PARAM	struAddParam;		//添加信息
    NET_DVR_DEL_PARAM 	struDelParam;		//删除信息
}NET_DVR_NPO_PARAM_UNION, *LPNET_DVR_NPO_PARAM_UNION;

// N+1模式设备参数
typedef struct tagNET_DVR_N_PLUS_ONE_DEVICE_PARAM
{
	DWORD					dwSize;
	NET_DVR_NPO_PARAM_UNION unionParam;
	BYTE 					byType; 	/* 0-添加，对应unionParam中的struAddParam 1-删除，对应unionParam中的struDelParam */
	BYTE  					byRes2[255];          // 保留
}NET_DVR_N_PLUS_ONE_DEVICE_PARAM, *LPNET_DVR_N_PLUS_ONE_DEVICE_PARAM;

// 数据回迁
typedef struct tagNET_DVR_DATA_CALLBACK_CFG
{
	DWORD				dwSize;
	BYTE   				byEnable; 	// 0-不启用数据回迁 1-启用数据回迁
	BYTE   				byDelData; 	// 当byEnable为1是有效 0-不删除备机录像数据 1-删除备机录像数据
	BYTE 	  			byRes[30];
}NET_DVR_DATA_CALLBACK_CFG, *LPNET_DVR_DATA_CALLBACK_CFG;

typedef struct tagNET_DVR_HD_STATUS
{
	DWORD 	dwSize;
	BYTE 	bySleepStatus;/*休眠状态0-不休眠 1-休眠*/
    BYTE  	byRes[127];
}NET_DVR_HD_STATUS, *LPNET_DVR_HD_STATUS;

typedef struct tagNET_DVR_RAID_BTS_CFG
{
	DWORD 	dwSize;
	BYTE 	bySpeed;	/*0-高速 1-中速 2-低速*/
    BYTE  	byRes[127];
}NET_DVR_RAID_BTS_CFG, *LPNET_DVR_RAID_BTS_CFG;

typedef struct tagNET_DVR_LUN_CLONE
{
	DWORD				dwSize;
	DWORD				dwSrcLunID;		// 源LUN ID
	DWORD   			dwDstLunID; 	// 目的LUN ID
	BYTE 	  			byRes[32];
}NET_DVR_LUN_CLONE, *LPNET_DVR_LUN_CLONE;

typedef struct tagNET_DVR_LUN_EXPAND
{
	DWORD				dwSize;
	DWORD				dwLunID;					// LUN ID
	DWORD				dwHSize;					// 扩展的大小高32位
	DWORD				dwLSize;					// 扩展的大小低32位
	char				szArrayIDGroup[NAME_LEN];	// 使用的阵列ID组，以逗号隔开，为空则为默认
	char   				szNewLunName[MAX_NAMELEN]; 	// 新LUN名
	BYTE 	  			byRes[32];
}NET_DVR_LUN_EXPAND, *LPNET_DVR_LUN_EXPAND;


typedef struct tagNET_DVR_DVR_NET_DISK_MODIFY
{
	DWORD				dwSize;
	char				szOldDvrNetDiskName[MAX_NAMELEN];		// 原DVR网盘共享名
	char   				szNewDvrNetDiskName[MAX_NAMELEN]; 	// 新DVR网盘共享名
	NET_DVR_IPADDR		struWarrantIP;						// 新授权的DVR网盘IP
	BYTE 	  			byRes[32];
}NET_DVR_DVR_NET_DISK_MODIFY, *LPNET_DVR_DVR_NET_DISK_MODIFY;


typedef struct tagNET_DVR_NAS_PARAM
{
	DWORD				dwSize;
	DWORD				dwLunID;		// LUN ID
	BYTE 	  			byRes[32];
}NET_DVR_NAS_PARAM, *LPNET_DVR_NAS_PARAM;

typedef struct tagNET_DVR_ISCSI_PARAM
{
	DWORD				dwSize;
	DWORD				dwTargetID;		// iSCSI服务的Target ID
	DWORD				dwLunID;		// LUN ID
	DWORD				dwAccessMode;	//读写方式 0-读写 1-同步读写 2-只读 3-智能只读;
	NET_DVR_IPADDR		struClientIP;		// 客户端IP，0.0.0.0为所以IP
	BYTE 	  			byRes[32];
}NET_DVR_ISCSI_PARAM, *LPNET_DVR_ISCSI_PARAM;

typedef struct tagNET_DVR_FC_PARAM
{
	DWORD				dwSize;
	DWORD				dwStoreLunID;					// 存储LUN ID
	DWORD				dwLogicLunID;					// 逻辑LUN ID，-1表示自动生成
	DWORD				dwHbaID;						// 光纤通道号
	DWORD				dwAccessMode;					//读写方式 0-读写 1-同步读写 2-只读 3-智能只读;
	char				szClientWWWPN[NAME_LEN]; 		// 客户光纤卡
	BYTE 	  			byRes[32];
}NET_DVR_FC_PARAM, *LPNET_DVR_FC_PARAM;


// 逻辑卷 60字节
typedef struct tagNET_DVR_LUN_PARAM
{
	DWORD		dwHCapacity;	// 逻辑卷大小高32位
	DWORD		dwLCapacity;	// 逻辑卷大小低32位
	char    	szName[MAX_NAMELEN]; 	// 逻辑卷名称
	DWORD		dwBlockSize;		// 逻辑卷的最小存储单元块大小
	char		szArrayIDGroup[NAME_LEN]; 	//使用的阵列ID组，以逗号隔开，为空则使用默认阵列
}NET_DVR_LUN_PARAM, *LPNET_DVR_LUN_PARAM;

// DVR网盘 84字节
typedef struct tagNET_DVR_DVR_PARAM_
{
	DWORD			dwHCapacity;	// DVR网盘大小高32位
	DWORD			dwLCapacity;	// DVR网盘大小低32位
	char 	   		szName[MAX_NAMELEN]; 	// DVR网盘名称
	DWORD			dwBlockSize;		// 逻辑卷的最小存储单元块大小
	NET_DVR_IPADDR	struWarrantIP;		// 授权的DVR网盘IP
	char			szArrayIDGroup[NAME_LEN]; 	//使用的阵列ID组，以逗号隔开，为空则使用默认阵列
}NET_DVR_DVR_PARAM, *LPNET_DVR_DVR_PARAM;

typedef union tagNET_DVR_VD_UNION
{
	BYTE						byUnionLen[256];  	// 联合体大小
	NET_DVR_OPERATE_VD_PARAM	struHikVDParam;		// 虚拟磁盘
	NET_DVR_LUN_PARAM			struLunParam;			// 逻辑卷
	NET_DVR_DVR_PARAM			struDvrParam;			// DVR网盘
}NET_DVR_VD_UNION, *LPNET_DVR_VD_UNION;

typedef struct tagNET_DVR_OPERATE_VD_PARAM_EX
{
	BYTE				byVDType;	//虚拟磁盘类型：0-私有虚拟磁盘 1-逻辑卷 2-DVR网盘
	BYTE				byRes1[3];
	NET_DVR_VD_UNION 	uVDParam;
	BYTE				byRes2[32];
}NET_DVR_OPERATE_VD_PARAM_EX, *LPNET_DVR_OPERATE_VD_PARAM_EX;

// CVR 2.0.X报警结构体
typedef struct tagNET_DVR_CVR_ALARM
{
	char    		szFirstType[NAME_LEN];  //主类型，不能为空
	char			szFirstIndex[NAME_LEN];	//主类型编号
	char			szSecondType[NAME_LEN];	//次类型，可以为空
	NET_DVR_TIME	struTime;		//报警时间
	BYTE 			byStatus;   	//状态 0-正常 非0-不正常，不同类型值表示意义不同，见下表
	BYTE		    byAlarmLevel;         //报警级别
	BYTE			byRes1[2];
	char           	szSecondIndex[NAME_LEN];  //次类型编号，可以为空
	char    		szThirdType[NAME_LEN];  //第三类型，可以为空
	char			szThirdIndex[NAME_LEN];	//第三类型编号
	char    		szFourthType[NAME_LEN];  //第四类型，可以为空
	char			szFourthIndex[NAME_LEN];	//第四类型编号
    BYTE      		byRes2[92];  //保留
}NET_DVR_CVR_ALARM, *LPNET_DVR_CVR_ALARM; 

typedef struct tagNET_DVR_WORKING_DEVICE_INFO
{
	NET_DVR_IPADDR	struIP;			//设备IP
	BYTE 			byLinkStatus; //连接状态 0-连接失败1-连接成功
	BYTE 			byWorkStatus; //工作状态 0-正常1-异常
	BYTE 			byBacupStatus; //备份状态0-不在备份1-正在备份
	BYTE 			bySyncProgress; //录像同步进度，0表示未开始，100表示同步完成
	NET_DVR_TIME_EX	struSyncBeginTime;	//同步开始时间
	NET_DVR_TIME_EX	struSyncEndTime;		//同步结束时
	char			szSerialNumber[SERIALNO_LEN] ; //设备序列号
	DWORD			dwSoftwareVersion ;		//设备软件版本
	BYTE  			byWorkingDeviceGUID[GUID_LEN]; //工作机GUID，非字符串，用于备机上搜索工作机录像
	char			szDevTypeName[DEV_TYPE_NAME_LEN];		//设备类型名称
	WORD			wDevType;		//设备类型值
}NET_DVR_WORKING_DEVICE_INFO, *LPNET_DVR_WORKING_DEVICE_INFO;

typedef struct tagNET_DVR_REDUNDANT_DEVICE_INFO
{
	NET_DVR_IPADDR	struIP;			//设备IP
	BYTE 			byWorkStatus; 	//工作状态 0-正常1-异常
	BYTE 			byBackupStatus; //备份状态0-不在监控 1-正在监控2-正在备份中2-正在同步
	WORD			wBackupPort;	//备份端口
}NET_DVR_REDUNDANT_DEVICE_INFO, *LPNET_DVR_REDUNDANT_DEVICE_INFO;

typedef union tagNET_DVR_NPO_DEV_INFO_UNION
{
    BYTE 							byUnionLen[512];			//联合体长度
	NET_DVR_WORKING_DEVICE_INFO		struWorkingDeviceInfo;		//工作机信息
	NET_DVR_REDUNDANT_DEVICE_INFO	struRedundantDeviceInfo; 	//备机信息
}NET_DVR_NPO_DEV_INFO_UNION, *LPNET_DVR_NPO_DEV_INFO_UNION;


typedef struct tagNET_DVR_N_PLUS_ONE_DEVICE_INFO
{
	DWORD						dwSize;
	NET_DVR_NPO_DEV_INFO_UNION	unionDevInfo;
	BYTE						byType;	/*类型 0-工作机，对应unionDevInfo中的struWorkingDeviceInfo 	1-备机，对应unionDevInfo中的struRedundantDeviceInfo*/
	BYTE 	  					byRes[127];	
}NET_DVR_N_PLUS_ONE_DEVICE_INFO, *LPNET_DVR_N_PLUS_ONE_DEVICE_INFO;

//ipc升级参数
typedef struct tagNET_DVR_UPGRADE_IPC_PARAM
{
	NET_DVR_STREAM_INFO	struStreamInfo[MAX_CHANNUM_V30];	// 64个监控点
	char  				szFileName[260];					// 升级文件名
}NET_DVR_UPGRADE_IPC_PARAM, *LPNET_DVR_UPGRADE_IPC_PARAM;


typedef struct tagNET_DVR_UPGRADE_IPC_ERR_INFO_SINGLE
{
	NET_DVR_STREAM_INFO	struStreamInfo; 	//监控点
	WORD				wErrCode;    		//对应错误码
	BYTE				byRes[30];          //保留
}NET_DVR_UPGRADE_IPC_ERR_INFO_SINGLE, *LPNET_DVR_UPGRADE_IPC_ERR_INFO_SINGLE;

typedef struct tagNET_DVR_UPGRADE_IPC_ERR_INFO
{
	NET_DVR_UPGRADE_IPC_ERR_INFO_SINGLE struErrInfoSingle[MAX_CHANNUM_V30];
}NET_DVR_UPGRADE_IPC_ERR_INFO, *LPNET_DVR_UPGRADE_IPC_ERR_INFO;

//IPC配置文件导入
typedef struct tagNET_DVR_IPC_CFG_FILE_PARAM
{
	char  		szFileName[260];					// 配置文件名
	BYTE		byRes[32];						
}NET_DVR_IPC_CFG_FILE_PARAM, *LPNET_DVR_IPC_CFG_FILE_PARAM;

typedef struct tagNET_DVR_IPC_CFG_FILE_ERR_INFO_SINGLE
{
	WORD 	wRow;   	//出错的行，0表示没出错，1表示第1行出错，以此类推
	WORD	wErrCode;	//错误码
	BYTE	byRes[32];
}NET_DVR_IPC_CFG_FILE_ERR_INFO_SINGLE, *LPNET_DVR_IPC_CFG_FILE_ERR_INFO_SINGLE;

typedef struct tagNET_DVR_IPC_CFG_FILE_ERR_INFO
{
	NET_DVR_IPC_CFG_FILE_ERR_INFO_SINGLE 	struErrInfoSingle[MAX_CHANNUM_V30];
}NET_DVR_IPC_CFG_FILE_ERR_INFO, *LPNET_DVR_IPC_CFG_FILE_ERR_INFO;

typedef struct tagNET_DVR_PTZ_PATTERN
{
    DWORD dwSize; 
	DWORD dwChannel; //通道号
	DWORD dwPatternCmd; //云台轨迹操作命令码,详见下面定义
	DWORD dwPatternID; //云台轨迹ID（删除所有轨迹时无效）
	BYTE  byRes[64]; 
}NET_DVR_PTZ_PATTERN, *LPNET_DVR_PTZ_PATTERN;

typedef struct tagNET_DVR_PTZ_PARKACTION_CFG
{
	DWORD dwSize;
	BYTE  byEnable; //是否启用，0-不启用，1-启用
	BYTE  byRes1[3];
	DWORD dwParkTime; //守望等待时间，单位s 
	WORD  wActionType; //守望动作类型，0-自动扫描，1-帧扫描，2-随机扫描，3-巡航扫描，4-花样扫描，5-预置点，6-全景扫描，7-垂直扫描
	WORD  wID; //ID号（巡航扫描、预置点、花样扫描的ID）
	BYTE  byRes[128]; 
}NET_DVR_PTZ_PARKACTION_CFG, *LPNET_DVR_PTZ_PARKACTION_CFG;

typedef struct tagNET_DVR_PTZ_MANUALTRACE
{
    DWORD dwSize; 
	DWORD dwChannel; //通道号
	NET_VCA_POINT struPoint; //定位坐标
	BYTE byTrackType; //跟踪类型0==普通跟踪 1==高速道路跟踪 2==城市道路跟踪
	BYTE byRes[63]; 
}NET_DVR_PTZ_MANUALTRACE, *LPNET_DVR_PTZ_MANUALTRACE;

typedef enum tagVQD_TYPE
{
    VQD_BLUR_FLAG     = 0x00000001,    //图像模糊
		VQD_LUMA_FLAG     = 0x00000002,//亮度异常
		VQD_CHROMA_FLAG   = 0x00000004,//图像偏色
		VQD_SNOW_FLAG     = 0x00000008,//雪花干扰
		VQD_STREAK_FLAG   = 0x00000010,//条纹干扰
		VQD_FREEZE_FLAG   = 0x00000020,//画面冻结
		VQD_SIGLOSE_FLAG  = 0x00000040,//信号丢失
		VQD_PTZ_FLAG      = 0x00000080//云台失控
}VQD_TYPE;

typedef struct tagNET_DVR_VQD_LOOP_DIAGNOSE_CFG
{
    DWORD  dwSize ;        //结构体大小
	BYTE	byEnable;	    // 诊断使能 0 :关闭，开启 1:开启
	BYTE 	byRes1[3] ;     //保留
	BYTE	byVQDTypeEnable[32];     //VQD诊断模式，0 --不启用 1--启用  每种诊断类型对应有灵敏度，灵敏度的下标与诊断类型的下标一致
								    /*数组0 图像模糊     数组1 亮度异常 数组2 图像偏色*/
	                                /*数组3 雪花干扰     数组4 条纹干扰 数组5 画面冻结*/
									/*数组6 信号丢失     数组7 云台失控*/	
	BYTE byThresholdValue[32] ;       //阈值0~100，不同诊断模式有各自对应的阈值
	NET_DVR_HANDLEEXCEPTION_V40      struAlarmHandleType;   //报警处理方式
	NET_DVR_SCHEDTIME   struAlarmTime[MAX_DAYS][MAX_TIMESEGMENT_V30];
	NET_DVR_SCHEDTIME   struHolidayAlarmTime[MAX_TIMESEGMENT_V30];  //假日布防时间段 
	BYTE    byRes[324];      //保留
}NET_DVR_VQD_LOOP_DIAGNOSE_CFG, *LPNET_DVR_VQD_LOOP_DIAGNOSE_CFG;


typedef struct tagNET_DVR_VQD_DIAGNOSE_EXCEPTION_INFO
{
    DWORD  dwChannelNO;   //通道号
	DWORD  dwVQDType;     // VQD诊断类型	
	NET_DVR_TIME struDiagnoseTime;    //诊断时间
	BYTE     byScoreValue;       //分数值 ，百分制
    BYTE     byRes[27];
}NET_DVR_VQD_DIAGNOSE_EXCEPTION_INFO,*LPNET_DVR_VQD_DIAGNOSE_EXCEPTION_INFO;


typedef struct tagNET_DVR_VQD_DIAGNOSE_INFO
{
	DWORD  dwSize ;        //结构体大小
	NET_DVR_VQD_DIAGNOSE_EXCEPTION_INFO  struVQDDiagnoseExceptionInfo ; //诊断异常信息结构体
}NET_DVR_VQD_DIAGNOSE_INFO, *LPNET_DVR_VQD_DIAGNOSE_INFO;

typedef struct tagNET_DVR_DEC_RESOURCE_LIST
{
	DWORD dwSize;
	BYTE  byDecStatus[MAX_SUBSYSTEM_NUM_V40/*120*/]; 
	//解码资源状态列表，byDecStatus[i]表示槽位号i的子系统状态，0-无效，1-空闲，2-普通解码(包括普通解码上墙和大屏主从屏)，3-智能解码
    BYTE  byRes[32];
}NET_DVR_DEC_RESOURCE_LIST,*LPNET_DVR_DEC_RESOURCE_LIST;

typedef struct tagNET_DVR_DEC_APPLICANT_INFO
{
	DWORD dwSize;
	DWORD dwDecResource; /*申请的解码资源，以分辨率衡量，0-DCIF 1-CIF, 2-QCIF, 3-4CIF, 4-2CIF 5（保留）,
						 6-QVGA(320*240), 7-QQVGA(160*120), 16-VGA（640*480）, 17-UXGA（1600*1200）, 18-SVGA （800*600）,
						 19-HD720p（1280*720）,20-XVGA,  21-HD900p, 27-HD1080i, 28-2560*1920, 29-1600*304, 30-2048*1536, 
						 31-2448*2048,32-2448*1200,33-2448*800,34-XGA（1024*768），35-SXGA（1280*1024）,36-WD1(960*576/960*480),
	37-1080i,38-WXGA(1440*900),39-HD_F(1920*1080/1280*720),40-HD_H(1920*540/1280*360),41-HD_Q(960*540/630*360)*/
    DWORD  dwChannel; //智能通道号
	NET_DVR_IPADDR  struIP;   //申请者IP
	WORD  wPort;         //申请者端口号(智能分析仪通讯端口)
	BYTE  byRes[18];
}NET_DVR_DEC_APPLICANT_INFO,*LPNET_DVR_DEC_APPLICANT_INFO;

typedef struct tagNET_DVR_DEC_RESOURCE_INFO
{
	DWORD dwSize;
	DWORD dwSlotNum;  //槽位号，此参数做释放解码资源和登陆解码子系统校验用
    NET_DVR_IPADDR struIP; //解码子系统IP地址
	WORD  wPort;      //端口号
	BYTE  byRes1[2];
	DWORD dwDecChan;  //解码通道号
    BYTE  sUserName[NAME_LEN];	/* 解码子系统登陆帐号 */
    BYTE  sPassword[PASSWD_LEN];	/* 解码子系统登陆密码 */
    BYTE  byRes2[32];
}NET_DVR_DEC_RESOURCE_INFO,*LPNET_DVR_DEC_RESOURCE_INFO;

typedef struct tagNET_DVR_DEC_CHAN_COND
{
	DWORD dwSize;
	DWORD dwSlotNum; //槽位号,填申请解码资源时返回的槽位号
	DWORD dwDecChan; //解码通道号
	BYTE  byRes[16];
}NET_DVR_DEC_CHAN_COND,*LPNET_DVR_DEC_CHAN_COND;

typedef struct tagNET_DVR_DEC_YUV_CFG
{
	DWORD dwSize;
	BYTE  byEnable;     //关联使能，0-无关联，1-关联
	BYTE  byRes1[3];
	//byEnable = 1时以下参数有效
	DWORD dwYUVAddress[3]; //YUV输出地址
	WORD  wWidth;       //YUV输出宽
	WORD  wHeight;      //YUV输出高
	BYTE  byEnableAudio;  //使能音频，0-不启用，1-启用
	BYTE  byRes2[3];
	DWORD dwAudioAddr;  //音频输出地址
	BYTE  byRes3[16];
}NET_DVR_DEC_YUV_CFG,*LPNET_DVR_DEC_YUV_CFG;

typedef struct tagNET_DVR_INPUT_INFO
{
	DWORD		dwSize;
	BYTE		byChanType;		//接入类型，1-本地模拟量通道，2-本地开关量通道，3-485通道，4-网络通道
	BYTE		byRes1[3];
	DWORD		dwChanNo;		//通道号
	DWORD		dwSubChanNo;	//槽位号
	DWORD		dwVariableNo;	//变量编号
	BYTE		byRes2[60];
}NET_DVR_INPUT_INFO, *LPNET_DVR_INPUT_INFO;

typedef struct tagNET_DVR_ALARM_VARIABLE_CFG
{
    DWORD		dwSize; 
	WORD		wVariableIndex;		//变量编号，只能获取
	WORD		wVariableType;		//变量类型 1-模拟量 2-开关量，只能获取
	BYTE		sDescribe[NAME_LEN];//变量描述
	BYTE		byLimitLineType;	//报警限值配置类型，0-不支持报警限值配置，1-两限值配置（即上限、下限），2-四限值配置
	BYTE		byRes[31];			//保留
}NET_DVR_ALARM_VARIABLE_CFG, *LPNET_DVR_ALARM_VARIABLE_CFG;


//模拟量点号相关参数
typedef struct tagNET_DVR_ALARM_SENSOR_POINT_CFG
{
	int   		nMeasureHigh;			// 量程上限 外部值*1000传入 可以为负数
    int   		nMeasureLow;			// 量程下限 外部值*1000传入
	BYTE		byAlarmMode;			// 报警模式，五种，-HHHH、-HHHL、-HHLL、HLLL、-LLLL，
										// 即：1111（上上上上），1110（上上上下），1100（上上下下），1000(上下下下)，0000(下下下下)
	BYTE 		byRes1[3];
	int			nAlarmValue[4];			// 报警限
    DWORD  		dwOsdCfg;				// 模拟量字符叠加，按位表示0-15对应视频通道1-16
	DWORD		dwSensitive;			// 灵敏度范围10~1000。外部 float*1000。 灵敏度表示当实时值的变化超过灵敏度的范围时，则表示实时值发生了变化，否则认为没有发生变化。如：灵敏度为0.1，则表示前后检测的两个值之差大于0.1时，则认为数据发生变化，需要上传。如果为1，则表示变化超过1时上报。
	DWORD		dwIPChanOsd;			// 数字通道叠加模拟量字符，按位表示，0~31对应数字通道1-32
	BYTE		byRes[24];
}NET_DVR_ALARM_SENSOR_POINT_CFG,*LPNET_DVR_ALARM_SENSOR_POINT_CFG;

typedef struct tagNET_DVR_ALARM_SWITCH_POINT_CFG
{
	BYTE		byRes[64];
}NET_DVR_ALARM_SWITCH_POINT_CFG,*LPNET_DVR_ALARM_SWITCH_POINT_CFG;

typedef union tagNET_DVR_ALARM_POINT_PARAM_UNION
{
	BYTE	byLength[64]; //联合体长度为64
	NET_DVR_ALARM_SENSOR_POINT_CFG struSensor;	//模拟量相关参数
	NET_DVR_ALARM_SWITCH_POINT_CFG struSwitch;	//开关量相关参数
}NET_DVR_ALARM_POINT_PARAM_UNION,*LPNET_DVR_ALARM_POINT_PARAM_UNION;

//点号信息
typedef struct tagNET_DVR_ALARM_POINT_CFG
{
    DWORD		dwSize;
	DWORD		dwPointNo;			//点号
	BYTE		sPointDescribe[NAME_LEN];		//点号描述
	NET_DVR_ALARM_POINT_PARAM_UNION struPointParam; //当变量类型为模拟量时，使用结构体struSensor，当变量类型为开关量时，使用结构体struSwitch
	BYTE		byPointType;		//点号类型，1-模拟量，2-开关量
	BYTE		byRes[31];			//保留
}NET_DVR_ALARM_POINT_CFG, *LPNET_DVR_ALARM_POINT_CFG;

//历史数据查询
typedef struct _NET_DVR_SEARCH_CONDITION
{
	DWORD		dwSize;
	BYTE		byMajorType;	//查询方式，1-全部，2-按时间， 按类型，时间+类型
	BYTE		byMinorType;	//1-点号，2-通道+槽位+变量号
	BYTE		byRes1[2];
	NET_DVR_TIME		struStartTime;	//起始时间
	NET_DVR_TIME		struStopTime;	//结束时间
	BYTE		byChanType;		//通道类型，1-模拟量，2-开关量，3-485通道，0xff表示无效
	BYTE		byRes2[3];
	DWORD		dwChanNo;		//通道号，从1开始，0xffffffff表示无效
	DWORD		dwSubChanNo;	//槽位号，从1开始，0xffffffff表示无效
	DWORD		dwVariableNo;	//变量号，从1开始，0xffffffff表示无效
	DWORD		dwPointNo;	//点号，0xffffffff表示无效
	BYTE      	byRes3[32];		//保留
}NET_DVR_SEARCH_CONDITION, *LPNET_DVR_SEARCH_CONDITION;

typedef struct _NET_DVR_HISTORY_DATA
{
	DWORD		dwSize;
	NET_DVR_TIME		struTime;	//时间点
	BYTE		byChanType;		//通道类型，1-模拟量，2-开关量，3-485通道，0xff表示无效
	BYTE		byRes1[3];
	DWORD		dwChanNo;		//通道号，从1开始，0xffffffff表示无效
	DWORD		dwSubChanNo;	//槽位号，从1开始，0xffffffff表示无效
	DWORD		dwVariableNo;	//变量号，从1开始，0xffffffff表示无效
	DWORD		dwPointNo;		//点号，0xffffffff表示无效
	int			iData;			//历史数据
	BYTE		byRes2[32];
}NET_DVR_HISTORY_DATA, *LPNET_DVR_HISTORY_DATA;

typedef struct tagNET_DVR_ALARMHOST_ALARM_MODE_CFG
{
	DWORD		dwSize;
	BYTE	byDataUploadMode;	//1-按通道上传，2-按监测点上传
	BYTE	byRes[31];
}NET_DVR_ALARMHOST_ALARM_MODE_CFG,*LPNET_DVR_ALARMHOST_ALARM_MODE_CFG;


typedef struct tagNET_DVR_ALARMHOST_POINT_VALUE
{
	BYTE	byChanType;		//接入类型，1-本地模拟量通道，2-本地开关量通道，3-485通道，4-网络通道
	BYTE	byPointType;	//点类型，1-遥测（模拟量），2-遥信（开关量）
	BYTE	byRes1[2];		//保留
	DWORD 	dwChanNo;		//485通道号，0xffffffff表示无效，通道类型为1时：表示本地模拟量通道号，通道类型为2时表示本地开关量通道号，通道类型为3时表示485通道号。
	DWORD	dwSubChanNo;	//槽位号， 0xffffffff表示无效，通道类型为3时使用
	DWORD	dwVariableNo;	//变量编号，0xffffffff表示无效
	DWORD 	dwPointNo;		//104点号，0xffffffff表示无效
	int		iValue;			//监测点的值
	BYTE	byRes[16];
}NET_DVR_ALARMHOST_POINT_VALUE,*LPNET_DVR_ALARMHOST_POINT_VALUE;

typedef union tagNET_DVR_ALARMHOST_DATA_UNION
{
	BYTE	byLength[40];
	NET_DVR_ALARMHOST_POINT_VALUE struPointValue;	//监测点实时数据
}NET_DVR_ALARMHOST_DATA_UNION,*LPNET_DVR_ALARMHOST_DATA_UNION;

typedef struct tagNET_DVR_ALARMHOST_DATA_UPLOAD
{
	DWORD		dwSize;
	BYTE		byDataType;		//数据类型，1-监测点实时数据上传
	BYTE		byRes1[3];
	NET_DVR_ALARMHOST_DATA_UNION struAlarmData;
	BYTE		byRes2[32];
}NET_DVR_ALARMHOST_DATA_UPLOAD, *LPNET_DVR_ALARMHOST_DATA_UPLOAD;

typedef struct  tagNET_DVR_INPUTVOLUME
{
	DWORD  dwSize;     /*结构长度*/
	BYTE   byAudioInputChan;//音频输入通道号 
	BYTE   byRes[63];		// 保留字节
}NET_DVR_INPUTVOLUME, *LPNET_DVR_INPUTVOLUME;

//IPC5.0.5
typedef struct tagNET_DVR_AUDIOOUT_VOLUME
{
	DWORD  dwSize;
	BYTE byAudioOutVolume;// 输出音量等级：归一化为0-100；
    BYTE byRes[63];
}NET_DVR_AUDIOOUT_VOLUME,*LPNET_DVR_AUDIOOUT_VOLUME;

typedef struct tagNET_DVR_FUZZY_UPGRADE
{
	DWORD  dwSize;
	char  sUpgradeInfo[MAX_UPGRADE_INFO_LEN];
    BYTE  byRes[64];
}NET_DVR_FUZZY_UPGRADE,*LPNET_DVR_FUZZY_UPGRADE;

typedef struct tagNET_DVR_RS485_WORK_MODE
{
	DWORD dwSize;
	BYTE  byWorkMode; //工作模式，0-控制台，1-私有透明通道，2-透明通道
	BYTE  byRes[31];
}NET_DVR_RS485_WORK_MODE, *LPNET_DVR_RS485_WORK_MODE;

typedef struct tagNET_DVR_TRANSPARENT_CLIENT_SINGLE
{
	BYTE byEnable; //使能透明通道，0-不使能，1-使能
	BYTE byRes1[3];
	NET_DVR_IPADDR struIP; //远程设备IP地址
	WORD wPort; //远程设备端口
	BYTE byRes2[18];	
}NET_DVR_TRANSPARENT_CLIENT_SINGLE, *LPNET_DVR_TRANSPARENT_CLIENT_SINGLE;

typedef struct tagNET_DVR_TRANSPARENT_SERVER_SINGLE
{
	BYTE byEnable; //使能透明通道，0-不使能，1-使能
	BYTE byRes1[3];
	NET_DVR_IPADDR struIP; //允许接入的远程设备IP	
	BYTE byRes2[16];	
}NET_DVR_TRANSPARENT_SERVER_SINGLE, *LPNET_DVR_TRANSPARENT_SERVER_SINGLE;

typedef struct tagNET_DVR_TRANSPARENT_CLIENT_MODE
{
	NET_DVR_TRANSPARENT_CLIENT_SINGLE struClientSingle[MAX_TRANSPARENT_CHAN_NUM];
	BYTE byRes[320];
}NET_DVR_TRANSPARENT_CLIENT_MODE, *LPNET_DVR_TRANSPARENT_CLIENT_MODE;

typedef struct tagNET_DVR_TRANSPARENT_SERVER_MODE
{
	WORD wPort; //本地监听的端口号，和RS485口一一对应
	BYTE byRes1[2];
	NET_DVR_TRANSPARENT_SERVER_SINGLE struServerSingle[MAX_TRANSPARENT_ACCESS_NUM];
	BYTE byRes2[332];	
}NET_DVR_TRANSPARENT_SERVER_MODE, *LPNET_DVR_TRANSPARENT_SERVER_MODE;

typedef union tagNET_DVR_TRANSPARENT_CHAN_WORK_MODE_UNION
{
	BYTE byRes[512];
	NET_DVR_TRANSPARENT_CLIENT_MODE struClientMode;  //客户端模式参数
	NET_DVR_TRANSPARENT_SERVER_MODE struServerMode; //服务器模式参数
}NET_DVR_TRANSPARENT_CHAN_WORK_MODE_UNION, *LPNET_DVR_TRANSPARENT_CHAN_WORK_MODE_UNION;

typedef struct tagNET_DVR_TRANSPARENT_CHAN_CFG
{
	DWORD dwSize;	
	BYTE  byWorkMode; //工作模式，1-客户端模式，2-服务器模式
	BYTE  byRes[3];
	NET_DVR_TRANSPARENT_CHAN_WORK_MODE_UNION struTransparentPara;
}NET_DVR_TRANSPARENT_CHAN_CFG, *LPNET_DVR_TRANSPARENT_CHAN_CFG;

typedef struct tagNET_DVR_NAKED_DATA_INFO
{
	char   sSocketIP[128];
	WORD   wSocktPort;
	BYTE   byRes[258];
}NET_DVR_NAKED_DATA_INFO, *LPNET_DVR_NAKED_DATA_INFO;

typedef enum tagNAKED_DATA_TYPE
{
	NAKED_DATA_TYPE_NOT_DEFINED = 0, //未定义
	NAKED_DATA_TYPE_POS_INFO    //接收的是Pos信息
}NAKED_DATA_TYPE;


typedef struct tagNET_DVR_NAKED_DATA_PARAM
{
	WORD  wPort;           //IP端口号，对于Pos信息接收，该值为0，则使用默认端口7050
	BYTE byRes[130];      //保留字节
}NET_DVR_NAKED_DATA_PARAM, *LPNET_DVR_NAKED_DATA_PARAM;

#define UPLOAD_POS_INFO     1001  //上传Pos信息

typedef struct tagNET_DVR_POS_INFO
{
	NET_DVR_STRUCTHEAD 	struVerHead;  //版本头
    DWORD dwChannelNum;          //通道号
	BYTE  byRes[60]; 
}NET_DVR_POS_INFO, *LPNET_DVR_POS_INFO;


#define MAX_IGNORE_STRING_NUM		4
#define FILTERRULE_NUM              4
#define MAX_POS_FILTER_DATA_LEN     32

typedef struct tagNET_DVR_POS_OSD_REGION
{
    WORD     wStartX;               /*overlay osd start x*/
    WORD     wStartY;                   /*overlay osd start y*/
    WORD     wRectWidth;                /*overlay osd start w*/  
    WORD     wRectHeight;               /*overlay osd start h*/
}NET_DVR_POS_OSD_REGION, *LPNET_DVR_POS_OSD_REGION;

typedef struct 
{
	DWORD dwDelayTime;                /*delay time(5-3600s)*/
    BYTE  byPrevOsd;                   /*overlay osd on preview*/
	BYTE  byRes1[3];                    /*preserve*/
    NET_DVR_POS_OSD_REGION  struOsdPosInfo;          /*overlay osd rect info*/
    BYTE  byRes[64];                   /*preserve*/
}NET_DVR_POS_ACTION, *LPNET_DVR_POS_ACTION;

typedef struct
{
    BYTE sData[MAX_POS_FILTER_DATA_LEN];/*交易开始标志，目前最大为32，只有anyCharacter为否时才生效*/
	BYTE byAnyCharacter;			/*交易开始标志是否为任意字符，0->否，1->是*/
	BYTE byHex;						/*界面上输入的交易开始标志是否为16进制表示，0->否，1->是*/
	BYTE byRes[30];					/*保留*/
}NET_DVR_GENERIC_START, *LPNET_DVR_GENERIC_START;

typedef struct
{
	BYTE  sData[MAX_POS_FILTER_DATA_LEN];/*交易结束标志，目前最大为32*/
	DWORD dwMoreLine;/*匹配到交易结束后还要继续查找多少行的数据*/
	BYTE  byHex;/*界面上输入的交易结束标志是否为16进制表示，0->否，1->是*/
	BYTE  byRes[31];
} NET_DVR_GENERIC_END, *LPNET_DVR_GENERIC_END;

typedef struct
{
	BYTE  sData[MAX_POS_FILTER_DATA_LEN];/*数据标志，目前最大为32*/
	BYTE  byHex;/*界面上输入的数据标志是否为16进制表示，0->否，1->是*/
	BYTE  byRes[31];
}NET_DVR_GENERIC_DATA_CFG, *LPNET_DVR_GENERIC_DATA_CFG;

typedef struct
{
    BYTE sData[MAX_POS_FILTER_DATA_LEN];/*忽略的字符，目前最大为32*/
    BYTE byRes[31];
}NET_DVR_IGNORE_STRING, *LPNET_DVR_IGNORE_STRING;

typedef struct
{
	BYTE  byCaseSensitive;/*是否区分大小写，0->不区分，1->区分*/
	BYTE  byRes1[3];   
	DWORD dwTimeout; /*叠加消失延时时间,单位:秒*/
	NET_DVR_GENERIC_START struTransactionStart;/*交易开始*/
	NET_DVR_GENERIC_END struTransactionEnd;/*交易结束*/
	NET_DVR_GENERIC_DATA_CFG struLineDeli;/*行间隔符*/
	NET_DVR_IGNORE_STRING struIgnoreString[MAX_IGNORE_STRING_NUM];/*忽略字符串，目前为4个*/
    BYTE byRes[40];    //保留
}NET_DVR_POS_GENERIC, *LPNET_DVR_GENERIC;

typedef struct
{
	DWORD  dwAddress;/*AVE协议中的地址*/
	DWORD  dwTimeout; /*叠加消失延时时间,单位:秒*/
	BYTE   byRes[492];
}NET_DVR_POS_AVE, *LPNET_DVR_AVE;

typedef  union _NET_DVR_POS_PROTOCOL_UNION
{
    BYTE byLenth[500];   //用于表示联合体长度，无实际意义
	NET_DVR_POS_GENERIC struGeneric;
	NET_DVR_POS_AVE struAve;
}NET_DVR_POS_PROTOCOL_UNION,*LPNET_DVR_POS_PROTOCOL_UNION;

typedef struct
{
	BYTE byEnable;    //规则使能
	BYTE byRes1[3];   //保留
	BYTE  sPosName[NAME_LEN];/*POS 名称，目前最大为32个字符*/
	DWORD dwProtocolType;/*协议类型，1->generic text协议, 2->AVE VSI-ADD	3->AVE Vnet*/
	NET_DVR_POS_PROTOCOL_UNION struPosProtocol;   //POS协议
	NET_DVR_POS_ACTION struAction;/*处理方式*/
	BYTE byRes[64];
}NET_DVR_FILTER_CONFIG, *LPNET_DVR_FILTER_CONFIG;

typedef struct
{
	NET_DVR_STRUCTHEAD  struVerHead;  //版本头
	DWORD dwMaxRuleNum;     //最多支持的可配规则数(只读)
	DWORD dwMaxGroupNum;    //最大支持的组号(只读)
    NET_DVR_FILTER_CONFIG struFilterCfg[FILTERRULE_NUM];  //过滤规则 
	BYTE  byRes[128];    //保留
}NET_DVR_POS_FILTER_CFG, *LPNET_DVR_POS_FILTER_CFG;

typedef struct
{
    WORD  wNetPort;  /*device net port*/
    BYTE  byRes[2];
}NET_DVR_NET_RECEIVE, *LPNET_DVR_NET_RECEIVE;

typedef struct
{
    NET_DVR_IPADDR  struNetIp;      /*device IP*/
} NET_DVR_NET_MONITOR, *LPNET_DVR_NET_MONITOR;

typedef struct
{
    NET_DVR_NET_RECEIVE struNetReceiveSet;/*网络接受模式*/
    NET_DVR_NET_MONITOR struNetMonitorSet;/*网络监听模式*/
    NET_DVR_SINGLE_RS232 struSingleRS232Set;/*串口方式*/
} NET_DVR_POS_CONNECTMODE, *LPNET_DVR_POS_CONNECTMODE;

//DVR与POS连接方式配置结构体
typedef struct
{
    NET_DVR_STRUCTHEAD  struVerHead;  //版本头
    DWORD  dwConnectMode;/*连接模式:0->网络监听,1->网络接受,2->串口接收*/
    NET_DVR_POS_CONNECTMODE struPosConnMode;/*连接模式配置*/
    BYTE  sPosName[NAME_LEN]; //pos名称
    BYTE  byPosEnable;     //POS使能
    BYTE  byRes[127];
} NET_DVR_CONNECT_POS_CFG, *LPNET_DVR_CONNECT_POS_CFG;

typedef struct  
{
    NET_DVR_STRUCTHEAD  struVerHead;  //版本头
    DWORD  dwFilterID;       //POS过滤规则ID 
    BYTE  byRes[128];      //保留
}NET_DVR_CHAN_FILTER_CFG, *LPNET_DVR_CHAN_FILTER_CFG; 

#define		MAX_LAN_ENCODE_LEN		32	//语言编码格式最大长度
typedef struct	tagNET_DVR_DEVICE_LAN_ENCODE
{	
	DWORD		dwSize;		
	BYTE		byLanEncode[MAX_LAN_ENCODE_LEN];	//设备语言编码格式
	BYTE		byRes[28];
}NET_DVR_DEVICE_LAN_ENCODE, *LPNET_DVR_DEVICE_LAN_ENCODE;

typedef struct tagNET_DVR_SCENECHANGE_DETECTION
{
	DWORD	dwSize;
	BYTE	byEnable; //使能，是否开启 0~不开启,1~开启
	BYTE	bySensitiveLevel;// 1-100，默认50，灵敏度越高，越容易报警
	BYTE	byRes1[2];
	NET_DVR_SCHEDTIME struAlarmSched[MAX_DAYS][MAX_TIMESEGMENT_V30];
	NET_DVR_HANDLEEXCEPTION_V40 struHandleException;  //异常处理方式
	DWORD	dwMaxRelRecordChanNum ;  //报警触发的录象通道 数（只读）最大支持数量
	DWORD	dwRelRecordChanNum ;     //报警触发的录象通道 数 实际支持的数量
	DWORD	dwRelRecordChan[MAX_CHANNUM_V30];//触发录像通道
	//报警触发的录象通道（四字节的通道号，初始值是 0xffffffff）
	BYTE    byRes2[128];
}NET_DVR_SCENECHANGE_DETECTION,*LPNET_DVR_SCENECHANGE_DETECTION;

typedef struct tagNET_DVR_SCENECHANGE_DETECTION_RESULT
{
	DWORD            dwSize;     	 // 结构大小
	NET_VCA_DEV_INFO struDevInfo;    //前端设备信息
	BYTE             byRes[128];      // 保留字节
}NET_DVR_SCENECHANGE_DETECTION_RESULT,*LPNET_DVR_SCENECHANGE_DETECTION_RESULT;
typedef enum
{
		PREVIEW_MOD = 0,
		ALARM_MOD,
		PLAYBACK_MOD,
		MAX_TYPE
}MODULE_TYPE;



typedef struct tagNET_DVR_STREAM_SRC_CFG
{
	DWORD dwSize;
	NET_DVR_STREAM_INFO struStreamID; //流信息
	NET_DVR_STREAM_SRC_INFO struStreamSrcInfo; //流源信息
}NET_DVR_STREAM_SRC_CFG,*LPNET_DVR_STREAM_SRC_CFG;

typedef struct tagNET_DVR_ENCODEINFO
{
	BYTE  byFormatType; //封装类型，1-裸流，2-RTP封装，3-PS封装，4-TS封装，5-私有，6-FLV，7-ASF，8-3GP, 9-RTP+PS（国标：GB28181），0xff-无效
	BYTE  byVideoEncType;//视频编码类型，0-私有264，1-标准h264，2-标准mpeg4，7-M-JPEG，0xff-无效
	WORD  wWidth; //图像宽度
	WORD  wHeight; //图像高度
	BYTE  byRes1[2];
	DWORD dwVideoBitrate; 	//视频码率,单位Kbps
	DWORD dwVideoFrameRate;	//帧率，200起表示小于1帧/秒的状态，其余值表示实际帧率值,200-1/2,201-1/4,202-1/8,203-1/16
	BYTE  byAudioEncType;//音频编码类型，0-OggVorbis，1-G711_U，2-G711_A，5-MPEG2,6-G726，7-AAC,0xff-无效	
	BYTE  byRes2[15];
}NET_DVR_ENCODEINFO, *LPNET_DVR_ENCODEINFO;

typedef struct tagNET_DVR_ADDRESS
{
	NET_DVR_IPADDR struIP; //IP地址
	WORD wPort;	//端口号
	BYTE byRes[2];
}NET_DVR_ADDRESS,*LPNET_DVR_ADDRESS;

typedef struct tagNET_DVR_TRANSSTATUS
{
	DWORD dwSize;
	NET_DVR_STREAM_INFO struStreamInfo;//流ID、转码通道信息	
	BYTE  byMode;//转码模式，1-主动转码，2-被动转码
	BYTE  byLinkNums;//连接数
	BYTE  byPassiveTransMode; //被动转码模式，0-无效，1-实时流，2-文件流
	BYTE  byRes;
	NET_DVR_ADDRESS struDstIPInfo[MAX_LINK];//目标转码ip地址
	BYTE  byTransResource;//所使用的转码资源数，按D1计算
	BYTE  byRes1[15];
	NET_DVR_ENCODEINFO struSrcEncodeInfo;//源编码信息
	NET_DVR_ENCODEINFO struDstEncodeInfo[MAX_LINK /*6*/];//目标编码信息
	BYTE  byRes2[36];
}NET_DVR_TRANSSTATUS, *LPNET_DVR_TRANSSTATUS;

typedef struct tagNET_DVR_TRANSDEVICE_STATUS
{
	DWORD dwSize;
	DWORD dwTotalResource;//全部转码资源，以D1为单位计算
	DWORD dwIdleResource;//剩余转码资源，以D1为单位计算
	BYTE  byCpuLoad;//CPU利用率
	BYTE  byRes[67];
}NET_DVR_TRANSDEVICE_STATUS, *LPNET_DVR_TRANSDEVICE_STATUS;

typedef struct tagNET_DVR_DEV_WORK_MODE
{
	DWORD dwSize;
	BYTE  byWorkMode; //1-通道模式，2-流ID模式
	BYTE  byDisplayMode; //0-普通，1-畅显
	BYTE  byRes[62];
}NET_DVR_DEV_WORK_MODE,*LPNET_DVR_DEV_WORK_MODE;


typedef struct tagNET_DVR_PASSIVETRANSINFO 
{
	DWORD dwSize;
    BYTE byStreamType;// 码流类型，0-主码流，1-子码流
	BYTE byLinkMode;// 0：TCP方式,1：UDP方式（保留）
	BYTE byPassiveTransMode; //被动转码模式，1-实时流，2-文件流
	BYTE byRes1[5];	
	BYTE byDataType;//缓冲区类型，1-SDP，2-码流头
	BYTE byRes2;
	WORD wDataLength;//数据长度
    char *pBuffer;//缓冲区
    BYTE byRes3[32]; // 保留
}NET_DVR_PASSIVETRANSINFO, *LPNET_DVR_PASSIVETRANSINFO;

typedef struct tagNET_DVR_BASEMAP_CONTROL_CFG
{
	DWORD dwSize;
	BYTE  byEnable;        //是否显示，1-显示，0-隐藏	
	BYTE  byBaseMapType;    //底图类型，1-图片底图，2-超高清输入底图
	BYTE  byRes1[2];
	DWORD dwBaseMapNo;     //底图号；底图类型为1时，此参数为图片序号，底图类型为2时此参数为超高清输入子系统输入口号（1字节矩阵号+1字节子板号+1字节输入口号+1字节保留）
	BYTE  byRes2[64];
}NET_DVR_BASEMAP_CONTROL_CFG,*LPNET_DVR_BASEMAP_CONTROL_CFG;

typedef struct tagNET_DVR_VIRTUAL_SCREEN_CFG
{
	DWORD dwSize;
	DWORD dwResolution; //分辨率，MAKE_RESOLUTION宏定义的值，从电视墙能力获取支持的分辨率值
	BYTE  byRes2[64];
}NET_DVR_VIRTUAL_SCREEN_CFG, *LPNET_DVR_VIRTUAL_SCREEN_CFG;

typedef struct tagNET_DVR_RECTCFG_EX 
{
    DWORD dwXCoordinate; /*矩形左上角起始点X坐标*/
    DWORD dwYCoordinate; /*矩形左上角Y坐标*/
    DWORD dwWidth;       /*矩形宽度*/
    DWORD dwHeight;      /*矩形高度*/
    BYTE  byRes[4];
}NET_DVR_RECTCFG_EX, *LPNET_DVR_RECTCFG_EX;

typedef struct tagNET_DVR_BASEMAP_WINCFG
{
	DWORD dwSize;
	BYTE  byEnable;
	BYTE  byRes1[7];
	NET_DVR_RECTCFG_EX struWinPosition;//目的窗口(相对显示墙),底图窗口的起始坐标和大小必须是基准坐标的整数倍
	BYTE  byRes2[64];
}NET_DVR_BASEMAP_WINCFG, *LPNET_DVR_BASEMAP_WINCFG;

typedef struct tagNET_DVR_BASEMAP_PIC_INFO
{
	DWORD  dwSize;
	BYTE   sPicName[NAME_LEN];//图片名称
	BYTE   byUsed; //是否已存在，0-不存在，1-存在
	BYTE   byRes[31];
}NET_DVR_BASEMAP_PIC_INFO,*LPNET_DVR_BASEMAP_PIC_INFO;

typedef struct tagNET_DVR_MATRIX_LOGO_INFO
{
	DWORD  dwSize;
	DWORD  dwLogoSize;//LOGO大小，包括BMP的文件头，图片大小超限，限100K，高和宽须是32的倍数
	BYTE   byRes[32];
}NET_DVR_MATRIX_LOGO_INFO,*LPNET_DVR_MATRIX_LOGO_INFO;

typedef struct tagNET_DVR_MATRIX_LOGO_CFG
{
	DWORD  dwSize;
	BYTE   byExist;  //logo是否存在，0-不存在，1-存在（此参数只能获取）
	BYTE   byRes1[3];
	DWORD  dwLogoSize;//LOGO大小，包括BMP的文件头(此参数只能获取)
	BYTE   byLogoName[NAME_LEN];  //logo名称
	BYTE   byRes[32];
}NET_DVR_MATRIX_LOGO_CFG,*LPNET_DVR_MATRIX_LOGO_CFG;

typedef struct tagNET_DVR_WIN_LOGO_CFG
{
	DWORD  dwSize;
	DWORD  dwLogoNo; //logo号
    BYTE   byEnable; //logo是否显示，1-显示，0-隐藏
	BYTE   byRes1[3];	
    DWORD  dwCoordinateX;	//图片显示区域X坐标
    DWORD  dwCoordinateY;	//图片显示区域Y坐标    
    BYTE   byFlash;  //是否闪烁1-闪烁，0-不闪烁
    BYTE   byTranslucent; //是否半透明1-半透明，0-不半透明
    BYTE   byRes2[34];				//保留    
}NET_DVR_WIN_LOGO_CFG,*LPNET_DVR_WIN_LOGO_CFG;	


typedef struct tagNET_DVR_BIG_SCREEN_AUDIO_CFG
{
	DWORD dwSize;
	DWORD dwWinIndex; //窗口号，从1开始，0表示底图
	BYTE  byEnable; //是否打开音频，1-打开音频，0-关闭音频
	BYTE  byRes[31];
}NET_DVR_BIG_SCREEN_AUDIO_CFG, *LPNET_DVR_BIG_SCREEN_AUDIO_CFG;

typedef struct tagNET_DVR_WIN_ZOOM_STATUS
{
    DWORD dwSize;
    BYTE  byZoomStatus;  //0-正常状态，1-放大状态
    BYTE  byRes1[3];
    NET_DVR_POINT_FRAME struPointFrame; //放大区域，当byZoomStatus为1时有效
    BYTE  byRes2[32];
}NET_DVR_WIN_ZOOM_STATUS,NET_DVR_WIN_ZOOM_STATUS;
/*******************************IPC5.1.4 恢复跟踪初始位 begin********************/
typedef struct tagNET_DVR_RESUME_INITRACKPOS_CFG
{
    DWORD           dwSize;     	 // 结构大小
    DWORD           dwChannel;;     // 通道号
    BYTE            byRes[16];      // 保留字节
}NET_DVR_RESUME_INITRACKPOS_CFG,*LPNET_DVR_RESUME_INITRACKPOS_CFG;
/*******************************IPC5.1.4  end *********************************/

typedef  struct tagNet_DVR_TEST_SELFCHECK_RESULT   
{
    DWORD   dwSize;     
    DWORD   dwChannel;      //通道号            
    BYTE    bySelfCheckStatus;   //自检状态值 0-未开始，1-成功，2-失败，3-自检中
    BYTE    byRes[23];   //保留字节
}NET_DVR_TEST_SELFCHECK_RESULT, *LPNET_DVR_TEST_SELECHECK_RESULT;

#define  MAX_TEST_COMMAND_NUM 32 
typedef struct  tagNET_DVR_TEST_COMMAND
{
    DWORD   dwSize;     
    DWORD   dwChannel;       //通道号
    BYTE    byTestCommand[MAX_TEST_COMMAND_NUM]; 
    //0-表示不开启测试， 1-表示开启测试
    //数组下标0开启老化测试程序                      
    //数组下标1红外灯进入测试模式
    BYTE    byRes[20];       //保留字节
}NET_DVR_TEST_COMMAND,*LPNET_DVR_TEST_COMMAND;

#define MAX_DEVMODULE_NUM 8
typedef struct tagNET_DVR_TEST_DEVMODULE_CFG
{
    DWORD   dwSize;
    DWORD   dwChannel;      //通道号
    BYTE    byDevFanModuleType[MAX_DEVMODULE_NUM]; //测试的设备类型
    // 0-不开启测试,1-开启测试
    // bit0-测试风扇1
    // bit1-测试风扇2
    BYTE    byDevHeaterModuleType[MAX_DEVMODULE_NUM]; //测试的设备类型
    // 0-不开启测试,1-开启测试
    // bit0-测试加热器1
    // bit1-测试加热器2
    BYTE    byRes[22];      //保留字节
}NET_DVR_TEST_DEVMODULE_CFG, *LPNET_DVR_TEST_DEVMODULE_CFG;

//SDI矩阵1.0
#define  MATRIX_MAX_OUTPUT_NUM      256              //矩阵最大输出通道个数
typedef struct tagNET_DVR_MATRIX_BASE_CFG
{
    DWORD dwSize; 
    DWORD dwValidInputNum;     //有效的输入通道数
    DWORD dwValidOutputNum;    //有效的输出通道数
    BYTE  byRes[64]; 
}NET_DVR_MATRIX_BASE_CFG, *LPNET_DVR_MATRIX_BASE_CFG;

typedef struct tagNET_DVR_MATRIX_SWITCH_INFO
{
    DWORD   dwSize; 
    DWORD   dwInputChan;        //输入通道号，为0表示取消和指定输出的关联关系
    DWORD   dwOutputChan;       //要切换到的输出通道号,0xffffffff表示切换到所有输出
    BYTE    byRes[32]; 
}NET_DVR_MATRIX_SWITCH_INFO, *LPNET_DVR_MATRIX_SWITCH_INFO;

typedef struct tagNET_DVR_IO_RELATION_INFO
{
    DWORD   dwSize; 
    DWORD   dwIORelation[MATRIX_MAX_OUTPUT_NUM];  //输出通道关联的输入通道, dwIORelation[i] = j表示输出通道(i + 1)和输入通道j关联,
                                                       //dwIORelation[i] = 0表示输出通道i + 1未关联输入通道                                                                
    BYTE    byRes[256]; 
}NET_DVR_IO_RELATION_INFO, *LPNET_DVR_IO_RELATION_INFO;



/**************************************终端出入口外接设备配置 Begin 2013-11-19***************************************/
//终端出入口外接设备配置 (批量配置) 2013-11-19
//批量接口配置
typedef struct tagNET_DVR_EXTERNAL_DEVCOND
{
	DWORD  dwSize;
	BYTE   byExternalDevTpye;//0-其他(保留)，1-远距离读头设备，2-出入口控制机，3-led屏  0xff-全部信息（长连接获取时使用）
	BYTE   byRelativeIndex;//0-其他(保留)，索引(相对于接入类型) 范围 1~8 Led的相对索引范围是（1～255）   0xff-全部信息（长连接获取时使用）
//	BYTE   byLaneID;// 逻辑车道号    
	BYTE   byRes[30];
}NET_DVR_EXTERNAL_DEVCOND,*LPNET_DVR_EXTERNAL_DEVCOND;

typedef struct tagNET_DVR_EXTERNAL_DEVCFG
{
	DWORD         dwSize;
	BYTE          byExternalDevTpye;//0-其他，1-远距离读头设备，2-出入口控制机，3-led屏 
	BYTE          byRes2[3];
	char          sDevName[MAX_DEVNAME_LEN];
	union
	{
		BYTE	byUnionLen[656];
		struct
		{
			NET_DVR_IPADDR  struDevIP;//DEV IP地址 144
			WORD     wDevPort;//设备端口
			BYTE     byRes[510];
		}struRrReader;//远距离读头设备
		struct
		{
			BYTE byRs485No; //RS485编号(外接设备类型一样，该编号可以重复；类型不一样，该编号互斥)
			BYTE byDevCtrlCode;//拨码地址，用于区分设备(1-255)
			BYTE byAutoIssuedData;//是否自动下发卡片数据 0-不自动下发，1-自动下发
			BYTE byOfflineDetEnable;//离线检测 0-关闭，1-开启
			BYTE byDetCycle;//检测周期（0～60 单位 s）
			BYTE byRes[651];
		}struGateway;//出入口控制机
		struct
		{
			BYTE byExternalMode;//0-RS485,1-网络
			BYTE byRes[3];
			NET_DVR_IPADDR  struDevIP;//DEV IP地址 144 (在byExternalMode == 1 时生效)
			WORD wDevPort;//设备端口(在byExternalMode == 1 时生效)
			BYTE byRs485No; //RS485编号(外接设备类型一样，该编号可以重复；类型不一样，该编号互斥)
			BYTE byDevCtrlCode;//拨码地址，用于区分设备(1-255)
            //led屏通过控制卡控制显示的，不同的控制卡类型支持的显示方式不同
			BYTE byCtrlCardType;//控制卡类型 0-保留(无效值) 1- EQ2013
			BYTE byLedScreenType;//屏类型 0-单色屏 1-双色屏
			BYTE byLedScreenUse;//屏用途0-其它 1-区位屏 2-提示屏 3-收费屏
            BYTE byLedDisplayMode;//屏幕字体显示方式: 1 "立即显示",	2 "左移" ,3 "右移" ,4 "上移", 	5 "下移"
            char sLedCustomInfo[MAX_LED_INFO];//屏幕字体显示信息
			//led屏是由控制卡控制的，led屏可以根据项目实际使用更换大小，此时需要终端通知控制卡目前使用的屏宽和屏高
			DWORD dwLedScreenH;//显示屏组成高度上需要的LED点数
			DWORD dwLedScreenW;//显示屏组成宽度上需要的LED点数
			BYTE byRes1[236];
		}struLed;//led屏
	}uExternalDevInfo; //由byExternalMode 值来决定哪个有效
	BYTE byRes[128];
}NET_DVR_EXTERNAL_DEVCFG, *LPNET_DVR_EXTERNAL_DEVCFG;

//长连接获取配置
typedef struct tagNET_DVR_EXTERNAL_DEVSTATUS//远距离读头设备
{
	DWORD  dwSize;
    char   sDevName[MAX_DEVNAME_LEN];//设备名称
    BYTE   byExternalDevTpye;//0-其他(保留)，1-远距离读头设备，2-出入口控制机，3-led屏  0xff-全部信息（长连接获取时使用）
	BYTE   byRelativeIndex;//0-其他(保留)，相对索引(相对于接入类型能) 范围 1~8  0xff-全部信息（长连接获取时使用）
	BYTE   byOnline;//0-不在线，1-在线
	BYTE   byRes[125];
}NET_DVR_EXTERNAL_DEVSTATUS,*LPNET_DVR_EXTERNAL_DEVSTATUS;

//终端出入口检测配置
typedef struct tagNET_DVR_ENTRANCEDET_CFG
{
	DWORD   dwSize;		//结构长度
    //离线检测开启时，如果检测到设备在线，则由终端匹配卡片信息，并发送道闸控制指令给出入口控制机；否则由出入口控制机自身匹配控制道闸
	BYTE   byOfflineDetEnable;//离线检测 0-关闭，1-开启
	BYTE   byDetCycle;//检测周期（0～60 单位 s）
	BYTE   byDevCtrlCode;//出入口控制机拨码地址，用于区分设备(1-255)
	BYTE   byRes[61];
}NET_DVR_ENTRANCEDET_CFG,*LPNET_DVR_ENTRANCEDET_CFG;

//终端出入口控制(控制接口 下发卡片信息)
typedef struct tagNET_DVR_ENTRANCEDEV_COMMAND
{
	DWORD  dwSize; //结构长度
	BYTE   byDevCtrlCode;//出入口控制机拨码地址，用于区分设备(1-255)
	BYTE   byManualIssuedData;//手动数据下发 0-关闭，1-开启 
	BYTE   byRes[62];
}NET_DVR_ENTRANCEDEV_COMMAND,*LPNET_DVR_ENTRANCEDEV_COMMAND;

//终端出入口控制(控制接口 清空下发卡片信息)
typedef struct tagNET_DVR_ENISSUED_DATADEL
{
	DWORD   dwSize; //结构长度
	BYTE   byDevCtrlCode;//出入口控制机拨码地址，用于区分设备(1-255)
	BYTE   byRes[27];
}NET_DVR_ENISSUED_DATADEL,*LPNET_DVR_ENISSUED_DATADEL;

//出入口过车收费明细（监听方式）
typedef  struct  _tagNET_ITS_PASSVEHICLE_COST_ITEM
{
    DWORD   dwSize;		//结构长度
	DWORD   dwPassVehicleID; //过车序号与出入口数据的过车序号相关联
	BYTE    byIntime[MAX_TIME_LEN]; //入场时间格式为yyyymmddhh24missfff
	BYTE    byOuttime[MAX_TIME_LEN]; //出场时间格式为yyyymmddhh24missfff
	BYTE    byCardNo[MAX_CARD_LEN];   //卡号
	BYTE    byPlateInfo[MAX_LICENSE_LEN]; //车牌号码
	float   fPayCost;       //收费金额(单位元)
	BYTE    byOperatorName[MAX_OPERATORNAME_LEN]; //操作人员名称
	BYTE    byVehicleType; //车辆类型  0-小型车 2 大型车
	BYTE    byRes1[3]; //预留字段1
	DWORD   dwPayRuleID; // 收费规则流水号
	DWORD   dwFreeRuleID; // 减免规则流水号
	BYTE    byRes2[256]; // 预留字段2
}NET_ITS_PASSVEHICLE_COST_ITEM, *LPNET_ITS_PASSVEHICLE_COST_ITEM;

//出入口交接班数据（监听方式）
typedef struct  _tagNET_ITS_HANDOVER_INFO
{
    DWORD   dwSize;		//结构长度
	BYTE    byOperatorName[MAX_OPERATORNAME_LEN]; //操作人员名称
	BYTE    byOperatorCard[MAX_CARD_LEN]; //操作人员卡号
	BYTE    byStartTime[MAX_TIME_LEN];//上班时间格式形如yyyymmddhh24miss
	BYTE    byEndTime[MAX_TIME_LEN]; //下班时间格式形如yyyymmddhh24miss
	float   fTotal_Pay;    //本次上班期间总的收费金额(单位元)
	DWORD   dwTotal_Records;   //本次上班期间总的过车收费的记录条数
	BYTE    byRes[64]; //预留
}NET_ITS_HANDOVER_INFO, *LPNET_ITS_HANDOVER_INFO;

/**************************************终端出入口外接设备配置 End 2013-11-19***************************************/

//2013-11-21 获取设备当前的温度和湿度
typedef struct tagNET_DVR_TEMP_HUMI
{ 
	DWORD    dwSize;            // 内容长度 && 版本（用于后期扩展）
	DWORD  	 dwChannel;         // 通道号，默认1
	int      iHumidity;         // 湿度，整数部分：val/1000，小数部分：val%1000
	int      iTemp;             // 温度，整数部分：val/1000，小数部分：val%100
	BYTE     byRes[8];          // 保留字节	
}NET_DVR_TEMP_HUMI, *LPNET_DVR_TEMP_HUMI;
typedef struct tagNET_DVR_MOBILE_CAPTUREPIC_CFG
{
	DWORD       dwSize;
	BYTE  byPreviewFpsAdjMode;   /* 预览帧率调节模式:0-不调节，标准帧率预览,1-标准低帧率预览,2-根据GPS速度进行帧率调节 */
	BYTE  bySelPeccType;           /* 是否选择违章类型 */	
    BYTE  byOptHabit;             /* 取证操作习惯, 0:长按取证;1:短按两次取证 */	
    BYTE  byEnablePeccRec;      /* 1: 使能违章录像抓取, 0: 禁止违章录像抓取 */
	BYTE  byPicSize;				/*0=CIF,1=QCIF,2=D1,3=UXGA(1600x1200), 4=SVGA(800x600), 5=HD720p(1280x720),6-VGA，7-XVGA，8-HD900p，9-HD1080，10-2560*1920，11-1600*304，12-2048*1536，13-2448*2048,14-2448*1200，15-2448*800，16-XGA(1024*768)，17-SXGA(1280*1024),18-WD1(960*576/960*480),19-1080i */
	BYTE  byPicQuality;			/* 图片质量系数 0-最好 1-较好 2-一般 */
	BYTE  byRes[62];
}NET_DVR_MOBILE_CAPTUREPIC_CFG,*LPNET_DVR_MOBILE_CAPTUREPIC_CFG;

/**********************************Ehome平台参数 begin 2013-10-9*********************************/
typedef struct tagNET_DVR_CMS_PARAM
{
	DWORD		dwSize;
	NET_DVR_IPADDR	struAddr;		// 平台服务器IP
	WORD   	wServerPort;   			// 平台服务器侦听端口，
	BYTE			bySeverProtocolType;	//平台协议类型 1-私有，2-Ehome
	BYTE   	byStatus;         	//设备注册到该平台的状态，1-未注册，2-已注册
	BYTE     sDeviceId[NAME_LEN/*32*/];    //设备ID
	char	sPassWord[PASSWD_LEN];
    BYTE   	byRes[240];      	// 保留字节
}NET_DVR_CMS_PARAM, *LPNET_DVR_CMS_PARAM;
/**********************************Ehome平台参数 end*********************************************/

typedef struct tagNET_DVR_MOBILE_PLATE_RECOGCFG
{
	DWORD       dwSize;
	BYTE  byDefaultCHN[MAX_CHJC_NUM]; /*设备运行省份的汉字简写  3 */ 
	BYTE  byTimeOsd;// 时间信息叠加 0 - 不叠加， 1- 叠加
	BYTE  byRecogResultOsd;//识别结果叠加  0 - 不叠加， 1- 叠加
	BYTE  byRecogHint;//识别成功提示 0 - 不提示， 1- 提示
	BYTE  byRecogDir;//识别方向 0: 正向, 1: 背向
	BYTE  byRecogEnv;//识别环境 0: 白天, 1: 晚上
	BYTE  byRecogPlateType;//0-小车牌识别，1-大车牌识别
	BYTE  byUploadPlate;//是否上传车牌 0 -不上传， 1-上传
	BYTE  byRes[62];
}NET_DVR_MOBILE_PLATE_RECOGCFG,*LPNET_DVR_MOBILE_PLATE_RECOGCFG;

typedef struct tagNET_DVR_MOBILE_RADAR_CFG
{	
	DWORD       dwSize;
    BYTE   byEnableRadar;   /* 0:不开启雷达  1:开启雷达 */	
    BYTE   byEnableAlarm;   /* 0:不开启报警  1:开启报警 */	
    WORD  wOverSpeed;    /* 范围为20~250 */	
    BYTE   bySpeedUnits;  /* 0:公里/小时   1:英里/小时 */	
    BYTE   bydirection;     /* 0:反向（雷达与车相向） 1:正向（雷达与车反向） */	
    BYTE   byMeasureMode;   /* 0:静态 (雷达状态)       1:动态 (雷达状态)*/	
    BYTE   byTargetType;    /* 0:最快(雷达测速车辆最快)  1:最近(雷达测速车辆最近)*/	
	BYTE   bySensitivity;  /* 灵敏度[0,100] */						  
	BYTE   byCaptureNum;   /* 抓拍张数[0,255] */  							  
	BYTE   byUploadPlate;  /*是否上传超速抓拍图片 0-不上传，1-上传*/	
	BYTE   byRes[61];
}NET_DVR_MOBILE_RADAR_CFG,*LPNET_DVR_MOBILE_RADAR_CFG;

typedef struct tagNET_DVR_MOBILE_LOCALPLATECHK_CFG
{
	DWORD       dwSize;
    BYTE  byCheck;  /* 稽查任务是否进行黑名单稽查 0-稽查，1-不稽查*/	
    BYTE  byCheckAlarm;/* 稽查成功报警 0-不报警，1-报警*/	
    BYTE  byCheckHint; /* 稽查成功提示 (软件提示) 0-不提示，1-提示*/	
    BYTE  byUploadBlackCar; /*是否上传黑车信息 0-不上传，1-上传*/
	BYTE  byRes[64];
}NET_DVR_MOBILE_LOCALPLATECHK_CFG,*LPNET_DVR_MOBILE_LOCALPLATECHK_CFG;

typedef struct tagNET_DVR_VEHICLE_CHECK
{
	DWORD dwSize;
	DWORD  dwChannel;//通道号0xff - 全部通道（默认是1,代表一个通道）
	NET_DVR_PLATE_INFO  struPlateInfo; //车牌信息
	WORD  wIllegalType; //违章类型采用国标定义 （参考附件）
	BYTE  byRes[2];
	char sIllegalTypeInfo[128];// 违规类型信息（128）
	NET_DVR_TIME_V30  struIllegalTime;//违规时间
	BYTE  byIllegalVehicleNum;//车辆违法次数
	BYTE  byRes1[3];
	char sCustomInfo[64];//自定义信息
	BYTE  byRes2[128]; // 保留字节
}NET_DVR_VEHICLE_CHECK,*LPNET_DVR_VEHICLE_CHECK;

typedef enum _LONG_CFG_SEND_DATA_TYPE_ENUM_
{
	ENUM_DVR_VEHICLE_CHECK = 1 //黑名单车辆数据稽查类型
}LONG_CFG_SEND_DATA_TYPE_ENUM;

//2013-11-25
typedef struct tagNET_DVR_WIPER_CONTINUEWORK_PARAM
{
	BYTE  byWorkTimeInterval;//工作时间间隔（单位：秒）[2s~60s]
	BYTE  byRes[3];
    DWORD dwContinueWorkTime;//持续工作时间（单位：秒）[2min~24h]界面显示按分钟单位
    BYTE  byRes1[8];
}NET_DVR_WIPER_CONTINUEWORK_PARAM,*LPNET_DVR_WIPER_CONTINUEWORK_PARAM;

typedef union tagNET_DVR_WIPERMODE_PARAM_UNION
{
	BYTE uLen[16];
	//当byWiperWorkMode = 1时生效
	NET_DVR_WIPER_CONTINUEWORK_PARAM struWiperContinueWorkParam; 
}NET_DVR_WIPERMODE_PARAM_UNION,*LPNET_DVR_WIPERMODE_PARAM_UNION;

typedef struct tagNET_DVR_WIPERINFO_CFG
{
    DWORD dwSize;
	//雨刷工作模式
	//0-单次模式，1-持续模式（针对配置结构NET_DVR_ROTATE_OPERATE_PARAM）
	BYTE  byWiperWorkMode;
    BYTE  byRes[23];
    NET_DVR_WIPERMODE_PARAM_UNION ustruWiperModeParam;
}NET_DVR_WIPERINFO_CFG,*LPNET_DVR_WIPERINFO_CFG;

//保存自动对焦参数 2013-10-26
typedef struct tagNET_DVR_AUTOFOCUS_TESTCFG
{ 
   	DWORD     dwSize;
    DWORD     dwChannel;			//通道号
	BYTE      byRes[24];            // 保留字节
}NET_DVR_AUTOFOCUS_TESTCFG,*LPNET_DVR_AUTOFOCUS_TESTCFG;

/*******************************LCD拼接屏 begin******************************************/
//////////////////////////显示参数 begin 2013-08-28////////////////////////////////
typedef struct tagNET_DVR_VIDEO_OUT_CFG
{	
	BYTE	byDisplayMode;		//显示模式，1-标准，2-冷色，3-暖色，0xff-自定义
	BYTE 	byBrightnessLevel; 	// 亮度值0-100
    BYTE	byContrastLevel; 	// 对比度0-100
    BYTE 	bySharpnessLevel; 	// 锐度0-100
    BYTE 	bySaturationLevel; 	// 饱和度0-100
	BYTE 	byHueLevel; 		// 色调0-100
	BYTE	byRes[6];			// 保留
}NET_DVR_VIDEO_OUT_CFG, *LPNET_DVR_VIDEO_OUT_CFG;
//色温
typedef struct tagNET_DVR_COLOR_TEMPERATURE_CFG
{	
	BYTE	byRed;				//红色， 0-100
	BYTE	byGreen;			//绿色， 0-100
	BYTE	byBlue;				//蓝色，0-100
	BYTE	byRedOffset;		//红色偏移，0-100
	BYTE	byGreenOffset;		//绿色偏移，0-100
	BYTE	byBlueOffset;		//蓝色偏移，0-100
	BYTE	byRes[6];		
}NET_DVR_COLOR_TEMPERATURE_CFG, *LPNET_DVR_COLOR_TEMPERATURE_CFG;

typedef struct tagNET_DVR_ADC_CFG
{	
	BYTE	byGainR;			//增益R， 0-100
	BYTE	byGainG;			//增益G，0-100
	BYTE	byGainB;			//增益B，0-100
	BYTE	byOffsetR;			//偏移量R，0-100
	BYTE	byOffsetG;			//偏移量G，0-100
	BYTE	byOffsetB;			//偏移量B，0-100
	BYTE	byRes[6];
}NET_DVR_ADC_CFG, *LPNET_DVR_ADC_CFG;

typedef struct tagNET_DVR_SCREEN_EDGE_CFG
{		
	BYTE	byEnable;	        //是否启用屏幕边缘 0-不启用 1-启用
	BYTE	byLeftEdge;	        //左边缘，0-100
	BYTE	byRightEdge;	    //右边缘，0-100
	BYTE	byTopEdge;	        //上边缘，0-100
	BYTE	byLowerEdge;	    //下边缘，0-100
	BYTE	byRes[7];
}NET_DVR_SCREEN_EDGE_CFG, *LPNET_DVR_SCREEN_EDGE_CFG;

typedef struct tagNET_DVR_SCREEN_DISPLAY_CFG
{
	DWORD   dwSize;	
	BYTE    byCfgType;       /*设置的参数类型，获取时此参数无效，
	                           0-无效，1-背光参数，2-视频参数，3-色温参数，4-ADC参数，5-屏幕边缘参数*/
	BYTE	byBackLight;		//背光 0~100
	BYTE	byRes1[2];
	NET_DVR_VIDEO_OUT_CFG 		  struVideoOutCfg;	 //视频参数（画面模式）
	NET_DVR_COLOR_TEMPERATURE_CFG struColorTempCfg;  //色温参数
	NET_DVR_ADC_CFG               struAdcCfg;        //ADC参数
	NET_DVR_SCREEN_EDGE_CFG       struScreenEdgeCfg; //屏幕边缘参数
	BYTE byRes[32];
}NET_DVR_SCREEN_DISPLAY_CFG, *LPNET_DVR_SCREEN_DISPLAY_CFG;
//////////////////////////显示参数 end/////////////////////////////////////////////
//模拟遥控类型
typedef enum tagNET_DVR_SCREEN_REMOTE_CTRL_TYPE
{
	REMOTE_CTRL_POWERSUPPLY_OPEN = 1,//1-电源开
	REMOTE_CTRL_POWERSUPPLY_CLOSE = 2,//2-电源关
	REMOTE_CTRL_SIGNALSOURCE,//3-信号源
	REMOTE_CTRL_MENU,//4-菜单
	REMOTE_CTRL_DETERMINATION,//5-确定
	REMOTE_CTRL_ON,//6-上
	REMOTE_CTRL_UNDER,//7-下
	REMOTE_CTRL_LEFT,//8-左
	REMOTE_CTRL_RIGHT,//9-右
	REMOTE_CTRL_INFO,//10-INFO
	REMOTE_CTRL_RETURN// 11-返回上一层		
}SCREEN_REMOTE_CTRL_TYPE;

//模拟遥控按键 2013-09-05
typedef struct tagNET_DVR_SIMULATE_SCREEN_REMOTE_CTRL
{
	DWORD       dwSize;	
	BYTE		byControlType;	//1-电源开，2-电源关，3-信号源，4-菜单，5-确定，6-上，7-下，8-左，9-右,  10-INFO, 11-返回上一层
	BYTE		byRes[15];
}NET_DVR_SIMULATE_SCREEN_REMOTE_CTRL,*LPNET_DVR_SIMULATE_SCREEN_REMOTE_CTRL;

//屏幕信号源配置
typedef struct tagNET_DVR_SCREEN_SIGNAL_CFG
{
	DWORD    dwSize;	
	BYTE     bySignalSourceType;	//输入源索引，见枚举 NET_DVR_CAM_MODE
	BYTE	 byNoSignalPic;		    //无信号画面模式，1-蓝屏，2-黑屏，3-LOGO画面
	BYTE	 byRes[14];
}NET_DVR_SCREEN_SIGNAL_CFG, *LPNET_DVR_SCREEN_SIGNAL_CFG;

//屏幕拼接配置
typedef struct tagNET_DVRSCREEN_SPLICE_CFG
{
	DWORD   dwSize;	
	BYTE	bySpliceIndex;			//自拼接屏号，0就是没有拼接，其他值表示自拼接屏的屏号。例如拼接0101~0202这4块屏，则这4块屏的bySpliceIndex必须相同，且非0.
	BYTE	bySpliceX;				//屏幕在自拼接屏中的行位置
	BYTE	bySpliceY;				//屏幕在自拼接屏中的列位置
	BYTE    byWidth;                //拼接规模宽，以屏幕为单位
	BYTE    byHeight;               //拼接规模高，以屏幕为单位
	BYTE	byRes[11];
}NET_DVR_SCREEN_SPLICE_CFG, *LPNET_DVR_SCREEN_SPLICE_CFG;

//风扇工作方式配置
typedef struct tagNET_DVR_SCREEN_FAN_WORK_MODE_CFG
{
	DWORD       dwSize;	
	BYTE		byWorkMode;		         //1-常开，2-自动
	BYTE		byTemperatureLimitValue; //风扇开启的温度阀值，工作模式为自动时该参数有效。
	BYTE		byRes[14];
}NET_DVR_SCREEN_FAN_WORK_MODE_CFG, *LPNET_DVR_SCREEN_FAN_WORK_MODE_CFG;

//VGA信号配置
typedef struct tagNET_DVR_SCREEN_VGA_CFG
{
	DWORD       dwSize;	
	BYTE        byEnableAutoAdjust;      //是否自动调整，0-否，1-是，当自动调整启用时以下参数无效
	BYTE		byHorizontalPosition;   //水平位置 0-100
	BYTE		byVerticalPosition;  	//垂直位置 0-100
	BYTE		byClock;	            //时钟 ，0-100
	BYTE		byPhase;                //相位，0-100
	BYTE		byRes[11];
}NET_DVR_SCREEN_VGA_CFG, *LPNET_DVR_SCREEN_VGA_CFG;

//屏幕菜单配置
typedef struct tagNET_DVR_SCREEN_MENU_CFG
{
	DWORD       dwSize;	
	BYTE		byMenuLanguage; //语言，1-中文，2-英文
	BYTE		byTransparency; //透明度 0-不透明，1-低，2-中，3-高
	BYTE		byDuration;	    //持续时间，0-常开，1-5秒，2-15秒，3-30秒
	BYTE		byRes[13];
}NET_DVR_SCREEN_MENU_CFG, *LPNET_DVR_SCREEN_MENU_CFG;

//画中画
typedef struct tagNET_DVR_PIP_CFG
{
	DWORD   dwSize;	
	BYTE	byEnable;	//是否启用画中画 0-不启用 1-启用
	BYTE	bySubWindowSource;	//子画面信号源，参考枚举NET_DVR_CAM_MODE
	BYTE	bySubWindowBorderColor;	//子画面边框颜色， 1-蓝色，2-黑色
	BYTE    byRes1;
	NET_DVR_RECTCFG  struPosition;    //子画面位置，屏幕总大小为100*100
	BYTE	byRes2[12];
}NET_DVR_PIP_CFG, *LPNET_DVR_PIP_CFG;

//去雾配置
typedef struct tagNET_DVR_DEFOG_LCD
{
	DWORD   dwSize;	
	BYTE	byDefogEnable;    //开启去雾开关，0~关闭，1~开启
	BYTE	byDefogModel;     //去雾模式，0~自动去雾，1~手动去雾
	BYTE    byDefogLevel;     //去雾强度等级，1-7个等级，默认等级为4。等级1为0.5；等级2为0.55；等级3为0.60；等级4为0.65；等级5为0.70；等级6为0.75；等级7为0.80。（去雾模式为手动去雾时，可配置去雾强度等级）
	BYTE	byRes[33];
}NET_DVR_DEFOG_LCD,*LPNET_DVR_DEFOG_LCD;

//屏幕维墙
typedef struct tagNET_DVR_SCREEN_WALL_CFG
{
	DWORD	dwSize;
	BYTE    byEnable; //状态开关。0-为关闭；1-为开启
	BYTE    byRes[35];
}NET_DVR_SCREEN_WALL_CFG, *LPNET_DVR_SCREEN_WALL_CFG;

//屏幕位置
typedef struct tagNET_DVR_SCREEN_POS_CFG
{
	DWORD	 dwSize;
    BYTE     byScreenRowNum;//屏幕行号。
	BYTE     byScreenColNum;//屏幕列号。
	BYTE     byRes[34];
}NET_DVR_SCREEN_POS_CFG, *LPNET_DVR_SCREEN_POS_CFG;

typedef struct tagNET_DVR_VIDEO_AUDIOIN_CFG
{
	DWORD     dwSize;     //结构体的长度
	DWORD     dwChanNo;   //绑定语音对讲作为音频输入的通道号
	BYTE	  byEnable;   //是否启用语音对讲 0-不启用 1-启用
	BYTE	  byRes[31];          //保留
}NET_DVR_VIDEO_AUDIOIN_CFG, *LPNET_DVR_VIDEO_AUDIOIN_CFG;

typedef struct _NET_DVR_VCA_DETION_CFG
{	
	DWORD   dwSize; 
	BYTE	byEnable;//使能
	BYTE	byRes1[3];
	NET_DVR_SCHEDTIME	struAlarmSched[MAX_DAYS][MAX_TIMESEGMENT_V30];
	NET_DVR_HANDLEEXCEPTION_V40 struHandleException;  //异常处理方式
	DWORD	dwMaxRelRecordChanNum ;  //报警触发的录象通道 数（只读）最大支持数量
	DWORD	dwRelRecordChanNum ;     //报警触发的录象通道 数 实际支持的数量
	DWORD	dwRelRecordChan[MAX_CHANNUM_V30/*64*/];//触发录像通道号
	BYTE	byEnablePreset[MAX_CHANNUM_V30];
	BYTE	byPresetNo[MAX_CHANNUM_V30];
	BYTE	byEnableCruise[MAX_CHANNUM_V30];
	BYTE	byCruiseNo[MAX_CHANNUM_V30];
	BYTE	byEnablePtzTrack[MAX_CHANNUM_V30];
	BYTE	byPTZTrack[MAX_CHANNUM_V30];
	BYTE	byRes[256];
}NET_DVR_VCA_DETION_CFG, *LPNET_DVR_VCA_DETION_CFG;

/*******************************LCD拼接屏 end******************************************/

/*******************************测试版本头 begin***************************************/
//[add] by panyadong 2013-12-11 
typedef struct tagNET_DVR_TEST_VERSION_HEAD
{
    DWORD        dwSize;
    DWORD        dwParam1;
    BYTE         byParam2;
    BYTE         byRes[31];
}NET_DVR_TEST_VERSION_HEAD, *LPNET_DVR_TEST_VERSION_HEAD;

typedef struct tagNET_DVR_TEST_VERSION_HEAD_V1
{
    DWORD        dwSize;
    DWORD        dwParam1;
    BYTE         byParam2;
    BYTE         byRes[31];
    DWORD        dwParam1_1;
    BYTE         byParam1_2;
    BYTE         byRes1[31];
}NET_DVR_TEST_VERSION_HEAD_V1, *LPNET_DVR_TEST_VERSION_HEAD_V1;

typedef struct tagNET_DVR_TEST_VERSION_HEAD_V2
{
    DWORD        dwSize;
    DWORD        dwParam1;
    BYTE         byParam2;
    BYTE         byRes[31];
    DWORD        dwParam1_1;
    BYTE         byParam1_2;
    BYTE         byRes1[31];
    DWORD        dwParam2_1;
    BYTE         byParam2_2;
    BYTE         byRes2[31];
}NET_DVR_TEST_VERSION_HEAD_V2, *LPNET_DVR_TEST_VERSION_HEAD_V2;

/*******************************测试版本头 end*****************************************/

/********************************SDK接口函数声明*********************************/
NET_DVR_API BOOL __stdcall NET_DVR_Init();
NET_DVR_API BOOL __stdcall NET_DVR_Cleanup();

//NET_DVR_SetDVRMessage的扩展
#ifdef _WIN32
NET_DVR_API BOOL __stdcall NET_DVR_SetDVRMessage(UINT nMessage,HWND hWnd);
NET_DVR_API BOOL __stdcall NET_DVR_SetExceptionCallBack_V30(UINT nMessage, HWND hWnd, void (CALLBACK* fExceptionCallBack)(DWORD dwType, LONG lUserID, LONG lHandle, void *pUser), void *pUser);
#elif defined(__linux__) || defined(__APPLE__)
NET_DVR_API BOOL __stdcall NET_DVR_SetExceptionCallBack_V30(UINT reserved1, void* reserved2, void (CALLBACK* fExceptionCallBack)(DWORD dwType, LONG lUserID, LONG lHandle, void *pUser), void *pUser);
/*Linux专有 */
#if defined(__linux__)
NET_DVR_API BOOL NET_DVR_DrawAreaInit(INITINFO InitInfo, DWORD iUseSDL = 1);
NET_DVR_API BOOL NET_DVR_DrawAreaRelease();
#endif
#endif

NET_DVR_API BOOL __stdcall NET_DVR_SetDVRMessCallBack(BOOL (CALLBACK *fMessCallBack)(LONG lCommand,char *sDVRIP,char *pBuf,DWORD dwBufLen));
NET_DVR_API BOOL __stdcall NET_DVR_SetDVRMessCallBack_EX(BOOL (CALLBACK *fMessCallBack_EX)(LONG lCommand,LONG lUserID,char *pBuf,DWORD dwBufLen));
NET_DVR_API BOOL __stdcall NET_DVR_SetDVRMessCallBack_NEW(BOOL (CALLBACK *fMessCallBack_NEW)(LONG lCommand,char *sDVRIP,char *pBuf,DWORD dwBufLen, WORD dwLinkDVRPort));
NET_DVR_API BOOL __stdcall NET_DVR_SetDVRMessageCallBack(BOOL (CALLBACK *fMessageCallBack)(LONG lCommand,char *sDVRIP,char *pBuf,DWORD dwBufLen, DWORD dwUser), DWORD dwUser);
typedef void (CALLBACK *MSGCallBack)(LONG lCommand, NET_DVR_ALARMER *pAlarmer, char *pAlarmInfo, DWORD dwBufLen, void* pUser);
NET_DVR_API BOOL __stdcall NET_DVR_SetDVRMessageCallBack_V30(MSGCallBack fMessageCallBack, void* pUser);

NET_DVR_API BOOL __stdcall NET_DVR_SetConnectTime(DWORD dwWaitTime = 3000, DWORD dwTryTimes = 3);
NET_DVR_API BOOL __stdcall NET_DVR_SetReconnect(DWORD dwInterval = 30000, BOOL bEnableRecon = TRUE);
NET_DVR_API DWORD __stdcall NET_DVR_GetSDKVersion();
NET_DVR_API DWORD __stdcall NET_DVR_GetSDKBuildVersion();
NET_DVR_API int __stdcall NET_DVR_IsSupport();
NET_DVR_API BOOL __stdcall NET_DVR_StartListen(char *sLocalIP,WORD wLocalPort);
NET_DVR_API BOOL __stdcall NET_DVR_StopListen();

NET_DVR_API LONG __stdcall NET_DVR_StartListen_V30(char *sLocalIP, WORD wLocalPort, MSGCallBack DataCallback, void* pUserData = NULL);
NET_DVR_API BOOL __stdcall NET_DVR_StopListen_V30(LONG lListenHandle);
NET_DVR_API LONG __stdcall NET_DVR_Login(char *sDVRIP,WORD wDVRPort,char *sUserName,char *sPassword,LPNET_DVR_DEVICEINFO lpDeviceInfo);
NET_DVR_API LONG __stdcall NET_DVR_Login_V30(char *sDVRIP, WORD wDVRPort, char *sUserName, char *sPassword, LPNET_DVR_DEVICEINFO_V30 lpDeviceInfo);

NET_DVR_API LONG __stdcall NET_DVR_Login_V40(LPNET_DVR_USER_LOGIN_INFO pLoginInfo,LPNET_DVR_DEVICEINFO_V30 lpDeviceInfo);
NET_DVR_API BOOL __stdcall NET_DVR_Login_Check(char *sDVRIP, WORD wDVRPort, char *sUserName, char *sPassword, LPNET_DVR_DEVICEINFO_V30 lpDeviceInfo);
NET_DVR_API BOOL __stdcall NET_DVR_Logout(LONG lUserID);
NET_DVR_API BOOL __stdcall NET_DVR_Logout_V30(LONG lUserID);
NET_DVR_API DWORD __stdcall NET_DVR_GetLastError();
NET_DVR_API char* __stdcall NET_DVR_GetErrorMsg(LONG *pErrorNo = NULL);
NET_DVR_API BOOL __stdcall NET_DVR_SetShowMode(DWORD dwShowType,COLORREF colorKey);
NET_DVR_API BOOL __stdcall NET_DVR_GetDVRIPByResolveSvr(char *sServerIP, WORD wServerPort, BYTE *sDVRName,WORD wDVRNameLen,BYTE *sDVRSerialNumber,WORD wDVRSerialLen,char* sGetIP);
NET_DVR_API BOOL  __stdcall NET_DVR_GetDVRIPByResolveSvr_EX(char *sServerIP, WORD wServerPort, BYTE *sDVRName, WORD wDVRNameLen, BYTE *sDVRSerialNumber, WORD wDVRSerialLen, char* sGetIP, DWORD *dwPort);

//预览相关接口
NET_DVR_API LONG __stdcall NET_DVR_PlayDirect(char *sDVRIP, char *sUserName, char *sPassword, \
											  LPNET_DVR_CLIENTINFO lpClientInfo, void(CALLBACK *fRealDataCallBack_V30) (LONG lRealHandle, DWORD dwDataType, BYTE *pBuffer, DWORD dwBufSize, void* pUser) = NULL, void* pUser = NULL, BOOL bBlocked = FALSE);
NET_DVR_API LONG __stdcall NET_DVR_RealPlay(LONG lUserID,LPNET_DVR_CLIENTINFO lpClientInfo);
NET_DVR_API LONG __stdcall NET_DVR_RealPlay_V30(LONG lUserID, LPNET_DVR_CLIENTINFO lpClientInfo, void(CALLBACK *fRealDataCallBack_V30) (LONG lRealHandle, DWORD dwDataType, BYTE *pBuffer, DWORD dwBufSize, void* pUser) = NULL, void* pUser = NULL, BOOL bBlocked = FALSE);
NET_DVR_API BOOL __stdcall NET_DVR_StopRealPlay(LONG lRealHandle);
NET_DVR_API BOOL __stdcall NET_DVR_StopPlayDirect(LONG lRealHandle);
NET_DVR_API BOOL __stdcall NET_DVR_RigisterDrawFun(LONG lRealHandle,void (CALLBACK* fDrawFun)(LONG lRealHandle,HDC hDc,DWORD dwUser),DWORD dwUser);
NET_DVR_API BOOL __stdcall NET_DVR_SetPlayerBufNumber(LONG lRealHandle,DWORD dwBufNum);
NET_DVR_API BOOL __stdcall NET_DVR_ThrowBFrame(LONG lRealHandle,DWORD dwNum);
NET_DVR_API BOOL __stdcall NET_DVR_SetAudioMode(DWORD dwMode);
NET_DVR_API BOOL __stdcall NET_DVR_OpenSound(LONG lRealHandle);
NET_DVR_API BOOL __stdcall NET_DVR_CloseSound();
NET_DVR_API BOOL __stdcall NET_DVR_OpenSoundShare(LONG lRealHandle);
NET_DVR_API BOOL __stdcall NET_DVR_CloseSoundShare(LONG lRealHandle);
NET_DVR_API BOOL __stdcall NET_DVR_Volume(LONG lRealHandle,WORD wVolume);
NET_DVR_API BOOL __stdcall NET_DVR_SaveRealData(LONG lRealHandle,char *sFileName);
NET_DVR_API BOOL __stdcall NET_DVR_StopSaveRealData(LONG lRealHandle);
NET_DVR_API BOOL __stdcall NET_DVR_SetRealDataCallBack(LONG lRealHandle,void(CALLBACK *fRealDataCallBack) (LONG lRealHandle, DWORD dwDataType, BYTE *pBuffer,DWORD dwBufSize,DWORD dwUser),DWORD dwUser);
NET_DVR_API BOOL __stdcall NET_DVR_SetStandardDataCallBack(LONG lRealHandle,void(CALLBACK *fStdDataCallBack) (LONG lRealHandle, DWORD dwDataType, BYTE *pBuffer,DWORD dwBufSize,DWORD dwUser),DWORD dwUser);
NET_DVR_API BOOL __stdcall NET_DVR_CapturePicture(LONG lRealHandle,char *sPicFileName);//bmp
NET_DVR_API BOOL __stdcall NET_DVR_SetCapturePictureMode(DWORD dwCaptureMode);


//动态生成I帧
NET_DVR_API BOOL __stdcall NET_DVR_MakeKeyFrame(LONG lUserID, LONG lChannel);//主码流
NET_DVR_API BOOL __stdcall NET_DVR_MakeKeyFrameSub(LONG lUserID, LONG lChannel);//子码流

//云台控制相关接口
NET_DVR_API BOOL __stdcall NET_DVR_PTZControl(LONG lRealHandle,DWORD dwPTZCommand,DWORD dwStop);
NET_DVR_API BOOL __stdcall NET_DVR_PTZControl_Other(LONG lUserID,LONG lChannel,DWORD dwPTZCommand,DWORD dwStop);
NET_DVR_API BOOL __stdcall NET_DVR_TransPTZ(LONG lRealHandle,char *pPTZCodeBuf,DWORD dwBufSize);
NET_DVR_API BOOL __stdcall NET_DVR_TransPTZ_Other(LONG lUserID,LONG lChannel,char *pPTZCodeBuf,DWORD dwBufSize);
NET_DVR_API BOOL __stdcall NET_DVR_PTZPreset(LONG lRealHandle,DWORD dwPTZPresetCmd,DWORD dwPresetIndex);
NET_DVR_API BOOL __stdcall NET_DVR_PTZPreset_Other(LONG lUserID,LONG lChannel,DWORD dwPTZPresetCmd,DWORD dwPresetIndex);
NET_DVR_API BOOL __stdcall NET_DVR_TransPTZ_EX(LONG lRealHandle,char *pPTZCodeBuf,DWORD dwBufSize);
NET_DVR_API BOOL __stdcall NET_DVR_PTZControl_EX(LONG lRealHandle,DWORD dwPTZCommand,DWORD dwStop);
NET_DVR_API BOOL __stdcall NET_DVR_PTZPreset_EX(LONG lRealHandle,DWORD dwPTZPresetCmd,DWORD dwPresetIndex);
NET_DVR_API BOOL __stdcall NET_DVR_PTZCruise(LONG lRealHandle,DWORD dwPTZCruiseCmd,BYTE byCruiseRoute, BYTE byCruisePoint, WORD wInput);
NET_DVR_API BOOL __stdcall NET_DVR_PTZCruise_Other(LONG lUserID,LONG lChannel,DWORD dwPTZCruiseCmd,BYTE byCruiseRoute, BYTE byCruisePoint, WORD wInput);
NET_DVR_API BOOL __stdcall NET_DVR_PTZCruise_EX(LONG lRealHandle,DWORD dwPTZCruiseCmd,BYTE byCruiseRoute, BYTE byCruisePoint, WORD wInput);
NET_DVR_API BOOL __stdcall NET_DVR_PTZTrack(LONG lRealHandle, DWORD dwPTZTrackCmd);
NET_DVR_API BOOL __stdcall NET_DVR_PTZTrack_Other(LONG lUserID, LONG lChannel, DWORD dwPTZTrackCmd);
NET_DVR_API BOOL __stdcall NET_DVR_PTZTrack_EX(LONG lRealHandle, DWORD dwPTZTrackCmd);
NET_DVR_API BOOL __stdcall NET_DVR_PTZControlWithSpeed(LONG lRealHandle, DWORD dwPTZCommand, DWORD dwStop, DWORD dwSpeed);
NET_DVR_API BOOL __stdcall NET_DVR_PTZControlWithSpeed_Other(LONG lUserID, LONG lChannel, DWORD dwPTZCommand, DWORD dwStop, DWORD dwSpeed);
NET_DVR_API BOOL __stdcall NET_DVR_PTZControlWithSpeed_EX(LONG lRealHandle, DWORD dwPTZCommand, DWORD dwStop, DWORD dwSpeed);
NET_DVR_API BOOL __stdcall NET_DVR_GetPTZCruise(LONG lUserID,LONG lChannel,LONG lCruiseRoute, LPNET_DVR_CRUISE_RET lpCruiseRet);


//文件查找与回放
NET_DVR_API LONG __stdcall NET_DVR_FindFile(LONG lUserID,LONG lChannel,DWORD dwFileType, LPNET_DVR_TIME lpStartTime, LPNET_DVR_TIME lpStopTime);
NET_DVR_API LONG __stdcall NET_DVR_FindNextFile(LONG lFindHandle,LPNET_DVR_FIND_DATA lpFindData);
NET_DVR_API BOOL __stdcall NET_DVR_FindClose(LONG lFindHandle);
NET_DVR_API LONG __stdcall NET_DVR_FindNextFile_V30(LONG lFindHandle, LPNET_DVR_FINDDATA_V30 lpFindData);
NET_DVR_API LONG __stdcall NET_DVR_FindNextFile_V40(LONG lFindHandle, LPNET_DVR_FINDDATA_V40 lpFindData);
NET_DVR_API LONG __stdcall NET_DVR_FindFile_V30(LONG lUserID, LPNET_DVR_FILECOND pFindCond);
NET_DVR_API BOOL __stdcall NET_DVR_FindClose_V30(LONG lFindHandle);

NET_DVR_API BOOL __stdcall NET_DVR_LockFileByName(LONG lUserID, char *sLockFileName);
NET_DVR_API BOOL __stdcall NET_DVR_UnlockFileByName(LONG lUserID, char *sUnlockFileName);
NET_DVR_API BOOL __stdcall NET_DVR_LockFileByNameV40(LONG lUserID, BOOL bLock, const NET_DVR_LOCK_FILE_BY_NAME_PARA *lpLockFilePara);
NET_DVR_API LONG __stdcall NET_DVR_PlayBackByName(LONG lUserID,char *sPlayBackFileName, HWND hWnd);
NET_DVR_API LONG __stdcall NET_DVR_PlayBackByTime(LONG lUserID,LONG lChannel, LPNET_DVR_TIME lpStartTime, LPNET_DVR_TIME lpStopTime, HWND hWnd);
NET_DVR_API LONG __stdcall NET_DVR_PlayBackReverseByName(LONG lUserID, char *sPlayBackFileName, HWND hWnd);

NET_DVR_API BOOL __stdcall NET_DVR_PlayBackControl(LONG lPlayHandle,DWORD dwControlCode,DWORD dwInValue,DWORD *LPOutValue);
NET_DVR_API BOOL __stdcall NET_DVR_StopPlayBack(LONG lPlayHandle);
NET_DVR_API BOOL __stdcall NET_DVR_SetPlayDataCallBack(LONG lPlayHandle,void(CALLBACK *fPlayDataCallBack) (LONG lPlayHandle, DWORD dwDataType, BYTE *pBuffer,DWORD dwBufSize,DWORD dwUser),DWORD dwUser);
NET_DVR_API BOOL __stdcall NET_DVR_SetPlayDataCallBack_V40(LONG lPlayHandle,void(CALLBACK *fPlayDataCallBack_V40) (LONG lPlayHandle, DWORD dwDataType, BYTE *pBuffer,DWORD dwBufSize,void *pUser),void *pUser);
NET_DVR_API BOOL __stdcall NET_DVR_PlayBackSaveData(LONG lPlayHandle,char *sFileName);
NET_DVR_API BOOL __stdcall NET_DVR_StopPlayBackSave(LONG lPlayHandle);
NET_DVR_API BOOL __stdcall NET_DVR_GetPlayBackOsdTime(LONG lPlayHandle, LPNET_DVR_TIME lpOsdTime);
NET_DVR_API BOOL __stdcall NET_DVR_PlayBackCaptureFile(LONG lPlayHandle,char *sFileName);
NET_DVR_API LONG __stdcall NET_DVR_GetFileByName(LONG lUserID,char *sDVRFileName,char *sSavedFileName);
NET_DVR_API LONG __stdcall NET_DVR_GetFileByTime(LONG lUserID,LONG lChannel, LPNET_DVR_TIME lpStartTime, LPNET_DVR_TIME lpStopTime, char *sSavedFileName);
NET_DVR_API BOOL __stdcall NET_DVR_StopGetFile(LONG lFileHandle);
NET_DVR_API int __stdcall NET_DVR_GetDownloadPos(LONG lFileHandle);
NET_DVR_API int	__stdcall NET_DVR_GetPlayBackPos(LONG lPlayHandle);

//升级
NET_DVR_API LONG __stdcall NET_DVR_AdapterUpgrade(LONG lUserID, char *sFileName);
NET_DVR_API LONG __stdcall NET_DVR_Upgrade(LONG lUserID, char *sFileName);
NET_DVR_API LONG __stdcall NET_DVR_VcalibUpgrade(LONG lUserID, LONG lChannel, char const *sFileName);
NET_DVR_API int __stdcall NET_DVR_GetUpgradeState(LONG lUpgradeHandle);
NET_DVR_API int __stdcall NET_DVR_GetUpgradeProgress(LONG lUpgradeHandle);
NET_DVR_API BOOL __stdcall NET_DVR_CloseUpgradeHandle(LONG lUpgradeHandle);
NET_DVR_API BOOL __stdcall NET_DVR_SetNetworkEnvironment(DWORD dwEnvironmentLevel);
//远程格式化硬盘
NET_DVR_API LONG __stdcall NET_DVR_FormatDisk(LONG lUserID,LONG lDiskNumber);
NET_DVR_API BOOL __stdcall NET_DVR_GetFormatProgress(LONG lFormatHandle, LONG *pCurrentFormatDisk,LONG *pCurrentDiskPos,LONG *pFormatStatic);
NET_DVR_API BOOL __stdcall NET_DVR_CloseFormatHandle(LONG lFormatHandle);
//报警
NET_DVR_API LONG __stdcall NET_DVR_SetupAlarmChan(LONG lUserID);
NET_DVR_API BOOL __stdcall NET_DVR_CloseAlarmChan(LONG lAlarmHandle);
NET_DVR_API LONG __stdcall NET_DVR_SetupAlarmChan_V30(LONG lUserID);
NET_DVR_API BOOL __stdcall NET_DVR_CloseAlarmChan_V30(LONG lAlarmHandle);
//语音对讲
NET_DVR_API LONG __stdcall NET_DVR_StartVoiceCom(LONG lUserID, void(CALLBACK *fVoiceDataCallBack)(LONG lVoiceComHandle, char *pRecvDataBuffer, DWORD dwBufSize, BYTE byAudioFlag, DWORD dwUser), DWORD dwUser);
NET_DVR_API LONG __stdcall NET_DVR_StartVoiceCom_V30(LONG lUserID, DWORD dwVoiceChan, BOOL bNeedCBNoEncData, void(CALLBACK *fVoiceDataCallBack)(LONG lVoiceComHandle, char *pRecvDataBuffer, DWORD dwBufSize, BYTE byAudioFlag, void* pUser), void* pUser);
NET_DVR_API BOOL __stdcall NET_DVR_SetVoiceComClientVolume(LONG lVoiceComHandle, WORD wVolume);
NET_DVR_API BOOL __stdcall NET_DVR_StopVoiceCom(LONG lVoiceComHandle);
//语音转发
NET_DVR_API LONG __stdcall NET_DVR_StartVoiceCom_MR(LONG lUserID, void(CALLBACK *fVoiceDataCallBack)(LONG lVoiceComHandle, char *pRecvDataBuffer, DWORD dwBufSize, BYTE byAudioFlag, DWORD dwUser), DWORD dwUser);
NET_DVR_API LONG __stdcall NET_DVR_StartVoiceCom_MR_V30(LONG lUserID, DWORD dwVoiceChan, void(CALLBACK *fVoiceDataCallBack)(LONG lVoiceComHandle, char *pRecvDataBuffer, DWORD dwBufSize, BYTE byAudioFlag, void* pUser), void* pUser);
NET_DVR_API BOOL __stdcall NET_DVR_VoiceComSendData(LONG lVoiceComHandle, char *pSendBuf, DWORD dwBufSize);
NET_DVR_API BOOL __stdcall NET_DVR_GetCurrentAudioCompress(LONG lUserID, LPNET_DVR_COMPRESSION_AUDIO lpCompressAudio);
//语音广播
NET_DVR_API BOOL __stdcall NET_DVR_ClientAudioStart();
NET_DVR_API BOOL __stdcall NET_DVR_ClientAudioStart_V30(void(CALLBACK *fVoiceDataCallBack)(char *pRecvDataBuffer, DWORD dwBufSize, void * pUser), void *pUser);
NET_DVR_API BOOL __stdcall NET_DVR_ClientAudioStop();
NET_DVR_API BOOL __stdcall NET_DVR_AddDVR(LONG lUserID);
NET_DVR_API LONG __stdcall NET_DVR_AddDVR_V30(LONG lUserID, DWORD dwVoiceChan);
NET_DVR_API BOOL __stdcall NET_DVR_DelDVR(LONG lUserID);
NET_DVR_API BOOL __stdcall NET_DVR_DelDVR_V30(LONG lVoiceHandle);
////////////////////////////////////////////////////////////
//透明通道设置
NET_DVR_API LONG __stdcall NET_DVR_SerialStart(LONG lUserID,LONG lSerialPort,void(CALLBACK *fSerialDataCallBack)(LONG lSerialHandle,char *pRecvDataBuffer,DWORD dwBufSize,DWORD dwUser),DWORD dwUser);
//485作为透明通道时，需要指明通道号，因为不同通道号485的设置可以不同(比如波特率)
NET_DVR_API BOOL __stdcall NET_DVR_SerialSend(LONG lSerialHandle, LONG lChannel, char *pSendBuf,DWORD dwBufSize);
NET_DVR_API BOOL __stdcall NET_DVR_SerialStop(LONG lSerialHandle);
NET_DVR_API BOOL __stdcall NET_DVR_SendTo232Port(LONG lUserID, char *pSendBuf, DWORD dwBufSize);
NET_DVR_API BOOL __stdcall NET_DVR_SendToSerialPort(LONG lUserID, DWORD dwSerialPort, DWORD dwSerialIndex, char *pSendBuf, DWORD dwBufSize);

//解码 nBitrate = 16000
NET_DVR_API void* __stdcall NET_DVR_InitG722Decoder(int nBitrate = 16000);
NET_DVR_API void __stdcall NET_DVR_ReleaseG722Decoder(void *pDecHandle);
NET_DVR_API BOOL __stdcall NET_DVR_DecodeG722Frame(void *pDecHandle, BYTE* pInBuffer, BYTE* pOutBuffer);
//编码
NET_DVR_API void* __stdcall NET_DVR_InitG722Encoder();
NET_DVR_API BOOL __stdcall NET_DVR_EncodeG722Frame(void *pEncodeHandle,BYTE* pInBuffer, BYTE* pOutBuffer);
NET_DVR_API void __stdcall NET_DVR_ReleaseG722Encoder(void *pEncodeHandle);

//解码
NET_DVR_API void* __stdcall NET_DVR_InitG726Decoder(void** pDecMoudle);
NET_DVR_API void __stdcall NET_DVR_ReleaseG726Decoder(void *pDecHandle);
NET_DVR_API BOOL __stdcall NET_DVR_DecodeG726Frame(void *pDecMoudle, BYTE* pInBuffer, BYTE* pOutBuffer, BYTE byReset);
//编码
NET_DVR_API void* __stdcall NET_DVR_InitG726Encoder(void** pEncMoudle);
NET_DVR_API BOOL __stdcall NET_DVR_EncodeG726Frame(void *pEncMoudle,BYTE* pInBuffer, BYTE* pOutBuffer, BYTE byReset);
NET_DVR_API void __stdcall NET_DVR_ReleaseG726Encoder(void *pEncHandle);
//远程控制本地显示
NET_DVR_API BOOL __stdcall NET_DVR_ClickKey(LONG lUserID, LONG lKeyIndex);
//远程控制设备端手动录像
NET_DVR_API BOOL __stdcall NET_DVR_StartDVRRecord(LONG lUserID,LONG lChannel,LONG lRecordType);
NET_DVR_API BOOL __stdcall NET_DVR_StopDVRRecord(LONG lUserID,LONG lChannel);
//解码卡
NET_DVR_API BOOL __stdcall NET_DVR_InitDevice_Card(long *pDeviceTotalChan);
NET_DVR_API BOOL __stdcall NET_DVR_ReleaseDevice_Card();
NET_DVR_API BOOL __stdcall NET_DVR_InitDDraw_Card(HWND hParent,COLORREF colorKey);
NET_DVR_API BOOL __stdcall NET_DVR_ReleaseDDraw_Card();
NET_DVR_API LONG __stdcall NET_DVR_RealPlay_Card(LONG lUserID,LPNET_DVR_CARDINFO lpCardInfo,long lChannelNum);
NET_DVR_API BOOL __stdcall NET_DVR_ResetPara_Card(LONG lRealHandle,LPNET_DVR_DISPLAY_PARA lpDisplayPara);
NET_DVR_API BOOL __stdcall NET_DVR_RefreshSurface_Card();
NET_DVR_API BOOL __stdcall NET_DVR_ClearSurface_Card();
NET_DVR_API BOOL __stdcall NET_DVR_RestoreSurface_Card();
NET_DVR_API BOOL __stdcall NET_DVR_OpenSound_Card(LONG lRealHandle);
NET_DVR_API BOOL __stdcall NET_DVR_CloseSound_Card(LONG lRealHandle);
NET_DVR_API BOOL __stdcall NET_DVR_SetVolume_Card(LONG lRealHandle,WORD wVolume);
NET_DVR_API BOOL __stdcall NET_DVR_AudioPreview_Card(LONG lRealHandle,BOOL bEnable);
NET_DVR_API LONG __stdcall NET_DVR_GetCardLastError_Card();
NET_DVR_API HANDLE __stdcall NET_DVR_GetChanHandle_Card(LONG lRealHandle);
NET_DVR_API BOOL __stdcall NET_DVR_CapturePicture_Card(LONG lRealHandle, char *sPicFileName);
//获取解码卡序列号此接口无效，改用GetBoardDetail接口获得(2005-12-08支持)
NET_DVR_API BOOL __stdcall NET_DVR_GetSerialNum_Card(long lChannelNum,DWORD *pDeviceSerialNo);
//日志
NET_DVR_API LONG __stdcall NET_DVR_FindDVRLog(LONG lUserID, LONG lSelectMode, DWORD dwMajorType,DWORD dwMinorType, LPNET_DVR_TIME lpStartTime, LPNET_DVR_TIME lpStopTime);
NET_DVR_API LONG __stdcall NET_DVR_FindNextLog(LONG lLogHandle, LPNET_DVR_LOG lpLogData);
NET_DVR_API BOOL __stdcall NET_DVR_FindLogClose(LONG lLogHandle);
NET_DVR_API LONG __stdcall NET_DVR_FindDVRLog_V30(LONG lUserID, LONG lSelectMode, DWORD dwMajorType,DWORD dwMinorType, LPNET_DVR_TIME lpStartTime, LPNET_DVR_TIME lpStopTime, BOOL bOnlySmart = FALSE);
NET_DVR_API LONG __stdcall NET_DVR_FindNextLog_V30(LONG lLogHandle, LPNET_DVR_LOG_V30 lpLogData);
NET_DVR_API BOOL __stdcall NET_DVR_FindLogClose_V30(LONG lLogHandle);
// 报警主机日志
NET_DVR_API LONG __stdcall NET_DVR_FindAlarmHostLog(LONG lUserID, LONG lSelectMode, NET_DVR_ALARMHOST_SEARCH_LOG_PARAM *lpSearchParam);
NET_DVR_API LONG __stdcall NET_DVR_FindNextAlarmHostLog(LONG lFindHandle, NET_DVR_ALARMHOST_LOG_RET *lpFindData);
NET_DVR_API BOOL __stdcall NET_DVR_FindAlarmHostLogClose(LONG lFindHandle);
//截止2004年8月5日,共113个接口
//ATM DVR
NET_DVR_API LONG __stdcall NET_DVR_FindFileByCard(LONG lUserID,LONG lChannel,DWORD dwFileType, int nFindType, BYTE *sCardNumber, LPNET_DVR_TIME lpStartTime, LPNET_DVR_TIME lpStopTime);
//截止2004年10月5日,共116个接口

//编码
NET_DVR_API void* __stdcall NET_DVR_InitG722Encoder();
NET_DVR_API BOOL __stdcall NET_DVR_EncodeG722Frame(void *pEncodeHandle,BYTE* pInBuffer, BYTE* pOutBuffer);
NET_DVR_API void __stdcall NET_DVR_ReleaseG722Encoder(void *pEncodeHandle);
//2005-09-15
NET_DVR_API BOOL __stdcall NET_DVR_CaptureJPEGPicture(LONG lUserID, LONG lChannel, LPNET_DVR_JPEGPARA lpJpegPara, char *sPicFileName);
//JPEG抓图到内存
NET_DVR_API BOOL __stdcall NET_DVR_CaptureJPEGPicture_NEW(LONG lUserID, LONG lChannel, LPNET_DVR_JPEGPARA lpJpegPara, char *sJpegPicBuffer, DWORD dwPicSize,  LPDWORD lpSizeReturned);


//2006-02-16
NET_DVR_API int __stdcall NET_DVR_GetRealPlayerIndex(LONG lRealHandle);
NET_DVR_API int __stdcall NET_DVR_GetPlayBackPlayerIndex(LONG lPlayHandle);

//2006-08-28 704-640 缩放配置
NET_DVR_API BOOL __stdcall NET_DVR_SetScaleCFG(LONG lUserID, DWORD dwScale);
NET_DVR_API BOOL __stdcall NET_DVR_GetScaleCFG(LONG lUserID, DWORD *lpOutScale);
NET_DVR_API BOOL __stdcall NET_DVR_SetScaleCFG_V30(LONG lUserID, LPNET_DVR_SCALECFG pScalecfg);
NET_DVR_API BOOL __stdcall NET_DVR_GetScaleCFG_V30(LONG lUserID, LPNET_DVR_SCALECFG pScalecfg);
//2006-08-28 ATM机端口设置
NET_DVR_API BOOL __stdcall NET_DVR_SetATMPortCFG(LONG lUserID, WORD wATMPort);
NET_DVR_API BOOL __stdcall NET_DVR_GetATMPortCFG(LONG lUserID, WORD *LPOutATMPort);

//2006-11-10 支持显卡辅助输出
NET_DVR_API BOOL __stdcall NET_DVR_InitDDrawDevice();
NET_DVR_API BOOL __stdcall NET_DVR_ReleaseDDrawDevice();
NET_DVR_API LONG __stdcall NET_DVR_GetDDrawDeviceTotalNums();
NET_DVR_API BOOL __stdcall NET_DVR_SetDDrawDevice(LONG lPlayPort, DWORD nDeviceNum);

NET_DVR_API BOOL __stdcall NET_DVR_PTZSelZoomIn(LONG lRealHandle, LPNET_DVR_POINT_FRAME pStruPointFrame);
NET_DVR_API BOOL __stdcall NET_DVR_PTZSelZoomIn_EX(LONG lUserID, LONG lChannel, LPNET_DVR_POINT_FRAME pStruPointFrame);

//解码设备DS-6001D/DS-6001F
NET_DVR_API BOOL __stdcall NET_DVR_StartDecode(LONG lUserID, LONG lChannel, LPNET_DVR_DECODERINFO lpDecoderinfo);
NET_DVR_API BOOL __stdcall NET_DVR_StopDecode(LONG lUserID, LONG lChannel);
NET_DVR_API BOOL __stdcall NET_DVR_GetDecoderState(LONG lUserID, LONG lChannel, LPNET_DVR_DECODERSTATE lpDecoderState);
//2005-08-01
NET_DVR_API BOOL __stdcall NET_DVR_SetDecInfo(LONG lUserID, LONG lChannel, LPNET_DVR_DECCFG lpDecoderinfo);
NET_DVR_API BOOL __stdcall NET_DVR_GetDecInfo(LONG lUserID, LONG lChannel, LPNET_DVR_DECCFG lpDecoderinfo);
NET_DVR_API BOOL __stdcall NET_DVR_SetDecTransPort(LONG lUserID, LPNET_DVR_PORTCFG lpTransPort);
NET_DVR_API BOOL __stdcall NET_DVR_GetDecTransPort(LONG lUserID, LPNET_DVR_PORTCFG lpTransPort);
NET_DVR_API BOOL __stdcall NET_DVR_DecPlayBackCtrl(LONG lUserID, LONG lChannel, DWORD dwControlCode, DWORD dwInValue,DWORD *LPOutValue, LPNET_DVR_PLAYREMOTEFILE lpRemoteFileInfo);
NET_DVR_API BOOL __stdcall NET_DVR_StartDecSpecialCon(LONG lUserID, LONG lChannel, LPNET_DVR_DECCHANINFO lpDecChanInfo);
NET_DVR_API BOOL __stdcall NET_DVR_StopDecSpecialCon(LONG lUserID, LONG lChannel, LPNET_DVR_DECCHANINFO lpDecChanInfo);
NET_DVR_API BOOL __stdcall NET_DVR_DecCtrlDec(LONG lUserID, LONG lChannel, DWORD dwControlCode);
NET_DVR_API BOOL __stdcall NET_DVR_DecCtrlScreen(LONG lUserID, LONG lChannel, DWORD dwControl);
NET_DVR_API BOOL __stdcall NET_DVR_GetDecCurLinkStatus(LONG lUserID, LONG lChannel, LPNET_DVR_DECSTATUS lpDecStatus);

//多路解码器
//2007-11-30 V211支持以下接口
NET_DVR_API BOOL __stdcall NET_DVR_MatrixStartDynamic(LONG lUserID, DWORD dwDecChanNum, LPNET_DVR_MATRIX_DYNAMIC_DEC lpDynamicInfo);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixStopDynamic(LONG lUserID, DWORD dwDecChanNum); 
NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetDecChanInfo(LONG lUserID, DWORD dwDecChanNum, LPNET_DVR_MATRIX_DEC_CHAN_INFO lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixSetLoopDecChanInfo(LONG lUserID, DWORD dwDecChanNum, LPNET_DVR_MATRIX_LOOP_DECINFO lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetLoopDecChanInfo(LONG lUserID, DWORD dwDecChanNum, LPNET_DVR_MATRIX_LOOP_DECINFO lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixSetLoopDecChanEnable(LONG lUserID, DWORD dwDecChanNum, DWORD dwEnable);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetLoopDecChanEnable(LONG lUserID, DWORD dwDecChanNum, LPDWORD lpdwEnable);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetLoopDecEnable(LONG lUserID, LPDWORD lpdwEnable);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixSetDecChanEnable(LONG lUserID, DWORD dwDecChanNum, DWORD dwEnable);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetDecChanEnable(LONG lUserID, DWORD dwDecChanNum, LPDWORD lpdwEnable);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetDecChanStatus(LONG lUserID, DWORD dwDecChanNum, LPNET_DVR_MATRIX_DEC_CHAN_STATUS lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetVideoStandard(LONG lUserID, DWORD dwDecChanNum, LPDWORD lpdwVideoStandard);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixSetVideoStandard(LONG lUserID, DWORD dwDecChanNum, DWORD dwVideoStandard);

//2007-12-22 增加支持接口 
NET_DVR_API BOOL __stdcall NET_DVR_MatrixSetTranInfo(LONG lUserID, LPNET_DVR_MATRIX_TRAN_CHAN_CONFIG lpTranInfo);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetTranInfo(LONG lUserID, LPNET_DVR_MATRIX_TRAN_CHAN_CONFIG lpTranInfo);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixSetRemotePlay(LONG lUserID, DWORD dwDecChanNum, LPNET_DVR_MATRIX_DEC_REMOTE_PLAY lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixSetRemotePlayControl(LONG lUserID, DWORD dwDecChanNum, DWORD dwControlCode, DWORD dwInValue, DWORD *LPOutValue);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetRemotePlayStatus(LONG lUserID, DWORD dwDecChanNum, LPNET_DVR_MATRIX_DEC_REMOTE_PLAY_STATUS lpOuter);
//2009-4-13 新增
NET_DVR_API BOOL __stdcall NET_DVR_MatrixStartDynamic_V30(LONG lUserID, DWORD dwDecChanNum, LPNET_DVR_PU_STREAM_CFG lpDynamicInfo);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixSetLoopDecChanInfo_V30(LONG lUserID, DWORD dwDecChanNum, LPNET_DVR_MATRIX_LOOP_DECINFO_V30 lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetLoopDecChanInfo_V30(LONG lUserID, DWORD dwDecChanNum, LPNET_DVR_MATRIX_LOOP_DECINFO_V30 lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetDecChanInfo_V30(LONG lUserID, DWORD dwDecChanNum, LPNET_DVR_MATRIX_DEC_CHAN_INFO_V30 lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixSetTranInfo_V30(LONG lUserID, LPNET_DVR_MATRIX_TRAN_CHAN_CONFIG_V30 lpTranInfo);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetTranInfo_V30(LONG lUserID, LPNET_DVR_MATRIX_TRAN_CHAN_CONFIG_V30 lpTranInfo);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetDisplayCfg(LONG lUserID, DWORD dwDispChanNum, LPNET_DVR_VGA_DISP_CHAN_CFG lpDisplayCfg);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixSetDisplayCfg(LONG lUserID, DWORD dwDispChanNum, LPNET_DVR_VGA_DISP_CHAN_CFG lpDisplayCfg);

NET_DVR_API LONG __stdcall NET_DVR_MatrixStartPassiveDecode(LONG lUserID, DWORD dwDecChanNum, LPNET_DVR_MATRIX_PASSIVEMODE lpPassiveMode /*, void(CALLBACK *fPassiveDataCallBack)(LONG lPassiveHandle, char * pSendBuf, DWORD dwBufSize, DWORD dwStatus, DWORD dwUser), DWORD dwUser*/);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixSendData(LONG lPassiveHandle, char *pSendBuf, DWORD dwBufSize);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixStopPassiveDecode(LONG lPassiveHandle);
NET_DVR_API BOOL __stdcall NET_DVR_UploadLogo(LONG lUserID, DWORD dwDispChanNum, LPNET_DVR_DISP_LOGOCFG lpDispLogoCfg, char *sLogoBuffer);
#define	NET_DVR_SHOWLOGO			1		/*显示LOGO*/
#define	NET_DVR_HIDELOGO			2		/*隐藏LOGO*/  
NET_DVR_API BOOL __stdcall NET_DVR_LogoSwitch(LONG lUserID, DWORD dwDecChan, DWORD dwLogoSwitch);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetDeviceStatus(LONG lUserID,  LPNET_DVR_DECODER_WORK_STATUS lpDecoderCfg);

#define	DISP_CMD_ENLARGE_WINDOW				1	/*显示通道放大某个窗口*/
#define	DISP_CMD_RENEW_WINDOW				2	/*显示通道窗口还原*/
#define	DISP_CMD_OPENAUDIO			        3	/*显示通道打开音频*/
#define	DISP_CMD_CLOSEAUDIO			        4	/*显示通道关闭音频*/

NET_DVR_API BOOL __stdcall NET_DVR_MatrixDiaplayControl(LONG lUserID, DWORD dwDispChanNum, DWORD dwDispChanCmd, DWORD dwCmdParam);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixPassiveDecodeControl(LONG lUserID, DWORD dwDecChanNum, LPNET_DVR_PASSIVEDECODE_CONTROL lpInter);
NET_DVR_API LONG __stdcall NET_DVR_MatrixGetPassiveDecodeStatus(LONG lPassiveHandle);

NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetDecChanCfg(LONG lUserID, DWORD dwDecChan, LPNET_DVR_MATRIX_DECCHAN_CONTROL lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixSetDecChanCfg(LONG lUserID, DWORD dwDecChan, LPNET_DVR_MATRIX_DECCHAN_CONTROL lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_RefreshPlay(LONG lPlayHandle);
//恢复默认值
NET_DVR_API BOOL __stdcall NET_DVR_RestoreConfig(LONG lUserID);
//保存参数
NET_DVR_API BOOL __stdcall NET_DVR_SaveConfig(LONG lUserID);
//重启
NET_DVR_API BOOL __stdcall NET_DVR_RebootDVR(LONG lUserID);
//关闭DVR
NET_DVR_API BOOL __stdcall NET_DVR_ShutDownDVR(LONG lUserID);

//参数配置 begin
NET_DVR_API BOOL __stdcall NET_DVR_GetDVRConfig(LONG lUserID, DWORD dwCommand,LONG lChannel, LPVOID lpOutBuffer, DWORD dwOutBufferSize, LPDWORD lpBytesReturned);
NET_DVR_API BOOL __stdcall NET_DVR_SetDVRConfig(LONG lUserID, DWORD dwCommand,LONG lChannel, LPVOID lpInBuffer, DWORD dwInBufferSize);
NET_DVR_API BOOL __stdcall NET_DVR_GetDVRWorkState_V30(LONG lUserID, LPNET_DVR_WORKSTATE_V30 lpWorkState);
NET_DVR_API BOOL __stdcall NET_DVR_GetDVRWorkState(LONG lUserID, LPNET_DVR_WORKSTATE lpWorkState);
NET_DVR_API BOOL __stdcall NET_DVR_SetVideoEffect(LONG lUserID, LONG lChannel, DWORD dwBrightValue, DWORD dwContrastValue, DWORD dwSaturationValue, DWORD dwHueValue);
NET_DVR_API BOOL __stdcall NET_DVR_GetVideoEffect(LONG lUserID, LONG lChannel, DWORD *pBrightValue, DWORD *pContrastValue, DWORD *pSaturationValue, DWORD *pHueValue);
NET_DVR_API BOOL __stdcall NET_DVR_ClientGetframeformat(LONG lUserID, LPNET_DVR_FRAMEFORMAT lpFrameFormat);
NET_DVR_API BOOL __stdcall NET_DVR_ClientSetframeformat(LONG lUserID, LPNET_DVR_FRAMEFORMAT lpFrameFormat);
NET_DVR_API BOOL __stdcall NET_DVR_GetAtmFrameFormat_V30(LONG lUserID, LONG lAtmChannel, LPNET_DVR_ATM_FRAMEFORMAT_V30 lpFrameFormat);
NET_DVR_API BOOL __stdcall NET_DVR_SetAtmFrameFormat_V30(LONG lUserID, LONG lAtmChannel, LPNET_DVR_ATM_FRAMEFORMAT_V30 lpFrameFormat);
NET_DVR_API BOOL __stdcall NET_DVR_GetAtmProtocol(LONG lUserID, LPNET_DVR_ATM_PROTOCOL lpAtmProtocol);
NET_DVR_API BOOL __stdcall NET_DVR_GetAlarmOut_V30(LONG lUserID, LPNET_DVR_ALARMOUTSTATUS_V30 lpAlarmOutState);
NET_DVR_API BOOL __stdcall NET_DVR_GetAlarmOut(LONG lUserID, LPNET_DVR_ALARMOUTSTATUS lpAlarmOutState);
NET_DVR_API BOOL __stdcall NET_DVR_SetAlarmOut(LONG lUserID, LONG lAlarmOutPort,LONG lAlarmOutStatic);

//视频参数调节
NET_DVR_API BOOL __stdcall NET_DVR_ClientSetVideoEffect(LONG lRealHandle,DWORD dwBrightValue,DWORD dwContrastValue, DWORD dwSaturationValue,DWORD dwHueValue);
NET_DVR_API BOOL __stdcall NET_DVR_ClientGetVideoEffect(LONG lRealHandle,DWORD *pBrightValue,DWORD *pContrastValue, DWORD *pSaturationValue,DWORD *pHueValue);

//配置文件
NET_DVR_API BOOL __stdcall NET_DVR_GetConfigFile(LONG lUserID, char *sFileName);
NET_DVR_API BOOL __stdcall NET_DVR_SetConfigFile(LONG lUserID, char *sFileName);
NET_DVR_API BOOL __stdcall NET_DVR_GetConfigFile_V30(LONG lUserID, char *sOutBuffer, DWORD dwOutSize, DWORD *pReturnSize);

NET_DVR_API BOOL __stdcall NET_DVR_GetConfigFile_EX(LONG lUserID, char *sOutBuffer, DWORD dwOutSize);
NET_DVR_API BOOL __stdcall NET_DVR_SetConfigFile_EX(LONG lUserID, char *sInBuffer, DWORD dwInSize);

//启用日志文件写入接口
NET_DVR_API BOOL __stdcall NET_DVR_SetLogToFile(DWORD nLogLevel = 0, char * strLogDir = NULL, BOOL bAutoDel = TRUE);
NET_DVR_API BOOL __stdcall NET_DVR_GetSDKState(LPNET_DVR_SDKSTATE pSDKState);
NET_DVR_API BOOL __stdcall NET_DVR_GetSDKAbility(LPNET_DVR_SDKABL pSDKAbl);
NET_DVR_API BOOL __stdcall NET_DVR_GetPTZProtocol(LONG lUserID, NET_DVR_PTZCFG *pPtzcfg);
//前面板锁定
NET_DVR_API BOOL __stdcall NET_DVR_LockPanel(LONG lUserID);
NET_DVR_API BOOL __stdcall NET_DVR_UnLockPanel(LONG lUserID);

NET_DVR_API BOOL __stdcall NET_DVR_SetRtspConfig(LONG lUserID, DWORD dwCommand, LPNET_DVR_RTSPCFG lpInBuffer, DWORD dwInBufferSize);
NET_DVR_API BOOL __stdcall NET_DVR_GetRtspConfig(LONG lUserID, DWORD dwCommand, LPNET_DVR_RTSPCFG lpOutBuffer, DWORD dwOutBufferSize);

//能力集获取
NET_DVR_API BOOL __stdcall NET_DVR_GetDeviceAbility(LONG lUserID, DWORD dwAbilityType, char* pInBuf, DWORD dwInLength, char* pOutBuf, DWORD dwOutLength);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetSubSystemInfo(LONG lUserID, LPNET_DVR_ALLSUBSYSTEMINFO lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixSetSubSystemInfo(LONG lUserID, LPNET_DVR_ALLSUBSYSTEMINFO lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetCodeSplitter(LONG lUserID, DWORD dwCodeChan, LPNET_DVR_CODESPLITTERINFO lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixSetCodeSplitter(LONG lUserID, DWORD dwCodeChan, LPNET_DVR_CODESPLITTERINFO lpInter);

//智能
//设置/获取参数关键字
NET_DVR_API BOOL __stdcall NET_DVR_SetBehaviorParamKey(LONG lUserID, LONG lChannel, DWORD dwParameterKey,int nValue);
NET_DVR_API BOOL __stdcall NET_DVR_GetBehaviorParamKey(LONG lUserID, LONG lChannel, DWORD dwParameterKey,int *pValue);

//获取/设置行为分析目标叠加接口
NET_DVR_API BOOL __stdcall NET_DVR_GetVCADrawMode(LONG lUserID, LONG lChannel, LPNET_VCA_DRAW_MODE lpDrawMode);
NET_DVR_API BOOL __stdcall NET_DVR_SetVCADrawMode(LONG lUserID, LONG lChannel, LPNET_VCA_DRAW_MODE lpDrawMode);

//球机跟踪模式设置接口
NET_DVR_API BOOL __stdcall NET_DVR_SetTrackMode(LONG lUserID, LONG lChannel, LPNET_DVR_TRACK_MODE lpTrackMode);
NET_DVR_API BOOL __stdcall NET_DVR_GetTrackMode(LONG lUserID, LONG lChannel, LPNET_DVR_TRACK_MODE lpTrackMode);

//重启智能库
NET_DVR_API BOOL __stdcall NET_VCA_RestartLib(LONG lUserID, LONG lChannel);

NET_DVR_API BOOL __stdcall NET_DVR_SaveRealData_V30(LONG lRealHandle, DWORD dwTransType, char *sFileName);

NET_DVR_API BOOL __stdcall NET_DVR_EncodeG711Frame(DWORD iType, BYTE *pInBuffer, BYTE *pOutBuffer);
NET_DVR_API BOOL __stdcall NET_DVR_DecodeG711Frame(DWORD iType, BYTE *pInBuffer, BYTE *pOutBuffer);
NET_DVR_API LONG __stdcall NET_DVR_FindFileByEvent(LONG lUserID, LPNET_DVR_SEARCH_EVENT_PARAM  lpSearchEventParam);
NET_DVR_API LONG __stdcall NET_DVR_FindNextEvent(LONG lSearchHandle, LPNET_DVR_SEARCH_EVENT_RET lpSearchEventRet);
//停止采用 NET_DVR_FindClose

NET_DVR_API LONG __stdcall NET_DVR_FindPDCInfo(LONG lUserID, LONG lChannel, LPNET_DVR_TIME lpStartTime, LPNET_DVR_TIME lpStopTime);
NET_DVR_API LONG __stdcall NET_DVR_FindNextPDCInfo(LONG lFindHandle,LPNET_DVR_PDC_QUERY lpFindData);
NET_DVR_API BOOL __stdcall NET_DVR_FindPDCClose(LONG lFindHandle);

// 标定校验 
#define NET_DVR_PDC_VERIFY_CALIBRATION          1  //当值为1是为PDC标定校验 pdc传入值为NET_VCA_POINT   传出值为 NET_VCA_RECT结构
#define NET_DVR_VERIFY_BEHAVIOR_CALIBRATION     2    // 行为分析标定线校验 
#define NET_DVR_VERIFY_ITS_CALIBRATION		    3 	// 智能交通标定校验 

NET_DVR_API BOOL __stdcall  NET_DVR_VerifyCalibration(LONG lUserID, DWORD dwCommand, LONG lChannel, LPVOID lpInBuffer, DWORD dwInBufferSize, LPVOID lpOuterBuffer, DWORD dwOuterBufferSize);
NET_DVR_API BOOL __stdcall  NET_DVR_ResetCounter(LONG lUserID,LONG lChannel);

NET_DVR_API BOOL __stdcall NET_DVR_GetPtzPosition(LONG lUserID, LONG lChannel, LONG lPositionID, LPNET_DVR_PTZ_POSITION lpPtzPosition);
NET_DVR_API BOOL __stdcall NET_DVR_SetPtzPosition(LONG lUserID, LONG lChannel, LONG lPositionID, LPNET_DVR_PTZ_POSITION lpPtzPosition);
NET_DVR_API BOOL __stdcall NET_DVR_SetPatrolTrack(LONG lUserID, LONG lChannel, LONG lPatrolIndex, LPNET_DVR_PATROL_TRACKCFG lpPatrolTrack);
NET_DVR_API BOOL __stdcall NET_DVR_GetPatrolTrack(LONG lUserID, LONG lChannel, LONG lPatrolIndex, LPNET_DVR_PATROL_TRACKCFG lpPatrolTrack);
NET_DVR_API LONG __stdcall NET_DVR_FindNextLog_MATRIX(LONG lLogHandle, LPNET_DVR_LOG_MATRIX lpLogData);
NET_DVR_API LONG __stdcall NET_DVR_FindDVRLog_Matrix(LONG lUserID, LONG lSelectMode, DWORD dwMajorType, DWORD dwMinorType, LPNET_DVR_VEDIOPLATLOG lpVedioPlatLog, LPNET_DVR_TIME lpStartTime, LPNET_DVR_TIME lpStopTime);

NET_DVR_API BOOL __stdcall NET_DVR_ManualSnap(LONG lUserID, LPNET_DVR_MANUALSNAP lpInter, LPNET_DVR_PLATE_RESULT lpOuter);
NET_DVR_API BOOL __stdcall NET_DVR_ContinuousShoot(LONG lUserID, LPNET_DVR_SNAPCFG lpInter);

NET_DVR_API BOOL __stdcall NET_DVR_GetPTZProtocol_Ex(LONG lUserID, LONG lChannel, NET_DVR_PTZCFG *pPtzcfg);

NET_DVR_API LONG __stdcall NET_DVR_StartEmailTest(LONG lUserID);
NET_DVR_API BOOL __stdcall NET_DVR_StopEmailTest(LONG lEmailTestHandle);
NET_DVR_API BOOL __stdcall NET_DVR_GetEmailTestProgress(LONG lEmailTestHandle, DWORD* pState);
NET_DVR_API BOOL __stdcall NET_DVR_GetIPCProtoList(LONG lUserID, LPNET_DVR_IPC_PROTO_LIST lpProtoList);
NET_DVR_API LONG __stdcall NET_DVR_SmartSearch(LONG lUserID,  LPNET_DVR_SMART_SEARCH_PARAM lpSmartSearchParam);
NET_DVR_API LONG __stdcall NET_DVR_SearchNextInfo(LONG lSearchHandle, LPNET_DVR_SMART_SEARCH_RET lpSmartSearchRet);
NET_DVR_API BOOL __stdcall NET_DVR_StopSearch(LONG lSearchHandle);

// IP San 文件目录查找
NET_DVR_API LONG __stdcall NET_DVR_FindIpSanDirectory(LONG lUserID, LPNET_DVR_IPSAN_SERACH_PARAM lpIpsanSearchParam);
NET_DVR_API LONG __stdcall NET_DVR_FindNextDirectory(LONG lFindHandle, LPNET_DVR_IPSAN_SERACH_RET lpFindData);
NET_DVR_API BOOL __stdcall NET_DVR_FindDirectoryClose(LONG lFindHandle);

typedef void (CALLBACK *REALDATACALLBACK) (LONG lPlayHandle, DWORD dwDataType, BYTE *pBuffer, DWORD dwBufSize, void* pUser);

NET_DVR_API LONG __stdcall NET_DVR_ZeroStartPlay(LONG lUserID, LPNET_DVR_CLIENTINFO lpClientInfo, REALDATACALLBACK fRealDataCallBack_V30 = NULL, void* pUser = NULL, BOOL bBlocked = TRUE);

NET_DVR_API BOOL __stdcall NET_DVR_ZeroStopPlay(LONG lPlayHandle);
NET_DVR_API BOOL __stdcall NET_DVR_ZeroMakeKeyFrame(LONG lUserID, LONG lZeroChan);
NET_DVR_API BOOL __stdcall NET_DVR_PlayBackControl_V40(LONG lPlayHandle,DWORD dwControlCode, LPVOID lpInBuffer = NULL, DWORD dwInLen = 0, LPVOID lpOutBuffer = NULL, DWORD *lpOutLen = NULL);
NET_DVR_API BOOL __stdcall NET_DVR_ZeroTurnOver(LONG lUserID, LONG lChannel, BOOL bNextPreview);

NET_DVR_API BOOL __stdcall NET_DVR_GetDiskList(LONG lUserID, LPNET_DVR_DISKABILITY_LIST lpDiskList);
NET_DVR_API LONG __stdcall NET_DVR_Backup(LONG lUserID, DWORD dwBackupType, LPVOID lpBackupBuff, DWORD dwBackupBuffSize);
NET_DVR_API LONG __stdcall NET_DVR_BackupByName(LONG lUserID, LPNET_DVR_BACKUP_NAME_PARAM lpBackupByName);
NET_DVR_API LONG __stdcall NET_DVR_BackupByTime(LONG lUserID, LPNET_DVR_BACKUP_TIME_PARAM lpBackupBytime);
NET_DVR_API BOOL __stdcall NET_DVR_GetBackupProgress(LONG lHandle, DWORD* pState);
NET_DVR_API BOOL __stdcall NET_DVR_StopBackup(LONG lHandle);

NET_DVR_API BOOL __stdcall NET_DVR_GetSadpInfoList(LONG lUserID, LPNET_DVR_SADPINFO_LIST lpSadpInfoList);
NET_DVR_API BOOL __stdcall NET_DVR_UpdateSadpInfo(LONG lUserID, LPNET_DVR_SADP_VERIFY lpSadpVerify, LPNET_DVR_SADPINFO lpSadpInfo);

NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetSubDecSystemJoinInfo(LONG lUserID, LPNET_DVR_ALLDECSUBSYSTEMJOININFO lpInter);

NET_DVR_API BOOL __stdcall NET_DVR_SetCodeSplitterAssociate(LONG lUserID, DWORD dwDecoderChan, DWORD dwSlotNum, LPNET_DVR_CODESPLITTERASSOCIATE lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_GetCodeSplitterAssociate(LONG lUserID, DWORD dwDecoderChan, DWORD dwSlotNum, LPNET_DVR_CODESPLITTERASSOCIATE lpInter);

NET_DVR_API BOOL __stdcall NET_DVR_InquestGetCDRWScheme(LONG lUserID, LPNET_DVR_INQUEST_CDRW_CFG lpCDRWCfg);
NET_DVR_API BOOL __stdcall NET_DVR_InquestSetCDRWScheme(LONG lUserID, LPNET_DVR_INQUEST_CDRW_CFG lpCDRWCfg);
NET_DVR_API BOOL __stdcall NET_DVR_InquestDeleteFile(LONG lUserID, LPNET_DVR_INQUEST_FILES lpDeleteFile);
NET_DVR_API BOOL __stdcall NET_DVR_InquestCDWByFile(LONG lUserID, LPNET_DVR_INQUEST_FILES lpCdrwFile);
NET_DVR_API LONG __stdcall NET_DVR_InquestUploadFile(LONG lUserID, char *sFileName);
NET_DVR_API BOOL __stdcall NET_DVR_InquestUploadClose(LONG lUploadHandle);
NET_DVR_API LONG __stdcall NET_DVR_InquestGetUploadState(LONG lUploadHandle, LPDWORD pProgress);
NET_DVR_API BOOL __stdcall NET_DVR_InquestStartCDW( LONG lUserID, BOOL bPause);
NET_DVR_API BOOL __stdcall NET_DVR_InquestStopCDW(LONG lUserID, BOOL bCancelWrite);
NET_DVR_API BOOL __stdcall NET_DVR_InquestGetCDWState(LONG lUserID, LPNET_DVR_INQUEST_CDRW_STATUS pStatus);
NET_DVR_API BOOL __stdcall NET_DVR_InquestGetPIPStatus(LONG lUserID, LPNET_DVR_INQUEST_PIP_STATUS pStatus);
NET_DVR_API BOOL __stdcall NET_DVR_InquestSetPIPStatus(LONG lUserID, LPNET_DVR_INQUEST_PIP_STATUS pStatus);
NET_DVR_API BOOL __stdcall NET_DVR_InquestCheckSecretKey(LONG lUserID, BOOL *bSecretSet);
NET_DVR_API BOOL __stdcall NET_DVR_InquestSetSecretKey(LONG lUserID, LPNET_DVR_INQUEST_SECRET_INFO pSecretInfo);
NET_DVR_API BOOL __stdcall NET_DVR_InquestStreamEncrypt(LONG lUserID, LONG lChannel, BOOL bEncrypt);
NET_DVR_API BOOL __stdcall NET_DVR_InquestGetEncryptState(LONG  lUserID, LONG lChannel, BOOL *bEncrypt);
NET_DVR_API LONG __stdcall NET_DVR_InquestFindFile(LONG lUserID);
NET_DVR_API LONG __stdcall NET_DVR_InquestFindNextFile(LONG lFindHandle, LPNET_DVR_INQUEST_FILEINFO lpFindData);
NET_DVR_API BOOL __stdcall NET_DVR_InquestFindClose(LONG lFindHandle);

// 9000RH
NET_DVR_API LONG __stdcall NET_DVR_RaidFastConfig(LONG lUserID, char *sName);
NET_DVR_API BOOL __stdcall NET_DVR_FastConfigProcess(LONG lHandle, DWORD *pState);
NET_DVR_API BOOL __stdcall NET_DVR_CloseFastConfig(LONG lHandle);
NET_DVR_API BOOL __stdcall NET_DVR_GetArraySpaceAlloc(LONG lUserID, DWORD dwSlot, LPNET_DVR_ARRAY_SPACE_ALLOC_INFO lpOutBuf);
NET_DVR_API BOOL __stdcall NET_DVR_DelArray(LONG lUserID, DWORD dwID);
NET_DVR_API BOOL __stdcall NET_DVR_CreateArray(LONG lUserID, LPNET_DVR_OPERATE_ARRAY_PARAM lpArrayParam);
NET_DVR_API BOOL __stdcall NET_DVR_CalcArraySize(LONG lUserID, LPNET_DVR_OPERATE_ARRAY_PARAM lpArrayParam, UINT64* lpArraySize);
NET_DVR_API BOOL __stdcall NET_DVR_MigrateArray(LONG lUserID, LPNET_DVR_OPERATE_ARRAY_PARAM lpArrayParam);
NET_DVR_API BOOL __stdcall NET_DVR_RebuildArray(LONG lUserID, LPNET_DVR_OPERATE_ARRAY_PARAM lpArrayParam);
NET_DVR_API BOOL __stdcall NET_DVR_CreateVD(LONG lUserID, LPNET_DVR_OPERATE_VD_PARAM lpVDParam);
NET_DVR_API BOOL __stdcall NET_DVR_CreateVDEx(LONG lUserID, LPNET_DVR_OPERATE_VD_PARAM_EX lpVDParamEx);
NET_DVR_API BOOL __stdcall NET_DVR_DelVD(LONG lUserID, DWORD dwID);
NET_DVR_API BOOL __stdcall NET_DVR_RepairVD(LONG lUserID, DWORD dwID);
NET_DVR_API BOOL __stdcall NET_DVR_SetSpareDisk(LONG lUserID, LPNET_DVR_SPARE_DISK_PARAM lpSpareDisk);
NET_DVR_API BOOL __stdcall NET_DVR_GetPDList(LONG lUserID, LPNET_DVR_PHY_DISK_LIST lpPDList);
NET_DVR_API BOOL __stdcall NET_DVR_GetArrayList(LONG lUserID, LPNET_DVR_ARRAY_LIST lpArrayList);
NET_DVR_API BOOL __stdcall NET_DVR_GetVDList(LONG lUserID, LPNET_DVR_VD_LIST lpVDList);
NET_DVR_API LONG __stdcall NET_DVR_ExpandDisk(LONG lUserID,DWORD dwVDSLot);
NET_DVR_API BOOL __stdcall NET_DVR_GetExpandProgress(LONG lExpandHandle, DWORD* pState);
NET_DVR_API BOOL __stdcall NET_DVR_CloseExpandHandle(LONG lExpandHandle);
NET_DVR_API LONG __stdcall NET_DVR_AlgoDebugStart(LONG lUserID, LONG lCHannel, void(CALLBACK *fAlgoLibInfoCallBack)(LONG lHandle, LONG lChannel,char *pRecvDataBuffer, DWORD dwBufSize, void* pUser), void* pUser);
NET_DVR_API BOOL __stdcall NET_DVR_AlgoDebugSend(LONG lHandle, LONG lChannel, char *pSendBuf, DWORD dwBufSize);
NET_DVR_API BOOL __stdcall NET_DVR_AlgoDebugStop(LONG lHandle);
NET_DVR_API BOOL __stdcall NET_DVR_SetLogPrint(BOOL bLogPrint);
NET_DVR_API BOOL __stdcall NET_DVR_SetLogPrintAction(DWORD nLogLevel, DWORD nToDevice, BOOL bEnable, int Reserve1, int Reserve2);

NET_DVR_API BOOL __stdcall NET_DVR_GetPositionRule(LONG lUserID, LONG lChannel, LONG lPositionIndex, LPNET_DVR_POSITION_RULE_CFG lpPositionRule);
NET_DVR_API BOOL __stdcall NET_DVR_GetPositionRule_V41(LONG lUserID, LONG lChannel, LONG lPositionIndex, LPNET_DVR_POSITION_RULE_CFG_V41 lpPositionRule);
NET_DVR_API BOOL __stdcall NET_DVR_SetPositionRule(LONG lUserID, LONG lChannel, LONG lPositionIndex, LPNET_DVR_POSITION_RULE_CFG lpPositionRule);
NET_DVR_API BOOL __stdcall NET_DVR_SetPositionRule_V41(LONG lUserID, LONG lChannel, LONG lPositionIndex, LPNET_DVR_POSITION_RULE_CFG_V41 lpPositionRule);
NET_DVR_API BOOL __stdcall NET_DVR_SetPositionLimitAngle(LONG lUserID, LONG lChannel, LONG lPositionIndex, LPNET_DVR_LIMIT_ANGLE lpLimitAngle);
NET_DVR_API BOOL __stdcall NET_DVR_GetPositionLimitAngle(LONG lUserID, LONG lChannel, LONG lPositionIndex, LPNET_DVR_LIMIT_ANGLE lpLimitAngle);
NET_DVR_API BOOL __stdcall NET_DVR_GetPtzPosition(LONG lUserID, LONG lChannel, LONG lPositionID, LPNET_DVR_PTZ_POSITION lpPtzPosition);
NET_DVR_API BOOL __stdcall NET_DVR_SetPtzPosition(LONG lUserID, LONG lChannel, LONG lPositionID, LPNET_DVR_PTZ_POSITION lpPtzPosition);
NET_DVR_API BOOL __stdcall NET_DVR_SetPatrolTrack(LONG lUserID, LONG lChannel, LONG lPatrolIndex, LPNET_DVR_PATROL_TRACKCFG lpPatrolTrack);
NET_DVR_API BOOL __stdcall NET_DVR_GetPatrolTrack(LONG lUserID, LONG lChannel, LONG lPatrolIndex, LPNET_DVR_PATROL_TRACKCFG lpPatrolTrack);
NET_DVR_API BOOL __stdcall NET_DVR_SetPatrolLimitAngle(LONG lUserID, LONG lChannel, LONG lPatrolIndex, LPNET_DVR_LIMIT_ANGLE lpLimitAngle);
NET_DVR_API BOOL __stdcall NET_DVR_GetPatrolLimitAngle(LONG lUserID, LONG lChannel, LONG lPatrolIndex, LPNET_DVR_LIMIT_ANGLE lpLimitAngle);
NET_DVR_API BOOL __stdcall NET_DVR_SetSceneMode(LONG  lUserID, LONG lChannel, DWORD dwSceneMode);
NET_DVR_API BOOL __stdcall NET_DVR_GetSceneMode(LONG lUserID, LONG lChannel, DWORD  *pSceneMode);
NET_DVR_API BOOL __stdcall NET_DVR_GetVCAVersion(LONG lUserID, LONG lChannel, LPNET_DVR_VCA_VERSION lpVersion);

NET_DVR_API BOOL __stdcall NET_DVR_ContinuousShoot(LONG lUserID, LPNET_DVR_SNAPCFG lpInter);     
NET_DVR_API BOOL __stdcall NET_DVR_MatrixPicAdjust(LONG lUserID, DWORD dwDispChan, DWORD dwPicAdjust, DWORD dwCmdParam); 
NET_DVR_API BOOL __stdcall NET_DVR_AlarmJoinedRecord(LONG lUserID, DWORD dwChan, DWORD dwAlarmSeq, DWORD dwRecordTime, DWORD dwRes);
NET_DVR_API BOOL __stdcall NET_DVR_GetUnitedMatrixInfo(LONG lUserID, LPNET_DVR_UNITEDMATRIXINFO lpInter);
typedef LONG(CALLBACK * REGCallBack)(LONG lUserID, LPNET_DVR_REGCALLBACKPARAM pRegCallbackParam, LPNET_DVR_LOGONREPONSEPARAM pInterParam, void *pUser);
NET_DVR_API BOOL __stdcall NET_DVR_SetRegisterCallBack(REGCallBack fRegCallBack, void* pUser);
NET_DVR_API BOOL __stdcall NET_DVR_PreviewRequest(LONG lUserID, LONG lChannel, LPNET_DVR_PREVIEWPARAM lpPreviewParam, LPNET_DVR_DEVICENATINFO lpOuter);
typedef LONG(CALLBACK * PREVIEWRESPONSECallBack)(LONG lUserID, LONG lStreamHandle, LPNET_DVR_PREVIEWCALLBACKPARAM pPewviewCallbackParam,void *pUser);
NET_DVR_API BOOL __stdcall NET_DVR_SetPreviewResponseCallBack(PREVIEWRESPONSECallBack fPreviewResponseCallBack, void *pUser);
NET_DVR_API BOOL __stdcall NET_DVR_PlaybackRequest(LONG lUserID, LPNET_DVR_PLAYBACKREQUESTPARAM lpPlayBackRequestParam);
typedef LONG(CALLBACK * PLAYBACKRESPONSECallBack)(LONG lUserID, LONG lPlaybackHandle, LPNET_DVR_PLAYBACKCALLBACKPARAM lpPlaybackParam,void *pUser);     
NET_DVR_API BOOL __stdcall NET_DVR_SetPlaybackResponseCallBack(PLAYBACKRESPONSECallBack fPlaybackResponseCallBack, void *pUser);          
typedef LONG(CALLBACK * VOICERESPONSECallBack)(LONG lUserID, LONG lVoiceHandle, LONG lVoiceChannel, BYTE nAudioType, void *pUser);     
NET_DVR_API BOOL __stdcall NET_DVR_SetVoiceResponseCallBack(VOICERESPONSECallBack fVoiceResponseCallBack, void *pUser);
NET_DVR_API BOOL __stdcall NET_DVR_VoiceRequest(LONG lUserID, LPNET_DVR_VOICEREQUESTPARAM lpVoiceParam);		   
NET_DVR_API BOOL __stdcall NET_DVR_AlarmSetupRequest(LONG lUserID, LPNET_DVR_ALARMSETUPREQUESTPARAM lpAlarmSetupParam);
NET_DVR_API BOOL __stdcall NET_DVR_GetDialParam(LONG lUserID, LPNET_DVR_DIALREQUEST lpDialRequest, LPNET_DVR_DIALPARAM lpDialParam);			 		 
NET_DVR_API BOOL __stdcall NET_DVR_SetDialParam(LONG lUserID, LPNET_DVR_DIALREQUEST lpDialRequest, LPNET_DVR_DIALPARAM lpDialParam);
NET_DVR_API BOOL __stdcall NET_DVR_GetSmsListInfo(LONG lUserID, LPNET_DVR_TIME_EX lpStartTime, LPNET_DVR_TIME_EX lpStopTime, LPNET_DVR_SMSLISTINFO lpSmsListInfo);
NET_DVR_API BOOL __stdcall NET_DVR_GetSmsContent(LONG lUserID, DWORD dwSmsIndex, LPNET_DVR_SMSCONTENT lpSmsContent);
NET_DVR_API BOOL __stdcall NET_DVR_SendSms(LONG lUserID, LPNET_DVR_SMSCONTENT lpSmsContent);
NET_DVR_API LONG __stdcall NET_DVR_StartServer(char *sLocalIP, WORD wLocalPort, BYTE byMode);
NET_DVR_API BOOL __stdcall NET_DVR_StopServer(LONG lServerHandle); 
NET_DVR_API LONG __stdcall NET_DVR_StartRecvNakedDataListen(NAKED_DATA_TYPE type, LPNET_DVR_NAKED_DATA_PARAM pParams);
NET_DVR_API BOOL __stdcall NET_DVR_StopRecvNakedDataListen(LONG lNakedDataRecvHandle);          
typedef void(CALLBACK * NAKEDDAtACALLBACK)(DWORD typeInfo, char *pInfo, DWORD dwInfoLen,DWORD dwIPLen, void* pUser);
NET_DVR_API BOOL __stdcall  NET_DVR_SetNakedDataRecvCallBack(LONG lNakedDataRecvHandle, void(CALLBACK *fNakedDataCallBack)(DWORD dwTypeInfo, NET_DVR_NAKED_DATA_INFO *pStruNakedDataInfo, char *pInfo, DWORD dwInfoLen, void* pUser), void* pUser);

typedef LONG(CALLBACK * ALARMSETUPRESPONSECallBack)(LONG lUserID, LONG lAlarmHandle, void * pUser);         
NET_DVR_API BOOL __stdcall NET_DVR_SetAlarmSetupResponseCallBack(ALARMSETUPRESPONSECallBack fAlarmSetupResponseCallBack, void * pUser);
NET_DVR_API BOOL __stdcall NET_DVR_SpringJPEGPicture(LONG lUserID, LONG lChannel, NET_DVR_PUSHJPEGPARA const *lpJpegPara);
NET_DVR_API BOOL __stdcall NET_DVR_SetPushModeParam(LPNET_DVR_PUSHMODEPARAM pPushParam);

NET_DVR_API BOOL __stdcall NET_DVR_AlarmHostSetupAlarmChan(LONG lUserID, NET_DVR_ALARMIN_SETUP *lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_AlarmHostCloseAlarmChan(LONG lUserID, NET_DVR_ALARMIN_SETUP *lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_BypassAlarmChan(LONG lUserID, NET_DVR_ALARMIN_SETUP *lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_UnBypassAlarmChan(LONG lUserID, NET_DVR_ALARMIN_SETUP *lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_AlarmHostAssistantControl(LONG lUserID, DWORD dwType, DWORD dwNumber, DWORD dwCmdParam);
NET_DVR_API BOOL __stdcall NET_DVR_SetAirCondition(LONG lUserID, LONG l485Index, NET_DVR_AIR_CONDITION_PARAM* lpAirConditionParam);
NET_DVR_API BOOL __stdcall NET_DVR_GetDeviceTypeList(LONG lUserID, NET_DVR_DEVICE_TYPE_LIST *lpDeviceTypeList);
NET_DVR_API BOOL __stdcall NET_DVR_GetDeviceProtoList(LONG lUserID, LONG lDeviceType, NET_DVR_DEVICE_PROTO_LIST *lpDeviceProtoList);
NET_DVR_API BOOL __stdcall NET_DVR_GetBatteryVoltage(LONG lUserID, float *pVoltage);
NET_DVR_API BOOL __stdcall NET_DVR_SetAlarmDeviceUser(LONG lUserID, LONG lUserIndex, NET_DVR_ALARM_DEVICE_USER* lpDeviceUser);
NET_DVR_API BOOL __stdcall NET_DVR_GetAlarmDeviceUser(LONG lUserID, LONG lUserIndex, NET_DVR_ALARM_DEVICE_USER* lpDeviceUser);
NET_DVR_API BOOL __stdcall NET_DVR_SetKeyboardUser(LONG lUserID, LONG lUserIndex, NET_DVR_KEYBOARD_USER* lpKeyboardUser);
NET_DVR_API BOOL __stdcall NET_DVR_GetKeyboardUser(LONG lUserID, LONG lUserIndex, NET_DVR_KEYBOARD_USER* lpKeyboardUser);
NET_DVR_API BOOL __stdcall NET_DVR_SetOperateUser(LONG lUserID, LONG lUserIndex, NET_DVR_OPERATE_USER* lpOperateUser);
NET_DVR_API BOOL __stdcall NET_DVR_GetOperateUser(LONG lUserID, LONG lUserIndex, NET_DVR_OPERATE_USER* lpOperateUser);
NET_DVR_API BOOL __stdcall NET_DVR_ControlGateway(LONG lUserID, LONG lGatewayIndex, DWORD dwStaic);
NET_DVR_API BOOL __stdcall NET_DVR_SetAlarmHostOut(LONG lUserID, LONG lAlarmOutPort, LONG lAlarmOutStatic);
typedef void(CALLBACK *fAlarmHostSerialDataCallBack)
(LONG lSerialHandle, LONG lPort, LONG lDateType, char *pRecvDataBuffer, DWORD  dwBufSize,void *pUser);
NET_DVR_API LONG __stdcall NET_DVR_AlarmHostSerialStart(LONG lUserID, LONG lSerialType, fAlarmHostSerialDataCallBack cbSerialDataCallBack, void *pUser);
NET_DVR_API BOOL __stdcall NET_DVR_AlarmHostSerialSend(LONG lSerialHandle,LONG lPort,char *pSendBuf,DWORD dwBufSize);
NET_DVR_API BOOL __stdcall NET_DVR_AlarmHostSerialStop(LONG  lSerialHandle);
NET_DVR_API BOOL __stdcall NET_DVR_GetMatrixPuChan(LONG lUserID, LONG lChanType, NET_DVR_PU_CHAN_LIST* lpChanList);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixAlarmOffMonitor(LONG lUserID, DWORD dwMonID, DWORD dwCamID);
NET_DVR_API BOOL __stdcall NET_DVR_GetCameraListInfo(LONG lUserID, DWORD dwCamNum, DWORD dwStartCam, LPNET_DVR_MATRIX_CAMERALIST lpCamListInfo);
NET_DVR_API BOOL __stdcall NET_DVR_GetMonitorListInfo(LONG lUserID, DWORD dwMonNum, DWORD dwStartMon, LPNET_DVR_MATRIX_MONITORLIST lpMonListInfo);
NET_DVR_API BOOL __stdcall NET_DVR_GetGlobalNum(LONG lUserID, DWORD *dwCamNum, DWORD *dwMonNum); 
NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetUnitedMatrixInfo(LONG lUserID, LPNET_DVR_ALLUNITEDMATRIXINFO lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixSetUnitedMatrixInfo(LONG lUserID, LPNET_DVR_ALLUNITEDMATRIXINFO lpInter); 
NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetGatewayInfo(LONG lUserID, LPNET_DVR_MATRIXGATEWAYINFO lpInter);		 
NET_DVR_API BOOL __stdcall NET_DVR_MatrixSetGatewayInfo(LONG lUserID, LPNET_DVR_MATRIXGATEWAYINFO lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixSpanSwitch(LONG lUserID, BYTE nSwitchMode, LPNET_DVR_MATRIXSWITCH lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixStartSwitch(LONG lUserID, LPNET_DVR_MATRIXSWITCHCTRL lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixSetConfigFile(LONG lUserID, LPNET_DVR_MATRIXDATABASE lpInter, char *sInBuffer,  DWORD dwInSize);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetConfigFile(LONG lUserID, LPNET_DVR_MATRIXDATABASE lpInter, char  *sOutBuffer,  DWORD   dwOutSize,  DWORD   *pReturnSize);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetSubSystemInfo_V40(LONG lUserID, LPNET_DVR_ALLSUBSYSTEMINFO_V40 lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixSetSubSystemInfo_V40(LONG lUserID, LPNET_DVR_ALLSUBSYSTEMINFO_V40 lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetSubDecSystemJoinInfo_V40(LONG lUserID, LPNET_DVR_ALLDECSUBSYSTEMJOININFO_V40 lpInter);
typedef void (CALLBACK *FLOWTESTCALLBACK)(LONG lFlowHandle, LPNET_DVR_FLOW_INFO pFlowInfo, void *pUser);
NET_DVR_API LONG __stdcall NET_DVR_StartNetworkFlowTest(LONG lUserID, NET_DVR_FLOW_TEST_PARAM* pFlowTest,  FLOWTESTCALLBACK fFlowTestCallback, void *pUser);
NET_DVR_API BOOL __stdcall NET_DVR_StopNetworkFlowTest(LONG lHandle);
NET_DVR_API LONG __stdcall NET_DVR_FindRecordLabel(LONG lUserID, LPNET_DVR_FIND_LABEL lpFindLabel);
NET_DVR_API LONG __stdcall NET_DVR_FindNextLabel(LONG lFindHandle, LPNET_DVR_FINDLABEL_DATA lpFindData);
NET_DVR_API BOOL __stdcall NET_DVR_StopFindLabel(LONG lFindHandle);
NET_DVR_API BOOL __stdcall NET_DVR_InsertRecordLabel(LONG lPlayHandle, NET_DVR_RECORD_LABEL* lpRecordLabel, NET_DVR_LABEL_IDENTIFY *lpLableIdentify);
NET_DVR_API BOOL __stdcall NET_DVR_DelRecordLabel(LONG lUserID, NET_DVR_DEL_LABEL_PARAM* lpDelLabelParam);
NET_DVR_API BOOL __stdcall NET_DVR_ModifyRecordLabel(LONG lUserID, NET_DVR_MOD_LABEL_PARAM * lpModLabelParam);
NET_DVR_API LONG __stdcall NET_DVR_FindPicture(LONG lUserID, NET_DVR_FIND_PICTURE_PARAM* pFindParam);
NET_DVR_API LONG __stdcall NET_DVR_FindNextPicture(LONG lFindHandle,LPNET_DVR_FIND_PICTURE lpFindData);
NET_DVR_API BOOL __stdcall NET_DVR_CloseFindPicture(LONG lFindHandle);
NET_DVR_API BOOL __stdcall NET_DVR_GetPicture(LONG lUserID,char *sDVRFileName,const char *sSavedFileName);
NET_DVR_API BOOL __stdcall NET_DVR_GetPicture_V30(LONG lUserID, char *sDVRFileName, char *sSavedFileBuf, DWORD dwBufLen, DWORD *lpdwRetLen);
NET_DVR_API LONG __stdcall NET_DVR_BackupPicture(LONG lUserID, NET_DVR_BACKUP_PICTURE_PARAM *lpBackupPicture);
NET_DVR_API LONG __stdcall NET_DVR_GetUpgradeStep(LONG lUpgradeHandle, LONG *pSubProgress);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetEncodeJoint(LONG lUserID, LONG lChannel, LPNET_DVR_ENCODE_JOINT_PARAM lpEncodeJoint);
NET_DVR_API BOOL  __stdcall NET_DVR_GetLocalIP(char strIP[16][16], DWORD *pValidNum, BOOL *pEnableBind);
NET_DVR_API BOOL  __stdcall NET_DVR_SetValidIP(DWORD dwIPIndex, BOOL bEnableBind);
NET_DVR_API BOOL __stdcall NET_DVR_GetVcaDevWorkState(LONG lUserID, LPNET_DVR_VCA_DEV_WORKSTATUS lpWorkState);
NET_DVR_API BOOL  __stdcall NET_DVR_SetRecvTimeOut(DWORD nRecvTimeOut = 5000); //最小3000毫秒
NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetDisplayCfg_V40(LONG lUserID, DWORD dwDispChanNum, LPNET_DVR_VGA_DISP_CHAN_CFG_V40 lpDisplayCfg);			  
NET_DVR_API BOOL __stdcall NET_DVR_MatrixSetDisplayCfg_V40(LONG lUserID, DWORD dwDispChanNum, LPNET_DVR_VGA_DISP_CHAN_CFG_V40 lpDisplayCfg);
NET_DVR_API BOOL __stdcall NET_DVR_ShutterCompensation(LONG lUserID);
NET_DVR_API BOOL __stdcall NET_DVR_CorrectDeadPixel(LONG lUserID, LONG lChannel, LPNET_DVR_CORRECT_DEADPIXEL_PARAM lpInParam);
NET_DVR_API BOOL __stdcall NET_DVR_CustomConfig(LONG lUserID, LONG lChannel, LPVOID lpInBuffer, DWORD dwInBufferSize, LPVOID lpOutBuffer, DWORD dwOutBufferSize, LPDWORD lpBytesReturned);
NET_DVR_API BOOL __stdcall NET_DVR_GetHistoricDataInfo(LONG lUserID, LONG lChannel, LPNET_DVR_HISTORICDATACFG lpHisData);
NET_DVR_API BOOL __stdcall NET_DVR_GetHistoricData(LONG lUserID, LONG lChannel, LPNET_DVR_PLATE_RESULT lpOuter);
NET_DVR_API BOOL __stdcall NET_DVR_ClearHistoricData(LONG lUserID, LONG lChannel);
NET_DVR_API LONG  __stdcall NET_DVR_InquestUploadFile_V30(LONG lUserID, LPNET_DVR_INQUEST_ROOM lpInquestRoom,  char *sFileName);
NET_DVR_API BOOL  __stdcall NET_DVR_InquestDeleteFile_V30(LONG lUserID, LPNET_DVR_INQUEST_ROOM lpInquestRoom, LPNET_DVR_INQUEST_FILES lpDeleteFile);
NET_DVR_API BOOL  __stdcall NET_DVR_InquestGetPIPStatus_V30(LONG lUserID, LPNET_DVR_INQUEST_ROOM lpInquestRoom, LPNET_DVR_INQUEST_PIP_STATUS lpStatus);
NET_DVR_API BOOL  __stdcall NET_DVR_InquestSetPIPStatus_V30(LONG lUserID, LPNET_DVR_INQUEST_ROOM lpInquestRoom, LPNET_DVR_INQUEST_PIP_STATUS lpStatus);
NET_DVR_API BOOL __stdcall NET_DVR_InquestGetPIPStatus_V40(LONG lUserID, NET_DVR_INQUEST_ROOM const *lpInquestRoom, LPNET_DVR_INQUEST_PIP_STATUS_V40 lpStatus);
NET_DVR_API BOOL __stdcall NET_DVR_InquestSetPIPStatus_V40(LONG lUserID, NET_DVR_INQUEST_ROOM const *lpInquestRoom, LPNET_DVR_INQUEST_PIP_STATUS_V40 lpStatus);
NET_DVR_API BOOL  __stdcall NET_DVR_InquestGetSystemInfo(LONG lUserID, LPNET_DVR_INQUEST_SYSTEM_INFO lpSystemInfo);
NET_DVR_API BOOL  __stdcall NET_DVR_InquestSetSystemInfo(LONG lUserID, LPNET_DVR_INQUEST_SYSTEM_INFO lpSystemInfo);
NET_DVR_API BOOL  __stdcall NET_DVR_InquestSendMessage(LONG lUserID, LPNET_DVR_INQUEST_ROOM lpInquestRoom, LPNET_DVR_INQUEST_MESSAGE lpInquestMessage);
NET_DVR_API BOOL  __stdcall NET_DVR_InquestStartCDW_V30(LONG lUserID, LPNET_DVR_INQUEST_ROOM lpInquestRoom, BOOL bNotBurn);
NET_DVR_API BOOL  __stdcall NET_DVR_InquestStopCDW_V30(LONG lUserID, LPNET_DVR_INQUEST_ROOM lpInquestRoom, BOOL bCancelWrite);
NET_DVR_API BOOL  __stdcall NET_DVR_InquestGetCDWState_V30(LONG lUserID, LPNET_DVR_INQUEST_ROOM lpInquestRoom, LPNET_DVR_INQUEST_CDRW_STATUS pStatus);
NET_DVR_API LONG  __stdcall NET_DVR_InquestResumeEvent(LONG lUserID, LPNET_DVR_INQUEST_RESUME_EVENT lpResumeEvent);
NET_DVR_API BOOL  __stdcall NET_DVR_InquestGetResumeProgress(LONG lHandle, DWORD* pState);
NET_DVR_API BOOL  __stdcall NET_DVR_InquestStopResume(LONG lHandle);
NET_DVR_API LONG  __stdcall NET_DVR_InquestFindFile_V30(LONG lUserID, LPNET_DVR_INQUEST_ROOM pInquestRoom);
NET_DVR_API BOOL  __stdcall NET_DVR_InquestGetDeviceVersion(LONG lUserID, LPNET_DVR_INQUEST_DEVICE_VERSION lpVersionInfo);
NET_DVR_API BOOL  __stdcall NET_DVR_SetSDKSecretKey(LONG lUserID, char *sSecretKey);
NET_DVR_API BOOL __stdcall NET_DVR_LockFileByTime(LONG lUserID, LPNET_DVR_TIME_LOCK lpLockPara, LPNET_DVR_LOCK_RETURN lpLockReturn);
NET_DVR_API BOOL __stdcall NET_DVR_UnlockFileByTime(LONG lUserID, LPNET_DVR_TIME_LOCK lpLockPara, LPNET_DVR_LOCK_RETURN lpLockReturn);
NET_DVR_API BOOL __stdcall NET_DVR_ScreenZoomIn(LONG lUserID, LPNET_DVR_SCREENZOOM pStruScreen);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetAllCameraInfo(LONG lUserID, LPNET_DVR_MATRIX_CAMERALIST lpCamListInfo);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetSingleCameraInfo(LONG lUserID, DWORD dwCameraId, LPNET_MATRIX_CAMERAINFO lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixAddCamera(LONG lUserID, DWORD dwCameraNum, BYTE *pBuffer, DWORD dwBufLength);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixModCameraInfo(LONG lUserID, LPNET_MATRIX_CAMERAINFO lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixDelCamera(LONG lUserID, DWORD dwCameraId);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetAllMonitorInfo(LONG lUserID, LPNET_DVR_MATRIX_MONITORLIST lpMonListInfo);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetSingleMonitorInfo(LONG lUserID, DWORD dwMonitorId, LPNET_MATRIX_MONITORINFO lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixAddMonitor(LONG lUserID, DWORD dwMonitorNum, BYTE *pBuffer, DWORD dwBufLength);			
NET_DVR_API BOOL __stdcall NET_DVR_MatrixModMonitorInfo(LONG lUserID, LPNET_MATRIX_MONITORINFO lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixDelMonitor(LONG lUserID, DWORD dwMonitorId);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetAllMatrixInfo(LONG lUserID, LPNET_DVR_MATRIXLIST lpMatrixListInfo);
NET_DVR_API BOOL __stdcall NET_DVR_GetSingleMatrixInfo(LONG lUserID, DWORD dwMatrixId, LPNET_MATRIX_MATRIXINFO lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_AddMatrix(LONG lUserID, LPNET_MATRIX_MATRIXINFO lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_ModMatrixInfo(LONG lUserID, LPNET_MATRIX_MATRIXINFO lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_DelMatrix(LONG lUserID, DWORD dwMatrixId);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetUartParam(LONG lUserID, DWORD dwSerialChan, LPNET_MATRIX_UARTPARAM lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixSetUartParam(LONG lUserID, DWORD dwSerialChan , LPNET_MATRIX_UARTPARAM lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetUserInfo(LONG lUserID, DWORD dwUserNum, LPNET_MATRIX_USERPARAM lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixAddUser(LONG lUserID, DWORD dwUserNum, LPNET_MATRIX_USERPARAM lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixModUserInfo(LONG lUserID, DWORD dwUserNum, LPNET_MATRIX_USERPARAM lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixDelUser(LONG lUserID, DWORD dwUserNum);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetResourceInfo(LONG lUserID, DWORD dwResourceNum, LPNET_MATRIX_RESOURSEGROUPPARAM lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixAddResourceInfo(LONG lUserID, DWORD dwResourceNum, LPNET_MATRIX_RESOURSEGROUPPARAM lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixModResourceInfo(LONG lUserID, DWORD dwResourceNum, LPNET_MATRIX_RESOURSEGROUPPARAM lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixDelResourceInfo(LONG lUserID, DWORD dwResourceNum);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetUserGroupInfo(LONG lUserID, DWORD dwUserGroupNum, LPNET_MATRIX_USERGROUPPARAM lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixAddUserGroupInfo(LONG lUserID, DWORD dwUserGroupNum, LPNET_MATRIX_USERGROUPPARAM lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixModUserGroupInfo(LONG lUserID, DWORD dwUserGroupNum, LPNET_MATRIX_USERGROUPPARAM lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixDelUserGroup (LONG lUserID, DWORD dwUserGroupNum);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetAllTrunkInfo(LONG lUserID, LPNET_DVR_MATRIX_TRUNKLIST lpTrunkListInfo);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetTrunkInfo(LONG lUserID, DWORD dwTrunkNum, LPNET_MATRIX_TRUNKPARAM lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixAddTrunk(LONG lUserID, LPNET_MATRIX_TRUNKPARAM lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixModTrunkInfo(LONG lUserID, LPNET_MATRIX_TRUNKPARAM lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixTrunkCtrl(LONG lUserID, DWORD dwTrunkNum, BYTE byCtrlMode);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixTrunkStatusQuery(LONG lUserID, DWORD dwTrunkNum, BYTE *byTrunkStatus);

NET_DVR_API BOOL __stdcall NET_DVR_FindBackgroundPic(LONG lUserID, DWORD dwPicID, BYTE *pPicBuffer, DWORD *lpPicLen);
NET_DVR_API BOOL __stdcall NET_DVR_DetectImage(LONG lUserID, LPNET_VCA_FD_PROCIMG_CFG lpFDProcImg,LPNET_VCA_FD_PROCIMG_RESULT lpOutBuf);
NET_DVR_API BOOL __stdcall NET_DVR_GetPictureModel(LONG lUserID, LPNET_VCA_REGISTER_PIC lpInBuf, LPNET_VCA_PICMODEL_RESULT lpOutBuf);
NET_DVR_API BOOL __stdcall NET_DVR_AddBlackList(LONG lUserID,LONG lChannel,LPNET_VCA_BLACKLIST_PARA lpInter);
NET_DVR_API LONG __stdcall NET_DVR_FindBlackList(LONG lUserID, LPNET_VCA_BLACKLIST_COND lpBlackListCond);
NET_DVR_API LONG __stdcall NET_DVR_FindNextBlackList(LONG lFindHandle,LPNET_VCA_BLACKLIST_INFO lpFindData);
NET_DVR_API BOOL __stdcall NET_DVR_FindBlackListClose(LONG lFindHandle);
NET_DVR_API BOOL __stdcall NET_DVR_GetBlackListPicture(LONG lUserID, DWORD dwRegisterID, LPNET_VCA_BLACKLIST_PIC lpOutBuffer);
NET_DVR_API BOOL __stdcall NET_DVR_UpdateBlackList(LONG lUserID,LONG lChannel, LPNET_VCA_BLACKLIST_PARA lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_DelBlackList(LONG lUserID,LONG lChannel, DWORD dwRegisterID);
NET_DVR_API LONG __stdcall NET_DVR_FindSnapPicture(LONG lUserID, LPNET_VCA_FIND_PICTURECOND lpFindParam);
NET_DVR_API LONG __stdcall NET_DVR_FindNextSnapPic(LONG lFindHandle,LPNET_VCA_SUB_SNAPPIC_DATA lpFindData);
NET_DVR_API BOOL __stdcall NET_DVR_FindSnapPicClose(LONG lFindHandle);
NET_DVR_API LONG __stdcall NET_DVR_AdvanceFindSnapPicture(LONG lUserID, LPNET_VCA_FIND_PICTURECOND_ADVANCE lpFindParam);
NET_DVR_API LONG __stdcall NET_DVR_FindFaceMatchAlarm(LONG lUserID, LPNET_VCA_FIND_PICTURECOND lpFindParam);
NET_DVR_API LONG __stdcall NET_DVR_FindNextFaceMatchAlarm(LONG lFindHandle, LPNET_VCA_FACESNAP_MATCH_ALARM_LOG lpFaceMatchAlarmLog);
NET_DVR_API BOOL __stdcall NET_DVR_FindFaceMatchAlarmClose(LONG lFindHandle);
NET_DVR_API BOOL __stdcall NET_DVR_GetFaceMatchPic(LONG lUserID, LPNET_VCA_FACEMATCH_PICCOND lpMatchCond, LPNET_VCA_FACEMATCH_PICTURE lpMatchPic);
NET_DVR_API BOOL __stdcall NET_DVR_FastAddBlackList(LONG lUserID,LONG lChannel,LPNET_VCA_BLACKLIST_FASTREGISTER_PARA lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixSetRemotePlay_V41(LONG lUserID, DWORD dwDecChanNum, LPNET_DVR_MATRIX_DEC_REMOTE_PLAY_V41 lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetDisplayCfg_V41(LONG lUserID, DWORD dwDispChanNum, LPNET_DVR_MATRIX_VOUTCFG lpVoutCfg);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixSetDisplayCfg_V41(LONG lUserID, DWORD dwDispChanNum, LPNET_DVR_MATRIX_VOUTCFG lpDisplayCfg);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetDeviceStatus_V41(LONG lUserID, LPNET_DVR_DECODER_WORK_STATUS_V41 lpDecoderCfg);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetSceneCfg(LONG lUserID, DWORD dwSceneNum, LPNET_DVR_MATRIX_SCENECFG lpSceneCfg);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixSetSceneCfg(LONG lUserID, DWORD dwSceneNum, LPNET_DVR_MATRIX_SCENECFG lpSceneCfg);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixSceneControl(LONG lUserID, DWORD dwSceneNum, DWORD dwCmd, DWORD dwCmdParam);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetCurrentSceneMode(LONG lUserID, DWORD *dwSceneNum);
NET_DVR_API BOOL __stdcall NET_DVR_GetAllValidWinInfo(LONG lUserID, LPNET_DVR_WINLIST lpWinListInfo);
NET_DVR_API BOOL __stdcall NET_DVR_ScreenWinCtrl(LONG lUserID, DWORD dwWinIndex, DWORD dwCommand, LPNET_DVR_SCREEN_WINCFG lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_GetScreenInputStatus(LONG lUserID, LPNET_DVR_SCREENINPUTSTATUS lpStatus);
NET_DVR_API LONG __stdcall NET_DVR_PicUpload(LONG lUserID, char const *sFileName, LPNET_DVR_PICTURECFG lpPictureCfg);
NET_DVR_API LONG __stdcall NET_DVR_GetPicUploadProgress(LONG lUploadHandle);
NET_DVR_API BOOL __stdcall  NET_DVR_CloseUploadHandle(LONG lUploadHandle);		
NET_DVR_API BOOL __stdcall NET_DVR_PicControl(LONG lUserID, BYTE byUseType, BYTE byPicIndex, BYTE byCtrlCmd);
NET_DVR_API LONG __stdcall NET_DVR_GetPicUploadState(LONG lUploadHandle);
NET_DVR_API BOOL __stdcall NET_DVR_ScreenCtrl(LONG lUserID, DWORD dwDeviceNum, LPNET_DVR_SCREEN_CONTROL lpStruScreenCtrl);
typedef void (CALLBACK *SCREENPICDATACB)(LONG nScreenPicHandle, DWORD dwDataType, BYTE *pBuffer, DWORD dwBufSize, void *pUser);
NET_DVR_API LONG __stdcall NET_DVR_StartScreenPic(LONG nUserID, DWORD nInputNum, SCREENPICDATACB PicDataCallback, void *pUserData);
NET_DVR_API BOOL __stdcall NET_DVR_StopScreenPic(LONG nScreenPicHandle);
NET_DVR_API BOOL __stdcall NET_DVR_FocusOnePush(LONG lUserID, LONG lChannel);
NET_DVR_API BOOL __stdcall NET_DVR_ResetLens(LONG lUserID, LONG lChannel);

typedef void(CALLBACK *fRemoteConfigCallback)(DWORD dwType, void* lpBuffer, DWORD dwBufLen, void* pUserData);
NET_DVR_API LONG __stdcall NET_DVR_StartRemoteConfig(LONG lUserID, DWORD dwCommand, LPVOID lpInBuffer, DWORD dwInBufferLen, fRemoteConfigCallback cbStateCallback, LPVOID pUserData);
NET_DVR_API BOOL __stdcall NET_DVR_StopRemoteConfig(LONG lHandle);
NET_DVR_API LONG __stdcall NET_DVR_GetNextRemoteConfig(LONG lHandle, void* lpOutBuff, DWORD dwOutBuffSize);
NET_DVR_API BOOL __stdcall NET_DVR_GetRemoteConfigState(LONG lHandle, void *pState);
NET_DVR_API BOOL __stdcall NET_DVR_SendRemoteConfig(LONG lHandle, DWORD dwDataType, char *pSendBuf, DWORD dwBufSize);

typedef void(CALLBACK *fLongCfgStateCallback)(LONG lHandle,  DWORD dwState, LPVOID pUserData);
NET_DVR_API BOOL __stdcall NET_DVR_CloseLongCfgHandle(LONG lHandle);
NET_DVR_API LONG __stdcall NET_DVR_RaidPullDiskStart(LONG lUserID, LONG lRaidID, fLongCfgStateCallback cbStateCallback, LPVOID pUserData);
NET_DVR_API LONG __stdcall NET_DVR_ScanRaidStart(LONG lUserID, fLongCfgStateCallback cbStateCallback, LPVOID pUserData);
NET_DVR_API LONG __stdcall NET_DVR_SetAccessCameraInfo(LONG lUserID, DWORD dwChannel, LPNET_DVR_ACCESS_CAMERA_INFO lpCameraInfo, fLongCfgStateCallback cbStateCallback, LPVOID pUserData);


NET_DVR_API BOOL __stdcall NET_DVR_InquiryRecordTimeSpan(LONG lUserID, DWORD dwChannel,  NET_DVR_RECORD_TIME_SPAN_INQUIRY const *lpInquiry, LPNET_DVR_RECORD_TIME_SPAN lpResult);
NET_DVR_API BOOL __stdcall NET_DVR_UpdateRecordIndex(LONG lUserID, DWORD dwChannel);
NET_DVR_API BOOL __stdcall NET_DVR_GetUpnpNatState(LONG lUserID, LPNET_DVR_UPNP_NAT_STATE lpState);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixSetLoopDecChanInfo_EX(LONG lUserID, DWORD dwDecChanNum, LPNET_DVR_MATRIX_LOOP_DECINFO_EX lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetLoopDecChanInfo_EX(LONG lUserID, DWORD dwDecChanNum, LPNET_DVR_MATRIX_LOOP_DECINFO_EX lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixStartDynamic_EX(LONG lUserID, DWORD dwDecChanNum, LPNET_DVR_PU_STREAM_CFG_EX lpDynamicInfo);
NET_DVR_API BOOL __stdcall NET_DVR_GetTrunkListInfo(LONG lUserID, DWORD dwTrunkNum, DWORD dwStartTrunk, LPNET_DVR_MATRIX_TRUNKLIST lpTrunkListInfo, DWORD *pReturnSize);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetSubDecSystemJoinInfo_V41(LONG lUserID, LPNET_DVR_ALLDECSUBSYSTEMJOININFO_V41 lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_AlarmHostSubSystemSetupAlarmChan(LONG lUserID, DWORD dwSubSystemNum);
NET_DVR_API BOOL __stdcall NET_DVR_AlarmHostSubSystemCloseAlarmChan(LONG lUserID, DWORD dwSubSystemNum);
NET_DVR_API BOOL __stdcall NET_DVR_AlarmHostClearAlarm(LONG lUserID, DWORD dwSubSystemNum);
NET_DVR_API BOOL __stdcall NET_DVR_AlarmHostArrayBypass(LONG lUserID);
NET_DVR_API BOOL __stdcall NET_DVR_AlarmHostArrayBypassResume (LONG lUserID);
NET_DVR_API BOOL __stdcall NET_DVR_AlarmHostSetReportMode(LONG lUserID, LONG lCenterNum, LPVOID lpInputBuf, DWORD dwInputBufLen);
NET_DVR_API BOOL __stdcall NET_DVR_AlarmHostGetReportMode(LONG lUserID, LPVOID lpOutputBuf, DWORD dwOutputBufLen);
NET_DVR_API LONG __stdcall NET_DVR_StartUploadAudio(LONG lUserID, DWORD dwAudioNum, DWORD dwAudioType, char const *sAudioFileName);
NET_DVR_API LONG __stdcall NET_DVR_StartDownloadAudio(LONG lUserID, DWORD dwAudioNum, char const *sAudioFileName);
NET_DVR_API BOOL __stdcall NET_DVR_StopAudioOperate(LONG lAudioHandle);
NET_DVR_API LONG __stdcall NET_DVR_GetAudioProgress(LONG lAudioHandle);
NET_DVR_API BOOL __stdcall NET_DVR_AudioCtrl(LONG lUserID, DWORD dwAudioNum, DWORD dwCtrlParam);
NET_DVR_API BOOL __stdcall NET_DVR_GetDeviceConfig(LONG lUserID, DWORD dwCommand, DWORD dwCount, LPVOID lpInBuffer, DWORD dwInBufferSize, LPVOID lpStatusList, LPVOID lpOutBuffer, DWORD dwOutBufferSize);
NET_DVR_API BOOL __stdcall NET_DVR_SetDeviceConfig(LONG lUserID, DWORD dwCommand, DWORD dwCount, LPVOID lpInBuffer, DWORD dwInBufferSize, LPVOID lpStatusList, LPVOID lpInParamBuffer, DWORD dwInParamBufferSize);
NET_DVR_API BOOL __stdcall NET_DVR_LockStreamFileByTime(LONG lUserID, LPNET_DVR_STREAM_TIME_LOCK lpLockPara, LPNET_DVR_LOCK_RETURN lpLockReturn);
NET_DVR_API BOOL __stdcall NET_DVR_UnlockStreamFileByTime(LONG lUserID, LPNET_DVR_STREAM_TIME_LOCK lpLockPara, LPNET_DVR_LOCK_RETURN lpLockReturn);
NET_DVR_API BOOL __stdcall NET_DVR_StartManualRecord(LONG lUserID, LPNET_DVR_MANUAL_RECORD_PARA lpManualRecPara);
NET_DVR_API BOOL __stdcall NET_DVR_StopManualRecord(LONG lUserID, LPNET_DVR_STREAM_INFO pIDInfo);
NET_DVR_API LONG __stdcall NET_DVR_PlayBackReverseByName(LONG lUserID, char *sPlayBackFileName, HWND hWnd);
NET_DVR_API LONG __stdcall NET_DVR_PlayBackByTime_V40(LONG lUserID, NET_DVR_VOD_PARA const* pVodPara);
NET_DVR_API LONG __stdcall NET_DVR_PlayBackReverseByTime_V40(LONG lUserID, HWND hWnd, LPNET_DVR_PLAYCOND pPlayCond);
NET_DVR_API LONG __stdcall NET_DVR_GetFileByTime_V40(LONG lUserID, char *sSavedFileName, LPNET_DVR_PLAYCOND  pDownloadCond);
NET_DVR_API LONG __stdcall NET_DVR_FindFile_V40(LONG lUserID, LPNET_DVR_FILECOND_V40 pFindCond);
NET_DVR_API LONG __stdcall NET_DVR_SetupAlarmChan_V41(LONG lUserID, LPNET_DVR_SETUPALARM_PARAM lpSetupParam);
NET_DVR_API BOOL __stdcall NET_DVR_AddDataBase(LONG lUserID, LPNET_VCA_DATABASE_PARAM lpInBuf);
NET_DVR_API LONG __stdcall NET_DVR_FindDataBase(LONG lUserID, LPNET_VCA_FIND_DATABASE_COND lpInBuf);
NET_DVR_API LONG __stdcall NET_DVR_FindNextDataBase(LONG lFindHandle, LPNET_VCA_DATABASE_PARAM lpOutBuf);
NET_DVR_API BOOL __stdcall NET_DVR_FindDataBaseClose(LONG lFindHandle);
NET_DVR_API BOOL __stdcall NET_DVR_UpdateDataBase(LONG lUserID, LPNET_VCA_DATABASE_PARAM lpInBuf);
NET_DVR_API BOOL __stdcall NET_DVR_DeleteDataBase(LONG lUserID, LPNET_VCA_DELETE_DATABASE_COND lpCond);
typedef void(CALLBACK *fSearchDBCallBack)(LONG lHandle, DWORD dwType, DWORD dwResultNum, BYTE* pBuffer, DWORD dwBufSize,void *pUser);
NET_DVR_API LONG __stdcall NET_DVR_InquireSnapDBRecord(LONG lUserID, DWORD dwDataBaseID, LPNET_VCA_INQUIRE_SNAPDB_COND lpInBuf, fSearchDBCallBack cbSearchDBCallBack, void *pUser);
NET_DVR_API BOOL __stdcall NET_DVR_GetInquireSnapDBProgress(LONG lInquireHandle, DWORD* pState);
NET_DVR_API BOOL __stdcall NET_DVR_DeleteSnapDBRecord(LONG lUserID, DWORD dwDataBaseID, LPNET_VCA_DELETE_SNAPRECORD_COND lpInBuf);
NET_DVR_API LONG __stdcall NET_DVR_SearchSnapDB(LONG lUserID, LPNET_VCA_SEARCH_SNAPDB_COND lpInBuf, fSearchDBCallBack cbSearchDBCallBack, void *pUser);
NET_DVR_API BOOL __stdcall NET_DVR_GetSearchSnapDBProgress(LONG lSearchHandle, DWORD* pState);
NET_DVR_API BOOL __stdcall NET_DVR_AddFaceDBRecord(LONG lUserID, DWORD dwDataBaseID, LPNET_VCA_DATARECORD_INFO lpInBuf);
NET_DVR_API BOOL __stdcall NET_DVR_FastAddFaceDBRecord(LONG lUserID, DWORD dwDataBaseID, LPNET_VCA_FAST_DATARECORD_INFO lpInBuf);
NET_DVR_API LONG __stdcall NET_DVR_InquireFaceDBRecord(LONG lUserID, LPNET_VCA_DATARECORD_COND lpInBuf,fSearchDBCallBack cbInquireDBCallBack, void *pUser);
NET_DVR_API BOOL __stdcall NET_DVR_GetInquireFaceDBProgress(LONG lInquireHandle, DWORD* pState);
NET_DVR_API BOOL __stdcall NET_DVR_UpdateFaceDBRecord(LONG lUserID, DWORD dwDataBaseID, LPNET_VCA_DATARECORD_INFO lpInBuf);
NET_DVR_API BOOL __stdcall NET_DVR_DeleteFaceDBRecord(LONG lUserID, DWORD dwDataBaseID, LPNET_VCA_DELETE_RECORD_COND lpInBuf);
typedef void(CALLBACK *fSearchDBCallBack)(LONG lSearchHandle, DWORD dwType, DWORD dwResultNum, BYTE* pBuffer, DWORD dwBufSize,void *pUser);
NET_DVR_API LONG __stdcall NET_DVR_SearchFaceDB(LONG lUserID, LPNET_VCA_SEARCH_FACEDB_COND lpInBuf,fSearchDBCallBack cbSearchDBCallBack, void *pUser);
NET_DVR_API BOOL __stdcall NET_DVR_GetSearchFaceDBProgress(LONG lSearchHandle, DWORD* pState);
NET_DVR_API LONG __stdcall NET_DVR_StopSearchDB(LONG lHandle);
NET_DVR_API BOOL __stdcall NET_DVR_FindMatchPicture(LONG lUserID, LPNET_VCA_FIND_MATCHPIC_COND lpFindCond, LPNET_VCA_FIND_MATCHPIC_RESULT lpFindResult);
NET_DVR_API BOOL __stdcall NET_DVR_RemoteControl(LONG lUserID, DWORD dwCommand, LPVOID lpInBuffer, DWORD dwInBufferSize);

NET_DVR_API BOOL __stdcall NET_DVR_PicViewRequest(LONG lUserID, NET_DVR_PIC_VIEW_PARAM *lpPicViewParam);
typedef LONG (CALLBACK *PicViewCallBack)(LPNET_DVR_PICVIEW_CALLBACKPARAM pStruPicViewParam, void *pUser);
NET_DVR_API BOOL __stdcall NET_DVR_SetPicViewResponseCallBack(PicViewCallBack fPicViewResponseCallBack, void *pUser);
NET_DVR_API BOOL __stdcall NET_DVR_SetPicViewDataCallBack(LONG lPicViewHandle, SCREENPICDATACB fPicDataCallback, void *pUserData);
NET_DVR_API BOOL __stdcall NET_DVR_GetDevList(LONG lUserID, LPNET_DVR_DEVLIST lpDevListInfo);
NET_DVR_API BOOL __stdcall NET_DVR_GetScreenList(LONG lUserID, LPNET_DVR_SCREENLIST lpScreenListInfo);
NET_DVR_API BOOL __stdcall NET_DVR_SetScreenRelation(LONG lUserID, NET_DVR_DISP_SCREEN const* lpScreenInfo);
NET_DVR_API BOOL __stdcall NET_DVR_TextShowCtrl(LONG lUserID, DWORD dwDeviceIndex, LPNET_DVR_TEXTSHOW lpText);
NET_DVR_API LONG __stdcall NET_DVR_StartUpgrade(LONG lUserID, LPNET_DVR_OPERATE_DEVICE lpStruOperate, DVCS_UPGRADESTATE_CB UpgradeStateCallback, void *pUserData);
NET_DVR_API BOOL __stdcall NET_DVR_StopUpgrade(LONG lUserID, LPNET_DVR_OPERATE_DEVICE lpStruOperate, LONG lUpgradeHandle);
NET_DVR_API BOOL __stdcall NET_DVR_AddNetSignal(LONG lUserID, LPNET_DVR_NETSIGNAL_INFO lpStruSignal, void* lpOutBuf , DWORD dwBufLen);
NET_DVR_API LONG __stdcall NET_DVR_StartPicPreview(LONG lUserID, NET_DVR_START_PIC_VIEW_INFO const* lpStruStartPicView, SCREENPICDATACB PicDataCallback, void *pUserData);
NET_DVR_API BOOL __stdcall NET_DVR_GetDeviceStatus(LONG lUserID, DWORD dwCommand, DWORD dwCount, LPVOID lpInBuffer, DWORD dwInBufferSize, LPVOID lpStatusList, LPVOID lpOutBuffer, DWORD dwOutBufferSize);
NET_DVR_API BOOL __stdcall NET_DVR_GetPlanList(LONG lUserID, DWORD dwDevNum, LPNET_DVR_PLAN_LIST lpPlanList);
NET_DVR_API BOOL __stdcall NET_DVR_GetInputSignalList(LONG lUserID, DWORD dwDevNum, LPNET_DVR_INPUT_SIGNAL_LIST lpInputSignalList);
NET_DVR_API LONG __stdcall NET_DVR_UploadFile(LONG lUserID, DWORD dwUploadType, LPVOID lpInBuffer, DWORD dwInBufferSize, char* sFileName);
NET_DVR_API LONG __stdcall NET_DVR_GetUploadState(LONG lUploadHandle, LPDWORD pProgress);
NET_DVR_API BOOL __stdcall NET_DVR_UploadClose(LONG lUploadHandle);
typedef void (CALLBACK *DATADOWNLOAD)(LONG nDownloadHandle, DWORD dwDataType, void* pBuffer, DWORD dwBufSize, void *pUser);
NET_DVR_API LONG __stdcall NET_DVR_StartUploadFile(LONG lUserID, LPNET_DVR_UPLOAD_PARAM  lpStruUploadParam);
NET_DVR_API LONG __stdcall NET_DVR_GetUploadFileProgress(LONG lFileHandle);
NET_DVR_API LONG __stdcall NET_DVR_GetUploadFileState(LONG lFileHandle);
NET_DVR_API BOOL __stdcall NET_DVR_StopUploadFile (LONG lFileHandle);
NET_DVR_API LONG __stdcall NET_DVR_StartDownloadFile(LONG lUserID, LPNET_DVR_DOWNLOAD_PARAM lpStruDownloadParam);
NET_DVR_API LONG __stdcall NET_DVR_GetDownloadFileProgress(LONG lFileHandle);
NET_DVR_API LONG __stdcall NET_DVR_GetDownloadFileState(LONG lFileHandle);
NET_DVR_API BOOL __stdcall NET_DVR_StopDownloadFile (LONG lFileHandle);

NET_DVR_API BOOL __stdcall NET_DVR_GetMobileDevStatus(LONG lUserID, DWORD dwStatusType, LPNET_DVR_MB_MOBILEDEV_STATUS lpstruMobileDevStatus);
NET_DVR_API BOOL __stdcall NET_DVR_SetVoiceDataCallBack(LONG lVoiceComHandle, BOOL bNeedCBNoEncData, void(CALLBACK *fVoiceDataCallBack)(LONG lVoiceComHandle, char *pRecvDataBuffer, DWORD dwBufSize, BYTE byAudioFlag, void* pUser), void* pUser);
NET_DVR_API BOOL __stdcall NET_DVR_SetTransparentParam(LONG lUserID, char *sInBuffer, DWORD dwInSize);
NET_DVR_API BOOL __stdcall NET_DVR_GetTransparentParam(LONG lUserID, char *sInBuffer, DWORD dwInSize, char *sOutBuffer, DWORD dwOutSize);

NET_DVR_API BOOL __stdcall NET_DVR_SetSDKLocalConfig(LPNET_DVR_SDKLOCAL_CFG lpSdkLocalCfg);
NET_DVR_API BOOL __stdcall NET_DVR_GetSDKLocalConfig(LPNET_DVR_SDKLOCAL_CFG lpSdkLocalCfg);

NET_DVR_API BOOL __stdcall NET_DVR_SetSDKLocalCfg(NET_SDK_LOCAL_CFG_TYPE enumType, void* const lpInBuff);
NET_DVR_API BOOL __stdcall NET_DVR_GetSDKLocalCfg(NET_SDK_LOCAL_CFG_TYPE enumType, void* lpOutBuff);

NET_DVR_API LONG __stdcall NET_DVR_OpticalUpgrade(LONG lUserID, char const *sFileName, LPNET_DVR_OPTICAL_INFO lpOpticalInfo);
typedef void(CALLBACK *fGPSDataCallback)(LONG nHandle, DWORD dwState, void* lpBuffer, DWORD dwBufLen, void* pUserData);
NET_DVR_API LONG __stdcall NET_DVR_GetVehicleGpsInfo(LONG nUserID, LPNET_DVR_GET_GPS_DATA_PARAM lpGPSDataParam, fGPSDataCallback cbGPSDataCallback, void* pUser);

NET_DVR_API BOOL __stdcall NET_DVR_ClosePreview(LONG lUserID, DWORD nSessionID);
NET_DVR_API BOOL __stdcall NET_DVR_ClosePlayBack(LONG lUserID, DWORD nSessionID);
NET_DVR_API LONG __stdcall NET_DVR_RealPlay_V40(LONG lUserID, LPNET_DVR_PREVIEWINFO lpPreviewInfo, REALDATACALLBACK fRealDataCallBack_V30 = NULL, void* pUser = NULL);

NET_DVR_API LONG __stdcall NET_DVR_StartDownload(LONG lUserID, DWORD dwDownloadType, LPVOID lpInBuffer, DWORD dwInBufferSize, const char *sFileName);
NET_DVR_API LONG __stdcall NET_DVR_GetDownloadState(LONG lDownloadHandle, LPDWORD pProgress);
NET_DVR_API BOOL __stdcall NET_DVR_StopDownload(LONG lHandle);

NET_DVR_API BOOL __stdcall NET_DVR_MatrixStartDynamic_V41(LONG lUserID, DWORD dwDecChanNum, LPNET_DVR_PU_STREAM_CFG_V41 lpDynamicInfo);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetLoopDecChanInfo_V41(LONG lUserID, DWORD dwDecChanNum, LPNET_DVR_MATRIX_LOOP_DECINFO_V41 lpOuter);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixSetLoopDecChanInfo_V41(LONG lUserID, DWORD dwDecChanNum, LPNET_DVR_MATRIX_LOOP_DECINFO_V41 lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetDecChanInfo_V41(LONG lUserID, DWORD dwDecChanNum, LPNET_DVR_MATRIX_DEC_CHAN_INFO_V41 lpOuter);

NET_DVR_API LONG __stdcall NET_DVR_StartT1Test(LONG lUserID, LPNET_DVR_ALARMHOST_DOWNLOAD_PARAM lpStruDownloadParam);
NET_DVR_API BOOL __stdcall NET_DVR_StopTT1Test(BOOL lHandle);
NET_DVR_API BOOL __stdcall NET_DVR_GetT1TestStatus(LONG lHandle, LONG *pStatus);
NET_DVR_API BOOL __stdcall NET_DVR_UploadLogo_NEW(LONG lUserID, DWORD dwLogoNo, LPNET_DVR_MATRIX_LOGO_INFO lpLogoInfo, char *sLogoBuffer);
NET_DVR_API LONG __stdcall NET_DVR_StartPassiveTransCode(LONG lUserID, NET_DVR_STREAM_INFO const *pStreamInfo, NET_DVR_COMPRESSIONCFG_V30 const *pDstTransInfo, NET_DVR_PASSIVETRANSINFO const *pPassiveTransInfo, void(CALLBACK *fTransCodeDataCallBack) (LONG lPassiveHandle, DWORD dwDataType, BYTE *pBuffer, DWORD dwBufSize, void* pUser) = NULL, void* pUser = NULL);
NET_DVR_API BOOL __stdcall NET_DVR_TransCodeInputData(LONG lPassiveHandle, BYTE *pBuffer, DWORD dwBufSize);
NET_DVR_API BOOL __stdcall NET_DVR_StopPassiveTransCode(LONG lPassiveHandle);
NET_DVR_API LONG __stdcall NET_DVR_GetPassiveTransChanNum(LONG lPassiveHandle);


#endif //

