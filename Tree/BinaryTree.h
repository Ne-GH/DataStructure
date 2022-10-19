/*********************************************************************
 * Auther : yongheng
 * Date : 2022/10/19 15:46
*********************************************************************/
#ifndef DATASTRUCTURE_BINARYTREE_H
#define DATASTRUCTURE_BINARYTREE_H

template<typename T>
class BinaryTree{
    class _Node{
        T _val;
        BinaryTree *_left;
        BinaryTree *_right;
    };
public:
    BinaryTree(){

    }
    ~BinaryTree(){

    }

};


#endif //DATASTRUCTURE_BINARYTREE_H
