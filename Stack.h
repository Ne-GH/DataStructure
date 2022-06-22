/*
*    Time: 04/10/22 12:56:43
*    Create By yongheng
*/

#include <cstddef>
#include <iostream>

// #define LIST_STACK

#if LIST_STACK
#include "./List.h"

#else 

#include "./Link_List.h"
#define List LinkList

#endif

template<typename T>
class Stack{
private:
    List<T> sta;

public:
    
    void Push(T data){
        sta.Push_back(data);
    }
    void Pop() {
        sta.Pop_back();
    }
    size_t Size(){
        return sta.Size();
    }
    T Top(){
        return sta.End();
    }


};

#undef List
#undef LIST_STACK
