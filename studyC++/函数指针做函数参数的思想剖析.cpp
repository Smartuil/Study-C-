#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int add(int a, int b) {//�������ʵ����
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


//����ָ������������
int MainOp(MyTypeFuncAdd myFuncAdd) {
	int c = myFuncAdd(5, 7);
	return c;
}

//����ָ������������
int MainOp2(int (*MyPointerFuncAdd)(int a, int b)) {
	int c = MyPointerFuncAdd(5, 7);
	return c;
}

//����ĵ��� �� ����ı�д���Էֿ�
void main() {
	add(1, 4);
	MyTypeFuncAdd myFuncAdd = add;
	myFuncAdd(4, 7);//��ӵ���

	MainOp(add);
	MainOp2(add);


	//��MainOpû�з����κα仯�������
	MainOp(add2);
}
