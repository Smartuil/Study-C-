#include "iostream"
#include "vector"

using namespace std;

void BubbleSort(vector<int> &arr) {

	int temp;
	bool flag;
	for (int i = 0; i < arr.size() - 1; i++) {
		flag = false;
		for (int j = arr.size() - 1; j > i; j--) {

			if (arr[j] < arr[j - 1]) {
				temp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = temp;
				flag = true;
			}
		}
		if (!flag) {
			break;
		}
	}
}

int main() {
	vector<int> arr = { 42,20,17,13,28,14,23,15 };
	BubbleSort(arr);
	for (auto i : arr) {
		cout << i << ",";
	}
	return 0;
}