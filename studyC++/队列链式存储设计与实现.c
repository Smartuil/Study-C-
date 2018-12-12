#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "linkqueue.h"

void main(){
	int a[10];
	LinkQueue* queue;
	queue = LinkQueue_Create();
	if (queue == NULL) {
		return;
	}

	for (int i = 0; i < 5; i++) {
		a[i] = i + 1;
		LinkQueue_Append(queue, &a[i]);
	}

	printf("len: %d\n", LinkQueue_Length(queue));
	printf("herder: %d\n", *((int*)LinkQueue_Header(queue)));
	
	while (LinkQueue_Length(queue) > 0) {
		int tmp;
		tmp = *((int*)LinkQueue_Rereieve(queue));
		printf("tmp: %d\n", tmp);
	}

		
}