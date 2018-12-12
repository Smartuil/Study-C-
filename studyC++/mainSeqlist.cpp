#include<iostream>
#include "seqlist_cpp.cpp"

using namespace std;

struct Teacher {
	char name[64];
	int age;
};

void main_seqlist_play(){
	Teacher t1, t2, t3 ,tmp;
	t1.age = 21, t2.age = 22, t3.age = 23;
	seqlist_cpp<Teacher> list(10);
	list.insert(t1, 0);
	list.insert(t2, 0);
	list.insert(t3, 0);

	for (int i = 0; i < list.getLength(); i++) {
		list.get(i, tmp);
		cout << tmp.age << " ";
	}

	list.clear();

	list.insert(t1, 0);
	list.insert(t2, 0);
	list.insert(t3, 0);
	for (int i = 0; i < list.getLength(); i++) {
		list.get(i, tmp);
		cout << tmp.age << " ";
	}

	while (list.getLength() > 0) {
		list.del(0, tmp);
		cout << tmp.age << " ";
	}
}


void main_seqlist_play_p() {
	Teacher t1, t2, t3;
	Teacher *p1, *p2, *p3;
	p1 = &t1;
	p2 = &t2;
	p3 = &t3;
	Teacher *tmp = NULL;
	t1.age = 21, t2.age = 22, t3.age = 23;
	seqlist_cpp<Teacher *> list(10);
	list.insert(p1, 0);
	list.insert(p2, 0);
	list.insert(p3, 0);

	for (int i = 0; i < list.getLength(); i++) {
		list.get(i, tmp);
		cout << tmp->age << " ";
	}
	while (list.getLength() > 0) {
		list.del(0, tmp);
		cout << tmp->age << " ";
	}
}

void main() {
	main_seqlist_play();
}