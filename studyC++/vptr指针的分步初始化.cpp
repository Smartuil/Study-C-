#include<iostream>
using namespace std;

//���캯���е����麯���ܷ�����̬��
class Parent {
public:
	Parent(int a = 0) {
		this->a = a;
		print();
	}

	virtual void print() {
		cout << "Dad" << endl;
	}
protected:
private:
	int a;
};

class Child : public Parent {
public:
	Child(int a = 0, int b = 0) : Parent(a) {
		this->b = b;
		print();
	}

	virtual void print() {
		cout << "Child" << endl;
	}
protected:
private:
	int b;
};

void howToPlay(Parent *base) {
	base->print();
}
void main() {
	Parent p1;
	Child c1;//����һ��������� ����������У��ڸ��๹�캯���е����麯��print
	

}