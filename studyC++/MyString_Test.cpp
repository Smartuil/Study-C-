#include<iostream>
#include "MyString.h"
using namespace std;

void main111() {
	//MyString s1;
	MyString s2("s2");
	MyString s3 = s2;
	MyString s4 = "22222";
	s4 = s2;
	s4 = "22222";
	cout << s4[1] <<endl;
	cout << s4 << endl;
	if (s2 != "111"){
		cout << "b相等" << endl;
	}
	else
	{
		cout << "不相等" << endl;
	}

	if (s2 != s3) {
		cout << "相等" << endl;
	}
	else {
		cout << "不相等" << endl;
	}
}

void main222() {
	//MyString s1;
	MyString s2("s2");
	MyString s3 = s2;

	s3 = "11";

	if (s3 < "22") {
		cout << "小于" << endl;
	}
	else {
		cout << "大于" << endl;
	}

	if (s3 < s2) {
		cout << "小于" << endl;
	}
	else {
		cout << "大于" << endl;
	}
}

void main() {
	MyString s1(128);
	cin >> s1;
	cout << s1;
}