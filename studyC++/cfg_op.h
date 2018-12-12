#pragma once


#ifndef _CFG_OP_H

#define _CFG_OP_H

#ifdef __cplusplus
extern "C" {
#endif

//1.写配置项
int WriteCfgItem(char *pFilename/*in*/,  char *pItemName/*in*/,  char *pItemValue/*in*/, int itemValueLen/*in*/);

//2.修改配置文件，有一个前提，调用者知道key存在
int ModifyCfgItem(const char *fielname, const char *key, const char *value);

//3.获取配置项
int GetCfgItem( char *pFilename/*in*/,  char *pKey/*in*/,  char *pValue/*in*/, int pValueLen/*out*/);
#ifdef __cplusplus
}
#endif

#endif // !_CFG_OP_H

