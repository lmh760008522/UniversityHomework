/* Note:Your choice is C IDE */
#include "stdio.h"
#include "string.h"
void main()
{
    char str[20];
    int i,j;
    gets(str);
    for(i=0;i<strlen(str);i++)
    {
    	if(str[i]==' ')
    	{
    		for(j=i;j<strlen(str);j++)
    		{
    			str[i]=str[i+1];
    		}
    	}
    }
    for(i=0;str[i]!='\0';i++)
    {
    	printf("%c",str[i]);
    }
    
}