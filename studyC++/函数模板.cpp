#include<iostream>
using namespace std;

void swap1(int &a, int &b) {
	int c = 0;
	c = a;
	a = b;
	b = c;
}

template <typename T>
void swap2(T &a, T &b) {
	T c = 0;
	c = a;
	a = b;
	b = c;
}

void main(){
	int x = 10;
	int y = 20;
	swap1(x, y);
	cout << x << " " << y << endl;
	swap2<int>(x, y);
	cout << x << " " << y << endl;

	char a = 'q';
	char b = 'w';
	swap2(a, b);//自动类型推倒
	cout << a << " " << b << endl;
}