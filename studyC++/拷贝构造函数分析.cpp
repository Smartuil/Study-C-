#define  _CRT_SECURE_NO_WARNINGS 
#include <iostream>

using namespace std;

class A {
public:
	A() {
		cout << "构造函数" << endl;
	}
	
	A(const A & a) {
		cout << "copy构造函数" << endl;
	}

	void operator=(const A & a) {
		cout << "=" << endl;
	}
};

int main() {
	A a;
	A aa(a);//copy

	A aaa = a;//copy

	A aaaa;
	aaaa = a;//=

	return 0;
}