//linear searching element in linked list
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head=NULL;
void creatList(int n)
{
    int data,i;
    struct node *fnNode,*temp;
    head=(struct node*)malloc(sizeof(struct node));
    if(head==NULL)
    {
      printf("Memory cannot be allocated");
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
            fnNode=(struct node*)malloc(sizeof(struct node));
            if(fnNode==NULL)
            {
                printf("Memory cannot be allocated");
            }
            else
            {
                printf("Input data for node %d: ",i);
                scanf("%d",&data);
                fnNode->data=data;
                fnNode->next=NULL;
                temp->next=fnNode;
                temp=temp->next;
            }
        }
    }
}
void display()
{
    struct node *p=head;
    if(head==NULL)
    {
        printf("Memory cannot be allocated");
    }
    while(p!=NULL)
    {
        printf("%d \n",p->data);
        p=p->next;
    }
}
void  searching(int val)
{
    int pos=1;//initialize
    struct node *ptr=head;
    while(ptr!=NULL)
    {
        if(val==ptr->data)
        {
            
            printf("ELement found at pos : %d",pos);
            return;
        }
        else
        {
            ptr=ptr->next;
            pos++;
        }
        
        
    }
    printf("Element not found");
    return 0;
}
int main()
{
    int data,i,n,val;
    printf("Input the number of elements in n: ");
    scanf("%d",&n);
    printf("The linked list is:\n");
    creatList(n);
    display();
    printf("Enter the element to find: ");
    scanf("%d",&val);
    searching(val);



}