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

#define MAXSIZE 1000

typedef struct {
    ElemType data;
    int cur;
}component,SLinkList[MAXSIZE];

/*******************************************************************************
 * 将一维数组space中各个分量链成一个备用链表
 * space[0].cur是头指针，0是空指针
*******************************************************************************/
void InitSpace(SLinkList &space) {
    for (int i = 0;i < MAXSIZE; ++i) {
        space[i].cur = i + 1;
    }
    space[MAXSIZE-1].cur = 0;
}

/*******************************************************************************
 * 在静态链表中查找第一个e,并返回位置
 * 没有找到时返回0
*******************************************************************************/
int LocateElem(SLinkList &space,ElemType e) {
    int i = 0;
    while (i && space[i].data != e) {
        i = space[i].cur;
    }
    return i;
}

/*******************************************************************************
 * 如果备用链表非空，则从备用链表中分配一个，并返回下标
 * 否则返回0
*******************************************************************************/
int Malloc(SLinkList &space) {
    int i = space[0].cur;
    if (space[0].cur) {
        space[0].cur = space[i].cur;
    }
    return i;
}


/*******************************************************************************
 * 将下标为k的元素回收到备用链表
*******************************************************************************/
void Free(SLinkList &space,int k) {
    space[k].cur = space[0].cur;
    space[0].cur = k;
}

int main() {

    SLinkList L;
    InitSpace(L);
    Mes(LocateElem(L,1));



    return 0;
}
