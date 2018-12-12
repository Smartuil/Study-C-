#include<iostream>
using namespace std;


//当函数返回值为引用时，若返回栈变量，不能成为其他引用的初始值，不能作为左值使用
//若返回静态变量或全局变量，可以成为其他引用的初始值，既可作为右值使用，也可作为左值使用


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

int &j2() {//有static  没问题

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

//作左值
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