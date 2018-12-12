#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getLen(int *p)
{
	{
		*p = 30;
	}
}
void main01() {
	int a = 10;
	int *p = NULL;
	a = 11;
	p = &a;
	*p = 20;
	printf("%d", a);


	system("pause");
	return;
}
int getLen2(char **p2)
{
	*p2 = 30;

	*p2 = (char *)malloc(1000);
	return 0;
}
void main02() {
	char *p = NULL;
	char **p2 = NULL;
	//p = 1;
	//p = 2;

	p2 = &p;
	*p2 = 20;
	{
		*p2 = 30;
	}
	system("pause");
	return;
}


void getLen3(char ***p3) {
	*p3 = 10;
}

void main03() {

	char **p = NULL;

	char **p3 = NULL;

	p = 1;
	p = 2;

	p3 = &p;
	*p3 = 10;
	{
		*p3 = 30;
	}
	system("pause");
	return;
}

void getLen4(char ********p8) {
	*p8 = 10;
}

void main() {

	char *******p7 = NULL;
	char ********p8 = NULL;


	p7 = 1;
	p7 = 2;

	p8 = &p7;
	*p8 = 10;
	{
		*p8 = 30;
	}
	system("pause");
	return;
}
