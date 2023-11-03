#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
};
void displaylist(struct node *head){
    struct node *temp=head;
    if(head!=NULL){
        do{
            printf("Data=%d \n",temp->data);
            temp=temp->next;
            printf("\n");
        }
        while(temp!=head);
    }
}
struct node *deletefromend (struct node *head){
    struct node *p=head;
    struct node *q =head->next;
    while(q->next!=head){
        p=p->next;
        q=q->next;
    }
    p->next=head;
    free(q);
    return head;

    }
int main(){
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fourth;
    head = (struct node*)malloc(sizeof(struct node));
    second = (struct node*)malloc(sizeof(struct node));
    third = (struct node*)malloc(sizeof(struct node));
    fourth = (struct node*)malloc(sizeof(struct node));
    head->data=1;
    head->next =second;
    second->data = 2;
    second ->next =third;
    third -> data =3;
    third -> next = fourth;
    fourth -> data =4;
    fourth -> next= head;
    printf("ELEMENTS BEFORE DELETION:\n");
    displaylist(head);
    printf("ELEMENTS AFTER DELETION:\n");
    head = deletefromend(head);
    displaylist(head);
    return 0;
}

