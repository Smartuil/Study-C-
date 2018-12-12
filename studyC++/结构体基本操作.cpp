#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Teacher {
	char name[64];
	int age;
	int id;
}Teacher;


//用类型定义变量方法3种
struct Student {
	char name[64];
	int age;
	int id;
}s1, s2 ;

struct {
	char name[64];
	int age;
	int id;
}s3,s4;


struct  {
	char name[64];
	int age;
	int id;
}s5 = {"name",112,1};



int  main01() {
	//struct Teacher t1;
	Teacher t1 = { "aa",23,1 };
	Teacher t2;

	strcpy(t1.name, "t1name");
	printf(t1.name);

	Teacher *p = NULL;
	p = &t1;
	printf("p->age:%d\n",p->age);

	system("pause");
	return 0;
}
void copyteacher(Teacher to, Teacher from) {
	to = from;

}

void copyteacher02(Teacher *to, Teacher *from) {
	(*to) = (*from);


}
void main() {
	Teacher t1 = { "aa",23,1 };
	Teacher t2;
	Teacher t3;
	copyteacher02(&t3, &t1);
	t2 = t1;

	printf("t2.age=%d\n", t2.age);
	printf("t3.age=%d\n", t3.age);

	system("pause");
}