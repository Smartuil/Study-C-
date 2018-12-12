#include<iostream>
using namespace std;


template <typename T>
class A{
public:
	A(T a = 0) {
		this->a = a;
	}

public:
	void print() {
		cout << a << endl;
	}

protected:
private:
	T a;
};


class B : public A<int>{
public:
	B(int a=10,int b=20) : A<int>(a) {
		this->b = b;
	}

	void printB() {
		cout << b << endl;
	}
protected:
private:
	int b;
};

template <typename T>
class C : public A<T>{
public:
	C(T c=10, T a=20) : A<T>(a) {
		this->c = c;
	}
	void printC() {
		cout << c << endl;
	}
protected:
private:
	T c;
};

void main() {
	C<int> c;
	c.printC();
}

void main2() {
	B b;
	b.printB();
}

void USEA(A<int> &a) {
	a.print();
}

void main1(){
	A <int>a1(111);
	USEA(a1);
}