#include<stdio.h>
typedef struct
{
	int row,col,dir;
 }ele;
 
 ele s[20];
 
typedef struct stack
{
	int top,maxstack;
	int elements[20];
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
 
 void initial(int maze[],int num)
 {
 	//³õÊ¼»¯ÃÔ¹¬ 
 }
 
 void path(int maze[])
 {
 	int i;
 	int row,col,nextrow,nextcol;
 	int dir,found =0;
 	int mark[20][20];
 	ele position;
 	mark[1][1]=0;
 	s[0].row =1;
 	s[0].col =1;
 	s[0].dir =1;
 	while(top>-1&&!found)
	 {
	 	posision
	 	
	} 
 }
