/*
    stack has fifo structure.
*/

#include<iostream>
#include<stack>
#include<queue>
using namespace std;

int main()
{
    queue<int> q ;
    q.push(1);
    q.push(2);
    q.emplace(3); 
    q.push(4);
    q.push(5);
    q.push(6);

    q.pop();// pops 6 
    q.pop();// pops 5

    cout<<q.size()<<endl; // 4
    while(!q.empty())
    {
        cout<<q.front()<<" ";   // 4 3 2 1
        q.pop();
    }

    // in queue front in stack top
    // size empty swap work as stack

    /// tc of puhs , front , top tc : O(1)
}