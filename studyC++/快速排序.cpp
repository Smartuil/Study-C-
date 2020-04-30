#include "iostream"
#include "vector"

using namespace std;

void quickSort(vector<int> &a, int l, int r) {
	if (l >= r)
		return;

	int i = l; int j = r; int key = a[l];//ѡ���һ����Ϊkey

	while (i < j) {

		while (i < j && a[j] >= key)//���������ҵ�һ��С��key��ֵ
			j--;
		if (i < j) {
			a[i] = a[j];
			i++;
		}

		while (i < j && a[i] < key)//���������ҵ�һ������key��ֵ
			i++;

		if (i < j) {
			a[j] = a[i];
			j--;
		}
	}
	//i == j
	a[i] = key;
	quickSort(a, l, i - 1);//�ݹ����
	quickSort(a, i + 1, r);//�ݹ����
}

int main() {
	vector<int> arr = { 42,20,17,13,28,14,23,15 };
	quickSort(arr, 0, arr.size() - 1);
	for (auto i : arr) {
		cout << i << ",";
	}
	return 0;
}