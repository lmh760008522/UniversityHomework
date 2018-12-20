#include <stdio.h>
#include <math.h>
int gcd(int m,int n)
{
	int r;
	   do
	{
		r=m%n;
		m=n;
		n=r;
	} while (r);
	return m;
}
int main()
{
	int m,n;
	printf("Please input m,n:\n");
	scanf("%d%d",&m,&n);
	printf("%d\n",gcd(m,n));
	return 0;
}