#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;

class A{
public:
	A() {
		p = new char[20];
		strcpy(p, "aaa");
		cout << "A" << endl;
	}

	 virtual ~A()//�������������Ҳ��ִ��
	{
		delete[] p;
		cout << "~A" << endl;
	}
protected:
private:
	char *p;
};

class B : public A {
public:
	B() {
		p = new char[20];
		strcpy(p, "bbb");
		cout << "B" << endl;
	}

	~B()
	{
		delete[] p;
		cout << "~B" << endl;
	}
protected:
private:
	char *p;
};

class C : public B {
public:
	C() {
		p = new char[20];
		strcpy(p, "ccc");
		cout << "C" << endl;
	}

	~C()
	{
		delete[] p;
		cout << "~C" << endl;
	}
protected:
private:
	char *p;
};

//��ͨ������ָ��  �����е�������������������ִ��һ��
//��ͨ������ָ�� �ͷ����е�������Դ
void howToDelete(A *base) {
	delete base;
}

void main(){
	C *myc = new C;
	//howToDelete(myc);
	 
	delete myc;//û��virtual   ����Ҳ����ȫ������

}