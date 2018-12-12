#pragma once
#include<iostream>
using namespace std;

template <typename T>
class MyVector
{
	
public:
	MyVector(int size = 0);
	MyVector(const MyVector &obj);
	~MyVector();

public:
	T& operator[](int index);
	MyVector& operator=(const MyVector &obj);
	friend ostream& operator<< <T>  (ostream &out, const MyVector &m);



	int getLen() {
		return m_len;
	}
protected:
	int m_len;
	T *m_space;
};

