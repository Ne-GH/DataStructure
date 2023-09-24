#include <iostream>

template <typename T,typename ...Args>
void Mes(T mes,const Args& ... args) {
    std::cout << mes;
    auto out = [](const auto &arg) {
        std::cout << ' ' << arg;
    };
    (...,out(args));
    std::cout << std::endl;
}


#define ElemType int
#define Status int
#define OK 1
#define ERROR -2


typedef struct LNode {
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;


/*******************************************************************************
 * 创建带头节点的链表,L是头节点 ,n是长度
 * 采用头插法，因此插入的数据与原来相比是逆序
*******************************************************************************/
void CreateList(LinkList &L,int n) {
    L = (LinkList)malloc(sizeof(ElemType));
    L->next = NULL;
    // 头插法
    for (int i = 0;i < n; ++i) {
        LinkList p = (LinkList)malloc(sizeof(LNode));
        scanf("%d",&p->data);
        p->next = L->next;
        L->next = p;
    }
}

/*******************************************************************************
 * 查找第i个元素，结果存放进e
*******************************************************************************/
Status GetElem(LinkList L,int i,ElemType &e) {
    LinkList p = L->next;
    int j = 1;
    while(p && j < i) {
        p = p->next;
        j ++;
    }
    if (p == NULL || j > i) 
        return ERROR;

    e = p->data;
    return OK;
}

/*******************************************************************************
 * 插入一个元素e，使之成为第i个元素
*******************************************************************************/
Status ListInsert(LinkList &L,int i,ElemType e) {
    LinkList p = L;
    int j = 0;

    while (p && j < i - 1) {
        p = p->next;
        ++j;
    }

    if (p == NULL || j > i - 1) {
        return ERROR;
    }
    LinkList s = (LinkList)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}

/*******************************************************************************
 * 在带头节点的单链线性表L中，删除第i个元素，并由e返回
*******************************************************************************/
Status ListDelete(LinkList &L,int i,ElemType& e) {
    int j = 0;
    LinkList p = L;
    while (p && j < i - 1) {
        p = p->next;
        j++;
    }
    if (p->next == NULL || j > i - 1)
        return ERROR;

    LinkList q = p->next;
    p->next = q->next;
    e = q->data;
    free(q);
    return OK;
}

void MergeList(LinkList &La,LinkList &Lb,LinkList &Lc) {
    LinkList pa = La->next;
    LinkList pb = Lb->next;
    LinkList pc;
    Lc = pc = La;
    while (pa && pb) {
        if (pa->data <= pb->data) {
            pc->next = pa;
            pc = pa;
            pa = pa->next;
        }
        else {
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        }
    }
    pc->next = pa ? pa : pb;
    free(Lb);
}

int main() {

    LinkList list;
    CreateList(list,5);

    // auto p = list->next;
    // for (int i = 0;i < 5; ++i) {
    //     Mes(p->data);
    //     p = p->next;
    // }

    int e;
    GetElem(list,2,e);
    Mes(e);

    Mes("");
    ListInsert(list,1,8);
    auto p = list->next;
    for (int i = 0;i < 6; ++i) {
        Mes(p->data);
        p = p->next;
    }
    ListDelete(list,1,e);
    
    Mes("");
    p = list->next;
    for (int i = 0;i < 5; ++i) {
        Mes(p->data);
        p = p->next;
    }

    LinkList list_2;
    CreateList(list_2,3);
    LinkList list_3;
    CreateList(list_3,0);
    MergeList(list,list_2,list_3);
    Mes("");
    p = list->next;
    while (p) {
        Mes(p->data);
        p = p->next;
    }


    return 0;
}