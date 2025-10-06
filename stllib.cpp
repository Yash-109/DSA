#include<bits/stdc++.h>
using namespace std;


// STL = Standard Template Library

// 1.Algorithms   2.Containers   3.Functions   4.iterators

void containerPairs()
{   
    pair<int, pair<int, int>> p = {1,{3,4}};
    cout<<p.first;
    cout<<p.second.first;
    pair<int,int> arr[]={{1,2}};
    cout<<arr[0].second;
}

void containerVectors()
{
    // vectorare dynamic but arrays are static so array = fixed sized and vector=mutable size
    //defining   
    vector<int> v;

    v.push_back(1);
    v.emplace_back(2); // emplace_back is bit faster than push_back

    vector<pair<int,int>> vec;
    vec.push_back({1,2});
    vec.emplace_back(1,2);

    vector<int> v(5,100);    // give 5 sized vector: {100,100,100,100,100}

    vector<int> v(5); // *** {0,0,0,0,0}  can increase or decrease size of vector ***

    vector<int> v1(5,20);
    vector<int> v2(v1);  // v2 is copy of v1 and v1 = {20,20,20,20,20}

    // accessing elements
    v1[0];
    v1[3];

    // example: vector v={20,10,15,6,7}

    vector<int>::iterator it = v.begin();   //v.begin=it point at 20
    it++;     // so now it = 10
    cout<< *(it)<<" ";  // o/p: 10  
                       // here only it = address but *(it) print valur of it because it is not normal variable it is iterator

    it = it+2;
    cout<< *(it)<< " "; // o/p: 6

    //{10,20,30,40}
    vector<int>::iterator it = v.end();  // will point to somewhere right of 40 not 40 ,,for 40 we should it--
    vector<int>::iterator it = v.rend(); // reverseEnd will point to somewhere left of 10 not 10 ,, for 10 we should it++
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

void containerList()
{
    list<int> l;
    l.push_back(2);  // {2}
    l.emplace_back(4); //{2,4}

    l.push_front(5); // {5,2,4}
    l.emplace_front(3); //{3,5,2,4}

    //rest functions are as vector: begin,end,rbegin,rend,clear,insert,size,swap

}

void containerDeque()
{
    // Insertion and deletion at both the front and rear. 
    deque<int> dq;
    dq.push_back(2);  // {2}
    dq.emplace_back(4); //{2,4}

    dq.push_front(5); // {5,2,4}
    dq.emplace_front(3); //{3,5,2,4}

    dq.pop_front(); //{5,2,4}
    dq.pop_back(); //{5,2}

    dq.front();
    dq.back();
    // all other function same
}

void containerStack()
{
     // stack= LIFO Last In First Out
     // push ,pop ,top all operation complexity: o(1)
     stack<int> s;
     s.push(1); //{1}
     s.push(2); //{2,1}
     s.push(2);
     s.push(3); //{3,2,2,1}
     s.push(5); // {5,3,2,2,1}

     cout<<s.top();   // o/p: 5

     s.pop();  //{3,2,2,1}
     s.top(); // 3
     s.size(); // 4

     cout<<s.empty();

     stack<int>st1, st2;
     st1.swap(st2);
}

void containerQueue()
{
    // FIFO: First In First Out
    // insertion at rear and deletion at front only
    queue<int> q;
    q.push(1); //{1}
    q.push(2); //{1,2}
    q.emplace(4); //{1,2,4}

    q.back() += 5; //{1,2,9}

    q.back(); // 9
    q.front(); //1 

    q.pop();  // {2,9}

    //size, swap,empty same as stack   also Complexity: o(1)
}

void priorityQueue()
{
    // Max Heap (maximum priority queue)

    // push(): log(n)
    // top(): o(n)
    // pop(): log(n)
    priority_queue<int> pq;
    pq.push(5); //{5}
    pq.push(2); //{5,2}
    pq.emplace(8); //{8,5,2}
    pq.push(10); //{10,8,5,2}

    pq.top(); // 10

    pq.pop(); //{8,5,2}

    pq.top(); // 8

    // size,swap same

    //Min Heap (minimum priority queue)
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(5); //{5}
    pq.push(2); //{2,5}}
    pq.emplace(8); //{2,5,8}
    pq.push(10); //{2,5,8,10}

    cout<<pq.top();  // 2
}

void containerSet()
{
    // store evrything in sorted manner and only store unique values

    // set operations insert,find,erase take logarithmic time complexity log(n)

    set<int> st;
    st.insert(1); //{1}
    st.emplace(2); //{1,2}
    st.insert(2); //{1,2}
    st.emplace(4); // {1,2,4}
    st.emplace(3); //{1,2,3,4}

    // functionality of insert in vector can be used aslo
    // to increase efficiency

    //{1,2,3,4,5}
    auto it = st.find(3); // returns iterator which points to 3 , means it is iterator

    auto it =st.find(6); // return iterator which point to after 5 as it is last element [kind of .end()]

    st.erase(5); //{1,2,3,4}  // takes ;ogarithmic time 

    int count =st.count(1); // if exist so count=1 bcz unique, if not exist count =0;

    auto it=st.find(3);
    st.erase(it); // so set can also erase iterator 

    //{1,2,3,4,5}
    auto it1= st.find(2);
    auto it2= st.find(4);
    st.erase(it1,it2); // after erase {1,4,5} {fisrt,last}

    vector<int> v = {11, 34, 56, 67, 89};

  	// Finding lower bound of 56
    cout << *lower_bound(v.begin(), v.end(), 56)
      << endl;
	
  	// Finding upper bound of 56
    cout << *upper_bound(v.begin(), v.end(), 56);

    //for set:syntax
    auto it = st.lower_bound(2);
    auto it = st.upper_bound(3);
}

void multiSet()
{
    // same as set but not unique onlt sorted
    multiset<int> ms;
    ms.insert(1); //{1}
    ms.insert(1); //{1,1}
    ms.insert(1); //{1,1,1}

    ms.erase(1); // all 1's eraced

    // if want to erase specific not all:

    ms.erase(ms.find(1)); //{1,1}

   // {1,1,1}
   ms.erase(ms.find(1), ms.find(1)+2); // {1} {star,end}

}

void unorderSet()
{
    unordered_set<int> unorderedset;
    //not ordered but unique most cases:o(1)
    // all operation  work but not lower and upper bound
}

int main()
{
    return 0;
}