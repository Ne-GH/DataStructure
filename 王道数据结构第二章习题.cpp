/*******************************************************************************
 * Author : yongheng
 * Data   : 2023/09/25 16:12
*******************************************************************************/
#include <iostream>
#include <stdlib.h>

#define ElemType char

template <typename T>
struct NodeBase {
    T data;
    struct NodeBase *next;
};

using Node = NodeBase<char>;

//struct Node {
//    ElemType data;
//    struct Node *next;
//};
using PNode = Node *;

typedef struct CDNode {
    ElemType data;
    struct CDNode *pre;
    struct CDNode *next;
}*PCDNode;

// 循环单链表
typedef struct CSNode {
    ElemType data;
    struct CSNode *next;
}*PCSNode;



// 创建一个带头结点的链表
template <typename T = PNode,typename NodeType = Node>
T CreateNNode(int num) {
    T RetL = (T)malloc(sizeof(NodeType));
    RetL->next = NULL;
    T end = RetL;

    for (int i = 0;i < num; ++i) {
        T p = (T)malloc(sizeof(NodeType));
        std::cin >> p->data;
        end->next = p;
        end = p;
        p->next = NULL;
    }
    return RetL;
}

// 创建带头节点的循环双向链表
PCDNode CreateCDNodeList(int num) {
    PCDNode L = (PCDNode)malloc(sizeof(CDNode));
    L->next = L->pre = L;
    while (num --) {
        PCDNode p = (PCDNode) malloc(sizeof(CDNode));
        std::cin >> p->data;
        p->pre = L->pre;
        p->next = L;
        L->pre->next = p;
        L->pre = p;
    }
    return L;
}

// 创建带头节点的循环单链表
PCSNode CreateCSNode(int num) {
    PCSNode L = (PCSNode)malloc(sizeof(CSNode));
    PCSNode last = L;
    while (num --) {
        PCSNode p = (PCSNode)malloc(sizeof (CSNode));
        std::cin >> p->data;
        last->next = p;
        last = p;
        last->next = L;
    }
    return L;

}

/*******************************************************************************
 * 获取第num个结点,方便构造题目中所要求的链表
*******************************************************************************/
PNode GetLinkNode(PNode L, int num) {
    while (num --) {
        L = L->next;
    }
    return L;
}

template <typename T = PNode>
void PrintList(T L) {
    std::cout << "L：";
    while (L) {
        std::cout << L->data << " ";
        std::cout.flush();
        L = L->next;
    }
    std::cout << std::endl;
}

/*******************************************************************************
 * 返回链表的长度，参数为头节点
 * 返回的长度信息不包含头结点
*******************************************************************************/
int GetLength(PNode L) {
    int len = 0;
    while (L->next) {
        len ++;
        L = L->next;
    }
    return len;
}
template <typename T = PNode>
void PrintL(T L) {
    PrintList(L->next);
}
void PrintP(PNode p) {
    PrintList(p);
}

// 例题2.1
void Delete_2_1(PNode &L,ElemType x) {
    if (L == NULL)
        return ;

    if (L->data == x) {
        PNode p = L;
        L = L->next;
        free(p);
        Delete_2_1(L,x);
    }
    else {
        Delete_2_1(L->next,x);
    }

}
void Test_2_1() {
    PNode L = CreateNNode(5);
    PNode p = L->next;
    std::cout << "2.1:" << std::endl;
    Delete_2_1(p,'3');
    PrintP(p);
    putchar(10);
}

// 例题2.2
void Delete_2_2(PNode &L,ElemType x) {
    PNode pre = L,cur = L->next;

    while (cur) {
        if (cur->data == x) {
            PNode p = cur;
            pre->next = cur->next;
            cur = cur->next;
            free(p);
        }
        else {
            pre = cur;
            cur = cur->next;
        }
    }
}
void Test_2_2() {
    std::cout << "2.2:" << std::endl;
    PNode L_2_2 = CreateNNode(5);
    Delete_2_2(L_2_2,'3');
    PrintL(L_2_2);
    putchar(10);
}

