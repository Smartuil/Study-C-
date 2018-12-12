#include "seqlist.h"
#include <stdio.h>
#include "malloc.h"
#include "string.h"



typedef struct _tag_SeqList {
	int len;
	int capacity;
	unsigned int **node;
}TSeqList;


SeqList* SeqList_Create(int capacity) {
	int ret = 0;
	TSeqList* tmp = NULL;
	tmp = (TSeqList*)malloc(sizeof(TSeqList));
	if (tmp == NULL) {
		ret = -1;
		printf("func SeqList_Create() err:%d", ret);
		return NULL;
	}
	memset(tmp, 0, sizeof(TSeqList));
	tmp->node = (unsigned int **)malloc(sizeof(unsigned int*)*capacity);
	if (tmp->node == NULL) {
		ret = -2;
		printf("func SeqList_Create()  malloc err:%d", ret);
		return NULL;
	}

	tmp->capacity = capacity;
	tmp->len = 0;
	return tmp;
}

void SeqList_Destroy(SeqList* list) {
	TSeqList *tlist = NULL;
	if (list == NULL) {
		return ;
	}
	tlist = (TSeqList*)list;
	if (tlist->node != NULL) {
		free (tlist->node);
	}
	free(tlist);
	return ;
}

void SeqList_Clear(SeqList* list) {
	TSeqList *tlist = NULL;
	if (list == NULL) {
		return ;
	}
	tlist = (TSeqList*)list;
	tlist->len = 0;//回到初始化状态
	return ;
}

int SeqList_Length(SeqList* list) {
	TSeqList *tlist = NULL;
	if (list == NULL) {
		return -1;
	}
	tlist = (TSeqList*)list;
	return tlist->len;
}

int SeqList_Capacity(SeqList* list) {
	TSeqList *tlist = NULL;
	if (list == NULL) {
		return -1;
	}
	tlist = (TSeqList*)list;
	return tlist->capacity;
}

int SeqList_Insert(SeqList* list, SeqListNode* node, int pos) {
	TSeqList *tlist = NULL;
	int i ,ret = 0;
	if (list == NULL || node == NULL || pos < 0) {
		ret = -1;
		printf("func SeqList_Insert err,ret = %d\n", ret);
		return ret;
	}
	tlist = (TSeqList*)list;
	if (tlist->len >= tlist->capacity) {
		ret = -2;
		printf("func SeqList_Insert (tlist->len >= tlist->capacity) err,ret = %d\n", ret);
		return ret;
	}
	//容错修正
	if (pos >= tlist->len) {
		pos = tlist->len;
	}

	for (i = tlist->len; i > pos; i--) {
		tlist->node[i] = tlist->node[i - 1];
	}

	tlist->node[i] = node;
	tlist->len++;
	return 0;
}

SeqListNode* SeqList_Get(SeqList* list, int pos) {
	TSeqList *tlist = NULL;
	SeqListNode* ret = 0;
	if (list == NULL ||  pos < 0) {
		printf("func SeqList_Insert err\n");
		return NULL;
	}
	tlist = (TSeqList*)list;
	ret = (void *)tlist->node[pos];
	return ret;
}

SeqListNode* SeqList_Delete(SeqList* list, int pos) {
	TSeqList *tlist = NULL;
	SeqListNode* ret = 0;
	int i;
	if (list == NULL || pos < 0) {
		printf("func SeqList_Insert err\n");
		return NULL;
	}
	tlist = (TSeqList*)list;
	ret = (SeqListNode*)tlist->node[pos];
	for (i = pos + 1; i < tlist->len; i++) {
		tlist->node[i - 1] = tlist->node[i];
	}
	tlist->len--;
	return ret;
}