#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int Element;
	struct node*Link;
}Node;
typedef int T;
T InputElement()
{
	T a ;
	scanf("%d",&a);
	return a;
}

Node *NewNode()
{
	Node*p=(Node*)malloc(sizeof(Node));
	if(!p)
	{
		fprintf(stderr,"The memery is full\n");
		exit(1);
	}
	p->Element=InputElement();
	p->Link=NULL;
	return p;
}

typedef Node*List;
List BuildList()
{
	Node *p,*r=NULL,*first=NULL;char c;
	printf("Another element? y/n");
	while((c=getchar())=='\n');
	while(tolower(c)!='n')
	{
		p=NewNode();
		if(first!=NULL)
			r->Link=p;
		else 
			first=p;
		r=p;
		printf("Another element ?y/n");
		while((c=getchar())=='\n');
	}
	return first;
}
void PrintList(List first)
{
	Node *p;
	p=first;
	printf("\n The list contains:\n");
	for(;p!=NULL;p=p->Link)
		printf("%d ",p->Element);
	printf("\n\n");
}

void Clear (List*first)
{
	Node *p=*first;
	while(*first)
	{
		p=(*first)->Link ;
		free(*first);
		*first=p;
	}
}

void main()
{
	List lst;
	lst=BuildList();
	PrintList(lst);
	Clear(&lst);
	PrintList(lst);
}

