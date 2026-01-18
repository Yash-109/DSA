/*
 * Problem: 1. Two Sum
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/two-sum/
 * 
 * Find two numbers in array that add up to target
 * Returns indices of the two numbers
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