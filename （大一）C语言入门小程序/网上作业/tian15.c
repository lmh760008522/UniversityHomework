#include <stdio.h>
int f(int a[3][3],int *max,int n)
{ 
int i,j,s=0;
*max=a[0][0];
for(i=0;i<n;i++)
{
s+=a[i][i]; 
for(j=0;j<3;j++) 
if(*max<a[i][j]) *max=a[i][j]; 
}
return s;
}
int main()
{ 
int a[3][3]={1,-2,9,4,-8,6,7,0,5};
int max,sum; /*max存最大元素值，sum存元素的和值*/
sum=f(a,&max,3); 
printf("sum=%d,max=%d\n",sum,max);
return 0;
}