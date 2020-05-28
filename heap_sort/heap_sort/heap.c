#include <stdio.h>
#include "heap.h"

void init(Heap* h) {
	h->size = 0;
}
bool isEmpty(Heap* h) {
	return(h->size == 0);
}
bool isFull(Heap* h) {
	return(h->size == MAX_NODE-1);
}
void add(Heap* h, Element e) {
	if (isFull(h)) return;
	else {
		h->size++;
		int i;
		for (i = h->size; i > 1 && e > h->heap[PARENT(i)]; i /= 2) {  //e < h->heap[PARENT(i)] 이면 min heap 구현
			h->heap[i] = h->heap[PARENT(i)];
		}
		h->heap[i] = e;
	}
}
Element remove1(Heap* h) {
	Element root, temp;
	int current, left, right, greatest;

	root = h->heap[1];
	h->heap[1] = h->heap[h->size];
	h->size--; 

	for (current = 1; current < h->size;) {
		left = LEFT_CHILD(current);
		right = RIGHT_CHILD(current);
		greatest = current;
		if (left <= h->size&&h->heap[left] > h->heap[current]) {
			greatest = left;
		}
		if (right <= h->size&&h->heap[right] > h->heap[greatest]) {
			greatest = right;
		}
		if (greatest == current) break;
		else {
			temp = h->heap[greatest];
			h->heap[greatest] = h->heap[current];
			h->heap[current] = temp;
			current = greatest;
		}
	}
	return root;
}
void print(Heap* h) {
	for (int i = 1; i <= h->size; i++) {
		printf("%d ", h->heap[i]);
	}
	printf("\n");
}
void graphvizDriver(Heap *h) {
	printf("digraph G {\n");
	graphvizPrint(h, 1);
	printf("}\n");
}

void graphvizPrint(Heap *h, int node) {
	if (node > h->size) return;
	if (node != 1) printf("\t\"%d\" -> \"%d\"\n", h->heap[node / 2], h->heap[node]);

	graphvizPrint(h, 2 * node);
	graphvizPrint(h, 2 * node + 1);
}