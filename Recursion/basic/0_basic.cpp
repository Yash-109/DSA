#include<iostream>
using namespace std;

/*
Each task done by loop can be done by recursion amd every problem done by recursion can be done by loop
*/

void printNums(int n){
    if(n>0){
    cout<<n<<endl;
    printNums(n-1);
    }
    else return;
}

int factorial(int n){ // TC: o(n)
    if(n == 0){ // Base case in recursion: lowest value that you know  ex. 0! = 1   so 0 is base case
        return 1;
    }
    return n * factorial(n-1);

    // Recursion works because the call stack is LIFO
    // | factorial(0) |  ← top (executes first on return)
    // | factorial(1) |
    // | factorial(2) |
    // | factorial(3) |
}

int sum(int n)
{
    if(n == 1){
        return 1;
    }
    return n + sum(n-1);
}
// Calls going down (push)
// sum(4)
// sum(3)
// sum(2)
// sum(1)   ← base case

// Returns coming up (pop)
// sum(1) returns 1
// sum(2) returns 2 + 1 = 3
// sum(3) returns 3 + 3 = 6
// sum(4) returns 4 + 6 = 10

int main()
{
    printNums(5);
    cout<<factorial(5)<<endl;; // 120
    cout<<sum(4)<<endl;  // 10 
    return 0;
}