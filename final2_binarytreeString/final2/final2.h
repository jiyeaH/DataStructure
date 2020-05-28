#pragma once
#define MAX_SIZE (20)
#include <stdbool.h>
#include <string.h>
#include <math.h>
#define BUCKET_SIZE (10)

//typedef int Element;
/*
typedef struct {
bool isQuestion;
	char msg[100];
}Element;
//*/ //문답할때 사용

typedef const char* Element;

typedef struct {
	Element data[MAX_SIZE];
	int size;
}BinaryTree;


void init(BinaryTree* bt);
int leftChild(const BinaryTree* bt, const int pos);
int rightChild(const BinaryTree* bt, const int pos);
int parent(const BinaryTree* bt, const int pos);
Element value(const BinaryTree* bt, const int pos);
void insert(BinaryTree* bt, const Element e);
int skewedTree(const BinaryTree* bt, const int pos);
void post_order_c(const BinaryTree bt, int index);