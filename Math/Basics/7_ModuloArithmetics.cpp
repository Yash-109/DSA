// reason for asking modulo of ans insted of direct ans is to prevent overflow of value in integer
/*
Properties of modulo::
(x + y) % m = x%m + y%m

(x - y) % m = x%m - y%m

(x . y) % m = x%m . y%m

IMPORTANT NOTES:
1. Division is NOT distributive: (x/y) % m ≠ (x%m) / (y%m)
   - Need Modular Multiplicative Inverse for division

2. For negative numbers:
   - In C++: (-5) % 3 = -2 (can be negative)
   - To make positive: ((x % m) + m) % m

3. Modular Exponentiation: (x^y) % m
   - Use binary exponentiation to avoid overflow
   - Time: O(log y)

4. Common Use Cases:
   - Large number calculations (avoid overflow)
   - Checking divisibility
   - Hashing
   - Cryptography

5. MOD value in problems: Usually 10^9+ 7 (1000000007) - a prime number

*/
