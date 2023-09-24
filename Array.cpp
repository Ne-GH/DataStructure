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

#define LIST_INIT_SIZE 100
#define LIST_INCREMENT 10
#define ElemType int

#define OVERFLOW 0
#define OK 1
#define ERROR 2

struct SqList {
    ElemType *elem;
    int length;     // 当前长度
    int listsize;   // 当前分配容量
};


/*******************************************************************************
 *
*******************************************************************************/


/*******************************************************************************
 * 初始化SqList
 * 内存分配长度为 LIST_INIT_SIZE,存放0个数据
 * 返回 OK
*******************************************************************************/
int InitList(SqList &L) {
    L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if (L.elem == NULL) {
        exit(OVERFLOW);   // 内存分配失败
    }
    L.length = 0;
    L.listsize = LIST_INIT_SIZE;
    return OK;
}



/*******************************************************************************
 * 使插入的元素成为第i个元素
*******************************************************************************/
int ListInsert(SqList &L,int i,ElemType e) {
    if (i < 1 || i > L.length + 1) {
        return ERROR;
    }

    if (L.length >= L.listsize) {
        L.elem = (ElemType *)realloc(L.elem, (L.listsize + LIST_INCREMENT) * sizeof(ElemType));
        if (L.elem == NULL) {
            exit(OVERFLOW);
        }
        L.listsize += LIST_INCREMENT;
    }

    auto q = &(L.elem[i-1]);
    for (auto p = &(L.elem[L.length-1]);p >= q; --p) {
        *(p+1) = *p;
    }
    *q = e;
    ++L.length;
    return OK;
}


/*******************************************************************************
 * 删除L中删除第i个元素
 * 返回值返回到e中
*******************************************************************************/
int ListDelete(SqList &L,int i,ElemType &e) {
    if (i < 1 || i > L.length) {
        return ERROR;
    }
    // p是第i个元素
    auto p = &(L.elem[i-1]);
    e = *p;
    // 
    auto q = L.elem + L.length - 1;

    for (++p; p <= q; ++p) {
        *(p-1) = *p;
    }
    -- L.length;
    return OK;
}


/*******************************************************************************
 * 在线性表L中查找第一个与e满足compare(L的元素,e)的元素的位序
 * 找不到时返回0
*******************************************************************************/
int LocateElem(SqList L,ElemType e,int (*compare)(ElemType,ElemType)) {

    int i = 1;
    auto p = L.elem;
    while (i <= L.length && !(*compare)(*p++,e)) 
        ++ i;
    
    if (i <= L.length)
        return i;
    return 0;
}

void MergeList(SqList La,SqList Lb,SqList &Lc) {

    auto pa = La.elem;
    auto pb = Lb.elem;
    Lc.listsize = Lc.length = La.length + Lb.length;
    auto pc = (ElemType *)malloc(Lc.listsize * sizeof(ElemType));
    if (Lc.elem == NULL) {
        exit(OVERFLOW);
    }
    Lc.elem = pc;
    auto pa_last = La.elem + La.length - 1;
    auto pb_last = Lb.elem + Lb.length - 1;
    while (pa <= pa_last && pb <= pb_last) {
        if (*pa <= *pb) {
            *pc ++ = *pa ++;
        }
        else {
            *pc ++ = *pb ++;
        }
    }
    while (pa <= pa_last) {
        *pc ++ = *pa ++;
    }
    while (pb <= pb_last) {
        *pc ++ = *pb ++;
    }
}


int main() {

    SqList sqlist;
    InitList(sqlist);
    ListInsert(sqlist,1,1);
    ListInsert(sqlist,1,2);
    int e;
    ListDelete(sqlist,1,e);
    Mes("e:",e);

    ListInsert(sqlist,1,2);
    Mes(sqlist.length,sqlist.listsize);
    Mes(sqlist.elem[0]);
    Mes(sqlist.elem[1]);

    Mes(LocateElem(sqlist,1,[](ElemType p,ElemType e) -> int { 
        if (p == e)
            return 1;
        return 0;
    }));

    SqList lb;
    InitList(lb);
    ListInsert(lb,1,5);
    ListInsert(lb,1,6);
    ListInsert(lb,1,7);

    SqList lc;
    MergeList(sqlist,lb,lc);
    Mes(lc.length);
    for(int i = 0;i < lc.length; ++i) {
        Mes(lc.elem[i]);
    }
}