#include "iostream"

using namespace std;
//
//int fun() {
//	cout << "static调用" << endl;
//	return 5;
//}
//
//static int n = fun();
//
//int main() {
//	cout << "主函数入口" << endl;
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
	//A a;       //很简单，定义a的时候调用了一次构造函数  
	//B b(a);
	B b;
}