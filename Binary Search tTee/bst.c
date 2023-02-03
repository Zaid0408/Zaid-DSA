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
N delete_BST(N tree, int val)
{
	N cur,parent;
	if(tree==NULL)
	{
		printf("Can not delete, Empty tree.\n");
		return tree;
	}
	cur=tree;
	parent=NULL;
	while((val!=cur->data) && (cur!=NULL))
	{
		parent=cur;
		if(val<cur->data)
		{
			cur=cur->left;
		}
		else
		{
			cur=cur->right;
		}
	}
	if(cur==NULL)
	{
		printf("Value is not present\n");
		return tree;
	}
	printf("\n The node to be deleted is %d",cur->data);
	if(cur->left==NULL && cur->right==NULL)
	{
		if(cur->data<parent->data)
		{
			parent->left=NULL;
		}
		else
		{
			parent->right=NULL;
		}
		printf("%d is deleted\n",cur->data);
	free(cur);
	}
	else if(cur->left==NULL)
	{
		if(cur->data<parent->data)
		{
			parent->left=cur->right;
		}
		else
		{
			parent->right=cur->right;
		}

	}

	else if(cur->right==NULL)
	{
	      if(cur->data<parent->data)
		{
			parent->left=cur->left;
		}
		else
		{
			parent->right=cur->left;
		}

	}
	else
	{
		N psuc,suc;
		psuc=cur;
		suc=cur->right;
		while(suc->left!=NULL)
		{
			psuc=suc;
			suc=suc->left;
		}
		cur->data=suc->data;
		if(psuc==cur)
		{
			psuc->right=suc->right;
		}
		else
		{
			psuc->left=suc->right;
		}
		printf("%d is deleted\n",suc->data);
		free(suc);
	}
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
    int ch,val;
	N tree=NULL;
	printf("\n1.Insert\n2.Inorder\n3.Preorder\n4.Postorder\n5.Delete\n6.Exit\n");
	while(1)
	{
        printf("Enter choice:\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				tree=insert(tree);
				break;
			case 2:
				in(tree);
				printf("\n");
				break;
			case 3:
				pre(tree);
				printf("\n");
				break;
			case 4:
				post(tree);
				printf("\n");
				break;
			case 5:
				printf("Enter value to delete\n");
				scanf("%d",&val);
				tree=delete_BST(tree,val);
				break;
			case 6:
				exit(0);
            default:printf("Invalid choice:");
                break;

		}
	}
	return 1;
}
