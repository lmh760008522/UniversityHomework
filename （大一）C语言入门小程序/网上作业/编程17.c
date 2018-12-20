/* Note:Your choice is C IDE */
#include "stdio.h"
enum Seasons {Spring,Summer,Autumn,Winter};
struct Date
{

       int year,month,day;

};
typedef enum Seasons seasons;
typedef struct Date date;
int main()
{
    seasons s;
    date d;
    scanf("%d%d%d",&d.year,&d.month,&d.day);
    if(d.month>=3&&d.month<=5)
      s=0;
    if(d.month>=6&&d.month<=8)
      s=1;
    if(d.month>=9&&d.month<=11)
      s=2;
    if(d.month>=12&&d.month<=2)
      s=3;
    switch(s)
    {
    	case 0:printf("Now it is Spring\n");break;
    	case 1:printf("Now it is Summer\n");break;
    	case 2:printf("Now it is Autumn\n");break;
    	case 3:printf("Now it is Winter\n");break;
    }
    return 0;
}