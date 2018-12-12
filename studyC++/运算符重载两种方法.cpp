#include<iostream>
using namespace std;

//运算符重载本质是函数调用
class Complex {
public:
	friend Complex operator + (Complex &a1, Complex &b1);
	friend Complex& operator ++ (Complex &c);
	friend Complex operator ++ (Complex &c, int);
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

	Complex& operator --() {
		this->a--;
		this->b--;
		return *this;
	}

	Complex operator --(int) {
		Complex tmp =  *this;
		this->a--;
		this->b--;
		return tmp;
	}

protected:
private:
	int a;
	int b;
};
//全局函数方式
Complex operator + (Complex &a1, Complex &b1) {
	Complex tmp(a1.a + b1.a, a1.b + b1.b);
	return tmp;
}

Complex& operator ++ (Complex &c) {
	c.a++;
	c.b++;
	return c;
}

Complex operator ++ (Complex &c, int) {
	Complex tmp = c;
	c.a++;
	c.b++;
	return tmp;
}

void main() {

	Complex c1(1, 2);
	Complex c2(3, 4);
	Complex c3;
	c3 = c1 + c2;
	c3.print();

	c3 = c1 - c2;
	c3.print();

	//前置++  --
	++c1;
	c1.print();
	--c2;
	c2.print();

	//后置
	c1++;
	c1.print();
	c2--;
	c2.print();
}