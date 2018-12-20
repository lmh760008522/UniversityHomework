/* Note:Your choice is C IDE */
#include "stdio.h"
int JudgePrime(int n)
  {
   int i;
   int judge=1;

   if(n==1) 
     judge=0;
   else if(n==2)
          judge=1;
   else 
   {for(i=2;i<=n-1;i++)
     {
     	if(n%i==0) break;
     }
    if (i==n)
       judge=1;
    else judge=0;
    return judge;
   }
  }

int main()
 {int x,y,a,b,p;
  for(x=2;x<=1000;x++)
   {y=2*x;
   	for (a=1;a<=y-1;a++)
   	   {b=y-a;
   	   	if( JudgePrime(a)&&JudgePrime(b) )
   	   	  {
   	   	  	p=y;
   	   	  }
   	   	  
   	   }
   	 if (p==y) printf("%d ",p);
   	 
   }
   return 0;
}