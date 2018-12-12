#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<vector>
#include<algorithm>
using namespace std;




//void main111() {
//	int i;
//	srand(time(NULL));    
//	for (i = 0; i < 10; i++)      
//		printf("Random number #%d: %d\n", i, rand());
//	system("pause");
//}
vector<int> s;
void main() {
	int start = 0;
	string str = "1234567891";
	s.clear();
	int x, len = (str.length() - 1) / 8 + 1;
	for (int i = 0; i < len; i++) {
		int end = str.length() - i * 8;
		start = max(0, end - start);
		sscanf(str.substr(start, end - start).c_str(), "%d", &x);
		s.push_back(x);
	}
	int a = s.front();
	cout << a;
	system("pause");
}