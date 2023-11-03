//•	Write a program to delete an element in an array. Write separate functions for reading the array.




#include <stdio.h>

void readArray(int a[], int n) {
    printf("Enter the size of array: ");
    scanf("%d", &n);
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
}

int main() {
    int a[100];
    int pos, n;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    readArray(a, n);

    printf("Enter the position of the element to delete: ");
    scanf("%d", &pos);

    if (pos > n || pos <= 0) {
        printf("Invalid position.\n");
    } else {
        for (int i = pos - 1; i < n - 1; i++) {
            a[i] = a[i + 1];
        }
        n--; // Decrease the size of the array after deletion

        printf("Array after deleting:\n");
        for (int i = 0; i < n; i++) {
            printf("%d ", a[i]);
        }
        printf("\n");
    }

    return 0;
}






