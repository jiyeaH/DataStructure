#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

#define MAX_WORD_SIZE	 100
#define MAX_MEANING_SIZE 200

// 데이터 형식
typedef struct {
	char word[MAX_WORD_SIZE];		// 키필드
	char meaning[MAX_MEANING_SIZE];
} element;
// 노드의 구조
typedef struct TreeNode {
	element key;
	struct TreeNode *left, *right;
} TreeNode;

int compare(element e1, element e2);
void display(TreeNode *p);
TreeNode *search(TreeNode *root, element key);
void insert_node(TreeNode **root, element key);
void delete_node(TreeNode **root, element key);
void help();