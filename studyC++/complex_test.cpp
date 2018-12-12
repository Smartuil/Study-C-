#include<iostream>
#include "complex.h"
#include "complex.cpp"//重点！！！！！！！！！！！！！！！
using namespace std;

void main() {
	Complex <int>c1(1, 2);
	Complex <int>c2(3, 4);

	Complex <int>c3 = c1 + c2;
	cout << c3 << endl;

	{
		Complex <int>c4 = mySub<int>(c1, c2);
		cout << c4 << endl;
	}

}