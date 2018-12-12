#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "seqqueue.h"

void main(){
	int a[10];
	SeqQueue* queue = NULL;
	queue = SeqQueue_Create(10);
	if (queue == NULL) {
		return;
	}
	for (int i = 0; i < 5; i++) {
		a[i] = i + 1;
		SeqQueue_Append(queue, (void*) &a[i]);
	}

	printf("len: %d\n", SeqQueue_Length(queue));
	printf("head: %d\n", *((int *)SeqQueue_Header(queue)));
	printf("capacity: %d\n", SeqQueue_Capaticy(queue));

	while (SeqQueue_Length(queue) > 0) {
		int tmp = *((int *)SeqQueue_Retrieve(queue));
		printf("tmp: %d\n", tmp);
	}
	SeqQueue_Destroy(queue);
}