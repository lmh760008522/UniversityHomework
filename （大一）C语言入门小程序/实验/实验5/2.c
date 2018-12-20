/* Note:Your choice is C IDE */
#include "stdio.h"
#include"time.h"
#include"stdlib.h"
void main()
{
    int t,x,n,i,j,k,time=1;
    double a[1000];
    srand(time(NULL));  
     //Åª²»³ö£¿£¿£¿
    for(i=0;i<1000;i++)
    {
    	a[i]=rand()%100+1;
    }
    for(j=0;j<1000;j++)
    {
    	for(k=i+1;k<1000;k++)
    	{
    		if(a[i]==a[k])
    		{time++;}
    	}
    	printf("(%d,%d)",a[i],time);
    }

    
}