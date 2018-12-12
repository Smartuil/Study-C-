#include<iostream>
using namespace std;


void divide(int x, int y) {
	if (y == 0) {
		throw x;//抛出int类型异常
	}

	cout << x / y << endl;
}

void mydivide(int x, int y) {
	divide(x, y);
}




void main() {
	try
	{
		throw 'Z';
	}
	catch (int e)
	{
		cout << "int 异常" << endl;
	}
	catch (...){
		cout << "未知 异常" << endl;
	}
}



void main1(){


	try
	{
		//divide(100, 4);
		//divide(10, 0);
		mydivide(1, 0);
	}
	catch (int e)
	{
		cout << e << "被零除" << endl;
	}
	catch ( ... )
	{
		cout << "未知类型异常" << endl;
	}
}