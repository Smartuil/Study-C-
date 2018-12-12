#include<iostream>
using namespace std;


struct Teacher {
	char name[64];
	int age;
};

int getTeacher(Teacher **p) {
	Teacher *tmp = NULL;
	
	if (p == NULL) {
		return -1;
	}
	tmp = (Teacher *)malloc(sizeof(Teacher));
	if (tmp == NULL) {
		return -2;
	}
	tmp->age = 111;
	*p = tmp;
}

int getTeacher1111(Teacher * &myp) {
	
	return 0;
}

int getTeacher2(Teacher *&myp) {
	myp = (Teacher*)malloc(sizeof(Teacher));
	if (myp == NULL) {
		return -1;
	}
	myp->age = 111;
	return 0;
}

void main() {

	Teacher *pt1;
	getTeacher2(pt1);
	cout << pt1->age << endl;
	system("pause");
}
