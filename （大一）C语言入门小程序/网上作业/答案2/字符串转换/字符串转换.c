#include<stdio.h>
int change(char *source,char * des)
{
	int i=0;
	while (*source)
	{
		if (*source>='0'&&*source<='9')
			des[i++]=*source;
		source++;
	}
	des[i]='\0';
	return i;
}
double calcu(char *s)
{
	double result=0;
	while (*s)
	{
		result=result*10+(*s-48);
		s++;
	}
	return result;
}
int main( )
{
	char str[50],strdes[50];
	gets(str);
	if (change(str,strdes))
		printf("%.4f\n",calcu(strdes));
	else
		printf("the digital string is empty!\n");
	return 0;
}
