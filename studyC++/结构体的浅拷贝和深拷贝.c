
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Teacher{
	char name[64];
	int age;
	char *bieming;
}Teacher; 

//�������ĵȺŲ���ֻ���ָ��ı�����ֵ��from��copy��to���������ָ�������ָ����ڴ�ռ����copy��ȥ��    ǳ����
//�ṹ������һ��һ�������ָ�� 
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