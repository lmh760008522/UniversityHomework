#include<stdio.h>
int main( )
{
	int y[10][10]={0},i,j,n;
 	scanf("%d",&n);
	for (i=1;i<=n;i++)
		y[i][1]=y[i][i]=1;
	for (i=3;i<=n;i++)
		for (j=2;j<n;j++)
			y[i][j]=y[i-1][j-1]+y[i-1][j];
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=i;j++)
			printf("%5d",y[i][j]);
		printf("\n");
	}
	return 0;
}
