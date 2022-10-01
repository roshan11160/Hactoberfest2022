/*Soluttion for Binary Search Tree : Lowest Common Ancestor */



#include <bits/stdc++.h>
/*
Node is defined as 

typedef struct node
{
   int data;
   node * left;
   node * right;
}node;

*/

bool isPresent(struct node* tree, int k)
{
	if(tree==NULL)
		return false;
	if(tree->data==k)
		return true;
	return isPresent(tree->left,k) || isPresent(tree->right,k);
}


node * lca(node * tree, int m,int n)
{
    
	if(tree==NULL)
		return NULL;
	if(tree->data>m && tree->data>n)
		return lca(tree->left,m,n);
	if(tree->data<m && tree->data<n)
		return lca(tree->right,m,n);
	if(tree->data<m && tree->data>n)
	{
		if(isPresent(tree->left,n) && isPresent(tree->right,m))
		{
			return tree;
		}
		else 
			return NULL;
	}
	if(tree->data>m && tree->data<n)
	{
		if(isPresent(tree->left,m) && isPresent(tree->right,n))
		{
			return tree;
		}
		else 
			return NULL;
	}
	if(tree->data==m)
	{
		if(tree->data<n)
		{
			if(isPresent(tree->right,n))
				return tree;
			else
				return NULL;
		}
		if(tree->data>n)
		{
			if(isPresent(tree->left,n))
				return tree;
			else
				return NULL;
		}
		if(tree->data==n)
			return tree;
	}
	if(tree->data==n)
	{
		if(tree->data<m)
		{
			if(isPresent(tree->right,m))
				return tree;
			else
				return NULL;
		}
		if(tree->data>m)
		{
			if(isPresent(tree->left,m))
				return tree;
			else
				return NULL;
		}
		if(tree->data==m)
			return tree;
	}

    
	return NULL;
	
}
