
#include<iostream>
using namespace std;



class Fruit {
public:
	virtual void sayname() = 0;
};

class Banana :public Fruit {
public:
	void sayname()
	{
		cout << "�����㽶\n";
	}
};

class Apple :public Fruit {
public:
	void sayname()
	{
		cout << "����ƻ��\n";
	}
};

class AbFactory {

public:
	virtual Fruit *CreateProduct() = 0;
};

class BananaFactory :public AbFactory {
public:
	virtual Fruit *CreateProduct() {
		return new Banana;
	}
};


	class AppleFactory :public AbFactory {
	public:
		virtual Fruit *CreateProduct() {
			return new Apple;
		}
	};

void main() {

	AbFactory *f = NULL;
	Fruit *fruit = NULL;

	f = new BananaFactory;
	fruit = f->CreateProduct();
	fruit->sayname();
	delete fruit;
	delete f;

	f = new AppleFactory;
	fruit = f->CreateProduct();
	fruit->sayname();
	delete fruit;
	delete f;

	system("pause");
}