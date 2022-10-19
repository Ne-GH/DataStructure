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

    BinaryTree<int> bt(10);
    bt.Insert(5);
    bt.Insert(11);
    bt.Insert(10);
    bt.Insert(1);
    bt.Insert(9);

    bt.PreOrderTraversal();
    cout << endl;
    bt.LnOrderTraversal();
    cout << endl;
    bt.PostOrderTraversal();
    cout << endl;
    bt.Output();
    bt.Destroy();




    return 0;
}