#include "iostream"

using namespace std;

class A {
public:
	virtual void print() {
		cout << "A's  print" << endl;
	};
	virtual ~A() {
		print();
		cout << "A's  destructor" << endl;
	}
};

class B :public A {
public:
	virtual void print() {
		cout << "B's  print" << endl;
	};
	~B() {
		print();
		cout << "B's destructor" << endl;
	}
};

int main() {
	A* a = new B;
	delete a;
	return 0;
}