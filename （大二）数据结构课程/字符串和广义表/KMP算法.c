#include<stdio.h>
#include <string.h>
typedef struct string
{
	char chs[100];
	int length,maxstring;
}string;
int  KMP(string s,string p ,int pos)
{
	int i=pos,j=0;
	int n=s.length,m=p.length;
	while (i<n&j<n)
	{
		if(j==-1||s.chs[i]==p.chs[j])
		{
			i++;
			j++;
		}
		else
		{
			j=f[j];//fÊÇÊ§°Üº¯Êý£¬ÊéP93 
		}
	}
	return ((j==m)?i-m:-1);
}

void fail(string p,int *f)
{
	int j=0,k=-1;
	f[0]=-1;
	while(j<p.length )
	{
		if(k==-1||p.chs[k])
		{
			j++;
			k++;
			if(p.chs[j]==p.chs[k]) 
				f[j]=f[k];
			else 
				f[j]=k;
		}
		else
		{
			k=f[k];
		}
	}
}
