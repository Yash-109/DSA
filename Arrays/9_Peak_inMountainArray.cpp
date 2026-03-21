/*
 * LeetCode Problem: 852. Peak Index in a Mountain Array
 * Problem Link: https://leetcode.com/problems/peak-index-in-a-mountain-array/
 * 
 * Time Complexity: O(log n) - Binary search to find peak element
 * Space Complexity: O(1) - Only using constant extra space
 */

/*
 * Approach (Binary Search on Mountain Array)
 * -----------------------------------------
 * - In a mountain array, values strictly increase then strictly decrease.
 * - Peak is the index mid such that A[mid-1] < A[mid] > A[mid+1].
 * - Use binary search between 1 and n-2:
 *     * If A[mid-1] < A[mid] and A[mid] > A[mid+1], return mid (found peak).
 *     * Else if A[mid-1] < A[mid], we are on the increasing slope, so the
 *       peak lies to the right -> move st = mid + 1.
 *     * Otherwise we are on the decreasing slope -> move end = mid - 1.
 *
 * Pseudocode
 * ---------
 *   function peakIndexInMountainArray(A):
 *       st = 1
 *       end = A.size() - 2
 *
 *       while st <= end:
 *           mid = st + (end - st) / 2
 *
 *           if A[mid-1] < A[mid] and A[mid] > A[mid+1]:
 *               return mid
 *
 *           if A[mid-1] < A[mid]:      // increasing side
 *               st = mid + 1
 *           else:                      // decreasing side
 *               end = mid - 1
 *
 *       return -1
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int st=1, end=A.size()-2;
        while(st<=end)
        {
            int mid = st + (end-st)/2;

            if(A[mid-1]<A[mid] && A[mid]>A[mid+1])
            {
                return mid;
            }

            if(A[mid-1]<A[mid])  // mid is in increasing side so peak must be in right part
            {
                st = mid+1;
            }
            else // peak in left part
            {
                end = mid-1;
            }
        }
        return -1;
    }
};