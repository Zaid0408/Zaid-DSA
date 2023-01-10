#include <stdio.h>
#include <stdlib.h>


struct node
{
	int data;
	struct node *next;
};

typedef struct node* N;
N start=NULL;
N sorted=NULL;

void Insertrear()
{
	N new_node, cur;
	new_node=(N)malloc(sizeof(struct node));
	printf("\nEnter a number");
	scanf("%d",&new_node->data);
	new_node->next=NULL;
	if(start==NULL)
	{
		start=new_node;
        return;
	}
    else{
        cur=start;
	    while(cur->next!=NULL)
	    {
			cur=cur->next;
	    }
		cur->next=new_node;
    }
}
void display()
{
	N temp=(N)malloc(sizeof(struct node));
	temp=start;
	if(start==NULL)
	{
		printf("List Empty che\n");
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
	printf("NULL\n");
}
void sortedInsert(N newnode)
{
    /* Special case for the head end */
    if (sorted == NULL || sorted->data >= newnode->data) {
        newnode->next = sorted;
        sorted = newnode;
    }
    else {
        N current = sorted;
        /* Locate the node before the point of insertion
         */
        while (current->next != NULL
               && current->next->data < newnode->data) {
            current = current->next;
        }
        newnode->next = current->next;
        current->next = newnode;
    }
}
void sortSLL()
{
    struct node* cur = start;
  
    // Traverse the given linked list and insert every
    // node to sorted
    while (cur != NULL) {
  
        // Store next for next iteration
        struct node* next = cur->next;
  
        // insert current in sorted linked list
        sortedInsert(cur);
  
        // Update current
        cur = next;
    }
    // Update head to point to sorted linked list
    start = sorted;


    printf("\nList sorted probably\n");
}
int main()
{
    for(int i=1;i<=5;i++)
        Insertrear();
    printf("\n Orignal list is:\n");
    display();
    sortSLL();
    printf("\n Sorted list is:\n");
    display();
    return 1;
    
}