#include "final1.h"

void beforeExit() {
	getchar();
}

void init(Queue* q) {
	q->front = 0; //������� dequeue �� �׸�
	q->rear = -1; //���� �ֱٿ� enqueue �� �׸� 
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
	q->rear = (q->rear + 1) % MAX_SIZE; //���� 1�� ���ϰ� rear���� �������� ������ �ʱⰪ�� -1�̴�.
	q->queue[q->rear] = data;
	q->size++;
}
Element deQueue(Queue* q) {
	if (isEmpty(q)) {
		printf("Error : Queue Empty\n");
		exit(1);
	}
	Element e;
	e = q->queue[q->front]; //front ���� �������� 1�� ���ϱ� ������ �ʱⰪ�� 0�̴�.
	q->front = (q->front + 1) % MAX_SIZE;
	q->size--;
	return e;
}

