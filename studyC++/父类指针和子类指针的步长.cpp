//#include<iostream>
//using namespace std;
//
////构造函数中调用虚函数能发生多态吗？
//class Parent {
//public:
//	Parent(int a = 0) {
//		this->a = a;
//	}
//
//	virtual void print() {
//		cout << "Dad" << endl;
//	}
//protected:
//private:
//	int a;
//};
//
//class Child : public Parent {
//public:
//	Child(int a = 0, int b = 0) : Parent(a) {
//		//this->b = b;
//	}
//
//	virtual void print() {
//		cout << "Child" << endl;
//	}
//protected:
//private:
//	//int b;
//};
//
//void howToPlay(Parent *base) {
//	base->print();
//}
//void main() {
//	Child *c = NULL;
//	Parent *p = NULL;
//
//	Child array[] = { Child(1),Child(2), Child(3) };
//	p = array;
//	c = array;
//	p->print();
//	c->print();
//	p++;
//	c++;
//	p->print();
//	c->print();
//}

#define  _CRT_SECURE_NO_WARNINGS 
#include <iostream>

using namespace std;

class Parent
{
public:
	Parent(int a)
	{
		this->a = a;
	}

	virtual void print()
	{
		cout << "Parent::print() " << a << endl;
	}
protected:
	int a;
};

class Child :public Parent {
public:
	Child(int a) :Parent(a)
	{

	}

	virtual void print()
	{
		cout << "Child :: Print() " << a << endl;
	}
private:
	int b;
};

int main(void)
{
	
	Child array[] = { Child(0), Child(1), Child(2) };
	//						array[0]   array[1] array[2]

	Child *cp = &array[0];
	Parent *pp = &array[0];


	cp->print(); //Child::
	pp->print(); //Child::发生多态

	Parent pppp(10);
	Child ccc(10);
	cout << sizeof(ccc);
	cout << sizeof(pppp);

	cout << "------" << endl;

	cp++; //Child::12
	//pp++;//8
	pp = cp;

	cp->print();
	pp->print();

	cout << " -----  " << endl;


	int i = 0;
	for (i = 0, cp = &array[0], pp = cp; i < 3; i++, cp++, pp = cp) {
		pp->print();
	}

	return 0;
}