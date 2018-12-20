#include <stdio.h>
typedef struct student
{
	int ID;
	char name[20];
	int score[3];
	double average;
} student;
void Input(struct student *pa,int n)
{
	int i,j;
	for (i=0;i<n;i++)
	{
		double sum=0.0;
		scanf("%d%s",&pa->ID,pa->name);
		for (j=0;j<3;)
		{
			scanf("%d",&pa->score[j]);
			sum+=pa->score[j++];
		}
		(*pa).average=sum/3.0;
		pa++;
	}
}

void Sort(struct student *pa,int n)
{
	int i,j;
	student temp;
	for (i=0;i<n;i++)
		for (j=n-1;j>i;j--)
			if ( ((pa+j)->average) > ((pa+j-1)->average))
			{
				temp=*(pa+j);
				*(pa+j)=*(pa+j-1);
				*(pa+j-1)=temp;
			}
}
void Output(const struct student *pa,int n)
{
	int i,j;
	for (i=0;i<n;i++)
	{
		printf("%d %s",pa->ID,(*pa).name);
		for (j=0;j<3;)
			printf(" %d",pa->score[j++]);
		printf(" %f",pa->average);
		printf("\n");
		pa++;
	}
}
int main()
{
	int i,j;
	student s[10],*pa=s;
	Input(pa,10);
	for (i=0;i<10;i++)
	{
		if (s[i].average<60)
			{
				printf("%d %s",s[i].ID,s[i].name);
				for (j=0;j<3;)
					printf(" %d",s[i].score[j++]);
				printf(" %f",s[i].average);
				printf("\n");
			}
	}
	Sort(pa,10);
	Output(pa,10);
	return 0;
}
