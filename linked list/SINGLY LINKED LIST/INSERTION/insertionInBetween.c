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
struct node *insertInBetween(struct node *head,int data,int index){
        struct node *ptr=(struct node*)malloc(sizeof(struct node));
        struct node *p=head;
        int i=0;
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
        struct node *head;
        struct node *second;
        struct node *third;
        int index;
        printf("Enter the index at which element needs to be inserted");
        scanf("%d",&index);
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
        printf("Element after insertion");
        head= insertInBetween(head,1,2);
        Traverse(head);
        return 0;
}