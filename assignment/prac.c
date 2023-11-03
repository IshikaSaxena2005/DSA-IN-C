#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

void enqueue(struct Queue* queue, int data) {
    struct Node* node = newNode(data);
    if (queue->rear == NULL) {
        queue->front = queue->rear = node;
    } else {
        queue->rear->next = node;
        queue->rear = node;
    }
}

int dequeue(struct Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty\n");
        return -1;
    }
    int data = queue->front->data;
    struct Node* temp = queue->front;
    queue->front = queue->front->next;
    free(temp);
    return data;
}

void reverseQueueFirstK(struct Queue* queue, int k) {
    if (queue == NULL || queue->front == NULL || k <= 0) {
        return;
    }

    struct Node* prev = NULL;
    struct Node* current = queue->front;
    struct Node* next = NULL;
    int count = 0;

    while (count < k && current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }

    queue->front = prev;
}

void printQueue(struct Queue* queue) {
    struct Node* current = queue->front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Queue* queue = createQueue();
    int n, k, data;

    printf("Enter the number of elements in the queue: ");
    scanf("%d", &n);

    printf("Enter the elements of the queue:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        enqueue(queue, data);
    }

    printf("Enter the value of k: ");
    scanf("%d", &k);

    printf("Queue before reversing first %d elements: ", k);
    printQueue(queue);

    reverseQueueFirstK(queue, k);

    printf("Queue after reversing first %d elements: ", k);
    printQueue(queue);

    return 0;
}
