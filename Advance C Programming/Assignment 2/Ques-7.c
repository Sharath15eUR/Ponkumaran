#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
struct Queue {
    int items[MAX_SIZE];
    int front;
    int rear;
};
void initQueue(struct Queue* q) {
    q->front = -1;
    q->rear = -1;
}
int isEmpty(struct Queue* q) {
    return (q->rear == -1);
}
int isFull(struct Queue* q) {
    return (q->rear == MAX_SIZE - 1);
}
void enqueue(struct Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue Overflow!\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = value;
}
int dequeue(struct Queue* q) {
    int item;
    if (isEmpty(q)) {
        printf("Queue Underflow!\n");
        return -1;
    }
    item = q->items[q->front];
    q->front++;
    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }
    return item;
}
int countElements(struct Queue* q) {
    if (isEmpty(q))
        return 0;
    else
        return (q->rear - q->front + 1);
}
void printQueue(struct Queue* q) {
    int i;
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements are: ");
    for (i = q->front; i <= q->rear; i++)
        printf("%d ", q->items[i]);
    printf("\n");
}

int main() {
    struct Queue q;
    initQueue(&q);

    printf("Initialize a queue!\n");
    printf("Check the queue is empty or not? %s\n", isEmpty(&q) ? "Yes" : "No");
    printf("Number of elements in queue: %d\n", countElements(&q));
    printf("Insert some elements into the queue:\n");
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    printQueue(&q);
    printf("Number of elements in queue: %d\n", countElements(&q));
    printf("Delete two elements from the said queue:\n");
    dequeue(&q);
    dequeue(&q);
    printQueue(&q);
    printf("Number of elements in queue: %d\n", countElements(&q));
    printf("Insert another element into the queue:\n");
    enqueue(&q, 4);
    printQueue(&q);
    printf("Number of elements in the queue: %d\n", countElements(&q));
    return 0;
}
