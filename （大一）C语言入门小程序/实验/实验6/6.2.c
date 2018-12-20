/* Note:Your choice is C IDE */
#include "stdio.h"
void main()
{
    int i=100,*p1;
    char c='a',*p2;
    float f=0.01f,*p3;
    double d=3.24,*p4;
    int arr[6]={11,22,33,44,55,66},*p5,num;
    p1=&i;
    p2=&c;
    p3=&f;
    p4=&d;
    p5=arr;
    printf("type name address size value *(pointer)\n\n");
    printf("int i%10p %3d %5d\n",&i,sizeof(i),i);
    printf("pointer p1 %10p %3d %10p %5d\n\n",&p1,sizeof(p1),i);
    printf("char c %10p %3d %3c\n",&c,sizeof(c),c);
    printf("pointer p2 %10p %3d %10p %3c\n\n",&p2,sizeof(p2),p2,*p2);
    printf("float f %10p %3d %6.2f\n",&f,sizeof(f),f);
    printf("pointer p3%10p %3d %10p %6.2f\n\n",&p3,sizeof(p3),p3,*p3);
    printf("double d %10p %3d %6.2f\n",&d,sizeof(d),d);
    printf("pointer p4 %10p %3d %10p %6.2f\n\n",&p4,sizeof(p4),p4,*p4);
    printf("array arr %10p %3d  ",arr,sizeof(arr));
    for(num=0;num<6;num++)
    {
    	printf("%d",arr[num]);
    	if(num!=5)
    	 printf(",");
    }
    printf("\n");
    printf("pointer p5 %10p %3d %10p %4d \n\n",&p5,sizeof(p5),p5,*p5);
    return 0;
}