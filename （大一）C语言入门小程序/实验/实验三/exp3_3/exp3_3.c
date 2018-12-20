#include <stdio.h>
#include <math.h>
int gcd(int m,int n)
{
	int r;
	r=m%n;
	m=n;
	if(r)
		return gcd(n,r);
	return n;
}
int main()
{
	int m,n,t;
	printf("Please input m,n:\n");
	scanf("%d%d",&m,&n);
	t=gcd(m,n);
	printf("%d\n",t);
	return 0;
}