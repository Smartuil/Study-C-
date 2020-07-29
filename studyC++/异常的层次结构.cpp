//#include<iostream>
//using namespace std;
//
//
//class MyArray{
//public:
//	MyArray(int len);
//	int getLen();
//	int &operator[](int index);
//	~MyArray();
//
//public:
//	class eSize {
//	public:
//		eSize(int size) {
//			m_size = size;
//		}
//
//		virtual void print() = 0;
//	protected:
//		int m_size;
//	};
//	class eNegative : public eSize {
//	public:
//		eNegative(int size) :eSize(size) {
//
//		}
//		virtual void print() {
//			cout << "eNegative" << m_size << " ";
//		}
//	};
//	class eTooBig : public eSize {
//	public:
//		eTooBig(int size) :eSize(size) {
//
//		}
//		virtual void print() {
//			cout << "eTooBig" << m_size << " ";
//		}
//	};
//	class eZero : public eSize {
//	public:
//		eZero(int size) :eSize(size) {
//
//		}
//		virtual void print() {
//			cout << "eZero" << m_size << " ";
//		}
//	};
//	class eTooSmall : public eSize {
//	public:
//		eTooSmall(int size) :eSize(size) {
//
//		}
//		virtual void print() {
//			cout << "eTooSmall" << m_size << " ";
//		}
//	};
//	
//protected:
//private:
//	int *m_space;
//	int m_len;
//};
//
//MyArray::MyArray(int len) {
//	if (len < 0) {
//		throw eNegative(len);
//	}
//	else if(len == 0)
//	{
//		throw eZero(len);
//	}
//	else if(len > 1000)
//	{
//		throw eTooBig(len);
//	}
//	else if (len < 3)
//	{
//		throw eTooSmall(len);
//	}
//	m_len = len;
//	m_space = new int[len];
//}
//
//int& MyArray::operator[](int index) {
//	return m_space[index];
//}
//
//int MyArray::getLen() {
//	return m_len;
//}
//
//MyArray::~MyArray() {
//	if (m_space != NULL) {
//		delete m_space;
//		m_space = NULL;
//		m_len = 0;
//	}
//}
//
//void main1(){
//	try
//	{
//		MyArray ma(10);
//		for (int i = 0; i < ma.getLen(); i++) {
//			ma[i] = i + 1;
//			cout << ma[i] << " ";
//		}
//	}
//	catch (MyArray::eNegative &e)
//	{
//		cout << "eNegative";
//	}
//	catch (MyArray::eZero &e)
//	{
//		cout << "eZero";
//	}
//	catch (MyArray::eTooBig &e)
//	{
//		cout << "eTooBig";
//	}
//	catch (MyArray::eTooSmall &e)
//	{
//		cout << "eTooSmall";
//	}
//}
//
//void main2() {
//	try
//	{
//		MyArray ma(-9);
//		for (int i = 0; i < ma.getLen(); i++) {
//			ma[i] = i + 1;
//			cout << ma[i] << " ";
//		}
//	}
//	catch (MyArray::eSize &e)
//	{
//		e.print();
//	}
//
//}

#define  _CRT_SECURE_NO_WARNINGS 
#include <iostream>

using namespace std;

class eSize
{
public:
	eSize(int len)
	{
		this->len = len;
	}
	virtual void printErr() {
		cout << "eSize error: len = " << len << endl;
	}
protected:
	int len;
};

class eNagtive :public eSize
{
public:
	eNagtive(int len) : eSize(len) {
	}

	virtual void printErr()
	{
		cout << "eNagtive error: len = " << len << endl;
	}
};

class eZero :public eSize
{
public:
	eZero(int len) :eSize(len) {

	}

	virtual void printErr()
	{
		cout << "eZero error: len = " << len << endl;
	}
};

class eTooBig :public eSize
{
public:
	eTooBig(int len) :eSize(len) {

	}

	virtual void printErr()
	{
		cout << "eTooBig error: len = " << len << endl;
	}
};

class eTooSmall :public eSize
{
public:
	eTooSmall(int len) :eSize(len) {

	}

	virtual void printErr()
	{
		cout << "eTooSmall error: len = " << len << endl;
	}
};

class MyArray
{
public:
	MyArray(int len)
	{
		if (len < 0) {
			throw eNagtive(len);
		}
		else if (len == 0) {
			throw eZero(len);
		}
		else if (len > 1000) {
			throw eTooBig(len);
		}
		else if (len < 10) {
			throw eTooSmall(len);
		}
		this->len = len;
		this->space = new int[len];
	}

	int & operator[](int index)
	{
		return this->space[index];
	}

	int getLen()
	{
		return this->len;
	}

	~MyArray() {
		if (this->space != NULL) {
			delete[] this->space;
			this->space = NULL;
			this->len = 0;
		}
	}
private:
	int len;//元素的个数
	int *space;
};

int main(void)
{
	try {
		MyArray array(3);

		for (int i = 0; i < array.getLen(); i++) {
			array[i] = i + 1;
		}

		for (int i = 0; i < array.getLen(); i++) {
			cout << array[i] << endl;
		}
	}
	catch (eSize &e) //eSize &e = eNagtive(len);
	{
		cout << "捕获到异常" << endl;
		e.printErr();//发生多态
	}

#if 0
	catch (eNagtive &e)
	{
		cout << "捕获到eNagive 异常" << endl;
		e.printErr();
	}
	catch (eZero &e) {
		cout << "捕获到eZero 异常" << endl;
		e.printErr();
	}
	catch (eTooBig &e) {
		cout << "捕获到eTooBig 异常" << endl;
		e.printErr();
	}
	catch (eTooSmall &e) {
		cout << "捕获到eTooSmall 异常" << endl;
		e.printErr();
	}
	catch (...)
	{
		cout << "捕获到未知异常" << endl;
	}
#endif


	return 0;
}