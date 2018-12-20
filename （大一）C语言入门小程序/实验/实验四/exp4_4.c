
#include <stdio.h>
#define R 3
#define C 3
int a[R][C]={0},b[R][C]={0};
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
			printf("%d ",a[i][j]);
		printf("\n");
	}
}

void printcharr(int a[][C])
{
	int i,j;
	for (i=0;i<C;i++)
	{
		for (j=0;j<R;j++)
			printf("%d ",a[i][j]);
		printf("\n");
	}
}


void charr(int a[][C])
{
	int i,j;
	for (i=0;i<C;i++)
		for (j=0;j<R;j++)
			b[i][j]=a[j][i];
}

int main()
{
	printf("Please input a[R][C]:\n");
	scanarr(a);
	printf("Before transpose:\n");
	printarr(a);
	charr(a);
	printf("After transpose:\n");
	printcharr(b);
	return 0;
}
