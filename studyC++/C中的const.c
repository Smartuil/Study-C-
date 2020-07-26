#include<stdio.h>

const int i = 10;

//void main()
//{
//	//const int i = 10;
//	int *p = &i;
//	*p = 30;
//	printf("%d", i);
//}

int main()
{
	int a = 0;
	int &b = a; //int * const b = &a 
	b = 11;  //*b = 11;

	return 0;
}
