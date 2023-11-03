#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
void Traverse(struct node *ptr){
        while(ptr!=0){
            printf("Element:%d \n",ptr->data);
            ptr = ptr->next;
        }
}
struct node *insertAtEnd(struct node *head,int data){
        struct node *ptr = (struct node*)malloc(sizeof(struct node));
        ptr ->data=data;
        struct node * p=head;
        while(p->next !=NULL){
            p=p->next;

        }
        p->next = ptr;
        ptr ->next = NULL;
        return head;


}
int main(){
        struct node *head;
        struct node *second;
        struct node *third;
        head = (struct node*)malloc(sizeof (struct node));
        second = (struct node*)malloc(sizeof(struct node));
        third = (struct node*)malloc(sizeof(struct node));
        head->data = 2;
        head->next = second;
        second -> data = 3;
        second -> next = third;
        third -> data = 4;
        third -> next = NULL;
        
        Traverse(head);
        printf("Element after insertion at end:\n");
        head= insertAtEnd(head,1);
        Traverse(head);
        return 0;
}