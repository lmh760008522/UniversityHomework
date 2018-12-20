#include <stdio.h>
#include <stdlib.h>
#include<malloc.h>
#define list Node*
typedef struct Node
{
	int data;
    struct Node *next;
}Node;

Node *create()
{
    Node *p=NULL;
    int num;
    printf("请输入数据：\n");
    scanf("%d",&num);
	p=(Node*)malloc(sizeof(Node));
    p->data=num;
    p->next=NULL;
    return p;
}


Node* buildlist()
{
	Node *head=NULL,*p=NULL,*r=NULL;
    int num;
    printf("输入0开始\n");
    scanf("%d",&num);
    while(num==0)
    {
		p=create();
		if(head==NULL)
    	{
		head=p;
        r=head;
    	}
   		else 
    	{
		r->next=p;
        r=p;
    	}
    	scanf("%d",&num);
    }
    r->next=head;
    return head;
}

void print(Node *head)
{
	Node *p=head;
    while(head->next!=p)
    {
		printf("%d ",head->data);
        head=head->next;
    }
    printf("%d",head->data );
    printf("\n");
}

void release(list *head)
{
	Node *p=(*head)->next,*q;
	(*head)->next=NULL;
	while(p)
	{
		q=p;
		p=p->next;
		free(q); 
	}
	printf("ok");
}

int main()
{
	Node *a;	
    a=buildlist();
    print(a);
    release(&a);
    return 0;
    
}
