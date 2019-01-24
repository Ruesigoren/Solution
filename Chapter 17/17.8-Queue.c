/*
 * File: 17.8-Queue.c
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

#define DefaultBufferSize 10

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
    void* *buffer;  //void* dynamic array: buffer
	int size;
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
	void* *buffer;
	int i;

	buffer = NewArray(DefaultBufferSize, void*);
	queue = New(queueADT);
	queue->buffer = buffer;
	queue->size = DefaultBufferSize;
	for (i = 0; i < queue->size; i++) {
		//*(queue->buffer + i) = NULL;
		queue->buffer[i] = NULL;
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
	FreeBlock(queue->buffer);
    FreeBlock(queue);
}

/*
 * Function: Enqueue
 * -----------------
 * This function adds a new element to the queue.
 */

void Enqueue(queueADT queue, void *obj)
{
	void* *newbuffer;
	int newsize;
	int i, j;

	if (queue->head == queue->tail &&
		queue->buffer[queue->head] != NULL) {
		newsize = 2 * queue->size;
		newbuffer = NewArray(newsize, void*);
		for (i = 0; i < newsize; i++) {
			if (i < queue->size) {
				j = (queue->head + i) % (queue->size);
				newbuffer[i] = queue->buffer[j];
			}
			else {
				newbuffer[i] = NULL;
			}
		}
		queue->head = 0;
		queue->tail = queue->size;
		queue->buffer = newbuffer;
		queue->size = newsize;
	}
    queue->buffer[queue->tail++] = obj;
	queue->tail %= queue->size;
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
		queue->buffer[queue->head] == NULL) {
		Error("Dequeue of empty queue");
	}
    result = queue->buffer[queue->head];
	queue->buffer[queue->head++] = NULL;
	queue->head %= queue->size;
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
	if (queue->head == queue->tail) {
		if (queue->buffer[queue->head] == NULL) {
			return 0;
		}
		return queue->size;
	}
	else if (queue->head < queue->tail) {
		return queue->tail - queue->head;
	}
	else {
		return queue->size - queue->head + queue->tail;
	}
}
