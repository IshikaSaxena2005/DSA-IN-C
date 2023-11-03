/*Write a program to reverse a linked list using optimal number of additional variable*/
#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node *next;
};
struct node *head=NULL;
void CreateList(int n)//creating list
{
    int data;
    struct node *fnNode,*temp;
    head=(struct node *)malloc(sizeof(struct node));
    if(head==NULL)
    {
        printf("List is empty");
    }
    else
    {   printf("Input data for node 1 : ");
        scanf("%d",&data);
        head->data=data;
        head->next =NULL;
        temp=head;
        for(int i=2;i<=n;i++)
        {
            fnNode=(struct node*)malloc(sizeof(struct node));
            if(fnNode==NULL)
            {
                printf("empty");
            }
            else
            {
                printf("Input data for node %d : ",i);
                scanf("%d",&data);
                fnNode->data=data;
                fnNode->next=NULL;
                temp->next=fnNode;
                temp=temp->next;
            }
        }
    }
}
void printList()
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
            printf("Data: %d \n",p->data);
            p=p->next;
        }
    }
}
struct node *reverseLinkedList()
{
    struct node *prev=NULL;
    struct node *next=NULL;
    struct node *p=head;
    while(p!=NULL)
    {
        next=p->next;//initializing next
        p->next=prev;
        prev=p;
        p=next;

    }
    return prev;
}
int main()
{
    int n,data;
    printf("Input the number of nodes present: ");
    scanf("%d",&n);
    CreateList(n);
    printf("List before reversing:\n");
    printList();
    printf("List after reversing:\n");
    head = reverseLinkedList();//updating head because in printList function we are returning head
    printList();
    return 0;

}