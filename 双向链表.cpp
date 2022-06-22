#include <stdio.h>
#include <stdlib.h>
typedef int Elemtype;
#pragma pack(1)
typedef struct Node {
	struct Node* last;//指向上一个节点
	Elemtype data;//存放数值
	int a;

	struct Node* next;//指向下一个节点
	struct Node* ce;

}DoubleLinkedList, * DLlist;
#pragma pack()

/*创建双向链表*/
DLlist CreatList()

{
	DLlist list = (DLlist)malloc(sizeof(DoubleLinkedList));
	//定义了一个头指针并分配了大小为DoubleLinkedList的空间,由list指向\
	并不是为list分配内存
	printf("%d\n", sizeof(DoubleLinkedList));
	printf("%p\n", list);
	printf("%p\n", &(list->a));
	printf("%p\n", &(list->data));
	printf("%p\n", &(list->last));
	printf("%p\n", &(list->next));
	printf("%p\n", &(list->ce));

	list->next = list->last = list;




	//list的next和last都指向自己
	list->data = -1;//指定一个特殊值，判断是否是头结点

	return list;

}

/*创建节点*/
DLlist CreatNode(Elemtype data)

{

	DLlist node = (DLlist)malloc(sizeof(DoubleLinkedList));

	node->data = data;

	node->last = node->next = node;//创建的时候使它的上一个和下一个节点都指向它本身，在插入时再做更改

	return node;

}

/*判断链表是否为空*/
int ListIsEmpty(DLlist L)

{

	if (L->last == L->next)//插入节点后，上一个节点和下一个节点必然不同

	{

		return 1;

	}

	return 0;

}

/*遍历打印双向链表*/
void PrintList(DLlist L)

{

	if (ListIsEmpty(L))
		printf("链表为空！\n");

	L = L->next;

	while (L->data != -1)

	{
		printf("%d-->", L->data);

		L = L->next;
	}

	printf("\n");

}

/*头插法插入建立链表*/
void InsertNodeByHead(DLlist L, Elemtype data)

{

	DLlist newnode = CreatNode(data);

	// 插入新节点，只有头结点的下一个节点和首节点的上一个节点会发生变化

	// 先使头结点的下一个节点的上一个节点指向插入的节点

	L->next->last = newnode;

	// 插入的节点指向首节点。首节点为头结点后一个节点

	newnode->next = L->next;

	// 头结点的下一个节点，插入的节点成为新的首节点

	L->next = newnode;

	//　最后将插入节点的上一个节点指向头结点

	newnode->last = L;

	printf("插入--%d--完成!\n", data);

}

/*尾插发建立链表*/
void InsertNodeByTail(DLlist L, Elemtype data)

{
	DLlist newnode = CreatNode(data);
	// 当前节点L的下一个节点不是头结点，即当前节点不是尾节点
	while (L->next->data != -1)
		L = L->next;
	//当前节点L是尾节点，使插入的节点的下一个节点指向当前节点的下一个节点

	newnode->next = L->next;

	//当前节点的下一个节点指向插入节点

	L->next = newnode;

	//插入节点的上一个指向当前节点

	newnode->last = L;

	printf("插入--%d--完成!\n", data);

}

/*删除值为data的节点*/
void RemoveNode(DLlist L, Elemtype data)

{

	DLlist last, next, delnode;

	L = L->next;

	//循环一次

	while (L->data != (-1))

	{

		//找到要删除的节点

		if (L->data == data)

		{

			delnode = L;

			last = delnode->last;//last为要删除节点的上一个节点

			next = delnode->next;//next为要删除节点的下一个节点

			delnode->next->last = last; //　要删除节点的下一个节点的上一个节点为删除节点的上一个节点

			delnode->last->next = next; //　要删除节点的上一个节点的下一个节点为删除节点的下一个节点

			printf("删除成功！\n");

			return;//删除后退出此函数，不执行while循环后面的语句

		}

		L = L->next;

	}

	printf("链表中无值为--%d--节点！\n", data);

}

/*在值为m的节点后插入值为data的节点*/
void InsertNode(DLlist L, Elemtype m, Elemtype data)

{

	DLlist next;

	DLlist newnode = CreatNode(data);

	L = L->next;

	//循环一次

	while (L->data != (-1))

	{

		//找到目的节点

		if (L->data == m)

		{

			next = L->next;

			//　插入节点的上一个节点指向当前节点

			newnode->last = L;

			// 当前节点的下一个节点的上一个节点指向插入的节点

			L->next->last = newnode;

			// 插入节点的下一个节点指向当前节点的下一个节点

			newnode->next = next;

			// 当前节点的下一个节点指向插入节点

			L->next = newnode;

			printf("添加成功！\n");

			return;//添加后退出此函数，不执行while循环后面的语句

		}

		L = L->next;

	}

	printf("链表中无值为--%d--的节点！\n", m);

}

/*将值为m的值修改为data*/
void ChangeNode(DLlist L, Elemtype m, Elemtype data)

{

	L = L->next;

	//循环一次

	while (L->data != (-1))

	{

		//找到目的节点

		if (L->data == m)

		{

			L->data = data;

			return;

		}

		L = L->next;

	}

	printf("链表中无值为--%d--的节点！\n", m);

}

/*获取值为data的节点的上一个节点*/
void GetLast(DLlist L, Elemtype data)

{

	L = L->next;

	while (L->data != (-1))

	{

		if (L->data == data)

		{

			if (L->last->data == (-1))

			{

				printf("值为-- %d --的节点的上一个节点为头结点！\n", data);

				return;

			}

			printf("节点-- %d --的上一个节点为-- %d --\n", L->data, L->last->data);

			return;

		}

		L = L->next;

	}

	printf("链表中无值为-- %d --的节点！\n", data);

}

/*获取值为data的节点的下一个节点*/
void GetNext(DLlist L, Elemtype data)

{

	L = L->next;

	while (L->data != (-1))

	{

		if (L->data == data)

		{

			if (L->next->data == (-1)) {
				printf("值为-- %d --的节点的下一个节点为头结点！\n", data);
				return;
			}
			printf("节点-- %d --的下一个节点为-- %d --\n", L->data, L->next->data);
			return;
		}
		L = L->next;
	}

	printf("链表中无值为-- %d --的节点！\n", data);
}

int main() {
	CreatList();



	return 0;
}
