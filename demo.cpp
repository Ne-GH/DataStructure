/*********************************************************************
 * Auther : yongheng
 * Date : 2022/10/18 01:28
*********************************************************************/

#include "Arrary/Arrary.h"
#include "List/List.h"
#include "Stack/Stack.h"
#include "Queue/Queue.h"

#include <iostream>

using std::cin,std::cout,std::endl;

int main(int argc,char *argv[]){
    Queue<int>que;
    for(int i = 0; i < 10; ++i){
        que.Push_back(i);
    }

    while(que.Size()){
        cout << que.Front() << endl;
        que.Pop_front();
    }



    return 0;
}