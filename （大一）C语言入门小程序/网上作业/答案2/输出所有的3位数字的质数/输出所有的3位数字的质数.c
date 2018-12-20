#include <stdio.h> 
#include <math.h> 
int main() 
{  int m,i,k,prime,count=0;  
    for (m=101;m<999;m=m+2)  
	{   k=(int)sqrt(m);   
         prime=1;  
		  for (i=2;prime&&i<=k;i++)   
		   if (m%i==0) prime=0;  
		    if (prime)   
			{    printf("%6d",m);   
			    count++;    
			 if (count%5==0) printf("\n");  
		     } 
   }  
			   printf("\n");  
			   return 0; 
 }