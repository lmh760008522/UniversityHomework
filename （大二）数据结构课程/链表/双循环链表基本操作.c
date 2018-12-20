#include <stdio.h>
#include <stdlib.h>
#include<malloc.h>
#define list Node*
typedef struct Node
{
	int data;
	struct Node *left,*right;
}Node;

Node *create()
{
    Node *p=NULL;
    int num;
    printf("请输入数据：\n");
    scanf("%d",&num);
	p=(Node*)malloc(sizeof(Node));
    p->data=num;
    p->right=NULL;
    p->left=NULL;
    return p;
}

Node* buildlist()
{
	Node *head=NULL,*p=NULL,*r=NULL,*q=NULL;
    int num;
    printf("输入0开始\n");
    scanf("%d",&num);
    while(num==0)
    {
		p=create();
		if(head==NULL)
    	{
		head=p;
        r=head;
        q=head;
    	}
   		else 
    	{
		r->right=p;
        r=p;
        r->left =q;
        q=p;
    	}
    	scanf("%d",&num);
    }
    q->right=head;
    printf("ok\n");
    return head;
}

void rightprint(Node *head)
{
	Node *p=head;
    while(head->right!=p)
    {
		printf("%d ",head->data);
        head=head->right;
    }
    printf("%d ",head->data );
    printf("\n");
}

void leftprint(Node *head)
{
	Node *p=head;
    while(head->left!=p)
    {
		printf("%d ",head->data);
        head=head->left;
    }
    printf("%d ",head->data );
    printf("\n");
}

void release(list *head)
{
	Node *p=(*head)->right,*q;
	(*head)->right=NULL;
	while(p)
	{
		q=p;
		p=p->right;
		free(q); 
	}
	printf("ok");
}

int main()
{
	Node *a;	
    a=buildlist();
    leftprint(a);
    rightprint(a);
    release(&a);
    return 0;
    
}
