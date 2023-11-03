#include<stdio.h>
#include<stdlib.h>
struct node//for using linked list to create queue
{
    int data;
    struct node *next;
};
struct queue//creation of queue
{
    struct node *front;
    struct node *rear;
};
struct queue *fnQueue;//global variables
struct node *fnNode;//global vriables
struct queue *createQueue()//create queue
{
    struct queue *fnQueue=(struct queue*)malloc(sizeof(struct queue));
    fnQueue->front=NULL;
    fnQueue->rear=NULL;
    return fnQueue;
}
void enqueue(int data)
{
    struct node *fnNode=(struct node*)malloc(sizeof(struct node));
    fnNode->data=data;
    fnNode->next=NULL;
    if(fnQueue->rear==NULL)
    {
        fnQueue->front=fnQueue->rear=fnNode;
    }
    else
    {
        fnQueue->rear->next=fnNode;
        fnQueue->rear=fnNode;
    }
}
int dequeue()
{
    if(fnQueue->front==NULL)
    {
        printf("Empty Queue");
        return -1;
    }
    else
    {
        int data=fnQueue->front->data;
        struct node *temp=fnQueue->front;
        fnQueue->front=fnQueue->front->next;
        free(temp);
        return data;
    }
}
void printQueue()
{
    struct node *p=fnQueue->front;    
    while(p!=NULL)
    {
        printf("%d \t",p->data);
        p=p->next;
    }
}
void reverse_first_k(int k)
{
    if(fnQueue==NULL||fnQueue->front==NULL||k<=0)
    {
        return ;
    }
    struct node *prev=NULL;
    struct node *next=NULL;
    struct node *current=fnQueue->front;
    int count=0;
    while(count<k && current!=NULL)
        {
            next=current->next;
            current->next=prev;
            prev=current;
            current=next;
            count++;
        }
        fnQueue->front=prev;
}
int main()
{
    int n,k,data;
    printf("Enter the number of elements in the queue: ");
    scanf("%d",&n);
    fnQueue = createQueue();
    printf("Enter the elemets of the queue:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&data);
        enqueue(data);
    }
    printf("Enter the value of k");
    scanf("%d",&k);
    printf("Queue before reversing %d elements:\n ",k);
    printQueue();
    printf("\n");
    printf("Queue after reversing %d element:\n",k);
    reverse_first_k(k);
    printQueue();
    return 0;
}