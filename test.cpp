/*
*    Time: 04/10/22 23:05:35
*    Create By yongheng
*/

#include <iostream>
#include "./MyClass.h"

using namespace std;

int main(int argc,char *argv[]){

    MyClass *p = new MyClass;
    
    p->key = 10;
    ++p->key;
    cout << p->key << endl;






    return 0;
}
