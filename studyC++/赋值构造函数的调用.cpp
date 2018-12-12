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
	A b = a;//默认提供copy构造函数
	system("pause");
}