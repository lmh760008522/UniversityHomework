#include <stdio.h>
#include <stdlib.h>
void create(int a[],int n)
{
 int i;
 for(i=0;i<n;i++)
 {
  a[i]=i+1;
 }
}
void print(int a[],int n)
{
 int i;
 for(i=0;i<n;i++)
 {
  printf("%d,",a[i]);
 }
}

int main() {

 int *array,n;
 
 scanf("%d",&n);
 array=(int*)malloc(n*sizeof(int));
 create(array,n);
 print(array,n);
 printf("\n");
 return 0;

}