// 例题2.3
void ReverseOut_2_3(PNode p) {
    if (p == NULL)
        return ;
    ReverseOut_2_3(p->next);
    std::cout << p->data << " ";
}
void ReverseOut_2_3_IgnoreHead(PNode L) {
    ReverseOut_2_3(L->next);
}
void Test_2_3() {
    std::cout << "2.3:" << std::endl;
    PNode L_2_3 = CreateNNode(5);
    ReverseOut_2_3_IgnoreHead(L_2_3);
    putchar(10);
}

// 例题2.4
void  DeleteOneMin_2_4(PNode& L) {
    PNode pre = L,cur = L->next,min = L->next,min_pre = L;
    while (cur) {
        if (cur->data < min->data) {
            min_pre = pre;
            min = cur;
        }
        else {
            pre = cur;
            cur = cur->next;
        }
    }
    std::cout << "删除的最小值是：" << min->data << std::endl;
    min_pre->next = min->next;
    free(min);
}
void Test_2_4() {
    std::cout << "2.4:" << std::endl;
    PNode L_2_4 = CreateNNode(5);
    DeleteOneMin_2_4(L_2_4);
    PrintL(L_2_4);
    putchar(10);
}

// 例题2.5
void Reverse_2_5(PNode &L) {
    // 没有元素或者只有一个元素
    if (L->next == NULL || L->next->next == NULL) {
        return;
    }
    PNode pre = L->next,cur = pre->next,next = cur->next;
    pre->next = NULL;
    while (next) {
        cur->next = pre;
        pre = cur;
        cur = next;
        next = next->next;
    }
    cur->next = pre;
    L->next = cur;
}
void Test_2_5() {
    std::cout << "2.5:" << std::endl;
    PNode L_2_5 = CreateNNode(5);
    Reverse_2_5(L_2_5);
    PrintL(L_2_5);
    putchar(10);
}

// 例题2.6
void SortUp_2_6(PNode &L) {
    if (L->next == NULL)
        return;

    PNode pre = L->next,cur = pre->next;
    PNode insert_pre,insert;
    while (cur) {
        if (cur->data < pre->data) {
            PNode p = cur;
            pre->next = cur->next;
            cur = cur->next;

            insert_pre = L;
            insert = L->next;
            while (insert_pre != pre) {
                if (p->data > insert->data) {
                    insert_pre = insert;
                    insert = insert->next;
                }
                else {
                    insert_pre->next = p;
                    p->next = insert;
                    break;
                }
            }
        }
        else {
            pre = cur;
            cur = cur->next;
        }
    }
}
void Test_2_6() {
    std::cout << "2.6:" << std::endl;
    PNode L_2_6 = CreateNNode(5);
    SortUp_2_6(L_2_6);
    PrintL(L_2_6);
    putchar(10);
}

// 例题2.7
void DeleteBetween_2_7(PNode &L,ElemType e1,ElemType e2) {
    if (e1 > e2) {
        ElemType tmp = e1;
        e1 = e2;
        e2 = tmp;
    }

    PNode pre = L,cur = L->next;
    while (cur) {
        if (cur->data > e1 && cur->data < e2) {
            PNode p = cur;
            cur = cur->next;
            pre->next = cur;
            free(p);
        }
        else {
            pre = cur;
            cur = cur->next;
        }
    }
}
void Test_2_7() {
    std::cout << "2.7:" << std::endl;
    PNode L_2_7 = CreateNNode(5);
    DeleteBetween_2_7(L_2_7,'1','5');
    PrintL(L_2_7);
    putchar(10);
}

