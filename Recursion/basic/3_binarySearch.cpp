/*
 * Problem: Binary Search using Recursion
 * 
 * Search for target element in sorted array using recursive binary search
 * Divides search space in half each iteration
 * 
 * Time Complexity: O(log n) - halves search space each step
 * Space Complexity: O(log n) - recursion call stack
 */

/*
 * Pseudocode: Recursive Binary Search
 *
 * function binSearch(arr, target, st, end):
 *     // base case: search space exhausted
 *     if st > end:
 *         return -1
 *
 *     mid = st + (end - st) / 2
 *
 *     // target found at mid
 *     if arr[mid] == target:
 *         return mid
 *
 *     // target lies in right half
 *     else if arr[mid] < target:
 *         return binSearch(arr, target, mid + 1, end)
 *
 *     // target lies in left half
 *     else:
 *         return binSearch(arr, target, st, mid - 1)
 *
 * function search(arr, target):
 *     return binSearch(arr, target, 0, size(arr) - 1)
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Recursive helper function for binary search
    int binSearch(vector<int>& arr, int tar, int st, int end) {
        // Base case: search space exhausted
        if (st <= end) {
            int mid = st + (end - st) / 2;  // Prevent overflow

            // Target found at middle
            if (arr[mid] == tar) {
                return mid;
            }
            // Target in right half
            else if (arr[mid] < tar) {
                return binSearch(arr, tar, mid + 1, end);
            }
            // Target in left half
            else {
                return binSearch(arr, tar, st, mid - 1);
            }
        }
        return -1;  // Target not found
    }

    // Main search function
    int search(vector<int>& arr, int tar) {
        return binSearch(arr, tar, 0, arr.size() - 1);
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 3, 5, 7, 9, 11, 13};
    int target = 7;
    
    int result = sol.search(arr, target);
    if(result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found" << endl;
    }
    
    return 0;
}
