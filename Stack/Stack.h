/*
*    Time: 04/10/22 12:56:43
*    Create By yongheng
*/

#ifndef _STACK_H_
#define _STACK_H_

#include <iostream>


#include "../Tools/out_error_msg.h"
#include "../Arrary/Arrary.h"

template<typename T>
class Stack{
private:
    Arrary<T> _stack;

public:
    
    void Push_back(T data){
        _stack.Push_back(data);
    }
    T Pop_back() {
        return _stack.Pop_back();
    }
    size_t Size(){
        return _stack.Size();
    }
    T Top(){
        return _stack.End();
    }


};

#endif
