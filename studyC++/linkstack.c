#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "linkstack.h"
#include "linklist.h"

typedef struct _tag_LinkStackNode {
	LinkListNode node;
	void* item;
}TLinkStackNode;


//创建栈相当于创建线性表
LinkStack* LinkStack_Create() {
	return LinkList_Create();
}
//销毁栈相当于销毁线性表
void LinkStack_Destory(LinkStack* stack) {
	LinkStack_Clear(stack);
	LinkList_Destroy(stack);
}

void LinkStack_Clear(LinkStack* stack) {
	if (stack == NULL) {
		return;
	}
	while (LinkStack_Size(stack) > 0) {
		LinkStack_Pop(stack);
	}
}

//void* item栈的业务节点------------>转化成  链表的业务节点
int LinkStack_Push(LinkStack* stack, void* item) {
	TLinkStackNode *tmp = NULL;
	int ret = 0;
	tmp = (TLinkStackNode*)malloc(sizeof(TLinkStackNode));
	if (tmp == NULL) {
		return -1;
	}
	memset(tmp, 0, sizeof(TLinkStackNode));
	tmp->item = item;
	ret = LinkList_Insert(stack, (LinkListNode*) tmp, 0);
	if (ret != 0) {
		printf("func LinkList_Insert() err ret=%d\n", ret);
		if (tmp != NULL) {
			free(tmp);
		}
	}
	return ret;
}

void* LinkStack_Pop(LinkStack* stack) {
	TLinkStackNode *tmp = NULL;
	void* item;
	tmp = (TLinkStackNode* )LinkList_Delete(stack, 0);
	if (tmp == NULL) {
		return NULL;
	}
	item = tmp->item;
	free(tmp);
	return item;
}

void* LinkStack_Top(LinkStack* stack) {
	TLinkStackNode *tmp = NULL;
	void* item;
	tmp = (TLinkStackNode *)LinkList_Get(stack, 0);
	if (tmp == NULL) {
		return NULL;
	}
	item = tmp->item;
	return item;
}

int LinkStack_Size(LinkStack* stack) {

	return LinkList_Length(stack);
}




