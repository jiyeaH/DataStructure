#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

#define MAXWORD 100

/* the tree node -���带 �Է¹��� Ʈ���� �����ϴ� ��Ʈ����.(root����) */

struct tnode {
	char *word;     // points to the text.
	struct tnode *left;   // left child.
	struct tnode *right;  // right child.
};

/* �Լ� ����.*/

struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
int getword(char *word, int);
struct tnode *talloc(void);

/*************************************************************/
/* word frequency count. �����Լ�.*/
/*************************************************************/

int main(void) {
	struct tnode *root;  // left �� right�� ��Ӵ�.
	char word[MAXWORD];  // keyword�� �Է¹��� �迭. Ʈ���� ���Ե� ��.

	root = NULL;   // root�� �ʱ�ȭ.
	while (getword(word, MAXWORD) != EOF)
		root = addtree(root, word);
	treeprint(root);
	return 0;
}

/*************************************************************/
/* getword.
/*  -�Ѱ谪�� �� getchar.
/*************************************************************/
int getword(char *word, int i)
{
	int cnt = 0;
	printf("�Է��Ͻÿ�. ����ÿ� ctrl+z\n");
	while ((*(word + cnt) = getchar()) != ' ' && *(word + cnt) != '\n')
	{
		if (cnt == (MAXWORD - 1)) {
			printf("�ܾ��� ũ�Ⱑ �ʰ��߽��ϴ�.\n");
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
/* -root�� �� �ڽ��� �� word�� �޾ƿ�.
/* -return ���� ���� �����Ǵ� ��Ʈ����.(word �� ������)
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
	else if ((cond = strcmp(w, p->word)) == 0)  // ��Ʈ�� ������ ����...
		printf("\n���ԺҰ�\n");
	else if (cond < 0)     // ��Ʈ���� ������ ���� �ڽ�..
		p->left = addtree(p->left, w);
	else        // ũ�� ������ �ڽ�..
		p->right = addtree(p->right, w);
	return p;
}

/*************************************************************/
/* treeprint.
/*  - ��Ʈ�� ���� �ڽ� ������ �ڽ��� ���ʷ� ���.
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



