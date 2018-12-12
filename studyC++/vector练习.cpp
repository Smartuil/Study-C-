#include<iostream>
using namespace std;
#include "vector"


void print(vector<int> &v) {
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}
}


void fun() {
	vector<int> v1;
	cout << v1.size() << endl;

	v1.push_back(1);
	v1.push_back(3);
	cout << v1.size() << endl;

	cout << v1.front() << endl;
	v1.front() = 11;//修改头部元素
	v1.back() = 111111;
	while (v1.size() > 0) {
		cout << v1.back() << " ";
		v1.pop_back();
	}

}

void fun2() {
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);
	v1.push_back(7);

	vector<int>v2 = v1;
	vector<int>v3(v1.begin(), v1.end());
}

void fun3() {
	vector<int> v1(10);

	for (int i = 0; i < 10; i++) {
		v1[i] = i + 1;
	}

	print(v1); 
}

void fun4() {
	vector<int> v1(10);
	v1.push_back(1);
	v1.push_back(2);
	print(v1);
}

void fun5() {
	vector<int> v1(10);
	for (int i = 0; i < 10; i++) {
		v1[i] = i + 1;
	}

	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++) {
		cout << *it << endl;
	}

	for (vector<int>::reverse_iterator it = v1.rbegin(); it != v1.rend(); it++) {
		cout << *it << endl;
	}
}

void fun6() {
	vector<int> v1(10);
	for (int i = 0; i < 10; i++) {
		v1[i] = i + 1;
	}
	v1.erase(v1.begin(), v1.begin() + 3);
	print(v1);
	v1.erase(v1.begin());
	print(v1);
	v1[1] = 2;
	v1[3] = 2;
	print(v1);
	for (vector<int>::iterator it = v1.begin(); it != v1.end(); ) {
		if (*it == 2) {
			it = v1.erase(it);
		}
		else
		{
			it++;
		}
	}
	print(v1);
}


void main(){
	fun6();
}