#include<iostream>
using namespace std;


class A{
public:
	virtual void print() = 0;
protected:
private:
};

class B : public A {
public:
	void print() {
		cout << "B" << endl;
	}
protected:
private:
};

void main(){
	A *a = NULL;
	a = new B;
	a->print();

}