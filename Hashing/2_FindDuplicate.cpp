/*
 * Problem: 287. Find the Duplicate Number
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/find-the-duplicate-number/
 * 
 * Given an array of n+1 integers where each integer is in range [1, n]
 * There is only one repeated number, but it can repeat more than once
 * Find the duplicate number without modifying the array
 * 
 * Solutions:
 * 1. Hash Set Approach: O(n) time, O(n) space
 * 2. Floyd's Cycle Detection (Optimal): O(n) time, O(1) space
 */

#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

// Approach 1: Hash Set 
// Time Complexity: O(n), Space Complexity: O(n)
// Note: Simple but uses extra space
class Solution1 {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> s;

        for (int val : nums) {
            if (s.find(val) != s.end()) {
                return val;   // duplicate found
            }
            s.insert(val);
        }

        return -1; // should never happen as per problem constraints
    }
};

// Approach 2: Floyd's Cycle Detection (Tortoise and Hare)
// Time Complexity: O(n), Space Complexity: O(1)
// Optimal solution - treats array as linked list where arr[i] points to arr[arr[i]]
class Solution2 {
public:
    int findDuplicate(vector<int>& arr) {
        int slow = arr[0];
        int fast = arr[0];

        // Phase 1: Detect cycle using slow and fast pointers
        // Duplicate creates a cycle in the "linked list"
        do {
            slow = arr[slow];          // Move 1 step
            fast = arr[arr[fast]];     // Move 2 steps
        } while (slow != fast);

        // Phase 2: Find entrance of cycle (the duplicate number)
        // Reset slow to start, keep fast at meeting point
        slow = arr[0];
        while (slow != fast) {
            slow = arr[slow];          // Move 1 step
            fast = arr[fast];          // Move 1 step
        }

        return slow;  // Both pointers meet at the duplicate number
    }
};

int main()
{
    vector<int> nums = {1, 3, 4, 2, 2};
    
    // Test Hash Set approach
    Solution1 sol1;
    cout << "Hash Set Approach: " << sol1.findDuplicate(nums) << endl;
    
    // Test Floyd's Cycle Detection (Optimal)
    Solution2 sol2;
    cout << "Floyd's Algorithm: " << sol2.findDuplicate(nums) << endl;
    
    return 0;
}


