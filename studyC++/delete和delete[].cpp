//#include "iostream"
//using namespace std;
//// 程序B  
//class CTextClassA
//{
//public:
//	int m_num;
//	CTextClassA() { m_num = 0; };
//	~CTextClassA() { cout << "~CTextClassA()" << endl; }
//
//	void SetNum(int n) { m_num = n; }
//};
//int main()
//{
//	CTextClassA *pa = new CTextClassA;
//	CTextClassA *pas = new CTextClassA[5];
//	CTextClassA *pas_arr[5];
//	for (int i = 0; i < 5; i++)
//	{
//		pas[i].SetNum(i);
//		pas_arr[i] = &pas[i];
//		cout << "pas" << i << ":" << pas[i].m_num << "\t";
//	}
//	delete pa;
//	delete[] pas;
//	return 0;
//}
//
//
#include "stdio.h"

class SomeClass {

public:

	virtual void some_member_func(int x, char *p) {

		printf("In SomeClass");
	};

};

class DerivedClass : public SomeClass {

public:

	// 如果你把下一行的注释销掉，带有 line (*)的那一行会出现错误

	// virtual void some_member_func(int x, char *p) { printf("In DerivedClass"); };

};

int main() {

	//声明SomeClass的成员函数指针

	typedef void (SomeClass::*SomeClassMFP)(int, char *);

	SomeClassMFP my_memfunc_ptr;

	my_memfunc_ptr = &DerivedClass::some_member_func; // ---- line (*)

	return 0;

}