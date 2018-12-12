
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sort(char **myp1/*in*/,int num1,char(*myp2)[30],int num2,char ***myp3,int *num3){
	int tmplen;
	int i,j,k;
	char *tmp;
	char **p3=NULL;
	p3=(char **) malloc((num1+num2) * sizeof(char *));//里面装的是指针 
	
	if(p3==NULL){
		return -1;
	} 
	
	
	for(i=0;i<num1;i++){
		tmplen=strlen(myp1[i])+1;
		p3[i]=(char *)malloc(tmplen*sizeof(char));
		if(p3[i]==NULL){
			return -2;
		}
		strcpy(p3[i],myp1[i]);
	} 
	
	for(j=0;j<num2;j++,i++){
		tmplen=strlen(myp2[j])+1;
		p3[i]=(char *)malloc(tmplen * sizeof(char ));
		if(p3[i]==NULL){
			return -3;
		}
		strcpy(p3[i],myp2[j]);
	}
	
	tmplen=num1+num2;
	
	//排序
	
	 for(i=0;i<tmplen;i++){
	 	for(j=i+1;j<tmplen;j++){
	 		if(strcmp(p3[i],p3[j])> 0 ){
	 			tmp=p3[i];
				 p3[i]=p3[j];
				 p3[j]=tmp;
			}
		 }
	 }
	 
	 
	 //间接赋值
	 
	 *num3=tmplen;
	 *myp3=p3;
	 
	  
	return 0;
}


void sortFree(char **p,int len){
	if(p==NULL){
		return ;
	}
	
	for(int i=0;i<len;i++)
		free(p[i]); 
	free(p);
}

void sortFree01(char ***myp,int len){//把二级指针指向二维内存释放掉，同时间接修改了实参的值 
	char **p=NULL;
	if(myp==NULL){
		return ;
	}
	p=*myp;//还原成二级指针 
	if(p==NULL){
		return ;
	}
	for(int i=0;i<len;i++)
		free(p[i]); 
	free(p);
	//myp是实参的地址 
	*myp=NULL;//间接赋值时指针存在的最大意义 
}


int main() {
	char *p1[]={"aaa","bbb","ccc"};
	char buf2[10][30]={"111","333","222"};
	char **p3=NULL;
	int len1,len2,len3;
	int ret;
	
	len1=sizeof(p1)/sizeof(*p1);
	len2=3;
	
	ret=sort(p1,len1,buf2,len2,&p3,&len3);
	if(ret!=0){
		printf("func sort() err:%d",ret);
		return ret;
	}
	for(int i=0;i<len3;i++){
		printf("%s\n",p3[i]);
	}
	return 0;
}