#include<stdio.h>
int main()
{
	FILE *fp1,*fp2;
	double data[4],a=0,b=1,c=2,d=3;
	int count=6;
	fp1=fopen("D:\\Almh\\study\\project\\cloudeclc\\data\\512_16\\mytest.txt","r");
	fp2=fopen("D:\\Almh\\study\\project\\cloudeclc\\data\\512_16\\mytest0.txt","w+");
	if(fp1==0||fp2==0)
	{
		printf("error\n");
	}
    while(fscanf(fp1,"%lf%lf%lf%lf",&data[0],&data[1],&data[2],&data[3])!=-1)
   {
		printf("%lf\t%lf\t%lf\t%lf\n",data[0],data[1],data[2],data[3]);
    	fprintf(fp2,"%lf  %lf  %lf  %lf\n",data[0],data[1],data[2],data[3]);
	}
	putchar('\n');
	rewind(fp2);
	rewind(fp1);
	
	while((fscanf(fp2,"%lf%lf%lf%lf",&data[0],&data[1],&data[2],&data[3]))!=-1)
   {
		printf("%lf\t%lf\t%lf\t%lf\n",data[0],data[1],data[2],data[3]);
	}
	printf("\n");
	fclose(fp2);
	fp2=fopen("D:\\Almh\\study\\project\\cloudeclc\\data\\512_16\\mytest0.txt","w+");
	while(count>0)
   {
    	fscanf(fp2,"%lf%lf%lf%lf",&data[0],&data[1],&data[2],&data[3]);
		if(count!=3)
		{
			fprintf(fp2,"%lf  %lf  %lf  %lf\n",data[0],data[1],data[2],data[3]);
		}
    	count--;
	}
	putchar('\n');
	rewind(fp2);
	while((fscanf(fp2,"%lf%lf%lf%lf",&data[0],&data[1],&data[2],&data[3]))!=-1)
    {
		printf("%lf\t%lf\t%lf\t%lf\n",data[0],data[1],data[2],data[3]);
	}
	printf("\n");
	rewind(fp2);
}
