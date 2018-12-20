#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef int T;
typedef struct node{
	T data;
	struct node *next;
}Node;
typedef struct list{
	Node *first;
	int size;
}List;


void print(Node *head)
{
	Node *p=NULL;
    p=head;
    while(p!=NULL)
    {
		printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

void insert(List *list)
{
	Node *p1=NULL,*p=NULL;
    p=(Node *)malloc(sizeof(Node));
    p->data=rand()%100+1;
    p->next=NULL;
    if(list->first==NULL){
    	list->first=p;
	}else{
		p1=list->first;
   		while(p1->next!=NULL){
    		p1=p1->next;
		}
		p1->next=p;
	}
}

void InsertSort(List *list){
	Node *unsorted,*sorted,*p,*q;
	if(list->first!=NULL){
		sorted=list->first;
		while(sorted->next!=NULL){
			unsorted=sorted->next;
			if(unsorted->data<list->first->data){
				sorted->next=unsorted->next;
				unsorted->next=list->first;
				list->first=unsorted;
			}
			else{
				q=list->first;
				p=q->next;
				while(unsorted->data>p->data){
					q=p;
					p=p->next;
				}
				if(unsorted==p){
					sorted=unsorted;
				}else{
					sorted->next=unsorted->next;
					unsorted->next=p;
					q->next=unsorted;
				}
			}
		}
	}
}

int main(){
	List ls;
	int i;
	ls.first=NULL;
	ls.size=6;
	srand(time(0));
	for(i=0;i<ls.size;i++){
		insert(&ls);
	}
	print(ls.first);
	InsertSort(&ls);
	print(ls.first);
	return 0;
}
