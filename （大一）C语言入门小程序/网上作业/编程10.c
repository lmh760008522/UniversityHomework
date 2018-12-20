#include "stdio.h"
#include "stdlib.h"
void create ( int a[], int n );
void print(int a[], int n);
int main()
{
	int n, *array;
	scanf("%d", &n);
	array = (int *)calloc(n, sizeof(int));
	create(array, n);
	print(array, n);
	free(array);
	return 0;
}
void create(int a[], int n)
{
	int i;
	for ( i = 0; i < n; i++)
	{
		a[i] = i + 1;
	}
}
void print(int a[], int n)
{
	int i;
	for ( i = 0; i < n; i++)
	{
		printf("%d,",a[i]);

	}
	printf("\n");
}