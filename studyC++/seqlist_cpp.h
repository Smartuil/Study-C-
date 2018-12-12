#pragma once

template <typename T>
class seqlist_cpp
{
public:
	seqlist_cpp(int cap);
	~seqlist_cpp();


	int getLength();

	int getCapacity();

	int insert(T &t, int pos);

	int get(int pos, T &t);

	int del(int pos, T &t);

	int clear();

private:
	int len;
	int capacity;
	T *pArray;
};

