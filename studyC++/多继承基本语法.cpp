#include<iostream>
using namespace std;

class A{
public:
	A(int b) {
		this->b1 = b;
	}

	void printA() {
		cout << b1 << endl;
	}
protected:
private:
	int b1;
};

class B {
public:
	B(int b) {
		this->b2 = b;
	}

	void printB() {
		cout << b2 << endl;
	}
protected:
private:
	int b2;
};

class C : public A, public B{
public:
	C(int b1, int b2, int c) : A(b1), B(b2){
		this->c = c;
	}

	void printC() {
		cout << c << endl;
	}
protected:
private:
	int c;
};


void main(){
	C c(1, 2, 3);
	c.printA();
	c.printB();
	c.printC();
}