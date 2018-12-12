#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//二叉链表
typedef struct BiTNode {
	int data;
	struct BiTNode *lchild, *rchild;
}BiTNode,*BiTree;

#define MAX_TREE_SIZE 100
typedef struct BPTNode {
	int data;
	int parentPosition;//指向双亲的指针  数组下标
	char LRTag;//左右孩子标志域
}BPTNode;

typedef struct BPTree {
	BPTNode nodes[100];//因为节点之间是分散的  需要把节点存储到数组中
	int num_node;//节点数目
	int root;//根节点的位置  注意此域存储的是父节点在数组的下标
}BPTree;


void main3() {
	BPTree tree;
	tree.nodes[0].parentPosition = 1000;
	tree.nodes[1].parentPosition = 0;
	tree.nodes[1].data = 'B';
	tree.nodes[1].LRTag = 1;

	tree.nodes[2].parentPosition = 0;
	tree.nodes[2].data = 'C';
	tree.nodes[2].LRTag = 2;
}


void main1(){
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


}

void main2() {
	BiTNode *t1, *t2, *t3, *t4, *t5;
	t1 = (BiTNode*)malloc(sizeof(BiTNode));
	t2 = (BiTNode*)malloc(sizeof(BiTNode));
	t3 = (BiTNode*)malloc(sizeof(BiTNode));
	t4 = (BiTNode*)malloc(sizeof(BiTNode));
	t5 = (BiTNode*)malloc(sizeof(BiTNode));
	t1->data = 1;
	t2->data = 2;
	t3->data = 3;
	t4->data = 4;
	t5->data = 5;

	t1->lchild = t2;
	t1->rchild = t3;
	t2->lchild = t4;
	t3->lchild = t5;


}