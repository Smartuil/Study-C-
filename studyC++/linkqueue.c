
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "linkqueue.h"
#include "linklist.h"

typedef struct _tag_LinkQueueNode 
{
	LinkListNode node;
	void* item;
}TLinkQueueNode;

LinkQueue* LinkQueue_Create() {
	return LinkList_Create();
}

void LinkQueue_Destroy(LinkQueue* queue) {
	LinkQueue_Clear(queue);
	LinkList_Destroy(queue);
	return ;
}

void LinkQueue_Clear(LinkQueue* queue) {
	while (LinkQueue_Length(queue) > 0) {
		LinkQueue_Rereieve(queue);
	}
	LinkList_Clear(queue);
	return ;
}

int LinkQueue_Append(LinkQueue* queue, void *item) {
	//需要把栈的item（栈的业务节点）转化成链表的LinkListNode
	int ret = 0;
	TLinkQueueNode *tmp = NULL;
	tmp = (TLinkQueueNode*)malloc(sizeof(TLinkQueueNode));
	if (tmp == NULL) {
		ret = -1;
		printf("func LinkQueue_Append() err ret=%d\n", ret);
		return ret;
	}
	memset(tmp, 0, sizeof(TLinkQueueNode));
	tmp->item = item;
	ret = LinkList_Insert(queue, (LinkListNode*)tmp, LinkList_Length(queue));
	if (ret != 0) {
		ret = 3;
		printf("LinkList_Insert() err ret=%d\n", ret);
		if (tmp != NULL) {
			free(tmp);
		}
		return ret;
	}
	return 0;
}

void* LinkQueue_Rereieve(LinkQueue* queue) {
	TLinkQueueNode* tmp = NULL;
	void *ret = NULL;
	tmp = (TLinkQueueNode*)LinkList_Delete(queue, 0);
	if (tmp == NULL) {
		printf("func LinkList_Delete() err");
		return NULL;
	}
	ret = tmp->item;
	if (tmp != NULL) {
		free(tmp);
	}
	return ret;
}

void* LinkQueue_Header(LinkQueue* queue) {
	TLinkQueueNode* tmp = NULL;
	void *ret = NULL;
	tmp = (TLinkQueueNode*)LinkList_Get(queue, 0);
	if (tmp == NULL) {
		printf("func LinkList_Get() err");
		return NULL;
	}
	return tmp->item;
}

int LinkQueue_Length(LinkQueue* queue) {
	return LinkList_Length(queue);
}
