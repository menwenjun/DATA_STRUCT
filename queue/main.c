#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main(void)
{
	QUEUE *q = createQueue(90);

	enQueue(100, q);
	enQueue(101, q);
	enQueue(102, q);
	enQueue(103, q);
	printf("%d\n", frontAndDequeue(q));
	printf("%d\n", frontAndDequeue(q));
	printf("%d\n", frontAndDequeue(q));
	enQueue(104, q);
	enQueue(105, q);
	enQueue(107, q);
	//printf("%d\n", front(q));
	//printf("%d\n", frontAndDequeue(q));
	//deQueue(q);
	printf("%d\n", frontAndDequeue(q));
	printf("%d\n", frontAndDequeue(q));
	enQueue(108, q);
	enQueue(109, q);
//	printf("%d\n", frontAndDequeue(q));
//	printf("%d\n", frontAndDequeue(q));
//	printf("%d\n", frontAndDequeue(q));


	disposeQueue(q);	

	return 0;
}

