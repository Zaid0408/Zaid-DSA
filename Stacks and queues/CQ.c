#include<stdio.h>
#include<stdlib.h>

#define max 5
int f=0;
int r=-1;
int ctr=0;
int q[max];
int full()
{
    if(ctr==max)
    {
        return 1;
    }
    else{
        return 0;
    }
}
int empty()
{
    if(ctr==0)
    {
        return 1;
    }
    else {
        return 0;
    }
}

void insert(int value)
{
    if(!full())
    {
        r=(r+1)%max;
        q[r]=value;
        ctr++;
    }
    else
    {
        printf("List is full");
    }
}
int delete()
{
    
    if(!empty())
    {
        int temp;
        temp=q[f];
        f=(f+1)%max;
        ctr--;
        return temp;

    }
    else
    {
        printf("Empty list\n");
        return -1;

    }
}
void display()
{ int i=f,p=ctr;
    if(!empty())
    {
        
        while(p>0)
        {
            printf("%d ",q[i]);
            i=(i+1)%max;
            p--;
        }
        
    }
    else
    {
        printf("List is empty\n");
    }
}
int main()
{
    int ch,num,x;
    printf("\n1.insert\n2.delete\n3.display\n4.exit\n");
    while(1)
    {
        printf("Enter choice:\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                 printf("Enter value to insert:\n");
                 scanf("%d",&num);
                 insert(num);
                 break;
            case 2:
                 x=delete();
                 if(x!=-1)
                    {printf("Deleted value is %d\n",x);}
                 else
                    {printf("No elements\n");}
                 break;
            case 3:
                 display();
                 break;
            case 4:
                 exit(0);

        }


    }

    
    return 0;
}
