#include<iostream>
using namespace std;//c++的命名空间

struct Teacer {
	int &a;
	double &b;
};

int main()
{
	int a = 10;
	int &b = a;
	//b是a的别名，请问c++编译器后面做了什么工作？
	b = 11;
	cout << "b--->" << a << endl;
	printf("a:%d\n", a);
	printf("b:%d\n", b);
	printf("&a:%d\n", &a);
	printf("&b:%d\n", &b);  //请思考：对同一内存空间可以取好几个名字吗？
	printf("sizeof(Teacher) %d\n", sizeof(Teacer));
	return 0;
}
