#include<stdio.h>
#include<stdlib.h>

#define MAX 5
int left=-1;
int right=-1;
int ctr=0;
int deque[MAX];

void insert_right()
{
    int val;
    printf("\n Enter the value to be added:");
    scanf("%d", &val);
    if((left == 0 && right == MAX -1) || (left == right+1))
    {
        printf("\n OVERFLOW");
        return;
    }
    if (left == -1) /* if queue is initially empty */
    {
        left = 0; right = 0;
    }
    else
    {
        if(right == MAX-1) /*right is at last position of queue */
            right = 0;
        else
            right = right+1;
    }
    deque[right] = val ;
}
void insert_left()
{
    int val;
    printf("\n Enter the value to be added:");
    scanf("%d", &val);
    if((left == 0 && right == MAX-1) || (left == right+1))
    {
        printf("\n OVERFLOW");
        return;
    }
    if (left == -1) /* if queue is initially empty */
    {
        left = 0; right = 0;
    }
    else
    {
        if(right == 0) 
            left = MAX -1;
        else
            left = left+1;
    }
    deque[left] = val ;
}
void delete_left()

{

if (left == -1)

{

printf("\n UNDERFLOW");

return ;

}

printf("\n The deleted element is : %d", deque[left]);

if(left == right) /*Queue has only one element */

{

left = -1;

right = -1;

}

else

{

if(left == MAX-1)

left = 0;

else

left = left+1;

}

}

void delete_right()
{
    if (left == -1)
    {
        printf("\n UNDERFLOW");
        return ;
    }
    printf("\n The element deleted is : %d", deque[right]);
    if(left == right) /*queue has only one element*/
    {
        left = -1;
        right = -1;
    }
    else
    {
        if(right == 0)
            right=MAX-1;
        else
            right=right-1;
    }
}