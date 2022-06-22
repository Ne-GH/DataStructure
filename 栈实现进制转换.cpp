#include<iostream>
#include<stdlib.h>
#define SIZE_STACK 40//初始量
#define SIZE_ADD 2000000//追加
typedef struct stack {
	int size;
	int* top;//指向栈顶后面的元素
	int* base;//指向栈底
}STACK, * PSTACK;

bool decide(PSTACK&);//判定是否已满
void init(PSTACK&);//初始化
void push(PSTACK&, int);//压栈
void pop(PSTACK&);

int main() {
	long long n;//待转换的数字
	PSTACK Sta = (PSTACK)malloc(sizeof(STACK));
	/*为一个结构体指针分配了内存,但是此时还没有为指针中的两个指针分配指向的内存*/

	init(Sta);
	do {
		printf("请输入你想转化为8进制的10进制正整数: ");

		if (std::cin >> n) {

			while (n) {//转化的过程中依次入栈
				push(Sta, n % 8);
				n /= 8;
				Sta->size++;
			}
			pop(Sta);
		}
		else
			break;
	} while (1);

	return 0;
}
void init(PSTACK& Sta) {//形参接收了地址,像实参一样使用
	Sta->base = (int*)malloc(SIZE_STACK * sizeof(int));//顺序表实现的栈
	if (!Sta->base)
		exit(-1);
	Sta->size = 0;//初始化栈中元素的数量为0
	Sta->top = Sta->base;//初始化top的指针										
	return;
}

void push(PSTACK& Sta, int n) {//压栈
	if (decide(Sta) != true)//返回true表示不满
		Sta = (PSTACK)realloc(Sta, 
			(SIZE_STACK + SIZE_ADD) * sizeof(long long));//追加分配
	*(Sta->top++) = n; /*数据赋给top当前指向的位置,然后top指针后移*/
	Sta->size++;
	return;
}

void pop(PSTACK& Sta) {//出栈
	Sta->top--;
	while (1) {
		printf("%d", *(Sta->top));
		if (Sta->top == Sta->base) {
			putchar(10);
			return;
		}
		Sta->top--;
	}
	Sta->size = 0;
	/*由于调用一次函数就将栈中的元素全部输出,因此,
		该函数的最后初始化栈中元素的数量*/
	return;
}

bool decide(PSTACK& Sta) {
	if (Sta->size < SIZE_STACK)
		return true;//不满
	else
		return false;//满
}