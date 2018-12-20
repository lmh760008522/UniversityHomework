#include "stdio.h"
void Find(int *a, int n, int *max, int *maxPos, int *min, int *minPos)
{
	int i;
	*max = *min = *a;
	for ( i = 0; i < n; i++)
	{
		if (a[i]>*max)
		{
			*max = a[i];
			*maxPos = i;
		}
		if (a[i] < *min)
		{
			*min = a[i];
			*minPos = i;
		}
	}
}
int main()
{
	int max, maxPos, min, minPos;
	int array[10] = { 23, 45, 90, -9, 43, 90, 4, 2, -9 };
	Find(array, 9, &max, &maxPos, &min, &minPos);
	printf("max=%d, maxPos=%d, min=%d, minPos=%d\n", max, maxPos, min, minPos);
	return 0;
}