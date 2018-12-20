#include <stdio.h>
#include <stdlib.h>
#include<malloc.h>
#include<time.h>
typedef int T;

typedef struct list{
	int size,maxlist;
	T data[10];
}List; 

void BubbleSort(List *list){
	int i,j,last=0;
	T temp;
	i=list->size-1;
	while(i>0){
		for(j=0;j<i;j++){
			if(list->data[j+1]<list->data[j]){
				temp=list->data[j+1];
				list->data[j+1]=list->data[j];
				list->data[j]=temp;
				
				last=j;
			}
		}
		i=last;
		
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
	BubbleSort(&ls);
	for(i=0;i<ls.size;i++){
		printf("%d ",ls.data[i]);
	}
	return 0;
}
