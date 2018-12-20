#include <stdio.h>
#include <math.h>
int main()
{
	int n,i,k;
	do
	{
		printf("Please input a positive integer:\n");
		scanf("%d",&n);
	}while ( n<=0 );
	if (n==1)
	{
		printf("%d is not a prime.\n",n);
	}
	else
	{
		k=(int)sqrt(n);
		for ( i=2; i<=k; i++)
		{
			if(n%i==0)
			{
				break;
			}
		}
	}
	if (i>k)
	{
		printf("%d is a prime.\n",n);
	}
	else
	{
		printf("%d is not a prime.\n",n);
	}
	return 0;
}