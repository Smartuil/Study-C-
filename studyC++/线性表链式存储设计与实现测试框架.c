#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "linklist.h"


typedef struct Teacher {
	LinkListNode node;
	char name[64];
	int age;
}Teacher;

void main(){
	int len = 0, ret = 0, i;
	LinkList* list = NULL;
	Teacher t1, t2, t3, t4;
	t1.age = 21;
	t2.age = 22;
	t3.age = 23;
	t4.age = 24;
	list = LinkList_Create();
	if (list == NULL) {
		return;
	}

	len = LinkList_Length(list);

	ret = LinkList_Insert(list, (LinkListNode*)&t1, 0);
	ret = LinkList_Insert(list, (LinkListNode*)&t2, 0);
	ret = LinkList_Insert(list, (LinkListNode*)&t3, 0);
	ret = LinkList_Insert(list, (LinkListNode*)&t4, 0);

	for (i = 0; i < LinkList_Length(list); i++) {
		Teacher *t = (Teacher *)LinkList_Get(list, i);
		if (t == NULL) {
			return;
		}
		printf("t->age:%d\t", t->age);
	}


	while (LinkList_Length(list) > 0) {
		Teacher *t = (Teacher *)LinkList_Delete(list, 0);
		if (t == NULL) {
			return;
		}
		printf("t->age:%d\t", t->age);
	}

	LinkList_Destroy(list);
}