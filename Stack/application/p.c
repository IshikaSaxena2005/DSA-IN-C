#include <stdio.h>
#include <string.h>
#define MAX 1000

int top = -1;
char stack[MAX];

// Function to add an item to the stack
void push(char item) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = item;
    }
}

// Function to remove an item from the stack
char pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        char item = stack[top--];
        return item;
    }
}

int main() {
    char inputString[MAX];
    char reversedString[MAX];
    
    printf("Enter a string: ");
    fgets(inputString, sizeof(inputString), stdin);

    // Remove the newline character from the input string if it's present
    int len = strlen(inputString);
    if (inputString[len - 1] == '\n') {
        inputString[len - 1] = '\0';
    }

    // Push each character onto the stack
    for (int i = 0; inputString[i] != '\0'; i++) {
        push(inputString[i]);
    }

    // Pop characters from the stack and store them in a char array to reverse the order
    int index = 0;
    while (top >= 0) {
        reversedString[index] = pop();
        index++;
    }
    reversedString[index] = '\0';

    // Display the reversed string
    printf("Reversed string: %s\n", reversedString);

    return 0;
}