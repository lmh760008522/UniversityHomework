#include <stdio.h>
int main()
{
	int sign;
	double i,item,sum;
	i=1.000000;
	sign=1;
	sum=0;
	while (i<=10)
	{
		item=sign/i;
		sum+=item;
		i++;
		sign=-sign;
	}
	printf("sum=%f\n",sum);
	return 0;
}