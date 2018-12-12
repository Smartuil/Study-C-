#include<iostream>
using namespace std;
#include "string"
#include "vector"
#include "list"
#include "set"
#include "algorithm"
#include "functional"

//函数对象  类重载了（）

template <typename T>
class ShowElemt{
public:
	ShowElemt() {
		n = 0;
	}
	void operator()( T &t) {
		n++;
		printN();
		cout << t << endl;
	}

	void printN() {
		cout << n << endl;
	}
protected:
private:
	int n;
};

//函数模板
template <typename T>
void FuncShowElemt(T &t) {
	cout << t << endl;
}

//普通函数
void FuncShowElemt2(int &t) {
	cout << t << endl;
}


//函数对象 定义    函数对象和普通函数的区别
void fun() {
	int a = 10;
	ShowElemt<int> showelemt;
	showelemt(a);//函数对象（）的执行  很像一个函数   仿函数

	FuncShowElemt<int> (a);
	FuncShowElemt2(a);
}
//函数对象是类对象  能突破函数的概念 能保持调用的状态
//函数对象的好处
void fun2() {
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);

	//for_each(v1.begin(), v1.end(), ShowElemt<int>());//匿名仿函数   匿名函数对象
	//for_each(v1.begin(), v1.end(), FuncShowElemt2);//通过回调函数  谁使用for_each谁去填写回掉函数的入口地址

	ShowElemt<int> show;
	//函数对象做函数参数
	/*
			template<class _InIt,
			class _Fn> inline
			_Fn for_each(_InIt _First, _InIt _Last, _Fn _Func)//不是引用
		{	// perform function for each element [_First, _Last)
			_Adl_verify_range(_First, _Last);
			auto _UFirst = _Get_unwrapped(_First);
			const auto _ULast = _Get_unwrapped(_Last);
			for (; _UFirst != _ULast; ++_UFirst)
			{
				_Func(*_UFirst);
			}

			return (_Func);
		}
	*/

	show = for_each(v1.begin(), v1.end(), show);
	show.printN();
}

template <typename T>
class IsDiv{
public:
	IsDiv(const T &divisor) {
		this->divisor = divisor;
	}

	bool operator()(T &t) {
		return (t%divisor == 0);
	}
protected:
private:
	T divisor;
};

//一元谓词
void fun3() {
	vector<int> v2;
	for (int i = 1; i < 33; i++)
	{
		v2.push_back(i);
	}
	int a = 4;
	IsDiv<int> myDiv(a);

	vector<int>::iterator it;
	it = find_if(v2.begin(), v2.end(), myDiv);
	//find_if(v2.begin(), v2.end(), IsDiv<int>(4));
	if (it == v2.end()) {
		cout << "容器中没有被4整除的元素" << endl;
	}
	else
	{
		cout << "第一个被4整除的元素是" << *it << endl;
	}
}

template <typename T>
class SumAdd{
public:
	T operator()(T &t1, T &t2) {
		return t1 + t2;
	}
};

void fun4() {
	vector<int> v1, v2;
	vector<int> v3;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);
	v2.push_back(2);
	v2.push_back(4);
	v2.push_back(6);

	v3.resize(10);
	transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), SumAdd<int>());

	for (vector<int>::iterator it = v3.begin(); it != v3.end(); it++) {
		cout << *it << endl;
	}

	
}

bool myCompare(const int &a, const int &b) {
	return a < b;
}

//二元谓词
void fun5() {
	vector<int> v(10);

	for (int i = 0; i < 10; i++) {
		int tmp = rand() % 100;
		v[i] = tmp;
	}

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << endl;
	}

	for_each(v.begin(), v.end(), FuncShowElemt2);
	sort(v.begin(), v.end(), myCompare);
	cout << endl << endl;
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << endl;
	}

}

struct CompareNoCase {
	bool operator()(const string &str1, const string &str2) const {
		string str1_;
		str1_.resize(str1.size());
		transform(str1.begin(), str1.end(), str1_.begin(), tolower);

		string str2_;
		str2_.resize(str2.size());
		transform(str2.begin(), str2.end(), str2_.begin(), tolower);
		return (str1_ < str2_);
	}
};


void fun6() {
	set<string> set1;
	set1.insert("bbb");
	set1.insert("aaa");
	set1.insert("ccc");
	set<string>::iterator it = set1.find("aAa");//区分大小写
	if (it != set1.end()) {
		cout << "找到aaa" << endl;
	}
	else
	{
		cout << "没有找到aaa" << endl;
	}

	set<string, CompareNoCase> set2;
	set2.insert("bbb");
	set2.insert("aaa");
	set2.insert("ccc");

	set<string, CompareNoCase>::iterator it2 = set2.find("aAa");
	if (it2 != set2.end()) {
		cout << "找到aaa" << endl;
	}
	else
	{
		cout << "没有找到aaa" << endl;
	}
}

void main(){
	fun6();
}