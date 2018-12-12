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
	cout << "普通函数" << endl;
}

void main() {
	int a = 10;
	char c = 'a';
	swap2(a, c);
	swap2(a, a);//调用模板函数
	swap2(c, a);//隐式类型转换
}