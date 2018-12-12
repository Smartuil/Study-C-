#include<iostream>
using namespace std;

template <typename T>
class Complex;
template <typename T>
Complex<T> mySub(Complex<T> &c1, Complex<T> &c2);


template <typename T>
class Complex {

	friend ostream &operator<<<T>(ostream &out, Complex &c);  //<< >>ֻ������������Ԫ����

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

//���캯��д������ⲿ
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

//��Ԫ����ʵ�� <<  ���������
template <typename T>
ostream &operator<<(ostream &out, Complex<T>  &c) {
	out << c.a << "+" << c.b << "i" << endl;
	return out;
}


//������Ԫ����
template <typename T>
Complex<T> mySub(Complex<T> &c1, Complex<T> &c2) {
	Complex<T> tmp(c1.a - c2.a, c1.b - c2.b);
	return tmp;
}

void main() {
	Complex <int>c1(1, 2);
	Complex <int>c2(3, 4);

	Complex <int>c3 = c1 + c2;
	cout << c3 << endl;

	{
		Complex <int>c4 = mySub(c1, c2);
		cout << c4 << endl;
	}


}