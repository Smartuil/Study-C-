#include<iostream>
using namespace std;


class MyArray{
public:
	MyArray(int len);
	int getLen();
	int &operator[](int index);
	~MyArray();

public:
	class eSize {
	public:
		eSize(int size) {
			m_size = size;
		}

		virtual void print() = 0;
	protected:
		int m_size;
	};
	class eNegative : public eSize {
	public:
		eNegative(int size) :eSize(size) {

		}
		virtual void print() {
			cout << "eNegative" << m_size << " ";
		}
	};
	class eTooBig : public eSize {
	public:
		eTooBig(int size) :eSize(size) {

		}
		virtual void print() {
			cout << "eTooBig" << m_size << " ";
		}
	};
	class eZero : public eSize {
	public:
		eZero(int size) :eSize(size) {

		}
		virtual void print() {
			cout << "eZero" << m_size << " ";
		}
	};
	class eTooSmall : public eSize {
	public:
		eTooSmall(int size) :eSize(size) {

		}
		virtual void print() {
			cout << "eTooSmall" << m_size << " ";
		}
	};
	
protected:
private:
	int *m_space;
	int m_len;
};

MyArray::MyArray(int len) {
	if (len < 0) {
		throw eNegative(len);
	}
	else if(len == 0)
	{
		throw eZero(len);
	}
	else if(len > 1000)
	{
		throw eTooBig(len);
	}
	else if (len < 3)
	{
		throw eTooSmall(len);
	}
	m_len = len;
	m_space = new int[len];
}

int& MyArray::operator[](int index) {
	return m_space[index];
}

int MyArray::getLen() {
	return m_len;
}

MyArray::~MyArray() {
	if (m_space != NULL) {
		delete m_space;
		m_space = NULL;
		m_len = 0;
	}
}

void main1(){
	try
	{
		MyArray ma(10);
		for (int i = 0; i < ma.getLen(); i++) {
			ma[i] = i + 1;
			cout << ma[i] << " ";
		}
	}
	catch (MyArray::eNegative &e)
	{
		cout << "eNegative";
	}
	catch (MyArray::eZero &e)
	{
		cout << "eZero";
	}
	catch (MyArray::eTooBig &e)
	{
		cout << "eTooBig";
	}
	catch (MyArray::eTooSmall &e)
	{
		cout << "eTooSmall";
	}
}

void main() {
	try
	{
		MyArray ma(-9);
		for (int i = 0; i < ma.getLen(); i++) {
			ma[i] = i + 1;
			cout << ma[i] << " ";
		}
	}
	catch (MyArray::eSize &e)
	{
		e.print();
	}

}