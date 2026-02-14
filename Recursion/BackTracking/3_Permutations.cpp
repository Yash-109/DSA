/*
 * Problem: Permutations (All possible arrangements)
 * LeetCode: 46
 * Technique: Backtracking with Swapping
 * 
 * Generate all possible permutations of a given array
 * Uses swap-based approach for in-place generation
 * 
 * Time Complexity: O(n! * n) - n! permutations, n to copy each
 * Space Complexity: O(n) - recursion depth
 * 
 * Logic:
 * 1. Fix each element at current position by swapping
 * 2. Recursively generate permutations for remaining elements
 * 3. Backtrack by swapping back to restore original state
 * 4. When idx reaches end, we have a complete permutation
 * 
 * Key Pattern: Swap -> Recurse -> Swap back (backtrack)
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void getPerms(vector<int>& nums, int idx, vector<vector<int>>& ans) {
        // Base case: reached end, found one complete permutation
        if (idx == nums.size()) {
            ans.push_back(nums);
            return;
        }

        // Try placing each element from idx to end at position idx
        for (int i = idx; i < nums.size(); i++) {
            swap(nums[idx], nums[i]);   // Make choice: place nums[i] at idx position
            getPerms(nums, idx + 1, ans);  // Recurse for next position
            swap(nums[idx], nums[i]);   // Backtrack: restore original state
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        getPerms(nums, 0, ans);
        return ans;
    }
};

int main() {
    Solution sol;
    
    // Test Case 1: Basic permutation
    vector<int> nums1 = {1, 2, 3};
    cout << "Input: [1, 2, 3]" << endl;
    cout << "All Permutations:" << endl;
    vector<vector<int>> result1 = sol.permute(nums1);
    for (auto& perm : result1) {
        cout << "[";
        for (int i = 0; i < perm.size(); i++) {
            cout << perm[i];
            if (i < perm.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
    cout << "Total permutations: " << result1.size() << " (3! = 6)" << endl;
    
    // Test Case 2: Smaller array
    cout << "\nTest Case 2:" << endl;
    vector<int> nums2 = {5, 6};
    cout << "Input: [5, 6]" << endl;
    vector<vector<int>> result2 = sol.permute(nums2);
    cout << "Permutations: ";
    for (auto& perm : result2) {
        cout << "[" << perm[0] << "," << perm[1] << "] ";
    }
    cout << "\nTotal: " << result2.size() << " (2! = 2)" << endl;
    
    return 0;
}
