/* Note:Your choice is C IDE */
#include "stdio.h"
void print(double a[])
{
	int i;
	for (i=0;i<10;i++)
	{
		printf("%lf ",a[i]);
	}
	printf("\n");
}
double ave(double a[])
{
	int i;
	double ave;
	double sum=0.0;
	for (i=0;i<10;i++)
	{
		sum+=a[i];
	}
	ave=sum/10;
	return ave;
}
double max(double a[])
{
	int i;
	double max0;
	max0=a[0];
	for(i=1;i<10;i++)
	{
		if(max0<a[i])
		{
			max0=a[i];
		}
	}
	return max0;
}
double search(double a[])
{
	int judge,i;
	double x;
	printf("input a integer\n");
	scanf("%lf",&x);
	for(i=0;i<10;i++)
	{
		if(x==a[i]) break;
	}
	if(i==10) 
       {
       	judge=0;
       }
	else 
	 {judge=1;
	  return i;
	 }
	return judge;
}
double sort(double a[])
{
	int i,j;
	double t;
	do
	{
		for(i=0;i<10;i++)
		{
			if(a[i]>a[i+1])
			{
				t=a[i];
				a[i]=a[i+1];
				a[i+1]=t;
			}
		}
    }while(a[0]<a[1]&&a[1]<a[2]&&a[2]<a[3]&&a[3]<a[4]&&a[4]<a[5]&&a[5]<a[6]&&a[6]<a[7]&&a[7]<a[8]&&a[8]<a[9]);
for(j=0;j<10;j++)
 printf("%d",a[j]);
 return 0;
}
void main()
{   int i;
	double ave0,max0,judge;
    double arrey[10];
    for(i=0;i<10;i++)
    {
    	 printf("IN PUT A NUMBER\n");
         scanf("%lf",&arrey[i]);
    }
    print(arrey);
    ave0=ave(arrey);
    printf("THE AVERAGE IS:%f\n",ave0);
    max0=max(arrey);
    printf("THE MAX IS:%d\n",max0);
    judge=search(arrey);
    if(judge) 
      printf("a[%d]",i);
    else 
      printf("no search\n");
    sort(arrey);

}