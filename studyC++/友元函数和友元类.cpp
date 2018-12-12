#include<iostream>
using namespace std;



class A{
public:
	friend void modifyA(A *pA, int _a);
	friend class B;
	A(int a = 0, int b = 0) {
		this->a = a;
		this->b = b;
	}

	void getA() {
		cout << a << endl;
	}
protected:
private:
	int a;
	int b;
};

class B{
public:
	void set(int a) {
		obj.a = a;
	}
	void get() {
		cout << obj.a << endl;
	}
protected:
private:
	A obj;
};

void modifyA(A *pA,int _a) {
	pA->a = _a;
}

void main(){
	//A a1(1,2);
	//a1.getA();

	//modifyA(&a1, 100);
	//a1.getA();
	B b1;
	b1.set(1000);
	b1.get();
}