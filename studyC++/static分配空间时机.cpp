#include "iostream"

using namespace std;
//
//int fun() {
//	cout << "static����" << endl;
//	return 5;
//}
//
//static int n = fun();
//
//int main() {
//	cout << "���������" << endl;
//	return 0;
//}

class A
{
public:
	A() { cout << "A" << endl; }
	~A() { cout << "~A" << endl; }
};

class B :public A
{
public:
	B(A &a) :_a(a)
	{
		cout << "B" << endl;
	}
	B() {}
	~B()
	{
		cout << "~B" << endl;
	}
private:
	A _a;
};

int main(void)
{
	//A a;       //�ܼ򵥣�����a��ʱ�������һ�ι��캯��  
	//B b(a);
	B b;
}