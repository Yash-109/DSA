// Array size is static whereas vector size is dynamic

#include<iostream>
using namespace std;
#include<vector>

            // size & capacity
            // push_back, pop_back  // tc:O(1)
            // empace_back
            // at() or []
            // front and back
            // erase, insert  // tc:O(n)

int main()
{
    vector<int> vec;
    vec.size(); // 0

    vec.push_back(1);  // now size 1   capacity =1
    vec.push_back(2);  // now size 2   capacity =2
    vec.push_back(3);  // size 3    but capacity =4  
   
    // capcity always get double after new element inseted
    vec.capacity(); // 4

    vec.push_back(4);
    vec.push_back(5);
    vec.emplace_back(6);

    for(int value : vec)
    {
        cout<<value<<" ";   // 1 2 3 4 5 6
    }

    vec.pop_back(); // pop 6

    cout<< vec[2]; // 3
    cout<< vec.at(2); //3

    cout<< vec.front();  // 1
    cout<<vec.back(); // 5


    // initializations:
    vector<int> vec1;
    vector<int> vec2 = {1,2,3};  // 1 2 3
    vector<int> vec3(3,10);   // vec3(size,value)  // 10 10 10
    vector<int> vec4(vec2);   // 1 2 3

    // erase and insert are costly functions

    vector<int> vecc={1,2,3,4,5,6,7};
    cout<<endl;
    vecc.erase(vecc.begin()); 
    cout<< vecc[0];  // 2

    // {2,3,4,5,6,7}
    vecc.erase(vecc.begin() + 2); 
    cout<< vecc[2]; // 5

    // {2,3,5,6,7}
    vecc.erase( vecc.begin() +1, vecc.begin() +3);  // 3 & 5 erased
    // so vector:  {2,6,7}    
    // vecc.erase(start,end+1);

    // erase adn clear changes size of vector but dont change capacity

    vector<int> v={1,2,3,4,5,6,7};
    v.insert(v.begin() + 2, 100);  // {1,2,100,3,4,5,6,7}
    // v.insert(indx,element);

    v.clear();   // clear whole vector
    cout<< v.size(); // 0
    cout<< v.capacity(); // 8

    cout<<v.empty();   // 1   here 1 = true


            // Iterators in vector::

    vec.begin();// points to first element
    *(vec.begin());  // dereferncing: points avalue of first ele 

    vec.end();  // points to next indx form last indx
    // if vector = {1,2,3}
    // *(vec.end());  // not 3    it gives ant garbage value

    vector<int> v1={1,2,3,4};

    vector<int>::iterator it;

    for(it = v1.begin(); it!=v1.end(); it++)
    {
        cout<< *(it);      // 1 2 3 4 
    }

    // backward::
    vector<int>::reverse_iterator rit; // iterator decalring

    for(rit = v1.rbegin(); rit!= v1.rend(); rit++)
    {
        cout<< *(rit);  // 4 3 2 1
    }

    //now instead declaring iterator outside we can 
    for(vector<int>::reverse_iterator rit = v1.rbegin(); rit!= v1.rend(); rit++)
    {
        cout<< *(rit);  // 4 3 2 1
    }

    // aslo ::
     for(auto rit = v1.rbegin(); rit!= v1.rend(); rit++)   
    {
        cout<< *(rit);  // 4 3 2 1
    }
    // by auto c++ automatically understand which type of varible we are trying to use
}