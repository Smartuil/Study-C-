#include<iostream>
using namespace std;

class Parent {
public:
	Parent(int a, int b) {
		this->a = a;
		this->b = b;
		cout << "Parent构造函数" << endl;
	}

	~Parent()
	{
		cout << "Parent析构函数" << endl;
	}

	void printP(int a, int b) {
		this->a = a;
		this->b = b;
		cout << "Dad" << endl;
	}

protected:
private:
	int a;
	int b;
};

class Child : public Parent {
public:

	Child(int c, int a, int b) : Parent(a, b) {
		this->c = c;
		cout << "Child构造函数" << endl;
	}
	~Child()
	{
		cout << "Child析构函数" << endl;
	}
	void printC() {
		cout << "son" << endl;
	}
protected:
private:
	int c;
};

void ObjPlay() {
	Child c1(1, 2, 3);
}
void main() {
	//Parent p(1, 2);
	ObjPlay();
	
}