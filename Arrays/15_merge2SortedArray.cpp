/*
 * Problem: 88. Merge Sorted Array
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/merge-sorted-array/
 * 
 * Merge two sorted arrays in-place (merge B into A)
 * Uses three-pointer approach starting from the end
 * Time Complexity: O(m+n)
 * Space Complexity: O(1)
 */

#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {  
        int indx = m+n-1, i=m-1, j=n-1;
        while(i>=0 && j>=0)
        {
            if(A[i]>=B[j])
            {
                A[indx--]=A[i--];
            }

            else{
                A[indx--] = B[j--];
            }
        }

        while(j>=0)
        {
            A[indx--] = B[j--];
        }
    }
};