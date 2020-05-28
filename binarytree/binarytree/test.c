#include "binaryTree.h"
#include <stdio.h>

void graphvizPrint(BinaryTree* bt, int node) {
	if (node > bt->size) return;

	if (node != 1) printf("\t\"%d\" -> \"%d\"\n", bt->data[node / 2], bt->data[node]);
	//if (node != 1) printf("\t\"%s\" -> \"%s\"\n", bt->data[node / 2].msg, bt->data[node].msg); //문답

	graphvizPrint(bt, 2 * node);
	graphvizPrint(bt, 2 * node + 1); //skewed tree 할땐 주석

}
void graphvizDriver(BinaryTree* bt) {
	printf("digraph G {\n");
	graphvizPrint(bt, 1);
	printf("}\n");
}



//*
void test() {
	BinaryTree bt;

	init(&bt);
	for (int i = 1; i <= 8; i++) {
		insert(&bt, i);
	}

	printf("root is %d\n", value(&bt, 1));

	printf("left: %d, right : %d of node 1.\n", value(&bt, leftChild(&bt, 1)), value(&bt, rightChild(&bt, 1)));
	printf("left: %d, right : %d of node 2.\n", value(&bt, leftChild(&bt, 2)), value(&bt, rightChild(&bt, 2)));
	printf("left: %d, right : %d of node 3.\n", value(&bt, leftChild(&bt, 3)), value(&bt, rightChild(&bt, 3)));
	printf("left: %d, right : %d of node 4.\n", value(&bt, leftChild(&bt, 4)), value(&bt, rightChild(&bt, 4)));
	printf("parent of %d is %d\n", 5, value(&bt, parent(&bt, 5)));


	graphvizDriver(&bt);
}
//*/

/*
void test1() {
	BinaryTree bt;

	init(&bt);
	for (int i = 1; i <= 8; i++) {
		insert(&bt, i);
	}

	printf("root is %d\n", value(&bt, 1));

	printf("skewde tree: %d of node 1.\n", value(&bt, skewedTree(&bt, 1)));
	printf("skewde tree: %d of node 2.\n", value(&bt, skewedTree(&bt, 2)));
	printf("skewde tree: %d of node 3.\n", value(&bt, skewedTree(&bt, 3)));
	printf("skewde tree: %d of node 4.\n", value(&bt, skewedTree(&bt, 4)));
	printf("parent of %d is %d\n", 5, value(&bt, parent(&bt, 5)));

	graphvizDriver(&bt);

}
//*/

/*
void test2() {
	BinaryTree bt;

	init(&bt);
	Element trainData[] = {
		{true,"is animal?"},
		{true, "has a 2 leg?"},
		{true, "is tall?"},
		{true, "can fly?"},
		{true, "is larger than human?"},
		{true, "has needle leaf?"},
		{true, "is flower?"},
		{false, "It is a Bird."},
		{false, "It is a Chicken."},
		{false, "It is a elephant."},
		{false, "It is a dag."},
		{false, "It is a pine Tree."},
		{false, "It is a bamboo."},
		{false, "It is a orchid."},
		{false, "It is a gress."}

	};
	for (int i = 0; i < 15; i++) {
		insert(&bt, trainData[i]);
	}
	graphvizDriver(&bt);
	int question = 1;
	char answer;
	do {
		printf("%s ", bt.data[question].msg);
		printf("if YES, Enter 'y' or 'n' : ");
		scanf("%c", &answer);

		if (answer == 'y') {
			question = leftChild(&bt, question);
		}
		else {
			question = rightChild(&bt, question);

		}
		scanf("%c", &answer);
	} while (bt.data[question].isQuestion);
	printf("%s \n", bt.data[question].msg);

}
//*/

int main() {
	test();
	return 0;
}