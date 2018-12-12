#include<iostream>
using namespace std;
#include "vector"
#include "algorithm"


void func1() {
	vector<int> v1;
	v1.push_back(-1);
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);

	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++) {
		cout << *it << endl;
	}

	int num1 = count(v1.begin(), v1.end(), 3);
	cout << num1 << endl;

}

	class Teacher{
	public:
		int age;
		char name[64];


		void print() {
			cout << age << name << endl;
		}
	protected:
	private:
	};


	void func2() {
		Teacher t1, t2, t3;
		t1.age = 23;
		t2.age = 24;
		t3.age = 35;
		vector<Teacher> v1;
		v1.push_back(t1);
		v1.push_back(t2);
		v1.push_back(t3);


		for (vector<Teacher>::iterator it = v1.begin(); it != v1.end(); it++) {
			cout << it->age << endl;
		}
	}


	void func3() {
		Teacher t1, t2, t3;
		t1.age = 23;
		t2.age = 24;
		t3.age = 35;

		Teacher *p1, *p2, *p3;
		p1 = &t1;
		p2 = &t2;
		p3 = &t3;

		vector<Teacher *> v1;
		v1.push_back(p1);
		v1.push_back(p2);
		v1.push_back(p3);


		for (vector<Teacher *>::iterator it = v1.begin(); it != v1.end(); it++) {
			cout << (*it)->age << endl;
		}
	}

void main(){
	func2();
}