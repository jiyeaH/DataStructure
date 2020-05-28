#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct weight {
	int up;
	int left;
};

struct weight w[4][4];

int recursive_mt(int n, int m) {
	int max, up, left;

	if (n == -1 || m == -1) return 0;

	up = recursive_mt(n - 1, m) + w[n][m].up;
	left = recursive_mt(n, m - 1) + w[n][m].left;

	if (up > left) max = up;
	else max = left;

	return max;
}

int main() {
	int mt[4][4];

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			mt[i][j] = 0;
			scanf("%d %d", &w[i][j].left, &w[i][j].up);
		}
	}
	
	printf("recursive : %d\n", recursive_mt(4, 4));


	///////////////////////////////////
	////                          /////
	////     dynamic programing   /////
	////                          /////
	///////////////////////////////////
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (i == 0 && j == 0) mt[i][j] = 0;
			else if (i == 0) mt[i][j] = mt[i][j-1] + w[i][j].left;
			else if (j == 0)mt[i][j] = mt[i - 1][j] + w[i][j].up;
			else if (mt[i - 1][j] + w[i][j].up > mt[i][j - 1] + w[i][j].left) mt[i][j] = mt[i - 1][j] + w[i][j].up;
			else mt[i][j] = mt[i][j - 1] + w[i][j].left;
		}
	}

	printf("dp : %d\n", mt[3][3]);



	return 0;
}

