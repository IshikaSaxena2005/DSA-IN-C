#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;

};
struct node *head=NULL;

void CreateList(int n){
    int data;
    int i;
    struct node *fnNode, *temp;
    head=(struct node*)malloc(sizeof(struct node));
    if(head==NULL){
        printf("List is empty,memory cannot be allocated");
    }
    else{
        printf("Input the data for Node 1: ");
        scanf("%d",&data);
        head->data=data;
        head->next=NULL;
        temp=head;
        for(i=2;i<=n;i++){
            fnNode=(struct node*)malloc(sizeof(struct node));
            if(fnNode==NULL){
                printf("Memory cannot be allocated");   
                 }
            else{
                printf("Input data for Node %d: ",i);
                scanf("%d",&data);
                fnNode->data=data;
                fnNode->next=NULL;
                temp->next=fnNode;
                temp=temp->next;
            }

        }

    }
}
void displayList(){
    struct node *p;
    if(head==NULL){
        printf("List is empty");
    }
    else{
        p=head;
      
        while(p!=NULL){
        printf("Data = %d \n",p->data);
        p=p->next;
        }
    }
}
struct node *insertinbetween (struct node *head,int index,int n){
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    struct node *p=head;
    int i=0;
    int data;
    printf("Enter the index to insert the ptr:");
    scanf("%d",&index);
     printf("Input the data of the node to be inserted:");
    scanf("%d",&data);
  
    while(i!=index-1){
        p=p->next;
        i++;
        }
    ptr->data=data;
    ptr->next=p->next;
    p->next=ptr;
    return head;
}
int main(){
    int index;
    int n;
    printf("Enter the number of node:");
    scanf("%d",&n);
    CreateList(n);
    printf("List is:\n");
    displayList();
    printf("List after insertion:\n");
    insertinbetween(head,index,n);
    displayList();
    return 0;

}