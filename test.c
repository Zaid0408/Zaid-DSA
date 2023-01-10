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
		if(pos==(count+1))
		{
			newnode->next=cur->next;
			cur->next=newnode;
			newnode->prev=cur;
			break;
		}
		cur=cur->next;
		count +=1;
	}
	if(pos<1 && pos> count+1)
	{
		printf("Invalid Position");
		return start;
	}
	if(cur->next==NULL)
	{
		cur->next=newnode;
		newnode->next=NULL;
		newnode->prev=cur;
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
		printf("\nEnter 1 to add element from before\nEnter 2 to add element at a given position\nEnter 3 to display list\nEnter 4 to exit:\n");
        scanf("%d",&a);
        switch (a)
        {
            case 1:start=Insertfront(start);
            break;
            case 2:start=Insert_pos(start);
            break;
            case 3:display(start);
            break;
            case 4:exit(0);
            break;
            default:printf("no");
            break;
        }
    }
    return 0;
}