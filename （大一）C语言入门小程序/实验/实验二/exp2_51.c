#include <stdio.h>
#include <math.h>
int main()
{
	int a,b,count,i,n,k;
	do
	{
		printf("Enter a,b:\n");
		scanf("%d%d",&a,&b);
	} while (a>b);
	for(n=a+1;n<b;n++)
	{
		k=(int)sqrt(n);
		for (i=2;i<=k;i++)
		{
			if (n%i==0)
			{
				break;
			}
		}
		if (i>k)
		{
			printf("%d ",n);
			count++;
			if (count%5==0)
			{
				printf("\n");
			}
		}
	}
	printf("\n");
	return 0;
}