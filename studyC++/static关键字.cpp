#include<iostream>
using namespace std;


class BB{
public:
	void getC() {
		cout << c << endl;
	}

	void addC() {
		c++;
	}

	static void getC2() {
		cout << c << endl;
		cout << a << endl;//对非静态成员“BB::a”的非法引用
	}
protected:
private:
	int a;
	int b;
	static int c;
};

int BB::c = 10;

void main(){

	BB b1, b2, b3;
	b1.getC();
	b2.addC();
	b3.getC();

	b3.getC2();

	BB::getC2();
}