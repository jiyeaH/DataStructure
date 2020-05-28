#include <stdio.h>
#include "binarytreenode.h"


// GraphViz 출력을 위한 코드
void printGraphViz(const Node* root) {
	if (root != NULL) {
		if (root->left != NULL)	printf("\t%d->%d\n", root->data, root->left->data);
		printGraphViz(root->left);

		if (root->right != NULL) printf("\t%d->%d\n", root->data, root->right->data);
		printGraphViz(root->right);
	}
}

void printGraphVizDriver(const Node* root) {
	printf("\ndigraph g{ \n");
	printGraphViz(root);
	printf("}\n");
}

void test1() {
	Node n1 = { 2,NULL,NULL };
	Node n2 = { 3,NULL,NULL };
	Node n3 = { 1,&n1,&n2 };

	Node* root = &n3;
	printf("----------test1-----\n\n");

	printf("%d ", root->data);
	printf("%d ", root->left->data);
	printf("%d ", root->right->data);
	printGraphVizDriver(root);

}
void test2() {
	Node* root = NULL;
	root = create(1);
	root->left = create(2);
	root->right = create(3);

	Node*t = root->left;
	t->left = create(4);
	t->right = create(5);

	t = root->right;
	t->left = create(6);
	t->right = create(7);
	printf("\n------------test2-----\n\n");

	print(root);
	printGraphVizDriver(root);
	dispose(root);


}
void test3() {
	Node* root = NULL;
	root = create(1);
	insertLeft(root, 2);
	insertRight(root, 3);

	Node* t = root->left;
	insertLeft(t, 4);
	insertRight(t, 5);

	t = root->right;
	insertLeft(t, 6);
	insertRight(t, 7);
	printf("\n-----------test3-----\n\n");
	print(root);
	printGraphVizDriver(root);
	dispose(root);
}

void test4() {
	Node n1 = { 20, NULL,NULL };
	Node n2 = { 30, NULL,NULL };
	Node n3 = { 10, &n1, &n2 };

	Node* root = &n3;
	Node n6 = { 60,NULL,NULL };
	Node n7 = { 70,NULL,NULL };

	Node n4 = { 40, &n6,NULL };
	Node n5 = { 50, NULL,&n7 };

	n1.left = &n4;
	n1.right = &n5;
	n4.left = &n6;
	n5.right = &n7;

	printGraphVizDriver(root);

	printf("\n-------------test4-----\n\n");
	inOrder(root); printf("\n");
	preOrder(root); printf("\n");
	postOrder(root); printf("\n");

	printf("\n---------이진트리 연산-----\n\n");
	printf("No of Nodes : %d\n", noOfNodes(root));
	printf("No of Internal Nodes : %d\n", noOfInternalNodes(root));
	printf("No of Leaf Nodes : %d\n", noOfLeafNodes(root));
	printf("Height of Trees : %d\n", height(root));
	printf("자식노드가 1개 : %d\n", noOfLeafOneNodes(root));

}
void test5() {
	Node* bst = NULL;
	printf("\n-------------test5-----\n\n");

	bst = BST_recursiveInsert(bst, 31);
	BST_recursiveInsert(bst, 16);
	BST_recursiveInsert(bst, 45);
	printGraphVizDriver(bst);

	BST_recursiveInsert(bst, 24);
	BST_recursiveInsert(bst, 7);
	printGraphVizDriver(bst);

	BST_recursiveInsert(bst, 19);
	BST_recursiveInsert(bst, 29);
	printGraphVizDriver(bst);

	bst = BST_recursiveDelete(bst, 7);
	bst = BST_recursiveDelete(bst, 16);
	bst = BST_recursiveDelete(bst, 24);
	bst = BST_recursiveDelete(bst, 31);
	printGraphVizDriver(bst);

	dispose(bst);
	bst = NULL;

}

int main() {
	test4();
	return 0;
}