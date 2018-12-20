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
    
    return head;
}
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

void release(list *head)
{
	Node *p=*head;
	while(*head)
	{
		p=(*head)->next;
		free(*head);
		*head=p;
	}
}

void *reverse(Node *head)
{
	Node *p1=NULL,*p2=NULL,*t=NULL;
	p1=head->next ;
	p2=p1->next;
	head->next=p2;
		p1->next=head;
		t=head;
		head=p1;
		p1=t;
	while(p2!=NULL)
	{
		p1->next=p2->next;
		p2->next=head;
		head=p2;
		p2=p1->next;
		
	}
	return head;
}

int main()
{
	Node *a;
	a=buildlist();
	print(a);
	a=reverse(a);
	print(a);
	return 0;
}

