/*
 * LeetCode Problem: 852. Peak Index in a Mountain Array
 * Problem Link: https://leetcode.com/problems/peak-index-in-a-mountain-array/
 * 
 * Time Complexity: O(log n) - Binary search to find peak element
 * Space Complexity: O(1) - Only using constant extra space
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