#include<iostream>
using namespace std;

class Parent {
public:
	Parent(int a = 0) {
		this->a = a;
	}

	void print() {
		cout << "Dad" << endl;
	}
protected:
private:
	int a;
};

class Parent2 {
public:
	Parent2(int a = 0) {
		this->a = a;
	}

	virtual void print() {
		cout << "Dad" << endl;
	}
protected:
private:
	int a;
};

void howToPlay(Parent *base) {
	base->print();
}
void main() {
	cout << sizeof(Parent) << " " << sizeof(Parent2);
}