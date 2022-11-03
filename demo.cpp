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


    Map<int,int>mp;
    mp.Insert(10,20);
    mp.Insert(20,30);
    mp.Insert(40,50);
    mp.Draw();

    cout << endl << mp[60] << endl;
    mp[20] = 650;
    cout << mp[20] << endl;
    mp.Delete(20);
    cout << mp[20] << endl;

    return 0;
}