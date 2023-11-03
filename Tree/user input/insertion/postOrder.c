#include<Stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *root=NULL;
//creation of NewNode to insert 
struct node *createNode(int data)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
void read_postOrder(struct node *root)
{
    if(root!=NULL)
    {
        read_postOrder(root->left);
        read_postOrder(root->right);
        printf("%d ",root->data);
    }
}
//insert a node in BST
struct node *insert(struct node *root,int data)
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
    struct node *root = NULL;
   int data,n;
   printf("Enter the total nodes present: ");
   scanf("%d",&n);
    for(int i=0;i<n;i++)
   {
     printf("Enter element %d:",i+1);
    scanf("%d",&data);
    root=insert(root,data);
   }
    read_postOrder(root);
   return 0;

}