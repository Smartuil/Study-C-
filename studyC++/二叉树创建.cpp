#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//二叉链表
typedef struct BiTNode {
	int data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

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
	BiTNode* p = NULL;
	p = CreateBiThrTree();
}
