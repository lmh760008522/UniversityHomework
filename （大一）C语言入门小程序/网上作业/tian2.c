#include<stdio.h>

int main() 
{ 
int start,pass,final;
int hour,minute,c,d=1;
scanf("%d%d",&start,&pass);/*读入两个整数*/
minute=start%100;
hour=start/100;
c=minute+pass;
d=c/60;
if (c<0)
{
d=d-1;
c=c-d*60;
}
minute=c%60;
hour=(hour+d+24)%24;
final=100*hour+minute;
printf("%d\n",final);
return 0;
}