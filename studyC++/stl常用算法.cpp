#include<iostream>
using namespace std;
#include "string"
#include "vector"
#include "list"
#include "set"
#include "algorithm"
#include "functional"
#include "iterator"


void print(vector<int> &v) {
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << endl;
	}
}

void print2(list<int> &l) {
	for (list<int>::iterator it = l.begin(); it != l.end(); it++) {
		cout << *it << endl;
	}
}

void showvector(int &n) {
	cout << n << endl;
}

class Show{
public:
	Show() {
		m_num = 0;
	}
	void operator()(int &n) {
		m_num++;
		cout << n << endl;
	}

	void print() {
		cout << m_num << endl;
	}
protected:
private:
	int m_num;
};

void fun() {
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);

	//print(v1);
	//cout << "------------" << endl;
	//函数对象 回到函数入口地址
	//for_each(v1.begin(), v1.end(), showvector);

	//for_each(v1.begin(), v1.end(), Show());

	Show my1 = for_each(v1.begin(), v1.end(), Show());
	my1.print();
}

int increase(int i) {
	return i + 100;
}

void fun2() {
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);

	print(v1);
	cout << "------------" << endl;

	transform(v1.begin(), v1.end(), v1.begin(), increase);//使用了回调函数
	print(v1);
	cout << "------------" << endl;

	transform(v1.begin(), v1.end(), v1.begin(), negate<int>());//预定义的函数对象
	print(v1);
	cout << "------------" << endl;


	list<int> mylist;
	mylist.resize(v1.size());
	transform(v1.begin(), v1.end(), mylist.begin(), bind2nd(multiplies<int>(), 10));//函数适配器
	print2(mylist);
	cout << "------------" << endl;

	transform(v1.begin(), v1.end(), ostream_iterator<int>(cout, " "), negate<int>());
}

int showvector2(int n) {
	cout << n << endl;
	return 0;
}


void fun3() {
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);

	vector<int> v2 = v1;

	for_each(v1.begin(), v1.end(), showvector);
	transform(v2.begin(), v2.end(), v2.begin(), showvector2);
}

void fun4() {
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(3);
	v1.push_back(5);
	v1.push_back(5);

	vector<int>::iterator it = adjacent_find(v1.begin(), v1.end());
	if (it == v1.end()) {
		cout << "没有找到重复的元素" << endl;
	}
	else
	{
		cout << *it << endl;
	}
	int index = distance(v1.begin(), it);
	cout << index << endl;
}

void fun5() {
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);
	v1.push_back(7);
	v1.push_back(9);

	bool b = binary_search(v1.begin(), v1.end(), 7);
	if (b) {
		cout << "找到" << endl;
	}
	else
	{
		cout << "没找到" << endl;
	}
}

void fun6() {
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);
	v1.push_back(7);
	v1.push_back(9);
	v1.push_back(7);
	v1.push_back(9);

	int num = count(v1.begin(), v1.end(), 7);
		cout << num << endl;

}


bool GreatThree(int num) {
	if (num > 3) {
		return true;
	}
	else
	{
		return false;
	}
}

void fun7() {
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);
	v1.push_back(7);
	v1.push_back(9);
	v1.push_back(7);
	v1.push_back(9);

	int num = count_if(v1.begin(), v1.end(), GreatThree);
	cout << num << endl;

}

void fun8() {
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);
	v1.push_back(7);
	v1.push_back(9);
	v1.push_back(7);
	v1.push_back(9);

	vector<int>:: iterator it = find(v1.begin(), v1.end(), 5);
	cout << *it << endl;

	vector<int>::iterator it1 = find_if(v1.begin(), v1.end(), GreatThree);
	cout << *it1 << endl;
}
void main(){
	fun8();
}