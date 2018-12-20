#include<stdio.h>
#include <stdlib.h>
#include<malloc.h>
#include<ctype.h>
typedef struct Node
{
	char data;
    struct Node *next;
}Node;

typedef struct stack
{
	Node *top;
}stack;

Node *create(char c)
{
    Node *p=NULL;
	p=(Node*)malloc(sizeof(Node));
    p->data=c;
    p->next=NULL;
    return p;
}

void push(stack *s,char c)
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
		printf("%c ",p->data);
        p=p->next;
    }
    printf("\n");
}

void stackfront(stack *s,char *x)
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

int isp(char c)
{
	int priority;
	switch(c)
	{
		case'(':priority=0;break;
		case'+':
		case'-':priority=5;break;
		case'*':
		case'/':priority=6;break;
		case'#':priority=0;break;
	}
	return priority;
}

int icp(char c)
{
	int priority;
	switch(c)
	{
		case'(':priority=8;break;
		case'+':
		case'-':priority=5;break;
		case'*':
		case'/':priority=6;break;
		case'#':priority=0;break;
	}
	return priority;
}

void realease(stack *s)
{
	while(s->top !=NULL)
	{
		pop(s);
	}
}

void reverse(char *exp)
{
	stack s;
	s.top =NULL;
	int i;
	char ch,x='?';
	push(&s,'#');
	printf("the expression is:\n");
	for(i=0;exp[i]!='#';i++)
	{
		ch=exp[i];
		if(isdigit(ch)||isalpha(ch))
		{
			printf("%c ",ch);
		} 
		else if(ch==')')
		{
			stackfront(&s,&x);
			while(x!='(')
			{
				printf("%c ",x);
				pop(&s);
				stackfront(&s,&x);
			}
			pop(&s);
		}
		else
		{
			stackfront(&s,&x);
			while(icp(ch)<=isp(x))
			{
				printf("%c ",x); 
				pop(&s); 
				stackfront(&s,&x);
			}
			push(&s,ch);
		}
	}
	stackfront(&s,&x);
	while(x!='#')
	{
		printf("%c ",x);
		pop(&s);
		stackfront(&s,&x);
	}
	realease(&s);
	print(&s);
}

int main()
{
	char exp[]={'a','/','(','b','-','c',')','+','d','*','e','#'};
	reverse(exp);
	return 0;
}
