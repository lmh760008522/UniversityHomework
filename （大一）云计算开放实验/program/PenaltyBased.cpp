#include<stdio.h>
#include<stdlib.h>
#include<math.h>
static double maiche[4]={0};
static int Keymin,Keymax;//最大负载机器，最小负载机器
static int flag=0;
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

void selectmax(double *data,int *key)
{
	int i;
	double max=data[0];
	*key=0;
	for(i=1;i<4;i++)
	{
		if(max<data[i])
		{
			max=data[i];
			*key=i;
		}
	}
}

int main()
{
	FILE *fp1;
	double data[4];//一个数据在4个机器上的运行时间 
	double save[6];//保存每个数据用时最少的机器 
	int i=0,key;
	double penalty,minpenalty;
	fp1=fopen("D:\\Almh\\study\\project\\cloudeclc\\data\\512_16\\mytest.txt","r");
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
		maiche[key]+=data[key]; 
	}
	printf("\n");
	rewind(fp1);
	i=0;
	selectmin(maiche,&Keymin);//找最小负载机器 
	selectmax(maiche,&Keymax);//找最大负载机器 
	while(fscanf(fp1,"%lf%lf%lf%lf",&data[0],&data[1],&data[2],&data[3])!=-1)
    {
       if(save[i++]==Keymax)
       {
       		if((maiche[Keymin]+data[Keymin])<((maiche[Keymax]+maiche[Keymin])/2))
			{
				penalty=(data[Keymin]-data[Keymax])/data[Keymax];
			}
			if(flag==0)
			{
				minpenalty=penalty;
				maiche[Keymin]+=data[Keymin];
				maiche[Keymax]-=data[Keymax];
				flag=1;
			}
			else
			{
		    	if(penalty<minpenalty)
		    	{
		    		minpenalty=penalty;
					maiche[Keymin]+=data[Keymin];
					maiche[Keymax]-=data[Keymax];
				}
			}
	 	}
	}
	printf("\na\t\tb\t\tc\t\td\n");
	printf("%lf\t%lf\t%lf\t%lf\n",maiche[0],maiche[1],maiche[2],maiche[3]);
 	fclose(fp1);
 	return 0;
}

