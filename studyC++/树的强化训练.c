#define _CRT_SECURE_NO_WARNINGS
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

int Depth(BiTNode *root) {
	int deptleft = 0;
	int deptright = 0;
	int deptval = 0;
	if (root == NULL) {
		return 0;
	}
	deptleft = Depth(root->lchild);
	deptright = Depth(root->rchild);
	deptval = 1 + (deptleft > deptright ? deptleft : deptright);
	return deptval;
}

BiTNode *copyTree(BiTNode* root) {
	BiTNode* newNode = NULL;
	BiTNode* newLp = NULL;
	BiTNode* newRp = NULL;
	if (root == NULL) {
		return NULL;
	}
	if (root->lchild != NULL) {
		newLp = copyTree(root->lchild);
	}
	else
	{
		newLp = NULL;
	}

	if (root->rchild != NULL) {
		newRp = copyTree(root->rchild);
	}
	else
	{
		newRp = NULL;
	}
	newNode = (BiTNode*)malloc(sizeof(BiTNode));
	if (newNode == NULL) {
		return NULL;
	}
	newNode->lchild = newLp;
	newNode->rchild = newRp;
	newNode->data = root->data;
	return newNode;
}
//先序创建
BiTNode * CreateBiThrTree() {
	BiTNode *node = NULL;
	char h;
	scanf("%c", &h);
	if (h == '#') {
		return NULL;
	}
	else
	{
		node = (BiTNode*)malloc(sizeof(BiTNode));
		if (node == NULL) {
			return NULL;
		}
		node->data = h;
		node->lchild = CreateBiThrTree();
		node->rchild = CreateBiThrTree();
		return node;
	}
}

void FreeTree(BiTNode *T) {
	if (T == NULL) {
		return;
	}
	if (T->lchild != NULL) {
		FreeTree(T->lchild);
		T->lchild = NULL;
	}
	if (T->rchild != NULL) {
		FreeTree(T->rchild);
		T->rchild = NULL;
	}
	if (T != NULL) {
		free(T);
		T = NULL;
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

	{
		BiTNode* p = NULL;
		p = CreateBiThrTree();
		preOrder(p);
	}

	//preOrder(&t1);
	//printf("\n");
	//inOrder(&t1);
	//printf("\n");
	//postOrder(&t1);
	//printf("\n");
	//printf("%d\n",Depth(&t1));

	//BiTNode* root = copyTree(&t1);
	//preOrder(root);
	//printf("\n");
}
