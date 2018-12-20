#include <stdio.h> 
struct st 
{ 
int x, y;
};
struct st data[2]; 
int main ( ) 
{
scanf("%d%d",&data[0].x,&data[0].y);
data[1]=data[0];
printf("%d %d\n", data[1].x, data[1].y);
return 0; 
}