/*String to Char[].
Create a Stack.
Push all characters, one by one.
Then Pop all characters, one by one and put into the char[].
Finally, convert to the String.*/
#include <stdio.h>

#include<stdlib.h>
#include<string.h>
#define MAX 1000


int top=-1;
char stack[MAX];

// Function to add an item to stack
void push(char item) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = item;
    }
}

// Function to remove an item from stack
char pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        char item = stack[top--];
        return item;
    }
}
int main()
{
    char inputString[MAX];
    char reversedString[MAX];
    printf("Input string: ");
    scanf("%s",inputString );
    int len =strlen(inputString);
    for(int i=0;i<len;i++){
        push(inputString[i]);
    }
    int i=0;
    while(top>=0)
    {
        reversedString[i]=pop();
        i++;

    }

    printf("Reversed string:%s \n",reversedString);
    return 0;

}