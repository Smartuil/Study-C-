#include<iostream>
using namespace std;


class Tree{
public:
protected:
private:
};


class Animal{
public:
	virtual void cry() = 0;
protected:
private:
};


class Dog : public Animal{
public:
	virtual void cry() {
		cout << "wangwang" << endl;
	}

	void doHome() {
		cout << "watching" << endl;
	}
protected:
private:
};


class Cat : public Animal{
public:
	virtual void cry() {
		cout << "miaomiao" << endl;
	}

	void doThing() {
		cout << "抓老鼠" << endl;
	}
protected:
private:
};

void play(Animal *a) {
	a->cry();

	//dynamic_cast 运行时类型识别
	Dog *d = dynamic_cast<Dog *>(a);
	if (d != NULL) {
		d->doHome();
	}

	Cat *c = dynamic_cast<Cat *>(a);
	if (c != NULL) {
		c->doThing();
	}
}

void printBuf(const char *p) {//要确保p指向的内存空间能够修改
	//p[0] = 'A';

	char *p1;

	//const char *=====>char *
	p1 = const_cast<char *>(p);
	p1[0] = 'A';
	cout << p << endl;
}


void main() {
	char buf[] = "dasdasdas";//分配了
	//char *buf = "dasdasdas";//指向的是常量  没有分配没存
	printBuf(buf);
}

void main2() {
	Dog d;
	Cat c;

	Animal *base = NULL;
	base = &d;
	base = static_cast<Animal *>(&d);
	base = reinterpret_cast<Animal *>(&c);

	{
		Tree *t = NULL;
		t = reinterpret_cast<Tree *>(&d);
		base = reinterpret_cast<Animal *>(&t);
		//base = static_cast<Animal *>(&t);
		
	}


	play(&d);
	play(&c);
}



void main1(){
	double dPi = 3.1415926;
	int num1 = (int)dPi;//C类型转换
	int num2 = static_cast<int>(dPi);//静态类型转换   编译时C++编译器会做类型检查
	int num3 = dPi;//C语言中隐式类型转换的地方均可以使用static_cast<>()进行类型转换

	//char * ====>int *
	char text[] = "hello";
	char *p1 = text;
	int *p2 = NULL;
	//p2 = static_cast<int*>(p1);//编译时C++编译器会做类型检查
	p2 = reinterpret_cast<int *>(p1);
	cout << p1 << endl;
	cout << p2 << endl;
}