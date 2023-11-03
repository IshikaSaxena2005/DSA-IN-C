#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *root=NULL;
struct node *createNode(int data)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
}
void read_preOrder(struct node *root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        read_preOrder(root->left);
        read_preOrder(root->right);
    }
}
struct node *insert(struct node *root,int data)
{
    if(root==NULL)
    {
        return createNode(data);
    }
    else if(data<root->data)
    {
        root->left=insert(root->left,data);
    }
    else if (data>root->data)
    {
        root->right=insert(root->right,data);
    }
    return root;
}
//func to find min
struct node *findMin(struct node *root)
{
    struct node *temp=root;
    while(temp->left!=NULL)
    {
        temp=temp->left;
    }
    return temp;
}
struct node *delete(struct node *root, int data) {
    if (root == NULL) {
        return root;
    } else if (data < root->data) {
        root->left = delete(root->left, data);
    } else if (data > root->data) {
        root->right = delete(root->right, data);
    } else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct node *temp = root;
            root = root->right;
            free(temp);
        } else if (root->right == NULL) {
            struct node *temp = root;
            root = root->left;
            free(temp);
        } else {
            // 2child
            struct node *minRight = findMin(root->right);
            root->data = minRight->data;
            root->right = delete(root->right, minRight->data);
        }
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
    inorder(root);
    printf("\n");
    printf("after deletion 0f 20:\n");
    root=delete(root,20);
    read_preOrder(root);
    printf("\nAfter deletion of 30:\n");
    root=delete(root,30);
    read_preOrder(root);
    printf("\nAfter deletion of 70:\n");
    root=delete(root,70);
    read_preOrder(root);
    return 0;
}


