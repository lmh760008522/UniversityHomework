#include <stdio.h>
int main()
{
	int sign,n;
	double i,item,sum;
	i=1.000000;
	sign=1;
	sum=0;
	printf("input n\n");
	scanf("%d",&n);
	while (i<=n)
	{
		item=sign/i;
		sum+=item;
		i++;
		sign=-sign;
	}
	printf("sum=%f\n",sum);
	return 0;
}