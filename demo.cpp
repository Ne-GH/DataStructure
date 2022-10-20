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

    Map<int,int> mp;
    mp.Insert(10,20);
    cout << mp[10] << endl;


    return 0;
}