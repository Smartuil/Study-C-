#include<iostream>
using namespace std;
#include "queue"

void fun() {
	queue<int> q;
	q.push(1);
	q.push(3);
	q.push(2);
	while (!q.empty()) {
		cout << q.front() << endl;
		q.pop();

	}

}

void main(){
	fun();
}