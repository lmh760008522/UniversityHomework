#include <stdio.h>
int main()
{
 int a[20] = {0};
 int res[20] = {0};
 int i, j, flag, total, delnum;
 i = j = flag = total = delnum = 0;
 scanf("%d", &a[total]);
 while(a[total] != 0)
 {
  total++;
  scanf("%d", &a[total]);
 }
 total++;
 scanf("%d", &delnum);
 printf("Before delete,elements are:\n");
 for(i = 0; i < total; i++)
 {
  printf("%5d",a[i]);
 }
 printf("\n");
 flag = 0;
 i = j = 0;
 while(a[i] != 0)
 {
  if(a[i] != delnum)
  {
   res[j] = a[i];
   j++;
  }
  else
  {
   flag = 1;
  }
  i++;
 }
 res[j] = a[i];
 j++;
total = j - 1;              
 if(flag == 0)
 {
  printf("does not exist,no operating!\n");
 }
 else
 {
  printf("After delete,elements are:\n");
  for(i = 0; i < j; i++)
  {
   printf("%5d",res[i]);
  }
  printf("\n");
 }
 return 0;
}