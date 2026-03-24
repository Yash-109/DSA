
/*
 * Problem: 155. Min Stack
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/min-stack/
 *
 * Design a stack that supports push, pop, top, and retrieving
 * the minimum element in constant time.
 *   - push(x)   : Push element x onto stack.
 *   - pop()     : Remove the element on top of the stack.
 *   - top()     : Get the top element.
 *   - getMin()  : Retrieve the minimum element in the stack.
 *
 * ------------------------------------------------------------
 * Approach 1 (Extra Space, Stack of Pairs)
 * ------------------------------------------------------------
 *   - Store for every element (value, minSoFar).
 *   - minSoFar at any index i = minimum of all values in stack from 0..i.
 *   - On push(x):
 *       newMin = stack.empty() ? x : min(x, stack.top().minSoFar)
 *       push( {x, newMin} )
 *   - On pop():     normal stack pop.
 *   - On top():     return stack.top().value.
 *   - On getMin():  return stack.top().minSoFar.
 *
 * Time Complexity  : O(1) per operation
 * Space Complexity : O(n) extra (we store minSoFar for every element)
 *
 * NOTE: This approach is simple but uses ~2*n space. The code for
 *       this approach is kept below as a reference, commented out.
 *
 * ------------------------------------------------------------
 * Approach 2 (Encoded Values, O(1) Extra Space)  <<< Used Below
 * ------------------------------------------------------------
 * Idea: Store only one stack<long long> and one variable minVal.
 *
 *   - When we push a value >= current minVal, we simply push it.
 *   - When we push a value < current minVal (new minimum), we
 *     encode it before pushing:
 *
 *       encoded = 2 * value - minVal
 *       push(encoded)
 *       minVal = value
 *
 *     Why this works:
 *       - encoded is always < value and also < new minVal,
 *         so it acts like a "marker" on the stack: any element
 *         smaller than current minVal means it is an encoded value
 *         for some previous minimum.
 *
 *   - On pop():
 *       - If top >= minVal: it is a normal value, just pop.
 *       - If top <  minVal: it is an encoded old minimum. Let top = t.
 *           The previous minimum before this push was:
 *              prevMin = 2 * minVal - t
 *           So we set minVal back to prevMin and pop t.
 *
 *   - On top():
 *       - If top >= minVal: real top value = top.
 *       - If top <  minVal: this top is encoded, and the real
 *         value that was pushed is the current minVal.
 *
 * Correctness intuition:
 *   - Every time we push a new minimum, we store a compressed marker
 *     that let us reconstruct the previous minimum on pop.
 *   - We never lose information about old minima: it is hidden
 *     inside the encoded value on the stack.
 *
 * Time Complexity  : O(1) per operation
 * Space Complexity : O(1) extra (apart from the stack itself)
 */

#include <stack>
using namespace std;

// ------------------------------------------------------------
// Reference implementation for Approach 1 (extra O(n) space)
// (Kept for learning / comparison; not used by the judge.)
// ------------------------------------------------------------
// class MinStack {
// public:
//     stack<pair<int, int>> st; // {value, minSoFar}
//
//     MinStack() {}
//
//     void push(int val) {
//         if (st.empty()) {
//             st.push({val, val});
//         } else {
//             int currentMin = st.top().second;
//             int newMin = min(val, currentMin);
//             st.push({val, newMin});
//         }
//     }
//
//     void pop() {
//         st.pop();
//     }
//
//     int top() {
//         return st.top().first;
//     }
//
//     int getMin() {
//         return st.top().second;
//     }
// };

// ------------------------------------------------------------
// Approach 2: Encoded stack with O(1) extra space (active solution)
// ------------------------------------------------------------
class MinStack {
public:
    stack<long long> st; // stores either real values or encoded markers
    long long minVal;    // current minimum in the stack

    MinStack() {}

    void push(int val) {
        long long x = val;

        if (st.empty()) {
            // First element: directly push and set minVal
            st.push(x);
            minVal = x;
        } else if (x >= minVal) {
            // Normal case: value is not a new minimum
            st.push(x);
        } else {
            // x is new minimum → encode previous min inside stack
            long long encoded = 2LL * x - minVal;
            st.push(encoded);
            minVal = x; // update current minimum to new value
        }
    }

    void pop() {
        // Assuming pop is called only on a non-empty stack
        long long topVal = st.top();

        if (topVal >= minVal) {
            // Normal value, just pop
            st.pop();
        } else {
            // topVal is an encoded marker for some old minimum
            // Recover previous minimum before this encoded push
            long long previousMin = 2LL * minVal - topVal;
            st.pop();
            minVal = previousMin;
        }
    }

    int top() {
        long long topVal = st.top();

        if (topVal >= minVal) {
            // Real top value
            return static_cast<int>(topVal);
        } else {
            // Encoded marker → actual value at this node is current minVal
            return static_cast<int>(minVal);
        }
    }

    int getMin() {
        return static_cast<int>(minVal);
    }
};
