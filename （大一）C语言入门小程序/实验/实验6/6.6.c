/* Note:Your choice is C IDE */
#include "stdio.h"
void main()
{
    int a[5];
    int i,min,max;
    for(i=0;i<5;i++)
    {
    	scanf("%d",a+i);
    }
    min=a[0];
    max=a[0];
    for(i=0;i<5;i++)
    {
    	if(min>a[i])
    	  min=a[i];
    	if(max<a[i])
    	  max=a[i];
    }
    for(i=0;i<5;i++)
    {
    	if(a[i]==min||a[i]==max)
    	   printf("(%d)",a[i]);
    	else 
    	 printf("%d",a[i]);
    }
}
