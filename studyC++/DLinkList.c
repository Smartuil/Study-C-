#include "DLinklist.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _tag_DLinkList {
	DLinkListNode head;
	DLinkListNode* slider;
	int len;
}TDLinkList;

DLinkList* DLinkList_Create() {
	TDLinkList *ret = NULL;
	ret = (TDLinkList*)malloc(sizeof(TDLinkList));
	memset(ret, 0, sizeof(TDLinkList));
	ret->head.next = NULL;
	ret->len = 0;
	ret->head.pre = NULL;
	ret->slider = NULL;
	return ret;
}

void DLinkList_Destroy(DLinkList* list) {
	if (list != NULL) {
		free(list);
		list = NULL;
	}
	return;
}

void DLinkList_Clear(DLinkList* list) {
	TDLinkList *slist = NULL;
	if (list == NULL) {
		return;
	}
	slist = (TDLinkList*)list;
	slist->len = 0;
	slist->head.next = NULL;
	slist->head.pre = NULL;
	slist->slider = NULL;
	return;
}

int DLinkList_Length(DLinkList* list) {
	TDLinkList *slist = NULL;
	if (list == NULL) {
		return -1;
	}
	slist = (TDLinkList*)list;
	return slist->len;
}

int DLinkList_Insert(DLinkList* list, DLinkListNode* node, int pos) {
	int ret = 0, i;
	TDLinkList *slist = NULL;
	DLinkListNode *current;
	DLinkListNode *next;
	if (list == NULL || node == 0 || pos < 0) {
		ret = 0;
		printf("func () err ret=%d\n", ret);
		return ret;
	}
	slist = (TDLinkList*)list;
	current = (DLinkListNode*)slist;
	next = current->next;
	for (i = 0; i < pos && (current->next != NULL); i++) {
		current = current->next;
	}
	current->next = node;
	node->next = next;
	
	if (next != NULL) {//当链表插入第一个元素需要特殊处理
		next->pre = node;
	}
	node->pre = current;
	//若第一次插入节点
	if (slist->len == 0) {
		slist->slider = node;//当链表插入第一个元素需要处理游标
	}
	
	//若在0位置插入，需要特殊处理  新节点next前pre指向null
	if (current == (DLinkListNode*)slist) {
		node->pre = NULL;
	}
	slist->len++;
	return ret;
}

DLinkListNode* DLinkList_Get(DLinkList* list, int pos) {
	int i;
	TDLinkList *slist = NULL;
	DLinkListNode *current;
	if (list == NULL || pos < 0) {
		printf("func DLinkList_Get() err\n");
		return NULL;
	}
	slist = (TDLinkList*)list;
	current = (DLinkListNode*)slist;
	for (i = 0; i < pos && (current->next != NULL); i++) {
		current = current->next;
	}
	return current->next;
}

DLinkListNode* DLinkList_Delete(DLinkList* list, int pos) {
	DLinkListNode* ret;
	int i;
	TDLinkList *slist = NULL;
	DLinkListNode *current;
	DLinkListNode *next;
	if (list == NULL || pos < 0) {
		printf("func DLinkList_Delete() err\n");
		return NULL;
	}
	slist = (TDLinkList*)list;
	current = (DLinkListNode*)slist;
	next = current->next->next;
	DLinkListNode* last = NULL;
	for (i = 0; i < pos && (current->next != NULL); i++) {
		current = current->next;
	}

	////若删除第一个元素（头结点）
	//if (current == ((DLinkListNode*)slist)) {
	//	last = (DLinkListNode*)DLinkList_Get(slist, slist->len - 1);
	//}

	ret = current->next;
	current->next = current->next->next;
	if (next != NULL) {
		next->pre = current;
		if (current == ((DLinkListNode*)slist)) {
			next->pre = NULL;
		}
	}

	//若删除的元素为游标所指的元素
	if (slist->slider == ret) {
		slist->slider = next;
	}
	////若删除元素后，链表长度为0
	//if (slist->len == 0) {
	//	slist->head.next = NULL;
	//	slist->slider = NULL;
	//}
	slist->len--;
	return ret;
}

DLinkListNode* DLinkList_DeleteNode(DLinkList* list, DLinkListNode* node) {
	TDLinkList* slist = (TDLinkList*)list;
	DLinkListNode* ret = NULL;
	int i = 0;

	if (slist != NULL) {
		DLinkListNode* current = (DLinkListNode*)slist;

		//查找node在循环链表中的位置i
		for (i = 0; i < slist->len; i++) {
			if (current->next == node) {
				ret = current->next;
				break;
			}
			current = current->next;
		}

		if (ret != NULL) {
			DLinkList_Delete(slist, i);
		}
	}
	return ret;
}

DLinkListNode* DLinkList_Reset(DLinkList* list) {
	TDLinkList* slist = (TDLinkList*)list;
	DLinkListNode* ret = NULL;
	if (slist != NULL) {
		slist->slider = slist->head.next;
		ret = slist->slider;
	}
	return ret;
}

DLinkListNode* DLinkList_Currnet(DLinkList* list) {
	TDLinkList* slist = (TDLinkList*)list;
	DLinkListNode* ret = NULL;
	if (slist != NULL) {
		ret = slist->slider;
	}
	return ret;
}
//把当前位置返回，并且游标下移
DLinkListNode* DLinkList_Next(DLinkList* list) {
	TDLinkList* slist = (TDLinkList*)list;
	DLinkListNode* ret = NULL;
	if ((slist != NULL) && (slist->slider != NULL)) {
		ret = slist->slider;
		slist->slider = ret->next;
	}
	return ret;
}

DLinkListNode* DLinkList_Pre(DLinkList* list) {
	TDLinkList* slist = (TDLinkList*)list;
	DLinkListNode* ret = NULL;
	if ((slist != NULL) && (slist->slider != NULL)) {
		ret = slist->slider;
		slist->slider = ret->pre;
	}
	return ret;
}