/* Note:Your choice is C IDE */
#include "stdio.h"
void main()
{
    int i,j,count=0;
    for(i=101;i<=999;i++)
    {
    	for(j=2;j<=i-1;j++)
    	{
    		if(i%j==0)
    		break;
    	}
    
      if(j==i)
      {
    	printf("%6d",i);
    	count++;
    	if (count%5==0)
    	  printf("\n");
      }
    }
    
}