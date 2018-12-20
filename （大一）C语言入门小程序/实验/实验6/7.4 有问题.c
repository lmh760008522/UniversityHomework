/* Note:Your choice is C IDE */
#include "stdio.h"
#include"string.h"
void main()
{
    char s[10][10],*c;
    int i,j;
    for(i=0;i<10;i++)
    {
    	gets(s[i]);
    }
    for(j=0;j<10;j++)
    {
    	for(i=1;i<10;i++)
    	{
    		if(strcmp(s[i],s[i+1])==-1)
    		{
    			c=s[i];
    			s[i]=s[i+1];
    			s[i+1]=c;
    	    }
    	}
    }
    for(i=0;i<10;i++)
    {
    	puts(s[i]);
    }
}