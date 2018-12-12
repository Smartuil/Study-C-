
#include<iostream>
#include "linklist_cpp.h"
using namespace std;

template <typename T>
linklist_cpp<T>::linklist_cpp(void)
{
	//Node<T> *head;
	head = new Node<T>;
	head->next = NULL;
	len = 0;
}

template <typename T>
linklist_cpp<T>::~linklist_cpp()
{
	Node<T> *tmp = NULL;
	while (head != NULL) {
		tmp = head->next;
		delete head;
		head = tmp;
	}
	len = 0;
	head = NULL;
}

template <typename T>
int linklist_cpp<T>::clear() {
	Node<T> *tmp = NULL;
	while (head != NULL) {
		tmp = head->next;
		delete head;
		head = tmp;
	}

	head = new Node<T>;
	head->next = NULL;
	len = 0;
	return 0;
}

template <typename T>
int linklist_cpp<T>::length() {

	return len;;
}

template <typename T>
int linklist_cpp<T>::insert(T& t, int pos) {
	Node<T> *current = NULL;
	current = head;
	for (int i = 0; i < pos; i++) {
		current = current->next;
	}
	Node<T> *node = new Node<T>;
	if (node == NULL) {
		return -1;
	}
	node->t = t;
	node->next = NULL;
	node->next = current->next;
	current->next = node;
	len++;
	return 0;
}

template <typename T>
int linklist_cpp<T>::get(int pos, T& t) {
	Node<T> *current = NULL;
	current = head;
	for (int i = 0; i < pos; i++) {
		current = current->next;
	}

	t = current->next->t;
	return 0;
}

template <typename T>
int linklist_cpp<T>::del(int pos, T& t) {
	Node<T> *current = NULL;
	Node<T> *ret = NULL;
	current = head;
	for (int i = 0; i < pos; i++) {
		current = current->next;
	}

	ret = current->next;//被删除饿元素
	t = ret->t;
	current->next = ret->next;
	len--;
	delete ret;

	return 0;
}
