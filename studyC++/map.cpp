#include<iostream>
using namespace std;
#include "map"
#include "string"

void fun() {
	map<int, string> map1;

	map1.insert(pair<int, string>(1, "teacher1"));
	map1.insert(pair<int, string>(2, "teacher2"));

	map1.insert(make_pair(3, "teacher3"));
	map1.insert(make_pair(4, "teacher4"));

	map1.insert(map<int, string>::value_type(5, "teacher5"));
	map1.insert(map<int, string>::value_type(6, "teacher6"));

	map1[7] = "teacher7";
	map1[8] = "teacher8";

	for (map<int, string>::iterator it = map1.begin(); it != map1.end(); it++) {
		cout << it->first << it->second << endl;
	}

	while (!map1.empty()) {
		map<int, string>::iterator it = map1.begin();
		cout << it->first << it->second << endl;
		map1.erase(it);
	}


}

void fun2() {
	map<int, string> map1;

	pair<map<int, string>::iterator,bool> mypair1 = map1.insert(pair<int, string>(1, "teacher1"));
	map1.insert(pair<int, string>(2, "teacher2"));

	pair<map<int, string>::iterator, bool> mypair3 = map1.insert(make_pair(3, "teacher3"));
	map1.insert(make_pair(4, "teacher4"));

	pair<map<int, string>::iterator, bool> mypair5 = map1.insert(map<int, string>::value_type(5, "teacher5"));
	pair<map<int, string>::iterator, bool> mypair6 = map1.insert(map<int, string>::value_type(5, "teacher5"));

	if (mypair5.second == true) {
		cout << "5成功" << endl;
	}
	else
	{
		cout << mypair5.first->first << mypair5.first->second << "失败" << endl;
	}

	if (mypair6.second == true) {
		cout << "6成功" << endl;
	}
	else
	{
		cout << mypair6.first->first << mypair6.first->second << "失败" << endl;
	}

	map1[7] = "teacher7";
	map1[7] = "teacher78";//覆盖！！！

	for (map<int, string>::iterator it = map1.begin(); it != map1.end(); it++) {
		cout << it->first << it->second << endl;
	}

	while (!map1.empty()) {
		map<int, string>::iterator it = map1.begin();
		cout << it->first << it->second << endl;
		map1.erase(it);
	}
}

void fun3() {
	map<int, string> map1;

	map1.insert(pair<int, string>(1, "teacher1"));
	map1.insert(pair<int, string>(2, "teacher2"));

	map1.insert(make_pair(3, "teacher3"));
	map1.insert(make_pair(4, "teacher4"));

	map1.insert(map<int, string>::value_type(5, "teacher5"));
	map1.insert(map<int, string>::value_type(6, "teacher6"));

	map1[7] = "teacher7";
	map1[8] = "teacher8";

	for (map<int, string>::iterator it = map1.begin(); it != map1.end(); it++) {
		cout << it->first << it->second << endl;
	}

	//while (!map1.empty()) {
	//	map<int, string>::iterator it = map1.begin();
	//	cout << it->first << it->second << endl;
	//	map1.erase(it);
	//}

	map<int, string>::iterator it =  map1.find(100);
	if (it == map1.end()) {
		cout << "不存在" << endl;
	}
	else
	{
		cout << it->first << it->second << endl;
	}

	pair<map<int, string>::iterator, map<int, string>::iterator> mypair = map1.equal_range(5);
	//第一个>=5   第二个>5 
	if (mypair.first == map1.end()) {
		cout << "第一个迭代器>=5位置不存在" << endl;
	}
	else
	{
		cout << mypair.first->first << mypair.first->second << endl;
	}

	if (mypair.second == map1.end()) {
		cout << "第二个迭代器>5位置不存在" << endl;
	}
	else
	{
		cout << mypair.second->first << mypair.second->second << endl;
	}
}
void main(){
	fun3();
}