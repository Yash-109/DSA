// in List we can push or pop or epmplace  form bith : front and back

#include<iostream>
#include<list>
using namespace std;

int main()
{
    list<int> l;

    l.emplace_back(1);        // push_back and emplace_back are same
    l.push_back(2);
    l.push_front(3);
    l.push_front(5);

    for(int val:l)
    {
        cout<<val<< " "; // 5 3 1 2 
    }
    cout<<endl;
    l.pop_back(); // 2 poped
    l.pop_front();  //  5 pop

        
    for(int val:l)
    {
        cout<<val<< " "; // 3 1 
    }
    
    // initialization:

    list<int> l1 = {1,2,3,4,5};


    // size,erase,clear,begin,end,rbegin,rend,insert,fornt,back   all are same for list as vector 

    // vecotr behaves like dynamic array whereas list behaves like doubly linked list so we ahve "front" opertion also in listS

    return 0;
}