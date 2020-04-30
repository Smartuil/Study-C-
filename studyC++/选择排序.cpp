#include "iostream"
#include "vector"

using namespace std;

void select_sort(vector<int> &array, int lenth) {

	for (int i = 0; i < lenth - 1; i++) {

		int minIndex = i;
		for (int j = i + 1; j < lenth; j++) {
			if (array[j] < array[minIndex]) {
				minIndex = j;
			}
		}
		if (minIndex != i) {
			int temp = array[i];
			array[i] = array[minIndex];
			array[minIndex] = temp;
		}
	}
}
int main() {
	vector<int> arr = { 42,20,17,13,28,14,23,15 };
	select_sort(arr,arr.size());
	for (auto i : arr) {
		cout << i << ",";
	}
	return 0;
}