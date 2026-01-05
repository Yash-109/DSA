/*
 * LeetCode Problem: 33. Search in Rotated Sorted Array
 * Problem Link: https://leetcode.com/problems/search-in-rotated-sorted-array/
 * 
 * Time Complexity: O(log n) - Binary search on rotated sorted array
 * Space Complexity: O(1) - Only using constant extra space
 */

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