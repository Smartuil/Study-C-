#include<iostream>
using namespace std;
#include "string"
#include "vector"
#include "list"
#include "set"
#include "algorithm"
#include "functional"


void fun() {
	plus<int> intAdd;
	int x = 10;
	int y = 20;
	int z = intAdd(x, y);
	cout << z << endl;

	plus<string> stringAdd;
	string s1 = "aaa";
	string s2 = "bbb";
	string s3 = stringAdd(s1, s2);
	cout << s3;

	vector<string> v1;
	v1.push_back("bbb");
	v1.push_back("ccc");
	v1.push_back("sss");
	v1.push_back("zzz");
	v1.push_back("zzz");
	v1.push_back("zzz");

	sort(v1.begin(), v1.end(), greater<string>());

	for (vector<string>::iterator it = v1.begin(); it != v1.end(); it++) {
		cout << *it << endl;
	}
	string s = "zzz";
	int num = count_if(v1.begin(), v1.end(), bind2nd(equal_to<string>(), s));
	cout << num << endl;
}

class IsGreat
{
public:
	IsGreat(int i) {
		m_num = i;
	}
	bool operator()(int &num) {
		return (num > m_num);
	}
private:
	int m_num;
};

void fun2() {
	vector<int> v1;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i + 1);
	}

	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++) {
		cout << *it << endl;
	}
	int num = count(v1.begin(), v1.end(), 3);
	cout << num << endl;
	//通过谓词求大于2的个数
	int num2 = count_if(v1.begin(), v1.end(), IsGreat(2));
	cout << num2 << endl;

	//通过预定义的函数对象求大于2的个数
	int num3 = count_if(v1.begin(), v1.end(), bind2nd(greater<int>(), 2));
	cout << num3 << endl;

	//求奇数
	int num4 = count_if(v1.begin(), v1.end(), bind2nd(modulus<int>(), 2));
	cout << num4 << endl;

	//求偶数
	int num5 = count_if(v1.begin(), v1.end(), not1(bind2nd(modulus<int>(), 2)));
	cout << num5 << endl;

}


void main(){
	fun2();
}