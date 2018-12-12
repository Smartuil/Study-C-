#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MaxLine 2048

//1.写配置项
int WriteCfgItem(char *pFilename/*in*/,  char *pKey/*in*/,  char *pValue/*in*/, int pValueLen/*in*/) {
	int rv = 0, iTag = 0, length = 0;
	FILE *fp = NULL;
	char lineBuf[MaxLine];
	char *pTmp = NULL;
	char *pBegin = NULL;
	char *pEnd = NULL;
	char fileBuf[2014 * 8] = { 0 };

	if (pFilename == NULL || pKey == NULL || pValueLen==NULL) {
		rv = -1;
		printf("SetCfgItem() err\n");
		goto End;
	}

	fp = fopen(pFilename, "r+");
	if (fp == NULL) {
		rv = -2;
		printf("fopen()err\n");
	}

	if (fp == NULL) {
		fp = fopen(pFilename, "w+t");
		if (fp == NULL) {
			rv = -3;
			printf("fopen()err\n");
			goto End;
		}
	}
	fseek(fp, 0L, SEEK_END);//把文件指针从0位置开始，移到文件末尾
	//获取文件长度
	length = ftell(fp);
	fseek(fp, 0L, SEEK_SET);

	if (length > 1024 * 8) {
		rv = -3;
		printf("文件超过1024*8");
		goto End;
	}

	while (!feof(fp)) {
		memset(lineBuf, 0, sizeof(lineBuf));
		pTmp = fgets(lineBuf, MaxLine, fp);
		if (pTmp == NULL) {
			break;
		}
		//key关键字是否在本行
		pTmp = strstr(lineBuf, pKey);
		if (pTmp == NULL) {//key关键字不在本行，copy到file中
			sprintf(fileBuf, lineBuf);
			continue;
		}
		else {//key关键字在本行，替换旧的行，再copy到fileBuf中
			sprintf(lineBuf, "%s = %s\n", pKey, pValue);
			strcat(fileBuf, lineBuf);
			iTag = 1;
		}
	}
	//若key关键字，不存在 追加
	if (iTag == 0) {
		fprintf(fp, "%s = %s\n", pKey, pValue);
	}
	else {//若key关键字存在，则重新创建文件
		if (fp != NULL) {
			fclose(fp);
			fp = NULL;
		}

		fp = fopen(pFilename, "w+r");
		if (fp == NULL) {
			rv = -4;
			printf("fopen()err\n");
			goto End;
		}
		fputs(fileBuf, fp);
	}


End:
	if (fp != NULL) {
		fclose(fp);
	}
	return 0;
}

//2.修改配置文件，有一个前提，调用者知道key存在
int ModifyCfgItem(const char *fielname, const char *key, const char *value);

//3.获取配置项
int GetCfgItem( char *pFilename/*in*/,  char *pKey/*in*/,  char *pValue/*in*/, int *pValueLen/*out*/) {
	int ret = 0;
	FILE *fp = NULL;

	char *pTmp = NULL;
	char *pBegin = NULL;
	char *pEnd = NULL;

	char lineBuf[MaxLine];
	fp = fopen(pFilename, "r");
	if (fp == NULL) {
		ret = -1;
		return ret;
	}

	while (!feof(fp)) {

		memset(lineBuf, 0, sizeof(lineBuf));
		fgets(lineBuf, MaxLine, fp);
		//printf("lineBuf%s", lineBuf);

		pTmp = strchr(lineBuf, '=');
		if (pTmp == NULL) {//没有等号
			continue;
		}

		pTmp = strstr(lineBuf, pKey);
		if (pTmp == NULL) {//判断key是不是在所在行
			continue;
		}
		pTmp = pTmp + strlen(pKey);
		pTmp = strchr(pTmp, '=');
		if (pTmp == NULL) {//判断key是不是在所在行
			continue;
		}

		pTmp = pTmp + 1;
		//printf("pTmp:%s", pTmp);
		
		//获取value起点
		while (1) {
			if (*pTmp == ' ') {
				pTmp++;
			}
			else {
				pBegin = pTmp;
				if (*pBegin == '\n') {
					printf("配置项：%s没有配置value\m", pKey);
					goto End;
				}
				break;
			}
		}
		//获取value结束点
		while (1) {
			if ((*pTmp == ' ') || *pTmp == '\n') {
				break;
			}
			else {
				pTmp++;
			}
		}
		pEnd = pTmp;

		//赋值
		*pValueLen = pEnd - pBegin;
		memcpy(pValue, pBegin, pEnd - pBegin);
		break;

	}

End:
	if (fp != NULL) {
		fclose(fp);
	}
	return 0;
}