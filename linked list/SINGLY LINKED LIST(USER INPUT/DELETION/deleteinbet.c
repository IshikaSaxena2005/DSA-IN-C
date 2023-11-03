#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *head;
void CreateList(int n){
    int data,i;
    struct node *fnNode,*temp;
    head = (struct node*)malloc(sizeof(struct node));
    if(head==NULL){
        printf("List is empty, memory cannot be allocated");
    }
    else{
        printf("Input data for Node 1:");
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
struct node *deleteinbet(struct node *head,int index,int n){
    struct node *p =head;
    struct node *q =head->next;
   
    for(int i=0;i<index-1;i++){
        p=p->next;
        q=q->next;
    }
    p->next=q->next;
    free (q);
    return head;

}
int main(){
    int n;
    int index;
    printf("Enter number of nodes:");
    scanf("%d",&n);
    printf("Enter the index at which the element needs to be deleted : ");
    scanf("%d",&index);
    CreateList(n);
    printf("List is :\n");
    displayList();
    printf("List after deletion:\n");
    deleteinbet(head,index,n);
    displayList();
    return 0;
}