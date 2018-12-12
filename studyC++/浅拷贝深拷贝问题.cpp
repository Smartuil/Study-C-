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
	//解决方案手动编写copy构造函数    深拷贝  浅拷贝会报错  内存释放问题
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
	}
protected:
private:
	char *m_p;
	int m_len;
};
void objplaymain(){

	Name obj1("abc");

	//Name obj2 = obj1;

	Name obj3("obj3");
	obj3 = obj1;//等号操作    //需要显示重载=操作符
	
}

void main() {

	objplaymain();
	system("pause");
}