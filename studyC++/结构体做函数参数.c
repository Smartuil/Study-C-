#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Teacher {
	char name[64];
	int age;
	int id;
}Teacher;

void printTeacher(Teacher *array, int num) {
	int i = 0;
	for (i = 0; i < num; i++) {
		printf("age%d\n", array[i].age);
	}
}

void sort(Teacher *array, int num) {
	int i, j;
	Teacher tmp;
	for (i = 0; i < num; i++) {
		for (j = i+1; j < num; j++) {
			if (array[i].age > array[j].age) {
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
		}
	}
}



void main1() {

	Teacher Array[3];

	for (int i = 0; i < 3; i++) {
		printf("请输入老师的年龄:");
		scanf("%d", &(Array[i].age));
	}

	printTeacher(Array, 3);
	sort(Array, 3);
	printTeacher(Array, 3);

	system("pause");
	return;
}
Teacher *createTeacher(int num) {
	Teacher *tmp = NULL;
	tmp = (Teacher *)malloc(sizeof(Teacher)*num);
	if (tmp == NULL)
		return NULL;

}

void FreeTeacher(Teacher *p) {
	if (p != NULL)
		free(p);

}

void main() {

	Teacher *pArray = NULL;
	pArray = createTeacher(3);

	for (int i = 0; i < 3; i++) {
		printf("请输入老师的年龄:");
		scanf("%d", &(pArray[i].age));
	}

	printTeacher(pArray, 3);
	sort(pArray, 3);
	printTeacher(pArray, 3);
	FreeTeacher(pArray);
	system("pause");
	return;
}