#include "final1.h"

int main() {
	Queue q;
	init(&q);
	int input[] = { 20, 3, 1, 50, 20, 12, 38, 29, 88 };
	int temp;
	int siz = sizeof(input) / sizeof(input[0]);
	for (int i = 0; i < siz; i++) {
		for (int j = 0; j < i - 1;j++) {
			if (input[j] >= input[j + 1]) {
				temp = input[j];
				input[j] = input[j + 1];
				input[j + 1] = temp;
			}
		}
	}
	int i = 0;
	while (!isFull(&q)) {
		enQueue(&q, input[i]);
		i++;
	}
	Element e;
	while (!isEmpty(&q)) {
		e = deQueue(&q);
		printf("%d\n", e);
	}
	printf("Queue size : %d\n", q.size);

	return 0;
}