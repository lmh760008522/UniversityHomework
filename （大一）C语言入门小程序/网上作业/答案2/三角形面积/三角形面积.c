#include <stdio.h>
#include <math.h>
int main()
{
  double a,b,c,s,Area;
  scanf("%lf%lf%lf",&a,&b,&c);
  if (a>0 && b>0 && c>0 && (a+b)>c && (a+c)>b && (b+c)>a)
  {
  	s=(a+b+c)/2;
  	Area=sqrt(s*(s-a)*(s-b)*(s-c));
    printf("Area=%.3f\n",Area);
  }
  else
  {
  	printf ("Error!Please input again.\n");
  }
  return 0;
}