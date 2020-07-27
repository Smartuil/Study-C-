//#define  _CRT_SECURE_NO_WARNINGS 
//#include <iostream>
//
//using namespace std;
//
//class Box
//{
//public:
//	Box(int l, int w) :length(l), width(w) {}
//
//	int volumu()
//	{
//		return length * width *height;
//	}
//
//	int length;//4
//	int width;//4
//	static int height; //声明一个静态的成员变量 //4
//	//static const int a = 10;
//};
//
////在外部初始化
//int  Box::height = 100;
//
//int main(void)
//{
//	Box b1(10, 20);
//	Box b2(30, 40);
//
//	cout << "b1: " << b1.volumu() << ", " << b1.height << endl;
//	cout << "b2: " << b2.volumu() << "," << b2.height << endl;
//	Box::height;
//
//	cout << "sizeof(b1) :" << sizeof(b1) << endl; //8
//	cout << "sizeof(b2) :" << sizeof(b2) << endl; //8  说明static修饰的成员变量并不属于对象中， 而是在全局区开辟的。
//
//
//	return 0;
//}

#define  _CRT_SECURE_NO_WARNINGS 
#include <iostream>

using namespace std;

class AA
{
public:
	AA(int a, int b)
	{
		m_a = a;
		m_b = b;
	}

	int getC()
	{
		cout << "c = " << m_c << endl;
		m_c++;
		return m_c;
	}

	static int m_c;//静态的成员变量  //1 在类的内部声明这个变量 用static
						//静态的成员变量是对本来共享，所有本类中的对象 都是公用一个内存区域
private:
	int m_a;
	int m_b;
};


//2 静态成员变量的初始化， 在类的外部去写
int AA::m_c = 0;

int main(void)
{
	AA aa1(10, 20), aa2(100, 200), aa3(1000, 2000);

	aa1.getC();
	aa2.getC();
	aa3.getC();

	//怎么去修改一个静态的成员变量
	AA::m_c = 200;

	aa1.getC();
	aa2.getC();
	aa3.getC();




	return 0;
}