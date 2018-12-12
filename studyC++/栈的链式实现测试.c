#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "linkstack.h"

void main() {
	int a[10];
	LinkStack* stack = NULL;
	stack = LinkStack_Create();
	if (stack == NULL) {
		return;
	}

	for (int i = 0; i < 5; i++) {
		a[i] = i + 1;
		LinkStack_Push(stack, &a[i]);
	}

	printf("Size:%d\n", LinkStack_Size(stack));
	printf("Top:%d\n", *((int *)LinkStack_Top(stack)));

	while (LinkStack_Size(stack) > 0) {
		printf("Pop:%d\n", *((int *)LinkStack_Pop(stack)));
	}
	LinkStack_Destory(stack);
}