#ifndef _QUEUE_H_
#define _QUEUE_H_

#define MinQueueSize 	5

typedef AVLtree *elementType;

typedef struct queueRecord
{
	int capacity;
	int front;
	int rear;
	int size;
	elementType *array;
}QUEUE;

int isEmpty(QUEUE *q);
int isFull(QUEUE *q);
QUEUE *createQueue(int maxElements);
void disposeQueue(QUEUE *q);
void makeEmpty(QUEUE *q);
void enQueue(elementType element, QUEUE *q);
elementType front(QUEUE *q);
void deQueue(QUEUE *q);
elementType frontAndDequeue(QUEUE *q);

#endif
