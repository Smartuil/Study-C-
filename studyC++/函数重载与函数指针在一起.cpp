#include<iostream>
using namespace std;


void func(int a) {
	cout << a;
}

void func(char *p) {
	cout << p;
}


void func(int a, int b) {
	cout << a << " " << b << endl;
}

void func(double a, double b) {
	cout << a << " " << b << endl;
}

//����ָ�� �����﷨

//����һ����������
//void func(int a, int b);
typedef void (myTypeFunc)(int a, int b); //myTypeFunc *myfuncp = NULL;//����һ������ָ��  ���ָ��ָ������ڵ�ַ

//����һ������ָ������
typedef void (*myPTypeFunc)(int a, int b);//������һ��ָ�����������
//myPTypeFunc fp = NULL;ͨ������ָ������  ������һ������ָ��

//����һ������ָ�� ����
void (*myVarPFunc)(int a, int b);

int main() {

	myPTypeFunc fp = NULL;//������һ������ָ�����
	fp = func;
	//fp(1);
	fp(1, 2);
	//fp(1.9, 2.0);
	system("pause");
	return 0;
}


