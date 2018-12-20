/* Note:Your choice is C IDE */
#include "stdio.h"
void main()
{
    double array[10],*p,max,min,sum=0.0,ave,temp;
    int i,j;
    for(i=0;i<10;i++)
    {
    	printf("input:\n");
    	scanf("%lf",array+i);
    }
    p=array;
    for(i=0;i<10;i++)
    {
    	printf("%p\t%f\n",p+i,*(p+i));
    }
    max=*p;
    for(i=0;i<10;i++)
    {
    	if(max<*(p+i))
    	{
    		max=*(p+i);
    	}
    }
    printf("max=%f\n",max);
    min=*p;
    for(i=0;i<10;i++)
    {
    	if(min>*(p+i))
    	{
    		min=*(p+i);
    	}
    }
    printf("min=%f\n",min);
    for(i=0;i<10;i++)
    {
    	sum+=*(p+i);
    }
    ave=sum/10;
    printf("ave=%f\n",ave);
    
    for(i=0;i<9;i++)
    {
    	for(j=9;j>i;j--)
    	{
    		if(*(p+j)<*(p+j-1))
    		{
    			temp=*(p+j-1);
    			*(p+j-1)=*(p+j);
    			*(p+j)=temp;
    		}
    	}
    }
    for(i=0;i<10;i++)
    {
    	printf("%f\n",*(p+i));
    }
}