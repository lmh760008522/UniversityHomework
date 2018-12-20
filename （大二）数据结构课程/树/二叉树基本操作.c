#include<stdio.h>
#include<stdlib.h> 
typedef struct btnode
{
	int data;
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

btnode * newnode()
{
	btnode *p=(btnode*)malloc(sizeof(btnode));
	return p;
}

void makebt(btree *a,btree *l,btree *r)//conbine two tree into one with a new node 
{
	int x;
	printf("new data is :\n");
	scanf("%d",&x);
	btnode *p=newnode();
	p->data =x;
	p->lchild =l->root ;
	p->rchild =r->root ;
	l->root =r->root =NULL;
	a->root =p;
}

void breakbt(btree *a,btree *l,btree *r)
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
	printf("%d",p->data );
}

void preorder(btnode *p)//先序 
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



//层次递归 
/*void PrintNodeAtLevel(BiTree T,int level)
{
    // 空树或层级不合理
    if (NULL == T || level < 1 )
        return;

    if (1 == level)
    {
        cout << T->data << "  ";
        return;
    }

    // 左子树的 level - 1 级
    PrintNodeAtLevel(T->leftChild,  level - 1);

    // 右子树的 level - 1 级
    PrintNodeAtLevel(T->rightChild, level - 1);
}
void LevelTraverse(BiTree T)
{
    if (NULL == T)
        return;

    int depth = Depth(T);

    int i;
    for (i = 1; i <= depth; i++)
    {
        PrintNodeAtLevel(T, i);
        cout << endl;
    }
}*/ 

int main()
{
	return 0;
}
