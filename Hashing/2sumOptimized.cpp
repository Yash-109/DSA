/*
 * Problem: 1. Two Sum (Optimized - Hash Map Approach)
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/two-sum/
 * 
 * Find two numbers in array that add up to target
 * Returns indices of the two numbers
 * 
 * Approach: Use unordered_map for fast searching O(1)
 * Time Complexity: O(n) - single pass through array
 * Space Complexity: O(n) - hash map storage
 */

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int tar) {  

        // Optimal approach using Hash Map:
        // Store each element with its index in map
        // For each element, check if (target - element) exists in map

        unordered_map<int,int> m;  // m[value] = index
        vector<int> ans;

        for(int i=0;i<arr.size();i++){
            int first = arr[i];
            int sec = tar - first;  // complement needed

            // Check if complement exists in map
            if(m.find(sec) != m.end())
            {
                ans.push_back(i);        // current index
                ans.push_back(m[sec]);   // complement's index
                break;
            }
            
            m[first] = i;  
            // Store: key = array element, value = index of that element
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    
    vector<int> result = sol.twoSum(nums, target);
    
    if(result.size() == 2) {
        cout << "Indices: " << result[0] << ", " << result[1] << endl;
        cout << "Values: " << nums[result[0]] << " + " << nums[result[1]] << " = " << target << endl;
    } else {
        cout << "No solution found" << endl;
    }
    
    return 0;
}
