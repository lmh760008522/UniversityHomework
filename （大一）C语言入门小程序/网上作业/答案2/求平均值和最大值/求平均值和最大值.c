#include <stdio.h>
typedef struct Student { 
 
 int num; 
 
 char name[20]; 
 
 int score; 
 
}STU; 

int main()
{
 STU res[3];
 int sum=0;
 int maxt=0;
 int id=0,i;
 float mean;
    for (i=0;i<3;i++)
 {
  scanf("%d",&res[i].num);
  scanf("%s",res[i].name);
  scanf("%d",&res[i].score);
  sum+=res[i].score;
  if(res[i].score>maxt)
   maxt=res[i].score,id=i;
 }
 mean=1.0*sum/3;
 printf("The average score=%.2f\nThe student who has the highest score is:\n%d\t%s\t%d\n",mean,res[id].num,res[id].name,res[id].score );
 return 0;
}