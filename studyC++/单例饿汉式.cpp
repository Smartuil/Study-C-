#include<iostream>
using namespace std;
//
//
//class singelton {
//private:
//	singelton() {
//		cout << "���캯��" << endl;
//	}
//
//public:
//	static singelton *getInstence() {
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
//singelton *singelton::m_singe = new singelton;
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

//��ʽ

class  Singelton2
{
private:
	Singelton2()
	{
		m_singer = NULL;
		m_count = 0;
		cout << "���캯��Singelton ... do" << endl;
	}

public:
	static Singelton2 *getInstance()
	{
		if (m_singer == NULL )
		{
		 	m_singer = new Singelton2;
		}
		return m_singer;
	}
	static void FreeInstance()
	{
		if (m_singer != NULL)
		{
			delete m_singer;
			m_singer = NULL;
			m_count = 0;
		}
	}
	static void printT()
	{
		cout << "m_count: " << m_count << endl;
	}

private:
	static Singelton2 *m_singer;
	static int m_count;
};

Singelton2 *Singelton2::m_singer = new Singelton2; //�����㴴��������ʵ��������ʵ��new����
int Singelton2::m_count = 0;

void main()
{
	cout << "��ʾ ����ʽ" << endl;

	Singelton2 *p1 = Singelton2::getInstance(); //ֻ����ʹ�õ�ʱ�򣬲�ȥ��������
	Singelton2 *p2 = Singelton2::getInstance();
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
	Singelton2::FreeInstance();
	Singelton2::FreeInstance();


	system("pause");
}