#include<stdio.h>
#include<string.h>
void Display(char pa[][20],int n)         //输出n个字符串
{
		int i;
		for(i=0;i<n;i++)
			printf("%s  ",pa[i]);    //pa[i]可以写成*(pa+i);
		printf("\n");
}
void Selection(char pa[][20],int n)        //选择排序函数定义
{
	int i,k,index;
	char temp[20];
	for (k=0;k<n-1;k++)                  
	{
		index=k ;                       
		for(i=k+1;i<n;i++) 
			if (strcmp(pa[i],pa[index])<0)            
			  index=i;
		if (index!=k)                    
		{		
			strcpy(temp,pa[index]);
			strcpy(pa[index],pa[k]);
			strcpy(pa[k],temp);
		}
	}   
}
int main( )
{
	char a[6][20];
	int i;
	for( i=0; i<6; i++ )
		gets(a[i]);
	Selection(a,6);
    Display(a,6);   
	return 0;
}
