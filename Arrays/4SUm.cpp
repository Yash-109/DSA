/*
 * Problem: 18. 4Sum
 * Difficulty: Medium
 *
 * Given an integer array nums and an integer target, return all unique
 * quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
 *   - a, b, c, and d are distinct indices,
 *   - nums[a] + nums[b] + nums[c] + nums[d] == target.
 *
 * The answer must not contain duplicate quadruplets.
 *
 * Approach used here (similar style to 3Sum optimal):
 *   - Sort the array.
 *   - Fix two indices i and j, then use two pointers p and q to find pairs
 *     that complete the quadruplet.
 *   - Carefully skip duplicates for i, j, p, and q to avoid duplicate
 *     quadruplets in the answer.
 *
 * Time Complexity:  O(n^3)
 * Space Complexity: O(1) extra (ignoring output)
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Utility function to print 2D vector of quadruplets
void printQuadruplets(const vector<vector<int>>& quads) {
    cout << "[";
    for (size_t i = 0; i < quads.size(); i++) {
        cout << "[" << quads[i][0] << ", " << quads[i][1]
             << ", " << quads[i][2] << ", " << quads[i][3] << "]";
        if (i + 1 < quads.size()) cout << ", ";
    }
    cout << "]" << endl;
}

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();
        if (n < 4) return ans;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; i++) {
            // Skip duplicate first elements
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            for (int j = i + 1; j < n - 2; j++) {
                // Skip duplicate second elements for this i
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                int p = j + 1, q = n - 1;

                while (p < q) {
                    long long sum =
                        (long long)nums[i] +
                        (long long)nums[j] +
                        (long long)nums[p] +
                        (long long)nums[q];

                    if (sum < (long long)target) {
                        p++;
                    } else if (sum > (long long)target) {
                        q--;
                    } else {
                        ans.push_back({nums[i], nums[j], nums[p], nums[q]});
                        p++;
                        q--;

                        // Skip duplicate third elements
                        while (p < q && nums[p] == nums[p - 1]) p++;
                        // Skip duplicate fourth elements
                        while (p < q && nums[q] == nums[q + 1]) q--;
                    }
                }
            }
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;

    Solution sol;
    vector<vector<int>> res = sol.fourSum(nums, target);

    cout << "Input:  [1, 0, -1, 0, -2, 2], target = 0" << endl;
    cout << "Output: ";
    printQuadruplets(res);

    return 0;
}