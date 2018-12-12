#include<iostream>
using namespace std;

//运算符重载本事是函数调用
class Complex {
public:
	int a;
	int b;

	Complex(int a = 0, int b = 0) {
		this->a = a;
		this->b = b;
	} 

	void print() {
		cout << a << "+" << b << "i" << endl;
	}
	//成员函数实现 
	Complex operator - (Complex &c) {
		Complex tmp(this->a - c.a, this->b - c.b);
		return tmp;
	}

protected:
private:
};
//全局函数方式
Complex operator + (Complex &a1, Complex &b1) {
	Complex tmp(a1.a + b1.a, a1.b + b1.b);
	return tmp;
}

void main(){
	int a = 0;
	int b = 0;
	int c;
	c = a + b;

	Complex c1(1, 2);
	Complex c2(3, 4);
	Complex c3;
	c3 = c1 + c2;
	c3.print();

	c3 = c1 - c2;
	c3.print();
}