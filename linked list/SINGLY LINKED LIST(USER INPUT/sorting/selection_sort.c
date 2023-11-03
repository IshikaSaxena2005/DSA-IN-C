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
void selection_sort(int n)
{
    struct node *p,*q;
    for(p=head;p!=NULL;p=p->next)
    {
        struct node *min =p;
        for(q=p->next;q!=NULL;q=q->next)
        {
            if(q->data<min->data)
            {

                min=q;
            }
        }
        int temp=p->data;
        p->data=min->data;
        min->data=temp;
    }
}
int main()
{
    int data,i,n,val;   
    printf("Input the number of elements in n: ");
    scanf("%d",&n);
    printf("The linked list is:\n");
    creatList(n);
    display();
  printf("Sorted linked list:\n");
    selection_sort(n);
    display();



}