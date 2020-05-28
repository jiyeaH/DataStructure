#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

#define MAXWORD 100

/* the tree node -워드를 입력받을 트리를 구성하는 스트럭쳐.(root형태) */

struct tnode {
	char *word;     // points to the text.
	struct tnode *left;   // left child.
	struct tnode *right;  // right child.
};

/* 함수 선언.*/

struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
int getword(char *word, int);
struct tnode *talloc(void);

/*************************************************************/
/* word frequency count. 메인함수.*/
/*************************************************************/

int main(void) {
	struct tnode *root;  // left 와 right의 어머니.
	char word[MAXWORD];  // keyword를 입력받을 배열. 트리에 삽입될 것.

	root = NULL;   // root의 초기화.
	while (getword(word, MAXWORD) != EOF)
		root = addtree(root, word);
	treeprint(root);
	return 0;
}

/*************************************************************/
/* getword.
/*  -한계값을 준 getchar.
/*************************************************************/
int getword(char *word, int i)
{
	int cnt = 0;
	printf("입력하시오. 종료시엔 ctrl+z\n");
	while ((*(word + cnt) = getchar()) != ' ' && *(word + cnt) != '\n')
	{
		if (cnt == (MAXWORD - 1)) {
			printf("단어의 크기가 초과했습니다.\n");
			exit(1);
		}

		if (*(word + cnt) == EOF)
			return *(word + cnt);

		cnt++;
	}

	*(word + cnt) = '\0';
	printf("%s", word);

	return *(word + cnt);
}

/*************************************************************/
/* addtree routine.
/* -root와 그 자식이 될 word를 받아옴.
/* -return 값은 새로 생성되는 스트럭쳐.(word 를 삽입함)
/*************************************************************/

struct tnode *addtree(struct tnode *p, char *w)
{
	int cond;
	if (p == NULL) {
		if ((p = talloc()) == NULL)
		{
			printf("error ");
			exit(1);
		}

		if ((p->word = (char*)malloc(strlen(w) + 1)) == NULL)
		{
			printf("error ");
			exit(1);
		}
		strcpy(p->word, w);        //strcpy.
		p->left = p->right = NULL;
	}
	else if ((cond = strcmp(w, p->word)) == 0)  // 루트랑 같으면 에라...
		printf("\n삽입불가\n");
	else if (cond < 0)     // 루트보다 작으면 왼쪽 자식..
		p->left = addtree(p->left, w);
	else        // 크면 오른쪽 자식..
		p->right = addtree(p->right, w);
	return p;
}

/*************************************************************/
/* treeprint.
/*  - 루트의 왼쪽 자식 오른쪽 자식을 차례로 출력.
/*************************************************************/

void treeprint(struct tnode *p)
{
	if (p != NULL) {
		treeprint(p->left);
		printf("%s\n", p->word);
		treeprint(p->right);
	}
}


struct tnode *talloc(void) {
	return (struct tnode *)malloc(sizeof(struct tnode));

}



