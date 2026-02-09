/*
 * Problem: 204. Count Primes
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/count-primes/
 * 
 * Algorithm: Sieve of Eratosthenes
 * 
 * Approach:
 * 1. Create a boolean array of size n+1, initially marking all as prime
 * 2. Start from the first prime number (2)
 * 3. Mark all multiples of that prime as non-prime
 * 4. Move to the next unmarked number and repeat
 * 5. Count all numbers that remain marked as prime
 * 
 * Why this is optimal:
 * - Avoids checking divisibility for each number individually
 * - Eliminates composites in batch by marking multiples
 * - Time complexity: O(n log log n) - much better than O(n√n)
 */

#include <iostream>
#include <vector>
using namespace std;

// Time Complexity: O(n log log n), Space Complexity: O(n)
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
    Solution sol;
    
    int test1 = 10;   // Expected: 4 (primes: 2, 3, 5, 7)
    int test2 = 0;    // Expected: 0
    int test3 = 1;    // Expected: 0
    int test4 = 30;   // Expected: 10 (primes: 2, 3, 5, 7, 11, 13, 17, 19, 23, 29)

    cout << "Count of primes less than " << test1 << ": " << sol.countPrimes(test1) << endl;
    cout << "Count of primes less than " << test2 << ": " << sol.countPrimes(test2) << endl;
    cout << "Count of primes less than " << test3 << ": " << sol.countPrimes(test3) << endl;
    cout << "Count of primes less than " << test4 << ": " << sol.countPrimes(test4) << endl;

    return 0;
}
