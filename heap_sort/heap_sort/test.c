#include <stdio.h>
#include "heap.h"

void test() {
	Heap h;

	init(&h);

	add(&h, 2);
	add(&h, 1);
	add(&h, 4);

	add(&h, 5);
	add(&h, 3);
	add(&h, 7);

	add(&h, 6);
	add(&h, 9);
	graphvizDriver(&h);

	int i = remove1(&h);
	printf("removed %d\n", i);
	graphvizDriver(&h);

	i = remove1(&h);
	printf("removed %d\n", i);
	graphvizDriver(&h);

	i = remove1(&h);
	printf("removed %d\n", i);
	graphvizDriver(&h);

	i = remove1(&h);
	printf("removed %d\n", i);
	graphvizDriver(&h);

	i = remove1(&h);
	printf("removed %d\n", i);
	graphvizDriver(&h);

	add(&h, 10);
	graphvizDriver(&h);

}


int main() {
	test();
	return 0;
}