// 例题2.8
PNode GetPublicNode_2_8(PNode &La,PNode &Lb) {
    int len_a = GetLength(La);
    int len_b = GetLength(Lb);
    int diff_len = 0;
    PNode long_link,short_link;
    if (len_a > len_b) {
        long_link  = La->next;
        short_link = Lb->next;
        diff_len = len_a - len_b;
    }
    else {
        long_link = Lb->next;
        short_link = La->next;
        diff_len = len_b - len_a;
    }

    while (diff_len --) {
        long_link = long_link->next;
    }

    while (long_link) {
        if (long_link != short_link) {
            long_link = long_link->next;
            short_link = short_link->next;
        }
        else {
            return long_link;
        }
    }

    return NULL;
}
void Test_2_8() {
    std::cout << "2.8:" << std::endl;
    PNode L_2_8_1 = CreateNNode(8);
    PNode L_2_8_2 = CreateNNode(7);
    PNode p = GetLinkNode(L_2_8_1,3);
    PNode last = GetLinkNode(L_2_8_2,7);
    last->next = p;
    p = GetPublicNode_2_8(L_2_8_1,L_2_8_2);
    std::cout << "公共结点的值为：" << p->data << std::endl;
    putchar(10);
}

// 例题2.9
void PrintSortUp_2_9(PNode L) {
    while (L->next) {
        PNode min_pre = L,min = L->next;
        PNode pre = L,cur = L->next;
        while (cur) {
            if (cur->data < min->data) {
                min = cur;
                min_pre = pre;
            }
            pre = cur;
            cur = cur->next;
        }
        PNode p = min;
        min_pre->next = min->next;
        std::cout << p->data << " ";
        free(p);
    }
    std::cout << std::endl;
    return;
}
void Test_2_9() {
    std::cout << "2.9:" << std::endl;
    PNode L_2_9 = CreateNNode(5);
    PrintSortUp_2_9(L_2_9);
    putchar(10);
}

// 例题2.10
void Split_2_10(PNode &L,PNode &La,PNode &Lb) {
    int num = 0;
    PNode pa = La,pb = Lb,cur = L->next;

    while (cur) {
        if (num % 2) {
            pb->next = cur;
            pb = cur;
            cur = cur->next;
            pb->next = NULL;

        }
        else {
            pa->next = cur;
            pa = cur;
            cur = cur->next;
            pa->next = NULL;
        }
        num ++;
    }
    L->next = NULL;
    free(L);
    return;
}
void Test_2_10() {
    std::cout << "2.10:" << std::endl;
    PNode L_2_10 = CreateNNode(10);
    PNode L_2_10_a = CreateNNode(0);
    PNode L_2_10_b = CreateNNode(0);
    Split_2_10(L_2_10,L_2_10_a,L_2_10_b);
    PrintL(L_2_10_a);
    PrintL(L_2_10_b);
    putchar(10);
}

// 例题2.11
void Split_2_11(PNode L,PNode &La,PNode &Lb) {

    PNode pa = La,pb = Lb;
    PNode cur = L->next;
    int num = 0;
    while (cur) {
        if (num % 2) {
            pa->next = cur;
            pa = cur;
            cur = cur->next;
        }
        else {
            pb = Lb->next;
            Lb->next = cur;
            cur = cur->next;
            Lb->next->next = pb;
        }
        num++;
    }
}
void Test_2_11() {
    std::cout << "2.11:" << std::endl;
    PNode L_2_11 = CreateNNode(10);
    PNode L_2_11_1 = CreateNNode(0);
    PNode L_2_11_2 = CreateNNode(0);
    Split_2_11(L_2_11,L_2_11_1,L_2_11_2);
    PrintL(L_2_11_1);
    PrintL(L_2_11_2);
    putchar(10);
}

// 例2.12
void RemoveDuplicates_2_12(PNode &L) {
    PNode pre = L,cur = L->next;

    while (cur) {
        if (cur->data == pre->data) {
            PNode p = cur;
            cur = cur->next;
            pre->next = cur;
            free(p);
        }
        else {
            pre = cur;
            cur = cur->next;
        }
    }
}
void Test_2_12() {
    std::cout << "2.12:" << std::endl;
    PNode L_2_12 = CreateNNode(10);
    RemoveDuplicates_2_12(L_2_12);
    PrintL(L_2_12);
    putchar(10);
}

