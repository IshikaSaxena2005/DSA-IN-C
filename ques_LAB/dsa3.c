//•	Write a program to search an element in an array using linear search technique.
//Write separate functions for reading the array, and for searching the element in the array.

#include <stdio.h>

void readArray(int a[], int n) {
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
}
void searchArray(int a[],int ele,int n)
{
        int found = 0; // Initialize a flag to indicate whether the element is found

    for (int i = 0; i < n; i++) {
        if (a[i] == ele) {
            found = 1;
            break; // No need to continue searching once the element is found
        }
    }

    if (found) {
        printf("Element found.\n");
    } else {
        printf("Element not found.\n");
    }
}

int main() {
    int ele, n;
    int a[100];

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    readArray(a, n);

    printf("Enter the element to search: ");
    scanf("%d", &ele);

    searchArray(a,ele,n);
    return 0;
}






