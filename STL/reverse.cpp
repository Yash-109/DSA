#include<iostream>
#include<vector>
#include<algorithm>   // this is imp
using namespace std;

int main(){
    vector<int> vec= {3,5,1,8,2};

    reverse(vec.begin(), vec.end());
    for(int val: vec)
    {
        cout<<val<<" "; // 2 8 1 5 3
    }
    cout<<endl;

    // vec = 2 8 1 5 3
    reverse(vec.begin() + 1, vec.begin()+ 3);
    for(int val: vec)
    {
        cout<<val<<" "; // 2 1 8 5 3
    }
    cout<<endl;

    // NEXT permutation
    /*
    s = abc   n!=6 permutation for abc:  abc, acb, bac, bca, cab, cba

    next_permutation(vec.begin(),vec.end());
    */

    string s = "abc";
    next_permutation(s.begin(),s.end());
    cout<<s<<endl;  // acb

    string s1= "bca";
    prev_permutation(s1.begin(),s1.end());  // previous permutation
    cout<<s1<<endl;  // bac


    cout<< max(4,5); //5
    cout<<min(4,7);   //4

    int a=5, b=10;
    swap(a,b);
    cout<<a; //10
    cout<<b; //5
    cout<<endl;

    // max & min element
    vector<int> vec1= {3,5,1,8,2};

    cout<< *(max_element(vec1.begin(), vec1.end()));  // 8
    // also min_elements

    // binary search
    // binary_search(v.begin(), v.end(), target);       // returns true or false if target exist or not
    cout<< binary_search(vec1.begin(), vec1.end(), 8);  // 0 (false) bcz have to sort first for binary s.

    sort(vec1.begin(), vec1.end());

    bool found = binary_search(vec1.begin(), vec1.end(), 8);
    cout << found;   // 1 (true)

    // count set bits 
    /*
    for int a = 15; we know int have 32 bits and last bit woould be 1111 for 15
    hense ans of set bits is 4
    */

    int x = 15;
    cout<< __builtin_popcount(x); // 4

    long int ab = 15;
    cout<< __builtin_popcountl(ab); // 4

    long long int n2= 15;
    cout<< __builtin_popcountll(n2); // 4

}