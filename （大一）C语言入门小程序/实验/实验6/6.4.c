/* Note:Your choice is C IDE */
#include "stdio.h"
void readin(int *a,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("input:\n");
		scanf("%d",a+i);
	}
}
void count(int *a,int n,int *b)
{
	int i,j,count1=0,count2
	=0,count3=0,count4=0,count5=0;
	for(i=0;i<n;i++)
	{
		if(a[i]>=0&&a[i]<=59) 
		   count1++;
		
		
		
		
		
		
	}
	b[0]=count1;
	
	
	
	
}
void print(int *a,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d",a[i]);
	}
}
void main()
{
    int a[10],b[5];
    readin(a,10);
    count(a,10,b);
    print(b,5);
}