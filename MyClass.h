/*
*    Time: 04/10/22 08:35:33
*    Create By yongheng
*/

#include <iostream>

class MyClass{
public:

public:
    int val;
    int key;
    MyClass(): val(0),key(0) {}
    MyClass(int key,int val) : val(val),key(key) {}
    friend std::ostream& operator << (std::ostream &out,MyClass val);

    bool operator== (MyClass right){
        return this->key == right.key && this->val == right.val;
    }
    bool operator!= (MyClass right){
        return !(*this==right);
    }
    bool operator< (MyClass right){
        if(this->key < right.key)
            return true;
        else if(this->key == right.key){
            return this->val < right.val;
        }
        return false;
    }
};

std::ostream& operator << (std::ostream &out,MyClass val){
    out << val.key << ": " << val.val << std::endl;
    return out;
}
