#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
	int data;
	struct Node *next;
}SList;

//������
typedef struct myNode {
	struct Node *next;
}myNode;


typedef struct Teacher {
	int data;
	char name[64];
	char name2[128];
	struct myNode node;
}Teacher;

typedef struct AdvTeacher {
	struct myNode node;
	int data;
	char name[64];
	char name2[128];
}AdvTeacher;

void TestAdv() {
	Teacher t1, t2, t3;
	t1.node.next = &(t2.node);
	t2.node.next = &(t3.node);
	t3.node.next = NULL;

}

SList *SList_Create();//��������
int SList_Print(SList *pHead);//��������
int SList_NodeInsert(SList *pHead,int x,int y);//����ֵ����x֮ǰ����y
int SList_NodeDel(SList *pHead, int y);
int SList_Destroy(SList *pHead);

SList *SList_Create() {
	SList *pHead, *pM, *pCur;
	int data;
	//����ͷ��㲢��ʼ��
	pHead = (SList *)malloc(sizeof(SList));
	if (pHead == NULL) {
		return 0;
	}
	pHead->data = 0;
	pHead->next = NULL;
	printf("\nplease enter your data:");
	scanf("%d", &data);
	pCur = pHead;
	while (data != -1) {
		//����ҵ��ڵ㲢��ʼ��//1 ���ϵؽ������� malloc�½ڵ�
		pM = (SList *)malloc(sizeof(SList));
		if (pM == NULL) {
			return 0;
		}
		pM->data = data;
		pM->next = NULL;

		//2 �½ڵ�������
		pCur->next = pM;
		//3 �½ڵ��ɵ�ǰ�ڵ�
		pCur = pM;//����ڵ��β��׷��
		printf("\nplease enter your data:");
		scanf("%d", &data);
	}
	return pHead;
}
int SList_Print(SList *pHead) {
	SList *tmp;
	if (pHead == NULL) {
		return -1;
	}
	tmp = pHead->next;
	printf("Begin\n");
	while (tmp) {
		printf("%d\n", tmp->data);
		tmp = tmp->next;
	}
	printf("End\n");
	return 0;
}
int SList_NodeInsert(SList *pHead, int x, int y) {
	SList *pM, *pCur, *pPre;
	//�����µ�ҵ��ڵ�
	pM = (SList *)malloc(sizeof(SList));
	if (pM == NULL) {
		return -1;
	}
	pM->data = y;
	pM->next = NULL;

	pPre = pHead;
	pCur = pHead->next;

	while (pCur) {
		if (pCur->data == x) {
			break;
		}
		pPre = pCur;
		pCur = pCur->next;
	}
	pM->next = pPre->next;
	pPre->next = pM;
	return 0;
}
int SList_NodeDel(SList *pHead, int x) {
	SList *pCur, *pPre;

	pPre = pHead;
	pCur = pHead->next;
	while (pCur) {
		if (pCur->data == x) {
			break;
		}
		pPre = pCur;
		pCur = pCur->next;
	}

	//ɾ������
	if (pCur == NULL) {
		printf("û���ҵ��ڵ�%d", x);
		return -1;
	}
	pPre->next = pCur->next;
	if (pCur != NULL) {
		free(pCur);
	}
	return 0;
}
int SList_Destroy(SList *pHead) {
	SList *tmp = NULL;
	if (pHead == NULL) {
		return -1;
	}
	
	while (pHead != NULL) {
		tmp = pHead->next;
		free(pHead);
		pHead = tmp;
	}
	return 0;
}

int SList_Reverse(SList *pHead) {
	SList *p = NULL;
	SList *q = NULL;
	SList *t = NULL;
	if (pHead == NULL || pHead->next==NULL || pHead->next->next==NULL) {
		return 0;
	}
	//p = pHead;
	//q = pHead->next;

	p = pHead->next;
	q = pHead->next->next;

	while (q) {
		t = q->next;
		q->next = p;
		p = q;
		q = t;
	}
	//ͷ�����β�ڵ�
	pHead->next->next = NULL;//ԭ����һ���ڵ��next����
	pHead->next = p;


	return 0;
}

void main() {
	int ret;
	SList *pHead = NULL;
	pHead = SList_Create();
	ret = SList_Print(pHead);
	ret = SList_NodeInsert(pHead, 20, 19);
	ret = SList_Print(pHead);
	ret = SList_NodeDel(pHead, 19);
	ret = SList_Print(pHead);

	ret = SList_Reverse(pHead);
	ret = SList_Print(pHead);

	system("pause");
	return;
}
