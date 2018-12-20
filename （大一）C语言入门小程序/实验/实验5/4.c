/* Note:Your choice is C IDE */
#include "stdio.h"
int h1(int a[][])
{
	int i,j,n;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("PLEASE INPUT ELEMENTS:");
		    scanf("%d",&a[i][j]);
		}
	}
	
}

int h2(int a[][])
{
	int i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%d",a[i][j]);
		}
		printf("\n");
	}
	return 0;
}
int h3(int a[][])
{
	int b[3][3];
	int i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			b[j][i]=a[i][j];
		}
	}
	for(j=0;j<3;j++)
	{
		for(i=0;j<3;j++)
		 printf("%d",b[i][j]);
		printf("\n");
	}
	return 0;
}
void main()
{
    int i,j;
    int arr[3][3];
    h1(arr[3][3]);
    h2(arr[3][3]);
    h3(arr[3][3]);
    printf("THE FORMER ARR IS:");
    for(i=0;i<3;i++)
    {
    	for (j=0;j<3;j++)
    	 printf("%d",arr[i][j]);
    	printf("\n");
    }
}