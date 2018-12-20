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
 
 //设以整数序列1，2，3，4作为栈的输入，实现所有可能输出算法
 void process(int pos,int *path ,int curp)//处理当前pos 的位置,即依次进栈的数据 
 {
 	int m,i;
 	int total=4;//定义输入序列的总个数 
 	if(pos<total)
 	{
 		push(&s,pos+1);
 		process(pos+1,path,curp);
 		pop();
	 }
	 if(s.top!=-1)//栈不为空 
	 {
	 	m=pop();
	 	path[curp]=m;
	 	curp++;
	 	process(pos+1,path,curp);
	 	push(m);
	 }
	 if(pos==total&&s.top!=-1)//输出一种可能的方案 
	 {
	 	for(i=0;i<curp;i++)
	 	{
	 		printf("%d ",path[i]);
	 		printf("\n");
		 }
	 }
  } 
  
  int main()
  {
  	int path[10];
	stack s;
	create(&s,4);
	push(&s,1);
	printf("输出所有序列：\n");
	process(1,path,0);
	return 0;
  }
