#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;

class A{
public:
	A() {
		p = new char[20];
		strcpy(p, "aaa");
		cout << "A" << endl;
	}

	 virtual ~A()//子类的析构函数也会执行
	{
		delete[] p;
		cout << "~A" << endl;
	}
protected:
private:
	char *p;
};

class B : public A {
public:
	B() {
		p = new char[20];
		strcpy(p, "bbb");
		cout << "B" << endl;
	}

	~B()
	{
		delete[] p;
		cout << "~B" << endl;
	}
protected:
private:
	char *p;
};

class C : public B {
public:
	C() {
		p = new char[20];
		strcpy(p, "ccc");
		cout << "C" << endl;
	}

	~C()
	{
		delete[] p;
		cout << "~C" << endl;
	}
protected:
private:
	char *p;
};

//想通过父类指针  把所有的子类对象的析构函数都执行一遍
//想通过父类指针 释放所有的子类资源
void howToDelete(A *base) {
	delete base;
}

void main(){
	C *myc = new C;
	//howToDelete(myc);
	 
	delete myc;//没有virtual   这样也可以全部析构

}