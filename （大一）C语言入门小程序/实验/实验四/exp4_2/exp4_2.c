#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 1000
void printarr(int a[],int n)
{
	int i;
	printf("The elements are:\n");
	for (i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
}

void BubbleSort(int a[],int n)
{
	int i,j,temp;
	for (i=0;i<n-1;i++)
		for (j=n-1;j>i;j--)
			if (a[j]<a[j-1])
			{
				temp=a[j];
				a[j]=a[j-1];
				a[j-1]=temp;
			}
}

void num(int a[],int n,int b[],int c[])
{
	int i,j=1,k;
	for (i=0;i<n;i++)
	{
		if (a[i]!=a[i+1])
		{
			b[j]=i+1;
			c[j]=a[i];
			j++;
		}
	}
	printf("The same elements are:\n");
	for (k=0;k<n;k++)
	{
		printf("(%d,%d) ",c[k],b[k+1]-b[k]);
		if (c[k]==0||b[k]==0||b[k+1]-b[k]==0)
			continue;
	}
}

int main()
{
	int i;
	int array[N],b[]={0},c[]={0};
	srand(time(NULL));
	for (i=0;i<N;i++)
		array[i]=rand()%10000+1;
	BubbleSort(array,N);
	printarr(array,N);
	printf("\n");
	num(array,N,b,c);
	printf("\n");
	return 0;
}