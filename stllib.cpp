#include<bits/stdc++.h>
using namespace std;


// STL = Standard Template Library

// 1.Algorithms   2.Containers   3.Functions   4.iterators

void containerPairs()
{   
    pair<int, pair<int, int>> p = {1,{3,4}};
    cout<<p.first;
    pair<int,int> arr[]={{1,2}};
    cout<<arr[0].second;
}

void containerVectors()
{
    // vectorare dynamic but arrays are static so array = fixed sized and vector=mutable size
    //defining   
    vector<int> v;

    v.push_back(1);
    v.emplace_back(2);

    vector<pair<int,int>> vec;
    vec.push_back({1,2});
    vec.emplace_back(1,2);

    vector<int> v(5,100);    // give 5 sized vector: {100,100,100,100,100}

    vector<int> v(5); //{0,0,0,0,0}  can increase or decrease size of vector

    vector<int> v1(5,20);
    vector<int> v2(v1);  // v2 is copy of v1 and v1 = {20,20,20,20,20}

    // accessing elements
    v1[0];
    v1[3];

    // example: vector v={20,10,15,6,7}

    vector<int>::iterator it = v.begin();   //v.begin=it point at 20
    it++;     // so now it = 10
    cout<< *(it)<<" ";  // o/p: 10  
                        // here only it = address but *(it) print valur of it because is not normal variable it is iterator

    it = it+2;
    cout<< *(it)<< " "; // o/p: 6

    //{10,20,30,40}
    vector<int>::iterator it = v.end();  // will point to somewhere right of 40 not 40 ,,for 40:it--
    vector<int>::iterator it = v.rend(); // reverseEnd will point to somewhere left of 10 not 10 ,, for 10:it++
    vector<int>::iterator it = v.rbegin();  // reverseBegin will point to 40 ,, if it++ then point to 30

    cout<<v.back(); // o/p: 40

    //access whole vector by iterator:

    for(vector<int>::iterator hey = v.begin(); hey!=v.end(); hey++)
    {
        cout<< *(it)<< " ";
    }

    for(auto hey = v.begin(); hey!=v.end(); hey++) // auto define automatic datatype
    {
        cout<< *(it)<< " ";
    }

    // int a=5;  means auto a=5; in c++ "auto" assign datatype automatic

    for(auto hey : v)
    {
        cout<<hey<< " ";
    }

    //{10,20,30,40}

    v.erase(v.begin()+1); // {10,30,40}

    //{10,20,30,40,50}
    v.erase(v.begin()+2, v.begin()+4); //{10,20,50}  removed 30 adn 40  v.erase(start,end)

    // Insert Function:

    vector<int> v(2,100); //{100,100}
    v.insert(v.begin(),300); // {300,100,100}
    v.insert(v.begin()+1,4,10); // {300,10,10,10,10,100,100}  // (index,n0. of element, element)

    vector<int> copyy(2,50);// {50,50}
    v.insert(v.begin(),copyy.begin(),copyy.end()); //{50,50,300,10,10,10,10,100,100}

    //{10,20}
    cout<<v.size(); // 2

    v.pop_back();  // 10

    //v1:{10,20}
    //v2: {30,40}

    v1.swap(v2); // v1->{30,40}  v2->{10,20}

    v.clear();  // erase entire vector

    cout<<v.empty();  // ans in boolean  true(0) or false(1)






} 
int main()
{
    return 0;
}