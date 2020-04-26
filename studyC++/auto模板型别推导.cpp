#include<iostream>
using namespace std;


template<typename T>
void f(std::initializer_list<T> p)
{
	cout << "sa";
}


void main(){
	f({3,4});
}

