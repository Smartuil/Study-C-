#pragma once
#include<iostream>
using namespace std;

//C��û���ַ���  �ַ����ࣨC�����ַ�����
//�մ� ""
class MyString{
public:
	MyString(int len);
	MyString(const char *p);
	MyString(const MyString & s);
	~MyString();

	MyString& operator=(const char *p);
	MyString& operator=(const MyString &s);

	char& operator[](int index);

	friend ostream& operator<<(ostream &out, MyString &s);
	friend istream& operator>>(istream &in, MyString &s);

	bool operator==(const char *p) const;
	bool operator==(MyString& s) const;
	bool operator!=(const char *p) const;
	bool operator!=(MyString& s) const;

	bool operator<(const char *p);
	bool operator<(const MyString &s);
	bool operator>(const char *p);
	bool operator>(const MyString &s);
private:
	int m_len;
	char *m_p;
};