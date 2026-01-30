// LeetCode 9: Palindrome Number
// Problem: Given an integer x, return true if x is a palindrome, and false otherwise.
// Core Logic: 
// 1. Negative numbers are not palindromes (e.g., -121 reads as 121-)
// 2. Reverse the number and compare with original
// 3. If reversed number equals original, it's a palindrome

#include <climits>

class Solution {
public:
    // Helper function to reverse a number
    int reverse(int n) {
        int revNum = 0;
        while(n != 0)
        {
            int dig = n % 10;

            // Check for overflow before multiplying by 10
            if(revNum > INT_MAX/10 || revNum < INT_MIN/10)
            {
                return 0; // Return 0 if overflow occurs
            }
            
            revNum = revNum * 10 + dig;
            n = n / 10;
        }
        return revNum;
    }

    bool isPalindrome(int n) {
        // Negative numbers are not palindromes
        if(n < 0) return false;

        // Reverse the number and check if it equals the original
        int revNum = reverse(n);
        return n == revNum;
    }
};