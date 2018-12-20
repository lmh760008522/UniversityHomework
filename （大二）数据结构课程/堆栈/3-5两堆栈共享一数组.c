#include<stdio.h>
typedef struct stack
{
	int top,maxstack;
 }stack;
 
 void push1(stack *s1,stack *s2,int x,int *a)
 {
 	if(s1->top+1<s2->top)
		a [++s1->top ]=x;
	else 
		printf("full\n");
 }
void push2(stack *s1,stack *s2,int x,int *a)
 {
 	if(s1->top+1<s2->top)
		a [--s2->top ]=x;
	else 
		printf("full\n");
 }
 
 void pop1(stack *s)
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
 void pop2(stack *s)
 {
	if(s->top>9)
 	{
 		printf("empty\n");
	 }
	 else
	 {
	 	s->top++;
	 }
 }
 void print1(stack *s,int *a)
 {
 	int count;
	 for(count=0;(s->top)>=count;count++)
 	{
 		printf("%d ",a[count ]);
	 }
	 printf("\n");
 }
 
  void print2(stack *s,int *a)
 {
 	int count;
	 for(count=9;(s->top)<=count;count--)
 	{
 		printf("%d ",a[count ]);
	 }
	  printf("\n");
 }
 
 int main()
 {
 	int a[10];
 	stack s1,s2;
 	s1.top=-1;
 	s2.top=10;
 	push1(&s1,&s2,4,a);
 	push1(&s1,&s2,5,a);
 	push1(&s1,&s2,6,a);
 	push1(&s1,&s2,7,a);
 	push2(&s1,&s2,5,a);
 	push2(&s1,&s2,5,a);
 	push2(&s1,&s2,5,a);
 	print1(&s1,a);
 	print2(&s2,a);
 	pop1(&s1);
 	pop2(&s2);
 	print1(&s1,a);
 	print2(&s2,a);
 	return 0;
 }
