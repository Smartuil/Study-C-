#include <stdio.h>
#include "seqlist.h"

typedef struct Teacher {
	char name[32];
	int age;
}Teacher;

void main(){
	int ret = 0;
	SeqList* list = NULL;
	Teacher t1, t2, t3, t4, t5;
	t1.age = 21;
	t2.age = 22;
	t3.age = 23;
	t4.age = 24;
	t5.age = 25;

	list = SeqList_Create(10);
	if (list == NULL) {
		printf("func SeqList_Create() err");
		return;
	}

	ret = SeqList_Insert(list, (SeqListNode*)&t1, 0);
	ret = SeqList_Insert(list, (SeqListNode*)&t2, 0);
	ret = SeqList_Insert(list, (SeqListNode*)&t3, 0);
	ret = SeqList_Insert(list, (SeqListNode*)&t4, 0);
	ret = SeqList_Insert(list, (SeqListNode*)&t5, 0);

	for (int i = 0; i < SeqList_Length(list); i++) {
		Teacher* t = (Teacher*)SeqList_Get(list, i);
		if (t == NULL) {
			return;
		}
		printf("t->age:%d\t", t->age);
	}

	while (SeqList_Length(list) > 0) {
		SeqList_Delete(list, 0);
	}
}