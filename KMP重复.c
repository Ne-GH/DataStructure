#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char W[10005], T[1000005];
int len_W, len_T;

void next_(int* next, int len_W) {
	int i = 0, j = -1;
	next[0] = -1;
	while (i < len_W - 1) {
		if (W[i] == W[j] || j == -1) {
			++i;
			++j;
			next[i] = j;

		}
		else {
			j = next[j];
		}
	}
	return;
}

int KMP_C(int len_W, int len_T) {
	int i = 0, j = 0, C = 0;
	int* next = (int*)malloc(len_W * sizeof(int));

	next_(next, len_W);
	while (i < len_T) {
		if (T[i] == W[j] || j == -1) {
			++i;
			++j;
		}

		else
			j = next[j];

		if (j == len_W) {
			j = 0;
			//j = next[j - 1];
			//--i;
			++C;
		}



	}

	free(next);
	return C;
}

int main() {
	int n;
	while (1) {
		scanf("%s", T);
		if (T[0] == '#')
			return 0;
		scanf("%s", W);
		len_W = strlen(W);
		len_T = strlen(T);
		printf("%d\n", KMP_C(len_W, len_T));

	}
	return 0;
}