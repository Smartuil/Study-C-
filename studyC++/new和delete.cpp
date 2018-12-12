#include<iostream>
using namespace std;



void main1(){
	//分配基础类型
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

	//分配数组类型
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
		cout << "构造函数";
	}

	~Test() {
		cout << "析构函数";
	}
protected:
private:
	int a;
};
//new 能执行构造函数   delete能执行构函数
void main() {

	Test *pT1 = (Test *)malloc(sizeof(Test));
	free(pT1);

	Test *pT2 = new Test(10);
	delete pT2;

}