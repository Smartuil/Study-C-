#include<iostream>
using namespace std;

class Obj{
public:
	Obj(int a, int b) {
		this->a = a;
		this->b = b;
		cout << "Obj���캯��" << a << " " << b << endl;
	}
	~Obj()
	{
		cout << "Obj��������" << endl;
	}
protected:
	int a;
	int b;
};

class Parent : public Obj {
public:
	Parent(const char *p) : Obj(1, 2) {
		this->p = p;
		cout << "Parent���캯��" << p << endl;
	}

	~Parent()
	{
		cout << "Parent��������" << p << endl;
	}


protected:
	const char *p;
};

class Child : public Parent {
public:
	Child(const char *p) : Parent(p), o1(3, 4), o2(5, 6) {
		myc = p;
		cout << "Child���캯��" << myc << endl;
	}

	~Child()
	{
		cout << "Child��������" << myc << endl;
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