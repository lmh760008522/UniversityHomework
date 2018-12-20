 #include<stdio.h>
#include<string.h>
void reverse(char *s)
{
	char *p=s,*q,t;
	int len=strlen(s);
	q=p+len-1;
	while (p<q)
	{
		t=*p;
		*p=*q;
		*q=t;
		p++;
		q--;
	}
}
int main( )
{
	char s[100];
	gets(s);
	reverse(s);
	puts(s);
	return 0;
}
