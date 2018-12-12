#include<iostream>
using namespace std;

template <typename T>
void swap2(T &a, T &b) {
	T c = 0;
	c = a;
	a = b;
	b = c;
}

void swap2(int a, char c) {
	cout << a << c << endl;
	cout << "ÆÕÍ¨º¯Êý" << endl;
}

void main() {
	int x = 10;
	int y = 20;
	cout << x << " " << y << endl;
	swap2<int>(x, y);
	cout << x << " " << y << endl;

	char a = 'q';
	char b = 'w';
	swap2(a, b);
	cout << a << " " << b << endl;
}