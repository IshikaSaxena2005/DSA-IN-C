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
struct node *delfrombet(struct node *head,int index)
{
    struct node *p=head;
    struct node *q=head->next;
    for(int i=0;i<index-1;i++)
    {
        p=p->next;
        q=q->next;
    }
    p->next=q->next;
    q->next->prev=p;//p ke next ka prev p ke barabar hoga
    free(q);
    return head;

}
int main()
{
    int n,index;
    printf("Enter the number of nodes");
    scanf("%d",&n);
    createList(n);
    displayList();
    printf("After deletion:\n");
    printf("Enter the index:");
    scanf("%d",&index);
    delfrombet(head,index);
    displayList();
    return 0;
}



