#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int add(int a, int b) {//子任务的实现着
	printf("func add......\n");
	return a + b;
}

int add2(int a, int b) {
	printf("func add2......\n");
	return a + b;
}


int add3(int a, int b) {
	printf("func add3......\n");
	return a + b;
}


int add4(int a, int b) {
	printf("func add4......\n");
	return a + b;
}



typedef int(*MyTypeFuncAdd)(int a, int b);


//函数指针做函数参数
int MainOp(MyTypeFuncAdd myFuncAdd) {
	int c = myFuncAdd(5, 7);
	return c;
}

//函数指针做函数参数
int MainOp2(int (*MyPointerFuncAdd)(int a, int b)) {
	int c = MyPointerFuncAdd(5, 7);
	return c;
}

//任务的调用 和 任务的编写可以分开
void main() {
	add(1, 4);
	MyTypeFuncAdd myFuncAdd = add;
	myFuncAdd(4, 7);//间接调用

	MainOp(add);
	MainOp2(add);


	//在MainOp没有发生任何变化的情况下
	MainOp(add2);
}
