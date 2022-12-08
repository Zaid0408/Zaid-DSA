#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
	struct node *prev;
};

struct node *Insertfront(struct node *start)
{
	struct node* newnode=(struct node*)malloc(sizeof(struct node));
	printf("ENter a number");
	scanf("%d",&newnode->data);
	if(start==NULL)
	{
		start=newnode;
		newnode->prev=start;
		newnode->next=NULL;
	}
	else
	{
		newnode->next=start;
		start=newnode;
		newnode->prev=start;
	}
	return start;
}


struct node *Insertrear(struct node *start)
{
	int num;
	struct node *new_node,*cur;
	new_node=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter a number");
	scanf("%d",&num);
	new_node->data=num;

	if(start==NULL)
	{
		start=new_node;
		new_node->prev=start;
		new_node->next=NULL;

	}
	else
	{
		cur=start;
		while(cur->next!=NULL)
		{
			cur=cur->next;
		}
		cur->next=new_node;
		new_node->prev=cur;
		new_node->next=NULL;
	}
	return start;
}
struct node* delete_front(struct node*start)
{
	struct node*temp;
	if(start == NULL)
	printf("Empty List");
	else if(start->next==NULL)
	{	
		free(start);
		start = NULL;
	}
	else
	{
		temp=start;
		start= start->next;
		free(temp);
		start->prev = NULL;
	}
    return start;
}

struct node* delete_rear(struct node*start)
{
	struct node*temp=start;
	if(start == NULL)
		printf("Empty List");
	else if(start->next==NULL)
	{	
		free(start);
		start = NULL;
	}
	else
	{
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp =temp->prev;
		free(temp->next);
		temp->next=NULL;
	}
	return start;
}

struct node* Insert_pos(struct node *start)
{
	struct node *cur,*newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	int pos,count=1;
	printf("Enter the elemnt to be inserted:\n");
	scanf("%d",&newnode->data);
	printf("Enter the position at which it has to be inserted:\n");
	scanf("%d",&pos);
	if(start== NULL)
	{
		printf("list is empty\n");
		return start;
	}
	if(pos==1)
	{
		newnode->next=start;
		start->prev=newnode;
		return newnode;
	}
	while(cur->next!=NULL)
	{
		if(pos==count+1)
		{
			newnode->next=cur->next;
			cur->next=newnode;
			newnode->prev=cur;
			
		}
		cur=cur->next;
		count +=1;
	}
	if(cur->next==NULL)
	{
		cur->next=newnode;
		newnode->next=NULL;
		newnode->prev=cur;
	}
	if(pos<1 && pos> count+1)
	{
		printf("Invalid Position");
		return start;
	}
	start=cur;
	return start;
}

void display(struct node *start)
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

int main()
{

	struct node *start=NULL;
	int a;
	while(1)
	{
		printf("\nEnter 1 to add element from before\nEnter 2 to display list\nEnter 3 to add element from rear\nEnter 4 to exit\nEnter 5 to delete front and\nEnter 6 to delete rear:\nEnter 7 to Insert at a given position\n");
		scanf("%d",&a);


		switch(a)
		{
			case 1:start=Insertfront(start);
			break;
			case 2:display(start);
			break;
			case 3:start=Insertrear(start);
			break;
			case 4:exit(0);
			break;
            case 5:start=delete_front(start);
            break;
            case 6:start=delete_rear(start);
            break;
			case 7:start=Insert_pos(start);
			break;
			default:printf("invalid choice");
			break;


		}

	}
	return 0;
}