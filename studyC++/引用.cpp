#include<iostream>
using namespace std;//c++�������ռ�

struct Teacer {
	int &a;
	double &b;
};

int main()
{
	int a = 10;
	int &b = a;
	//b��a�ı���������c++��������������ʲô������
	b = 11;
	cout << "b--->" << a << endl;
	printf("a:%d\n", a);
	printf("b:%d\n", b);
	printf("&a:%d\n", &a);
	printf("&b:%d\n", &b);  //��˼������ͬһ�ڴ�ռ����ȡ�ü���������
	printf("sizeof(Teacher) %d\n", sizeof(Teacer));
	return 0;
}
