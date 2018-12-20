/* Note:Your choice is C IDE */
#include "stdio.h"
int fun(int p[],int n)
{
	int count=0;
	int i,j;
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(p[i]==p[j])
			{
				count++;
				while(j<n-1);
				{
					p[j]=p[j+1];
					j++;
				}
			}
		}
	}
	return n-count;
	
}
void main()
{
    int i,a[10],num;
    for(i=0;i<10;i++)
    {
    	scanf("%d",&a[i]);
    }
    num=fun(a,10);
    for(i=0;i<num;i++)
    {
    	printf("%d  ",a[i]);
    }
    printf("\n");
    printf("%d",num);
}