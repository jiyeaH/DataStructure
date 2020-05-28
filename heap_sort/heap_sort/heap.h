#pragma once
#include <stdbool.h>
#define MAX_NODE (100)
#define LEFT_CHILD(i) (i*2)
#define RIGHT_CHILD(i) ((i*2)+1)
#define PARENT(i) (i/2)

typedef int Element;
typedef struct {
	Element heap[MAX_NODE];
	int size;
}Heap;

void init(Heap* h);
bool isEmpty(Heap* h);
bool isFull(Heap* h);
void add(Heap* h, Element e);
Element remove1(Heap* h);
void graphvizDriver(Heap* h);
void graphvizPrint(Heap* h, int node);