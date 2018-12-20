#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *fp1;
	double array[512][16]={0};
	int i=0,j=0;
	fp1=fopen("D:\\Almh\\study\\project\\cloudeclc\\data\\data1.txt","r");
	if(fp1==0)
	{
		printf("error\n");
		exit(1);
	}
	for(i=0;i<512;i++)
    {
		j=0;
		for(;j<16;j++)
		{
			fscanf(fp1,"%lf",&array[i][j]);
		}
	}
	for(i=0;i<512;i++)
    {
		j=0;
		for(;j<16;j++)
		{
			printf("%lf\t",array[i][j]);
		}
		printf("\n");
	}
	fclose(fp1);
	return 0;
	
 } 
