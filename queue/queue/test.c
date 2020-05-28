#include <stdio.h>
#include "circularqueue.h"
//*
void test() {
	Queue q;

	init(&q);
	printf("Queue Initialization\n");
	printf("Queue size : %d\n\n", q.size);

	int i = 0;
	while (!isFull(&q)) {
		enQueue(&q, i);
		i++;
	}
	printf("Now enqueue %d elements.\n", q.size);
	printf("Queue size : %d\n", q.size);
	printf("Full ? : %d \n", isFull(&q));

	printf("Now dequeue %d elements.\n", q.size);
	Element e;
	while (!isEmpty(&q)) {
		e = deQueue(&q);
		printf("%d\n", e);
	}
	printf("Queue size : %d\n", q.size);
	printf("Empty ? %d\n", isEmpty(&q));

}
//*/

int main() {
	test();
	return 0;
}