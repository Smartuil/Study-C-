#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include "MyString.h"


MyString::MyString(int len) {
	if (len == 0) {
		m_len = 0;
		m_p = new char[m_len + 1];
		strcpy(m_p, "");
	}
	else {
		m_len = len;
		m_p = new char[m_len + 1];
		memset(m_p, 0, m_len);
	}
	
}

MyString::MyString(const char *p) {
	if (p == NULL) {
		m_len = 0;
		m_p = new char[m_len + 1];
		strcpy(m_p, "");
	}
	else {
		m_len = strlen(p);
		m_p = new char[m_len + 1];
		strcpy(m_p, p);
	}

}

MyString::MyString(const MyString & s) {
	m_len = s.m_len;
	m_p = new char[m_len + 1];
	strcpy(m_p, s.m_p);
}

MyString::~MyString() {
	if (m_p != NULL) {
		delete[] m_p;
		m_p = NULL;
		m_len = 0;
	}
}

MyString& MyString::operator=(const char *p) {
	//旧的内存释放
	if (m_p != NULL) {
		delete[] m_p;
		m_len = 0;
	}
	//根据p分配内存
	if (p == NULL) {
		m_len = 0;
		m_p = new char[m_len + 1];
		strcpy(m_p, "");
	}
	else
	{
		m_len = strlen(p);
		m_p = new char[m_len + 1];
		strcpy(m_p, p);
	}
	return *this;
	
}

MyString& MyString::operator=(const MyString &s) {
	//旧的内存释放
	if (m_p != NULL) {
		delete[] m_p;
		m_len = 0;
	}
	//根据p分配内存

	m_len = s.m_len;
	m_p = new char[m_len + 1];
	strcpy(m_p, s.m_p);

	return *this;
}

char& MyString::operator[](int index) {
	return m_p[index];
}

ostream& operator<<(ostream &out, MyString &s) {
	out << s.m_p;
	return out;
}
istream& operator>>(istream &in, MyString &s) {
	cin >> s.m_p;
	return in;
}


bool MyString::operator==(const char *p) const {
	if (p == NULL) {
		if (m_len == 0) {
			return 1;
		}
		else {
			return 0;
		}
	}
	else {
		if (m_len == strlen(p)) {
			return !strcmp(m_p, p);
		}
		else {
			return 0;
		}
	}
	return 1;
}

bool MyString::operator==(MyString& s) const {
	if (m_len != s.m_len) {
		return 0;
	}
	return !strcmp(m_p, s.m_p);
}

bool MyString::operator!=(const char *p) const {
	return !(*this == p);
}

bool MyString::operator!=(MyString& s) const {
	return !(*this == s);
}

bool MyString::operator<(const char *p) {
	return strcmp(this->m_p, p);
}

bool MyString::operator<(const MyString &s) {
	return strcmp(this->m_p, s.m_p);
}

bool MyString::operator>(const char *p) {
	return strcmp(p, this->m_p);
}

bool MyString::operator>(const MyString &s) {
	return strcmp(s.m_p, this->m_p);
}
