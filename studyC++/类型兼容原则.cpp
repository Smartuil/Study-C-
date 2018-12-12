#include<iostream>
using namespace std;

class Parent{
public:
	void printP() {
		cout << "dad" << endl;
	}

	Parent() {
		cout << "Parent构造函数" << endl;
	}

	Parent(const Parent &obj) {
		cout << "Parent  copy构造函数" << endl;
	}
protected:
private:
	int a;
};

class Child : public Parent {
public:
	void printC() {
		cout << "son" << endl;
	}
protected:
private:
	int c;
};

void howToPrint(Parent *base) {
	base->printP();
}

void howToPrint2(Parent &base) {
	base.printP();
}

void main(){
	Parent p1;
	p1.printP();

	Child c1;
	c1.printP();
	c1.printC();
	//赋值兼容原则
	//1-1 基类指针（引用）指向子类对象
	Parent *p = NULL;
	p = &c1;
	p->printP();

	//1-2 指针做函数参数

	howToPrint(&p1);
	howToPrint(&c1);
	//1-3引用做函数参数

	howToPrint2(p1);
	howToPrint2(c1);

	//第二层含义
	//父类对象初始化子类对象      子类就是一种特殊的父类
	Parent p3 = c1;
}