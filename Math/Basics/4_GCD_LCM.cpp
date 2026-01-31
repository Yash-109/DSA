// GCD = Greatest common division

#include <iostream>
using namespace std;

// Approach 1: Brute Force - Time Complexity: O(min(a,b))
int gcdBruteForce(int a, int b) {
    int minVal = min(a, b);
    
    for (int i = minVal; i >= 1; i--) {
        if (a % i == 0 && b % i == 0) {
            return i;  // here we return the first i so we will get greatest not smallest
        }
    }
    return 1;
}

// Approach 2: Euclidean Algorithm - Time Complexity: O(log(min(a,b)))
// Core Logic: GCD(a, b) = GCD(b, a % b)
// The algorithm repeatedly replaces the larger number with the remainder
// until one of them becomes 0. The non-zero value is the GCD.
// Example: GCD(28, 20) -> GCD(20, 8) -> GCD(8, 4) -> GCD(4, 0) = 4
int gcd(int a, int b) {
    while(a > 0 && b > 0) {
        if(a > b) {
            a = a % b;  // Replace larger number with remainder
        } else {
            b = b % a;  // Replace larger number with remainder
        }
    }
    
    if(a == 0) return b;  // If a becomes 0, b is the GCD
    return a;             // If b becomes 0, a is the GCD
}

// LCM = Least Common Multiple
// Formula: LCM(a, b) = (a * b) / GCD(a, b)
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int main() {
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;
    
    cout << "GCD using Euclidean Algorithm: " << gcd(a, b) << endl;
    cout << "GCD using Brute Force: " << gcdBruteForce(a, b) << endl;
    cout << "LCM: " << lcm(a, b) << endl;
    
    return 0;
}
