#include<iostream>
#include "linklist_cpp.cpp"
using namespace std;



struct Teacher {
	char name[64];
	int age;
};

void main_linklist_play() {
	Teacher t1, t2, t3, tmp;
	t1.age = 21, t2.age = 22, t3.age = 23;
	linklist_cpp<Teacher> list;
	list.insert(t1, 0);
	list.insert(t2, 0);
	list.insert(t3, 0);

	for (int i = 0; i < list.length(); i++) {
		list.get(i, tmp);
		cout << tmp.age << " ";
	}

	list.clear();

	list.insert(t1, 0);
	list.insert(t2, 0);
	list.insert(t3, 0);
	for (int i = 0; i < list.length(); i++) {
		list.get(i, tmp);
		cout << tmp.age << " ";
	}

	while (list.length() > 0) {
		list.del(0, tmp);
		cout << tmp.age << " ";
	}
}

void main() {
	main_linklist_play();
}