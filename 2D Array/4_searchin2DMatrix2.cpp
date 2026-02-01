// here the difference from previous question is rows are overlapping
// means target can exist in any row

/*
 * Problem: 240. Search a 2D Matrix II
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/search-a-2d-matrix-ii/
 * 
 * Search for a target value in an m x n matrix where:
 * - Integers in each row are sorted in ascending order from left to right
 * - Integers in each column are sorted in ascending order from top to bottom
 * - Rows can overlap (target can exist in any row)
 * 
 * Algorithm:
 * We know that (0,0) is smallest value and (m-1,n-1) is largest value
 * Start from top-right corner (0, n-1):
 * - If target == current: found
 * - If target < current: move left (c--)
 * - If target > current: move down (r++)
 * 
 * COMPARISON WITH FILE 3 (searchIn2DMatrix):
 * File 3 Approach: Binary Search on rows + Binary Search on columns
 * - Time Complexity: O(log m + log n) ≈ O(log(m*n)) - MORE OPTIMIZED
 * - Works when rows are NON-OVERLAPPING (each row range is unique)
 * - Uses double binary search: first find row, then find element in row
 * 
 * File 4 Approach: Staircase Search
 * - Time Complexity: O(m + n) - LESS OPTIMIZED than file 3
 * - Required when rows are OVERLAPPING (target can exist in any row)
 * - Can't use double binary search because row ranges overlap
 * - Uses linear elimination from top-right corner
 * 
 * Note: File 3's O(log(m*n)) is more optimized than File 4's O(m+n)
 * But File 3's approach only works for non-overlapping row matrices!
 */

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    // Staircase Search Approach
    // Time Complexity: O(m + n), Space Complexity: O(1)
    bool searchMatrix(vector<vector<int>>& mat, int target) 
    {
        int m = mat.size(), n = mat[0].size();

        // Start from top-right corner
        int r = 0, c = n - 1;

        while (r < m && c >= 0) 
        {
            if (target == mat[r][c]) 
            {
                return true;
            } 
            else if (target < mat[r][c]) 
            {
                c--;        // Move left
            } 
            else 
            {
                r++;        // Move down
            }
        }
        return false;
    }
};