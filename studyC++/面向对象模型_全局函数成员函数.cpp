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
	//����һ�������൱�ڷ�����������t1���Ԫ�أ�this����t1
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

//ȫ�ֺ���ת�ɳ�Ա��������һ������
Test TestAdd(Test &t1, Test &t2) {
	Test tmp;
	return tmp;
}
//��Ա����ת��ȫ�ֺ�������һ������
void print(Test *pT) {
	cout << pT->a << pT->b << endl;
}

void main1(){

	Test t1(1, 2);
	Test t2(3, 4);
	Test t3;
	t3 = TestAdd(t1, t2);//ȫ�ֺ����ķ���
	
	//��Ա��������
	{
		Test t4 = t1.TestAdd(t2);//��������ֱ��ת����t4
		t4.print();

		Test t5;
		t5 = t1.TestAdd(t2);//���������Ƹ�t5
		t5.print();
	}
	
}

void main() {
	Test t1(1, 2);
	Test t2(3, 4);
	//t1=t2+t1;
	t1.TestAdd2(t2);
}