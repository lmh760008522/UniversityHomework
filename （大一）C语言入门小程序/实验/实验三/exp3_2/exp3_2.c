#include <stdio.h>
#include <math.h>
int JudgePrime(int n);
int main()
{
	int m,i,a;
	do
	{
		printf("Please input m\n");
		scanf("%d",&m);
	}while(m%2!=0 && m<=2);
	for (i=1;i<=m;i++)
	{
		a=m-i;
		if(JudgePrime(i) && JudgePrime(a) && i<=a)
		{
			printf("%d=%d+%d\n",m,i,a);
		}
	}
	printf("\n");
	return 0;
}
int JudgePrime(int n)
{
	int i,k;
	int judge=1;
	if (n==1)
	{
		judge=0;
	}
	else
	{
		k=(int)sqrt(n);
		for (i=2;judge && i<=k;i++)
		{
			if(n%i==0)
			{
				judge=0;
			}
		}
	}
	return judge;
}