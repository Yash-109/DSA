
// LeetCode 238: Product of Array Except Self
// Time Complexity: O(n^2) - brute force approach
// Space Complexity: O(1) - not counting the output array

/*
 * Approach 1 (Brute Force)
 * ------------------------
 * - For each index i, multiply all elements nums[j] where j != i.
 * - Store the product in ans[i]. Time: O(n^2).
 *
 * Approach 2 (Prefix and Suffix Products)
 * --------------------------------------
 * - Build prefix[i] = product of all elements before i.
 * - Build suffix[i] = product of all elements after i.
 * - Then ans[i] = prefix[i] * suffix[i] for every i. Time: O(n), Space: O(n).
 *
 * Approach 3 (Space-Optimized Prefix + Running Suffix)
 * ----------------------------------------------------
 * - Use ans[] itself to store prefix products.
 * - Then traverse from right to left maintaining a running suffix product and
 *   multiply into ans[i]. Overall Time: O(n), extra Space: O(1).
 *
 * Pseudocode (Space-Optimized)
 * ----------------------------
 *   function productExceptSelf(nums):
 *       n = nums.size()
 *       ans = array of size n filled with 1
 *
 *       // prefix pass
 *       for i from 1 to n-1:
 *           ans[i] = ans[i-1] * nums[i-1]
 *
 *       // suffix pass
 *       suffix = 1
 *       for i from n-2 down to 0:
 *           suffix = suffix * nums[i+1]
 *           ans[i] = ans[i] * suffix
 *
 *       return ans
 */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);  // it means vector ans intialized with alll value 1 of size n
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(i != j) {
                    ans[i] *= nums[j];
                }
            }   
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 4};
    vector<int> result = sol.productExceptSelf(nums);
    
    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    
    return 0;
}



//optimal approach:  TC:O(n)  ans SC:O(n)

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
    int n=nums.size();
    vector<int> ans(n,1);
    vector<int> prefix(n,1);
    vector<int> suffix(n,1);

    //for prefix   O(n)
    for(int i=1;i<n;i++)
    {
         prefix[i]=prefix[i-1]*nums[i-1];
    }

    //for suffix   O(n) 
    for(int i=n-2;i>=0;i--)
    {
        suffix[i]=suffix[i+1]*nums[i+1];
    }
    
    for(int i=0;i<n;i++)    // O(n)  so, total TC= O(3n) = O(n)
    {
        ans[i]=prefix[i]*suffix[i];
    }
    return ans;
    }
};

//space optimization by removing extra vectors prefix and suffix
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
    int n=nums.size();
    vector<int> ans(n,1);   

    //for prefix   O(n)
    for(int i=1;i<n;i++)
    {
        ans[i]=ans[i-1]*nums[i-1];
    }

    //for suffix   O(n) 
    int suffix=1;
    for(int i=n-2;i>=0;i--)
    {
        suffix*=nums[i+1];
        ans[i]*=suffix;
    }
    return ans;    //so, tc=O(n) and sc=O(1) if we dont take sc for vector ans
    }
};