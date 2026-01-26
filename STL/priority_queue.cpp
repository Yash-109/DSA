// in priority queue we have highest priority element at top which is largest too

// when pop elemnt pop in soreted order: largest then secong largest then third largestS

#include<iostream>
#include<queue>
using namespace std;

int main()
{
    priority_queue<int> q;
    q.push(5);
    q.push(3);
    q.push(10);
    q.push(4);

    while(!q.empty())
    {
        cout<<q.top()<<" ";   //  10 5 4 3
        q.pop();
    }

    // for reverse order prioruty queue : smallest to largest 
    priority_queue<int, vector<int>, greater <int>> q;
    q.push(5);
    q.push(3);
    q.push(10);
    q.push(4);

    while(!q.empty())
    {
        cout<<q.top()<<" ";   //  3 4 5 10
        q.pop();
    }

    // here greater <int> is a functor  which is function object  

    // priority queue function: push,emplace, pop, top, size, empty

    // Unique because of sorting:: tc of push,emplce and pop is O(logn)
    // but tc pf top is O(1)
    
}


