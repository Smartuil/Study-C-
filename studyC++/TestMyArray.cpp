#include<iostream>
#include "MyArray.h"
using namespace std;

void main(){
	Array a1(10);

	for (int i = 0; i < a1.length(); i++) {
		//a1.setData(i, i);
		a1[i] = i;
	}
	cout << "打印a1" << endl;
	for (int i = 0; i < a1.length(); i++) {
		//cout << a1.getData(i) << " ";
		cout << a1[i] << " ";
	}
	cout << endl;
	Array a2 = a1;
	cout << "打印a2" << endl;
	for (int i = 0; i < a1.length(); i++) {
		//cout << a2.getData(i) << " ";
		cout << a2[i] << " ";
	}

	{
		Array a3(5);
		a3 = a1;
		a3 = a2 = a1; 

		cout << endl;
		cout << "打印a3" << endl;
		for (int i = 0; i < a1.length(); i++) {
			//cout << a2.getData(i) << " ";
			cout << a3[i] << " ";
		}
	}


	{
		cout << endl;
		if (a1 == a2) {
			cout << "相等" << endl;
		}

		cout << endl;
		if (a1 != a2) {
			cout << "不相等" << endl;
		}
	}
}