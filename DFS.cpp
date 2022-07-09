#include<stdio.h>
#include<stdlib.h>

#define OK 1
#define TRUE 1
#define FALSE 0
#define MVNum 100 	//��󶥵���
typedef int Status;
typedef char VerTexType;

typedef struct ArcNode { //�߽�㣨���ɱ�������
	int adjvex; 				//�ñ���ָ��Ķ����λ��
	struct ArcNode* nextarc; //ָ����һ���ߵ�ָ��
}ArcNode;
typedef struct VNode { 	//��ͷ���
	VerTexType data; 		//������Ϣ
	ArcNode* firstarc; 		//ָ���һ�������ö���ıߵ�ָ��
}VNode, AdjList[MVNum]; //��ͷ��������
typedef struct { 			//�ڽӱ�����
	AdjList vertices;
	int vexnum, arcnum; 	//ͼ�ĵ�ǰ�������ͱ���
}ALGraph;
int visited[MVNum]; 		//������ʱ�־����

int LocateVex(ALGraph G, VerTexType u)
{
	int i;
	for (i = 0; i < G.vexnum; ++i)
		if (u == G.vertices[i].data)
			return i;
	return -1;
}

Status CreateUDG(ALGraph& G)
{ 						//�����ڽӱ��洢��ʽ����������ͼ G 
	int i, j, k;
	VerTexType v1, v2;
	ArcNode* p1, * p2;
	printf("�����ܶ��������ܱ�����");
	scanf("%d%d", &G.vexnum, &G.arcnum); //�����ܶ��������ܱ���
	printf("����ÿ�����㣺");
	for (i = 0; i < G.vexnum; ++i) { //��������㣬�����ͷ����������ͷ������
		getchar();
		scanf("%c", &G.vertices[i].data); 	//���붥��ֵ
		G.vertices[i].firstarc = NULL;		//��ʼ����ͷ����ָ����Ϊ NULL
	}//for
	printf("����ÿ���������Ķ��㣺\n");
	getchar();
	for (k = 0; k < G.arcnum; ++k) { 		//������ߣ������ڽӱ�

		scanf("%c%*c%c%*c", &v1, &v2);
		i = LocateVex(G, v1); 		//ȷ�� v1 ��ͼ G ��ͷ�����е�λ�� i
		j = LocateVex(G, v2); 		//ȷ�� v2 ��ͼ G ��ͷ�����е�λ�� j
		p1 = (ArcNode*)malloc(sizeof(ArcNode)); //����һ���µı߽��*p1
		p1->adjvex = j; 			//��¼�ڽӵ� vj �ڱ�ͷ�����е�λ�� j
		p1->nextarc = G.vertices[i].firstarc; G.vertices[i].firstarc = p1;
		//���µı߽��*p1 ���뵽���� vi �ı������ײ�
		p2 = (ArcNode*)malloc(sizeof(ArcNode));
		//������һ���ԳƵ��µı߽��*p2
		p2->adjvex = i; //��¼�ڽӵ� vi �ڱ�ͷ�����е�λ�� i
		p2->nextarc = G.vertices[j].firstarc; G.vertices[j].firstarc = p2;
		//���µı߽��*p2 ���뵽���� vj �ı������ײ�
	}//for
	return OK;
}
void Display(ALGraph G)
{
	int i;
	ArcNode* p;
	printf("*****�ڽӱ���ʾ������������ͼ*****\n");
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
	//�� v �������������ȱ���ͼ G���ݹ飩
	int w;
	ArcNode* p;
	printf("%c ", G.vertices[v].data);//���� v ���㣬
	visited[v] = TRUE; 			//���÷��ʱ�־�������Ӧ����ֵΪ 1
	p = G.vertices[v].firstarc; 	//p ָ�� v ����ı������ĵ�һ���߽��
	while (p != NULL) { 			//���߽��ǿ�
		w = p->adjvex;			//��ʾ w �� v ���ڽӵ�
		if (!visited[w]) DFS(G, w);	//�� w δ���ʣ���ݹ���� DFS
		p = p->nextarc; 		//p ָ����һ���߽��
	}
}
int main()
{
	ALGraph G;
	VerTexType c;
	CreateUDG(G);
	Display(G);
	printf("�����������ͨͼ����ʼ�㣺");
	scanf("%c", &c);
	printf("\n���������������ͼ�����");
	for (int i = 0; i < G.vexnum; i++)
		visited[i] = FALSE; //�÷��ʱ�־����ĳ�ֵΪ 0
	DFS(G, LocateVex(G, c));
	return 0;
}