#include <stdio.h>
#include <math.h>
int main()
{
	int year;
	double capital,sum,rate;
	printf("Enter year and capital\n");
	scanf("%d%lf",&year,&capital);
	switch (year)
	{
	case 1:
		rate=0.0325;
		break;
	case 2:
		rate=0.0375;
		break;
	case 3:
		rate=0.0425;
		break;
	case 5:
		rate=0.0475;
		break;
	default:
		rate=0;
		break;
	}
		if (rate==0)
		{
			printf("Error input!\n");
		}
		else
		{
			sum=pow((1+rate),year)*capital;
			printf("sum=%f\n",sum);
		}
		return 0;
}