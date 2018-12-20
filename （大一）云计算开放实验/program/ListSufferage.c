#include<stdio.h>
#include<stdlib.h>
static double maiche[4]={0};

typedef struct term
{
	int key;//机器
	int i; 
	double piority;
}term;

term piorityValues[6];

void select(double *min1,double *min2,double *data,int *key1,int *key2)
{
	int i;
	*min1=data[0];
	*key1=0;
	for(i=1;i<4;i++)
	{
		if(*min1>data[i])
		{
			*min1=data[i];
			*key1=i;
		}
	}
	if(*key1==0)
	{
		*min2=data[1];
		*key2=1;
	}
	else
	{
		*min2=data[0];
		*key2=0;
	}
	for(i=0;i<4;i++)
	{
		if((i!=*key1)&&(*min2>data[i]))
		{
			*min2=data[i];
			*key2=i;
		}
	}
}

double ListSufferage(double *data,int *key1)
{
	double min1,min2;
	int key2,i;
	double piority;
	select(&min1,&min2,data,key1,&key2);
	for(i=0;i<4;i++)
	{
		if(i==*key1)
		{
			piority=min2/min1;
		}
		else
		{
			piority=min1/data[i];
		}
	}
	return piority;
}

void sort(term *Save)
{
	int i,j,tempi,tempk;
	double temp;
	for(i=0;i<5;i++)
	{
		for(j=i+1;j<6;j++)
		{
			if(Save[i].piority<Save[j].piority)
			{
				temp=Save[i].piority;
				Save[i].piority=Save[j].piority;
				Save[j].piority=temp;
				tempi=Save[i].i;
				Save[i].i=Save[j].i;
				Save[j].i=tempi;
				tempk=Save[i].key;
				Save[i].key=Save[j].key;
				Save[j].key=tempk;
		}
	}
}

int main()
{
	FILE *fp1;
	int i=0;
	double key;
	double data[4];
	fp1=fopen("D:\\Almh\\study\\project\\cloudeclc\\data\\512_16\\mytest.txt","r");
	if(fp1==0)
	{
		printf("error\n");
		exit(1);
	}
	while(fscanf(fp1,"%lf%lf%lf%lf",&data[0],&data[1],&data[2],&data[3])!=-1)
   {
		printf("%lf\t%lf\t%lf\t%lf\n",data[0],data[1],data[2],data[3]);
    	piorityValues[i].piority+=ListSufferage(data,&key);
    	piorityValues[i].i=i;
    	piorityValues[i].key=key;
    	i++;
	}
	printf("\n");
	rewind(fp1);
	sort(piorityValues);
	//根据顺序安排任务 
	printf("\na\t\tb\t\tc\t\td\n");
	printf("%lf\t%lf\t%lf\t%lf\n",maiche[0],maiche[1],maiche[2],maiche[3]);
 	fclose(fp1);
 	return 0;
}
