#include <stdio.h>
#include <string.h>
struct A
{ 
int x,y;
double ave; 
}; 
int main()
{ 
struct A a[3];
int i;
for (i=0;i<3;i++)
{
scanf("%d%d",&a[i].x,&a[i].y);
a[i].ave=(a[i].x+a[i].y)/2.0; 
}
for (i=0;i<3;i++)
{
printf("%d %d %lf\n",a[i].x,a[i].y,a[i].ave); 
}
return 0;
}