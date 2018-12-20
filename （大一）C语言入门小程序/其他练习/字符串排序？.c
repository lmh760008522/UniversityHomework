/* Note:Your choice is C IDE */
#include "stdio.h"
#include"string.h"
void sort(char *str[5])
{
	int i,j,k;
	char *temp;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			if(strcmp(str[j],str[j+1])>0)
			{
				temp=str[j];
				str[j]=str[j+1];
				str[j+1]=temp;
			}
		}
		
	}
	
}
void main()
{
    char *str[5];
    int i;
    for(i=0;i<5;i++)
    {
    	gets(str[i]);
    }
    sort(str);
    for{i=0;i<5;i++}
     printf("%s\n",str[i]);
}