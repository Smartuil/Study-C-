#include<iostream>
using namespace std;

//C++��const�������ĳ�����C���Ǹ�ð�ƻ�


struct Teacher {
	char name[64];
	int age;
};
//ָ����ָ����ڴ�ռ䲻�ܱ��޸�
int printTeacher(const Teacher *pT) {
	//pT->age = 10;
	return 0;
}
//ָ����������ܱ��޸�
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
