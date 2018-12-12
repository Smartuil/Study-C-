#include<iostream>
using namespace std;
#include "stack"

void fun() {
	stack<int> s;
	for (int i = 0; i < 10; i++) {
		s.push(i + 1);
	}

	while (!s.empty()) {
		int tmp = s.top();
		cout << tmp << endl;
		s.pop();
	}
}

class Teacher{
public:
	int age;
	char name[32];

	void print() {
		cout << age << endl;
	}
protected:
private:
};

void fun2() {
	Teacher t1, t2, t3;
	t1.age = 22;
	t2.age = 32;
	t3.age = 332;
	stack<Teacher> s;
	s.push(t1);
	s.push(t2);
	s.push(t3);

	while (!s.empty()) {
		Teacher tmp = s.top();
		tmp.print();
		s.pop();
	}
}


void fun3() {
	Teacher t1, t2, t3;
	t1.age = 22;
	t2.age = 32;
	t3.age = 332;
	stack<Teacher *> s;
	s.push(&t1);
	s.push(&t2);
	s.push(&t3);

	while (!s.empty()) {
		Teacher *tmp = s.top();
		tmp->print();
		s.pop();
	}
}

void main(){
	fun3();
}