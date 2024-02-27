#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *left;
	struct node *right;
};
struct node *insert(struct node *r,int key)
{
	struct node *n;
	if(r==NULL)
	{
		n=(struct node *)malloc (sizeof(struct node));
		n->data=key;
		n->left=NULL;
		n->right=NULL;
		r=n;
	}
	else if(key>r->data)
		r->right=insert(r->right,key);
	else if(key<r->data)
		r->left=insert(r->left,key);
	return r;
}
void inorder(struct node *r)
{
	if(r!=NULL)
	{
		inorder(r->left);
		printf("%d ",r->data);
		inorder(r->right);
	}
}
void preorder(struct node *r)
{
	if(r!=NULL)
	{
		printf("%d ",r->data);
		preorder(r->left);
		preorder(r->right);
	}
}
void postorder(struct node *r)
{
	if(r!=NULL)
	{
		postorder(r->right);
		postorder(r->left);
		printf("%d ",r->data);
	}
}
int smallest_element(struct node *r)
{
	while(r->left!=NULL)
		r=r->left;
	return r->data;
}
int greatest_element(struct node *r)
{
	while(r->right!=NULL)
		r=r->right;
	return r->data;
}
struct node *find(struct node *r,int e)
{
	while(r!=NULL)
		{
		if(e<r->data)
		{
			r=r->left;
		}
		else if(r->data<e)
		{
			r=r->right;
		}
		else
		{
			return r;
		}
	}
	return NULL;
}

int main()
{
	struct node *root=NULL;
	int i,n,val;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&val);
		root=insert(root,val);
	}
	inorder(root);
	printf("\n");
	preorder(root);
	printf("\n");
	postorder(root);
	printf("\n");
	printf("%d\n",smallest_element(root));
	printf("%d\n",greatest_element(root));
	printf("%d\n",find(root,5));
}
