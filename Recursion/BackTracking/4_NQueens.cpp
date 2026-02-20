/*
 * Problem: N-Queens
 * LeetCode: 51
 * Technique: Backtracking with Constraint Checking
 * 
 * Place N queens on an N×N chessboard such that no two queens attack each other
 * Queens attack horizontally, vertically, and diagonally
 * 
 * Time Complexity: O(n!) - exploring valid queen placements 
 * Space Complexity: O(n²) - board storage + O(n) recursion depth
 * 
 * Logic:
 * 1. Place queens row by row (one queen per row)
 * 2. For each column in current row, check if it's safe
 * 3. If safe: place queen, recurse to next row
 * 4. After recursion: backtrack by removing queen
 * 5. A position is safe if no queen in same column, row, or diagonals
 * 
 * Key Insight: By placing one queen per row, we don't need to check
 * rows above (they're already filled) or rows below (not filled yet)
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:

// Check if placing queen at (row, col) is safe
bool isSafe(vector<string> &board, int row, int col, int n){
    // Check horizontal (same row)
    for(int j = 0; j < n; j++){  
        if(board[row][j] == 'Q'){  // Row fixed, check all columns
            return false;
        }
    }

    // Check vertical (same column)
    for(int i = 0; i < n; i++){
        if(board[i][col] == 'Q'){ // Column fixed, check all rows
            return false; 
        }
    }

    // Check left diagonal (↖ direction)
    for(int i = row, j = col; i >= 0 && j >= 0; i--, j--){
        if(board[i][j] == 'Q') {
            return false;
        }
    }

    // Check right diagonal (↗ direction)
    for(int i = row, j = col; i >= 0 && j < n; i--, j++){
        if(board[i][j] == 'Q') {
            return false;
        }
    }

    return true;  // Safe to place queen
}
// Recursive function to place queens row by row
void nQueens(vector<string> &board, int row, int n, vector<vector<string>> &ans){
    // Base case: All queens placed successfully
    if(row == n){
        ans.push_back(board);
        return;
    }

    // Try placing queen in each column of current row
    for(int j = 0; j < n; j++){
        if(isSafe(board, row, j, n)) {
            board[row][j] = 'Q';           // Make choice: place queen
            nQueens(board, row + 1, n, ans);  // Recurse to next row
            board[row][j] = '.';           // Backtrack: remove queen
        }
    }
}
    vector<vector<string>> solveNQueens(int n) {
        // Initialize board: n rows, each row is a string of n dots
        // Example for n=4: ["..", "..", "..", ".."]
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> ans;

        nQueens(board, 0, n, ans);
        return ans;
    }
};

int main() {
    Solution sol;
    
    // Test Case 1: 4-Queens
    cout << "N-Queens Problem (n = 4)" << endl;
    cout << "=======================" << endl;
    vector<vector<string>> result1 = sol.solveNQueens(4);
    cout << "Total solutions: " << result1.size() << endl << endl;
    
    for(int i = 0; i < result1.size(); i++) {
        cout << "Solution " << (i + 1) << ":" << endl;
        for(const string& row : result1[i]) {
            cout << row << endl;
        }
        cout << endl;
    }
    
    // Test Case 2: 8-Queens (Classic problem)
    cout << "\nN-Queens Problem (n = 8)" << endl;
    cout << "======================" << endl;
    vector<vector<string>> result2 = sol.solveNQueens(8);
    cout << "Total solutions: " << result2.size() << endl;
    
    // Test Case 3: Edge case
    cout << "\nN-Queens Problem (n = 1)" << endl;
    vector<vector<string>> result3 = sol.solveNQueens(1);
    cout << "Total solutions: " << result3.size() << endl;
    if(!result3.empty()) {
        cout << "Solution: " << result3[0][0] << endl;
    }
    
    return 0;
}