#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
void displayList(struct node *head){
    struct node *temp=head;
    if(head!=NULL){
        do{
            printf("Data:%d \n",temp->data);
            temp=temp->next;
        }
        while(temp!=head);
    }
    printf("\n");
}
struct node *insertAtEnd(struct node *head,int data){
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data = data;
    if(head!=NULL){
        struct node *temp=head;
        while(temp->next!=head){
            temp=temp->next;
        }
        temp->next=ptr;
        ptr->next=head;
    } else {
        head = ptr;
        ptr->next = head;
    }
    return head;
}
int main(){
    struct node *head=NULL;
    head=(struct node*)malloc(sizeof(struct node));
    struct node *second=(struct node *)malloc(sizeof(struct node));
    struct node *third = (struct node *)malloc(sizeof(struct node));
    head->data = 1;
    head->next =second;
    second->data = 2;
    second->next = third;
    third->data=3;
    third->next = head;
    printf("List is:\n");
    displayList(head);
    printf("List after insertion:\n");
    head=insertAtEnd(head,4);
    displayList(head);
    return 0;
}