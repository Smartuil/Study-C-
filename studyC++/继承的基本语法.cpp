#include<iostream>
using namespace std;


class Parent{
public:
	void print() {
		a = 0;
		b = 0;
		cout << a << " " << b << endl;
	}


protected:
private:
	int a;
	int b;
};

class Child : public Parent{
//class Child : protected Parent{
//class Child : private Parent{
public:
protected:
private:
	int c;
};

void main(){
	Child c1;
	c1.print();
	//c1.a;
}