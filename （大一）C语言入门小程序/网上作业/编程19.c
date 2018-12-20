
#include<stdio.h>
#include<string.h>
char reverse(char *str)
{
	char *q,*p,k;
	int i;
    p=str+strlen(str)-1;
    q=str;
    for( ;q<p;q++,p--)
    {
    	k=*q;
    	*q=*p;
    	*p=k;
    }
}
int main()
{
	char str[20];
	gets(str);
	reverse(str);
	puts(str);
	return 0;
}