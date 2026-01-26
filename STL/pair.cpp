
#include<iostream>
#include<vector>
using namespace std;

int main()
{
    pair<int, int> p = {1,5};

    cout<<p.first<<endl; // 1
    cout<<p.second<<endl; // 5

    pair<string, int> p1 = {"yash",5};

    cout<<p1.first<<endl; // yash
    cout<<p1.second<<endl; // 5

    pair<int, pair<char, int>> p2 = {1, {'a',5}};

    cout<<p2.first<<endl; // 1
    cout<<p2.second.first<<endl; // a


    vector<pair<int, int>> vec = {{1, 2}, {3,4}, {5,6}};

    for(pair<int, int> p3: vec)   // this line can be: for(auto p3: vec)
    {
        cout<<p3.first<<" " << p3.second<< endl; 
        /*
            1 2 
            3 4 
            5 6
        */      
    }

    vec.push_back({7,8});   // push_back only insert which is given  it cant convert value in pair but emplace_back can do it

    vec.emplace_back(7,8);  // in-place boject create

    // push_back and emplace_back has syntax differnce
    return 0;
}