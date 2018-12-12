#include<iostream>
using namespace std;

class A{
public:
	int a;
	int b;

public:
	void get() {
		cout << b << endl;
	}
protected:
private:
};

class B : public A{
public:
	int b;
	int c;

public:
	void get() {
		cout << b << endl;
	}
protected:
private:
};

void main(){
	B b1;
	b1.b = 1;
	b1.A::b = 100;
	b1.A::get();
}