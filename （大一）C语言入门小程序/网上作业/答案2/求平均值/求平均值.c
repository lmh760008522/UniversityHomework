#include<stdio.h>
int main()
{
 int count=0,i,m=0,n=0;
 double a[20],average,max,min,sum=0;
 for(i=0;i<20;i++)
  scanf("%lf",&a[i]);
 max=a[0]; /* 在循环体外面 */

 for(i=1;i<20;i++)
 { 
     if(a[i]>max)
   max=a[i];
 }
 for(i=0;i<20;i++)
 {
  if(a[i]==max)
   m++;
 }
 min=a[0];
 for(i=1;i<20;i++)
 {
  if(a[i]<min)
   min=a[i];
 }
 for(i=0;i<20;i++)
 {   
     if(a[i]==min)
        n++;}
 count=20-(m+n);
 for(i=0;i<20;i++)
 { sum+=a[i];}
 average=(sum-m*max-n*min)/count;
 printf("count=%d,average=%f\n",count,average);
 getchar();
 return 0;
}