/*
*    Time: 04/10/22 08:49:55
*    Create By yongheng
*/

#include <iostream>
#include "./List.h"
#include "./MyClass.h"

using namespace std;

int main(int argc,char *argv[]){

    List<MyClass> l;

    for(int i = 0;i < 20; ++i){
        l.Insert(1, MyClass(i,i));
    }
    l.Show();





    return 0;
}
