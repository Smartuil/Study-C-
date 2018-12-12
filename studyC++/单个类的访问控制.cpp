#include<iostream>
using namespace std;

//private 只能在内部使用
//protected 内部使用，继承的子类中可用
class Parent{
public:
	int a;
protected:
	int b;
private:
	int c;

public:
	void print() {
		cout << "print" << endl;
	}
};


class Child : public Parent{
public:
	void useVar() {
		a = 0;
		b = 0;
		//c = 0;
	}
protected:
private:
};

class Child2 : private Parent {
public:
	void useVar() {
		a = 0;
		b = 0;
		//c = 0;
	}
protected:
private:
};

class Child3 : protected Parent {
public:
	void useVar() {
		a = 0;
		b = 0;
		//c = 0;
	}
protected:
private:
};


void main1(){
	Parent p1, p2;
	p1.a = 10;
	//p1.b = 20;
	//p2.c = 30;
}

void main2() {
	Child2 c1, c2;
	//c1.a = 10;
	//c1.b = 20;
	//c2.c = 30;
}

void main() {
	Child2 c1, c2;
	//c1.a = 10;
	//c1.b = 20;
	//c2.c = 30;
}