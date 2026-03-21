

// Most imp is target exist in only non - overlaping (unique) row
/*

 * Problem: 74. Search a 2D Matrix
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/search-a-2d-matrix/
 * 
 * Search for a target value in an m x n matrix with sorted rows and columns
 * 
 * Algorithm:
 * 1. Search correct row using binary search
 *    - if target is mat[midRow][0] <= target <= mat[midRow][n-1] means we found the row
 *    - else if target > mat[midRow][n-1] then startRow = mid+1
 *    - else if target < mat[midRow][0] then endRow = mid-1
 * 
 * 2. Apply binary search on columns to find element
 */

/*
 * Pseudocode (Row + Column Binary Search)
 * --------------------------------------
 *   function searchMatrix(mat, target):
 *       m = mat.size()
 *       n = mat[0].size()
 *       startRow = 0
 *       endRow = m - 1
 *
 *       // step 1: find row where target may lie
 *       while startRow <= endRow:
 *           midRow = startRow + (endRow - startRow) / 2
 *
 *           if mat[midRow][0] <= target <= mat[midRow][n-1]:
 *               // step 2: binary search within this row
 *               return binarySearchRow(mat, target, midRow)
 *           else if target > mat[midRow][n-1]:
 *               startRow = midRow + 1
 *           else:
 *               endRow = midRow - 1
 *
 *       return false
 *
 *   function binarySearchRow(mat, target, row):
 *       st = 0
 *       end = number_of_columns - 1
 *
 *       while st <= end:
 *           mid = st + (end - st) / 2
 *           if mat[row][mid] == target:
 *               return true
 *           else if mat[row][mid] < target:
 *               st = mid + 1
 *           else:
 *               end = mid - 1
 *
 *       return false
 */

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    // Helper function: Binary search within a specific row
    // Time Complexity: O(log n) where n is number of columns
    bool searchInRow(vector<vector<int>>& mat, int target, int row)
    {
        int n = mat[0].size();
        int st = 0, end = n-1;
        
        while(st <= end)
        {
            int mid = st + (end-st)/2;
            
            if(target == mat[row][mid])
            {
                return true;
            }
            else if(target > mat[row][mid])
            {
                st = mid+1;
            }
            else
            {
                end = mid-1;
            }
        }
        return false;
    }
    
    // Main function: Search in 2D matrix
    // Time Complexity: O(log m + log n), Space Complexity: O(1)
    bool searchMatrix(vector<vector<int>>& mat, int target) 
    {
        // Binary search on total number of rows
        int m = mat.size(), n = mat[0].size();
        int startRow = 0, endRow = m-1; 
        
        while(startRow <= endRow)
        {
            int midRow = startRow + (endRow-startRow)/2;

            if(target >= mat[midRow][0] && target <= mat[midRow][n-1])
            {
                // Found the row, now search in this row
                return searchInRow(mat, target, midRow);
            }
            else if(target > mat[midRow][n-1])
            {
                // Go down (right in row search)
                startRow = midRow+1;
            }
            else
            {
                // Go up (left in row search)
                endRow = midRow-1;
            }
        }
        return false;
    }
};