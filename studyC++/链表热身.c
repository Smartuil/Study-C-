#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct Student {
	char name[64];
	int id;
}Student;

typedef struct Teacher {
	char name[64];
	int id;
	char *p;
	char **p2;
	Student s1;
	Student *p3;
}Teacher;

//�ṹ������һ���ṹ��
//�ṹ����һ���ṹ��ָ��
//�ṹ����һ���Լ����͵Ľṹ�壬ʧ�ܣ�����
//�ṹ����һ��ָ���Լ����͵�ָ��

//typedef struct AdvTeacher {
//	char name[64];
//	int id;
//	AdvTeacher AdvTeacher;
//}AdvTeacher;//�Լ����ʹ�С��û�о���������£������Լ����͵�Ԫ���ǲ���ȷ�ģ��ṹ�岻��Ƕ�׶��壬ȷ�������������͵��ڴ��С

typedef struct AdvTeacher2 {
	char name[64];
	int id;
	struct AdvTeacher2 *p;
}AdvTeacher2;

void main() {

	Teacher t1;
	AdvTeacher2 advt1;
	system("pause");
	return;
}