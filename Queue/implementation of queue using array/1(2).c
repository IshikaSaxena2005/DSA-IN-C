//circular queue
#include<stdio.h>
#include<stdlib.h>
#define MAX 1000
int queue[MAX];
int front=-1;
int rear=-1;
void enqueue(int value)
{
    if((rear+1)%MAX==front)
        {
            printf("Queue Overflow");
        }
    else if(front==-1&&rear==-1)
        {
            front =0;
            rear=0;
        }
    else
        {
            front=0;
            rear=(rear+1)%MAX;
        }
    queue[rear]=value;
}
void dequeue()
    {
        if(front==-1&&rear==-1)
            {
                printf("Queue Underflow");
            }
        else if (front==rear)
            {
                printf("Dequeue : %d",queue[front]);
                front=-1;
                rear=-1;
            }
        else
            {
                printf("Dequeue: %d \t",queue[front]);
                front=(front+1)%MAX;
            }
    }
void printQueue()
    {
        printf("Elements of the queue: ");
        if(front==-1&&rear==-1)
            {
                printf("Queue is empty");
            }
        else
            {
                int i=front;
                do
                {
                    printf("%d\t",queue[i]);
                    i=(i+1)%MAX;
                } while (i!=(rear+1)%MAX);
                
            }
    }
    int main()
        {
            int choice,value,n;
            printf("Enter no. of elements in the queue: ");
            scanf("%d",&n);
            for(int i=0;i<n;i++)
                {
                    printf("Enter element %d : ",i+1);
                    scanf("%d",&value);
                    enqueue(value);
                }
                printQueue();
                while(1)
                    {
                        printf("Enter choice(1:enqueue, 2:dequeue,  3:exit)");
                        scanf("%d",&choice);
                        switch(choice)
                            {
                                case 1:
                                        printf("Enter the value to enqueue");
                                        scanf("%d",&value);
                                        enqueue(value);
                                        break;
                                case 2:
                                        dequeue();
                                        break;
                                case 3:
                                        return 0;
                                        break;
                                default:
                                    printf("INVALID CHOICE");

                            }
                        printQueue();
                    }
            return 0;
}

