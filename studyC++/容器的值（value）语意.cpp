#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include "vector"
#include "string"

class Teacher {
public:
	Teacher(char *name, int age) {
		m_panme = new char[strlen(name) + 1];
		strcpy(m_panme, name);
		m_age = age;
	}

	~Teacher()
	{
		if (m_panme != NULL) {
			delete[] m_panme;
			m_panme = NULL;
			m_age = 0;
		}
	}

	void print() {
		cout << m_panme << m_age << endl;
	}

	//Teacher t2 = t1;
	Teacher(const Teacher &t) {
		m_panme = new char[strlen(t.m_panme) + 1];
		strcpy(m_panme, t.m_panme);
		m_age = t.m_age;
	}
	//t3 = t2 = t1;
	Teacher& operator=(const Teacher &t) {
		//先释放t2旧的内存释放掉
		if (m_panme != NULL) {
			delete[] m_panme;
			m_panme = NULL;
			m_age = 0;
		}
		//根据t1大小分配内存
		m_panme = new char[strlen(t.m_panme) + 1];
		//copy t1数据
		strcpy(m_panme, t.m_panme);
		m_age = t.m_age;

		return *this;
	}
protected:
private:
	char *m_panme;
	int m_age;
};


void fun() {
	char name[] = "t1";
	Teacher t1(name, 23);
	vector<Teacher> v1;
	v1.push_back(t1);//把t1拷贝一份放在容器中
	t1.print();
}


void main(){
	fun();
}