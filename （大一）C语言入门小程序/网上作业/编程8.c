/* Note:Your choice is C IDE */
#include "stdio.h"
int main()
{
    int a[40];
    int i,n,k=0;
    a[0]=1;
    a[1]=1;
    for(i=2;i<40;i++)
    {
    	a[i]=a[i-2]+a[i-1];
    }
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
    	printf("%12d",a[i]);
    	k++;
    	if(k%6==0) printf("\n");
    }
	return 0;
    
}