#include<iostream>
using namespace std;


class Test{
public:
	int a;
	int b;

public:
	Test(int a = 0, int b = 0) {
		this->a = a;
		this->b = b;
	}

	Test TestAdd(Test &t) {
		Test tmp(this->a + t.a, this->b + t.b);
		return tmp;
	}
	//返回一个引用相当于返回自身，返回t1这个元素，this就是t1
	Test& TestAdd2(Test &t) {
		this->a = this->a + t.a;
		this->b = this->b + t.b;
		return *this;
	}

	void print() {
		cout << a << b << endl;
	}

protected:
private:
};

//全局函数转成成员函数少了一个参数
Test TestAdd(Test &t1, Test &t2) {
	Test tmp;
	return tmp;
}
//成员函数转成全局函数多了一个参数
void print(Test *pT) {
	cout << pT->a << pT->b << endl;
}

void main1(){

	Test t1(1, 2);
	Test t2(3, 4);
	Test t3;
	t3 = TestAdd(t1, t2);//全局函数的方法
	
	//成员函数方法
	{
		Test t4 = t1.TestAdd(t2);//匿名对象直接转化成t4
		t4.print();

		Test t5;
		t5 = t1.TestAdd(t2);//匿名对象复制给t5
		t5.print();
	}
	
}

void main() {
	Test t1(1, 2);
	Test t2(3, 4);
	//t1=t2+t1;
	t1.TestAdd2(t2);
}