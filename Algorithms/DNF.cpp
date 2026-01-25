/*
 * Problem: 75. Sort Colors (Dutch National Flag Problem)  // same as sortArray 0s,1s,2s
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/sort-colors/
 * 
 * Sort array containing 0s, 1s, and 2s in-place using Dutch National Flag Algorithm
 * Uses three pointers: low (0s boundary), mid (current), high (2s boundary)
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int low = 0, mid = 0, high = n-1;

        while(mid <= high)
        {
            if(nums[mid] == 0)
            {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid] == 1) mid++;
            else
            {
                swap(nums[high], nums[mid]);
                high--;
            }
        }
    }
};