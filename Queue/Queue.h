/*********************************************************************
 * Auther : yongheng
 * Date : 2022/10/18 12:45
*********************************************************************/
#ifndef DATASTRUCTURE_QUEUE_H
#define DATASTRUCTURE_QUEUE_H

#include "../List/List.h"


template<typename T>
class Queue {
private:
    List<T> _queue;
public:
    Queue(){
        _queue = List<T>();
    }
    ~Queue(){

    }

    void Push_back(T val){
        _queue.Push_back(val);
        return;
    }

    T Pop_front(){
        T ret = _queue.Front();
        _queue.Delete(0);
        return ret;
    }

    T Front(){
        return _queue.Front();
    }

    size_t Size(){
        return _queue.Size();
    }

};


#endif //DATASTRUCTURE_QUEUE_H
