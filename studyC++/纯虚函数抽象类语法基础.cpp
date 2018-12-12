#include<iostream>
using namespace std;

class Figure{
public:
	virtual void getArea() = 0;
protected:
private:
};

class Circle : public Figure {
public:
	Circle(int a, int b) {
		this->a = a;
		this->b = b;
	}
	virtual void getArea() {
		cout << 3.14*a*a << endl;
	}
protected:
private:
	int a;
	int b;
};

class Tri : public Figure {
public:
	Tri(int a, int b) {
		this->a = a;
		this->b = b;
	}
	virtual void getArea() {
		cout << a*b/2 << endl;
	}
protected:
private:
	int a;
	int b;
};

void play(Figure *base) {
	base->getArea();
}
class Square : public Figure {
public:
	Square(int a, int b) {
		this->a = a;
		this->b = b;
	}
	virtual void getArea() {
		cout << a * b  << endl;
	}
protected:
private:
	int a;
	int b;
};

void main(){
	Circle c1(10, 20);
	Tri t1(20, 30);
	Square s1(30, 40);
	play(&c1);
	play(&t1);
	play(&s1);
}