#include "iostream"
#include "vector"

using namespace std;

void shell_sort(vector<int> &array, int lenth) {

	int temp = 0;
	int incre = lenth;

	while (true) {
		incre = incre / 2;

		for (int k = 0; k < incre; k++) {

			for (int i = k + incre; i < lenth; i += incre) {

				for (int j = i; j > k; j -= incre) {
					if (array[j] < array[j - incre]) {
						temp = array[j - incre];
						array[j - incre] = array[j];
						array[j] = temp;
					}
					else {
						break;
					}
				}
			}
		}

		if (incre == 1) {
			break;
		}
	}
}

int main() {
	vector<int> arr = { 42,20,17,13,28,14,23,15 };
	shell_sort(arr, arr.size());
	for (auto i : arr) {
		cout << i << ",";
	}
	return 0;
}