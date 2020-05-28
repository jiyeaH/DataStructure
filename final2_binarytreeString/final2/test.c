#include "final2.h"
#include <stdio.h>


/*
void post_order(BinaryTree bt, int index) {

	if (index <= bt.size) {
		post_order(bt, index * 2);
		post_order(bt, index * 2 + 1);
		printf("%d ", bt.data[index]);
	}
}

int child(BinaryTree bt) { //완전 이진트리일때만

	if (bt.size % 2 == 0) {
		return 1;
	}

	return 0;
}

void test1() {
	BinaryTree bt;

	init(&bt);
	int input[] = { 20, 3, 1, 50, 20, 12, 38, 29, 88 };

	for (int i = 0; i < 8; i++) {
		insert(&bt, input[i]);
	}

	printf("root is %d\n", value(&bt, 1));
	printf("parent of %d is %d\n", 5, value(&bt, parent(&bt, 5)));

	printf("\n");
	post_order(bt, 1);
	printf("\n");
	printf("자식이 1개인 노드의 개수 : %d\n", child(bt));

}
//*/

//*

void test2() {
	BinaryTree bt;
	init(&bt);

	Element sample[] = {
		"i","j","k","test","sample","average","max","min","a"
	};
	
	for (int i = 0; i < 10; i++) {
		insert(&bt, sample[i]);
		
	}
	for (int i = 1; i < (sizeof(sample) / sizeof(sample[0]) + 1); i++) {
		printf("%s\n", bt.data[i]);
	}
	printf("root is %s\n", value(&bt, 1));

	printf("left: %s, right : %s of node 1.\n", value(&bt, leftChild(&bt, 1)), value(&bt, rightChild(&bt, 1)));
	printf("left: %s, right : %s of node 2.\n", value(&bt, leftChild(&bt, 2)), value(&bt, rightChild(&bt, 2)));
	printf("left: %s, right : %s of node 3.\n", value(&bt, leftChild(&bt, 3)), value(&bt, rightChild(&bt, 3)));
	printf("left: %s, right : %s of node 4.\n", value(&bt, leftChild(&bt, 4)), value(&bt, rightChild(&bt, 4)));


	printf("배열의 크기 : %d", (sizeof(sample) / sizeof(sample[0])));
	printf("\n후위탐색\n");
	post_order_c(bt, 1); 	

	/*
	Element temp;
	for (int i = 1; i < 9; i++) {
		for (int j = 0; j < i - 1; j++) {
			int ret = strcmp(sample[i], sample[i + 1]);
			//printf("%d", ret);

			if (ret == -1) {
				temp = sample[j];
				sample[j] = sample[j + 1];
				sample[j + 1] = temp;
			}
			else if (ret == 1) {
				temp = sample[j + 1];
				sample[j + 1] = sample[j];
				sample[j] = temp;
			}

		}

	}
	//*/

}
//*/
int main() {
	test2();
	return 0;
}