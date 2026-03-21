/*
 * Problem: 1. Two Sum
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/two-sum/
 * 
 * Find two numbers in array that add up to target
 * Returns indices of the two numbers
 */

/*
 * Approach (Two Pointers on Sorted Array)
 * --------------------------------------
 * - Use two indices: i at the start and j at the end of the sorted array.
 * - At each step compute currentSum = nums[i] + nums[j].
 *   - If currentSum is greater than target, we need a smaller sum, so move
 *     j one step left.
 *   - If currentSum is less than target, we need a larger sum, so move
 *     i one step right.
 *   - If currentSum equals target, we have found the pair and return
 *     their indices.
 * - If i crosses j without finding such a pair, then no valid pair exists.
 *
 * Pseudocode
 * ---------
 *   function twoSum(nums, target):
 *       i = 0
 *       j = nums.size() - 1
 *
 *       while i < j:
 *           currentSum = nums[i] + nums[j]
 *
 *           if currentSum > target:
 *               j = j - 1
 *           else if currentSum < target:
 *               i = i + 1
 *           else:
 *               return [i, j]
 *
 *       return empty list   // no pair found
 */

#include<iostream>
#include<vector>
using namespace std;

// Two Pointer Approach - Works on sorted arrays
// Time Complexity: O(n), Space Complexity: O(1)
vector<int> pairsum(vector<int> nums, int target)
{
    // brute force approach o(n^2)
    // vector<int> ans;
    // int n=nums.size();
    // for(int i=0;i<n;i++){
    //     for(int j=i+1;j<n;j++)
    //     {
    //         if(nums[i]+nums[j]== target)
    //         {
    //             ans.push_back(i);
    //             ans.push_back(j);
    //             return ans;
    //         }
    //     }
    // }
    // return ans;

    // Two Pointer Approach: Time Complexity O(n)
    // Note: This approach only works if the array is sorted

    vector<int> ans;
    int n = nums.size();
    int i = 0;           // Left pointer
    int j = n - 1;       // Right pointer
    while(i < j)
    {
        int pairsum = nums[i] + nums[j];
        
        if(pairsum > target)
        {
            j--;  // Sum too large, move right pointer left
        }
        else if(pairsum < target)
        {
            i++;  // Sum too small, move left pointer right
        }
        else
        {
            ans.push_back(i);
            ans.push_back(j);
            return ans;
        }
    }
    return ans;
}
int main()
{
    vector<int> nums={2,7,11,15};
    int target=18;
    vector<int> ans=pairsum(nums,target);
    cout<<ans[0]<<","<<ans[1];
    return 0;
}