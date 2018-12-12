#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "linklist.h"
#include "linkstack.h"




//二叉链表
typedef struct BiTNode {
	int data;
	struct BiTNode *lchild, *rchild;
}BiTNode;

//一直往左走 找到中序遍历的起点
BiTNode* goLeft(BiTNode *T, LinkStack *s) {
	if (T == NULL) {
		return NULL;
	}
	while (T->lchild != NULL) {
		LinkStack_Push(s, (void *)T);
		T = T->lchild;
	}
	return T;
}

void InOrder2(BiTNode* root) {
	LinkStack *s = LinkStack_Create();
	BiTNode *t = NULL;
	t = goLeft(root, s);

	while (t) {
		printf("%d", t->data);
		//如果t有右子树  重复步骤1
		if (t->rchild != NULL) {
			t = goLeft(t->rchild, s);
		}
		else if (LinkStack_Size(s) > 0)
		{
			//t = s.top();//如果t没有  根据栈顶指示回退
			//s.pop();

			t = LinkStack_Pop(s);
		}
		else//如果t没有 并且栈为空
		{
			t = NULL;
		}
	}
}

void main() {
	BiTNode t1, t2, t3, t4, t5;
	memset(&t1, 0, sizeof(BiTNode));
	memset(&t2, 0, sizeof(BiTNode));
	memset(&t3, 0, sizeof(BiTNode));
	memset(&t4, 0, sizeof(BiTNode));
	memset(&t5, 0, sizeof(BiTNode));
	t1.data = 1;
	t2.data = 2;
	t3.data = 3;
	t4.data = 4;
	t5.data = 5;

	t1.lchild = &t2;
	t1.rchild = &t3;
	t2.lchild = &t4;
	t3.lchild = &t5;
	
	InOrder2(&t1);
}