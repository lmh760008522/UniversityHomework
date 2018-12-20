#include<stdio.h>
#include<stdlib.h>
#include<math.h>

static int Keymin,Keymax;//最大负载机器，最小负载机器
static int flag=0;
typedef struct Maiche
{
	int key;
	double time;
}Maiche;
Maiche maiche[4];

void buildMaiche(Maiche *a)
{
	int i=0;
	for(i=0;i<4;i++)
	{
		a[i].key=i;
		a[i].time=0;
	}
}

void selectmin(double *data,int *key)
{
	int i;
	double min=data[0];
	*key=0;
	for(i=1;i<4;i++)
	{
		if(min>data[i])
		{
			min=data[i];
			*key=i;
		}
	}
}

void sort(Maiche *Save)
{
	int i,j;
	Maiche temp;
	for(i=0;i<3;i++)
	{
		for(j=i+1;j<4;j++)
		{
			if(Save[i].time>Save[j].time)
			{
				temp=Save[i];
				Save[i]=Save[j];
				Save[j]=temp;
			}
		}
	}
}

int main()
{
	FILE *fp1;
	double data[4];//一个数据在4个机器上的运行时间 
	double save[6];//保存每个数据用时最少的机器 
	int i=0,j,flag=0,key=0;
	int maxLode;//最大负载机器 
	double maxTime,time;// 最大负载机器对应的时间 
	double penalty,minpenalty;
	buildMaiche(maiche);
	fp1=fopen("D:\\Almh\\study\\project\\cloudeclc\\data\\512_16\\test1.txt","r");
	if(fp1==0)
	{
		printf("error\n");
		exit(1);
	}
	while(fscanf(fp1,"%lf%lf%lf%lf",&data[0],&data[1],&data[2],&data[3])!=-1)
   {
		printf("%lf\t%lf\t%lf\t%lf\n",data[0],data[1],data[2],data[3]);
        selectmin(data,&key);//找到运行最小时间的机器 
        save[i++]=key;
		maiche[key].time+=data[key]; 
	}
	rewind(fp1);
	while(i<4)
	{
		i++;
		sort(maiche);
		maxLode=3;
		maxTime=maiche[3].time;
		for(i=0;i<3;i++)//除了最大负载的全部机器 
		{
			time=maiche[i].time;
			for(j=0;j<6;j++)
			{
				fscanf(fp1,"%lf%lf%lf%lf",&data[0],&data[1],&data[2],&data[3]);
				if(maiche[3].key==save[j])
				{
					if((time+data[maiche[i].key])<maxTime)
					{
						penalty=(data[maiche[i].key]-data[maiche[3].key])/data[maiche[3].key];
						if(flag==0)
						{
							minpenalty=penalty;
							maiche[3].time-=data[maiche[3].key];
							maiche[i].time+=data[maiche[i].key];
							save[j]=i;
							flag=1;
						} 
						else
						{
							if(minpenalty<penalty)
							{
								maiche[3].time-=data[maiche[3].key];
								maiche[i].time+=data[maiche[i].key];
								save[j]=i;
								flag=1;
							}
						}
					}
				}
			}
		} 
	}
 	printf("\n"); 
	printf("%d\t\t%d\t\t%d\t\t%d\n",maiche[0].key,maiche[1].key,maiche[2].key,maiche[3].key);
	printf("%lf\t%lf\t%lf\t%lf\n",maiche[0].time,maiche[1].time,maiche[2].time,maiche[3].time);
 	fclose(fp1);
 	return 0;
}