// 例2.13
PNode MergeSortDown_2_13(PNode &La,PNode &Lb) {
    PNode Lc = (PNode)malloc(sizeof(Node));
    PNode pa = La->next,pb = Lb->next;
    PNode p;
    while (pa && pb) {
        if (pa->data < pb->data) {
            p = pa;
            pa = pa->next;
            p->next = Lc->next;
            Lc->next = p;
        }
        else {
            p = pb;
            pb = pb->next;
            p->next = Lc->next;
            Lc->next = p;
        }
    }
    PNode over;
    if (pa) {
        over = pa;
    }
    else {
        over = pb;
    }
    while (over) {
        p = over;
        over = over->next;
        p->next = Lc->next;
        Lc->next = p;
    }
    return Lc;
}
void Test_2_13() {
    std::cout << "2.13" << std::endl;
    PNode La = CreateNNode(5);
    PNode Lb = CreateNNode(5);
    PNode Lc = MergeSortDown_2_13(La,Lb);
    PrintL(Lc);
    putchar(10);
}

// 例2.14
PNode GetPublicNodeList_2_14(PNode &La,PNode &Lb) {
    PNode Lc = (PNode)malloc(sizeof(Node));
    Lc->next = NULL;
    PNode pa = La->next,pb = Lb->next,pc = Lc;
    while (pa && pb) {
        if (pa->data < pb->data) {
            pa = pa->next;
        }
        else if (pa->data == pb->data) {
            PNode p = (PNode)malloc(sizeof(Node));
            p->data = pa->data;
            p->next = NULL;
            pc->next = p;
            pc = p;

            pa = pa->next;
            pb = pb->next;
        }
        else {
            pb = pb->next;
        }
    }
    return Lc;
}
void Test_2_14() {
    std::cout << "2.14" << std::endl;
    PNode La = CreateNNode(5);
    PNode Lb = CreateNNode(3);
    PNode pc = GetPublicNodeList_2_14(La,Lb);
    PrintL(pc);
    putchar(10);
}

// 例2.15
void Intersect_2_15(PNode &La,PNode &Lb) {
    PNode pa = La->next,pb = Lb->next;
    PNode pre = La;

    while (pa && pb) {
        if (pa->data < pb->data) {
            PNode p = pa;
            pa = pa->next;
            pre->next = pa;
            free(p);
        }
        else if (pa->data > pb->data) {
            pb = pb->next;
        }
        else {
            pre = pa;
            pa = pa->next;
            pb = pb->next;
        }
    }

}
void Test_2_15() {
    std::cout << "2.15" << std::endl;
    PNode La = CreateNNode(5);
    PNode Lb = CreateNNode(5);
    Intersect_2_15(La,Lb);
    PrintL(La);
    putchar(10);
}

// 例2.16
bool CheckSubset_2_16(PNode &La,PNode &Lb) {
    PNode pa = La->next,pb = Lb->next;

    PNode cur_beg = pa;
    while (cur_beg) { // 此次匹配的起点
        if (cur_beg->data == pb->data) {
            PNode a = cur_beg;
            PNode b = pb;
            while (a && b) {
                if (a->data == b->data) {
                    a = a->next;
                    b = b->next;
                }
                else {
                    break;
                }
            }
            // b没有匹配完毕，匹配失败
            if (b) {
                cur_beg = cur_beg->next;
            }
            else {
                return true;
            }
        }
        else {
            cur_beg = cur_beg->next;
        }
    }
    return false;

}
void Test_2_16() {
    std::cout << "2.16" << std::endl;
    PNode La = CreateNNode(5);
    PNode Lb = CreateNNode(3);
    std::cout << CheckSubset_2_16(La,Lb) << std::endl;
    putchar(10);

}

// 例2.17
bool CheckCDListSymmetry_2_17(PCDNode &L) {
    PCDNode front = L->next,last = L->pre;
    while (front != last && front->next != last) {
        if (front->data == last->data) {
            front = front->next;
            last = last->pre;
        }
        else {
            return false;
        }
    }
    if (front->data == last->data) {
        return true;
    }
    return false;
}
void Test_2_17() {
    std::cout << "2.17" << std::endl;
    PCDNode L = CreateCDNodeList(5);
    std::cout << CheckCDListSymmetry_2_17(L);
    putchar(10);
    putchar(10);
}

