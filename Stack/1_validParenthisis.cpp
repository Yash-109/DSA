#include <stack>
#include <string>
using namespace std;

/*
 * Problem: 20. Valid Parentheses
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/valid-parentheses/
 *
 * Given a string s containing just the characters '(', ')', '{', '}', '[' and ']',
 * determine if the input string is valid.
 *
 * A string is valid if:
 *   - Open brackets must be closed by the same type of brackets.
 *   - Open brackets must be closed in the correct order.
 *
 * Approach Used Here: Stack of opening brackets
 * ------------------------------------------------
 *   - Traverse the string from left to right.
 *   - When we see an opening bracket '(', '{', '[', push it onto a stack.
 *   - When we see a closing bracket ')', '}', ']', the stack MUST NOT be empty
 *     and the top of the stack must be its matching opening bracket.
 *       - If it matches, pop the stack and continue.
 *       - If it does not match, the string is invalid.
 *   - After processing the entire string, the stack must be empty for the
 *     string to be valid (every opening bracket has a matching closing one).
 *
 * Pseudocode
 * ---------
 *   create empty stack<char> st
 *
 *   for each character ch in s:
 *       if ch is '(', '{', '[':
 *           push ch onto st
 *       else:   // ch is one of ')', '}', ']'
 *           if st is empty:
 *               return false
 *
 *           top = st.top()
 *           if (top, ch) is a matching pair:   // (), {}, []
 *               st.pop()
 *           else:
 *               return false
 *
 *   if st is empty:
 *       return true
 *   else:
 *       return false
 *
 * Time Complexity : O(n)  - each character is pushed and popped at most once
 * Space Complexity: O(n)  - in the worst case, all characters are opening
 */

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (int i = 0; i < static_cast<int>(s.size()); i++) {
            char ch = s[i];

            // Opening brackets: push onto the stack
            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            } else { // Closing bracket
                // No opening bracket available to match
                if (st.empty()) {
                    return false;
                }

                char top = st.top();

                // Valid matching pairs
                if ((top == '(' && ch == ')') ||
                    (top == '{' && ch == '}') ||
                    (top == '[' && ch == ']')) {
                    st.pop();
                } else {
                    // Mismatched pair
                    return false;
                }
            }
        }

        // String is valid only if no unmatched opening brackets remain
        return st.empty();
    }
};