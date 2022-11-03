/*********************************************************************
 * Auther : yongheng
 * Date : 2022/10/18 01:28
*********************************************************************/

#include "Arrary/Arrary.h"
#include "List/List.h"
#include "Stack/Stack.h"
#include "Queue/Queue.h"
#include "Tree/BinaryTree.h"
#include "Map/Map.h"
#include <iostream>

using std::cin,std::cout,std::endl;


int main(int argc,char *argv[]){

    BinaryTree<int> bt;

    bt.Insert(10);
    bt.Insert(11);
    bt.Insert(12);
    bt.Insert(13);
    bt.Insert(14);
    bt.Draw();


    return 0;
}