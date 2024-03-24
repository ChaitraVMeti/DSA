#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10

struct PQElement {
    int data;
    int priority;
};

struct PQueue {
    struct PQElement items[MAX_SIZE];
    int size;
};

void displayQueue(struct PQueue *, FILE *);
void initializeQueue(struct PQueue *);
int isEmpty(struct PQueue *);
void push(struct PQueue *, int);

int main() {
    int arr[MAX_SIZE];
    int k = 0, num;

    srand(time(NULL));

    struct PQueue queue;
    initializeQueue(&queue);

    FILE *fptr;
    fptr = fopen("text.txt", "r");

    if (fptr == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (fscanf(fptr, "%d", &num) == 1) {
        arr[k] = num;
        k++;
    }

    fclose(fptr);
    fptr = fopen("text.txt", "a");

    printf("Pushing elements into the priority queue:\n");
    for (int i = 0; i < MAX_SIZE; i++)
        push(&queue, arr[i]);

    displayQueue(&queue, fptr);

    fclose(fptr);

    return 0;
}

void initializeQueue(struct PQueue *queue) {
    queue->size = 0;
}

int isEmpty(struct PQueue *queue) {
    return queue->size == 0;
}

void push(struct PQueue *queue, int data) {
    if (queue->size == MAX_SIZE) {
        printf("Queue is full.\n");
        return;
    }

    struct PQElement element;
    element.data = data;
    element.priority = rand() % 100;
    queue->items[queue->size++] = element;
}

void displayQueue(struct PQueue *queue, FILE *file) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }

    fprintf(file, "\nPriority Queue:\n");
    for (int i = 0; i < queue->size; i++) {
        fprintf(file, "Data: %d, Priority: %d\n", queue->items[i].data, queue->items[i].priority);
    }
}
