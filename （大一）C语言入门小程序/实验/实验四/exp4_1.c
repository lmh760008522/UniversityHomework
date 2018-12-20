#include <stdio.h>
#define N 10
void printarr(double a[],int n)
{
	int i,m;
	printf("The elements are:\n");
	for (i=0;i<10;i++)
	{
		printf("%5f ",a[i]);
		m++;
		if (m%5==0)
			printf("\n");
	}
}

double ave(double a[],int n)
{
	int i;
	double ave,sum=0;
	for (i=0;i<n;i++)
	{
		sum+=a[i];
	}
	ave=sum/10.000000;
	return ave;
}

double maxarr(double a[],int n)
{
	int i;
	double max;
	max=a[0];
	for (i=0;i<n;i++)
	{
		if (a[i]>max)
			max=a[i];
	}
	return max;
}

int searcharr(double a[],int n,double x)
{
	int i,j=0;
	printf("Please input n:\n");
	scanf("%lf",&x);
	for (i=0;i<n;i++)
	{
		if (x==a[i])
		{
			printf("%f=a[%d]\n",x,i);
			j++;
		}	
	}
	if (j==0)
	{
		printf("Not find!\n");
	}
	return i;
}

void BubbleSort(double a[],int n)
{
	int i,j;
	double temp;
	for (i=0;i<n-1;i++)
		for (j=n-1;j>i;j--)
			if(a[j]<a[j-1])
			{
				temp=a[j];
				a[j]=a[j-1];
				a[j-1]=temp;
			}
}

int main()
{
	int i;
	double array[N],d,e;
	double x=0;
	printf("Please input array[]:\n");
	for (i=0;i<10;i++)
	{
		scanf("%lf",&array[i]);
	}
	printarr(array,N);
	d=ave(array,N);
	e=maxarr(array,N);
	printf("average=%f\n",d);
	printf("max=%f\n",e);
	searcharr(array,N,x);
	BubbleSort(array,N);
	printarr(array,N);
	return 0;
}