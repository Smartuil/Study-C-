//#include<iostream>
//#include <windows.h>
//using namespace std;
//
//
//class singelton {
//private:
//	singelton() {
//		cout << "���캯��begin" << endl;
//		//Sleep(1000);
//		cout << "���캯��end" << endl;
//	}
//
//public:
//	static singelton *getInstence() {
//		if (m_singe == NULL) {
//			m_singe = new singelton;
//		}
//		return m_singe;
//	}
//
//	static void freeInstence() {
//		if (m_singe != NULL) {
//			delete m_singe;
//			m_singe = NULL;
//		}
//	}
//
//private:
//	static singelton *m_singe;
//};
//
//singelton *singelton::m_singe = NULL;
//
//void main() {
//	singelton *p1 = singelton::getInstence();
//	singelton *p2 = singelton::getInstence();
//
//	if (p1 == p2) {
//		cout << "ͬһ������" << endl;
//	}
//	else
//	{
//		cout << "no" << endl;
//	}
//
//	singelton::freeInstence();
//	system("pause");
//}

//����ʽ
#include <iostream>
using namespace std;

//����ʽ
class  Singelton
{
private:
	Singelton()
	{
		m_singer = NULL;
		m_count = 0;
		cout << "���캯��Singelton ... do" << endl;
	}

public:
	static Singelton *getInstance()
	{
		if (m_singer == NULL)  //����ʽ��1 ÿ�λ�ȡʵ����Ҫ�ж� 2 ���̻߳�������
		{
			m_singer = new Singelton;
		}
		return m_singer;
	}
	static void printT()
	{
		cout << "m_count: " << m_count << endl;
	}

private:
	static Singelton *m_singer;
	static int m_count;
};

Singelton *Singelton::m_singer = NULL;  //����ʽ ��û�д�����������
int Singelton::m_count = 0;


void main()
{
	cout << "��ʾ ����ʽ" << endl;
	Singelton *p1 = Singelton::getInstance(); //ֻ����ʹ�õ�ʱ�򣬲�ȥ��������
	Singelton *p2 = Singelton::getInstance();
	if (p1 != p2)
	{
		cout << "����ͬһ������" << endl;
	}
	else
	{
		cout << "��ͬһ������" << endl;
	}
	p1->printT();
	p2->printT();

	system("pause");
	return;
}