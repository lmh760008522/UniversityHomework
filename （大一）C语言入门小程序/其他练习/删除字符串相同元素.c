/* Note:Your choice is C IDE */
#include "stdio.h"
#include"string.h"
void main()
{
    char *a;
    int i,j,k,len;
    gets(a);
    len=strlen(a);
    for(i=0;i<len;i++)
    {
    	for(j=i+1;j<len;j++)
    	{
    		if(a[i]==a[j])
    		{
    			for(k=j;k<len;k++)
    		    {
    		    	a[k]=a[k+1];
    		    }
    		   j--;
    		}
    	}
    }
    puts(a);
    
}