
#include<stdio.h>
#include<stdlib.h>
#define MAX 1000
int queue[MAX];
int front = -1;
int rear = -1;
void enqueue(int value)
{
    if(rear==MAX-1)
    {
        printf("Queue Overflow");
    }
    else
    {
        if(front ==-1)
            front =0;
        
        rear++;
    
    queue[rear]=value;
   

    }
}
int dequeue()
{
    if(front==-1 && rear==-1)
    {
        printf("Queue Underflow");
    }
    else
    {
        int value =queue[front];
        if(front==rear)
        {
            front = rear =-1;
        }
        else
        {
            front++;
        }
        printf("Dequeued %d from the queue",value);
        return value;
    }
}
void printQueue()
{
   if(front!=-1)
   {
    printf("Elements of the queue:\n");
    for(int i=front;i<=rear;i++)
    {
        printf("%d\t",queue[i]);
 
    }
    printf("\n");
   }
}
int main()
{
    int choice, value,n;
    printf("Enter the no. of elements of the queue: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("Enter element %d  ",i+1);
        scanf("%d",&value);
        enqueue(value);
        
    }
    printQueue();
    while(1)
    {
        printf("Enter choice: (1:enqueue, 2:dequeue 3: exit): ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d",&value);
                enqueue(value);
                break;
            case 2:
                value=dequeue();
                if(value !=-1)
                    {
                        printf("Dequeued item : %d",value);
                        break;
                    }
            case 3:
                return 0;
                break;
            default:
                printf("Invalid choice");
        }
    printQueue();

    }
    return 0;
}
