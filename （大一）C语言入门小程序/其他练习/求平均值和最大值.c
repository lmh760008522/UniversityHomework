/* Note:Your choice is C IDE */
#include "stdio.h"
typedef struct Student {

       int num;

       char name[20];

       int score;

}STU; 

int main()
{
    float ave=0.0;
    int max=0,i;
    STU a[3];
    for(i=0;i<3;i++)
    {
    	scanf("%d",&a[i].num);
    	scanf("%s",a[i].name);
    	scanf("&d",&a[i].score);
    	ave+=a[i].score/3.0;
    }
    for(i=1;i<3;i++)
    {
    	if(a[max].score<a[i].score)
    	   max=i;
    }
    printf("The average score=%.2f\n",ave);
    printf("The student who has the highest score is:\n");
    printf("%d\t%s\t%d\n",a[max].num,a[max].name,a[max].score);
    return 0;
}