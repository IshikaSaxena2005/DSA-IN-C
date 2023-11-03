/* A single array A [1...MAXSIZE] is used to implement two stacks. The two stacks grow
from opposite ends of the array. Variables top1 and top2 (top1< top2) point to the 
location of the topmost element in each of the stacks. If the space is to be used
efficiently, then analyse and write the condition for “stack full”. Test your condition by 
taking an example.
*/
#include<stdio.h>
#include<stdbool.h>
#define MAX_SIZE 2

int A[MAX_SIZE];
int top1=-1;
int top2 = MAX_SIZE;
bool isStackFull_1()
{
    return (top1+1==top2);//agr abb top1 full hii hai toh abb toh voh top2 meh hii element chala jae
}
bool isStackFull_2()
{
    return (top2-1==top1);
}
void pushStack_1(int value)
{
    if(!isStackFull_1())
    {
        A[++top1]=value;
    }
    else
    {
        printf("Stack is FULL");
    }
}
void pushStack_2(int value)
{
    if(!isStackFull_2())
    {
        A[--top2]=value;
    }
    else
    {
        printf("Stack is FULL");
    }
}
int main()
{
    int MAX;
    int choice,elements;
 
    while(1)
    {
        printf("1: Push in Stack 1.\n");
        printf("2: Push in Stack 2.\n");
        printf("3: EXIT.\n");
        printf("ENTER CHOICE:\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter the element to enter in Stack1 : ");
                scanf("%d",&elements);
                break;
            case 2:
                printf("Enter the element to enter in Stack2 : ");
                scanf("%d",&elements);
                break;
            case 3:
                return 0;
            default:
                printf("INVALID");
        }
    }
    return 0;
}