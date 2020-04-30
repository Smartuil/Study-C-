#include "iostream"
#include "vector"

using namespace std;

//�ϲ� ������������a[first--middle],a[middle+1--end]�ϲ�
void mergeArray(vector<int> &a, int first, int middle, int end, vector<int> &temp) {
	int i = first;
	int m = middle;
	int j = middle + 1;
	int n = end;
	int k = 0;
	while (i <= m && j <= n) {
		if (a[i] <= a[j]) {
			temp[k] = a[i];
			k++;
			i++;
		}
		else {
			temp[k] = a[j];
			k++;
			j++;
		}
	}
	while (i <= m) {
		temp[k] = a[i];
		k++;
		i++;
	}
	while (j <= n) {
		temp[k] = a[j];
		k++;
		j++;
	}

	for (int ii = 0; ii < k; ii++) {
		a[first + ii] = temp[ii];
	}
}

void merge_sort(vector<int> &a, int first, int last, vector<int> &temp) {

	if (first < last) {
		int middle = (first + last) / 2;
		merge_sort(a, first, middle, temp);//��벿���ź���
		merge_sort(a, middle + 1, last, temp);//�Ұ벿���ź���
		mergeArray(a, first, middle, last, temp); //�ϲ����Ҳ���
	}
}

int main() {
	vector<int> arr = { 42,20,17,13,28,14,23,15 };
	vector<int> temp(arr.size(), 0);
	merge_sort(arr, 0, arr.size() - 1, temp);
	for (auto i : arr) {
		cout << i << ",";
	}
	return 0;
}