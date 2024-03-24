#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 5
struct CircularQueue
{
int items[MAX_SIZE];
int front;
int rear;
};
int is_empty(struct CircularQueue* queue)
{
return queue->front == -1;
}
int is_full(struct CircularQueue* queue)
{
return (queue->rear + 1) % MAX_SIZE == queue->front;
}
void enqueue(struct CircularQueue* queue, int item)
{
if (is_full(queue))
{
printf("Queue is full. Cannot enqueue.\n");
return;
}
if (is_empty(queue))
{
queue->front = 0;
queue->rear = 0;
}
else
{
queue->rear = (queue->rear + 1) % MAX_SIZE;
}
queue->items[queue->rear] = item;
printf("Enqueued: %d\n", item);
}
int dequeue(struct CircularQueue* queue)
{
if (is_empty(queue))
{
printf("Queue is empty. Cannot dequeue.\n");
return -1;
}
int item = queue->items[queue->front];
if (queue->front == queue->rear)
{
queue->front = -1;
queue->rear = -1;
}
else
{
queue->front = (queue->front + 1) % MAX_SIZE;
}
printf("Dequeued: %d\n", item);
return item;
}
void display(struct CircularQueue* queue)
{
if (is_empty(queue))
{
printf("Queue is empty.\n");
return;
}
printf("Queue contents: ");
int i = queue->front;
do
{
printf("%d ", queue->items[i]);
i = (i + 1) % MAX_SIZE;
} while (i != (queue->rear + 1) % MAX_SIZE);
printf("\n");
}
int main()
{
struct CircularQueue queue;
queue.front = -1;
queue.rear = -1;
enqueue(&queue, 10);
enqueue(&queue, 20);
enqueue(&queue, 30);
display(&queue);
dequeue(&queue);
display(&queue);
enqueue(&queue, 40);
enqueue(&queue, 50);
enqueue(&queue, 60);
display(&queue);
return 0;
}
