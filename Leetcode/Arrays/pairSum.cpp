//Problem: 1. Two Sum
//Difficulty: Easy
//Link: https://leetcode.com/problems/two-sum/

#include<iostream>
#include<vector>
using namespace std;

vector<int> pairsum(vector<int> nums,int target)
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

    //two pointer o(n)  ony if we have sorted array

    vector<int> ans;
    int n=nums.size();
    int i=0;
    int j=n-1;
    while(i<j)
    {
        int pairsum=nums[i]+nums[j];
        if(pairsum>target)
        {
            j--;
        }
        else if(pairsum<target)
        {
            i++;
        }
        else{
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