#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cfg_op.h"

#define CFGNAME "d:/mycfg.ini"

void mymenu() {
	printf("=============================\n");
	printf("1.����д�����ļ�\n");
	printf("2.���Զ������ļ�\n");
	printf("0.�˳�\n");
	printf("=============================\n");

}


//1.д������
int TWriteCfg() {
	int ret = 0;
	char name[1024] = { 0 };
	char value[1024] = { 0 };
	printf("\n�����key:");
	scanf("%s", name);
	printf("\n�����value:");
	scanf("%s", value);

	ret = WriteCfgItem(CFGNAME/*in*/, name/*in*/, value/*in*/, strlen(value)/*out*/);
	if (ret != 0) {
		printf("func WriteCfgItem() err:%d\n", ret);
		return ret;
	}
	printf("��������ǣ�%s = %s\n", name, value);
	return ret;
}


//3.��ȡ������
int TGetCfg() {
	int ret = 0;
	char name[1024] = { 0 };
	char value[1024] = { 0 };
	int vlen = 0;
	printf("\n�����key:");
	scanf("%s", name);

	ret = GetCfgItem(CFGNAME/*in*/, name/*in*/, value/*in*/, &vlen/*out*/);
	if (ret != 0) {
		printf("func GetCfgItem() err:%d\n", ret);
		return ret;
	}
	printf("value:%s\n",value);
	return ret;
}


void main() {

	int choice;
	

	for (;;) {
		//��ʾһ���˵�
		mymenu();
scanf("%d", &choice);
		switch (choice) {
		case 1:
			TWriteCfg();
			break;
		case 2:
			TGetCfg();
			break;
		case 0:
			exit(0);
		default:
			exit(0);
		}
	}

	system("pause");
	return;
}
