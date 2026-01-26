
//  deque: double ended queue
// dequeue:  means poping elemnt form queue


#include<iostream>
#include<deque>

using namespace std;

int main()
{
    deque<int> d={1,2,3,4,5,6};

    cout<<d[3];  // 4    same thing in list is not possible
    
    /* all operation same as list

    deque = dynamic arrays              we have random access
    list = DLL (diubly linked list)     we dont have random access

    */
    return 0;
}