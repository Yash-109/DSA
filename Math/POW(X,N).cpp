// LeetCode 50: Pow(x, n)
// Time Complexity: O(log n) - binary exponentiation reduces the problem by half each iteration
// Space Complexity: O(1) - only using constant extra space

#include <iostream>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {

        // ✅ Handle corner/base cases first
        if (n == 0) return 1.0;              // Any number to power 0 is 1
        if (x == 0) return 0.0;              // 0 to any power is 0
        if (x == 1) return 1.0;              // 1^anything = 1
        if (x == -1 && n % 2 == 0) return 1.0;   // (-1)^even = 1
        if (x == -1 && n % 2 != 0) return -1.0;  // (-1)^odd = -1

        // ✅ Convert exponent 'n' to long (to avoid overflow for INT_MIN)
        long binaryform = n;   // store n in a long variable

        // ✅ If power is negative, invert x and make exponent positive
        if (n < 0)
        {
            x = 1 / x;                  // example: 3^-5 = (1/3)^5
            binaryform = -binaryform;   // make exponent positive for loop
        }

        double ans = 1;  // final result will be stored here

        // ✅ Binary exponentiation loop (O(log n) time)
        // We repeatedly square x and multiply it into ans when needed
        while (binaryform > 0)
        {
            // If current bit of exponent is 1 → multiply 'ans' by 'x'
            if (binaryform % 2 == 1)
            {
                ans *= x;
            }

            // Square the base for next bit (x = x^2)
            x *= x;

            // Move to the next bit of the exponent
            binaryform /= 2;
        }

        // ✅ Return the final answer
        return ans;
    }
};

// Example driver code to test in VS Code
int main() {
    Solution sol;
    cout << sol.myPow(2, 10) << endl;   // Expected: 1024
    cout << sol.myPow(2.1, 3) << endl;  // Expected: 9.261
    cout << sol.myPow(2, -2) << endl;   // Expected: 0.25
}
