#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main01_fputs() {
	FILE *fp = NULL;
	//char *filename = "c:\\1.txt";
	const char *filename = "d:/1.txt";//统一使用45度   wl通用
	char a[27] = "abcdefghijklmn";

	fp = fopen(filename, "w+");
	if (fp == NULL) {
		printf("func fopen() err:%d:", fp);
		return;
	}
	fputs(a, fp);

	fclose(fp);
	return;
}



void main02_fgets() {
	FILE *fp = NULL;
	//char *filename = "d:\\1.txt";
	char *filename = "d:/1.txt";//统一使用45度   wl通用
	char buf[1024];

	fp = fopen(filename, "r+");
	if (fp == NULL) {
		printf("func fopen() err:%d:", fp);
		return;
	}
	while (!feof(fp)) {
		char *p=fgets(buf, 1024, fp);
		if (p == NULL) {
			goto End;
		}
		printf("%s", buf);
	}
	printf("\n");

End:
	if (fp != NULL) {
		fclose(fp);
	}


	return;
}
void main() {
	//main01_fputs();
	main02_fgets();
	system("pause");
	return;
}