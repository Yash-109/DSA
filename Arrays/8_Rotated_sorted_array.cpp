/*
 * LeetCode Problem: 33. Search in Rotated Sorted Array
 * Problem Link: https://leetcode.com/problems/search-in-rotated-sorted-array/
 * 
 * Time Complexity: O(log n) - Binary search on rotated sorted array
 * Space Complexity: O(1) - Only using constant extra space
 */

/*
 * Approach (Modified Binary Search)
 * ---------------------------------
 * - The array is sorted then rotated; at any mid, at least one side
 *   [st..mid] or [mid..end] is sorted.
 * - Standard steps:
 *   1) Compute mid; if A[mid] == target, return mid.
 *   2) Check which half is sorted:
 *        - If A[st] <= A[mid], left half is sorted.
 *            * If target lies in [A[st], A[mid]], move end = mid - 1.
 *            * Else move st = mid + 1.
 *        - Else right half is sorted.
 *            * If target lies in [A[mid], A[end]], move st = mid + 1.
 *            * Else move end = mid - 1.
 * - Repeat until st > end; if not found, return -1.
 *
 * Pseudocode
 * ---------
 *   function search(A, target):
 *       st = 0
 *       end = A.size() - 1
 *
 *       while st <= end:
 *           mid = st + (end - st) / 2
 *
 *           if A[mid] == target:
 *               return mid
 *
 *           if A[st] <= A[mid]:      // left part sorted
 *               if A[st] <= target and target <= A[mid]:
 *                   end = mid - 1
 *               else:
 *                   st = mid + 1
 *           else:                    // right part sorted
 *               if A[mid] <= target and target <= A[end]:
 *                   st = mid + 1
 *               else:
 *                   end = mid - 1
 *
 *       return -1
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& A, int target) {
        int st=0, end=A.size()-1;
        while(st<=end)
        {
            int mid = st + (end-st)/2;
            if(A[mid]==target)
            {
                return mid;
            }

            if(A[st]<=A[mid])  // Check if left part is sorted
            {
                if(A[st] <= target && target <= A[mid]) // move left
                {
                    end = mid-1;
                }
                else // move right
                {
                    st = mid+1;
                }
            }

            else // check if right part is sorted
            {
                if(A[mid] <= target && target <= A[end]) // move right
                {
                    st= mid+1;
                }
                else  // move left
                {
                    end = mid-1;
                }
            }
        }
        return -1;
    }

};