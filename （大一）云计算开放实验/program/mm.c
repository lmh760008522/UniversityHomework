#include <stdio.h>
static double a=0,b=0,c=0,d=0;
void mm(double *array)
{ 
	double min;
	int i=1,key=0;
	min=array[0];
	while(i<4)
	{
		if(array[i]<min)
		{
			min=array[i];
			key=i;
		}
		i++;
	}
	switch(key)
	{
		case 0:a+=min;break;
		case 1:b+=min;break;
		case 2:c+=min;break;
		case 3:d+=min;break;
	}
	
}

int main()
{
	double array[4];
	int i=0,j;
	while(i<4)
	{
		for(j=0;j<4;j++)
		{
			array[j]=i+j;
		}
		for(j=0;j<4;j++)
		{
			printf("%lf\t",array[j]);
		}
		printf("\n");
		i++;
		mm(array);
	}
	printf("\na\t\tb\t\tc\t\td\n");
	printf("%lf\t%lf\t%lf\t%lf\n",a,b,c,d);
	return 0;	
}
