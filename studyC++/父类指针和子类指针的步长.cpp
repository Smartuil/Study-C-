#include<iostream>
using namespace std;

//构造函数中调用虚函数能发生多态吗？
class Parent {
public:
	Parent(int a = 0) {
		this->a = a;
	}

	virtual void print() {
		cout << "Dad" << endl;
	}
protected:
private:
	int a;
};

class Child : public Parent {
public:
	Child(int a = 0, int b = 0) : Parent(a) {
		//this->b = b;
	}

	virtual void print() {
		cout << "Child" << endl;
	}
protected:
private:
	//int b;
};

void howToPlay(Parent *base) {
	base->print();
}
void main() {
	Child *c = NULL;
	Parent *p = NULL;

	Child array[] = { Child(1),Child(2), Child(3) };
	p = array;
	c = array;
	p->print();
	c->print();
	p++;
	c++;
	p->print();
	c->print();
}