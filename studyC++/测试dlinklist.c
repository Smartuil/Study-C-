#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "DLinklist.h"


typedef struct Value {
	DLinkListNode DLinknode;
	int v;
}Value;
void main() {
	DLinkList* list = DLinkList_Create();

	Value v1, v2, v3, v4, v5, v6, v7, v8;
	int i = 0;
	v1.v = 1;
	v2.v = 2;
	v3.v = 3;
	v4.v = 4;
	v5.v = 5;
	v6.v = 6;
	v7.v = 7;
	v8.v = 8;

	DLinkList_Insert(list, (DLinkListNode*)&v1, DLinkList_Length(list));
	DLinkList_Insert(list, (DLinkListNode*)&v2, DLinkList_Length(list));
	DLinkList_Insert(list, (DLinkListNode*)&v3, DLinkList_Length(list));
	DLinkList_Insert(list, (DLinkListNode*)&v4, DLinkList_Length(list));
	DLinkList_Insert(list, (DLinkListNode*)&v5, DLinkList_Length(list));

	for (i = 0; i < 2 * DLinkList_Length(list); i++) {
		Value* pv = (Value*)DLinkList_Get(list, i);
		printf("%d\n", pv->v);
	}

	DLinkList_Delete(list, DLinkList_Length(list)-1);
	DLinkList_Delete(list, 0);
	printf("\n");
	for (i = 0; i < DLinkList_Length(list); i++) {
		Value* pv = (Value*)DLinkList_Next(list);
		printf("%d\n", pv->v);
	}

	DLinkList_Reset(list);
	DLinkList_Next(list);
	printf("\n");
	Value* pv = (Value*)DLinkList_Next(list);
	printf("%d\n", pv->v);

	DLinkList_Destroy(list);
}
