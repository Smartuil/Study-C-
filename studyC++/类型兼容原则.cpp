#include<iostream>
using namespace std;

class Parent{
public:
	void printP() {
		cout << "dad" << endl;
	}

	Parent() {
		cout << "Parent���캯��" << endl;
	}

	Parent(const Parent &obj) {
		cout << "Parent  copy���캯��" << endl;
	}
protected:
private:
	int a;
};

class Child : public Parent {
public:
	void printC() {
		cout << "son" << endl;
	}
protected:
private:
	int c;
};

void howToPrint(Parent *base) {
	base->printP();
}

void howToPrint2(Parent &base) {
	base.printP();
}

void main(){
	Parent p1;
	p1.printP();

	Child c1;
	c1.printP();
	c1.printC();
	//��ֵ����ԭ��
	//1-1 ����ָ�루���ã�ָ���������
	Parent *p = NULL;
	p = &c1;
	p->printP();

	//1-2 ָ������������

	howToPrint(&p1);
	howToPrint(&c1);
	//1-3��������������

	howToPrint2(p1);
	howToPrint2(c1);

	//�ڶ��㺬��
	//��������ʼ���������      �������һ������ĸ���
	Parent p3 = c1;
}