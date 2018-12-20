#include <stdio.h>
#define N 10
int array[N],*p=&array[0],i=0;
void scanarr(int a[])
{
	for (i=0;i<N;i++)
		scanf("%d",&*(p+i));
}
void printarr1(int a[])
{
	for (i=0;i<N;i++)
		printf("a[%d]\t%p\t%d\n",i,p+i,*(p+i));
}
void printarr(int a[])
{
	for (i=0;i<N;i++)
		printf("a[%d]=%d ",i,*(p+i));
	printf("\n");
}
void searcharr(int a[])
{
	int sum=0;
	double ave;
	int min=*p,max=*p;
	for (i=0;i<N;i++)
	{
		sum+=*(p+i);
		if (*(p+i)>max)
			max=*(p+i);
		if (*(p+i)<min)
			min=*(p+i);
	}
	ave=sum/10.000000;
	printf("max=%d\nmin=%d\nave=%f\n",max,min,ave);
}
void BubbleSort(int a[])
{
	int i,j,temp;
	for (i=0;i<N;i++)
		for (j=N-1;j>i;j--)
			if (*(p+j)<*(p+j-1))
			{
				temp=*(p+j);
				*(p+j)=*(p+j-1);
				*(p+j-1)=temp;
			}
}
int main()
{
	scanarr(array);
	printarr1(array);
	searcharr(array);
	BubbleSort(array);
	printarr(array);
	return 0;
}