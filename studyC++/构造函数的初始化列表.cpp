#include<iostream>
using namespace std;

class A
{
public:
	A(int _a) {
		a = _a;
		cout << "A构造函数" << a << endl;
	}

	~A() {
		cout << "A析构函数" << a << endl;
	}
protected:
private:
	int a;
};

//在B类中组合了一个A类对象（A类设计了构造函数)
class B
{
public:
	B(int _b1, int _b2) :a1(1), a2(2),c(0） {

	}

	B(int _b1, int _b2,int m, int n) :a1(m), a2(n)，c(0) {
		b1 = _b1;
		b2 = _b2;
		cout << "B构造函数"  << endl;
	}

	~B(){
		cout << "B析构函数" << endl;
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

	B objb2(1, 2, 3 ,4，5);//先执行被组合对像的构造函数，如果组合对象有多个，按照定义顺序，而不是按照初始化列表的顺序
	//析构函数相反
	//初始化列表用来给const属性赋值

	//system("pause");
}

