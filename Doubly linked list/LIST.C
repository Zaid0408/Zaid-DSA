  
  

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node{
	int data;
	struct node *prev;
	struct node *rlink;
};


struct node * insert_front(int item, struct node * first){
	struct node * t;
	t = (struct node *)malloc(sizeof(struct node));
	t -> data = item;
	t -> prev = NULL;
	t -> rlink = first;
	first -> prev = t;
	return t;
}

struct node * insertBefore(struct node * first)
{
	int val;
	struct node *newnode,*cur;
	printf("Enter the element to be inserted: ");
	scanf("%d",&newnode->data);
	printf("Enter the value before which the element has to be inserted:");
	scanf("%d",&val);
	if(first==NULL)
	{
		printf("EMpty list\n");
		return first;
	}
	cur=first;
	while( cur->data!= val || cur->next== NULL)
	{
		cur=cur->next;
	}
	cur=insert_front(newnode->data,cur);
}


struct node * delete_mid(struct node * first){
	int len = 0;
	int mid;
	int count = 0;
	struct node * c = first;
	while(c != NULL)
	{
		len++;
		c = c -> rlink;
	}
	if(len == 0)
	{
		printf("List is empty\n");
		return first;
	}
	c = first;
	mid = len/2 + len%2;
	while(count != mid-1)
	{
		count++;
		c = c -> rlink;
	}
	if(c -> prev == NULL && c -> rlink == NULL)
	{
		printf("last element reached");
		return NULL;
	}
	if(c == first){
		c -> rlink -> prev = NULL;
		return c -> rlink;
	}
	c -> prev -> rlink = c -> rlink;
	c -> rlink -> prev = c -> prev;
	return first;
}

void display(struct node * first){
	struct node * c = first;
	if(c == NULL)
		printf("List is empty_disp\n");
	while(c != NULL){
		printf("%d\t", c -> data);
		c = c -> rlink;
	}
	printf("\n");
}

int main(){
	int choice, item;
	struct node * first;
	first = NULL;
	while(1){
	printf("\nEnter your choice -\n1. Insert front\t2. Delete mid\n3. Display\n");
	scanf("%d", &choice);
	switch(choice){
		case 1:
			printf("Enter item - \n");
			scanf("%d", &item);
			first = insert_front(item, first);
			break;
		case 2:
			first = delete_mid(first);
			break;
		case 3:
			display(first);
			break;
		case 4:exit(0);
			break;
	}
	}
	return 1;
}
