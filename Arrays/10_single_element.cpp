/*
 * LeetCode Problem: 540. Single Element in a Sorted Array
 * Problem Link: https://leetcode.com/problems/single-element-in-a-sorted-array/
 * 
 * Time Complexity: O(log n) - Binary search on sorted array
 * Space Complexity: O(1) - Only using constant extra space
 */

/*
 * Approach (Binary Search on Index Parity)
 * ---------------------------------------
 * - In the sorted array, every element except one appears exactly twice.
 *   Pairs are adjacent: [..., x, x, y, y, z, ...].
 * - Before the single element, pairs start at even indices (0,2,4,...).
 *   After the single element, pairs start at odd indices (1,3,5,...).
 * - Use binary search to find the index where this pairing pattern breaks.
 *   - Handle edge cases: if first or last element is unique, return it.
 *   - For a mid index that is not at the boundaries:
 *       - If A[mid] is different from both neighbors, it is the answer.
 *       - Otherwise, use mid parity to decide which half to keep:
 *           * If mid is even:
 *               - If A[mid] == A[mid-1], single element is on the left.
 *               - Else, it is on the right.
 *           * If mid is odd:
 *               - If A[mid] == A[mid-1], single element is on the right.
 *               - Else, it is on the left.
 * - Shrink the search space accordingly until the unique element is found.
 *
 * Pseudocode
 * ---------
 *   function singleNonDuplicate(A):
 *       n = A.size()
 *       if n == 1:
 *           return A[0]
 *
 *       st = 0
 *       end = n - 1
 *
 *       while st <= end:
 *           mid = st + (end - st) / 2
 *
 *           if mid == 0 and A[0] != A[1]:
 *               return A[0]
 *           if mid == n-1 and A[n-1] != A[n-2]:
 *               return A[n-1]
 *
 *           if A[mid-1] != A[mid] and A[mid] != A[mid+1]:
 *               return A[mid]
 *
 *           if mid % 2 == 0:      // mid even
 *               if A[mid] == A[mid-1]:
 *                   end = mid - 1   // unique in left half
 *               else:
 *                   st = mid + 1    // unique in right half
 *           else:                  // mid odd
 *               if A[mid] == A[mid-1]:
 *                   st = mid + 1    // unique in right half
 *               else:
 *                   end = mid - 1   // unique in left half
 *
 *       return -1   // should not reach here if input is valid
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& A) {
        int n = A.size();
        if(n==1){ return A[0];} // if array size is only 1
        int st=0, end=n-1;
        
        while(st<=end)
        {
            int mid = st + (end-st)/2;
            if(mid == 0 && A[0]!=A[1])  // if first element is unique
            {
                return A[0];    
            }
            if(mid == n-1 && A[n-1]!= A[n-2]) // if last element is unique
            {
                return A[n-1];
            }

            if(A[mid-1] != A[mid] && A[mid] != A[mid+1])
            {
                return A[mid];
            }
            if(mid%2==0) // mid is even means left and right part also even
            {
                if(A[mid]==A[mid-1]) // unique element in left part
                {
                    end = mid-1;
                }
                else // unique element in right part
                {
                    st = mid+1;
                }
            }

            else // mid is odd means left and right part also odd
            {
                if(A[mid]==A[mid-1]) // unique element in right part
                {
                    st = mid+1;
                }
                else // unique element in left part
                {
                    end = mid-1;
                }
            }
        }

        return -1;
        
    }
};