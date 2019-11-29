#ifndef __INI_H__
#define __INI_H__

#ifdef __cplusplus
extern "C" {
#endif
//从INI文件读取字符串类型数据  
extern char *GetIniKeyString(char *title,char *key,char *filename);

//从INI文件读取整类型数据  
extern int GetIniKeyInt(char *title,char *key,char *filename);

#ifdef __cplusplus
}
#endif

#endif//__INI_H__