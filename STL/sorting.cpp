// sorting is algorithm

#include<iostream>
#include<vector>
#include<algorithm>   // this is imp
using namespace std;

 bool comparitorrr(pair<int, int>p1, pair<int, int>p2)  // for sorting by second value
    {
        if(p1.second < p2.second) return true;
        if(p1.second > p2.second) return false;
        
        if(p1.first<p2.first) return true;  // this condition is for same element in 2nd place in pairs
        else return false;              // ex. pairs are {1,5}, {3,6}, {3,5}, {7,5}
                                        // so ans       1,5  3,5   7,5   3,6
    }

int main()
{
    int arr[5]= {3,5,1,8,2};
    sort(arr,arr + 5);
    for(int val: arr)
    {
        cout<<val<<" "; // 1 2 3 5 8
        
    }
    cout<<endl;

    vector<int> vec= {3,5,1,8,2};
    sort(vec.begin(), vec.end());
    for(int val: vec)
    {
        cout<<val<<" "; // 1 2 3 5 8
    }
    cout<<endl;

    vector<int> vec1= {3,5,1,8,2};
    sort(vec1.begin(), vec1.end(), greater<int>());  // for desceneding order  greater<int>() is a comparison function object(functor)
    for(int val: vec1)
    {
        cout<<val<<" "; // 8 5 3 2 1 
    }
    cout<<endl;

    vector<pair<int, int>> vec2={{3,2}, {4,5}, {7,3}};

    sort(vec2.begin(), vec2.end());
    for (auto p : vec2)
    {
        cout << p.first << " " << p.second << "\n";  // pair sort on besis of first element of pair
        /*
        3 2    
        4 5
        7 3
        */
    }
    cout<<endl;

    // custom comparitor:

    sort(vec2.begin(), vec2.end(), comparitorrr);  // comparitorrr is function above for custom logic in sorting
    for (auto p : vec2)
    {
        cout << p.first << " " << p.second << "\n";  // sorted by second pair element
        /*
        3 2    
        7 3
        4 5
        */
    }
}