/*
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

Pseudocode (from board):
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