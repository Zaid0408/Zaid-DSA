#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
void ToH(int n,char src,char dest,char spa)
{
    if(n==1)
        printf("Move disc %d from %c to %c\n",n,src,dest);
    else
    {
        printf("\n");
        ToH(n-1,src,spa,dest);
        printf("Move disc %d from %c to %c\n",n,src,dest);
        ToH(n-1,spa,dest,src);
        printf("\n");
    }

}

int main()
{
    int x;
    printf("Enter the number of disks for Towers of Hanoi problem:\n");
    scanf("%d",&x);
    ToH(x,'X','Z','Y');
    return 1;
}