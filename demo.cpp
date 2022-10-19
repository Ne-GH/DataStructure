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
    bt.Insert(1);
    bt.Insert(11);
    bt.Insert(12);
    bt.Insert(13);
    bt.Insert(1);
    bt.Insert(7);
    bt.Insert(9);
    bt.Insert(12);

    bt.PreOrderTraversal();
    cout << endl;
    bt.LnOrderTraversal();
    cout << endl;
    bt.PostOrderTraversal();
    cout << endl;
    bt.Draw();
    cout << endl;
    cout << endl;
    bt.Delete(12);
    bt.Draw();





    bt.Destroy();




    return 0;
}