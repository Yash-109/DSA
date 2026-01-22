/*
 * Problem: 75. Sort Colors (Dutch National Flag Problem)
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/sort-colors/
 * 
 * Sort array containing 0s, 1s, and 2s in-place
 * Three approaches: Brute Force, Counting, and Dutch National Flag (Optimal)
 * Time Complexity: O(n) - Optimal approach
 * Space Complexity: O(1)
 */

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        sort(nums.begin(),nums.end());  // bruteforce

        // optimized
        int n=nums.size();
        int count0 = 0, count1 = 0, count2 = 0;

        for(int i=0;i<n;i++)  // O(n)
        {
            if(nums[i]==0) count0++;
            else if(nums[i]==1) count1++;
            else count2++;
        }

        // O(n)
        int indx=0;
        for(int i=0;i<count0;i++)
        {
            nums[indx++] = 0;
        }

         for(int i=0;i<count1;i++)
        {
            nums[indx++] = 1;
        }

         for(int i=0;i<count2;i++)
        {
            nums[indx++] = 2;
        }

        // optimal:

        int n=nums.size();
       int low=0, mid = 0, high=n-1;

        while(mid<=high)
        {
            if(nums[mid]==0)
            {
                swap(nums[low],nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid]==1) mid++;
            else
            {
                swap(nums[high],nums[mid]);
                high--;
            }
        }
        
    }
};