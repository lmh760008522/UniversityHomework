/* Note:Your choice is C IDE */
#include "stdio.h"
#include "string.h"
void main()
{
    char str[20];
    gets(str);
    puts(str);
    printf("sizeof(str)=%d\n",sizeof(str));
    printf("strlen(str)=%d\n",strlen(str));
    
}