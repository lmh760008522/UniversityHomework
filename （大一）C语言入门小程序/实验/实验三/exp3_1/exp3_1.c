#include <stdio.h>
void DrawPic(int n,char c)
{
	int i,j;
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=40-i;j++)
		{
			printf(" ");
		}
		for (j=1;j<=2*i-1;j++)
		{
			printf("%c",c);
		}
		printf("\n");
	}
	printf("\n");
	return;
}
int main()
{
	int t,n;
	char c;
	for (t=1;t<=5;t++)
	{
		printf("Please input n and c:\n");
		scanf("%d,%c",&n,&c);
		DrawPic(n,c);
	}
	return 0;
}