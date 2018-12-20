/* Note:Your choice is C IDE */
#include "stdio.h"
#include"string.h"
#include"math.h"
void main()
{
    char *str;
    int i,j=0,len;
    float a=0;
    gets(str);
    for(i=0;str!='\0';i++)
    {
    	if(str[i]>='0'&&str[i]<='9')
    	{
    		str[j++]=str[i];
    	}
    }
    str[j]='\n';
    len=strlen(str);
    i=0;
    do
    {
    	a+=a*10+(str[i]-48);
    	i++;
    }while(len!=0);
    printf("%.4f",a);
    
}