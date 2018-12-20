#include "stdio.h"
#include"string.h"
int fun(char *ss[5])
{
	int len;
	int i,j;
	len=strlen(ss[i]);
	for(i=1;i<5;i++)
	{
		if(len<strlen(ss[i]))
		 len=strlen(ss[i]);
	}
	for(i=0;i<5;i++)
	{
		for(j=0;j<len;j++)
		{
			if(!ss[i][j])
			{
				ss[i][j]='*';
			}
		}
	}
	return len;
}
void main()
{
    char ss[5][10];
    int i,j,count;
    for(i=0;i<5;i++)
    {
    	scanf("%s",ss[i]);
    }
    count=fun(ss);
    for(i=0;i<5;i++)
    {
    	for(j=0;j<10;j++)
    	{
    		printf("%c",ss[i][j]);
    	}
    }
    printf("%d",count);
}