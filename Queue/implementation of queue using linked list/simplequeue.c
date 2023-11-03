#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node *next;
};
struct node *front=NULL;
struct node *rear=NULL;
void enqeue(int data)
{
    struct node *new_node=(struct node *)malloc(sizeof(struct node));
    if(new_node==NULL)
    {
        printf("Memory cannot be allocated");
    }
    else
    {
        new_node->data=data;
        new_node->next=NULL;
        if(front==NULL&&rear==NULL)
        {
            front=new_node;
            rear=new_node;
        }
        else{
            rear->next=new_node;
            rear=new_node;
        }

    }

}
int dequeue()
{
    int data;
    if(front==NULL)
    {
        printf("Queue Underflow");
        return -1;
    }
    else
    {
       struct node *temp=front;
       front = front->next;
       data= temp->data;
       free(temp);
       

       //front ke next ko check krr rhe hai
       if(front==NULL)
       {
        rear=NULL;
       }
    }
    return data;
}
void display()
{
    if(front==NULL&& rear==NULL)
    {
        printf("Queue is empty");
    }
    else
    {
        struct node *p=front;
        while(p!=NULL)
        {
            printf("%d \t",p->data);
            p=p->next;
        }
    }
}
int main()
{
    int choice,data,n,i;
    printf("Enter the number of elements to push in the stack");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("Enter element %d : ",i+1);
        scanf("%d",&data);
        enqeue(data);
    }
   
    while(1)
    {
        printf("Enter choice: (1: enqueue , 2:dequeue, 3: display )\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter the element to enqueue : ");
                scanf("%d",&data);
                enqeue(data);
                break;
            case 2:
             
                dequeue();
                break;
            case 3:
                display();
                break;
            default:
                printf("Invalid choice");

        }
   


    }
    return 0;
}