#include<stdio.h>
#define N 4
int isSymmetrical(int (*p)[N])
{
	int i,j;
	for (i=0;i<N;i++)
		for (j=0;j<=i;j++)
			if (p[i][j]!=p[j][i])
			   return 0;
	return 1;
}
int main( )
{
	int arr[N][N],i,j;
	for (i=0;i<N;i++)
		for (j=0;j<N;j++)
			scanf("%d",&arr[i][j]);
	if (isSymmetrical(arr))
		printf("Yes\n");
	else
	    printf("No\n");
    return 0;
}
