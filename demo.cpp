/*********************************************************************
 * Auther : yongheng
 * Date : 2022/10/18 01:28
*********************************************************************/

#include "Arrary/Arrary.h"
#include "List/List.h"
#include "Stack/Stack.h"
#include "Queue/Queue.h"
#include "Tree/BinaryTree.h"
#include <iostream>

using std::cin,std::cout,std::endl;


int main(int argc,char *argv[]){

    BinaryTree<int> bt;
    bt.Insert(10);
    bt.Insert(15);
    bt.Insert(6);
    bt.Insert(12);
    bt.Insert(19);

    bt.Draw();

    cout << endl << endl;
    auto p = bt.Search(12);

    cout << *p << endl;

    cout << bt.GetDeep() << endl;

    bt.Destroy();


    return 0;
}