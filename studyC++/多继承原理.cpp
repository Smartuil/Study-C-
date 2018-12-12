#include<iostream>
using namespace std;

class B {
public:
	int b;

	B() {
		cout << "构造" << endl;
	}
};

class B1 :  public B {
public:
	int b1;
};

class B2 :  public B {//虚继承解决二义性
public:
	int b2;
};

class C : public B1, public B2 {
public:
	int c;
};

void main1() {
	C c1;
	c1.b1 = 100;
	c1.b2 = 200;
	c1.c = 300;
	//c1.b = 400;
}

class C1{
public:
	int k;
protected:
private:
};

class C2 {
public:
	int k;
protected:
private:
};

class D : virtual public C1,public C2 {
public:
protected:
private:
};

void main() {
	D d;
	d.C1::k = 9;
	//d.k;//虚继承解决不了
}