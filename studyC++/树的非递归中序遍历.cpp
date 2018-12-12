#include<iostream>
using namespace std;
#include "stack"


//二叉链表
typedef struct BiTNode {
	int data;
	struct BiTNode *lchild = NULL, *rchild = NULL;
}BiTNode, *BiTree;

//一直往左走 找到中序遍历的起点
BiTNode* goLeft(BiTNode *T, stack<BiTNode*> &s) {
	if (T == NULL) {
		return NULL;
	}
	while (T->lchild != NULL) {
		s.push(T);
		T = T->lchild;
	}
	return T;
}

void InOrder2(BiTNode* root) {
	stack<BiTNode*> s;
	BiTNode *t = NULL;
	t = goLeft(root, s);

	while (t) {
		printf("%d", t->data);
		//如果t有右子树  重复步骤1
		if (t->rchild != NULL) {
			t = goLeft(t->rchild, s);
		}
		else if(!s.empty())
		{
			t = s.top();//如果t没有  根据栈顶指示回退
			s.pop();
		}
		else//如果t没有 并且栈为空
		{
			t = NULL;
		}
	}
}

void inOrder(BiTNode *root) {
	if (root == NULL) {
		return;
	}
	inOrder(root->lchild);
	printf("%d", root->data);

	inOrder(root->rchild);
}

void main() {
	BiTNode t1, t2, t3, t4, t5;
	t1.data = 1;
	t2.data = 2;
	t3.data = 3;
	t4.data = 4;
	t5.data = 5;

	t1.lchild = &t2;
	t1.rchild = &t3;
	t2.lchild = &t4;
	t3.lchild = &t5;
	inOrder(&t1);
	printf("\n");
	InOrder2(&t1);
}