/*
 * Problem: 54. Spiral Matrix
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/spiral-matrix/
 * 
 * Return all elements of the matrix in spiral order (clockwise)
 * 
 * Algorithm: Layer by Layer Traversal
 * ===================
 * 1) Initialize boundaries: 
 *    - srow = 0 (starting row)
 *    - scol = 0 (starting column)
 *    - erow = m-1 (ending row)
 *    - ecol = n-1 (ending column)
 * 
 * 2) While condition: srow <= erow && scol <= ecol
 * 
 * 3) Four directions traversal in each layer:
 *    
 *    TOP: for(j = scol to ecol)
 *         mat[srow][j]
 *         srow++
 *    
 *    RIGHT: for(i = srow to erow)
 *           mat[i][ecol]
 *           ecol--
 *    
 *    BOTTOM: for(j = ecol to scol) - with single row check
 *            mat[erow][j]
 *            erow--
 *    
 *    LEFT: for(i = erow to srow) - with single column check
 *          mat[i][scol]
 *          scol++
 * 
 * 4) Corner case: Handle single row or single column with break conditions
 * 
 * Time Complexity: O(m * n) - visit each element once
 * Space Complexity: O(1) - excluding output array
 */

/*
 * Pseudocode (Spiral Order Traversal)
 * -----------------------------------
 *   function spiralOrder(mat):
 *       m = mat.size()
 *       n = mat[0].size()
 *       srow = 0
 *       scol = 0
 *       erow = m - 1
 *       ecol = n - 1
 *       ans = empty list
 *
 *       while srow <= erow and scol <= ecol:
 *           // top row
 *           for j from scol to ecol:
 *               append mat[srow][j] to ans
 *
 *           // right column
 *           for i from srow + 1 to erow:
 *               append mat[i][ecol] to ans
 *
 *           // bottom row (if more than one row)
 *           for j from ecol - 1 down to scol:
 *               if srow == erow:
 *                   break
 *               append mat[erow][j] to ans
 *
 *           // left column (if more than one column)
 *           for i from erow - 1 down to srow + 1:
 *               if scol == ecol:
 *                   break
 *               append mat[i][scol] to ans
 *
 *           srow = srow + 1
 *           erow = erow - 1
 *           scol = scol + 1
 *           ecol = ecol - 1
 *
 *       return ans
 */

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        int srow = 0, scol = 0;
        int erow = m - 1, ecol = n - 1;

        vector<int> ans;

        while (srow <= erow && scol <= ecol) {

            // top
            for (int j = scol; j <= ecol; j++) {
                ans.push_back(mat[srow][j]);
            }

            // right
            for (int i = srow + 1; i <= erow; i++) {
                ans.push_back(mat[i][ecol]);
            }

            // bottom
            for (int j = ecol - 1; j >= scol; j--) {
                if (srow == erow) {
                    break;
                }
                ans.push_back(mat[erow][j]);
            }

            // left
            for (int i = erow - 1; i >= srow + 1; i--) {
                if (scol == ecol) {
                    break;
                }
                ans.push_back(mat[i][scol]);
            }

            srow++;
            erow--;
            scol++;
            ecol--;
        }

        return ans;
    }
};
