#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;


class Name
{
public:
	Name(const char *myp) {
		m_len = strlen(myp);
		m_p = (char *)malloc(m_len + 1);
		strcpy(m_p, myp);
	}
	//��������ֶ���дcopy���캯��    ���  ǳ�����ᱨ��  �ڴ��ͷ�����
	Name(const Name& obj) {
		m_len = obj.m_len;
		m_p = (char *)malloc(m_len + 1);
		strcpy(m_p, obj.m_p);
	}

	~Name() {
		if (m_p != NULL) {
			free(m_p);
			m_p = NULL;
			m_len = 0;
		}
		cout << "��������" << endl;
	}

	Name& operator=(Name &obj) {
		//���ͷžɵ��ڴ�
		if (this->m_p != NULL) {
			delete[] m_p;
			m_len = 0;
		}
		this->m_len = obj.m_len;
		this->m_p = new char[m_len+1];
		strcpy(this->m_p, obj.m_p);
		return *this;
	}
protected:
private:
	char *m_p;
	int m_len;
};
void objplaymain() {

	Name obj1("abc");

	Name obj2 = obj1;

	Name obj3("obj3");
	obj2 = obj3 = obj1;//�ȺŲ���    //��Ҫ��ʾ����=������

}

void main() {

	objplaymain();

}