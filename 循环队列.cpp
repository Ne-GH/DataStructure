#include<cstdio>
#include<cstdlib>
typedef struct Queue {
	int* pBase;
	int front;
	int rear;
}QUEUE;
void init(QUEUE*);
bool en_queue(QUEUE*, int val);
void traverse_queue(QUEUE* pQ);
bool full_queue(QUEUE*);
bool out_queue(QUEUE* pQ, int* pVal);
bool emput_queue(QUEUE* pQ);
int main() {
	QUEUE Q;//定义Q变量有三个成员
	int Val;
	init(&Q);
	en_queue(&Q, 1);
	en_queue(&Q, 2);
	en_queue(&Q, 3);
	en_queue(&Q, 4);
	en_queue(&Q, 5);
	en_queue(&Q, 6);
	en_queue(&Q, 7);
	en_queue(&Q, 8);

	traverse_queue(&Q);
	if (out_queue(&Q, &Val))
		printf("出队成功,队列出队的元素是%d\n", Val);
	else
		printf("出队失败!\n");

	return 0;
}
void init(QUEUE* pQ) {
	pQ->pBase = (int*)malloc(sizeof(int) * 6);//动态分配了大小为6\
											    类型为int的数组
	pQ->front = 0;
	pQ->rear = 0;
	return;
}
bool en_queue(QUEUE* pQ, int val) {
	if (full_queue(pQ))
		return false;
	else {
		pQ->pBase[pQ->rear] = val;
		pQ->rear = (pQ->rear + 1) % 6;
		return true;
	}


}
bool full_queue(QUEUE* pQ) {
	if ((pQ->rear + 1) % 6 == pQ->front)
		return true;
	else
		return false;
}
void traverse_queue(QUEUE* pQ) {
	int i = pQ->front;
	while (i != pQ->rear) {
		printf("%d ", pQ->pBase[i]);
		i = (i + 1) % 6;
	}
	printf("\n");
	return;
}
bool out_queue(QUEUE* pQ, int* pVal) {
	if (emput_queue(pQ))
		return false;
	else {

		*pVal = pQ->pBase[pQ->front];
		pQ->front = (pQ->front + 1) % 6;
		return true;
	}
}

bool emput_queue(QUEUE* pQ) {
	if (pQ->front == pQ->rear)
		return true;
	else
		return false;
}