#include<iostream>
using namespace std;

class Obj{
public:
	Obj(int a, int b) {
		this->a = a;
		this->b = b;
		cout << "Obj构造函数" << a << " " << b << endl;
	}
	~Obj()
	{
		cout << "Obj析构函数" << endl;
	}
protected:
	int a;
	int b;
};

class Parent : public Obj {
public:
	Parent(const char *p) : Obj(1, 2) {
		this->p = p;
		cout << "Parent构造函数" << p << endl;
	}

	~Parent()
	{
		cout << "Parent析构函数" << p << endl;
	}


protected:
	const char *p;
};

class Child : public Parent {
public:
	Child(const char *p) : Parent(p), o1(3, 4), o2(5, 6) {
		myc = p;
		cout << "Child构造函数" << myc << endl;
	}

	~Child()
	{
		cout << "Child析构函数" << myc << endl;
	}

protected:
	const char *myc;
	Obj o1;
	Obj o2;

};

void ObjPlay() {


	Child c1("Test");
}
void main() {
	//Parent p(1, 2);
	ObjPlay();

}