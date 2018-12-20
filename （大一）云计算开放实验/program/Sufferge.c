#include<stdio.h>
#include<stdlib.h>
static double maiche[4]={0};
static int i=0;

typedef struct term
{
	int key;//机器
	double time;//时间跨度 
	double sufferage;
}term;

term Save[6];

void select(double *min1,double *min2,double *data,int *key)
{
	int i;
	*min1=data[0];
	*key=0;
	for(i=1;i<4;i++)
	{
		if(*min1>data[i])
		{
			*min1=data[i];
			*key=i;
		}
	}
	if(key==0)
	{
		*min2=data[1];
	}
	else
	{
		*min2=data[0];
	}
	for(i=0;i<4;i++)
	{
		if((i!=*key)&&(*min2>data[i]))
		{
			*min2=data[i];
		}
	}
}

void clculate(double *data)
{
	double min1,min2;
	double time=0;
	double sufferage;
	int key;
	select(&min1,&min2,data,&key);
	sufferage=min1-min2;
	Save[i].sufferage=sufferage;
	Save[i].key=key;
	Save[i].time=data[key];
	i++;
	/*
	for(i=1;i<4;i++)
	{
		if((maiche[i]+data[i])<min1)
		{
			min2=min1;
			min1=maiche[i]+data[i];
		}
		else if((maiche[i]+data[i])<min2)
		{
			min2=maiche[i]+data[i];
		}
	}
	sufferage=min2-min1;
	if(maiche[Key1]==0)
	{
		maiche[Key]+=data[Key1];
	}
	else if(sufferage>time)
	{
		
	}*/
}

void sort(term *Save)
{
	int i,j,temp0;
	double temp;
	for(i=0;i<5;i++)
	{
		for(j=i+1;j<6;j++)
		{
			if(Save[i].sufferage>Save[j].sufferage)
			{
				temp=Save[i].time;
				Save[i].time=Save[j].time;
				Save[j].time=temp;
				temp0=Save[i].key;
				Save[i].key=Save[j].key;
				Save[j].key=temp;
			} 
		}
	}
}

void Sufferage()
{
	int i;
	sort(Save);
	for(i=0;i<6;i++)
	{
		maiche[Save[i].key]+=Save[i].time;
	}
}

int main()
{
	FILE *fp1;
	double data[4];//一个数据在4个机器上的运行时间 
	fp1=fopen("D:\\Almh\\study\\project\\cloudeclc\\data\\512_16\\test1.txt","r");
	if(fp1==0)
	{
		printf("error\n");
		exit(1);
	}
	while(fscanf(fp1,"%lf%lf%lf%lf",&data[0],&data[1],&data[2],&data[3])!=-1)
   {
		printf("%lf\t%lf\t%lf\t%lf\n",data[0],data[1],data[2],data[3]);
    	clculate(data);
	}
	Sufferage();
	printf("\n");
	rewind(fp1);
	printf("\na\t\tb\t\tc\t\td\n");
	printf("%lf\t%lf\t%lf\t%lf\n",maiche[0],maiche[1],maiche[2],maiche[3]);
 	fclose(fp1);
 	return 0;
}
