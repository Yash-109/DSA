/*
====================
Part 1: Concept
====================

Problem: Next Greater Element (NGE)

Given an array arr, for every element arr[i] find the next element to its
right that is strictly greater than arr[i]. If no such element exists,
store -1 for that position.

Example:
  arr = [6, 8, 0, 1, 3]
  NGE  = [8, -1, 1, 3, -1]

Approach (Monotonic Stack, iterating from right to left):
  - Maintain a stack that always keeps elements in decreasing order from
    bottom to top.
  - Traverse the array from the last index to the first.
  - For each arr[i], pop elements from the stack while they are
    less than or equal to arr[i] (removing invalid candidates).
  - After popping:
      * If the stack is empty, there is no greater element on the right;
        set NGE[i] = -1.
      * Otherwise, the top of the stack is the next greater element;
        set NGE[i] = stack.top().
  - Push arr[i] onto the stack and continue.

Time Complexity:  O(n)  (each element is pushed and popped at most once)
Space Complexity: O(n)  (stack + answer array)

Pseudocode :
  stack<int> s
  vector<int> NGE(n)

  for (i = n - 1; i >= 0; i--) {
      while (s.size() > 0 && s.top() <= arr[i]) {
          // removing invalid elements
          s.pop()
      }

      if (s.empty()) {
          NGE[i] = -1
      } else {
          NGE[i] = s.top()
      }

      s.push(arr[i])
  }
*/

#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

int main() {

  vector<int> arr = {6, 8, 0, 1, 3};

  // next greater element
  stack<int> s;
  vector<int> ans(arr.size(), 0);

  for (int i = arr.size() - 1; i >= 0; i--) {

    while (s.size() > 0 && s.top() <= arr[i]) {
      s.pop();
    }

    if (s.empty()) {
      ans[i] = -1;
    } else {
      ans[i] = s.top();
    }

    s.push(arr[i]);
  }

  // print
  for (int val : ans) {
    cout << val << " ";
  }
  cout << endl;

  return 0;
}

/*
====================
Part 2: LeetCode 496 - Next Greater Element I
====================

Here nums1 is a subset of nums2 and all elements are unique.
We compute the next greater element for every value in nums2 using the
same monotonic stack idea as above, but instead of storing in an array we
store the answers in an unordered_map: value in nums2 -> its NGE.

Then for each value x in nums1 we simply return mp[x]. This lets us answer
queries in O(1) time per element.

Time Complexity:  O(n + m)  (n = |nums2|, m = |nums1|)
Space Complexity: O(n)      (stack + map)
*/

class Solution {
public:
  vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    // unordered_map stores: value in nums2 -> its next greater element
    unordered_map<int, int> mp;

    stack<int> s;

    for (int i = static_cast<int>(nums2.size()) - 1; i >= 0; i--) {
      while (!s.empty() && s.top() <= nums2[i]) {
        s.pop();
      }

      if (s.empty()) {
        mp[nums2[i]] = -1;
      } else {
        mp[nums2[i]] = s.top();
      }

      s.push(nums2[i]);
    }

    vector<int> ans;
    ans.reserve(nums1.size());

    // Use the map to answer for nums1: each lookup is O(1)
    for (int x : nums1) {
      ans.push_back(mp[x]);
    }

    return ans;
  }
};