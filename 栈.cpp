#include<cstdio>
#include<cstdlib>
typedef struct node {
	int data;
	struct node* pnext;
}NODE, * PNODE;

typedef struct stack {
	PNODE pTop;
	PNODE pBottom;
}STACK, * PSTACK;
void init(PSTACK pS);
void push(PSTACK pS, int x);
void sraverse(PSTACK pS);
void destroy(PSTACK pS);
int main() {
	STACK S;//定义了一个stack(栈)S;
	init(&S);//初始化,取实参地址
	push(&S, 1);//压栈
	push(&S, 2);//压栈
	push(&S, 3);//压栈
	push(&S, 4);//压栈
	push(&S, 5);//压栈
	push(&S, 6);//压栈
	sraverse(&S);//遍历,由栈的先进后出特性可知,
				 //输出结果应该为6,5,4,3,2,1
	return 0;
}
void init(PSTACK pS) {
	pS->pTop = (PNODE)malloc(sizeof(NODE));
	if (pS->pTop == NULL) {
		printf("动态内存分配失败");
		exit(-1);
	}
	else {
		pS->pBottom = pS->pTop;
		pS->pTop->pnext = NULL;//也可以用pS->Bottom
	}
	printf("创建了一个空的栈\n");
	return;
}
void push(PSTACK pS, int x) {
	PNODE New = (PNODE)malloc(sizeof(NODE));
	New->data = x;
	New->pnext = pS->pTop;
	pS->pTop = New;
	return;
}
void sraverse(PSTACK pS) {
	PNODE p = pS->pTop;
	while (p->pnext != pS->pBottom->pnext) {
		printf("%d  ", p->data);
		p = p->pnext;
	}
	return;
}