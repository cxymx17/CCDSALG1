#ifndef QUEUE_H
#define QUEUE_H

#define MAX_QUEUE_SIZE 256

typedef struct {
  int front, rear, size;
  char items[MAX_QUEUE_SIZE][MAX_QUEUE_SIZE];
} Queue;

// Function prototypes
void initQueue(Queue *q);
int isQueueFull(Queue *q);
int isQueueEmpty(Queue *q);
void enqueue(Queue *q, char *item); // add item to the queue
char *dequeue(Queue *q);            // remove & return item from the queue
char *
peekQueue(Queue *q); // peek at the front item of the queue without dequeuing it

#endif