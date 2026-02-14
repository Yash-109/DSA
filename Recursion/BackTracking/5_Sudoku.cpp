/*
 * Problem: Sudoku Solver
 * LeetCode: 37
 * Technique: Backtracking with Constraint Checking
 * 
 * Fill a 9x9 Sudoku board following these rules:
 * - Each row must contain digits 1-9 without repetition
 * - Each column must contain digits 1-9 without repetition
 * - Each 3x3 sub-box must contain digits 1-9 without repetition
 * 
 * Time Complexity: O(9^m) where m = number of empty cells (worst case 9^81)
 * Space Complexity: O(1) for board (given) + O(m) recursion depth
 * 
 * Logic:
 * 1. Traverse board cell by cell (row by row, column by column)
 * 2. For empty cells (marked with '.'), try digits 1-9
 * 3. Check if digit is safe (not in same row, column, or 3x3 box)
 * 4. If safe: place digit, recurse to next cell
 * 5. If recursion succeeds, return true; else backtrack
 * 6. If no digit works, return false to trigger backtracking
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Check if placing digit at (row, col) is safe
    bool isSafe(vector<vector<char>>& board, int row, int col, char dig) {
        // Check row - digit should not exist in same row
        for (int j = 0; j < 9; j++) {
            if (board[row][j] == dig) {
                return false;
            }
        }

        // Check column - digit should not exist in same column
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == dig) {
                return false;
            }
        }

        // Check 3x3 grid - digit should not exist in current 3x3 box
        int srow = (row / 3) * 3;  // Starting row of 3x3 box
        int scol = (col / 3) * 3;  // Starting column of 3x3 box

        for (int i = srow; i < srow + 3; i++) {
            for (int j = scol; j < scol + 3; j++) {
                if (board[i][j] == dig) {
                    return false;
                }
            }
        }

        return true;  // Safe to place digit
    }

    // Recursive helper function to solve sudoku
    bool helper(vector<vector<char>>& board, int row, int col) {
        // Base case: All rows processed, sudoku solved
        if (row == 9) {
            return true;
        }

        // Calculate next cell position
        int nextRow = row;
        int nextCol = col + 1;
        if (nextCol == 9) {  // Move to next row
            nextRow = row + 1;
            nextCol = 0;
        }

        // If current cell is already filled, move to next cell
        if (board[row][col] != '.') {
            return helper(board, nextRow, nextCol);
        }

        // Try placing digits 1-9 in empty cell
        for (char dig = '1'; dig <= '9'; dig++) {
            if (isSafe(board, row, col, dig)) {
                board[row][col] = dig;  // Make choice: place digit
                if (helper(board, nextRow, nextCol)) {  // Recurse to next cell
                    return true;  // Solution found
                }
                board[row][col] = '.';  // Backtrack: remove digit
            }
        }

        return false;  // No valid digit found, trigger backtracking
    }

    void solveSudoku(vector<vector<char>>& board) {
        helper(board, 0, 0);
    }
};

// Helper function to print sudoku board
void printBoard(vector<vector<char>>& board) {
    for (int i = 0; i < 9; i++) {
        if (i % 3 == 0 && i != 0) {
            cout << "------+-------+------" << endl;
        }
        for (int j = 0; j < 9; j++) {
            if (j % 3 == 0 && j != 0) {
                cout << "| ";
            }
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    Solution sol;
    
    // Test Case 1: Classic Sudoku Puzzle
    cout << "Sudoku Solver" << endl;
    cout << "=============" << endl << endl;
    
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    
    cout << "Original Puzzle:" << endl;
    printBoard(board);
    
    cout << "\nSolving..." << endl << endl;
    sol.solveSudoku(board);
    
    cout << "Solved Puzzle:" << endl;
    printBoard(board);
    
    return 0;
}


