/*
 * Problem: Print All Subsets (Power Set)
 * Technique: Backtracking / Recursion
 * 
 * Generate and print all possible subsets of a given array
 * Uses include/exclude pattern with backtracking
 * 
 * Time Complexity: O(2^n) - where n is array size (2 choices for each element)
 * Space Complexity: O(n) - recursion call stack depth
 */

#include <iostream>
#include <vector>
using namespace std;

// Recursive function to print all subsets using backtracking
void printSubsets(vector<int>& arr, vector<int>& ans, int i) {
    // Base case: reached end of array, print current subset
    if (i == arr.size()) {
        for (int val : ans) {
            cout << val << " ";
        }
        cout << endl;
        return;
    }   

    // Include current element in subset (make choice)
    ans.push_back(arr[i]);
    printSubsets(arr, ans, i + 1);

    // Backtrack: remove element to explore other possibilities
    ans.pop_back();

    // Exclude current element from subset (undo choice)
    printSubsets(arr, ans, i + 1);
}

int main() {
    vector<int> arr = {1, 2, 3};
    vector<int> ans; // Store current subset being built

    printSubsets(arr, ans, 0);
    // Output: All 2^3 = 8 subsets including empty set
    return 0;
}


// leetcode problem: 78:  same time complexity same logic but returning same array insted of printing it 
class Solution {
public:
    void getAllSubsets(
        vector<int>& nums,
        vector<int>& ans,
        int i,
        vector<vector<int>>& allSubsets
    ) {
        if (i == nums.size()) {
            allSubsets.push_back(ans);
            return;
        }

        // include
        ans.push_back(nums[i]);
        getAllSubsets(nums, ans, i + 1, allSubsets);

        ans.pop_back();  // this is the most important step for backtracking

        // exclude
        getAllSubsets(nums, ans, i + 1, allSubsets);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> allSubsets;
        vector<int> ans;

        getAllSubsets(nums, ans, 0, allSubsets);
        return allSubsets;
    }
};
