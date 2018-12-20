#include <stdio.h>
#include <stdlib.h>
int main()
{
	FILE *fin,*fout;
	char s1[]="D:\\f1.txt",s2[]="D:\\f2.txt";
	char ch;
	fin=fopen(s1,"r");
	if (fin==0)
	{
		printf("file error\n");
		exit(1);
	}
	fout=fopen(s2,"w");
	if (fout==0)
	{
		printf("file error\n");
		exit(1);
	}
	while( (ch=fgetc(fin))!=EOF )
	{
		if (ch>='A' && ch<='z')
			{
				fprintf(fout,"%c %d ",ch,ch);
			}
	}
	fclose(fin);
	fclose(fout);
	return 0;
}