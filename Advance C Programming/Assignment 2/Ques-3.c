#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Queue {
    int items[MAX_SIZE];
    int front;
    int rear;
};

struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

int isEmpty(struct Queue* queue) {
    if (queue->rear == -1)
        return 1;
    else
        return 0;
}

void enqueue(struct Queue* queue, int value) {
    if (queue->rear == MAX_SIZE - 1)
        printf("\nQueue is Full!!");
    else {
        if (queue->front == -1)
            queue->front = 0;
        queue->rear++;
        queue->items[queue->rear] = value;
    }
}

int dequeue(struct Queue* queue) {
    int item;
    if (isEmpty(queue)) {
        printf("\nQueue is Empty!!");
        item = -1;
    } else {
        item = queue->items[queue->front];
        queue->front++;
        if (queue->front > queue->rear) {
            queue->front = queue->rear = -1;
        }
    }
    return item;
}

void sortQueue(struct Queue* queue) {
    int temp[MAX_SIZE];
    int i, j, size = 0;

    while (!isEmpty(queue)) {
        temp[size++] = dequeue(queue);
    }

    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (temp[j] > temp[j + 1]) {
                int t = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = t;
            }
        }
    }
    for (i = 0; i < size; i++) {
        enqueue(queue, temp[i]);
    }
}

void display(struct Queue* queue) {
    int i;
    if (isEmpty(queue))
        printf("\nQueue is Empty!!\n");
    else {
        printf("\nQueue elements are:\n");
        for (i = queue->front; i < queue->rear + 1; i++) {
            printf("%d ", queue->items[i]);
        }
        printf("\n");
    }
}

int main() {
    struct Queue* queue = createQueue();
    int n, i, data;

    printf("Enter the number of elements in the queue: ");
    scanf("%d", &n);

    printf("Enter the elements of the queue:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &data);
        enqueue(queue, data);
    }

    printf("\nOriginal queue:\n");
    display(queue);

    sortQueue(queue);

    printf("\nQueue after sorting:\n");
    display(queue);

    return 0;
}
