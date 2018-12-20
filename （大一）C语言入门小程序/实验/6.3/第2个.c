/* Note:Your choice is C IDE */
#include "stdio.h"
#include"stdlib.h"
void main()
{
    FILE *fp1,*fp2;
    char str[100],ch;
    fp1=fopen("D:\\f1.txt","r+");
    if(fp1==0)
    {
    	printf("file error\n");
    }
    while(fgets(str,100,fp1)!=NULL)
    {
    	printf("%s,str");
    }
    fp2=fopen("D:\\f2.txt","w+");
    if(fp2==0)
    {
    	printf("error");
    }
    ch=fgetc(fp1);
    while(ch)
    {
    	fputc(ch,fp2);
    	ch=fseek(fp1,1,ch);
    }
    fclose(fp1);
    fclose(fp2);
}