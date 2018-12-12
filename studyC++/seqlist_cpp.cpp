#include "seqlist_cpp.h"
#include<iostream>
using namespace std;



template <typename T>
seqlist_cpp<T>::seqlist_cpp(int cap)
{
	pArray = new T[cap];
	this->capacity = cap;
	this->len = 0;
}

template <typename T>
seqlist_cpp<T>::~seqlist_cpp()
{
	delete[] pArray;
	pArray = NULL;
	this->len = 0;
	this->capacity = 0;
}

template <typename T>
int seqlist_cpp<T>::getLength() {

	return this->len;
}

template <typename T>
int seqlist_cpp<T>::getCapacity() {

	return this->capacity;
}

template <typename T>
int seqlist_cpp<T>::insert(T &t, int pos) {
	int i = 0;
	if (pos < 0) {
		return -1;
	}

	for (i = this->len; i > pos; i--) {
		pArray[i] = pArray[i - 1];
	}

	pArray[i] = t;//stl元素保存时通过复制的机制实现的  你的类要可以复制才行
	this->len++;
	return 0;
}

template <typename T>
int seqlist_cpp<T>::get(int pos, T &t) {
	int i = 0;
	if (pos < 0) {
		return -1;
	}
	t = pArray[pos];
	return 0;
}

template <typename T>
int seqlist_cpp<T>::del(int pos, T &t) {
	int i = 0;
	if (pos < 0) {
		return -1;
	}
	t = pArray[pos];
	for (i = pos + 1; i < this->len; i++) {
		pArray[i - 1] = pArray[i];
	}
	this->len--;

	return 0;
}

template <typename T>
int seqlist_cpp<T>::clear() {
	this->len = 0;
	return 0;
}