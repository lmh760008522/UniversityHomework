#include <stdio.h>
#define N 5
int main()
{
int a[N],min;
int i;
for(i=0;i<N;i++)
scanf("%d",&a[i]);
min=a[0];
for(i=2;i<N;i+=2)
if(min>a[i])
min=a[i];
printf("%d",min);
return 0;
}