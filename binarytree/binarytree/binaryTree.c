#include <stdio.h>
#include "binaryTree.h"
#include <string.h>
#include <math.h>

void init(BinaryTree* bt) {
	bt->size = 0;
	bt->data[0] = 0; //Y or N 할때만 주석처리
}

int leftChild(const BinaryTree* bt, const int pos) {
	if (pos * 2 <= bt->size) return pos * 2;
	else return 0;
}

int rightChild(const BinaryTree* bt, const int pos) {
	if (pos * 2 + 1 <= bt->size) return pos * 2 + 1;
	else return 0;
}

int skewedTree(const BinaryTree* bt, const int pos) {//이부분 구현하기.
	if (pos <= bt->size) return pow(2, (pos - 1));

	else return 0;
}


int parent(const BinaryTree* bt, const int pos) {
	if (pos == 1) return 0;
	else return pos / 2;
}

void insert(BinaryTree* bt, const Element e) {
	if (bt->size >= MAX_SIZE - 1) return;
	else {
		bt->size++;
		bt->data[bt->size] = e;
	}

}
Element value(const BinaryTree* bt, const int pos) {
	if (pos >= 0 && pos <= bt->size)
		return bt->data[pos];

}