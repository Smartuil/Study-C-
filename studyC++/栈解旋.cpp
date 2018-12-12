#include<iostream>
using namespace std;



class Test{
public:
	Test(int a = 0, int b = 0) {
		this->a = a;
		this->b = b;
		cout << "构造函数" << endl;
	}

	~Test()
	{
		cout << "析构函数" << endl;
	}

protected:
private:
	int a;
	int b;
};

void divide(int x, int y) {
	if (y == 0) {
		throw x;//抛出int类型异常
	}

	cout << x / y << endl;
}

void mydivide() {
	Test t1(1, 2), t2(2, 3);
	cout << "mydivide" << endl;
	throw 1;
}





void main() {


	try
	{
		mydivide();
	}
	catch (int e)
	{
		cout << e << "被零除" << endl;
	}
	catch (...)
	{
		cout << "未知类型异常" << endl;
	}
}