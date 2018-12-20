#include "stdio.h"
struct student
{
	int num;
	char c;
	double g1,g2,g3;
};
void input(struct student *pa,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d $s %lf %lf %lf",pa[i].num,pa[i].c,pa[i].g1,pa[i].g2,pa[i].g3);
	}
}
void sort(struct student *pa,int n)
{
	int i,j,k;
	struct student temp;
    for(i=0;i<n-1;i++)
	{
		k=0;
		for(j=0;j<n;j++)
		{
			if(((pa+j)->g1+(pa+j)->g2+(pa+j)->g3)>((pa+j+1)->g1+(pa+j+1)->g2+(pa+j+1)->g3))
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
	printf("学号  姓名  成绩1 成绩2 成绩3");
    for(i=0;i<n;i++)
	{
		printf("%d  %s  %lf  %lf  %lf",pa[i].num,pa[i].c,pa[i].g1,pa[i].g2,pa[i].g3);
	}
}
int main()
{
	struct student pa[5];
	int i;
	input(pa,10);
	for(i=0;i<10;i++)
	{
		if((pa[i].g1<60)||(pa[i].g2<60)||(pa[i].g3<60))
		{
			printf("%d  %s  %lf  %lf  %lf",pa[i].num,pa[i].c,pa[i].g1,pa[i].g2,pa[i].g3);
		}
	}
	sort(pa,10);
	output(pa,10);
	return 0;
}