#include<iostream>
using namespace std;



void main111() {

	//普通引用

	int a = 10;
	int &b = a;

	//常量引用

	int x = 10;
	const int &y = x;//让变量 引用只读属性，不能通过y修改x
	//y = 21;


	//初始化
	//1 用变量初始化常引用
	{
		int x1 = 10;
		const int &y1 = x1;
	}
	//2 用字面量去初始化常量引用
	{
		const int a = 10;//C++编译器把a放在符号表中
		//int &m = 40;//普通引用  引用一个字面量  没有内存地址
		//引用就是给内存取多个别名
		const int &m = 42;//C++编译器给m分配内存空间
	}
	system("pause");
}

struct Teacher {
	char name[64];
	int age;
};

//const int&  相当于 const int * const e
void getTeacher(const Teacher &p) {
	//常量引用让实参  拥有只读属性
	cout << p.age << endl;
}

void main() {
	Teacher t1;
	t1.age = 111;
	getTeacher(t1);
	system("pause");
}
