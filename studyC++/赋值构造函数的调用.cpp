#include<iostream>
using namespace std;

class A
{
public:
	A(int m_a) {
		a = m_a;
	}
protected:
private:
	int a;
};
void main(){
	A a(1);
	A b = a;//Ĭ���ṩcopy���캯��
	system("pause");
}