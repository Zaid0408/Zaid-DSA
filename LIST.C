#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
void Insertrear();
void Del_front();
void display();
struct node
{
	int data;
	struct node *next;
};

struct node *start=NULL;


int main()
{

	int a;
	while(1)
	{
		printf("Enter 1 to add element\nEnter 2 to display list\nEnter 3 to delete element\nEnter 4 to exit\n");
		scanf("%d",&a);


		switch(a)
		{
			case 1:Insertrear();
			break;
			case 2:display();
			break;
			case 3:Del_front();
			break;
			case 4:exit(0);
			break;
			default:printf("invalid choice");
			break;


	}

	}
	return 0;
}


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
			printf("%d, ",temp->data);
			temp=temp->next;
		}
	}
}
