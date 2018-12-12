#include<iostream>
using namespace std;
#include "map"
#include "string"

class Person {
public:
	string name;
	int age;
	string tel;
	double sal;
protected:
private:
};

void fun() {
	Person p1, p2, p3, p4, p5;
	p1.name = "wang1";
	p1.age = 21;
	p2.name = "wang2";
	p2.age = 22;
	p3.name = "zhang3";
	p3.age = 23;
	p4.name = "zhang4";
	p4.age = 24;
	p5.name = "zhao5";
	p5.age = 25;
	multimap<string, Person> map;
	map.insert(make_pair("sale", p1));
	map.insert(make_pair("sale", p2));

	map.insert(make_pair("dev", p3));
	map.insert(make_pair("dev", p4));

	map.insert(make_pair("finacial", p5));

	for (multimap<string, Person>::iterator it = map.begin(); it != map.end(); it++) {
		cout << it->first << "\t" << it->second.name << endl;
	}

	cout << "遍历结束" << endl;

	cout<<map.count("dev") << endl;
	multimap<string, Person>::iterator it = map.find("dev");
	int tag = 0;
	while (it != map.end() && tag<map.count("dev")) {
		cout << it->first << "\t" << it->second.name << endl;
		it++;
		tag++;
	}
}


void fun2() {
	Person p1, p2, p3, p4, p5;
	p1.name = "wang1";
	p1.age = 21;
	p2.name = "wang2";
	p2.age = 22;
	p3.name = "zhang3";
	p3.age = 23;
	p4.name = "zhang4";
	p4.age = 24;
	p5.name = "zhao5";
	p5.age = 25;
	multimap<string, Person> map;
	map.insert(make_pair("sale", p1));
	map.insert(make_pair("sale", p2));

	map.insert(make_pair("dev", p3));
	map.insert(make_pair("dev", p4));

	map.insert(make_pair("finacial", p5));

	for (multimap<string, Person>::iterator it = map.begin(); it != map.end(); it++) {
		//cout << it->first << "\t" << it->second.name << endl;
		if (it->second.age == 24) {
			it->second.name = "liubonan";
		}
	}

	for (multimap<string, Person>::iterator it = map.begin(); it != map.end(); it++) {
		cout << it->first << "\t" << it->second.name << endl;
	}


	cout << "遍历结束" << endl;
}

void main(){
	fun2();
}