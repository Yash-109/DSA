/*
 * Recursion Basics
 * 
 * Fundamental concepts and examples of recursion
 * Every loop can be written as recursion and vice versa
 * Key components: Base case, Recursive case, Call stack
 */

#include<iostream>
using namespace std;

// Print numbers from n to 1 in descending order
// Time Complexity: O(n), Space Complexity: O(n)
void printNums(int n){
    // Base case: stop when n <= 0
    if(n>0){
        cout<<n<<endl;
        printNums(n-1);  // Recursive call with smaller problem
    }
    else return;
}

// Calculate factorial of n
// Time Complexity: O(n), Space Complexity: O(n) for call stack
int factorial(int n){
    // Base case: 0! = 1
    if(n == 0){
        return 1;
    }
    // Recursive case: n! = n * (n-1)!
    return n * factorial(n-1);

    // Recursion works because the call stack is LIFO
    // | factorial(0) |  ← top (executes first on return)
    // | factorial(1) |
    // | factorial(2) |
    // | factorial(3) |
}

// Calculate sum of first n natural numbers
// Time Complexity: O(n), Space Complexity: O(n)
int sum(int n)
{
    // Base case
    if(n == 1){
        return 1;
    }
    // Recursive case: sum(n) = n + sum(n-1)
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