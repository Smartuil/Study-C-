#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "seqstack.h"
#include "seqlist.h"

//创建栈相当于创建线性表
SeqStack* SeqStack_Create(int capacity) {
	return SeqList_Create(capacity);
}
//销毁栈相当于销毁线性表
void SeqStack_Destory(SeqStack* stack) {
	SeqList_Destroy(stack);
}

void SeqStack_Clear(SeqStack* stack) {
	SeqList_Clear(stack);
}

int SeqStack_Push(SeqStack* stack, void* item) {
	return SeqList_Insert(stack, item, SeqList_Length(stack));//尾插
}

void* SeqStack_Pop(SeqStack* stack) {

	return SeqList_Delete(stack, SeqList_Length(stack) - 1);
}

void* SeqStack_Top(SeqStack* stack) {

	return SeqList_Get(stack, SeqList_Length(stack) - 1);
}

int SeqStack_Size(SeqStack* stack) {

	return SeqList_Length(stack);
}

int SeqStack_Capacity(SeqStack* stack) {

	return SeqList_Capacity(stack);
}




