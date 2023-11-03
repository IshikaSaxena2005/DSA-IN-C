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
struct node *deleteinbegin(){
    struct node *ptr =head;
    head=head->next;
    free(ptr);
    return head;
}
int main(){
    int n;
    printf("Enter the no. of nodes:\n");
    scanf("%d",&n);
    CreateList(n);
    printf("List is :\n");
    displayList();
    printf("List after deletion:\n");
    deleteinbegin();
    displayList();
    return 0;
}