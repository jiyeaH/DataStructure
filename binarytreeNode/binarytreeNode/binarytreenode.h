#pragma once

typedef int Element;

typedef struct Node {
	Element data;
	struct Node* left;
	struct Node* right;

}Node;

Node* create(Element e);
void dispose(Node* n);
void print(const Node* root);
Node* insertLeft(Node* root, int value);
Node* insertRight(Node* root, int value);

void inOrder(const Node* root);
void preOrder(const Node* root);
void postOrder(const Node* root);

int noOfNodes(const Node* root);
int noOfLeafNodes(const Node* root);
int noOfInternalNodes(const Node* root);
int height(const Node* root);
int noOfLeafOneNodes(const Node* root);

//이진 탐색 트리
Node* BST_recursiveSearch(Node* root, Element e);
Node* BST_iterativeSearch(Node* root, Element e);

Node* BST_recursiveInsert(Node* root, Element e);
Node* BST_recursiveDelete(Node* root, Element e);

Node* BST_findMin(Node* root);
Node* BST_findMax(Node* root);