#include<iostream>
using namespace std;

class Interface1{
public:
	virtual int add(int a, int b) = 0;
	virtual void print() = 0;
protected:
private:
};

class Interface2 {
public:
	virtual int mult(int a, int b) = 0;
	virtual void print() = 0;
protected:
private:
};

class Parent{
public:
	int getA() {
		return a;
	}
protected:
private:
	int a;
};


class Child : public Interface1, public Interface2, public Parent{
public:
	virtual int add(int a, int b) {
		cout << "Child add()" << endl;
		return a + b;
	}
	virtual void print() {
		cout << "Child print()" << endl;
	}
	virtual int mult(int a, int b) {
		cout << "Child mult()" << endl;
		return a * b;
	}
protected:
private:
};


void main(){
	Child c1;
	Interface1 *i1 = &c1;
	i1->add(1, 2);

	Interface2 *i2 = &c1;
	i2->mult(2, 3);

}
