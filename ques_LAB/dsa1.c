//•	Write a program to insert an element in an array. Write separate functions for reading the array.
#include<stdio.h>
void readArray(int a[],int n){
  printf("enter the elements:");
  for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
}
  void displayArray(int a[], int n){
  for(int i=0;i<n;i++){
    printf("%d ",a[i]);
  }
  printf("\n");

}
int main()
{
    int a[100];
    int ele,pos,n;
    printf("enter the size of the array: ");
    scanf("%d",&n);
    readArray(a,n);
    printf("enter the position to insert the element: ");
    scanf("%d",&pos);
    printf("enter the element to be inserted: ");
    scanf("%d",&ele);
    for(int i=n;i>pos-1;i--){

        a[i]=a[i-1];
    }
    a[pos-1]=ele;
    /*printf("array after insertion: ");
    n++;
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);

    }*/
    n++;
     displayArray(a, n);

    return 0;


}
