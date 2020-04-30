#include "iostream"
#include "vector"

using namespace std;

void  insert_sort(vector<int> &array, int lenth) {

	int temp;

	for (int i = 0; i < lenth - 1; i++) {
		for (int j = i + 1; j > 0; j--) {
			if (array[j] < array[j - 1]) {
				temp = array[j - 1];
				array[j - 1] = array[j];
				array[j] = temp;
			}
			else {
				break;
			}
		}
	}
}

int main() {
	vector<int> arr = { 42,20,17,13,28,14,23,15 };
	insert_sort(arr, arr.size());
	for (auto i : arr) {
		cout << i << ",";
	}
	return 0;
}