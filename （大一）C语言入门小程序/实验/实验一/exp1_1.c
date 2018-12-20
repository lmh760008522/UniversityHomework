#include <stdio.h>
int main ()
{
	int a,b;
    double ave;
	printf("Please input two integers\n");
	scanf("%d%d",&a,&b);
	ave=(a+b)/2;
	printf("ave=%f\n",ave);
	return 0;
}