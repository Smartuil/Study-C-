#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//二叉链表
typedef struct BiTNode {
	int data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

void preOrder(BiTNode *root) {
	if (root == NULL) {
		return;
	}
	printf("%d", root->data);
	preOrder(root->lchild);
	preOrder(root->rchild);
}

void inOrder(BiTNode *root) {
	if (root == NULL) {
		return;
	}
	inOrder(root->lchild);
	printf("%d", root->data);
	
	inOrder(root->rchild);
}

void postOrder(BiTNode *root) {
	if (root == NULL) {
		return;
	}
	
	postOrder(root->lchild);
	postOrder(root->rchild);
	printf("%d", root->data);
}
int sum;
void countLeaf(BiTNode* root) {
	if (root != NULL) {
		if (root->lchild == NULL && root->rchild == NULL) {
			sum++;
		}
		if (root->lchild)countLeaf(root->lchild);
		if (root->rchild)countLeaf(root->rchild);
	}
}

void countLeaf2(BiTNode* root, int *sum) {
	if (root != NULL) {
		if (root->lchild == NULL && root->rchild == NULL) {
			(*sum)++;
		}
		if (root->lchild)countLeaf2(root->lchild, sum);
		if (root->rchild)countLeaf2(root->rchild, sum);
	}
}

void countLeaf3(BiTNode* root, int *sum) {
	if (root != NULL) {
		if (root->lchild)countLeaf2(root->lchild, sum);
		if (root->rchild)countLeaf2(root->rchild, sum);
		if (root->lchild == NULL && root->rchild == NULL) {
			(*sum)++;
		}
	}
}

void main() {
	int count = 0;
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

	preOrder(&t1);
	printf("\n");
	inOrder(&t1);
	printf("\n");
	postOrder(&t1);
	printf("\n");
	countLeaf(&t1);
	printf("%d\n",sum);
	countLeaf2(&t1, &count);
	printf("%d\n", count);
	count = 0;
	countLeaf3(&t1, &count);
	printf("%d\n", count);
}
