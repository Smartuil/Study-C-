#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//数组的指针：是一个指针，什么样的指针呢？指向数组的指针。int (*p)[4];

//指针的数组：是一个数组，什么样的数组呢？装着指针的数组。int *p[3];


void main1() {

	int a[10];//a代表数组首元素的地址  &a代表整个数组的地址  a+1 （4）   &a+1步长不一样（40）

	{
		//定义一个数组类型
		typedef int(myTypeArray)[10];
		myTypeArray myArray;
		myArray[0] = 10;
		printf("%d\n", myArray[0]);
	}

	{
		//定义一个指针数组类型
		typedef int(*pTypeArray)[10];//int *p;
		pTypeArray myPArray;//sizeof(int)*10
		myPArray = &a;

		//int b = 10;
		//int *p = NULL;
		//p = &b;

		(*myPArray)[0] = 20;
		printf("%d\n", a[0]);
	}

	{
		//定义一个指向数组类型的指针  数组类的指针
		int (*MtPointer)[10];//变量  告诉C编译器  给我分配内存
		MtPointer = &a;
		(*MtPointer)[0] = 40;
		printf("%d\n", a[0]);
	}

}

//函数指针
//1 如何定义一个函数类型
//2 如何定义一个函数指针类型
//3 如何定义一个函数指针  （指向一个函数的入口地址）

int add(int a, int b) {
	printf("func add......\n");
	return a + b;
}

void main() {
	add(1, 2);//直接调用    函数名就是函数的入口地址

	{
		//1 定义一个函数类型

		typedef int(MyFuncTtype)(int a, int b);
		MyFuncTtype *myPointerFunc = NULL;//定义了一个指针  指向某一种类的函数
		myPointerFunc = &add;
		myPointerFunc(3, 4);//间接调用

		myPointerFunc = add;//没有&也能编译通过   C过程  兼容历史版本的原因
	}

	{
		//2 定义一个函数指针类型
		typedef int (*MyPointerFuncTtype)(int a, int b);//int * a=NULL;
		MyPointerFuncTtype myPointerFunc;
		myPointerFunc = add;
		myPointerFunc(4, 6);
	}

	{
		//3 定义一个函数指针  （指向一个函数的入口地址）
		int(*MyPointerFunc)(int a, int b);
		MyPointerFunc = add;
		MyPointerFunc(3, 6);
	}
}