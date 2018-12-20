#include "stdio.h"
int main()
{
	int a[20],max,min,count=0,i;
	double sum=0;
	for (i=0;i<20; i++)
	{
		scanf("%d", (a + i));
	}
	max = a[0];
	min = a[0];
	for (i = 1; i < 20; i++)
	{
		if (a[i]>max)
		    max = a[i];
		if (a[i] < min)
			min = a[i];
	}
	for (i = 0; i < 20; i++)
	{
		if(a[i]!=min&&a[i]!=max)
		{
			sum += a[i];
			count++;
		}
	}
	printf("count=%d,average=%f", count,sum/count);
	printf("\n");
	return 0;
}