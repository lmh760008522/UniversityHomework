#include <stdio.h>
#include <stdlib.h>
#include<malloc.h>
typedef struct Node
{
	int data;
    struct Node *next;
}Node;

typedef struct list
{
	Node *frist;
	int size;
}list;

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

list* buildlist()
{
	Node *head=NULL,*p=NULL,*r=NULL;
	list *a;
	a->frist =NULL;
	a->size =0;
    int num;
    printf("输入0开始和继续，非0结束\n");
    scanf("%d",&num);
    while(num==0)
    {
		a->size ++;
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
    a->frist->next=head;
    return a;
}
void print(list *head)
{
	Node *p=NULL;
    p=head->frist ->next;
    while(p!=NULL)
    {
		printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

list* move(list *a,int x)
{
	Node *p1=a->frist ,*p2;
	int count=1;
	if(a->size<=0)
	{
		printf("no data\n");
	}
	else
	{
		while(count++<x)
    	{
    		p2=p1;
    		p1=p1->next ;
		}
		if(p1==a->frist)
		{
			a->frist =p1->next;
		}
		else
		{
			p2->next =p1->next;
		}
		free(p1);
		a->size --;
		printf("ok\n");
	}
	return a;
}
void release(list *a)
{
	while(a->size >0)
	{
		move(a,a->size);
	}
}

list *insert(list *head,int num)
{
	
	Node *p1=NULL,*p2=NULL,*p=NULL;
	int x;
	if(head->size ++<=20)
	{
    p=(Node *)malloc(sizeof(Node));
    printf("你的数据是？\n"); 
    scanf("%d",&x);
    p->data=x;
    p->next=NULL;
    p1=head->frist ;
    while(p1->data<num)
    {
		p2=p1;
        p1=p1->next;
    }
    if(p1==head->frist )
    {
		p->next=p1;
        head->frist =p;
    }
    else
	{
		p2->next=p;
        p->next=p1;
    }
	}
    return head;
}

int main()
{
	list *a;
	int x,y;	
    a=buildlist();
    print(a);
    printf("插在哪个数据前？\n");
    scanf("%d",&x);
    a=insert(a,x);
    print(a);
	printf("删除第几个数据？\n");
    scanf("%d",&y);
    a=move(a,y);
    print(a);
    release(a);
    return 0;
    
}
