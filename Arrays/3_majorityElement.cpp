#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

//  Leetcode: 169: Majority Element

/*
 * Approach 1 (Sorting + Frequency Count)
 * -------------------------------------
 * - Sort the array; the majority element (appearing > n/2 times) must occupy
 *   the middle region.
 * - Walk through the sorted array and count the frequency of the current
 *   value; when any frequency exceeds n/2, that value is the majority.
 *
 * Approach 2 (Moore's Voting Algorithm)
 * -------------------------------------
 * - Maintain a candidate 'ans' and a counter 'freq'.
 * - Traverse the array:
 *     - If freq == 0, set candidate = current element.
 *     - If current element == candidate, increment freq.
 *     - Else decrement freq.
 * - After one pass, 'candidate' is the potential majority element.
 * - Do a second pass to verify candidate actually appears > n/2 times.
 *
 * Pseudocode (Moore's Voting + Verification)
 * -----------------------------------------
 *   function majorityElement(nums):
 *       candidate = 0
 *       freq = 0
 *
 *       for each x in nums:
 *           if freq == 0:
 *               candidate = x
 *           if x == candidate:
 *               freq = freq + 1
 *           else:
 *               freq = freq - 1
 *
 *       // verify candidate
 *       count = 0
 *       for each x in nums:
 *           if x == candidate:
 *               count = count + 1
 *
 *       if count > nums.size() / 2:
 *           return candidate
 *       else:
 *           return -1
 */
int main()
{
    vector<int> nums={2,2,1,1,1,2,2};
    int n=nums.size();

    //sort
    sort(nums.begin(), nums.end());
     
    int freq=1, ans=nums[0];
    for(int i=1;i<n;i++)
    {
        if(nums[i]==nums[i-1])
        {
            freq++;
        }
        else{
            freq=1;
            ans=nums[i];
        }
        if(freq>n/2)
        {
            ans=nums[i];
            break;
        }
    }
    cout<<ans;
    return 0;
     
}


// Moores motive algorithm: 
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int freq=0,  ans =0;
        for(int i=0;i<nums.size();i++)
        {
            if(freq==0)
            {
                ans=nums[i];
            }
            if(ans==nums[i])
            {
                freq++;
            }
            else{
                freq--;
            }
        }
        int count=0;
        for(int val:nums)
        {
            if(val==ans)
            {
                count++;
            }
        }
        if(count>nums.size()/2)
        {
            return ans;
        }
        else{return -1;}
    }
};