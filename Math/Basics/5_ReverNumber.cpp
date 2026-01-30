// LeetCode 7: Reverse Integer
// Problem: Given a signed 32-bit integer x, return x with its digits reversed.
// If reversing x causes the value to go outside the signed 32-bit integer range [-2^31, 2^31 - 1], then return 0.

#include <climits>

class Solution {
public:
    int reverse(int n) {
        int revNum= 0 ;
        while(n != 0)
        {
            int dig = n%10;

            if(revNum > INT_MAX/10 || revNum < INT_MIN/10)
            {
                return 0; // for constarint in question
            }
            
            revNum = revNum*10 + dig;
            n = n/10;
        }
        return revNum;
    }
};