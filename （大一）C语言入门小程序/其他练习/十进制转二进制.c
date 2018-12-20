/* Note:Your choice is C IDE */
#include "stdio.h"
void main()
{
    int a[16];
    int n,k,i=0,j;
    scanf("%d",&n);
    while(n)
    {
    	n=n/2;
    	k=n%2;
    	a[i++]=k;
    }
    i--;
    for(j=i;j>=0;j--)
     printf("%d",a[j]);
}