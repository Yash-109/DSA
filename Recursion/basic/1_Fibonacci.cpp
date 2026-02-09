/*
 * Problem: Fibonacci Number
 * 
 * Calculate nth Fibonacci number using recursion
 * Fibonacci sequence: 0, 1, 1, 2, 3, 5, 8, 13, 21...
 * Formula: F(n) = F(n-1) + F(n-2)
 * 
 * Time Complexity: O(2^n) - exponential (inefficient, consider DP for optimization)
 * Space Complexity: O(n) - recursion call stack depth
 */

#include<iostream>
using namespace std;

// Returns nth Fibonacci number
int fibonacci(int n){
    // Base cases: F(0) = 0, F(1) = 1
    if(n==0 || n==1){
        return n;
    }
    else{
        // Recursive case: F(n) = F(n-1) + F(n-2)
        return fibonacci(n-1) + fibonacci(n-2);
    }
}
int main(){
    int n = 3;
    cout << "Fibonacci(" << n << ") = " << fibonacci(n) << endl;
    // Output: Fibonacci(3) = 2
    return 0;
}