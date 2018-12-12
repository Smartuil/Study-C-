#include<iostream>
using namespace std;


//class Complex{
//public:
//
//	friend ostream &operator<<(ostream &out, Complex C);
//	Complex(int a = 0, int b = 0) {
//		this->a = a;
//		this->b = b;
//	}
//
//	void print() {
//		cout << a << "+" << b << "i" << endl;
//	}
//
//	Complex operator+(Complex &c) {
//		Complex tmp(this->a + c.a, this->b + b);
//		return tmp;
//	}
//
//protected:
//private:
//	int a;
//	int b;
//};
//
//ostream &operator<<(ostream &out, Complex c) {
//	out<< c.a << "+" << c.b << "i" << endl;
//	return out;
//}

template <typename T>
class Complex {

	friend ostream &operator<<(ostream &out, Complex &c) {
		out << c.a << "+" << c.b << "i" << endl;
		return out;
	}

	friend Complex mySub(Complex &c1, Complex &c2) {
		Complex tmp(c1.a - c2.a, c1.b - c2.b);
		return tmp;
	}

public:


	Complex(T a, T b) {
		this->a = a;
		this->b = b;
	}

	void print() {
		cout << a << "+" << b << "i" << endl;
	}

	Complex operator+(Complex &c) {
		Complex tmp(this->a + c.a, this->b + b);
		return tmp;
	}

protected:
private:
	T a;
	T b;
};




//ostream &operator<<(ostream &out, Complex &c) {
//	out << c.a << "+" << c.b << "i" << endl;
//	return out;
//}

void main(){
	Complex <int>c1(1, 2);
	Complex <int>c2(3, 4);

	Complex <int>c3 = c1 + c2;
	cout << c3 << endl;

	{
		Complex <int>c4 = mySub(c1 , c2);
		cout << c4 << endl;
	}


}