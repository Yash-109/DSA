/*
    stack has lifo structure.
*/

#include<iostream>
#include<stack>
using namespace std;

int main()
{
    stack<int> s ;
    s.push(1);
    s.push(2);
    s.emplace(3);  // emplace = push in stack
    s.push(4);
    s.push(5);
    s.push(6);

    s.top(); // 6

    s.pop();// pops 6 
    s.pop();// pops 5

    cout<<s.size()<<endl; // 4
    while(!s.empty())
    {
        cout<<s.top()<<" ";   // 4 3 2 1
        s.pop();
    }

    /*
    stack has function: push, emplace, pop, top, size, empty, swap
    */

//     // if s = 1,2,3,4  // size =4

    stack<int> s2;
    s2.swap(s);

    cout<<s2.size(); // 4
    cout<<s.size();  //0

     while(!s2.empty())
    {
        cout<<s2.top()<<" ";   // 4 3 2 1
        s2.pop();
    }

    // tc of push, top, pop O(1)

}