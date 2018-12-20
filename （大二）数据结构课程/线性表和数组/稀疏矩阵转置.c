#include<stdio.h>
typedef struct term
{
	int row,col;
	double data;
}term;
typedef struct triples
{
	int rows,cols,nonzeros;
	term element[20];
}triples;

triples transpose(triples a)
{
	triples b;
	int i,j;
	int num[20],k[20];
	int col=a.cols ,nonzeros=a.nonzeros ;
	b.cols =a.rows ;
	b.rows =a.cols ;
	if(nonzeros>0)
	{
	for(i=0;i<col;i++)
	{
		num[i]=0;
	}
	for(i=0;i<nonzeros;i++)
	{
		num[a.element [i].col]++;
	}
	k[0]=0;
	for(i=1;i<col;i++)
	{
		k[i]=k[i-1]+num[i-1];
	}
	for(i=0;i<nonzeros;i++)
	{
		j=k[a.element [i].col]++;
		b.element [j].row=a.element [i].col;
		b.element [j].col=a.element [i].row;
		b.element [j].data=a.element [i].data;
	}
    }
    return b;
}

void print(triples a)
{
	int i;
	for(i=0;i<a.nonzeros ;i++)
	{
		printf("%d\t%d\t%f\n",a.element [i].row,a.element [i].col,a.element [i].data);
	}
}

int main()
{

	
}
