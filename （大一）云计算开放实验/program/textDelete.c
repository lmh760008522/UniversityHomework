#include<stdio.h>
int main()
{
	FILE *fp1,*fp2,*fp3;
	double data[4];
	int count=6;
	fp1=fopen("D:\\Almh\\study\\project\\cloudeclc\\data\\512_16\\mytest.txt","r");
	fp2=fopen("D:\\Almh\\study\\project\\cloudeclc\\data\\512_16\\mytest0.txt","w+");
	fp3=fopen("D:\\Almh\\study\\project\\cloudeclc\\data\\512_16\\mytest1.txt","w+");
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
	
	while((fscanf(fp2,"%lf%lf%lf%lf",&data[0],&data[1],&data[2],&data[3]))!=-1)
   {
		printf("%lf\t%lf\t%lf\t%lf\n",data[0],data[1],data[2],data[3]);
	}
	printf("\n");
	rewind(fp2);
	
	
    while((fscanf(fp2,"%lf%lf%lf%lf",&data[0],&data[1],&data[2],&data[3]))!=-1)//删除已完成任务 ,重写文件 
    	{   
			//fscanf(fp2,"%lf%lf%lf%lf",&data[0],&data[1],&data[2],&data[3]);
			//printf("%lf\t%lf\t%lf\t%lf\n",data[0],data[1],data[2],data[3]);	
			if(count!=3)
    	    {
    	    	fprintf(fp3,"%lf  %lf  %lf  %lf\n",data[0],data[1],data[2],data[3]);
    	    	
		    }
		    count--;
		    
		}
		rewind(fp3);
		fclose(fp2);
		printf("\n");
	while((fscanf(fp3,"%lf%lf%lf%lf",&data[0],&data[1],&data[2],&data[3]))!=-1)
   {
		printf("%lf\t%lf\t%lf\t%lf\n",data[0],data[1],data[2],data[3]);
	}
	printf("\n");
	rewind(fp3);
	fp2=fopen("D:\\Almh\\study\\project\\cloudeclc\\data\\512_16\\mytest0.txt","w+");
	 while(	fscanf(fp3,"%lf%lf%lf%lf",&data[0],&data[1],&data[2],&data[3])!=-1)
    {
		printf("%lf\t%lf\t%lf\t%lf\n",data[0],data[1],data[2],data[3]);
    	fprintf(fp2,"%lf  %lf  %lf  %lf\n",data[0],data[1],data[2],data[3]);
	}
	//fprintf(fp2,"\n");
	putchar('\n');
	rewind(fp2);
	while((fscanf(fp2,"%lf%lf%lf%lf",&data[0],&data[1],&data[2],&data[3]))!=-1)
   {
		printf("%lf\t%lf\t%lf\t%lf\n",data[0],data[1],data[2],data[3]);
	}
	
	fclose(fp1);
	fclose(fp2);
	fclose(fp3);
	return 0;
}
