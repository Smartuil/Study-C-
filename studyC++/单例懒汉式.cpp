#include<iostream>
#include <windows.h>
using namespace std;


class singelton {
private:
	singelton() {
		cout << "���캯��begin" << endl;
		//Sleep(1000);
		cout << "���캯��end" << endl;
	}

public:
	static singelton *getInstence() {
		if (m_singe == NULL) {
			m_singe = new singelton;
		}
		return m_singe;
	}

	static void freeInstence() {
		if (m_singe != NULL) {
			delete m_singe;
			m_singe = NULL;
		}
	}

private:
	static singelton *m_singe;
};

singelton *singelton::m_singe = NULL;

void main4() {
	singelton *p1 = singelton::getInstence();
	singelton *p2 = singelton::getInstence();

	if (p1 == p2) {
		cout << "ͬһ������" << endl;
	}
	else
	{
		cout << "no" << endl;
	}

	singelton::freeInstence();
	system("pause");
}