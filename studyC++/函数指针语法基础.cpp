#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//�����ָ�룺��һ��ָ�룬ʲô����ָ���أ�ָ�������ָ�롣int (*p)[4];

//ָ������飺��һ�����飬ʲô���������أ�װ��ָ������顣int *p[3];


void main1() {

	int a[10];//a����������Ԫ�صĵ�ַ  &a������������ĵ�ַ  a+1 ��4��   &a+1������һ����40��

	{
		//����һ����������
		typedef int(myTypeArray)[10];
		myTypeArray myArray;
		myArray[0] = 10;
		printf("%d\n", myArray[0]);
	}

	{
		//����һ��ָ����������
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
		//����һ��ָ���������͵�ָ��  �������ָ��
		int (*MtPointer)[10];//����  ����C������  ���ҷ����ڴ�
		MtPointer = &a;
		(*MtPointer)[0] = 40;
		printf("%d\n", a[0]);
	}

}

//����ָ��
//1 ��ζ���һ����������
//2 ��ζ���һ������ָ������
//3 ��ζ���һ������ָ��  ��ָ��һ����������ڵ�ַ��

int add(int a, int b) {
	printf("func add......\n");
	return a + b;
}

void main() {
	add(1, 2);//ֱ�ӵ���    ���������Ǻ�������ڵ�ַ

	{
		//1 ����һ����������

		typedef int(MyFuncTtype)(int a, int b);
		MyFuncTtype *myPointerFunc = NULL;//������һ��ָ��  ָ��ĳһ����ĺ���
		myPointerFunc = &add;
		myPointerFunc(3, 4);//��ӵ���

		myPointerFunc = add;//û��&Ҳ�ܱ���ͨ��   C����  ������ʷ�汾��ԭ��
	}

	{
		//2 ����һ������ָ������
		typedef int (*MyPointerFuncTtype)(int a, int b);//int * a=NULL;
		MyPointerFuncTtype myPointerFunc;
		myPointerFunc = add;
		myPointerFunc(4, 6);
	}

	{
		//3 ����һ������ָ��  ��ָ��һ����������ڵ�ַ��
		int(*MyPointerFunc)(int a, int b);
		MyPointerFunc = add;
		MyPointerFunc(3, 6);
	}
}