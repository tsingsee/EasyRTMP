/*
	Copyright (c) 2012-2017 EasyDarwin.ORG.  All rights reserved.
	Github: https://github.com/EasyDarwin
	WEChat: EasyDarwin
	Website: http://www.easydarwin.org
*/

package org.easydarwin.easyrtmp.config;

/**
 * 类Config的实现描述：//TODO 类实现描述
 */
public class Config {
    public static final String SERVER_URL = "serverUrl";
    public static final String DEFAULT_SERVER_URL = "rtmp://www.easydss.com/live/stream_"+String.valueOf((int) (Math.random() * 1000000 + 100000));
    public static final String PREF_NAME = "easy_pref";
    public static final String K_RESOLUTION = "k_resolution";
}
