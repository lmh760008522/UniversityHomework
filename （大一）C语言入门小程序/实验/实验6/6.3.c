/* Note:Your choice is C IDE */
#include "stdio.h"
int find(int *a)
{
	int i,j,k,m,count=0;
	for(i=100;i<999;i++)
	{
		j=i%10;
		k=i/10%10;
		m=i/100;
		if(i==j*j*j+k*k*k+m*m*m)
		  a[count++]=i;
	}
	return count--;
}
void main()
{
	int i,count;
	int a[100]={0};
	count=find(a);
	for(i=0;i<100;i++)
	 printf("%3d,%d",a[i],count);
	
    
}