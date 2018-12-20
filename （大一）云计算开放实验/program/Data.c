#include <stdio.h>
#include <stdlib.h>

double processor_fasttime[17];              //每一台机器最快完成的任务时间
int processor_fasttask[17];                  //每一台机器最快完成的任务编号

double processor_slowtime[17];             //每一台机器最慢完成的任务时间
int processor_slowtask[17];                //每一台机器最慢完成的任务编号

double task_average[513];                   //各任务在所有机器上执行的平均时间

double task_time[513][2];                     //每一个任务在各机器上的执行时间的最大值、最小值

int main()
{
	FILE *fp, *fp1, *fp2, *fp3, *fp4, *fp5;
	int flag = 1;
	double time;
	fp = fopen("//Users//romancekobe//Downloads//Braun_et_al//u_c_hihi.0", "r+");
	fp1 = fopen("//Users//romancekobe//Desktop//processor_slowtime.txt ", "w");
	fp2 = fopen("//Users//romancekobe//Desktop//processor_fasttime.txt ", "w");
	fp3 = fopen("//Users//romancekobe//Desktop//task_average.txt ", "w");
	fp4 = fopen("//Users//romancekobe//Desktop//task_maxtime.txt ", "w");
	fp5 = fopen("//Users//romancekobe//Desktop//task_mintime.txt ", "w");
	double sum = 0;
    for(int i = 1; i <= 16; i++)
    {
    	fscanf(fp, "%lf", &processor_slowtime[i]);
    	processor_fasttime[i] = processor_slowtime[i];
    	if(flag == 1)
    	{
    		task_time[1][0] = processor_slowtime[i];
    		task_time[1][1] = processor_slowtime[i];
    		flag = 0;
    	}
    	if(processor_slowtime[i] > task_time[1][0])
    		task_time[1][0] = processor_slowtime[i];
    	if(processor_slowtime[i] < task_time[1][1])
    		task_time[1][1] = processor_slowtime[i];
    	processor_slowtask[i] = 1;
    	processor_fasttask[i] = 1;
    	sum += processor_slowtime[i];
    }
    task_average[1] = sum / 16;
    flag = 1;
    for(int i = 2; i <= 512; i++)
    {
    	sum = 0;
    	for(int j = 1; j <= 16; j++)
    	{
    		fscanf(fp, "%lf", &time);
    		if(flag == 1)
    		{
    			task_time[i][0] = time;
    			task_time[i][1] = time;
    			flag = 0;
    		}
    		if(time > task_time[i][0])
    			task_time[i][0] = time;
    		if(time < task_time[i][1])
    			task_time[i][1] = time;
    		if(time < processor_fasttime[j])
    		{
    			processor_fasttime[j] = time;
    			processor_fasttask[j] = i;
    		}
    		if(time > processor_slowtime[j])
    		{
    			processor_slowtime[j] = time;
    			processor_slowtask[j] = i;
    		}
    		sum += time;
    	}
    	task_average[i] = sum / 16;
    	flag = 1;
    }
    for(int i = 1; i <= 16; i++)
    {
    	fprintf(fp1, "%f\n", processor_slowtime[i]);
    	fprintf(fp2, "%f\n", processor_fasttime[i]);
    }
    for(int i = 1; i <= 512; i++)
    {
    	fprintf(fp3, "%f\n", task_average[i]);
    	fprintf(fp4, "%f\n", task_time[i][0]);
    	fprintf(fp5, "%f\n", task_time[i][1]);
    }
    return 0;
}
