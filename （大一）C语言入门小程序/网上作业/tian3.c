#include<stdio.h>
int main()
{
int n,m,r,count=0;
printf("please input a integer:\n");
scanf("%d",&m);
if (m<0) m=-m; /*保证最终的m不小于0*/
n=m; /*此处n用来保存最初的m值,以便于最后的输出*/
do
{
r=m%10;
printf("%d",r);
count++;
m=m/10;
}while (m); 
printf("\n%d has %d digits\n",n,count);
return 0;
}