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
		cout << "b���" << endl;
	}
	else
	{
		cout << "�����" << endl;
	}

	if (s2 != s3) {
		cout << "���" << endl;
	}
	else {
		cout << "�����" << endl;
	}
}

void main222() {
	//MyString s1;
	MyString s2("s2");
	MyString s3 = s2;

	s3 = "11";

	if (s3 < "22") {
		cout << "С��" << endl;
	}
	else {
		cout << "����" << endl;
	}

	if (s3 < s2) {
		cout << "С��" << endl;
	}
	else {
		cout << "����" << endl;
	}
}

void main() {
	MyString s1(128);
	cin >> s1;
	cout << s1;
}