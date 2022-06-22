#include <stdio.h>
#include<stdlib.h>

#define Max 100//顶点数量
#define Max_stak 100
int visited[Max]; //访问标志数组

typedef struct {//邻接矩阵存储
    char vexs[Max];//图中的顶点
    int arcs[Max][Max];//邻接矩阵
    int vexnum, arcnum;//当前顶点数和图的边数
} Graph;//图


typedef struct {
    int top;
    int* base;
}Stack;//栈
//返回顶点'u'在图'G'中的下标,未找到返回-1
int LocateVex(Graph G, char u) {
    for (int i = 0; i < G.vexnum; ++i) {
        if (u == G.vexs[i])
            return i;
    }
    return -1;//没有找到
}

//构造无向图G
int CreateUDG(Graph& G) {
    int i, j, k;
    char v1, v2;
    printf("请输入总的顶点数和总边数: ");
    scanf("%d%d", &G.vexnum, &G.arcnum);
    printf("输入每个顶点: ");
    for (i = 0; i < G.vexnum; ++i) {
        getchar();//接收缓冲区中的空格等无效字符
        scanf("%c", &G.vexs[i]);//输入顶点字符
    }//输入顶点字符
    for (i = 0; i < G.arcnum; ++i) {
        for (j = 0; j < G.vexnum; ++j)
            G.arcs[i][j] = 0;
    }//将数组中的数据初始化为0
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
    }//打印二维矩阵
}

//构造一个栈
void InitStack(Stack& S) {
    S.base = (int*)malloc(sizeof(int) * Max_stak);
    if (!S.base)
        exit(-1);
    S.top = 0;//栈顶下标初始化为0
}

//将元素插入栈
void EnStack(Stack& S, int e) {
    if (S.top == Max_stak - 1)
        return;//栈满
    S.base[S.top] = e;
    S.top++;
}

//判断栈是否为空
bool StackEmpty(Stack S) {
    if (S.top == 0)
        return true;
    return false;
}

//栈顶元素赋给e并出栈
void DeStack(Stack& S, int& e) {
    e = S.base[S.top];
    S.top--;
}

//返回图中第v个元素的第一个未被访问的邻接点的下标
int FirseAdjVex(Graph G, int v) {
    for (int i = 0; i < G.vexnum; ++i) {
        if (1 == G.arcs[v][i] && 0 == visited[i]) {
            //存在弧,且该顶点未被访问
            return i;
        }
    }
    return -1;
}


void DFS(Stack& S, Graph G, int v) {
    printf("%c ", G.vexs[v]);
    visited[v] = 1;//标记为已访问
    while (-1 != FirseAdjVex(G, v))
        //确保每个与下标v代表的字符相关联的字符都遍历到 
        DFS(S, G, FirseAdjVex(G, v)); //递归遍历
}
int main() {
    Graph G;
    Stack S;
    char c;
    CreateUDG(G);//构造G的无向图
    Display(G);//输出图G的邻接矩阵
    printf("请输入遍历连通图的起始点: ");
    getchar();
    scanf("%c", &c);
    printf("\n深度优先搜索遍历图结果: ");
    DFS(S, G, LocateVex(G, c));
    return 0;
}

