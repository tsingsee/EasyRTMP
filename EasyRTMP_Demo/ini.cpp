
#include <string.h>  
  
#ifdef _WIN32  
#include <Windows.h>  
#include <stdio.h>  
#else  
  
#include <unistd.h>  
#include <fcntl.h>  
#include <stdio.h>  
#include <stdlib.h>  
#include <stdarg.h>  
#endif 

#include "ini.h"

/*
下边是配置文件：
[CAT]
age=2
name=Tom
*/

//从INI文件读取字符串类型数据  
char *GetIniKeyString(char *title,char *key,char *filename)   
{   
    FILE *fp;   
    char szLine[1024];  
    static char tmpstr[1024];  
    int rtnval;  
    int i = 0;   
    int flag = 0;   
    char *tmp;  
  
    if((fp = fopen(filename, "r")) == NULL)   
    {   
        printf("have   no   such   file \n");  
        return "";   
    }  
    while(!feof(fp))   
    {   
        rtnval = fgetc(fp);   
        if(rtnval == EOF)   
        {   
            break;   
        }   
        else   
        {   
            szLine[i++] = rtnval;   
        }   
        if(rtnval == '\n' || rtnval == '\r')   
        {   
#ifndef WIN32  
            //i--;  
#endif    
            szLine[--i] = '\0';  
            i = 0;   
            tmp = strchr(szLine, '=');   
  
            if(( tmp != NULL )&&(flag == 1))   
            {   
                if(strstr(szLine,key)!=NULL)   
                {   
                    //注释行  
                    if ('#' == szLine[0])  
                    {  
                    }  
                    else if ( '\/' == szLine[0] && '\/' == szLine[1] )  
                    {  
                          
                    }  
                    else  
                    {  
                        //找打key对应变量  
                        strcpy(tmpstr,tmp+1);   
                        fclose(fp);  

						while(tmpstr[strlen(tmpstr) - 1] == ' ' || tmpstr[strlen(tmpstr) - 1] == '\t')
							tmpstr[strlen(tmpstr) - 1] = '\0';

                        return tmpstr;   
                    }  
                }   
            }  
            else   
            {   
                strcpy(tmpstr,"[");   
                strcat(tmpstr,title);   
                strcat(tmpstr,"]");  
                if( strncmp(tmpstr,szLine,strlen(tmpstr)) == 0 )   
                {  
                    //找到title  
                    flag = 1;   
                }  
            }  
        }  
    }  
    fclose(fp);   
    return "";   
}  
  
//从INI文件读取整类型数据  
int GetIniKeyInt(char *title,char *key,char *filename)  
{  
	int ret = 0;
	char* strValue = GetIniKeyString(title,key,filename);
	if(strlen(strValue) <= 0)
	{
		return ret;
	}
	else
	{
		ret = atoi(strValue);
	}

    return ret;  
}  