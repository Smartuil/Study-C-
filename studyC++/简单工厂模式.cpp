#include<iostream>
using namespace std;


class Fruit {

public:
	virtual void getFruit() = 0;

};

class Banana :public Fruit {
public:
	virtual void getFruit() {
		cout << "我是香蕉\n";
	}
};

class Apple :public Fruit {
public:
	virtual void getFruit() {
		cout << "我是苹果\n";
	}
};



class Factor {

public:
	Fruit *create(const char *p) {
		if (strcmp(p, "banana") == 0) {
			return new Banana;
		}
		else if (strcmp(p, "apple") == 0) {
			return new Apple;
		}
		else {
			cout << "不支持\n";
		}
	}
};
void main() {

	Factor *f = new Factor();
	Fruit *fruit = NULL;
	fruit = f->create("banana");
	fruit->getFruit();
	delete fruit;

	fruit = f->create("apple");
	fruit->getFruit();
	delete fruit;

	system("pause");
}