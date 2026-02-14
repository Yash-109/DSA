/*
 * Problem: Subsets II (with Duplicates)
 * LeetCode: 90
 * Technique: Backtracking with Duplicate Handling
 * 
 * Generate all unique subsets from an array that may contain duplicates
 * Key Insight: When excluding an element, skip all its duplicates to avoid repetition
 * 
 * Time Complexity: O(2^n) - where n is array size
 * Space Complexity: O(n) - recursion depth + temporary storage
 * 
 * Logic:
 * 1. Sort array to group duplicates together
 * 2. For each element: include it OR exclude it and all its duplicates
 * 3. Backtrack after exploring each path
 * 
 * Why repeatation occurs: When we choose to exclude an element, if the same 
 * duplicate element appears later, including it would create the same subset
 * Solution: Skip all duplicates when excluding
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void getAllSubsets(vector<int>& nums, vector<int>& ans, int i, vector<vector<int>>& allSubsets) {
        if (i == nums.size()) {
            allSubsets.push_back(ans);
            return;
        }

        // include
        ans.push_back(nums[i]);
        getAllSubsets(nums, ans, i + 1, allSubsets);

        ans.pop_back();

        // Skip all duplicates of current element when excluding
        // This prevents duplicate subsets in the result
        int idx = i + 1;
        while (idx < nums.size() && nums[idx] == nums[idx - 1]) {
            idx++;
        }

        // exclude current element and all its duplicates
        getAllSubsets(nums, ans, idx, allSubsets);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // Sort to group duplicates together - essential for duplicate detection
        sort(nums.begin(), nums.end());

        vector<vector<int>> allSubsets;
        vector<int> ans;

        getAllSubsets(nums, ans, 0, allSubsets);

        return allSubsets;
    }
};

int main() {
    Solution sol;
    
    // Test Case 1: Array with duplicates
    vector<int> nums1 = {1, 2, 2};
    cout << "Input: [1, 2, 2]" << endl;
    cout << "Unique Subsets:" << endl;
    vector<vector<int>> result1 = sol.subsetsWithDup(nums1);
    for (auto& subset : result1) {
        cout << "[";
        for (int i = 0; i < subset.size(); i++) {
            cout << subset[i];
            if (i < subset.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
    // Output: [], [1], [1,2], [1,2,2], [2], [2,2]
    
    cout << "\nTest Case 2: Array with multiple duplicates" << endl;
    vector<int> nums2 = {4, 4, 4, 1, 4};
    cout << "Input: [4, 4, 4, 1, 4]" << endl;
    vector<vector<int>> result2 = sol.subsetsWithDup(nums2);
    cout << "Total unique subsets: " << result2.size() << endl;
    
    return 0;
}
