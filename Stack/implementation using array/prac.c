#include <stdio.h>
#define MAX 1000

int top;
int stack[MAX];

// Function to add an item to stack
void push(int item) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = item;
    }
}
void printStack() {
    int i;
    printf("Stack: ");
    for(i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}
// Function to remove an item from stack
int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        int item = stack[top--];
        return item;
    }
}

// Function to initialize the stack
void init() {
    top = -1;
}

int main() {
    init();
    int choice, value, n, i;
    
    printf("Enter the number of elements present in the stack: ");
    scanf("%d", &n);
    
    for(i = 0; i < n; i++) {
        printf("Enter element %d: ", i+1);
        scanf("%d", &value);
        push(value);
        printStack();
    }
    
    while(1) {
        printf("Enter choice (1: push, 2: pop, 3: exit): ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: 
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                
                break;
            case 2:
                value = pop();
                if(value != -1)
                    printf("Popped value: %d\n", value);
                    
                break;
            case 3:
                return 0;

            default:
                printf("Invalid choice\n");
        }
        printStack();
    }
  
    
    return 0;
}