#include "complex.h"



//构造函数写在类的外部
template <typename T>
Complex<T>::Complex(T a, T b) {
	this->a = a;
	this->b = b;
}

template <typename T>
void Complex<T>::print() {
	cout << a << "+" << b << "i" << endl;
}

template <typename T>
Complex<T> Complex<T>::operator+(Complex<T> &c) {
	Complex tmp(this->a + c.a, this->b + b);
	return tmp;
}

//友元函数实现 <<  运算符重载
template <typename T>
ostream &operator<<(ostream &out, Complex<T>  &c) {
	out << c.a << "+" << c.b << "i" << endl;
	return out;
}


template <typename T>
Complex<T> mySub(Complex<T> &c1, Complex<T> &c2) {
	Complex<T> tmp(c1.a - c2.a, c1.b - c2.b);
	return tmp;
}
