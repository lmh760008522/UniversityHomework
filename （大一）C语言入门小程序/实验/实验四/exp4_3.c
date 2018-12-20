
#include <stdio.h>
#define R 5
#define C 5
void scanarr(int a[][C])
{
	int i,j;
	for (i=0;i<R;i++)
	{
		for (j=0;j<C;j++)
			scanf("%d",&a[i][j]);
	}
}

void printarr(int a[][C])
{
	int i,j;
	for (i=0;i<R;i++)
	{
		for (j=0;j<C;j++)
			printf("%5d ",a[i][j]);
		printf("\n");
	}
}

int sumarr(int a[][C])
{
	int i,sum=0;
	for (i=0;i<5;i++)
		sum+=a[i][i];
	for (i=4;i>=0;i--)
		sum+=a[i][4-i];
	sum-=a[3][3];
	return sum;
}

int main()
{
	int array[R][C];
	printf("Please input array[R][C]\n");
	scanarr(array);
	printf("The elements are:\n");
	printarr(array);
	printf("sum=%d\n",sumarr(array));
	return 0;
}