// 例2.18
PCSNode SpliceCSNode_2_18(PCSNode &pa,PCSNode &pb) {
    PCSNode last_pa = pa;
    while (last_pa->next != pa) {
        last_pa = last_pa->next;
    }

    PCSNode last_pb = pb;
    while (last_pb->next != pb) {
        last_pb = last_pb->next;
    }
    last_pa->next = pb;
    last_pb->next = pa;


    return pa;
}
void Test_2_18() {
    std::cout << "2.18" << std::endl;
    PCSNode pa = CreateCSNode(5);
    pa->data = 'x';
    PCSNode pb = CreateCSNode(5);
    pb->data = 'x';

    auto new_pa = SpliceCSNode_2_18(pa,pb);
    for (int i = 0;i < 20; ++i) {
        std::cout << new_pa->data << " ";
        new_pa = new_pa->next;
    }
    putchar(10);
    putchar(10);
}

// 例2.19
void RemoveMinCSNode_2_19(PCSNode &L) {
    while (L->next != L) {
        PCSNode min = L->next,min_pre = L;
        PCSNode cur = L->next,pre = L;

        while (cur != L) {
            if (cur->data < min->data) {
                min = cur;
                min_pre = pre;
            }
            pre = cur;
            cur = cur->next;
        }
        min_pre->next = min->next;
        std::cout << min->data << " ";
        free(min);
    }
}
void Test_2_19() {
    std::cout << "2.19" << std::endl;
    auto L = CreateCSNode(5);
    RemoveMinCSNode_2_19(L);
    putchar(10);
    putchar(10);
}


// 第20题的非循环双链表
struct Node2_20 {
    int data = 0;
    int freq = 0;
    Node2_20 *pre;
    Node2_20 *next;
};
Node2_20 *CreateNode2_20List(int num) {
    Node2_20 *L = (Node2_20 *)malloc(sizeof(Node2_20));
    L->next = L->pre = NULL;
    while (num --) {
        auto p = (Node2_20 *)malloc(sizeof(Node2_20));
        std::cin >> p->data;
        p->freq = 0;
        p->next = L->next;
        p->pre = L;
        if (L->next) {
            L->next->pre = p;
        }
        L->next = p;
    }
    return L;
}
// 例2.20本体
Node2_20 *Locate_2_20(Node2_20 *&L,int x) {
    auto pre = L,cur = L->next;
    while (cur) {
        // 如果数据是要查找的数据，那么就从链表中取下这个结点
        if (cur->data == x) {
            // 如果频度小于pre的freq,则不需要取出结点并重排
            if (++(cur->freq) <= pre->freq) {
                return cur;
            }
            // 否则，取出结点
            pre->next = cur->next;
            if (cur->next) {
                cur->next->pre = pre;
            }
            break;
        }
        else {
            pre = cur;
            cur = cur->next;
        }

    }
    if (cur == NULL) {
        return NULL;
    }
    // 重新插入到合适的位置
    Node2_20 *select = cur;
    pre = L,cur = L->next;
    while (cur) {
        if (select->freq < cur->freq) {
            pre = cur;
            cur = cur->next;
        }
        else {
            pre->next = select;
            select->next = cur;
            cur->pre = select;
            select->pre = pre;
            return select;
        }
    }

    return NULL;

}
void PrintNode2_20(Node2_20 *L) {
    while (L->next) {
        std::cout << L->next->data << " ";
        L = L->next;
    }
    std::cout << std::endl;

}
void Test_2_20() {
    std::cout << "2.20" << std::endl;
    // 先构造一个非循环双链表
    auto L = CreateNode2_20List(5);
    L->freq = 0;
    Locate_2_20(L,1);
    PrintNode2_20(L);
    Locate_2_20(L,3);
    PrintNode2_20(L);
    Locate_2_20(L,6);
    PrintNode2_20(L);
    putchar(10);
}

