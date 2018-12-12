#include "Circlelist.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _tag_CircleList {
	CircleListNode head;
	CircleListNode* slider;
	int len;
}TCircleList;

CircleList* CircleList_Create() {
	TCircleList *ret = NULL;
	ret = (TCircleList*)malloc(sizeof(TCircleList));
	memset(ret, 0, sizeof(TCircleList));
	ret->head.next = NULL;
	ret->len = 0;
	ret->slider = NULL;
	return ret;
}

void CircleList_Destroy(CircleList* list) {
	if (list != NULL) {
		free(list);
		list = NULL;
	}
	return;
}

void CircleList_Clear(CircleList* list) {
	TCircleList *slist = NULL;
	if (list == NULL) {
		return;
	}
	slist = (TCircleList*)list;
	slist->len = 0;
	slist->head.next = NULL;
	slist->slider = NULL;
	return;
}

int CircleList_Length(CircleList* list) {
	TCircleList *slist = NULL;
	if (list == NULL) {
		return -1;
	}
	slist = (TCircleList*)list;
	return slist->len;
}

int CircleList_Insert(CircleList* list, CircleListNode* node, int pos) {
	int ret = 0, i;
	TCircleList *slist = NULL;
	CircleListNode *current;
	if (list == NULL || node == 0 || pos < 0) {
		ret = 0;
		printf("func () err ret=%d\n", ret);
		return ret;
	}
	slist = (TCircleList*)list;
	current = (CircleListNode*)slist;
	for (i = 0; i < pos && (current->next != NULL); i++) {
		current = current->next;
	}
	node->next = current->next;
	current->next = node;
	//若第一次插入节点
	if (slist->len == 0) {
		slist->slider = node;
	}
	slist->len++;
	//若头插法，current仍然指向头部
	//原因是：跳0步  没有跳走
	if (current == (CircleListNode*)slist) {
		CircleListNode* last = CircleList_Get(slist, slist->len - 1);
		last->next = current->next;
	}
	return ret;
}

CircleListNode* CircleList_Get(CircleList* list, int pos) {
	int i;
	TCircleList *slist = NULL;
	CircleListNode *current;
	if (list == NULL || pos < 0) {
		printf("func CircleList_Get() err\n");
		return NULL;
	}
	slist = (TCircleList*)list;
	current = (CircleListNode*)slist;
	for (i = 0; i < pos && (current->next != NULL); i++) {
		current = current->next;
	}
	return current->next;
}

CircleListNode* CircleList_Delete(CircleList* list, int pos) {
	CircleListNode* ret;
	int i;
	TCircleList *slist = NULL;
	CircleListNode *current;
	if (list == NULL || pos < 0) {
		printf("func CircleList_Delete() err\n");
		return NULL;
	}
	slist = (TCircleList*)list;
	current = (CircleListNode*)slist;
	CircleListNode* last = NULL;
	for (i = 0; i < pos && (current->next != NULL); i++) {
		current = current->next;
	}
	//若删除第一个元素（头结点）
	if (current == ((CircleListNode*)slist)) {
		last=(CircleListNode*)CircleList_Get(slist,slist->len-1);
	}
	ret = current->next;
	current->next = current->next->next;
	slist->len--;

	//判断链表是否为空
	if (last != NULL) {
		slist->head.next = ret->next;
		last->next = ret->next;
	}

	//若删除的元素为游标所指的元素
	if (slist->slider == ret) {
		slist->slider = ret->next;
	}
	//若删除元素后，链表长度为0
	if (slist->len == 0) {
		slist->head.next = NULL;
		slist->slider = NULL;
	}
	return ret;
}

CircleListNode* CircleList_DeleteNode(CircleList* list, CircleListNode* node) {
	TCircleList* slist = (TCircleList*)list;
	CircleListNode* ret = NULL;
	int i = 0;

	if (slist != NULL) {
		CircleListNode* current = (CircleListNode*)slist;

		//查找node在循环链表中的位置i
		for (i = 0; i < slist->len; i++) {
			if (current->next == node) {
				ret = current->next;
				break;
			}
			current = current->next;
		}

		if (ret != NULL) {
			CircleList_Delete(slist, i);
		}
	}
	return ret;
}

CircleListNode* CircleList_Reset(CircleList* list) {
	TCircleList* slist = (TCircleList*)list;
	CircleListNode* ret = NULL;
	if (slist != NULL) {
		slist->slider = slist->head.next;
		ret = slist->slider;
	}
	return ret;
}

CircleListNode* CircleList_Currnet(CircleList* list) {
	TCircleList* slist = (TCircleList*)list;
	CircleListNode* ret = NULL;
	if (slist != NULL) {
		ret = slist->slider;
	}
	return ret;
}
//把当前位置返回，并且游标下移
CircleListNode* CircleList_Next(CircleList* list) {
	TCircleList* slist = (TCircleList*)list;
	CircleListNode* ret = NULL;
	if ((slist != NULL) && (slist->slider != NULL)){
		ret = slist->slider;
		slist->slider = ret->next;
	}
	return ret;
}