#include<stdio.h>
void Hanoi(int, char, char, char);
int main() {
	int n;
	scanf("%d", &n);
	//n为有多少盘子
	Hanoi(n, 'A', 'B', 'C');

	return 0;
}
void Hanoi(int n, char A, char B, char C) {
	if (n == 1)
		printf("%c->%c\n", A, C);
	else {
		Hanoi(n - 1, A, C, B);
		//将A上的n-1个盘子借助C移动到B\
		不要管具体的实现,记住这是从宏观不断向微观递推= =
		printf("%c->%c\n", A, C);
		Hanoi(n - 1, B, A, C);
		//将A上的n-1个盘子借助A移动到C
	}


	return;
}