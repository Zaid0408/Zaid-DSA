#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *left,*right;
};
typedef struct node* N;

N insert(N tree)
{
	N cur,parent;
	N newnode=(N)malloc(sizeof(struct node));
	printf("Enter the data:\n");
	scanf("%d",&newnode->data);
	newnode->right=NULL;
	newnode->left=NULL;
	if(tree==NULL)
	{
		tree=newnode;
		return tree;
	}
	else
	{
		parent=NULL;
		cur=tree;
		while(cur!=NULL)
		{
			parent=cur;
			if(newnode->data< cur->data)
				 cur=cur->left;
			else
				 cur=cur->right;
		}
	}
	if(newnode->data <parent->data)
		parent->left=newnode;
	else
		parent->right=newnode;

	return tree;
}

void pre(N tree)
{
	if(tree!=NULL)
	{
		printf("%d-> ",tree->data);
		pre(tree->left);
		pre(tree->right);
	}
}

void post(N tree)
{
	if(tree!=NULL)
	{
		
		post(tree->left);
		post(tree->right);
		printf("%d-> ",tree->data);
	}
}

void in(N tree)
{
	if(tree!=NULL)
	{
		
		in(tree->left);
		printf("%d-> ",tree->data);
		in(tree->right);
	}
}


int main()
{
	N tree=NULL;
	int i=0;
	while(i<5)
	{
		tree=insert(tree);
		i++;
	}
	printf("\nPre-Order is:\n");
	pre(tree);
	printf("\nPost-Order is:\n");
	post(tree);
	printf("\nIn-Order is:\n");
	in(tree);
	return 1;
}