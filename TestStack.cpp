/*
*    Time: 04/10/22 21:58:11
*    Create By yongheng
*/

#include <iostream>
#include "./Stack.h"

using namespace std;

int main(int argc,char *argv[]){

    Stack<int> sta;

    LinkList<int> ll;

    for(int i = 0;i < 10; ++i){
        sta.Push(i);
    }


    while(sta.Size() != 0){
        cout << sta.Top() << " ";
        sta.Pop();
    }



    return 0;
}
