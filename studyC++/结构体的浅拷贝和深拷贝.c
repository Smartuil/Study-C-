
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Teacher{
	char name[64];
	int age;
	char *bieming;
}Teacher; 

//编译器的等号操作只会把指针的变量的值从from从copy到to，但不会把指针变量所指向的内存空间给从copy过去，    浅拷贝
//结构体中套一个一级或二级指针 
void copyTeacher(Teacher *to,Teacher *from){
	*to=*from;
	
	to->bieming=(char *)malloc(100);
	strcpy(to->bieming,from->bieming);
	
	//memcpy(to,from,sizeof(Teacher));
}


int main() {
	Teacher t1;
	Teacher t2;
	
	strcpy(t1.name,"name1");
	
	
	copyTeacher(&t1,&t2);
	
	
	t1.bieming=(char *)malloc(100); 
	strcpy(t1.bieming,"ss");
	
	if(t1.bieming!=NULL){
		free(t1.bieming);
		t1.bieming=NULL;
	}


	
	if(t2.bieming!=NULL){
		free(t2.bieming);
		t2.bieming=NULL;
	}
	
	
	return 0;
}