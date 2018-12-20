/* Note:Your choice is C IDE */
#include "stdio.h"
int main()
{
    int a[10][10];
    int i,j,n;
    for(i=0;i<10;i++)
    {
    	a[i][0]=1;
    	a[i][i]=1;
    }
    for(i=2;i<9;i++)
    {
    	for(j=1;j<i;j++)
    	{
    		a[i][j]=a[i-1][j-1]+a[i-1][j];
    	}
    	
    }
    do
    {
         scanf("%d",&n);
    }while(n<=0||n>=10);
    for(i=0;i<n;i++)
    {
    	for(j=0;j<=i;j++)
    	{
    		printf("%5d\t",a[i][j]);
    	}
    	printf("\n");
    }
    return 0;
    
    
}