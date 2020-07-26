#include<iostream>

//const int i = 10;

void main()
{
	const int i = 10;
	int *p = &i;
	*p = 30;
	std::cout << i;
}