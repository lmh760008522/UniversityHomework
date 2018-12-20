/* Note:Your choice is C IDE */
#include "stdio.h"

int main()
{
    double x,y;
    scanf("%lf",&x);
    if(x<20)
      y=x+100;
    else if(x>=20&&x<=100)
      y=x;
    else if (x>100)
      y=x-100;
    printf("x=%f,y=%f",x,y);
    return 0;
}