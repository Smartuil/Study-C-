#include<iostream>
using namespace std;


//����������ֵΪ����ʱ��������ջ���������ܳ�Ϊ�������õĳ�ʼֵ��������Ϊ��ֵʹ��
//�����ؾ�̬������ȫ�ֱ��������Գ�Ϊ�������õĳ�ʼֵ���ȿ���Ϊ��ֵʹ�ã�Ҳ����Ϊ��ֵʹ��


int getAA1() {
	int a;
	a = 10;
	return a;
}

int &getAA2() {
	int a;
	a = 10;
	return a;
}

int *getAA3() {
	int a;
	a = 10;
	return &a;
}

int j() {
	static int a = 10;
	a++;
	return a;
}

int &j2() {//��static  û����

	static int a = 10;
	a++;
	return a;
}

void main111() {
	int a1 = getAA1();
	int a2 = getAA2();
	//int *a3 = getAA3();
	int &a3 = getAA2();

	cout << a1 <<endl << a2 << endl << a3 << endl;
	system("pause");
}

//����ֵ
int g1() {
	static int a = 10;
	a++;
	return a;
}

int &g2() {
	static int a = 10;
	a++;
	return a;
}
void main() {
	g1() = 100;
	g2() = 100;
	system("pause");
}