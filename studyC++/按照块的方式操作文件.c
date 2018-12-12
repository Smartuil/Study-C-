#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Teacher {
	char name[64];
	int age;
}Teacher;

void main_fwrite() {
	FILE *fp = NULL;
	char *filename = "d:/1.txt";
	Teacher tArray[3];
	for (int i = 0; i < 3; i++) {
		sprintf(tArray[i].name, "%d%d%d", i + 1, i + 1, i + 1);
		tArray[i].age = i + 20;
	}


	fp = fopen(filename, "wb");
	if (fp == NULL) {
		printf("err");
		return;
	}

	for (int i = 0; i < 3; i++) {
		int myN=fwrite(&tArray[i], sizeof(Teacher), 1, fp);
	}

	if (fp != NULL) {
		fclose(fp);
	}
}


void main_fread() {
	FILE *fp = NULL;
	char *filename = "d:/1.txt";
	Teacher tArray[3];


	fp = fopen(filename, "rb");
	if (fp == NULL) {
		printf("err");
		return;
	}

	for (int i = 0; i < 3; i++) {
		fread(&tArray, sizeof(Teacher), 1, fp);
		//int myN = fwrite(&tArray[i], sizeof(Teacher), 1, fp);
	}

	for (int i = 0; i < 3; i++) {
		printf( "%s", tArray[i].name);
	}

	if (fp != NULL) {
		fclose(fp);
	}
}

void main() {
	//main_fwrite();
	main_fread();
	system("pause");
	return;
}




