#include<stdio.h>
#include<stdlib.h>

#define OK 1
#define TRUE 1
#define FALSE 0
#define MVNum 100 	//最大顶点数
typedef int Status;
typedef char VerTexType;

typedef struct ArcNode { //边结点（构成边链表）
	int adjvex; 				//该边所指向的顶点的位置
	struct ArcNode* nextarc; //指向下一条边的指针
}ArcNode;
typedef struct VNode { 	//表头结点
	VerTexType data; 		//顶点信息
	ArcNode* firstarc; 		//指向第一条依附该顶点的边的指针
}VNode, AdjList[MVNum]; //表头向量类型
typedef struct { 			//邻接表类型
	AdjList vertices;
	int vexnum, arcnum; 	//图的当前顶点数和边数
}ALGraph;
int visited[MVNum]; 		//定义访问标志数组

int LocateVex(ALGraph G, VerTexType u)
{
	int i;
	for (i = 0; i < G.vexnum; ++i)
		if (u == G.vertices[i].data)
			return i;
	return -1;
}

Status CreateUDG(ALGraph& G)
{ 						//采用邻接表存储形式，创建无向图 G 
	int i, j, k;
	VerTexType v1, v2;
	ArcNode* p1, * p2;
	printf("输入总顶点数和总边数：");
	scanf("%d%d", &G.vexnum, &G.arcnum); //输入总顶点数，总边数
	printf("输入每个顶点：");
	for (i = 0; i < G.vexnum; ++i) { //输入各顶点，构造表头结点表（即表头向量）
		getchar();
		scanf("%c", &G.vertices[i].data); 	//输入顶点值
		G.vertices[i].firstarc = NULL;		//初始化表头结点的指针域为 NULL
	}//for
	printf("输入每条边依附的顶点：\n");
	getchar();
	for (k = 0; k < G.arcnum; ++k) { 		//输入各边，构造邻接表

		scanf("%c%*c%c%*c", &v1, &v2);
		i = LocateVex(G, v1); 		//确定 v1 在图 G 表头向量中的位置 i
		j = LocateVex(G, v2); 		//确定 v2 在图 G 表头向量中的位置 j
		p1 = (ArcNode*)malloc(sizeof(ArcNode)); //生成一个新的边结点*p1
		p1->adjvex = j; 			//记录邻接点 vj 在表头向量中的位置 j
		p1->nextarc = G.vertices[i].firstarc; G.vertices[i].firstarc = p1;
		//将新的边结点*p1 插入到顶点 vi 的边链表首部
		p2 = (ArcNode*)malloc(sizeof(ArcNode));
		//生成另一个对称的新的边结点*p2
		p2->adjvex = i; //记录邻接点 vi 在表头向量中的位置 i
		p2->nextarc = G.vertices[j].firstarc; G.vertices[j].firstarc = p2;
		//将新的边结点*p2 插入到顶点 vj 的边链表首部
	}//for
	return OK;
}
void Display(ALGraph G)
{
	int i;
	ArcNode* p;
	printf("*****邻接表表示法创建的无向图*****\n");
	for (i = 0; i < G.vexnum; i++)
	{
		printf("%c", G.vertices[i].data);
		p = G.vertices[i].firstarc;
		while (p)
		{
			printf("->%d", p->adjvex);
			p = p->nextarc;
		}
		printf("\n");
	}
}
void DFS(ALGraph G, int v) {
	//从 v 顶点出发深度优先遍历图 G（递归）
	int w;
	ArcNode* p;
	printf("%c ", G.vertices[v].data);//访问 v 顶点，
	visited[v] = TRUE; 			//并置访问标志数组的相应分量值为 1
	p = G.vertices[v].firstarc; 	//p 指向 v 顶点的边链表的第一个边结点
	while (p != NULL) { 			//若边结点非空
		w = p->adjvex;			//表示 w 是 v 的邻接点
		if (!visited[w]) DFS(G, w);	//若 w 未访问，则递归调用 DFS
		p = p->nextarc; 		//p 指向下一个边结点
	}
}
int main()
{
	ALGraph G;
	VerTexType c;
	CreateUDG(G);
	Display(G);
	printf("请输入遍历连通图的起始点：");
	scanf("%c", &c);
	printf("\n深度优先搜索遍历图结果：");
	for (int i = 0; i < G.vexnum; i++)
		visited[i] = FALSE; //置访问标志数组的初值为 0
	DFS(G, LocateVex(G, c));
	return 0;
}