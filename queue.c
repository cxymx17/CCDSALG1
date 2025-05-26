#include "queue.h"
#include <string.h>

/*  initQueue initializes the queue to be empty
    @param q - the queue to initialize
*/
void initQueue(Queue *q) {
  q->front = -1;
  q->rear = -1;
  q->size = 0;
}

/*  isQueueFull checks if the queue is full
    @param q - the queue to check
*/
int isQueueFull(Queue *q) { return q->size == MAX_QUEUE_SIZE; }

/*  isQueueEmpty checks if the queue is empty
    @param q - the queue to check
*/
int isQueueEmpty(Queue *q) { return q->size == 0; }

/*  enqueue adds an item to the rear of the queue
    @param q - the queue to enqueue the item into
    @param item - the item to enqueue
*/
void enqueue(Queue *q, char *item) { //
  if (isQueueEmpty(q)) {
    q->front = 0;
  }
  q->rear++; // inrease index to "move" the index values of the queue
  strcpy(q->items[q->rear], item);
  q->items[q->rear][strlen(q->items[q->rear])] = '\0';
  q->size++;
}

/*  dequeue removes and returns the item from the front of the queue
    @param q - the queue to dequeue the item from
*/
char *dequeue(Queue *q) { // returns the dequeued expression
  char *value = q->items[q->front];
  q->front += 1;
  q->size--;

  return value;
}

/*  peekQueue returns the item from the front of the queue without removing it
    @param q - the queue to get the front item from
*/
char *peekQueue(Queue *q) {
  return q->items[q->front]; // returns the front of the queue
}