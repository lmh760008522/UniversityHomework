#include <stdio.h>
#include <stdlib.h>
#include<malloc.h>
#include<time.h>
typedef int T;

typedef struct list{
	int size,maxlist;
	T data[10];
}List; 

int Partiton(List *list,int left,int right){
	int i=left,j=right+1;
	T pivot,temp;
	pivot=list->data[left];
	do{
		do{
			i++;
		}while(list->data[i]<pivot);
		do{
			j--;
		}while(list->data[j]>pivot);
		if(i<j){
			temp=list->data[j];
				list->data[j]=list->data[i];
				list->data[i]=temp;
		}
	}while(i<j);
	temp=list->data[j];
	list->data[j]=list->data[left];
	list->data[left]=temp;
	return j;
}
void QSort(List *list,int left,int right){
	int k;
	if(left<right){
		k=Partiton(list,left,right);
		QSort(list,left,k-1);
		QSort(list,k+1,right);
	}
}
void QuickSort(List *list){
	QSort(list,0,list->size-1);
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
	QuickSort(&ls);
	for(i=0;i<ls.size;i++){
		printf("%d ",ls.data[i]);
	}
	return 0;
}
