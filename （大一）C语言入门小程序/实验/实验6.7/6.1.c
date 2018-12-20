/* Note:Your choice is C IDE */
#include "stdio.h"
void swap1(int ,int);
void swap2(int *,int);
void swap3(int *,int *);
void swap4(int *,int *);
void main()
{
    int x=10,y=20;
    printf("x=%d,y=%d\n",x,y);
    swap1(x,y);
    printf("after swap1:x=%d,y=%d\n\n",x,y);
    x=10;
    y=20;
    printf("x=%d,y=%d\n",x,y);
    swap2(&x,y);
    printf("after swap2:x=%d,y=%d\n\n",x,y);
    x=10;
    y=20;
    printf("x=%d,y=%d\n",x,y);
    swap3(&x,&y);
    printf("after swap3:x%d,y=%d\n\n",x,y);
    x=10;
    y=20;
    printf("x=%d,y=%d\n",x,y);
    vswap4(&x,&y);
    printf("after swap4:x=%d,y%d\n\n",x,y);
    
}
void swap1(int a,int b)
{
	int t=a;
	a=b;
	b=t;
}
void swap2(int *a,int b)
{
	int t=*a;
	*a=b;
	b=t;
	
}
void swap3(int *a,int *b)
{
	int t=*a;
	*a=*b;
	*b=t;
}
void swap4(int *a,int *b)
{
	int *t=a;
	a=b;
	b=t;
	
}