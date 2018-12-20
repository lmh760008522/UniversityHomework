#include<stdio.h> 
double fun(int n)
{ 
double t,sn=0.0;
int i,j;
for(i=1; i<=n;i++)
{ 
t=1.0;
for(j=1;j<=i;j++)
t=t*j;
sn+=1/t;
}
return sn;
}

int main()
{
int n;
scanf("%d",&n);
printf("sum=%lf\n",fun(n));
return 0;
}