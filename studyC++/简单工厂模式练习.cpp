#include "iostream"
using namespace std;
//需求：//模拟四则运算；
		//用操作符工厂类生产操作符（加减乘除）, 进行结果运算

//运算符抽象类 COperation	
//加减乘除具体的类	(注意含有2个操作数)
//工厂类CCalculatorFactory 
//核心思想 用一个工厂来根据输入的条件产生不同的类，然后根据不同类的virtual函数得到不同的结果

class COperation
{
public:
	int first;
	int second;

public:
	virtual double GetResult() = 0;
private:
};

class AddOperation : public COperation
{
public:
	double GetResult()
	{
		return first + second;
	}
private:
};

class SubOperation : public COperation
{
public:
	double GetResult()
	{
		return first - second;
	}
private:
};

class CCalculatorFactory
{
public:
	static COperation*CreateOperation(char cOperator)
	{
		COperation * tmp = NULL;
		switch (cOperator)
		{
		case '+':
			tmp = new AddOperation();
			break;
		case '-':
			tmp = new SubOperation();
			break;
		default:
			tmp = NULL;
		}
		return tmp;
	}
};

void main()
{
	COperation *op1 = CCalculatorFactory::CreateOperation('+');
	op1->first = 10;
	op1->second = 20;
	cout << op1->GetResult() << endl;

	COperation *op2 = CCalculatorFactory::CreateOperation('-');
	op2->first = 10;
	op2->second = 20;
	cout << op2->GetResult() << endl;

	cout << "hello...\n";
	system("pause");
}
