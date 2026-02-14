/*
 * Problem: Rat in a Maze
 * GeeksforGeeks Problem
 * Technique: Backtracking with Path Tracking
 * 
 * Find all possible paths for a rat to reach from top-left to bottom-right
 * in a maze. Rat can move in 4 directions: Down(D), Up(U), Left(L), Right(R)
 * 
 * Input: Matrix where 1 = path, 0 = blocked cell
 * Output: All possible paths as strings (e.g., "DDRR")
 * 
 * Time Complexity: O(4^N) where N = n×n (exponential with pruning via visited marking)
 * Space Complexity: O(N) - recursion stack depth
 * 
 * Logic:
 * 1. Start from (0,0), try moving in all 4 directions
 * 2. Mark current cell as visited (-1) to avoid revisiting
 * 3. Move to valid neighbor cells (within bounds, not blocked, not visited)
 * 4. When destination (n-1, n-1) is reached, store the path
 * 5. Backtrack by unmarking cell to explore other paths
 * 
 * Key Pattern: Mark visited -> Recurse 4 directions -> Unmark (backtrack)
 */

#include <iostream>
#include <vector>
using namespace std;

void helper(vector<vector<int>> &mat, int r, int c,
            string path, vector<string> &ans) {

    int n = mat.size();

    // Invalid cell: out of bounds, blocked (0), or already visited (-1)
    if (r < 0 || c < 0 || r >= n || c >= n || mat[r][c] == 0 || mat[r][c] == -1) {
        return;
    }

    // Destination reached: bottom-right corner
    if (r == n - 1 && c == n - 1) {
        ans.push_back(path);
        return;
    }

    // Mark current cell as visited
    mat[r][c] = -1;

    // Explore all 4 directions (D, U, L, R)
    helper(mat, r + 1, c, path + "D", ans); // Down
    helper(mat, r - 1, c, path + "U", ans); // Up
    helper(mat, r, c - 1, path + "L", ans); // Left
    helper(mat, r, c + 1, path + "R", ans); // Right

    // Backtrack: unmark cell for exploring other paths
    mat[r][c] = 1;
}

vector<string> findPath(vector<vector<int>> &mat) {
    int n = mat.size();
    vector<string> ans;

    // If starting cell is blocked, no path possible
    if (mat[0][0] == 0 || mat[n-1][n-1] == 0) {
        return ans;
    }

    helper(mat, 0, 0, "", ans);

    return ans;
}

int main() {
    // Test Case 1
    cout << "Rat in a Maze Problem" << endl;
    cout << "=====================" << endl << endl;
    
    vector<vector<int>> mat1 = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };

    cout << "Maze 1:" << endl;
    for (auto& row : mat1) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    vector<string> paths1 = findPath(mat1);
    cout << "\nPossible Paths: " << paths1.size() << endl;
    for (string path : paths1) {
        cout << path << endl;
    }

    // Test Case 2: Simple 2x2 maze
    cout << "\n\nMaze 2:" << endl;
    vector<vector<int>> mat2 = {
        {1, 1},
        {1, 1}
    };
    
    for (auto& row : mat2) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    vector<string> paths2 = findPath(mat2);
    cout << "\nPossible Paths: " << paths2.size() << endl;
    for (string path : paths2) {
        cout << path << endl;
    }

    return 0;
}
