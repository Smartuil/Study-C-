#pragma once
#include "iostream"
using namespace std;
template <typename T>
class Complex;
template <typename T>
Complex<T> mySub(Complex<T> &c1, Complex<T> &c2);


template <typename T>
class Complex {

	friend ostream &operator<<<T>(ostream &out, Complex<T> &c);  //<< >>只有这两个用友元函数

	friend Complex mySub<T>(Complex &c1, Complex &c2);

public:


	Complex(T a, T b);

	void print();

	Complex operator+(Complex &c);

protected:
private:
	T a;
	T b;
};
