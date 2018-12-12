#include "linklist.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _tag_LinkList {
	LinkListNode head;
	int len;
}TLinkList;

LinkList* LinkList_Create() {
	TLinkList *ret = NULL;
	ret = (TLinkList*)malloc(sizeof(TLinkList));
	memset(ret, 0, sizeof(TLinkList));
	ret->head.next = NULL;
	ret->len = 0;

	return ret;
}

void LinkList_Destroy(LinkList* list) {
	if (list != NULL) {
		free(list);
		list = NULL;
	}
	return;
}

void LinkList_Clear(LinkList* list) {
	TLinkList *tlist = NULL;
	if (list == NULL) {
		return;
	}
	tlist = (TLinkList*)list;
	tlist->len = 0;
	tlist->head.next = NULL;
	return;
}

int LinkList_Length(LinkList* list) {
	TLinkList *tlist = NULL;
	if (list == NULL) {
		return -1;
	}
	tlist = (TLinkList*)list;
	return tlist->len;
}

int LinkList_Insert(LinkList* list, LinkListNode* node, int pos) {
	int ret = 0, i;
	TLinkList *tlist = NULL;
	LinkListNode *current;
	if (list == NULL || node == 0 || pos < 0) {
		ret = 0;
		printf("func () err ret=%d\n", ret);
		return ret;
	}
	tlist = (TLinkList*)list;
	current = &(tlist->head);
	for (i = 0; i < pos && (current->next!=NULL); i++) {
		current = current->next;
	}
	node->next = current->next;
	current->next = node;
	tlist->len++;
	return 0;
}

LinkListNode* LinkList_Get(LinkList* list, int pos) {
	int i;
	TLinkList *tlist = NULL;
	LinkListNode *current;
	if (list == NULL || pos < 0) {
		printf("func LinkList_Get() err\n");
		return NULL;
	}
	tlist = (TLinkList*)list;
	current = &(tlist->head);
	for (i = 0; i < pos && (current->next != NULL); i++) {
		current = current->next;
	}
	return current->next;
}

LinkListNode* LinkList_Delete(LinkList* list, int pos) {
	LinkListNode* ret;
	int i;
	TLinkList *tlist = NULL;
	LinkListNode *current;
	if (list == NULL || pos < 0) {
		printf("func LinkList_Delete() err\n");
		return NULL;
	}
	tlist = (TLinkList*)list;
	current = &(tlist->head);
	for (i = 0; i < pos && (current->next != NULL); i++) {
		current = current->next;
	}
	ret = current->next;
	current->next = current->next->next;
	tlist->len--;
	return ret;
}