#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main01_fputc() {
	FILE *fp = NULL;
	//char *filename = "c:\\1.txt";
	const char *filename = "c:/1.txt";//统一使用45度   wl通用
	char a[27] = "abcdefghijklmn";

	fp=fopen(filename, "r+");
	if (fp == NULL) {
		printf("func fopen() err:%d:", fp);
		return;
	}
	for (int i = 0; i < strlen(a); i++) {
		fputc(a[i], fp);
	}

	fclose(fp);
	system("pause");
	return;
}



void main02_fgetc() {
	FILE *fp = NULL;
	//char *filename = "c:\\1.txt";
	const char *filename = "c:/1.txt";//统一使用45度   wl通用
	char a[27] = "abcdefghijklmn";

	fp = fopen(filename, "r+");
	if (fp == NULL) {
		printf("func fopen() err:%d:", fp);
		return;
	}
	while (!feof(fp)) {
		char *tmpc = fgetc(fp);
		printf("%c", tmpc);
	}
	if (fp!=NULL) {
		fclose(fp);
	}
	
	system("pause");
	return;
}
void main() {
	//main01_fputc();
	main02_fgetc();
	system("pause");
	return;
}