#include<stdio.h>
#define LEAP_YEAR(y)   (y)%4==0&&(y)%100!=0||(y)%400==0
void main()
{
   int year;
   scanf("%d",&year);
   if(year>=1000 && year<=9999)
   {
      if(LEAP_YEAR(year))
	  {
        printf("%d is a leap year!\n", year);
	  }
      else
	  {
      printf("%d is not a leap year!\n", year);
	  }
   } 
   else
   {
      printf("Input error!\n");
   }
}