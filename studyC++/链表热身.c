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

//结构体中套一个结构体
//结构体套一个结构体指针
//结构体套一个自己类型的结构体，失败！！！
//结构体套一个指向自己类型的指针

//typedef struct AdvTeacher {
//	char name[64];
//	int id;
//	AdvTeacher AdvTeacher;
//}AdvTeacher;//自己类型大小还没有决定的情况下，引用自己类型的元素是不正确的，结构体不能嵌套定义，确定不了数据类型的内存大小

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