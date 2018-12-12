#include "MyVector.h"

using namespace std;



template <typename T>
MyVector<T>::MyVector(int size) {
	m_len = size;
	m_space = new T[m_len];
}

template <typename T>
MyVector<T>::MyVector(const MyVector &obj) {
	m_len = obj.m_len;
	m_space = new T[m_len];
	for (int i = 0; i < m_len; i++) {
		m_space[i] = obj.m_space[i];
	}
}

template <typename T>
MyVector<T>::~MyVector() {
	if (m_space != NULL) {
		delete[] m_space;
		m_space = NULL;
		m_len = 0;
	}
}

template <typename T>
T& MyVector<T>::operator[](int index) {
	return m_space[index];
}

//a1 = a2 = a1
template <typename T>
MyVector<T>& MyVector<T>::operator=(const MyVector<T> &obj) {
	//先把旧的内存释放掉
	if (m_space != NULL) {
		delete[] m_space;
		m_space = NULL;
		m_len = 0;
	}
	//根据a1分配内存
	m_len = obj.m_len;
	m_space = new T[m_len];
	//copy数据
	for (int i = 0; i < m_len; i++) {
		m_space[i] = obj[i];
	}
	return *this;
}

template <typename T>
ostream &operator<<(ostream &out, const MyVector<T> &m) {
	for (int i = 0; i < m.m_len; i++) {
		out << m.m_space[i];
	}
	out << endl;
	return out;
}


