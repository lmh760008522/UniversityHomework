#include <stdio.h>
#include <stdlib.h>
#include<malloc.h>
typedef struct Node
{
	int data;
    struct Node *next;
}Node;

typedef struct stack
{
	Node *top;
}stack;


Node *create()
{
    Node *p=NULL;
    int num;
    printf("ÇëÊäÈëÊý¾Ý£º\n");
    scanf("%d",&num);
	p=(Node*)malloc(sizeof(Node));
    p->data=num;
    p->next=NULL;
    return p;
}

void push(stack *s)
{
	Node *p=create();
	p->next = s->top;
	s->top=p;
}

void pop(stack *s)
{
	Node *p=s->top;
	s->top=p->next;
	free(p);
}

void print(stack *s)
{
	Node *p=NULL;
    p=s->top;
    while(p!=NULL)
    {
		printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

int main()
 {
 	stack s;
 	push(&s);
 	print(&s);
 	push(&s);
 	print(&s);
 	push(&s);
 	print(&s);
 	pop(&s);
 	print(&s);
	pop(&s);
 	print(&s);
	pop(&s);
 	print(&s);
 	return 0;
 }
