#include<iostream>
using namespace std;
#include "deque"
#include "algorithm"

void print(deque<int> &d) {
	for (deque<int>::iterator it = d.begin(); it != d.end(); it++) {
		cout << *it << endl;
	}
}

void fun() {
	deque<int> d1;
	d1.push_back(1);
	d1.push_front(2);
	d1.push_back(3);
	d1.push_front(4);
	d1.push_back(5);
	d1.push_front(6);

	print(d1);

	d1.pop_back();
	d1.pop_front();
	print(d1);
	cout << endl;
	deque<int>::iterator it = find(d1.begin(), d1.end(), 3);
	if (it != d1.end()) {
		cout << distance(d1.begin(), it) << endl;
	}
	else
	{
		cout << "NULL" << endl;
	}
}

void main(){
	fun();
}