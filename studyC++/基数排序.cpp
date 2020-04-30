#include "iostream"
#include "vector"

using namespace std;

void RadixSort(vector<int> &A, vector<int> &temp, int n, int k, int r, vector<int> &cnt) {

	//A:ԭ����
	//temp:��ʱ����
	//n:���е����ָ���
	//k:����λ��2
	//r:����10
	//cnt:�洢bin[i]�ĸ���

	for (int i = 0, rtok = 1; i < k; i++, rtok = rtok * r) {

		//��ʼ��
		for (int j = 0; j < r; j++) {
			cnt[j] = 0;
		}
		//����ÿ�����ӵ����ָ���
		for (int j = 0; j < n; j++) {
			cnt[(A[j] / rtok) % r]++;
		}
		//cnt[j]�ĸ����޸�Ϊǰj������һ���м�������
		for (int j = 1; j < r; j++) {
			cnt[j] = cnt[j - 1] + cnt[j];
		}
		for (int j = n - 1; j >= 0; j--) {      //�ص����
			cnt[(A[j] / rtok) % r]--;
			temp[cnt[(A[j] / rtok) % r]] = A[j];
		}
		for (int j = 0; j < n; j++) {
			A[j] = temp[j];
		}
	}
}

int main() {
	vector<int> arr = { 27,91,1,97,17,23,84,28,72,5,67,25 };
	vector<int> temp(arr.size(), 0);
	vector<int> cnt(10, 0);
	RadixSort(arr, temp, arr.size(), 2, 10, cnt);
	for (auto i : arr) {
		cout << i << ",";
	}
	return 0;
}