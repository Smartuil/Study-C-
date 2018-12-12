#include<iostream>
using namespace std;

class Parent{
public:
	Parent(int a) {
		this->a = a;
		cout << a << endl;
	}

	virtual void print() {
		cout << "Parent" << endl;
	}
protected:
private:
	int a;
};


class Child: public Parent{
public:
	Child(int b) : Parent(10) {
		this->b = b;
		cout << b << endl;
	}

	virtual void print() {//父类有  子类可写可不写
		cout << "Child" << endl;
	}

protected:
private:
	int b;
};


void howToPrint(Parent *base) {
	base->print();
}

void howToPrint2(Parent &base) {
	base.print();
}


void main(){
	Parent *p = NULL;
	Parent p1(20);
	Child c1(30);
	p = &p1;
	p->print();

	p = &c1;
	p->print();

	{
		Parent &base2 = p1;
		base2.print();

		Parent &base3 = c1;//别名
		base3.print();//还是父类的

	}

	{
		howToPrint(&p1);
		howToPrint(&c1);
		howToPrint2(p1);//都还是父类的  没有virtual时
		howToPrint2(c1);
	}
}