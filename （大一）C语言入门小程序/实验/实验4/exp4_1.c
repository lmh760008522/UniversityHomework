/* Note:Your choice is C IDE */
#include "stdio.h"
void DrawPic(int n,char c)
 {
 	int i,j;
    for(i=1;i<=n;i++)
    {
    	for (j=1;j<=n-i;j++)
    	printf (" ");
    	for (j=1;j<=2*i-1;j++)
        printf("%c",c);
        printf("\n");
    } 
  
    return;
 }
 void main()
{
 DrawPic(7,'*');
 printf("\n");
 DrawPic(11,'@');
 printf("\n");
 DrawPic(20,'$');
 printf("\n");
 DrawPic(40,'#');
   
}