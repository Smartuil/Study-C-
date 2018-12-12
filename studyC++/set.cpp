#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include "set"
//1集合  元素唯一  自动排序（默认从小到大）   不能按照[]方式插入元素
//红黑树
void fun() {
	set<int> s1;
	for (int i = 0; i < 5; i++) {
		int tmp = rand();
		s1.insert(tmp);
	}
	s1.insert(100);
	s1.insert(100);
	s1.insert(100);

	for (set<int>::iterator it = s1.begin(); it != s1.end(); it++) {
		cout << *it << " ";
	}

	cout << endl;
	while (!s1.empty()) {
		set<int>::iterator it = s1.begin();
		cout << *it << " ";
		s1.erase(s1.begin());
	}
}


void fun2() {
	set<int> s1;
	set<int, less<int>> s2;
	set<int, greater<int>> s3;
	for (int i = 0; i < 5; i++) {
		int tmp = rand();
		s3.insert(tmp);
	}

	for (set<int, greater<int>>::iterator it = s3.begin(); it != s3.end(); it++) {
		cout << *it << endl;
	}
}

class Student{
public:
	Student( const char *name, int age) {
		strcpy(this->name, name);
		this->age = age;
	}

	char name[64];
	int age;
protected:
private:
};

//仿函数
struct FunStudent
{
	bool operator()(const Student &left, const Student &right) {
		if (left.age < right.age) {
			return true;
		}
		else
		{
			return false;
		}
	}
};


void fun3() {
	set<Student,FunStudent> s;
	Student s1("s1", 12);
	Student s2("s2", 22);
	Student s3("s3", 132);
	Student s4("s4", 132);//没有插入进去

	s.insert(s1);
	s.insert(s2);
	s.insert(s3);
	s.insert(s4);

	for (set<Student,FunStudent>::iterator it = s.begin(); it != s.end(); it++) {
		cout << it->age << it->name << endl;
	}
}

//如何判断insert返回值
void fun4() {
	set<Student, FunStudent> s;
	Student s1("s1", 12);
	Student s2("s2", 22);
	Student s3("s3", 132);
	Student s4("s4", 132);//没有插入进去

	pair<set<Student, FunStudent>::iterator,bool> pair1  = s.insert(s1);
	if (pair1.second == true) {
		cout << "s1成功" << endl;
	}
	else
	{
		cout << "s1失败" << endl;
	}
	s.insert(s2);
	s.insert(s3);
	pair<set<Student, FunStudent>::iterator, bool> pair2 = s.insert(s4);
	if (pair2.second == true) {
		cout << "s4成功" << endl;
	}
	else
	{
		cout << "s4失败" << endl;
	}

	for (set<Student, FunStudent>::iterator it = s.begin(); it != s.end(); it++) {
		cout << it->age << it->name << endl;
	}
}


void fun5() {
	set<int> s1;

	for (int i = 0; i < 5; i++) {
		s1.insert(i + 1);
	}

	for (set<int>::iterator it = s1.begin(); it != s1.end(); it++) {
		cout << *it << " ";
	}
	set<int>::iterator it = s1.find(5);
	cout << *it << endl;


}

void main(){
	fun4();
	
}