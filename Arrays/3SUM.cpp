/*
 * Problem: 15. 3Sum
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/3sum/
 * 
 * Given an integer array nums, return all the unique triplets [nums[i], nums[j], nums[k]]
 * such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
 *
 * The answer must not contain duplicate triplets.
 *
 * Approaches:
 * 1. Brute Force + set (O(n^3 * logU), O(U))
 * 2. Better: Two-sum with set for each i (O(n^2 * logU), O(U + n))
 * 3. Optimal: Sort + two pointers without extra set (O(n^2), O(1) extra)
 */

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

// Utility function to print 2D vector of triplets
void printTriplets(const vector<vector<int>>& triplets) {
    cout << "[";
    for (size_t i = 0; i < triplets.size(); i++) {
        cout << "[" << triplets[i][0] << ", " << triplets[i][1] << ", " << triplets[i][2] << "]";
        if (i + 1 < triplets.size()) cout << ", ";
    }
    cout << "]" << endl;
}

// Approach 1: Brute Force + set
// Time Complexity: O(n^3 * log U) where U = number of unique triplets
// Space Complexity: O(U)
class Solution1 {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        set<vector<int>> s; // to store unique sorted triplets

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        vector<int> trip = {nums[i], nums[j], nums[k]};
                        sort(trip.begin(), trip.end());

                        if (s.find(trip) == s.end()) {
                            s.insert(trip);
                            ans.push_back(trip);
                        }
                    }
                }
            }
        }
        return ans;
    }
};

// Approach 2: Better (Hashing + set of triplets)
// Fix one element, then use a set to find pairs that sum to -nums[i]
// Time Complexity: O(n^2 * log U)
// Space Complexity: O(U + n)
class Solution2 {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> uniqueTriplets;

        for (int i = 0; i < n; i++) {
            int target = -nums[i];
            set<int> s; // stores elements seen for this i

            for (int j = i + 1; j < n; j++) {
                int third = target - nums[j];

                if (s.find(third) != s.end()) {
                    vector<int> trip = {nums[i], nums[j], third};
                    sort(trip.begin(), trip.end());
                    uniqueTriplets.insert(trip);
                }

                s.insert(nums[j]);
            }
        }

        vector<vector<int>> ans(uniqueTriplets.begin(), uniqueTriplets.end());
        return ans;
    }
};

// Approach 3: Optimal (Sorting + Two Pointers)
// Time Complexity: O(n^2)
// Space Complexity: O(1) extra (answer not counted)
class Solution3 {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {
            // Skip duplicate first elements to avoid duplicate triplets
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int j = i + 1, k = n - 1;

            while (j < k) {
                long long sum = (long long)nums[i] + nums[j] + nums[k];

                if (sum < 0) {
                    j++;
                } else if (sum > 0) {
                    k--;
                } else {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;

                    // Skip duplicate second elements
                    while (j < k && nums[j] == nums[j - 1]) j++;
                    // Skip duplicate third elements
                    while (j < k && nums[k] == nums[k + 1]) k--;
                }
            }
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};

    cout << "Input: [-1, 0, 1, 2, -1, -4]\n";

    // Brute Force
    Solution1 sol1;
    cout << "Brute Force:        ";
    printTriplets(sol1.threeSum(nums));

    // Better
    Solution2 sol2;
    cout << "Better (Hashing):   ";
    printTriplets(sol2.threeSum(nums));

    // Optimal
    Solution3 sol3;
    cout << "Optimal (2-ptr):    ";
    printTriplets(sol3.threeSum(nums));

    return 0;
}
