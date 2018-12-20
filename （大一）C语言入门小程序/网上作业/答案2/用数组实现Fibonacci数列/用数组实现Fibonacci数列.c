#include<stdio.h>
main()
{
long int fib[ 40 ];
int i, n, cnt = 0;
scanf( "%d", &n );
fib[ 0 ] = 1;
fib[ 1 ] = 1;
for( i = 2; i < n; i++ )
{
fib[ i ] = fib[ i-1 ] + fib[ i-2 ];
}
for( i = 0; i < n; i++ )
{
printf( "%12d", fib[ i ] );
cnt++;
if( cnt % 6 == 0 ) printf( "\n" );
}
printf( "\n" );
getch();
}