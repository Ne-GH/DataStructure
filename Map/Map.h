/*********************************************************************
 * Auther : yongheng
 * Date : 2022/10/18 13:59
*********************************************************************/
#ifndef DATASTRUCTURE_MAP_H
#define DATASTRUCTURE_MAP_H

#include "../Tree/BinaryTree.h"

template<typename K,typename V>
class Map{
private:
    class _Pair{
    private:
        K _key;
        V _val;
    };

    BinaryTree<_Pair> _map;


public:

    Map(){

    }
    ~Map(){

    }

};
#endif //DATASTRUCTURE_MAP_H
