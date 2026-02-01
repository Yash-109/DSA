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