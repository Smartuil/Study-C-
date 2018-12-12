#include<iostream>
#include "MyArray.h"
using namespace std;


Array::Array(int length) {
	if (length < 0) {
		length = 0;
	}
	m_length = length;
	m_space = new int[m_length];
}

Array::Array(const Array& obj) {
	this->m_length = obj.m_length;
	this->m_space = new int[this->m_length];
	for (int i = 0; i < obj.m_length; i++) {//数组元素复制
		this->m_space[i] = obj.m_space[i];
	}
}

Array::~Array() {
	if (m_space != NULL) {
		delete[] m_space;
		m_length = 0;
	}
}


void Array::setData(int index, int value) {
	m_space[index] = value;
}
int Array::getData(int index) {
	return m_space[index];
}
int Array::length() {
	return m_length;
}

int& Array::operator[] (int i) {

	return m_space[i];
}

Array& Array::operator=(Array &a) {
	//释放原来的内存空间
	if (this->m_space != NULL) {
		delete[] m_space;
		m_length = 0;
	}

	m_length = a.m_length;
	m_space = new int[m_length];

	for (int i = 0; i < m_length; i++) {
		m_space[i] = a[i];
	}
	return *this;
}

bool Array::operator==(Array &a) {
	if (this->m_length != a.m_length) {
		return 0;
	}

	for (int i = 0; i < m_length; i++) {
		if (this->m_space[i] != a[i]) {
			return 0;
		}
	}
	return 1;
}

bool Array::operator!=(Array &a) {
	if (*this == a) {
		return 1;
	}
	else {
		return 0;
	}	
}
