//. Write the program and algorithm to add two polynomials using linked list. Explain with 
//an example.
#include<stdio.h>
#include<stdlib.h>

struct node         //Defining a polynomial consisting of Exponent and Coefficient
{
    float coeff;
    int expo;
    struct node *next;
};
struct node *head=NULL;

void swapData(struct Node* a, struct Node* b)
{
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

struct node *D_Sort(struct node *head)
{

}