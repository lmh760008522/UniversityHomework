/* Note:Your choice is C IDE */
#include "stdio.h"
#include "stdlib.h"
struct student
{
	int num;
	char name[20];
	int age;
	double score;
};

void readout(struct student *pa,int n)
{
	FILE *fp;
	fp=fopen("D:\\Info.dat","r");
	fread(pa,sizeof(fp),1,fp);
	fclose(fp);
	
}
void sort(struct student *pa,int n)
{
	int i,j;
	struct student temp;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1;j++)
		{
			if(pa[j].score<pa[j+1].score)
			{
				temp=pa[j];
				pa[j]=pa[j+1];
				pa[j+1]=temp;
			}
		}
	}
}
void main()
{
    FILE  *fp;
    struct student st[3];
    int i;
    for(i=0;i<3;i++)
    {
    	scanf("%d %s %d %lf",&st[i].num,&st[i].name,&st[i].age,&st[i].score);
    }
    fp=fopen("D:\\Info.dat","w+");
    if(fp==0)
    {
    	printf("file error\n");
    }
    fwrite(&st,sizeof(st),1,fp);
    fread(&st,sizeof(st),1,fp);
    while(!feof(fp))
    {
    	printf("%d %s %d %lf",st->num,st->name,st->age,st->score);
    	fread(&st,sizeof(st),1,fp);
    }
    fclose(fp);
    readout(st,3);
    sort(st,3);
    fread(&st,sizeof(st),1,fp);
    while(!feof(fp))
    {
    	printf("%d %s %d %lf",st->num,st->name,st->age,st->score);
    	fread(&st,sizeof(st),1,fp);
    }
}