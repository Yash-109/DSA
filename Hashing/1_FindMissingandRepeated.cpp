/*
 * Problem: Find Missing and Repeated Values
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/find-missing-and-repeated-values/
 * 
 * Given an n x n integer grid, find:
 * - The repeated number (appears twice)
 * - The missing number (from 1 to n*n)
 * 
 * Approach: Use hash set to detect duplicate, then use sum formula
 * Time Complexity: O(n^2) - traverse all elements once
 * Space Complexity: O(n^2) - hash set storage
 */

#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> ans;
        unordered_set<int> s;
        int n = grid.size();
        int repeatedNum, missingNum;

        int expectedSum = 0, actualSum = 0; 

        // Traverse grid to find repeated number and calculate actual sum
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                actualSum += grid[i][j];

                // Check if current element already exists in set (duplicate found)
                if(s.find(grid[i][j]) != s.end())
                {
                    repeatedNum = grid[i][j];
                    ans.push_back(repeatedNum);  // First element is repeated number
                }
                s.insert(grid[i][j]);
            }
        }

        // Calculate expected sum using formula: sum = n * (n+1) / 2
        // For grid of size n x n, total elements = n*n, so sum = (n*n) * (n*n + 1) / 2
        expectedSum = (n * n) * ((n * n) + 1) / 2;
        
        // Missing number = expectedSum - (actualSum - repeatedNum)
        missingNum = expectedSum + repeatedNum - actualSum;
        ans.push_back(missingNum);  // Second element is missing number
        
        return ans;
    }
};

int main()
{
    Solution sol;
    
    // Test case: 3x3 grid with values 1-9, where 2 is repeated and 8 is missing
    vector<vector<int>> grid = {
        {1, 3, 2},
        {2, 4, 6},
        {5, 7, 9}
    };
    
    vector<int> result = sol.findMissingAndRepeatedValues(grid);
    
    cout << "Repeated number: " << result[0] << endl;
    cout << "Missing number: " << result[1] << endl;
    
    return 0;
} 