#include<iostream>
using namespace std;

class A
{
public:
	A(int _a) {
		a = _a;
		cout << "A���캯��" << a << endl;
	}

	~A() {
		cout << "A��������" << a << endl;
	}
protected:
private:
	int a;
};

//��B���������һ��A�����A������˹��캯��)
class B
{
public:
	B(int _b1, int _b2) :a1(1), a2(2),c(0�� {

	}

	B(int _b1, int _b2,int m, int n) :a1(m), a2(n)��c(0) {
		b1 = _b1;
		b2 = _b2;
		cout << "B���캯��"  << endl;
	}

	~B(){
		cout << "B��������" << endl;
	}
protected:
private:
	int b1;
	int b2;
	A a1;
	A a2;
	const int c;
};

void main(){

	//A a1(10);
	//B objb(1,2);

	B objb2(1, 2, 3 ,4��5);//��ִ�б���϶���Ĺ��캯���������϶����ж�������ն���˳�򣬶����ǰ��ճ�ʼ���б��˳��
	//���������෴
	//��ʼ���б�������const���Ը�ֵ

	//system("pause");
}

