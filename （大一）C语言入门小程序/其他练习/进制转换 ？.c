/* Note:Your choice is C IDE */
#include "stdio.h"
void main()
{
    int i=0,x,k,j,s[20];
    scanf("%d",&x);
    i=0;
    while(x!=0);
    {
    	x=x/2;
    	s[i]=x%2;
    	i++;
    }
    for(j=i-2;j>=0;j--)
     printf("%d",s[j]);
}