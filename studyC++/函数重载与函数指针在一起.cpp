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

//函数指针 基础语法

//声明一个函数类型
//void func(int a, int b);
typedef void (myTypeFunc)(int a, int b); //myTypeFunc *myfuncp = NULL;//定义一个函数指针  这个指针指向函数入口地址

//声明一个函数指针类型
typedef void (*myPTypeFunc)(int a, int b);//声明了一个指针的数据类型
//myPTypeFunc fp = NULL;通过函数指针类型  定义了一个函数指针

//定义一个函数指针 变量
void (*myVarPFunc)(int a, int b);

int main() {

	myPTypeFunc fp = NULL;//定义了一个函数指针变量
	fp = func;
	//fp(1);
	fp(1, 2);
	//fp(1.9, 2.0);
	system("pause");
	return 0;
}


