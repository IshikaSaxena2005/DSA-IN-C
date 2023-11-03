#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
void Traverse(struct node *ptr){
    while(ptr!=0){
        printf("Element %d \n",ptr->data);
        ptr= ptr->next;
    }
}
struct node *deleteInBetween(struct node *head,int index){
    struct node *p = head;
    struct node *q = head->next;
    for(int i=0;i<index-1;i++){
        p=p->next;
        q=q->next;
    }
    p->next = q->next;
    free(q);
    return head;

}
int main(){
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fourth;
    head = (struct node*)malloc(sizeof(struct node));
    second =(struct node*)malloc(sizeof(struct node));
    third = (struct node*)malloc(sizeof(struct node));
    fourth = (struct node*)malloc(sizeof(struct node));
    head-> data = 1;
    head->next = second;
    second ->data =2;
    second ->next = third;
    third -> data =3;
    third -> next = fourth;
    fourth -> data =4;
    fourth -> next =NULL;
    printf("ELEMENTS BEFORE DELETION:\n");
    Traverse(head);
    printf("ELEMENTS AFTER DELETION:\n");
    head = deleteInBetween(head,2);
    Traverse(head);
    return 0;

}
