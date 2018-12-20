#include<stdio.h>
enum Seasons {Spring,Summer,Autumn,Winter};
struct Date
{
	int year,month,day;
};
int main( )
{
	struct Date d;
	enum Seasons s;
	scanf("%d%d%d",&d.year,&d.month,&d.day);
	if (d.month>=3&&d.month<=5)
		s=Spring;
	else if(d.month>=6&&d.month<=8)
		s=Summer;
	else if (d.month>=9&&d.month<=11)
		s=Autumn;
	else if(d.month==12||d.month==1||d.month==2)
		s=Winter;
	switch(s)
	{
		case Spring: printf("Now it is Spring\n"); break;
		case Summer: printf("Now it is Summer\n"); break;
		case Autumn: printf("Now it is Autumn\n"); break;
		case Winter: printf("Now it is Winter\n"); break;
	}
	return 0;
}
