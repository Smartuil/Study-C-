#pragma once


#ifndef _CFG_OP_H

#define _CFG_OP_H

#ifdef __cplusplus
extern "C" {
#endif

//1.д������
int WriteCfgItem(char *pFilename/*in*/,  char *pItemName/*in*/,  char *pItemValue/*in*/, int itemValueLen/*in*/);

//2.�޸������ļ�����һ��ǰ�ᣬ������֪��key����
int ModifyCfgItem(const char *fielname, const char *key, const char *value);

//3.��ȡ������
int GetCfgItem( char *pFilename/*in*/,  char *pKey/*in*/,  char *pValue/*in*/, int pValueLen/*out*/);
#ifdef __cplusplus
}
#endif

#endif // !_CFG_OP_H

