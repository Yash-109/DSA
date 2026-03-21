#include<iostream>
#include<vector>
#include<list>
using namespace std;


// stack using vector  (same in array but size fixed in arrays)
class Stack1{
    vector<int> v;

public:

    void push(int val){  // O(1)
        v.push_back(val);
    }

    void pop(){ // O(1)
        v.pop_back();
    }

    int top(){ // O(1)
        return v[v.size()-1];
    }

    bool empty(){
        return v.size() == 0;  // if size = 0 then true else false
    }
};

// stack using Linked List
class Stack2{
    list<int> ll;

public:

    void push(int val){  // O(1)
        ll.push_front(val);
    }

    void pop(){ // O(1)
        ll.pop_front();
    }

    int top(){ // O(1)
        return ll.front(); 
    }

    bool empty(){
        return ll.size() == 0;  // if size = 0 then true else false
    }
};

// for implementing stack directly using stl:
/*
#include<stack> 
int main(){
    stack<int> s;
    

    s.push(10);
    s.push(20);
    s.push(30);

    while(!s.empty()){
        cout<< s.top() << " "; // 30 20 10
        s.pop();
    }
    cout<<endl;
    return 0;
}
*/
int main(){
    Stack1 s;
    Stack2 s2;

    s.push(10);
    s.push(20);
    s.push(30);

    while(!s.empty()){
        cout<< s.top() << " "; // 30 20 10
        s.pop();
    }
    cout<<endl;

    s2.push(10);
    s2.push(20);
    s2.push(30);

    while(!s2.empty()){
        cout<< s2.top() << " "; // 30 20 10
        s2.pop();
    }
    cout<<endl;
    return 0;
}