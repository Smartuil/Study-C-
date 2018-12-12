#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "seqstack.h"

void main() {
	int a[10];
	SeqStack* stack = NULL;
	stack = SeqStack_Create(10);
	if (stack == NULL) {
		return;
	}

	for (int i = 0; i < 5; i++) {
		a[i] = i + 1;
		SeqStack_Push(stack, &a[i]);
	}

	printf("Capacity:%d\n", SeqStack_Capacity(stack));
	printf("Size:%d\n", SeqStack_Size(stack));
	printf("Top:%d\n", *((int *)SeqStack_Top(stack)));

	while (SeqStack_Size(stack) > 0) {
		printf("Pop:%d\n", *((int *)SeqStack_Pop(stack)));
	}
}