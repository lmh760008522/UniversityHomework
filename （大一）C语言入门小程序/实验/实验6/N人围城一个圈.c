/* Note:Your choice is C IDE */
#include "stdio.h"
void main()
{
    int a[10],i,k=0,j;
    a[9]=0;
    for(i=0;i<9;i++)
    {
    	a[i]=i+1;
    }
    do
    {
    	for(i=0;i<10;i++)
    	{
    		k++;
    		if(k%3==0)
    		{
    			for(j=i;j<10;j++)
    			{
    				a[i]=a[i+1];
    			}
    		}
    	}
    }while(a[1]);
    printf("%d",a[0]);

}