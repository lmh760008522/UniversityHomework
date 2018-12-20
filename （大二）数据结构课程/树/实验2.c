#include<stdio.h>
#include<stdlib.h> 
#define list Node*

//二叉树定义 

typedef struct btnode//定义二叉树
{
	char data;
	struct btnode *lchild,*rchild;
}btnode;
typedef struct btree
{
	struct btnode *root;
}btree;

void createbt(btree *a) //create a empty tree
{
	a->root = NULL;
}

btnode *newnode()
{
	btnode *p=(btnode*)malloc(sizeof(btnode));
	return p;
}

void breakbt(btree *a,btree *l,btree *r)//删除根节点
{
	btnode *p=a->root ;
	if(p!=NULL)
	{
		l->root =p->lchild ;
		r->root =p->rchild ;
		free(p);
		a->root =NULL;
	}
}

void visit(btnode *p)//visit 
{
	printf("%c",p->data );
}

void preorder(btnode *p)//先序遍历
{
	if(p!=NULL)
	{
		visit(p);
		preorder(p->lchild );
		preorder(p->rchild );
	}
}
void pre(btree *a)
{
	preorder(a->root );
}

void inorder(btnode *p)//中序 
{
	if(p!=NULL)
	{
		inorder(p->lchild );	
		visit(p);
		inorder(p->rchild );	
	}
}
void in(btree *a)
{
	inorder(a->root );
}

void postorder(btnode *p)//后序 
{
	if(p!=NULL)
	{
		postorder(p->lchild );	
		postorder(p->rchild );
		visit(p);	
	}
}
void post(btree *a)
{
	postorder(a->root );
}

//队列定义 
typedef struct Node
{
	btnode *data;
    struct Node *next;
}Node;

typedef struct queue
{
	Node *front,*rear;
 } queue;
 
 Node *create(btnode *num)
{
    Node *p=NULL;
	p=(Node*)malloc(sizeof(Node));
    p->data=num;
    p->next=NULL;
    return p;
}

int isempty(queue *q)
{
	if(q->front==NULL)
		return 1;
	else 
		return 0;
}

void append(queue *q,btnode *num)
{
	Node *p;
	p=create(num);
	if(q->front ==NULL)
	{
		q->front =p;
		q->rear =p; 
	}
	else
	{
		q->rear->next=p;
		q->rear=p;
	}
}

btnode* pop(queue *q)
{
	Node *p;
	btnode *c;
	if(isempty(q))
	{
		printf("empty\n");
	}
	else
	{
		p=q->front ;
		c=p->data ;
		q->front =p->next ;
		free(p);
	}
	return c;
}

void queuefront(queue *q,btnode *x)
{
	Node *p=q->front ;
	if(isempty(q))
	{
		printf("empty\n");
	}
	else
	{
		x=p->data;
	}
}


//二叉树应用 

btnode * precreate1()
{
	char c;
	btnode *p;
	printf("请输入前序序列,以#结束:\n");
	scanf("%c",&c);
	if(c!='#')
	{
		p=newnode();
		p->data =c;
		p->lchild=p->rchild =NULL;
		p->lchild=precreate1();	
		p->rchild=precreate1();	
	}
	else
	{
		p=NULL;
	}
	return p;
}
void precreate(btree *a)//递归建立二叉树
{
	a->root =precreate1();
}

void arrcreate(btree *a)//数组存放二叉树
{
	char c;
	int i,j;
	btnode *arr[32];
	btnode *p;
	printf("输入一个字符和位置,如A,1：（#,0结束）\n");
	scanf("%c,%d",&c,&i);
	while(c!='#'&&i!=0)
	{
		if(i<32)
		{
			p=newnode();
			p->data=c;
			p->lchild =p->rchild =NULL;
			arr[i]=p;
			if(i!=1)
			{
				j=i/2;
				if(j%2==0)
				{
					arr[j]->lchild =p;
				}
				else
				{
					arr[j]->rchild =p;
				}
			}
			printf("go on\n");
			scanf("%c,%d",&c,&i);
		}
		else
		{
			printf("full!\n");
			break;
		}
	}
	a->root =arr[1];
}

int max(int a,int b)
{
	if(a>b)
		return a;
	else 
		return b;
}
int depth(btnode *p)
{
	if(!p)
		return 0;
	else
		return 1+max(depth(p->lchild),depth(p->rchild ));
}
void clchight(btree *a)//height
{
	btnode *p=a->root ;
	printf("高度为：%d\n",depth(p));
}

int size(btnode *p) 
{
	if(!p)
		return 0;
	else
		return 1+size(p->lchild )+size(p->rchild );
}
void clcsize(btree *a)//计算结点 
{
	btnode *p=a->root ;
	printf("结点数为：%d\n",size(p));
}

void change(btnode *p)
{
	btnode *t;
	if(p->lchild ||p->rchild )
	{
		if(p->lchild )
			change(p->lchild );
		if(p->rchild )
			change(p->rchild );
		t=p->rchild ;
		p->rchild =p->lchild ;
		p->lchild =t;
	}
}
void exchange(btree *a)//交换左右子树 
{
	change(a->root );
}

void layerorder(btree *a)//层次遍历 
{
	btnode *p=a->root ,*q;
	queue *t;
	append(t,p);
	while(!isempty(t))
	{
		q=pop(t);
		printf("%c ",q->data );
		append(t,q->lchild );
		append(t,q->rchild );
	}
	printf("\n");
}

int main()
{
	int i;
	btree *a;
	printf("==========主菜单==========\n");
	printf("输入1：递归建立二叉树     \n");
	printf("输入2：数组建立二叉树     \n");
	printf("输入3：先序打印二叉树     \n");
	printf("输入4：中序打印二叉树     \n");
	printf("输入5：后序打印二叉树     \n");
	printf("输入6：层次打印二叉树     \n");
	printf("输入7：计算二叉树的高度   \n");
	printf("输入8：计算二叉树的结点数 \n");
	printf("输入9：交换二叉树左右子树 \n");
	printf("输入0：退出               \n");
	printf("==========================\n");
	scanf("%d",&i);
	while(i!=0)
	{ 
	switch(i)
	{
	case(1):
		precreate(a);
		break;
    case(2):
    	arrcreate(a);
		break;
	case(3):
		if(a)
		{
			preorder(a->root );
		}
		else
		{
			printf("non exist!\n");
		}
		break;
	case(4):
		if(a)
		{
			inorder(a->root );
		}
		else
		{
			printf("non exist!\n");
		}break;
	case(5):
		if(a)
		{
			postorder(a->root );
		}
		else
		{
			printf("non exist!\n");
		}
		break;
	case(6):
		if(a)
		{
			layerorder(a);
		}
		else
		{
			printf("non exist!\n");
		}
		break;
	case(7):
		if(a)
		{
			clchight(a);
		}
		else
		{
			printf("non exist!\n");
		}
		break;
	case(8):
	    if(a)
		{
			clcsize(a);
		}
		else
		{
			printf("non exist!\n");
		}
		break;
	case(9):
	    if(a)
		{
			exchange(a);
		}
		else
		{
			printf("non exist!\n");
		}
		break;
    scanf("%d",&i);
	}
}
printf("结束，谢谢使用!\n");
	return 0;
}
