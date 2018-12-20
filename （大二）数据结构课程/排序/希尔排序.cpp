#include <stdio.h>
#include <stdlib.h>
#include<malloc.h>
#include<time.h>
typedef int T;

typedef struct list{
	int size,maxlist;
	T data[10];
}List; 

void InsSort(List *list,int h){
	int i,j;
	T x;
	for(i=h;i<list->size;i+=h){
		x=list->data[i];
		for(j=i-h;j>=0&&x<list->data[j];j-=h){
			list->data[j+h]=list->data[j];
		}
		list->data[j+h]=x;
	}
}
void ShellSort(List *list){
	int i,size=list->size;
	do{
		size=size/3+1;
		for(i=0;i<size;i++){
			InsSort(list,size);
		}
	}while(size>1);
}

int main(){
	List ls;
	int i;
	srand(time(0));
	ls.size=6;
	for(i=0;i<ls.size;i++){
		ls.data[i]=rand()%100+1;
	}
	for(i=0;i<ls.size;i++){
		printf("%d ",ls.data[i]);
	}
	putchar('\n');
	ShellSort(&ls);
	for(i=0;i<ls.size;i++){
		printf("%d ",ls.data[i]);
	}
	return 0;
}
