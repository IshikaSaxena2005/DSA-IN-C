#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head=NULL;
void createList(int n)
{
    int data,i;
    struct node *temp,*fnNode,*enNode;
    head=(struct node*)malloc(sizeof(struct node));
    if(head==NULL)
    {
        printf("Memort cannot be allocated");
    }
    else
    {
        printf("Input data for node 1:");
        scanf("%d",&data);
        head->data=data;
        head->next=NULL;
        head->prev=NULL;
        temp=head;
        enNode=head;
        for(int i=2;i<=n;i++)
        {
            fnNode=(struct node*)malloc(sizeof(struct node));
            if(fnNode==NULL)
            {
                printf("Memory cannot be allocated ");
            }
            else
            {
                printf("Input data for node %d:",i);
                scanf("%d",&data);
                fnNode->data=data;
                fnNode->next=NULL;
                fnNode->prev=temp;
                temp->next=fnNode;
                temp=temp->next;
                enNode=fnNode;
            }
        }
    }
}
void displayList()
{
    struct node *ptr=head;
    if(head==NULL)
    {
        printf("Memory cannot be allocated");
    }
    else
    {
        while(ptr!=NULL)
        {
            printf("data = %d \n",ptr->data);
            ptr=ptr->next;
        }
    }
}
struct node *delfromstart()
{
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    ptr=head;
    head=head->next;
    head->prev=NULL;
    free(ptr);
    return head;
}
int main()
{
    int n;
    printf("Enter the number of nodes");
    scanf("%d",&n);
    createList(n);
    displayList();
    printf("After deletion:\n");
    delfromstart();
    displayList();
    return 0;
}



