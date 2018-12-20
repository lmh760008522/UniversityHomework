/* Note:Your choice is C IDE */
#include "stdio.h"
void main()
{
    int arr[5][5]={2,0,0,0,0,6,79,8,0,0,34,36,78,0,0,7,6,5,4,3,99,1000,1,1,1};
    int i,j;
    int sum1,sum2;
    sum1=0;
    sum2=0;
    for(i=0;i<5;i++)
       sum1+=arr[i][i];
    for(j=0;j<5;j++)
       sum2+=arr[i][4-i];
    printf("主对角线的和为%d\n",sum1);
    printf("次对角线的和为%d\n",sum2);
    for(i=0;i<5;i++)
    {
    	for(j=0;j<5;j++)
    	   {printf(" %5d ",arr[i][j]);}
    	printf("\n");
    }
    return 0;
}