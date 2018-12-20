#include<stdio.h>
#include<math.h>
void shijinzhi(int n)
{
	int m;
	if(n)
	{
		shijinzhi(n/2);
	    m=n%2;
		printf("%d",m);
	}
}
int main()
{
	char a[4];
	int i,sum,t;
	sum=0;
	gets(a);
	for(i=2;i>=0;i--)
	{
		t=(a[2-i]-48)*(pow((double)8,i));
		sum=sum+t;
	}
	shijinzhi(sum);
	printf("\n");
	return 0;
}