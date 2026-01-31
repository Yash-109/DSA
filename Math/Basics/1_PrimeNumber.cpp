/*
 * Problem: Prime Numbers
 * Difficulty: Easy / Medium
 * Link: https://leetcode.com/problems/count-primes/ (Problem 204)
 * 
 * 1. Print all prime numbers up to n
 * 2. Count prime numbers less than n using Sieve of Eratosthenes
 */

#include <iostream>
#include <vector>
using namespace std;

// Time Complexity: O(n√n), Space Complexity: O(1)
void printPrimesUpToN(int n)
{
    cout << "Prime numbers up to " << n << ": ";
    for (int i = 2; i <= n; i++) {
        bool isPrime = true;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            cout << i << " ";
        }
    }
    cout << endl;
}

// Time Complexity: O(n log log n), Space Complexity: O(n)
// Sieve of Eratosthenes Algorithm - LeetCode 204  
class Solution {
public:
    int countPrimes(int n) {
        vector<bool> isPrime(n+1,true);
        int count=0;
        for(int i=2; i<n; i++)
        {
            if(isPrime[i])
            {
                count++;
            }

            for(int j=i*2; j<n; j = j+i)
            {
                isPrime[j] = false;
            }
        }
        return count;
    }
};

int main() {
    // Test case 1: Print primes up to 20
    int n1 = 20;
    printPrimesUpToN(n1);
    cout << endl;

    // Test case 2: Print primes up to 50
    int n2 = 50;
    printPrimesUpToN(n2);
    cout << endl;

    // Test case 3: Count primes using Sieve of Eratosthenes
    Solution sol;
    int test1 = 10;   // Primes: 2,3,5,7 -> count=4
    int test2 = 0;    // No primes
    int test3 = 1;    // No primes
    int test4 = 30;   // Primes: 2,3,5,7,11,13,17,19,23,29 -> count=10

    cout << "Count of primes less than " << test1 << ": " << sol.countPrimes(test1) << endl;
    cout << "Count of primes less than " << test2 << ": " << sol.countPrimes(test2) << endl;
    cout << "Count of primes less than " << test3 << ": " << sol.countPrimes(test3) << endl;
    cout << "Count of primes less than " << test4 << ": " << sol.countPrimes(test4) << endl;

    return 0;
}
