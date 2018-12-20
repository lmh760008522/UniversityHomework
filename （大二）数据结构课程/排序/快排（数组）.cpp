#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef int T;

typedef struct list{
	int size,maxlist;
	T data[10];
}List; 

void Insertsort(List *list){
	int i,j;
	T x;
	for(i=1;i<list->size;i++){
		x=list->data[i];
		for(j=i-1;j>=0&&x<list->data[j];j--){
			list->data[j+1]=list->data[j];
		}
		list->data[j+1]=x;
	}
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
	Insertsort(&ls);
	for(i=0;i<ls.size;i++){
		printf("%d ",ls.data[i]);
	}
	return 0;
}
