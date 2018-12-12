
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Teacher {
	char name[64];
	char *bieming; 
	char **stuname;
	int age;
	int id;
}Teacher;

void printTeacher(Teacher *array, int num) {
	int i = 0;
	for (i = 0; i < num; i++) {
		printf("age%d\n", array[i].age);
	}
}

void sort(Teacher *array, int num) {
	int i, j;
	Teacher tmp;
	for (i = 0; i < num; i++) {
		for (j = i+1; j < num; j++) {
			if (array[i].age > array[j].age) {
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
		}
	}
}



void main1() {

	Teacher Array[3];

	for (int i = 0; i < 3; i++) {
		printf("请输入老师的年龄:");
		scanf("%d", &(Array[i].age));
	}

	printTeacher(Array, 3);
	sort(Array, 3);
	printTeacher(Array, 3);

	system("pause");
	return;
}
Teacher *createTeacher01(int num) {
	Teacher *tmp = NULL;
	tmp = (Teacher *)malloc(sizeof(Teacher)*num);
	if (tmp == NULL)
		return NULL;

}   

int createTeacher02(Teacher **pt,int num) {
	Teacher *tmp = NULL;
	tmp = (Teacher *)malloc(sizeof(Teacher)*num);
	if (tmp == NULL)
		return -1;
		
	*pt=tmp;//二级指针形参去简介的修改实参的值 
	memset(tmp,0,sizeof(Teacher)*3);
	for(int i=0;i<3;i++){
		
		char **p=NULL;
		tmp[i].bieming=(char *)malloc(60);
		
			p=(char **)malloc(3*sizeof(char *));//打造二维内存 
			for(int j=0;j<3;j++){
				p[j]=(char *)malloc(120);
			}
			tmp[i].stuname=p;
	}

	return 0;

}  

void FreeTeacher(Teacher *p,int num) {
	if (p == NULL)
		return;
		
	for(int i=0;i<num;i++){
		if(p[i].bieming!=NULL)
			free(p->bieming);
			
		if(p[i].stuname!=NULL){ 
			char **myp=p[i].stuname;
			for(int j=0;j<3;j++){
				
				if(myp[j]!=NULL){
					free(myp[j]);
				}
			}
			free(myp);
			p[i].stuname=NULL;
		}
	}
	free(p);

}

int main() {
	int ret =0;

	Teacher *pArray = NULL;
	ret= createTeacher02(&pArray,3);
	if(ret!=0){
		printf("error\n");
	}

	for (int i = 0; i < 3; i++) {
//		printf("请输入老师的年龄:");
//		scanf("%d", &(pArray[i].age));
//		
//		printf("请输别名:");
//		scanf("%s", (pArray[i].bieming));
		for(int j=0;j<3;j++){
			printf("输入学生姓名");
			scanf("%s",pArray[i].stuname[j]);
		} 
	}

	printTeacher(pArray, 3);
	sort(pArray, 3);
	printTeacher(pArray, 3);
	FreeTeacher(pArray,3);
	system("pause");
	return 0;
}