/* Note:Your choice is C IDE */
#include "stdio.h"
#include"string.h"
int fun(char *ch)
{
	int count=0;
	int i;
	while(*ch)
	{
		if(*ch!=' ')
		{
			count++;
			while(*ch++!=' ') ;
		}
		*ch++;
	}
	return count;
}
void main()
{
    char ch[20];
    int count=0;
    gets(ch);
    count=fun(ch);
    printf("%d",count);
}