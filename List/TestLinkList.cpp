/*
*    Time: 04/10/22 10:07:07
*    Create By yongheng
*/

#include <iostream>
#include "./Link_List.h"
using namespace std;

int main(int argc,char *argv[]){

    LinkList<int>ll;
    
    for(int i = 1;i <= 10; ++i){
        ll.Push_back(i);
    }

    cout << endl;
    ll.Show();



    // ll.Show();



    return 0;
}
