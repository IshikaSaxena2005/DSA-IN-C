#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node *next;
};
struct node *top=NULL;
void push(int new_data)
{
    struct node *new_node =(struct node*)malloc(sizeof(struct node));
    if(new_node==NULL)
    {
        printf("memor cannot be allocated");
    }
    else
    {
        new_node->data=new_data;
        new_node->next=top;
        top=new_node;
    }
}
int pop()
{
    struct node*temp;
    if(top==NULL)
    {
        printf("Stack Underflow");
    }
    else
    {
        temp=top;
        top=top->next;
        int popped_val=temp->data;
        free(temp);
        return popped_val;
    }
}

void display()
{
    if(top==NULL)
    {
        printf("Stack is empty");
    }
    else
    {
        struct node *p=top;
        printf("Stack:");
        while(p!=NULL)
        {
            printf("%d \t",p->data);
            p=p->next;
        }
    }
}
int main()
{   
    int choice,value,n;
    printf("Enter the number of elements to push in the stack: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("Enter element %d : ",i+1);
        scanf("%d",&value);
        push(value);
    }
    while(1)
    {
        printf("Enter choice(1:push,2:pop, 3:exit)");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter the value to push ");
                scanf("%d",&value);
                push(value);
                break;
            case 2:
                value = pop();
                printf("popped value:%d",value);
                break;
            case 3:
                return 0;
            default:
                printf("Invalid choice");

        }
        display();
    }
    return 0;

}