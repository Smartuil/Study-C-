#include<iostream>
#include<cstdio>
#define N 10
using namespace std;
int n=2, y=3, tsum = 0;
int ans[N] = {};
int a[N] = {1, 2};
void retrack(int i) {
	int k;
	if (i == n) {
		for (k = 0; k < n; ++k)
			printf("%d ", ans[k]);
		//cout << ans[k] << " ";
		printf("\n");
		return;
	}
	int l = y / a[i];
	for (k = 0; k <= l; ++k) {
		int t = k * a[i];
		if (tsum + t <= y && tsum + t >= 0) {
			tsum += t;
			ans[i] = k;
			retrack(i + 1);
			tsum -= t;
		}
		else
			break;
	}
}
int main() {

	retrack(0);
	//system("pause");
	return 0;
}
