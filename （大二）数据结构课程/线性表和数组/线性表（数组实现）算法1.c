#include<stdio.h>

typedef struct list
{
	int size,maxlist;
	int elements[20];
} list;

void createlist(list *a,int maxsize)
{
	a->size =0;
	a->maxlist =maxsize;
}

void clear(list *a)
{
	a->size =0;
}

list *insert(list *a,int pos,int x)//在pos 处插入x 
{
	int i;
	for(a->size -1;i>=pos;i++)
	{
		a->elements [i+1]=a->elements [i];
	}
	a->elements [pos]=x;
	a->size ++;
	return a;
}
list * remove(list *a,int pos,int  *x)//删除 pos处的x 
{
	int i;
	*x=a.elements [pos];
	for(i=pos+1;i<a.size ;i++)
	{
		a.elements [i-1]=a.elements [i];
	}
	a.size --;
	return a;
}

//用最少的时间把所有负数的元素移到全部整数的旁边 
void move(list *a)//从左到右找到一个正数，从右到左找到一个负数，两者交换 
{
	int i=0,j=a.size -1,k;
	int t;
	if(i<=j)
	{
		while(a.elements [i]<=0)
		{
			i++;
		}
		while(a.elements [j]>=0)
		{
			j--;
		}
		if(i<j)
		{
			t=a.elements [i];
			a.elements[i]=a.elements [j];
			a.elements [j]=t;
		}
	}
 } 

