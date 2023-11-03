#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
void Traverse(struct node *ptr){
    while(ptr!=0){
        printf("Element %d \n",ptr->data);
        ptr=ptr->next;
    }
}
struct node *deletionFromLast(struct node *head){
    struct node *p = head;
    struct node *q = head ->next;
    while(q->next !=NULL){
        p = p->next;
        q = q ->next;

    }
    p->next =NULL;
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
    fourth -> next= NULL;
    printf("ELEMENTS BEFORE DELETION:\n");
    Traverse(head);
    printf("ELEMENTS AFTER DELETION:\n");
    head = deletionFromLast(head);
    Traverse(head);
    return 0;
}


