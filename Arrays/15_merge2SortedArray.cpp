/*
 * Problem: 88. Merge Sorted Array
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/merge-sorted-array/
 * 
 * Merge two sorted arrays in-place (merge B into A)
 * Uses three-pointer approach starting from the end
 * Time Complexity: O(m+n)
 * Space Complexity: O(1)
 */

/*
 * Approach (Three Pointers from the End)
 * --------------------------------------
 * - Array A has size m + n; the first m elements are valid, and the last n
 *   positions are empty space to accommodate elements of B.
 * - Use three indices:
 *     i = m - 1  -> last valid element in A
 *     j = n - 1  -> last element in B
 *     k = m + n - 1 -> last position in A (where merged result is built)
 * - Compare A[i] and B[j] from the back:
 *     - Place the larger one at A[k] and move the corresponding pointer
 *       (i or j) and also decrement k.
 * - After one array is exhausted, if elements remain in B, copy them into A
 *   (any remaining elements in A are already in correct place).
 * - This way we merge in-place without using extra space.
 *
 * Pseudocode
 * ---------
 *   function merge(A, m, B, n):
 *       i = m - 1
 *       j = n - 1
 *       k = m + n - 1
 *
 *       while i >= 0 and j >= 0:
 *           if A[i] >= B[j]:
 *               A[k] = A[i]
 *               i = i - 1
 *           else:
 *               A[k] = B[j]
 *               j = j - 1
 *           k = k - 1
 *
 *       while j >= 0:        // copy remaining elements from B
 *           A[k] = B[j]
 *           j = j - 1
 *           k = k - 1
 *
 *       // no need to copy remaining A elements; they are already in place
 */

#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {  
        int indx = m+n-1, i=m-1, j=n-1;
        while(i>=0 && j>=0)
        {
            if(A[i]>=B[j])
            {
                A[indx--]=A[i--];
            }

            else{
                A[indx--] = B[j--];
            }
        }

        while(j>=0)
        {
            A[indx--] = B[j--];
        }
    }
};