#include<iostream>
using namespace std;
#include "queue"
#include "vector"

void fun() {
	priority_queue<int> p;//默认是最大值优先级队列
	priority_queue<int, vector<int>, less<int >> p3;//提前定义好的预定义函数
	priority_queue<int, vector<int>, greater<int>> p2;//最小值优先级队列

	p.push(11);
	p.push(21);
	p.push(232);

	cout << p.top() << endl;

	p2.push(11);
	p2.push(21);
	p2.push(232);
	while (p2.size() > 0) {
		cout << p2.top() << endl;
		p2.pop();
	}



}

void main(){
	fun();
}