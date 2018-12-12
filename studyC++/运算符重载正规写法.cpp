#include<iostream>
using namespace std;

//运算符重载本质是函数调用
class Complex {
public:
	friend ostream& operator<<(ostream &out, Complex c);
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
		Complex tmp = *this;
		this->a--;
		this->b--;
		return tmp;
	}

	Complex operator + (Complex &a1) {
		Complex tmp(a1.a + this->a, a1.b + this->b);
		return tmp;
	}

	Complex& operator ++ () {
		this->a++;
		this->b++;
		return *this;
	}

	Complex operator ++ (int) {
		Complex tmp = *this;
		this->a++;
		this->b++;
		return tmp;
	}


protected:
private:
	int a;
	int b;
};


void main1() {

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

ostream& operator<<(ostream &out, Complex c) {
	out << c.a << "+" << c.b << "i" << endl;
	return out;
}

void main() {
	int a = 10;
	Complex c1(1, 2);
	Complex c2(3, 4);
	//函数返回值当左值需要返回一个引用
	cout << c1 << "aaa" ;

}