#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

#define MAX_WORD_SIZE	 100
#define MAX_MEANING_SIZE 200

// ������ ����
typedef struct {
	char word[MAX_WORD_SIZE];		// Ű�ʵ�
	char meaning[MAX_MEANING_SIZE];
} element;
// ����� ����
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