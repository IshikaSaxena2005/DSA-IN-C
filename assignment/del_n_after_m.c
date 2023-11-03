#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node *next;
};
struct node *head=NULL;
void CreateList(int nodes)
{
    int data,i;
    struct node *temp,*fnNode;
    head=(struct node *)malloc(sizeof(struct node));
    if(head==NULL)
    {
        printf("List is empty");
    }
    else
    {
        printf("Input data for node 1 : ");
        scanf("%d",&data);
        head->data=data;
        head->next=NULL;
        temp=head;
        for(int i=2;i<=nodes;i++)
        {
            fnNode=(struct node *)malloc(sizeof(struct node));
            if(fnNode==NULL)
            {
                printf("Memory cannot be allocated");
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
void print_List()
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
        printf("Data = %d \n",p->data);
        p=p->next;
    }
   }
}
struct node *delete_n_after_m(int m,int n)
{
    struct node *current=head;
    struct node *temp;
    while(current!=NULL)
    {
        for(int i=1;i<m && current !=NULL;i++)//m-1 steps tak skip becaz usse nhi kuch krna 
        {
            current=current->next;
        }
        if(current==NULL)// skip ke baad agr koi node hii nhi bache toh kya hi delete kregeh iiliye break statement
        {
            break;
        }
        temp = current->next;//ekk tep pinter joh m ko read krne ke baad waale nodes se start  kregeh
        for(int i=0;i<n && temp!=NULL;i++)//deleting n nodes
        {
            struct node *temp2=temp;
            temp=temp->next;
            free(temp2);
        }
        current->next=temp;//next nodes ko temp dena
        current=temp;//current pointer to next node update krna aur loop continue
    }
    return head;//return the updated head
}
int main()
{
    int nodes,data,m,n;
    printf("Input the number of nodes present: ");
    scanf("%d",&nodes);
    CreateList(nodes);
    printf("List before deletion: \n");
    print_List();
    printf("input the value of m:");
    scanf("%d",&m);
    printf("input value of n:");
    scanf("%d",&n);
    printf("List after deletion: \n");
    head= delete_n_after_m(m,n);
    print_List();
    return 0;
}