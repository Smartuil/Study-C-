#include<iostream>
using namespace std;



void main1(){
	//�����������
	int *p = (int *)malloc(sizeof(int));
	*p = 10;
	free(p);
	int *p2 = new int;
	*p2 = 20;
	free(p2);
	int *p3 = new int(30);
	cout << *p3;
	delete p3;


}

void main2() {

	//������������
	int *p = (int *)malloc(sizeof(int) * 10);
	p[0] = 10;
	free(p);

	int *pArray = new int[10];
	pArray[1] = 100;
	delete[] pArray;

}


class Test{
public:
	Test(int _a) {
		a = _a;
		cout << "���캯��";
	}

	~Test() {
		cout << "��������";
	}
protected:
private:
	int a;
};
//new ��ִ�й��캯��   delete��ִ�й�����
void main() {

	Test *pT1 = (Test *)malloc(sizeof(Test));
	free(pT1);

	Test *pT2 = new Test(10);
	delete pT2;

}