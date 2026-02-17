/*
 * Problem: Palindrome Partitioning
 * LeetCode: 131
 * Technique: Backtracking with String Partitioning
 * 
 * Partition a string such that every substring is a palindrome
 * Return all possible palindrome partitioning combinations
 * 
 * Time Complexity: O(n * 2^n) - 2^n partitions, n for palindrome check
 * Space Complexity: O(n) - recursion depth + partition storage
 * 
 * Logic (from diagram for s = "aab"):
 * 1. Start with full string, try creating partitions at each position
 * 2. For each prefix substring (0 to i+1):
 *    - Check if it's a palindrome
 *    - If yes: add to current partition, recurse with remaining string
 *    - Backtrack: remove from partition to try other combinations
 * 3. Base case (BC): when string becomes empty, save current partition
 * 
 * Example: "aab"
 *   Path 1: [a] -> [a,a] -> [a,a,b] ✓
 *   Path 2: [aa] -> [aa,b] ✓
 * 
 * Key Pattern: Try all prefixes -> Recurse with suffix -> Backtrack
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Helper: Check if a string is palindrome
    bool isPalin(string s) {
        string s2 = s;
        reverse(s2.begin(), s2.end());
        return s == s2;
    }

    // Recursive backtracking to find all palindrome partitions
    void getAllParts(string s, vector<string> &partitions, vector<vector<string>> &ans) {
        // Base case: empty string means we've successfully partitioned
        if (s.size() == 0) {
            ans.push_back(partitions);
            return;
        }

        // Try all possible prefixes as first partition
        for (int i = 0; i < s.size(); i++) {
            string part = s.substr(0, i + 1);  // Get prefix from 0 to i

            // Only proceed if current prefix is a palindrome
            if (isPalin(part)) {
                partitions.push_back(part);  // Make choice: add palindrome
                getAllParts(s.substr(i + 1), partitions, ans);  // Recurse with remaining suffix
                partitions.pop_back();  // Backtrack: remove to try other partitions
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> partitions;

        getAllParts(s, partitions, ans);
        return ans;
    }
};

int main() {
    Solution sol;
    
    // Test Case 1: Example from diagram (aab)
    string s1 = "aab";
    cout << "Input: s = \"" << s1 << "\"" << endl;
    cout << "All Palindrome Partitions:" << endl;
    vector<vector<string>> result1 = sol.partition(s1);
    for (auto& partition : result1) {
        cout << "[";
        for (int i = 0; i < partition.size(); i++) {
            cout << "\"" << partition[i] << "\"";
            if (i < partition.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
    cout << "Total partitions: " << result1.size() << endl;
    // Expected: [["a","a","b"], ["aa","b"]]
    
    // Test Case 2: Single character palindrome
    cout << "\nTest Case 2:" << endl;
    string s2 = "a";
    cout << "Input: s = \"" << s2 << "\"" << endl;
    vector<vector<string>> result2 = sol.partition(s2);
    cout << "Output: [[\"a\"]]" << endl;
    
    // Test Case 3: All palindromes
    cout << "\nTest Case 3:" << endl;
    string s3 = "aba";
    cout << "Input: s = \"" << s3 << "\"" << endl;
    cout << "Palindrome Partitions:" << endl;
    vector<vector<string>> result3 = sol.partition(s3);
    for (auto& partition : result3) {
        cout << "[";
        for (int i = 0; i < partition.size(); i++) {
            cout << "\"" << partition[i] << "\"";
            if (i < partition.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
    // Expected: [["a","b","a"], ["aba"]]
    
    return 0;
}
