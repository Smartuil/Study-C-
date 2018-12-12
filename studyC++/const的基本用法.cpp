#include<iostream>
using namespace std;

//C++中const是真正的常量，C中是个冒牌货


struct Teacher {
	char name[64];
	int age;
};
//指针所指向的内存空间不能被修改
int printTeacher(const Teacher *pT) {
	//pT->age = 10;
	return 0;
}
//指针变量本身不能被修改
int printTeacher2( Teacher * const pT) {
	pT->age = 10;
	//pT = NULL;
	return 0;
}

int printTeacher3(const Teacher * const pT) {
	//pT->age = 10;
	//pT = NULL;
	cout << pT->age;
	return 0;
}
void main() {
	Teacher t1;
	t1.age = 23;
	printTeacher3(&t1);
	system("pause");
}
