/*
Problem: Stock Span Problem

Given an array price[] where price[i] is the price of a stock on day i
(0‑indexed), for every day i you have to find its stock span.

Stock span of day i = number of consecutive days (including day i itself)
just before or up to i where the price of the stock was less than or equal
to price[i]. The span always ends at i and extends backwards.

Example:
price = [100, 80, 60, 70, 60, 75, 85]
span  = [1,   1,  1,  2,  1,  4,  6]

Goal: Print the span for each day in order.

Approach (Monotonic Stack, O(n)):
- Maintain a stack that stores indices of days, with prices in strictly
    decreasing order from bottom to top.
- For the current day i:
    - Pop from the stack while the price at the stored index is
        less than or equal to price[i] (these days are covered by span of i).
    - If the stack becomes empty, it means there is no previous day with a
        greater price, so span[i] = i + 1 (from day 0 to i).
    - Otherwise, the top of the stack is the closest previous day with a
        greater price; span[i] = i - topIndex.
    - Push the current index i on the stack.

Pseudocode:
    read n and array price[0..n-1]
    create array span[0..n-1]
    create empty stack S   // stores indices

    for i from 0 to n-1:
            while S is not empty AND price[S.top()] <= price[i]:
                    S.pop()

            if S is empty:
                    span[i] = i + 1
            else:
                    span[i] = i - S.top()

            S.push(i)

    output all values of span[]
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {

    // stock prices
    vector<int> price = {100, 80, 60, 70, 60, 75, 85};

    // answer array initialized with 0
    vector<int> ans(price.size(), 0);

    // stack stores indices
    stack<int> s;

    for (int i = 0; i < price.size(); i++) {

        // remove all previous smaller or equal prices
        while (!s.empty() && price[s.top()] <= price[i]) {
            s.pop();
        }

        // if stack empty → no previous greater element
        if (s.empty()) {
            ans[i] = i + 1;
        } 
        else {
            ans[i] = i - s.top();
        }

        // push current index
        s.push(i);
    }

    // print result
    for (int val : ans) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}