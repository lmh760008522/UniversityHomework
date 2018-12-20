#include <stdio.h>
#include <stdlib.h>
#include<malloc.h>
#define list Node*
typedef struct Node
{
	int data;
    struct Node *next;
}Node;

typedef struct queue
{
	Node *front,*rear;
 } queue;
 
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

int isempty(queue *q)
{
	if(q->front==NULL)
		return 1;
	else 
		return 0;
}

queue *append(queue *q)
{
	Node *p;
	p=create();
	if(q->front ==NULL)
	{
		q->front =p;
		q->rear =p; 
	}
	else
	{
		q->rear->next=p;
		q->rear=p;
	}
	return q;
}

queue *pop(queue *q)
{
	Node *p;
	if(isempty(q))
	{
		printf("empty\n");
	}
	else
	{
		p=q->front ;
		q->front =p->next ;
		free(p);
	}
}

void queuefront(queue *q,int *x)
{
	Node *p=q->front ;
	if(isempty(q))
	{
		printf("empty\n");
	}
	else
	{
		*x=p->data;
	}
}

void print(queue *q)
{
	Node *p=q->front ;
	if(isempty(q))
	{
		printf("empty\n");
	}
	else
	{
		while(p!=q->rear )
		{
			printf("%d ",p->data);
			p=p->next ;
		}
		printf("%d\n",p->data );
	}
}

int main()
{
	queue q;
	int a;
	q.front =NULL;
	q.rear =NULL;
	printf("0开始和继续，非0结束\n");
	
	while(!a)
	{
		append(&q);
		scanf("%d",&a);
	}
	print(&q);
	pop(&q);
	print(&q);
	return 0;
}
