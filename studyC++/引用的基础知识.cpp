#include<iostream>
using namespace std;


void main1() {

	int a = 10;
	int &b = a;
	cout << a << b << endl;
	system("pause");
}

void main22() {

	int a = 10;
	int &b = a;
	//int &c;//��ͨ���ñ����ʼ��
	cout << a << b << endl;
	system("pause");
}
void myswap(int a, int b) {
	int c = a;
	a = b;
	b = c;
}

void myswap2(int &a, int &b) {
	int c = a;
	a = b;
	b = c;
}
void main222() {

	int a = 10;
	int &b = a;
	int c = 20;
	myswap2(a, c);
	cout << a << c << endl;
	system("pause");
}

//�����������͵�����

struct Teacher{
	char name[64];
	int age;
};

void printT(Teacher *pT) {
	cout << pT->age << endl;
}

void printT2(Teacher &pT) {
	cout << pT.age << endl;
}

void printT3(Teacher pT) {
	cout << pT.age << endl;
}
void main() {
	Teacher t1;
	t1.age = 23;
	printT(&t1);
	printT2(t1);
	printT3(t1);//��������
	system("pause");
}