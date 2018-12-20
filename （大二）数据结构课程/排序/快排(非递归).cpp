#include <stdio.h>
#include <stdlib.h>
#include<malloc.h>
#include<time.h>
typedef int T;

typedef struct list{
	int size,maxlist;
	T data[10];
}List; 

typedef struct stack{
	int low;
	int high;
}Stack;
Stack st[10];

void QuickSort(List *list){
	int i,j,low,high,top=-1;
	int n=list->size;
	T temp;
	top++;//进栈
	st[top].low=0;
	st[top].high=n-1;
	while(top>-1){//栈非空，取出一个子文件进行划分 
		printf("d");
		low=st[top].low;
		high=st[top].high;
		top--;
		i=low;
		j=high;
		if(low<high){
			temp=list->data[low];
			while(i<j){
				while(i<j&&list->data[j]>temp){
					j--;
				}
				list->data[i]=list->data[j];
				while(i<j&&list->data[i]<temp){
					i++;
				}
				list->data[j]=temp;
				
			}
				top++;
				st[top].low=low;
				st[top].high=i-1;
				top++;
				st[top].low=i+1;
				st[top].high=high;
		}
	}
}

int main(){
	List ls;
	int i;
	srand(time(0));
	ls.size=6;
	ls.maxlist=10;
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
