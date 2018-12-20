#include<stdio.h>
#include<math.h>
int main()
{
	double x,sum,item;
	int sign,n;
	scanf("%lf",&x);
	sum=0;
	n=1;
	sign=1;
	item=1;
	do
	{
		item=item*x/n;
		sum+=sign*item;
		sign=-sign;
		n++;
	}while(fabs(item)>=1E-5);
    printf("sum=%.2f\n",sum);
	return 0;
}
    