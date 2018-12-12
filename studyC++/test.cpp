#include<iostream>
using namespace std;
class A{
public:
	A() {
		cout << "构造函数" << endl;
	}
	A(const A &a) {
		cout << "copy构造函数" << endl;
	}
	//A& operator=(const A &a) {
	//	cout << "=构造函数" << endl;
	//	return *this;
	//}
protected:
private:
};



void main(){
	A a1;
	A a2(a1);
	A a3 = a2;
	//a1 = a2;
}