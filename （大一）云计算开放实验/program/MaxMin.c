#include<stdio.h>
#include<stdlib.h>
static double maiche[4]={0};
static double Max=0;
static int Key=0;
static int Judge=0;
static int Count=0;
void findmin(double *array,int a,int count)
{
	double min;
	int i=1,key=0;
	min=array[0]+maiche[0];
	while(i<4)//找到某个任务在四个机器运行后的最短时间 
	{
		if(array[i]+maiche[i]<min)
		{
			min=array[i]+maiche[i];
			key=i;
		}
		i++;
	}
	if(a==0)//初次运行赋值 
	{
		Max=min;
		Key=key;
		Judge=1;
		Count=count;
	}
	else
	{
		if(min>=Max)
		{
			Max=min;
			Key=key;
			Count=count;
		}
	}
}

void minmax(int Key,double Min)
{
	switch(Key)
	{
		case 0:maiche[0]=Max;break;
		case 1:maiche[1]=Max;break;
		case 2:maiche[2]=Max;break;
		case 3:maiche[3]=Max;break;
	}
}


int main()
{
	FILE *fp1,*fp2,*fp3;
	double data[4];//一个数据在4个机器上的运行时间 
	int count=1,j=6;//j为多少个数据，count计算行数 
	fp1=fopen("D:\\Almh\\study\\project\\cloudeclc\\data\\512_16\\mytest.txt","r");
	fp2=fopen("D:\\Almh\\study\\project\\cloudeclc\\data\\512_16\\mytest0.txt","w+");
	fp3=fopen("D:\\Almh\\study\\project\\cloudeclc\\data\\512_16\\mytest1.txt","w+");
	if(fp1==0||fp2==0)
	{
		printf("error\n");
		exit(1);
	}
	while(fscanf(fp1,"%lf%lf%lf%lf",&data[0],&data[1],&data[2],&data[3])!=-1)//将文件一复制到文件二 
    {
		printf("%lf\t%lf\t%lf\t%lf\n",data[0],data[1],data[2],data[3]);
    	fprintf(fp2,"%lf %lf %lf %lf\n",data[0],data[1],data[2],data[3]);
	}
	printf("\n");
	/*
	rewind(fp2);
	while((fscanf(fp2,"%lf %lf %lf %lf",&data[0],&data[1],&data[2],&data[3]))!=-1)
   	{
    	printf("%lf\t%lf\t%lf\t%lf\n",data[0],data[1],data[2],data[3]);
	}*/
	fclose(fp2);
    while(j>0)
    {	
    	count=1;
    	Judge=0;
    	fp2=fopen("D:\\Almh\\study\\project\\cloudeclc\\data\\512_16\\mytest0.txt","r+");
    	
    	//printf("dayin2 ");
		while((fscanf(fp2,"%lf %lf %lf %lf",&data[0],&data[1],&data[2],&data[3]))!=-1)//打印2 
    	{
			//printf("%lf\t%lf\t%lf\t%lf\n",data[0],data[1],data[2],data[3]);
			findmin(data,Judge,count);
    		count++;
		}
		//printf("\n");
    	minmax(Key,Max);
		count=1;
		rewind(fp2);
		fp3=fopen("D:\\Almh\\study\\project\\cloudeclc\\data\\512_16\\mytest1.txt","w+");
    	while((fscanf(fp2,"%lf %lf %lf %lf",&data[0],&data[1],&data[2],&data[3]))!=-1)//删除已完成任务 ,重写文件 
    	{
			if(count!=Count)
    	    {
				fprintf(fp3,"%lf %lf %lf %lf\n",data[0],data[1],data[2],data[3]);
		    }
		    count++;
		}
		fclose(fp2);
		rewind(fp3);
		/*
		printf("dayin3 ");
		while((fscanf(fp3,"%lf %lf %lf %lf",&data[0],&data[1],&data[2],&data[3]))!=-1)//打印3 
    	{
    		printf("%lf\t%lf\t%lf\t%lf\n",data[0],data[1],data[2],data[3]);
		}
		printf("\n");*/
		rewind(fp3);
		//printf("\n");
		fp2=fopen("D:\\Almh\\study\\project\\cloudeclc\\data\\512_16\\mytest0.txt","w+");
		while((fscanf(fp3,"%lf %lf %lf %lf",&data[0],&data[1],&data[2],&data[3]))!=-1)//将3复制到2 
    	{
    		fprintf(fp2,"%lf %lf %lf %lf\n",data[0],data[1],data[2],data[3]);
		}
		fclose(fp2);
		fclose(fp3);
		j--;
		//printf("%d jieshu1lun ",j);
		//printf("\n");
	}
	printf("\na\t\tb\t\tc\t\td\n");
	printf("%lf\t%lf\t%lf\t%lf\n",maiche[0],maiche[1],maiche[2],maiche[3]);
 	fclose(fp1);
	fclose(fp2);
 	return 0;
}
