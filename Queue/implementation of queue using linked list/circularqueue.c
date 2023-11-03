#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL)
    {
        printf("Memory cannot be allocated\n");
    }
    else
    {
        new_node->data = data;
        if (front == NULL)
        {
            new_node->next = new_node; // For the first element, point to itself
            front = new_node;
            rear = new_node;
        }
        else
        {
            new_node->next = front; // Point the new node to the front of the queue
            rear->next = new_node; // Update the last node's next to the new node
            rear = new_node; // Move rear to the new node
        }
    }
}

void dequeue()
{
    if (front == NULL)
    {
        printf("Queue Underflow\n");
    }
    else
    {
        struct node *temp = front;
        if (front == rear)
        {
            front = NULL;
            rear = NULL;
        }
        else
        {
            front = front->next;
            rear->next = front;
        }
        printf("Popped element: %d\n", temp->data);
        free(temp);
    }
}

void display()
{
    if (front == NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        struct node *temp = front;
        do
        {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != front);
        printf("\n");
    }
}

int main()
{
    int choice, data, n;
    printf("Enter the number of elements to push in the queue: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &data);
        enqueue(data);
    }

    while (1)
    {
        printf("Enter choice: (1: enqueue, 2: dequeue, 3: display, 4: exit)\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the element to enqueue: ");
            scanf("%d", &data);
            enqueue(data);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            return 0;
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}
