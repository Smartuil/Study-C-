#include<iostream>
using namespace std;

//构造函数中调用虚函数能发生多态吗？
class Parent {
public:
	Parent(int a = 0) {
		this->a = a;
		print();
	}

	virtual void print() {
		cout << "Dad" << endl;
	}
protected:
private:
	int a;
};

class Child : public Parent {
public:
	Child(int a = 0, int b = 0) : Parent(a) {
		this->b = b;
		print();
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
void main() {
	Parent p1;
	Child c1;//定义一个子类对象 在这个过程中，在父类构造函数中调用虚函数print
	

}