#include "stdio.h"
#include "stdlib.h"
int main()
{
     FILE *f1,*f2;
	 char ch;
	 f1=fopen("D:\\f1.txt","r");
	 if(f1==0)
	 {
		 printf("file error\n");
		 exit(1);
	 }
	 while((ch=fgetc(f1))!=EOF)
     {
		 putchar(ch);
	 }
	 putchar('\n');
	 f2=("D:\\f2.txt","w");
	 if(f2==0)
     {
		 printf("file error");
		 exit(1);
	 }
	 while((ch=fgetc(f1))!=EOF)\
	 {
		 fputc(ch,f2);

	 }
	 fclose(f1);
     fcluse(f2);
	 return 0;
}