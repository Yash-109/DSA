/*
in set unique values stored in particular sorted order

*/

#include<set>
#include<iostream>
using namespace std;

int main()
{
    set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(5);

    s.insert(1);
    s.insert(2);
    s.insert(3);

    s.size(); // 5 bcz all unique 
    for(auto values: s)
    {
        cout<<values<<" "; // 1 2 3 4 5   sorted
    }

    // emplace,insert,count,erase,find tc O(logn) like map


    /*
        lower bound: eaxct that value or just greater than that value
        upper bound: gerater than value

    */
   set<int> s1;
    s1.insert(1);
    s1.insert(2);
    s1.insert(3);
    s1.insert(5);
    s1.insert(6);

    cout<<*(s.lower_bound(4));// 5 bcz greated than 4 and nearests
    // if 4 or >4 value not exist then returns s.end() which is 0

    /*
    if set has 1,2,3,4,5,6,7
    s.lower_bound(4) = 4
    s.upper_bound(4)= 5    bcz have to be greater than key
    */


    /*
    Multi set: allows duplicate element
    declare  =    multiset<int> s1;  


    unorder set:  values are not sorted. randomly inserted
    #include<unordered_set>
    declare: unordered_set<int> s1;

    in unorder set lower and uper bound cant be calculated as they are not sortd
    tc : O(1). That is why unorder map and unordered set widely used for lesser tc


std::set / std::unordered_set
insert() – inserts unique element
find() – finds element
count() – checks existence (0 or 1)
erase() – removes element
size() – returns number of elements
    */

}