// 例2.21
bool CheckRing_2_21(PNode p) {
    if (p == NULL || p->next == NULL) {
        return false;
    }
    PNode quick_node = p->next->next,slow_node = p->next;
    while (quick_node && quick_node->next) {
        if (quick_node == slow_node)
            return true;
        quick_node = quick_node->next->next;
        slow_node = slow_node->next;
    }
    return false;
}
void Test_2_21() {
    std::cout << "2.21" << std::endl;
    PNode L = CreateNNode(10);
    auto p = GetLinkNode(L,4);
    auto end = GetLinkNode(L,10);
    end->next = p;
    std::cout << CheckRing_2_21(L->next) << std::endl;
    putchar(10);
}

// 例2.22
bool Select_2_22(PNode p,int k) {
    PNode front = p,last = p;
    while (k --) {
        if (last == NULL)
            return false;
        last = last->next;
    }
    while (last) {
        front = front->next;
        last = last->next;
    }
    std::cout << front->data << std::endl;
    return true;
}
void Test_2_22() {
    std::cout << "2.22" << std::endl;
    auto L = CreateNNode(5);
    auto ret = Select_2_22(L->next,2);
    std::cout << "ret:" << ret << std::endl;
    putchar(10);
}

// 例2.23,
void Test_2_23 (){
    std::cout << "2.23:" << std::endl;
    PNode L_2_8_1 = CreateNNode(8);
    PNode L_2_8_2 = CreateNNode(7);
    PNode p = GetLinkNode(L_2_8_1,3);
    PNode last = GetLinkNode(L_2_8_2,7);
    last->next = p;
    p = GetPublicNode_2_8(L_2_8_1,L_2_8_2);
    std::cout << "公共结点的值为：" << p->data << std::endl;
    putchar(10);
}

// 例2.24
using INode = NodeBase<int>;
void DeleteOne_2_24(INode *&L,int n) {
    bool *arr = new bool[n+1];
    std::fill(arr,arr+n,false);

    INode *pre = L,*cur = L->next;
    while (cur) {
        if (arr[std::abs(cur->data)] == false) {
            arr[std::abs(cur->data)] = true;
            pre = cur;
            cur = cur->next;
        }
        else {
            auto p = cur;
            cur = cur->next;
            pre->next = cur;
            free(p);
        }
    }
    delete[] arr;
}
void Test_2_24() {
    std::cout << "2.24" << std::endl;
    INode *L = CreateNNode<INode *,INode>(9);
    DeleteOne_2_24(L,10);
    PrintL<INode *>(L);
    putchar(10);
}

void end_2_25(PNode &L) {
    // 没有元素或者只有一个元素
    if (L->next == NULL || L->next->next == NULL)
        return;
    PNode quick_node = L->next->next,slow_node = L->next;
    while (quick_node && quick_node->next) {
        quick_node = quick_node->next->next;
        slow_node = slow_node->next;
    }

    PNode pre = slow_node->next,cur = pre->next,next = cur->next;
    slow_node->next = NULL;
    pre->next = NULL;
    while (next) {
        cur->next = pre;
        pre = cur;
        cur = next;
        next = next->next;
    }
    cur->next = pre;
    slow_node->next = NULL;
    // 此时next 中是 an,an-1,an-2
    PNode end = cur;
    pre = L->next,cur = L->next->next;
    PNode p;
    while (end) {
        pre->next = end;
        p = end;
        end = end->next;
        p->next = cur;
    // pre  9  cur
        pre = cur;
        if (cur != NULL)
            cur = cur->next;
    }
}
void Test_2_25() {
    PNode L = CreateNNode(10);
    end_2_25(L);
    PrintL(L);

}

int main() {
    freopen("input.txt","r",stdin);
    Test_2_1();
    Test_2_2();
    Test_2_3();
    Test_2_4();
    Test_2_5();
    Test_2_6();
    Test_2_7();
    Test_2_8();
    Test_2_9();
    Test_2_10();
    Test_2_11();
    Test_2_12();
    Test_2_13();
    Test_2_14();
    Test_2_15();
    Test_2_16();
    Test_2_17();
    Test_2_18();
    Test_2_19();
    Test_2_20();
    Test_2_21();
    Test_2_22();
    Test_2_23();
    Test_2_24();
    Test_2_25();



    return 0;
}


