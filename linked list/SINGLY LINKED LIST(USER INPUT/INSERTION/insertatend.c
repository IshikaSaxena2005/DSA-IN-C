#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
};
struct node *head=NULL;
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
struct node *insertatend(){
    struct node *ptr=(struct node*)malloc(sizeof (struct node));
    int data;
    struct node *p=head;
    ptr->data=data;
    printf("Input the data of the node to be inserted:");
    scanf("%d",&data);
    ptr->data=data;
    ptr->next =NULL;
    while(p->next!=NULL){
        p=p->next;
        
    }
    p->next=ptr;
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
    insertatend();
    displayList();
    return 0;

}