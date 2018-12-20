#include<stdio.h>
typedef struct stack
{
	int top,maxstack;
	int elements[50];
 }stack;
 
 void create(stack *s,int max)
 {
 	s->top=-1;
 	s->maxstack =max;
 }
 
 void push(stack *s,int x)
 {
 	s->elements [++s->top ]=x;
 }
 
 void pop(stack *s)
 {
 	if(s->top<0)
 	{
 		printf("empty\n");
	 }
	 else
	 {
	 	s->top--;
	 }
 }
 void print(stack *s)
 {
 	for(s->top =0;(s->top )<(2 );(s->top )++)
 	{
 		printf("%d ",s->elements[s->top ]);
	 }
 }
 
 int main()
 {
 	stack s;
 	int x;
 	create(&s,10);
 	push(&s,10);
 	push(&s,15);
 	print(&s);
 	return 0;
 }
