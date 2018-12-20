#include<stdio.h>
#include<stdlib.h>

void delete(double task[512][16],int min_min_task)//将任务Task映射到 P上后删除 
{
	int i,j;
	for(i=min_min_task;i>=0;i--){
		for(j=0;j<16;j++){
			task[min_min_task][j]=task[min_min_task-1][j];
		}
	} 
    for(j=0;j<16;j++){
		task[0][0]=0;
	}
}

int main()
{
	FILE *fp1;
	int i,j,t;
	double task[512][16]={0},p[16]={0},pro[16];
	double makespan;
	double min_time,min_min_time;
	int min_min_task,min_min_p,min_task,min_p;
	fp1=fopen("D:\\Almh\\study\\project\\cloudeclc\\data\\12\\u_s_lolo.0","r");
	if(fp1==0)
	{
		printf("error\n");
		exit(1);
	}
	for(i=0;i<512;i++)//将数据存入数组 
    {
		j=0;
		for(;j<16;j++)
		{
			fscanf(fp1,"%lf",&task[i][j]);
		}
	}
	for(t=0;t<512;t++){
		min_min_time=p[0]+=task[t][0];
		min_min_task=t;
		min_min_p=0; 
		for(i=t;i<512;i++){
			min_time=p[0]+=task[i][0];
			min_p=0;
			for(j=1;j<16;j++){
				p[j]+=task[i][j];
				if(min_time>p[j]){//找到每个任务最小完成时间 
					min_time=p[j];
					min_p=j;
				}
			}
			if(min_min_time<min_time){//找到最小完成时间的最大 
				min_min_time=min_time;
				min_min_task=i;
				min_min_p=min_p;
			}	
		}
		pro[min_min_p]+=task[min_min_task][min_min_p];//部署任务 
		for(j=0;j<16;j++){
			p[j]=pro[j];
		}
		delete(task,min_min_task);//删除任务 
	}
	makespan=pro[0];
	for(i=1;i<16;j++){
		if(pro[i]<makespan){
			pro[i]=makespan;
		}
	printf("%lf",makespan);
	fclose(fp1);
	return 0;
	}
	
}
