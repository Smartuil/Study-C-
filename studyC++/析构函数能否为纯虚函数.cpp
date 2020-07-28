#include "iostream"
//https://blog.csdn.net/yapian8/article/details/46418687
using namespace std;

class A {
public:

	virtual ~A() = 0;
};

//class B : public A {
//	~B(){}
//};

int main() {
	int a[] = { 1,3,4,5,3 };
	cout << sizeof(a+1);
	cout << a + 1;
	return 0;
}