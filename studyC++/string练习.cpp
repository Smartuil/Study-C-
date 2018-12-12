#include<iostream>
using namespace std;
#include "string"
#include "algorithm"

void fun() {
	string s1 = "aaa";
	string s2("bbb");
	string s3 = s2;
	string s4(10, 'a');
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;

}
void fun2() {
	string s1 = "abcdefg";

	for (int i = 0; i < s1.length(); i++) {
		cout << s1[i] << endl;
	}

	for (string::iterator it = s1.begin(); it != s1.end(); it++) {
		cout << *it << endl;
	}

	for (int i = 0; i < s1.length(); i++) {
		cout << s1.at(i) << endl;//at抛出异常
	}

}

void fun3() {
	string s1 = "aaabbb";
	//s1====>char *
	cout << s1.c_str() << endl;

	//char *====>string
	string s2 = "aaabbb";
	//s1  copy到buf中
	char buf1[128] = {0};
	s1.copy(buf1, 3);
	cout << buf1 << endl;
}

void fun4() {
	string s1 = "aaa";
	string s2 = "bbbbbb";
	s1 = s1 + s2;
	cout << s1 << endl;

	string s3 = "dddd";
	string s4 = "sasas";
	s3.append(s4);
	cout << s3 << endl;
}

void fun5() {
	string s1 = "dqadasdas hello world hello";
	int index = s1.find("hello", 0);
	cout << index << endl;

	int offindex = s1.find("hello", 0);
	while (offindex != string::npos) {
		cout << offindex << endl;
		offindex = offindex + 1;
		offindex = s1.find("hello", offindex);
	}



	offindex = s1.find("hello", 0);
	while (offindex != string::npos) {
		cout << offindex << endl;
		s1.replace(offindex, 5, "HEOOLO");
		offindex = offindex + 1;
		offindex = s1.find("hello", offindex);
	}
	cout << s1 << endl;
}

void fun6() {
	string s1 = "hello hello2 hello3";
	string::iterator it = find(s1.begin(), s1.end(), 'l');
	if (it != s1.end()) {
		s1.erase(it);
	}
	cout << s1 << endl;

	s1.erase(s1.begin(), s1.end());
	cout << s1 << endl;

	string s2 = "dasda";
	s2.insert(0, "AAAAA");
	s2.insert(s2.length(), "ccccccccccccccc");
	cout << s2 << endl;

}



void fun7() {
	string s1 = "AAAbbb";
	transform(s1.begin(), s1.end(), s1.begin(), toupper);
	cout << s1 << endl;

	string s2 = "AAAbbb";
	transform(s2.begin(), s2.end(), s2.begin(), tolower);
	cout << s2 << endl;
}

void main(){
	fun7();
}