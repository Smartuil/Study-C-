#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include "MyVector.cpp"


using namespace std;

void main1(){
	MyVector<int> m1(10);
	for (int i = 0; i < m1.getLen(); i++) {
		m1[i] = i + 1;
		cout << m1[i] << " ";
	}
	cout << endl;

	MyVector<int> m2 = m1;
	for (int i = 0; i < m2.getLen(); i++) {
		cout << m1[i] << " ";
	}
	cout << endl;

	cout << m2 << endl;
}

void main2() {
	MyVector<char> m1(10);
	m1[0] = 'a';
	m1[1] = 'b';
	m1[2] = 'c';
	m1[3] = 'd';
	cout << m1 << endl;
}


class Teacher{
public:
	Teacher() {
		age = 33;
		name = new char[1];
		strcpy(name, "");
	}

	Teacher(const Teacher &t) {
		name = new char[strlen(t.name) + 1];
		strcpy(name, t.name);
		age = t.age;
	}


	~Teacher()
	{
		if (name != NULL) {
			delete[] name;
			name = NULL;
		}
	}

	Teacher(const char *myname, int myage) {
		this->age = myage;
		name = new char[strlen(myname) + 1];
		strcpy(name, myname);
	}


	void print() {
		cout << name << age << endl;
	}
	friend ostream& operator<<(ostream &o, Teacher &t);

	Teacher& operator=(const Teacher &t) {
		if (name != NULL) {
			delete[] name;
			name = NULL;
			age = 23;
		}
		name = new char[strlen(t.name) + 1];
		strcpy(name, t.name);
		age = t.age;

		return *this;
	}

protected:
private:
	int age;
	//char name[32];
	char *name;/////////报错
};

ostream & operator<<(ostream &o, Teacher &t) {
	o << t.name << t.age << endl;
	return o;
}


void main() {
	Teacher t1("t1", 23), t2("t2", 24), t3("t3", 25), t4("t4", 26);
	MyVector<Teacher *> tArray(4);
	tArray[0] = &t1;
	tArray[1] = &t2;
	tArray[2] = &t3;//浅拷贝
	tArray[3] = &t4;

	//for (int i = 0; i < 4; i++) {  
	//	tArray[i]->print();
	//}

	//cout << tArray;

}


void main3() {
	Teacher t1("t1", 23), t2("t2", 24), t3("t3", 25), t4("t4", 26);
	MyVector<Teacher> tArray(4);
	tArray[0] = t1;
	tArray[1] = t2;
	tArray[2] = t3;//浅拷贝
	tArray[3] = t4;

	//for (int i = 0; i < 4; i++) {
	//	tArray[i].print();
	//}

	cout << tArray;

}