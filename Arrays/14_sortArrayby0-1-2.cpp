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

/*
 * Approach (Dutch National Flag Algorithm)
 * ---------------------------------------
 * - Maintain three regions in the array using indices low, mid and high:
 *     [0 .. low-1]     -> all 0s
 *     [low .. mid-1]   -> all 1s
 *     [mid .. high]    -> unknown / unprocessed
 *     [high+1 .. n-1]  -> all 2s
 * - Start with low = 0, mid = 0, high = n-1 and process nums[mid]:
 *     - If nums[mid] == 0: swap(nums[low], nums[mid]), increment low and mid
 *     - If nums[mid] == 1: just increment mid
 *     - If nums[mid] == 2: swap(nums[mid], nums[high]) and decrement high
 *       (do not increment mid here because the new element at mid is
 *        unprocessed and must be checked again)
 * - Continue until mid surpasses high; at that point the whole array is
 *   partitioned into 0s, then 1s, then 2s.
 *
 * Pseudocode
 * ---------
 *   function sortColors(nums):
 *       n = nums.size()
 *       low  = 0
 *       mid  = 0
 *       high = n - 1
 *
 *       while mid <= high:
 *           if nums[mid] == 0:
 *               swap(nums[low], nums[mid])
 *               low  = low + 1
 *               mid  = mid + 1
 *
 *           else if nums[mid] == 1:
 *               mid = mid + 1
 *
 *           else:   // nums[mid] == 2
 *               swap(nums[mid], nums[high])
 *               high = high - 1
 *
 *       // array is now sorted as 0s, then 1s, then 2s
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

        // optimal: dutch national flag algorithm

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