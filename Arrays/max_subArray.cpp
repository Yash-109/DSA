#include<bits/stdc++.h>
using namespace std;

//Problem: 53: Maximum SubArray 
//difficulty: easy

//Approach: Kadane's Algorithm
// The idea is to scan the array from left to right and keep track of:
// 1. currsum: current subarray sum ending at current position
// 2. maxsum: maximum subarray sum seen so far
// 
// Key Logic:
// - If currsum becomes negative, reset it to 0 (start fresh subarray)
//   because a negative sum would only decrease future sums

// Time Complexity: O(n) - single pass
// Space Complexity: O(1) - only using two variables

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currsum=0;
        int maxsum=INT_MIN;
        for(int val:nums)
        {
         currsum+=val;
         maxsum= max(currsum,maxsum);
         if(currsum<0)
         {
            currsum=0;
         }   
        }
        return maxsum;
    }
    
};