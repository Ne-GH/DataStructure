#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

#define OVERFLOW -2
#define OK 1
#define  ERROR 0

typedef int status;

typedef int ElemType;

typedef ElemType* Triplet;

int InitTriplet(Triplet* T, int v1, int v2, int v3) {//构造三元组T，依次赋值v1,v2,v3    
	(*T) = (int*)malloc(3 * sizeof(int));
	if (!T) exit(OVERFLOW);
	(*T)[0] = v1; (*T)[1] = v2; (*T)[2] = v3;
	return OK;

}
int DestoryTriplet(Triplet* t) {//销毁三元组
	free(*t);
	*t = NULL;

	return OK;
}
int Get(Triplet t, int i, int* e) {
	//去三元组的一个分量，用e返回t的第i元素的值
	if (i < 1 || i>3)  return ERROR;

	*e = t[i - 1];

	return OK;
}
int Put(Triplet* t, int i, int e) {
	if (i < 1 || i>3) return OVERFLOW;

	(*t)[i - 1] = e;

	return OK;

}
int Min(Triplet T, int* e) {
	*e = (T[0] <= T[1]) ? ((T[0] <= T[2]) ? T[0] : T[2]) : ((T[1] <= T[2]) ? T[1] : T[2]);
	return OK;
}
void Print(Triplet T) {
	int i;

	ElemType elem, * p = &elem;

	for (i = 1; i <= 3; i++) {
		Get(T, i, p);
		printf("T[%d]=%d\n", i, elem);
	}

}
int main() {
	Triplet T, * t = &T;
	int e1, e2, e3, e, * p = &e;
	int i;

	printf("\n请输入三元组元素e1 e2 e3:\n");
	scanf("%d%d%d", &e1, &e2, &e3);
	printf("输出的三元组为：\n");
	InitTriplet(t, e1, e2, e3);
	Print(T);
	printf("\n请输入要取出的三元组分量的位序\n");
	scanf("%d", &i);
	if (i >= 1 && i <= 3) {
		Get(T, i, p);
		printf("\n三元组中第%d个元素是：%d\n", i, *p);

	}
	printf("\n最大值为:%d\n", e);
	Min(T, p);
	printf("\n最小值为:%d\n", e);
	DestoryTriplet(t);
}
