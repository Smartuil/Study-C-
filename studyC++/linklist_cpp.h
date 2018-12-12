#pragma once

template <typename T>
struct Node {
	T t;
	Node<T> *next;
};


template <typename T>
class linklist_cpp
{
public:
	linklist_cpp(void);
	~linklist_cpp();

	int clear();

	int length();

	int insert(T& t, int pos);

	int get(int pos, T& t);

	int del(int pos, T& t);

private:
	Node<T> *head;
	int len;
};

