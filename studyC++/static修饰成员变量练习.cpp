//#define  _CRT_SECURE_NO_WARNINGS 
//#include <iostream>
//
//using namespace std;
//
//class Box
//{
//public:
//	Box(int l, int w) :length(l), width(w) {}
//
//	int volumu()
//	{
//		return length * width *height;
//	}
//
//	int length;//4
//	int width;//4
//	static int height; //����һ����̬�ĳ�Ա���� //4
//	//static const int a = 10;
//};
//
////���ⲿ��ʼ��
//int  Box::height = 100;
//
//int main(void)
//{
//	Box b1(10, 20);
//	Box b2(30, 40);
//
//	cout << "b1: " << b1.volumu() << ", " << b1.height << endl;
//	cout << "b2: " << b2.volumu() << "," << b2.height << endl;
//	Box::height;
//
//	cout << "sizeof(b1) :" << sizeof(b1) << endl; //8
//	cout << "sizeof(b2) :" << sizeof(b2) << endl; //8  ˵��static���εĳ�Ա�����������ڶ����У� ������ȫ�������ٵġ�
//
//
//	return 0;
//}

#define  _CRT_SECURE_NO_WARNINGS 
#include <iostream>

using namespace std;

class AA
{
public:
	AA(int a, int b)
	{
		m_a = a;
		m_b = b;
	}

	int getC()
	{
		cout << "c = " << m_c << endl;
		m_c++;
		return m_c;
	}

	static int m_c;//��̬�ĳ�Ա����  //1 ������ڲ������������ ��static
						//��̬�ĳ�Ա�����ǶԱ����������б����еĶ��� ���ǹ���һ���ڴ�����
private:
	int m_a;
	int m_b;
};


//2 ��̬��Ա�����ĳ�ʼ���� ������ⲿȥд
int AA::m_c = 0;

int main(void)
{
	AA aa1(10, 20), aa2(100, 200), aa3(1000, 2000);

	aa1.getC();
	aa2.getC();
	aa3.getC();

	//��ôȥ�޸�һ����̬�ĳ�Ա����
	AA::m_c = 200;

	aa1.getC();
	aa2.getC();
	aa3.getC();




	return 0;
}