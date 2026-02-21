/*
 * Problem: Knight's Tour
 * LeetCode: 2596 (Check Knight Tour Configuration)
 * Technique: Recursion with Validation
 * 
 * Validate if a given grid represents a valid knight's tour.
 * Knight moves in L-shape: (±2, ±1) and (±1, ±2) combinations
 * 
 * Time Complexity: O(8^(n²)) - we have n² cells and for each cell we have 8 choices
 * Space Complexity: O(n²) - recursion call stack
 * 
 * Logic:
 * 1. Start from (0,0), check if it has expected value (0)
 * 2. Try all 8 possible knight moves from current position
 * 3. Check if next cell has expected value (expVal + 1)
 * 4. If last cell (n²-1) is reached with valid sequence: return true
 * 5. Otherwise return false
 * 
 * References:
 * - Similar pattern to Rat in Maze (trying multiple directions)
 * - Similar to N-Queens (constraint checking at each step)
 * - Unlike Count Inversion (which uses divide-conquer), this uses pure recursion
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isValid(vector<vector<int>>& grid, int r, int c, int n, int expVal) {
        // boundary + expected value check
        if (r < 0 || c < 0 || r >= n || c >= n || grid[r][c] != expVal) {
            return false;
        }

        // all cells visited successfully
        if (expVal == n * n - 1) {
            return true;
        }

        // 8 possible knight moves
        int ans1 = isValid(grid, r - 2, c + 1, n, expVal + 1);
        int ans2 = isValid(grid, r - 1, c + 2, n, expVal + 1);
        int ans3 = isValid(grid, r + 1, c + 2, n, expVal + 1);
        int ans4 = isValid(grid, r + 2, c + 1, n, expVal + 1);
        int ans5 = isValid(grid, r + 2, c - 1, n, expVal + 1);
        int ans6 = isValid(grid, r + 1, c - 2, n, expVal + 1);
        int ans7 = isValid(grid, r - 1, c - 2, n, expVal + 1);
        int ans8 = isValid(grid, r - 2, c - 1, n, expVal + 1);

        return ans1 || ans2 || ans3 || ans4 || ans5 || ans6 || ans7 || ans8;
    }

    bool checkValidGrid(vector<vector<int>>& grid) {
        return isValid(grid, 0, 0, grid.size(), 0);
    }
};

// Time Complexity: O(8^(n²)) - we have n² cells and for each cell we have 8 choices
// Space Complexity: O(n²) - recursion call stack