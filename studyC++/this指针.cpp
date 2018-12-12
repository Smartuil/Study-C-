#include<iostream>
using namespace std;


class Test{
public:
	Test(int a, int b) {
		this->a = a;
		this->b = b;
	}

	//const写在什么地方没有关系
	//const修饰谁？不是形参a.
	//修饰this指向的内存空间
	void OpVar(int a, int b) const{//======>void OpVar(Test *const this, int a, int b) 
		//this->a = 100;
		cout << a << endl;
		cout << b << endl;
	}
protected:
private:
	int a;
	int b;
};
void main(){

}