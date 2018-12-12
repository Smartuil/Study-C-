#include<iostream>
using namespace std;

class Parent{
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

class Child : public Parent{
public:
	Child(int a = 0, int b = 0 ) : Parent(a) {
		this->b = b;
	}

	virtual void print() {
		cout << "Child" << endl;
	}
protected:
private:
	int b;
};

void howToPlay(Parent *base) {
	base->print();
}
void main(){
	Parent p1;
	Child c1;

	howToPlay(&p1);
	howToPlay(&c1);
}