#include "stdio.h"
#include "string.h"
struct student
{
	int num;
	char c[10];
	double grade[3];
	double ave;
	
};
void input(struct student *pa,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d %s %lf %lf %lf",&pa[i].num,&pa[i].c,&pa[i].grade[0],&pa[i].grade[1],&pa[i].grade[2]);
		pa[i].ave=(pa[i].grade[0]+pa[i].grade[1]+pa[i].grade[2])/3.0;
	}
}
void sort(struct student *pa,int n)
{
	int i,j;
	struct student temp;
    for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1;j++)
		{
			if(pa[j].ave<pa[j+1].ave)
			{
				temp=pa[j];
				pa[j]=pa[j+1];
				pa[j+1]=temp;
			}
		}
	}
}
void output(const struct student *pa,int n )
{
	int i;
	printf("学号  姓名  成绩1 成绩2 成绩3  平均分\n");
    for(i=0;i<n;i++)
	{
		printf("%d  %s  %f  %f  %f %f\n",pa[i].num,pa[i].c,pa[i].grade[0],pa[i].grade[1],pa[i].grade[2],pa[i].ave);
	}
}
int main()
{
	struct student pa[5];
	int i;
	input(pa,5);
	for(i=0;i<5;i++)
	{
		if((pa[i].grade[0]<60)||(pa[i].grade[1]<60)||(pa[i].grade[2]<60))
		{
			printf("%d  %s  %lf  %lf  %lf\n",pa[i].num,pa[i].c,pa[i].grade[0],pa[i].grade[1],pa[i].grade[2]);
		}
	}
	sort(pa,5);
	output(pa,5);
	return 0;
}