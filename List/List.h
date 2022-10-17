/*
*    Time: 04/10/22 09:18:36
*    Create By yongheng
*/

#include <cstddef>
#include <iostream>
#include "./cout_error_msg.h"



template<typename T>
class LinkList{
public:

    LinkList(){
        _head = new _Node;
        // _head->data = _Node();
        _head->_next = NULL;
        _end = _head;
        // _end = _head->_next;
    }

    ~LinkList(){
        _Node* tmp;
        while(_head){
            tmp = _head;
            _head = _head->_next;
            delete tmp;
        }
    }

    void Insert(size_t pos,T data){

        // pos == 1, end = head;
        // link_lin = 0;
        if(pos <= 0 ||pos > _link_len+1){
            COUT_ERROR("pos" << pos << "is" << "error");
            return;
        }

        int cnt = 0;
        pos--;
        _Node *tmp = _head;

        _Node *q = new _Node(data);

        while(cnt++ < pos){
            tmp = tmp->_next;
        }

        q->_next = tmp->_next;
        tmp->_next = q;

        if(pos == _link_len){
            _end = tmp->_next;
        }

        _link_len ++;

    }

    void Push_back(T data){
        // Insert(this->_link_len+1, data);
       
        
        _Node *p = new _Node(data);
        _end->_next = p;
        p->_next = nullptr;
        _end = _end->_next;

        _link_len ++;


        return;
    }

    void Show(){
        _Node *p = _head->_next;

        while(p){
            std::cout << p->data << std::endl;
            p = p->_next;
        }

    }

    void Delete(size_t pos){

        if(pos <= 0 || pos > _link_len){
            COUT_ERROR("pos" << pos << "is error");
            return;
        }

        _Node *tmp = _head;
        pos--;
        size_t cnt = 0;
        while(cnt++ < pos){
            tmp = tmp->_next;
        }
        _Node *q = tmp->_next;
        tmp->_next = tmp->_next->_next;

        if(cnt == _link_len){
            _end = tmp;
        }

        delete q;
        _link_len --;

    }

    void Pop_back(size_t pos){
        Delete(_link_len);
    }

    T *Find_val_by_pos(size_t pos){

        if(pos <= 0 || pos > _link_len){
            COUT_ERROR("pos" << pos << "is error");
            return nullptr;
        }

        _Node *tmp = _head;

        size_t cnt = 0;
        while(cnt++ < pos){
            tmp = tmp->_next;
        }

        return &(tmp->data);
    }

    size_t Find_pos_by_val(T val){
        _Node *tmp = _head->_next;

        size_t cnt = 1;
        while(tmp){
            if(tmp->data == val){
                return cnt;
            }
            cnt ++;
            tmp = tmp->_next;

        }
        return 0;
    }

    void Pop_back(){
        Delete(this->_link_len);
    }
    
    T Front(){
        return *begin();
    }
    T End(){
        return *end();
    }

    T *begin(){
        if(_link_len != 0){
            return &(_head->_next->data);
        }
        return T();
    }
    T *end(){
        if(_link_len != 0){
            return &(_end->data);
        }
        return T();
    }

    size_t Size(){
        return _link_len;
    }
    
    
    
private:


    class _Node{
        public:
            _Node(){}
            _Node(T data):data(data){}
            T data;
            _Node *_next;
    };

    size_t _link_len= 0;

    _Node *_head;
    _Node *_end;


};
