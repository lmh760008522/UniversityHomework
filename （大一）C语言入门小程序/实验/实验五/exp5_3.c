#include <stdio.h>
#include <string.h>
void scan(char (*str)[100])
{
	int i;
	for (i=0;i<10;i++)
		gets(str[i]);
}
void print(char (*str)[100])
{
	int i;
	for (i=0;i<10;i++)
		puts(str[i]);
}
void sort(char (*str)[100])
{
	int i,j;
	char temp[100];
	for (i=0;i<10;i++)
		for (j=0;j<9;j++)
			if (strcmp(str[j],str[j+1])<0)
			{
				strcpy(temp,str[j]);
				strcpy(str[j],str[j+1]);
				strcpy(str[j+1],temp);
			}
}
int main()
{
	char str[10][100];
	scan(str);
	sort(str);
	print(str);
	return 0;
}