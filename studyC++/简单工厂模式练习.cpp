#include "iostream"
using namespace std;
//����//ģ���������㣻
		//�ò������������������������Ӽ��˳���, ���н������

//����������� COperation	
//�Ӽ��˳��������	(ע�⺬��2��������)
//������CCalculatorFactory 
//����˼�� ��һ���������������������������ͬ���࣬Ȼ����ݲ�ͬ���virtual�����õ���ͬ�Ľ��

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
