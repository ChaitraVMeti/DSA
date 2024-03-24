#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_QUEUE_SIZE 100

typedef struct {
    int front;
    int rear;
    int data[MAX_QUEUE_SIZE];
} Queue;

void initQueue(Queue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

int isEmpty(Queue *queue) {
    return queue->front == -1;
}

int isFull(Queue *queue) {
    return (queue->rear + 1) % MAX_QUEUE_SIZE == queue->front;
}

void enqueue(Queue *queue, int data) {
    if (isFull(queue)) {
        printf("Queue is full.\n");
        return;
    }
    if (isEmpty(queue)) {
        queue->front = queue->rear = 0;
    } else {
        queue->rear = (queue->rear + 1) % MAX_QUEUE_SIZE;
    }
    queue->data[queue->rear] = data;
}

int dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return -1;
    }
    int data = queue->data[queue->front];
    if (queue->front == queue->rear)
        queue->front = queue->rear = -1;
    else
        queue->front = (queue->front + 1) % MAX_QUEUE_SIZE;
    return data;
}

void distributeCandies(int candies[], int n) {
    Queue queue;
    initQueue(&queue);
    for (int i = 0; i < n; ++i) {
        if (candies[i] > 0) {
            enqueue(&queue, i);
        }
    }
    int candiesToDistribute = n;
    int currentChild = dequeue(&queue);
    while (candiesToDistribute > 0) {
        candies[currentChild]++;
        if (candies[currentChild] > 0)
            enqueue(&queue, currentChild);
        currentChild = dequeue(&queue);
        candiesToDistribute--;
    }
}

int main() {
    int arr[MAX_QUEUE_SIZE], k = 0, num;
    FILE *fptr;
    srand(time(NULL));

    fptr = fopen("text.txt", "w");
    if (fptr == NULL) {
        printf("File not available.");
        exit(0);
    }
    for (int i = 0; i < 10; i++) {
        num = rand() % 100;
        fprintf(fptr, "%d\n", num);
    }
    fclose(fptr);

    fptr = fopen("text.txt", "r");
    if (fptr == NULL) {
        printf("File not available.");
        exit(0);
    }
    while (fscanf(fptr, "%d", &num) != EOF) {
        arr[k] = num;
        k++;
    }
    fclose(fptr);

    distributeCandies(arr, k);

    fptr = fopen("text.txt", "a");
    if (fptr == NULL) {
        printf("File not available.");
        exit(0);
    }
    fputs("\nFinal distribution of candies:\n", fptr);
    for (int i = 0; i < k; ++i) {
        fprintf(fptr, "Child %d has %d Candies\n", i + 1, arr[i]);
    }
    fclose(fptr);

    return 0;
}
