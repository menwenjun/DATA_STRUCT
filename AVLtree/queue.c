#include <stdio.h>
#include <stdlib.h>
#include "AVLtree.h"
#include "queue.h"

int isEmpty(QUEUE *q)
{
	return (q->size == 0);
}
int isFull(QUEUE *q)
{
	return (q->size == q->capacity);
}
QUEUE *createQueue(int maxElements)
{
	if(maxElements < MinQueueSize) {
		printf("queue size is too small\n");	
		return NULL;
	} else {
		QUEUE *q = (QUEUE *)malloc(sizeof(struct queueRecord));
		q->array = (elementType *)malloc(sizeof(elementType) * maxElements);
		q->capacity = maxElements;
		makeEmpty(q);
		return q;
	}
}
void disposeQueue(QUEUE *q)
{
	if(q != NULL) {
		free(q->array);	
		free(q);
	}	
}
void makeEmpty(QUEUE *q)
{
	if(q != NULL) {
		q->front = 1;	
		q->rear = 0;
		q->size = 0;
	}
}
static int succ(int value, QUEUE *q) 
{
	if(++value == q->capacity) 
		value = 0;
	return value;
}
void enQueue(elementType element, QUEUE *q)
{
	if(!isFull(q)) {
		q->size++;	
		q->rear = succ(q->rear, q);
		q->array[q->rear] = element;
	} else {
		printf("Full queue\n");	
	}
}
elementType front(QUEUE *q)
{
	if(!isEmpty(q)) {
		return q->array[q->front];	
	} else {
		printf("empty queue\n");	
	}
}
void deQueue(QUEUE *q)
{
	if(!isEmpty(q)) {
		q->size--;
		q->front = succ(q->front, q);
	} else {
		printf("empty queue\n");	
	}
}
elementType frontAndDequeue(QUEUE *q)
{
	if(!isEmpty(q)) {
		elementType ret = q->array[q->front];
		q->size--;
		q->front = succ(q->front, q);
		return ret;	
	} else {
		printf("empty queue\n");	
		return 0;
	}
}

