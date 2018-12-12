#include<iostream>
using namespace std;

template <typename T>
int mySort(T *array, T size) {
	T tmp;
	if (array == NULL) {
		return -1;
	}

	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			if (array[i] < array[j]) {
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
		}
	}
	return 0;
}

template <typename T>
int myPrint(T *array, int size) {
	for (int i = 0; i < size; i++) {
		cout << array[i] << endl;
	}
	return 0;

}
void main(){

	int array[] = { 11,43,65,876,234,987,212 };
	cout << "排序之前" << endl;
	myPrint(array, sizeof(array) / sizeof(*array));
	int size = sizeof(array) / sizeof(*array);
	mySort<int>(array, size);
	cout << "排序之后" << endl;
	myPrint(array, sizeof(array) / sizeof(*array));


	{
		char buf[] = "dadsadasdasda";
		int len = strlen(buf);
		myPrint<char>(buf, len);
		mySort<char>(buf, len);
		cout << "排序之后" << endl;
		myPrint<char>(buf, len);
	}
}