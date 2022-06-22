#include<stdio.h>
#include<stdlib.h>
typedef int Elem;

struct node {
	Elem* data;
	Elem length;
	Elem size;
};

void init(struct node*&);//初始化
void seek(struct node*&);//查找
void delete_(struct node*&);//删除
void insert(struct node*&);//插入
void print(struct node*&);//打印

int main() {
	node* NODE = (node*)malloc(sizeof(node));

	init(NODE);

	while (1) {
		printf(
			"1.插入元素\n"
			"2.删除元素\n"
			"3.查找元素\n"
			"4.退出\n"
			"请选择你要进行的操作: "
			);
		int n;
		scanf("%d", &n);
		switch (n) {
		case 1:
			insert(NODE);
			print(NODE);
			break;
		case 2:
			delete_(NODE);
			print(NODE);
			break;
		case 3:
			seek(NODE);
			break;
		case 4:
			goto A;
			break;
		default:
			printf(
				"选择错误\n"
				"------------------------------------\n"
				);
		}

	}
A:
	free(NODE->data);
	free(NODE);
	printf("该表已清空\n");
	return 0;

}

void init(struct node*& T) {
	printf("输入元素个数和各元素的值: ");
	scanf("%d", &(T->length));
	T->data = (Elem*)malloc(100 * sizeof(Elem));
	if (!(T->data)) {
		printf("分配内存失败\n");
		exit(-1);
	}
	int i = 0;
	while (i < T->length) {
		scanf("%d", &(T->data[i]));
		i++;
	}

	return;
}

void print(struct node*& T) {
	printf("------------------------------------\n");
	for (int i = 0; i < T->length; i++)
		printf("%d\t", T->data[i]);
	putchar(10);
	printf("------------------------------------\n");
	return;
}

void delete_(struct node*& T) {
	printf("输入要删除元素的位置: ");
	int n;
	scanf("%d", &n);
	if (n > T->length)
		printf("不能在该位置删除数据\n");
	else {
		for (int i = n - 1; i < T->length - 1; i++)//位序n及之后的数据依次前移
			T->data[i] = T->data[i + 1];
		T->length--;//表长-1;
	}
	return;
}

void insert(struct node*& T) {
	printf("输入要插入元素的位置和值: ");
	int n;
	scanf("%d", &n);
	if (n > T->length + 1)
		printf("不能在该位置插入数据\n");
	else {
		for (int i = T->length; i >= n; i--)//插入位置及之后的值,从后往前一次后移
			T->data[i] = T->data[i - 1];
		scanf("%d", &(T->data[n - 1]));
		T->length++;//表长+1,成员运算符的优先级更高,不需要括号
	}
	return;
}

void seek(struct node*& T) {
	printf("请输入要查找的值: ");
	int x;
	scanf("%d", &x);
	int i;
	for (i = 0; i < T->length; i++) {//遍历查找
		if (T->data[i] == x) {
			printf("该元素的位置是%d\n", i + 1);
			break;
		}
	}
	if (i == T->length)//如果找到,i最大为T->length-1,break后不会自增
		printf("未找到该元素\n");
	return;

}