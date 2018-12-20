/* Note:Your choice is C IDE */
#include "stdio.h"
void main()
{
    int a[4][4];
    int i,j,k;
    int max;
    for(i=0;i<4;i++)
    {
    	for(j=0;j<4;j++)
    	{
    		printf("please input a integer:");
    		scanf("%d",&a[i][j]);
    	}
    }
    for(i=0;i<3;i++)
    {
    	for(j=0;j<3;j++)
    	{
    		if(a[i][j]<a[i][j+1])
    		{
    			max=a[i][j+1];
    		}
    		else max=a[i][j];
    	}
    	if(max>=a[i][0]&&max>=a[i][1]&&max>=a[i][2]&&max>=a[i][3])
    	   { k=max;}
    }
    for(i=0;i<4;i++)
    {
    	for(j=0;j<4;j++)
    	{
    		if(a[i][j]==k)
    		  printf("(%d) ",k);
    		else printf("%d ",a[i][j]);
    		
    	}
    	printf("\n");
    }
   
    
        
    
}