 #include<stdio.h>
int OctToBin(int n,int *p)
{	
int i,r,k=0;
	while (n)
	{	r=n%8;	    
    		for (i=1;i<=3;i++)  		{   
            p[k++]=r%2;	
			r=r/2;
		}
		n=n/8;
	}
	return k;
}
int main()
{
	int i,n,array[30],k;
	scanf("%o",&n);
k=OctToBin(n,array);
while(array[k-1]==0)k--;
	for(i=k-1;i>=0;i--)
		printf("%d",array[i]);
	printf("\n");
	return 0;
}     
