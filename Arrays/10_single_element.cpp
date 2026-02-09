/*
 * LeetCode Problem: 540. Single Element in a Sorted Array
 * Problem Link: https://leetcode.com/problems/single-element-in-a-sorted-array/
 * 
 * Time Complexity: O(log n) - Binary search on sorted array
 * Space Complexity: O(1) - Only using constant extra space
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