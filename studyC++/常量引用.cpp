#include<iostream>
using namespace std;



void main111() {

	//��ͨ����

	int a = 10;
	int &b = a;

	//��������

	int x = 10;
	const int &y = x;//�ñ��� ����ֻ�����ԣ�����ͨ��y�޸�x
	//y = 21;


	//��ʼ��
	//1 �ñ�����ʼ��������
	{
		int x1 = 10;
		const int &y1 = x1;
	}
	//2 ��������ȥ��ʼ����������
	{
		const int a = 10;//C++��������a���ڷ��ű���
		//int &m = 40;//��ͨ����  ����һ��������  û���ڴ��ַ
		//���þ��Ǹ��ڴ�ȡ�������
		const int &m = 42;//C++��������m�����ڴ�ռ�
	}
	system("pause");
}

struct Teacher {
	char name[64];
	int age;
};

//const int&  �൱�� const int * const e
void getTeacher(const Teacher &p) {
	//����������ʵ��  ӵ��ֻ������
	cout << p.age << endl;
}

void main() {
	Teacher t1;
	t1.age = 111;
	getTeacher(t1);
	system("pause");
}
