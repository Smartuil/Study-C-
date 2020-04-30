#include "iostream"
#include "vector"

using namespace std;

//��i�ڵ㿪ʼ����,nΪ�ڵ����� ��0��ʼ���� i�ڵ���ӽڵ�Ϊ 2*i+1, 2*i+2  
void MinHeapFixdown(vector<int> &a, int i, int n) {

	int j = 2 * i + 1; //�ӽڵ�
	int temp = 0;

	while (j < n) {
		//�������ӽڵ���Ѱ����С��
		if (j + 1 < n && a[j + 1] < a[j]) {
			j++;
		}

		if (a[i] <= a[j])
			break;

		//�ϴ�ڵ�����
		temp = a[i];
		a[i] = a[j];
		a[j] = temp;

		i = j;
		j = 2 * i + 1;
	}
}

//������С��
void MakeMinHeap(vector<int> &a, int n) {
	for (int i = (n - 1) / 2; i >= 0; i--) {
		MinHeapFixdown(a, i, n);
	}
}

void MinHeap_Sort(vector<int> &a, int n) {
	int temp = 0;
	MakeMinHeap(a, n);

	for (int i = n - 1; i > 0; i--) {
		temp = a[0];
		a[0] = a[i];
		a[i] = temp;
		MinHeapFixdown(a, 0, i);
	}
}

int main() {
	vector<int> arr = { 88,85,83,73,72,60,57,48,42,6 };
	MinHeap_Sort(arr, arr.size());
	for (auto i : arr) {
		cout << i << ",";
	}
	return 0;
}