#include<stdio.h>
int main()
{
	const double pi=3.14159;
	float rad,hei,area,vol;
    printf("please input two integers\n");
	scanf("%lf%lf",&rad,&hei);
	area=2*pi*rad*hei+2*pi*rad*rad;
	vol=pi*rad*rad*hei;
	printf("area=%lf\n",area);
	printf("vol=%lf\n",vol);
	return 0;
}