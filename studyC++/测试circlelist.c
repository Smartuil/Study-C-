#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "circlelist.h"


typedef struct Value {
	CircleListNode circlenode;
	int v;
}Value;
void main(){
	CircleList* list = CircleList_Create();

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

	CircleList_Insert(list, (CircleListNode*)&v1, 0);
	CircleList_Insert(list, (CircleListNode*)&v2, 0);
	CircleList_Insert(list, (CircleListNode*)&v3, 0);
	CircleList_Insert(list, (CircleListNode*)&v4, 0);

	for (i = 0; i < 2 * CircleList_Length(list); i++) {
		Value* pv = (Value*)CircleList_Get(list, i);
		printf("%d\n", pv->v);
	}

	while (CircleList_Length(list) > 0) {
		CircleList_Delete(list, 0);
	}
	CircleList_Destroy(list);
}
