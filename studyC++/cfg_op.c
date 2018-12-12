#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MaxLine 2048

//1.д������
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
	fseek(fp, 0L, SEEK_END);//���ļ�ָ���0λ�ÿ�ʼ���Ƶ��ļ�ĩβ
	//��ȡ�ļ�����
	length = ftell(fp);
	fseek(fp, 0L, SEEK_SET);

	if (length > 1024 * 8) {
		rv = -3;
		printf("�ļ�����1024*8");
		goto End;
	}

	while (!feof(fp)) {
		memset(lineBuf, 0, sizeof(lineBuf));
		pTmp = fgets(lineBuf, MaxLine, fp);
		if (pTmp == NULL) {
			break;
		}
		//key�ؼ����Ƿ��ڱ���
		pTmp = strstr(lineBuf, pKey);
		if (pTmp == NULL) {//key�ؼ��ֲ��ڱ��У�copy��file��
			sprintf(fileBuf, lineBuf);
			continue;
		}
		else {//key�ؼ����ڱ��У��滻�ɵ��У���copy��fileBuf��
			sprintf(lineBuf, "%s = %s\n", pKey, pValue);
			strcat(fileBuf, lineBuf);
			iTag = 1;
		}
	}
	//��key�ؼ��֣������� ׷��
	if (iTag == 0) {
		fprintf(fp, "%s = %s\n", pKey, pValue);
	}
	else {//��key�ؼ��ִ��ڣ������´����ļ�
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

//2.�޸������ļ�����һ��ǰ�ᣬ������֪��key����
int ModifyCfgItem(const char *fielname, const char *key, const char *value);

//3.��ȡ������
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
		if (pTmp == NULL) {//û�еȺ�
			continue;
		}

		pTmp = strstr(lineBuf, pKey);
		if (pTmp == NULL) {//�ж�key�ǲ�����������
			continue;
		}
		pTmp = pTmp + strlen(pKey);
		pTmp = strchr(pTmp, '=');
		if (pTmp == NULL) {//�ж�key�ǲ�����������
			continue;
		}

		pTmp = pTmp + 1;
		//printf("pTmp:%s", pTmp);
		
		//��ȡvalue���
		while (1) {
			if (*pTmp == ' ') {
				pTmp++;
			}
			else {
				pBegin = pTmp;
				if (*pBegin == '\n') {
					printf("�����%sû������value\m", pKey);
					goto End;
				}
				break;
			}
		}
		//��ȡvalue������
		while (1) {
			if ((*pTmp == ' ') || *pTmp == '\n') {
				break;
			}
			else {
				pTmp++;
			}
		}
		pEnd = pTmp;

		//��ֵ
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