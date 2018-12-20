#include<stdio.h>
#include <stdlib.h>
#include<malloc.h>
#include<ctype.h>
typedef struct Node
{
	int data;
    struct Node *next;
}Node;

typedef struct stack
{
	Node *top;
}stack;

Node *create(int c)
{
    Node *p=NULL;
	p=(Node*)malloc(sizeof(Node));
    p->data=c;
    p->next=NULL;
    return p;
}

void push(stack *s,int c)
{
	Node *p=create(c);
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

void realease(stack *s)
{
	while(s->top !=NULL)
	{
		pop(s);
	}
}

void stackfront(stack *s,int *x)
{
	Node *p=s->top ;
	if(s->top ==NULL)
	{
		printf("empty\n");
	}
	else
	{
		*x=p->data;
	}
}

void operate(stack *s,char c)
{
	double x,y;
	Node *p=s->top ;
	x=p->data ;
	pop(s);
	p=s->top ;
	y=p->data ;
	switch(c)
	{
		case'+':push(s,x+y);break;
		case'-':push(s,x-y);break;
		case'*':push(s,x*y);break;
		case'/':push(s,y/x);break;
	}
}

void calculate(char *exp)
{
	char c;
	int i,x=0;
	stack s;
	s.top =NULL;
	for(i=0;exp[i]!='#';i++)
	{
		c=exp[i];
		switch(c)
		{
			case'+':
			case'-':
			case'*':
			case'/':operate(&s,c);break;
			default:push(&s,c-'0');break;
		}
	}
	stackfront(&s,&x);
	printf("the result is:%d\n",x);
	realease(&s);
	print(&s);
}

int main()
{
	char exp[]={'6','4','2','-','/','3','2','*','+','#'};
	calculate(exp);
	return 0;
 } 
