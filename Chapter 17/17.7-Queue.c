/*
 * File: 17.7-Queue.c
 * ------------------
 * This file implements the queue.h abstraction using an array.
 */

#include <stdio.h>

#include "genlib.h"
#include "queue.h"

/*
 * Constants:
 * ----------
 * MaxQueueSize -- Maximum number of elements in the queue
 */

#define MaxQueueSize 10

/*
 * Type: queueCDT
 * --------------
 * This type provides the concrete counterpart to the queueADT.
 * The representation used here consists of an array coupled
 * with an integer indicating the effective size.  This
 * representation means that Dequeue must shift the existing
 * elements in the queue.
 */

struct queueCDT {
    void *array[MaxQueueSize];
    int head;
	int tail;
};

/* Exported entries */

/*
 * Function: NewQueue
 * ------------------
 * This function allocates and initializes the storage for a
 * new queue.
 */

queueADT NewQueue(void)
{
    queueADT queue;
	int i;

    queue = New(queueADT);
	for (i = 0; i < MaxQueueSize; i++) {
		queue->array[i] = NULL;
	}
    queue->head = 0;
	queue->tail = 0;
    return (queue);
}

/*
 * Function: FreeQueue
 * -------------------
 * This function frees the queue storage.
 */

void FreeQueue(queueADT queue)
{
    FreeBlock(queue);
}

/*
 * Function: Enqueue
 * -----------------
 * This function adds a new element to the queue.
 */

void Enqueue(queueADT queue, void *obj)
{
	if (queue->tail == queue->head &&
		queue->array[queue->head] != NULL) {
		Error("Enqueue called on a full queue");
	}
    queue->array[queue->tail++] = obj;
	queue->tail %= MaxQueueSize;
	/*
	if (queue->tail == MaxQueueSize) {
		queue->tail = 0;
	}
	*/
}

/*
 * Function: Dequeue
 * -----------------
 * This function removes and returns the data value at the
 * head of the queue.
 */

void *Dequeue(queueADT queue)
{
    void *result;

	if (queue->tail == queue->head &&
		queue->array[queue->head] == NULL) {
		Error("Dequeue of empty queue");
	}
    result = queue->array[queue->head];
	queue->array[queue->head++] = NULL;
	queue->head %= MaxQueueSize;
	/*
	if (queue->head == MaxQueueSize - 1) {
		queue->head = 0;
	}
	else {
		queue->head++;
	}
	*/
    return (result);
}

/*
 * Function: QueueLength
 * ---------------------
 * This function returns the number of elements in the queue.
 */

int QueueLength(queueADT queue)
{
	if (queue->head <= queue->tail) {
		if (queue->head == queue->tail && queue->array[queue->head] != NULL) {
			return MaxQueueSize;
		}
		return queue->tail - queue->head;
	}
	else {
		return MaxQueueSize - queue->head + queue->tail;
	}
}
