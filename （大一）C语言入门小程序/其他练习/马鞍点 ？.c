/* Note:Your choice is C IDE */
#include "stdio.h"
void main()
{
    int i,j,max,min,k,m;
    int a[3][3]={1,2,3,8,3,4,2,3,9};
    for(i=0;i<3;i++)
     {
     	for(j=0;j<3;j++)
     	{
     	   printf("%d\t",a[i][j]);
     	
     	}
     	printf("\n");
     }
    for(i=0;i<3;i++)
    {
    	max=a[i][0];
    	k=0;
    	for(j=1;j<3;j++)
    	{
    		if(max<a[i][j])
    		  {
    		  	max=a[i][j];
    		  	k=j;
    		  }
    	}
    	min=a[0][k];
    	for(m=0;m<3;m++)
    	{
    		if(min>a[m][j])
    		 min=a[m][j];
    	}
    	if(min==max)
    	  printf("%dÊÇÂí°°",min);
    	
    }
}