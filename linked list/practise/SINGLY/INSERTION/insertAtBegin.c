#include<stdio.h>
#include<stdlib.h>
//node creation
struct node
{
    int data;
    struct node *next;
};
struct node *head=NULL;
//create list ka function
void createList(int n)
{
    int i, data;
    struct node *temp, *fnNode;
    head= (struct node* )malloc(sizeof(struct node));
    //check if head null hai kya
    if(head==NULL)
    {
        printf("List is empty");
    }
    else
    {
        printf("Input data for node 1: ");
        scanf("%d",&data);
        head->data=data;
        head->next=NULL;
        temp=head;
        for(i=2;i<=n;i++)
        {
        fnNode=(struct node *)malloc(sizeof(struct node));
        //check if fnNode is empty
        if(fnNode==NULL)
        {
            printf("Memory cannnot be allocated");
        }
        else
        {
            printf("Input data for node %d:",i);
            scanf("%d",&data);
            fnNode->data=data;
            fnNode->next=NULL;
            temp->next = fnNode;
            temp=temp->next;
        }
        }

    }

}
void displayList()
{
    struct node *p;
    if(head==NULL)
    {
        printf("List is empty");

    }
    else
    {
        p=head;
        while(p!=NULL)
        {
            printf("DATA = %d \n",p->data);
            p=p->next;
        }
    }
}
struct node *insertInBegin()
{
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    int data;
    printf("Input the data of the ptr:");
    scanf("%d",&data);
    ptr->data= data;
    ptr->next = head;
    head=ptr;
    return ptr;

}
int main()
{
    int n;
    printf("Enter the number of node:");
    scanf("%d",&n);
    createList(n);
    displayList();
    printf("List after insertion");
    insertInBegin();
    displayList();
    return 0;
}