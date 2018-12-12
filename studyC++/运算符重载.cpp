#include<iostream>
using namespace std;

//��������ر����Ǻ�������
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
	//��Ա����ʵ�� 
	Complex operator - (Complex &c) {
		Complex tmp(this->a - c.a, this->b - c.b);
		return tmp;
	}

protected:
private:
};
//ȫ�ֺ�����ʽ
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