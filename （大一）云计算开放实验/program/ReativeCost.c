#include<stdio.h>
#include<stdlib.h>
#include<math.h>
static double maiche[4]={0};
static double Min=0;
static int Key=0;
int key=0;


ReativeCost(double *data)
{
	double rs,rd;
	double average=(data[0]+data[1]+data[2]+data[3])/4;
	double t;
	int i;
	rs=data[0]/average;
	rd=maiche[0]+data[0];
	t=pow(rs,0.5)*rs;
	for(i=1;i<4;i++)
	{
		rs=data[i]/average;
		rd=maiche[i]+data[i];
		if(t>pow(rs,0.5)*rs)
		{
			t=pow(rs,0.5)*rs;
			key=i;
		}
	}
	maiche[key]+=data[key];
}
int main()
{
	FILE *fp1;
	double data[4];//一个数据在4个机器上的运行时间 
	fp1=fopen("D:\\Almh\\study\\project\\cloudeclc\\data\\512_16\\mytest.txt","r");
	if(fp1==0)
	{
		printf("error\n");
		exit(1);
	}
	while(fscanf(fp1,"%lf%lf%lf%lf",&data[0],&data[1],&data[2],&data[3])!=-1)
   {
		printf("%lf\t%lf\t%lf\t%lf\n",data[0],data[1],data[2],data[3]);
    	ReativeCost(data);
	}
	printf("\n");
	rewind(fp1);
	printf("\na\t\tb\t\tc\t\td\n");
	printf("%lf\t%lf\t%lf\t%lf\n",maiche[0],maiche[1],maiche[2],maiche[3]);
 	fclose(fp1);
 	return 0;
}

