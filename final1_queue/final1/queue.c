#include "final1.h"

void beforeExit() {
	getchar();
}

void init(Queue* q) {
	q->front = 0; //가장먼저 dequeue 된 항목
	q->rear = -1; //가장 최근에 enqueue 된 항목 
	q->size = 0;
}
bool isFull(Queue* q) {
	return (q->size == MAX_SIZE);
}
bool isEmpty(Queue* q) {
	return(q->size == 0);
}
void enQueue(Queue* q, Element data) {
	if (isFull(q)) {
		printf("Error : Queue Full\n");
		exit(1);
	}
	q->rear = (q->rear + 1) % MAX_SIZE; //먼저 1을 더하고 rear값을 가져오기 때문에 초기값이 -1이다.
	q->queue[q->rear] = data;
	q->size++;
}
Element deQueue(Queue* q) {
	if (isEmpty(q)) {
		printf("Error : Queue Empty\n");
		exit(1);
	}
	Element e;
	e = q->queue[q->front]; //front 값을 가져오고 1을 더하기 때문에 초기값이 0이다.
	q->front = (q->front + 1) % MAX_SIZE;
	q->size--;
	return e;
}

