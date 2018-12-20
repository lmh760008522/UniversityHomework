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

Node *copy(Node *head) 
{
	Node *p1=NULL,*p2=NULL,*h=NULL,*t;
	t=head;
	while(t!=NULL)
	{
		p2=(Node*)malloc(sizeof(Node));
		p2->data=t->data ;
		p2->next=NULL;
		if(h==NULL)
		{
			h=p2;
			p1=h;
		}
		else
		{
			p1->next=p2;
			p1=p1->next;
		}
		t=t->next ;
	}
	return h;
	
}

int main()
{
	Node *a,*b;
	a=buildlist();
    print(a);
    b=copy(a);
    print(b);
    release(&a);
    release(&b);
    return 0;
	
}
