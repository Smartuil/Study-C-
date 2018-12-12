#include<iostream>
using namespace std;
#include "list"

void fun() {
	list<int> l;
	for (int i = 0; i < 10; i++) {
		l.push_back(i);
	}

	list<int>::iterator it = l.begin();
	while (it != l.end()) {
		cout << *it << endl;
		it++;
	}
	it = l.begin();
	it++;
	it++;
	it++;
	l.insert(it, 100);//插入在前边
	it = l.begin();
	while (it != l.end()) {
		cout << *it << endl;
		it++;
	}

}

void main(){
	fun();
}