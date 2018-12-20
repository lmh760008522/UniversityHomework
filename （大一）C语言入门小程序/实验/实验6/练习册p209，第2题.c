/* Note:Your choice is C IDE */
#include "stdio.h"
#include"string.h"
void main()
{
 char s[20];
 int i,j,k;
 gets(s);
 for(i=0;s[i]!='\n';i++)
 {
 	for(j=i+1;s[j]!='\n';j++)
 	{
 		if(s[i]=s[j])
 		{
 			for(k=j;k<strlen(s);k++)
 			{
 				s[k]=s[k+1];
 			}
 		}
 	    
 		
 	}
 }
 puts(s);
}