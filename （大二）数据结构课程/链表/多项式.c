#include <stdio.h>
#include <stdlib.h>
#include<malloc.h>
#define list Node*
typedef struct Node
{
	int data,x;
    struct Node *next;
}Node;

Node *create()
{
    Node *p=NULL;
    int data,x;
    printf("请输入数据：\n");
    scanf("%d %d",&data,&x);
	p=(Node*)malloc(sizeof(Node));
    p->data=data;
    p->x =x;
    p->next=NULL;
    return p;
}

Node* buildlist()
{
	Node *head=NULL,*p=NULL,*r=NULL;
    int num;
    printf("输入0开始和继续，非0结束\n");
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
		printf("%d x ^ %d ",p->data,p->x );
		if(p->next!=NULL)
		{
			printf("+");
		}
        p=p->next;
    }
    printf("\n");
}

Node * add(Node *a,Node *b)
{
	int i;
	Node *p=a,*q=b,*t;
	while(p!=NULL&&q!=NULL)
	{
		if(a->x ==b->x)
		{
			b->data +=a->data ;
		}
		else if(a->x>b->x)
		{
			t=p;
			p=p->next;
			while(p->x>b->x)
			{
				t=p;
				p=p->next ;
			}
			t->next=q;
			b=a;
			
		}
		else
		{
			p=p->next ;
		}
		q=q->next;
	}
	if(p!=NULL)
	{
		q->next=p;
	}
	return b;
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

Node *delete1(Node *head,int m)
{
	Node *p1=NULL,*p2=NULL;
	int count=1;
    p1=head;
    while(count++<m)
    {
    	p2=p1;
    	p1=p1->next ;
	}
	if(p1!=NULL)
	{
		if(p1==head)
		{
			head=p1->next;
		}
		else
		{
			p2->next =p1->next;
		}
		free(p1);
		printf("ok\n");
	}
	else
		printf(" no  data\n");
    return head;
}

int main()
{
	Node *a,*b;
	int x,y,z,t;
	printf("请输入a :\n");
    a=buildlist();
    print(a);
    printf("请输入b :\n");
    b=buildlist();
    print(b);
    b=add(a,b);
    print(b);
    release(&a);
    release(&b);
    return 0;
}
