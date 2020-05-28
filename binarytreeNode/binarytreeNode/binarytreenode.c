#include <stdio.h>
#include <malloc.h>
#include "binarytreenode.h"
#define max(X,Y) ( (X) > (Y) ? (X) : (Y) )

Node* create(Element e) {
	Node* n = (Node *)malloc(sizeof(Node));
	n->data = e;
	n->left = NULL;
	n->right = NULL;

	return n;
}

void dispose(Node* root) {
	if (root != NULL) {
		dispose(root->left);
		dispose(root->right);
		free(root);
	}
}
void print(const Node* root) {
	if (root != NULL) {
		print(root->left);
		printf("%d ", root->data);
		print(root->right);
	}
}

Node* insertLeft(Node* root, int value) {
	root->left = create(value);
	return root->left;
}

Node* insertRight(Node* root, int value) {
	root->right = create(value);
	return root->right;
}

void inOrder(const Node* root) {
	if (root) {
		inOrder(root->left);
		printf("%d ", root->data);
		inOrder(root->right);
	}
}
void preOrder(const Node* root) {
	if (root) {
		printf("%d ", root->data);
		preOrder(root->left);
		preOrder(root->right);
	}
}
void postOrder(const Node* root) {
	if (root) {
		postOrder(root->left);
		postOrder(root->right);
		printf("%d ", root->data);
	}
}

int noOfNodes(const Node* root) {
	if (!root) return 0;
	else return noOfNodes(root->left) + noOfNodes(root->right) + 1;
}

int noOfLeafNodes(const Node* root) {
	if (!root) return 0;
	else {
		if (root->left == NULL && root->right == NULL) return 1;
		else return noOfLeafNodes(root->left) + noOfLeafNodes(root->right);
	}
}
int noOfLeafOneNodes(const Node* root) {// 자식노드가 1개
	if (!root) return 0;
	else {
		if (root->left == NULL && root->right != NULL || root->left != NULL && root->right == NULL) return 1;
		else if (root->left == NULL && root->right == NULL) return 0;
		else return noOfLeafOneNodes(root->left) + noOfLeafOneNodes(root->right);
	}
}

int noOfInternalNodes(const Node* root) {
	if (!root) return 0;
	else if (root->left == NULL && root->right == NULL) return 0;
	else if (root->left != NULL || root->right != NULL) return noOfInternalNodes(root->left) + noOfInternalNodes(root->right) + 1;

}

int height(const Node* root) {

	if (!root) return 0;
	else return 1 + max(height(root->left), height(root->right));
}


Node* BST_recursiveSearch(Node* root, Element e) {
	if (root == NULL) return NULL;
	if (e == root->data) return root;
	else if (e < root->data) return BST_recursiveSearch(root->left, e);
	else return BST_recursiveSearch(root->right, e);
}
Node* BST_iterativeSearch(Node* root, Element e) {
	while (root) {
		if (e == root->data) return root;
		else if (e < root->data) root = root->left;
		else root = root->right;
	}
	return NULL;
}
Node* BST_recursiveInsert(Node* root, Element e) {
	if (root == NULL) root = create(e);
	else if (e < root->data) root->left = BST_recursiveInsert(root->left, e);
	else root->right = BST_recursiveInsert(root->right, e);

	return root;
}
Node* BST_findMin(Node* node) {
	if (node == NULL) {
		return NULL;
	}
	if (node->left) BST_findMin(node->left);
	else return node;
}
/*
Node* BST_findMax(Node* node) {
	if (node == NULL) {
		return NULL;
	}
	if (node->right) BST_findMax(node->right);
	else return node;
}
*/
Node* BST_recursiveDelete(Node* root, Element e) {
	if (root == NULL) return root;
	else if (e == root->data) {
		Node* temp;
		if (root->left&&root->right) {
			temp = BST_findMin(root->right);
			root->data = temp->data;
			root->right = BST_recursiveDelete(root->right, temp->data);
		}
		else {
			temp = root;
			if (root->left == NULL) root = root->right;
			else if (root->right == NULL)root = root->left;
			free(temp);
		}
	}
	else if (e < root->data) root->left = BST_recursiveDelete(root->left, e);
	else if (e > root->data) root->right = BST_recursiveDelete(root->right, e);

	return root;
}