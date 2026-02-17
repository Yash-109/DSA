/*
 * Problem: Combination Sum (Elements can be reused)
 * LeetCode: 39
 * Technique: Backtracking with Repetition Allowed
 * 
 * Find all unique combinations where candidate numbers sum to target
 * Same number may be chosen unlimited times from candidates
 * 
 * Time Complexity: O(2^t) - where t is target value
 * Space Complexity: O(t) - recursion depth and combination storage
 * 
 * Logic:
 * 1. At each index, we have two choices:
 *    a) Include current element (stay at same index - can reuse)
 *    b) Exclude current element (move to next index)
 * 2. Base case: target becomes 0 (found valid combination)
 * 3. Backtrack when target becomes negative or index exceeds array
 * 
 * Key Pattern: Include (same idx) -> Backtrack -> Exclude (next idx)
 * Difference from Subsets: Elements can be reused (idx stays same on include)
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    void solve(vector<int>& arr, int idx, int tar,
               vector<int>& combin,
               vector<vector<int>>& ans) {
        
        if (tar == 0) {
            ans.push_back(combin);
            return;
        }
        
        if (idx == arr.size() || tar < 0) {
            return;
        }

        // include (can reuse same index)
        combin.push_back(arr[idx]);
        solve(arr, idx, tar - arr[idx], combin, ans);
        combin.pop_back();

        // exclude
        solve(arr, idx + 1, tar, combin, ans);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& arr, int tar) {
        vector<vector<int>> ans;
        vector<int> combin;
        solve(arr, 0, tar, combin, ans);
        return ans;
    }
    
};

int main() {
    Solution sol;
    
    // Test Case 1: Basic combination sum
    vector<int> candidates1 = {2, 3, 6, 7};
    int target1 = 7;
    cout << "Input: candidates = [2, 3, 6, 7], target = " << target1 << endl;
    cout << "All Combinations that sum to " << target1 << ":" << endl;
    vector<vector<int>> result1 = sol.combinationSum(candidates1, target1);
    for (auto& combo : result1) {
        cout << "[";
        for (int i = 0; i < combo.size(); i++) {
            cout << combo[i];
            if (i < combo.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
    cout << "Total combinations: " << result1.size() << endl;
    // Expected: [[2,2,3], [7]]
    
    // Test Case 2: Multiple same elements
    cout << "\nTest Case 2:" << endl;
    vector<int> candidates2 = {2, 3, 5};
    int target2 = 8;
    cout << "Input: candidates = [2, 3, 5], target = " << target2 << endl;
    cout << "Combinations:" << endl;
    vector<vector<int>> result2 = sol.combinationSum(candidates2, target2);
    for (auto& combo : result2) {
        cout << "[";
        for (int i = 0; i < combo.size(); i++) {
            cout << combo[i];
            if (i < combo.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
    cout << "Total: " << result2.size() << endl;
    // Expected: [[2,2,2,2], [2,3,3], [3,5]]
    
    return 0;
}
