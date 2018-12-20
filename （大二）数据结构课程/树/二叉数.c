#include<stdio.h>

typedef struct btnode
{
	int data;
	struct btnode *lnext,*rnext;
 } btnode;
 typedef struct btree
 {
 	struct btnode *root;
 }btree;
 
 
