#include<iostream>
using namespace std;

class A {
public:
	//Ĭ����private
	A() {
		cout << "A����" << endl;
	}
public:
	static int a;
	int b;

public:
	void get() {
		cout << b << endl;
	}


protected:
private:
};
int A::a = 100;

class B : private A {
public:
	int b;
	int c;

public:
	void get() {
		cout << b << endl;
		cout << a << endl;
	}

	B() {
		cout << "B����" << endl;
	}
protected:
private:
};

void main() {
	A a1;
	a1.get();
	B b1;
	b1.get();
}