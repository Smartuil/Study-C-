//#include<iostream>
//using namespace std;
//
//
//
//void main1(){
//	//�����������
//	int *p = (int *)malloc(sizeof(int));
//	*p = 10;
//	free(p);
//	int *p2 = new int;
//	*p2 = 20;
//	free(p2);
//	int *p3 = new int(30);
//	cout << *p3;
//	delete p3;
//
//
//}
//
//void main2() {
//
//	//������������
//	int *p = (int *)malloc(sizeof(int) * 10);
//	p[0] = 10;
//	free(p);
//
//	int *pArray = new int[10];
//	pArray[1] = 100;
//	delete[] pArray;
//
//}
//
//
//class Test{
//public:
//	Test(int _a) {
//		a = _a;
//		cout << "���캯��";
//	}
//
//	~Test() {
//		cout << "��������";
//	}
//protected:
//private:
//	int a;
//};
////new ��ִ�й��캯��   delete��ִ�й�����
//void main() {
//
//	Test *pT1 = (Test *)malloc(sizeof(Test));
//	free(pT1);
//
//	Test *pT2 = new Test(10);
//	delete pT2;
//
//}

#define  _CRT_SECURE_NO_WARNINGS 
#include <iostream>

using namespace std;

class Test
{
public:
	Test()
	{
		m_a = 0;
		m_b = 0;
		cout << "0��0 ����" << endl;
	}
	Test(int a, int b)
	{
		m_a = a;
		m_b = b;
		cout << "a = " << m_a << ", b = " << m_b << "���� " << endl;
	}

	void setA(int a)
	{
		m_a = a;
	}
	void setB(int b)
	{
		m_b = b;
	}

	void printT()
	{
		cout << "a = " << m_a << ", b = " << m_b << endl;
	}

	~Test()
	{
		cout << "a = " << m_a << ", b = " << m_b << "���� " << endl;
	}
private:
	int m_a;
	int m_b;
};


//C������
void test1()
{
	int *p = (int*)malloc(sizeof(int));
	*p = 10;
	cout << *p << endl;
	if (p != NULL) {
		free(p);
		//delete p; //delete �����ͷ�malloc�Ŀ��ٵ��ڴ�
	}

	int *array_p = (int*)malloc(sizeof(int) * 10);
	for (int i = 0; i < 10; i++) {
		array_p[i] = i + 10;
	}

	for (int i = 0; i < 10; i++) {
		cout << array_p[i] << endl;
	}

	if (array_p != NULL) {
		free(array_p);
	}


	cout << " --------  " << endl;

	Test *tp = (Test*)malloc(sizeof(Test)); //������ö���Ĺ��캯��
	//p(10, 20);
	tp->setA(10);
	tp->setB(20); //malloc�����Ķ���ָ�룬ֻ�ܹ�ͨ����Ա���������г�ʼ��
	tp->printT();

	if (tp != NULL) {
		free(tp); //������ö��������
	}
}

//malloc ��free �ڶ�����ͨ�����ǿ��Ի��ʹ�õģ�����malloc��free�Ǻ�����
//new ��delete �ǲ�����������һ��������

//C++�е�new delete
void test2()
{
	//new �ܹ��������malloc������
	int *p = new int; //�ڶ��϶�̬����4���ֽ�
	*p = 10;
	cout << *p << endl;

	if (p != NULL) {
		//delete p; //delete һ������
		free(p); //��new���ٵ��ڴ棬 freeҲ�ܹ��ͷš�
	}

	cout << "-----" << endl;

	int *array_p = new int[10];
	for (int i = 0; i < 10; i++) {
		array_p[i] = i + 10;
	}
	for (int i = 0; i < 10; i++) {
		cout << array_p[i] << endl;
	}

	if (array_p != NULL) {
		delete[]   array_p; //delete һ������
	}


	cout << "-------" << endl;
	//Test *tp = new Test(10, 20);//�������в����Ĺ��캯�� //new �ڴ���һ�������ʱ�򣬻���ö���Ĺ��캯��
	Test *tp = new Test;//�������޲ι��캯��
	tp->printT();
	if (tp != NULL) {
		delete tp; //delete���ͷ�һ������ָ���ʱ�򣬻���ö�����������
	}
}

int main(void)
{
	//test1();
	//test2();

	//double *a = new double[1];
	////.... 
	//delete[] a;

	//int *ip = new int(12);
	//cout << *ip;

	//delete ip;

	Test *ip = new Test[10];
	delete[] ip;

	return 0;
}