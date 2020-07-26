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
	////typeid:返回指针或引用所指对象的实际类型
	//std::cout << typeid(p1).name() << "  " << typeid(p2).name() << std::endl;
	//std::cout << (typeid(p1) == typeid(p2)) << "\n";

	//std::cout << typeid(*p1).name() << "  " << typeid(*p2).name() << std::endl;
	//std::cout << (typeid(*p1) == typeid(*p2)) << "\n";//重载的方式判定类型是否一致

	//dynamic_cast : 将基类类型的指针或引用安全地转换为派生类型的指针和引用
	A a1;
	B b1;
	A *p1 = &a1;
	A *p2 = &b1;
	B *p3(nullptr);
	p3 = dynamic_cast<B*>(p2);
	//dynamic_cast必须要有虚函数，根据虚函数表转换，不能转换
	//转换失败为空 类的空指针可以调用不调用数据的函数
	//转换成功就是地址
	std::cout << p3 << "\n";
	p3->test();
	std::cin.get();
}