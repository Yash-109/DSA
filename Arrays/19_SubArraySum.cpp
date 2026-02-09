/*
 * Problem: 560. Subarray Sum Equals K
 *
 * Given an integer array nums and an integer k, return the total number of
 * subarrays whose sum is equal to k.
 *
 * This problem introduces a very important concept that will be reused in
 * many other problems: prefix sum + hashmap.
 *
 * Approaches:
 * 1. Brute Force (O(n^2))
 * 2. Optimal: Prefix Sum + HashMap (O(n))
 */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Approach 1: Brute Force
// Time Complexity: O(n^2)
// Space Complexity: O(1)
class Solution1 {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;

        for (int i = 0; i < n; i++) {          // starting index of subarray
            int sum = 0;
            for (int j = i; j < n; j++) {      // ending index of subarray
                sum += nums[j];
                if (sum == k) count++;
            }
        }

        return count;
    }
};

// Approach 2: Optimal using Prefix Sum + HashMap
// ps = prefix sum
// subarraySum[i..j] = ps[j] - ps[i-1]
//
// case 1 : we need to find ps[i-1] = ps[j] - k
// case 2 : if ps[j] == k, then the subarray [0..j] itself has sum k
//
// We iterate over j, maintain current prefix sum ps[j], and for each j:
//   - check case 2 directly (ps[j] == k)
//   - for case 1, we look for (ps[j] - k) in the hashmap which stores
//     frequencies of all previous prefix sums ps[i-1].
//
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution2 {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        int prefixSum = 0;  // ps[j]

        unordered_map<int, int> freq; // prefixSum -> frequency (how many times we have seen this ps before)

        for (int j = 0; j < n; j++) {
            prefixSum += nums[j]; // update ps[j]

            // case 2: if ps[j] == k, subarray [0..j] has sum k
            if (prefixSum == k) {
                count++;
            }

            // case 1: we need ps[i-1] = ps[j] - k
            int val = prefixSum - k;
            if (freq.find(val) != freq.end()) {
                count += freq[val];
            }

            // store current prefix sum for future j's
            freq[prefixSum]++;
        }

        return count;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, -2, 5};
    int k = 5;

    Solution1 sol1;
    Solution2 sol2;

    cout << "Input array: [1, 2, 3, -2, 5], k = 5" << endl;
    cout << "Brute Force count:  " << sol1.subarraySum(nums, k) << endl;
    cout << "Prefix Sum count:   " << sol2.subarraySum(nums, k) << endl;

    return 0;
}
