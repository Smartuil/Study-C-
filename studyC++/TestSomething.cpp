#include "iostream"

using namespace std;
//
//void GetMemory(char *p)
//{
//	p = (char *)malloc(100);
//}
//
//void GetMemory2(char **p)
//{
//	*p = (char *)malloc(100);
//}
//
//void Test(void)
//{
//	char *str = NULL;
//	//GetMemory(str);
//	GetMemory2(&str);
//	strcpy(str, "hello world");
//	printf(str);
//	free(str);
//}
//
//int main()
//{
//	Test();
//
//	return 0;
//}

//#include <iostream> 
//using namespace std;
//int main(void)
//{
//	const int a = 10;
//	int * p = (int *)(&a);
//	*p = 20;
//	cout << "a = " << a << ", *p = " << *p << endl;
//	return 0;
//}

//#include "iostream"
//using namespace std;
//class A
//{
//public:
//	virtual void Test()
//	{
//		printf("A test\n");
//	}
//};
//class B : public A
//{
//public:
//	void func()
//	{
//		Test();
//	}
//	virtual void Test()
//	{
//		printf("B test\n");
//	}
//};
//class C : public B
//{
//public:
//	virtual void Test()
//	{
//		printf("C test\n");
//	}
//};
void main()
{
//	C c;
//	((B *)(&c))->func();
//	((B)c).func();
//
	int a[5] = { 0 };
	cout << a << endl;
	cout << &a[0] << endl;
	cout << &a << endl;

	cout << a + 1 << endl;
	cout << &a[0] + 1 << endl;
	cout << &a + 1 << endl;
//
//
//	char a[5] = { 'a','b','c','d' };
//	char(*p1)[5] = &a;
//	char(*p2)[5] = (char(*)[5])a;
//
//	printf("a=%d\n", a);
//	printf("a=%c\n", a[0]);
//	printf("p1=%c\n", **p1);
//	printf("p2=%c\n", **p2);
//	printf("p1+1=%c\n", **(p1 + 1));
//	printf("p2+1=%c\n", **(p2 + 1));
}

//#include<iostream>
//using namespace std;//c++的命名空间
//class circle
//{
//public:
//
//	double r;
//
//	double pi = 3.1415926;
//	double area = pi * r*r;
//
//};

//int main()
//{
//	circle pi;
//	cout << "请输入area" << endl;
//	cin >> pi.r;
//
//	cout << pi.area << endl;	//乱码
//
//	system("pause");
//	return 0;
//}

//void main()
//{
//	int a = 10; //c编译器分配4个字节内存。。。a内存空间的别名
//	int &b = a;  //b就是a的别名。。。
//	a = 11; //直接赋值
//	{
//		int *p = &a;
//		*p = 12;
//		printf("a %d \n", a);
//	}
//	b = 14;
//	printf("a:%d b:%d", a, b);
//	system("pause");
//}

