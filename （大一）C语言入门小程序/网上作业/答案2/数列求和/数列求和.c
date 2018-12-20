#include <stdlib.h>
#include <math.h>
int main()
{
double x,num,sum=0;
int i=1,j,flag=1;
double jie;
scanf("%lf",&x);
while(1)
{
j=i;
jie=1.0;
while(j)
{//计算阶乘
jie*=j--;
}
num=pow(x,i++)/jie;//pow为计算x的i次方
if(fabs(num)<0.00001)//fabs计算绝对值
{
break;
}
if(flag)//是加是减用flag标志
{
sum+=num;
flag=0;
}
else
{
sum-=num;
flag=1;
}
//printf("sum=%lf,num=%lf,jie=%ld,i=%d\n",sum,num,jie,i);
}
printf("sum=%.2f\n",sum);
getch();
return 0;
}