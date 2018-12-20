/* Note:Your choice is C IDE */
#include "stdio.h"
#include "math.h"
int main()
{
    double a,b,c,s,area;
    scanf("%lf%lf%lf",&a,&b,&c);
    if(a<=0||b<=0||c<=0||(a+b)<=c||(c+b)<=a||(a+c)<=b)
    {
    	printf("Error!Please input again.");
    }
    else
    {
    	s=(a+b+c)/2;
    	area=sqrt(s*(s-a)*(s-b)*(s-c));
    	printf("Area=%.3f\n",area);
    }
    return 0;
}