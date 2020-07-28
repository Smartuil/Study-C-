#define  _CRT_SECURE_NO_WARNINGS 
#include <iostream>

using namespace std;

class A
{
public:
	static int s;
	virtual void print1() {}
private:

};

int A::s = 0;//静态成员变量要在类的外部初始化

class B :public A
{
public:
	virtual void print1() {}
private:
};

int main(void)
{
	B b;
	cout << b.s << endl;
	b.s = 100;
	cout << b.s << endl;

	cout << A::s << endl;

	A a = b;
	a.print1();
	A *aa = new B;
	aa->print1();
	return 0;
}