#include <stdio.h>
#include <stdlib.h>


struct node
{
	int data;
	struct node *next;
};

struct node *start=NULL;

void Insertrear()
{
	int num;
	struct node *new_node, *cur;
	new_node=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter a number");
	scanf("%d",&num);
	new_node->data=num;
	new_node->next=NULL;
	if(start==NULL)
	{
		start=new_node;
	}
	else
	{
		cur=start;
		while(cur->next!=NULL)
		{
			cur=cur->next;
		}
		cur->next=new_node;

	}
}
void Del_front()
{
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	if(start == NULL)
	{
		printf("List is empty");
	}
	else
	{
		temp=start;
		start=start->next;
		free(temp);
	}
}

void display()
{
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp=start;
	if(start==NULL)
	{
		printf("List Empty che");
		return;
	}
	else
	{
		printf("The contents of the list are:");
		while(temp!=NULL)
		{
			printf("%d -> ",temp->data);
			temp=temp->next;
		}
	}
	printf("\n");
}
void Insertfront()
{
	struct node *temp,*cur;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter a Number:\n");
	scanf("%d",&temp->data);
	temp->next=start;
	start=temp;
}
void Del_rear()
{
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	struct node *temp2=(struct node*)malloc(sizeof(struct node));
	if(start==NULL)
	{
		printf("List is empty\n");

	}
	else if(start->next==NULL)
	{
		start=NULL;
		free(temp);
	}
	else{
		temp=start;
		while(temp->next!= NULL)
		{
			temp2=temp;
			temp=temp->next;

		}
		temp->next=NULL;
		free(temp);
	}
}
void Insert_before()
{
	struct node *newnode,*cur,*prev;
	newnode=(struct node*)malloc(sizeof(struct node));
	int val;
	printf("Enter the number to be inserted:\n");
	scanf("%d",&newnode->data);
	printf("Enter the value before which the number has to be inserted:\n");
	scanf("%d",&val);
	cur=start;
	if(start==NULL)
	{
		printf("List empty\n");
		free(newnode);
		return;
	}
	while(cur!=NULL)
	{
		if(cur->data==val)
			break;
		prev=cur;
		cur=cur->next;
	}
	if(cur==start)
	{
		newnode->next=start;
		start=newnode;
	}

	else if(cur==NULL)
	{
		printf("Element not present in the linked list\n");
	}
	else
	{
		newnode->next=cur;
		prev->next=newnode;
	}
}
void Insert_after()
{
	struct node *newnode,*cur,*prev;
	newnode=(struct node*)malloc(sizeof(struct node));
	int val;
	printf("Enter the number to be inserted:\n");
	scanf("%d",&newnode->data);
	printf("Enter the value after which the number has to be inserted:\n");
	scanf("%d",&val);
	cur=start;
	if(start==NULL)
	{
		printf("List empty\n");
		free(newnode);
		return;
	}
	while(cur!=NULL)
	{
		if(cur->data==val)
			break;
		cur=cur->next;
	}
	if(cur==start)
	{
		newnode->next=start;
		start=newnode;
	}
	else if(cur==NULL)
	{
		printf("Element not present in the linked list\n");
	}
	else
	{
		newnode->next=cur->next;
		cur->next=newnode;
	}

}
int main()
{

	int a;
	while(1)
	{
		printf("\nEnter 1 to add element to the rear\nEnter 2 to add element to the front list\nEnter 3 to delete element from the front\nEnter 4 to delete element from the rear\nEnter 5 to exit\nEnter 6 to display list:\nEnter 7 to insert before a given element\nEnter 8 to insert after a given element\n");
		scanf("%d",&a);


		switch(a)
		{
			case 1:Insertrear();
			break;
			case 2:Insertfront();
			break;
			case 3:Del_front();
			break;
			case 4:Del_rear();
			break;
			case 5:exit(0);
			break;
			case 6:display();
			break;
			case 7:Insert_before();
			break;
			case 8:Insert_after();
			break;
			default:printf("invalid choice");
			break;
		}

	}
	return 0;
}

