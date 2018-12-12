#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getContentLen(const char *filename, char **buf, int *len) {
	char *tmp = NULL;
	tmp = (char *)malloc(100*sizeof(char));
	if (tmp == NULL) {
		return -1;
	}

	strcpy(tmp, "aaaaaa");
	*len = 10;
	*buf = tmp;
	return 0;
}

int getContentLen02(const char *filename, char **buf, int *len) {
	char *tmp = NULL;
	tmp = (char *)malloc(100 * sizeof(char));

	if (buf == NULL) {
		*len = 10;
	}
	else {
		strncpy(tmp, "aaaaaa",10);
		*len = 10;
	}
	return 0;
}

void main() {
	const char *filename = "d:/1.txt";
	char *p = NULL;
	int len = 0;
	getContentLen(filename, &p, &len);
	

	if (p != NULL) {
		free(p);
		p = NULL;
	}
	
	getContentLen02(filename, NULL, &len);
	p = (char *)malloc(len);
	if (p != NULL) {
		return;
	}
	getContentLen02(filename, p, &len);
	if (p != NULL) {
		free(p);
		p = NULL;
	}
	system("pause");
	return;
}
