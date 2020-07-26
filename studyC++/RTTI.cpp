#include "iostream"

class A
{
public:
	int num;
	static int data;
	virtual void run()
	{
		std::cout << "A run \n";
	}
};
int A::data = 1;
class B :public A
{
public:
	int num = 0;
	static int data;
	void run()
	{
		std::cout << "B run\n";
	}
	void test()
	{
		std::cout << num << "\n";
		std::cout << "B test\n";
	}
};
int B::data = 2;

void main()
{
	//A a1;
	//B b1;
	//A *p1 = &a1;
	//A *p2 = &b1;
	////typeid:����ָ���������ָ�����ʵ������
	//std::cout << typeid(p1).name() << "  " << typeid(p2).name() << std::endl;
	//std::cout << (typeid(p1) == typeid(p2)) << "\n";

	//std::cout << typeid(*p1).name() << "  " << typeid(*p2).name() << std::endl;
	//std::cout << (typeid(*p1) == typeid(*p2)) << "\n";//���صķ�ʽ�ж������Ƿ�һ��

	//dynamic_cast : ���������͵�ָ������ð�ȫ��ת��Ϊ�������͵�ָ�������
	A a1;
	B b1;
	A *p1 = &a1;
	A *p2 = &b1;
	B *p3(nullptr);
	p3 = dynamic_cast<B*>(p2);
	//dynamic_cast����Ҫ���麯���������麯����ת��������ת��
	//ת��ʧ��Ϊ�� ��Ŀ�ָ����Ե��ò��������ݵĺ���
	//ת���ɹ����ǵ�ַ
	std::cout << p3 << "\n";
	p3->test();
	std::cin.get();
}