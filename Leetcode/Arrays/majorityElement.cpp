#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

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