#include<stdio.h>
void Quicksort(int* a, int x, int len);
int FindPos(int* a, int x, int len);
int main() {
	int val;
	int* L, * H;
	int a[6] = { -2,1,-3330,5,4,-3 };
	Quicksort(a, 0, 5);
	for (int i = 0; i < 6; i++) {
		printf("%d ", a[i]);
	}
	return 0;
}
void Quicksort(int* a, int x, int len) {
	int pos;
	if (x < len) {
		pos = FindPos(a, x, len);
		Quicksort(a, x, pos - 1);
		Quicksort(a, pos + 1, len);
	}

	return;
}
int FindPos(int* a, int x, int len) {
	int val = a[x];
	while (x < len) {
		while (x < len && a[len] >= val)
			--len;
		a[x] = a[len];
		while (x < len && a[x] <= val)
			++x;
		a[len] = a[x];
	}
	a[x] = val;
	return len;
}
