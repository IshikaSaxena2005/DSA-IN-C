#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node*right;
};
struct node*root=NULL;
//creation of Newnode to insert
struct node *createNode(int data)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
void read_inorder(struct node *root)
{
    if(root!=NULL)
    {
        read_inorder(root->left);
        printf("%d ",root->data);
        read_inorder(root->right);
    }
}
//insert a node in BST
struct node*insert(struct node*root,int data)
{
    if(root==NULL)
    {
        return createNode(data);
    }
    if(data<root->data)
    {
        root->left=insert(root->left,data);
    }
    else if (data>root->data)
    {
        root->right=insert(root->right,data);
    }
    return root;
}
int main()
{
    root= insert(root,50);
    insert(root,30);
    insert(root,20);
    insert(root,40);
    insert(root,70);
    insert(root,60);
    insert(root,80);
    read_inorder(root);
    return 0;
}