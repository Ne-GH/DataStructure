#include <stdio.h>
#include<stdlib.h>
#define Max 100			//顶点数量
#define Max_queue 100//队列最大长度
int visited[Max]; 			//访问标志数组

typedef struct {			//邻接矩阵存储
    char vexs[Max];		//图中的顶点
    int arcs[Max][Max];	//邻接矩阵
    int vexnum, arcnum;	//当前顶点数和图的边数
} Graph;					//图

typedef struct {
    int front;			//首元素
    int back;			//尾元素
    int* base;			//指向队列的首地址
}SqQueue;

//返回顶点'u'在图'G'中的下标,未找到返回-1
int LocateVex(Graph G, char u) {

    for (int i = 0; i < G.vexnum; ++i) {
        if (u == G.vexs[i])
            return i;
    }
    return -1;		//没有找到

}

//构造无向图G
int CreateUDG(Graph& G) {
    int i, j, k;
    char v1, v2;
    printf("请输入总的顶点数和总边数: ");
    scanf("%d%d", &G.vexnum, &G.arcnum);
    printf("输入每个顶点: ");

    for (i = 0; i < G.vexnum; ++i) {
        getchar();				//接收缓冲区中的空格等无效字符
        scanf("%c", &G.vexs[i]);	//输入顶点字符
    }							//输入顶点字符
    for (i = 0; i < G.arcnum; ++i) {
        for (j = 0; j < G.vexnum; ++j)
            G.arcs[i][j] = 0;
    }							//将数组中的数据初始化为0
    printf("输入每条边依附的顶点\n");
    for (k = 0; k < G.arcnum; ++k) {
        scanf("%*c%c%*c%c", &v1, &v2);
        //用%*c接收缓冲区的无效字符,类似于getchar()
        i = LocateVex(G, v1);
        j = LocateVex(G, v2);
        G.arcs[i][j] = 1;//邻接矩阵标记有边
        G.arcs[j][i] = 1;//无向图的邻接矩阵对称
    }
    return 0;
}

//输出图的邻接矩阵
void Display(Graph G) {
    printf("**********邻接矩阵表示法创建的无向图************\n");
    for (int i = 0; i < G.vexnum; ++i) {
        for (int j = 0; j < G.vexnum; ++j) {
            printf("%d ", G.arcs[i][j]);
        }
        putchar(10);
    }											//打印二维矩阵
}

//构造一个队列
void InitQueue(SqQueue& Q) {
    Q.base = (int*)malloc(sizeof(int) * Max_queue);//为队列分配内存
    if (!Q.base)							//malloc分配内存失败时返回NULL
        exit(-1);						//结束程序
    Q.front = Q.back = 0;				//队列为空,首尾下标均为0
}

//将元素插入循环队列
void EnQueue(SqQueue& Q, int e) {
    if ((Q.back + 1) % Max_queue == Q.front)//队列已满
        return;
    Q.base[Q.back] = e;					//将e放入队尾
    Q.back = (Q.back + 1) % Max_queue;	//队尾后移1
}

//判断队列是否为空,为空时返回true
bool QueueEmpty(SqQueue Q) {
    if (Q.back == Q.front)
        return true;
    return false;
}

//队首元素赋给e并出队
void DeQueue(SqQueue& Q, int& e) {
    e = Q.base[Q.front];					//将队首元素赋给变量e
    Q.front = (Q.front + 1) % Max_queue;	//队首元素出队
}

//返回图中第v个元素的第一个邻接点
int FirseAdjVex(Graph G, int v) {
    for (int i = 0; i < G.vexnum; ++i) {
        if (1 == G.arcs[v][i] && 0 == visited[i]) { //存在弧,且该顶点未被访问
            return i;
        }
    }
    return -1;
}

//返回 v 相对于 w 的下一个邻接点
int NextAdjVex(Graph G, int u, int w) {
    for (int i = w; i < G.vexnum; ++i) {
        if (1 == G.arcs[u][i] && 0 == visited[i])
            return i;
    }
    return -1;
}
void BFS(Graph G, int v) {
    SqQueue Q;
    int u, w;//u表示出队的顶点
    printf("%c ", G.vexs[v]);
    visited[v] = 1;							//顶点v的状态标记为已访问
    InitQueue(Q);						//初始化队列Q
    EnQueue(Q, v);						//顶点v入队
    while (!QueueEmpty(Q)) {				//队列Q非空
        DeQueue(Q, u);					//队头元素出队并置为u
        for (w = FirseAdjVex(G, u); w >= 0; w = NextAdjVex(G, u, w)) {
            if (!visited[w]) {				//如果顶点w未被访问
                printf("%c ", G.vexs[w]);
                visited[w] = 1;			//标记为已访问
                EnQueue(Q, w);		//顶点w入队
            }
        }
    }
}
int main() {
    Graph G;
    char c;
    CreateUDG(G);						//构造G的无向图
    Display(G);							//输出图G的邻接矩阵
    printf("请输入遍历连通图的起始点: ");
    getchar();
    scanf("%c", &c);
    printf("\n广度优先搜索遍历图结果: ");
    BFS(G, LocateVex(G, c));
    return 0;
}
