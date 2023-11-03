//tower of hanoi
//rules:
/*1. only onr disk move at a time
2. disk can be moved if it is the upper most disk in the stck
3. no disk may be placed on the top of a smaller disk
Moving disks from A to C*/
#include<stdio.h>
void TowerOfHanoi(int n,char from_rod,char to_rod,char aux_rod)
{
    if(n<=0)
    {
        printf("Invalid input");
    }
    else if (n==1)//when only one disk is present
    {
        printf(" Move disk 1 from %c rod to %c rod.\n",from_rod,to_rod);
        return ;

    }
    else
    {
        TowerOfHanoi(n-1,from_rod,aux_rod,to_rod);
            printf(" Move disk %d from %c rod to %c rod.\n",n,from_rod,to_rod);
                TowerOfHanoi(n-1,aux_rod,to_rod,from_rod);
        return ;
    }
    
}
int main()
{
    int n;
    char A,B,C;
    printf("Enter the number of disks: ");
    scanf("%d",&n);
    printf("Tower of Hanoi for %d disks:\n",n);
    TowerOfHanoi(n,'A','C','B');
    return 0;
}