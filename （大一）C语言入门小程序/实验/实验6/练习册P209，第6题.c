/* Note:Your choice is C IDE */
#include "stdio.h"
int fun(char p[5][5])
{
	int i,j;
	int count,max=0;
	for(i=0;i<5;i++)
	{
		count=0;
		for(j=0;j<5;j++)
		{
			if(p[i][j]!='\n')
		       count++;
		   
		}
		if(max<count)
		   max=count;
	}
	return max;
}
void main()
{
    char p[5][5];
    int i,j,count;
    for(i=0;i<5;i++)
    {
    	gets(p[i]);
    }
    count=fun(p);
    for(i=0;i<5;i++)
    {
    	for(j=0;j<count;j++)
    	{
    		if(p[i][j]=='\n')
    		{
    			p[i][j]='*';
    			p[i][j+1]='\n';
    		}
    	}
    }
    for(i=0;i<5;i++)
    {
    	puts(p[i]);
    }
}