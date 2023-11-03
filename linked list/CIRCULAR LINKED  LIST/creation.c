#include<stdio.h>
#include<stdlib.h>
struct  node{
    int data;
    struct node *next;
};
void displayList(struct node *head){
    struct node *temp=head;
    if(head!=NULL){
        do{
            printf("Data = %d \n",temp->data);
            temp=temp->next;

        }
        while(temp!=head);
    }printf("\n");
}
int main(){
    struct node *head=NULL;
    head=(struct node *)malloc(sizeof(struct node));
    struct node *second =(struct node*)malloc(sizeof(struct node));
    struct node *third =(struct node*)malloc(sizeof(struct node));
    head->data=1;
    head->next = second;
    second->data =2;
    second->next=third;
    third->data =3;
    third->next=head;
    printf("List is:\n");
    displayList(head);
    return 0;
}