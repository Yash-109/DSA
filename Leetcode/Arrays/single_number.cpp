#include<bits/stdc++.h>
using namespace std;

 //Problem: 136: Single Number
 //Difficulty: easy
 //Approach: 
 // Use XOR operation to find the single number
 // Key properties of XOR:
 // 1. a ^ a = 0 (any number XORed with itself is 0)
 // 2. a ^ 0 = a (any number XORed with 0 is the number itself)
 // 3. XOR is commutative and associative
 // Since every number appears twice except one, all pairs will cancel out (become 0)
 // and only the single number will remain
 // Time Complexity: O(n), Space Complexity: O(1)

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(int val:nums)
        {
            ans ^=val;
        }
        return ans;
    }
};